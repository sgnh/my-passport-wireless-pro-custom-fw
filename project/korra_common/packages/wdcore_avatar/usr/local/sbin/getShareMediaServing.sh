#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getShareMediaServing.sh <share> 
#
# Returns - none/any/music_only/pictures_only/videos_only
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

contentdir=/etc/contentdir

if [ $# != 1 ]; then
	echo "usage: getShareMediaServing.sh <share>"
	exit 1
fi

# check if share  exists first
#getShares.sh all | grep -q -x $share
#if [ $? == 1 ]; then
#	echo "Share not found"
#	exit 1
#fi

echo "contentdir=`cat ${contentdir}`" | awk -v share=$share '
BEGIN { 
    FS = "="; RS = "\n";
	found = 0;
	sharepath = sprintf("/%s", share);
}
{
	if ($1 == "contentdir") {
		split($2, shareArr, ",");
		for ( share in shareArr ) {
			split(shareArr[share], detail, "|");
			if (detail[2] == sharepath) {
				found = 1;
				if (detail[1] == "+A") {
					print "any"
				}
				if (detail[1] == "+M") {
					print "music_only"
				}
				if (detail[1] == "+P") {
					print "pictures_only"
				}
				if (detail[1] == "+V") {
					print "videos_only"
				}
				exit 0;
			}
		}
	}
}
END {
	if (found == 0)
		print "none";
}
'


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
