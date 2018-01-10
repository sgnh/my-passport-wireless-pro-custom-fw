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
##########QA test performance#########
backupTest=0
######################################
RuningStatus=0
needCompare=0
total_size=0
SD_BACKUP_ROOT="SD Card Imports"
SD_MOUNT=/media/SD_Card
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
function removeTempfile()
{
	if [ -f "/tmp/AllCmpDir" ]; then
		rm /tmp/AllCmpDir
	fi
	if [ -f "/tmp/DoneFolder" ]; then
		rm /tmp/DoneFolder
	fi
	if [ -f "/tmp/BackUpTemplist" ]; then
		rm /tmp/BackUpTemplist
	fi
	if [ -f "/tmp/SDCard_AutoProcessing" ]; then
		rm /tmp/SDCard_AutoProcessing
	fi
	if [ -f "/tmp/SDCard_ButtonProcessing" ]; then
		rm /tmp/SDCard_ButtonProcessing
	fi
	if [ -f "/tmp/RsyncConfliclist" ]; then
		rm /tmp/RsyncConfliclist
	fi
	
	if [ -f "/tmp/rsyncExcludefile" ]; then
		rm /tmp/rsyncExcludefile
	fi
}
function finishSdBackup()
{
	removeTempfile
	/usr/local/sbin/sendAlert.sh 1609 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
	echo "42;100" > /tmp/MCU_Cmd
	echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
	echo $timestampDBG ": SDCard_StorageTransfer.sh Complete!!" >> /tmp/backup.log
	echo "transferred_size_in_bytes=${total_size}" > /tmp/transfer_size
	sed -i "s/status=.*/status=completed/" /tmp/transfer_state
}

function USB_BackupQueueCheck() #check USB backup process
{
	USB_status=`cat /etc/nas/config/usb-transfer-status.conf | awk -F= '{print $NF}'`
	echo $timestampDBG ": SDCard_StorageTransfer.sh USB_BackupQueueCheck" $USB_status >> /tmp/backup.log
	if [ "$USB_status" != "completed" ]; then
		usb_standby=`echo "${USB_status}" | awk -F: '{print $1}'`
		echo $timestampDBG ": SDCard_StorageTransfer.sh USB_BackupQueueCheck sdstandby:" $sdstandby >> /tmp/backup.log
		sleep 20
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		if [ "$usb_standby" == "standby" ]; then
			triggerMode=`echo "${USB_status}" | awk -F: '{print $2}'`
			if [ "${triggerMode}" == "Button" ]; then
				/sbin/ButtonStorageTransfer.sh USB
			elif [ "${triggerMode}" == "Auto" ]; then
				/sbin/USB_AutoStorageTransfer.sh
			else
				/sbin/ButtonStorageTransfer.sh USB
			fi
		elif [ "$usbstandby" == "checkin" ]; then

			/sbin/ButtonStorageTransfer.sh USB 2>&1 &
		fi
	fi
}

