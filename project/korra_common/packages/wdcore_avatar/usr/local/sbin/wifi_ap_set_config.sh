#!/bin/bash
#
#
# wifi_ap_set_config.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/wifinetwork-param.conf 2>/dev/null

if [ -f "/tmp/WiFiApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_ap_set_config.sh" $@ >> /tmp/wifiap.log
fi
wifiset2g4=0
wifiset5g=0
korralite=0
version_api=`cat /etc/version.packages | grep RESTAPI_2.4`

#if [ "$AP_CHANNEL_LITE" == "" ]; then
#	modrtk=`lsmod | grep 8189es`
#	if [ "$modrtk" == "" ]; then
#		korralite=1
#	fi
#else
#	if [ "$AP_CHANNEL_LITE" == "2" ] || [ "$AP_CHANNEL_LITE" == "5" ]; then
#		korralite=1
#	fi
#fi	
	

RestartService(){
	/etc/init.d/S50avahi-daemon restart	
	/etc/init.d/S77upnp restart
}

function trans_to_hex() {
	for i in $(echo $1 | sed -e "s/\./ /g"); do  
      	printf '%02x' $i >/dev/null 2>/dev/null < /dev/null
    done
}

ErrorCode(){
	echo "wifi_ap_set_config.sh --ism_band <2.4 | 5> --enabled <true | false> [ --ssid <value> ] [ --broadcast <value> ] [ --security_key <value> ] [ --security_mode <value> ] [--channel <value>] [--static_ip <value>] [--subnet_mask <value>] [--network_mode <value>] [--channel_mode <value>][--dhcp_enabled <true | false>]"
	#echo "wifi_ap_set_config.sh --enabled_5G <true | false> [ --ssid_5G <value> ] [ --broadcast_5G <value> ] [ --security_key_5G <value> ] [ --security_mode_5G <value> ] [--channel_5G <value>] [--static_ip_5G <value>] [--subnet_mask_5G <value>] [--network_mode_5G <value>] [--channel_mode_5G <value>][--enable_dhcp_5G <true | false>]"
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_ap_set_config.sh error code" $1 >> /tmp/wifiap.log
	fi
	exit $1
}

CheckChannelRange()
{
	if [ "${AP_AVAILABLE_CHANNEL}" == "" ] || [ "${AP5G_AVAILABLE_CHANNEL}" == "" ]; then
		/usr/local/sbin/wifi_ap_get_config.sh updateCH
	fi	

if [ "$1" == "$AP_IFACE" ]; then
	pickup2G4chanl=`echo "${AP_AVAILABLE_CHANNEL}" | grep -rsw "${2}"`
	if [ "$pickup2G4chanl" == "" ]; then
		ErrorCode 244
	fi
	
elif [ "$1" == "$AP5G_IFACE" ]; then 
	pickup5Gchanl=`echo "${AP5G_AVAILABLE_CHANNEL}" | grep -rsw "${2}"`
	if [ "$pickup5Gchanl" == "" ]; then
		ErrorCode 244
	fi
fi
}

#option=$1
#hotspot=$2
LIMIT_SSID_LEN=32
borderChannel_L=0
disconnectime=0
restart2G4=0
restart5G=0

if [ "$version_api" != "" ]; then
	wifiset2g4=1
fi

if [ $# == 0 ]; then
	ErrorCode 255
fi

while [ "$1" != "" ]; do
	case "$1" in
		--PBCconnect )
					AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
					AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
					if [ "${AP1mode}" == "0" ] && [ "${AP2mode}" == "0" ]; then
						/sbin/wifi-restart AP all > /dev/null 2>&1
						/etc/init.d/S77upnp restart
					elif [ "${AP1mode}" == "0" ] && [ "${AP2mode}" == "1" ]; then
						/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork > /dev/null 2>&1
					elif [ "${AP1mode}" == "1" ] && [ "${AP2mode}" == "0" ]; then
						/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork > /dev/null 2>&1
					elif [ "${AP1mode}" == "-1" ] && [ "${AP2mode}" == "-1" ]; then
						/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork > /dev/null 2>&1
						/etc/init.d/S77upnp restart
					fi
					if [ "$AP_BROADCAST" == "false" ] && [ "$AP5G_BROADCAST" == "false" ]; then
						echo "22;0;" > /tmp/MCU_Cmd
						exit 1 
					fi
					if [ "$AP5G_HOTSPOT" == "true" ] && [ "$AP5G_BROADCAST" == "true" ]; then
						hostapd_cli -i $AP5G_IFACE wps_pbc
						sleep 5
					fi
					if [ "$AP_HOTSPOT" == "true" ] && [ "$AP_BROADCAST" == "true" ]; then
						hostapd_cli -i $AP_IFACE wps_pbc
					fi
					/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
					exit 0
					;;
		
		--ism_band )
					freq="${2}"
					if [ "$freq" == "2.4" ]; then
						wifiset2g4=1
						wifiset5g=0
					elif [ "$freq" == "5" ]; then
						wifiset2g4=0
						wifiset5g=1
					else
						ErrorCode 242
					fi
					shift
					;;
		--enabled )	
					if [ "$wifiset2g4" == "1" ]; then
						wifion="${2}"
						if [ "$wifion" != "true" ] && [ "$wifion" != "false" ] && [ "$wifion" != "EnabledHomeNetwork" ] && [ "$wifion" != "LeaveHomeNetwork" ]; then
							ErrorCode 254
						fi
					elif [ "$wifiset5g" == "1" ]; then
						wifi5gon="${2}"
						if [ "$wifi5gon" != "true" ] && [ "$wifi5gon" != "false" ] && [ "$wifi5gon" != "EnabledHomeNetwork" ] && [ "$wifi5gon" != "LeaveHomeNetwork" ]; then
							ErrorCode 254
						fi
					fi
					shift
					;;
		--enabled_5G )	
					wifi5gon="${2}"
					if [ "$wifi5gon" != "true" ] && [ "$wifi5gon" != "false" ] && [ "$wifi5gon" != "EnabledHomeNetwork" ] && [ "$wifi5gon" != "LeaveHomeNetwork" ]; then
						ErrorCode 254
					fi
					shift
					;;			
		--ssid )	
					#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
					if [ "$wifiset2g4" == "1" ]; then
						ssid="${2}"
						ssidtmep="${2}"
        				if [ ${#ssid} -gt ${LIMIT_SSID_LEN} ]; then 
        					#echo "wifi_ap_set_config.sh ssid does not support more than 32 alphanumeric characters."
        					ErrorCode 253
        				fi
						disconnectime=1
					#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then
					elif [ "$wifiset5g" == "1" ]; then
						ssid5g="${2}"
        				if [ ${#ssid5g} -gt ${LIMIT_SSID_LEN} ]; then 
        					#echo "wifi_ap_set_config.sh ssid does not support more than 32 alphanumeric characters."
        					ErrorCode 253
        				fi
						disconnectime=1
					fi
					shift
                    ;;
        --ssid_5G )	
        			if [ "$wifi5gon" != "false" ]; then
						ssid5g="${2}"
        				if [ ${#ssid5g} -gt ${LIMIT_SSID_LEN} ]; then 
        					#echo "wifi_ap_set_config.sh ssid does not support more than 32 alphanumeric characters."
        					ErrorCode 253
        				fi
						disconnectime=1
					fi
					shift
                    ;;                        
        --broadcast )  
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
        				broadcast="$2"
        				if [ "$broadcast" != "true" ] && [ "$broadcast" != "false" ]; then
							ErrorCode 252
						fi
                    	if [ "$broadcast" == "false" ]; then
                        	disconnectime=1              
                    	fi  
                    #elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then
                    elif [ "$wifiset5g" == "1" ]; then
                    	broadcast5g="$2"
        				if [ "$broadcast5g" != "true" ] && [ "$broadcast5g" != "false" ]; then
							ErrorCode 252
						fi
                    	if [ "$broadcast5g" == "false" ]; then
                        	disconnectime=1                    
                    	fi
                    fi    
                    shift  
                    ;;
                    
        --broadcast_5G )  
        			if [ "$wifi5gon" != "false" ]; then
        				broadcast5g="$2"
        				if [ "$broadcast5g" != "true" ] && [ "$broadcast5g" != "false" ]; then
							ErrorCode 252
						fi
                    	if [ "$broadcast5g" == "false" ]; then
                        	disconnectime=1                    
                    	fi
                    fi    
                    shift    
                    ;;            
        --security_key )
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
        	        	security_key="$2"
                    	disconnectime=1
					#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then
					elif [ "$wifiset5g" == "1" ]; then
						security_key5g="$2"
                   	 	disconnectime=1
					fi
					shift
                    ;;
        --security_key_5G )
        			if [ "$wifi5gon" != "false" ]; then
        	        	security_key5g="$2"
                   	 	disconnectime=1
					fi
					shift
                    ;;                  
        --security_mode )
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
                    	security_mode="$2"
                    	disconnectime=1
                    #elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
                    elif [ "$wifiset5g" == "1" ]; then	
                    	security_mode5g="$2"
                    	disconnectime=1
                    fi
                    shift
                    ;;
        --security_mode_5G )
        			if [ "$wifi5gon" != "false" ]; then
                    	security_mode5g="$2"
                    	disconnectime=1
                    fi
                    shift
                    ;;            
   		--ip )      
   					#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
   					if [ "$wifiset2g4" == "1" ]; then
       					ipaddr="$2"
       					disconnectime=1
       				#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
       				elif [ "$wifiset5g" == "1" ]; then	
       					ipaddr5g="$2"
       					disconnectime=1
       				fi
       				shift
       				;;		
       	--ip_5G )   
       				if [ "$wifi5gon" != "false" ]; then
       					ipaddr5g="$2"
       					disconnectime=1
       				fi
       				shift
       				;;							
       	--netmask )
       				#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
       				if [ "$wifiset2g4" == "1" ]; then
       					netmask="$2"
       					if [ "$netmask" != "255.255.255.0" ] && [ "$netmask" != "255.255.255.255" ]; then
       						ErrorCode 251
       					fi
       					disconnectime=1
       				#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
       				elif [ "$wifiset5g" == "1" ]; then	
       					netmask5g="$2"
       					if [ "$netmask5g" != "255.255.255.0" ] && [ "$netmask5g" != "255.255.255.255" ]; then
       						ErrorCode 251
       					fi
       					disconnectime=1
       				fi
       				shift
       				;;
       	--netmask_5G )
       				if [ "$wifi5gon" != "false" ]; then
       					netmask5g="$2"
       					if [ "$netmask5g" != "255.255.255.0" ] && [ "$netmask5g" != "255.255.255.255" ]; then
       						ErrorCode 251
       					fi
       					disconnectime=1
       					
       				fi
       				shift
       				;;			
       	--channel_mode )     
       				#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
       				if [ "$wifiset2g4" == "1" ]; then
       					ChannelMode="$2"
       					if [ "$ChannelMode" != "auto" ] && [ "$ChannelMode" != "manual" ]; then
       						ErrorCode 250
       					fi
       				#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
       				elif [ "$wifiset5g" == "1" ]; then	
       					ChannelMode5g="$2"
       					if [ "$ChannelMode5g" != "auto" ] && [ "$ChannelMode5g" != "manual" ]; then
       						ErrorCode 250
       					fi
       				fi
       				shift
       				;;
       	--channel_mode_5G )
       				if [ "$wifi5gon" != "false" ]; then
       					ChannelMode5g="$2"
       					if [ "$ChannelMode5g" != "auto" ] && [ "$ChannelMode5g" != "manual" ]; then
       						ErrorCode 250
       					fi
       				fi
       				shift
       				;;			
        --channel )
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
        				wifichannel="$2"
        			#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then
        			elif [ "$wifiset5g" == "1" ]; then	
        				wifichannel5g="$2"
        			fi
        			shift
        			;;
        --channel_5G )
        			if [ "$wifi5gon" != "false" ]; then
        				wifichannel5g="$2"
        			fi
        			shift
        			;;			
		--network_mode )
					#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
					if [ "$wifiset2g4" == "1" ]; then
        				wifi_mode="$2"
        				if [ "${wifi_mode}" != "bgn" ] && [ "${wifi_mode}" != "bg" ] && [ "${wifi_mode}" != "b" ]; then
        					ErrorCode 248
        				fi 
        			#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
        			elif [ "$wifiset5g" == "1" ]; then	
        				wifi_mode5g="$2"
        				#if [ "${wifi_mode5g}" != "bgn" ] && [ "${wifi_mode5g}" != "bg" ] && [ "${wifi_mode5g}" != "b" ]; then
        				#	ErrorCode 248
        				#fi 
        			fi
        			shift
        			;; 
        --network_mode_5G )
        			if [ "$wifi5gon" != "false" ]; then
        				wifi_mode5g="$2"
        				#if [ "${wifi_mode5g}" != "bgn" ] && [ "${wifi_mode5g}" != "bg" ] && [ "${wifi_mode5g}" != "b" ]; then
        				#	ErrorCode 248
        				#fi 
        			fi
        			shift
        			;;  
        --enable_dhcp )		
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
        				dhcp_server="$2"
        				if [ "${dhcp_server}" != "true" ] && [ "${dhcp_server}" != "false" ]; then
        					ErrorCode 247
        				fi
        				disconnectime=1
        			#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
        			elif [ "$wifiset5g" == "1" ]; then	
        				dhcp_server5g="$2"
        				if [ "${dhcp_server5g}" != "true" ] && [ "${dhcp_server5g}" != "false" ]; then
        					ErrorCode 247
        				fi
        				disconnectime=1
        			fi
        			shift
        			;;	
        --dhcp_enabled )		
        			#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
        			if [ "$wifiset2g4" == "1" ]; then
        				dhcp_server="$2"
        				if [ "${dhcp_server}" != "true" ] && [ "${dhcp_server}" != "false" ]; then
        					ErrorCode 247
        				fi
        				disconnectime=1
        			#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
        			elif [ "$wifiset5g" == "1" ]; then	
        				dhcp_server5g="$2"
        				if [ "${dhcp_server5g}" != "true" ] && [ "${dhcp_server5g}" != "false" ]; then
        					ErrorCode 247
        				fi
        				disconnectime=1
        			fi
        			shift
        			;;			
        --enable_dhcp_5G )		
        			if [ "$wifi5gon" != "false" ]; then
        				dhcp_server5g="$2"
        				if [ "${dhcp_server5g}" != "true" ] && [ "${dhcp_server5g}" != "false" ]; then
        					ErrorCode 247
        				fi
        				disconnectime=1
        			fi
        			shift
        			;;
        --channelWidth )
					#if [ "$wifion" != "false" ] && [ "$wifiset2g4" == "1" ]; then
					if [ "$wifiset2g4" == "1" ]; then
        				CWidth="$2"
        				if [ "${CWidth}" != "20" ] && [ "${CWidth}" != "Auto40" ]; then
        					ErrorCode 248
        				fi 
        			#elif [ "$wifi5gon" != "false" ] && [ "$wifiset5g" == "1" ]; then	
        			elif [ "$wifiset5g" == "1" ]; then	
        				CWidth5g="$2"
        				if [ "${CWidth5g}" != "20" ] && [ "${CWidth5g}" != "Auto40" ] && [ "${CWidth5g}" != "Auto80" ]; then
        					ErrorCode 248
        				fi 
        			fi
        			shift
        			;;													     
        * )         echo "$2"
        			ErrorCode 246
                    ;;
    esac
    shift
	done
	
