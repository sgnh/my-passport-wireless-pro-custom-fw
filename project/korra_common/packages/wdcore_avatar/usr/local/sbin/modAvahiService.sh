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
TestServiceName="$1"

if [ "$TestServiceName" == "Default" ]; then
	sed -i 's/<name .*/\<name replace-wildcards=\"yes\"\>%h\<\/name\>/' /tmp/avahi_service/services/afpd.service
	sed -i 's/<name .*/\<name replace-wildcards=\"yes\"\>%h\<\/name\>/' /etc/avahi/services/afpd.service
else
	sed -i 's/<name .*/\<name replace-wildcards=\"no\"\>'"${TestServiceName}"'\<\/name\>/' /tmp/avahi_service/services/afpd.service
	sed -i 's/<name .*/\<name replace-wildcards=\"no\"\>'"${TestServiceName}"'\<\/name\>/' /etc/avahi/services/afpd.service
fi
sleep 1
/etc/init.d/S50avahi-daemon restart
#---------------------
# End Script
#---------------------
