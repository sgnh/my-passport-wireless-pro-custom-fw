#!/bin/bash
#
# 
. /etc/nas/config/wifinetwork-param.conf 2>/dev/null

if [ $# -ne 1 ]; then
	echo "$#"
	echo "Usage: set5gch.sh 161"
	exit
fi

#echo "$0 : $1"
ACS5GChannel=$1

sed -i 's/^channel=.*/channel='"${ACS5GChannel}"'/g' /etc/hostapd/hostapd.conf.5G
sed -i 's/AP5G_CHANNEL=.*/AP5G_CHANNEL='"${ACS5GChannel}"'/' /etc/nas/config/wifinetwork-param.conf


if [ "$ACS5GChannel" == "216" ] || [ "$ACS5GChannel" == "212" ] || [ "$ACS5GChannel" == "208" ] || [ "$ACS5GChannel" == "204" ] || [ "$ACS5GChannel" == "200" ] || [ "$ACS5GChannel" == "196" ] || [ "$ACS5GChannel" == "192" ] || [ "$ACS5GChannel" == "188" ] || [ "$ACS5GChannel" == "184" ] || [ "$ACS5GChannel" == "140" ] || [ "$ACS5GChannel" == "165" ] || [ "$ACS5GChannel" == "38" ] || [ "$ACS5GChannel" == "42" ] || [ "$ACS5GChannel" == "46" ]; then
	sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' /etc/hostapd/hostapd.conf.5G
fi
if [ "$ACS5GChannel" == "136" ] || [ "$ACS5GChannel" == "128" ] || [ "$ACS5GChannel" == "120" ] || [ "$ACS5GChannel" == "161" ] || [ "$ACS5GChannel" == "153" ] || [ "$ACS5GChannel" == "48" ] || [ "$ACS5GChannel" == "40" ] || [ "$ACS5GChannel" == "56" ] || [ "$ACS5GChannel" == "64" ] || [ "$ACS5GChannel" == "104" ] || [ "$ACS5GChannel" == "112" ]; then
	sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' /etc/hostapd/hostapd.conf.5G
else
	sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' /etc/hostapd/hostapd.conf.5G
fi

#/etc/init.d/S60hostapd restart $AP5G_IFACE
/sbin/wifi-restart AP $AP5G_IFACE
