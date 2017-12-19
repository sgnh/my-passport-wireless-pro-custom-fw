#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getSystemHealth.sh 
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf
. /etc/system.conf

if [ "`getVolumeStatus.sh`" == "bad" ] || [ "`getTemperatureStatus.sh`" == "bad" ] || [ "`getSmartStatus.sh`" == "bad" ]; then
	echo "bad"
else
	echo "good"
fi