if [ "$wifion" == "EnabledHomeNetwork" ]; then
	if [ "$AP5G_HOTSPOT" == "false" ] && [ "$AP_HOTSPOT" == "false" ]; then
		sed -i 's/AP_HOTSPOT=.*/AP_HOTSPOT=true/' /etc/nas/config/wifinetwork-param.conf
		/sbin/wifi-restart AP $AP_IFACE
		exit 0
	fi

	AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
	if [ "$AP2mode" == "0" ]; then
		/sbin/wifi-restart AP $AP_IFACE
	fi
	#/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork
	#/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
	exit 0
elif [ "$wifion" == "LeaveHomeNetwork" ]; then		
	/etc/init.d/S60hostapd stop $AP_IFACE
	AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
	if [ "$AP2mode" != "1" ]; then
		/etc/init.d/S77upnp restart
		echo "ClientMode" > /tmp/ConnectionMode
		if [ "$AP_CHANNEL_LITE" == "0" ]; then	
			ifconfig br0 down
		fi
	fi
	#/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G LeaveHomeNetwork
	#/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
	exit 0
fi	

if [ "$wifi5gon" == "EnabledHomeNetwork" ]; then
	AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
	if [ "$AP1mode" == "0" ]; then
		/sbin/wifi-restart AP $AP5G_IFACE
	fi
	#/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
	exit 0
