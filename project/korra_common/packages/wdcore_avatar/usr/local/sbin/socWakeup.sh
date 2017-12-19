#!/bin/sh
if [ -f /tmp/StandbyMode ]; then
	echo in > /sys/class/gpio/gpio3/direction
	echo 3 > /sys/class/gpio/unexport
	killall -17 ghelper
	echo "37;0" > /tmp/MCU_Cmd
	rm -f /tmp/StandbyMode
	/etc/init.d/S90multi-role restart > /dev/null 2>&1 &
fi
