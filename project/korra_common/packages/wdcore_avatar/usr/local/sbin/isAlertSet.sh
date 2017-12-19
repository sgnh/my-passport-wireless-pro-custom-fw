#!/bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# isAlertSet.sh <alert code> 
#     Check if alert has been set.  Returns 0 if alert is set, 1 if not set.
#
# Note: alert codes /etc/alert-param.sh
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/alert-param.sh

if [ $# -lt 1 ]; then
    echo "Usage: isAlertSet.sh <alert_code>"
    exit 1
fi

alertCode=$1
alertdb="/CacheVolume/.wd-alert/wd-alert.db"
if [ -s "${alertdb}" ]; then
    alert=`sqlite3 "${alertdb}" "SELECT * FROM AlertHistory where alert_code=${alertCode}"`
	if [ ! -z "$alert" ]; then
		exit 0
	fi
fi
exit 1

