#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getVolumeStatus.sh 
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
uesdspace=`df -h | grep /media/sdb1 | awk '{ print $5}' | awk -F% '{print $1}'`
badlimit=95
goodlimit=5

if [ ${uesdspace} -ge ${badlimit} ]; then
	echo "bad"
else
	echo "good"
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