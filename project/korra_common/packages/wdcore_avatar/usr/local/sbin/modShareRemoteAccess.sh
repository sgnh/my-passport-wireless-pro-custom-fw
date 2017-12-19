#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modShareRemoteAccess.sh <share> <enable/disable> 
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

share=$1
state=$2

if [ $# != 2 ]; then
	echo "usage: modShareRemoteAccess.sh <share> <enable/disable>"
	exit 1
fi

# check if share  exists first
#getShares.sh all | grep -q -x $share
#if [ $? == 1 ]; then
#	echo "Share not found"
#	exit 1
#fi

awk -v share=$share -v state=$state '
BEGIN { 
    FS = "|";
}
{
	numshare=0;
	for (i=1; i<= NF; i++) {
		if ($i != share) {
			if (numshare != 0) {
				printf("%s", FS);
			}
			printf("%s", $i);
			numshare=numshare+1;
		}
	}
	if (state == "enable") {
		if (numshare > 0) {
			printf("%s", FS);
		}
		printf("%s", share);
	}	
	printf("\n");
	exit 0;
}
' ${remoteAccessConfig} > ${remoteAccessConfig}-new

mv -v ${remoteAccessConfig}-new ${remoteAccessConfig}

# php -f /usr/local/sbin/mionet_share_update.php > /dev/null &

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