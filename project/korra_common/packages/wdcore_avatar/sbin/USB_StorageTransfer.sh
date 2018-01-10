#!/bin/bash
#
# USB_StorageTransfer.sh
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
total_size=0
USB_BACKUP_ROOT="USB Imports"
USB_MOUNT=/media/USB
MTPfolder="/media/USB/DCIM"
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
	
	if [ -f "/tmp/USB_AutoProcessing" ]; then
		rm /tmp/USB_AutoProcessing
	fi

	if [ -f "/tmp/USB_ButtonProcessing" ]; then
		rm /tmp/USB_ButtonProcessing
	fi

	if [ -f "/tmp/RsyncConfliclist" ]; then
		rm /tmp/RsyncConfliclist
	fi
	
	if [ -f "/tmp/rsyncExcludefile" ]; then
		rm /tmp/rsyncExcludefile
	fi
}

function finishBackup()
{
	removeTempfile
	/usr/local/sbin/sendAlert.sh "1610" "${StorageProduct}" "${SerialNum}" &
	echo "42;100" > /tmp/MCU_Cmd
	echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
	echo $timestampDBG ": USB_StorageTransfer.sh Completed !" >> /tmp/backup.log
	echo "transferred_size_in_bytes=${total_size}" > /tmp/transfer_size
	sed -i "s/status=.*/status=completed/" /tmp/transfer_state
	/usr/local/sbin/storage_transfer_status.sh > /dev/null 2>&1 &
}

function SD_BackupQueueCheck()
{
	SD_status=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
	echo $timestampDBG ": USB_StorageTransfer.sh SD_BackupQueueCheck SD_status:" $SD_status >> /tmp/backup.log
	if [ "${SD_status}" != "completed" ]; then
		sdstandby=`echo "${SD_status}" | awk -F: '{print $1}'`
		echo $timestampDBG ": USB_StorageTransfer.sh SD_BackupQueueCheck sdstandby:" $sdstandby >> /tmp/backup.log
		sleep 20
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		if [ "$sdstandby" == "standby" ]; then
			triggerMode=`echo "${SD_status}" | awk -F: '{print $2}'`
			if [ "${triggerMode}" == "Button" ]; then	
				/sbin/ButtonStorageTransfer.sh SD
			elif [ "${triggerMode}" == "Auto" ]; then
				/sbin/SDCard_AutoStorageTransfer.sh
			else
				/sbin/ButtonStorageTransfer.sh SD
			fi
		elif [ "$sdstandby" == "checkin" ]; then
			/sbin/ButtonStorageTransfer.sh SD 2>&1 &
		fi
	fi
}

function ReproduceFileBackup()
{
	find "${1}" -name "*_tmparchive" > /tmp/usbArchivePath
	ArchiveCount=`cat /tmp/usbArchivePath | grep -c _tmparchive`
	if [ ${ArchiveCount} != 0 ]; then
		for  ((i=1; i<=$ArchiveCount; i=i+1))    
		do
			ArchivePath=`cat /tmp/usbArchivePath | sed -n "${i}p"`
			filetimestamp=`stat -c %y "${ArchivePath}" | cut -d "." -f 1`
			USBpath="${ArchivePath%/*}"
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
			mv "${USBpath}/${tmpname}" "${USBpath}/${newname}"
			touch --date="${filetimestamp}" "${USBpath}/${newname}"
			#echo $timestampDBG ": USB_StorageTransfer.sh ReproduceFileBackup" "${USBpath}/${newname}" >> /tmp/backup.log
		done
		rm /tmp/usbArchivePath
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

echo $timestampDBG ": USB_StorageTransfer.sh" $@ >> /tmp/backup.log

echo status=waiting > /tmp/transfer_state
echo "total_size_in_bytes=1024" > /tmp/transfer_size_total
echo "transferred_size_in_bytes=0" > /tmp/transfer_size
echo 0 > /tmp/transferExistSize
echo 0 > /tmp/transferDoneSize

sharename="${1}"
backmethod="${2}"

if [ "$backmethod" == "" ]; then
	method="${USB_ModeTransfer}"
else
	method=${backmethod}
fi


if [ -f "/tmp/detectInterface" ]; then
	devicefound=`cat /tmp/detectInterface`
	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
		devType="MTP"
		if [ ! -d "/media/USB/DCIM" ]; then
			deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
		fi
	fi
fi

StorageVendor=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $7}'`
echo "${StorageVendor}" | grep -q -v '[A-Za-z0-9]'
if [ $? == 0 ]; then
	StorageVendor=USB
