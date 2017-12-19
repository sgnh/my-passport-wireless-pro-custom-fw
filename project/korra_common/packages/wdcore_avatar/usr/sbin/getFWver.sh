#!/bin/sh
echo "1;0;" > /tmp/MCU_Cmd
sleep 1
clear
echo "FW version: `cat /etc/version`"
echo "MCU version: `cat /tmp/MCU_Version`"
echo "Asmedia version:"
stbtool -v "`cat /tmp/HDDDevNode`"
