#!/bin/sh

source /etc/power.conf

enabled=$1
ACMode=`cat /tmp/battery | cut -d " " -f 1`

if [ "${enabled}" == "true" ] || [ "${enabled}" == "false" ]; then
    if [ "${enabled}" == "false" ]; then
        if [ -f /tmp/wipe-status ];then
            status=`cat /tmp/wipe-status`
            if [ "$status" == "insufficient_power" ]; then
                rm -f /tmp/wipe-status
            fi
        fi
    fi
    if [ "${powerprofile}" == "max_life" ]; then
        /usr/local/sbin/setMediaCrawlerPowerMode.sh ${enabled} & > /dev/null 2> /dev/null
    fi
    /etc/init.d/S90powerprofile restart
    echo -n "Stop SWAP sevice: "
    /sbin/EnableDisableSwap.sh disable
    echo "done"
    echo -n "Starting SWAP sevice: "
    if [ "${ACMode}" == "charging" ] ; then
        /sbin/EnableDisableSwap.sh enable
    fi
    /usr/local/sbin/sendHWCollect.sh 104 ${ACMode}
    exit 0
else
    echo "SetPowerProfile.sh true | false"
    exit 1
fi

