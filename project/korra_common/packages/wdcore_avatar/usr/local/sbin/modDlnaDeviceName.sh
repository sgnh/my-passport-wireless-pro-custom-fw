#!/bin/bash
#
# © 2012 Western Digital Technologies, Inc. All rights reserved.
#
# update dms_descr.xml from /etc/nasdevice.xml

# since the device description should already have been updated by the upnp_nas,
# just restart the server

#/etc/init.d/twonky restart

#exit $?
TWONKY_IP="`cat /tmp/twonky_server`" 
curl -m 5 -s http://${TWONKY_IP}/rpc/set_option?friendlyname="$1" 
curl_exit_code=`echo $?` 
if [ $curl_exit_code != 0 ]; then 
logger -p local5.info "modDlnaDeviceName.sh curl failure $curl_exit_code trying to set Twonky friendlyname to $1." 
echo "modDlnaDeviceName.sh curl failure $curl_exit_code trying to set Twonky friendlyname to $1." 
fi 