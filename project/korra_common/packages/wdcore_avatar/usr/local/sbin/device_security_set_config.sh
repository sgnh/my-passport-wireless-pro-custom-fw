#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# device_security_set_config.sh 
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
status=$1

case ${status} in
	true)
        echo "device_security="${status} > /etc/device_security.conf
        echo "29;0" > /tmp/MCU_Cmd 2>/dev/null
		;;
	false)
		echo "device_security="${status} > /etc/device_security.conf
        echo "29;1" > /tmp/MCU_Cmd 2>/dev/null
		;;
	*)
		echo "usage: device_security_set_config.sh <true/false>" 

esac
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
