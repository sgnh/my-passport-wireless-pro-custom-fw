#!/bin/sh
#
# © 2010 Western Digital Technologies, Inc. All rights reserved.
#
# sendAlert.sh <alert code> 
#
# Note: alert codes /etc/alert-param.sh
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#. /etc/nas/alert-param.sh

if [ $# -lt 1 ]; then
    echo "Usage: sendAlert.sh <alert_code> [<value1> [<value2>] ]"
    exit
fi

facility="local6"
alertCode=$1

if [ "$alertCode" -lt "1000" ]; then
	sev="crit"
elif [ "$alertCode" -lt "2000" ]; then
	sev="warn"
else
	sev="info"
fi
desc=`awk -v code=$alertCode 'BEGIN{FS=" = ";RS="\n"}{if (code == $1) {print $2; exit 0;}}' /etc/nas/strings/en_US/alertmessages.txt`

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
    desc="${desc} ${param}"
fi

logger -p ${facility}.${sev} "${alertCode}: ${desc}"

timeout=5
inittime=`date +%s`
curtime=${inittime}
success=0
alertdb="/CacheVolume/.wd-alert/wd-alert.db"

ParmTemp=$(mktemp /tmp/output.XXXXXXXXXX) || { echo "Failed to create temp file"; exit 1; }
echo "${param}" > "${ParmTemp}"
sed -i "s/'/\\'\'/g" "${ParmTemp}"
param=`cat "${ParmTemp}"`

if [ -s "${alertdb}" ]; then
    while [ `expr $curtime - $inittime` -lt $timeout ]
    do
        sqlite3 "${alertdb}" "INSERT INTO AlertHistory (alert_code, desc) VALUES ('${alertCode}', '${param}')" > /dev/null 2>&1
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

[ "${success}" != "0" ] && incUpdateCount.pm alert &

#sendEmailAlerts.sh
