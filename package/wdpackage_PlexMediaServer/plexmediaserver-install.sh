#!/bin/sh

retry=3

plexupdate_progress()
{
     echo "upgrading $1" > /tmp/fw_update_status
     echo "upgrading $1" > /tmp/plexfw_update_status
     sleep 1
     cat /tmp/fw_update_status
     cat /tmp/plexfw_update_status
}

link_Library() {
    isMounted=`mount | grep "/media/sdb1" | wc -l`
    if [ $isMounted -eq 0 ]; then
        echo "No User HDD founded"
	exit 1
    fi

    if [ -d /media/sdb1/.wdcache/.plexmediaserver ]; then
        isLinkToWdcache=`ls -l /usr/local/plexmediaserver/Library | grep "/media/sdb1/.wdcache/.plexmediaserver" | wc -l`
        if [ $isLinkToWdcache -eq 0 ]; then
            rm -f /usr/local/plexmediaserver/Library
            ln -sf /media/sdb1/.wdcache/.plexmediaserver /usr/local/plexmediaserver/Library
        fi
        return
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


if [ ! -d /usr/local/plexmediaserver ]; then
    mv $1 /usr/local/plexmediaserver
fi
chmod 775 /usr/local/plexmediaserver/plexmediaserver.sh
cp -a /usr/local/sbin/packages/plexmediaserver/S80plexmediaserver /etc/init.d/S80plexmediaserver
cp -a /usr/local/sbin/packages/plexmediaserver/primax-plexmediaserver.service /lib/systemd/system/multi-user.target.wants/primax-plexmediaserver.service
mkdir -p /home/root
plexupdate_progress 65
link_Library
plexupdate_progress 85
ln -sf ld-linux-armhf.so.3 /lib/ld-linux.so.3
if [ ! -f /etc/nas/service_startup/plexmediaserver ]; then
    echo "disabled" > /etc/nas/service_startup/twonky
    echo "enabled"  > /etc/nas/service_startup/plexmediaserver
fi

