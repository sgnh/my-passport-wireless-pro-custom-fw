#!/bin/bash
#
# SDCard_StorageTransfer.sh
#
# Used to triiger Storage Transfer process
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
. /etc/nas/config/sdcard-transfer-status.conf
. /etc/system.conf
source /etc/power.conf
ACMode=`cat /tmp/battery | cut -d " " -f 1`

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
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": AdaptCPUfreq.sh" $@ >> /tmp/backup.log

CPUstatus=`/etc/init.d/S98powerprofile status`
#CPUstatus=`cat /tmp/powerprofilestatus`
#mode=echo "$CPUstatus" | head -1 | cut -d '=' -f 2
speed=`echo "$CPUstatus" | cut -d '=' -f 2`
if [ -f "/tmp/sdstats" ]; then
	BackupStatus=`cat /tmp/sdstats | cut -d '=' -f 2`
fi

if [ "$1" == "startbackup" ]; then
	echo "Adapt CPU Power Profile: "
	if [ "$speed" == "300000" ]; then
		echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
        echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
        Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
        Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
        if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "800000" ]; then
       		echo ">>>>>>>>>>Changing 800000 done"
        fi
	fi
elif [ "$1" == "endbackup" ]; then
	if [ "${speed}" == "800000" ]; then
		echo "Adapt CPU Power Profile: "
		if [ "${powerprofile}" == "max_life" ] && [ "${ACMode}" == "discharging" ] ; then
			echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
			echo 300000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
			Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
			Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
			if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "300000" ]; then
				echo ">>>>>>>>>>>Changing 300000 done"
			else
				echo "failed"
			fi
		fi
	fi
elif [ "$1" == "CheckingCPUfreq" ]; then
	if [ "$BackupStatus" != "running" ]; then
		#echo "CheckingCPUfreq CPU Power Profile: "
		if [ "$speed" == "300000" ]; then
			if [ "${powerprofile}" == "max_system_performance" ] && [ "${ACMode}" == "charging" ] ; then
				echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
				echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
				Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
				Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
				if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "800000" ]; then
					echo ">>>>>>>>>Changing 800000 done"
				else
					echo "failed"
				fi
			fi
    	
			if [ "${powerprofile}" == "max_system_performance" ] && [ "${ACMode}" == "discharging" ] ; then
 				echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
				echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
				Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
				Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
				if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "800000" ]; then
					echo ">>>>>>>>>>Changing 800000 done"
				else
					echo "failed"
				fi
			fi
		
			if [ "${powerprofile}" == "max_life" ] && [ "${ACMode}" == "charging" ] ; then
				echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
				echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
				Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
				Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
				if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "800000" ]; then
					echo ">>>>>>>>>Changing 800000 done"
				else
					echo "failed"
				fi
			fi
    	fi
    	if [ "$speed" == "800000" ]; then
			if [ "${powerprofile}" == "max_life" ] && [ "${ACMode}" == "discharging" ] ; then
				echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
				echo 300000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
				Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
				Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
				if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "300000" ]; then
					echo ">>>>>>>>Changing 300000 done"
				else
					echo "failed"
				fi
			fi
		fi
	else	
		if [ "$speed" == "300000" ]; then
			echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
        	echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
       	 	Current_mode=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor`
        	Current_speed=`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`
        	if [ "${Current_mode}" == "userspace" ] && [ "${Current_speed}" == "800000" ]; then
       			echo ">>>>>>Changing 800000 done"
        	fi
		fi
	fi
fi


exit 0
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


