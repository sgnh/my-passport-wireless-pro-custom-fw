#!/bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getTemperatureStatus.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/wdcomp.d/wd-nas/temperature-monitor.conf


Hd_temp=`cat /tmp/mcuTemperature | awk '{ print $4}'`

if [ ${Hd_temp} -le ${TEMP_T1} ]; then
	echo "good"
elif [ ${Hd_temp} -gt ${TEMP_T1} ] && [ ${Hd_temp} -le ${TEMP_T2} ]; then
	echo "warn"
elif [ ${Hd_temp} -gt ${TEMP_T2} ]; then
	echo "bad"
else
	echo "unknown"
fi

