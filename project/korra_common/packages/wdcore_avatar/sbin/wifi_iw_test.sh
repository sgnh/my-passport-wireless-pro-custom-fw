#!/bin/bash
#
# 2014 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_HybridMode.sh
#
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin


testclcle="${1}"

while [ "${testclcle}" != "0" ]; do
	echo "testclcle" $testclcle
	#/sbin/wifi-restart STA
	#iw --debug dev wlan1 scan
	
	#/usr/local/sbin/wifi_client_ap_configuration_set.sh --enabled false
	#sleep 1
	#/usr/local/sbin/wifi_client_ap_configuration_set.sh --enabled true
	wifi_client_ap_scan.sh
	sleep 1
	
	testclcle=`expr ${testclcle} - 1`
	
done

exit 0

# EOF

