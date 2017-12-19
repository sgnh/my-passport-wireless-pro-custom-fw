#!/bin/sh
# usage : set_hybrid_list ${ACT} ${MAC}
# ACT 0: set  1: delete

source /etc/nas/config/wifinetwork-param.conf
plist="/etc/nas/hybrid_list"
#plist="/tmp/hybrid_list"
if [ -f "/tmp/WiFiApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": set_hybrid_list.sh" $@ >> /tmp/wifiap.log
fi

ACT=$1
Ip=$2

check_mac_is_valid() {
	MAC_IS_ALNUM=`echo ${MAC} | tr -d "[:digit:]" | tr -d [:ABCDEFabcdef]`
	MAC_LEN=`expr "${MAC}" : '.*'`
	
	if [ $MAC_IS_ALNUM ] || [ $MAC_LEN != 17 ]; then
		echo "Please check the MAC address is valid! (${MAC_LEN})"
		exit 1
	fi
}

mac_to_lower() {
	MAC=`echo $MAC | tr [:upper:] [:lower:]`
}

kick_wifi_client() {
	InternConnect=`/usr/local/sbin/InternetAccess.sh`
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": set_hybrid_list.sh InternConnect" $InternConnect  >> /tmp/wifiap.log
	fi
	if [ "${InternConnect}" == "InternetConnectionFailed" ]; then
		/usr/local/sbin/set_wifi_ap_client_disconnect.sh "${MAC}" "ShortKick" > /dev/null
	fi
}

[ -e $plist ] && echo "$plist exist" || touch $plist

	MAC=`get_wifi_ap_clients.sh | grep "${Ip}" | cut -d '"' -f 2`
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": set_hybrid_list.sh Ip&MacAddress" "${Ip}" $MAC  >> /tmp/wifiap.log
	fi
	
	check_mac_is_valid
	mac_to_lower

	if [ $ACT -eq 0 ]; then
		exist=`cat $plist | grep $MAC`
		if [ -z "$exist" ]; then 
			echo "${MAC}" >> $plist
			kick_wifi_client
			if [ -f "/etc/nas/hybrid_list" ]; then
                cp -a /etc/nas/hybrid_list /tmp/
            fi
		fi
	else
		sed -i "/${MAC}/d" $plist
		kick_wifi_client
	fi	
	
exit 0

