#!/bin/bash
#
# ｿ2010 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_connect.sh
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

RememberedConnect=0
macSetting=0
confjoin=1
hiddenSsid=0
cli2bssid=1
ChangeNetwork=false
cliDhcp=true
clientDHCP=true
trusted=false
auto_join=true
Onboarding=false
#auto_login=true
remember=true
maclone=false
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_connect.sh" $@ >> /tmp/wificlientap.log
fi

function trans_to_hex {
	for i in $(echo $1 | sed -e "s/\./ /g"); do  
      	printf '%02x' $i >/dev/null 2>/dev/null < /dev/null
    done
}

RemoveWPS() {
	if [ -f "/tmp/WPSpinMethod" ]; then
		rm /tmp/WPSpinMethod
	fi
}

ErrorCode(){
	echo "wifi_client_ap_connect.sh --connect <mac>|<ssid> [--security_key <key>] [--security_mode <mode>] \
[--auto_join true|false] [--remember_network true|false] [--trusted true|false] \
[--dhcp_enabled true|false] [--ip <ip>] [--netmask <netmask>] [--gateway <gateway> ] \
[--dns0 <dns0> ] [--dns1 <dns1>] [--dns2 <dns2>][--mac_clone_enable < mac_clone_enable > ] \
[--clone_mac_address  < clone_mac_address >] | --disconnect <mac> | --pinconnect <wps_pin> --mac <mac> | \
 --ssid <ssid> [--trusted true|false]"

	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_connect.sh input parameter error" "$1"  >> /tmp/wificlientap.log
	fi
	exit 1
}

