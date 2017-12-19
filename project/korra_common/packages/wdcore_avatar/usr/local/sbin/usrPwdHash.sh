#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# usrPwdHash.sh <userName>
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

if [ $# -lt 1 ]; then
    echo "usage:   usrPwdHash.sh <userName>"
    echo "returns: username \n hashedvalue"
    exit 1
fi

userId=$1

awk -F':' -v uid=${userId} 'BEGIN{OFS="\n";} {if (uid == $1) {print $1,$2}}' /etc/shadow

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

exit 0