elif [ "$wifi5gon" == "LeaveHomeNetwork" ]; then
	/etc/init.d/S60hostapd stop $AP5G_IFACE
	AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
	if [ "$AP1mode" != "1" ]; then
		/etc/init.d/S77upnp restart
		echo "ClientMode" > /tmp/ConnectionMode
		if [ "$AP_CHANNEL_LITE" == "0" ]; then	
			ifconfig br0 down
		fi
	fi
	#/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
	exit 0
fi

##########KorraLite Check
if [ "$korralite" == "1" ]; then
	if [ "$wifion" == "true" ] && [ "$wifi5gon" == "true" ]; then
		ErrorCode 241
	elif [ "$wifion" == "false" ] && [ "$wifi5gon" == "false" ]; then
		ErrorCode 241
	fi
fi
####2.4G####
if [ "${security_mode}" == "NONE" ]; then
	if [ `expr $(echo "$security_key" | wc -m) - 1` -ne 0 ]; then
		exit 1
	fi
	securitype=NONE
elif [ "${security_mode}" != "" ] && [ "${security_key}" != "" ]; then
	securitype=`echo ${security_mode} | awk -F/ '{print $1}'`
	ciphertype=`echo ${security_mode} | awk -F/ '{print $2}'`
	if [ "$securitype" == "WPAPSK" ] || [ "$securitype" == "WPA2PSK" ] || [ "$securitype" == "WPAPSK1WPAPSK2" ]; then
		if [ `expr $(echo "$security_key" | wc -m) - 1` -lt 8 ] || [ `expr $(echo "$security_key" | wc -m) - 1` -gt 63 ]; then
    		exit 4
    	fi
	elif [ "$securitype" == "WEP" ]; then
    	if [ `expr $(echo "$security_key" | wc -m) - 1` == 5 ] || [ `expr $(echo "$security_key" | wc -m) - 1` == 10 ] || [ `expr $(echo "$security_key" | wc -m) - 1` == 13 ] || [ `expr $(echo "$security_key" | wc -m) - 1` == 26 ]; then
    		if [ `expr $(echo "$security_key" | wc -m) - 1` == 10 ] || [ `expr $(echo "$security_key" | wc -m) - 1` == 26 ]; then
    			for ((index=1; index<=`expr $(echo "$security_key" | wc -m) - 1`; index++ )); do
    				character=`echo "${security_key}" | sed 's/\(.\{1\}\)/\1 /g' | awk -v num=$index '{print $num}'`
    				echo ${character} | grep -q -v '[A-Fa-f0-9]'
    				if [ $? == 0 ]; then
						exit 5
					fi
    			done
    		fi
    	else
    		exit 6
    	fi
	fi
