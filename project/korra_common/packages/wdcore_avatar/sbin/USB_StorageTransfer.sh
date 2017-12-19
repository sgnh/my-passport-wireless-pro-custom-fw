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
source /etc/power.conf
ACMode=`cat /tmp/battery | cut -d " " -f 1`
RuningStatus=0
deepfolder=0
USB_BACKUP_FOLDER_NAME="USB Imports"
USB_MOUNT=/media/USB
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
echo $timestampDBG ": USB_StorageTransfer.sh" $@ >> /tmp/backup.log

echo 0 > /tmp/USBStatusError
echo status=waiting > /tmp/transfer_state
echo "total_size_in_bytes=1024" > /tmp/transfer_size_total
echo "transferred_size_in_bytes=0" > /tmp/transfer_size
echo 0 > /tmp/transferExistSize
echo 0 > /tmp/transferDoneSize

sharename="${1}"
backmethod="${2}"

if [ -f "/tmp/detectInterface" ]; then
	devicefound=`cat /tmp/detectInterface`
	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
		if [ ! -d "/media/USB/DCIM" ]; then
			deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
		fi
	fi
fi

function finishSdBackup()
{
	#/sbin/AdaptCPUfreq.sh endbackup
	removeTempfile
	/usr/local/sbin/sendAlert.sh "1610" "${StorageProduct}" "${SerialNum}" &
	echo "42;100" > /tmp/MCU_Cmd
	total=`cat /tmp/transfer_size_total | sed -n '1p' | sed -n 's/.*=//p'` 
	echo "transferred_size_in_bytes=${total}" > /tmp/transfer_size
	echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf 
	sed -i "s/status=.*/status=completed/" /tmp/transfer_state
	#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestampDBG ": USB_StorageTransfer.sh Completed !" >> /tmp/backup.log
	/usr/local/sbin/storage_transfer_status.sh > /dev/null 2>&1 &
	chmod -R 777 "/shares/Storage/USB Imports"
}

function SD_BackupQueueCheck()
{
	SD_backup=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
	sdstandby=`echo "${SD_backup}" | awk -F: '{print $1}'`
	#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestampDBG ": USB_StorageTransfer.sh SD_BackupQueueCheck" $usbstandby >> /tmp/backup.log
	sleep 20
	if [ "$sdstandby" == "standby" ]; then
		triggerMode=`echo "${SD_backup}" | awk -F: '{print $2}'`
		if [ "${triggerMode}" == "Button" ]; then	
			/sbin/ButtonStorageTransfer.sh SD
		elif [ "${triggerMode}" == "Auto" ]; then
			/sbin/SDCard_AutoStorageTransfer.sh
		else
			/sbin/ButtonStorageTransfer.sh SD
		fi
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
	elif [ "$sdstandby" == "checkin" ]; then
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		/sbin/ButtonStorageTransfer.sh SD 2>&1 &
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
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": USB_StorageTransfer.sh ReproduceFileBackup" "${USBpath}/${newname}" >> /tmp/backup.log
   		done
   		rm /tmp/usbArchivePath
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
	
	if [ -f "/tmp/USB_AutoProcessing" ]; then
		rm /tmp/USB_AutoProcessing
	fi

	if [ -f "/tmp/USB_ButtonProcessing" ]; then
		rm /tmp/USB_ButtonProcessing
	fi
	
}
#timestamp=$(date "+%m-%d-%Y-%H%M")
timeoffset=`cat /etc/timezone_offset`
if [ "$timeoffset" == "" ]; then
	timeoffset=0
fi
timecommand="date "+%Y-%m-%d" -uD '%s' -d "$(( `date -u +%s`+${timeoffset}*60*60 ))""
timestamp=`eval $timecommand`
#timestamp=$(date "+%Y-%m-%d")
timestampYear=$(date "+%Y")
timestampDate=$(date "+%m.%d")

if [ "$backmethod" == "" ]; then
	method="${USB_ModeTransfer}"
else
	method=${backmethod}
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

fullCID=$SerialNum
ImportDIR="/shares/Storage/USB Imports/${timestamp}"
UsbStorage="/shares/Storage/USB Imports/${timestamp}/${CID}"

