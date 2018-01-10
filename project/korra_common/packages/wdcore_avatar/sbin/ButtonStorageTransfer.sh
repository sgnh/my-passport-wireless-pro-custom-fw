#!/bin/bash
#
# ButtonStorageTransfer.sh
#
# Used to trigger Storage Transfer process by Button
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf

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
targetDst="${1}"
Mode="${2}"
Auto="${3}"

timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": ButtonStorageTransfer.sh" $@ >> /tmp/backup.log

factory_conf=/etc/nas/config/factory.conf                                                                                                                                                                                                                                      
if [ -f "$factory_conf" ] && [ `grep FACTORY_MODE $factory_conf | wc -l` == "1" ] && [ `grep FACTORY_MODE $factory_conf | awk -F= '{print $2}'` == "1" ]; then
	echo $timestamp ":  ButtonStorageTransfer Factory mode" >> /tmp/backup.log
    exit 0
fi

targetDst=SD

if [ -f "/tmp/SDCard_ButtonProcessing" ] || [ "${TransferStatus}" != "completed" ]; then
	sdTransfer=0
	echo $timestamp ":  ButtonStorageTransfer TransferStatus:" ${TransferStatus} >> /tmp/backup.log
else
	SDpartitionNum=`ls /tmp/mmcblk0*-info | wc -l`
	echo $timestamp ":  ButtonStorageTransfer SDpartitionNum:" ${SDpartitionNum} >> /tmp/backup.log
	if [ "${SDpartitionNum}" == "0" ]; then
		sdTransfer=0
	else
		sdTransfer=1
	fi
fi

if [ -f "/tmp/USB_ButtonProcessing" ] || [ "${USB_TransferStatus}" != "completed" ]; then
	usbTransger=0
	echo $timestamp ":  ButtonStorageTransfer USB_TransferStatus:" ${USB_TransferStatus} >> /tmp/backup.log
else
	USBpartitionNum=`ls /tmp/sd*-info | wc -l`
	echo $timestamp ":  ButtonStorageTransfer USBpartitionNum:" ${USBpartitionNum} >> /tmp/backup.log
	if [ "${USBpartitionNum}" == "0" ]; then
		usbTransger=0
		
	else
		usbTransger=1
	fi
fi

if [ "${sdTransfer}" == "0" ] && [ "${usbTransger}" == "0" ]; then
	echo $timestamp ":  ButtonStorageTransfer No External Drive:" ${sdTransfer} ${usbTransger} >> /tmp/backup.log
	exit 0
fi 

source /etc/nas/config/sdcard-transfer-status.conf
source /etc/nas/config/usb-transfer-status.conf
sdmethod=${TransferMode}
usbmethod=${USB_ModeTransfer}
	
if [ "${sdTransfer}" == "1" ]; then
	if [ "$USB_TransferStatus" != "completed" ]; then
		echo "TransferStatus=standby:Button:""$sdmethod" > /etc/nas/config/sdcard-transfer-status.conf #put sd card backup to standby
	else
		touch /tmp/SDCard_ButtonProcessing

		DiskNum="${SDpartitionNum}"
		while [ "${DiskNum}" != "0" ]; do
			#SD_status=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
			#if [ "$SD_status" == "completed" ]; then
				if [ "$SDpartitionNum" == "1" ]; then 
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}'`
				else
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}' | sed -n ${DiskNum}p`
				fi
				DiskNum=`expr $DiskNum - 1`
			
 				#Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   				#Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`
				#echo $timestamp ": ButtonStorageTransfer.sh SD jobs Running" $Running >> /tmp/backup.log
				#echo $timestamp ": ButtonStorageTransfer.sh SD jobs Waiting" $Waiting >> /tmp/backup.log
   				#if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
       				#echo status=waiting > /tmp/transfer_state
   					/usr/local/sbin/storage_transfer_job_start.sh "/${sdshare}" 2>&1 &
					echo $timestamp ": ButtonStorageTransfer.sh SD jobs trigger" $sdshare >> /tmp/backup.log
       				sleep 30 #wait for restapi database ready
       			#fi
   			#fi                     
		done
	fi
	
	if [ -f "/tmp/SDCard_ButtonProcessing" ]; then
		rm /tmp/SDCard_ButtonProcessing
	fi
fi

#if [ "${sdTransfer}" == "1" ]; then
#	status=`storage_transfer_status.sh | grep "status" | cut -d '=' -f 2`
#	breakcount=0
#	while [ "${status}" != completed ]; do
#		status=`storage_transfer_status.sh | grep "status" | cut -d '=' -f 2`
#		sleep 10
#		breakcount=`expr $breakcount + 1`
#		if [ "${breakcount}" -gt 5 ]; then
#			break;
#		fi
#	done
#	sleep 10
#fi

if [ "${usbTransger}" == "1" ]; then
	if [ "$TransferStatus" != "completed" ]; then
		echo "USB_TransferStatus=standby:Button:""$usbmethod" > /etc/nas/config/usb-transfer-status.conf
	else
		touch /tmp/USB_ButtonProcessing
		DiskNum="${USBpartitionNum}"
		
		while [ "$DiskNum" != "0" ]; do
			
			if [ "$USBpartitionNum" == "1" ]; then 
				USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}'`
			else	
				USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}' | sed -n ${DiskNum}p`
			fi
			DiskNum=`expr $DiskNum - 1`
			
			#Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   			#Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`
   			#timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestamp ": ButtonStorageTransfer.sh USB jobs Running" $Running >> /tmp/backup.log
			#echo $timestamp ": ButtonStorageTransfer.sh USB jobs Waiting" $Waiting >> /tmp/backup.log
   			#if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
       			#echo status=waiting > /tmp/transfer_state
   				/usr/local/sbin/storage_transfer_job_start.sh "/${USBshare}" 2>&1 &
				echo $timestamp ": ButtonStorageTransfer.sh USB jobs trigger" $USBshare >> /tmp/backup.log
       			sleep 30
   			#fi
		done
	fi
	if [ -f "/tmp/USB_ButtonProcessing" ]; then
		rm /tmp/USB_ButtonProcessing
	fi
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


