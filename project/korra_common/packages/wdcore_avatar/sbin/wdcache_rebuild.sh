#!/bin/bash
#
#

umount -f /CacheVolume/.wd-alert/
mkdir /media/sdb1/.wdcache
chmod -R 777 /media/sdb1/.wdcache
chmod -R 777 /CacheVolume/
cp -rf /CacheVolume/* /media/sdb1/.wdcache/

cp -rf /CacheVolume/.twonkymedia/ /media/sdb1/.wdcache/
cp -rf /CacheVolume/.wd-alert/ /media/sdb1/.wdcache/

rm -rf /CacheVolume/

ln -s /media/sdb1/.wdcache/ /CacheVolume
mount -o loop /etc/safeloop  /CacheVolume/.wd-alert
