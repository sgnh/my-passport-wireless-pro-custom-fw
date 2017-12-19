#!/bin/bash
#
# SDCard_StorageTransfer.sh
#
# Used to triiger Storage Transfer process
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf
. /etc/system.conf

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": ExtenalStorageEject.sh" $@ >> /tmp/removeDeviceLogs.log

target=$1

if [ "$target" == "SD" ]; then
	sd_files=$(ls /tmp/mmcblk0*-info | wc -l)
	if [ "${sd_files}" != 0 ]; then
		device_handle=`cat /tmp/mmcblk0*-info | awk -F: '{print $9}'`
		/usr/local/sbin/wdAutoMountAdm.pm ejectDrive "${device_handle}"
	fi

elif [ "$target" == "USB" ]; then
	usb_files=$(ls /tmp/sd*-info | wc -l)
	if [ "${usb_files}" != 0 ]; then
		device_handle=`cat /tmp/sd*-info | awk -F: '{print $9}'`
		/usr/local/sbin/wdAutoMountAdm.pm ejectDrive "${device_handle}"
	fi
	

else
	echo $timestamp ": ExtenalStorageEject.sh failed target to umount"  >> /tmp/removeDeviceLogs.log
	exit 1
fi
	
exit 0
#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}

