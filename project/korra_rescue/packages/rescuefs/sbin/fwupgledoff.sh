#!/bin/sh
#
#

gpio_path=/sys/class/gpio
blue_led=/sys/class/gpio/gpio47
led_power=/sys/class/gpio/gpio42

killall fwupgled.sh 
#echo 1 > ${led_power}/value
echo 1 > ${blue_led}/value
echo 42 > ${gpio_path}/unexport
echo 47 > ${gpio_path}/unexport

