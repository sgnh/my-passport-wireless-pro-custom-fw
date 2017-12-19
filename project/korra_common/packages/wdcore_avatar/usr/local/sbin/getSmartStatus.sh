#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getSmartStatus.sh 
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf
. /etc/system.conf

if [ -f /tmp/smart_fail ]; then
	echo "bad"
else
	echo "good"
fi