if [ -f "/tmp/runningBackupDst" ]; then
	rm -rf /tmp/runningBackupDst
fi

if [ ! -d "/shares/Storage/USB Imports" ]; then
    mkdir -p "/shares/Storage/USB Imports"
    chmod -R 777 "/shares/Storage/USB Imports"
fi


if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
	USB_MOUNT="/media/USB"
else
	USB_MOUNT=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $3}'`
fi
dev_node=`cat /tmp/sd*-info | grep "${sharename}" | awk -F: '{print $4}'`
chknode=`blkid "${dev_node}"`	
isFAT32=`blkid "${dev_node}" | grep vfat | wc -l`

#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
#echo $timestampDBG ": USB_StorageTransfer.sh isFAT32" $isFAT32 >> /tmp/backup.log

ModeAuth=`cat /proc/mounts | grep "${USB_MOUNT}" | awk '{print $4}' | awk -F, '{print $1}'`
if [ "$ModeAuth" == "ro" ]; then
	ReadOnly=1
fi

#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestampDBG ": USB_StorageTransfer.sh ReadOnly" $ModeAuth $ReadOnly >> /tmp/backup.log

if [ "$devicefound" == "PTP" ]; then
	if [ "$method" == "move" ]; then
		method=copy
		MTP_WrongMethod=1
		echo "1" > /tmp/USBStatusError
		ReadOnly=1
	fi
fi

