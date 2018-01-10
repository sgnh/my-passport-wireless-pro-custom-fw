#!/bin/sh
AC=`cat /tmp/battery  | awk '{print $1}'`

if [ "${AC}" == "charging" ]; then
	wlan3_interface=`cat /tmp/monitor.ifconfig | grep -c wlan3`
	if [ ${wlan3_interface} -gt 0 ]; then
		wlan3_stations=`cat /proc/net/rtl8189es/wlan3/all_sta_info | grep -c macaddr`
		if [ ${wlan3_stations} -gt 1 ]; then
			exit 0
		fi
	fi
	wlan1_interface=`cat /tmp/monitor.ifconfig | grep -c wlan1`
	if [ ${wlan1_interface} -gt 0 ]; then
		wlan1_stations=`cat /proc/net/rtl8821au/wlan1/all_sta_info | grep -c macaddr`
		if [ ${wlan1_stations} -gt 1 ]; then
			exit 0
		fi
	fi
	wlan0_interface=`cat /tmp/monitor.ifconfig | grep -c wlan0`
	if [ ${wlan0_interface} -gt 0 ]; then
		wlan0_stations=`cat /proc/net/rtl8821au/wlan0/all_sta_info | grep -c macaddr`
		if [ ${wlan0_stations} -gt 2 ]; then
			exit 0
		fi
	fi
	wlan2_interface=`cat /tmp/monitor.ifconfig | grep -c wlan2`
	if [ ${wlan2_interface} -gt 0 ]; then
		wlan2_stations=`cat /proc/net/rtl8189es/wlan2/all_sta_info | grep -c macaddr`
		if [ ${wlan2_stations} -gt 2 ]; then
			exit 0
		fi
	fi
	detect_trim_device=`mount | grep /media/sdb1 | grep discard | wc -l`
	if [ ${detect_trim_device} -eq 1 ]; then
		echo "`date`-start" > /tmp/fstrim.log
		time fstrim -v /media/sdb1 >> /tmp/fstrim.log
		echo "`date`-end" >> /tmp/fstrim.log
	fi
	exit 0
fi
