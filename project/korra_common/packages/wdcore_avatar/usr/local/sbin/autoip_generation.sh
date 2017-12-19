#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# autoip_generation.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/nas/config/wifinetwork-param.conf
DHCPD_CONF_PATH="/etc/dhcpd.conf"
AP_interface=br0

interface=$1

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": autoip_generation.sh" $@ >> /tmp/wificlientap.log
fi

if [ "$interface" != "$STA2G4_IFACE" ] && [ "$interface" != "$STA_IFACE" ]; then
	exit 1
fi

ReGenerateProfile(){
	wifi_client_remembered.sh > /dev/null 2>&1 &
}
RestartService(){
	sleep 15
	/etc/init.d/S77upnp restart
	/etc/init.d/S50avahi-daemon restart
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

function RefreshDHCPconf(){
	newip="$1"
	
	AP_SUBNET="${newip%.*}.0"
    AP_DHCP_UPPER_BOUND="${newip%.*}.100"
    AP_DHCP_LOWER_BOUND="${newip%.*}.200"
	
    sed -i '111,$d' $DHCPD_CONF_PATH

    echo "option routers $newip;"                                   >> $DHCPD_CONF_PATH
    echo "option domain-name-servers $newip;"                       >> $DHCPD_CONF_PATH
    echo " "                                                        >> $DHCPD_CONF_PATH
    echo "subnet $AP_SUBNET netmask $AP_MASK {"                     >> $DHCPD_CONF_PATH
    echo "    pool {"                                               >> $DHCPD_CONF_PATH
    echo "        max-lease-time 86400;"                            >> $DHCPD_CONF_PATH
    echo "        range $AP_DHCP_UPPER_BOUND $AP_DHCP_LOWER_BOUND;" >> $DHCPD_CONF_PATH
    echo "        option routers $newip;"                           >> $DHCPD_CONF_PATH
    echo "        option domain-name-servers $newip, $AP_DNS;"      >> $DHCPD_CONF_PATH
    echo "        allow unknown-clients;"                           >> $DHCPD_CONF_PATH
    echo "    }"                                                    >> $DHCPD_CONF_PATH
    echo "}"                                                        >> $DHCPD_CONF_PATH
}

if [ ! -f "/tmp/AutoIP_Generation" ]; then
	wlan0_if=`ifconfig | grep ^${interface}`
	if [ "$wlan0_if" != "" ]; then
		echo "go auto ip" > /tmp/AutoIP_Generation
		sleep 40
		
		trust=`cat /tmp/ifplugd_trust`
		if [ "${trust}" == "untrusted" ]; then
			CheckAPExist
		fi
		#connectedCipher=`wpa_cli -i "${interface}" status | grep -rsw "pairwise_cipher" | awk -F= '{print $NF}'`
		#if [ "$connectedCipher" == "WEP-40" ] || [ "$connectedCipher" == "WEP-104" ]; then
			networkConfig=`/usr/local/sbin/getNetworkConfig.sh`
			if [ "$networkConfig" == "disconnected" ]; then
				rm /tmp/AutoIP_Generation
				exit 0
			fi
		#fi
		
		connectedmac=`wpa_cli -i "${interface}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
		connectStatus=`wpa_cli -i "${interface}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
		connectedip=`wpa_cli -i "${interface}" status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
		if [ "$connectedip" == "" ]; then
			/sbin/ifup "${interface}"
			sleep 3
			/sbin/ifup "${interface}"
		fi
		connectedip=`wpa_cli -i "${interface}" status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
		connectedipblock=`wpa_cli -i "${interface}" status | grep -rsw "ip_address" | awk -F= '{print $NF}'| awk -F. '{print $1"."$2"."$3}'`
		autoIp=`wpa_cli -i "${interface}" status | grep -rsw "ip_address" | awk -F= '{print $NF}' | awk -F. '{print $1"."$2}'`
		ApIP=`wifi_ap_get_config.sh INTERNAL_QUERY | grep "ip=" | awk -F= '{print $2}' | cut -d '"' -f 2 | awk -F. '{print $1"."$2"."$3}'`
		
		if [ "$connectedip" == "" ] || [ "$autoIp" == "169.254" ]; then
			if [ "$connectedmac" != "" ] && [ "$connectStatus" == "COMPLETED" ]; then
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": autoip_generation.sh auto ip generation" "$connectedip" "$connectedmac" "$connectStatus" >> /tmp/wificlientap.log
				fi
				/etc/init.d/S50avahi-daemon stop
				killall avahi-autoipd
				avahi-autoipd --wait --daemonize "${interface}"
				route add -net 224.0.0.0 netmask 240.0.0.0 dev "${interface}"
				route add -net 0.0.0.0 netmask 0.0.0.0 dev "${interface}" metric 1000
			fi
		elif [ "$ApIP" == "$connectedipblock" ]; then
			Ap_1=`wifi_ap_get_config.sh INTERNAL_QUERY | grep "ip=" | awk -F= '{print $2}' | cut -d '"' -f 2 | awk -F. '{print $1}'`
			Ap_2=`wifi_ap_get_config.sh INTERNAL_QUERY | grep "ip=" | awk -F= '{print $2}' | cut -d '"' -f 2 | awk -F. '{print $2}'`
			Ap_3=`wifi_ap_get_config.sh INTERNAL_QUERY | grep "ip=" | awk -F= '{print $2}' | cut -d '"' -f 2 | awk -F. '{print $3}'`
			if [ "$Ap_3" == "254" ]; then
				Ap_3=0
			else
				Ap_3=`expr $Ap_3 + 1`
			fi
			Ap_4=`wifi_ap_get_config.sh INTERNAL_QUERY | grep "ip=" | awk -F= '{print $2}' | cut -d '"' -f 2 | awk -F. '{print $4}'`
			newAPIP=$Ap_1"."$Ap_2"."$Ap_3"."$Ap_4
			echo $newAPIP > /tmp/autoIPgeneration
			wlan1_if=`ifconfig | grep ^$AP_interface`
			if [ "$wlan1_if" != "" ]; then 
				wifi_ap_set_config.sh --enabled true --ism_band "2.4" --ip "$newAPIP" 
			else
				ifconfig ${AP_interface} ${newAPIP} up
				sed -i 's/AP_IP=.*/AP_IP='${newAPIP}'/' /etc/nas/config/wifinetwork-param.conf
				ifconfig ${AP_interface} down
				RefreshDHCPconf ${newAPIP}
			fi
			sleep 10
			/etc/init.d/S90multi-role restart
		fi
		RestartService > /dev/null 2>&1 & 
		rm /tmp/AutoIP_Generation
	fi
fi 
