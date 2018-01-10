#!/bin/sh

source /etc/power.conf
devstr=$1
destdir=/media
dev=${devstr:0:3}
ishddrive=1

isCacheEnabled=0
CacheModName=pmxcache

check_pmxcache(){
    lsmod | grep -q "pmxcache"
    if [ $? -eq 0 ]; then
        lsmod | grep -q "pmxfs"
        [ $? -eq 0 ] && isCacheEnabled=1
    fi
}

connect_alert_database()
{
    HDDSpace=`df | grep /DataVolume | awk '{print $4}'`
    if [ ! -d "/CacheVolume/.wd-alert" ] && [ $HDDSpace -lt 1124000 ]; then
        if [ ! -d "/media/sdb1/.wdcache" ]; then
            rm -rf /CacheVolume
            rm -rf /var/tmp
            ln -sf ../tmp /var/tmp
        fi
    else
        checklink=`ls -l /CacheVolume | grep "/media/sdb1/.wdcache" | wc -l`
        if [ "$checklink" == "0" ] && [ $HDDSpace -gt 1124000 ] ; then
            if [ ! -d "/media/sdb1/.wdcache" ]; then
                mkdir -p /media/sdb1/.wdcache
            fi
            mv /CacheVolume/* /media/sdb1/.wdcache/
            rm -Rf /CacheVolume
            ln -sf /media/sdb1/.wdcache /CacheVolume
        fi
    fi 
    if [ ! -d /etc/wd-alert ]; then
        mkdir -p /etc/wd-alert
    fi
    if [ -L /CacheVolume/.wd-alert ]; then
        checklink=`ls -l /CacheVolume/.wd-alert | grep "/etc/wd-alert" | wc -l`
        if [ "$checklink" == "0" ]; then
            rm -Rf /CacheVolume/.wd-alert
            ln -sf /etc/wd-alert /CacheVolume/.wd-alert 
        fi
    else
        if [ -f /CacheVolume/.wd-alert/wd-alert.db ]; then
            cp /CacheVolume/.wd-alert/wd-alert.db /etc/wd-alert/
        fi
        if [ -f /CacheVolume/.wd-alert/wd-alert-desc.db ]; then
            cp /CacheVolume/.wd-alert/wd-alert-desc.db /etc/wd-alert/
        fi
        rm -Rf /CacheVolume/.wd-alert
        ln -sf /etc/wd-alert /CacheVolume/.wd-alert 
    fi
}

my_check()
{
    if [ $ishddrive -eq 1 ]; then
        fstype=`blkid /dev/$1 | sed -n 's/.*TYPE="\([^"]*\)".*/\1/p'`
        echo "${PPID} FStype $fstype on $1" >> /tmp/automount.log
        if [ "$fstype" == "exfat" ]; then
            if [ ! -f /tmp/StartupHDDChecked ]; then
                chkexfat -f --safe /dev/$1
                result=$?
                echo "Quick Testing Result on $1: $result"
                touch /tmp/StartupHDDChecked
                if [ "$result" != "1" ]; then
                    echo "${PPID} exFAT Quick check Failed" >> /tmp/automount.log
                    chkexfat -f /dev/$1
                else
                    echo "${PPID} exFAT Quick check Passed" >> /tmp/automount.log
                fi
            fi
        fi
        if [ "$fstype" == "ntfs" ]; then
            if [ ! -f /tmp/StartupHDDChecked ]; then
                chkntfs -f --safe /dev/$1
                result=$?
                echo "Quick Testing Result on $1: $result"
                touch /tmp/StartupHDDChecked
                if [ "$result" != "252" ]; then
                    if [ "$result" == "1" ];then
                        echo "${PPID} NTFS Quick check Passed" >> /tmp/automount.log
                    else
                        echo "${PPID} NTFS Quick check Failed" >> /tmp/automount.log
                        chkntfs -f /dev/$1
                    fi
                else
                    echo "${PPID} NTFS Quick on Read Only" >> /tmp/automount.log
                fi
            else
                echo "{PPID} Quick Checked"
            fi
        fi
        if [ "$fstype" == "hfsplus" ]; then
            if [ ! -f /tmp/StartupHDDChecked ]; then
                chkhfs -f --safe /dev/$1
                result=$?
                echo "Quick Testing Result on $1: $result"
                touch /tmp/StartupHDDChecked
                if [ "$result" != "1" ]; then
                    echo "${PPID} HFS Quick check Failed" >> /tmp/automount.log
                    chkhfs -f /dev/$1
                else
                    echo "${PPID} HFS Quick check Passed" >> /tmp/automount.log
                fi
            fi
        fi
    fi
}

