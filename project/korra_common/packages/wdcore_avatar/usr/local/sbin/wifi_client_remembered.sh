#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_remembered.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/nas/config/wifinetwork-param.conf
dnsConfig=/etc/resolv.conf
SaveLimit=20
ifAction=$1
ifdelay=$2

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_remembered.sh" "$@" >> /tmp/wificlientap.log
fi

if [ "$ifAction" != "${STA2G4_IFACE}" ] && [ "$ifAction" != "${STA_IFACE}" ]; then
	exit 1
fi

Freq_2G="2412, 2417, 2422, 2427, 2432, 2437, 2442, 2442, 2447, 2452, 2457, 2462, 2467, 2472, 2484"
Freq_5G="5180, 5200, 5220, 5240, 5260, 5280, 5300, 5320, 5500, 5520, 5540, 5560, 5580, 5660, 5680, 5700, 5745, 5765, 5785, 5805, 5825"
		

CheckSaveProfileNum(){
	#only restore 20 profile
	SaveNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_remembered.sh: Profile SaveNum:" $SaveNum  >> /tmp/wificlientap.log
	fi
	if [ "${SaveNum}" -gt "${SaveLimit}" ]; then
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_remembered.sh: Delete Oldest AP"  >> /tmp/wificlientap.log
		fi
		sed -i '21,$d' /etc/nas/config/wifinetwork-remembered.conf
	fi
}

clearTempfile()
{
	if [ -f "/tmp/scanlist" ]; then
		rm /tmp/scanlist
	fi
}

while [ -f "/tmp/wifiprofileupdate" ]; do
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_remembered.sh: waitfor wifiprofileupdate" >> /tmp/wificlientap.log
	fi
	sleep 1
done

