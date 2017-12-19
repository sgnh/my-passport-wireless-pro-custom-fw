#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_trust_mode.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/config/wifinetwork-param.conf

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
ifname=$1
ifaction=$2
execRemember=$3

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_trust_mode.sh" $@ >> /tmp/wificlientap.log
fi

if [ "$ifname" != "$STA2G4_IFACE" ] && [ "$ifname" != "$STA_IFACE" ]; then
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_trust_mode.sh fail interface" $ifname >> /tmp/wificlientap.log
	fi
	exit 1
fi
	
interface=`pidof hostapd`
if [ "$interface" != "" ]; then
	AP_Status=true
else
	AP_Status=false
fi

if [ ! -f "/tmp/wifi_client_trust_execute" ]; then
	echo "go trust" > /tmp/wifi_client_trust_execute
	
	connectedmac=`wpa_cli -i "${ifname}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
	if [ "$connectedmac" != "" ]; then
		found_mac=`grep -rsi "${connectedmac}" /etc/nas/config/wifinetwork-remembered.conf`
  		if [ "$found_mac" != "" ]; then
  			UpdateConf=/etc/nas/config/wifinetwork-remembered.conf
  		else
  			found_mac=`grep -rsi "${connectedmac}" /tmp/wifinetwork-remembered.conf`
  			if [ "$found_mac" != "" ]; then
  				UpdateConf=/tmp/wifinetwork-remembered.conf
  			else
  				if [ -f "/tmp/wifi_client_trust_execute" ]; then
  					rm /tmp/wifi_client_trust_execute
  				fi
  				exit 2
  			fi
  		fi
  		
		#connectedCipher=`wpa_cli -i "${ifname}" status | grep -rsw "pairwise_cipher" | awk -F= '{print $NF}'`
		#if [ "$connectedCipher" == "WEP-40" ] || [ "$connectedCipher" == "WEP-104" ]; then
			networkConfig=`/usr/local/sbin/getNetworkConfig.sh`
			if [ "$networkConfig" == "disconnected" ]; then
				if [ -f "/tmp/wifi_client_trust_execute" ]; then
					rm /tmp/wifi_client_trust_execute
				fi
				exit 0
			fi
		#fi	
		#clear file retry count 
		/usr/sbin/iptables -F INPUT
        /usr/sbin/iptables -F OUTPUT
        /usr/sbin/iptables -t nat -F
        /usr/sbin/iptables -t nat -A POSTROUTING -o $ifname -j MASQUERADE
		echo 0 > /tmp/ApCliRetry 
		trusted=`grep -rsi \""${connectedmac}"\" $UpdateConf | awk 'BEGIN {FS="trusted="} {print $2}'| cut -d '"' -f 2 | head -1` 
			if [ "$trusted" == "true" ]; then			
				echo "ShareMode" > /tmp/ConnectionMode
	
				echo "trusted" > /tmp/ifplugd_trust
				
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 80 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 9000 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 1900 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 137:138 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 139 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 445 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 22 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 548 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 21 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 53 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 443 -j DROP > /dev/null 2> /dev/null < /dev/null
				#/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 9443 -j DROP > /dev/null 2> /dev/null < /dev/null
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_trust_mode.sh Delete iptables rule" >> /tmp/wificlientap.log
				fi
				dlnaservice=`getServiceStartup.sh dlna_server`
				if [ "$dlnaservice" == "enabled" ]; then
					route add -net 224.0.0.0 netmask 240.0.0.0 dev "${ifname}"
				fi
				#/usr/sbin/iptables -D INPUT -i wlan0 -p icmp --icmp-type echo-request -j DROP > /dev/null 2> /dev/null < /dev/null
			elif [ "$trusted" == "false" ]; then	
				if [ "$AP_Status" == "false" ]; then
					/usr/local/sbin/wifi_ap_set_config.sh --enabled EnabledHomeNetwork > /dev/null 2> /dev/null < /dev/null
				fi
				echo "untrusted" > /tmp/ifplugd_trust
				echo "ShareMode" > /tmp/ConnectionMode
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 80 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 9000 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 1900 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 137:138 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 139 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 445 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 22 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p udp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 548 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 21 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 53 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 443 -j DROP > /dev/null 2> /dev/null < /dev/null
				#/usr/sbin/iptables -D INPUT -i "${ifname}" -p tcp --dport 9443 -j DROP > /dev/null 2> /dev/null < /dev/null
				#/usr/sbin/iptables -D INPUT -i "${ifname}" -p icmp --icmp-type echo-request -j DROP > /dev/null 2> /dev/null < /dev/null
				
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 80 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 9000 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p udp --dport 1900 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p udp --dport 137:138 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 139 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 445 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 22 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p udp --dport 5353 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 548 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 21 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 53 -j DROP > /dev/null 2> /dev/null < /dev/null
				/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 443 -j DROP > /dev/null 2> /dev/null < /dev/null
				#/usr/sbin/iptables -A INPUT -i "${ifname}" -p tcp --dport 9443 -j DROP > /dev/null 2> /dev/null < /dev/null
				#/usr/sbin/iptables -A INPUT -i "${ifname}" -p icmp --icmp-type echo-request -j DROP > /dev/null 2> /dev/null < /dev/null
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_trust_mode.sh Add iptables rule" >> /tmp/wificlientap.log
				fi
			fi
		
	else
		#connectMode=`cat /tmp/ifplugd_trust`
		echo "nontrusted" > /tmp/ifplugd_trust
		echo "ApMode" > /tmp/ConnectionMode
		echo "192.168.60.1" > /tmp/resolv.conf
		if [  -f "/tmp/InternetConnection" ]; then
			rm -f /tmp/InternetConnection
		fi
		if [  -f "/tmp/Rnum" ]; then
			rm -f /tmp/Rnum
		fi
		sleep 3
		/etc/init.d/S77upnp restart > /dev/null 2>&1 &
		#num_remember=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
		#if [ "${num_remember}" == 0 ]; then
		#	/sbin/wifi-restart STA &
		#fi
	fi
	if [ -f "/tmp/wifi_client_trust_execute" ]; then
		rm /tmp/wifi_client_trust_execute
	fi
fi
