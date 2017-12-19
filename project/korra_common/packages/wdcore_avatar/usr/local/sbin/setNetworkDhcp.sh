#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# setNetworkDhcp.sh
#
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/networking-general.conf 2>/dev/null
. /etc/nas/config/wifinetwork-param.conf
NorestartService=0
tmp_conf=/etc/.tmp_netconf

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": setNetworkDhcp.sh" $@ >> /tmp/wificlientap.log
fi


if [ "$1" == "" ]; then
	if [ "$STA_CHANNEL" == "2" ]; then
   		iname=$STA2G4_IFACE
   	else
   		iname=$STA_IFACE
   	fi
else
	while [ "$1" != "" ]; do
		gw_mac=`echo ${1} | grep "gateway_mac_address="`
		if [ "${gw_mac}" == "" ]; then
			iname=`echo ${1}`
   			if [ "${iname}" == "wlan0-connect" ]; then
      			NorestartService=1
      			iname=$STA_IFACE
   			elif [ "${iname}" == "wlan2-connect" ]; then
   				NorestartService=1
      			iname=$STA2G4_IFACE
   			else
   				if [ "$STA_CHANNEL" == "2" ]; then
   					iname=$STA2G4_IFACE
   				else
   					iname=$STA_IFACE
   				fi
   			fi
   			if [ "${iname}" != "$STA_IFACE" ] && [ "${iname}" != "$STA2G4_IFACE" ]; then
       			exit 1
   			fi	
		else
			gw_mac=`echo ${1} | grep "gateway_mac_address=" | cut -d'=' -f2`
		fi
		shift
	done
fi

if [ "$gw_mac" == "" ] && [ "$iname" == "" ]; then
	echo "usage: setNetworkDhcp.sh <iname> gateway_mac_address=<gateway_mac_address>"
	exit 0
fi

if [ "${gw_mac}" != "" ]; then
	gw_mac=`wpa_cli -i "${iname}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
fi

configurationMethod=`awk -v name="$iname" '{ if ($1 == "iface" && $2 == name) { print $4; exit 0; } }' ${networkConfig}`
if [ "$configurationMethod" == "dhcp" ]; then
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": setNetworkDhcp.sh DHCP already" >> /tmp/wificlientap.log
	fi
	exit 0
fi

if [ "${iname}" != "" ]; then
   if_found=""
   while read aline
   do
       echo ${aline} | grep "iface ${iname} " > /dev/null
       if [ $? -eq 0 ] && [ "${if_found}" != "yes" ]; then
	   if_found="yes"
           echo "iface ${iname} inet dhcp" >> ${tmp_conf}
           while read modline
           do
              echo ${modline} | grep 'auto' > /dev/null
              if [ $? -eq 0 ]; then
                  echo "" >> ${tmp_conf}
                  echo ${modline} >> ${tmp_conf}
                  break
              fi
           done
       else
           echo ${aline} >> ${tmp_conf}
       fi
   done < ${networkConfig}
   if [ "${if_found}" != "yes" ]; then
       echo "" >> ${tmp_conf}
       echo "auto ${iname}" >> ${tmp_conf}
       echo "iface ${iname} inet dhcp" >> ${tmp_conf}
       #echo "allow-hotplug ${iname}" >> ${tmp_conf}
   fi

# do NOT change the interface file while the network is up
# ifdown relies on the values to shut down the gateway and
# to know whether to stop the dhcp client.
   
   	if [ "$NorestartService" == "0" ]; then
   		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": setNetworkDhcp.sh Reset" >> /tmp/wificlientap.log
		fi
   		
   		matchssid=`grep -rsni "${gw_mac}" /etc/nas/config/wifinetwork-remembered.conf | head -1`
		if [ "${matchssid}" != "" ]; then
			lineNum=`echo "$matchssid" | cut -d ':' -f 1`
			ConnectProfile=`grep -rsi "${gw_mac}" /etc/nas/config/wifinetwork-remembered.conf | head -1`
			cli2Ssid=`echo "${ConnectProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
			#cli2key=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2`
			cli2key="${STA_PSK_KEY}"
			cli2mac=`echo ${ConnectProfile} | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
   			cli2join=`echo ${ConnectProfile} | awk 'BEGIN{FS="auto_join=" } {print $NF}' | cut -d '"' -f 2`
   			cli2trust=`echo ${ConnectProfile} | awk 'BEGIN{FS="trusted=" } {print $NF}' | cut -d '"' -f 2`
   			cli2encryptype=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $1}'`
   			cli2cipher=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $2}' | awk '{print $1}'`
   			cli2bssid=`echo ${ConnectProfile} | awk 'BEGIN{FS="bssi\/dmap=" } {print $NF}' | cut -d ' ' -f 1`
   			cli2Signal=`echo ${ConnectProfile} | awk 'BEGIN{FS="signal_strength=" } {print $NF}' | cut -d '"' -f 2`
			clisecured=`echo ${ConnectProfile} | awk 'BEGIN{FS="secured=" } {print $NF}' | cut -d ' ' -f 1`
			cliDhcp=`echo ${ConnectProfile} | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2`
			cliclone=`echo ${ConnectProfile} | awk 'BEGIN{FS="mac_clone_enable=" } {print $NF}' | cut -d '"' -f 2`
			clicloneaddr=`echo ${ConnectProfile} | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2`
			cliremembered=`echo ${ConnectProfile} | awk 'BEGIN{FS="remembered=" } {print $NF}' | cut -d '"' -f 2`
			cliwpsenabled=`echo ${ConnectProfile} | awk 'BEGIN{FS="wps_enabled=" } {print $NF}' | cut -d '"' -f 2`
			cliband=`echo "${ConnectProfile}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
		
			if [ "$cli2encryptype" == "NONE" ]; then
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${cli2mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""true"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" \
					dhcp_enabled=\"true\" ip=\""$clientIP"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=0 Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				elif [ "$cli2encryptype" == "WEP" ]; then
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${cli2mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\""\
					dhcp_enabled=\"true\" ip=\""$clientIP"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=0 Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				else
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${cli2mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}/${cli2cipher}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\""\
					dhcp_enabled=\"true\" ip=\""$clientIP"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=0 Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				fi
				
				if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": setNetworkDhcp.sh update profile" $hiddenProfile >> /tmp/wificlientap.log
			fi
		
			checkloop=1
			if [ -f "/tmp/wifinetwork-remembered_tmp.conf" ]; then
				rm /tmp/wifinetwork-remembered_tmp.conf
			fi
			
			cat /etc/nas/config/wifinetwork-remembered.conf | while read RemProfile
			do
				if [ "$checkloop" == "$lineNum" ]; then
					echo $hiddenProfile >> /tmp/wifinetwork-remembered_tmp.conf
				else
					echo $RemProfile >> /tmp/wifinetwork-remembered_tmp.conf
				fi
		 		checkloop=`expr $checkloop + 1`
			done
			cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
			cat /tmp/wifinetwork-remembered_tmp.conf > /tmp/wifinetwork-remembered.conf
		fi
	fi
     
   	sed -i 's/STA_NETWORK_TYPE=.*/STA_NETWORK_TYPE='dhcp'/' /etc/nas/config/wifinetwork-param.conf
   	mv ${tmp_conf}  ${networkConfig}
   	#mv ${tmp_conf}  /etc/.multif	
   	if [ "$NorestartService" == "0" ]; then
   		ifconfig ${iname} down
   		/sbin/ifdown ${iname}
   		echo 0 > /tmp/ApCliRetry   
   		sleep 1
   		/sbin/ifup ${iname}
   		/etc/init.d/S40ifplugd restart
   	fi
fi