if [ "$method" == "move" ] || [ "$method" == "copy" ]; then
	if [ ! -d "${UsbStorage}" ]; then
		mkdir -p "${UsbStorage}"
		chmod -R 777 "${ImportDIR}"
		chmod -R 777 "${UsbStorage}"
		newCreate=1
	fi
	if [ `ps aux | grep rsync | grep "${USB_MOUNT}" | wc -l` -ne 0 ] && [ `cat /etc/nas/config/usb-transfer-status.conf | grep process | wc -l` -ne 0 ]; then
		rm -rf "${UsbStorage}"
		killall rsync > /dev/null 2>&1
		echo "18;0;" > /tmp/MCU_Cmd 
		removeTempfile
		#sleep 10
		SD_BackupQueueCheck
		echo $timestampDBG ": USB_StorageTransfer.sh wrong process" >> /tmp/backup.log
		exit 1
	fi
	
	/usr/local/sbin/storage_transfer_LED_status.sh starting
	echo "USB_TransferStatus=process" > /etc/nas/config/usb-transfer-status.conf
	
	/usr/local/sbin/incUpdateCount.pm storage_transfer &
	
	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
		if [ ! -d "/media/USB/DCIM" ]; then
			deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
			total_size=0
			if [ ${deepfolderNum} -eq 0 ]; then
				total_size=`rsync -rv "/media/USB" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
			else
				for ((dx=1; dx<=deepfolderNum; dx++ )); do
					if [ "${dx}" == 1 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
					elif [ "${dx}" == 2 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
					elif [ "${dx}" == 3 ]; then
						MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
					fi
					temp_total_size=`rsync -rv "${MTPfolder}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
					if [ $? != 0 ]; then
						sleep 10
						temp_total_size=`rsync -rv "${MTPfolder}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
					fi
					total_size=`expr ${total_size} + ${temp_total_size}`
				done
			fi
		else
			total_size=`rsync -rv "/media/USB/DCIM" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
			if [ $? != 0 ]; then
				sleep 10
				total_size=`rsync -rv "/media/USB/DCIM" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
			fi
		fi
	else
		total_size=`rsync -rv "${USB_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
		#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	fi
	
	#totalDF=`df | grep "${USB_MOUNT}" | awk '{print $3}'`
	#total_size=`expr "${totalDF}" \* 1024`
    if [ $? -eq 0 ]; then
    	if [ "$total_size" != "" ] && [ "$total_size" != "0" ]; then
			sed -i 's/total_size_in_bytes=.*/total_size_in_bytes='${total_size}'/' /tmp/transfer_size_total
        elif [ "$total_size" == "" ]; then
        	sleep 5
        	total_size=`rsync -rv "${USB_MOUNT}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
        	sed -i 's/total_size_in_bytes=.*/total_size_in_bytes='${total_size}'/' /tmp/transfer_size_total
        fi 
    else
    	/usr/local/sbin/sendAlert.sh 1608 "${StorageProduct}" "${SerialNum}" &
    	#echo "18;0;" > /tmp/MCU_Cmd
    	echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
        #/sbin/AdaptCPUfreq.sh endbackup
        killall rsync > /dev/null 2>&1
        removeTempfile
        #sleep 10
        
        echo "status=failed" > /tmp/transfer_state
        SD_BackupQueueCheck
        echo "42;125;" > /tmp/MCU_Cmd
        echo $timestampDBG ": USB_StorageTransfer.sh wrong total size" ${total_size} >> /tmp/backup.log
        exit 1
    fi
	rsync -rv "${UsbStorage}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp' > /tmp/backedupsize
	echo "${UsbStorage}" > /tmp/runningBackupDst
	removeTempfile
	echo "status=running" > /tmp/transfer_state	
	#/sbin/AdaptCPUfreq.sh startbackup
	CalTransfer.sh > /dev/null 2>&1 &
	find "/shares/Storage/USB Imports" -name "${CID}" > /tmp/DoneFolder 
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
	
	if [ "$method" == "move" ]; then
		cat /tmp/DoneFolder | while read DoneFolders
		do
			CmpDirs="${DoneFolders}"
			if [ "${devicefound}" == "MTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive "/media/USB/DCIM/" \"${CmpDirs}\" > /dev/null 2>&1"
				else
					deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
					if [ ${deepfolderNum} -eq 0 ]; then
						execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive "/media/USB/" \"${CmpDirs}\" > /dev/null 2>&1"
					else
						for ((dx=1; dx<=deepfolderNum; dx++ )); do
							if [ "${dx}" == 1 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
							elif [ "${dx}" == 2 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
							elif [ "${dx}" == 3 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
							fi
							execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive \"${MTPfolder}\" \"${CmpDirs}\" > /dev/null 2>&1"
						done
					fi
				fi
			else
				if [ $isFAT32 -eq 1 ]; then
					execmd="nice -n -19 rsync -ah --size-only --existing --backup --modify-window=1 --suffix=_tmparchive \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
				else
					execmd="nice -n -19 rsync -ah --existing --backup --suffix=_tmparchive \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
				fi
			fi
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": USB_StorageTransfer.sh rsync existing:" $execmd >> /tmp/backup.log
			eval "$execmd"
			if [ $? != 0 ]; then
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestampDBG ": USB_StorageTransfer.sh rsync existing:" $execmd >> /tmp/backup.log
				echo $timestampDBG ": USB_StorageTransfer.sh rsync: Error 1" >> /tmp/backup.log
				echo "1" > /tmp/USBStatusError
				break
			fi
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist $divide >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
			done
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": USB_StorageTransfer.sh out Loop" $exist $transferDoneSize >> /tmp/backup.log
			echo 0 > /tmp/transferExistSize
			ReproduceFileBackup "${CmpDirs}"
		done
		if [ -f "/tmp/AllCmpDir" ]; then
			AllCmpDirs=`cat /tmp/AllCmpDir`
			if [ "${devicefound}" == "MTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" /media/USB/DCIM/ | grep -v ".wdmc" > /tmp/BackUpTemplist"
					if [ "$RsyncExecmd" != "" ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh Mv 1 cmd:" $RsyncExecmd >> /tmp/backup.log
						eval "$RsyncExecmd"
					fi
				else
					if [ -f "/tmp/BackUpTemplist" ]; then
						rm /tmp/BackUpTemplist
					fi
					if [ "$deepfolderNum" == 0 ]; then
						MTPfolder="/media/USB"
						RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" ${MTPfolder} | grep -v ".wdmc" >> /tmp/BackUpTemplist"
						if [ "$RsyncExecmd" != "" ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh Cp 2 cmd:" $RsyncExecmd >> /tmp/backup.log
							eval "$RsyncExecmd"
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
							RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
							if [ "$RsyncExecmd" != "" ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh Mv 2 cmd:" $RsyncExecmd >> /tmp/backup.log
								eval "$RsyncExecmd"
							fi
						done
					fi
				fi
			else
				if [ $isFAT32 -eq 1 ]; then
					RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				else
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				fi
				if [ "$RsyncExecmd" != "" ]; then
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestampDBG ": USB_StorageTransfer.sh rsync delete:" $RsyncExecmd >> /tmp/backup.log
					eval "$RsyncExecmd"
				fi
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
				#echo $timestampDBG ": USB_StorageTransfer.sh DIR backupfile:" $backupfile >> /tmp/backup.log
				if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
					if [ ! -d "${UsbStorage}/${backupfile}" ]; then
						fname=`dirname "${UsbStorage}"\/"${backupfile}"`
						if [ ! -d "${fname}" ]; then
							mkdir -p "${fname}"
							chmod -R 777 "${fname}"
						fi

						if [ -d /media/USB/DCIM/"${backupfile}" ]; then
							execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
							eval "$execmd"
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 7" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
								break
							fi
						else
							if [ "${deepfolderNum}" == 0 ]; then
								MTPfolder="/media/USB"
								execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
								eval "$execmd"
								if [ $? != 0 ]; then
									#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
									echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
									echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
									echo "1" > /tmp/USBStatusError
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
								
									if [ -d "${MTPfolder}"/"${backupfile}" ]; then
										execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
										#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
										#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
										eval "$execmd"
										if [ $? != 0 ]; then
											#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
											echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
											echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
											echo "1" > /tmp/USBStatusError
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
							mkdir -p "${fname}"
							chmod -R 777 "${fname}"
							#echo "create" "$fname"
						fi
						execmd="mv -f \"${USB_MOUNT}/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						#echo $timestampDBG ": USB_StorageTransfer.sh Mv :" $execmd >> /tmp/backup.log
						eval "$execmd"
						#echo "Move directory execmd:" "$execmd"
					fi
				fi
			done
	
			cat /tmp/DoneFolder | while read DoneFolders
			do
				AllDir="$AllDir"" "\""${DoneFolders}"/\"
				echo "$AllDir" > /tmp/AllCmpDir
			done
			AllCmpDirs=`cat /tmp/AllCmpDir`
			
			if [ "${devicefound}" == "MTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" /media/USB/DCIM/ | grep -v ".wdmc" > /tmp/BackUpTemplist"
					eval "$RsyncExecmd"	
				else
					if [ -f "/tmp/BackUpTemplist" ]; then
						rm /tmp/BackUpTemplist
					fi
					if [ "${deepfolderNum}" == 0 ]; then
						MTPfolder="/media/USB"
						RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${MTPfolder}" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
						if [ "$RsyncExecmd" != "" ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh Cp 2 cmd:" $RsyncExecmd >> /tmp/backup.log
							eval "$RsyncExecmd"
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
							RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
							eval "$RsyncExecmd"	
						done
					fi
				fi		
            else
            	if [ $isFAT32 -eq 1 ]; then
					RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				else
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				fi
				eval "$RsyncExecmd"	
			fi
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_ITEM " } {print $NF}'`
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": USB_StorageTransfer.sh ITEM backupfile:" $backupfile >> /tmp/backup.log
				if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
					fi
					if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then							
						if [ -f /media/USB/DCIM/"${backupfile}" ]; then
							execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
							eval "$execmd"
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 7" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
								break
							fi
						else
							if [ "${deepfolderNum}" == 0 ]; then
								MTPfolder="/media/USB"
								execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
								eval "$execmd"
								if [ $? != 0 ]; then
									#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
									echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
									echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
									echo "1" > /tmp/USBStatusError
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
								
									if [ -f ${MTPfolder}/"${backupfile}" ]; then
										execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
										#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
										#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
										eval "$execmd"
										if [ $? != 0 ]; then
											#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
											echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
											echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
											echo "1" > /tmp/USBStatusError
											break
										fi
									fi
								done
							fi
						fi				
					fi		
              	else
              		echo "$backupfile" > /tmp/kkk
					sed -i 's/`/\\`/g' /tmp/kkk
					backupfile=`cat /tmp/kkk`
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
						#echo "create" "$fname"
					fi
					if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then
						execmd="mv -f \"${USB_MOUNT}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						#echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
						eval "$execmd"
						if [ $? != 0 ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
							echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd: Error 2" >> /tmp/backup.log
							echo "1" > /tmp/USBStatusError
							break
						fi	
					fi
				fi
			done
			
			if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
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
			if [ "$devicefound" == "MTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					execmd="cp -a /media/USB/DCIM/* \"${UsbStorage}/\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"	
					if [ $? != 0 ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
						echo $timestampDBG ": USB_StorageTransfer.sh Error 14" >> /tmp/backup.log
						echo "1" > /tmp/USBStatusError
             		fi
				else
					if [ "${deepfolderNum}" == 0 ]; then
						MTPfolder="/media/USB"
						execmd="cp -a \"${MTPfolder}\"/* \"${UsbStorage}/\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
						eval "$execmd"	
						if [ $? != 0 ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
							echo $timestampDBG ": USB_StorageTransfer.sh Error 12" >> /tmp/backup.log
							echo "1" > /tmp/USBStatusError
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
								
							execmd="cp -a \"${MTPfolder}\"/* \"${UsbStorage}/\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
							eval "$execmd"	
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 12" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
               				fi		
						done
					fi				
				fi			
			else
				execmd="mv -f "${USB_MOUNT}"/.[^.]* \"${UsbStorage}/\" > /dev/null 2>&1"
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
				eval "$execmd"
			
				filenum=`ls "${USB_MOUNT}"/ | wc -l`
				if [ "${filenum}" != 0 ]; then
					execmd="mv -f "${USB_MOUNT}"/* \"${UsbStorage}/\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
					if [ $? != 0 ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd:" $execmd >> /tmp/backup.log
						echo $timestampDBG ": USB_StorageTransfer.sh Mv cmd: Error 3" >> /tmp/backup.log
						echo "1" > /tmp/USBStatusError
					fi
				fi
			fi
		fi		
		
		removeTempfile
		RuningStatus=`cat /tmp/USBStatusError`
		if [ "${RuningStatus}" -eq 0 ]; then
			`rm -rf "${USB_MOUNT}"/*`
			#`chmod -R 777 "${UsbStorage}"`
		else
			chmod -R 777 "/shares/Storage/USB Imports"
			if [ "$ReadOnly" == "1" ]; then
				/usr/local/sbin/sendAlert.sh 1612 "${StorageProduct}" "${SerialNum}" &
			else	
				/usr/local/sbin/sendAlert.sh 1606 "${StorageProduct}" "${SerialNum}" & 
			fi
			#echo "18;0;" > /tmp/MCU_Cmd
			echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
            sync
           	sync
           	sync
            if [ -f /tmp/USB_Process_Canceled ]; then
            	echo "status=canceled" > /tmp/transfer_state
                rm -f /tmp/USB_Process_Canceled
            else
			   if [ "$ReadOnly" == "1" ]; then
			    	echo "status=UsbReadOnlyfailed" > /tmp/transfer_state
			    else
			    	echo "status=failed" > /tmp/transfer_state
			    fi
            fi
            echo "42;125;" > /tmp/MCU_Cmd
			#/sbin/AdaptCPUfreq.sh endbackup
			#sleep 10	
			SD_BackupQueueCheck
			
			exit 1
		fi
	fi
		
	if [ "$method" == "copy" ]; then
		cat /tmp/DoneFolder | while read DoneFolders
		do
			CmpDirs="${DoneFolders}"
			if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive "/media/USB/DCIM/" \"${CmpDirs}\" > /dev/null 2>&1"
				else
					deepfolderNum=`realpath /media/USB/*/DCIM | wc -l`
					if [ ${deepfolderNum} -eq 0 ]; then
						execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive "/media/USB/" \"${CmpDirs}\" > /dev/null 2>&1"
					else
						for ((dx=1; dx<=deepfolderNum; dx++ )); do
							if [ "${dx}" == 1 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '1p'`"
							elif [ "${dx}" == 2 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '2p'`"
							elif [ "${dx}" == 3 ]; then
								MTPfolder="`realpath /media/USB/*/DCIM | sed -n '3p'`"
							fi
							execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive \"${MTPfolder}\" \"${CmpDirs}\" > /dev/null 2>&1"
						done
					fi
				fi
			else
				if [ $isFAT32 -eq 1 ]; then
					execmd="nice -n -19 rsync -ahP --size-only --info=progress2 --existing --backup --modify-window=1 --suffix=_tmparchive \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
				else
					execmd="nice -n -19 rsync -ahP --existing --info=progress2 --backup --suffix=_tmparchive \""${USB_MOUNT}"/\" \"${CmpDirs}\" > /dev/null 2>&1"
				fi
			fi
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			#echo $timestampDBG ": USB_StorageTransfer.sh rsync existing:" $execmd >> /tmp/backup.log
			eval "$execmd"
			if [ $? != 0 ]; then
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestampDBG ": USB_StorageTransfer.sh rsync existing:" $execmd >> /tmp/backup.log
				echo $timestampDBG ": USB_StorageTransfer.sh rsync: Error 4" >> /tmp/backup.log
				echo "1" > /tmp/USBStatusError
				break
			fi
			exist=`cat /tmp/transferExistSize`
			transferDoneSize=`cat /tmp/transferDoneSize`
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist $divide >> /tmp/backup.log
			while [ "${exist}" -gt "${transferDoneSize}" ]; do
				exist=`cat /tmp/transferExistSize`
				transferDoneSize=`cat /tmp/transferDoneSize`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": USB_StorageTransfer.sh exist" $exist $transferDoneSize >> /tmp/backup.log
			done
			#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestampDBG ": USB_StorageTransfer.sh out Loop" $exist $transferDoneSize >> /tmp/backup.log
			cat /tmp/transferExistSize > /tmp/transferDoneSize
			echo 0 > /tmp/transferExistSize
			ReproduceFileBackup "${CmpDirs}"
		done
#YC add for performance test
SYNC_START=$(date +%s)
        if [ -f "/tmp/AllCmpDir" ]; then
			AllCmpDirs=`cat /tmp/AllCmpDir`
			if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" /media/USB/DCIM/ | grep -v ".wdmc" > /tmp/BackUpTemplist"
					if [ "$RsyncExecmd" != "" ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh Cp 1 cmd:" $RsyncExecmd >> /tmp/backup.log
						eval "$RsyncExecmd"
					fi	
				else
					if [ -f "/tmp/BackUpTemplist" ]; then
						rm /tmp/BackUpTemplist
					fi
					if [ "$deepfolderNum" == 0 ]; then
						MTPfolder="/media/USB"
						RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${MTPfolder}" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
						if [ "$RsyncExecmd" != "" ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh Cp 2 cmd:" $RsyncExecmd >> /tmp/backup.log
							eval "$RsyncExecmd"
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
							RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
							if [ "$RsyncExecmd" != "" ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh Cp 2 cmd:" $RsyncExecmd >> /tmp/backup.log
								eval "$RsyncExecmd"
							fi
						done
					fi
				fi	
            else
				if [ $isFAT32 -eq 1 ]; then
					RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				else
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				fi
			
				if [ "$RsyncExecmd" != "" ]; then
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestampDBG ": USB_StorageTransfer.sh rsync delete:" $RsyncExecmd >> /tmp/backup.log
					eval "$RsyncExecmd"
				fi
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
				#echo $timestampDBG ": USB_StorageTransfer.sh DIR backupfile:" $backupfile >> /tmp/backup.log
				if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
					if [ ! -d "${UsbStorage}/${backupfile}" ]; then
						fname=`dirname "${UsbStorage}"\/"${backupfile}"`
						if [ ! -d "${fname}" ]; then
							mkdir -p "${fname}"
							chmod -R 777 "${fname}"
						fi

						if [ -d /media/USB/DCIM/"${backupfile}" ]; then
							execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
							eval "$execmd"
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 7" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
								break
							fi
						else
							if [ "${deepfolderNum}" == 0 ]; then
								MTPfolder="/media/USB"
								execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
								eval "$execmd"
								if [ $? != 0 ]; then
									#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
									echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
									echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
									echo "1" > /tmp/USBStatusError
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
										#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
										#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
										eval "$execmd"
										if [ $? != 0 ]; then
											#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
											echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
											echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
											echo "1" > /tmp/USBStatusError
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
							mkdir -p "${fname}"
							chmod -R 777 "${fname}"
							#echo "create" "$fname"
						fi
						execmd="cp -a \"${USB_MOUNT}/${backupfile}\" \"${fname}\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
						eval "$execmd"
					fi
				fi		
			done
				
			cat /tmp/DoneFolder | while read DoneFolders
			do
				AllDir="$AllDir"" "\""$DoneFolders"/\"
				echo "$AllDir" > /tmp/AllCmpDir
			done
			AllCmpDirs=`cat /tmp/AllCmpDir`	
			
			if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" /media/USB/DCIM/ | grep -v ".wdmc" > /tmp/BackUpTemplist"
					eval "$RsyncExecmd"	
				else
					if [ -f "/tmp/BackUpTemplist" ]; then
						rm /tmp/BackUpTemplist
					fi
					if [ "${deepfolderNum}" == 0 ]; then
						MTPfolder="/media/USB"
						RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
						if [ "$RsyncExecmd" != "" ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh Cp 2 cmd:" $RsyncExecmd >> /tmp/backup.log
							eval "$RsyncExecmd"
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
							RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" \"${MTPfolder}\" | grep -v ".wdmc" >> /tmp/BackUpTemplist"
							eval "$RsyncExecmd"	
						done
					fi
				fi		
            else
				if [ $isFAT32 -eq 1 ]; then
					RsyncExecmd="rsync -avn --size-only --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				else
					RsyncExecmd="rsync -avun --modify-window=1 --iconv=UTF-8 --delete"${AllCmpDirs}" "${USB_MOUNT}"/ | grep -v ".wdmc" > /tmp/BackUpTemplist" 
				fi
				eval "$RsyncExecmd"	
			fi
			
			cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM" | while read backupfile
			do
				backupfile=`echo "$backupfile" | awk 'BEGIN{FS="RSYNC_delete_ITEM " } {print $NF}'`
				echo "$backupfile" > /tmp/kkk
				sed -i 's/`/\\`/g' /tmp/kkk
				sed -i 's/\$/\\$/g' /tmp/kkk
				backupfile=`cat /tmp/kkk`
				#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
				#echo $timestampDBG ": USB_StorageTransfer.sh ITEM backupfile:" $backupfile >> /tmp/backup.log
				if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
					fname=`dirname "${UsbStorage}"\/"${backupfile}"`
					if [ ! -d "${fname}" ]; then
						mkdir -p "${fname}"
						chmod -R 777 "${fname}"
					fi
					if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then							
						if [ -f /media/USB/DCIM/"${backupfile}" ]; then
							execmd="cp -a /media/USB/DCIM/\"${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
							eval "$execmd"
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 7" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
								break
							fi
						else
							if [ "${deepfolderNum}" == 0 ]; then
								MTPfolder="/media/USB"
								execmd="cp -a \"${MTPfolder}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
								eval "$execmd"
								if [ $? != 0 ]; then
									#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
									echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
									echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
									echo "1" > /tmp/USBStatusError
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
										#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
										#echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
										eval "$execmd"
										if [ $? != 0 ]; then
											#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
											echo $timestampDBG ": USB_StorageTransfer.sh MTP delete_DIR Cp" $execmd >> /tmp/backup.log
											echo $timestampDBG ": USB_StorageTransfer.sh Error 5" >> /tmp/backup.log
											echo "1" > /tmp/USBStatusError
											break
										fi
									fi
								done
							fi
						fi				
					fi		
              	else
					echo "$backupfile" > /tmp/kkk
					sed -i 's/`/\\`/g' /tmp/kkk
					backupfile=`cat /tmp/kkk`
					if [ -d "/media/USB/${backupfile}" ] && [ ! -d "${UsbStorage}/${backupfile}" ]; then
						mkdir -p "${UsbStorage}"\/"${backupfile}"
						chmod -R 777 "${UsbStorage}"\/"${backupfile}"
						#echo "create" "${UsbStorage}"\/"${backupfile}"
					else
						fname=`dirname "${UsbStorage}"\/"${backupfile}"`
						if [ ! -d "${fname}" ]; then
							mkdir -p "${fname}"
							chmod -R 777 "${fname}"
							#echo "create" "$fname"
						fi
						if [ ! -d "${UsbStorage}/${backupfile}" ] && [ ! -f "${UsbStorage}/${backupfile}" ]; then
							execmd="cp -a \"${USB_MOUNT}/${backupfile}\" \"${UsbStorage}/${backupfile}\" > /dev/null 2>&1"
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh cp cmd:" $execmd >> /tmp/backup.log
							eval "$execmd"
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh cp cmd:" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 11" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
								break
							fi
							#echo "execmd" "$execmd"
						fi
					fi
				fi
			done
			if [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_DIR")" == "" ] && [ "$(cat /tmp/BackUpTemplist | grep "RSYNC_delete_ITEM")" == "" ]; then
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
        	if [ "$devicefound" == "MTP" -o "$devicefound" == "PTP" ]; then
				if [ -d "/media/USB/DCIM" ]; then
					execmd="cp -a /media/USB/DCIM/* \"${UsbStorage}/\" > /dev/null 2>&1"
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"	
					if [ $? != 0 ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
						echo $timestampDBG ": USB_StorageTransfer.sh Error 14" >> /tmp/backup.log
						echo "1" > /tmp/USBStatusError
					fi
				else
					if [ "${deepfolderNum}" == 0 ]; then
						MTPfolder="/media/USB"
						execmd="cp -a \"${MTPfolder}\"/* \"${UsbStorage}/\" > /dev/null 2>&1"
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
						eval "$execmd"	
						if [ $? != 0 ]; then
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
							echo $timestampDBG ": USB_StorageTransfer.sh Error 12" >> /tmp/backup.log
							echo "1" > /tmp/USBStatusError
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
							#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
							#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
							eval "$execmd"	
							if [ $? != 0 ]; then
								#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
								echo $timestampDBG ": USB_StorageTransfer.sh Error 12" >> /tmp/backup.log
								echo "1" > /tmp/USBStatusError
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
					#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
					#echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
					eval "$execmd"
					if [ $? != 0 ]; then
						#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestampDBG ": USB_StorageTransfer.sh MTP Cp cmd:" $execmd >> /tmp/backup.log
						echo $timestampDBG ": USB_StorageTransfer.sh Error 15" >> /tmp/backup.log
						echo "1" > /tmp/USBStatusError
           			fi
           		fi
           	fi
		fi
		
		
			
#YC add for performance test
SYNC_END=$(date +%s)
DIFF=$(( $SYNC_END - $SYNC_START ))
echo "SYNC took $DIFF seconds"          

        removeTempfile
		RuningStatus=`cat /tmp/USBStatusError`
		if [ "${RuningStatus}" -eq 0 ]; then
			`chmod -R 777 "/shares/Storage/USB Imports"`
		else
			chmod -R 777 "/shares/Storage/USB Imports"
			if [ "${MTP_WrongMethod}" == "1" ]; then
				/usr/local/sbin/sendAlert.sh 1612 "${StorageProduct}" "${SerialNum}" &
			else
				/usr/local/sbin/sendAlert.sh 1606 "${StorageProduct}" "${SerialNum}" &
			fi 
			#echo "18;0;" > /tmp/MCU_Cmd
			echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
           	sync
			sync
			sync
            if [ -f /tmp/USB_Process_Canceled ]; then
            	echo "status=canceled" > /tmp/transfer_state
                rm -f /tmp/USB_Process_Canceled
            else
            	if [ "$MTP_WrongMethod" == "1" ]; then
			    			echo "status=UsbReadOnlyfailed" > /tmp/transfer_state
			    		else
			    			echo "status=failed" > /tmp/transfer_state
			    		fi
            fi
            echo "42;125;" > /tmp/MCU_Cmd
			#/sbin/AdaptCPUfreq.sh endbackup
			#killall rsync > /dev/null 2>&1
			#sleep 5
			SD_BackupQueueCheck
			exit 1
		fi    			
	fi
fi

echo ${CID} > /media/sdb1/.wdcache/.${fullCID}
#echo ${CID} > /media/sdb1/USB\ Imports/${CID}/${timestamp}/.${fullCID}
finishSdBackup

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


