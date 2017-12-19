#!/bin/sh

source /etc/power.conf
devstr=$1
destdir=/media
dev=${devstr:0:3}

isCacheEnabled=0
CacheModName=pmxcache

check_pmxcache(){
	lsmod | grep -q "pmxcache"
	if [ $? -eq 0 ]; then
		lsmod | grep -q "avplg"
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

check_DeviceNode()
{
    ishddrive=0
    isusbdrv=0
    if [ ! -f /tmp/USBDevNode ]; then
        echo "41;1;" > /tmp/MCU_Cmd
        echo "" >  /tmp/USBdeviceAttached
    fi
    
}

my_umount()
{
    if [ -f /tmp/USBDevNode ]; then
        USBdev=`cat /tmp/USBDevNode | cut -c 6-8`
    fi
    if [ -f /tmp/USBdeviceAttached ]; then
	echo "41;2;" > /tmp/MCU_Cmd
	rm -f /tmp/USBdeviceAttached
    fi
    echo "${PPID} my_umount $dev $USBdev" >> /tmp/automount.log
    if [ "$dev" == "$USBdev" ]; then
        mount_type=USB
	mount_point=`cat /tmp/$1-info | cut -f 3 -d ':' | cut -c 8-`
    else
        mount_type=Internal
	mount_point=sdb1
    fi
    /sbin/removeDevice.sh USB $1
    if grep -qs "^/dev/$1 " /proc/mounts ; then
        umount /dev/$1;
    fi

    [ -d "${destdir}/${mount_point}" ] && umount -f "${destdir}/${mount_point}" && rmdir "${destdir}/${mount_point}"
    sleep 1
    if [ "${mount_type}" == "USB" ]; then
       sleep 1
       if [ ! -d "${destdir}/${mount_point}" ]; then
           rm -f /tmp/USBDevNode
           #sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
           sed -i 's/USB_TransferStatus=.*/USB_TransferStatus=completed/' /etc/nas/config/usb-transfer-status.conf
       	   #echo "status=failed" > /tmp/transfer_state
       	   #echo "18;0;" > /tmp/MCU_Cmd
       else
           umount "${destdir}/${mount_point}";
           rmdir "${destdir}/${mount_point}";
           rm -f /tmp/USBDevNode
           #sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
           sed -i 's/USB_TransferStatus=.*/USB_TransferStatus=completed/' /etc/nas/config/usb-transfer-status.conf
           #echo "status=failed" > /tmp/transfer_state
           #echo "18;0;" > /tmp/MCU_Cmd
       fi
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

my_mount()
{
    echo "${PPID} ${dev} USB:${USBdev} HD:${HDDdev}" >> /tmp/automount.log
    if [ "${dev}" == "${USBdev}" ]; then
    	echo "43;1" > /tmp/MCU_Cmd
		mount_type=USB
		mount_point=`blkid /dev/$1 | sed -n 's/.*UUID="\([^"]*\)".*/\1/p'`
		if [ "${mount_point}" == "" ]; then
			mount_point=`blkid /dev/$1 | sed -n 's/.*UUID="\([^"]*\)".*/\1/p'`
			if [ "${mount_point}" == "" ]; then
				mount_point=USBDevice_$1
			fi
		fi
        mounted=`mount | grep "${destdir}/${mount_point} " | wc -l`
        if [ ${mounted} -eq 1 ]; then
            umount "${destdir}/${mount_point}";
        fi   
    else
        mount_type=Internal
        add_video_format
       	mount_point=sdb1
    fi
		
    mkdir -p "${destdir}/${mount_point}" || exit 1

    isFAT32=`blkid /dev/$1 | grep vfat | wc -l`
 
    if [ ${isFAT32} -eq 1 ]; then
        fstype=vfat
        isMounted=`mount | grep "$1 " | wc -l`
        if [ $isMounted -eq 0 ]; then
            isDirty=`fsck.fat -n "/dev/$1" | grep "Dirty bit is set"  | wc -l`
        fi
        if [ "${mount_type}" == "USB" ]; then
            mkdir -p "${destdir}/${mount_point}" || exit 1
            if ! mount -t auto -o async -o utf8=1 "/dev/$1" "${destdir}/${mount_point}"; then
                rmdir "${destdir}/${mount_point}"
              	/sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
              	echo "43;0" > /tmp/MCU_Cmd
              	exit 1
            fi
        else
	    	check_pmxcache
	   		if [ $isCacheEnabled -eq 1 ]; then
				isMounted=`mount | grep -c "/media/sdb1 type ${CacheModName}"`
				if [ $isMounted -eq 0 ]; then
		   			if ! mount -t ${CacheModName} -o ${CacheModName}=avplg "/dev/$1" "${destdir}/$mount_point"; then
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
        fi
    else
        fstype=ufsd
        isMount=`mount | grep "$1 " | wc -l`
        if [ $isMount -eq 0 ]; then
            isDirty=`blkid /dev/$1 | grep DIRTY | wc -l`
        fi
        if [ "$mount_type" == "USB" ]; then
	    isMounted=`mount | grep -c "${destdir}/${mount_point} type ${fstype}"`
	    	if [ ${isMounted} -ne 0 ]; then
	    		echo "43;0" > /tmp/MCU_Cmd
            	echo "${PPID} Mount on $1 Already" >> /tmp/automount.log
				exit 1
	    	fi
            mkdir -p "${destdir}/${mount_point}" || exit 1
            if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000 "/dev/$1" "${destdir}/${mount_point}"; then
                rmdir "${destdir}/${mount_point}"
              	/sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
                # my_check $1
                #if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000 "/dev/$1" "${destdir}/$mount_point"; then
                #    rmdir "${destdir}/$mount_point_fuse"
                #    /sbin/StorageAlert.sh $mount_point $devstr $dev &
                #    exit 1
                #fi
            fi
        else
            mkdir -p "${destdir}/${mount_point}" || exit 1
            echo "${PPID} Mount on $1" >> /tmp/automount.log
            check_pmxcache
	    if [ $isCacheEnabled -eq 1 ]; then
		isMounted=`mount | grep -c "/media/sdb1 type ${CacheModName}"`
		if [ $isMounted -eq 0 ]; then
		    mountOpt="async,force,fmask=0000,dmask=0000"
		    if ! mount -t ${CacheModName} -o ${CacheModName}=avplg,${mountOpt} "/dev/$1" "${destdir}/${mount_point}"; then
                        rmdir "${destdir}/${mount_point}"
              	        /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
              	        echo "43;0" > /tmp/MCU_Cmd
              	        exit 1
                    fi
		else
                    echo "${PPID} Already mount on $1" >> /tmp/automount.log
                    exit 1
		fi
	    else
		if ! mount -t ufsd -o trace=off,async,force,fmask=0000,dmask=0000 "/dev/$1" "${destdir}/${mount_point}"; then
                     # failed to mount, clean up mountpoint
                    rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
                    /sbin/StorageAlert.sh ${mount_point} ${devstr} ${dev} & 
                    echo "${PPID} Already mount on $1 or mount fail" >> /tmp/automount.log
                    echo "43;0" > /tmp/MCU_Cmd
                    exit 1
                fi
            fi
        fi
    fi
    
    mounted=`mount | grep "$1 " | wc -l`
    if [ ${mounted} -eq 0 ]; then
        rmdir "${destdir}/${mount_point}" 2>&1 > /dev/null
        echo "43;0" > /tmp/MCU_Cmd
        exit 1
    fi

    if [ ${isDirty} -ne 0 ]; then
        /usr/local/sbin/sendAlert.sh 0009 &
    fi
    if [ ${ishddrive} -eq 1 ]; then
    	isDataV=`mount | grep "DataVolume" | wc -l`
    	if [ ${isDataV} -eq 0 ]; then
        	mount /media/sdb1 /DataVolume
        	mount --bind /media/sdb1 /shares/Storage
        	if [ ! -f /tmp/HDSerial ]; then
        		HDSerial=`hdparm -I \`cat /tmp/HDDDevNode\` | sed -n -e 's/.*Serial Number:\(.*\)/\1/p' | sed -e 's/^[ \t]*//' | awk '{gsub("WD-","",$0); print $0}'`
        		echo "$HDSerial" > /tmp/HDSerial
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
        connect_alert_database
        #fi
    fi
    if [ ${isusbdrv} -eq 1 ]; then
    	killall -16 ghelper
    fi
    if [ "$mount_type" == "USB" ]; then
		mounted=`mount | grep "/dev/$1 " | wc -l`
		if [ ${mounted} -gt 0 ]; then
    		echo "/dev/${USBdev}" > /tmp/USBDevNode
			echo 4096 > /sys/block/${USBdev}/bdi/read_ahead_kb
    		sleep 3
			mounted=`mount | grep "/dev/$1 " | wc -l`
			if [ ${mounted} -eq 0 ]; then
				if [ ! -f /tmp/autoMountRetry ]; then
					echo 0 > /tmp/autoMountRetry
				fi
				RetryVal=`cat /tmp/autoMountRetry`
				RetryVal=`expr $RetryVal + 1`
				if [ ${RetryVal} -lt 3 ]; then
					echo "${RetryVal}" > /tmp/autoMountRetry
					echo "${PPID} RRetry with ${USBdev} $1 ${RetryVal}" >> /tmp/automount.log
					sleep 5
					echo "add" > /sys/block/${USBdev}/$1/uevent
				else
					rm -f /tmp/autoMountRetry
				fi
			else
				/sbin/addDevice.sh USB $1 ${destdir}/${mount_point} $fstype
				rm -f /tmp/autoMountRetry
			fi
		else
			if [ ! -f /tmp/autoMountRetry ]; then
				echo 0 > /tmp/autoMountRetry
			fi
			RetryVal=`cat /tmp/autoMountRetry`
			RetryVal=`expr $RetryVal + 1`
			if [ ${RetryVal} -lt 3 ]; then
				echo "${RetryVal}" > /tmp/autoMountRetry
				echo "${PPID} Retry with ${USBdev} $1 ${RetryVal}" >> /tmp/automount.log
				sleep 5
				echo "add" > /sys/block/${USBdev}/$1/uevent
			else
				rm -f /tmp/autoMountRetry
			fi
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

echo "${PPID} ${ACTION} ${DEVNAME} $1 $2 $3 $4" >> /tmp/automount.log
#Block event when system just resume
#pmxrtpm=`cat /proc/scsi/pmxrtpm`
#if [ ${pmxrtpm} -eq 0 ]; then
#    exit
#fi
                                                              
case "${ACTION}" in
add|"")
    
    check_DeviceNode
    if [ "${DEVNAME}" == "$1" ] && [ ${ishddrive} -eq 1 ] ; then
        exit 1
    fi
    isHdrType=`blkid /dev/$1 | grep "PTTYPE=" | wc -l`
    if [ ${isHdrType} -ne 0 ]; then
        isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
    	if [ ${isKnownType} -eq 0 ]; then
        	 echo "$1 is Header Type!!"
        	exit 1
    	fi
    fi

    isKnownType=`blkid /dev/$1 | grep " TYPE=" | wc -l`
    if [ ${isKnownType} -eq 0 ]; then
        echo "$1 Type Unknown!!"
        exit 1
    fi
    USBdev=$dev
    isusbdrv=1
    echo "/dev/${USBdev}" > /tmp/USBDevNodes
    
    if [ -f /tmp/USBDevNode ]; then
        USBdev=`cat /tmp/USBDevNode | cut -c 6-8`
    fi
    if [ "$dev" == "$USBdev" ]; then
          echo "USB ADD event of $1"
          isGPT=`blkid /dev/$1 | grep EFI | wc -l`
          if [ $isGPT -eq 1 ]; then
                echo "***GPT found, ignore $1***"
                exit 1
	  fi
          my_mount $1
    fi

    if [ ${ishddrive} -eq 1 ]; then
        isHDDMount=`grep /dev/$HDDdev /proc/mounts | wc -l`
        if [ ${isHDDMount} -eq 1 ]; then
            echo "HDD already mounted"
        else
            echo "Try to Mounte HDD"
            isGPT=`blkid /dev/$1 | grep EFI | wc -l`
            if [ ${isGPT} -eq 1 ]; then
                echo "***GPT found, ignore $1***"
                exit 1
            fi
            #my_check $1
            my_mount $1
        fi
    fi
    ;;
change)
    BlockSize=`cat /sys/block/${DEVNAME}/size`
    NoOfParations=`cat /proc/partitions | grep ${DEVNAME} | wc -l`
    NoOfMount=`mount | grep ${DEVNAME} | wc -l`
    echo "${PPID} ${NoOfParations}, ${NoOfMount}, ${BlockSize}" >> /tmp/automount.log
    if [ ${NoOfParations} -eq 0 ] && [ ${NoOfMount} -eq 0 ]; then
        sleep 1
        echo add > /sys/block/${DEVNAME}/uevent
        exit 0
    fi
    if [ ${NoOfParations} -eq 0 ] && [ ${NoOfMount} -ne 0 ]; then
        Parations=`realpath /sys/block/${DEVNAME}/${DEVNAME}*`
        for device in ${Parations} ; do
            echo "${PPID} echo remove to ${Parations}/uevent" >> /tmp/automount.log
            echo remove > "${Parations}/uevent"
        done
        echo "${PPID} echo remove to /sys/block/${DEVNAME}/uevent" >> /tmp/automount.log
        echo remove > /sys/block/${DEVNAME}/uevent
    fi
    ;;
remove)
    echo "####${ACTION}####"
    #isMounted=`mount | grep -c "/dev/$1 on"`
    #[ ${isMounted} -eq 0 ] && echo "$1 is not mounted, exit" >> /tmp/automount.log && exit 1
    echo "${PPID} do remove $1" >> /tmp/automount.log
    my_umount $1
    ;;
esac
