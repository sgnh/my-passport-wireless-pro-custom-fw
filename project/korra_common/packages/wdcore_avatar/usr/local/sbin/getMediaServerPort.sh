#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getMediaServerPort.sh
#
# RETURNS: Port of media server
#

#---------------------


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /usr/local/sbin/share-param.sh
. /etc/system.conf


# get info_clients option from Twonky
sed -n -e '/URL=/s#.*127.0.0.1:\([0-9]*\)/.*#\1#p' /CacheVolume/.twonkymedia/twonky-config.html
