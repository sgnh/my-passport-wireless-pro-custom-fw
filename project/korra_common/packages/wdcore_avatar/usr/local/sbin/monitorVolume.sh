#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# monitorVolume.sh 
#  Note: this is called by cron
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/alert-param.sh
. /etc/system.conf
[ -f /usr/local/sbin/ledConfig.sh ] && . /usr/local/sbin/ledConfig.sh
. /usr/local/sbin/data-volume-config_helper.sh

lockFile="/tmp/monitorVolume"

# exit if in standby, or factory restore in progress
if [ -f /tmp/standby ] || [ -f ${reformatDataVolume} ]; then
	exit 0;
fi

# exit if system has no internal drives
driveList=( `internalDrives` )
if [ "${driveList[@]}" == "0" ]; then
    exit 0
fi

# exit if already another instance of script is in progress
lockfile-create --retry 0 "${lockFile}" >/dev/null 2>&1
if [ $? -ne 0 ]; then
    exit 0
fi

# If script were to take longer than 5 minutes
lockfile-touch ${lockFile} &
pid="$!"

df | grep -q ${dataVolumeDevice}
if [ $? -ne 0 ] || [ -f /tmp/tst_volume ]; then
	if [ ! -f /tmp/volume_failed ]; then
		sendAlert.sh "${volumeFailure}"
		incUpdateCount.pm system_state
	fi
    ledCtrl.sh LED_EV_VOLUME LED_STAT_ERR
	touch /tmp/volume_failed

    # clean up mutual exclusion
    kill "${pid}" >/dev/null 2>&1
    lockfile-remove ${lockFile} >/dev/null 2>&1

	exit 0
else
	rm -f /tmp/volume_failed
fi


# clean up mutual exclusion
kill "${pid}" >/dev/null 2>&1
lockfile-remove ${lockFile} >/dev/null 2>&1
