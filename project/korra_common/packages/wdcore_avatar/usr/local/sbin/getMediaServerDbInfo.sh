#!/bin/bash
#
# � 2010, 2012 Western Digital Technologies, Inc. All rights reserved.
#
# getMediaServerDbInfo.sh 
#
# returns:
#   version=<string>
#   music_tracks=<number>
#   pictures=<number>
#   videos=<number>
#   time_db_update=<seconds since epoch>
#   scan_in_progress=<true|false>
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

if [ -x /usr/local/sbin/getDlnaDbInfo.sh ]; then
  /usr/local/sbin/getDlnaDbInfo.sh "$@"
  RC=$?
else
  time_db_update=`/bin/ls -g -o --time-style="+%s" /boot/boot.scr 2>/dev/null | awk '{ print $4 }'`
  echo version=0.0.0
  echo music_tracks=0
  echo pictures=0
  echo videos=0
  echo time_db_update=${time_db_update:-0}
  echo scan_in_progress=false
  RC=0
fi

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