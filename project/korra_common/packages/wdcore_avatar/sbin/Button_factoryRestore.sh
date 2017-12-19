#!/bin/bash

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

AC_check_25_percent()
{
    echo "12;0;" > /tmp/MCU_Cmd
    AC=`cat /tmp/battery  | awk '{print $1}'`
    BatLevel=`cat /tmp/battery  | awk '{print $2}'`
    if [ ${BatLevel} -lt 5 ]; then
        exit 11
    fi
}

AC_check_25_percent
/bin/echo "16;0" > /tmp/MCU_Cmd
/usr/local/sbin/factoryRestore.sh noreformat
reboot
exit 0
