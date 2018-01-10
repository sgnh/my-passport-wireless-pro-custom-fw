#!/bin/sh
case $1 in
	"hdd")
		kill `pidof smbd`;
		/etc/init.d/S95RestAPI stop;
		/etc/init.d/S93crond stop;
		/etc/init.d/S92wdnotifierd stop;
		/etc/init.d/S85wdmcserverd stop;
		/etc/init.d/S80twonkyserver stop;
		[ -e /etc/init.d/S80twonkyserver ] && /etc/init.d/S80twonkyserver stop;
		[ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver stop;
		kill `pidof twonkystarter`;
		/etc/init.d/S75smb stop;
		/etc/init.d/S74swapfile stop;
		/etc/init.d/S63vsftpd stop;
		/etc/init.d/S55netatalk stop;
		killall mv
		killall cp
		killall convert
		killall ufraw-batch
		sync
		umount /var/ftp/Storage
		sleep 1
		umount /shares/Storage
		sleep 1
		umount /DataVolume
		sleep 1
		umount /media/sdb1
		MountDevNode=`cat /tmp/MountedDevNode`
		StorageMounted=`mount | grep ${MountDevNode} | wc -l`
		if [ ${StorageMounted} -ne 0 ]; then
			umount -l ${MountDevNode}
			sleep 1
		fi
		rm -f /tmp/HDDDevNode
		timeout -t 120 /usr/local/sbin/ejectExternalDevices.sh
		result=$?
		if [ ${result} == "143" ]; then
			fuser -mk /media/sdb1
		fi

		;;
	"network")
		kill `pidof smbd`;
		/etc/init.d/S95RestAPI stop;
		/etc/init.d/S93crond stop;
		/etc/init.d/S92wdnotifierd stop;
		/etc/init.d/S85wdmcserverd stop;
		/etc/init.d/S80twonkyserver stop;
		[ -e /etc/init.d/S80twonkyserver ] && /etc/init.d/S80twonkyserver stop;
		[ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver stop;
		kill `pidof twonkystarter`;
		/etc/init.d/S75smb stop;
		/etc/init.d/S74swapfile stop;
		/etc/init.d/S63vsftpd stop;
		/etc/init.d/S55netatalk stop;
		killall mv
		killall cp
		killall convert
		killall ufraw-batch
		;;
	"hddup")
		/sbin/intlmount.sh
		/etc/init.d/S43initdisk start;
		/etc/init.d/S55netatalk start;
		/etc/init.d/S63vsftpd start;
		/etc/init.d/S74swapfile start;
		/etc/init.d/S75smb start;
		/etc/init.d/S85wdmcserverd stop;
		sleep 1
		/etc/init.d/S85wdmcserverd start;
		/etc/init.d/S92wdnotifierd start;
		/etc/init.d/S93crond start;
		[ -e /etc/init.d/S80twonkyserver ] && /etc/init.d/S80twonkyserver start;
		[ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver start;
		/etc/init.d/S95RestAPI start;
		umount /var/ftp/Storage
		StorageMounted=`mount | grep "/media/sdb1" | wc -l`
		if [ ${StorageMounted} == "1" ]; then
			mount --bind /media/sdb1/ /var/ftp/Storage
		fi
		mdev -s
		#/sbin/refresh_contentdirs.sh
		;;
	"networkup")
		;;
	*)
		exit 1
		;;
esac

exit 0
