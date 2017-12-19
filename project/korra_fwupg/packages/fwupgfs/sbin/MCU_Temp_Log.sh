#!/bin/sh

if [ -d /media/SDcard ]; then
    echo "`date +%Y/%m/%d-%H:%M:%S`: $1,$2,$3,$4" >> /media/SDcard/MCU_Temp.log
    cat /tmp/battery >> /media/SDcard/MCU_Temp.log
    cat /tmp/batterymV >> /media/SDcard/MCU_Temp.log
fi

