#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
#Script used to change the Apache https servername name.
#Usage:
#  modServerName.sh <servername>
#
# NOTE:  Caller to do all input validation
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/wdcomp.d/apache-php-webdav/apache-php-webdav.conf 2> /dev/null

if [ $# != 1 ]; then
        echo "usage: modServerName.sh <servername>"
        exit 1
fi

servername=$1
currentServerName=`getServerName.sh`
[ "$currentServerName" == "$servername" ] && exit 0

if [ -z $servername ]; then
    echo "" > ${SERVER_NAME_CONFIG}
else
    alias=`echo $servername | awk -F. '{printf("*.%s.%s",$(NF-1),$(NF))}'`
    echo -e "ServerName ${servername}\nServerAlias ${alias}" > ${SERVER_NAME_CONFIG}
fi

daemon -U -X "apache2ctl -k graceful"
exit 0
