#!/bin/bash
#/sbin/EnableDisableSwap.sh disable
umount /media/sdb1_fuse
umount /DataVolume
umount /var/ftp/Storage
umount /media/sdb1/.wdcache/.wd-alert
sync
killall filecache
umount /media/sdb1
