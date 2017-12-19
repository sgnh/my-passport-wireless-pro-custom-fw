#!/bin/sh

ACMode=`cat /tmp/battery | cut -d " " -f 1`
if [ "${ACMode}" == "discharging" ] ; then
	for diskvolume in /sys/bus/scsi/devices/*; do
		if [ -f "$diskvolume/vendor" ] && [ -f "$diskvolume/model" ] ; then
			vendor=`cat "$diskvolume/vendor" | awk '{print $1}'`
			model=`cat "$diskvolume/model"`
			if [ "$vendor" == "WD" ] && [ "$model" == "My Passport 083C" ]; then
				cat "$diskvolume/power/runtime_status"
				exit 1
			fi
		fi
	done
else
	powerstatus=`hdparm -C \`cat /tmp/HDDDevNode\` | grep active | wc -l`
	if [ "${powerstatus}" == 1 ]; then
		echo "active"
	else
		echo "suspended"
	fi
fi
