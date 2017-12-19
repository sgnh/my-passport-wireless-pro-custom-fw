#!/bin/bash
#
# ï¿?2010 Western Digital Technologies, Inc. All rights reserved.
#
# updateFirmwareFromFile.sh <filename> [check_filesize]"
#

# prepare for starup all process
start_all_services()
{
    [ -e /etc/init.d/S55netatalk ]        && /etc/init.d/S55netatalk start 2>/dev/null
    [ -e /etc/init.d/S63vsftpd ]          && /etc/init.d/S63vsftpd start 2>/dev/null
    [ -e /etc/init.d/S80twonkyserver ]    && /etc/init.d/S80twonkyserver start 2>/dev/null
    [ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver start 2>/dev/null
    [ -e /etc/init.d/S85wdmcserverd ]     && /etc/init.d/S85wdmcserverd start 2>/dev/null
    [ -e /etc/init.d/S92wdnotifierd ]     && /etc/init.d/S92wdnotifierd start 2>/dev/null
    [ -e /etc/init.d/S85lld2d ]           && /etc/init.d/S85lld2d start 2>/dev/null
    [ -e /etc/init.d/S93crond ]           && /etc/init.d/S93crond start 2>/dev/null
    [ -e /etc/init.d/S95RestAPI ]         && /etc/init.d/S95RestAPI start 2>/dev/null
}

# prepare for shutdown process
shutdown_all_services()
{
    [ -e /etc/init.d/S96rsynchk ]         && /etc/init.d/S96rsynchk stop 2>/dev/null
    [ -e /etc/init.d/S95RestAPI ]         && /etc/init.d/S95RestAPI stop 2>/dev/null
    [ -e /etc/init.d/S93crond ]           && /etc/init.d/S93crond stop 2>/dev/null
    [ -e /etc/init.d/S92wdnotifierd ]     && /etc/init.d/S92wdnotifierd stop 2>/dev/null
    [ -e /etc/init.d/S85lld2d ]           && /etc/init.d/S85lld2d stop 2>/dev/null
    [ -e /etc/init.d/S85wdmcserverd ]     && /etc/init.d/S85wdmcserverd stop 2>/dev/null
    [ -e /etc/init.d/S80twonkyserver ]    && /etc/init.d/S80twonkyserver stop 2>/dev/null
    [ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver stop 2>/dev/null
    [ -e /etc/init.d/S63vsftpd ]          && /etc/init.d/S63vsftpd stop 2>/dev/null
    [ -e /etc/init.d/S55netatalk ]        && /etc/init.d/S55netatalk stop 2>/dev/null
}

update_progress()
{
     echo "upgrading $1" > /tmp/fw_update_status
     sleep 1
     cat /tmp/fw_update_status
}

plexupdate_progress()
{
     echo "upgrading $1" > /tmp/fw_update_status
     echo "upgrading $1" > /tmp/plexfw_update_status
     sleep 1
     cat /tmp/fw_update_status
     cat /tmp/plexfw_update_status
}

# post entries to updatelog
uplog()
{
    logtext=${@}
    logtag="`basename $0`:`date -u +"%D %T"`:"
    echo "${logtag}${logtext}" 2>&1 | tee -a ${updatelog}
}

# flag error after attempting to apply upgrade using dpkg
pre-update_error()
{
    errortext=${@}
    echo "Error fw_update_status: ${errortext}" 2>&1 | tee -a ${updatelog}
    echo  ${errortext} > /tmp/fw_update_status
    uplog ${errortext}
    rm -f ${FW_UPDATE_MUTEX}
    #send alert for firmware update fail
    sendAlert.sh 1003
    /usr/local/sbin/sendHWCollect.sh 102 UpdateFW Failed `cat /etc/version`
    sleep 1
    echo "11;0;" > /tmp/MCU_Cmd
    start_all_services
    exit 1
}

check_for_install_package()
{
    isInstallPackage=`file $1 | grep "gzip compressed data" | wc -l`
    if [ ${isInstallPackage} -eq 1 ]; then
        mkdir -p /CacheVolume/install_package
        plexupdate_progress 10
        tar xvfz $1 -C /CacheVolume/install_package
        plexupdate_progress 30
        result=$?
        if [ ${result} != "0" ]; then
            rm -Rf /CacheVolume/install_package
            pre-update_error "failed 200 \"invalid firmware package\""
        fi
        isValidPackage=`ls /CacheVolume/install_package | wc -l`
        if [ ${isValidPackage} -eq 1 ]; then
            PackageFullName=`ls /CacheVolume/install_package`
            PackageName=`echo ${PackageFullName} | cut -d "-" -f 1`
            #PackageVersion=`echo ${PackageFullName} | cut -d "-" -f 2-`
	    PackageVersion=`echo $1 | cut -d "-" -f 2- | sed 's/.bin.*//'`
            if [ -f /CacheVolume/install_package/${PackageFullName}/${PackageName}-install.sh ]; then
                plexupdate_progress 50
		rm -Rf /usr/local/${PackageName}
                /CacheVolume/install_package/${PackageFullName}/${PackageName}-install.sh /CacheVolume/install_package/${PackageFullName}
                rm -Rf /CacheVolume/install_package
                echo "${PackageName}:${PackageVersion}:$1:installed" > /etc/installed_packages/${PackageName}
                plexupdate_progress 90
            fi
            if [ -f /usr/local/sbin/packages/${PackageName}-install.sh ]; then
                plexupdate_progress 50
		rm -Rf /usr/local/${PackageName}
                /usr/local/sbin/packages/${PackageName}-install.sh /CacheVolume/install_package/${PackageFullName}
                rm -Rf /CacheVolume/install_package
                echo "${PackageName}:${PackageVersion}:$1:installed" > /etc/installed_packages/${PackageName}
                plexupdate_progress 90
            else
                rm -Rf /CacheVolume/install_package
                pre-update_error "failed 200 \"invalid firmware package\""
            fi
        else
            rm -Rf /CacheVolume/install_package
            pre-update_error "failed 200 \"invalid firmware package\""
        fi
        plexupdate_progress 100
        reboot
        exit 0
    fi
}

pre-update_error_50()
{
    errortext=${@}
    echo "Error fw_update_status: ${errortext}" 2>&1 | tee -a ${updatelog}
    echo  ${errortext} > /tmp/fw_update_status
    uplog ${errortext}
    rm -f ${FW_UPDATE_MUTEX}
    #send alert for firmware update fail
    sendAlert.sh 1618
    /usr/local/sbin/sendHWCollect.sh 102 UpdateFW FailedBatter50 `cat /etc/version`
    sleep 1
    echo "11;0;" > /tmp/MCU_Cmd
    start_all_services
    exit 1
}

# prepare for pkg upgrades
pkg_upgrade_init()
{
    #ledCtrl.sh LED_EV_FW_UPDATE LED_STAT_IN_PROG
    incUpdateCount.pm firmware_update
    
    ## - TODO: Use signal & run-levels
    ## Stop processes 
    #[ -e /etc/init.d/S99crond ]           && /etc/init.d/S99crond stop 2>/dev/null
    #[ -e /etc/init.d/S95lld2d ]           && /etc/init.d/S95lld2d stop 2>/dev/null
    #[ -e /etc/init.d/S95RestAPI ]         && /etc/init.d/S95RestAPI stop 2>/dev/null
    #[ -e /etc/init.d/S92wdnotifierd ]     && /etc/init.d/S92wdnotifierd stop 2>/dev/null
    #[ -e /etc/init.d/S92twonkyserver ]    && /etc/init.d/S92twonkyserver stop 2>/dev/null
    #[ -e /etc/init.d/S91smb ]             && /etc/init.d/S91smb stop 2>/dev/null
    #[ -e /etc/init.d/S85wdmcserverd ]     && /etc/init.d/S85wdmcserverd stop 2>/dev/null
    #[ -e /etc/init.d/S70vsftpd ]          && /etc/init.d/S70vsftpd stop 2>/dev/null
    #[ -e /etc/init.d/S50netatalk ]        && /etc/init.d/S50netatalk stop 2>/dev/null
    #[ -e /etc/init.d/S50avahi-daemon ]    && /etc/init.d/S50avahi-daemon stop 2>/dev/null
    sync
    sleep 2
    cat /etc/saveconfigfiles.txt | xargs tar cvf /etc/saveconfigfiles.tar
}

#
pkg_upgrade_exec()
{
    tar xvfz "${filename}" -C /tmp 2>&1
    if [ ! -f /tmp/fwupg_images/upgrade.sh ]; then
        update_error "failed 200 \"invalid firmware package\""
    fi
    /tmp/fwupg_images/upgrade.sh 2>&1 | tee -a ${updatelog}
    status=$?
}

# flag error after attempting to apply upgrade using dpkg
update_error()
{
    error=${1}
    echo  ${error} > /tmp/fw_update_status
    uplog ${error}
    echo "Error fw_update_status: ${error}" 2>&1 | tee -a ${updatelog}
    [ -z "${update_container}" ] && restoreRaid
    #ledCtrl.sh LED_EV_FW_UPDATE LED_STAT_OK
    rm -f ${FW_UPDATE_MUTEX}
    exit 1
}

pkg_upgrade_verify()
{
    cat ${updatelog} | grep -q "not a debian format archive"
    if [ $? -eq 0 ]; then
        update_error "failed 200 \"invalid firmware package\""
    fi
    
    cat ${updatelog} | grep -q "Install not supported"
    if [ $? -eq 0 ]; then
        update_error "failed 200 \"invalid firmware package\""
    fi
    
    cat ${updatelog} | grep -q "dpkg-deb: subprocess <decompress> returned error"
    if [ $? -eq 0 ]; then
        update_error "failed 202 \"upgrade download failure\""
    fi
    
    if [ ${status} -ne 0 ]; then
        echo "dkpg exited with non-zero status: ${status}"
        update_error "Update failed. Check ${updatelog} for details."
    fi
}

start_update_korra()
{
	#check battery power for update
	echo "12;0;" > /tmp/MCU_Cmd
	sleep 1
	AC=`cat /tmp/battery  | awk '{print $1}'`
	BatLevel=`cat /tmp/battery  | awk '{print $2}'`
	#if [ ${BatLevel} -lt 25 ]; then #under 25% , don't upgrade even in charging mode
	#    	error="failed 206 \"Upgrade failure due to Insufficient Power\""
        #	echo  ${error} > /tmp/fw_update_status                       
        #	pre-update_error $error
	#fi

	#if [ ${BatLevel} -lt 50 ]; then
	#if [ ${AC} == "discharging" ]; then
	#    	error="failed 206 \"Upgrade failure due to Insufficient Power\""
	#	echo  ${error} > /tmp/fw_update_status                       
	#	pre-update_error_50 $error
	#fi
	#fi

	tar xvf $1 updatefw -C /tmp/ || pre-update_error "failed 200 \"invalid firmware package\""

	[ -d /CacheVolume/ ] && rm -rf /CacheVolume/chktmp
	mount_ro=`mount | grep "/media/sdb1 " | grep "ro," | wc -l`
	if [ ${mount_ro} -eq 1 ]; then
		pre-update_error "failed 201 \"not enough space on device for upgrade\""
	fi
	mkdir -p /CacheVolume/chktmp
	tar xvf $1 -C /CacheVolume/chktmp
	cd /CacheVolume/chktmp/ && isFAIL=`md5sum -c fw.md5 | grep -c FAILED`
	[ $isFAIL -eq 1 ] && pre-update_error "failed 200 \"invalid firmware package\""
	isFW10045=`cat /CacheVolume/chktmp/fw.version | grep "1.00.45" | wc -l`
	if [ ${isFW10045} -eq 1 ]; then
		cp /usr/local/sbin/updatefw /tmp/updatefw
	fi
	isFromInternet=`echo $1| grep "/media/sdb1/.wdcache/update" | wc -l`
	if [ ${isFromInternet} -eq 0 ]; then
		if [ -d "/media/sdb1/.wdcache/update" ]; then
			touch /media/sdb1/.wdcache/update/UpdateDone
		fi
	fi
	RCmajorver="$FactoryFWVersion_Major"
	RCminorver="$FactoryFWVersion_Minor"
	HDDCapacity=`cat /tmp/HDDCapacity`
	if [ "$HDDCapacity" == "" ]; then
		HDDCapacity=4
	fi
	if [ "${HDDCapacity}"  == "4" ]; then
		version_newmajor=`cat /CacheVolume/chktmp/fw.version | awk -F. '{print $1}' | cut -d '_' -f 2`
		version_newminor=`cat /CacheVolume/chktmp/fw.version | awk -F. '{print $2}'`

		if [ "$RCmajorver" == "" ] || [ "$RCminorver" == "" ]; then
			if [ -f "/etc/FactoryFwVer" ]; then
				RCmajorver=`cat /etc/FactoryFwVer | awk -F. '{print $1}' | cut -d '_' -f 2`
				RCminorver=`cat /etc/FactoryFwVer | awk -F. '{print $2}'`	
			fi
		fi
		if [ "${version_newminor}" -lt "${RCminorver}" ]; then
			echo "cannot downgrade!!"
			error="failed 208 \"Cannot downgrade to anything older than the factory installed firmware\""
   	 		pre-update_error $error
		fi
	fi
	
	/tmp/updatefw $1
	echo "update done"
	exit
}
## section: main script

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/system.conf
#[ -f /usr/local/sbin/ledConfig.sh ] && . /usr/local/sbin/ledConfig.sh
filename=${1}
check_size=${2:-""}
test=${3:-""}
# check params
if [ $# -lt 1 ]; then
    echo "usage: updateFirmwareFromFile.sh <filename> [check_filesize]"
    exit 1
fi
if [ ! -f "${filename}" ]; then
    echo "File not found"
    exit 1
fi
/usr/local/sbin/sendHWCollect.sh 102 UpdateFW Start `cat /etc/version`
#check battery power for update
echo "12;0;" > /tmp/MCU_Cmd
AC=`cat /tmp/battery  | awk '{print $1}'`
BatLevel=`cat /tmp/battery  | awk '{print $2}'`
if [ ${BatLevel} -lt 50 ]; then
    if [ ${AC} == "discharging" ]; then
	    error="failed 206 \"Upgrade failure due to Insufficient Power\""
        echo  ${error} > /tmp/fw_update_status                       
        pre-update_error_50 $error
    fi
fi
# set a 'non-idle' status for the manual update-from-file case
[ ! -f /tmp/fw_update_status ] && echo "downloading" > /tmp/fw_update_status

# startup update process
#echo "10;0" >/tmp/MCU_Cmd &
shutdown_all_services
logtag="`basename $0`:`date -u +"%D %T"`:"
logger -s -t "${logtag}" "( $@ )"
echo "upgrading 0" > /tmp/fw_update_status
# initiate updatelog
updatelog="/CacheVolume/update.log"
echo "${logtag}upgrade start: $@" 2>&1 | tee ${updatelog}

FW_UPDATE_MUTEX=/tmp/fw_update_mutex
[ -f ${FW_UPDATE_MUTEX} ] && exit 0
touch ${FW_UPDATE_MUTEX}

uplog "check_size=${check_size}"

check_for_install_package $1

# Cleanup Cache file
echo 1 > /tmp/CacheMgrFile
echo 3 > /proc/sys/vm/drop_caches

#============================
#Backup current configurations
sync
sleep 2
cat /etc/saveconfigfiles.txt | xargs tar cvf /etc/saveconfigfiles.tar
#Run Korra Update !!!
start_update_korra $1
#============================

# check disk usage
fwUpdateSpace=`tar vtzf "${filename}" | awk '{SUM += $3} END {print SUM}'`
dfout=`df -B 1| grep /tmp`
avail=`echo "$dfout" | awk '{printf("%d",$2-$3)}'`
echo "${avail} ${fwUpdateSpace}"
if [ "${avail}" -lt "${fwUpdateSpace}" ]; then
    if [ -f /tmp/MountedDevNode ]; then
         dfout=`df -B 1| grep \`cat /tmp/MountedDevNode\``
         avail=`echo "$dfout" | awk '{printf("%d",$2-$3)}'`
         echo "${avail} ${fwUpdateSpace}"
         if [ "${avail}" -lt "${fwUpdateSpace}" ]; then
             error="failed 201 \"not enough space on device for upgrade\""
             echo  ${error} > /tmp/fw_update_status
             pre-update_error $error
         else
             if [ -d /CacheVolume/fwupg_images ]; then
                 rm -Rf /CacheVolume/fwupg_images
             fi
             mkdir -p /CacheVolume/fwupg_images
             ln -sf /CacheVolume/fwupg_images /tmp/fwupg_images
         fi
    else
        error="failed 201 \"not enough space on device for upgrade\""
        echo  ${error} > /tmp/fw_update_status
        pre-update_error $error
    fi
fi

if [ "${check_size}" != "" ] && [ "${test}" == "test_size" ]; then
    uplog "truncating file for size test..."
    blocksize_ls_original=$(ls -l ${filename} | cut -d' ' -f5)
    uplog "blocksize_ls_original=$blocksize_ls_original"
    dd if=${filename} of=${filename}-new bs=1M count=120
    mv ${filename}-new ${filename}
fi

# check file size if file was downloaded
if [ "${check_size}" != "" ]; then
    FileSize=( $(cat /tmp/fw_upgrade_filesize) )
    blocksize_dpkg0="${FileSize[0]}"
    blocksize_dpkg1="${FileSize[1]}"
    blocksize_ls=$(ls -l ${filename} | cut -d' ' -f5)
    uplog "blocksize_dpkg0=$blocksize_dpkg0"
    uplog "blocksize_dpkg1=$blocksize_dpkg1"
    uplog "blocksize_ls=$blocksize_ls"
    if [ "${blocksize_dpkg0}" != "${blocksize_ls}" ] && [ "${blocksize_dpkg1}" != "${blocksize_ls}" ]; then
        error="failed 202 \"failed download file size check\""
        pre-update_error "${error}"
    fi
fi

version_current=`cat /etc/version | tr -d .-`
#master_package_name=${modelNumber}
master_package_name=`echo AV1W`
version_newfile=`tar -xOzf "${filename}" fwupg_images/version | tr -d .-`
package_newfile=`tar -xOzf "${filename}" fwupg_images/package`

echo "upgrading 10" > /tmp/fw_update_status
# extract master package and update-container names
master_package_new=${package_newfile%%-*}
update_container=${package_newfile#*-}
update_container=${update_container%%-*}
[ "${master_package_name}" == "${update_container}" ] && update_container=''

uplog "version_current=$version_current"
uplog "version_newfile=$version_newfile"
uplog "package_newfile=$package_newfile"
uplog "master_package_name=$master_package_name"
uplog "master_package_new=$master_package_new"
uplog "update_container=$update_container"

# declare arithmetic variable types (ensure conversion to base 10)
let "vnew = $((10#$version_newfile))"
let "vnow = $((10#$version_current))"
if [ "${master_package_new}" == "wd.container" ] || [ "${master_package_new}" == "wd.group" ] || [ "${master_package_new}" == "wd.supergroup" ]; then
    uplog "Package compatiblities will be enforced by the incomming policy rules."
else
    # enforce same 'master-package' name
    if [ "${master_package_name}" != "${master_package_new}" ]; then
            error="failed 200 \"invalid firmware package\""
            pre-update_error $error
    fi
    # ITR#34229: don't allow down rev code to be applied
    # -but allow 'patch updates" with any version
    #if [ -z "${update_container}" ] && [ "${vnew}" -lt "${vnow}" ]; then
    #        error="failed 200 \"invalid firmware package\""
    #        pre-update_error $error
    #fi
fi

status=1

# Prepare for package upgrade
pkg_upgrade_init
# Do pkg upgrades
pkg_upgrade_exec
# Verify upgrade
pkg_upgrade_verify

sendAlert.sh 2004 $version_newfile

rm -f /etc/.fw_upgrade_alert
rm -f /etc/.fw_update_alert
# Unmount & reboot
rm -f ${FW_UPDATE_MUTEX}
rm /media/sdb1/.wdcache/.wd-alert/wd-alert-desc.db
#umount -f /DataVolume
#umount -f /media/sdb1
#umount -f /media/sda1

# sleep 10 seconds to allow UI to detect update
#sleep 10
#reboot -f -h -i &

exit ${status}
