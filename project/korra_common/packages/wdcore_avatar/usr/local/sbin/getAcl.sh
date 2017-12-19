#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getAcl.sh <share> <RW/RO> 
#
# Returns: users matching ACL list for given share
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /usr/local/sbin/data-volume-config_helper.sh
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

shareName=$1
type=$2

if [ $# != 2 ]; then
	echo "usage: getAcl.sh <share> <RW/RO>"
	exit 1
fi

if [ $type != "RW" ] && [ $type != "RO" ]; then
	echo "Must designate RW or RO for ACL"
	exit 1
fi


awk -v share=$shareName -v type=$type -v disk=$dataVolumeDevice '
BEGIN {
	RS = "\n" ; FS = ":";
}
{
	sharepath = sprintf("[%s]/shares/%s",disk, share);
	if ( $1 == sharepath ) {
		# print all matching users
		for (i=2; i <= NF; i=i+2) {
			if (   ( type == "RW" && $(i+1) == "RWBEX" ) \
				|| ( type == "RO" && $(i+1) == "RBE" ) ) {
				print $i
			}
		}
	}
}
' $trustees


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


