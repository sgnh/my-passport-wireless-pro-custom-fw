#!/bin/sh
#
# WD AM3352 PowerProfile

if [ $# -eq 2 ]; then
	cpu1=`cat /sys/bus/cpu/devices/cpu1/online`
	if [ "$1" == "1" ]; then
		if [ "$cpu1" == "1" ]; then
		echo "Core 2 Off"
		echo 0 > /sys/bus/cpu/devices/cpu1/online
		fi
	fi
	if [ "$1" == "2" ]; then
		if [ "$cpu1" == "0" ]; then
		echo "Core 2 On"
		echo 1 > /sys/bus/cpu/devices/cpu1/online
		fi
		echo $2 > /sys/bus/cpu/devices/cpu1/cpufreq/scaling_max_freq
	fi
	echo $2 > /sys/bus/cpu/devices/cpu0/cpufreq/scaling_max_freq
else
	echo "$0 core freq"
	echo "core: 1|2"
	echo "freq: 400000|500000|720000|800000"
fi
sleep 1
echo "Current CPU Freq:"
cat /sys/bus/cpu/devices/cpu0/cpufreq/scaling_cur_freq
#cpufreq-info | grep CPU



