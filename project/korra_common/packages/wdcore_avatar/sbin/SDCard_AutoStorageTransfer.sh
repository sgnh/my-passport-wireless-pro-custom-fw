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

if [ "${AutoTransfer}" == "false" ]; then
	exit 0
else
	if [ -f "/tmp/SDCard_AutoProcessing" ]; then
		exit 1
	fi
	
	if [ "${TransferStatus}" == "process" ]; then
		exit 1
	fi
	
	if [ "$USB_TransferStatus" != "completed" ]; then
		echo "TransferStatus=standby:Auto:""$method" > /etc/nas/config/sdcard-transfer-status.conf
	else
		partitionNum=`ls /tmp/mmcblk0*-info | wc -l`
		totalNum="${partitionNum}"
		if [ "${partitionNum}" != "0" ]; then
			echo "TransferStatus=checkin" > /etc/nas/config/sdcard-transfer-status.conf
			touch /tmp/SDCard_AutoProcessing
		fi
		while [ "$partitionNum" != "0" ]; do
			SD_backup=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
			if [ "$SD_backup" == "completed" ] || [ "$SD_backup" == "checkin" ]; then
				echo "partitionNum" ${partitionNum}
		
				if [ "$totalNum" == "1" ]; then 
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}'`
				else
					sdshare=`cat /tmp/mmcblk0*-info | awk -F: '{print $1}' | sed -n ${partitionNum}p`
				fi
				partitionNum=`expr $partitionNum - 1`
			
				method=${TransferMode}
				autotransfer=${AutoTransfer}
				
				echo $timestamp ": SDCard_AutoStorageTransfer.sh backup triggering" >> /tmp/backup.log
			 	#Running=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=2' | wc -l`
   				#Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select jobstate_id from Jobs where jobstate_id=1' | wc -l`	
                #if [ "${Running}" -eq "0" ] && [ "${Waiting}" -eq "0" ]; then
    				#echo status=waiting > /tmp/transfer_state
					#echo "sdshare" ${sdshare}
   					/usr/local/sbin/storage_transfer_job_start.sh "/${sdshare}" &	
       				sleep 30
				#fi
			fi
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