elif [ "${security_mode}" == "" ] && [ "${security_key}" != "" ]; then
	ErrorCode 245
elif [ "${security_mode}" != "" ] && [ "${security_key}" == "" ]; then
	ErrorCode 244
fi	

if [ "$ipaddr" != "" ]; then
	trans_to_hex "$ipaddr"
	if [ "$?" != 0 ]; then	
    	ErrorCode 243
	fi
fi
if [ "$wifichannel" != "" ]; then
	CheckChannelRange "$AP_IFACE" "$wifichannel"
fi

if [ "${ssid}" != "" ]; then
	echo "${ssid}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	if [ $? == 0 ]; then
		echo "$ssid" > /tmp/kkk
		sed -i 's/\\/\\\\/g' /tmp/kkk
		sed -i 's/"/\\"/g' /tmp/kkk
		sed -i 's/\$/\\$/g' /tmp/kkk
		sed -i 's/&/\\&/g' /tmp/kkk
		sed -i 's/\//\\\//g' /tmp/kkk
		sed -i 's/|/\\|/g' /tmp/kkk
		#sed -i 's/\`/\\`/g' /tmp/kkk
		ssid=`cat /tmp/kkk`
		rm /tmp/kkk
	fi
fi 	

if [ "$security_key" != "" ]; then
	echo "${security_key}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	if [ $? == 0 ]; then
		echo $security_key > /tmp/pwd
		sed -i 's/\\/\\\\/g' /tmp/pwd
		sed -i 's/"/\\"/g' /tmp/pwd
		sed -i 's/\$/\\$/g' /tmp/pwd
		sed -i 's/&/\\&/g' /tmp/pwd
		sed -i 's/\//\\\//g' /tmp/pwd
		sed -i 's/|/\\|/g' /tmp/pwd
		security_key=`cat /tmp/pwd`
		rm /tmp/pwd
	fi
