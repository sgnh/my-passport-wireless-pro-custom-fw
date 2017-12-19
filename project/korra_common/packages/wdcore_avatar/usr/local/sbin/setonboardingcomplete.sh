#!/bin/sh
# ? 2010 Western Digital Technologies, Inc. All rights reserved.
#
# setServiceStartup.sh <servicename> <enabled/disabled>
#
# Enables or disables the given service in the startup list
#
#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
APACHE_CONF=/etc/apache2/httpd.conf
#---------------------
# Begin Script
#---------------------
method="${1}"

if [ "${method}" == "OnboardingCheck" ]; then
	exit 1
    if [ -f "/etc/.device_Unconfigured" ]; then
		cp -a /var/www/indexOrigin.php /var/www/index.php
	fi
else
	if [ -f "/etc/.device_Unconfigured" ]; then
		rm -f /etc/.device_Unconfigured
		/etc/init.d/S67dhcp-server restart
		/sbin/UrlRedirect.sh DelRule
		#sed -i '4,4c \'#Include\ /etc/apache2/extra/httpd-captiveportal.conf ${APACHE_CONF}
		#sed -i '516,$d' ${APACHE_CONF}
		#cp -a /var/www/indexOrigin.php /var/www/index.php
	fi
fi
#---------------------
# End Script
#---------------------



