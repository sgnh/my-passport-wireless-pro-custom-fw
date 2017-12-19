#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getNetworkConfig.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/networking-general.conf 2>/dev/null
. /etc/nas/config/wifinetwork-param.conf


iname=$1
NotConnect=0

if [ "${iname}" == "lo" ]; then
	echo "static"
	echo address "127.0.0.1"
	echo netmask "255.0.0.0"
	exit 0
fi

if [ $STA_CLIENT == "false" ]; then
	echo "disconnected"
	exit 0
fi

if [ $# -gt 0 ]; then
	if [ "$STA_CHANNEL_LITE" == "0" ]; then
		if [ "$iname" == "$STA2G4_IFACE" ] || [ "$iname" == "$STA_IFACE" ]; then
    		connectIF=`iw "${iname}" link`
    		if [ "${connectIF}" == "Not connected." ]; then
				echo "disconnected"
				exit 0
			fi
		else
			echo "disconnected"
			exit 0
		fi
	elif [ "$STA_CHANNEL_LITE" == "2" ]; then
		if [ "$iname" == "$STA2G4_IFACE" ]; then
			connectIF=`iw "${iname}" link`
    		if [ "${connectIF}" == "Not connected." ]; then
				echo "disconnected"
				exit 0
			fi
		else
			echo "disconnected"
			exit 0
		fi
	elif [ "$STA_CHANNEL_LITE" == "5" ]; then
		if [ "$iname" == "$STA_IFACE" ]; then
			connectIF=`iw "${iname}" link`
    		if [ "${connectIF}" == "Not connected." ]; then
				echo "disconnected"
				exit 0
			fi
		else
			echo "disconnected"
			exit 0
		fi
	fi
else
	if [ "$STA_CHANNEL_LITE" == "0" ]; then
		connectIF=`iw $STA_IFACE link`
	    if [ "${connectIF}" == "Not connected." ]; then
	    	connectIF=`iw $STA2G4_IFACE link`
	        if [ "${connectIF}" == "Not connected." ]; then
	        	echo "disconnected"
	            exit 0
	        else
	        	iname=$STA2G4_IFACE
	        fi
	   	else
	    	iname=$STA_IFACE
		fi	
	elif [ "$STA_CHANNEL_LITE" == "2" ]; then
		connectIF=`iw $STA2G4_IFACE link`
	    if [ "${connectIF}" == "Not connected." ]; then
	    	echo "disconnected"
	        exit 0
	    else
	    	iname=$STA2G4_IFACE
	    fi
	elif [ "$STA_CHANNEL_LITE" == "5" ]; then
		connectIF=`iw $STA_IFACE link`
	    if [ "${connectIF}" == "Not connected." ]; then
	        echo "disconnected"
	        exit 0
	   	else
	    	iname=$STA_IFACE
		fi	
	fi
fi

if [ "${iname}" == "$STA_IFACE" ] || [ "${iname}" == "$STA2G4_IFACE" ]; then
	cliipaddr=`ifconfig "${iname}" | grep "inet addr" | awk 'BEGIN {FS="addr:"}{print $NF}'| cut -d ' ' -f 1`
	connectStatus=`wpa_cli -i "${iname}" status | grep -rsi wpa_state | awk -F= '{print $NF}'`
	#connectedip=`wpa_cli -i "${iname}" status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
	if [ "${connectStatus}" != "COMPLETED" ]; then
		echo "disconnected"
		exit 0
	fi
	configurationMethod=`awk -v name="$iname" '{ if ($1 == "iface" && $2 == name) { print $4; exit 0; } }' ${networkConfig}`
	#essid=`iwconfig wlan0 | grep ESSID | awk -F: '{print $2}' | awk -F/ '{print $1}'`
	autoIp=`wpa_cli -i "${iname}" status | grep -rsw "ip_address" | awk -F= '{print $NF}' | awk -F. '{print $1"."$2}'`
	connectedmac=`wpa_cli -i "${iname}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
	if [ "$configurationMethod" == "dhcp" ]; then	
    	connection=`cat /etc/resolv.conf 2> /dev/null`
    	if [ $? == 0 ]; then
    		if [ "${NotConnect}" == "1" ]; then
    			echo "disconnected"
    		else
    			echo "dhcp"
    			echo address `ifconfig "${iname}" | grep "inet addr" | sed 's/[ ][ ]*/:/g' | awk -F: '{print $4}'`
    			echo netmask `ifconfig "${iname}" | grep "inet addr" | sed 's/[ ][ ]*/:/g' | awk -F: '{print $8}'`
    			if [ "$autoIp" != "169.254" ]; then
    				echo gateway `ip route | awk '/default/ { print $3 }'`
    				cat $dnsConfig | awk '{if ($1 == "nameserver" && $2 != "") printf("nameserver %s\n",$2)}'
    			fi
    			echo "gateway_mac_address" $connectedmac 	
    		fi
    	else
    		if [ "$autoIp" = "169.254" ]; then
    			echo "dhcp"
    			echo address `ifconfig "${iname}" | grep "inet addr" | sed 's/[ ][ ]*/:/g' | awk -F: '{print $4}'`
    			echo netmask `ifconfig "${iname}" | grep "inet addr" | sed 's/[ ][ ]*/:/g' | awk -F: '{print $8}'`
    			echo "gateway_mac_address" $connectedmac 	
    		else
    			echo "disconnected"
    		fi
    	fi
    	
	elif [ "${configurationMethod}" == "static" ]; then
		if [ "${NotConnect}" == "1" ]; then
			echo "disconnected"
			exit 0
		fi
		echo "static"
    	while read aline
    	do
        	# find the iface config record
        	echo ${aline} | grep "\<iface $iname\>" > /dev/null
        	if [ $? -eq 0 ];  then
            	while read confline
            	do
                	echo $confline | grep '^\s*\(iface\|mapping\|auto\|allow-\)' > /dev/null
                	if [ $? -eq 0 ]; then
                    	break
                	fi
                	echo $confline | grep "address" | sed 's/^[ \t]*//'
                	echo $confline | grep "netmask" | sed 's/^[ \t]*//'
                	echo $confline | grep "gateway" | sed 's/^[ \t]*//'
            	done
            	# Done searching.
            	break
        	fi

    	done < ${networkConfig}
    	cat $dnsConfig | awk '{if ($1 == "nameserver" && $2 != "") printf("nameserver %s\n",$2)}'
    	connectedmac=`wpa_cli -i "${iname}" status | grep -rsw "bssid" | awk -F= '{print $NF}' | tr [:lower:] [:upper:]`
    	echo "gateway_mac_address" $connectedmac 
	fi

fi
	
	