fi
########
####5G####
if [ "${security_mode5g}" == "NONE" ]; then
	if [ `expr $(echo "$security_key5g" | wc -m) - 1` -ne 0 ]; then
		exit 1
	fi
	securitype5g=NONE
elif [ "${security_mode5g}" != "" ] && [ "${security_key5g}" != "" ]; then
	securitype5g=`echo ${security_mode5g} | awk -F/ '{print $1}'`
	ciphertype5g=`echo ${security_mode5g} | awk -F/ '{print $2}'`
	if [ "$securitype5g" == "WPAPSK" ] || [ "$securitype5g" == "WPA2PSK" ] || [ "$securitype5g" == "WPAPSK1WPAPSK2" ]; then
		if [ `expr $(echo "$security_key5g" | wc -m) - 1` -lt 8 ] || [ `expr $(echo "$security_key5g" | wc -m) - 1` -gt 63 ]; then
    		exit 4
    	fi
	elif [ "$securitype5g" == "WEP" ]; then
    	if [ `expr $(echo "$security_key5g" | wc -m) - 1` == 5 ] || [ `expr $(echo "$security_key5g" | wc -m) - 1` == 10 ] || [ `expr $(echo "$security_key5g" | wc -m) - 1` == 13 ] || [ `expr $(echo "$security_key5g" | wc -m) - 1` == 26 ]; then
    		if [ `expr $(echo "$security_key5g" | wc -m) - 1` == 10 ] || [ `expr $(echo "$security_key5g" | wc -m) - 1` == 26 ]; then
    			for ((index=1; index<=`expr $(echo "$security_key5g" | wc -m) - 1`; index++ )); do
    				character=`echo "${security_key5g}" | sed 's/\(.\{1\}\)/\1 /g' | awk -v num=$index '{print $num}'`
    				echo ${character} | grep -q -v '[A-Fa-f0-9]'
    				if [ $? == 0 ]; then
						exit 5
					fi
    			done
    		fi
    	else
    		exit 6
    	fi
	fi
elif [ "${security_mode5g}" == "" ] && [ "${security_key5g}" != "" ]; then
	ErrorCode 245
elif [ "${security_mode5g}" != "" ] && [ "${security_key5g}" == "" ]; then
	ErrorCode 244
fi	

if [ "$ipaddr5g" != "" ]; then
	trans_to_hex "$ipaddr5g"
	if [ "$?" != 0 ]; then	
    	ErrorCode 243
	fi
fi

