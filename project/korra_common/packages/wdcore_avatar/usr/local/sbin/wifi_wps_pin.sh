#!/bin/bash
#
#
#
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

echo "Enter :" "$1 $2 $3 $4"

AP_IFACE=wlan2
AP5G_IFACE=wlan0
wifi2g4=0
wifi5g=0

AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
if [ "${AP1mode}" == "1" ]; then
	wifi5g=1
fi
AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
if [ "${AP2mode}" == "1" ]; then
	wifi2g4=1
fi
 
if [ "$1" == "get" ]; then
	if [ "$wifi2g4" == "1" ]; then
		hostapd_cli -i $AP_IFACE wps_ap_pin set 12345670 0 > /dev/null
	fi
	if [ "$wifi5g" == "1" ]; then
		hostapd_cli -i $AP5G_IFACE wps_ap_pin set 12345670 0 > /dev/null
	fi
	
	if [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "1" ]; then
		hostapd_cli -i $AP_IFACE wps_ap_pin get
	elif [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "0" ]; then
		hostapd_cli -i $AP_IFACE wps_ap_pin get
	elif [ "$wifi5g" == "1" ] && [ "$wifi2g4" == "0" ]; then
		hostapd_cli -i $AP5G_IFACE wps_ap_pin get
	fi
else
	keyin="${1}""${2}"
	WPS_pin=`echo "${keyin}" | awk -F- '{print $1$2}'`
	if [ `expr $(echo "$WPS_pin" | wc -m) - 1` != 8 ] && [ `expr $(echo "$WPS_pin" | wc -m) - 1` != 4 ]; then
		echo "Error length WPS pin"
		exit 0
	fi
 	
 	if [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "1" ]; then
		#result=`hostapd_cli -i $AP_IFACE wps_check_pin "$1"`
		execmd="hostapd_cli -i $AP_IFACE wps_check_pin \"$WPS_pin\""
		echo $execmd
		result=`eval $execmd`
		if [ "$result" == "FAIL-CHECKSUM" ] || [ "$result" == "FAIL" ]; then
			echo "Error checksum WPS pin"
			exit 0
		fi
	elif [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "0" ]; then
		result=`hostapd_cli -i $AP_IFACE wps_check_pin "$WPS_pin"`
		if [ "$result" == "FAIL-CHECKSUM" ] || [ "$result" == "FAIL" ]; then
			echo "Error checksum WPS pin"
			exit 0
		fi
	elif [ "$wifi5g" == "1" ] && [ "$wifi2g4" == "0" ]; then
		result=`hostapd_cli -i $AP5G_IFACE wps_check_pin "$WPS_pin"`
		if [ "$result" == "FAIL-CHECKSUM" ] || [ "$result" == "FAIL" ]; then
			echo "Error checksum WPS pin"
			exit 0
		fi
	fi

	if [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "1" ]; then
		#hostapd_cli -i $AP5G_IFACE wps_pin any $1 > /dev/null
		#sleep 3
		#hostapd_cli -i $AP_IFACE wps_pin any $1 > /dev/null
		#echo "OK!"
		execmd="hostapd_cli -i ${AP5G_IFACE} wps_pin any $WPS_pin"
		echo $execmd
		eval $execmd
		sleep 3
		execmd="hostapd_cli -i ${AP_IFACE} wps_pin any $WPS_pin"
		echo $execmd
		eval $execmd
		echo "OK!"
	elif [ "$wifi2g4" == "1" ] && [ "$wifi5g" == "0" ]; then
		hostapd_cli -i $AP_IFACE wps_pin any $WPS_pin > /dev/null
		echo "OK!"
	elif [ "$wifi5g" == "1" ] && [ "$wifi2g4" == "0" ]; then
		hostapd_cli -i $AP5G_IFACE wps_pin any $WPS_pin > /dev/null
		echo "OK!"
	fi
fi

exit 0