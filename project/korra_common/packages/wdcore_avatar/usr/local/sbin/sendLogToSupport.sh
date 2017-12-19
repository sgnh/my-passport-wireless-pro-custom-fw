#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# sendLogToSupport.sh 
#
# returns: 
#   Name of file send to support, or server_connection_failed (if failed to send to support)
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
#. /etc/nas/config/wd-nas.conf 2>/dev/null
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

logFile=`getSystemLog.sh`
fileName=`echo $logFile | awk -F/ '{print $NF}'`

curl -4 -T $logFile ftp://ftpext2.wdc.com --user ${supportFTPLogin} 2> /dev/null

if [ $? != 0 ]; then
	echo "server_connection_failed"
	exit 0;
fi

rm $logFile
echo $fileName


#---------------------
# End Script
#---------------------
# Copy stdout to script log also
#} ## | tee -a ./scriptsLog.txt
# Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}
