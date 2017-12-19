#!/bin/bash
#
#
# wifi_ap_get_config.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/wifinetwork-param.conf 2>/dev/null

function Channel_Freq_Trans()
{
	case "$1" in
		2.412 )
			echo "1"
				;;
		2.417 )
			echo "2"
				;;
		2.422 )
			echo "3"
				;;
		2.427 )
			echo "4"
				;;
		2.432 )
			echo "5"
				;;
		2.437 )
			echo "6"
				;;
		2.442 )
			echo "7"
				;;
		2.447 )
			echo "8"
				;;
		2.452 )
			echo "9"
				;;
		2.457 )
			echo "10"
				;;
		2.462 )
			echo "11"
				;;
		2.467 )
			echo "12"
				;;	
		2.472 )
			echo "13"
				;;	
		2.484 )
			echo "14"
				;;
		5.18 )
			echo "36"
				;;
		5.19 )
			echo "38"
				;;
		5.2 )
			echo "40"
				;;		
		5.21 )
			echo "42"
				;;
		5.22 )
			echo "44"
				;;
		5.23 )
			echo "46"
				;;
		5.24 )
			echo "48"
				;;
		5.26 )
			echo "52"
				;;
		5.28 )
			echo "56"
				;;
		5.3 )
			echo "60"
				;;
		5.32 )
			echo "64"
				;;
		5.5 )
			echo "100"
				;;
		5.52 )
			echo "104"
				;;
		5.54 )
			echo "108"
				;;
		5.56 )
			echo "112"
				;;
		5.58 )
			echo "116"
				;;
		5.6 )
			echo "120"
				;;
		5.62 )
			echo "124"
				;;
		5.64 )
			echo "128"
				;;
		5.66 )
			echo "132"
				;;
		5.68 )
			echo "136"
				;;
		5.7 )
			echo "140"
				;;
		5.745 )
			echo "149"
				;;
		5.765 )
			echo "153"
				;;
		5.785 )
			echo "157"
				;;
		5.805 )
			echo "161"
				;;
		5.825 )
			echo "165"
				;;
		* )
			echo "UnKnown Channel"
			;;
	esac
}


function MaxChannelGet()
{
	#if [ "$AP_AVAILABLE_CHANNEL" == "" ] || [ "$AP5G_AVAILABLE_CHANNEL" == "" ]; then               
        if [ -f "/tmp/g2channels" ]; then
        	rm /tmp/g2channels
        fi
        if [ -f "/tmp/g5channels" ]; then
            rm /tmp/g5channels
        fi
        
        if [ ! -f "/tmp/maxchannelist" ]; then
            iw phy2 info | grep "MHz" > /tmp/maxchannelist
            iw phy0 info | grep "MHz" >> /tmp/maxchannelist
        fi
        notReady=`cat /tmp/maxchannelist | wc -l`
        if [ "${notReady}" == "0" ]; then
            sleep 3
            iw phy2 info | grep "MHz" > /tmp/maxchannelist
            iw phy0 info | grep "MHz" >> /tmp/maxchannelist
        fi
        cat /tmp/maxchannelist | while read channels
        do
            channel=`echo "$channels" | grep -v "no IR" | grep -v "radar detection" | grep -v "passive scanning" | grep -v "disabled" | awk -F\[ '{print $2}' | awk -F\] '{print $1}'`
            if [ "$channel" == "" ]; then
            	continue
            fi
            if [ "$channel" -le "14" ]; then
            	if [ ! -f "/tmp/g2channels" ]; then
                    echo -n "$channel" > /tmp/g2channels
                else
                	echo -n ", ""$channel" >> /tmp/g2channels
                fi
            else
            	if [ ! -f "/tmp/g5channels" ]; then
                	echo -n "$channel" > /tmp/g5channels
              	else
                	echo -n ", ""$channel" >> /tmp/g5channels
                fi
            fi
                
        done
        
        if [ -f "/tmp/g2channels" ]; then
                MAXCHANNEL_2G=`cat /tmp/g2channels`
                #echo "MAXCHANNEL_2G" $MAXCHANNEL_2G
                sed -i 's/AP_AVAILABLE_CHANNEL=.*/AP_AVAILABLE_CHANNEL='\""${MAXCHANNEL_2G}"\"'/' /etc/nas/config/wifinetwork-param.conf
        fi
        
        if [ -f "/tmp/g5channels" ]; then
                MAXCHANNEL_5G=`cat /tmp/g5channels`
                #echo "MAXCHANNEL_5G" $MAXCHANNEL_5G
                sed -i 's/AP5G_AVAILABLE_CHANNEL=.*/AP5G_AVAILABLE_CHANNEL='\""${MAXCHANNEL_5G}"\"'/' /etc/nas/config/wifinetwork-param.conf
        fi
	#fi

	if [ -f "/tmp/g2channels" ]; then
        rm /tmp/g2channels
	fi
	if [ -f "/tmp/g5channels" ]; then
        rm /tmp/g5channels
	fi
	iw phy2 info > /etc/nas/config/wifinetworkinfo
	iw phy0 info >> /etc/nas/config/wifinetworkinfo
}

