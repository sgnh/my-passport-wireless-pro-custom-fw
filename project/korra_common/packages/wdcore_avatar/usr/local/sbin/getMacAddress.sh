#!/bin/sh
#
# © 2010 Western Digital Technologies, Inc. All rights reserved.
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/wifinetwork-param.conf 2>/dev/null
AP_interface=wlan2

if [ "$STA_CHANNEL_LITE" == "0" ]; then
	if [ "${STA_CHANNEL}" == 5 ]; then
		activeIF=${STA_IFACE}
	else
		activeIF=${STA2G4_IFACE}
	fi
else
	activeIF=wlan1
fi


iw dev ${activeIF} info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]
exit 0



	

