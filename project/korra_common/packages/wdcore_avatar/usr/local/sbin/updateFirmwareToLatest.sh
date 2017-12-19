#!/bin/bash
#
# � 2013 Western Digital Technologies, Inc. All rights reserved.
#
# updateFirmwareToLatest.sh reboot | {imagelink} | {imagelink} download | install
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf
#[ -f /usr/local/sbin/ledConfig.sh ] && . /usr/local/sbin/ledConfig.sh


logtag="`basename $0`:`date -u +"%D %T"`:"
logger -s -t "${logtag}" "( $@ )"

OPT_REBOOT=""
OPT_LINK=""
OPT_AUTO=""

echo ${1} ${2} > /tmp/updateToLatest

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


FW_DOWNLOAD_MUTEX=/tmp/newfw_download_mutex
CHECK_FILESIZE="check_filesize"

[ -f ${FW_DOWNLOAD_MUTEX} ] && exit 0
touch ${FW_DOWNLOAD_MUTEX}

if [ -z "${OPT_LINK}" ]; then
    if [ -s "${upgrade_link}" ]; then
        cat "${upgrade_link}" > /tmp/update_url
    else
        logger -s -t "$0" "no upgrade"
        rm -f ${FW_DOWNLOAD_MUTEX}
        exit 1;
    fi
else
    echo "${OPT_LINK}" > /tmp/update_url
	CHECK_FILESIZE=""
fi

update_site=`cat /etc/fwupdate.conf`
model=$modelNumber
current_version=`cat /etc/version`
newfwversion=`cat /tmp/fw_upgrade_version`
update_file="/var/tmp/updateFile.deb"

# delete any old update files
rm -f ${update_file}

# check disk usage
fwUpdateSpace=`echo 209715200`
dfout=`df -B 1 /var/tmp | sed -e /Filesystem/d`
avail=`echo "$dfout" | awk '{print $2-$3}'`
if [ "${avail}" -lt "${fwUpdateSpace}" ] ; then
    error="failed 201 \"not enough space on device for upgrade\""
    echo  ${error} > /tmp/fw_update_status
    echo ${error} 
    rm -f ${FW_DOWNLOAD_MUTEX}
    exit 1
fi

if [ "$OPT_AUTO" == "" ]; then
	echo "downloading" > /tmp/fw_update_status
	sleep 1
fi

if [ "${newfwversion}" != "" ]; then
	if [ -f /media/sdb1/.wdcache/update/MyPassportWirelessGen2_${newfwversion}.bin ]; then
		cp /media/sdb1/.wdcache/update/MyPassportWirelessGen2_${newfwversion}.bin ${update_file}
		touch /media/sdb1/.wdcache/update/UpdateDone
	else
		curl -4 "`cat /tmp/update_url`" > ${update_file} 2>/tmp/fw_download_status
		status=$?		
		if [ $status != 0 ]; then
			# set error status for update errors
			error="failed 202 \"failed to get FW link for upgrade\""
			echo  ${error} > /tmp/fw_update_status
			echo ${error} 
			rm -f /tmp/update_url
			rm -f ${update_file}
			rm -f ${FW_DOWNLOAD_MUTEX}
			exit $status
		fi
	fi
fi


# check that update_file actually exists before starting update sequence
if [ -s ${update_file} ]; then
    #ledCtrl.sh LED_EV_FW_UPDATE LED_STAT_IN_PROG
    #send alert for firmware downloaded
    clearAlerts.sh 1011
    sendAlert.sh 1600
    echo "" > /FWupgfromInternet
    if [ "$OPT_AUTO" == "" ]; then
    	clearAlerts.sh 1600
    	/usr/local/sbin/sendHWCollect.sh 102 AutoUpdate Start `cat /etc/version`
    	updateFirmwareFromFile.sh ${update_file} ${CHECK_FILESIZE}
    fi
    status=$?
fi 

if [ "$OPT_AUTO" == "1" ]; then
	if [ ! -d "/media/sdb1/.wdcache/update" ]; then
		mkdir -p /media/sdb1/.wdcache/update
		chmod 777 -R /media/sdb1/.wdcache/update
	else
		if [ -f "/media/sdb1/.wdcache/update/UpdateDone" ]; then
			rm /media/sdb1/.wdcache/update/UpdateDone
		fi
	fi

	newfwversion=`cat /tmp/fw_upgrade_version`
	mv -f ${update_file} /media/sdb1/.wdcache/update/MyPassportWirelessGen2_${newfwversion}.bin
	rm -f /tmp/update_url
	rm -f ${FW_DOWNLOAD_MUTEX}

	rm -f /etc/.fw_upgrade_alert
	rm -f /etc/.fw_update_alert
else
 	rm -f /tmp/update_url
	rm -f ${update_file}
	rm -f ${FW_DOWNLOAD_MUTEX}
	if [ $status == 0 ]; then
    	if [ "${OPT_REBOOT}" == "reboot" ]; then
        	reboot
    	fi
	fi
fi

exit $status
