#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# getServiceStartup.sh <servicename>
#
# Gets current service startup
#

#---------------------


# Include conf.
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

serviceName=$1

if [ $# != 1 ]; then
	echo "usage: getServiceStartup.sh <servicename>"
	exit 1
fi

# convert generic DLNA server to specific instance
if [ "$serviceName" == "dlna_server" ]; then
	dlna_name=`/usr/local/sbin/getDlnaServer.sh`
# Could not get dlna server
	if [ -n "$dlna_name" ]; then 
		serviceName=$dlna_name	
	else
		exit 1
	fi
fi

if [ ! -f /etc/nas/service_startup/${serviceName} ]; then
# Comment this command because of restapi doesn't want it
	#echo "service ${serviceName} not found"
	echo "disabled"
	exit 1
fi

cat /etc/nas/service_startup/${serviceName}

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
