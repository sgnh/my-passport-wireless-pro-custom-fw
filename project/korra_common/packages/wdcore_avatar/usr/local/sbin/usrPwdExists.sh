#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# usrPwdExists.sh <userName>
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
    echo "usage: usrPwdExists.sh <userName>"
    exit 1
fi

PWD_EXISTS=$(awk -F: -v user=${1} '{
    if (user == $1) {
        print $2
    }
}' /etc/shadow)


if [ -n "${PWD_EXISTS}" ] && [ "${PWD_EXISTS}" != '' ] && [ "${PWD_EXISTS}" != '!' ] && [ "${PWD_EXISTS}" != '*' ]; then
    PASSWORD="yes"
else
    PASSWORD="no"
fi

echo "${PASSWORD}" | awk '{print $1;}'


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