#!/bin/bash
#
# ï¿?2010 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_update.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
source /etc/nas/config/wifinetwork-param.conf
if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
option_mac=$1
restartSTA=0
maclone=false
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_update_V2.sh" $@ >> /tmp/wificlientap.log
fi

ErrorCode(){
	echo "wifi_client_ap_update_V2.sh --mac <mac_address> [--trusted true|false] [--remember_network true|false] \
[--dhcp_enabled true|false [--ip <ip>] [--netmask <netmask> ] [--gateway <gateway> ] [--dns0 <dns0> ] \
[--dns1 <dns1>] [--dns2 <dns2>]] [--mac_clone_enable < mac_clone_enable >] \
[--clone_mac_address  < clone_mac_address >]"

	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_update_V2.sh input parameter error" "$1"  >> /tmp/wificlientap.log
	fi
	exit 1
}

if [ "$STA_CHANNEL_LITE" == "0" ]; then
	if [ "${STA_CHANNEL}" == 5 ]; then
		activeIF="${STA_IFACE}"
	else
		#activeIF=${STA_IFACE}
		activeIF="${STA2G4_IFACE}"
	fi
elif [ "$STA_CHANNEL_LITE" == "2" ]; then
	activeIF="${STA2G4_IFACE}"
elif [ "$STA_CHANNEL_LITE" == "5" ]; then
	activeIF="${STA_IFACE}"
fi

 

RestartService(){
	/etc/init.d/S77upnp restart
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

function trans_to_hex {
	for i in $(echo $1 | sed -e "s/\./ /g"); do  
      	printf '%02x' $i >/dev/null 2>/dev/null < /dev/null
    done
}

if [ $STA_CLIENT == "true" ]; then
	connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi "wpa_state" | awk -F= '{print $NF}'`
fi

if [ "$option_mac" == "--mac" ]; then
  	string_mac=$2
  	found_mac=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf`
  	if [ "$found_mac" != "" ]; then
  		UpdateConf=/etc/nas/config/wifinetwork-remembered.conf
  	else
  		found_mac=`grep -rsi "${string_mac}" /tmp/wifinetwork-remembered.conf`
  		if [ "$found_mac" != "" ]; then
  			UpdateConf=/tmp/wifinetwork-remembered.conf
  		else
  			exit 2
  		fi
  	fi
  	#if [ "$Debugmode" == "1" ]; then
  	#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	#	echo $timestamp ": wifi_client_ap_update_V2.sh update Profile from" >> /tmp/wificlientap.log
	#	echo $timestamp ": wifi_client_ap_update_V2.sh" "$UpdateConf" >> /tmp/wificlientap.log
	#	echo $timestamp ": wifi_client_ap_update_V2.sh update Profile" >> /tmp/wificlientap.log
	#	echo $timestamp ": wifi_client_ap_update_V2.sh" "$found_mac" >> /tmp/wificlientap.log
  	#fi
else
	ErrorCode "--mac"
	exit 1	
fi

if [ "$3" == "" ]; then
	ErrorCode "NOT enough prarmeter"
	exit 1
fi 

while [ "$3" != "" ]; do
   case $3 in
       --trusted )             shift
                               trusted=$3
                               opt_trusted=true
                               if [ "$trusted" != "true" ] && [ "$trusted" != "false" ]; then
                               		ErrorCode "--trusted"
                                 	exit 1                        
                               fi
                               ;;

       --remember_network )    shift
                               remember=$3
                               opt_remember=true
                               if [ "$remember" == "true" ]; then
                               		b_remember=true
                               else
                                 	if [ "$remember" == "false" ]; then
                               	  		b_remember=false
                                 	else
                                 		ErrorCode "--remember_network"
                                 		exit 1
                                 	fi
                               fi
                               ;;
       --dhcp_enabled )			if [ "$4" != "true" ] && [ "$4" != "false" ]; then
        							ErrorCode "--dhcp_enabled"
        						else
        							shift
       								clientDHCP="$3"
       								opt_networkConfig=true
        						fi
       							;;
      --ip )					trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
      								shift
									 clientIp="$3"
									 opt_networkConfig=true
								else
									ErrorCode "--ip"
								fi
      								;;
    	--netmask )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientmask="$3"
									opt_networkConfig=true
								else 
									ErrorCode "--netmask"
								fi
       							;;

    	--gateway )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientgw="$3"
									opt_networkConfig=true
								fi
        						;;
       	--dns0 )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientdns0="$3"
									opt_networkConfig=true
								fi
        						;;
       	--dns1 )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientdns1="$3"
									opt_networkConfig=true
								fi
        						;;
      	--dns2 )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientdns2="$3"
									opt_networkConfig=true
								fi
        						;;
        						
       --mac_clone_enable )		if [ "$4" != "true" ] || [ "$4" != "false" ]; then
        							shift		
        							opt_clone=true					
        							maclone="$3"
        						fi
        						;;
        
        --cloned_mac_address )	if [ "$maclone" == "true" ]; then
        							shift
        							if [ "$3" == "" ]; then
        								ErrorCode "--cloned_mac_address"
        							else
        								cloneaddr="$3"
        							fi
        						fi
        						;;

       * )                     ErrorCode "--Unknown parameter"
                               exit 1
   esac
   shift
