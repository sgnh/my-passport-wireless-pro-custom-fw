#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# Get the apache https servername
#Usage:
#  getServerName.sh
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/wdcomp.d/apache-php-webdav/apache-php-webdav.conf 2> /dev/null

cat ${SERVER_NAME_CONFIG} | awk '/ServerName/{ print $2 }'

exit 0
