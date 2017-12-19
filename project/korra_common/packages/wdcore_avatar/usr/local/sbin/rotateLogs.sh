#!/bin/sh
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

# check for log files larger than 1MB & do cleanup
/etc/init.d/purgelogs.sh

# check if /var/log/messages file is removed, re-create
if [ ! -e /var/log/messages ]; then
    logrotate -f /etc/logrotate.conf
fi

# check if logs are full, cleanup rotated logs if so
dfout=`df | grep ramlog`
percent=`echo "$dfout" | awk '{printf("%.0f\n",($3*100/$2 + 1)) }'`
if [ "$percent" -gt "90" ]; then
	logger "Logs getting full, remove all rotated logs"
	rm /var/log/*.1*
	rm /var/log/apache2/*.1*
	rm /var/log/*.2*
	rm /var/log/apache2/*.2*
fi

# remove all "auth" logs
rm /var/log/auth*

/usr/sbin/logrotate /etc/logrotate.conf
