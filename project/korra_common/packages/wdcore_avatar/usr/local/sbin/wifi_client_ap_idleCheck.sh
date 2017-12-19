#!/bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_idleCheck.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/nas/config/wifinetwork-param.conf

NetworkNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`

if [ "$NetworkNum" == "0" ]; then
	#/etc/init.d/S90multi-role stop
	#sed -i 's/STA_CLIENT=.*/STA_CLIENT=false/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_REMB=.*/STA_CONF_REMB=0/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_ORDER=.*/STA_CONF_ORDER=0/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_SSID_NAME=.*/STA_SSID_NAME=/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_SECURITY_MODE=.*/STA_SECURITY_MODE=/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CIPHER_TYPE=.*/STA_CIPHER_TYPE=/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_PSK_KEY=.*/STA_PSK_KEY=/' /etc/nas/config/wifinetwork-param.conf
	sed -i 's/STA_CONF_HIDDEN=.*/STA_CONF_HIDDEN=/' /etc/nas/config/wifinetwork-param.conf
fi

exit 0




