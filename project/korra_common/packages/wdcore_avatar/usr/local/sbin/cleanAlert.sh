#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# cleanAlert.sh - cleans up the alert sqlite3 database by time and/or number of entries
#
# Note: alert codes /etc/alert-param.sh
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#. /etc/nas/alert-param.sh

alertdb="/CacheVolume/.wd-alert/wd-alert.db"
rc=0
numskeep=2000 #number of latest alert entries to keep
interval=2592000 # 30 days
limitsize=5242880 # 5 MB
corruptrc=11 # sqlite3 corrupt return code

if [ ! -s "${alertdb}" ]; then
    logger -s "cleanAlert.sh: db file: ${alertdb} does not exist"
    exit 1
fi

### due to db locking, none of the below cleanups will be guaranteed to run ###
### Remove alert entries that are older than 30 dayts ###

now=`date +%s` # get current epoch

removetime=`expr ${now} - ${interval}`

sqlite3 "${alertdb}" "DELETE FROM AlertHistory WHERE log_time < datetime(${removetime}, 'unixepoch')"
rc=$? # also used to determine if database is corrupted
[ "${rc}" != "0" ] && logger -s "cleanAlert.sh: entries expiration failed with exit code: ${rc}"

### Remove alert entires not of recent 2000 entries ###

count=`sqlite3 "${alertdb}" "SELECT COUNT(id) FROM AlertHistory"`

if [ $count -gt $numskeep ]; then
    logger -s "cleanAlert.sh: database exceeds max entries count: ${count}. keeping only ${numskeep} entries."
    sqlite3 "${alertdb}" "DELETE FROM AlertHistory WHERE id <= (SELECT id FROM AlertHistory ORDER BY id DESC LIMIT 1 OFFSET ${numskeep})"
    rc=$?
    [ "${rc}" != "0" ] && logger -s "cleanAlert.sh: entries deletion failed with exit code: ${rc}"
fi

### Run the sqlite3 VACUUM command to reduce the database freelist and fragmentation if size is larger than 5MB ###

dbsize=`stat -c %s "${alertdb}"`

if [ $dbsize -gt $limitsize ]; then
    logger -s "cleanAlert.sh: database exceeds size limit: ${limitsize}. performing vacuum operation."
    sqlite3 "${alertdb}" "VACUUM"
    rc=$?
    [ "${rc}" != "0" ] && logger -s "cleanAlert.sh: vacuum operation failed with exit code: ${rc}"
fi

### Delete and restore the database file if the database is detected to be corrutped ###

if [ "${rc}" == "${corruptrc}" ]; then
    logger -s "cleanAlert.sh: database corruption detected. restoring database."
    rm "${alertdb}"
    cp "/etc/wdcomp.d/alerts/saved_settings/${alertdb}" "${alertdb}"
    chown root:www-data "${alertdb}"
    chmod 775 "${alertdb}"
    exit 2
fi

exit $rc
