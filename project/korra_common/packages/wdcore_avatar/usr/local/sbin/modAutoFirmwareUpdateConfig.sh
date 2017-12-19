#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modAutoFirmwareUpdateConfig.sh <enable/disable> <install_day> <install_hour>
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

enable=$1
day=$2
hour=$3

if [ $# != 3 ]; then
	echo "usage: modAutoFirmwareUpdateConfig.sh <enable/disable> <install_day> <install_hour>"
	exit 1
fi

if [ "$enable" != "enable" ] && [ "$enable" != "disable" ]; then
    echo "usage: modAutoFirmwareUpdateConfig.sh <enable/disable> <install_day> <install_hour>"
    echo "Should be enable or disable"
    exit 1
fi
#if [[ $day != [0-6] ]]; then
#    echo "usage: modAutoFirmwareUpdateConfig.sh <enable/disable> <install_day> <install_hour>"
#    echo "<install_day> range from 0 to 6"
#    exit 1
#fi
#if [ $hour -lt 0 ] || [ $hour -gt 23 ] ; then
#    echo "usage: modAutoFirmwareUpdateConfig.sh <enable/disable> <install_day> <install_hour>"
#    echo "<install_hour> range from 0 to 23"
#    exit 1
#fi

conf="/etc/auto_update.conf"
echo "au_enable=$enable" >  $conf
echo "au_day=$day" >> $conf
echo "au_hour=$hour" >> $conf

# configure cron job
myCronFile="/etc/cron.d/auto_update"
if [ $day == "0" ]; then
	echo "00 3 * * * root  /usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert; /usr/local/sbin/checkAutoUpdate.sh" > temp_cronFile
	#echo "00 $hour * * * root  /usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert; /usr/local/sbin/checkAutoUpdate.sh" > temp_cronFile
else
	echo "00 3 * * * root  /usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert; /usr/local/sbin/checkAutoUpdate.sh" > temp_cronFile
	#echo "00 $hour * * $day root  /usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert; /usr/local/sbin/checkAutoUpdate.sh" > temp_cronFile
fi
mv temp_cronFile $myCronFile
/etc/init.d/S93crond reload
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
