#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# modMediaServerEnable.sh <mac_address> <enable/disable>
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
#. /usr/local/sbin/share-param.sh
#. /etc/system.conf


if [ $# != 2 ]; then
	echo "usage: modDlnaServerEnable.sh <mac_address> <enable/disable>"
	exit 1
fi

# Twnoky 7.2 deprecates the client_enable and client_disable APIs  and adds a client_change API
# The client_change API needs a gateway-MAC-address and an unique index to uniquely identify a connacted client
# So we convert from a mac address (which is what's given to us) to a key constituting a gateway-mac::index

mac_addr=$1
all_index=`grep -B 2 $mac_addr /tmp/info_connected_clients | grep :: `
all_index_num=`grep -Fx $mac_addr /tmp/info_connected_clients | wc -l`
enable=$2
port=`getMediaServerPort.sh`
TWONKY_IP="`cat /tmp/twonky_server`"


#To extract the gateway-mac::index, print the two lines before the matching line (w/mac addr), then print the first line; 
#gateway_mac_and_index=`grep -B 2 $mac_addr /tmp/info_connected_clients | head -1`

# The input max address is not shown in client list
if [ "$all_index_num" == "0" ]; then
    exit 1
fi
for index in $all_index
do
	case ${enable} in
	enable)
		curl "http://${TWONKY_IP}/rpc/client_change?key=${index}&enabled=1" > /tmp/info_client_change 2>/dev/null	
		validate=`head -n 6 /tmp/info_client_change | tail -n 1` #pick up the ENABLED field from the response and validate it
		if [ "$validate" != "1" ]
		then 
		    exit 1
		fi
		;;
	disable)
		curl "http://${TWONKY_IP}/rpc/client_change?key=${index}&enabled=0" > /tmp/info_client_change 2>/dev/null	
		validate=`head -n 6 /tmp/info_client_change | tail -n 1`
		if [ "$validate" != "0" ]
		then 
		    exit 1
		fi
		;;
	*)
		echo "usage: modDlnaServerEnable.sh <mac_address> <enable/disable>"
		exit 1
	esac
done
exit 0


