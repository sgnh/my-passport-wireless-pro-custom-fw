#!/bin/sh
#
# � 2011 Western Digital Technologies, Inc. All rights reserved.
#
# restoreSettingsFromDir.sh <directory>  
#
# Restore settings from a given directory.  Directory MUST reside in OS partition (cannot be in DataVolume).
# Note that the directory should have the restore files in the proper relative locations for restore.
#
#---------------------
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

logger -s -t "$(basename $0)" "begin script: $@"

. /etc/system.conf
. /etc/nas/config/wd-nas.conf 2>/dev/null

SOURCE_DIR=${1}

if [ $# != 1 ]; then
	echo "usage: restoreSettingsFromDir.sh <directory>"
	echo "		<directory> = restore directory"
	exit 1
fi

if [ ! -d ${SOURCE_DIR} ]; then
	echo "Directory ${SOURCE_DIR} does not exist"
	exit 1
fi

# save directory in trigger file
echo ${SOURCE_DIR} > ${RESTORE_SETTINGS_FROM_DIR_TRIGGER}