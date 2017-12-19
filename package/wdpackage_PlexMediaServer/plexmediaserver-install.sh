#!/bin/sh
if [ ! -d /usr/local/plexmediaserver ]; then
    mv $1 /usr/local/plexmediaserver
fi
#cp -a /usr/local/sbin/packages/plexmediaserver/plexmediaserver.sh /usr/local/plexmediaserver/plexmediaserver.sh
chmod 775 /usr/local/plexmediaserver/plexmediaserver.sh
cp -a /usr/local/sbin/packages/plexmediaserver/S80plexmediaserver /etc/init.d/S80plexmediaserver
cp -a /usr/local/sbin/packages/plexmediaserver/primax-plexmediaserver.service /lib/systemd/system/multi-user.target.wants/primax-plexmediaserver.service
mkdir -p /home/root
if [ ! -L /usr/local/plexmediaserver/Library ]; then
    mkdir -p /media/sdb1/.wdcache/.plexmediaserver
    ln -sf /media/sdb1/.wdcache/.plexmediaserver /usr/local/plexmediaserver/Library
fi
ln -sf ld-linux-armhf.so.3 /lib/ld-linux.so.3
if [ ! -f /etc/nas/service_startup/plexmediaserver ]; then
    echo "disabled" > /etc/nas/service_startup/twonky
    echo "enabled"  > /etc/nas/service_startup/plexmediaserver
fi

