#!/bin/sh

systemfolder_list="/shares /shares/Storage \
/var/www/htdocs /var/www/htdocs/ui /var/www/rest-api /var/www/rest-api/api /var/www/rest-api/config \
/usr/local/sbin /usr/local/nas /usr/local/orion /usr/local/wdmcserver /usr/local/twonkymedia-7 /usr/local/bin \
/tmp /CacheVolume /var/log /etc/init.d /etc /etc/samba /etc/nas /etc/nas/config /etc/nas/service_startup /etc/nas/notify.d /etc/netatalk \
/etc/nas/strings"

NotFoundItems=0

for i in $systemfolder_list
do
	if [ ! -d "$i" ]; then
		echo "Not find Folder $i";
		NotFoundItems=`expr $NotFoundItems + 1`
	fi
done

if [ $NotFoundItems -gt 0 ]; then
	echo "Check Failed"
else
	echo "Check Pass"
fi