if [ $# == 0 ]; then
	ErrorCode "--All"
fi

#if [ "$STA_CLIENT" == "false" ]; then 
#	if [ "$Debugmode" == "1" ]; then
#		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
#		echo $timestamp ": wifi_client_ap_connect.sh Wifi client off" >> /tmp/wificlientap.log
#	fi
#	exit 1
#fi

option_connect=$1
string_mac="${2}"
if [ "$option_connect" == "--connect" ]; then
	RememberAP=`cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | head -1`
	#RememberAP=`cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsi "\"${string_mac}\""`
	if [ "$RememberAP" != "" ]; then
  		RememberedConnect=1
  		cli2Signal=`echo "${RememberAP}" | awk 'BEGIN{FS="signal_strength=" } {print $NF}' | cut -d '"' -f 2`
		if [ "$cli2Signal" == "0" ]; then
			if [ "$Debugmode" == "1" ]; then
  				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_connect.sh miss target MAC:" "${string_mac}"  >> /tmp/wificlientap.log
  			fi
  			exit 2
		else
			if [ "$Debugmode" == "1" ]; then
  				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_connect.sh RememberAP target profile:" "${RememberAP}"  >> /tmp/wificlientap.log
  			fi
		fi  		
  		
  		if [ "$RememberedConnect" == "1" ]; then
  			cli2mac=`echo "${RememberAP}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
    		auto_join=`echo "${RememberAP}" | awk 'BEGIN{FS="auto_join=" } {print $NF}' | cut -d '"' -f 2`
    		trusted=`echo "${RememberAP}" | awk 'BEGIN{FS="trusted=" } {print $NF}' | cut -d '"' -f 2`
    		cli2encryptype=`echo "${RememberAP}" | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $1}'`

    		ciphertype=`echo "${RememberAP}" | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $2}' | awk '{print $1}'`
    		security_mode=$cli2encryptype\/$ciphertype
    		cli2bssid=`echo "${RememberAP}" | awk 'BEGIN{FS="bssi\/dmap=" } {print $NF}' | cut -d ' ' -f 1`
    		cli2key_base=`echo "${RememberAP}" | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2` 
    		#security_key=`echo "$cli2key_base" | openssl base64 -d`
    		echo "${cli2key_base}" | awk -F: '{print $1}' > /tmp/opensslbase64
			echo "${cli2key_base}" | awk -F: '{print $2}' >> /tmp/opensslbase64
			echo "${cli2key_base}" | awk -F: '{print $3}' >> /tmp/opensslbase64
			security_key=`cat "/tmp/opensslbase64" | openssl base64 -d`
    		
    		remember=`echo "${RememberAP}" | awk 'BEGIN{FS="remembered=" } {print $NF}' | cut -d '"' -f 2`
    		clientDHCP=`echo "${RememberAP}" | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2`
			clientIp=`echo "${RememberAP}" | awk 'BEGIN{FS="ip=" } {print $NF}' | cut -d '"' -f 2`
			clientmask=`echo "${RememberAP}" | awk 'BEGIN{FS="netmask=" } {print $NF}' | cut -d '"' -f 2`
			clientgw=`echo "${RememberAP}" | awk 'BEGIN{FS="gateway=" } {print $NF}' | cut -d '"' -f 2`
			clientdns0=`echo "${RememberAP}" | awk 'BEGIN{FS="dns0=" } {print $NF}' | cut -d '"' -f 2`
			clientdns1=`echo "${RememberAP}" | awk 'BEGIN{FS="dns1=" } {print $NF}' | cut -d '"' -f 2`
			clientdns2=`echo "${RememberAP}" | awk 'BEGIN{FS="dns2=" } {print $NF}' | cut -d '"' -f 2`
			maclone=`echo "${RememberAP}" | awk 'BEGIN{FS="mac_clone_enable=" } {print $NF}' | cut -d '"' -f 2`
			cloneaddr=`echo "${RememberAP}" | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2`
			cliband=`echo "${RememberAP}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
			cliwpsenabled=`echo ${RememberAP} | awk 'BEGIN{FS="wps_enabled=" } {print $NF}' | cut -d '"' -f 2`
			
			echo "${RememberAP}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2 > /tmp/cli2Ssid
    		sed -i 's/"//' /tmp/cli2Ssid	
			sed -i 's/\(.*\)\"/\1/' /tmp/cli2Ssid
			cli2Ssid=`cat /tmp/cli2Ssid`
   			rm /tmp/cli2Ssid	
			
       		if [ "$Debugmode" == "1" ]; then
  				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_connect.sh exist list: ""$cli2Ssid" "$cli2mac" "$cli2bssid" >> /tmp/wificlientap.log
  			fi
       		
			if [ "$cli2bssid" == "1" ]; then
				macSetting=1
				hiddenSsid=0
			else
				macSetting=0
				hiddenSsid=1
			fi
		fi
	fi

elif [ "$option_connect" == "--pinconnect" ]; then 
#wifi_client_ap_connect.sh --pinconnect 12345678 --mac C8:D3:A3:68:35:6A --trusted false	
	pincode="$2"
	if [ `expr $(echo $pincode | wc -m) - 1` != 8 ]; then
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_connect.sh WPS PIN Error:" "$pincode" >> /tmp/wificlientap.log
		fi
		exit 7
	fi

	ConnectAP=$3
	if [ "$3" == "--ssid" ]; then
		string_mac="$4"
	elif [ "$3" == "--mac" ]; then
		string_mac="$4"
	fi

	confjoin=2
	macaddr=`grep -rsi "\"${string_mac}\"" /tmp/scanlist | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="mac="} {print $NF}' | cut -d '"' -f 2 | tail -1` 
	if [ "${string_mac}" ==  "${macaddr}" ]; then
		macSetting=1
	fi
	wpsupport=`grep -rsi "\"${string_mac}\"" /tmp/scanlist | grep -v 'signal_strength="0"' | awk 'BEGIN {FS="wps_mode="} {print $NF}' | cut -d '"' -f 2 | tail -1` 
	if [ "$wpsupport" == "false" ]; then
		echo "WpsNotSupported" > /tmp/WPSpinMethod
	fi
	
	security_mode=`grep -rsi "\"${string_mac}\"" /tmp/scanlist | grep -v 'signal_strength="0"' | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | tail -1`
	security_key=MyPassportWirelessWPSSecurityKeyTEMPoRarily
	
elif [ "$option_connect" == "--PBCconnect" ]; then

#echo ApMode > /tmp/ConnectionMode
#/sbin/wifi-restart STA
#wpa_cli -i wlan0 wps_pbc
#wpa_cli -i wlan2 wps_pbc
#wpa_cli -i wlan2 wps_cancel

exit 0
elif [ "$option_connect" == "--disconnect" ]; then
	ErrorCode "-- option_connect disconnect "
else 
	ErrorCode "-- option_connect error "
fi


