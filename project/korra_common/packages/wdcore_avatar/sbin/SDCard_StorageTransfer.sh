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
RuningStatus=0
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
timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestampDBG ": SDCard_StorageTransfer.sh" $@ >> /tmp/backup.log

echo 0 > /tmp/SDStatusError
echo status=waiting > /tmp/transfer_state
echo "total_size_in_bytes=1024" > /tmp/transfer_size_total
echo "transferred_size_in_bytes=0" > /tmp/transfer_size
echo 0 > /tmp/transferExistSize
echo 0 > /tmp/transferDoneSize

sctool `cat /tmp/SDDevNode`

sharename="${1}"
backmethod="${2}"

function finishSdBackup()
{
	#/sbin/AdaptCPUfreq.sh endbackup
	removeTempfile
	/usr/local/sbin/sendAlert.sh 1609 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
	echo "42;100" > /tmp/MCU_Cmd
	total=`cat /tmp/transfer_size_total | sed -n '1p' | sed -n 's/.*=//p'` 
	echo "transferred_size_in_bytes=${total}" > /tmp/transfer_size
	echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
	sed -i "s/status=.*/status=completed/" /tmp/transfer_state
	#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestampDBG ": SDCard_StorageTransfer.sh Complete!!" >> /tmp/backup.log
	/usr/local/sbin/storage_transfer_status.sh > /dev/null 2>&1 &
	#chmod -R 777 "/shares/Storage/SD Card Imports"
}

function USB_BackupQueueCheck()
{
	#check USB backup process
	USB_backup=`cat /etc/nas/config/usb-transfer-status.conf | awk -F= '{print $NF}'`
	usbstandby=`echo "${USB_backup}" | awk -F: '{print $1}'`
	#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestampDBG ": SDCard_StorageTransfer.sh USB_BackupQueueCheck" $usbstandby >> /tmp/backup.log
	sleep 20
	if [ "$usbstandby" == "standby" ]; then
		triggerMode=`echo "${USB_backup}" | awk -F: '{print $2}'`
		
		if [ "${triggerMode}" == "Button" ]; then
			/sbin/ButtonStorageTransfer.sh USB
		elif [ "${triggerMode}" == "Auto" ]; then
			/sbin/USB_AutoStorageTransfer.sh
		else
			/sbin/ButtonStorageTransfer.sh USB
		fi
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
	elif [ "$usbstandby" == "checkin" ]; then
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		/sbin/ButtonStorageTransfer.sh USB 2>&1 &
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
}
#timestamp=$(date "+%m-%d-%Y-%H%M")
#timestamp=$(date "+%Y-%m-%d")
timeoffset=`cat /etc/timezone_offset`
if [ "$timeoffset" == "" ]; then
	timeoffset=0
fi

timecommand="date "+%Y-%m-%d" -uD '%s' -d "$(( `date -u +%s`+${timeoffset}*60*60 ))""
timestamp=`eval $timecommand`

StorageVendor=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $7}'`
echo "${StorageVendor}" | grep -q -v '[A-Za-z0-9]'
if [ $? == 0 ]; then
	StorageVendor=SDCard
