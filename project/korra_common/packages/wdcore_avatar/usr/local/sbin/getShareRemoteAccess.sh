#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getShareRemoteAccess.sh <share> 
#
# Returns - enable - share enabled for remote access, or disable - share disabled for remote access
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

share=$1
state=$2

if [ $# != 1 ]; then
	echo "usage: getShareRemoteAccess.sh <share>"
	exit 1
fi

# check if share  exists first
#getShares.sh all | grep -q -x $share
#if [ $? == 1 ]; then
#	echo "Share not found"
#	exit 1
#fi

awk -v share=$share '
BEGIN { 
    FS = "|";
	found =0;
}
{
	for (i=1; i<= NF; i++) {
		if ( $i == share ) {
			found = 1;
			exit 0;
		}
	}
}
END {
	if (found == 0)
		print "disable";
	else
		print "enable";
}
' ${remoteAccessConfig}


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
