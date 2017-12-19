#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getFirmwareUpdateStatus.sh
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
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

if [ -f /tmp/fw_update_status ]; then
	fw_update_status=`cat /tmp/fw_update_status`
	if [[ "${fw_update_status}" =~ "downloading" ]]; then
		if [ ! -f /tmp/fw_download_status ]; then
			## to fix race condition when downloading state is not yet available
			echo "downloading 0"
		else
			if [ "${fw_update_status}" == "plex_downloading" ]; then
				awk  'BEGIN{RS="\r"} END{printf("plex_downloading %s\n",$1)}' /tmp/fw_download_status
			else
				awk  'BEGIN{RS="\r"} END{printf("downloading %s\n",$1)}' /tmp/fw_download_status
			fi
		fi
	else
		cat /tmp/fw_update_status
	fi
else
	echo "idle"
fi

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