while [ "$3" != "" ]; do
	case $3 in
   		--mac )
   				shift
   				if [ "${pincode}" != "" ]; then
   					string_mac="$3"
   				fi
   				;;		
   		
   		--isOnboarding )
   				shift
   				Onboarding="$3"
   				if [ "${Onboarding}" != "true" ] && [ "${Onboarding}" != "false" ]; then
   					ErrorCode "--isOnboarding"
   				fi
   				;;
       	--security_key  )
       			shift
                security_key="$3"
                ;;
       	--security_mode )
       	  		shift
                security_mode="$3"
                ;;
       	--auto_join )
       	      	shift
                auto_join="$3"
                if [ "$auto_join" != "true" ] && [ "$auto_join" != "false" ]; then
              		ErrorCode "--auto_join"
                fi
                ;;          
       --trusted )
       			shift
                trusted="$3"
                if [ "$trusted" != "true" ] && [ "$trusted" != "false" ]; then
              		ErrorCode "--trusted"
                fi
                ;;
       --remember_network )
       			shift
                remember="$3"
                if [ "$remember" != "true" ] && [ "$remember" != "false" ]; then
              		ErrorCode "--remember_network"
                fi
                ;;
       --change_network )	   
       			shift
       			ChangeNetwork="$3"
        		;;
       --dhcp_enabled )
       			shift
       			clientDHCP="$3"
       			if [ "$clientDHCP" != "true" ] && [ "$clientDHCP" != "false" ]; then
        			ErrorCode "--dhcp_enabled"
        		fi
       			;;
     	--ip )	
     			if [ "$clientDHCP" == "false" ]; then
      				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
      					shift
						clientIp="$3"
					else
						ErrorCode "--ip"
					fi
				fi
      			;;
    	--netmask )
    			if [ "$clientDHCP" == "false" ]; then
    				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
       					shift
						clientmask="$3"
					else 
						ErrorCode "--netmask"
					fi
				fi
       			;;

    	--gateway )				
    			if [ "$clientDHCP" == "false" ]; then
    				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
       					shift
						clientgw="$3"
					else
						ErrorCode "--gateway"
					fi
				fi
        		;;
       	--dns0 )				
       			if [ "$clientDHCP" == "false" ]; then
       				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
       					shift
						clientdns0="$3"
					fi
				fi
        		;;
       	--dns1 )
       			if [ "$clientDHCP" == "false" ]; then
       				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
       					shift
						clientdns1="$3"
					fi
				fi
        		;;
       			
      	--dns2 )
      			if [ "$clientDHCP" == "false" ]; then
      				trans_to_hex "$4"
       				if [ "$?" == 0 ]; then	
       					shift
						clientdns2="$3"
					fi
				fi
        		;;
        						
        --mac_clone_enable )
        		shift							
        		maclone="$3"
        		if [ "$maclone" != "true" ] && [ "$maclone" != "false" ]; then
        			ErrorCode "--mac_clone_enable"
        		fi
        		;;
        
        --cloned_mac_address )	
        		if [ "$maclone" == "true" ]; then
        			shift
        			if [ "$3" == "" ]; then
        				ErrorCode "--cloned_mac_address"
        			else
        				cloneaddr="$3"
        			fi
        		fi
        		;;
   esac
   shift
done

if [ "$clientDHCP" == "false" ]; then
	if [ "$clientIp" == "" ] && [ "$clientmask" == "" ]; then
		ErrorCode "--clientIp --clientmask"
	fi
fi

if [ "${security_mode}" == "" ]; then
	ErrorCode "--security_mode"
	exit 1
fi

