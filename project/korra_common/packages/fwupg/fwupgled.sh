#!/bin/sh
#
#

gpio_path=/sys/class/gpio
blue_led=/sys/class/gpio/gpio0
red_led=/sys/class/gpio/gpio1
green_led=/sys/class/gpio/gpio29
led_power=/sys/class/gpio/gpio88

LED_ON()
{
	echo 1 > ${blue_led}/value
	echo 1 > ${red_led}/value
	echo 1 > ${green_led}/value

}

LED_OFF()
{
	echo 0 > ${blue_led}/value
	echo 0 > ${red_led}/value
	echo 0 > ${green_led}/value
}

DELAY_ON()
{
   delay=0
   while [ $delay -lt 20 ]
   do
	delay=`expr $delay + 1`
   done
}

DELAY_OFF()
{
   delay=0
   while [ $delay -lt 30 ]
   do
	delay=`expr $delay + 1`
   done
}

LED_ONOFF()
{
    loop=0
    while [ $loop -lt 60 ]
    do
	LED_ON
	DELAY_ON
	LED_OFF
	DELAY_OFF
	loop=`expr $loop + 1`
    done

    echo 1 > ${led_power}/value
    echo 0 > ${gpio_path}/unexport
    echo 1 > ${gpio_path}/unexport
    echo 29 > ${gpio_path}/unexport
    echo 88 > ${gpio_path}/unexport
}

echo "Starting mcu update..."
echo "33;0;" > /tmp/MCU_Cmd &
sleep 1
echo 0 > ${gpio_path}/export
echo 1 > ${gpio_path}/export
echo 29 > ${gpio_path}/export
echo 88 > ${gpio_path}/export
echo out > ${blue_led}/direction
echo out > ${red_led}/direction
echo out > ${green_led}/direction
echo out > ${led_power}/direction
echo 0 > ${led_power}/value
sleep 1
LED_ONOFF