check_HFS_dir_permission()
{
    isHFSplus=`blkid /dev/$1 | sed -n 's/.*TYPE="\([^"]*\)".*/\1/p'`
    # echo "isHFSplus ${isHFSplus}" >> /tmp/automount.log
	
    if [ "$isHFSplus" == "hfsplus" ]; then
        perm=`ls -ld /shares/Storage | awk '{ print $1 }' | sed 's/-//g'`		
        if [ "${#perm}" -ne 10 ]; then
            chmod 777 /shares/Storage -R
            echo "change permission for /share/Storage" >> /tmp/automount.log
        fi
    fi
}

my_mount()
{
    echo "${PPID} ${dev} USB:${USBdev} HD:${HDDdev}" >> /tmp/automount.log

    mount_type=Internal
    add_video_format
    mount_point=sdb1
	
		
    mkdir -p "${destdir}/${mount_point}" || exit 1

    isFAT32=`blkid /dev/$1 | grep vfat | wc -l`

    if [ ${isFAT32} -eq 1 ]; then
        fstype=vfat
        isDirty=`fsck.fat -n "/dev/$1" | grep "Dirty bit is set"  | wc -l`
        check_pmxcache
        if [ $isCacheEnabled -eq 1 ]; then
            isMounted=`mount | grep -c "/media/sdb1 type ${CacheModName}"`
            if [ $isMounted -eq 0 ]; then
                if ! mount -t ${CacheModName} -o ${CacheModName}=pmxfs "/dev/$1" "${destdir}/$mount_point"; then
                    rmdir "${destdir}/$mount_point"
                    /sbin/StorageAlert.sh $mount_point $devstr $dev & 
                    exit 1
                fi
            fi
        else
            if ! mount -t auto -o async -o utf8=1 "/dev/$1" "${destdir}/${mount_point}"; then
                rmdir "${destdir}/${mount_point}"
                /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} &
                exit 1
            fi
        fi
    else
        fstype=ufsd
        isDirty=`blkid /dev/$1 | grep DIRTY | wc -l`
        mkdir -p "${destdir}/${mount_point}" || exit 1
        echo "${PPID} Mount on $1" >> /tmp/automount.log
        check_pmxcache
        if [ $isCacheEnabled -eq 1 ]; then
            isMounted=`mount | grep -c "/media/sdb1 type ${CacheModName}"`
            if [ $isMounted -eq 0 ]; then
                isDiscard=`cat /etc/TRIM_Enable`
                if [ ${isDiscard} = "" ];then
                    isDiscard=0
                fi
                if [ ${isDiscard} -eq 1 ]; then
                    mountOpt="async,force,fmask=0000,dmask=0000,discard"
                else
                    mountOpt="async,force,fmask=0000,dmask=0000"
                fi		    
                if ! mount -t ${CacheModName} -o "${CacheModName}=pmxfs,${mountOpt}" "/dev/$1" "${destdir}/${mount_point}"; then
                    rmdir "${destdir}/${mount_point}"
                    /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
                    exit 1
                fi
            else
                echo "${PPID} Already mount on $1" >> /tmp/automount.log
                exit 1
            fi
        else
            if ! mount -t ufsd -o "${mountOpt}" "/dev/$1" "${destdir}/${mount_point}"; then
                # failed to mount, clean up mountpoint
                rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
                /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
                echo "${PPID} Already mount on $1 or mount fail" >> /tmp/automount.log
                exit 1
            fi
        fi
    fi
    
    mounted=`mount | grep "$1 " | wc -l`
    if [ ${mounted} -eq 0 ]; then
        rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
        exit 1
    fi
    if [ ${isDirty} -ne 0 ]; then
        /usr/local/sbin/sendAlert.sh 0007 &
    fi
    if [ ${ishddrive} -eq 1 ]; then
        isDataV=`mount | grep "DataVolume" | wc -l`
        if [ ${isDataV} -eq 0 ]; then
            mount /media/sdb1 /DataVolume
            mount --bind /media/sdb1 /shares/Storage

            check_HFS_dir_permission $1

            if [ ! -f /tmp/HDSerial ]; then
                HDSerial_temp=`hdparm -I \`cat /tmp/HDDDevNode\` | sed -n -e 's/.*Serial Number:\(.*\)/\1/p' | sed -e 's/^[ \t]*//' | awk '{gsub("WD-","",$0); print $0}'`
                HDSerial=${HDSerial_temp// /}
                echo "${HDSerial}" > /tmp/HDSerial
            else
                HDSerial=`cat /tmp/HDSerial`
            fi
            result=`sqlite3 /usr/local/nas/orion/orion.db 'select * from Volumes' | grep "${HDSerial}"_1  | wc -l`
            if [ ${result} == "0" ]; then
                /usr/local/sbin/volume_mount.sh mount "${HDSerial}"_1 "" "/dev/$1" ${fstype}
            fi
        fi
        #echo "/dev/${HDDdev}" > /tmp/HDDDevNode
        echo "/dev/$1" > /tmp/MountedDevNode
        rm /var/tmp
        ln -s /CacheVolume /var/tmp

        #factory_conf="/etc/nas/config/factory.conf"
        #if [ ! -f $factory_conf ] ||  [ `grep FACTORY_MODE $factory_conf | wc -l` != "1" ] || [ `grep FACTORY_MODE $factory_conf | awk -F= '{print $2}'` != "1" ]; then
        if [ ! -f /media/sdb1/.wdcache ]; then
            mkdir -p /media/sdb1/.wdcache
        fi
        if [ ! -f /media/sdb1/.wdcache/coredump ]; then
            mkdir -p /media/sdb1/.wdcache/coredump
        fi
        connect_alert_database
        if [ ! -L /var/lib/systemd/coredump ]; then
            mv /var/lib/systemd/coredump/* /media/sdb1/.wdcache/coredump/
            rmdir /var/lib/systemd/coredump
            ln -sf /media/sdb1/.wdcache/coredump /var/lib/systemd/coredump
        fi
    fi
}

#Video format for FUSE(file cache)
add_video_format()
{
    if [ -f /tmp/videoformat ]; then
        rm /tmp/videoformat
    fi
    if [ ! -f /usr/local/wdmcserver/bin/mime_types.txt ]; then
        echo .mp4 >> /tmp/videoformat	
        echo .avi >> /tmp/videoformat	
        echo .wmv >> /tmp/videoformat	
        echo .rm >> /tmp/videoformat	
        echo .rmvb >> /tmp/videoformat	
        echo .mov >> /tmp/videoformat	
        echo .dat >> /tmp/videoformat	
        echo .m1v >> /tmp/videoformat	
        echo .mp3 >> /tmp/videoformat	
        echo .wma >> /tmp/videoformat	
        echo .mkv >> /tmp/videoformat	
   else
        cat /usr/local/wdmcserver/bin/mime_types.txt | grep video/  > /tmp/mime_types.tmp1
        sed '/#/d' /tmp/mime_types.tmp1 > /tmp/mime_types.tmp2
        awk '{ {if($2!="")print "."$2} {if($3!="")print "."$3} {if($4!="")print "."$4}  {if($5!="")print "."$5} }' /tmp/mime_types.tmp2  > /tmp/videoformat1
        cat /tmp/videoformat1 | awk -F'\t' '{print $1}' | tr '\n' ', ' > /tmp/videoformat
        rm /tmp/videoformat1
        rm /tmp/mime_types.tmp1
        rm /tmp/mime_types.tmp2	
   fi
}

action_add_internal_hdd()
{
    isHdrType=`blkid /dev/$1 | grep "PTTYPE=" | wc -l`
    if [ ${isHdrType} -ne 0 ]; then
        isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
        if [ ${isKnownType} -eq 0 ]; then
            echo "$1 is Header Type!!"
            return
        fi
    fi

    isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
    if [ ${isKnownType} -eq 0 ]; then
        echo "$1 Type Unknown!!"
        return
    fi

    isHDDMount=`grep /dev/$1 /proc/mounts | wc -l`
    if [ ${isHDDMount} -eq 1 ]; then
       echo "HDD already mounted"
    else
      echo "Try to Mounte HDD"
      isGPT=`blkid /dev/$1 | grep -i "efi system" | wc -l`
      if [ ${isGPT} -eq 1 ]; then
           echo "***GPT found, ignore $1***"
           return
      fi
        #my_check $1
        my_mount $1
    fi        
}

#echo "${PPID} ${ACTION} ${DEVNAME} $1 $2 $3 $4" >> /tmp/automount.log

#Find all sda [Internal HDD]
echo "/dev/sda" > /tmp/HDDDevNode
ALLSDA=`cd /dev && ls -1 sda*`
umask 0000
for SDA in $ALLSDA ; do
    if [ $SDA != "" ]; then
        echo "Find $SDA"
        action_add_internal_hdd $SDA
    fi 
done 

