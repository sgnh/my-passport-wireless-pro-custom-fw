#!/bin/bash
#
# (c) 2012 Western Digital Technologies, Inc. All rights reserved.
#
# enableLocalSwap.sh <swapLocation> <sizeMB>
#
# <sizeMB> - size of swap file in MB. 
#
# returns "enabled" to stdout if swap created
#

#---------------------
# add stderr to stdout
exec 2>&1

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/system.conf

defaultLocation="/DataVolume/cache"
swapLocation=${1:-"/DataVolume/cache"}
size=${2:-"220"}
swapFile="${swapLocation}/swapfile"

createSwapFile()
{
	if [ ! -f ${swapFile} ]; then
		logger -s "Creating ${size}MB swap file on ${swapFile}"
		dd if=/dev/zero of=${swapFile} bs=1M count=$size 2>/dev/null
		chmod 0600 $swapFile
		mkswap $swapFile
	fi
}

[ "${swap_enable}" == "false" ] && exit 1
system_ram=`cat /proc/meminfo | awk '/MemTotal:/ {print $2}'`
[ "${system_ram}" -gt "500000" ] && exit 1

if [ "${swapLocation}" != "${defaultLocation}" ]; then
	swapon -s | grep -q "/var/media"
	already_enable=$?
	if [ "${already_enable}" != "0" ] && [ -f "${swapLocation}/swap_enable" ]; then
		createSwapFile
		logger -s "Enabling swapfile on ${swapFile}"
		swapon ${swapFile}
		swapoff "${defaultLocation}/swapfile"
		exit 0
	fi
else
	createSwapFile
	logger -s "Enabling swapfile on ${swapFile}"
	swapon ${swapFile}
	exit 0
fi
exit 1


