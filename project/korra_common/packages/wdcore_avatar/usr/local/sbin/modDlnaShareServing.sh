#!/bin/bash
#
# � 2010, 2012 Western Digital Technologies, Inc. All rights reserved.
#
# modDlnaShareServing.sh <share> <none/any/music_only/pictures_only/videos_only>
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /usr/local/sbin/share-param.sh
. /etc/system.conf

share=$1
setting=$2
port=`getMediaServerPort.sh`

contentdir=/etc/contentdir

if [ $# != 2 ]; then
	echo "usage: modDlnaShareServing.sh <share> <none/any/music_only/pictures_only/videos_only>"
	exit 1
fi

writeTwonkyContentDir.sh

