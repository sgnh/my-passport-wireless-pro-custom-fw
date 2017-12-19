#!/bin/bash
#
# SDCard_StorageTransfer.sh
#
# Used to triiger Storage Transfer process
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
echo $timestamp ": USB_AutoStorageTransfer.sh" $@ >> /tmp/backup.log

if [ "${USB_TransferAuto}" == "false" ]; then
	exit 0
else
	if [ -f "/tmp/USB_AutoProcessing" ]; then
		exit 1
	fi
	
   	if [ "${USB_TransferStatus}" == "process" ]; then
		exit 1
	fi
	
	
	if [ "$TransferStatus" != "completed" ]; then
		echo "USB_TransferStatus=standby:Auto:""$method" > /etc/nas/config/usb-transfer-status.conf
	else
		partitionNum=`ls /tmp/sd*-info | wc -l`
		totalNum="${partitionNum}"
		if [ "${partitionNum}" != "0" ]; then
			echo "USB_TransferStatus=checkin" > /etc/nas/config/usb-transfer-status.conf
			touch /tmp/USB_AutoProcessing
		fi
		
		while [ "$partitionNum" != "0" ]; do
			USB_backup=`cat /etc/nas/config/usb-transfer-status.conf | awk -F= '{print $NF}'`
			if [ "$USB_backup" == "completed" ] || [ "$USB_backup" == "checkin" ]; then
				
				if [ "$totalNum" == "1" ]; then 
					USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}'`
				else
					USBshare=`cat /tmp/sd*-info | awk -F: '{print $1}' | sed -n ${partitionNum}p`
				fi
				partitionNum=`expr $partitionNum - 1`
				
				#Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   				#Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`
				#if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then	
				#devicefound=`cat /tmp/detectInterface`
				#if [ "$devicefound" == "MTP" ]; then
				#	USBshare="USB_MTP"
				#elif [ "$devicefound" == "PTP" ]; then # Louis
				#	USBshare="USB_PTP"				
				#fi
				#echo status=waiting > /tmp/transfer_state
				echo $timestamp ": USB_AutoStorageTransfer.sh backup trigger" >> /tmp/backup.log
				
   				/usr/local/sbin/storage_transfer_job_start.sh "/${USBshare}" &
   				sleep 30
   				#fi
   			fi
   		done
   	fi
   	if [ -f "/tmp/USB_AutoProcessing" ]; then
		rm /tmp/USB_AutoProcessing
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

