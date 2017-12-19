#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getSystemCapacity.sh 
# - Returns capacity in TB (0.5 resolution)
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

df -B GB | grep /DataVolume | awk '
{
	gsub("GB","",$2);
	capacity = int($2);
	capacity = capacity + 500;
	remainder = capacity % 1000;
	whole = capacity / 1000;
	if ( remainder > 500 )
		printf("%i.5TB\n",whole);
	else
		printf("%iTB\n",whole);
}'


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