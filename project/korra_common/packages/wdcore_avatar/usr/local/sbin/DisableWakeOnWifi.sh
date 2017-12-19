#!/bin/sh
exit 0

echo "12;0;" > /tmp/MCU_Cmd
AC=`cat /tmp/battery  | awk '{print $1}'`
BatLevel=`cat /tmp/battery  | awk '{print $2}'`
HDDbusy=`cat /sys/block/sda/device/power/runtime_status`

if [ ${HDDbusy} == "active" ]; then
    echo "HDD busy"
    exit 0

fi
if [ ${AC} == "charging" ]; then
    echo "CHARGING"
    exit 0
fi
if [ -f /tmp/fw_update_mutex ]; then
	echo "FW UPDATING..."
	exit 0
fi

#/sbin/wifi-restart UPDATE_STA_CONF
#wpa_cli -i wlan0 disable_network 0
#/etc/init.d/S90multi-role stop
powerprofile=`/usr/local/sbin/power_get_profile.sh`
if [ "$powerprofile" == "max_life" ]; then
	/etc/init.d/S60hostapd stop
	sleep 20 
    ifconfig wlan0 down
    ifconfig wlan2 down 
	sleep 20
	
	touch /tmp/DisableWake
fi

 

exit 0