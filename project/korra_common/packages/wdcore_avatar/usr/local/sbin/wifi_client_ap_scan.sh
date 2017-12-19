#!/bin/bash
#
# 2014 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_scan.sh
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
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_scan.sh" $@ >> /tmp/wificlientap.log
fi

start_scan=0
tempDisable=1
currentstate=0
WEP_Fail=0
connectStatus="INACTIVE"

if [ -f "/tmp/wificlientdisconnect" ]; then
	sleep 3
fi

if [ "$1" == "" ]; then
	while [ -f "/tmp/wifi_client_trust_execute" ] || [ -f "/tmp/wifi_client_remembered_execute" ]; do
		sleep 1
	done
	b_all=true
fi

if [ "$STA_CHANNEL_LITE" == "0" ]; then
	if [ "${STA_CHANNEL}" == 5 ]; then
		activeIF=${STA_IFACE}
	else
		activeIF=${STA2G4_IFACE}
		#activeIF=${STA_IFACE}
	fi
else
	activeIF=wlan1
fi

if [ -f "/tmp/connected" ]; then 
	rm /tmp/connected
fi

if [ -f "/tmp/scan_result" ]; then
	sed -i 's/connected="true"./connected="false" /' /tmp/scan_result 
fi
#sed -i 's/connected="true"./connected="false" /' /etc/nas/config/wifinetwork-remembered.conf


while [ "$1" != "" ]; do
   case $1 in
       --current )             shift
                               b_current=true
                               b_remembered=false
                               ;;
       --remembered )          
       							shift
                               b_remembered=true
                               b_current=false
                               para1=$1
                               start_scan=1
                               ;;
       --mac )                 
       						   shift
                               b_mac=true
                               b_current=false
                               b_remembered=false
                               string_mac=$1
                               start_scan=1
                               
                               ;;
       * )                     echo "wifi_client_ap_scan.sh [ | --current | --remembered | --mac <mac> ]"
                               if [ "$tempDisable" == "1" ]; then
    								if [ -f "/tmp/clientStatus" ]; then
    									rm /tmp/clientStatus
    								fi
    								if [ "$STA_CLIENT" == "true" ]; then 
										wpa_cli -i "${activeIF}" enable_network 0 > /dev/null
									fi
								fi
                               exit 1
                               ;;
   esac
   shift
done

