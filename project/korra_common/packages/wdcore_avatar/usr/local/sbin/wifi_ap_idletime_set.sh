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
	echo $timestamp ": wifi_ap_set_config.sh" $@ >> /tmp/wifiap.log
fi

ErrorCode(){
	echo "/usr/local/sbin/wifi_ap_idletime_get.sh --idle [time]"
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_ap_idletime_get.sh input parameter error" "$1"  >> /tmp/wifiap.log
	fi
	exit 1
}

if [ $# == 0 ]; then
	ErrorCode "--All"
fi


while [ "$1" != "" ]; do
	case "$1" in
		--idle)		shift
					##if [ "$1" != "0" ] && [ "$1" != "1" ] && [ "$1" != "3" ] && [ "$1" != "5" ] && [ "$1" != "10" ]; then
		           	##	ErrorCode "idle time error"
		           	##else 
		           		oldtime=${AP_IDLE_TIME}
		           		if [ "${oldtime}" != "${1}" ]; then
		           			sed -i 's/AP_IDLE_TIME=.*/AP_IDLE_TIME='${1}'/' /etc/nas/config/wifinetwork-param.conf
		           			killall -10 monitor
		           		fi
		           	##fi
					;;
		*)			ErrorCode "--Unknown"
					;;
	esac
	shift
done

exit 0