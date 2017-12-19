#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getDataVolumeUsage.sh 

## optional first (single) parameter may specify "size" only or "usage" only

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf

##-------------------
## PHP example usage:
## Add to file: "/var/www/rest-api/api/Storage/src/Storage/Controller/Usage.php"
##-------------------
# unset($answer);
# exec_runtime("sudo /usr/local/sbin/getDataVolumeUsage.sh size", $answer, $retVal);
# $result['size'] = $answer[0];
# unset($answer);
# exec_runtime("sudo /usr/local/sbin/getDataVolumeUsage.sh usage", $answer, $retVal);
# $result['usage'] = $answer[0];       
##-------------------

[ -z "${1}" ] && df -B GB | grep /DataVolume | awk '{printf("%s %s\n",$3,$2)}'
[ -z "${1}" ] && exit 0

if [ "${1}" == "size" -o "${1}" == "usage" ]; then
    size=$(df -B KB | grep /DataVolume | awk '{printf("%s\n",$2)}')
    usage=$(df -B KB | grep /DataVolume | awk '{printf("%s\n",$3)}')
    size=${size%%kB}000
    usage=${usage%%kB}000
#    echo "<storage_usage> <size>${size}</size> <usage>${usage}</usage> </storage_usage>"
     [ "${1}" == "size" ] && echo "${size}"
     [ "${1}" == "usage" ] && echo "${usage}"
fi

