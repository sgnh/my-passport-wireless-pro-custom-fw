#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# monitorSmartStatus.sh
#  Note: this is called by cron 
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin


. /etc/nas/alert-param.sh
. /usr/local/sbin/data-volume-config_helper.sh 2>/dev/null
[ -f /usr/local/sbin/ledConfig.sh ] && . /usr/local/sbin/ledConfig.sh
. /etc/system.conf

# exit if in standby
if [ -f /tmp/standby ]; then
	exit 0;
fi

# exit if system has no internal drives
driveList=( `internalDrives` )
if [ "${driveList[@]}" == "0" ]; then
    exit 0
fi

atLeastOneDriveFailed=FALSE
for drive in "${driveList[@]}"
do
    smartctl -d ata -H ${drive} | grep -q PASSED
    if [ $? -ne 0 ]; then
        atLeastOneDriveFailed=TRUE
    fi
done

if [ "$atLeastOneDriveFailed" = "TRUE" ] || [ -f /tmp/tst_smart ]; then
	if [ ! -f /tmp/smart_fail ]; then
		sendAlert.sh "${driveSmartFail}"
		ledCtrl.sh LED_EV_DISK_SMART LED_STAT_ERR
		incUpdateCount.pm system_state
	fi
	touch /tmp/smart_fail
else
	rm -f /tmp/smart_fail
fi
