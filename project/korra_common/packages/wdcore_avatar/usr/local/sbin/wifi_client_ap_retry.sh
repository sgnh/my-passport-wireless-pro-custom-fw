#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_retry.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/config/wifinetwork-param.conf

Retry_ct=$1
CurrentRank=${STA_CONF_ORDER}
TempConnect=${STA_CONF_REMB}
loop=0
NoAJoinCt=0
FollowSignal=0
ApSignalTarget1=0
checkloop=0
ConnectRetry=`cat /tmp/ApCliRetry`

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_client_ap_retry.sh" $@ >> /tmp/wificlientap.log
fi

if [ "$STA_CLIENT" == "false" ]; then
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_client_ap_retry.sh Client Turn OFF" >> /tmp/wificlientap.log
	fi
	exit 3
fi

if [ -f "/tmp/TargetConnectAP" ]; then
	rm /tmp/TargetConnectAP
fi

if [ ! -f "/tmp/wifinetwork-remembered.conf" ]; then
	sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
	TempConnect=0
fi

if [ "$Retry_ct" -ge 2 ]; then
	for ((index=1; index<3; index++ )); do
		if [ -f /tmp/clientStatus ]; then
			ApCliStatus=`cat /tmp/clientStatus`
			if [ "$ApCliStatus" != "0" ]; then
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_client_ap_scan.sh wlan busy, wait" >> /tmp/wificlientap.log
				fi
				sleep 2
			else
				break;
			fi
		fi
    done

	if [ -f /tmp/clientStatus ]; then
		ApCliStatus=`cat /tmp/clientStatus`
		if [ "$ApCliStatus" != "0" ]; then
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_scan.sh wlan busy, wait" >> /tmp/wificlientap.log
			fi
			exit 2
		fi
	fi
	
	FileNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
	if [ "$FileNum" == 0 ]; then
		LimitRetry=0
	else
		LimitRetry=1
	fi
	
	NewRank=$CurrentRank	
	if [ -f "/tmp/ClientConnStatus" ]; then
		ApCliStauts=`cat /tmp/ClientConnStatus`
		/sbin/wifi-restart UPDATE_STA_CONF
		if [ "$STA_CHANNEL" == "2" ]; then
   			iname=$STA2G4_IFACE
   			#iname=${STA_IFACE}
		else
			iname=${STA_IFACE}
		fi
		wpa_cli -i ${iname} reconfigure

		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_retry.sh Wrong password:" "$ApCliStauts" >> /tmp/wificlientap.log
		fi
		if [ ! -f "/tmp/CliKeyRetry" ]; then
			keytry=0
			echo $keytry > /tmp/CliKeyRetry 
		else
			keytry=`cat /tmp/CliKeyRetry` 
			keytry=`expr $keytry + 1`
			echo $keytry > /tmp/CliKeyRetry 
		fi
		if [ "$keytry" -ge "$LimitRetry" ]; then
			#echo "Change Profile"  >> /tmp/clientdebug
			sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
			
			TempConnect=0
			NewRank=`expr $CurrentRank + 1`
			if [ "${NewRank}" -ge "$FileNum" ]; then
				NewRank=0
			fi
			sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER='${NewRank}'/' /etc/nas/config/wifinetwork-param.conf
			ConnectRetry=0
			echo $ConnectRetry > /tmp/ApCliRetry 
			echo "client_disconnect" > /tmp/client_disconnect
			rm /tmp/CliKeyRetry 
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_client_ap_retry.sh Change Profile:" "$NewRank" >> /tmp/wificlientap.log
			fi
		else
			exit 0
		fi
	fi
	
	if [ "$TempConnect" == "1" ]; then
		ReadProfileConf=/tmp/wifinetwork-remembered.conf
		RetryLimit=1
	else
		RetryLimit=1
		if [ "$FileNum" -ge "1" ]; then
			`/usr/local/sbin/wifi_client_ap_scan.sh --remembered signalConnect > /tmp/RememberNetwork1`
			cat /tmp/RememberNetwork1 | while read ConnectProfile
			do
				if [ "$loop" == "$NewRank" ]; then		
					echo $ConnectProfile > /tmp/TargetConnectAP
					if [ "$Debugmode" == "1" ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": wifi_client_ap_retry.sh Target Profile:" >> /tmp/wificlientap.log
						echo $timestamp ": wifi_client_ap_retry.sh" "$ConnectProfile" >> /tmp/wificlientap.log
					fi
					ApSignalTarget1=`echo "$ConnectProfile" | awk 'BEGIN{FS=" signal_strength=" }{print $2}' | cut -d '"' -f 2`
					echo $ApSignalTarget1 > /tmp/ApSignalTarget1
					ApSsidTarget1=`echo "${ConnectProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
					echo $ApSsidTarget1 > /tmp/ApSsidTarget1
					sed -i 's/"/\1/' /tmp/ApSsidTarget1	
					sed -i 's/\(.*\)\"/\1/' /tmp/ApSsidTarget1
					ApSsidTarget1=`cat /tmp/ApSsidTarget1`
				fi
				loop=`expr $loop + 1`
			done
			ApSignalTarget1=`cat /tmp/ApSignalTarget1`
			rm /tmp/ApSignalTarget1
			ApSsidTarget1=`cat /tmp/ApSsidTarget1`
			rm /tmp/ApSignalTarget1
			#if [ ! -f "/tmp/ConnectionLoop" ]; then
			#	echo "0" > /tmp/ConnectionLoop
				actionloop=0
			#else 
			#	actionloop=`cat /tmp/ConnectionLoop`
			#fi
			cat /tmp/RememberNetwork1 | sort -t '"' -k 6 -r -n > /tmp/RememberNetwork
			matchssid=`grep -rsnw \""${ApSsidTarget1}"\" /tmp/RememberNetwork`
			actionloop=`echo "$matchssid" | cut -d ':' -f 1`
			cat /tmp/RememberNetwork | while read RemProfile
			do
				if [ "$checkloop" -lt "$actionloop" ]; then
					ApSsidTarget2=`echo ${RemProfile} | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
					ApSignalTarget2=`echo "$RemProfile" | awk 'BEGIN{FS=" signal_strength=" }{print $2}' | cut -d '"' -f 2`
					ApJoinTarget2=`echo ${RemProfile} | awk 'BEGIN{FS="auto_join=" } {print $NF}' | cut -d '"' -f 2`
					if [ "$ApJoinTarget2" == "false" ]; then
						continue
					fi
					#echo "ApSignalTarget1" $ApSignalTarget1
					#echo "ApSignalTarget2" $ApSignalTarget2
					if [ "$ApSignalTarget2" -gt "$ApSignalTarget1" ]; then
						diffSignal=`expr $ApSignalTarget2 - $ApSignalTarget1`
						echo "diffSignal" $diffSignal
						if [ "$diffSignal" -gt "10" ]; then
							#echo "ApSsidTarget2" $ApSsidTarget2
							echo $RemProfile > /tmp/TargetConnectAP
							if [ "$Debugmode" == "1" ]; then
								timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestamp ": wifi_client_ap_retry.sh Singal:" "$ApSsidTarget2" "$ApSignalTarget2" "${ApSsidTarget1}" "$ApSignalTarget1" >> /tmp/wificlientap.log
								echo $timestamp ": wifi_client_ap_retry.sh Change Target Profile:" >> /tmp/wificlientap.log
								echo $timestamp ": wifi_client_ap_retry.sh" "$RemProfile" >> /tmp/wificlientap.log
							fi
							#cat /tmp/TargetConnectAP > /tmp/wifinetwork-remembered.conf
							ConnectRetry=0
							echo $ConnectRetry > /tmp/ApCliRetry 	
							#echo "ReadProfileConf" $ReadProfileConf
							#cat /tmp/TargetConnectAP	
							checkloop=`expr $checkloop + 1`
							if [ "${checkloop}" -ge "$FileNum" ]; then
								checkloop=0
							fi
							#echo "$checkloop" > /tmp/ConnectionLoop
							break
						fi
					fi
				fi
				checkloop=`expr $checkloop + 1`
			done
			
		fi
	fi
		if [ -f "/tmp/TargetConnectAP" ]; then
			ReadProfileConf=/tmp/TargetConnectAP
		else
			ReadProfileConf=/etc/nas/config/wifinetwork-remembered.conf
		fi
	
		cat "${ReadProfileConf}" | grep -v 'signal_strength="0"' | while read lineProfile
		do
				cli2Ssid=`echo "${lineProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
    			cli2mac=`echo "${lineProfile}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
    			cli2join=`echo "${lineProfile}" | awk 'BEGIN{FS="auto_join=" } {print $NF}' | cut -d '"' -f 2`
    			cli2trust=`echo "${lineProfile}" | awk 'BEGIN{FS="trusted=" } {print $NF}' | cut -d '"' -f 2`
    			cli2encryptype=`echo "${lineProfile}" | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $1}'`
    			cli2cipher=`echo "${lineProfile}" | awk 'BEGIN{FS="security_mode=" } {print $NF}' | cut -d '"' -f 2 | awk -F/ '{print $2}' | awk '{print $1}'`
    			cli2bssid=`echo "${lineProfile}" | awk 'BEGIN{FS="bssi\/dmap=" } {print $NF}' | cut -d ' ' -f 1`
    			cat /tmp/wifinetwork-remembered.conf | grep "security_key"
    			if [ $? == 0 ]; then
    				cli2key=`echo "${lineProfile}" | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2` 
    				#cli2key=`echo "$cli2key" | openssl base64 -d`
    				echo "${cli2key}" | awk -F: '{print $1}' > /tmp/opensslbase64
					echo "${cli2key}" | awk -F: '{print $2}' >> /tmp/opensslbase64
					echo "${cli2key}" | awk -F: '{print $3}' >> /tmp/opensslbase64
					cli2key=`cat "/tmp/opensslbase64" | openssl base64 -d`
    			else
    				RememberAP=`cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsw "${cli2Ssid}" | grep -rsi "${cli2mac}" | head -1`
  					if [ "${RememberAP}" != "" ]; then
  						cli2key=`echo "${RememberAP}" | awk 'BEGIN{FS="security_key=" } {print $NF}' | cut -d '"' -f 2` 
    					echo "${cli2key}" | awk -F: '{print $1}' > /tmp/opensslbase64
						echo "${cli2key}" | awk -F: '{print $2}' >> /tmp/opensslbase64
						echo "${cli2key}" | awk -F: '{print $3}' >> /tmp/opensslbase64
						cli2key=`cat "/tmp/opensslbase64" | openssl base64 -d`
    				else
    					echo "${cli2key}" | awk -F: '{print $1}' > /tmp/opensslbase64
						echo "${cli2key}" | awk -F: '{print $2}' >> /tmp/opensslbase64
						echo "${cli2key}" | awk -F: '{print $3}' >> /tmp/opensslbase64
						cli2key=`cat "/tmp/opensslbase64" | openssl base64 -d`
    				fi
    			fi
				cliDhcp=`echo "${lineProfile}" | awk 'BEGIN{FS="dhcp_enabled=" } {print $NF}' | cut -d '"' -f 2`
				cliip=`echo "${lineProfile}" | awk 'BEGIN{FS="ip=" } {print $NF}' | cut -d '"' -f 2`
				climask=`echo "${lineProfile}" | awk 'BEGIN{FS="netmask=" } {print $NF}' | cut -d '"' -f 2`
				cligw=`echo "${lineProfile}" | awk 'BEGIN{FS="gateway=" } {print $NF}' | cut -d '"' -f 2`
				clidns0=`echo "${lineProfile}" | awk 'BEGIN{FS="dns0=" } {print $NF}' | cut -d '"' -f 2`
				clidns1=`echo "${lineProfile}" | awk 'BEGIN{FS="dns1=" } {print $NF}' | cut -d '"' -f 2`
				clidns2=`echo "${lineProfile}" | awk 'BEGIN{FS="dns2=" } {print $NF}' | cut -d '"' -f 2`
				cliclone=`echo "${lineProfile}" | awk 'BEGIN{FS="mac_clone_enable=" } {print $NF}' | cut -d '"' -f 2`
				clicloneaddr=`echo "${lineProfile}" | awk 'BEGIN{FS="cloned_mac_address=" } {print $NF}' | cut -d '"' -f 2`
				cliremembered=`echo "${lineProfile}" | awk 'BEGIN{FS="remembered=" } {print $NF}' | cut -d '"' -f 2`
				cliband=`echo "${lineProfile}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
				if [ "${cliband}" == "2" ]; then
					activeIF=wlan3
				else
					activeIF=wlan1
				fi
				
				echo "${cli2Ssid}" | grep -q '\"\|\$\|\&\|/\||\|\\'
				if [ $? == 0 ]; then
					echo $cli2Ssid > /tmp/clientssid
					sed -i 's/\\/\\\\/g' /tmp/clientssid
					sed -i 's/"/\\"/g' /tmp/clientssid
					sed -i 's/\$/\\$/g' /tmp/clientssid
					sed -i 's/&/\\&/g' /tmp/clientssid
					sed -i 's/\//\\\//g' /tmp/clientssid
					sed -i 's/|/\\|/g' /tmp/clientssid
					sed -i 's/\\"/"/' /tmp/clientssid
					sed -i 's/\(.*\)\\"/\1"/' /tmp/clientssid
					cli2Ssid=`cat /tmp/clientssid`
					rm /tmp/clientssid
				fi 	
			
				echo "${cli2key}" | grep -q '\"\|\$\|\&\|/\||\|\\'
				if [ $? == 0 ]; then
					echo $cli2key > /tmp/clientpwd
					sed -i 's/\\/\\\\/g' /tmp/clientpwd
					sed -i 's/"/\\"/g' /tmp/clientpwd
					sed -i 's/\$/\\$/g' /tmp/clientpwd
					sed -i 's/&/\\&/g' /tmp/clientpwd
					sed -i 's/\//\\\//g' /tmp/clientpwd
					sed -i 's/|/\\|/g' /tmp/clientpwd
					sed -i 's/\\"/"/' /tmp/clientpwd
					sed -i 's/\(.*\)\\"/\1"/' /tmp/clientpwd
					cli2key=`cat /tmp/clientpwd`
					rm /tmp/clientpwd
				fi
	
				if [ "$cli2key" == "MyPassportWirelessWPSSecurityKeyTEMPoRarily" ]; then
					break
				fi
				
				if [ "$cli2key" == "MyPassportWirelessPBCSecurityKeyTEMPoRarily" ]; then
					PBCstate=`cat /tmp/WPStatus`
					if [ "$PBCstate" == "NONE" ]; then
						sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
						TempConnect=0
						NewRank=`expr $CurrentRank + 1`
						if [ "${NewRank}" -ge "$FileNum" ]; then
							NewRank=0
						fi
						sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER='${NewRank}'/' /etc/nas/config/wifinetwork-param.conf
						ConnectRetry=0
						echo $ConnectRetry > /tmp/ApCliRetry 
						echo "client_disconnect" > /tmp/client_disconnect
						break
					else
						break
					fi
				fi
				
				if [ "$cli2join" == "true" ]; then
					if [ "$cliremembered" == "true" ] || [ "$TempConnect" == "1" ]; then
						if [ "$STA_CLIENT" == "false" ]; then
							if [ "$Debugmode" == "1" ]; then
								timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
								echo $timestamp ": wifi_client_ap_retry.sh Client Turn OFF" >> /tmp/wificlientap.log
							fi
							exit 3
						fi
						if [ "$cli2bssid" == "1" ]; then
							#sleep 5
							if [ "$TempConnect" == "1" ]; then
								if [ "$cli2encryptype" == "NONE" ]; then
								execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								elif [ "$cli2encryptype" == "WEP" ]; then
							 	execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_key \"$cli2key\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								else
								execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_key \"$cli2key\" --security_mode \"$cli2encryptype/$cli2cipher\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								fi
								if [ ! -f /tmp/clientStatus ]; then
									connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
									if [ "$connectStatus" != "COMPLETED" ]; then
										eval $execmd
										if [ $? != 0 ]; then
											rm /tmp/client_disconnect
											exit 0
										fi
									fi
								fi
							else
								if [ "$cli2encryptype" == "NONE" ]; then
								execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								elif [ "$cli2encryptype" == "WEP" ]; then
							 	execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_key \"$cli2key\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								else
								execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect \"$cli2mac\" --security_key \"$cli2key\" --security_mode \"$cli2encryptype/$cli2cipher\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								fi
								if [ ! -f /tmp/clientStatus ]; then
									connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
									if [ "$connectStatus" != "COMPLETED" ]; then
										eval $execmd
										if [ $? != 0 ]; then
											rm /tmp/client_disconnect
											exit 0
										fi
									fi
								fi
							fi
						else
							#sleep 5
							if [ "$TempConnect" == "1" ]; then
								if [ "$cli2encryptype" == "NONE" ]; then
									execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								elif [ "$cli2encryptype" == "WEP" ]; then
							 		execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_key \"$cli2key\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								else
									execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_key \"$cli2key\" --security_mode \"$cli2encryptype/$cli2cipher\" --auto_join true --trusted \"$cli2trust\" --dhcp_enabled $cliDhcp --ip $cliip --netmask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								fi
								if [ ! -f /tmp/clientStatus ]; then
									connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
									if [ "$connectStatus" != "COMPLETED" ]; then
										eval $execmd
										if [ $? != 0 ]; then
											rm /tmp/client_disconnect
											exit 0
										fi
									fi
								fi
							
							else
								if [ "$cli2encryptype" == "NONE" ]; then
									execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --mask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								elif [ "$cli2encryptype" == "WEP" ]; then
							 		execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_key \"$cli2key\" --security_mode \"$cli2encryptype\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --mask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								else
									execmd="/usr/local/sbin/wifi_client_ap_connect.sh --connect $cli2Ssid --security_key \"$cli2key\" --security_mode \"$cli2encryptype/$cli2cipher\" --auto_join true --trusted \"$cli2trust\" --change_network true --dhcp_enabled $cliDhcp --ip $cliip --mask $climask --gateway $cligw --dns0 $clidns0 --dns1 $clidns1 --dns2 $clidns2 --mac_clone_enable $cliclone --cloned_mac_address $clicloneaddr"
								fi
								if [ ! -f /tmp/clientStatus ]; then
									connectStatus=`wpa_cli -i "${activeIF}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
									if [ "$connectStatus" != "COMPLETED" ]; then
										eval $execmd
										if [ $? != 0 ]; then
											rm /tmp/client_disconnect
											exit 0
										fi
									fi
								fi
							fi
						fi
					
						if [ "$Debugmode" == "1" ]; then
							timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
							echo $timestamp ": wifi_client_ap_retry.sh retry connect:" >> /tmp/wificlientap.log
							echo $timestamp ": wifi_client_ap_retry.sh" "$execmd" >> /tmp/wificlientap.log
						fi
						break
					fi
				else
					NoAJoinCt=`expr $NoAJoinCt + 1`
					NewRank=`expr $NewRank + 1`
					if [ "${NewRank}" -gt "$FileNum" ]; then
						NewRank=0
					fi
					sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER='${NewRank}'/' /etc/nas/config/wifinetwork-param.conf
					/sbin/wifi-restart STA &
				fi		
		done
	
		if [ "$execmd" == "" ]; then
			if [ "$NoAJoinCt" == "$FileNum" ]; then
				/etc/init.d/S90multi-role restart
				sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER=0/' /etc/nas/config/wifinetwork-param.conf
				rm /tmp/client_disconnect
				exit 0
			fi
		fi
		
	if [ ! -f "/tmp/client_disconnect" ]; then
		ConnectRetry=`cat /tmp/ApCliRetry`
		#echo "Old ConnectRetry" $ConnectRetry >> /tmp/clientdebug
		if [ "$ConnectRetry" -ge "$RetryLimit" ]; then
		
			if [ "$TempConnect" == "1" ]; then
				sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
				#if [ "$TempConnect" == "1" ]; then
				#	echo "ConnectionFailed" > /tmp/ClientConnStatus
				#fi
			else
				NewRank=`expr $CurrentRank + 1`
				if [ "${NewRank}" -ge "$FileNum" ]; then
					NewRank=0
				fi
				sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER='${NewRank}'/' /etc/nas/config/wifinetwork-param.conf
				#echo "NewRank" $NewRank >> /tmp/clientdebug
			fi
			ConnectRetry=0
			echo $ConnectRetry > /tmp/ApCliRetry 
			#echo "Change New Connect" >> /tmp/clientdebug
			#echo "0" > /tmp/ConnectionLoop
		else
			ConnectRetry=`expr $ConnectRetry + 1`
			#echo "New ConnectRetry" $ConnectRetry >> /tmp/clientdebug
			echo $ConnectRetry > /tmp/ApCliRetry 
		fi
	else
		rm /tmp/client_disconnect
	fi
fi





