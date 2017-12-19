#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# monitorVolume.sh 
#  Note: this is called by cron
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf
. /etc/nas/alert-param.sh
. /etc/system.conf
. /etc/wdcomp.d/wd-nas/wd-nas.conf 2> /dev/null

MAX_USAGE_THRESH=95
MIN_USAGE_THRESH=93

# check DataVolume percent used
percentUsed=`getDataVolumePercentUsed.sh`
echo "% used=${percentUsed} MAX=${MAX_USAGE_THRESH}"
if [ -f /tmp/tst_freespace ] || [ "${percentUsed}" -gt "${MAX_USAGE_THRESH}" ]; then
	if [ ! -f ${FREESPACE_STATUS_FILE} ]; then
		sendAlert.sh "${diskNearCapacity}"
	fi
	if [ ! -f ${FREESPACE_STATUS_FILE} ]; then
		touch ${FREESPACE_STATUS_FILE}
		incUpdateCount.pm system_state
	fi
else
	if [ "${percentUsed}" -le "${MIN_USAGE_THRESH}" ]; then
		if [ -f ${FREESPACE_STATUS_FILE} ]; then
			rm -f ${FREESPACE_STATUS_FILE}
			incUpdateCount.pm system_state
		fi
	fi
fi

