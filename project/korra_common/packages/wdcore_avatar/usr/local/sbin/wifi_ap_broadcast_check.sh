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
#if [ "$Debugmode" == "1" ]; then
#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
#	echo $timestamp ": wifi_ap_broadcast_check.sh" $@ >> /tmp/wifiap.log
#fi

ErrorCode(){
	echo "/usr/local/sbin/wifi_ap_broadcast_check.sh"
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_ap_broadcast_check.sh input parameter error" "$1"  >> /tmp/wifiap.log
	fi
	exit 1
}

iface=$1

#if [ "$AP_CHANNEL_LITE" == "0" ]; then
	if [ "$iface" == "AP2G4" ]; then
		if [ "$AP_HOTSPOT" == "true" ]; then
			ap1=`cat /proc/net/rtl8189es/wlan2/ap_info | grep "SSID"`
			if [ "$ap1" != "" ]; then
				echo "1"
			else
				echo "0"
			fi
		else
			echo "-1"	
		fi
	elif [ "$iface" == "AP5G" ]; then
	 	if [ "$AP5G_HOTSPOT" == "true" ]; then
			ap2=`cat /proc/net/rtl8821au/wlan0/ap_info | grep "SSID"`
			if [ "$ap2" != "" ]; then
				echo "1"
			else
				echo "0"
			fi
		else
			echo "-1"
		fi
	else
		echo "-1"
	fi

#fi
exit 0