#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# writeTwonkyContentDir.sh
#
#


#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /usr/local/sbin/share-param.sh
. /etc/system.conf


if [ "`getServiceStartup.sh twonky`" == "disabled" ]; then
	exit 0;
fi

share=$1
setting=$2
TWONKY_IP="`cat /tmp/twonky_server`"

contentdir=/etc/contentdir

# ensure all cr/lf are filtered from contentdir
tr -d '\r\n' < ${contentdir} > /tmp/contentdir
mv /tmp/contentdir ${contentdir}

encoded_contentdir=`cat ${contentdir} | urlEncode.sh`

# get contentdir set option from Twonky
timeout -t 5 curl "http://${TWONKY_IP}/rpc/set_option?contentdir=${encoded_contentdir}" > /tmp/contentdir 2>/dev/null
if [ $? == 1 ]; then
	echo "Failed twonky get"
	exit 1
fi