fi

StorageProduct=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $1}' | sed -e 's/\ //g'`
SerialNum=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $6}' | cut -d ' ' -f 2 | awk -F_ '{print $1}'`
len=${#SerialNum}
if [ "${len}" -ge 4 ]; then
	startword=`expr ${#SerialNum} - 4`
else
	startword=1
fi
StorageSerial=`echo "${SerialNum}" | cut -c $startword-$len`
CID="${StorageVendor}"" ${StorageProduct}"" ${StorageSerial}"	

ImportDIR="/shares/Storage/${USB_BACKUP_ROOT}/${timestamp}"
UsbStorage="/shares/Storage/${USB_BACKUP_ROOT}/${timestamp}/${CID}"

if [ -f "/tmp/runningBackupDst" ]; then
	rm -rf /tmp/runningBackupDst
fi

if [ ! -d "/shares/Storage/${USB_BACKUP_ROOT}" ]; then
	mkdir -p "/shares/Storage/${USB_BACKUP_ROOT}"
	chmod -R 777 "/shares/Storage/${USB_BACKUP_ROOT}"
fi

if [ "${devType}" == "MTP" ]; then
	USB_MOUNT="/media/USB"
	deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
else
	USB_MOUNT=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $3}'`
fi
dev_node=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $4}'`
isFAT32=`blkid "${dev_node}" | grep vfat | wc -l`
#echo $timestampDBG ": USB_StorageTransfer.sh isFAT32" $isFAT32 >> /tmp/backup.log

ModeAuth=`cat /proc/mounts | grep "${USB_MOUNT}" | awk '{print $4}' | awk -F, '{print $1}'`
if [ "$ModeAuth" == "ro" ]; then
	ReadOnly=1
fi
echo $timestampDBG ": USB_StorageTransfer.sh ReadOnly:" ${ModeAuth} ${ReadOnly} "isFAT32" ${isFAT32} >> /tmp/backup.log

if [ "$method" == "move" ]; then
	method=copy
fi

if [ "$method" == "move" ] || [ "$method" == "copy" ] || [ "$method" == "copy_all" ]; then
	if [ "$method" == "copy_all" ]; then
		needCompare=0
	else
		needCompare=1
	fi
	if [ ! -d "${UsbStorage}" ]; then
		mkdir -p "${UsbStorage}"
		newCreate=1
	fi
fi
	
/usr/local/sbin/storage_transfer_LED_status.sh starting
echo "USB_TransferStatus=process" > /etc/nas/config/usb-transfer-status.conf
/usr/local/sbin/incUpdateCount.pm storage_transfer &
	
