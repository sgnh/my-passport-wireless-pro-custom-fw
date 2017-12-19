#!/bin/sh
case $1 in
	"hdd")
		sleep 5;
		/etc/init.d/S30mdev start;
		/etc/init.d/S43initdisk start;
		/etc/init.d/S55netatalk start;
		/etc/init.d/S63vsftpd start;
		/etc/init.d/S75smb start;
		/etc/init.d/S80twonkyserver start;
		/etc/init.d/S85wdmcserverd start;
		/etc/init.d/S92wdnotifierd start;
		/etc/init.d/S93crond start;
		/etc/init.d/S95RestAPI start;
		;;
	"network")
		;;
	*)
		exit 1
		;;
esac

exit 0
