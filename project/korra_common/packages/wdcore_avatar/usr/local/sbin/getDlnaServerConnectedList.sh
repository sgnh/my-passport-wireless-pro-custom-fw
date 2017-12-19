#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getDlnaServerConnectedList.sh
#
# RETURNS:
#  "mac_address" "ip_address" "friendly_name" "device_description" "enabled/disabled"
# Returns a list of attributes for players ONLY; servers have been filtered out

#Twonky 7.2 notes; we now get 12 return values in the order below
# The script has been adjusted from Twonky 5 to accomodate the new order
#Key (#1)
#ID  (#2)
#MAC (#3)
#IP  (#4)
#IS_AGGREGATION_SERVER (#5) 
#ENABLED (#6)
#DEVICE_TYPE (#7)
#ICON (#8)
#ICON_MIME_TYPE (#9) 
#VIEW_NAME (#10)
#HAS_DEFAUT_VIEW (#11) 
#USER_FRIENDLY_NAME (#12)
########## (#END)

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /usr/local/sbin/share-param.sh
. /etc/system.conf


TWONKY_IP="`cat /tmp/twonky_server`"

# get info_clients option from Twonky
# Returns a *complete* list of known/supported clients as a tuple; ID, description
if [ ! -f /tmp/info_clients ]; then
	curl "http://${TWONKY_IP}/rpc/info_clients" > /tmp/info_clients 2>/dev/null
	if [ $? != 0 ]; then
        rm /tmp/info_clients
        echo "Failed twonky get"
		exit 1
	fi
fi

curl "http://${TWONKY_IP}/rpc/info_connected_clients" > /tmp/info_connected_clients 2>/dev/null
if [ $? != 0 ]; then
	echo "Failed twonky get"
	exit 1
fi
#-v info_clients=${info_clients}
awk '
BEGIN { 
    FS = "\n"; RS = "##########\n";
	getline info < "/tmp/info_clients"
	split(info, info_arr, ",")
	for ( item in info_arr ) info_count++;
}
{
	id = $1;
	mac = $3;
	ip = $4;
        is_aggregation_server = $5;
	if ( $6 == 1 )
		enable = "enable";
	else
		enable = "disable";
		
	friendly_name = $12;
	for (i = 1; i <= info_count; i=i+2) {
		if (info_arr[i] == id) {
			desc = info_arr[i+1];
			break;
		}
	}
        if ( is_aggregation_server != 1 )
	         printf("\"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n", mac, ip, friendly_name, desc, enable);
}

' /tmp/info_connected_clients
