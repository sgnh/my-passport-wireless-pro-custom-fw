#!/bin/bash

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin



external_device=`find /tmp/ -name "*-info" | wc -l`

if [ "${external_device}" == "0" ]; then
    if [ -f /tmp/compiling_external_db ]; then
        echo "43;0" > /tmp/MCU_Cmd
        rm -f /tmp/compiling_external_db
    fi
    if [ -f /tmp/init_compiling_external_db ]; then
        echo "43;0" > /tmp/MCU_Cmd
        rm -f /tmp/init_compiling_external_db
    fi
    exit 1
fi

if [ "$1" == "init" ]; then
    echo "43;1" > /tmp/MCU_Cmd
    touch /tmp/init_compiling_external_db
fi

if [ -f /tmp/init_compiling_external_db ]; then
    rm -f /tmp/init_compiling_external_db
    touch /tmp/compiling_external_db
    exit 1
fi

compiling_external_db=`/usr/local/sbin/getMediaCrawlerStatus.sh  | grep "/shares/.USB" | grep -e "\"scanning\"" -e "\"extracting\"" -e "\"transcoding\"" | wc -l`

if [ "${compiling_external_db}" -gt "0" ]; then
    if [ ! -f /tmp/compiling_external_db ]; then
        echo "43;1" > /tmp/MCU_Cmd
        touch /tmp/compiling_external_db
    fi
fi

if [ "${compiling_external_db}" == "0" ] && [ -f /tmp/compiling_external_db ]; then
    echo "43;0" > /tmp/MCU_Cmd
    if [ -f /tmp/init_compiling_external_db ]; then
        rm -f /tmp/init_compiling_external_db
    fi
    rm -f /tmp/compiling_external_db
fi

exit 0