function UpdateAPconfig()
{
	echo -n "{\"2.4\" : {" > /tmp/apconfig
	echo -n "\"enabled\" : \"${AP_HOTSPOT}\", " >> /tmp/apconfig
	echo "$AP_SSID_NAME" > /tmp/kkk
	sed -i 's/\\/\\\\/g' /tmp/kkk
	sed -i 's/"/\\"/g' /tmp/kkk
	#sed -i 's/['\'']/'\\\\\''/g' /tmp/kkk
	ssid=`cat /tmp/kkk`
	rm /tmp/kkk
	echo -n "\"ssid\" : \"${ssid}\", " >> /tmp/apconfig
	echo -n "\"broadcast\" : \"${AP_BROADCAST}\", " >> /tmp/apconfig
	if [ "$AP_ENCRYPTION_TYPE" == "NONE" ]; then
   		echo -n "\"is_secured\" : \"false\", " >> /tmp/apconfig
	else
   		echo -n "\"is_secured\" : \"true\", " >> /tmp/apconfig
	fi	

	if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "2" ]; then
		echo -n "\"mac_address\" : \"`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", " >> /tmp/apconfig
	else
		echo -n "\"mac_address\" : \"`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", " >> /tmp/apconfig
	fi
	if [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
		echo -n "\"security_mode\" : \"${AP_ENCRYPTION_TYPE}/${AP_CIPHER_TYPE}\", " >> /tmp/apconfig
	else
		echo -n "\"security_mode\" : \"${AP_ENCRYPTION_TYPE}\", " >> /tmp/apconfig
	fi
	if [ "${AP_CHANNEL}" == "0" ]; then
		echo -n "\"channel_mode\" : \"auto\", " >> /tmp/apconfig
		
	else
		echo -n "\"channel_mode\" : \"manual\", " >> /tmp/apconfig
		#echo -n "\"channel\" : ${AP_CHANNEL}, " >> /tmp/apconfig
	fi
	
	if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "2" ]; then
		wifiFreq=`iwlist "${AP_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
	else
		wifiFreq=`iwlist "${AP5G_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
	fi	
	chl=`Channel_Freq_Trans "${wifiFreq}"`	
	echo -n "\"channel\" : ${chl}, " >> /tmp/apconfig
	
	echo -n "\"ip\" : \"${AP_IP}\", " >> /tmp/apconfig
	echo -n "\"netmask\" : \"${AP_MASK}\", " >> /tmp/apconfig
	echo -n "\"network_mode\" : \"${AP_NETWORK_MODE}\", " >> /tmp/apconfig
	echo -n "\"dhcp_enabled\" : \"${AP_DHCPD_ENABLE}\", " >> /tmp/apconfig

	echo -n "\"available_channels\" : [$AP_AVAILABLE_CHANNEL], " >> /tmp/apconfig
	if [ "$AP_ENCRYPTION_TYPE" == "NONE" ]; then
		echo -n "\"security_key\" : \"\"}, " >> /tmp/apconfig
	else
		echo -n "\"security_key\" : \"$AP_ENCRYPTION_KEY\"}, " >> /tmp/apconfig
	fi
	
	echo -n "\"5\" : {" >> /tmp/apconfig
	echo -n "\"enabled\" : \"${AP5G_HOTSPOT}\", " >> /tmp/apconfig
	echo "$AP5G_SSID_NAME" > /tmp/kkk
	sed -i 's/\\/\\\\/g' /tmp/kkk
	sed -i 's/"/\\"/g' /tmp/kkk
	#sed -i 's/['\'']/'\\\\\''/g' /tmp/kkk
	ssid5g=`cat /tmp/kkk`
	rm /tmp/kkk
	echo -n "\"ssid\" : \"${ssid5g}\", " >> /tmp/apconfig
	echo -n "\"broadcast\" : \"${AP5G_BROADCAST}\", " >> /tmp/apconfig
	if [ "$AP5G_ENCRYPTION_TYPE" == "NONE" ]; then
   		echo -n "\"is_secured\" : \"false\", " >> /tmp/apconfig
	else
   		echo -n "\"is_secured\" : \"true\", " >> /tmp/apconfig
	fi

	if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "5" ]; then
		echo -n "\"mac_address\" : \"`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", " >> /tmp/apconfig
	else
		echo -n "\"mac_address\" : \"`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", " >> /tmp/apconfig
	fi

	if [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
		echo -n "\"security_mode\" : \"${AP5G_ENCRYPTION_TYPE}/${AP5G_CIPHER_TYPE}\", " >> /tmp/apconfig
	else
		echo -n "\"security_mode\" : \"${AP5G_ENCRYPTION_TYPE}\", " >> /tmp/apconfig
	fi

	if [ "${AP5G_CHANNEL}" == "0" ]; then
		echo -n "\"channel_mode\" : \"auto\", " >> /tmp/apconfig
		
	else
		echo -n "\"channel_mode\" : \"manual\", " >> /tmp/apconfig
		#echo -n "\"channel\" : ${AP5G_CHANNEL}, " >> /tmp/apconfig
	fi
	
	if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "5" ]; then
		wifiFreq=`iwlist "${AP5G_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
	else
		wifiFreq=`iwlist "${AP_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
	fi
	chl=`Channel_Freq_Trans "${wifiFreq}"` 
	echo -n "\"channel\" : ${chl}, " >> /tmp/apconfig

	echo -n "\"ip\" : \"${AP5G_IP}\", " >> /tmp/apconfig
	echo -n "\"netmask\" : \"${AP5G_MASK}\", " >> /tmp/apconfig
	echo -n "\"network_mode\" : \"${AP5G_NETWORK_MODE}\", " >> /tmp/apconfig
	echo -n "\"dhcp_enabled\" : \"${AP5G_DHCPD_ENABLE}\", " >> /tmp/apconfig

	echo -n "\"available_channels\" : [$AP5G_AVAILABLE_CHANNEL], " >> /tmp/apconfig
	if [ "$AP5G_ENCRYPTION_TYPE" == "NONE" ]; then
		echo -n "\"security_key\" : \"\"}" >> /tmp/apconfig
	else
		echo -n "\"security_key\" : \"${AP5G_ENCRYPTION_KEY}\"}" >> /tmp/apconfig
	fi
	echo  "}" >> /tmp/apconfig
}



