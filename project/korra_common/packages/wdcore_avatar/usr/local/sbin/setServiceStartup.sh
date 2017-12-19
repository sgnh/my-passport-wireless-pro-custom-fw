#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# setServiceStartup.sh <servicename> <enabled/disabled>
#
# Enables or disables the given service in the startup list
#

#---------------------


 # Include conf.
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf
. /usr/local/sbin/ledConfig.sh

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

# Initialization
serviceName=$1
newstate=$2
param1="${3}"

service_ssh=S57sshd
service_vsftpd=S63vsftpd
service_twonky=S80twonkyserver
service_plexmediaserver=S80plexmediaserver
service_dlna=S80twonkyserver

CURRENT_DLNA=twonky


# Input should be two parameters
if [ $# == 1 ]; then
	echo "usage: setServiceStartup.sh <servicename> <enabled/disabled>"
	exit 1
fi
# Newstate should be either enabled or disabled
if [ "$newstate" != "enabled" ] && [ "$newstate" != "disabled" ]; then
	echo "usage: setServiceStartup.sh <servicename> <enabled/disabled>"
	exit 1
fi
# Check serviceName
if [ "$serviceName" != "ssh" ] && \
   [ "$serviceName" != "vsftpd" ] && \
   [ "$serviceName" != "twonky" ] && \
   [ "$serviceName" != "plexmediaserver" ] && \
   [ "$serviceName" != "dlna_server" ]; then
	exit 1
fi
# Convert generic DLNA server to specific instance
if [ "$serviceName" == "dlna_server" ]; then
	dlna_name=`/usr/local/sbin/getDlnaServer.sh`
	if [ -n "$dlna_name" ]; then
		serviceName=$dlna_name		
	else
		exit 1 
	fi
fi
# Check the currcent state of the service
currentstate=`getServiceStartup.sh ${serviceName}`
if [ $? == 1 ]; then
# ERROR: getServiceStartup.sh
	exit 1
fi
# Check if the newstate equals to currentstate, then do nothing.
if [ "$currentstate" == "$newstate" ] && [ "$serviceName" != "ssh" ]; then
	echo "Service $serviceName already $newstate"
	exit 0
fi
# Set conf.
if [ "$newstate" == "enabled" ]; then
	echo $newstate > /etc/nas/service_startup/$serviceName
fi
if [ $newstate == "enabled" ]; then
	action="start"
	do="true"
else
	action="stop"
# NTP should not be started
	if [ $serviceName != "ntpdate" ]; then
		do="true"
	fi
fi

if [ "$do" == "true" ]; then	
	[ -f /etc/init.d/$serviceName ] && /etc/init.d/$serviceName $action   # > /dev/null 2> /dev/null 
	if [ "$serviceName" == "ssh" ]; then
		if [ $newstate == "enabled" ]; then
			echo "root:$param1" | chpasswd
		fi
		[ -f /etc/init.d/${service_ssh} ] && /etc/init.d/${service_ssh} $action > /dev/null 2> /dev/null
	elif [ "$serviceName" == "vsftpd" ]; then
		[ -f /etc/init.d/${service_vsftpd} ] && /etc/init.d/${service_vsftpd} $action > /dev/null 2> /dev/null 
	elif [ "$serviceName" == "twonky" ]; then
		if [ "${serviceName}" == "${CURRENT_DLNA}" ]; then
			currentplexstate=`getServiceStartup.sh plexmediaserver`
			if [ $currentplexstate == "enabled" ] && [ "$newstate" == "enabled" ]; then
				[ -f /etc/init.d/${service_plexmediaserver} ] && /etc/init.d/${service_plexmediaserver} stop > /dev/null 2> /dev/null 
				[ -f /etc/nas/service_startup/plexmediaserver ] && echo disabled > /etc/nas/service_startup/plexmediaserver
			fi
			[ -f /etc/init.d/${service_twonky} ] && /etc/init.d/${service_twonky} $action > /dev/null 2> /dev/null 
# Fix it because of Jmeter.
			[ $? == "13" ]
		else
			currentplexstate=`getServiceStartup.sh plexmediaserver`
			if [ $currentplexstate == "enabled" ] && [ "$newstate" == "enabled" ]; then
				[ -f /etc/init.d/${service_twonky} ] && /etc/init.d/${service_twonky} stop > /dev/null 2> /dev/null 
				[ -f /etc/init.d/${service_plexmediaserver} ] && /etc/init.d/${service_plexmediaserver} stop > /dev/null 2> /dev/null 
			fi
			[ -f /etc/nas/service_startup/plexmediaserver ] && echo disabled > /etc/nas/service_startup/plexmediaserver
		fi
	elif [ "$1" == "dlna_server" ]; then
		if [ "${serviceName}" == "${CURRENT_DLNA}" ]; then
			currentplexstate=`getServiceStartup.sh plexmediaserver`
			if [ $currentplexstate == "enabled" ] && [ "$newstate" == "enabled" ]; then
				[ -f /etc/init.d/${service_plexmediaserver} ] && /etc/init.d/${service_plexmediaserver} stop > /dev/null 2> /dev/null 
				[ -f /etc/nas/service_startup/plexmediaserver ] && echo disabled > /etc/nas/service_startup/plexmediaserver
			fi
			[ -f /etc/init.d/${service_dlna} ] && /etc/init.d/${service_dlna} $action > /dev/null 2> /dev/null 

# Fix it because of Jmeter.
			[ $? == "13" ]
		else
			currentplexstate=`getServiceStartup.sh plexmediaserver`
			if [ $currentplexstate == "enabled" ] && [ "$newstate" == "enabled" ]; then
				[ -f /etc/init.d/${service_dlna} ] && /etc/init.d/${service_dlna} stop > /dev/null 2> /dev/null 
				[ -f /etc/init.d/${service_plexmediaserver} ] && /etc/init.d/${service_plexmediaserver} stop > /dev/null 2> /dev/null
			fi 
			[ -f /etc/nas/service_startup/plexmediaserver ] && echo disabled > /etc/nas/service_startup/plexmediaserver
		fi
	elif [ "$1" == "plexmediaserver" ]; then
		currenttwonkystate=`getServiceStartup.sh twonky`
		if [ $currenttwonkystate == "enabled" ] && [ "$newstate" == "enabled" ]; then
			[ -f /etc/init.d/${service_twonky} ] && /etc/init.d/${service_twonky} stop > /dev/null 2> /dev/null 
			[ -f /etc/nas/service_startup/twonky ] && echo disabled > /etc/nas/service_startup/twonky
		fi
		[ -f /etc/init.d/${service_plexmediaserver} ] && /etc/init.d/${service_plexmediaserver} $action > /dev/null 2> /dev/null 
	fi
fi
if [ "$newstate" == "disabled" ]; then
	echo $newstate > /etc/nas/service_startup/$serviceName
fi

# send a system/OK event through the ledCtrl to refresh the led state
#if [ $serviceName == "status-led" ]; then
#	ledCtrl.sh LED_EV_SYSTEM LED_STAT_OK
#fi

# reload mDNSResponder to check services
## Note: this is really only needed for itunes, however, the cost of reloading mDNSResponder is very low, 
## and didn't want to make a special case for it, since service setting changes are done so infrequently.
###bonjour not complete, fixed later
#/etc/init.d/mDNSResponder reload >/dev/null &

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
