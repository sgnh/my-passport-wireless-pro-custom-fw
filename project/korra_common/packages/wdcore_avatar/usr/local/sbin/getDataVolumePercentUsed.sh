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

dfout=`df | grep /DataVolume`

if [ "$1" == "precise" ]; then
    percent=`echo "$dfout" | awk '{printf("%.10f\n",($3*100/$2 + 1)) }'`
else
    percent=`echo "$dfout" | awk '{printf("%.0f\n",($3*100/$2 + 1)) }'`
fi

echo $percent
