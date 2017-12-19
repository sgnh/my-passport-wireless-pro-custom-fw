#!/bin/sh

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ $# -lt 0 ]; then
        echo "usage: setStorageScan.sh <0/1>"
        exit 1
fi

case "$1" in
        0 )
                sudo echo 0 > /usr/local/orion/crawlersettings/ExternalVolumeMediaView
                ;;
        1 )
                sudo echo 1 > /usr/local/orion/crawlersettings/ExternalVolumeMediaView
                ;;
        * )
                echo "usage: setStorageScan.sh <0/1>"
                ;;
esac