if [ "$wifichannel5g" != "" ]; then
	CheckChannelRange "$AP5G_IFACE" "$wifichannel5g"
fi

if [ "${ssid5g}" != "" ]; then
	echo "${ssid5g}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	if [ $? == 0 ]; then
		echo "$ssid5g" > /tmp/kkk
		sed -i 's/\\/\\\\/g' /tmp/kkk
		sed -i 's/"/\\"/g' /tmp/kkk
		sed -i 's/\$/\\$/g' /tmp/kkk
		sed -i 's/&/\\&/g' /tmp/kkk
		sed -i 's/\//\\\//g' /tmp/kkk
		sed -i 's/|/\\|/g' /tmp/kkk
		#sed -i 's/\`/\\`/g' /tmp/kkk
		ssid5g=`cat /tmp/kkk`
		rm /tmp/kkk
	fi
fi 	

if [ "${security_key5g}" != "" ]; then
	echo "${security_key5g}" | grep -q '\"\|\$\|\&\|/\||\|\\'
	if [ $? == 0 ]; then
		echo $security_key5g > /tmp/pwd
		sed -i 's/\\/\\\\/g' /tmp/pwd
		sed -i 's/"/\\"/g' /tmp/pwd
		sed -i 's/\$/\\$/g' /tmp/pwd
		sed -i 's/&/\\&/g' /tmp/pwd
		sed -i 's/\//\\\//g' /tmp/pwd
		sed -i 's/|/\\|/g' /tmp/pwd
		security_key5g=`cat /tmp/pwd`
		rm /tmp/pwd
	fi
fi
########
######## Error handling #########
if [ "$wifion" == "false" ] && [ "$wifi5gon" == "" ] && [ "$AP5G_HOTSPOT" == "false" ]; then
	ErrorCode 241
elif [ "$wifi5gon" == "false" ] && [ "$wifion" == "" ] && [ "$AP_HOTSPOT" == "false" ]; then
	wifion=true
fi
####2.4G####
	sed -i 's/AP_WPS_CONFIGURED=.*/AP_WPS_CONFIGURED=2/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/AP_WPS_APLOCKED=.*/AP_WPS_APLOCKED=1/' /etc/nas/config/wifinetwork-param.conf

	if [ "$wifion" == "false" ]; then
		if [ "$korralite" != "1" ]; then
			restart2G4=1
		fi
		sed -i 's/AP_HOTSPOT=.*/AP_HOTSPOT=false/' /etc/nas/config/wifinetwork-param.conf
	elif [ "$wifion" == "true" ]; then
		restart2G4=1
		sed -i 's/AP_HOTSPOT=.*/AP_HOTSPOT=true/' /etc/nas/config/wifinetwork-param.conf
	
		if [ "$korralite" == "1" ]; then
			sed -i 's/AP5G_HOTSPOT=.*/AP5G_HOTSPOT=false/' /etc/nas/config/wifinetwork-param.conf
		fi
	fi
	if [ "$ssid" != "" ]; then
		sed -i 's/AP_SSID_NAME=.*/AP_SSID_NAME='\""${ssid}"\"'/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_SSID_NAME/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf		
	fi
 	
	if [ "$broadcast" != "" ]; then
		sed -i 's/AP_BROADCAST=.*/AP_BROADCAST='${broadcast}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	
	if [ "$security_mode" != "" ]; then
		sed -i 's/AP_ENCRYPTION_TYPE=.*/AP_ENCRYPTION_TYPE='${securitype}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	if [ "$ciphertype" != "" ]; then
		sed -i 's/AP_CIPHER_TYPE=.*/AP_CIPHER_TYPE='${ciphertype}'/' /etc/nas/config/wifinetwork-param.conf
	else
		if [ "$security_mode" != "" ]; then
			sed -i 's/AP_CIPHER_TYPE=.*/AP_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
		fi
	fi

	if [ "$security_key" != "" ]; then
		sed -i 's/AP_ENCRYPTION_KEY=.*/AP_ENCRYPTION_KEY='\""${security_key}"\"'/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP_ENCRYPTION_KEY/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf	
	fi

	if [ "$ipaddr" != "" ]; then
		if [ "$AP_IP" != "$ipaddr" ]; then
			restart2G4=1
			if [ "$korralite" != "1" ]; then
				restart5G=1
			fi
		fi
		sed -i 's/AP_IP=.*/AP_IP='${ipaddr}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_IP=.*/AP5G_IP='${ipaddr}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$netmask" != "" ]; then
		sed -i 's/AP_MASK=.*/AP_MASK='${netmask}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_MASK=.*/AP5G_MASK='${netmask}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	if [ "$ChannelMode" == "auto" ]; then 
    	wifichannel=0
	fi

	if [ "$wifichannel" != "" ]; then
		sed -i 's/AP_CHANNEL=.*/AP_CHANNEL='${wifichannel}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$dhcp_server" != "" ]; then
		if [ "$AP_DHCPD_ENABLE" != "$dhcp_server" ]; then
			restart2G4=1
			if [ "$korralite" != "1" ]; then
				restart5G=1
			fi
		fi
		sed -i 's/AP_DHCPD_ENABLE=.*/AP_DHCPD_ENABLE='${dhcp_server}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_DHCPD_ENABLE=.*/AP5G_DHCPD_ENABLE='${dhcp_server}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$wifi_mode" == "" ]; then
		if [ "$AP_NETWORK_MODE" == "" ]; then 
			echo "AP_NETWORK_MODE=bgn" >> /etc/nas/config/wifinetwork-param.conf
		fi
	else
		if [ "$AP_NETWORK_MODE" == "" ]; then 
			echo "AP_NETWORK_MODE="$wifi_mode >> /etc/nas/config/wifinetwork-param.conf
		else
			sed -i 's/AP_NETWORK_MODE=.*/AP_NETWORK_MODE='${wifi_mode}'/' /etc/nas/config/wifinetwork-param.conf
		fi
	fi
		
	if [ "$CWidth" != "" ]; then
		sed -i 's/AP_CHANL_WIDTH=.*/AP_CHANL_WIDTH='${CWidth}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	
