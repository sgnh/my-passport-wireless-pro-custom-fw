#!/bin/sh
hdd=`cat /tmp/HDDDevNode`
kill `pidof smbd`;
/etc/init.d/S99crond stop;
/etc/init.d/S95RestAPI stop;
/etc/init.d/S92wdnotifierd stop;
/etc/init.d/S92twonkyserver stop;
kill `pidof twonkystarter`;
/etc/init.d/S91smb stop;
/etc/init.d/S85wdmcserverd stop;
/etc/init.d/S50netatalk stop;
sleep 10;
umount /media/sdb1/;
umount /media/sdb1_fuse/;
umount /DataVolume/;
wipefs -ap $hdd;
echo "d
n
p
1


t
7
w
"|fdisk $hdd;
sleep 2;
mdev -s;
sleep 5;
umount /DataVolume/;
umount /media/sdb1/;
umount /media/sdb1_fuse/;
echo "y

"|mkexfat ${hdd}1;
sleep 3;
reboot
