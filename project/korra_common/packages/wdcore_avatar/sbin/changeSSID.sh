#!/bin/sh
LIMIT_SSID_LEN=32
ssid="$1"
if [ "$ssid" != "" ]; then
	
    
	sed -i 's/AP5G_SSID_NAME=.*/AP5G_SSID_NAME='\""${ssid}"\"'/' /etc/nas/config/wifinetwork-param.conf
	
	sed -i 's/AP_SSID_NAME=.*/AP_SSID_NAME='\""${ssid}"\"'/' /etc/nas/config/wifinetwork-param.conf

	/sbin/wifi-restart AP all
fi