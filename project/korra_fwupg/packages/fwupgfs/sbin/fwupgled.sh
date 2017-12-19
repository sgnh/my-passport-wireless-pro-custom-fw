#!/bin/sh
#
#

gpio_path=/sys/class/gpio
blue_led=/sys/class/gpio/gpio47
led_power=/sys/class/gpio/gpio42

LED_ON()
{
    echo 0 > ${led_power}/value
    echo 1 > ${blue_led}/value

}

LED_OFF()
{
    echo 0 > ${led_power}/value
	echo 0 > ${blue_led}/value
}

DELAY_ON()
{
   delay=0
   while [ $delay -lt 240 ]
   do
	delay=`expr $delay + 1`
   done
}

DELAY_OFF()
{
   delay=0
   while [ $delay -lt 240 ]
   do
	delay=`expr $delay + 1`
   done
}

LED_ONOFF()
{
    loop=0
    while [ $loop -lt 20 ]
    do
	LED_ON
	DELAY_ON
	LED_OFF
	DELAY_OFF
	loop=`expr $loop + 1`
    done
}

echo "Starting mcu update..."
#echo 42 > ${gpio_path}/export
#echo 47 > ${gpio_path}/export
#echo 0 > ${led_power}/value
#echo 0 > ${led_power}/value
#echo out > ${blue_led}/direction
#echo out > ${led_power}/direction
#echo 0 > ${led_power}/value
#echo 0 > ${led_power}/value
#echo 0 > ${led_power}/value
echo "33;0;" > /tmp/MCU_Cmd &
LED_ONOFF

