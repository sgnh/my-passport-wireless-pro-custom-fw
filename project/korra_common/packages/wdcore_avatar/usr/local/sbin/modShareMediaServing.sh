#!/bin/bash
#
# � 2010, 2012 Western Digital Technologies, Inc. All rights reserved.
#
# modShareMediaServing.sh <share> <none/any/music_only/pictures_only/videos_only>
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
setting=$2

contentdir=/etc/contentdir

if [ $# != 2 ]; then
	echo "usage: modShareMediaServing.sh <share> <none/any/music_only/pictures_only/videos_only>"
	exit 1
fi

# check if share exists first; useful for stand-alone script testing
getShares.sh all | grep -q -x $share
if [ $? == 1 ]; then
	echo "Share not found"
	exit 1
fi

case $setting in
none)
	settingcode="none"
	;;
any)
	settingcode="+A"
	;;
music_only)
	settingcode="+M"
	;;
pictures_only)
	settingcode="+P"
	;;
videos_only)
	settingcode="+V"
	;;
*)
	echo "usage: modShareMediaServing.sh <share> <none/any/music_only/pictures_only/videos_only>"
	exit 1
esac

RC=0

# pre-remove if DLNA server needs it
if [ $setting == none -a -x /usr/local/sbin/modDlnaShareServing.sh ]; then
	/usr/local/sbin/modDlnaShareServing.sh $share $setting
	RC=$?
fi

awk -v share=${share} -v settingcode=${settingcode} '
BEGIN { 
    FS = "|"; RS = ",";
	found = 0;
	sharepath = sprintf("/%s", share);
	first = 1;
}
{
	gsub("\n","",$2);
	if ($2 == sharepath) {
		found = 1;
		if (settingcode != "none") {
			if (first == 0) {
				printf("%s",RS);
			}
			printf("%s%s%s",settingcode,FS,sharepath);
			first = 0;
		}
	}
	else {
		if ($1 != "" && $2 != "") {
			if (first == 0) {
				printf("%s",RS);
			}
			printf("%s%s%s",$1,FS,$2);
			first = 0;
		}
	}
}
END {
	if (found == 0 && settingcode != "none") {
		if (first == 0) {
			printf("%s",RS);
		}
		printf("%s%s%s",settingcode,FS,sharepath);		
	}
}
' ${contentdir} > ${contentdir}-new
mv ${contentdir}-new ${contentdir}

# update DLNA server
if [ -x /usr/local/sbin/modDlnaShareServing.sh ]; then
	/usr/local/sbin/modDlnaShareServing.sh $share $setting
	RC=$?
fi

# modify itunes configuration
rescanItunes.sh

# indicate that a change has been made to a share
incUpdateCount.pm "share" &

exit $RC

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