done

if [ "$clientDHCP" == "false" ]; then
	if [ "$clientIp" == "" ] || [ "$clientmask" == "" ]; then
		ErrorCode "--clientIp --clientmask"
		exit 6
	fi
fi

if [ "$maclone" == "true" ]; then
	if [ "$cloneaddr" == "" ]; then
		ErrorCode "--cloneaddr"
		exit 6
	fi
fi

#if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
#	wifi_client_ap_scan.sh --remembered > /dev/null
#fi

if [ "$opt_clone" == "true" ]; then
	saved_maclone=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac_clone_enable="} {print $NF}' | cut -d '"' -f 2`
	ScanCloneAddr=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	if [ "$maclone" == "true" ]; then
		if [ "$saved_maclone" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="true"./mac_clone_enable="true" /' "$UpdateConf"
		else
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="false"./mac_clone_enable="true" /' "$UpdateConf"
			sed -i '/'\"${string_mac}\"'/ s/cloned_mac_address='\""${ScanCloneAddr}"\"'./cloned_mac_address='\""${cloneaddr}"\"' /' "$UpdateConf"
			if [ "$connectStatus" == "COMPLETED" ]; then
				if [ "$saved_maclone" != "$maclone" ]; then
					restartSTA=1
				fi
			fi
		fi
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_update_V2.sh Enable MACclone of profile" "$ScanCloneAddr" >> /tmp/wificlientap.log
		fi
	else
		if [ "$saved_maclone" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="true"./mac_clone_enable="false" /' "$UpdateConf"
			sed -i '/'\"${string_mac}\"'/ s/cloned_mac_address='\""${ScanCloneAddr}"\"'./cloned_mac_address='\"""\"' /' "$UpdateConf"
			if [ "$connectStatus" == "COMPLETED" ]; then
				if [ "$saved_maclone" != "$maclone" ]; then
					restartSTA=1
				fi
			fi
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_update_V2.sh Disable MACclone of profile" "$maclone" >> /tmp/wificlientap.log
			fi
		else
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="false"./mac_clone_enable="false" /' "$UpdateConf"
		fi	
	fi
	if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
		cat "$UpdateConf" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
	fi
fi


if [ "$opt_trusted" == "true" ]; then
	saved_trusted=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN {FS="trusted="} {print $NF}' | cut -d '"' -f 2`	
					
	if [ "$trusted" == "true" ]; then
		echo "trusted" > /tmp/ifplugd_trust
		if [ "$saved_trusted" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/trusted="true"./trusted="true" /' "$UpdateConf"
		else
			sed -i '/'\"${string_mac}\"'/ s/trusted="false"./trusted="true" /' "$UpdateConf"
			if [ "$connectStatus" == "COMPLETED" ]; then
				connectedessid=`wpa_cli -i "$activeIF" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
				conf_remember=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
				 
				
				if [ "${connectedessid}" == "${conf_remember}" ]; then	
					/usr/sbin/iptables -F INPUT
					/etc/init.d/S77upnp restart
					route add -net 224.0.0.0 netmask 240.0.0.0 dev "${activeIF}"
					if [ "$Debugmode" == "1" ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": wifi_client_ap_update_V2.sh Delete iptables rule" "${connectedessid}" "${conf_remember}" >> /tmp/wificlientap.log
					fi
				fi
			fi
		fi
	else
		echo "untrusted" > /tmp/ifplugd_trust
		if [ "$saved_trusted" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/trusted="true"./trusted="false" /' "$UpdateConf"
			if [ "$connectStatus" == "COMPLETED" ]; then
				connectedessid=`wpa_cli -i "$activeIF" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
				conf_remember=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
				if [ "${connectedessid}" == "${conf_remember}" ]; then	
					CheckAPExist
					/usr/sbin/iptables -F INPUT
					
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 80 -j DROP 
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 5353 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 9000 -j DROP 
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p udp --dport 1900 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p udp --dport 137:138 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 139 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 445 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 22 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p udp --dport 5353 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 548 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 21 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 53 -j DROP
					/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 443 -j DROP
					#/usr/sbin/iptables -A INPUT -i "${activeIF}" -p tcp --dport 9443 -j DROP
					/etc/init.d/S77upnp restart
					if [ "$Debugmode" == "1" ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": wifi_client_ap_update_V2.sh Add iptables rule" "${connectedessid}" "${conf_remember}" >> /tmp/wificlientap.log
					fi
					route del -net 224.0.0.0 netmask 240.0.0.0 dev "${activeIF}"
				fi
			fi
		else
			sed -i '/'\"${string_mac}\"'/ s/trusted="false"./trusted="false" /' "$UpdateConf"
		fi	
	fi
	if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
		cat "$UpdateConf" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
	fi 
fi

if [ "$opt_remember" == "true" ]; then
	saved_remember=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN {FS="remembered="} {print $NF}' | cut -d '"' -f 2`
	if [ "$remember" == "true" ]; then
		if [ "$saved_remember" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="true" /' "$UpdateConf"
		else
			sed -i '/'\"${string_mac}\"'/ s/remembered="false"./remembered="true" /' "$UpdateConf"
		fi
		if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
			cat "$UpdateConf" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
		fi 
		found_mac=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf`
		if [ "$found_mac" == "" ]; then
			cat /tmp/wifinetwork-remembered.conf >> /etc/nas/config/wifinetwork-remembered.conf
			#if [ "$Debugmode" == "1" ]; then
			#	profileleft=`cat /etc/nas/config/wifinetwork-remembered.conf`
			#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			#	echo $timestamp ": wifi_client_ap_update_V2.sh Add profile latest profile list ">> /tmp/wificlientap.log
			#	echo $timestamp ": wifi_client_ap_update_V2.sh "$profileleft >> /tmp/wificlientap.log
			#fi
		else
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_update_V2.sh profile already exist ">> /tmp/wificlientap.log
				echo $timestamp ": wifi_client_ap_update_V2.sh ""$string_mac" >> /tmp/wificlientap.log
			fi
		fi
	else
		if [ "$saved_remember" == "true" ]; then
			sed -i '/'"${string_mac}"'/ s/remembered="true"./remembered="false" /' /tmp/scan_result
			sed -i '/'"${string_mac}"'/ s/remembered="false"./remembered="false" /' /tmp/scan_result
			sed -i '/'"${string_mac}"'/ s/remembered="true"./remembered="false" /' /tmp/wifinetwork-remembered.conf
		fi
		
		connectedessid=`wpa_cli -i "$activeIF" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
		conf_remember=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
		if [ "${connectedessid}" == "${conf_remember}" ]; then	
			if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
				sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="false" /' "$UpdateConf"
				cat "$UpdateConf" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
			fi
		fi
		
		found_mac=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf`
		if [ "$found_mac" != "" ]; then
			sed '/'\""${string_mac}"\"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
			cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
			#cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered.conf
			rm /tmp/wifinetwork-remembered_tmp.conf
			#if [ "$Debugmode" == "1" ]; then
			#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			#	profileleft=`cat /etc/nas/config/wifinetwork-remembered.conf`
			#	echo $timestamp ": wifi_client_ap_update_V2.sh remove profile, latest profile list" >> /tmp/wificlientap.log
			#	echo $timestamp ": wifi_client_ap_update_V2.sh "$profileleft >> /tmp/wificlientap.log
			#fi
		fi
		
		#connectedessid=`wpa_cli -i "$activeIF" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
		#conf_remember=`grep -rsi "\"${string_mac}\"" "$UpdateConf" | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
		#if [ "${connectedessid}" == "${conf_remember}" ]; then	
		#	sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="false" /' /tmp/wifinetwork-remembered.conf
		#fi	
	fi 
fi

if [ "$opt_networkConfig" == "true" ]; then
	ScanDHCP=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanIp=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="ip=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanMask=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="netmask=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanGW=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="gateway=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanDNS0=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="dns0=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanDNS1=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="dns1=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	ScanDNS2=`cat "${UpdateConf}" | grep -rsi "${string_mac}" | awk 'BEGIN{FS="dns2=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	if [ "$clientDHCP" == "false" ]; then
		if [ "$clientDHCP" != "$ScanDHCP" ] || [ "$ScanIp" != "$clientIp" ] || [ "$ScanMask" != "clientgw" ] || [ "$ScanGW" != "clientgw" ] || [ "$ScanDNS0" != "$clientdns0" ] || [ "$ScanDNS1" != "$clientdns1" ] || [ "$ScanDNS2" != "$clientdns2" ]; then
			restartSTA=1
			sed -i '/'\""${string_mac}"\"'/ s/dhcp_enabled='\""${ScanDHCP}"\"'./dhcp_enabled='\""${clientDHCP}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/ip='\""${ScanIp}"\"'./ip='\""${clientIp}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/netmask='\""${ScanMask}"\"'./netmask='\""${clientmask}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/gateway='\""${ScanGW}"\"'./gateway='\""${clientgw}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/dns0='\""${ScanDNS0}"\"'./dns0='\""${clientdns0}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/dns1='\""${ScanDNS1}"\"'./dns1='\""${clientdns1}"\"' /' "$UpdateConf"
			sed -i '/'\""${string_mac}"\"'/ s/dns2='\""${ScanDNS2}"\"'./dns2='\""${clientdns2}"\"' /' "$UpdateConf"
		fi
		/usr/local/sbin/setNetworkStatic.sh "ifname=wlan0-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
	else
		if [ "$clientDHCP" != "$ScanDHCP" ]; then
			restartSTA=1
			sed -i '/'\""${string_mac}"\"'/ s/dhcp_enabled='\""${ScanDHCP}"\"'./dhcp_enabled='\""${clientDHCP}"\"' /' "$UpdateConf"
		fi
		/usr/local/sbin/setNetworkDhcp.sh "wlan0-connect"
	fi
	
	if [ "$UpdateConf" == "/etc/nas/config/wifinetwork-remembered.conf" ]; then
		cat "$UpdateConf" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
	fi
fi


if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_update_V2.sh restartSTA" "$restartSTA" >> /tmp/wificlientap.log
fi

if [ "$restartSTA" == "1" ]; then
	#cat "$UpdateConf" | grep -rsi "\"${string_mac}\"" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
	sed -i 's/STA_CONF_JOIN=.*/STA_CONF_JOIN=1/' /etc/nas/config/wifinetwork-param.conf
	/etc/init.d/S73multi-role stop
	/sbin/wifi-restart UPDATE_STA_CONF
	sleep 1
	if [ "$opt_clone" == "true" ]; then
		if [ "$maclone" == "true" ]; then
			ifconfig wlan0 down hw ether "${cloneaddr}"
		#else
		#	phy0macaddr=`cat /sys/module/wlcore/holders/wl18xx/drivers/platform\:wl18xx_driver/wl18xx/ieee80211/phy0/macaddress | tr [:lower:] [:upper:]`
		#	ifconfig wlan0 down hw ether "${phy0macaddr}"
		fi
	fi
	/sbin/wifi-restart STA &
fi
  	
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	found_mac=`grep -rsi "\"${string_mac}\"" "$UpdateConf"`
	echo $timestamp ": wifi_client_ap_update_V2.sh Complete update Profile" >> /tmp/wificlientap.log
	echo $timestamp ": wifi_client_ap_update_V2.sh" "$found_mac" >> /tmp/wificlientap.log
fi

exit 0

#sed -i '/${string_mac}/ s/auto_login:false./auto_login:true /' /etc/nas/config/wifinetwork-remembered.conf

# EOF

