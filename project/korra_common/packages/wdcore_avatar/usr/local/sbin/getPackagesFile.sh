#!/bin/bash
#
# � 2016 Western Digital Technologies, Inc. All rights reserved.
#
# getPackagesStatus.sh <packagename>
#
# Gets current package status
# Return: notfound,downloading,downloaded,installed
#

#---------------------


# Include conf.
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#---------------------
# Begin Script
#---------------------

packageName=$1

if [ $# != 1 ]; then
	echo "usage: getPackagesStatus.sh <packagename>"
	exit 1
fi

if [ ! -f /etc/installed_packages/${packageName} ]; then
# Comment this command because of restapi doesn't want it
	echo "notfound"
	exit 1
fi

cat /etc/installed_packages/${packageName}|cut -d ":" -f 3

#---------------------
# End Script
#---------------------

