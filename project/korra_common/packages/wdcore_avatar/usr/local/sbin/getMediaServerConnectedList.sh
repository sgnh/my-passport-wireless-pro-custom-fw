#!/bin/sh
#
# � 2010, 2011, 2012 Western Digital Technologies, Inc. All rights reserved.
#
# getMediaServerConnectedList.sh
#
# RETURNS:
#  "mac_address" "ip_address" "friendly_name" "device_description" "enabled/disabled' 
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf

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

# use generic DLNA function, if it exists, else return nothing
# the calling code will provide an empty REST response
# do NOT return an error
if [ -x /usr/local/sbin/getDlnaServerConnectedList.sh ]; then
  /usr/local/sbin/getDlnaServerConnectedList.sh
fi


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