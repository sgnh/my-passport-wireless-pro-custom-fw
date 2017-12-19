#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getShares.sh <type>
#   type = public,private, or all
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

awk -v type_input=$1 '
	BEGIN	{ 
		RS = "\n" ; FS = ":";
		type = tolower(type_input)
	}
	{
		split($1, dev_share, "]/");
		split(dev_share[2], sn, "/");
		if ( (sn[1] == "shares") && (length(sn[2]) > 0)) {
			if ( type == "all" ) {
				print sn[2]
			}
			else if (type == "public") {
				if ($2 == "*" && $3 == "RWBEX")
					print sn[2]
			}
			else if (type == "private") {
				if (!($2 == "*" && $3 == "RWBEX"))
					print sn[2]
			}
			else {
				print "parameter must be public,private,all"
				exit 1
			}
		}
	}
	END	 { } 
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