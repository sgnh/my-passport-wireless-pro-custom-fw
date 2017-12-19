#!/bin/bash
#
#
# power_get_battery_status_performance.sh 
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/power.conf

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------

if [ "${powerprofile}" == "max_system_performance" ] ; then
	BatteryLevel=`cat /tmp/battery | cut -d " " -f 2`
	echo "charging $BatteryLevel"
else
	if [ -f /tmp/battery ]; then
		cat /tmp/battery
	else
		echo "charging 0" 
	fi
fi

#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}