#!/bin/sh

source /etc/power.conf
devstr=$1
destdir=/media
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
    if [ ! -f /tmp/$1-info ]; then
        exit 0
    fi
    mount_point=`cat /tmp/$1-info | cut -f 3 -d ':' | cut -c 8-`
    /sbin/removeDevice.sh SDcard $1
    fuser -mk "${destdir}/${mount_point}";

    if grep -qs "^/dev/$1 " /proc/mounts ; then
        umount /dev/$1;
    fi
    if grep -qs "^/dev/$1 " /proc/mounts ; then
        sleep 1
        echo "${PPID} my_umount $1 retry 1" >> /tmp/automount.log
        umount -l /dev/$1;
    fi
    if grep -qs "^/dev/$1 " /proc/mounts ; then
        sleep 1
	echo "${PPID} my_umount $1 retry 2" >> /tmp/automount.log
        umount -l /dev/$1;
    fi
    [ -d "${destdir}/${mount_point}" ] && umount -f "${destdir}/${mount_point}" && rmdir "${destdir}/${mount_point}"

    if [ ! -d "${destdir}/${mount_point}" ]; then
        rm -f /tmp/SDDevNode
        sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
        #echo "status=failed" > /tmp/transfer_state
        #echo "18;0;" > /tmp/MCU_Cmd
    else
        umount "${destdir}/${mount_point}";
		rmdir "${destdir}/${mount_point}";
        rm -f /tmp/SDDevNode
        sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
        #echo "status=failed" > /tmp/transfer_state
        #echo "18;0;" > /tmp/MCU_Cmd
    fi

}


my_mount()
{
    echo "$dev SD:$SDdev HD:$HDDdev"
    timeoffset=`cat /etc/timezone_offset`
    if [ "$timeoffset" == "" ]; then
        timeoffset=-8
    fi


    if [ "${timeoffset}" != "" ];then
        timeoffset_min=`dc ${timeoffset} 60 mul p`
        timeoffset_min_exfat=`dc ${timeoffset} -60 mul p`
    else
        timeoffset_min=-480
        timeoffset_min_exfat=480
    fi
    mount_point=`blkid /dev/$1 | sed -n 's/.*UUID="\([^"]*\)".*/\1/p'`
    if [ "${mount_point}" == "" ]; then
        mount_point=`blkid /dev/$1 | sed -n 's/.*UUID="\([^"]*\)".*/\1/p'`
	if [ "${mount_point}" == "" ]; then
		mount_point=SDCard_$1
	fi
    fi
    echo "43;1" > /tmp/MCU_Cmd
    mounted=`mount | grep "${destdir}/${mount_point} " | wc -l`
    if [ ${mounted} -eq 1 ]; then
        umount "${destdir}/${mount_point}";
    fi   
    
    mkdir -p "${destdir}/$mount_point" || exit 1

    isFAT32=`blkid /dev/$1 | grep vfat | wc -l`
 
    if [ $isFAT32 -eq 1 ]; then
       fstype=vfat
       isMounted=`mount | grep "$1 " | wc -l`
       if [ $isMounted -eq 0 ]; then
           isDirty=`fsck.fat -n "/dev/$1" | grep "Dirty bit is set"  | wc -l`
       fi
       if ! mount -t auto -o async,utf8=1,noatime,nodiratime,time_offset=${timeoffset_min} "/dev/$1" "${destdir}/$mount_point"; then
           rmdir "${destdir}/${mount_point}"
           /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} &
           echo "43;0" > /tmp/MCU_Cmd
           exit 1
       fi
       echo "18;2;" > /tmp/MCU_Cmd
    else
       mkdir -p "${destdir}/${mount_point}" || exit 1
       echo "${PPID} Mount on $1" >> /tmp/automount.log
       fstype=ufsd
       isMounted=`mount | grep "$1 " | wc -l`
       if [ $isMounted -eq 0 ]; then
           isDirty=`blkid /dev/$1 | grep DIRTY | wc -l`
       fi
       isExFat=`blkid /dev/$1 | grep exfat | wc -l`
       if [ $isExFat -eq 1 ]; then
           if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000,bias=${timeoffset_min_exfat} "/dev/$1" "${destdir}/$mount_point"; then
               # failed to mount, clean up mountpoint
               rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
               /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} &
               echo "43;0" > /tmp/MCU_Cmd
               exit 1
           fi
       else
           if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000 "/dev/$1" "${destdir}/$mount_point"; then
               # failed to mount, clean up mountpoint
               rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
               /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} &
               echo "43;0" > /tmp/MCU_Cmd
               exit 1
           fi
       fi
       echo "18;2;" > /tmp/MCU_Cmd
    fi
    sleep 2
    mounted=`mount | grep "$1 " | wc -l`
    TryMount=0
    TryMountMax=5
    while [ ${mounted} -eq 0 ]; do
        echo "${PPID} Re Check SD Mount - ${TryMount}"  >> /tmp/automount.log
        sleep 3
        mounted=`mount | grep "$1 " | wc -l`
        if [ ${mounted} -eq 0 ] && [ ${TryMount} -gt ${TryMountMax} ] ; then
            echo "${PPID} SD Mount failed"  >> /tmp/automount.log
            rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
            foundpartitions=`cat /proc/partitions | grep " $1" | wc -l`
            if [ ${foundpartitions} -eq 1 ]; then
                echo "${PPID} Found in partitions, Re-Trigger"  >> /tmp/automount.log
                echo add > /sys/block/mmcblk0/$1/uevent
            fi
            echo "43;0" > /tmp/MCU_Cmd
            exit 1
        fi
        TryMount=`expr "${TryMount}" + 1`
    done
    if [ ${isDirty} -ne 0 ]; then
        /usr/local/sbin/sendAlert.sh 0008 &
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
    if [ ${shared} -eq 0 ]; then
      if [ "$mount_point" == "SDcard" ]; then
        echo "/dev/${SDdev}" > /tmp/SDDevNode
    	fi
    fi
    echo 4096 > /sys/block/mmcblk0/bdi/read_ahead_kb
    /sbin/addDevice.sh SDcard $1 ${destdir}/${mount_point} ${fstype}
}

echo "${PPID} ${ACTION} ${DEVNAME} $1 $2 $3 $4" >> /tmp/automount.log
#Block event when system just resume
#pmxrtpm=`cat /proc/scsi/pmxrtpm`
#if [ ${pmxrtpm} -eq 0 ]; then
#    exit
#fi
                                                             
case "${ACTION}" in
add|"")
    echo "SDa $1 Coming"
    check_DeviceNode
    isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
    if [ ${isKnownType} -eq 0 ]; then
        echo "$1 Type Unknown!!"
        exit 1
    fi
    echo "SD ADD event of $1"
    isGPT=`blkid /dev/$1 | grep -i "efi system" | wc -l`
    if [ ${isGPT} -eq 1 ]; then
          echo "***GPT found, ignore $1***"
          exit 1
    fi
    my_mount $1
    echo "SDd $1 Coming"
    ;;
remove)
    echo "####${ACTION}####"
    echo "do remove" >> /tmp/automount.log
    my_umount $1
    ;;
esac