cmd="$1"

if [ "$cmd" == "updateCH" ]; then
	MaxChannelGet
	exit 0
fi

if [ "$cmd" == "updateconfig" ]; then
    if [ ! -f "/tmp/updateApconfig" ]; then
	    touch /tmp/updateApconfig
        UpdateAPconfig 
	    rm /tmp/updateApconfig
    fi
    exit 0
fi
source /etc/nas/config/wifinetwork-param.conf

if [ "$cmd" == "" ]; then
	if [ -f "/tmp/apconfig" ]; then
		cat /tmp/apconfig
	else
		echo -n "{\"2.4\" : {"
		echo -n "\"enabled\" : \"${AP_HOTSPOT}\", "
		echo "$AP_SSID_NAME" > /tmp/kkk
		sed -i 's/\\/\\\\/g' /tmp/kkk
		sed -i 's/"/\\"/g' /tmp/kkk
		#sed -i 's/['\'']/'\\\\\''/g' /tmp/kkk
		ssid=`cat /tmp/kkk`
		rm /tmp/kkk
		echo -n "\"ssid\" : \"${ssid}\", " 
		echo -n "\"broadcast\" : \"${AP_BROADCAST}\", "
		if [ "$AP_ENCRYPTION_TYPE" == "NONE" ]; then
   			echo -n "\"is_secured\" : \"false\", "
		else
   			echo -n "\"is_secured\" : \"true\", "
		fi	

		if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "2" ]; then
			echo -n "\"mac_address\" : \"`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", "
		else
			echo -n "\"mac_address\" : \"`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", "
		fi
		if [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
			echo -n "\"security_mode\" : \"${AP_ENCRYPTION_TYPE}/${AP_CIPHER_TYPE}\", "
		else
			echo -n "\"security_mode\" : \"${AP_ENCRYPTION_TYPE}\", "
		fi
		if [ "${AP_CHANNEL}" == "0" ]; then
			echo -n "\"channel_mode\" : \"auto\", "
			if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "2" ]; then
				wifiFreq=`iwlist "${AP_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`	
			else
				wifiFreq=`iwlist "${AP5G_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`	
			fi	
			chl=`Channel_Freq_Trans "${wifiFreq}"`	
			echo -n "\"channel\" : ${chl}, "
		else
			echo -n "\"channel_mode\" : \"manual\", "
			echo -n "\"channel\" : ${AP_CHANNEL}, "
		fi

		echo -n "\"ip\" : \"${AP_IP}\", "
		echo -n "\"netmask\" : \"${AP_MASK}\", "
		echo -n "\"network_mode\" : \"${AP_NETWORK_MODE}\", "
		echo -n "\"dhcp_enabled\" : \"${AP_DHCPD_ENABLE}\", "

		echo -n "\"available_channels\" : [$AP_AVAILABLE_CHANNEL], "
		if [ "$AP_ENCRYPTION_TYPE" == "NONE" ]; then
			echo -n "\"security_key\" : \"\"}, "
		else
			echo -n "\"security_key\" : \"$AP_ENCRYPTION_KEY\"}, "
		fi
	
		echo -n "\"5\" : {"
		echo -n "\"enabled\" : \"${AP5G_HOTSPOT}\", "
		echo "$AP5G_SSID_NAME" > /tmp/kkk
		sed -i 's/\\/\\\\/g' /tmp/kkk
		sed -i 's/"/\\"/g' /tmp/kkk
		#sed -i 's/['\'']/'\\\\\''/g' /tmp/kkk
		ssid5g=`cat /tmp/kkk`
		rm /tmp/kkk
		echo -n "\"ssid\" : \"${ssid5g}\", "
		echo -n "\"broadcast\" : \"${AP5G_BROADCAST}\", "
		if [ "$AP5G_ENCRYPTION_TYPE" == "NONE" ]; then
   			echo -n "\"is_secured\" : \"false\", "
		else
   			echo -n "\"is_secured\" : \"true\", "
		fi

		if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "5" ]; then
			echo -n "\"mac_address\" : \"`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", "
		else
			echo -n "\"mac_address\" : \"`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`\", "
		fi

		if [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
			echo -n "\"security_mode\" : \"${AP5G_ENCRYPTION_TYPE}/${AP5G_CIPHER_TYPE}\", "
		else
			echo -n "\"security_mode\" : \"${AP5G_ENCRYPTION_TYPE}\", "
		fi

		if [ "${AP5G_CHANNEL}" == "0" ]; then
			echo -n "\"channel_mode\" : \"auto\", "
			if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "5" ]; then
				wifiFreq=`iwlist "${AP5G_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
			else
				wifiFreq=`iwlist "${AP_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
			fi
			chl=`Channel_Freq_Trans "${wifiFreq}"`
			echo -n "\"channel\" : ${chl}, "
		else
			echo -n "\"channel_mode\" : \"manual\", "
			echo -n "\"channel\" : ${AP5G_CHANNEL}, "
		fi

		echo -n "\"ip\" : \"${AP5G_IP}\", "
		echo -n "\"netmask\" : \"${AP5G_MASK}\", "
		echo -n "\"network_mode\" : \"${AP5G_NETWORK_MODE}\", "
		echo -n "\"dhcp_enabled\" : \"${AP5G_DHCPD_ENABLE}\", "

		echo -n "\"available_channels\" : [$AP5G_AVAILABLE_CHANNEL], "
		if [ "$AP5G_ENCRYPTION_TYPE" == "NONE" ]; then
			echo -n "\"security_key\" : \"\"}"
		else
			echo -n "\"security_key\" : \"${AP5G_ENCRYPTION_KEY}\"}"
		fi
		echo  "}"
	fi
