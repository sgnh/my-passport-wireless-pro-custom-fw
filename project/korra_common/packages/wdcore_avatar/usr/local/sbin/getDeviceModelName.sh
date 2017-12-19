#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getDeviceModelName.sh 
#
#


#---------------------
# add stderr to stdout
exec 2>&1

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

source /etc/system.conf && echo "${modelName}"

