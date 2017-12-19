#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# storage_transfer_get_config.sh
#
# Used to retrieve the configured Storage Transfer property set in the device.
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
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
echo $timestamp ": storage_transfer_get_config.sh" $@ >> /tmp/backup.log

version_api=`cat /etc/version.packages | grep RESTAPI_2.4`
if [ "$version_api" == "" ]; then
	if [ $# == 0 ]; then
		storageType=all
	else
		storageType="${1}"
	fi

	if [ "$storageType" != "all" ] && [ "$storageType" != "sdcard" ] && [ "$storageType" != "usb" ]; then
		echo "storage_transfer_get_config.sh [ --storage_type <sdcard | usb>]"
		exit 254
	elif [ "$storageType" == "all" ]; then
		echo "{\"sdcard\" : [\"${AutoTransfer}\", \"${TransferMode}\"], \"usb\" : [\"$USB_TransferAuto\", \"$USB_ModeTransfer\"]}"	
	elif [ "$storageType" == "sdcard" ]; then
		echo "{\"sdcard\" : [\"${AutoTransfer}\", \"${TransferMode}\"]}"
	elif [ "$storageType" == "usb" ]; then
		echo "{\"usb\" : [\"$USB_TransferAuto\", \"$USB_ModeTransfer\"]}"
	fi
else
	echo ${AutoTransfer} ${TransferMode}
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