if [ "$STA_CLIENT" == "true" ] && [ "$para1" == "" ]; then
	connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
	#if [ "$connectStatus" != "COMPLETED" ]; then
	#	for ((k=0; k<1; k++))
	#	do
	#		#sleep 1
	#		connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
	#	done
	#fi
	if [ "$connectStatus" == "COMPLETED" ]; then
		networkConfig=`/usr/local/sbin/getNetworkConfig.sh`
		if [ "$networkConfig" == "disconnected" ]; then
			WEP_Fail=1
		fi
	else
		if [ "$b_current" == "true" ]; then
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_scan.sh No connection" >> /tmp/wificlientap.log
			fi	
			exit 0
		fi
	fi

	
	if [ "$WEP_Fail" != "1" ] && [ "$connectStatus" == "COMPLETED" ]; then
		connectedessid=`wpa_cli -i "${activeIF}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
        iwconfigSsid=`iwconfig "${activeIF}" | grep ESSID | awk 'BEGIN{FS="  Nickname" }{print $1}' | awk 'BEGIN{FS="ESSID:" }{print $NF}'`
        echo "${iwconfigSsid}" > /tmp/iwconfigSsid
        sed -i 's/"//' /tmp/iwconfigSsid        
        sed -i 's/\(.*\)\"/\1/' /tmp/iwconfigSsid
        connectedemac=`cat /tmp/iwconfigSsid`
        rm /tmp/iwconfigSsid
        if [ "$connectedemac" == "" ]; then
			connectedemac=`wpa_cli -i "${activeIF}" status | grep -rsw "ssid" | awk -F= '{print $NF}' > /tmp/connectedemac`
			sed -i 's/\\//g' /tmp/connectedemac
			sed -i 's/\\\\/\\/g' /tmp/connectedemac
			sed -i 's/\\"/"/g' /tmp/connectedemac
			connectedemac=`cat /tmp/connectedemac`
			rm /tmp/connectedemac
        fi            
        
        if [ ! -f "/tmp/wificlientdisconnect" ]; then
			UplinkMode=`cat /tmp/ConnectionMode`
			if [ "${UplinkMode}" == "ShareMode" ]; then
				cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsw "${iwconfigSsid}" | head -1 > /tmp/connected
				sed -i 's/connected="false"./connected="true" /' /tmp/connected 
				sed -i 's/signal_strength="0"./signal_strength="100" /' /tmp/connected
			else
				cat /tmp/wifinetwork-remembered.conf | grep -rsw "${iwconfigSsid}" | grep -v 'signal_strength="0"' | head -1 > /tmp/connected
				sed -i 's/connected="false"./connected="true" /' /tmp/connected
				sed -i 's/signal_strength="0"./signal_strength="100" /' /tmp/connected
			fi
			if [ -f "/tmp/scan_result" ]; then
				#	sed -i '/'"${iwconfigSsid}"'/ s/connected="false"./connected="true" /' /tmp/scan_result 
				#	sed -i '/'"${iwconfigSsid}"'/ s/signal_strength="0"./signal_strength="100" /' /tmp/scan_result 
				matchssid=`cat /tmp/scan_result | grep -rsnw "${iwconfigSsid}" | grep -v 'signal_strength="0"'`
				if [ "${matchssid}" != "" ]; then
					lineNum=`echo "${matchssid}" | cut -d ':' -f 1`
					sed -i ${lineNum}d /tmp/scan_result
				fi
			fi
		fi
	fi
fi


if [ "$b_all" == "true" ]; then
	if [ -f "/tmp/scan_result" ]; then
		if [ "${iwconfigSsid}" != "" ]; then
			showConnected=`cat /tmp/scan_result | grep -rsw "${iwconfigSsid}"`
			if [ "${showConnected}" == "" ]; then
				sed -i 's/connected="false"./connected="true" /' /tmp/wifinetwork-remembered.conf
				cat /tmp/connected >> /tmp/scan_result
				cat /tmp/scan_result >> /tmp/scanlist
				cat /tmp/scan_result | awk 'BEGIN {FS="bssi/dmap="} {print $1}'
				#cp -a /tmp/scan_result /tmp/scanlist
			fi
		else
			cat /tmp/scan_result >> /tmp/scanlist
			cat /tmp/scan_result | awk 'BEGIN {FS="bssi/dmap="} {print $1}'
			#cp -a /tmp/scan_result /tmp/scanlist
		fi
		/sbin/wifi_scanning_update.sh Delay > /dev/null 2>&1 &
	else
		/sbin/wifi_scanning_update.sh
		if [ -f "/tmp/scan_result" ]; then
			cat /tmp/scan_result | awk 'BEGIN {FS="bssi/dmap="} {print $1}'
		fi
	fi
	exit 0
fi

if [ "$b_current" == "true" ]; then
	if [ "$STA_CLIENT" == "true" ]; then	
		currentSSID=`cat /tmp/connected`
		if [ "${currentSSID}" != "" ]; then
			cliband=`cat /tmp/connected | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
			uplinkAP=`cat /tmp/connected | awk 'BEGIN {FS="bssi/dmap="} {print $1}'`
			uplinkAP="${uplinkAP} Frequency=\"$cliband\"" 
			echo $uplinkAP
			#cat /tmp/connected | awk 'BEGIN {FS="security_key="} {print $1}'
		fi
	fi
	exit 0
fi

if [ "$b_remembered" == "true" ]; then
	#if [ ! -f "/tmp/runScan" ]; then
		/sbin/wifi_scanning_update.sh > /dev/null 2>&1
	#fi
	
	if [ "$para1" == "" ]; then
		sed -i '/'"${connectedessid}"'/ s/connected="false"./connected="true" /' /etc/nas/config/wifinetwork-remembered.conf
		cat /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="bssi/dmap="} {print $1}' | sort -t '"' -k 6 -r -n
	elif [ "$para1" == "signalConnect" ]; then
	 	cat /etc/nas/config/wifinetwork-remembered.conf | grep -v 'signal_strength="0"'
	
	elif [ "$para1" == "signalCHECK" ]; then
	 	cat /etc/nas/config/wifinetwork-remembered.conf | sort -t '"' -k 6 -r -n | grep -v 'signal_strength="0"'
	fi

	exit 0
fi

if [ "$b_mac" == "true" ]; then	
	if [ -f "/tmp/scan_result" ]; then
		grep -rsi "$string_mac" /tmp/scan_result | awk 'BEGIN {FS="bssi/dmap="} {print $1}'
	fi
fi

exit 0

# EOF