case $security_mode in
	NONE )
		if [ `expr $(echo $security_key | wc -m) - 1` == 0 ]; then
       		security_key=""
       	else
       		if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_connect.sh OPEN Security with Key:" "$security_key" >> /tmp/wificlientap.log
			fi
       		exit 6
       	fi
		;;
	WEP )
		if [ `expr $(echo $security_key | wc -m) - 1` == 5 ] || [ `expr $(echo $security_key | wc -m) - 1` == 10 ] || [ `expr $(echo $security_key | wc -m) - 1` == 13 ] || [ `expr $(echo $security_key | wc -m) - 1` == 26 ]; then
    		if [ `expr $(echo $security_key | wc -m) - 1` == 10 ] || [ `expr $(echo $security_key | wc -m) - 1` == 26 ]; then
    			for ((index=1; index<=`expr $(echo ${security_key} | wc -m) - 1`; index++ )); do
    				character=`echo ${security_key} | sed 's/\(.\{1\}\)/\1 /g' | awk -v num=$index '{print $num}'`
    				echo ${character} | grep -q -v '[A-Fa-f0-9]'
    				if [ $? == 0 ]; then
						if [ "$Debugmode" == "1" ]; then
							timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestamp ": wifi_client_ap_connect.sh WEP Security with Key:" "$security_key" >> /tmp/wificlientap.log
						fi
						exit 5
					fi
    			done
    		fi
        else
        	if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_connect.sh WEP Security with Key:" "$security_key" >> /tmp/wificlientap.log
			fi
        	exit 4
        fi
		;;
		
	* )
		securitype=`echo "${security_mode}" | awk -F/ '{print $1}'`
		ciphertype=`echo "${security_mode}" | awk -F/ '{print $2}'`
    	if [ "$securitype" == "WPAPSK" ] || [ "$securitype" == "WPA2PSK" ] || [ "$securitype" == "WPAPSK1WPAPSK2" ]; then
    		if [ "$ciphertype" != "TKIPAES" ] && [ "$ciphertype" != "TKIP" ] && [ "$ciphertype" != "AES" ]; then
        		if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_ap_connect.sh Unknown Security" >> /tmp/wificlientap.log
				fi
        		exit 5
        	fi
        	if [ `expr $(echo $security_key | wc -m) - 1` -lt 8 ] && [ `expr $(echo $security_key | wc -m) - 1` -gt 63 ]; then
        		if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_ap_connect.sh WPA Security with Key:" "$security_key" >> /tmp/wificlientap.log
				fi
            	exit 4
        	fi
   	 	fi
		;;
esac

if [ "$RememberedConnect" != "1" ]; then
	if [ ! -f "/tmp/scanlist" ]; then
		cat /tmp/scan_result >> /tmp/scanlist
	fi
	ConnectProfile=`cat "/tmp/scanlist" | grep -rsi "${string_mac}" | grep -v 'signal_strength="0"' | tail -1`	
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_connect.sh scanlist ConnectProfile:" "$ConnectProfile" >> /tmp/wificlientap.log
	fi
	if [ "${ConnectProfile}" != "" ]; then
		macSetting=1
		cli2Ssid=`echo "${ConnectProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2` 
		cli2mac=`echo "${ConnectProfile}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
		cli2Signal=`echo "${ConnectProfile}" | awk 'BEGIN{FS="signal_strength=" } {print $NF}' | cut -d '"' -f 2`
		cliwpsenabled=`echo "${ConnectProfile}" | awk 'BEGIN{FS="wps_enabled=" } {print $NF}' | cut -d '"' -f 2`
		cliband=`echo "${ConnectProfile}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
	else
		macSetting=0
		cli2Ssid="${string_mac}"
		cli2mac="00:00:00:00:00:00"
		cli2Signal="90"
		cliwpsenabled="false"
		cliband="All"
		cli2bssid=0
	fi
fi

if [ "$security_mode" != "NONE" ]; then
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_connect.sh WPA Security with Key:" "$security_key" >> /tmp/wificlientap.log
	fi
	echo -n "${security_key}" | openssl base64 > /tmp/opensslbase64
	Keyline=`cat /tmp/opensslbase64 | wc -l`
	if [ "${Keyline}" == "1" ]; then
		security_key=`cat /tmp/opensslbase64`
	elif [ "${Keyline}" == "2" ]; then
		security_key="`cat /tmp/opensslbase64 | sed -n 1p`"":""`cat /tmp/opensslbase64 | sed -n 2p`"
	elif [ "${Keyline}" == "3" ]; then	
		security_key="`cat /tmp/opensslbase64 | sed -n 1p`"":""`cat /tmp/opensslbase64 | sed -n 2p`"":""`cat /tmp/opensslbase64 | sed -n 3p`"
	fi
fi

