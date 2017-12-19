#!/bin/sh
/etc/init.d/S80plexmediaserver stop
rm -f /etc/nas/service_startup/plexmediaserver
rm -f /usr/local/plexmediaserver/Library
#rm -Rf /media/sdb1/.wdcache/.plexmediaserver
rm -f /lib/systemd/system/multi-user.target.wants/primax-plexmediaserver.service
rm -f /etc/init.d/S80plexmediaserver
rm -Rf /usr/local/plexmediaserver

