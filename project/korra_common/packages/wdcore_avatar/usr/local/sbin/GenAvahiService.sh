#!/bin/bash
#
# � 2014 Primax Technologies, Inc. All rights reserved.
#
# InternetAccess.sh 
#
#  
#   
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#---------------------
# Begin Script
#---------------------
TestService="$1"

if [ ! -d "/etc/avahi/AvahiService" ]; then
	echo "creat "
	cp -a /etc/avahi/services /etc/avahi/AvahiService 
fi

if [ "$TestService" == "" ]; then
	cd /etc/avahi/
	if [ -d "/etc/avahi/services" ]; then
		rm -rf /etc/avahi/services
		mkdir -p /etc/avahi/services
	fi
	cp -a /etc/avahi/AvahiService/afpd.service /etc/avahi/services/
	
	rm -rf "/tmp/avahi_service"
	/etc/init.d/S50avahi-daemon stop
	/etc/init.d/S50avahi-daemon start
	
elif [ "$TestService" == "All" ]; then
	cd /etc/avahi/
	if [ -d "/etc/avahi/services" ]; then
		rm -rf /etc/avahi/services
		mkdir -p /etc/avahi/services
	fi
	cp -a /etc/avahi/AvahiService/web.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/wd2go.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/smb.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/ssh.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/sftp-ssh.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/daap.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/afpd.service /etc/avahi/services/
	cp -a /etc/avahi/AvahiService/adisk.service /etc/avahi/services/
	
	rm -rf "/tmp/avahi_service"
	/etc/init.d/S50avahi-daemon stop
	/etc/init.d/S50avahi-daemon start
fi


#---------------------
# End Script
#---------------------