fi
StorageProduct=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $1}' | sed -e 's/\ //g'`
SerialNum=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $6}' | cut -d ' ' -f 2 | awk -F_ '{print $1}'`
#StorageSerial=`echo "${SerialNum}" | cut -c 1-6`
len=${#SerialNum}
if [ "${len}" -ge 4 ]; then
	startword=`expr ${#SerialNum} - 4`
else
	startword=1
fi
StorageSerial=`echo "${SerialNum}" | cut -c $startword-$len`
CID="${StorageVendor}"" ${StorageProduct}"" ${StorageSerial}"	
fullCID=$SerialNum

#if [ -d /media/sdb1_fuse ]; then
#	ImportDIR="/media/sdb1_fuse/SD Card Imports/${CID}"
#    SDcard="/media/sdb1_fuse/SD Card Imports/${CID}/${timestamp}"
#else
#	ImportDIR="/media/sdb1/SD Card Imports/${CID}"
#    SDcard="/media/sdb1/SD Card Imports/${CID}/${timestamp}"
#fi
  ImportDIR="/shares/Storage/SD Card Imports/${timestamp}"
  SDcard="/shares/Storage/SD Card Imports/${timestamp}/${CID}"
  
if [ "$backmethod" == "" ]; then
	method=${TransferMode}
else
	method=$backmethod
fi

if [ ! -d "/shares/Storage/SD Card Imports" ]; then
    mkdir -p "/shares/Storage/SD Card Imports"
    chmod -R 777 "/shares/Storage/SD Card Imports"
fi

if [ -f "/tmp/runningBackupDst" ]; then
	rm /tmp/runningBackupDst
fi


SD_MOUNT=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $3}'`
dev_node=`cat /tmp/mmcblk0*-info | grep "${sharename}" | awk -F: '{print $4}'`
chknode=`blkid "${dev_node}"`
isFAT32=`blkid "${dev_node}" | grep vfat | wc -l`
ModeAuth=`cat /proc/mounts | grep "${SD_MOUNT}" | awk '{print $4}' | awk -F, '{print $1}'`
if [ "$ModeAuth" == "ro" ]; then
	ReadOnly=1
fi

#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestampDBG ": SD_StorageTransfer.sh ReadOnly" $ModeAuth $ReadOnly >> /tmp/backup.log


