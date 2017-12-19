#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_client_ap_ButtonPress.sh
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
	echo $timestamp ": wifi_client_ap_ButtonPress.sh" $@ >> /tmp/wifiap.log
fi

restart2G4=0
restart5G=0

trustMode=`cat /tmp/ifplugd_trust`

AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`

profileNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
uplink1=`cat /proc/net/rtl8821au/wlan1/all_sta_info | grep -c macaddr`
uplink3=`cat /proc/net/rtl8189es/wlan3/all_sta_info | grep -c macaddr` 
if [ "$profileNum" != "0" ] && [ "$uplink1" == "1" ] && [ "$uplink3" == "1" ]; then
	killall -11 monitor
fi

if [ "$trustMode" == "untrusted" ] || [ "$trustMode" == "trusted" ]; then
	
	
	if [ "$AP1mode" == "0" ]; then
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_ButtonPress.sh Turn ON AP1 mode to Downlink Client"  >> /tmp/wifiap.log
		fi
		echo "ForceShareMode" > /tmp/ConnectionMode
		#SdStatus=`/usr/local/sbin/storage_transfer_device_available.sh`
		#if [ "$SdStatus" != "true" ]; then
		#echo "22;01;" > /tmp/MCU_Cmd
		#fi
		#/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork > /dev/null 2>&1 &
		restart5G=1
	elif [ "$AP1mode" == "1" ]; then
		WifiMode=`cat /tmp/ConnectionMode`
		#if [ "$WifiMode" == "ApMode" ]; then
		#	uplinkNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
		#	if [ "$uplinkNum" -gt "0" ]; then
		#		if [ "$Debugmode" == "1" ]; then
		#			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		#			echo $timestamp ": wifi_client_ap_ButtonPress.sh Change to Client mode"  >> /tmp/wifiap.log
		#		fi
		#		/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G LeaveHomeNetwork > /dev/null 2>&1 &
		#	fi
		#fi
	fi
	if [ "$AP2mode" == "0" ]; then
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_client_ap_ButtonPress.sh Turn ON AP2 mode to Downlink Client"  >> /tmp/wifiap.log
		fi
		echo "ForceShareMode" > /tmp/ConnectionMode
		#SdStatus=`/usr/local/sbin/storage_transfer_device_available.sh`
		#if [ "$SdStatus" != "true" ]; then
		#echo "22;01;" > /tmp/MCU_Cmd
		#fi
		#/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork > /dev/null 2>&1 &
		restart2G4=1
	elif [ "$AP2mode" == "1" ]; then
		WifiMode=`cat /tmp/ConnectionMode`
		#if [ "$WifiMode" == "ApMode" ]; then
		#	uplinkNum=`cat /etc/nas/config/wifinetwork-remembered.conf | wc -l`
		#	if [ "$uplinkNum" -gt "0" ]; then
		#		if [ "$Debugmode" == "1" ]; then
		#			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		#			echo $timestamp ": wifi_client_ap_ButtonPress.sh Change to Client mode"  >> /tmp/wifiap.log
		#		fi
		#		/usr/local/sbin/wifi_ap_set_config.sh --enabled LeaveHomeNetwork > /dev/null 2>&1 &
		#	fi
		#fi
	fi
fi

if [ "$restart5G" == "1" ] && [ "$restart2G4" == "1" ]; then
	#echo "22;01;" > /tmp/MCU_Cmd
	/sbin/wifi-restart AP all &
elif [ "$restart5G" == "1" ] && [ "$restart2G4" == "0" ]; then
	#echo "22;01;" > /tmp/MCU_Cmd
	/usr/local/sbin/wifi_ap_set_config.sh --enabled_5G EnabledHomeNetwork > /dev/null 2>&1 &
elif [ "$restart5G" == "0" ] && [ "$restart2G4" == "1" ]; then
	#echo "22;01;" > /tmp/MCU_Cmd
	/usr/local/sbin/wifi_ap_set_config.sh --ism_band 2.4 --enabled EnabledHomeNetwork > /dev/null 2>&1 &
fi


exit 0
