#!/bin/sh
chmod 775 /mnt/usr/local/plexmediaserver/plexmediaserver.sh
cp -a /mnt/usr/local/sbin/packages/plexmediaserver/S80plexmediaserver /mnt/etc/init.d/S80plexmediaserver
cp -a /mnt/usr/local/sbin/packages/plexmediaserver/primax-plexmediaserver.service /mnt/lib/systemd/system/multi-user.target.wants/primax-plexmediaserver.service
mkdir -p /mnt/home/root
if [ ! -L /mnt/usr/local/plexmediaserver/Library ]; then
    cp -a /usr/local/plexmediaserver/Library /mnt/usr/local/plexmediaserver/Library
fi
ln -sf ld-linux-armhf.so.3 /mnt/lib/ld-linux.so.3
if [ ! -f /mnt/etc/nas/service_startup/plexmediaserver ]; then
    echo "disabled" > /mnt/etc/nas/service_startup/twonky
    echo "enabled"  > /mnt/etc/nas/service_startup/plexmediaserver
fi

