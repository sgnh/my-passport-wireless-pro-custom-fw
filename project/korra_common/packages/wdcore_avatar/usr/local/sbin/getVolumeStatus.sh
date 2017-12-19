#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getFreeSpaceStatus.sh 
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf
. /etc/system.conf

sdb1=`mount | grep /media/sdb1 | wc -l`
if [ $sdb1 -eq 0 ]; then
	echo "bad"
	exit 0
fi

datavolume=`mount | grep /DataVolume | wc -l`
if [ $datavolume -eq 0 ]; then
	echo "bad"
else
	echo "good"
fi
exit 0
#if [ -f /tmp/volume_failed ]; then
#	echo "bad"
#else
#	echo "good"
#fi
