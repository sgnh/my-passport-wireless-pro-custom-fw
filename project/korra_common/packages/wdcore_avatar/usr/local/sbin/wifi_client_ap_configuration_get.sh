#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_configuration_get.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/nas/config/wifinetwork-param.conf

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_configuration_get.sh" $@ >> /tmp/wificlientap.log
fi
if [ "$STA_CLIENT" == "true" ] || [ "$STA_CLIENT" == "false" ]; then
	echo "enabled="$STA_CLIENT
	echo "hunt_time="$STA_HUNT_TIME
else
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_configuration_get.sh Check wpa_supplicant pid"  >> /tmp/wificlientap.log
	fi
	wappid=`pidof wpa_supplicant`
	if [ "$wappid" == "" ]; then
		echo "enabled="false
	else
		echo "enabled="true
	fi
fi

exit 0