function ReproduceFileBackup()
{
	find "${1}" -name "*_tmparchive" > /tmp/sdArchivePath
	ArchiveCount=`cat /tmp/sdArchivePath | grep -c _tmparchive`
	if [ ${ArchiveCount} != 0 ]; then
		for  ((i=1; i<=$ArchiveCount; i=i+1))    
		do
			ArchivePath=`cat /tmp/sdArchivePath | sed -n "${i}p"`
			filetimestamp=`stat -c %y "${ArchivePath}" | cut -d "." -f 1`
			SDpath="${ArchivePath%/*}"
			tmpname=${ArchivePath##*/}
			oldname=${tmpname%%_tmparchive} 
			name=${oldname%.*}     
			havepoint=`echo ${oldname} | grep "\." | wc -l`
			if [ `echo ${oldname} | grep "\." | wc -l` -eq 0 ]; then
				newname="${name}-backup-`date +%Y.%m.%d.%H%M`"
			else
				subname=${oldname##*.}                                                                            
				newname="${name}-backup-`date +%Y.%m.%d.%H%M`.${subname}"
			fi
			#Rpathname=`echo $ArchivePath | cut -c ${#CmpDirs}-${#ArchivePath}`
			#nobackup=${Rpathname%%$tmpname} 
			#echo "nobackup" "$nobackup"
			mv "${SDpath}/${tmpname}" "${SDpath}/${newname}"
			touch --date="${filetimestamp}" "${SDpath}/${newname}"
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": SDCard_StorageTransfer.sh ReproduceFileBackup" "${SDpath}/${newname}" >> /tmp/backup.log
		done
		rm /tmp/sdArchivePath
	fi
}

timeoffset=`cat /etc/timezone_offset`
if [ "$timeoffset" == "" ]; then
	timeoffset=-8
fi

timeoffset_hour=`echo ${timeoffset} | cut -d '.' -f1`
timeoffset_min_string=`echo ${timeoffset} | cut -s -d '.' -f2`

if [ "${timeoffset_min_string}" != "" ];then
	timeoffset_min=`dc .${timeoffset_min_string} 60 mul p`
else
	timeoffset_min=0
fi

if [ ${timeoffset_hour} -lt 0 ]; then
	timeoffset_string=`printf %03d%02d ${timeoffset_hour} ${timeoffset_min}`
else
	timeoffset_string="+"`printf %02d%02d ${timeoffset_hour} ${timeoffset_min}`
fi

if [ ${timeoffset_string} == "" ]; then
	timeoffset_string="+0000"
fi

timeoffset_seconds=`dc ${timeoffset} 60 mul 60 mul p`

timecommand="date "+%Y-%m-%d/T%H.%M.%S${timeoffset_string}" -uD '%s' -d "$(( `date -u +%s`+${timeoffset_seconds} ))""
timestamp=`eval $timecommand`
timestampDBG="${timestamp}"

echo $timestampDBG ": SDCard_StorageTransfer.sh" $@ >> /tmp/backup.log

echo status=waiting > /tmp/transfer_state
echo "total_size_in_bytes=1024" > /tmp/transfer_size_total
echo "transferred_size_in_bytes=0" > /tmp/transfer_size
echo 0 > /tmp/transferExistSize
echo 0 > /tmp/transferDoneSize

sharename="${1}"
backmethod="${2}"

if [ "$backmethod" == "" ]; then
	method=${TransferMode}
else
	method=$backmethod
fi

StorageVendor=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $7}'`
echo "${StorageVendor}" | grep -q -v '[A-Za-z0-9]'
if [ $? == 0 ]; then
	StorageVendor=SDCard
fi
StorageProduct=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $1}' | sed -e 's/\ //g'`
SerialNum=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $6}' | cut -d ' ' -f 2 | awk -F_ '{print $1}'`
len=${#SerialNum}
if [ "${len}" -ge 4 ]; then
	startword=`expr ${#SerialNum} - 4`
else
	startword=1
fi
StorageSerial=`echo "${SerialNum}" | cut -c $startword-$len`
CID="${StorageVendor}"" ${StorageProduct}"" ${StorageSerial}"

ImportDIR="/shares/Storage/${SD_BACKUP_ROOT}/${timestamp}"
SDcard="/shares/Storage/${SD_BACKUP_ROOT}/${timestamp}/${CID}"

if [ -f "/tmp/runningBackupDst" ]; then
	rm /tmp/runningBackupDst
fi

if [ ! -d "/shares/Storage/SD Card Imports" ]; then
	mkdir -p "/shares/Storage/${SD_BACKUP_ROOT}"
	chmod -R 777 "/shares/Storage/${SD_BACKUP_ROOT}"
fi

SD_MOUNT=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $3}'`
dev_node=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $4}'`
isFAT32=`blkid "${dev_node}" | grep vfat | wc -l`

ModeAuth=`cat /proc/mounts | grep "${SD_MOUNT}" | awk '{print $4}' | awk -F, '{print $1}'`
if [ "$ModeAuth" == "ro" ]; then
	ReadOnly=1
fi

echo $timestampDBG ": SD_StorageTransfer.sh ReadOnly" $ModeAuth $ReadOnly "isFAT32" ${isFAT32} >> /tmp/backup.log
####KORRA+ remove move option, so for all operaions only support copy#####
if [ "$method" == "move" ]; then
	method=copy
fi

if [ "$method" == "move" ] || [ "$method" == "copy" ] || [ "$method" == "copy_all" ]; then
	if [ "$method" == "copy_all" ]; then
		needCompare=0
	else
		needCompare=1
	fi
	
	if [ ! -d "${SDcard}" ]; then
		mkdir -p "${SDcard}"
		newCreate=1
	fi
fi
	
/usr/local/sbin/storage_transfer_LED_status.sh starting
echo "TransferStatus=process" > /etc/nas/config/sdcard-transfer-status.conf
/usr/local/sbin/incUpdateCount.pm storage_transfer &

