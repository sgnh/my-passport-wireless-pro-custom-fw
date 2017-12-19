#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# restoreConfig.sh <config_file_path> 
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/networking-general.conf 2>/dev/null
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

default_configFile="/etc/default/factory.conf"

if [ $# != 1 ]; then
	echo "usage: restoreConfig.sh <config_file_path>"
	exit 1
fi

configFile=$1
if [ -f $configFile ]; then
	tar -xf $configFile -C /
	tar -tf $configFile > /tmp/restoreConfig.tmp 
	tar -tf $default_configFile > /tmp/defaultConfig.tmp
	current=`cat /tmp/restoreConfig.tmp`
	for conf in $current
	do	
		echo -n $conf
		if [ -z `grep $conf /tmp/defaultConfig.tmp` ]; then
			rm /$conf
			echo " Remove"
		else
			echo " None"
		fi
		
	done 	 
	[ -f /tmp/restoreConfig.tmp ] && rm /tmp/restoreConfig.tmp
	[ -f /tmp/defaultConfig.tmp ] && rm /tmp/defaultConfig.tmp
	
	[ $? == "0" ] && /etc/init.d/rcK
	sleep 1 
	[ $? == "0" ] && /etc/init.d/rcS
else
	exit 1
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

exit 0

if [ -f $configFile ]; then
	exit 0
else
	cat /etc/saveconfigfiles.txt | xargs tar cvf $configFile
fi

