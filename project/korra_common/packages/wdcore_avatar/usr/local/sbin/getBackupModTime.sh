#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getBackupModTime.sh <backupshare> <backupname> 
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

case ${1} in
"TimeMachine")
    stat -c '%Y' "/DataVolume/backup/TimeMachine/${2}.sparsebundle/bands"
	;;
"SmartWare")
	metadata_file=`find "/DataVolume/backup/SmartWare/WD SmartWare.swstor/${2}/" -mindepth 2 -maxdepth 2 | grep .com.wdc.metadata.xml`
        if [ ! -f "$metadata_file" ]; then
            # backup in progress, return current time
	    date +%s
        else
	    stat -c '%Y' "$metadata_file"
        fi
	;;
*)
	echo "No backup share $1 found"
	exit 1
	;;
esac

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
