#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modMediaServerEnable.sh <mac_address> <enable/disable>
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

if [ $# != 2 ]; then
	echo "usage: modMediaServerEnable.sh <mac_address> <enable/disable>"
	exit 1
fi

RC=0

if  [ -x /usr/local/sbin/modDlnaServerEnable.sh ]; then
  /usr/local/sbin/modDlnaServerEnable.sh "$@"
  RC=$?
fi

exit $RC

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
