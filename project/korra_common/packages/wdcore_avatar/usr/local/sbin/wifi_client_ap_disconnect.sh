#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_disconnect.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/config/wifinetwork-param.conf

if [ -f "/tmp/wificlientdisconnect" ]; then
	exit 0
else
	touch /tmp/wificlientinterfacebusy
	touch /tmp/wificlientdisconnect
fi

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_disconnect.sh" $@ >> /tmp/wificlientap.log
fi
ErrorCode(){
	echo "/usr/local/sbin/wifi_client_ap_disconnect.sh --mac <mac_address>"
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_disconnect.sh input parameter error" "$1"  >> /tmp/wificlientap.log
	fi
	rm /tmp/wificlientdisconnect
	rm /tmp/wificlientinterfacebusy
	exit 1
}

CheckAPExist(){

	if [ "$AP_CHANNEL_LITE" == "0" ]; then
		AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
		AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
	
		if [ "${AP1mode}" == "0" ] && [ "${AP2mode}" == "0" ]; then
			/sbin/wifi-restart AP
		elif [ "$AP1mode" == "1" ] && [ "$AP2mode" == "0" ]; then
			/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork
		elif [ "$AP1mode" == "0" ] && [ "$AP2mode" == "1" ]; then
			/usr/local/sbin/wifi_ap_set_config.sh --ism_band 5 --enabled EnabledHomeNetwork
		fi
	elif [ "$AP_CHANNEL_LITE" == "2" ]; then	
		AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
		if [ "$AP2mode" == "0" ]; then
			/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork
		fi
	elif [ "$AP_CHANNEL_LITE" == "5" ]; then
		AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
		if [ "$AP1mode" == "0" ]; then
			/usr/local/sbin/wifi_ap_set_config.sh --ism_band 5 --enabled EnabledHomeNetwork
		fi
	fi
}

if [ $# == 0 ]; then
	ErrorCode "--All"
fi


while [ "$1" != "" ]; do
	case "$1" in
		--mac	)	shift
					string_mac="$1"
					option_connect=disconnect
					;;
					
		*)			ErrorCode "--Unknown"
					;;
	esac
	shift
done

if [ "$option_connect" == "disconnect" ]; then
	if [ "$STA_CHANNEL_LITE" == "0" ]; then
		if [ "${STA_CHANNEL}" == 5 ]; then
			activeIF=${STA_IFACE}
		else
			activeIF=${STA2G4_IFACE}
			#activeIF=${STA_IFACE}
		fi
	elif [ "$STA_CHANNEL_LITE" == "2" ]; then	
		activeIF=${STA2G4_IFACE}
	elif [ "$STA_CHANNEL_LITE" == "5" ]; then	
		activeIF=${STA_IFACE}
	fi
	
	connectMAC=`wpa_cli -i "${activeIF}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
	if [ "${connectMAC}" == "" ]; then
		sleep 3
		connectMAC=`iwconfig "$activeIF" | grep "Access Point" | awk '{print $NF}'`
	fi
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_disconnect.sh connected MAC addr:" "$connectMAC" >> /tmp/wificlientap.log
	fi
	if [ "$connectMAC" == "$string_mac" ]; then
		sed -i 's/connected="true"./connected="false" /' /tmp/scan_result 
		sed -i '/'"${string_mac}"'/ s/remembered="true"./remembered="false" /' /tmp/scan_result 
	
		sed -i 's/connected="true"./connected="false" /' /etc/nas/config/wifinetwork-remembered.conf
		
		#sed -i '/'"${connectMAC}"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
		#sed -i '1d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
		#cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
		#rm /tmp/wifinetwork-remembered_tmp.conf
		rm /tmp/wifinetwork-remembered.conf
		sed -i '/'"${connectMAC}"'/d' /etc/nas/config/wifinetwork-remembered.conf
		
		#wpa_cli -i "${activeIF}" disconnect &
		iw dev "${activeIF}" disconnect
		/sbin/wifi-restart UPDATE_STA_CONF
		wpa_cli -i "${activeIF}" reconfigure
		#/sbin/wifi-restart STA > /dev/null/ 2>&1 &
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_disconnect.sh Disconnecting Target Router"  >> /tmp/wificlientap.log
		fi
		
		#num_remember=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
		sed -i 's/STA_SSID_NAME=.*/STA_SSID_NAME=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_MAC_MAPPING=.*/STA_MAC_MAPPING=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_MAC_ADDRESS=.*/STA_MAC_ADDRESS=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_SECURITY_MODE=.*/STA_SECURITY_MODE=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_CIPHER_TYPE=.*/STA_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY=/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_WEP_KEY=.*/STA_WEP_KEY=/' /etc/nas/config/wifinetwork-param.conf		
		
		CheckAPExist
		#echo "24;00;" > /tmp/MCU_Cmd
		/usr/local/sbin/wifi_client_trust_mode.sh "${activeIF}" down > /dev/null 2>&1 &
		rm /tmp/wificlientinterfacebusy
		#/sbin/wifi_scanning_update.sh > /dev/null 2>&1 &
		
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			profileleft=`cat /etc/nas/config/wifinetwork-remembered.conf`
			echo $timestamp ": wifi_client_ap_disconnect.sh Delete target Profile, latest profile list" >> /tmp/wificlientap.log
			echo $timestamp ": wifi_client_ap_disconnect.sh " $profileleft >> /tmp/wificlientap.log
		fi
		
		rm /tmp/wificlientdisconnect
		
		exit 0
	else
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_disconnect.sh Dismatch Target, Only remove profile" >> /tmp/wificlientap.log
		fi
		sed -i '/'"${string_mac}"'/ s/remembered="true"./remembered="false" /' /tmp/wifinetwork-remembered.conf
		sed -i '/'"${string_mac}"'/d' /etc/nas/config/wifinetwork-remembered.conf
		#sed -i '/'"${string_mac}"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
		#cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
		#cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered.conf
		#rm /tmp/wifinetwork-remembered_tmp.conf
	fi	
fi

rm /tmp/wificlientdisconnect
rm /tmp/wificlientinterfacebusy
exit 0