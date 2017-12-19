#!/bin/sh
#
# © 2010 Western Digital Technologies, Inc. All rights reserved.
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

# get MAC address, and remove all whitespace
mac_addr=`ifconfig "wlan1" | grep -m 1 "wlan[0-9] " | sed -n -e 's/.*HWaddr \(.*\)/\1/p' | tr -d ":" | sed 's/^[ \t]*//;s/[ \t]*$//'`
echo "73656761-7465-7375-636b-$mac_addr"
