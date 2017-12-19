#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getUserInfo.sh <name>
#
# Returns Full name of user
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
	echo "usage: getUserInfo.sh <username> [fieldname]"
	exit 1
fi

fieldname=${2:-"fullname"}

# attempt to handel both old and new formats..

if [ "${fieldname}" == "fullname" ]; then
    awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd | grep -q ','
    if [ $? -ne 0 ]; then
        awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd
    else
        awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd | cut -d ',' -f 1
    fi
fi

if [ "${fieldname}" == "userid" ]; then
    awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd | grep -q ','
    if [ $? -ne 0 ]; then
        awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd
    else
        awk -F: -v user=${1} '{if (user == $1) {print $5}}' /etc/passwd | cut -d ',' -f 2
    fi
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