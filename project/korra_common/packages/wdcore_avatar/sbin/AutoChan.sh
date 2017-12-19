#!/bin/bash
#
# AutoChan.sh
#
# Used to AP Auto Channel Selection
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/config/wifinetwork-param.conf
HOSTAPD_CONF_2G_PATH="/etc/hostapd/hostapd.conf.2G"
HOSTAPD_CONF_5G_PATH="/etc/hostapd/hostapd.conf.5G"
factory_conf=/etc/nas/config/factory.conf

channelwidth20="216, 212, 208, 204, 200, 196, 192, 188, 184, 140, 165, 38, 42, 46"
channelwidth40minus="136, 128, 120, 161, 153, 48, 40, 56, 64, 104, 112"
#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------
iface=$1
boot=$2
if [ "$iface" == "" ]; then
	iface=all
fi
if [ -f "/tmp/WiFiApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": AutoChan.sh" $@ >> /tmp/wifiap.log
fi

#if [ "$AP5G_CHANNEL" != 0 ] && [ "$AP_CHANNEL" != 0 ]; then
#	exit 0
#fi

if [ "$iface" == "$AP_IFACE" ] && [ "$AP_HOTSPOT" == "false" ]; then
	exit 2
fi

if [ "$iface" == "$AP5G_IFACE" ] && [ "$AP5G_HOTSPOT" == "false" ]; then
	exit 2
fi

#waitscan=`pidof iwlist`
#if [ "$waitscan" != "" ]; then
#	sleep 2
	#ps aux
	#waitscan=`pidof iwlist`
	#echo "waitscan" $waitscan > /tmp/kkk
#fi
AP1mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP5G`
AP2mode=`/usr/local/sbin/wifi_ap_broadcast_check.sh AP2G4`
if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": AutoChan.sh AP1mode" $AP1mode "AP2mode" $AP2mode >> /tmp/wifiap.log
fi

if [ -f $factory_conf ] && [ `grep FACTORY_MODE $factory_conf | wc -l` == "1" ] && [ `grep FACTORY_MODE $factory_conf | awk -F= '{print $2}'` == "1" ]; then
	if [ "${AP1mode}" == "0" ] || [ "${AP2mode}" == "0" ]; then
		sleep 3
	fi
	echo "6 1 1" > /proc/net/rtl8189es/wlan2/chbw_info
	echo "149 2 1" > /proc/net/rtl8821au/wlan0/chbw_info
	exit 0
fi
#cat /proc/net/rtl8821au/$STA_IFACE/best_channel > /tmp/bestchannel
if [ "$iface" == "all" ]; then
	if [ "${AP1mode}" == "0" ] || [ "${AP2mode}" == "0" ]; then
		sleep 3
	fi
	if [ "$AP_CHANNEL" == "0" ]; then
		ACS2G4Channel=`cat /proc/net/rtl8189es/$STA2G4_IFACE/best_channel | grep "best_channel_24G" | awk '{print $3}'`
		echo "${AP_AVAILABLE_CHANNEL}" | grep "${ACS2G4Channel}" > /dev/null
		if [ $? != 0 ]; then
			ACS2G4Channel=`cat /proc/net/rtl8189es/$STA2G4_IFACE/best_channel | grep "best2nd_channel_24G" | awk '{print $3}'`
		fi
		sed -i 's/^channel=.*/channel='"${ACS2G4Channel}"'/g' $HOSTAPD_CONF_2G_PATH
		if [ "${AP_CHANL_WIDTH}" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_2G_PATH
		else
			if [ "${ACS2G4Channel}" -ge "8" ]; then
				vht=1
				HT40=2
				sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			else
				vht=1
				HT40=1
				sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			fi
		fi
		if [ "${boot}" == "booting" ]; then
			echo "${ACS2G4Channel} ${vht} ${HT40}" > /proc/net/rtl8189es/wlan2/chbw_info
		fi
	else
		if [ "$AP_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
		else
			if [ "${AP_CHANNEL}" -ge "8" ]; then
				vht=1
				HT40=2
				#sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			else
				vht=1
				HT40=1
				#sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			fi
		fi
		#if [ "${boot}" == "booting" ]; then
			echo "${AP_CHANNEL} ${vht} ${HT40}" > /proc/net/rtl8189es/wlan2/chbw_info
		#fi
	fi
	if [ "$AP5G_CHANNEL" == "0" ]; then
		ACS5GChannel=`cat /proc/net/rtl8821au/$STA_IFACE/best_channel | grep "best_channel_5G" | awk '{print $3}'`
		echo "${AP5G_AVAILABLE_CHANNEL}" | grep "${ACS5GChannel}" > /dev/null
		if [ $? != 0 ]; then
			ACS5GChannel=`cat /proc/net/rtl8821au/$STA_IFACE/best_channel | grep "best2nd_channel_5G" | awk '{print $3}'`
		fi
		sed -i 's/^channel=.*/channel='"${ACS5GChannel}"'/g' $HOSTAPD_CONF_5G_PATH
		if [ "$AP5G_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_5G_PATH
		else
			htcap=`echo "${channelwidth20}" | grep -rsw "${ACS5GChannel}"`
			if [ "$htcap" != "" ]; then
				vht=0
				HT40=0
				sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' ${HOSTAPD_CONF_5G_PATH}
			else
				htcap=`echo "${channelwidth40minus}" | grep -rsw "${ACS5GChannel}"`
				if [ "$htcap" != "" ]; then
					vht=2
					HT40=2
					sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				else
					vht=2
					HT40=1
					sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				fi
			fi
		fi
		if [ "${boot}" == "booting" ]; then
			echo "$ACS5GChannel $vht $HT40" > /proc/net/rtl8821au/wlan0/chbw_info
		fi
	else
		if [ "$AP5G_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_5G_PATH
		else
			htcap=`echo "${channelwidth20}" | grep -rsw "${AP5G_CHANNEL}"`
			if [ "$htcap" != "" ]; then
				vht=0
				HT40=0
			else
				htcap=`echo "${channelwidth40minus}" | grep -rsw "${AP5G_CHANNEL}"`
				if [ "$htcap" != "" ]; then
					vht=2
					HT40=2
					#sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				else
					vht=2
					HT40=1
					#sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				fi
			fi
		fi
		#if [ "${boot}" == "booting" ]; then
			echo "$AP5G_CHANNEL $vht $HT40" > /proc/net/rtl8821au/wlan0/chbw_info
		#fi
	fi
	/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
elif [ "${iface}" == "${AP_IFACE}" ]; then
	if [ "$AP2mode" != "1" ]; then
		sleep 3
	fi
	if [ "$AP_CHANNEL" == "0" ]; then
		ACS2G4Channel=`cat /proc/net/rtl8189es/$STA2G4_IFACE/best_channel | grep "best_channel_24G" | awk '{print $3}'`
		echo "${AP_AVAILABLE_CHANNEL}" | grep "${ACS2G4Channel}" > /dev/null
		if [ $? != 0 ]; then
			ACS2G4Channel=`cat /proc/net/rtl8189es/$STA2G4_IFACE/best_channel | grep "best2nd_channel_24G" | awk '{print $3}'`
		fi
		sed -i 's/^channel=.*/channel='"${ACS2G4Channel}"'/g' $HOSTAPD_CONF_2G_PATH
		if [ "$AP_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_2G_PATH
		else
			if [ "$ACS2G4Channel" -ge "8" ]; then
				vht=1
				HT40=2
				sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			else
				vht=1
				HT40=1
				sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			fi
		fi
		echo "$ACS2G4Channel $vht $HT40" > /proc/net/rtl8189es/wlan2/chbw_info
	else
		if [ "$AP_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
		else
			if [ "${AP_CHANNEL}" -ge "8" ]; then
				vht=1
				HT40=2
				#sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			else
				vht=1
				HT40=1
				#sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_2G_PATH
			fi
		fi
		echo "${AP_CHANNEL} ${vht} ${HT40}" > /proc/net/rtl8189es/wlan2/chbw_info
	fi
	/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
elif [ "${iface}" == "${AP5G_IFACE}" ]; then
	if [ "$AP1mode" != "1" ]; then
		sleep 3
	fi
	
	if [ "$AP5G_CHANNEL" == "0" ]; then
		ACS5GChannel=`cat /proc/net/rtl8821au/$STA_IFACE/best_channel | grep "best_channel_5G" | awk '{print $3}'`
		echo "${AP5G_AVAILABLE_CHANNEL}" | grep "${ACS5GChannel}" > /dev/null
		if [ $? != 0 ]; then
			ACS5GChannel=`cat /proc/net/rtl8821au/$STA_IFACE/best_channel | grep "best2nd_channel_5G" | awk '{print $3}'`
		fi
		sed -i 's/^channel=.*/channel='"${ACS5GChannel}"'/g' $HOSTAPD_CONF_5G_PATH
		if [ "$AP5G_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_5G_PATH
		else
			htcap=`echo "${channelwidth20}" | grep -rsw "${ACS5GChannel}"`
			if [ "$htcap" != "" ]; then
				vht=0
				HT40=0
				sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_5G_PATH
			else
				htcap=`echo "${channelwidth40minus}" | grep -rsw "${ACS5GChannel}"`
				if [ "$htcap" != "" ]; then
					vht=2
					HT40=2
					sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				else
					vht=2
					HT40=1
					sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				fi
			fi
		fi
		echo "$ACS5GChannel $vht $HT40" > /proc/net/rtl8821au/wlan0/chbw_info
	else
		if [ "$AP5G_CHANL_WIDTH" == "20" ]; then
			vht=0
			HT40=0
			sed -i 's/^ht_capab=.*/ht_capab='[SHORT-GI-20]'/g' $HOSTAPD_CONF_5G_PATH
		else
			htcap=`echo "${channelwidth20}" | grep -rsw "${AP5G_CHANNEL}"`
			if [ "$htcap" != "" ]; then
				vht=0
				HT40=0
			else
				htcap=`echo "${channelwidth40minus}" | grep -rsw "${AP5G_CHANNEL}"`
				if [ "$htcap" != "" ]; then
					vht=2
					HT40=2
					#sed -i 's/^ht_capab=.*/ht_capab='[HT40-][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				else
					vht=2
					HT40=1
					#sed -i 's/^ht_capab=.*/ht_capab='[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]'/g' $HOSTAPD_CONF_5G_PATH
				fi
			fi
		fi
		echo "$AP5G_CHANNEL $vht $HT40" > /proc/net/rtl8821au/wlan0/chbw_info
	fi
	/usr/local/sbin/wifi_ap_get_config.sh updateconfig > /dev/null 2>&1
fi


exit 0

#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}


