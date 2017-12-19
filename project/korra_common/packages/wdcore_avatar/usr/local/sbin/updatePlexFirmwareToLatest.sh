#!/bin/bash
#
# � 2016 Western Digital Technologies, Inc. All rights reserved.
#
# updatePlexFirmwareToLatest.sh reboot | {imagelink} | {imagelink} download | install
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin


logtag="`basename $0`:`date -u +"%D %T"`:"
logger -s -t "${logtag}" "( $@ )"

OPT_REBOOT=""
OPT_LINK=""
OPT_AUTO=""

echo ${1} ${2} > /tmp/updatePlexToLatest

if [ "${1}" == "reboot" ]; then
    OPT_REBOOT='true'
    OPT_LINK="${2}"
else
    OPT_LINK="${1}"
    if [ "${2}" == "reboot" ]; then
        OPT_REBOOT='true'
    elif [ "${2}" == "AutoUpdate" ]; then
    	OPT_AUTO=1
    fi
fi

query_site=`cat /etc/plexfwupdate.conf`
echo "${query_site}" > /tmp/plexquery_url
#curl -k "https://plex.tv/downloads/details/1?build=linux-ubuntu-x86_64&distro=ubuntu" > /tmp/plexupdateinfo 2>/dev/null
curl -k "`cat /tmp/plexquery_url`" > /tmp/plexupdateinfo 2>/dev/null
status=$?
if [ $status != 0 ]; then
    rm -f /tmp/plexupdateinfo
    exit 1    
fi
fileHash=`cat /tmp/plexupdateinfo | grep "Package manifest" | sed -n 's/.*fileHash="\([^"]*\)".*/\1/p'```
fileName_temp=`cat /tmp/plexupdateinfo | grep "Package manifest" | sed -n 's/.*fileName="\([^"]*\)".*/\1/p'```
fileName=`echo ${fileName_temp} | sed -e 's/_/-/g'`
url=`cat /tmp/plexupdateinfo | grep "Package manifest" | sed -n 's/.*url="\([^"]*\)".*/\1/p'```
version=`cat /tmp/plexupdateinfo | grep "Release id" | sed -n 's/.*version="\([^"]*\)".*/\1/p'```
fixed=`cat /tmp/plexupdateinfo | grep "Release id" | sed -n 's/.*fixed="\([^"]*\)".*/\1/p'```
current_version=`/usr/local/sbin/getPackagesVersion.sh plexmediaserver`

echo "${version}"
echo "${fileName}"
echo "${fileHash}"
echo "${url}"
echo "${fixed}"
rm -f /tmp/plexupdateinfo

if [ "${version}" == "" ] || [ "${fileName}" == "" ] || [ "${url}" == "" ] || [ "${fileHash}" == "" ]; then
    exit 1
fi

if [ "${current_version}" == "${version}" ]; then
    if [ -f "${update_file}" ]; then
        exit 0
    fi
fi

FW_DOWNLOAD_MUTEX=/tmp/fw_download_mutex
CHECK_FILESIZE="check_filesize"

[ -f ${FW_DOWNLOAD_MUTEX} ] && exit 0
touch ${FW_DOWNLOAD_MUTEX}

update_site=${url}
echo "${update_site}" > /tmp/plexupdate_url
update_file="/CacheVolume/plexmediaserver-${version}.bin"
update_file_temp="/CacheVolume/temp_plexmediaserver-${version}.bin"

# delete any old update files
rm -f ${update_file_temp}

# check disk usage
fwUpdateSpace=`echo 209715200`
dfout=`df -B 1 /var/tmp | sed -e /Filesystem/d`
avail=`echo "$dfout" | awk '{print $2-$3}'`
if [ "${avail}" -lt "${fwUpdateSpace}" ] ; then
    error="plex_failed 201 \"not enough space on device for upgrade\""
    echo  ${error} > /tmp/fw_update_status
    echo ${error} 
    rm -f ${FW_DOWNLOAD_MUTEX}
    exit 1
fi

if [ "$OPT_AUTO" == "" ]; then
	echo "plex_downloading" > /tmp/fw_update_status
	sleep 1
fi
if [ ! -f ${update_file} ]; then
    curl -k "`cat /tmp/plexupdate_url`" > ${update_file_temp} 2>/tmp/fw_download_status
    status=$?
    download_Filehash=`sha1sum ${update_file_temp} | cut -d " " -f 1`
    if [ $status != 0 ] || [ "${fileHash}" != "${download_Filehash}" ]; then
        # set error status for update errors
        error="plex_failed 205 \"failed to get FW link for upgrade\""
        echo  ${error} > /tmp/fw_update_status
        echo ${error} 
        rm -f /tmp/plexupdate_url
        rm -f ${update_file}
        rm -f ${FW_DOWNLOAD_MUTEX}
        exit $status
    fi
    mv ${update_file_temp} ${update_file}
fi
echo "idle" > /tmp/fw_download_status
echo "plex_downloaded" > /tmp/fw_update_status
PackageName=`ls ${update_file} | cut -d "-" -f 1 | cut -c 14-`
#PackageVersion=`ls ${update_file} | cut -d "-" -f 2-`
PackageVersion="${version}"
echo "${PackageName}:${PackageVersion}:${update_file}:downloaded" > /etc/installed_packages/${PackageName}

# check that update_file actually exists before starting update sequence
if [ -s ${update_file} ] && [ "$1" == "install" ]; then
    if [ "$OPT_AUTO" == "" ]; then
    	updatePlexFirmwareFromFile.sh
    fi
    status=$?
    rm -f ${FW_DOWNLOAD_MUTEX}
fi 

exit $status
