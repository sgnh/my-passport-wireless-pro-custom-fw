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


create_Library() {
    isMounted=`mount | grep "/media/sdb1" | wc -l`
    if [ $isMounted -eq 0 ]; then
        echo "No User HDD founded"
	exit 1
    fi

    if [ ! -f /media/sdb1/.wdcache/plexmediaserver.img ]; then
        UserHDDSpace=`df | grep "/media/sdb1" | awk '{print $4}'`
        if [ $UserHDDSpace -gt 10485760 ]; then
            dd if=/dev/zero of=/media/sdb1/.wdcache/plexmediaserver.img bs=1M count=10240
            mkfs.ext4 /media/sdb1/.wdcache/plexmediaserver.img
        fi
    fi
    if [ -f /media/sdb1/.wdcache/plexmediaserver.img ]; then
        mkdir -p /data/plexmediaserver
        mount -t ext4 -o loop /media/sdb1/.wdcache/plexmediaserver.img /data/plexmediaserver
        sleep 1
        isDataPlexmediaserverMounted=`mount | grep "/data/plexmediaserver" | wc -l`
        while [ $isDataPlexmediaserverMounted -eq 0 ] && [ ${retry} -gt 0 ]
        do
            sleep 3        
            mount -t ext4 -o loop /media/sdb1/.wdcache/plexmediaserver.img /data/plexmediaserver
            isDataPlexmediaserverMounted=`mount | grep "/data/plexmediaserver" | wc -l`
            ((retry --))
        done    
    fi

    if [ $isDataPlexmediaserverMounted -eq 1 ]; then
        if [ ! -L /usr/local/plexmediaserver/Library ]; then
            ln -sf /data/plexmediaserver /usr/local/plexmediaserver/Library
        else
            isLinkToData=`ls -l /usr/local/plexmediaserver/Library | grep "/data/plexmediaserver/" | wc -l`
            if [ $isLinkToData -eq 0 ]; then
                rm -f /usr/local/plexmediaserver/Library
                ln -sf /data/plexmediaserver /usr/local/plexmediaserver/Library
            fi
        fi
    else
        if [ ! -d /media/sdb1/.wdcache/.plexmediaserver ]; then
            mkdir -p /media/sdb1/.wdcache/.plexmediaserver
        fi
        if [ ! -L /usr/local/plexmediaserver/Library ]; then
            if [ ! -d /media/sdb1/.wdcache/.plexmediaserver ]; then
                mkdir -p /media/sdb1/.wdcache/.plexmediaserver
            fi
            mv /usr/local/plexmediaserver/Library/* /media/sdb1/.wdcache/.plexmediaserver/
            rm -Rf /usr/local/plexmediaserver/Library
            ln -sf /media/sdb1/.wdcache/.plexmediaserver /usr/local/plexmediaserver/Library
        else
            isLinkToWdcache=`ls -l /usr/local/plexmediaserver/Library | grep "/media/sdb1/.wdcache/.plexmediaserver" | wc -l`
            if [ $isLinkToWdcache -eq 0 ]; then
                rm -f /usr/local/plexmediaserver/Library
                ln -sf /media/sdb1/.wdcache/.plexmediaserver /usr/local/plexmediaserver/Library
            fi
        fi
    fi

}


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
            killall ufraw-batch
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
    
            if [ "$fstype" == "exfat" ] || [ "$fstype" == "ntfs" ] || [ "$fstype" == "hfsplus" ]; then
                chkufsd -f ${MountDevNode} > /tmp/chkdisk.log
            fi
            if [ "$fstype" == "vfat" ]; then
                fsck.fat -aw ${MountDevNode} > /tmp/chkdisk.log
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

            if [ -d /usr/local/plexmediaserver/Library ]; then
                rm -Rf /usr/local/plexmediaserver/Library
            fi
            if [ -d /media/sdb1/.wdcache/.plexmediaserver ]; then
                rm -Rf /media/sdb1/.wdcache/.plexmediaserver
            fi
            if [ -f /media/sdb1/.wdcache/plexmediaserver.img ]; then
                rm -f /media/sdb1/.wdcache/plexmediaserver.img
            fi
            if [ -L /usr/local/plexmediaserver/Library ]; then
                rm -f /usr/local/plexmediaserver/Library
            fi
            create_Library
            #/etc/init.d/S80plexmediaserver start

            rm /tmp/PlexRebuild
            reboot
        fi
        ;;

*)
        echo "usage: cmdPlex.sh <rebuild>"
        exit 1
esac


