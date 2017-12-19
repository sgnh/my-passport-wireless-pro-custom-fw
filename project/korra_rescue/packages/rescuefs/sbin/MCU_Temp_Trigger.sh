#!/bin/sh
#source /etc/power.conf

#if [ "${powerprofile}" == "max_life" ]; then
#    if [ -f /tmp/BatteryNormalStart ]; then
#        rm /tmp/BatteryNormalStart
#    fi
#    if [ -f /tmp/ChangePerformance ]; then
#        rm /tmp/ChangePerformance
#    fi
#    if [ -f /tmp/BatteryTempCritical ]; then
#        rm /tmp/BatteryTempCritical
#    fi
#    exit 0
#fi

if [ -f /tmp/BatteryTempCritical ]; then
    if [ "$1" -lt "47" ]; then
        if [ -f /tmp/BatteryNormalStart ]; then
            now_time=`date "+%s"`
            start_time=`cat /tmp/BatteryNormalStart`
            time_diff=`expr $now_time - $start_time`
            if [ "$time_diff" -gt "1800" ]; then
                touch /tmp/ChangePerformance
                rm /tmp/BatteryTempCritical
                rm /tmp/BatteryNormalStart
            fi
        else
            date +%s > /tmp/BatteryNormalStart
        fi
    else
        if [ -f /tmp/BatteryNormalStart ]; then
            rm /tmp/BatteryNormalStart
        fi
    fi
else
    if [ "$1" -gt "55" ]; then
        echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
        echo 300000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
        touch /tmp/BatteryTempCritical
    fi
fi

if [ -f /tmp/ChangePerformance ]; then
    echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
    echo 800000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
    rm /tmp/ChangePerformance
fi