if [ ! -f "/tmp/wifi_client_remembered_execute" ]; then
	touch /tmp/wifi_client_remembered_execute
	
	#if [ "$ifdelay" == "" ]; then
		sleep 2
	#else
	#	sleep "${ifdelay}"
	#fi
	/sbin/ifup "${ifAction}"
	
	#connectedCipher=`wpa_cli -i "${ifAction}" status | grep -rsw "pairwise_cipher" | awk -F= '{print $NF}'`
	#if [ "$connectedCipher" == "WEP-40" ] || [ "$connectedCipher" == "WEP-104" ]; then
	networkConfig=`/usr/local/sbin/getNetworkConfig.sh`
		if [ "$networkConfig" == "disconnected" ]; then
			rm /tmp/wifi_client_remembered_execute
			exit 0
		fi
	#fi
	
	connectedmac=`wpa_cli -i "${ifAction}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
	connectStatus=`wpa_cli -i "${ifAction}" status | grep -rsw "wpa_state" | awk -F= '{print $NF}'`
	#connectedip=`wpa_cli -i "${ifAction}" status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
	
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_remembered.sh Connection Status" "$connectStatus"  >> /tmp/wificlientap.log
	fi
	
	if [ "$connectStatus" == "COMPLETED" ] && [ "$connectedmac" != "" ]; then
		iwconfigSsid=`iwconfig "${ifAction}" | grep ESSID | awk 'BEGIN{FS="  Nickname" }{print $1}' | awk 'BEGIN{FS="ESSID:" }{print $NF}'`
		if [ "$connectedSsid" != "" ]; then
			#echo ${iwconfigSsid:31} > /tmp/iwconfigSsid
			echo "${iwconfigSsid}" > /tmp/iwconfigSsid
			sed -i 's/"/\1/' /tmp/iwconfigSsid
			sed -i 's/\(.*\)\"/\1/' /tmp/iwconfigSsid
			connectedSsid=`cat /tmp/iwconfigSsid`
			rm /tmp/iwconfigSsid
		else
			connectedSsid=`wpa_cli -i "${ifAction}" status | grep -rsw "ssid" | awk -F= '{print $NF}'`
		fi
		ConnectProfile=`head -n 1 /tmp/wifinetwork-remembered.conf`
		cli2Ssid=`echo "${ConnectProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
		#cli2key=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2`
		cli2key="${STA_PSK_KEY}"
		cli2mac=`echo ${ConnectProfile} | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
   		cli2join=`echo ${ConnectProfile} | awk 'BEGIN{FS="auto_join=" } {print $NF}' | cut -d '"' -f 2`
   		cli2trust=`echo ${ConnectProfile} | awk 'BEGIN{FS="trusted=" } {print $NF}' | cut -d '"' -f 2`
   		cli2encryptype=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $1}'`
   		cli2cipher=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $2}' | awk '{print $1}'`
   		#cli2bssid=`echo ${ConnectProfile} | awk 'BEGIN{FS="bssi\/dmap=" } {print $NF}' | cut -d ' ' -f 1`
   		cli2bssid="${STA_MAC_MAPPING}"
   		cli2Signal=`echo ${ConnectProfile} | awk 'BEGIN{FS="signal_strength=" } {print $NF}' | cut -d '"' -f 2`
		clisecured=`echo ${ConnectProfile} | awk 'BEGIN{FS="secured=" } {print $NF}' | cut -d ' ' -f 1`
		cliDhcp=`echo ${ConnectProfile} | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2`
		cliclone=`echo ${ConnectProfile} | awk 'BEGIN{FS="mac_clone_enable=" } {print $NF}' | cut -d '"' -f 2`
		clicloneaddr=`echo ${ConnectProfile} | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2`
		cliremembered=`echo ${ConnectProfile} | awk 'BEGIN{FS="remembered=" } {print $NF}' | cut -d '"' -f 2`
		cliwpsenabled=`echo ${ConnectProfile} | awk 'BEGIN{FS="wps_enabled=" } {print $NF}' | cut -d '"' -f 2`
		confband=`echo "${ConnectProfile}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
		frep=`iw dev "${STA2G4_IFACE}" link | grep -rsw "freq" | cut -d " " -f 2`
		kkk=`echo "${Freq_2G}" | grep -rsw "${frep}"`
		if [ $? == "0" ]; then
			cliband=2
		else
			cliband=5
		fi
		sed -i 's/STA_CHANNEL=.*/STA_CHANNEL='${cliband}'/' /etc/nas/config/wifinetwork-param.conf
		#if [ "${confband}" == "All" ]; then
		#	if [ "${cliband}" == "5" ]; then
		#		wpa_cli -i wlan3 disable_network 0
		#	else
		#		wpa_cli -i wlan1 disable_network 0
		#	fi
		#fi
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_remembered.sh Config" "$cli2Ssid" "$cli2mac" "$cligw" "$cli2encryptype" "$cli2cipher" "$cliband" "$cli2bssid" >> /tmp/wificlientap.log
		fi
		#if [ "$wifi5g" == "1" ] && [ "$wifi2g4" == "1" ]; then
		#	cliband=`iw $STA_IFACE link`
		#	if [ "$cliband" != "Not connected." ]; then
		#		cliband=5
		#	else
		#		cliband=2
		#	fi
		#fi
		if [ "$cli2Ssid" == "" ] && [ "$cli2mac" == "" ] && [ "$cli2encryptype" == "" ]; then
			rm /tmp/wifi_client_remembered_execute
			exit 0
		elif [ "$cli2Ssid" == "" ]; then
			cli2Ssid=`wpa_cli -i "${ifAction}" status | grep -rsw "ssid" | awk -F= '{print $NF}'`
		fi
		if [ "$cliDhcp" == "false" ]; then
			cliip=`echo ${ConnectProfile} | awk 'BEGIN{FS="ip=" } {print $NF}' | cut -d '"' -f 2`
			climask=`echo ${ConnectProfile}  | awk 'BEGIN{FS="netmask=" } {print $NF}' | cut -d '"' -f 2`
			cligw=`echo ${ConnectProfile} | awk 'BEGIN{FS="gateway=" } {print $NF}' | cut -d '"' -f 2`
			clidns0=`echo ${ConnectProfile} | awk 'BEGIN{FS="dns0=" } {print $NF}' | cut -d '"' -f 2`
			clidns1=`echo ${ConnectProfile} | awk 'BEGIN{FS="dns1=" } {print $NF}' | cut -d '"' -f 2`
			clidns2=`echo ${ConnectProfile} | awk 'BEGIN{FS="dns2=" } {print $NF}' | cut -d '"' -f 2`
			if [ "${clidns0}" != "" ]; then
				echo "nameserver ${clidns0}" > ${dnsConfig}
			fi
			if [ "${clidns1}" != "" ]; then
				echo "nameserver ${clidns1}" >> ${dnsConfig}
			fi
			if [ "${clidns2}" != "" ]; then
				echo "nameserver ${clidns2}" >> ${dnsConfig}
			fi
		else			
			echo $networkConfig | while read dhcpConfig
			do 
				echo $dhcpConfig > /tmp/netconf
			done
			dhcpConfig=`cat /tmp/netconf`
			dhcpip=`echo "$dhcpConfig" | awk '{print $2}'`
			if [ "$dhcpip" == "address" ]; then
				cliip=`echo "$dhcpConfig" | awk '{print $3}'`
			fi
			dhcpmask=`echo "$dhcpConfig" | awk '{print $4}'`
			if [ "$dhcpmask" == "netmask" ]; then
				climask=`echo "$dhcpConfig" | awk '{print $5}'`
			fi
			dhcpgw=`echo "$dhcpConfig" | awk '{print $6}'`
			if [ "$dhcpgw" == "gateway" ]; then
				cligw=`echo "$dhcpConfig" | awk '{print $7}'`
			fi
			dhcpdns0=`echo "$dhcpConfig" | awk '{print $8}'`
			if [ "$dhcpdns0" == "nameserver" ]; then
				clidns0=`echo "$dhcpConfig" | awk '{print $9}'`
			fi
			dhcpdns1=`echo "$dhcpConfig" | awk '{print $10}'`
			if [ "$dhcpdns1" == "nameserver" ]; then
				clidns1=`echo "$dhcpConfig" | awk '{print $11}'`
			fi
			dhcpdns2=`echo "$dhcpConfig" | awk '{print $12}'`
			if [ "$dhcpdns2" == "nameserver" ]; then
				clidns2=`echo "$dhcpConfig" | awk '{print $13}'`
			fi	
			rm /tmp/netconf
		fi
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_remembered.sh DHCP Config" "$cliDhcp" "$cliip" "$climask" "$cligw" "$clidns0" "$clidns1" "$clidns2" >> /tmp/wificlientap.log
		fi	
		
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_remembered.sh connectedSsid" "$connectedSsid" >> /tmp/wificlientap.log
			echo $timestamp ": wifi_client_remembered.sh connectedmac" "$connectedmac" >> /tmp/wificlientap.log
			echo $timestamp ": wifi_client_remembered.sh Target STA_SSID_NAME" "$cli2Ssid" >> /tmp/wificlientap.log
			echo $timestamp ": wifi_client_remembered.sh SSID STA_CONF_REMB" ${STA_CONF_REMB} >> /tmp/wificlientap.log
		fi
		
		if [ ${STA_CONF_HIDDEN} == "1" ]; then
			sed -i 's/STA_CONF_HIDDEN=.*/STA_CONF_HIDDEN=0/' /etc/nas/config/wifinetwork-param.conf		
			if [ "$cli2key" == "MyPassportWirelessPBCSecurityKeyTEMPoRarily" ]; then
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_remembered.sh Trigger by WPS PBC ">> /tmp/wificlientap.log
				fi
				scantmp=`grep -rsi "\"${connectedmac}\"" /tmp/scan_result`
				if [ -f "/tmp/WPSpinKEY" ]; then
					wpapsk=`cat /tmp/WPSpinKEY` 
					#echo "${wpapsk}" | grep -q '\"\|\$\|\&\|/\||\|\\'
					#if [ $? == 0 ]; then
					#	echo $wpapsk > /tmp/clientpwd
					#	sed -i 's/\\/\\\\/g' /tmp/clientpwd
					#	sed -i 's/"/\\"/g' /tmp/clientpwd
					#	sed -i 's/\$/\\$/g' /tmp/clientpwd
					#	sed -i 's/&/\\&/g' /tmp/clientpwd
					#	sed -i 's/\//\\\//g' /tmp/clientpwd
					#	sed -i 's/|/\\|/g' /tmp/clientpwd
					#	wpapsk=`cat /tmp/clientpwd`
						len=${#wpapsk}
						clen=`expr $len - 2`
						wpapsk=`expr substr $wpapsk 2 $clen`
						rm /tmp/clientpwd
					#fi
					rm /tmp/WPSpinKEY	
				fi
		
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_remembered.sh WPS PIN PSK" "$wpapsk" >> /tmp/wificlientap.log
				fi
				
				if [ "$scantmp" != "" ]; then
					echo $scantmp > /tmp/wifinetwork-remembered.conf
					sed -i '/'"${connectedmac}"'/ s/security_key=.*/security_key='\"${wpapsk}\"' /' /tmp/wifinetwork-remembered.conf
				else 	
					key_mgmt=`wpa_cli -i "${ifAction}" status | grep -rsw "key_mgmt" | awk -F= '{print $NF}'`
					if [ "$key_mgmt" == "WPA-PSK" ]; then
						key_mgmt="WPAPSK"
					else 
						key_mgmt="WPA2PSK"
					fi
									
					hiddenProfile="ssid=\""${connectedSsid}"\" mac=\""${connectedmac}"\" signal_strength=\""80"\" auto_join=\""true"\"  trusted=\""false"\" security_mode=\""${key_mgmt}/AES"\" connected=\""true"\" remembered=\""true"\" secured=\"true\" wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""true"\" ip=\"\" netmask=\"\" gateway=\"\" dns0=\"\" dns1=\"\" dns2=\"\" mac_clone_enable=\"false\" cloned_mac_address=\"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${wpapsk}\""
					
					cli2encryptype=${key_mgmt}
					cli2cipher="AES"
					
					echo "${hiddenProfile}" | awk 'BEGIN {FS="bssi/dmap="} {print $1}' > /tmp/wifinetwork-remembered.conf	
				fi
				cli2key="${wpapsk}"
				
				confSsid="${connectedSsid}"
				echo "${confSsid}" | grep -q '\"\|\$\|\&\|/\||\|\\'
				if [ $? == 0 ]; then
					echo "$confSsid" > /tmp/clientssid
					sed -i 's/\\/\\\\/g' /tmp/clientssid
					sed -i 's/"/\\"/g' /tmp/clientssid
					sed -i 's/\$/\\$/g' /tmp/clientssid
					sed -i 's/&/\\&/g' /tmp/clientssid
					sed -i 's/\//\\\//g' /tmp/clientssid
					sed -i 's/|/\\|/g' /tmp/clientssid
					confSsid=`cat /tmp/clientssid`
					rm /tmp/clientssid
				fi
				sed -i 's/STA_MAC_ADDRESS=.*/STA_MAC_ADDRESS='${connectedmac}'/' /etc/nas/config/wifinetwork-param.conf
				sed -i 's/STA_SSID_NAME=.*/STA_SSID_NAME='\""${confSsid}"\"'/' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/|/\\|/g' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/\$/\\\$/g' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
				sed -i '/STA_SSID_NAME/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf		
				
				confpsk="${wpapsk}"
				#echo "${confpsk}" | grep -q '\"\|\$\|\&\|/\||\|\\'
				#	if [ $? == 0 ]; then
				#		echo $confpsk > /tmp/clientpwd
				#		sed -i 's/\\/\\\\/g' /tmp/clientpwd
				#		sed -i 's/"/\\"/g' /tmp/clientpwd
				#		sed -i 's/\$/\\$/g' /tmp/clientpwd
				#		sed -i 's/&/\\&/g' /tmp/clientpwd
				#		sed -i 's/\//\\\//g' /tmp/clientpwd
				#		sed -i 's/|/\\|/g' /tmp/clientpwd
				#		confpsk=`cat /tmp/clientpwd`
				#		rm /tmp/clientpwd
				#fi
				sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY='\"${confpsk}\"'/' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/|/\\|/g' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
				#sed -i '/STA_PSK_KEY/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf
				STA_SSID_NAME="$connectedSsid"
				echo "22;0;"  > /tmp/MCU_Cmd
			fi
		
			#if [ "$Debugmode" == "1" ]; then
			#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			#	echo $timestamp ": wifi_client_remembered.sh connectedSsid" "$connectedSsid" >> /tmp/wificlientap.log
			#fi
			
			confSsid="${STA_SSID_NAME}"
				echo "${confSsid}" | grep -q '\"\|\$\|\&\|/\||\|\\'
				if [ $? == 0 ]; then
					echo "$confSsid" > /tmp/clientssid
					sed -i 's/\\/\\\\/g' /tmp/clientssid
					sed -i 's/"/\\"/g' /tmp/clientssid
					sed -i 's/\$/\\$/g' /tmp/clientssid
					sed -i 's/&/\\&/g' /tmp/clientssid
					sed -i 's/\//\\\//g' /tmp/clientssid
					sed -i 's/|/\\|/g' /tmp/clientssid
					confSsid=`cat /tmp/clientssid`
					rm /tmp/clientssid
				fi
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_remembered.sh Save conf STA_SSID_NAME:" "$STA_SSID_NAME" >> /tmp/wificlientap.log
			fi
			
			if [ "$STA_SSID_NAME" == "$connectedSsid" ]; then
				if [ "$cli2encryptype" == "NONE" ]; then
					hiddenProfile="ssid=\""${connectedSsid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				elif [ "$cli2encryptype" == "WEP" ]; then
					hiddenProfile="ssid=\""${connectedSsid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				else
					hiddenProfile="ssid=\""${connectedSsid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}/${cli2cipher}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				fi
		
				#if [ "${STA_CONF_REMB}" == "1" ]; then
					sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
					matchssid=`cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsnw "\"${connectedSsid}\""`
					#scanSsid=`echo "${matchssid}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
					#scanMAC=`echo "${matchssid}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
					#if [ "${connectedSsid}" == "${scanSsid}" ] && [ "${cli2mac}" == "${scanMAC}" ]; then
					if [ "${matchssid}" != "" ]; then
						if [ "$Debugmode" == "1" ]; then
							timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestamp ": wifi_client_remembered.sh Replace Profile: ""${connectedSsid}" >> /tmp/wificlientap.log
						fi
						lineNum=`echo "${matchssid}" | cut -d ':' -f 1`
						#sed -i "${lineNum}"d /etc/nas/config/wifinetwork-remembered.conf
						sed ${lineNum}d /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
						cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
					fi
					sed -i 's/\\"/"/g' /etc/nas/config/wifinetwork-remembered.conf
					cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
					echo "${hiddenProfile}" > /etc/nas/config/wifinetwork-remembered.conf
					cat /tmp/wifinetwork-remembered_tmp.conf >> /etc/nas/config/wifinetwork-remembered.conf
					#sed -i 's/\\\\/\\/g' /etc/nas/config/wifinetwork-remembered.conf
				
					rm /tmp/wifinetwork-remembered_tmp.conf
					CheckSaveProfileNum
				#else
				#	matchssid=`grep -rsnw "\"${connectedSsid}\"" /etc/nas/config/wifinetwork-remembered.conf`
				#	if [ "${matchssid}" != "" ]; then
				#		if [ "$Debugmode" == "1" ]; then
				#			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				#			echo $timestamp ": wifi_client_remembered.sh Replace Profile inlist" >> /tmp/wificlientap.log
				#			echo $timestamp ": wifi_client_remembered.sh" "${matchssid}" >> /tmp/wificlientap.log
				#		fi
				#		lineNum=`echo "$matchssid" | cut -d ':' -f 1`
				#		checkloop=1
				#		if [ -f "/tmp/wifinetwork-remembered_tmp.conf" ]; then
				#			rm /tmp/wifinetwork-remembered_tmp.conf
				#		fi
		        #
				#		cat /etc/nas/config/wifinetwork-remembered.conf | while read RemProfile
				#		do
				#			if [ "$checkloop" == "$lineNum" ]; then
				#				echo $hiddenProfile >> /tmp/wifinetwork-remembered_tmp.conf
				#			else
				#				echo $RemProfile >> /tmp/wifinetwork-remembered_tmp.conf
				#			fi
		 		#			checkloop=`expr $checkloop + 1`
				#		done
				#		cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
				#	else
				#		cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
				#		echo $hiddenProfile > /etc/nas/config/wifinetwork-remembered.conf
				#		sed -i 's/\\"/"/g' /etc/nas/config/wifinetwork-remembered.conf
				#		cat /tmp/wifinetwork-remembered_tmp.conf >> /etc/nas/config/wifinetwork-remembered.conf
				#	fi
				#fi
				
				echo "${hiddenProfile}" | awk 'BEGIN {FS="bssi/dmap="} {print $1}' > /tmp/wifinetwork-remembered.conf
				sed -i 's/\\"/"/g' /tmp/wifinetwork-remembered.conf
				
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_remembered.sh, latest profile: ">> /tmp/wificlientap.log
					echo $timestamp ": wifi_client_remembered.sh" "$hiddenProfile" >> /tmp/wificlientap.log
				fi
			fi
		else
			#ConnectProfile=`head -n 1 /tmp/wifinetwork-remembered.conf`	
			#cli2mac=`echo ${ConnectProfile} | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
			#cli2key=`echo ${ConnectProfile} | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2`
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_remembered.sh" "STA_MAC_ADDRESS" "$STA_MAC_ADDRESS" "connectedmac" "$connectedmac" >> /tmp/wificlientap.log
				echo $timestamp ": wifi_client_remembered.sh" "connectedSsid" "$connectedSsid" "cli2Ssid" "$cli2Ssid" >> /tmp/wificlientap.log
			fi
			if [ "$STA_MAC_ADDRESS" == "$connectedmac" ] || [ "\"$connectedSsid"\" == "\"$cli2Ssid"\" ]; then
				if [ "$cli2key" == "MyPassportWirelessWPSSecurityKeyTEMPoRarily" ]; then
					if [ "$Debugmode" == "1" ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": wifi_client_remembered.sh Trigger by WPS PIN ">> /tmp/wificlientap.log
					fi
					if [ -f "/tmp/WPSpinKEY" ]; then
						wpapsk=`cat /tmp/WPSpinKEY` 
						#echo "${wpapsk}" | grep -q '\"\|\$\|\&\|/\||\|\\'
						#if [ $? == 0 ]; then
						#	echo $wpapsk > /tmp/clientpwd
						#	sed -i 's/\\/\\\\/g' /tmp/clientpwd
						#	sed -i 's/"/\\"/g' /tmp/clientpwd
						#	sed -i 's/\$/\\$/g' /tmp/clientpwd
						#	sed -i 's/&/\\&/g' /tmp/clientpwd
						#	sed -i 's/\//\\\//g' /tmp/clientpwd
						#	sed -i 's/|/\\|/g' /tmp/clientpwd
						#	wpapsk=`cat /tmp/clientpwd`
							len=${#wpapsk}
							clen=`expr $len - 2`
							wpapsk=`expr substr $wpapsk 2 $clen`
							#rm /tmp/clientpwd
						#fi
						if [ "$Debugmode" == "1" ]; then
							timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestamp ": wifi_client_remembered.sh WPS PIN PSK" "$wpapsk" >> /tmp/wificlientap.log
						fi
						cli2key="${wpapsk}"
						rm /tmp/WPSpinKEY	
					fi
					sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY='\"${cli2key}\"'/' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/|/\\|/g' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
					sed -i '/STA_PSK_KEY/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf
					echo "22;0;"  > /tmp/MCU_Cmd
				fi
									
				if [ "$cli2encryptype" == "NONE" ]; then
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				elif [ "$cli2encryptype" == "WEP" ]; then
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				else
					hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${connectedmac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$cli2join"\" trusted=\""$cli2trust"\" security_mode=\""${cli2encryptype}/${cli2cipher}"\" connected=\""true"\" remembered=\""${cliremembered}"\" secured=${clisecured} wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$cliDhcp"\" ip=\""$cliip"\" netmask=\""$climask"\" gateway=\""$cligw"\" dns0=\""$clidns0"\" dns1=\""$clidns1"\" dns2=\""$clidns2"\" mac_clone_enable=\""$cliclone"\" cloned_mac_address=\""$clicloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${cli2key}\""
				fi
				#sed '/'"${connectedSsid}"'/d' /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf				
				#cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
				#if [ "${STA_CONF_REMB}" == "1" ]; then
					if [ "$Debugmode" == "1" ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": wifi_client_remembered.sh: update Profile"  >> /tmp/wificlientap.log
					fi
				
					sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
					matchssid=`cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsnw "\"${connectedSsid}\""`
					if [ "${matchssid}" != "" ]; then
						lineNum=`echo "$matchssid" | cut -d ':' -f 1`
						#sed -i "${lineNum}"d /etc/nas/config/wifinetwork-remembered.conf
						sed ${lineNum}d /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
						cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
					fi
					sed -i 's/\\"/"/g' /etc/nas/config/wifinetwork-remembered.conf
					cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
					echo "${hiddenProfile}" > /etc/nas/config/wifinetwork-remembered.conf
					cat /tmp/wifinetwork-remembered_tmp.conf >> /etc/nas/config/wifinetwork-remembered.conf
					#sed -i 's/\\\\/\\/g' /etc/nas/config/wifinetwork-remembered.conf
				
					rm /tmp/wifinetwork-remembered_tmp.conf
					CheckSaveProfileNum
				#else
				#	matchssid=`grep -rsnw "\"${connectedSsid}\"" /etc/nas/config/wifinetwork-remembered.conf`
				#	if [ "${matchssid}" != "" ]; then
				#		lineNum=`echo "$matchssid" | cut -d ':' -f 1`
				#		checkloop=1
				#		if [ -f "/tmp/wifinetwork-remembered_tmp.conf" ]; then
				#			rm /tmp/wifinetwork-remembered_tmp.conf
				#		fi
				#		cat /etc/nas/config/wifinetwork-remembered.conf | while read RemProfile
				#		do
				#			if [ "$checkloop" == "$lineNum" ]; then
				#				echo $hiddenProfile >> /tmp/wifinetwork-remembered_tmp.conf
				#			else
				#				echo $RemProfile >> /tmp/wifinetwork-remembered_tmp.conf
				#			fi
		 		#			checkloop=`expr $checkloop + 1`
				#		done
				#		cat /tmp/wifinetwork-remembered_tmp.conf > /etc/nas/config/wifinetwork-remembered.conf
				#	else
				#		cat /etc/nas/config/wifinetwork-remembered.conf > /tmp/wifinetwork-remembered_tmp.conf
				#		echo $hiddenProfile > /etc/nas/config/wifinetwork-remembered.conf
				#		sed -i 's/\\"/"/g' /etc/nas/config/wifinetwork-remembered.conf
				#		cat /tmp/wifinetwork-remembered_tmp.conf >> /etc/nas/config/wifinetwork-remembered.conf
				#	fi
				#fi
				
				echo "${hiddenProfile}" | awk 'BEGIN {FS="bssi/dmap="} {print $1}' > /tmp/wifinetwork-remembered.conf
				sed -i 's/\\"/"/g' /tmp/wifinetwork-remembered.conf
				#sed -i 's/\\\\/\\/g' /tmp/wifinetwork-remembered.conf
				
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_remembered.sh, latest profile: ">> /tmp/wificlientap.log
					echo $timestamp ": wifi_client_remembered.sh" "$hiddenProfile" >> /tmp/wificlientap.log
				fi
			fi
		fi
		/usr/local/sbin/wifi_client_trust_mode.sh "${ifAction}" up execRemember > /dev/null 2>&1 &
		clearTempfile
		/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1 &
	fi
	rm /tmp/wifi_client_remembered_execute
	exit 0
fi
