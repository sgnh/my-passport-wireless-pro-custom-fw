#!/bin/sh
#
#Sent alert for unsupport storage or filesystem
#
#
#

fs_support1=ntfs
fs_support2=vfat
fs_support3=exfat
fs_support4=hfsplus

if [ $# == 0 ]; then
	exit 1
fi

if [ -f /tmp/CID ]; then
	vendor=`awk -F"_" '{print $1}' /tmp/CID`
	model=`awk -F"_" '{print $2}' /tmp/CID`
	SN=`awk -F"_" '{print $3}' /tmp/CID`
fi

if [ -f /tmp/SDDevNode ]; then              
	SDDevNode=`cat /tmp/SDDevNode`
	blkid ${SDDevNode}1 | grep LABEL > /dev/null
	if [ $? == "0" ]; then
		Label=`blkid ${SDDevNode}1 | awk -F"=" '{print $2}' | awk '{print $1}'`	
		FS=`blkid ${SDDevNode}1 | awk -F"=" '{print $4}' | awk '{print $1}'`	
	else
		Label="NULL"
		FS=`blkid ${SDDevNode}1 | awk -F"=" '{print $3}' | awk '{print $1}'`
	fi
fi

#echo "vemdor:$vendor model:$model SN=:$SN Label:$Label FS:$FS"

#check SD card unsupport
if [ "$1" == "UnsprtSD" ]; then                                                                               
	/usr/local/sbin/sendAlert.sh 1004 Unknown Unknown Unknown                                                                                                       
	exit 0
fi 

# check SD card
if [ "$1" == "SDcard" ]; then
	#SDgpio=`cat /sys/kernel/debug/gpio | grep gpio-31 | awk '{print $5}'`
	SDmountpoint=`ls /dev/mmcblk0*`
	if [ "${SDmountpoint}" != "" ]; then
			#blkid | grep "$3" | grep "${fs_support1}\|${fs_support2}\|${fs_support3}\|${fs_support4}" > /dev/null
			blkid ${SDDevNode}1 | grep "${fs_support1}\|${fs_support2}\|${fs_support3}\|${fs_support4}" > /dev/null
			if [ "$?" != 0 ]; then
				#/usr/local/sbin/sendAlert.sh 1005 $vendor $model $SN $FS $Label
				/usr/local/sbin/sendAlert.sh 1617 $vendor $model $SN
			fi
	fi
fi

#if [ "$1" == "sdb1_fuse" ]; then
#check file system of HDD
#	blkid | grep "$3" | grep "${fs_support1}\|${fs_support2}\|${fs_support3}\|${fs_support4}" > /dev/null
#	if [ "$?" != 0 ]; then
#		/usr/local/sbin/sendAlert.sh 1121
#	fi
#check mount HDD
#	mount | grep "sdb1_fuse" > /dev/null
#	if [ $? -ne 0 ]; then
#		/usr/local/sbin/sendAlert.sh 0201
#		/usr/local/sbin/incUpdateCount.pm system_state &
#	fi
#fi

if [ "$1" == "sda1" ]; then
#check file system of HDD
	blkid /dev/$1 | grep "$3" | grep "${fs_support1}\|${fs_support2}\|${fs_support3}\|${fs_support4}" > /dev/null
	if [ "$?" != 0 ]; then
		/usr/local/sbin/sendAlert.sh 1121
	fi

#check mount HDD
	mount | grep "sda1" > /dev/null
	if [ $? -ne 0 ]; then
		/usr/local/sbin/sendAlert.sh 0201
		/usr/local/sbin/incUpdateCount.pm system_state &
	fi
fi
