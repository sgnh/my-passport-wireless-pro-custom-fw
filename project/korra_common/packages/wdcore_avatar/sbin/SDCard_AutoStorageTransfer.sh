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
echo $timestamp ": SDCard_AutoStorageTransfer.sh" $@ >> /tmp/backup.log

sdmethod=${TransferMode}

if [ "${AutoTransfer}" == "false" ]; then
	exit 0
else
	if [ -f "/tmp/SDCard_AutoProcessing" ] || [ "${TransferStatus}" != "completed" ]; then
		echo $timestamp ": SDCard_AutoStorageTransfer.sh exit: TransferStatus" ${TransferStatus} >> /tmp/backup.log
		exit 1
	fi

	SDpartitionNum=`ls /tmp/mmcblk0*-info | wc -l`
	if [ "${SDpartitionNum}" == "0" ]; then
		echo $timestamp ":  SDCard_AutoStorageTransfer None SDpartitionNum:" ${SDpartitionNum} >> /tmp/backup.log
		exit 1
	fi
	
	if [ "$USB_TransferStatus" != "completed" ]; then
		echo "TransferStatus=standby:Auto:""$sdmethod" > /etc/nas/config/sdcard-transfer-status.conf
	else
		touch /tmp/SDCard_AutoProcessing
		DiskNum="${SDpartitionNum}"
	
		while [ "$DiskNum" != "0" ]; do
			if [ "$SDpartitionNum" == "1" ]; then 
				sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}'`
			else
				sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}' | sed -n ${DiskNum}p`
			fi
			DiskNum=`expr $DiskNum - 1`
		
			#Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   			#Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`	
            #if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
    		#echo status=waiting > /tmp/transfer_state
   			/usr/local/sbin/storage_transfer_job_start.sh "/${sdshare}" &	
   			echo $timestamp ": SDCard_AutoStorageTransfer.sh SD jobs trigger" $sdshare >> /tmp/backup.log
       		sleep 30
			#fi
		done
   	fi
   	if [ -f "/tmp/SDCard_AutoProcessing" ]; then
		rm /tmp/SDCard_AutoProcessing
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


