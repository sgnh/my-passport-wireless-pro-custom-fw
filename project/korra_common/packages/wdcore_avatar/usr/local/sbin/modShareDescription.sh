#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modShareDescripton.sh <share> <description> 
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
desc=$2

if [ $# != 2 ]; then
	echo "usage: modShareDescription.sh <share> <description>"
	exit 1
fi

awk -v share=$share -v desc="$desc" '
BEGIN { 
    RS = "\n" ; FS = " ";
	state = 0;
}
{
	if (state == 0) {
		for (i=1; i< NF; i++) {
			if ( $i == "sharename" && $(i+1) == "=" && $(i+2) == share ) {
				state = 1;
				break;
			}
		}
		print $0;
	} else if (state == 1) {
		if ($1 == "comment" && $2 == "=") {
			printf("  comment = %s\n",desc);
			state = 2;
		}
		else {
			print $0;
		}
	}
	else {
		print $0;
	}
}
END {
	if (state == 0) {
		exit 1;
	}
}
' $sambaOverallShare > $sambaOverallShare-new
if [ $? == 1 ]; then
	echo "share not found"
	rm $sambaOverallShare-new
else
	mv $sambaOverallShare-new $sambaOverallShare
fi

# reload
daemon -U -X "/etc/init.d/samba reload"

# indicate that a change has been made to a share
incUpdateCount.pm "share"

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
