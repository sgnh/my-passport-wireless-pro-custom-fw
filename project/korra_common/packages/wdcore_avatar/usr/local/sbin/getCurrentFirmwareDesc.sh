#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getCurrentFwDesc.sh 
#
# returns: 
#  "<name>" "<version>" "<description>" "<buildtime>" "<lastupdate time>"
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/wd-nas.conf 2>/dev/null
. /etc/system.conf

VERSION_FILE=/etc/version
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

name="${modelName}"
version=`cat ${VERSION_FILE}`
description="Core F/W"
buildtime=`cat /etc/version.buildtime`
lastupdate=`cat /etc/version.update`
echo "\"${name}\" \"${version}\" \"${description}\" \"${buildtime}\" \"${lastupdate}\""
echo "3" > /proc/sys/vm/drop_caches

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
