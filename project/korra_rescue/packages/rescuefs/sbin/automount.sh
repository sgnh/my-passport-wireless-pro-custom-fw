#!/bin/sh

devstr=$1
destdir=/media
dev=${devstr:0:3}

check_DeviceNode()
{
    ishddrive=0
    issdcard=0
    vendor=`cat /sys/block/$dev/device/vendor | awk '{print $1}'`
    model=`cat /sys/block/$dev/device/model`
    size=`cat /sys/block/$dev/size`
    #Temp for Korra and Korra Lite
    [ "$model" == "My Passport 25AF" ] && HDD_MODEL="My Passport 25AF"
    [ "$model" == "My Passport 2601" ] && HDD_MODEL="My Passport 2601"
    [ "$model" == "2115            " ] &&  HDD_MODEL="2115            " && echo "ASMedia ASMT 2115"
    if [ "$vendor" == "ASMT" ] && [ "$model" == "$HDD_MODEL" ]; then
        echo "USB SATA Bridge $dev maybe cortupted !!!"
        if [ ! -f /tmp/ASMediaUpdating ]; then
            touch /tmp/ASMediaUpdating
            asmupdate -u /dev/$dev /etc/firmware/AsmSataFw.bin
            rm /tmp/ASMediaUpdating
        fi
        exit 0
    fi
    if [ "$vendor" == "WD" ] && [ "$model" == "$HDD_MODEL" ]; then
        if [ $size -gt 4194304 ]; then
            echo "User Disk/Volume: $devstr"
            HDDdev=$dev
            mkdir -p --mode=0755 /tmp/hddmounts/$devstr
            echo "$devstr" > /tmp/HDDDevNode
            mount -o force,rw /dev/$devstr /tmp/hddmounts/$devstr > /dev/null 2>&1 && echo "Mount $devstr succeeded!" > /dev/console || \
            (sleep 1 && mount -o force,rw /dev/$devstr /tmp/hddmounts/$devstr > /dev/null 2>&1 && echo "Mount $devstr succeeded on second time!" > /dev/console)
            isMounted=`mount | grep "$devstr " | wc -l`
            if [ $isMounted -gt 0 ]; then
                echo "$devstr" > /tmp/HDDDevNode
            fi
        else
            echo "System Disk/Volume: $devstr"
        fi
    else
        mkdir -p --mode=0755 /tmp/usbmounts/$devstr
        mount -o rw /dev/$devstr /tmp/usbmounts/$devstr > /dev/null 2>&1 && echo "Mount $devstr succeeded!" > /dev/console || \
        (sleep 1 && mount -o rw /dev/$devstr /tmp/usbmounts/$devstr > /dev/null 2>&1 && echo "Mount $devstr succeeded on second time!" > /dev/console)
    fi
}

echo "${ACTION} ${DEVNAME} $1 $2 $3 $4" >> /tmp/automount.log
                                                              
case "${ACTION}" in
add|"")
    check_DeviceNode
    ;;
remove)
    echo "####${ACTION}####"
    echo "do remove" >> /tmp/automount.log
    my_umount $1
    ;;
esac
