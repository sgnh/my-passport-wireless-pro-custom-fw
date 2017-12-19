#!/bin/sh
#
# upgrade.sh
#

updatelog="/CacheVolume/update.log"
FW_UPDATE_MUTEX="/tmp/fw_update_mutex"

# post entries to updatelog
uplog()
{
    logtext=${@}
    logtag="`basename $0`:`date -u +"%D %T"`:"
    echo "${logtag}${logtext}" 2>&1 | tee -a ${updatelog}
}

# flag error after attempting to apply upgrade using dpkg
update_error()
{
    errortext=${@}
    echo "Error fw_update_status: ${errortext}" 2>&1 | tee -a ${updatelog}
    echo  ${errortext} > /tmp/fw_update_status
    uplog ${errortext}
    rm -f ${FW_UPDATE_MUTEX}
    #send alert for firmware update fail
    sendAlert.sh 1003
    sleep 1
    echo "11;0;" > /tmp/MCU_Cmd
    if [ -f "/usr/local/sbin/killService.sh" ]; then
        /usr/local/sbin/killService.sh hddup
        killall tee
    fi
    if [ "${filename}" != "" ]; then
        isFromWebUI=`echo "${filename}" | grep "/CacheVolume" | wc -l`
        if [ ${isFromWebUI} -eq "1" ]; then
            rm -f ${filename}
        fi
    fi
    exit 1
}
echo "upgrading 15" > /tmp/fw_update_status

if [ -f /CacheVolume/update.log ]; then
    filename=`cat /CacheVolume/update.log | grep "upgrade start: " | sed -n -e 's/^.*upgrade start: //p'`
    gunzip -t "${filename}"
    if [ $? != "0" ]; then
        error="failed 200 \"invalid firmware package\""
        update_error $error
        exit 1
    fi
