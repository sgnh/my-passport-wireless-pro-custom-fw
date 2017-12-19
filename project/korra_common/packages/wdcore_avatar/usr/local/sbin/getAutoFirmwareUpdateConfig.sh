#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getAutoFirmwareUpdateConfig.sh
# RETURNS:
# <enable/disable> <install_day> <install_hour> 
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

if [ -f "/tmp/notacepteula" ]; then	 
	conf="/etc/auto_update.conf"	 
    echo "au_enable=enable" >  $conf	 
    echo "au_day=0" >> $conf
    echo "au_hour=3" >> $conf	 
    rm /tmp/notacepteula	 
fi

conf="/etc/auto_update.conf"

if [ ! -f $conf ]; then
	echo "disable 0 3"
else
	source $conf
	echo "$au_enable $au_day $au_hour"
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