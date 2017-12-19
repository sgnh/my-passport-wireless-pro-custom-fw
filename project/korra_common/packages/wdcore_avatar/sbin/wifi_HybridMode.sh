#!/bin/bash
#
# 2014 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_HybridMode.sh
#
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/config/wifinetwork-param.conf

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_HybridMode.sh" $@ >> /tmp/wifiap.log
fi

cmd1="$1"

if [ "$cmd1" == "connected" ]; then
	if [ -f "/tmp/hybrid_list" ]; then
    	rm /tmp/hybrid_list
    	cat /etc/nas/hybrid_list | while read KickMAC
    	do
    		if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_HybridMode.sh Kick" $KickMAC >> /tmp/wifiap.log
			fi
    		/usr/local/sbin/set_wifi_ap_client_disconnect.sh "${KickMAC}" "ShortKick" > /dev/null
    	done
    fi
    
    
    
elif [ "$cmd1" == "disconnected" ]; then
	if [ -f "/etc/nas/hybrid_list" ]; then
    	cp -a /etc/nas/hybrid_list /tmp/
    	cat /etc/nas/hybrid_list | while read KickMAC
    	do
    		if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_HybridMode.sh Kick" $KickMAC >> /tmp/wifiap.log
			fi
    		/usr/local/sbin/set_wifi_ap_client_disconnect.sh "${KickMAC}" "ShortKick" > /dev/null
    	done
    fi
fi


exit 0

# EOF

