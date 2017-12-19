#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# schedulerGet.sh <schedule_name> <command>
#
# Get all schedules for a given command.  Return error code of 1 if no schedules exist.
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ $# != 2 ]; then
	echo "usage: schedulerGet.sh <schedule_name> <command>"
	exit 1
fi

schedule_name=$1
command=$2

conf="/etc/cron.d/${schedule_name}"

if [ ! -f $conf ]; then
	echo "Schedule ${schedule_name} not found"
	exit 1
fi

cat $conf | grep -w "$command"
if [ "$?" == "0" ]; then
	exit 0
else
	exit 1
fi