if [ "$method" == "move" ] || [ "$method" == "copy" ]; then
	if [ ! -d "${SDcard}" ]; then
		mkdir -p "${SDcard}"
		chmod -R 777 "${ImportDIR}"
		chmod -R 777 "${SDcard}"
		newCreate=1
	fi
	if [ `ps aux | grep rsync | grep "$SD_MOUNT" | wc -l` -ne 0 ] && [ `cat /etc/nas/config/sdcard-transfer-status.conf | grep process | wc -l` -ne 0 ]; then
		rm -rf "${SDcard}"
		#killall rsync
		echo "18;0;" > /tmp/MCU_Cmd 
		removeTempfile
		#sleep 10
		USB_BackupQueueCheck
		exit 1
	fi
	
	/usr/local/sbin/storage_transfer_LED_status.sh starting
	echo "TransferStatus=process" > /etc/nas/config/sdcard-transfer-status.conf
	/usr/local/sbin/incUpdateCount.pm storage_transfer &
	total_size=`rsync -rv "${SD_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
	#totalDF=`df | grep "${SD_MOUNT}" | awk '{print $3}'`
	#total_size=`expr "${totalDF}" \* 1024`
    if [ $? -eq 0 ]; then
    	if [ "$total_size" != "" ] && [ "$total_size" != "0" ]; then
		    sed -i 's/total_size_in_bytes=.*/total_size_in_bytes='${total_size}'/' /tmp/transfer_size_total
        elif [ "$total_size" == "" ]; then
        	sleep 5
        	total_size=`rsync -rv "${SD_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
        	sed -i 's/total_size_in_bytes=.*/total_size_in_bytes='${total_size}'/' /tmp/transfer_size_total
        fi 
    else
    	/usr/local/sbin/sendAlert.sh 1607 &
    	#echo "18;0;" > /tmp/MCU_Cmd
    	echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
    	killall rsync > /dev/null 2>&1
    	removeTempfile
        
        echo "status=failed" > /tmp/transfer_state
        echo "42;125;" > /tmp/MCU_Cmd
        #/sbin/AdaptCPUfreq.sh endbackup
        #sleep 10
        USB_BackupQueueCheck
        exit 1
    fi
	rsync -rv "${SDcard}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp' > /tmp/backedupsize
	echo "${SDcard}" > /tmp/runningBackupDst
	removeTempfile
	echo "status=running" > /tmp/transfer_state	
	#/sbin/AdaptCPUfreq.sh startbackup	
	/sbin/CalTransfer.sh > /dev/null 2>&1 &
	find "/shares/Storage/SD Card Imports" -name "${CID}" > /tmp/DoneFolder
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
	
	if [ "$method" == "move" ]; then
		cat /tmp/DoneFolder | while read DoneFolders
		do
			CmpDirs="${DoneFolders}"
			if [ $isFAT32 -eq 1 ]; then
				RsyncExecmd="nice -n -19 rsync -ahP --size-only --info=progress2 --existing --backup --modify-window=1 --suffix=_tmparchive \""${SD_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
			else
				RsyncExecmd="nice -n -19 rsync -ahP --existing --backup --info=progress2 --suffix=_tmparchive \""${SD_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
			fi
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": SDCard_StorageTransfer.sh rsync existing:" $RsyncExecmd >> /tmp/backup.log
			eval "$RsyncExecmd"
			if [ $? != 0 ]; then
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestampDBG ": SDCard_StorageTransfer.sh rsync existing:" $RsyncExecmd >> /tmp/backup.log
				echo $timestampDBG ": SDCard_StorageTransfer.sh Error 1" >> /tmp/backup.log
				echo "1" > /tmp/SDStatusError
				break
			fi
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist $divide >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
			done
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh out Loop" $exist $transferDoneSize >> /tmp/backup.log
			cat /tmp/transferExistSize > /tmp/transferDoneSize
			echo 0 > /tmp/transferExistSize
			ReproduceFileBackup "${CmpDirs}"
		done
		if [ -f "/tmp/AllCmpDir" ]; then
			AllCmpDirs=`cat /tmp/AllCmpDir`		
			if [ $isFAT32 -eq 1 ]; then
				RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			else 
				RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			fi
			if [ "$RsyncExecmd" != "" ]; then
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestampDBG ": SDCard_StorageTransfer.sh rsync delete:" $RsyncExecmd >> /tmp/backup.log
				eval "$RsyncExecmd"
			fi
		
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_DIR " } {print $NF}'`
				ori_backupfile=$backupfile
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh DIR backupfile:" $backupfile >> /tmp/backup.log
				if [ -d ""${SD_MOUNT}"/${ori_backupfile}" ] && [ ! -d "${SDcard}/${backupfile}" ]; then
					fname=`dirname "${SDcard}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
						#echo "create" "$fname"
					fi
					execmd="mv -f \"${SD_MOUNT}/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
				fi
			done
			
			cat /tmp/DoneFolder | while read DoneFolders
			do
				AllDir="$AllDir"" "\""${DoneFolders}"/\"
				echo "$AllDir" > /tmp/AllCmpDir
			done
			AllCmpDirs=`cat /tmp/AllCmpDir`
			if [ $isFAT32 -eq 1 ]; then
				RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			else
				RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			fi
			eval "$RsyncExecmd"	
		
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_ITEM " } {print $NF}'`
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh ITEM backupfile:" $backupfile >> /tmp/backup.log
				fname=`dirname "${SDcard}"\/"${backupfile}"`
				if [ ! -d "${fname}" ]; then
					mkdir -p "${fname}"
					chmod -R 777 "${fname}"
					#echo "create" "$fname"
				fi
				if [ ! -d "${SDcard}/${backupfile}" ] && [ ! -f "${SDcard}/${backupfile}" ]; then
					execmd="mv -f \"${SD_MOUNT}/${backupfile}\" \"${SDcard}/${backupfile}\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
					if [ $? != 0 ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
						echo $timestampDBG ": SDCard_StorageTransfer.sh Error 2" >> /tmp/backup.log
						echo "1" > /tmp/SDStatusError
						break
					fi	
				fi
			done
			if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
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
				if [ $? != 0 ]; then		
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestampDBG ": SDCard_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
					echo $timestampDBG ": SDCard_StorageTransfer.sh Error 3" >> /tmp/backup.log
					echo "1" > /tmp/SDStatusError
				fi
			fi
		fi		
		
		removeTempfile
		RuningStatus=`cat /tmp/SDStatusError`
		if [ "${RuningStatus}" -eq 0 ]; then
			`rm -rf "${SD_MOUNT}"/*`
			chmod -R 777 "/shares/Storage/SD Card Imports"
		else
			chmod -R 777 "/shares/Storage/SD Card Imports"
			if [ "$ReadOnly" == "1" ]; then
				/usr/local/sbin/sendAlert.sh 1611 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
			else	
				/usr/local/sbin/sendAlert.sh 1605 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
			fi
			#/sbin/AdaptCPUfreq.sh endbackup
			#killall rsync > /dev/null 2>&1
			#echo "18;0;" > /tmp/MCU_Cmd
			echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
			sync
        	sync
        	sync
            if [ -f /tmp/SDCard_Process_Canceled ]; then
            	echo "status=canceled" > /tmp/transfer_state
                rm -f /tmp/SDCard_Process_Canceled
            else
            	if [ "$ReadOnly" == "1" ]; then
			    	echo "status=SdReadOnlyfailed" > /tmp/transfer_state
			    else
			    	echo "status=failed" > /tmp/transfer_state
			    fi
            fi
            echo "42;125;" > /tmp/MCU_Cmd
			#sleep 10
			USB_BackupQueueCheck
			exit 1
		fi
	fi	
	if [ "$method" == "copy" ]; then
    	cat /tmp/DoneFolder | while read DoneFolders
		do
			CmpDirs="${DoneFolders}"
			if [ $isFAT32 -eq 1 ]; then
				execmd="nice -n -19 rsync -ah --size-only --existing --backup --modify-window=1 --suffix=_tmparchive \"${SD_MOUNT}\"/ \"${CmpDirs}\" > /dev/null 2>&1"
			else
				execmd="nice -n -19 rsync -ah --existing --backup --suffix=_tmparchive \"${SD_MOUNT}\"/ \"${CmpDirs}\" > /dev/null 2>&1"
			fi
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": SDCard_StorageTransfer.sh rsync existing" $execmd >> /tmp/backup.log
			eval "$execmd"
			if [ $? != 0 ]; then
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestampDBG ": SDCard_StorageTransfer.sh rsync existing" $execmd >> /tmp/backup.log
				echo $timestampDBG ": SDCard_StorageTransfer.sh Error 4" >> /tmp/backup.log
				echo "1" > /tmp/SDStatusError
				break
			fi
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist $divide >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
				#sleep 5
				#touch /tmp/getStorageTransferStatus
			done
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh out Loop" $exist $transferDoneSize >> /tmp/backup.log
			echo 0 > /tmp/transferExistSize
			ReproduceFileBackup "${CmpDirs}"				
		done
#YC add for performance test
SYNC_START=$(date +%s)
echo "SYNC_START $SYNC_START" >> /tmp/backup.log
        if [ -f "/tmp/AllCmpDir" ]; then
			AllCmpDirs=`cat /tmp/AllCmpDir`		
			if [ $isFAT32 -eq 1 ]; then
				RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			else
				RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			fi
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh rsync delete" $RsyncExecmd >> /tmp/backup.log
			eval "$RsyncExecmd"	
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_DIR " } {print $NF}'`
				ori_backupfile=$backupfile
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh DIR backupfile" $backupfile >> /tmp/backup.log
				if [ -d ""${SD_MOUNT}"/${ori_backupfile}" ] && [ ! -d "${SDcard}/${backupfile}" ]; then
					fname=`dirname "${SDcard}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
						#echo "create" "$fname"
					fi
					#echo "create" "${SDcard}"\/"${backupfile}"
					execmd="cp -a \""${SD_MOUNT}"/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": SDCard_StorageTransfer.sh Cp cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
				fi
			done
			
			cat /tmp/DoneFolder | while read DoneFolders
			do
				AllDir="$AllDir"" "\""$DoneFolders"/\"
				echo "$AllDir" > /tmp/AllCmpDir
			done
			AllCmpDirs=`cat /tmp/AllCmpDir`		
			if [ $isFAT32 -eq 1 ]; then
				RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			else
				RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${SD_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			fi
			eval "$RsyncExecmd"	
				
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_ITEM " } {print $NF}'`
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh ITEM:" $backupfile >> /tmp/backup.log
				if [ -d ""${SD_MOUNT}"/${backupfile}" ] && [ ! -d "${SDcard}/${backupfile}" ]; then
					mkdir -p "${SDcard}"\/"${backupfile}"
					chmod -R 777 "${SDcard}"\/"${backupfile}"
					#echo "create" "${SDcard}"\/"${backupfile}"
				else
					fname=`dirname "${SDcard}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
						#echo "create" "$fname"
					fi
					if [ ! -d "${SDcard}/${backupfile}" ] && [ ! -f "${SDcard}/${backupfile}" ]; then
						execmd="cp -a \""${SD_MOUNT}"/${backupfile}\" \"${SDcard}/${backupfile}\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						eval "$execmd"
						if [ $? != 0 ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": SDCard_StorageTransfer.sh Cp cmd:" $execmd >> /tmp/backup.log
							echo $timestampDBG ": SDCard_StorageTransfer.sh Error 5" >> /tmp/backup.log
							echo "1" > /tmp/SDStatusError
							break
						fi
						#echo "execmd" "$execmd"
					fi
				fi
			done
			if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
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
        	execmd="cp -a "${SD_MOUNT}"/.[^.]* \"${SDcard}/\" > /dev/null 2>&1"
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": SDCard_StorageTransfer.sh Cp cmd:" $execmd >> /tmp/backup.log
			eval "$execmd"
			
			filenum=`ls "${SD_MOUNT}"/ | wc -l`
			if [ "${filenum}" != 0 ]; then
				execmd="cp -a "${SD_MOUNT}"/* \"${SDcard}/\" > /dev/null 2>&1"
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": SDCard_StorageTransfer.sh Cp cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
				if [ $? != 0 ]; then
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestampDBG ": SDCard_StorageTransfer.sh Cp cmd:" $execmd >> /tmp/backup.log
					echo $timestampDBG ": SDCard_StorageTransfer.sh Error 6" >> /tmp/backup.log
					echo "1" > /tmp/SDStatusError
            	fi
            fi
		fi
#YC add for performance test
SYNC_END=$(date +%s)
echo "SYNC_END $SYNC_END" >> /tmp/backup.log
DIFF=$(( $SYNC_END - $SYNC_START ))
echo "SYNC took $DIFF seconds" >> /tmp/backup.log

		RuningStatus=`cat /tmp/SDStatusError`
		if [ "${RuningStatus}" -eq 0 ]; then
			`chmod -R 777 "/shares/Storage/SD Card Imports"`
		else
			chmod -R 777 "/shares/Storage/SD Card Imports"
			/usr/local/sbin/sendAlert.sh 1605 "${StorageVendor}" "${StorageProduct}" "${SerialNum}" &
			#echo "18;0;" > /tmp/MCU_Cmd
			echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
			
            if [ -f /tmp/SDCard_Process_Canceled ]; then
            	echo "status=canceled" > /tmp/transfer_state
                rm -f /tmp/SDCard_Process_Canceled
            else
                echo "status=failed" > /tmp/transfer_state
            fi
            echo "42;125;" > /tmp/MCU_Cmd
			#/sbin/AdaptCPUfreq.sh endbackup
			#killall rsync > /dev/null 2>&1
			#sleep 10
			USB_BackupQueueCheck
				
			exit 1
		fi    		
	fi
fi

echo ${CID} > /media/sdb1/.wdcache/.${fullCID}
#echo ${CID} > /media/sdb1/SD\ Card\ Imports/${CID}/${timestamp}/.${fullCID}
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


