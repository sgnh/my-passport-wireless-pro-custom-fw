#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# schedulerExists.sh <schedule_name> <command>
#
# Returns exit code of 0 if the schedule exists, otherwise exit code of 1 if it does not exist
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ $# != 2 ]; then
	echo "usage: schedulerExists.sh <schedule_name> <command>"
	exit 1
fi

schedulerGet.sh "$1" "$2" > /dev/null