retry_size=3
while [ "${total_size}" == 0 ]
do
	if [ "${devType}" == "MTP" ]; then
		if [ ! -d "/media/USB/DCIM" ]; then
			if [ "${deepfolderNum}" -eq 0 ]; then
				#total_size=`rsync -rvn "/media/USB" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
				total_size=`/bin/du -s -b "/media/USB" | awk '{print $1}'`
				#total_size=`expr "${CapacityCal}" \* 1024`
			else
				for ((dx=1; dx<=deepfolderNum; dx++ )); do
					if [ "${dx}" == 1 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
					elif [ "${dx}" == 2 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
					elif [ "${dx}" == 3 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
					fi
					#temp_total_size=`rsync -rv "${MTPfolder}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
					temp_total_size=`/bin/du -s -b "${MTPfolder}" | awk '{print $1}'`
					#temp_total_size=`expr "${CapacityCal}" \* 1024`
					total_size=`expr ${total_size} + ${temp_total_size}`
				done
			fi
		else
			#total_size=`rsync -rvn "/media/USB/DCIM" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
			total_size=`/bin/du -s -b "${MTPfolder}" | awk '{print $1}'`
			#total_size=`expr "/media/USB/DCIM" \* 1024`
		fi
	else
		#total_size=`rsync -rvn "${USB_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
		total_size=`/bin/du -s -b "${USB_MOUNT}" | awk '{print $1}'`
		#total_size=`expr "${CapacityCal}" \* 1024`
	fi

	if [ "$total_size" == "" ] || [ "$total_size" == "0" ]; then
		echo $timestampDBG ": USB_StorageTransfer.sh get wrong capacity:" ${total_size} >> /tmp/backup.log
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
	/usr/local/sbin/sendAlert.sh 1608 "${StorageProduct}" "${SerialNum}" &
	echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
	killall rsync > /dev/null 2>&1
	removeTempfile
	echo "status=failed" > /tmp/transfer_state
	echo "42;125;" > /tmp/MCU_Cmd
	echo $timestampDBG ": USB_StorageTransfer.sh get wrong capacity:" ${total_size} >> /tmp/backup.log
	SD_BackupQueueCheck
	exit 1
fi

    
/bin/du -s -b "${UsbStorage}" | awk '{print $1}' > /tmp/backedupsize
#rsync -rv "${UsbStorage}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp' > /tmp/backedupsize
echo "${UsbStorage}" > /tmp/runningBackupDst
removeTempfile
echo "status=running" > /tmp/transfer_state	
CalTransfer.sh > /dev/null 2>&1 &

		
if [ "${needCompare}" == "1" ]; then
	find "/shares/Storage/${USB_BACKUP_ROOT}" -type d -maxdepth 3 -name "${CID}" > /tmp/DoneFolder ##Search for already existing backup folder
	cat /tmp/DoneFolder | while read DoneFolders
	do
		if [ "${UsbStorage}" == "${DoneFolders}" ] && [ "$newCreate" == "1" ]; then
			filenum=`ls -al "${UsbStorage}" | wc -l`
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
		if [ "${UsbStorage}" == "${CmpDirs}" ] && [ "$newCreate" == "1" ]; then
			continue
		fi
		if [ "${devType}" == "MTP" ]; then
			if [ -d "/media/USB/DCIM" ]; then
				execmd="nice -n -19 rsync -ahnrvvP --size-only --iconv=UTF-8 --existing "/media/USB/DCIM/" \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
			else
				if [ "${deepfolderNum}" -eq 0 ]; then
					execmd="nice -n -19 rsync -ahnrvvP --size-only --existing "/media/USB/" \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
				else
					for ((dx=1; dx<=deepfolderNum; dx++ )); do
						if [ "${dx}" == 1 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
						elif [ "${dx}" == 2 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
						elif [ "${dx}" == 3 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
						fi
						execmd="nice -n -19 rsync -ahnrvvP --size-only --iconv=UTF-8 --existing \"${MTPfolder}\" \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
					done
				fi
			fi
		else
			if [ "${isFAT32}" -eq 1 ]; then
				execmd="nice -n -19 rsync -ahnrvvP --size-only --iconv=UTF-8 --existing --modify-window=1 \""${USB_MOUNT}"/\" \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
			else
				execmd="nice -n -19 rsync -ahnrvvP --existing --iconv=UTF-8 --modify-window=1 \""${USB_MOUNT}"/\" \"${CmpDirs}\" >> /tmp/RsyncConfliclist"
			fi
		fi
		#echo $timestampDBG ": USB_StorageTransfer.sh rsync find conflict list:" $execmd >> /tmp/backup.log
		eval "$execmd"
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			echo $timestampDBG ": USB_StorageTransfer.sh rsync Error find conflict list:" $execmd "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			RuningStatus=1
			break
		fi
		#ReproduceFileBackup "${CmpDirs}"
	done

	if [ -f "/tmp/RsyncConfliclist" ]; then
		cat /tmp/RsyncConfliclist | grep "NON_CONFLICT" | uniq | while read existfname
		do
			existfile=`echo "$existfname" | awk 'BEGIN{FS="NON_CONFLICT: " } {print $NF}' | awk 'BEGIN{FS='\"${USB_MOUNT}/\"' } {print $NF}'`
			#fname=`echo ${existfile} | awk 'BEGIN{FS='\"${USB_MOUNT}/\"' } {print $NF}'`
			echo $existfile >> /tmp/rsyncExcludefile
		done
	fi

	if [ ! -f "/tmp/rsyncExcludefile" ]; then
		touch /tmp/rsyncExcludefile
	fi

	cat /tmp/DoneFolder | while read DoneFolders
	do
		CmpDirs="${DoneFolders}"
		if [ "${UsbStorage}" == "${CmpDirs}" ] && [ "$newCreate" == "1" ]; then
			continue
		fi
		if [ "${devType}" == "MTP" ]; then
			if [ -d "/media/USB/DCIM" ]; then
				execmd="nice -n -19 rsync -ahrP --size-only --iconv=UTF-8 --existing --chmod=a+rwx --info=progress2 --backup --exclude-from=/tmp/rsyncExcludefile --backup-dir=\""${UsbStorage}"\" "/media/USB/DCIM/" \"${CmpDirs}\" > /dev/null 2>&1"
			else
				if [ "${deepfolderNum}" -eq 0 ]; then
					execmd="nice -n -19 rsync -ahrP --size-only --iconv=UTF-8 --existing --chmod=a+rwx --info=progress2 --backup --exclude-from=/tmp/rsyncExcludefile --backup-dir=\""${UsbStorage}"\" "/media/USB/" \"${CmpDirs}\" > /dev/null 2>&1"
				else
					for ((dx=1; dx<=deepfolderNum; dx++ )); do
						if [ "${dx}" == 1 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
						elif [ "${dx}" == 2 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
						elif [ "${dx}" == 3 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
						fi
						execmd="nice -n -19 rsync -ahrP --size-only --iconv=UTF-8 --existing --chmod=a+rwx --info=progress2 --exclude-from=/tmp/rsyncExcludefile --backup --backup-dir=\""${UsbStorage}"\" \"${MTPfolder}\" \"${CmpDirs}\" > /dev/null 2>&1"
					done
				fi
			fi
		else
			if [ "${isFAT32}" -eq 1 ]; then
				execmd="nice -n -19 rsync -ahrP --size-only --iconv=UTF-8 --existing --chmod=a+rwx --info=progress2 --modify-window=1 --exclude-from=/tmp/rsyncExcludefile --backup --backup-dir=\""${UsbStorage}"\" \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
			else
				execmd="nice -n -19 rsync -ahrP --existing --iconv=UTF-8 --chmod=a+rwx --info=progress2 --modify-window=1 --exclude-from=/tmp/rsyncExcludefile --backup --backup-dir=\""${UsbStorage}"\" \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
			fi
		fi
		#echo $timestampDBG ": USB_StorageTransfer.sh rsync existing:" $execmd >> /tmp/backup.log
		eval "$execmd"
		ERROR_CODE=$?
		if [ "${ERROR_CODE}" != 0 ]; then
			echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync Error compared with existing:" $execmd "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			RuningStatus=1
			break
		fi
		if [ "${backupTest}" == "0" ]; then
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
			done
			echo $timestampDBG ": USB_StorageTransfer.sh finish compared existing" $exist $transferDoneSize >> /tmp/backup.log
			cat /tmp/transferExistSize > /tmp/transferDoneSize
			echo 0 > /tmp/transferExistSize
		fi
		#ReproduceFileBackup "${CmpDirs}"
	done

#YC add for performance test
SYNC_START=$(date +%s)
	if [ -f "/tmp/AllCmpDir" ]; then
		AllCmpDirs=`cat /tmp/AllCmpDir`
		#echo $timestampDBG ": USB_StorageTransfer.sh AllCmpDirs:" $AllCmpDirs >> /tmp/backup.log
		if [ "${devType}" == "MTP" ]; then
			if [ -d "/media/USB/DCIM" ]; then
				RsyncExecmd="rsync -avun --size-only --iconv=UTF-8 --ignore-existing --delete"${AllCmpDirs}" /media/USB/DCIM/ | grep -v ".wdmc" > /tmp/BackUpTemplist"
				if [ "$RsyncExecmd" != "" ]; then
					#echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync new file detect cmd 1:" $RsyncExecmd >> /tmp/backup.log
					eval "$RsyncExecmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=2
						echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync Error:" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					fi
				fi	
			else
				if [ "$deepfolderNum" == 0 ]; then
					MTPfolder="/media/USB"
					RsyncExecmd="rsync -avun --size-only --iconv=UTF-8 --ignore-existing --delete"${AllCmpDirs}" "/media/USB/" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
					if [ "$RsyncExecmd" != "" ]; then
						#echo $timestampDBG ": USB_StorageTransfer.sh rsync new file detect cmd 2:" $RsyncExecmd >> /tmp/backup.log
						eval "$RsyncExecmd"
						ERROR_CODE=$?
						if [ "${ERROR_CODE}" != 0 ]; then
							RuningStatus=3
							echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync Error:" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
						fi
					fi
				else
					for ((dx=1; dx<=deepfolderNum; dx++ )); do
						if [ "${dx}" == 1 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
						elif [ "${dx}" == 2 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
						elif [ "${dx}" == 3 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
						fi
						RsyncExecmd="rsync -avun --size-only --iconv=UTF-8 --ignore-existing --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
						if [ "$RsyncExecmd" != "" ]; then
							#echo $timestampDBG ": USB_StorageTransfer.sh rsync new file detect cmd 3:" $RsyncExecmd >> /tmp/backup.log
							eval "$RsyncExecmd"
							ERROR_CODE=$?
							if [ "${ERROR_CODE}" != 0 ]; then
								RuningStatus=4
								echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync Error:" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log	
							fi
						fi
					done
				fi
			fi	
		else
			if [ "${isFAT32}" -eq 1 ]; then
				RsyncExecmd="rsync -avun --size-only --modify-window=1 --iconv=UTF-8 --ignore-existing --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			else
				RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --ignore-existing --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
			fi
			if [ "$RsyncExecmd" != "" ]; then
				#echo $timestampDBG ": USB_StorageTransfer.sh rsync delete:" $RsyncExecmd >> /tmp/backup.log
				eval "$RsyncExecmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=5
					echo $timestampDBG ": USB_StorageTransfer.sh MTP rsync Error:" $RsyncExecmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log			
				fi
			fi
		fi
		
		cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR" | while read backupfile ####check by folder
		do
			backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_DIR " } {print $NF}'` #| sed -e 's/\\$/\\\\$/g' | sed -e 's/\`/\\\`/g'			
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
			#echo $timestampDBG ": USB_StorageTransfer.sh DIR backupfile:" $backupfile >> /tmp/backup.log
			if [ "${devType}" == "MTP" ]; then
				if [ ! -d "${UsbStorage}/${backupfile}" ]; then
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						execmd="mkdir -p \"${fname}\""
						eval "$execmd"
					fi

					if [ -d /media/USB/DCIM/"${backupfile}" ]; then
						execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
						eval "$execmd"
						ERROR_CODE=$?
						if [ "${ERROR_CODE}" != 0 ]; then
							RuningStatus=6
							echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
							break
						fi
					else
						if [ "${deepfolderNum}" == 0 ]; then
							execmd="cp -a \"/media/USB/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							eval "$execmd"
							ERROR_CODE=$?
							if [ "${ERROR_CODE}" != 0 ]; then
								RuningStatus=7
								echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
								break
							fi
						else
							for ((dx=1; dx<=deepfolderNum; dx++ )); do
								if [ "${dx}" == 1 ]; then
									MTPfolder=`realpath /media/USB/*/DCIM | sed -n '1p'`
								elif [ "${dx}" == 2 ]; then
									MTPfolder=`realpath /media/USB/*/DCIM | sed -n '2p'`
								elif [ "${dx}" == 3 ]; then
									MTPfolder=`realpath /media/USB/*/DCIM | sed -n '3p'`
								fi
								
								if [ -d ${MTPfolder}/"${backupfile}" ]; then
									execmd="cp -a ${MTPfolder}/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
									eval "$execmd"
									ERROR_CODE=$?
									if [ "${ERROR_CODE}" != 0 ]; then
										RuningStatus=8
										eecho $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
										break
									fi
								fi
							done
						fi
					fi
				fi			
			else
				if [ -d ""${USB_MOUNT}"/${ori_backupfile}" ] && [ ! -d "${UsbStorage}/${backupfile}" ]; then
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
					execmd="mkdir -p \"${fname}\""
						eval "$execmd"
					fi
					if [ "$method" == "move" ]; then
						execmd="mv -f \"${USB_MOUNT}/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
					else
						execmd="cp -a \"${USB_MOUNT}/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
					fi
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=9
						echo $timestampDBG ": USB_StorageTransfer.sh USB cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
						break
					fi
				fi
			fi		
		done
				
		cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile ####check by each file
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
			if [ "${devType}" == "MTP" ]; then
				fname=`dirname "${UsbStorage}"\/"${backupfile}"`
				if [ ! -d "${fname}" ]; then
					execmd="mkdir -p \"${fname}\""
					eval "$execmd"
				fi
				if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then							
					if [ -f /media/USB/DCIM/"${backupfile}" ]; then
						execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
						eval "$execmd"
						ERROR_CODE=$?
						if [ "${ERROR_CODE}" != 0 ]; then
							RuningStatus=10
							echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
							break
						fi
					else
						if [ "${deepfolderNum}" == 0 ]; then
							execmd="cp -a \"/media/USB/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							eval "$execmd"
							ERROR_CODE=$?
							if [ "${ERROR_CODE}" != 0 ]; then
								RuningStatus=11
								echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
								break
							fi
						else
							for ((dx=1; dx<=deepfolderNum; dx++ )); do
								if [ "${dx}" == 1 ]; then
									MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
								elif [ "${dx}" == 2 ]; then
									MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
								elif [ "${dx}" == 3 ]; then
									MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
								fi
								
								if [ -f "${MTPfolder}"/"${backupfile}" ]; then
									execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
									#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
									eval "$execmd"
									ERROR_CODE=$?
									if [ "${ERROR_CODE}" != 0 ]; then
										RuningStatus=12
										echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
										break
									fi
								fi
							done
						fi
					fi				
				fi		
			else
				if [ -d "/media/USB/${backupfile}" ] && [ ! -d "${UsbStorage}/${backupfile}" ]; then
					mkdir -p "${UsbStorage}"\/"${backupfile}"
				else
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						execmd="mkdir -p \"${fname}\""
						eval "$execmd"
					fi
					if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then
						if [ "$method" == "move" ]; then
							execmd="mv -f \"${USB_MOUNT}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
						else
							execmd="cp -a \"${USB_MOUNT}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
						fi
						eval "$execmd"
						ERROR_CODE=$?
						if [ "${ERROR_CODE}" != 0 ]; then
							RuningStatus=13
							echo $timestampDBG ": USB_StorageTransfer.sh USB cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
							break
						fi
						#echo "execmd" "$execmd"
					fi
				fi
			fi
		done

		if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
			echo $timestampDBG ": USB_StorageTransfer.sh No backup ITEM" >> /tmp/backup.log
			filenum=`ls -al "${UsbStorage}" | wc -l`
			if [ "$filenum" -eq 1 ]; then
				rm -rf "${UsbStorage}"
				#finishUSBBackup
			fi
			filenum=`ls -al "${ImportDIR}" | wc -l`
			if [ "$filenum" -eq 1 ]; then
				rm -rf "${ImportDIR}"		
				#finishUSBBackup
			fi
		fi
	else	
		if [ "${devType}" == "MTP" ]; then
			if [ -d "/media/USB/DCIM" ]; then
				execmd="cp -a /media/USB/DCIM/* \"${UsbStorage}/\" > /dev/null 2>&1"
				#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=14
					echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
				fi
			else
				if [ "${deepfolderNum}" == 0 ]; then
					execmd="cp -a /media/USB/* \"${UsbStorage}/\" > /dev/null 2>&1"
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=15
						echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					fi
				else
					for ((dx=1; dx<=deepfolderNum; dx++ )); do
						if [ "${dx}" == 1 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
						elif [ "${dx}" == 2 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
						elif [ "${dx}" == 3 ]; then
							MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
						fi
								
						execmd="cp -a \"${MTPfolder}/\"* \"${UsbStorage}/\" > /dev/null 2>&1"
						eval "$execmd"
						ERROR_CODE=$?
						if [ "${ERROR_CODE}" != 0 ]; then
							RuningStatus=16
							echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
						fi		
					done
				fi				
			fi			
		else
			if [ "$method" == "move" ]; then
				execmd="mv -f "${USB_MOUNT}"/.[^.]* \"${UsbStorage}/\" > /dev/null 2>&1"
				eval "$execmd"
				filenum=`ls "${USB_MOUNT}"/ | wc -l`
				if [ "${filenum}" != 0 ]; then
					execmd="mv -f "${USB_MOUNT}"/* \"${UsbStorage}/\" > /dev/null 2>&1"
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=16
						echo $timestampDBG ": USB_StorageTransfer.sh USB cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					fi
				fi
			else
				execmd="cp -a "${USB_MOUNT}"/.[^.]* \"${UsbStorage}/\" > /dev/null 2>&1"
				eval "$execmd"
				filenum=`ls "${USB_MOUNT}"/ | wc -l`
				if [ "${filenum}" != 0 ]; then
					execmd="cp -a "${USB_MOUNT}"/* \"${UsbStorage}/\" > /dev/null 2>&1"
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=16
						echo $timestampDBG ": USB_StorageTransfer.sh USB cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					fi
				fi
			fi
		fi
	fi
elif [ "$method" == "copy_all" ]; then
#YC add for performance test
SYNC_START=$(date +%s)
	if [ "${devType}" == "MTP" ]; then
		if [ -d "/media/USB/DCIM" ]; then
			execmd="cp -a /media/USB/DCIM/* \"${UsbStorage}/\" > /dev/null 2>&1"
			#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
			eval "$execmd"
			ERROR_CODE=$?
			if [ "${ERROR_CODE}" != 0 ]; then
				RuningStatus=14
				echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			fi
		else
			if [ "${deepfolderNum}" == 0 ]; then
				execmd="cp -a /media/USB/* \"${UsbStorage}/\" > /dev/null 2>&1"
				eval "$execmd"
				ERROR_CODE=$?
				if [ "${ERROR_CODE}" != 0 ]; then
					RuningStatus=15
					echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
				fi
			else
				for ((dx=1; dx<=deepfolderNum; dx++ )); do
					if [ "${dx}" == 1 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
					elif [ "${dx}" == 2 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
					elif [ "${dx}" == 3 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
					fi
								
					execmd="cp -a \"${MTPfolder}/\"* \"${UsbStorage}/\" > /dev/null 2>&1"
					eval "$execmd"
					ERROR_CODE=$?
					if [ "${ERROR_CODE}" != 0 ]; then
						RuningStatus=16
						echo $timestampDBG ": USB_StorageTransfer.sh MTP cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
					fi		
				done
			fi				
		fi
	else
		execmd="cp -a "${USB_MOUNT}"/.[^.]* \"${UsbStorage}/\" > /dev/null 2>&1"
		eval "$execmd"
		filenum=`ls "${USB_MOUNT}"/ | wc -l`
		if [ "${filenum}" != 0 ]; then
			execmd="cp -a "${USB_MOUNT}"/* \"${UsbStorage}/\" > /dev/null 2>&1"
			eval "$execmd"
			ERROR_CODE=$?
			if [ "${ERROR_CODE}" != 0 ]; then
				RuningStatus=16
				echo $timestampDBG ": USB_StorageTransfer.sh USB cmd" $execmd "RuningStatus" $RuningStatus "ERROR_CODE" $ERROR_CODE >> /tmp/backup.log
			fi
		fi
	fi
fi

#YC add for performance test
SYNC_END=$(date +%s)
DIFF=$(( $SYNC_END - $SYNC_START ))
echo "SYNC took $DIFF seconds"          
	
removeTempfile
if [ -d "${ImportDIR}" ]; then
	execmd="chmod -R 777 \"${ImportDIR}/\""
fi
eval "$execmd"
echo $timestampDBG ": USB_StorageTransfer.sh change attribute" $execmd >> /tmp/backup.log
if [ "${RuningStatus}" != "0" ]; then
	#chmod -R 777 "/shares/Storage/${USB_BACKUP_ROOT}"
	if [ "${MTP_WrongMethod}" == "1" ]; then
		/usr/local/sbin/sendAlert.sh 1612 "${StorageProduct}" "${SerialNum}" &
	else
		/usr/local/sbin/sendAlert.sh 1606 "${StorageProduct}" "${SerialNum}" &
	fi
	echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
	sync
	sync
	sync
	if [ -f /tmp/USB_Process_Canceled ]; then
		echo "status=canceled" > /tmp/transfer_state
		rm -f /tmp/USB_Process_Canceled
	else
		echo "status=failed" > /tmp/transfer_state	
	fi
	echo "42;125;" > /tmp/MCU_Cmd
	SD_BackupQueueCheck
	exit 1
fi    			

echo ${CID} > /media/sdb1/.wdcache/.${SerialNum}
finishBackup

sync
sync
sync

#sleep 1
SD_BackupQueueCheck
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


