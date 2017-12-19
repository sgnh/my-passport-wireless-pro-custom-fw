#! /bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getSystemState.sh
# 	get current system state
#
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ -f "/tmp/ready" ]; then
	echo "ready"
else
	HDDDevNode=`cat /proc/mounts | grep "/media/sdb1" | awk '{print $1}'`
	echo "${HDDDevNode}" > /tmp/HDDDevNode
	Serial=`hdparm -I ${HDDDevNode} | sed -n -e 's/.*Serial Number:\(.*\)/\1/p' | sed -e 's/^[ \t]*//' | awk '{gsub("WD-","",$0); print $0}'`
	DVexit=`cat /proc/mounts | grep DataVolume`
	SSexit=`cat /proc/mounts | grep "/shares/Storage"`
	MSexit=`cat /proc/mounts | grep "/media/sdb1"`
	if [ "${Serial}" != "" ] && [ "${DVexit}" != "" ] && [ "${SSexit}" != "" ] && [ "${MSexit}" != "" ]; then
		#cat /proc/mounts | grep DataVolume | cut -d " " -f 1 > /tmp/HDDDevNode
		touch "/tmp/ready"
	else
		echo "initializing"
	fi
fi
