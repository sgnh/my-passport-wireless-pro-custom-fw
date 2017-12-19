#!/bin/bash
#
# getNewPlexFirmwareUpgrade.sh <immediate>
#
# returns:
#  "<version>"
# -OR-
# "no upgrade"
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin


# see share-param.sh
upgrade_link="/tmp/plexfw_upgrade_link"
#logtag=$(basename $0)
#logger -s -t "$logtag" "begin script: $@"

server_msg="/tmp/dev_plexfw_upgrade_link"
fw_upgrade="/tmp/plexfw_upgrade_info"
update_site=`cat /etc/plexfwupdate.conf`
current_version=`/usr/local/sbin/getPackagesVersion.sh plexmediaserver`

# clear old files from aborted update attempts
rm -f ${server_msg}

if [ "$1" != "immediate" ]; then
    if [ -f ${fw_upgrade} ]; then
        cat ${fw_upgrade}
    else
        echo "\"no upgrade\""
    fi
    exit 0
fi
update_query="${update_site}"
curl -k "$update_query" > ${server_msg} 2>/dev/null

Version=`cat ${server_msg} | grep "Release id" | sed -n 's/.*version="\([^"]*\)".*/\1/p'```

if [ "${Version}" == "" ]; then 
    isUpgrade='false'
else
    isUpgrade='true'
fi

echo $Version > /tmp/plexfw_upgrade_version

# first check that server_msg file exists and is not empty
if [ -s ${server_msg} ]; then
    if [ "${isUpgrade}" == 'false' ]; then
        echo "\"no upgrade\"" | tee ${fw_upgrade}
    else
        if [ "${current_version}" != "${Version}" ]; then
            echo "${Version}" | tee ${fw_upgrade}
        else
            echo "\"no upgrade\"" | tee ${fw_upgrade}
	fi
    fi
else
    echo "\"error\"" | tee ${fw_upgrade}
    # disable auto-update
    rm -f ${upgrade_link}
fi

