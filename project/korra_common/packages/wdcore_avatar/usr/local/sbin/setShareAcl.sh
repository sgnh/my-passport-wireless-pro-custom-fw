#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# setShareAcl.sh <acl> <directory> 
#
# Set acl 
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/wd-nas.conf 2>/dev/null

setfacl -b -m "${1}" "${2}"
setfacl -d -m "${1}" "${2}"
setfattr -n "${SYNC_ACL_ATTR}" -v "start" "${2}"
daemon -U -X syncFileAcl.sh
