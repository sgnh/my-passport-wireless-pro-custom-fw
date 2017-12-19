#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getActiveLocalNetwork.sh <parameter>
#   where parameter is either:
#   <--addr> get IP/netmask of active LAN
#   <--name> get name of active interface


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/networking-general.conf 2>/dev/null

parm=$1

NETWORK_DEVICE="eth0"
eth0_state=`cat /sys/class/net/eth0/operstate 2>/dev/null`
wifi_state=`cat /sys/class/net/wifi0/operstate 2>/dev/null`
if [ "$wifi_state" == "up" -a "$eth0_state" == "down" ]; then
	NETWORK_DEVICE="wifi0"
fi

if [ "$parm" == "--addr" ]; then
	ip addr show dev $NETWORK_DEVICE | awk '/inet /{print $2}'
else
	echo $NETWORK_DEVICE
fi

exit 0

