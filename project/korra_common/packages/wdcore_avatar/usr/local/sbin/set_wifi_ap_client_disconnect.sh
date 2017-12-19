#!/bin/sh
source /etc/nas/config/wifinetwork-param.conf
plist="/tmp/block_mac"

if [ "$1" == "" ]; then
	echo "error"
	exit 1
fi

method="${2}"

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": set_wifi_ap_client_disconnect.sh" $1 $2  >> /tmp/wifiap.log
fi

check_mac_is_valid() {
	MAC_IS_ALNUM=`echo ${mac} | tr -d "[:digit:]" | tr -d [:ABCDEFabcdef]`
	MAC_LEN=`expr "${mac}" : '.*'`
	
	if [ $MAC_IS_ALNUM ] || [ $MAC_LEN != 17 ]; then
		echo "Please check the MAC address is valid! (${MAC_LEN})"
		exit 1
	fi
}

[ -e $plist ] && echo "$plist exist" || touch $plist

mac=`echo $1 | tr [A-Z] [a-z]`
check_mac_is_valid


if [ "$AP_CHANNEL_LITE" == "0" ]; then
	if [ "${AP5G_HOTSPOT}" == "true" ]; then
		checkconnect=`hostapd_cli -i "${AP5G_IFACE}" sta "${mac}" | grep "${mac}"`
		if [ "${checkconnect}" != "" ]; then
			if [ "${method}" == "ShortKick" ]; then
				hostapd_cli -i "${AP5G_IFACE}" disassociate "${mac}" > /dev/null
				iw dev "${AP5G_IFACE}" station del "${mac}" > /dev/null		 
			else
				exist=`cat $plist | grep $mac`
				if [ -z "$exist" ]; then
					echo "${mac}" >> $plist
					
					/sbin/wifi_ap_kick_client.sh "${AP5G_IFACE}" "${mac}" > /dev/null 2>&1 &
					
				fi
			fi
		fi
	fi
	if [ "${AP_HOTSPOT}" == "true" ]; then
		checkconnect=`hostapd_cli -i "${AP_IFACE}" sta "${mac}" | grep "${mac}"`
		if [ "${checkconnect}" != "" ]; then
			if [ "${method}" == "ShortKick" ]; then
				hostapd_cli -i "${AP_IFACE}" disassociate $mac > /dev/null
				iw dev "${AP_IFACE}" station del "${mac}" > /dev/null
			else
				exist=`cat $plist | grep $mac`
				if [ -z "$exist" ]; then 
					echo "${mac}" >> $plist
					/sbin/wifi_ap_kick_client.sh "${AP_IFACE}" "${mac}" > /dev/null 2>&1 &
				fi
			fi
		fi
	fi
elif [ "$AP_CHANNEL_LITE" == "2" ]; then	
	hostapd_cli -i "${AP_IFACE}" disassociate $mac
	iw dev "${AP_IFACE}" station del "${mac}"
elif [ "$AP_CHANNEL_LITE" == "5" ]; then	
	hostapd_cli -i "${AP5G_IFACE}" disassociate $mac
	iw dev "${AP5G_IFACE}" station del "${mac}"		
fi

OUT=$?
exit $OUT
