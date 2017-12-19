#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# scheduleAdd.sh <schedule_name> <command> <minute> <hour> <day> <month> <day_of_week>
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ $# != 7 ]; then
	echo "usage: scheduleAdd.sh <schedule_name> <command> <minute> <hour> <day> <month> <day_of_week>"
	exit 1
fi

schedule_name=$1
command=$2
min=$3
hour=$4
dom=$5
mon=$6
dow=$7

validNum()
{
	# Return 0 if valid, 1 if not. Specify number and maxvalue as args
	num=$1  max=$2
	
	if [ "$num" = "X" ]; then
		return 0
	elif [ ! -s $(echo $num | sed 's/[[:digit:]]//g') ]; then
		return 1
	elif [ $num -lt 0 -o $num -gt $max ]; then
		return 1
	else
		return 0
	fi
}

validDay()
{
	# Return 0 if a valid dayname, 1 otherwise
	case $(echo $1 | tr '[:upper:]' '[:lower:]') in
		sun*|mon*|tue*|wed*|thu*|fri*|sat*) return 0 ;;
		X) return 0 ;;
		*) return 1
	esac
}

validMon()
{
	# Return 0 if a valid month name, 1 otherwise
	case $(echo $1 | tr '[:upper:]' '[:lower:]') in
		jan*|feb*|mar*|apr*|may|jun*|jul*|aug*) 	return 0 ;;
		sep*|oct*|nov*|dec*) 						return 0 ;;
		X) return 0 ;;
		*) return 1
	esac
}

fixvars()
{
	# Translate all '*' into 'X' to bypass shell expansion hassles
	sourceline="${min} ${hour} ${dom} ${mon} ${dow} root ${command}"
	min=$(echo "$min" | tr '*' 'X')
	hour=$(echo "$hour" | tr '*' 'X')
	dom=$(echo "$dom" | tr '*' 'X')
	mon=$(echo "$mon" | tr '*' 'X')
	dow=$(echo "$dow" | tr '*' 'X')
}

fixvars

# minute check
for minslice in $(echo "$min" | sed 's/[,-]/ /g') ; do
	if ! validNum $minslice 60 ; then
		echo "Invalid minute value \"$minslice\""
		exit 1
	fi
done

# hour check
for hrslice in $(echo "$hour" | sed 's/[,-]/ /g') ; do
	if ! validNum $hrslice 24 ; then
		echo "Invalid hour value \"$hrslice\""
		exit 1
	fi
done

# day of month check
for domslice in $(echo "$dom" | sed 's/[,-]/ /g') ; do
	if ! validNum $domslice 31 ; then
		echo "Invalid day of month value \"$domslice\""
		exit 1
	fi
done

# month check
for monslice in $(echo "$mon" | sed 's/[,-]/ /g') ; do
	if ! validNum $monslice 12 ; then
		if ! validMon "$monslice" ; then
			echo "Invalid month value \"$monslice\""
			exit 1
		fi
	fi
done

# day of week check
for dowslice in $(echo "$dow" | sed 's/[,-]/ /g') ; do
	if ! validNum $dowslice 7 ; then
		if ! validDay "$dowslice" ; then
			echo "Invalid day of week value \"$dowslice\""
			exit 1
		fi
	fi
done

conf="/etc/cron.d/${schedule_name}"

echo "${sourceline}" >> ${conf}

if [ $? != "0" ]; then
	"fail to save schedule"
	exit $?
fi

/etc/init.d/cron reload > /dev/null