if [ "$security_mode" == "NONE" ]; then
	hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${string_mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$auto_join"\" trusted=\""$trusted"\" security_mode=\""${security_mode}"\" connected=\""false"\" remembered=\""${remember}"\" secured=\""false"\" wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$clientDHCP"\" ip=\""$clientIp"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$maclone"\" cloned_mac_address=\""$cloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${security_key}\""
elif [ "$security_mode" == "WEP" ]; then
	hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${string_mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$auto_join"\" trusted=\""$trusted"\" security_mode=\""${security_mode}"\" connected=\""false"\" remembered=\""${remember}"\" secured=\""true"\" wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$clientDHCP"\" ip=\""$clientIp"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$maclone"\" cloned_mac_address=\""$cloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${security_key}\""
else
	hiddenProfile="ssid=\""${cli2Ssid}"\" mac=\""${string_mac}"\" signal_strength=\""${cli2Signal}"\" auto_join=\""$auto_join"\" trusted=\""$trusted"\" security_mode=\""${security_mode}"\" connected=\""false"\" remembered=\""${remember}"\" secured=\""true"\" wps_enabled="\"${cliwpsenabled}\"" dhcp_enabled=\""$clientDHCP"\" ip=\""$clientIp"\" netmask=\""$clientmask"\" gateway=\""$clientgw"\" dns0=\""$clientdns0"\" dns1=\""$clientdns1"\" dns2=\""$clientdns2"\" mac_clone_enable=\""$maclone"\" cloned_mac_address=\""$cloneaddr"\" bssi/dmap=$cli2bssid Frequency=\"${cliband}\" security_key=\"${security_key}\""
fi

#echo "${hiddenProfile}" | awk 'BEGIN {FS="bssi/dmap="} {print $1}' > /tmp/wifinetwork-remembered.conf	
echo "${hiddenProfile}" > /tmp/wifinetwork-remembered.conf	

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_connect.sh target Profile:" "$hiddenProfile" >> /tmp/wificlientap.log
fi

if [ "$cli2Ssid" != "" ]; then
	OldSsid=${STA_SSID_NAME}
	if [ "${OldSsid}" != "${cli2Ssid}" ]; then
		echo 0 > /tmp/ApCliRetry
	fi
	
	echo "${cli2Ssid}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	if [ $? == 0 ]; then
		echo "$cli2Ssid" > /tmp/clientssid
		sed -i 's/\\/\\\\/g' /tmp/clientssid
		sed -i 's/"/\\"/g' /tmp/clientssid
		sed -i 's/\$/\\$/g' /tmp/clientssid
		sed -i 's/&/\\&/g' /tmp/clientssid
		sed -i 's/\//\\\//g' /tmp/clientssid
		sed -i 's/|/\\|/g' /tmp/clientssid
		cli2Ssid=`cat /tmp/clientssid`
		rm /tmp/clientssid
	fi 	
	
	sed -i 's/STA_SSID_NAME=.*/STA_SSID_NAME='\""${cli2Ssid}"\"'/' /etc/nas/config/wifinetwork-param.conf
	sed -i '/STA_SSID_NAME/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_SSID_NAME/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
	sed -i '/STA_SSID_NAME/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
	sed -i '/STA_SSID_NAME/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
	sed -i '/STA_SSID_NAME/ s/\\"/"/g' /etc/nas/config/wifinetwork-param.conf
	sed -i '/STA_SSID_NAME/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf	
fi

if [ "${macSetting}" == "1" ]; then
	sed -i 's/STA_MAC_ADDRESS=.*/STA_MAC_ADDRESS='${cli2mac}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_MAC_MAPPING=.*/STA_MAC_MAPPING='${macSetting}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_HIDDEN=.*/STA_CONF_HIDDEN=0/' /etc/nas/config/wifinetwork-param.conf
else
	sed -i 's/STA_MAC_ADDRESS=.*/STA_MAC_ADDRESS='${cli2mac}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_MAC_MAPPING=.*/STA_MAC_MAPPING='${macSetting}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_HIDDEN=.*/STA_CONF_HIDDEN=1/' /etc/nas/config/wifinetwork-param.conf
fi

if [ "$security_mode" == "NONE" ] || [ "$security_mode" == "WEP" ]; then
	sed -i 's/STA_SECURITY_MODE=.*/STA_SECURITY_MODE='${security_mode}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CIPHER_TYPE=.*/STA_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
else
	sed -i 's/STA_SECURITY_MODE=.*/STA_SECURITY_MODE='${securitype}'/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CIPHER_TYPE=.*/STA_CIPHER_TYPE='${ciphertype}'/' /etc/nas/config/wifinetwork-param.conf
fi

if [ "${security_key}" == "" ]; then
	sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY=/' /etc/nas/config/wifinetwork-param.conf
else
	#echo "${security_key}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	#if [ $? == 0 ]; then
	#	echo $security_key > /tmp/clientpwd
	#	sed -i 's/\\/\\\\/g' /tmp/clientpwd
	#	sed -i 's/"/\\"/g' /tmp/clientpwd
	#	sed -i 's/\$/\\$/g' /tmp/clientpwd
	#	sed -i 's/&/\\&/g' /tmp/clientpwd
	#	sed -i 's/\//\\\//g' /tmp/clientpwd
	#	sed -i 's/|/\\|/g' /tmp/clientpwd
	#	wpapsk=`cat /tmp/clientpwd`
	#	rm /tmp/clientpwd
	#fi
	sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY='\""${security_key}"\"'/' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
	#sed -i '/STA_PSK_KEY/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf	
fi

sed -i 's/STA_CONF_JOIN=.*/STA_CONF_JOIN='${confjoin}'/' /etc/nas/config/wifinetwork-param.conf
if [ "${remember}" == "false" ]; then
	sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
else
	sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=1/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER=0/' /etc/nas/config/wifinetwork-param.conf
fi

if [ "${STA_CLIENT}" == "false" ]; then	
	sed -i 's/STA_CLIENT=.*/STA_CLIENT=true/' /etc/nas/config/wifinetwork-param.conf
fi

if [ "${cliband}" == "2" ]; then
	sed -i 's/STA_CHANNEL=.*/STA_CHANNEL=2/' /etc/nas/config/wifinetwork-param.conf
elif [ "${cliband}" == "5" ]; then
	sed -i 's/STA_CHANNEL=.*/STA_CHANNEL=5/' /etc/nas/config/wifinetwork-param.conf
else
	sed -i 's/STA_CHANNEL=.*/STA_CHANNEL='${cliband}'/' /etc/nas/config/wifinetwork-param.conf
fi


if [ "${maclone}" == "true" ]; then
	/etc/init.d/S73multi-role stop
	ifconfig wlan0 down hw ether "${cloneaddr}"
fi

if [ "$option_connect" == "--connect" ]; then
	killall -11 monitor
	if [ -f "/tmp/ClientConnStatus" ]; then
		rm /tmp/ClientConnStatus
	fi
	/sbin/wifi-restart STA > /dev/null 2>&1 &
	
elif [ "$option_connect" == "--pinconnect" ]; then 

/sbin/wifi-restart STA
if [ "$cliwpsenabled" == "false" ]; then 
	echo "WpsNotSupported" > /tmp/WPSpinMethod
	exit 1
else
	wpa_cli -i wlan1 wps_reg "$string_mac" $pincode
	echo "wps paired device not available" > /tmp/WPSpinMethod
	echo "22;1;"  > /tmp/MCU_Cmd
fi
exit 0

elif [ "$option_connect" == "--PBCconnect" ]; then

#echo ApMode > /tmp/ConnectionMode
#/sbin/wifi-restart STA
#wpa_cli -i wlan0 wps_pbc
#wpa_cli -i wlan2 wps_pbc
#wpa_cli -i wlan2 wps_cancel

exit 0

else 
	ErrorCode "-- option_connect error "
fi



if [ "$Onboarding" == "true" ]; then
	touch /tmp/OnboardingWiFiClientApConnection
else
	if [ -f "/tmp/OnboardingWiFiClientApConnection" ]; then
		rm /tmp/OnboardingWiFiClientApConnection
	fi
fi

if [ "$clientDHCP" == "false" ]; then
	if [ "$cliband" == "2" ]; then
		/usr/local/sbin/setNetworkStatic.sh "ifname=wlan2-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
	elif [ "$cliband" == "5" ]; then
		/usr/local/sbin/setNetworkStatic.sh "ifname=wlan0-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
	else
		/usr/local/sbin/setNetworkStatic.sh "ifname=wlan2-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
		/usr/local/sbin/setNetworkStatic.sh "ifname=wlan0-connect" "$clientIp" "$clientmask" "$clientgw" "$clientdns0" "$clientdns1" "$clientdns2"
	fi
else
	if [ "$cliband" == "2" ]; then
		/usr/local/sbin/setNetworkDhcp.sh "wlan2-connect"
	elif [ "$cliband" == "5" ]; then
		/usr/local/sbin/setNetworkDhcp.sh "wlan0-connect"
	else
		/usr/local/sbin/setNetworkDhcp.sh "wlan2-connect"
		/usr/local/sbin/setNetworkDhcp.sh "wlan0-connect"
	fi
fi

RemoveWPS
echo ApMode > /tmp/ConnectionMode

exit 0
