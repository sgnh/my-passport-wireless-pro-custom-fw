#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# schedulerRemove.sh <schedule_name> <command>
# 
# remove all schedules for a given command
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ $# != 2 ]; then
	echo "usage: schedulerRemove.sh <schedule_name> <command>"
	exit 1
fi

schedule_name=$1
command=$2

conf="/etc/cron.d/${schedule_name}"

if [ ! -f $conf ]; then
	echo "Schedule ${schedule_name} not found"
	exit 1
fi

schedulerExists.sh "$schedule_name" "$command"
if [ "$?" != "0" ]; then
	exit 1
fi

tmpfile=`mktemp`
cat $conf | grep -vw "$command" > $tmpfile
mv $tmpfile $conf
/etc/init.d/cron reload > /dev/null
