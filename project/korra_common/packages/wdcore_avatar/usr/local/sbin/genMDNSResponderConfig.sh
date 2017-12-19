#!/bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# genMDNSResponderConfig.sh - generates the mDNSResponder.conf file.
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
upnpDeviceFile=/etc/nas/nasdevice.xml
CONF_FILE=/etc/nas/mDNSResponder.conf
. /etc/system.conf

if [ -f /etc/nas/timeMachine.conf ]; then
    . /etc/nas/timeMachine.conf
fi

hostname=`hostname`
serialNumber=`getSerialNumber.sh`
modelNumber=`awk -F'[<|>]' '/modelNumber/{print $3; exit 0;}' $upnpDeviceFile`
udn=`getUpnp_uuid.sh`
modelURL=`awk -F'[<|>]' '/modelURL/{print $3; exit 0;}' $upnpDeviceFile`
manufacturer=`awk -F'[<|>]' '/manufacturer/{print $3; exit 0;}' $upnpDeviceFile`
modelDescription=`awk -F'[<|>]' '/modelDescription/{print $3; exit 0;}' $upnpDeviceFile`
modelName=`awk -F'[<|>]' '/modelName/{print $3; exit 0;}' $upnpDeviceFile`

# HTTP
echo "$hostname" > $CONF_FILE
echo "_http._tcp. local." >> $CONF_FILE
echo "80" >> $CONF_FILE
echo "TXTVersion=1.1" >> $CONF_FILE
echo "Vendor=WDC" >> $CONF_FILE
echo "modelURL=$modelURL" >> $CONF_FILE
echo "manufacturer=$manufacturer" >> $CONF_FILE
echo "modelDescription=$modelDescription" >> $CONF_FILE
echo "modelName=$modelName" >> $CONF_FILE
echo "modelNumber=$modelNumber" >> $CONF_FILE
echo "serialNumber=$serialNumber" >> $CONF_FILE
echo "UDN=$udn" >> $CONF_FILE
echo "" >> $CONF_FILE

itunes_startup=`getServiceStartup.sh itunes`
if [ "$?" == "0" ] && [ "$itunes_startup" == "enabled" ]; then
	# daap
	echo "$hostname" >> $CONF_FILE
	echo "_daap._tcp. local." >> $CONF_FILE
	echo "3689" >> $CONF_FILE
	echo "Machine Name=$hostname" >> $CONF_FILE
	echo "" >> $CONF_FILE
fi

# wd-2go
echo "$hostname" >> $CONF_FILE
echo "_wd-2go._tcp. local." >> $CONF_FILE
echo "80" >> $CONF_FILE
echo "TXTVersion=1.1" >> $CONF_FILE
echo "Vendor=WDC" >> $CONF_FILE
echo "modelURL=$modelURL" >> $CONF_FILE
echo "manufacturer=$manufacturer" >> $CONF_FILE
echo "modelDescription=$modelDescription" >> $CONF_FILE
echo "modelName=$modelName" >> $CONF_FILE
echo "modelNumber=$modelNumber" >> $CONF_FILE
echo "serialNumber=$serialNumber" >> $CONF_FILE
echo "UDN=$udn" >> $CONF_FILE
echo "" >> $CONF_FILE

# afpovertcp
echo "$hostname" >> $CONF_FILE
echo "_afpovertcp._tcp. local." >> $CONF_FILE
echo "548" >> $CONF_FILE
echo "" >> $CONF_FILE

# adisk (for TimeMachine) - modified to use live port of 548, note that this is only used by bonjour conformance test
# Specify a backup if a backup has been enabled backup for a selected backup share and the
# time machine directory for the share exists.
if ([ "$backupEnabled" = "true" ] && [ ! -z "$backupShare" ] && [ -d "/shares/$backupShare" ]); then
    echo "$hostname" >> $CONF_FILE
    echo "_adisk._tcp. local." >> $CONF_FILE
    echo "9" >> $CONF_FILE
    echo "sys=waMA=`getMacAddress.sh`,adVF=0x100" >> $CONF_FILE
    echo "dk0=adVN=${backupShare},adVF=0x83" >> $CONF_FILE
    echo "" >> $CONF_FILE
fi