fi
if [ ! -f /tmp/fwupg_images/checklist ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
else
    cd /tmp/fwupg_images/
    md5sum -c checklist
    if [ $? != "0" ]; then
        error="failed 200 \"invalid firmware package\""
        update_error $error
        exit 1
    fi
    cd /
fi

upgrademd5=`md5sum /tmp/fwupg_images/upgrade.sh | cut -c 1-32`
fileupgrademd5=`cat /tmp/fwupg_images/upgrade.sh.md5`
MLOmd5=`md5sum /tmp/fwupg_images/MLO | cut -c 1-32`
fileMLOmd5=`cat /tmp/fwupg_images/MLO.md5`
ubootmd5=`md5sum /tmp/fwupg_images/u-boot.img | cut -c 1-32`
fileubootmd5=`cat /tmp/fwupg_images/u-boot.img.md5`
uImagemd5=`md5sum /tmp/fwupg_images/uImage | cut -c 1-32`
fileuImagemd5=`cat /tmp/fwupg_images/uImage.md5`
rootfsmd5=`md5sum /tmp/fwupg_images/rootfs.cpio | cut -c 1-32`
filerootfsmd5=`cat /tmp/fwupg_images/rootfs.cpio.md5`
uImageupdatemd5=`md5sum /tmp/fwupg_images/uImage-update | cut -c 1-32`
fileuImageupdatemd5=`cat /tmp/fwupg_images/uImage-update.md5`
versionmd5=`md5sum /tmp/fwupg_images/version | cut -c 1-32`
fileversionmd5=`cat /tmp/fwupg_images/version.md5`
version_packagesmd5=`md5sum /tmp/fwupg_images/version.packages | cut -c 1-32`
fileversion_packagesmd5=`cat /tmp/fwupg_images/version.packages.md5`
version_buildtimemd5=`md5sum /tmp/fwupg_images/version.buildtime | cut -c 1-32`
fileversion_buildtimemd5=`cat /tmp/fwupg_images/version.buildtime.md5`
AsmSataFwmd5=`md5sum /tmp/fwupg_images/AsmSataFw.bin | cut -c 1-32`
fileAsmSataFwmd5=`cat /tmp/fwupg_images/AsmSataFw.bin.md5`

if [ "${upgrademd5}" != "${fileupgrademd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi

if [ "${MLOmd5}" != "${fileMLOmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${ubootmd5}" != "${fileubootmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${AsmSataFwmd5}" != "${fileAsmSataFwmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${uImagemd5}" != "${fileuImagemd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${rootfsmd5}" != "${filerootfsmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${uImageupdatemd5}" != "${fileuImageupdatemd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${versionmd5}" != "${fileversionmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${version_packagesmd5}" != "${fileversion_packagesmd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi
if [ "${version_buildtimemd5}" != "${fileversion_buildtimemd5}" ]; then
    error="failed 200 \"invalid firmware package\""
    update_error $error
    exit 1
fi

echo "10;0" >/tmp/MCU_Cmd &
if [ -f /CacheVolume/.twonkymedia/twonkyserver.ini ]; then
	rm -f /CacheVolume/.twonkymedia/twonkyserver.ini
fi
if [ -f /CacheVolume/.twonkymedia/twonky-locations-70.db ]; then
	rm -f /CacheVolume/.twonkymedia/twonky-locations-70.db
fi
if [ -d /DataVolume/upload ]; then
	mv /DataVolume/upload /DataVolume/Upload
fi
if [ -d /CacheVolume/.twonkymedia/db ]; then
	rm -Rf /CacheVolume/.twonkymedia/db/*
fi
if [ -d /CacheVolume/Upload ]; then
	rm -Rf /CacheVolume/Upload/*
fi

echo "upgrading 25" > /tmp/fw_update_status
if [ -f "/tmp/fwupg_images/MLO" ]; then
	size=`ls -la "/tmp/fwupg_images/MLO" | awk '{print $5}'`
#	mtd_debug read /dev/mtd0 0 $size /tmp/test.bin
    nanddump /dev/mtd0 -l $size  -f /tmp/temp.bin
    head -c $size /tmp/temp.bin > /tmp/test.bin
    md5_org=`md5sum /tmp/test.bin | awk '{print $1}'`
	md5_new=`md5sum /tmp/fwupg_images/MLO | awk '{print $1}'`
	if [ "${md5_org}" == "${md5_new}" ]; then
		mv /tmp/fwupg_images/MLO /tmp/fwupg_images/MLO-noupdate.bin
	else
		killall mcu_daemon
		sleep 1
	fi
    rm -f /tmp/temp.bin
	rm -f /tmp/test.bin
fi
if [ -f "/tmp/fwupg_images/u-boot.img" ]; then
	size=`ls -la "/tmp/fwupg_images/u-boot.img" | awk '{print $5}'`
#	mtd_debug read /dev/mtd4 0 $size /tmp/test.bin
    nanddump /dev/mtd4 -l $size  -f /tmp/temp.bin
    head -c $size /tmp/temp.bin > /tmp/test.bin
	md5_org=`md5sum /tmp/test.bin | awk '{print $1}'`
	md5_new=`md5sum /tmp/fwupg_images/u-boot.img | awk '{print $1}'`
	if [ "${md5_org}" == "${md5_new}" ]; then
		mv /tmp/fwupg_images/u-boot.img /tmp/fwupg_images/u-boot-noupdate.bin
	else
		killall mcu_daemon
		sleep 1
	fi
    rm -f /tmp/temp.bin
	rm -f /tmp/test.bin
fi
echo "upgrading 35" > /tmp/fw_update_status
if [ -f "/tmp/fwupg_images/MLO" ]; then
	flash_erase /dev/mtd0 0 0
	sleep 1
	nandwrite -p /dev/mtd0 /tmp/fwupg_images/MLO
	sleep 1
	flash_erase /dev/mtd1 0 0
	sleep 1
	nandwrite -p /dev/mtd1 /tmp/fwupg_images/MLO
	sleep 1
	flash_erase /dev/mtd2 0 0
	sleep 1
	nandwrite -p /dev/mtd2 /tmp/fwupg_images/MLO
	sleep 1
	flash_erase /dev/mtd3 0 0
	sleep 1
	nandwrite -p /dev/mtd3 /tmp/fwupg_images/MLO
	sleep 1
	if [ -f "/tmp/fwupg_images/u-boot.img" ]; then
		echo "Keep Turn off mcu_daemon"
	else
		/bin/mcu_daemon &
		sleep 2
	fi
fi
if [ -f "/tmp/fwupg_images/u-boot.img" ]; then
	flash_erase /dev/mtd4 0 0
	sleep 1
	nandwrite -p /dev/mtd4 /tmp/fwupg_images/u-boot.img
	sleep 1
	/bin/mcu_daemon &
	sleep 2
fi
echo "upgrading 45" > /tmp/fw_update_status
if [ -f "/tmp/fwupg_images/uImage" ]; then
	flash_erase /dev/mtd6 0 0
	sleep 1
	nandwrite -p /dev/mtd6 /tmp/fwupg_images/uImage
    sleep 1
fi
echo "upgrading 55" > /tmp/fw_update_status
# Cleanup Cache file
echo 1 > /tmp/CacheMgrFile
echo 3 > /proc/sys/vm/drop_caches
echo "upgrading 65" > /tmp/fw_update_status
# move image to ramdisk
mv /tmp/fwupg_images/rootfs.cpio /tmp/rootfs.cpio
mv /tmp/fwupg_images/uImage-update /tmp/uImage-update
echo "upgrading 75" > /tmp/fw_update_status
if [ -f "/tmp/fwupg_images/AsmSataFw.bin" ]; then
	mv /tmp/fwupg_images/AsmSataFw.bin /tmp/AsmSataFw.bin
	/etc/init.d/S92twonkyserver stop
	/sbin/EnableDisableSwap.sh disable
	umount /media/sdb1/.wdcache/.wd-alert
	umount /var/ftp/Public
	umount /var/ftp/Storage
	umount /DataVolume
	umount /media/sdb1
	umount /media/sdb1_fuse
	HDD=`cat /tmp/HDDDevNode`
	/sbin/asmupdate -u $HDD /tmp/AsmSataFw.bin
	echo "upgrading 85" > /tmp/fw_update_status
	sleep 2
fi

kexec -l /tmp/uImage-update --ramdisk=/tmp/rootfs.cpio --command-line="root=/dev/ram rw console=ttyO0,115200" --atags &
echo "upgrading 90" > /tmp/fw_update_status
sleep 5
echo "upgrading 100" > /tmp/fw_update_status
sleep 10
kexec -e
