#!/bin/sh


powerprofile=`/usr/local/sbin/power_get_profile.sh`
if [ "$powerprofile" == "max_life" ] && [ -f "/tmp/DisableWake" ]; then
	AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
	AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
	if [ "$AP2mode" == "0" ]; then
		/sbin/wifi-restart AP wlan2 
	fi
	if [ "$AP1mode" == "0" ]; then
		/sbin/wifi-restart AP wlan0 
	fi
	
	rm /tmp/DisableWake
fi

exit 0
