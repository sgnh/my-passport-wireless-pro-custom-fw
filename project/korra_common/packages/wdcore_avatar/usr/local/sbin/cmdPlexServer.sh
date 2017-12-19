#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# cmdPlexServer.sh <rebuild>
#
#
#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/system.conf


cmd=$1

if [ "`getServiceStartup.sh plexmediaserver`" == "disabled" ]; then
	exit 0;
fi

case ${cmd} in

rebuild)
        if [ ! -f "/tmp/PlexRebuild" ]; then
            touch /tmp/PlexRebuild
            #/etc/init.d/S80plexmediaserver stop
            #sleep 5

            MountDevNode=`cat /tmp/MountedDevNode`
            fstype=`blkid ${MountDevNode} | sed -n 's/.* TYPE="\([^"]*\)".*/\1/p'`
            #/usr/local/sbin/killService.sh hdd > /dev/null
            kill `pidof smbd`;
            /etc/init.d/S95RestAPI stop;
            /etc/init.d/S93crond stop;
            /etc/init.d/S92wdnotifierd stop;
            /etc/init.d/S85wdmcserverd stop;
            [ -e /etc/init.d/S80plexmediaserver ] && /etc/init.d/S80plexmediaserver stop;
            /etc/init.d/S75smb stop;
            /etc/init.d/S74swapfile stop;
            /etc/init.d/S63vsftpd stop;
            /etc/init.d/S55netatalk stop;
            killall mv
            killall cp
            killall convert
            sync
            umount /var/ftp/Storage
            sleep 1
            umount /shares/Storage
            sleep 1
            umount /DataVolume
            sleep 1
            umount /media/sdb1
            rm -f /tmp/HDDDevNode
            timeout -t 120 /usr/local/sbin/ejectExternalDevices.sh
            result=$?
            if [ ${result} == "143" ]; then
                fuser -mk /media/sdb1
            fi
            umount -l ${MountDevNode}	
            sleep 1
    
            #if [ "$fstype" == "exfat" ]; then
            #    chkexfat -f "${MountDevNode}"
            #fi
            #if [ "$fstype" == "ntfs" ]; then
            #    chkntfs -f "${MountDevNode}"
            #fi
            #if [ "$fstype" == "hfsplus" ]; then
            #    chkhfs -f "${MountDevNode}"
            #fi
            if [ "$fstype" == "exfat" ] || [ "$fstype" == "ntfs" ] || [ "$fstype" == "hfsplus" ]; then
                chkufsd -f "${MountDevNode}"
            fi
            if [ "$fstype" == "vfat" ]; then
                fsck.fat -aw ${MountDevNode}
            fi
            sync
            #/usr/local/sbin/killService.sh hddup > /dev/null
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
            /etc/init.d/S95RestAPI start;
            umount /var/ftp/Storage
            StorageMounted=`mount | grep "/media/sdb1" | wc -l`
            if [ ${StorageMounted} == "1" ]; then
                mount --bind /media/sdb1/ /var/ftp/Storage
            fi
            mdev -s
            sleep 1
	
            rm -Rf /usr/local/plexmediaserver/Library
            rm -Rf /media/sdb1/.wdcache/.plexmediaserver/
            /etc/init.d/S80plexmediaserver start
		
            rm /tmp/PlexRebuild
            reboot
        fi
        ;;

*)
        echo "usage: cmdPlex.sh <rebuild>"
        exit 1
esac


