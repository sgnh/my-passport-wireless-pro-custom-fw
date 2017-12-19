#!/bin/sh

devstr=$1
destdir=/tmp/usbmounts
dev=${devstr}


check_DeviceNode()
{
    issdcard=0
    SDdev=$dev
    echo "/dev/${SDdev}" > /tmp/SDDevNode
    issdcard=1
}

my_umount()
{
    mount_point=SDcard

    if grep -qs "^/dev/$1 " /proc/mounts ; then
        umount -l "${destdir}/$mount_point";
    fi

    [ -d "${destdir}/$mount_point" ] && rmdir "${destdir}/$mount_point"

    if [ ! -d "${destdir}/$mount_point" ]; then
        rm -f /tmp/SDDevNode
        sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
        echo "18;0;" > /tmp/MCU_Cmd
    else
        umount -l "${destdir}/$mount_point";
        rm -f /tmp/SDDevNode
        sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
        echo "18;0;" > /tmp/MCU_Cmd
    fi
    #umount -l /media/AFPSDcard
}
                         

my_mount()
{
    echo "$dev SD:$SDdev HD:$HDDdev" > /tmp/sdmount.log
    mount_point=SDcard
		
    mkdir -p "${destdir}/$mount_point" || exit 1

    isFAT32=`blkid /dev/$1 | grep vfat | wc -l`
 
    if [ $isFAT32 -eq 1 ]; then
       fstype=vfat
       if ! mount -t auto -o async -o utf8=1 "/dev/$1" "${destdir}/$mount_point"; then
           rmdir "${destdir}/$mount_point"
           /sbin/StorageAlert.sh $mount_point $devstr $dev &
           exit 1
       fi
       echo "18;2;" > /tmp/MCU_Cmd
    else
       mkdir -p "${destdir}/$mount_point" || exit 1
       echo "${PPID} Mount on $1" >> /tmp/automount.log
       fstype=ufsd
       if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000 "/dev/$1" "${destdir}/$mount_point"; then
            # failed to mount, clean up mountpoint
            rmdir "${destdir}/$mount_point" 2>&1 > /dev/null
            /sbin/StorageAlert.sh $mount_point $devstr $dev &
            exit 1
       fi
       echo "18;2;" > /tmp/MCU_Cmd
    fi
    mounted=`mount | grep "$1 " | wc -l`
    if [ $mounted -eq 0 ]; then
        rmdir "${destdir}/$mount_point" 2>&1 > /dev/null
        exit 1
    fi

    if [ ${issdcard} -eq 1 ]; then
         if [ ! -f /tmp/sdsize ]; then
          	echo "total_size_in_bytes=0" > /tmp/sdsize_total
            echo "transferred_size_in_bytes=0" > /tmp/sdsize
         fi
         if [ ! -f /tmp/sdstats ]; then
	            echo "status=waiting" > /tmp/sdstats
         fi
         killall -10 ghelper
    fi
    shared=`cat /etc/samba/smb-shares.conf | grep "\[$mount_point\]" | wc -l`
    if [ $shared -eq 0 ]; then
      if [ "$mount_point" == "SDcard" ]; then
        echo "/dev/${SDdev}" > /tmp/SDDevNode
        #rm -Rf /media/AFPSDcard/*
        #mount /media/SDcard /media/AFPSDcard
        #if [ ! -d /var/ftp/SDcard ]; then
        #        mkdir -p /var/ftp/SDcard
        #        chown root:ftp /var/ftp/SDcard
        #        chmod 775 /var/ftp/SDcard
        #fi
        #mount --bind /media/SDcard /var/ftp/SDcard
    	fi
    fi
}

echo "${PPID} ${ACTION} ${DEVNAME} $1 $2 $3 $4" >> /tmp/sdmount.log
#Block event when system just resume
#pmxrtpm=`cat /proc/scsi/pmxrtpm`
#if [ $pmxrtpm -eq 0 ]; then
#exit
#fi
                                                             
case "${ACTION}" in
add|"")
    echo "SDa $1 Coming" > /tmp/sdmount.log
    check_DeviceNode
    isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
    if [ $isKnownType -eq 0 ]; then
        echo "$1 Type Unknown!!"
        exit 1
    fi
    echo "SD ADD event of $1" > /tmp/sdmount.log
    isGPT=`blkid /dev/$1 | grep EFI | wc -l`
    if [ $isGPT -eq 1 ]; then
          echo "***GPT found, ignore $1***" > /tmp/sdmount.log
          exit 1
    fi
    my_mount $1
    echo "SDd $1 Coming" > /tmp/sdmount.log
    ;;
remove)
    echo "####${ACTION}####"
    echo "do remove" >> /tmp/automount.log
    #umount /var/ftp/SDcard
    #if grep -qs "^/dev/$1 " /proc/mounts ; then
    #    umount -l /dev/$1
    #fi    
    my_umount $1
    ;;
esac
