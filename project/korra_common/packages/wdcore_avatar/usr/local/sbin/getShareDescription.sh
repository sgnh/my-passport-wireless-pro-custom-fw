#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getShareDescription.sh <share> 
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

if [ $# == 0 ]; then
	echo "usage: getShareDescription.sh <share>"
	exit 1
fi

awk -v share=$share '
BEGIN { 
    RS = "## BEGIN ##" ; FS = "\n";
	found = 0;
}
{
	split($1, sn, " ");
	if ( sn[1] == "sharename" && sn[2] == "=" && sn[3] == share ) {
		found = 1;
		for (i = 2; i <= NF; i++) {
			split ($i, field, " = ");
			if ( field[1] == "  comment" ) {
				print field[2]
				exit 0;
			}
		}
	}
}
END {
	if (!found) {
		print "share not found"
		exit 1;
	}
}
' $sambaOverallShare


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


