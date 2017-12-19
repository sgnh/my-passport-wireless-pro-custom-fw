#!/bin/sh
echo "12;0;" > /tmp/MCU_Cmd
AC=`cat /tmp/battery  | awk '{print $1}'`
BatLevel=`cat /tmp/battery  | awk '{print $2}'`
HDDbusy=`cat /sys/block/sda/device/power/runtime_status`

if [ ${HDDbusy} == "active" ]; then
    echo "HDD busy"
    exit 0

fi

if [ "${AC}" == "charging" ]; then
    echo "CHARGING"
    exit 0
fi

if [ -f /tmp/fw_update_mutex ]; then
	echo "FW UPDATING..."
	exit 0
fi

if [ -f /tmp/InSuspendMode ]; then
	echo "In Suspend Mode"
	exit 0
fi
touch /tmp/InSuspendMode

echo 0 > /proc/scsi/pmxrtpm

sleep 3

ExternalUSBport=`/usr/local/sbin/wdAutoMountAdm.pm getDrives | grep "storage_type=USB" | wc -l`
ExternalSDCardport=`/usr/local/sbin/wdAutoMountAdm.pm getDrives | grep "storage_type=SDCARD" | wc -l`
ExternalDevices=`/usr/local/sbin/wdAutoMountAdm.pm getDrives | grep handle | sed -n -e 's/^.*handle=//p'`

for ExternalDevice in ${ExternalDevices} ; do
	/usr/local/sbin/wdAutoMountAdm.pm ejectDrive ${ExternalDevice}
	sleep 1
done

ls /media/
if [ ${ExternalUSBport} -gt 0 ]; then
	echo "18;0;" > /tmp/MCU_Cmd
	sleep 1
	echo "41;2;" > /tmp/MCU_Cmd
	sleep 1
fi
if [ ${ExternalSDCardport} -gt 0 ]; then
	echo "18;0;" > /tmp/MCU_Cmd
	sleep 1
fi
sync
sync
sync

powerprofile=`/usr/local/sbin/power_get_profile.sh`
if [ "$powerprofile" == "max_life" ]; then
	echo "24;01;" > /tmp/MCU_Cmd
	killall -15 hostapd
	sleep 20 
	ifconfig wlan0 down
	ifconfig wlan2 down 
	ifconfig wlan0 down
	ifconfig wlan2 down 
	sleep 20
	touch /tmp/DisableWake
fi
/etc/init.d/S73multi-role stop

echo "Remove USB module"
rmmod ohci_hcd
rmmod ehci_rtk
rmmod ehci_platform
rmmod ehci_hcd
rmmod rtksd_mod

isAuto=`cat /sys/block/sda/device/power/control`
if [ $isAuto == "auto" ]; then
	echo on > /sys/block/sda/device/power/control
	echo on > /sys/block/sdb/device/power/control
	echo on > /sys/block/sdc/device/power/control
	echo on > /sys/block/sdd/device/power/control
	sleep 1
fi
sleep 1
echo "36;0" > /tmp/MCU_Cmd
sleep 3
echo ram > /sys/kernel/suspend/mode
echo mem > /sys/power/state

echo "37;0;" > /tmp/MCU_Cmd
sleep 5

echo "Insmod USB module"
insmod /lib/modules/3.10.24-rtk-nas/kernel/drivers/usb/host/ehci-hcd.ko
insmod /lib/modules/3.10.24-rtk-nas/kernel/drivers/usb/host/ehci-rtk.ko
insmod /lib/modules/3.10.24-rtk-nas/kernel/drivers/usb/host/ehci-platform.ko
insmod /lib/modules/3.10.24-rtk-nas/kernel/drivers/usb/host/ohci-hcd.ko
insmod /lib/modules/3.10.24-rtk-nas/kernel/drivers/mmc/host/rtksd_mod.ko

sleep 10
echo "44;0;" > /tmp/MCU_Cmd
powerprofile=`/usr/local/sbin/power_get_profile.sh`
if [ "$powerprofile" == "max_life" ]; then
	sleep 5
	/sbin/wifi-restart AP
	echo "24;00;" > /tmp/MCU_Cmd
fi
killall -11 monitor

source /etc/nas/config/wifinetwork-param.conf
if [ "$STA_CLIENT" == "true" ]; then
	sleep 15
	sed -i 's/STA_CONF_JOIN=.*/STA_CONF_JOIN=1/' /etc/nas/config/wifinetwork-param.conf
	/sbin/wifi-restart STA > /dev/null 2>&1
	cat /etc/nas/config/wifinetwork-remembered.conf | grep -rsw "${STA_SSID_NAME}" | head -1 | awk 'BEGIN {FS="bssi/dmap="} {print $1}' > /tmp/wifinetwork-remembered.conf
	sleep 1
	/usr/local/sbin/wifi_client_ap_retry.sh 2
fi

AC=`cat /tmp/battery  | awk '{print $1}'`
BatLevel=`cat /tmp/battery  | awk '{print $2}'`
if [ "${AC}" == "discharging" ]; then
	if [ "${AC}" == "discharging" ]; then
		if [ ${BatLevel} -lt 15 ]; then
			/usr/local/sbin/sendAlert.sh 1601
			sleep 5
			halt
			exit 0
		fi
	fi
fi
while :; do
    kworker=`ps aux | grep kworker | wc -l`
    if [ ${kworker} -lt 20 ]; then
        echo 1 > /proc/scsi/pmxrtpm
        sleep 1
        if [ $isAuto == "auto" ]; then
                echo auto > /sys/block/sda/device/power/control
                echo auto > /sys/block/sdb/device/power/control
                echo auto > /sys/block/sdc/device/power/control
                echo auto > /sys/block/sdd/device/power/control
                sleep 1
        fi
        rm -f /tmp/InSuspendMode
        echo 4 > /proc/sys/kernel/printk
        exit 0
    fi
    echo "Resume in process..."
    /sbin/CheckMediaScanStatus.sh &
    sleep 30
done