####5G####
	if [ "$wifi5gon" == "false" ]; then
		if [ "$korralite" != "1" ]; then
			restart5G=1
		fi
		sed -i 's/AP5G_HOTSPOT=.*/AP5G_HOTSPOT=false/' /etc/nas/config/wifinetwork-param.conf
	elif [ "$wifi5gon" == "true" ]; then
		restart5G=1
		sed -i 's/AP5G_HOTSPOT=.*/AP5G_HOTSPOT=true/' /etc/nas/config/wifinetwork-param.conf
		if [ "$korralite" == "1" ]; then
			sed -i 's/AP_HOTSPOT=.*/AP_HOTSPOT=false/' /etc/nas/config/wifinetwork-param.conf
		fi
	fi
		
	if [ "$ssid5g" != "" ]; then
		sed -i 's/AP5G_SSID_NAME=.*/AP5G_SSID_NAME='\""${ssid5g}"\"'/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_SSID_NAME/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf		
	fi
 	
	if [ "$broadcast5g" != "" ]; then
		sed -i 's/AP5G_BROADCAST=.*/AP5G_BROADCAST='${broadcast5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	
	if [ "$security_mode5g" != "" ]; then
		sed -i 's/AP5G_ENCRYPTION_TYPE=.*/AP5G_ENCRYPTION_TYPE='${securitype5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	
	if [ "$ciphertype5g" != "" ]; then
		sed -i 's/AP5G_CIPHER_TYPE=.*/AP5G_CIPHER_TYPE='${ciphertype5g}'/' /etc/nas/config/wifinetwork-param.conf
	else
		if [ "$security_mode5g" != "" ]; then
			sed -i 's/AP5G_CIPHER_TYPE=.*/AP5G_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
		fi
	fi

	if [ "$security_key5g" != "" ]; then
		sed -i 's/AP5G_ENCRYPTION_KEY=.*/AP5G_ENCRYPTION_KEY='\""${security_key5g}"\"'/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/\\/\\\\/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/"/\\"/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/\$/\\$/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/\\"/"/' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/`/\\`/g' /etc/nas/config/wifinetwork-param.conf
		sed -i '/AP5G_ENCRYPTION_KEY/ s/\(.*\)\\"/\1"/' /etc/nas/config/wifinetwork-param.conf	
	fi

	if [ "$ipaddr5g" != "" ]; then
		if [ "$AP5G_IP" != "$ipaddr5g" ]; then
			if [ "$korralite" != "1" ]; then
				restart2G4=1
			fi
			restart5G=1
		fi
		sed -i 's/AP5G_IP=.*/AP5G_IP='${ipaddr5g}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_IP=.*/AP_IP='${ipaddr5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$netmask5g" != "" ]; then
		sed -i 's/AP5G_MASK=.*/AP5G_MASK='${netmask5g}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_MASK=.*/AP_MASK='${netmask5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$ChannelMode5g" == "auto" ]; then 
    	wifichannel5g=0
	fi

	if [ "$wifichannel5g" != "" ]; then
		sed -i 's/AP5G_CHANNEL=.*/AP5G_CHANNEL='${wifichannel5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$dhcp_server5g" != "" ]; then
		if [ "$AP5G_DHCPD_ENABLE" != "$dhcp_server5g" ]; then
			if [ "$korralite" != "1" ]; then
				restart2G4=1
			fi
			restart5G=1
		fi
		sed -i 's/AP5G_DHCPD_ENABLE=.*/AP5G_DHCPD_ENABLE='${dhcp_server5g}'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_DHCPD_ENABLE=.*/AP_DHCPD_ENABLE='${dhcp_server5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi

	if [ "$wifi_mode5g" != "" ]; then
		sed -i 's/AP5G_NETWORK_MODE=.*/AP5G_NETWORK_MODE='${wifi_mode}'/' /etc/nas/config/wifinetwork-param.conf
	fi
	
	if [ "$CWidth5g" != "" ]; then
		sed -i 's/AP5G_CHANL_WIDTH=.*/AP5G_CHANL_WIDTH='${CWidth5g}'/' /etc/nas/config/wifinetwork-param.conf
	fi
sync
sync

if [ "$korralite" == "1" ]; then
	if [ "$wifion" == "true" ] && [ "$STA_CHANNEL" == "5" ]; then
		/sbin/wifi-restart STA
	elif [ "$wifi5gon" == "true" ] && [ "$STA_CHANNEL" == "2" ]; then
		/sbin/wifi-restart STA
	fi
fi

if [ "$restart5G" == "1" ] && [ "$restart2G4" == "1" ]; then
	if [ "$disconnectime" == "1" ]; then
		/sbin/wifi-restart AP all LONGDELAY 2>&1 &
	else
		/sbin/wifi-restart AP all 2>&1 &
	fi
	
elif [ "$restart5G" == "1" ] && [ "$restart2G4" == "0" ]; then
	if [ "$korralite" != "1" ]; then
		if [ "$disconnectime" == "1" ]; then
			/sbin/wifi-restart AP $AP5G_IFACE LONGDELAY 2>&1 &
		else
			/sbin/wifi-restart AP $AP5G_IFACE 2>&1 &
		fi
	else
		sed -i 's/AP_IFACE=.*/AP_IFACE='wlan2'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_IFACE=.*/AP5G_IFACE='wlan0'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_IFACE=.*/STA_IFACE='wlan1'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA2G4_IFACE=.*/STA2G4_IFACE='wlan3'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_CHANNEL=.*/STA_CHANNEL='5'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_CHANNEL_LITE=.*/AP_CHANNEL_LITE='5'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_CHANNEL_LITE=.*/STA_CHANNEL_LITE='5'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_HOTSPOT=.*/AP_HOTSPOT='false'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_BRIDGE_ENABLED=.*/AP_BRIDGE_ENABLED='false'/' /etc/nas/config/wifinetwork-param.conf
		if [ "$disconnectime" == "1" ]; then
			/sbin/wifi-restart AP all LONGDELAY 2>&1 &
		else
			/sbin/wifi-restart AP all 2>&1 &
		fi
	fi
	
elif [ "$restart5G" == "0" ] && [ "$restart2G4" == "1" ]; then
	if [ "$korralite" != "1" ]; then
		if [ "$version_api" != "" ]; then
			if [ "${broadcast}" == "" ]; then
				broadcast=true
			fi
			wifi_ap_set_config.sh --enabled_5G "$wifion" --ssid_5G "${ssidtmep}" --security_mode_5G "$security_mode"  --security_key_5G "$security_key" --broadcast_5G "${broadcast}" --channel_mode_5G auto
		fi
		
		if [ "$disconnectime" == "1" ]; then
			/sbin/wifi-restart AP $AP_IFACE LONGDELAY 2>&1 &
		else
			/sbin/wifi-restart AP $AP_IFACE 2>&1 &
		fi
	else
		sed -i 's/AP_IFACE=.*/AP_IFACE='wlan0'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_IFACE=.*/AP5G_IFACE='wlan2'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_IFACE=.*/STA_IFACE='wlan3'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA2G4_IFACE=.*/STA2G4_IFACE='wlan1'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_CHANNEL=.*/STA_CHANNEL='2'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_CHANNEL_LITE=.*/AP_CHANNEL_LITE='2'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/STA_CHANNEL_LITE=.*/STA_CHANNEL_LITE='2'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP5G_HOTSPOT=.*/AP5G_HOTSPOT='false'/' /etc/nas/config/wifinetwork-param.conf
		sed -i 's/AP_BRIDGE_ENABLED=.*/AP_BRIDGE_ENABLED='false'/' /etc/nas/config/wifinetwork-param.conf	
		if [ "$disconnectime" == "1" ]; then
			/sbin/wifi-restart AP all LONGDELAY 2>&1 &
		else
			/sbin/wifi-restart AP all 2>&1 &
		fi
	fi
fi


/usr/local/sbin/incUpdateCount.pm wifi_ap 2>&1 &
/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1

sync
exit 0
# We want at least one non-option argument. 
# Remove this block if you don't need it.
#if [ $# -eq 0 ]; then
#    echo $USAGE >&2
#    exit 1
#fi

# Access additional arguments as usual through 
# variables $@, $*, $1, $2, etc. or using this loop:
#for PARAM; do
#    echo $PARAM
#done

# EOF

