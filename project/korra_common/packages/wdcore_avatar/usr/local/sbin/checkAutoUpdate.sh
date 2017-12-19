#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# checkAutoUpdate.sh
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf

conf="/etc/auto_update.conf"
au_checked_day=/tmp/au_checked_day
upgrade_link=`cat /tmp/fw_upgrade_link`

if [ -f $conf ]; then
	source $conf
	if [ "$au_enable" == "enable" -o "$au_enable" == "true" ]; then
		current_day=`date +%u`
		#if [ ! -f $au_checked_day ] || [ "`cat $au_checked_day`" != "$current_day" ]; then
		#	current_hour=$((`date +%k`))
		#	if [ "$current_hour" == "$au_hour" ]; then
		#		if [ "$au_day" == "0" ] || [ "$current_day" == "$au_day" ]; then
					logger -s "Trigger auto-update"
		#			echo $current_day > $au_checked_day
					updateFirmwareToLatest.sh "${upgrade_link}" "AutoUpdate"
		#		fi
		#	fi
		#fi
	fi		
fi
