#!/bin/bash
#
# � 2011 Western Digital Technologies, Inc. All rights reserved.
#
# isFactoryFresh.sh
#
# returns exit code 0 if factory fresh, exit code 1 if not
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/wd-nas.conf 2>/dev/null
. /etc/system.conf
. ${REST_API_ROOT}/config/globalconfig.ini 2> /dev/null

# NOTE: this should eventually be moved to /etc/nas/config/dlna-access.conf
ACCESS_DB_PATH="/shares/Public/.nflc_data"
MEDIA_CRAWLER_DB_PATH=".wdmc"
WD_PHOTOS_PATH=".wdphotos"

FOUND=/tmp/file_found
rm -f ${FOUND}

# ignore files in backups
find $BACKUPS_PATH -type f -exec touch ${FOUND} \; -print -quit
if [ -f ${FOUND} ]; then
        echo "Backup file found, Not factory fresh"
        exit 1
fi

# check if files found in /shares, ignore hidden files and files in SOFTWARE_PATH and media crawer db
find $WD_SHARES_PATH -type f \( -iname ".*" \) -prune \
                                -o -wholename $SOFTWARE_PATH -prune \
                -o -wholename $WD_SHARES_PATH/$MEDIA_CRAWLER_DB_PATH -prune \
                -o -wholename $ACCESS_DB_PATH -prune \
                -o -wholename ${WD_SHARES_PATH}/$WD_PHOTOS_PATH -prune \
                                -o -type f -exec touch ${FOUND} \; -print -quit
if [ -f ${FOUND} ]; then
        echo "Share file found, Not factory fresh"
        exit 1
fi

echo "Factory fresh"
exit 0
