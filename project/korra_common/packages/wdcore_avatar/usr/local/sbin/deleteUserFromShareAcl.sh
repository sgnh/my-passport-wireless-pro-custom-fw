#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# deleteUserFromShareAcl.sh <user> <directory> 
#
# Set acl 
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/wd-nas.conf 2>/dev/null

acl=`getfacl --absolute-names "${2}" | grep "${1}"`
if [ ! -z "${acl}" ]; then 
	setfacl -x "${1}" "${2}"
	setfacl -d -x "${1}" "${2}"
	setfattr -n "${SYNC_ACL_ATTR}" -v "start" "${2}"
	daemon -U -X syncFileAcl.sh
fi