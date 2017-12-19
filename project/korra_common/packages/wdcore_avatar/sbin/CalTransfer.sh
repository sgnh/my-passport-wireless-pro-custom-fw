#!/bin/bash
#
total=`cat /tmp/transfer_size_total`
size=`cat /tmp/transfer_size`
state=`cat /tmp/transfer_state`

ExistupdateCount=10
transferDoneSize=0
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": CalTransfer.sh Start" $total $size $state $exist >> /tmp/backup.log

while [ `cat /tmp/transfer_state | sed -n 's/.*=//p'` == "running" ]; do
	exist=`cat /tmp/transferExistSize`

	total=`cat /tmp/transfer_size_total`
	size=`cat /tmp/transfer_size`
	state=`cat /tmp/transfer_state`

	#timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	#echo $timestamp ": CalTransfer.sh RUN" $backupFolder $total $size $state $exist >> /tmp/backup.log
	if [ "${exist}" != 0 ]; then
		divide=`expr ${exist} / 10`
		#echo $timestamp ": CalTransfer.sh old divide:" ${divide} >> /tmp/backup.log
		#echo $timestamp ": CalTransfer.sh old transferDoneSize:" ${transferDoneSize} >> /tmp/backup.log
		if [ -f "/tmp/getStorageTransferStatus" ] ;then
			if [ "${divide}" == "" ]; then
				divide=0
			fi
			if [ "${transferDoneSize}" == "" ]; then
				transferDoneSize=0
			fi
			transferDoneSize=`expr ${transferDoneSize} + ${divide}`
			#echo $timestamp ": CalTransfer.sh new transferDoneSize:" ${transferDoneSize} >> /tmp/backup.log
			#echo $timestamp ": CalTransfer.sh new divide:" ${divide} >> /tmp/backup.log
			if [ "${exist}" -gt "${transferDoneSize}" ]; then
				echo "transferred_size_in_bytes=""$transferDoneSize" > /tmp/transfer_size
			fi
			if [ "${transferDoneSize}" != "" ]; then
				echo "${transferDoneSize}" > /tmp/transferDoneSize
			fi
			rm /tmp/getStorageTransferStatus
		fi
	else
		transferDoneSize=`cat /tmp/transferDoneSize`
		if [ "${transferDoneSize}" == "" ]; then
				transferDoneSize=0
		fi
		
		if [ -f "/tmp/runningBackupDst" ]; then
			backupFolder=`cat /tmp/runningBackupDst`
		fi
		if [ "${backupFolder}" != "" ]; then
			#rsyncCt=`ps aux | grep rsync | grep rv | wc -l`
			#if [ "$rsyncCt" -le 1 ]; then
			DoneSize=`rsync -rv "${backupFolder}" | grep "total size is" | awk '{print $4}' | sed -n 's/,//gp'`
			#RsyncExecmd="du -s \"${backupFolder}\" > /tmp/DoneSize"
			#eval "$RsyncExecmd"
			#folderSizeKB=`cat /tmp/DoneSize | awk '{print $1}'`
			#DoneSize=`expr "${folderSizeKB}" \* 1024`
	
			if [ "$DoneSize" == "" ]; then
				DoneSize=0
			fi
			OrigSize=`cat /tmp/backedupsize`
			if [ "$OrigSize" == "" ]; then
				OrigSize=0
			fi
			if [ "$OrigSize" -gt "$DoneSize" ]; then
				transferredSize=`expr $OrigSize - $DoneSize + $transferDoneSize`
			else
				transferredSize=`expr $DoneSize - $OrigSize + $transferDoneSize`
			fi
			
			if [ "$transferredSize" -gt "$total" ]; then
				transferredSize=$total
			fi
			echo "transferred_size_in_bytes=""$transferredSize" > /tmp/transfer_size
			#fi
	
		else
			echo "transferred_size_in_bytes=0" > /tmp/transfer_size
		fi
	fi
	
	sdpct=0
    sdpct=`expr \`cat /tmp/transfer_size | cut -d "=" -f 2\` \* 100 / \`cat /tmp/transfer_size_total | cut -d "=" -f 2\``
    echo "$sdpct" > /tmp/sdpct                            
    if [ $sdpct -ge 25 ] && [ $sdpct -lt 50 ]; then
		echo "42;25" > /tmp/MCU_Cmd                                                                
    elif [ $sdpct -ge 50 ] && [ $sdpct -lt 75 ]; then
		echo "42;50" > /tmp/MCU_Cmd
    elif [ $sdpct -ge 75 ] && [ $sdpct -lt 100 ]; then
        echo "42;75" > /tmp/MCU_Cmd              
    elif [ $sdpct -ge 100 ] ; then               
        echo "42;100" > /tmp/MCU_Cmd
    fi
    sleep 5
done

total=`cat /tmp/transfer_size_total`
size=`cat /tmp/transfer_size`
state=`cat /tmp/transfer_state`
#echo "42;100" > /tmp/MCU_Cmd
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": CalTransfer.sh END" $backupFolder $total $size $state >> /tmp/backup.log

if [ -f "/tmp/getStorageTransferStatus" ] ;then
	rm /tmp/getStorageTransferStatus
fi

#rsync_pid=`pidof rsync`
#if [ "${rsync_pid}" != "" ]; then
#	kill -15 ${rsync_pid}
#fi
