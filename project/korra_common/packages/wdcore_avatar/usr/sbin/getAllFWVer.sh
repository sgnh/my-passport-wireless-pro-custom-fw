#!/bin/sh
echo "1;0;" > /tmp/MCU_Cmd
sleep 1
ASMediaVer=`stbtool -v \`cat /tmp/HDDDevNode\` |cut -d ':' -f 2`
WiFi24G=`cat /proc/net/rtl8189es/ver_info | head -1 | cut -d ' ' -f 2`
WiFi24Gchip=`cat /proc/net/rtl8189es/ver_info | head -1 | cut -d ' ' -f 1`
WiFi5G=`cat /proc/net/rtl8821au/ver_info | head -1 | cut -d ' ' -f 2`
WiFi5Gchip=`cat /proc/net/rtl8821au/ver_info | head -1 | cut -d ' ' -f 1`
clear
echo "FW version: `cat /etc/version`"
echo "MCU version: `cat /tmp/MCU_Version`"
echo "ASMedia version:${ASMediaVer}"
echo "WiFi 2.4G(${WiFi24Gchip}) version: ${WiFi24G}"
echo "WiFi   5G(${WiFi5Gchip}) version: ${WiFi5G}"
