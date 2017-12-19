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
    timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ":  ButtonStorageTransfer Factory mode" >> /tmp/backup.log
    exit 0
fi

if [ "${targetDst}" == "" ] || [ "${targetDst}" == "SD" ]; then
	targetDst=SD

	if [ "${AutoTransfer}" == "true" ] || [ -f "/tmp/SDCard_ButtonProcessing" ] || [ "${TransferStatus}" == "process" ]; then
		sdTransfer=0
	else
		partitionNum=`ls /tmp/mmcblk0*-info | wc -l`
		if [ "${partitionNum}" == "0" ]; then
			sdTransfer=0
		else
			sdTransfer=1
		fi
	fi

	if [ "${USB_TransferAuto}" == "true" ] || [ -f "/tmp/USB_ButtonProcessing" ] || [ "${USB_TransferStatus}" == "process" ]; then
		usbTransger=0
	else
		partitionNum=`ls /tmp/sd*-info | wc -l`
		if [ "${partitionNum}" == "0" ]; then
			usbTransger=0
		else
			usbTransger=1
		fi
	fi
elif [ "${targetDst}" == "USB" ]; then
	if [ "${USB_TransferAuto}" == "true" ] || [ -f "/tmp/USB_ButtonProcessing" ] || [ "${USB_TransferStatus}" == "process" ]; then
		usbTransger=0
	else
		partitionNum=`ls /tmp/sd*-info | wc -l`
		if [ "${partitionNum}" == "0" ]; then
			usbTransger=0
		else
			usbTransger=1
		fi
	fi
fi

if [ "${sdTransfer}" == "0" ] && [ "${usbTransger}" == "0" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ":  ButtonStorageTransfer No External Drive Insert" >> /tmp/backup.log
	exit 0
fi 

source /etc/nas/config/sdcard-transfer-status.conf
source /etc/nas/config/usb-transfer-status.conf
	
if [ "${sdTransfer}" == "1" ]; then
	if [ "$USB_TransferStatus" != "completed" ]; then
		echo "TransferStatus=standby:Button:""$method" > /etc/nas/config/sdcard-transfer-status.conf
	else
		partitionNum=`ls /tmp/mmcblk0*-info | wc -l`
		totalNum="${partitionNum}"
	
		echo "TransferStatus=checkin" > /etc/nas/config/sdcard-transfer-status.conf
			
		touch /tmp/SDCard_ButtonProcessing
		while [ "${partitionNum}" != "0" ]; do
			SD_backup=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
			if [ "$SD_backup" == "completed" ] || [ "$SD_backup" == "checkin" ]; then
				
				if [ "$totalNum" == "1" ]; then 
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}'`
				else
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}' | sed -n ${partitionNum}p`
				fi
				partitionNum=`expr $partitionNum - 1`
			
				method=${TransferMode}
				autotransfer=${AutoTransfer}
		
 				Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   				Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`
   				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": ButtonStorageTransfer.sh SD jobs Running" $Running >> /tmp/backup.log
				echo $timestamp ": ButtonStorageTransfer.sh SD jobs Waiting" $Waiting >> /tmp/backup.log
   				if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
       				echo status=waiting > /tmp/transfer_state
       				
					#echo "sdshare" ${sdshare}
   					/usr/local/sbin/storage_transfer_job_start.sh "/${sdshare}" 2>&1 &
   					
   					#timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": ButtonStorageTransfer.sh SD jobs Running share" $sdshare >> /tmp/backup.log
       				sleep 30
       			fi
   			fi                     
		done
	fi
	
	if [ -f "/tmp/SDCard_ButtonProcessing" ]; then
		rm /tmp/SDCard_ButtonProcessing
	fi
fi

if [ "${sdTransfer}" == "1" ]; then
	status=`storage_transfer_status.sh | grep "status" | cut -d '=' -f 2`
	breakcount=0
	while [ "${status}" != completed ]; do
		status=`storage_transfer_status.sh | grep "status" | cut -d '=' -f 2`
		sleep 10
		breakcount=`expr $breakcount + 1`
		if [ "${breakcount}" -gt 5 ]; then
			break;
		fi
	done
	sleep 10
fi

if [ "${usbTransger}" == "1" ]; then
	if [ "$TransferStatus" != "completed" ]; then
		echo "USB_TransferStatus=standby:Button:""$method" > /etc/nas/config/usb-transfer-status.conf
	else
		touch /tmp/USB_ButtonProcessing

		partitionNum=`ls /tmp/sd*-info | wc -l`
		totalNum="${partitionNum}"
		
		echo "USB_TransferStatus=checkin" > /etc/nas/config/usb-transfer-status.conf
		echo $timestamp ": ButtonStorageTransfer.sh USB" $partitionNum >> /tmp/backup.log
		
		while [ "$partitionNum" != "0" ]; do
			USB_backup=`cat /etc/nas/config/usb-transfer-status.conf | awk -F= '{print $NF}'`
			echo $timestamp ": ButtonStorageTransfer.sh USB status" $USB_backup >> /tmp/backup.log
			if [ "$USB_backup" == "completed" ] || [ "$USB_backup" == "checkin" ]; then
			
				if [ "$totalNum" == "1" ]; then 
					USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}'`
				else	
					USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}' | sed -n ${partitionNum}p`
				fi
				partitionNum=`expr $partitionNum - 1`
			
				method=${USB_ModeTransfer}
				autotransfer=${USB_TransferAuto}
		
    			Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   				Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`
   				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": ButtonStorageTransfer.sh USB jobs Running" $Running >> /tmp/backup.log
				echo $timestamp ": ButtonStorageTransfer.sh USB jobs Waiting" $Waiting >> /tmp/backup.log
   				if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
       				echo status=waiting > /tmp/transfer_state
       				
					#devicefound=`cat /tmp/detectInterface`
					#if [ "$devicefound" == "MTP" ]; then
					#	USBshare="USB_MTP"
					#elif [ "$devicefound" == "PTP" ]; then # Louis
					#	USBshare="USB_PTP"
					#fi
					#echo "USBshare" ${USBshare}
   					/usr/local/sbin/storage_transfer_job_start.sh "/${USBshare}" 2>&1 &
   					
   					#timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestamp ": ButtonStorageTransfer.sh SD jobs Running share" $USBshare >> /tmp/backup.log
       				sleep 30
   				fi                     	
   			fi
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