elif [ "$cmd" == "INTERNAL_QUERY" ]; then
	AP_band="$2"
	if [ "$AP_band" == "5G" ]; then
		if [ "$AP5G_HOTSPOT" == "true" ]; then
	    	echo "enabled_5G=true"
		else
	    	echo "enabled_5G=false"
		fi
	
		#echo "ssid_5G=${AP5G_SSID_NAME}""(5GHz)" 
		echo "ssid_5G=${AP5G_SSID_NAME}" 
	
		if [ "$AP5G_BROADCAST" == "true" ]; then
	    	echo "broadcast_5G=true"
		else
	    	echo "broadcast_5G=false"
		fi
	
		if [ "$AP5G_ENCRYPTION_TYPE" == "NONE" ]; then
	    	echo "secured_5G=false"
		else
	    	echo "secured_5G=true"
		fi
	
		echo "mac_address_5G=`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`"
		if [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP5G_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
			echo "security_mode_5G=${AP5G_ENCRYPTION_TYPE}/${AP5G_CIPHER_TYPE}"
		else
			echo "security_mode_5G=${AP5G_ENCRYPTION_TYPE}"
		fi
		
		if [ "${AP5G_CHANNEL}" == "0" ]; then
			echo "channel_mode_5G=auto"
			wifiFreq=`iwlist "${AP5G_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
			chl=`Channel_Freq_Trans "${wifiFreq}"`
			echo "channel_5G=${chl}"
		else
			echo "channel_mode_5G=manual"
			echo "channel_5G=${AP5G_CHANNEL}"
		fi
	
		echo "ip_5G=${AP5G_IP}"
		echo "netmask_5G=${AP5G_MASK}"
		echo "network_mode_5G=${AP5G_NETWORK_MODE}"
	
		if [ "$AP5G_DHCPD_ENABLE" == "true" ]; then
	    	echo "enable_dhcp_5G=true"
		else
	    	echo "enable_dhcp_5G=false"
		fi
	
		#max_channels=`iwlist "${AP5G_IFACE}" channel | grep "${AP5G_IFACE}" | awk -F " " '{print $2}'`
		#filter='^[0-9]+$'
		#if ! [[ $max_channels =~ $filter ]] ; then
	    #	max_channels=
		#fi
		echo "max_available_channel_5G=$AP5G_AVAILABLE_CHANNEL"
	else
		if [ "$AP_HOTSPOT" == "true" ]; then
	    	echo "enabled=true"
		else
	    	echo "enabled=false"
		fi
	
		#echo "ssid=${AP_SSID_NAME}""(2.4GHz)"   
		echo "ssid=${AP_SSID_NAME}" 
	
		if [ "$AP_BROADCAST" == "true" ]; then
	    	echo "broadcast=true"
		else
	    	echo "broadcast=false"
		fi
	
		if [ "$AP_ENCRYPTION_TYPE" == "NONE" ]; then
	    	echo "secured=false"
		else
	    	echo "secured=true"
		fi
	
		echo "mac_address=`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`"
		if [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPA2PSK" ] || [ "${AP_ENCRYPTION_TYPE}" == "WPAPSK1WPAPSK2" ]; then
			echo "security_mode=${AP_ENCRYPTION_TYPE}/${AP_CIPHER_TYPE}"
		else
			echo "security_mode=${AP_ENCRYPTION_TYPE}"
		fi
		
		if [ "${AP_CHANNEL}" == "0" ]; then
			echo "channel_mode=auto"
			wifiFreq=`iwlist "${AP_IFACE}" channel | grep "Current" | awk -F: '{print $NF}' | awk '{print $1}'`
			chl=`Channel_Freq_Trans "${wifiFreq}"`
			echo "channel=${chl}"
		else
			echo "channel_mode=manual"
			echo "channel=${AP_CHANNEL}"
		fi
	
		echo "ip=${AP_IP}"
		echo "netmask=${AP_MASK}"
		echo "network_mode=${AP_NETWORK_MODE}"
	
		if [ "$AP_DHCPD_ENABLE" == "true" ]; then
	    	echo "enable_dhcp=true"
		else
	    	echo "enable_dhcp=false"
		fi
	
		max_channels=`iwlist "${AP_IFACE}" channel | grep "${AP_IFACE}" | awk -F " " '{print $2}'`
		filter='^[0-9]+$'
		if ! [[ $max_channels =~ $filter ]] ; then
	    	max_channels=11
		fi
		echo "max_available_channel=$max_channels"
	fi
fi
