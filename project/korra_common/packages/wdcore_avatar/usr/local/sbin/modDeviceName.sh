#! /bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
#Script used to change host name and description.
#Usage:
#  machineName.sh Newname 'A nice description of machine'
#
# NOTE:  Caller to do all input validation
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf


if [ $# != 2 ]; then
	echo "usage: modDeviceName.sh <devicename> <devicedescription>"
	exit 1
fi
currentDeviceName=`hostname`
currentDeviceDescription=`getDeviceDescription.sh`
if [ "$1" == "$currentDeviceName" ] && [ "$2" == "$currentDeviceDescription" ]; then
	exit 0
fi

# Make changes

sed -e '/netbios name/s/\(.*=\)\(\s*\)\(.*$\)/\1\2'"${1}"'/' \
    -e '/server string/s/\(.*=\)\(\s*\)\(.*$\)/\1\2'"${2}"'/' $sambaConfig > $sambaConfig-new
if [ $? != 0 ]; then
    exit 1
fi

echo "${1}" >/etc/hostname
/bin/hostname "${1}"

# Replace config files
mv -f $sambaConfig-new $sambaConfig

# update /etc/hosts
genHostsConfig.sh

# Restart services
renice 0 -p $$
# wait for networking to finish before reporting OK
/etc/init.d/S35network restart

# other services can be backgrounded
/etc/init.d/S50avahi-daemon restart
/etc/init.d/S75smb restart
/etc/init.d/S77upnp restart
/etc/init.d/S55netatalk restart
#/etc/init.d/upnp_nas restart
## Backed out lltd restart.  This causes web UI to disconnect during device name change, and hang.
##/etc/init.d/lltd restart
#daemon -U -X rescanItunes.sh

if [ -x /usr/local/sbin/modDlnaDeviceName.sh ]; then
    /usr/local/sbin/modDlnaDeviceName.sh $@
fi

exit 0
