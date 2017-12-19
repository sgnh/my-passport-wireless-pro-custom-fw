#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# saveConfiguration.sh 
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/networking-general.conf 2>/dev/null
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

configFile=/CacheVolume/`hostname`-`date +%Y%m%d-%H%M`.conf
if [ -f /etc/saveconfigfiles.txt ]; then
	cat /etc/saveconfigfiles.txt | xargs tar cf $configFile 2>/dev/null
	echo "$configFile"
else
	exit 1
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
