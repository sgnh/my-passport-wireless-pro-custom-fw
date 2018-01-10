#!/bin/bash
#
# ï¿?2010 Western Digital Technologies, Inc. All rights reserved.
#
# storage_transfer_start_now.sh
#
# Used to manually initiate a Storage Transfer process
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf
. /etc/system.conf

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": storage_transfer_start_now.sh called:" $@ >> /tmp/backup.log

echo status=waiting > /tmp/transfer_state
echo "total_size_in_bytes=0" > /tmp/transfer_size_total
echo "transferred_size_in_bytes=0" > /tmp/transfer_size

#AutoTransfer=false
#TransferMode=copy
#USB_TransferAuto=false
#USB_ModeTransfer=copy
HDDmount=`cat /tmp/HDDDevNode`

incoming=$#
if [ "$incoming" == "0" ]; then
	echo "Usage: storage_transfer_start_now [move | copy <share_name>]"
	exit 1	
elif [ "$incoming" == "2" ]; then
	method="${1}"
	sharename="${2}"
elif [ "$incoming" == "1" ]; then
	sharename="${1}"
fi
	
available_chk=`/usr/local/sbin/storage_transfer_device_available.sh "storageType" "${sharename}"`
echo $timestamp ": storage_transfer_start_now.sh" $available_chk >> /tmp/backup.log
if [ "$available_chk" == "SD" ]; then
	SDmount=`cat /tmp/mmcblk0p*-info | grep -rsw "${sharename}" | awk -F: '{print $3}'`
	SDVolume=`df | grep "${SDmount}" | awk '{ print $3 }'`
	HDDSpace=`df | grep "${HDDmount}" | head -1 |awk '{ print $4 }'`
	FormatType=`cat /tmp/mmcblk0p*-info | grep -rsw "${sharename}" | awk -F: '{print $5}'`
		
	if [ "$SDVolume" -gt "$HDDSpace" ]; then                                             
		/usr/local/sbin/sendAlert.sh 1603 &
		/usr/local/sbin/incUpdateCount.pm storage_transfer &
		echo "status=SDoutcapacity" > /tmp/transfer_state
		sleep 3
		echo "42;125;" > /tmp/MCU_Cmd
		#/sbin/ButtonStorageTransfer.sh USB
		exit 1                                                                       
   	elif [ "$SDVolume" == "" ]; then
		echo "42;125;" > /tmp/MCU_Cmd
		echo "status=failed" > /tmp/transfer_state
		/usr/local/sbin/sendAlert.sh 1607 &
		/usr/local/sbin/incUpdateCount.pm storage_transfer &
		#/sbin/ButtonStorageTransfer.sh USB
		exit 1
	fi
	
	if [ "$USB_TransferStatus" != "completed" ]; then
		if [ ! -f "/tmp/sd*-info" ]; then
			echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		fi
	fi
		
	if [ "$TransferStatus" != "completed" ]; then
		if [ ! -f "/tmp/mmcblk0*-info" ]; then
			echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		fi
	fi
		
	source /etc/nas/config/sdcard-transfer-status.conf
	source /etc/nas/config/usb-transfer-status.conf
		
	if [ "${USB_TransferStatus}" == "process" ]; then
		echo "TransferStatus=standby:""$method" > /etc/nas/config/sdcard-transfer-status.conf
		exit 0
	fi
		
	if [ "${TransferStatus}" == "process" ]; then
		echo "18;0;" > /tmp/MCU_Cmd 
		echo $timestamp ": storage_transfer_start_now.sh Still process" >> /tmp/backup.log
		exit 1
	fi
		
	if [ "$method" == "move" ]; then
		/sbin/SDCard_StorageTransfer.sh "${sharename}" move true 2>&1 &
		exit 0
	elif [ "$method" == "copy" ]; then
		/sbin/SDCard_StorageTransfer.sh "${sharename}" copy true 2>&1 &
		exit 0
	else
		#echo "aaasharename" $sharename
		/sbin/SDCard_StorageTransfer.sh "${sharename}" ${TransferMode} true 2>&1 &
		exit 0
	fi
elif [ "$available_chk" == "USB" ]; then
	devicefound=`cat /tmp/detectInterface`
	SerialNum=`cat /tmp/HDSerial`
	USBDescription=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $7}'`
	HDDSpace=`sudo df | grep "$HDDmount" | head -1 |awk '{ print $4 }'`
	if [ "${devicefound}" == "MTP" ]; then
		USBmount="/media/USB"
		USBVolume=`df | grep "${USBmount}" | awk '{ print $3 }'`
		if [ "$USBVolume" == "" ]; then
			USBVolume=`du -s "/media/USB" | awk '{print $1}'`
		fi
	elif [ "${devicefound}" == "PTP" ]; then
		USBmount="/media/USB"
		USBVolume=`df | grep "${USBmount}" | awk '{ print $3 }'`
		if [ "$USBVolume" == "" ]; then
			USBVolume=`du -s "/media/USB" | awk '{print $1}'`
		fi
	else
		USBmount=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $3}'`
		USBVolume=`df | grep "${USBmount}" | awk '{ print $3 }'`
	fi
	if [ "${USBVolume}" -gt "${HDDSpace}" ]; then                                             
		/usr/local/sbin/sendAlert.sh 1604 $USBDescription $SerialNum &
		/usr/local/sbin/incUpdateCount.pm storage_transfer &
		echo "status=USBoutcapacity" > /tmp/transfer_state
		sleep 3
		echo "42;125;" > /tmp/MCU_Cmd
		exit 1
	elif [ "$USBVolume" == "" ]; then
		echo "42;125;" > /tmp/MCU_Cmd
		/usr/local/sbin/sendAlert.sh 1608 &
		echo "status=failed" > /tmp/transfer_state
		exit 1
	fi
		
	if [ "$USB_TransferStatus" != "completed" ]; then
		if [ ! -f "/tmp/sd*-info" ]; then
			echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		fi
	fi
		
	if [ "$TransferStatus" != "completed" ]; then
		if [ ! -f "/tmp/mmcblk0*-info" ]; then
			echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		fi
	fi
		
	source /etc/nas/config/sdcard-transfer-status.conf
	source /etc/nas/config/usb-transfer-status.conf
		
	if [ "${TransferStatus}" == "process" ]; then
		echo "USB_TransferStatus=standby:""$method" > /etc/nas/config/usb-transfer-status.conf
		exit 0
	fi
	if [ "${USB_TransferStatus}" == "process" ]; then
		echo "status=failed" > /tmp/transfer_state
		echo "18;0;" > /tmp/MCU_Cmd
		exit 1
	fi
		
	if [ "$method" == "move" ]; then
		/sbin/USB_StorageTransfer.sh "${sharename}" move true 2>&1 &
		exit 0
	elif [ "$method" == "copy" ]; then
		/sbin/USB_StorageTransfer.sh "${sharename}" copy true 2>&1 &
		exit 0
	else
		/sbin/USB_StorageTransfer.sh "${sharename}" "${USB_ModeTransfer}" true 2>&1 &
		exit 0
	fi
elif [ "$available_chk" == "false" ]; then
	echo "Unable to locate storage device"
	echo "status=failed" > /tmp/transfer_state
	echo "42;125;" > /tmp/MCU_Cmd
	exit 1
fi


exit 0
#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}