retry_size=3
while [ "${total_size}" == 0 ]
do
	#total_size=`rsync -rvn "${SD_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
	total_size=`/bin/du -s -b "${SD_MOUNT}" | awk '{print $1}'`
	#echo $timestampDBG ": SD_StorageTransfer.sh get capacity:" ${CapacityCal} >> /tmp/backup.log
	#total_size=`expr "${CapacityCal}" \* 1024`
	#echo $timestampDBG ": SD_StorageTransfer.sh get total_size:" ${total_size} >> /tmp/backup.log

	if [ "$total_size" == "" ] && [ "$total_size" == "0" ]; then
		if [ "$retry_size" == 0 ]; then
			break
		fi
		retry_size=`expr $retry_size - 1`
		sleep 10
	fi
done

if [ "$total_size" != "" ] && [ "$total_size" != "0" ]; then
	sed -i 's/total_size_in_bytes=.*/total_size_in_bytes='${total_size}'/' /tmp/transfer_size_total

else
	/usr/local/sbin/sendAlert.sh 1607 "${StorageProduct}" "${SerialNum}" &
	echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
	killall rsync > /dev/null 2>&1
	removeTempfile
	echo "status=failed" > /tmp/transfer_state
	echo "42;125;" > /tmp/MCU_Cmd
	echo $timestampDBG ": SD_StorageTransfer.sh get wrong capacity:" ${total_size} >> /tmp/backup.log
	USB_BackupQueueCheck
	exit 1
fi

	#rsync -rv "${SDcard}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp' > /tmp/backedupsize
/bin/du -s -b "${SDcard}" | awk '{print $1}' > /tmp/backedupsize
echo "${SDcard}" > /tmp/runningBackupDst
removeTempfile
echo "status=running" > /tmp/transfer_state	
/sbin/CalTransfer.sh > /dev/null 2>&1 &
		
