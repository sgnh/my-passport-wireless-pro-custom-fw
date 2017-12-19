#!/bin/bash
#
# This script is run when a system starts its UPnP service in order to update
# the "nasdevice.xml" file which is used to describe a WD NAS device.  The file
# only needs to be updated the first time the UPnP service is started in order
# to initialize a few parameters that are based on the specific system hardware
# (such as serial number).  The uninitialized parameters are identified by
# having the value "__Uninitialized__".
#
# Copyright (c) [2011] Western Digital Technologies, Inc. All rights reserved.

# Determine the hostname, uuid, and serial number of the system.

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/default/upnp_nas

DLNA_UPDATER=${DLNA_UPDATER:-/usr/local/sbin/modDlnaDeviceDescription.sh}

PRIMARY_INTERFACE=eth0
SECONDARY_INTERFACE=wifi0

uuid=`getUpnp_uuid.sh`
hostname=`hostname`
serialNumber=`getSerialNumber.sh`
uninitialized='__Uninitialized__'
filename="$UPNPNAS_SOURCE_DIR/$UPNPNAS_FILE"
copyname="$UPNPNAS_DIR/$UPNPNAS_FILE"
ipaddr=`ifconfig $PRIMARY_INTERFACE | awk '/inet addr:/{gsub(/.*:/,"",$2);print$2}'`
[ -z $ipaddr ] && ipaddr=`ifconfig $SECONDARY_INTERFACE | awk '/inet addr:/{gsub(/.*:/,"",$2);print$2}'`

keyArray=('UDN' 'friendlyName' 'presentationURL' 'serialNumber')

valueArray[0]="uuid:$uuid"       # UDN
valueArray[1]="$hostname"        # friendlyName
valueArray[2]="http://$ipaddr"   # presentationURL
valueArray[3]="$serialNumber"    # serialNumber

data=''
parameterInitialized=0

# Read the contents of the "nasdevice.xml" file, only checking parameters that
# may need to be updated.  If any of them are uninitialized or changed, then
# initialize them.  current values should never be '__Uninitialized__'

while line=$(line)
do
    key=$(echo $line | sed -e 's,.*</\(.*\)>.*,\1,')
    current=$(echo $line | sed -e 's,.*>\(.*\)<.*,\1,')

    for index in ${!keyArray[*]}; do
        if [ "$key" == ${keyArray[$index]} ]; then
            if [ "$current" != ${valueArray[$index]} ]; then
                line=$(echo "$line" | \
  sed -n "s|\(<${keyArray[$index]}.*>\)\(.*\)\(</${keyArray[$index]}>\)|\1${valueArray[$index]}\3|p")
                parameterInitialized=1
            fi
        fi
    done

    if [ -n "$line" ]; then
         data+="$line\n"
    fi
done <$filename

# If a parameters was initialized, update the file.

if [ $parameterInitialized -eq 1 ]; then
    echo -e "$data" > $filename
fi

if [ ! -f $copyname -o $parameterInitialized -eq 1 ]; then
    cp $filename $copyname
fi

if [ -x $DLNA_UPDATER -a $parameterInitialized -eq 1 ]; then
    $DLNA_UPDATER
fi
