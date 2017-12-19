#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
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
	echo $timestamp ": wifi_client_ap_update.sh" $@ >> /tmp/wificlientap.log
fi
RestartService(){
	/etc/init.d/S77upnp restart
}

function trans_to_hex {
	for i in $(echo $1 | sed -e "s/\./ /g"); do  
      	printf '%02x' $i >/dev/null 2>/dev/null < /dev/null
    done
}

if [ "${STA_CHANNEL}" == 5 ]; then
	activeIF=${STA_IFACE}
else
	activeIF=${STA_IFACE}
fi 

if [ $STA_CLIENT == "true" ]; then
	connectStatus=`wpa_cli -i ${activeIF} status | grep -rsi wpa_state | awk -F= '{print $NF}'`
fi

if [ "$option_mac" == "--mac" ]; then
  	string_mac=$2
  	found_mac=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf |wc -l`
  	if [ $found_mac -eq 0 ]; then
  		exit 2
  	fi
else
	echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] \
[--dhcp_client true|false] [--ip <ip>] [--netmask <netmask> ] [--gateway <gateway> ] [--dns0 <dns0> ] [--dns1 <dns1>] [--dns2 <dns2>] "
	exit 1	
fi

if [ "$3" == "" ]; then
	echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] \
[--dhcp_client true|false] [--ip <ip>] [--netmask <netmask> ] [--gateway <gateway> ] [--dns0 <dns0> ] [--dns1 <dns1>] [--dns2 <dns2>] "
	exit 1
fi 

while [ "$3" != "" ]; do
   case $3 in
       --trusted )             shift
                               trusted=$3
                               opt_trusted=true
                               if [ "$trusted" == "true" ]; then
                               		b_trusted=true
                               else
                               		if [ "$trusted" == "false" ]; then
                               	  		b_trusted=false
                                 	else
                                 		echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] "
                                 		exit 1
                                 	fi                              
                               fi
                               ;;
       --auto_join )           shift
                               auto_join=$3
                               opt_auto_join=true
                               if [ "$auto_join" == "true" ]; then
                               		b_auto_join=true
                               else
                                 	if [ "$auto_join" == "false" ]; then
                               	  		b_auto_join=false
                                 	else
                                 		echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] "
                                 		exit 1
                                	fi                              
                               fi
                               ;;
#       --auto_login )          shift
#                               auto_login=$3
#                               opt_auto_login=true
#                               if [ "$auto_login" == "true" ]; then
#                               	b_auto_login=true
#                               else
#                                 if [ "$auto_login" == "false" ]; then
#                               	  b_auto_login=false
#                                 else
#                                 	exit 1
#                                 fi                              
#                               fi
#                               ;;
       --remember )    shift
                               remember=$3
                               opt_remember=true
                               if [ "$remember" == "true" ]; then
                               		b_remember=true
                               else
                                 	if [ "$remember" == "false" ]; then
                               	  		b_remember=false
                                 	else
                                 		echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] "
                                 		exit 1
                                 	fi
                               fi
                               ;;
       --dhcp_enabled )			if [ "$4" != "true" ] && [ "$4" != "false" ]; then
        							exit 7
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
									exit 7
								fi
      								;;
    	--netmask )				trans_to_hex "$4"
       							if [ "$?" == 0 ]; then	
       								shift
									clientmask="$3"
									opt_networkConfig=true
								else 
									exit 7
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
        								exit 9
        							else
        								cloneaddr="$3"
        							fi
        						fi
        						;;

       * )                     echo "wifi_client_ap_update.sh --mac <mac_address> [ --trusted true|false ] [ --auto_join true|false ] | [ --remember true|false ] \
[--dhcp_client true|false] [--ip <ip>] [--netmask <netmask> ] [--gateway <gateway> ] [--dns0 <dns0> ] [--dns1 <dns1>] [--dns2 <dns2>] "
                               exit 1
   esac
   shift
done

if [ "$clientDHCP" == "false" ]; then
	if [ "$clientIp" == "" ] || [ "$clientmask" == "" ]; then
		exit 6
	fi
#elif [ "$clientDHCP" == "true" ]; then
	#if [ "$clientIp" != "" ] || [ "$clientmask" != "" ] || [ "$gateway" != "" ] || [ "$dns0" != "" ] || [ "$dns1" != "" ] || [ "$dns2" != "" ]; then
	#	exit 6
	#fi
fi

if [ "$maclone" == "true" ]; then
	if [ "$cloneaddr" == "" ]; then
		exit 6
	fi
fi

#wifi_client_ap_scan.sh --remembered > /dev/null

if [ "$opt_clone" == "true" ]; then
	saved_maclone=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac_clone_enable="} {print $NF}' | cut -d '"' -f 2`
	ScanCloneAddr=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	if [ "$maclone" == "true" ]; then
		if [ "$saved_maclone" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="true"./mac_clone_enable="true" /' /etc/nas/config/wifinetwork-remembered.conf
		else
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="false"./mac_clone_enable="true" /' /etc/nas/config/wifinetwork-remembered.conf
			sed -i '/'\""${string_mac}"\"'/ s/cloned_mac_address='\""${ScanCloneAddr}"\"'./cloned_mac_address='\""${cloneaddr}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
			if [ "$connectStatus" == "COMPLETED" ]; then
				restartSTA=1
			fi
		fi
	else
		if [ "$saved_maclone" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="true"./mac_clone_enable="false" /' /etc/nas/config/wifinetwork-remembered.conf
			sed -i '/'\""${string_mac}"\"'/ s/cloned_mac_address='\""${ScanCloneAddr}"\"'./cloned_mac_address='\"""\"' /' /etc/nas/config/wifinetwork-remembered.conf
			if [ "$connectStatus" == "COMPLETED" ]; then
				restartSTA=1
			fi
		else
			sed -i '/'\"${string_mac}\"'/ s/mac_clone_enable="false"./mac_clone_enable="false" /' /etc/nas/config/wifinetwork-remembered.conf
		fi	
	fi 
fi

if [ "$opt_auto_join" == "true" ]; then
	saved_auto_join=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="auto_join="} {print $NF}' | cut -d '"' -f 2`
	if [ "$auto_join" == "true" ]; then
		if [ "$saved_auto_join" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/auto_join="true"./auto_join="true" /' /etc/nas/config/wifinetwork-remembered.conf
		else
			sed -i '/'\"${string_mac}\"'/ s/auto_join="false"./auto_join="true" /' /etc/nas/config/wifinetwork-remembered.conf
			if [ "$connectStatus" != "COMPLETED" ]; then
				restartSTA=1
			fi
		fi
	else
		if [ "$saved_auto_join" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/auto_join="true"./auto_join="false" /' /etc/nas/config/wifinetwork-remembered.conf
		else
			sed -i '/'\"${string_mac}\"'/ s/auto_join="false"./auto_join="false" /' /etc/nas/config/wifinetwork-remembered.conf
		fi	
	fi 
fi

#if [ "$opt_auto_login" == "true" ]; then
#	saved_auto_login=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="auto_login="} {print $NF}' | cut -d '"' -f 2`
#	if [ "$auto_login" == "true" ]; then
#		if [ "$saved_auto_login" == "true" ]; then
#			sed -i '/'${string_mac}'/ s/auto_login="true"./auto_login="true" /' /etc/nas/config/wifinetwork-remembered.conf
#		else
#			sed -i '/'${string_mac}'/ s/auto_login="false"./auto_login="true" /' /etc/nas/config/wifinetwork-remembered.conf
#		fi
#	else
#		if [ "$saved_auto_login" == "true" ]; then
#			sed -i '/'${string_mac}'/ s/auto_login="true"./auto_login:="false" /' /etc/nas/config/wifinetwork-remembered.conf
#		else
#			sed -i '/'${string_mac}'/ s/auto_login="false"./auto_login="false" /' /etc/nas/config/wifinetwork-remembered.conf
#		fi	
#	fi 
#fi
if [ "$opt_trusted" == "true" ]; then
	saved_trusted=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="trusted="} {print $NF}' | cut -d '"' -f 2`	
	if [ "$trusted" == "true" ]; then
		echo "trusted" > /tmp/ifplugd_trust
		if [ "$saved_trusted" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/trusted="true"./trusted="true" /' /etc/nas/config/wifinetwork-remembered.conf
		else
			sed -i '/'\"${string_mac}\"'/ s/trusted="false"./trusted="true" /' /etc/nas/config/wifinetwork-remembered.conf
			if [ "$connectStatus" == "COMPLETED" ]; then
				connectedessid=`wpa_cli -i ${activeIF} status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
				conf_remember=`grep -rsi "\"${string_mac}\"" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
				if [ "${connectedessid}" == "${conf_remember}" ]; then	
					#/usr/local/sbin/wifi_ap_set_config.sh --enabled LeaveHomeNetwork
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 80 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 5353 -j DROP 
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 9000 -j DROP 
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 1900 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 137:138 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 139 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 445 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 22 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 5353 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 548 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 21 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 53 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 443 -j DROP
				fi
			fi
		fi
	else
		echo "untrusted" > /tmp/ifplugd_trust
		if [ "$saved_trusted" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/trusted="true"./trusted="false" /' /etc/nas/config/wifinetwork-remembered.conf
			if [ "$connectStatus" == "COMPLETED" ]; then
				connectedessid=`wpa_cli -i ${activeIF} status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
				conf_remember=`grep -rsi "\"${string_mac}\"" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
				if [ "${connectedessid}" == "${conf_remember}" ]; then	
					interface=`pidof hostapd`
					if [ "$interface" == "" ]; then
						/usr/local/sbin/wifi_ap_set_config.sh --enabled EnabledHomeNetwork 
						/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork 
					fi
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 80 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 5353 -j DROP 
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 9000 -j DROP 
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 1900 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 137:138 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 139 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 445 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 22 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p udp --dport 5353 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 548 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 21 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 53 -j DROP
					/usr/sbin/iptables -D INPUT -i ${activeIF} -p tcp --dport 443 -j DROP
					
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 80 -j DROP 
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 5353 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 9000 -j DROP 
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p udp --dport 1900 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p udp --dport 137:138 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 139 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 445 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 22 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p udp --dport 5353 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 548 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 21 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 53 -j DROP
					/usr/sbin/iptables -A INPUT -i ${activeIF} -p tcp --dport 443 -j DROP
				fi
			fi
		else
			sed -i '/'\"${string_mac}\"'/ s/trusted="false"./trusted="false" /' /etc/nas/config/wifinetwork-remembered.conf
		fi	
	fi 
fi

if [ "$opt_remember" == "true" ]; then
	saved_remember=`grep -rsi "\"${string_mac}\"" /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="remembered="} {print $NF}' | cut -d '"' -f 2`
	if [ "$remember" == "true" ]; then
		if [ "$saved_remember" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="true" /' /etc/nas/config/wifinetwork-remembered.conf
		else
			sed -i '/'\"${string_mac}\"'/ s/remembered="false"./remembered="true" /' /etc/nas/config/wifinetwork-remembered.conf
		fi
	else
		if [ "$saved_remember" == "true" ]; then
			sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="false" /' /etc/nas/config/wifinetwork-remembered.conf
			sed -i '/'\"${string_mac}\"'/ s/remembered="true"./remembered="false" /' /tmp/scan_result
		else
			sed -i '/'\"${string_mac}\"'/ s/remembered="false"./remembered="false" /' /etc/nas/config/wifinetwork-remembered.conf
		fi
		
		conf_remember=`grep -rsi "\"${string_mac}\"" /etc/nas/config/wifinetwork-remembered.conf | tail -1 | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
		#connection_mac=`iwconfig ${activeIF} | grep "Access Point" | awk 'BEGIN {FS="Access Point: "} {print $NF}' | cut -d ' ' -f 1`
		connection_mac=`wpa_cli -i ${activeIF} status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
		
		if [ "${conf_remember}" != "" ]; then
			if [ "${conf_remember}" == "${connection_mac}" ]; then
				sed '/'\""${string_mac}"\"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
				cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
				cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered.conf
				rm /tmp/wifinetwork-remembered_tmp.conf
				num_remember=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
				if [ "${num_remember}" == 0 ]; then
					#sed -i 's/STA_CLIENT=.*/STA_CLIENT=false/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_SSID_NAME=.*/STA_SSID_NAME=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_MAC_MAPPING=.*/STA_MAC_MAPPING=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_MAC_ADDRESS=.*/STA_MAC_ADDRESS=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_SECURITY_MODE=.*/STA_SECURITY_MODE=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_CIPHER_TYPE=.*/STA_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY=/' /etc/nas/config/wifinetwork-param.conf
					sed -i 's/STA_WEP_KEY=.*/STA_WEP_KEY=/' /etc/nas/config/wifinetwork-param.conf
				fi
				sed -i '/'\""${string_mac}"\"'/ s/remembered="true"./remembered="false" /' /tmp/wifinetwork-remembered.conf
				#cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered.conf
				/sbin/wifi-restart UPDATE_STA_CONF 
				/sbin/wifi-restart STA &
				/usr/local/sbin/wifi_client_trust_mode.sh "down" &
				rm /tmp/ifplugd_trust
				AP1mode=`ifconfig | grep ^AP_IFACE`
				if [ "$APmode" == "" ]; then
					/usr/local/sbin/wifi_ap_set_config.sh --enabled EnabledHomeNetwork
				fi
				AP2mode=`ifconfig | grep ^AP5G_IFACE`
				if [ "$AP2mode" == "" ]; then
					/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork
				fi
				
				echo "ApMode" > /tmp/ConnectionMode
				echo "192.168.60.1" > /tmp/resolv.conf
				#RestartService
				exit 0
			else
				sed '/'\""${string_mac}"\"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
				cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
				#cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered.conf
				sed -i '/'\""${string_mac}"\"'/ s/remembered="true"./remembered="false" /' /tmp/wifinetwork-remembered.conf
				rm /tmp/wifinetwork-remembered_tmp.conf
				/sbin/wifi-restart UPDATE_STA_CONF 
				exit 0
			fi	
			echo "24;00;" > /tmp/MCU_Cmd
		fi
	fi 
fi



if [ "$opt_networkConfig" == "true" ]; then
conf_remember=`grep -rsi "\"${string_mac}\"" /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2`
connection_mac=`wpa_cli -i ${activeIF} status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
if [ "${conf_remember}" != "" ]; then
	if [ "${conf_remember}" == "${connection_mac}" ]; then
		restartSTA=1
	fi
fi

	ScanDHCP=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/dhcp_enabled='\""${ScanDHCP}"\"'./dhcp_enabled='\""${clientDHCP}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanIp=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="ip=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/ip='\""${ScanIp}"\"'./ip='\""${clientIp}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanMask=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="netmask=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/netmask='\""${ScanMask}"\"'./netmask='\""${clientmask}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanGW=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="gateway=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/gateway='\""${ScanGW}"\"'./gateway='\""${clientgw}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanDNS0=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="dns0=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/dns0='\""${ScanDNS0}"\"'./dns0='\""${clientdns0}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanDNS1=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="dns1=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/dns1='\""${ScanDNS1}"\"'./dns1='\""${clientdns1}"\"' /' /etc/nas/config/wifinetwork-remembered.conf
	ScanDNS2=`grep -rsi "${string_mac}" /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="dns2=" } {print $NF}' | cut -d '"' -f 2 | head -1`
	sed -i '/'\""${string_mac}"\"'/ s/dns2='\""${ScanDNS2}"\"'./dns2='\""${clientdns2}"\"' /' /etc/nas/config/wifinetwork-remembered.conf

	if [ "$clientDHCP" == "false" ]; then
		if [ "$restartSTA" == "1" ]; then
			/usr/local/sbin/setNetworkStatic.sh "ifname=wlan0-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
		fi
	else
		if [ "$restartSTA" == "1" ]; then
			/usr/local/sbin/setNetworkDhcp.sh "wlan0-connect"
		fi
	fi
fi

if [ "$restartSTA" == "1" ]; then
	cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsi "\"${string_mac}\"" | grep -v 'signal_strength="0"' > /tmp/wifinetwork-remembered.conf
	sed -i 's/STA_CONF_JOIN=.*/STA_CONF_JOIN=1/' /etc/nas/config/wifinetwork-param.conf
	/etc/init.d/S73multi-role stop
	sleep 1
	if [ "$opt_clone" == "true" ]; then
		if [ "$maclone" == "true" ]; then
			ifconfig ${activeIF} down hw ether "${cloneaddr}"
		else
			phy0macaddr=`cat /sys/module/wlcore/holders/wl18xx/drivers/platform\:wl18xx_driver/wl18xx/ieee80211/phy0/macaddress | tr [:lower:] [:upper:]`
			ifconfig ${activeIF} down hw ether "${phy0macaddr}"
		fi
	fi
	/sbin/wifi-restart STA &
fi

exit 0

#sed -i '/${string_mac}/ s/auto_login:false./auto_login:true /' /etc/nas/config/wifinetwork-remembered.conf

# EOF