if [ "${needCompare}" == "1" ]; then
	find "/shares/Storage/${SD_BACKUP_ROOT}" -type d -maxdepth 3 -name "${CID}" > /tmp/DoneFolder ##Search for already existing backup folder
	cat /tmp/DoneFolder | while read DoneFolders
	do
		if [ "${SDcard}" == "${DoneFolders}" ] && [ "$newCreate" == "1" ]; then
			filenum=`ls -al "${SDcard}" | wc -l`
			if [ "$filenum" -eq 1 ]; then
				continue	
			fi
		fi
		AllDir="$AllDir"" "\""${DoneFolders}"/\"
		echo "$AllDir" > /tmp/AllCmpDir
	done

	cat /tmp/DoneFolder | while read DoneFolders
	do
		CmpDirs="${DoneFolders}"
		if [ "${SDcard}" == "${CmpDirs}" ] && [ "$newCreate" == "1" ]; then
			continue
		fi
		if [ $isFAT32 -eq 1 ]; then
			execmd="nice -n -19 rsync -ahnrvvP --iconv=UTF-8 --size-only --existing --modify-window=1 \"${SD_MOUNT}\"/ \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
		else
			execmd="nice -n -19 rsync -ahnrvvP --iconv=UTF-8 --existing --modify-window=1 \"${SD_MOUNT}\"/ \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
		fi

		#echo $timestampDBG ": SDCard_StorageTransfer.sh rsync find conflict list:" $execmd >> /tmp/backup.log
		eval "$execmd"
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			echo $timestampDBG ": SDCard_StorageTransfer.sh rsync Error find conflict list:" $execmd "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			RuningStatus=1
			break
		fi
		exist=`cat /tmp/transferExistSize`
	done

	if [ -f "/tmp/RsyncConfliclist" ]; then
		cat /tmp/RsyncConfliclist | grep "NON_CONFLICT" | uniq | while read existfname
		do
			existfile=`echo "$existfname" | awk 'BEGIN{FS="NON_CONFLICT: " } {print $NF}' | awk 'BEGIN{FS='\"${SD_MOUNT}/\"' } {print $NF}'`
			#fname=`echo ${existfile} | awk 'BEGIN{FS='\"${SD_MOUNT}/\"' } {print $NF}'`
			echo $existfile >> /tmp/rsyncExcludefile
		done
	fi

	if [ ! -f "/tmp/rsyncExcludefile" ]; then
		touch /tmp/rsyncExcludefile
	fi

	cat /tmp/DoneFolder | while read DoneFolders
	do
		CmpDirs="${DoneFolders}"
		if [ "${SDcard}" == "${CmpDirs}" ] && [ "$newCreate" == "1" ]; then
			continue
		fi
		if [ $isFAT32 -eq 1 ]; then
			execmd="nice -n -19 rsync -ahrP --iconv=UTF-8 --size-only --existing --chmod=a+rwx --modify-window=1 --info=progress2 --exclude-from=/tmp/rsyncExcludefile --backup --backup-dir=\""${SDcard}"\" \""${SD_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
		else
			execmd="nice -n -19 rsync -ahrP --iconv=UTF-8 --existing --chmod=a+rwx --modify-window=1 --info=progress2 --exclude-from=/tmp/rsyncExcludefile --backup --backup-dir=\""${SDcard}"\" \""${SD_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
		fi
		#echo $timestampDBG ": SDCard_StorageTransfer.sh rsync find conflict list:" $execmd >> /tmp/backup.log
		eval "$execmd"
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			echo $timestampDBG ": SDCard_StorageTransfer.sh rsync Error compared with existing:" $execmd "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			RuningStatus=1
			break
		fi
		if [ "${backupTest}" == "0" ]; then
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			#echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
			done
			echo $timestampDBG ": SDCard_StorageTransfer.sh compared existing" $exist $transferDoneSize >> /tmp/backup.log
			echo 0 > /tmp/transferExistSize	
		fi
		#ReproduceFileBackup "${CmpDirs}"
	done

#YC add for performance test
SYNC_START=$(date +%s)
echo "SYNC_START $SYNC_START"
	if [ -f "/tmp/AllCmpDir" ]; then
		AllCmpDirs=`cat /tmp/AllCmpDir`
		if [ $isFAT32 -eq 1 ]; then
			RsyncExecmd="rsync -avun --size-only --iconv=UTF-8 --ignore-existing --modify-window=1 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
		else
			RsyncExecmd="rsync -avun --modify-window=1 --ignore-existing --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
		fi
		#echo $timestampDBG ": SDCard_StorageTransfer.sh rsync delete" $RsyncExecmd >> /tmp/backup.log
		eval "$RsyncExecmd"	
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			RuningStatus=5
			echo $timestampDBG ": SDCard_StorageTransfer.sh rsync Error:" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
		fi

		cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR" | while read backupfile
		do
			backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_DIR " } {print $NF}'`
			ori_backupfile=$backupfile
			echo "$backupfile" > /tmp/kkk
			sed -i 's/`/\\`/g' /tmp/kkk
			sed -i 's/\$/\\$/g' /tmp/kkk
			backupfile=`cat /tmp/kkk`
			#checkexist=`cat /tmp/rsyncExcludefile | grep -w "$backupfile" | wc -l`
			#echo "checkexist" $checkexist "backupfile" $backupfile
			#if [ "${checkexist}" != "0" ]; then
			#	continue
			#fi
			#echo $timestampDBG ": SDCard_StorageTransfer.sh DIR backupfile" $backupfile >> /tmp/backup.log
			if [ -d ""${SD_MOUNT}"/${ori_backupfile}" ] && [ ! -d "${SDcard}/${backupfile}" ]; then
				fname=`dirname "${SDcard}"\/"${backupfile}"`
				if [ ! -d "${fname}" ]; then
					execmd="mkdir -p \"${fname}\""
					eval "$execmd"
				fi
				if [ "$method" == "move" ]; then
					execmd="mv -f \""${SD_MOUNT}"/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
				else
					execmd="cp -a \""${SD_MOUNT}"/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
				fi
				#echo $timestampDBG ": SDCard_StorageTransfer.sh DIR Cp cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=9
					echo $timestampDBG ": SDCard_StorageTransfer.sh cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					break
				fi
			fi
		done
				
		cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile
		do
			backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_ITEM " } {print $NF}'`
			echo "$backupfile" > /tmp/kkk
			sed -i 's/`/\\`/g' /tmp/kkk
			sed -i 's/\$/\\$/g' /tmp/kkk
			backupfile=`cat /tmp/kkk`
			#checkexist=`cat /tmp/rsyncExcludefile | grep -w "$backupfile" | wc -l`
			#echo "checkexist" $checkexist "backupfile" $backupfile
			#if [ "${checkexist}" != "0" ]; then
			#	continue
			#fi
			#echo $timestampDBG ": SDCard_StorageTransfer.sh ITEM:" $backupfile >> /tmp/backup.log
			if [ -d ""${SD_MOUNT}"/${backupfile}" ] && [ ! -d "${SDcard}/${backupfile}" ]; then
				#mkdir -p "${SDcard}"\/"${backupfile}"
				execmd="mkdir -p "${SDcard}"\/"${backupfile}""
				#echo $timestampDBG ": SDCard_StorageTransfer.sh ITEM make cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
			else
				fname=`dirname "${SDcard}"\/"${backupfile}"`
				if [ ! -d "${fname}" ]; then
					execmd="mkdir -p \"${fname}\""
					eval "$execmd"
				fi
				if [ ! -d "${SDcard}/${backupfile}" ] && [ ! -f "${SDcard}/${backupfile}" ]; then
					if [ "$method" == "move" ]; then
						execmd="mv -f \""${SD_MOUNT}"/${backupfile}\" \"${SDcard}/${backupfile}\" > /dev/null 2>&1"
					else
						execmd="cp -a \""${SD_MOUNT}"/${backupfile}\" \"${SDcard}/${backupfile}\" > /dev/null 2>&1"
					fi
					#echo $timestampDBG ": SDCard_StorageTransfer.sh ITEM Cp cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=13
						echo $timestampDBG ": SDCard_StorageTransfer.sh cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
						break
					fi
					#echo "execmd" "$execmd"
				fi
			fi
		done

		if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
			echo $timestampDBG ": SDCard_StorageTransfer.sh No backup ITEM" >> /tmp/backup.log
			filenum=`ls -al "${SDcard}" | wc -l`
			if [ "$filenum" -eq 1 ]; then
				#finishSdBackup
				rm -rf "${SDcard}"	
			fi
			filenum=`ls -al "${ImportDIR}" | wc -l`
			if [ "$filenum" -eq 1 ]; then
				#finishSdBackup
				rm -rf "${ImportDIR}"	
			fi
		fi
	else
		if [ "$method" == "move" ]; then
			execmd="mv -f "${SD_MOUNT}"/.[^.]* \"${SDcard}/\" > /dev/null 2>&1"
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
			eval "$execmd"
			
			filenum=`ls "${SD_MOUNT}"/ | wc -l`
			if [ "${filenum}" != 0 ]; then
				execmd="mv -f "${SD_MOUNT}"/* \"${SDcard}/\" > /dev/null 2>&1"
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=20
					echo $timestampDBG ": SDCard_StorageTransfer.sh cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					break
				fi	
			fi
		else
			execmd="cp -a "${SD_MOUNT}"/.[^.]* \"${SDcard}/\" > /dev/null 2>&1"
			eval "$execmd"
			filenum=`ls "${SD_MOUNT}"/ | wc -l`
			if [ "${filenum}" != 0 ]; then
				execmd="cp -a "${SD_MOUNT}"/* \"${SDcard}/\" > /dev/null 2>&1"
				eval "$execmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=16
					echo $timestampDBG ": SDCard_StorageTransfer.sh cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
				fi
			fi
		fi
	fi
elif [ "$method" == "copy_all" ]; then
SYNC_START=$(date +%s)
echo "SYNC_START $SYNC_START"
	execmd="cp -a "${SD_MOUNT}"/.[^.]* \"${SDcard}/\" > /dev/null 2>&1"
	eval "$execmd"
	filenum=`ls "${SD_MOUNT}"/ | wc -l`
	if [ "${filenum}" != 0 ]; then
		execmd="cp -a "${SD_MOUNT}"/* \"${SDcard}/\" > /dev/null 2>&1"
		eval "$execmd"
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			RuningStatus=16
			echo $timestampDBG ": SDCard_StorageTransfer.sh cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
		fi
	fi
fi
	
#YC add for performance test
SYNC_END=$(date +%s)
echo "SYNC_END $SYNC_END"
DIFF=$(( $SYNC_END - $SYNC_START ))
echo "SYNC took $DIFF seconds"

removeTempfile
if [ -d "${ImportDIR}" ]; then
	execmd="chmod -R 777 \"${ImportDIR}/\""
fi
eval "$execmd"
echo $timestampDBG ": SDCard_StorageTransfer.sh change attribute" $execmd >> /tmp/backup.log
if [ "${RuningStatus}" != "0" ]; then
	chmod -R 777 "/shares/Storage/${SD_BACKUP_ROOT}"
	/usr/local/sbin/sendAlert.sh 1605 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
	echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
	sync
	sync
	sync
	if [ -f /tmp/SDCard_Process_Canceled ]; then
		echo "status=canceled" > /tmp/transfer_state
		rm -f /tmp/SDCard_Process_Canceled
	else
		echo "status=failed" > /tmp/transfer_state
	fi
	echo "42;125;" > /tmp/MCU_Cmd
	USB_BackupQueueCheck
	exit 1
fi	


echo ${CID} > /media/sdb1/.wdcache/.${SerialNum}
finishSdBackup

sync
sync
sync

#sleep 1
USB_BackupQueueCheck

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


