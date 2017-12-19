#!/bin/sh
sed -i 's/ssid=.*/ssid='\"$1\"'/' /etc/wpa_supplicant.conf
sed -i 's/STA_CLIENT=.*/STA_CLIENT=true/' /etc/nas/config/wifinetwork-param.conf
killall wpa_supplicant
/etc/init.d/S90multi-role restart &
