#!/bin/bash

SDCardFolder=`mount |grep mmcblk | grep /media | sed -n -e 's/^.*on //p' | sed -n -e 's/ type.*//p'`

if [ -d ${SDCardFolder} ]; then
    echo "`date +%Y/%m/%d-%H:%M:%S`: $1,$2,$3,$4" >> ${SDCardFolder}/MCU_Temp.log
    cat /tmp/battery >> ${SDCardFolder}/MCU_Temp.log
    cat /tmp/batterymV >> ${SDCardFolder}/MCU_Temp.log
fi

