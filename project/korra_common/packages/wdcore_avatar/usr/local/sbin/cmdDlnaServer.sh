#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# cmdMediaServer.sh <rebuild/reset_defaults/rescan>
#
#
#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /usr/local/sbin/share-param.sh
. /etc/system.conf


cmd=$1
TWONKY_IP="`cat /tmp/twonky_server`" 
#include a helper function, wait_for_server_up
. /usr/local/sbin/waitForDlnaServerUp.sh

if [ "`getServiceStartup.sh twonky`" == "disabled" ]; then
	exit 0;
fi

case ${cmd} in
reset_defaults)
	if [ "$TWONKY_IP" != "" ]; then
		curl "http://${TWONKY_IP}/rpc/reset"
	fi
	;;
rebuild)
	#/etc/init.d/twonky stop
	#sleep 2
	#rm -rf /CacheVolume/twonkymedia
	#/etc/init.d/twonky start
	if [ "$TWONKY_IP" != "" ]; then
	curl -s "http://${TWONKY_IP}/rpc/rebuild"
	wait_for_server_up
	fi
	;;
rescan)
	if [ "$TWONKY_IP" != "" ]; then
	curl "http://${TWONKY_IP}/rpc/rescan"
	fi
	;;
*)
	echo "usage: cmdMediaServer.sh <rebuild/reset_defaults/rescan>"
	exit 1
esac

# get info_status option from Twonky
if [ $? == 1 ]; then
	echo "Failed twonky get"
	exit 1
fi
