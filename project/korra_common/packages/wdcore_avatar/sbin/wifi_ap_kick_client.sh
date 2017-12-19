#!/bin/sh
#
# 2014 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_HybridMode.sh
#
#


if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

AP_interface="${1}"
kick_mac="${2}"

echo "AP_interface" "$AP_interface"
echo "kick_mac" "$kick_mac"

if [ "$AP_interface" == "" ] || [ "$kick_mac" == "" ]; then
	exit 1
fi

for ((index=1; index<2000; index++ )); do
	hostapd_cli -i "${AP_interface}" disassociate "${kick_mac}" > /dev/null
	iw dev "${AP_interface}" station del "${kick_mac}" > /dev/null		 
done

exit 0

# EOF

