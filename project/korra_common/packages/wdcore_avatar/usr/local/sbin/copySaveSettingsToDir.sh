#!/bin/sh
#
# � 2011 Western Digital Technologies, Inc. All rights reserved.
#
# copySaveSettingsToDir.sh <directory>
#
# Copy save settings to given <directory>
#

#---------------------
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/system.conf
. /etc/nas/config/wd-nas.conf 2>/dev/null

directory=${1}
mkdir -p ${directory}

if [ "$#" == "0" ]; then
	echo "usage: copySaveSettingsToDir.sh <dest_directory>"
	echo "		<dest_directory> = destination directory"
	exit 1
fi

TMP_FILE=`mktemp`
getSaveSettingsList.sh all > ${TMP_FILE}
while read line
do
	mkdir -p ${directory}/`dirname ${line}`
	cp -av "${line}" "${directory}/${line}"
done < ${TMP_FILE}
rm ${TMP_FILE}
