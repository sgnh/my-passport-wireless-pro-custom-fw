#!/bin/bash
#
#
# wifi_ap_get_config.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/wifinetwork-param.conf 2>/dev/null

if [ -f "/tmp/WiFiApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_ap_idletime_get.sh" $@ >> /tmp/wifiap.log
fi

ErrorCode(){
	echo "/usr/local/sbin/wifi_ap_idletime_get.sh"
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_ap_idletime_get.sh input parameter error" "$1"  >> /tmp/wifiap.log
	fi
	exit 1
}

echo "idle=""$AP_IDLE_TIME"

exit 0