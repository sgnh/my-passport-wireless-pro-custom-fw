#!/bin/sh
#
#
# sendHWCollect.sh <hwcollect code> 
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin


if [ $# -lt 1 ]; then
    echo "Usage: sendHWCollect.sh <hwcollect_code> [<value1> [<value2>] ]"
    exit
fi

HWCollectCode=$1

# add the additional substituion values to the end if format 
# =;<value1>;;<value2>;<value3>;-
if [ $# -gt 1 ]; then
    shift
    param="+"
    for j in "$@"
    do
        param="${param};${j}"
    done
    param="${param};-"
fi

timeout=5
inittime=`date +%s`
curtime=${inittime}
success=0
hwcollectdb="/hwcollect/hwcollect.log"

ParmTemp=$(mktemp /tmp/output.XXXXXXXXXX) || { echo "Failed to create temp file"; exit 1; }
echo "${param}" > "${ParmTemp}"
sed -i "s/'/\\'\'/g" "${ParmTemp}"
param=`cat "${ParmTemp}"`

if [ ! -f "${hwcollectdb}" ]; then
    touch ${hwcollectdb}
fi

if [ -f "${hwcollectdb}" ]; then
    while [ `expr $curtime - $inittime` -lt $timeout ]
    do
	echo "${curtime};${HWCollectCode};${param}" >> "${hwcollectdb}"
        if [ $? -eq 0 ]; then
            curtime=`expr $inittime + $timeout + 1`
            success=1
        else
            curtime=`date +%s`
        fi
    done
fi

if [ -f "${ParmTemp}" ]; then
	rm "${ParmTemp}"
fi

[ "${success}" != "0" ]

