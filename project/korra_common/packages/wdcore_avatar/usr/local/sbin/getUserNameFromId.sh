#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getUserNameFromId.sh <deviceUserId>
#
# Returns user name based on user id
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

if [ $# != 1 ]; then
    echo "usage: getUserNameFromId.sh <deviceUserId>"
    exit 1
fi

getUsers.sh > /tmp/userlist

while read user; do
    grpId=$(getUserInfo.sh "${user}" 'userid')
    # echo "grpId=$grpId"
    if [ "${grpId}" == "${1}" ]; then
        echo "$user" | awk '{print $1}'
    fi
done < /tmp/userlist

rm -f /tmp/userlist

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