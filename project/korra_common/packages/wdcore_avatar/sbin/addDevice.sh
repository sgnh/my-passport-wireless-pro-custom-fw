#!/bin/bash

echo "${PPID} $1 $2 $3 $4" >> /tmp/addDeviceLogs.log

DeviceType=$1
DevicePartitionNode=$2
DeviceMountPath=$3
DeviceFSType=$4

VolumeName=`blkid -d /dev/$2 | sed -n 's/.* LABEL="\([^"]*\)".*/\1/p'`
devicefound=`cat /tmp/detectInterface`
if [ "${devicefound}" == "MTP" ] && [ "${DeviceType}" == "USB" ]; then
	VolumeUUID="MTP"
elif [ "${devicefound}" == "PTP" ] && [ "${DeviceType}" == "USB" ]; then
	VolumeUUID="PTP"
else
	VolumeUUID=`blkid /dev/$2 | sed -n 's/.*UUID="\([^"]*\)".*/\1/p'`
	if [ "${VolumeUUID}" == "" ]; then
		if [ "${DeviceType}" == "USB" ]; then
			dcim_check=`find /media/USBDevice_${2} -type d -maxdepth 1 -name "DCIM"`
			if [ "$dcim_check" != "" ]; then
				VolumeUUID=`stat -c %Z /media/USBDevice_${2}/DCIM`
			else
				folder_check=`find /media/USBDevice_${2} -type d -maxdepth 1 | tail -1`
				VolumeUUID=`stat -c %Z "${folder_check}"`
			fi
		elif [ "${DeviceType}" == "SDcard" ]; then
			dcim_check=`find /media/SDCard_${2} -type d -maxdepth 1 -name "DCIM"`
			if [ "$dcim_check" != "" ]; then
				VolumeUUID=`stat -c %Z /media/SDCard_${2}/DCIM`
			else
				folder_check=`find /media/SDCard_${2} -type d -maxdepth 1 | tail -1`
				VolumeUUID=`stat -c %Z "${folder_check}"`
			fi
		fi	
		#fattype=`fdisk -l | grep $2 | grep FAT32`
        #echo "${PPID} ${fattype} " >> /tmp/addDeviceLogs.log
        #if [ "${fattype}" != "" ]; then
        #    ExtendBoot=`dd bs=1 skip=66 count=1 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #    echo "${PPID}" "ExtendBoot" "${ExtendBoot} " >> /tmp/addDeviceLogs.log
  		#	if [ "${ExtendBoot}" == "29" ]; then  
        #    	sectorDump=`dd bs=1 skip=67 count=4 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #    	echo "${PPID} ${sectorDump} " >> /tmp/addDeviceLogs.log
        #    	if [ "${sectorDump}" == "00000000" ]; then
        #        	dd if=/dev/urandom of=/dev/$2 bs=1 count=4 seek=67
        #        	sectorDump=`dd bs=1 skip=67 count=4 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #        	echo "${PPID} ${sectorDump} " >> /tmp/addDeviceLogs.log
        #        	if [ "${sectorDump}" != "00000000" ]; then
        #            	VolumeUUID=`echo "${sectorDump}" | awk -vFS="" '{print $7$8$5$6"-"$3$4$1$2}'`
        #        	fi
        #    	else
        #        	VolumeUUID="${sectorDump}"
        #    	fi
        #    fi
        #else
        #    fattype=`fdisk -l | grep $2 | grep FAT16`
        #    echo "${PPID} ${fattype} " >> /tmp/addDeviceLogs.log
        #    if [ "${fattype}" != "" ]; then
        #    	ExtendBoot=`dd bs=1 skip=38 count=1 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #    	echo "${PPID}" "ExtendBoot" "${ExtendBoot} " >> /tmp/addDeviceLogs.log
  		#		if [ "${ExtendBoot}" == "29" ]; then          
        #        	sectorDump=`dd bs=1 skip=39 count=4 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #        	echo "${PPID} ${sectorDump} " >> /tmp/addDeviceLogs.log
        #        	if [ "${sectorDump}" == "00000000" ]; then
        #            	dd if=/dev/urandom of=/dev/$2 bs=1 count=4 seek=39
        #            	sectorDump=`dd bs=1 skip=39 count=4 if=/dev/$2 | hexdump -ve '1/1 "%02X"'`
        #            	echo "${PPID} ${sectorDump} " >> /tmp/addDeviceLogs.log
        #            	if [ "${sectorDump}" != "00000000" ]; then
        #                	VolumeUUID=`echo "${sectorDump}" | awk -vFS="" '{print $7$8$5$6"-"$3$4$1$2}'`
        #                	#VolumeUUID="${sectorDump}"
        #            	fi
        #        	else
        #            	VolumeUUID="${sectorDump}"
        #        	fi
        #        fi
        #    fi
        #fi

		if [ "${VolumeUUID}" == "" ]; then
			if [ "${DeviceType}" == "USB" ]; then
				VolumeUUID=USBDevice_$2
			fi
			if [ "${DeviceType}" == "SDcard" ]; then
				VolumeUUID=SDCard_$2
			fi
		fi
	fi
fi

if [ "${DeviceType}" == "SDcard" ]; then
	StorageType=SDCARD
	DeviceNode=${DevicePartitionNode:0:7}
	PartitionNO=${DevicePartitionNode:8:10}
	DeviceVendor=`/sbin/mmc_name /dev/${DeviceNode}` 
	DeviceProduct_temp=`cat /sys/block/${DeviceNode}/device/name`
	DeviceProduct=${DeviceProduct_temp//[[:blank:]]/}
	DeviceSerialNumber_temp=`cat /sys/block/${DeviceNode}/device/serial | cut -c 3-`
	DeviceSerialNumber=${DeviceSerialNumber_temp//[[:blank:]]/}
	DeviceRev=`cat /sys/block/${DeviceNode}/device/hwrev`
	DeviceLock=`cat /sys/block/${DeviceNode}/ro`
	if [ "${DeviceLock}" == "1" ]; then
		DeviceLock=security_on
	else
		DeviceLock=security_off
	fi
	echo "${DeviceNode}:${DeviceVendor}:${DeviceProduct}:${DeviceSerialNumber}:${DeviceRev}:${DeviceLock}" > /tmp/$DeviceNode-device
	echo "${PPID} ${DeviceNode}:${DeviceVendor}:${DeviceProduct}:${DeviceSerialNumber}:${DeviceRev}:${DeviceLock} to /tmp/$DeviceNode-device" >> /tmp/addDeviceLogs.log
fi

if [ "${DeviceType}" == "USB" ]; then
	StorageType=USB
	DeviceNode=${DevicePartitionNode:0:3}
	PartitionNO=${DevicePartitionNode:3:5}
	if [ "${devicefound}" == "MTP" ]; then
		DeviceNode=mtpfs
		DevicePartitionNode=sdmtpfs
		echo "mtp device is found." >> /tmp/addDeviceLogs.log
		echo "${PPID} ${DeviceNode} ${DevicePartitionNode}" >> /tmp/addDeviceLogs.log
	elif [ "${devicefound}" == "PTP" ]; then
		DeviceNode=ptpfs
		DevicePartitionNode=sdptpfs
		echo "ptp device is found." >> /tmp/addDeviceLogs.log
		echo "${PPID} ${DeviceNode} ${DevicePartitionNode}" >> /tmp/addDeviceLogs.log
	else
		DeviceUSBStorageNO=`ls /sys/block/$DeviceNode/device/scsi_disk | cut -f 1 -d ':'`
		DeviceVendor_temp=`cat /proc/scsi/usb-storage/${DeviceUSBStorageNO} | sed -n -e 's/.*Vendor: \(.*\)/\1/p'`
		DeviceVendor=${DeviceVendor_temp//[[:blank:]]/}
		DeviceProduct_temp=`cat /proc/scsi/usb-storage/${DeviceUSBStorageNO} | sed -n -e 's/.*Product: \(.*\)/\1/p'`
		DeviceProduct=${DeviceProduct_temp//[[:blank:]]/}
		DeviceSerialNumber_temp=`cat /proc/scsi/usb-storage/${DeviceUSBStorageNO} | sed -n -e 's/.*Serial Number: \(.*\)/\1/p'`
		DeviceSerialNumber=${DeviceSerialNumber_temp//[[:blank:]]/}
		DeviceModel_temp=`cat /sys/block/$DeviceNode/device/model`
		DeviceModel=${DeviceModel_temp//[[:blank:]]/}
		echo "${PPID} ${DeviceUSBStorageNO} ${DeviceVendor} ${DeviceProduct} ${DeviceSerialNumber} ${DeviceModel}" >> /tmp/addDeviceLogs.log
	fi
	#Search through /sys/bus/usb/devices/3-* and /sys/bus/usb/devices/4-*
	USBdevices=`realpath /sys/bus/usb/devices/3-*;realpath /sys/bus/usb/devices/4-*`
	for device in ${USBdevices} ; do
		if [ -f "${device}/authorized"  ]; then
			USBDeviceVendor_temp=`cat "${device}/manufacturer"`
			USBDeviceVendor=${USBDeviceVendor_temp//[[:blank:]]/}
			USBDeviceProduct_temp=`cat "${device}/product"`
			USBDeviceProduct=${USBDeviceProduct_temp//[[:blank:]]/}
			USBDeviceSerialNumber_temp=`cat "${device}/serial"`
			USBDeviceSerialNumber=${USBDeviceSerialNumber_temp//[[:blank:]]/}
			if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ]; then
				FoundDevice="${device}"
				echo "${PPID} ${USBDeviceVendor}, ${USBDeviceProduct}, ${USBDeviceSerialNumber} ${DeviceVendor}, ${DeviceProduct}, ${DeviceSerialNumber}" >> /tmp/addDeviceLogs.log
			else
				#echo "${USBDeviceVendor}, ${USBDeviceProduct}, ${USBDeviceSerialNumber}"
				#echo "${DeviceVendor}, ${DeviceProduct}, ${DeviceSerialNumber}"
				echo "${PPID} ${USBDeviceVendor}, ${USBDeviceProduct}, ${USBDeviceSerialNumber} ${DeviceVendor}, ${DeviceProduct}, ${DeviceSerialNumber}" >> /tmp/addDeviceLogs.log
				if [ "${DeviceVendor}" == "${USBDeviceVendor}" ] || [ "${DeviceProduct}" == "${USBDeviceProduct}" ] || [ "${DeviceSerialNumber}" == "${USBDeviceSerialNumber}" ]; then
					FoundDevice="${device}"
					echo "${PPID} ${USBDeviceVendor}, ${USBDeviceProduct}, ${USBDeviceSerialNumber} ${DeviceVendor}, ${DeviceProduct}, ${DeviceSerialNumber}" >> /tmp/addDeviceLogs.log
				fi
			fi
		fi
	done
	#echo "${FoundDevice}"
	#if [ ! -f "${FoundDevice}/manufacturer" ]; then
	#	exit 1;
	#fi
	USBidVendor=`cat ${FoundDevice}/idVendor`
	USBidProduct=`cat ${FoundDevice}/idProduct`
	echo "${PPID} ${USBidVendor} ${USBidProduct}" >> /tmp/addDeviceLogs.log
	if [ ! -f  "/tmp/$DeviceNode-device" ]; then
		echo "${DeviceNode}" > /tmp/${DeviceNode}-device
		isMultipleDevices=`lsusb | grep "${USBidVendor}:${USBidProduct}" | wc -l`
		if [ ${isMultipleDevices} -eq 1 ]; then
			lsusb -v -d ${USBidVendor}:${USBidProduct} >> /tmp/${DeviceNode}-device
		else
			USBbusnum=`cat ${FoundDevice}/busnum`
			USBdevnum=`cat ${FoundDevice}/devnum`
			lsusb -v -s ${USBbusnum}:${USBdevnum} >> /tmp/${DeviceNode}-device
		fi
	fi
	
	if [ "$USBidVendor" == "2672" ] && [ "${DeviceType}" == "USB" ]; then
		echo ": GoPro detect" >> /tmp/addDeviceLogs.log
		echo "45;01;" > /tmp/MCU_Cmd
	fi

	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ] && [ "${DeviceType}" == "USB" ]; then
		#if [ "$USBidVendor" == "2672" ]; then
		#	echo $timestamp ": GoPro detect" >> /tmp/addDeviceLogs.log
		#	echo "45;01;" > /tmp/MCU_Cmd
		#fi
		if [ "${USBDeviceSerialNumber}" == "" ]; then
			USBDeviceSerialNumber="${USBidVendor}${USBidProduct}"
		fi
		DeviceUUID=${USBDeviceSerialNumber}
		PartitionNO=""
	else
		DeviceUUID=${DeviceSerialNumber}
	fi
fi

if [ -f /var/lock/addDevice ] ; then
	exec 300>/var/lock/addDevice
	flock -x 300

	VolumeName=""
	if [ "${VolumeName}" != "" ]; then
		if [ "${PartitionNO}" != "" ]; then
			ShareName=${VolumeName}-${PartitionNO}
		else
			ShareName=${VolumeName}
		fi
	else
		if [ "${DeviceType}" == "SDcard" ]; then
			if [ "${PartitionNO}" != "" ]; then
				ShareName=${DeviceVendor}_${DeviceProduct}-${PartitionNO}
			else
				ShareName=${DeviceVendor}_${DeviceProduct}
			fi
		fi
		if [ "${DeviceType}" == "USB" ]; then
			if [ "${USBDeviceProduct}" != "${DeviceModel}" ]; then
				if [ "${DeviceModel}" != "" ]; then
					USBDeviceProduct=${DeviceModel}
				fi
			fi
			if [ "${PartitionNO}" != "" ]; then
				ShareName=${USBDeviceProduct// /_}-${PartitionNO}
			else
				ShareName=${USBDeviceProduct// /_}
			fi
		fi
	fi
	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ] && [ "${DeviceType}" == "USB" ]; then
		DeviceUUID=${USBDeviceSerialNumber}
	else
		if [ "${PartitionNO}" != "" ]; then
			DeviceUUID=${DeviceSerialNumber}_${VolumeUUID}_${PartitionNO}
		else
			DeviceUUID=${DeviceSerialNumber}_${VolumeUUID}
		fi
	fi
        echo "${PPID} ShareName:${ShareName}, DeviceUUID:${DeviceUUID}" >> /tmp/addDeviceLogs.log
	is_DeviceUUID_existed=`cat /etc/samba/smb-shares.conf | grep "${DeviceUUID};" | wc -l`

	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ] && [ "${DeviceType}" == "USB" ] && [ "${is_DeviceUUID_existed}" != "0" ]; then
		TmpShareName=${ShareName}_${is_DeviceUUID_existed}
		is_DeviceUUID_existed=0
		ShareName=$TmpShareName
	fi
	if [ "${is_DeviceUUID_existed}" == "0" ]; then
		echo "#Begin DeviceUUID = ${DeviceUUID};" >> /etc/samba/smb-shares.conf
		echo "[${ShareName}]" >> /etc/samba/smb-shares.conf
		echo "comment =" >> /etc/samba/smb-shares.conf
		echo "path = ${DeviceMountPath}" >> /etc/samba/smb-shares.conf
		echo "browseable = yes" >> /etc/samba/smb-shares.conf
		echo "available = yes" >> /etc/samba/smb-shares.conf
		echo "public = yes" >> /etc/samba/smb-shares.conf
		echo "guest ok = yes" >> /etc/samba/smb-shares.conf
		echo "oplocks = yes" >> /etc/samba/smb-shares.conf
		echo "map archive = no" >> /etc/samba/smb-shares.conf
		read_only=`mount | grep ${DevicePartitionNode} | grep "ro," | wc -l`
		if [ "${read_only}" == "0" ]; then
			echo "writable = yes" >> /etc/samba/smb-shares.conf
			echo "read only = no" >> /etc/samba/smb-shares.conf
		else
			readonlyflag=true
			echo "writable = no" >> /etc/samba/smb-shares.conf
			echo "read only = yes" >> /etc/samba/smb-shares.conf
		fi
		echo "valid users =">> /etc/samba/smb-shares.conf
		echo "invalid users =" >> /etc/samba/smb-shares.conf
		echo "write list =" >> /etc/samba/smb-shares.conf
		echo "read list =" >> /etc/samba/smb-shares.conf
		echo '# !!properties = "media_serving"' >> /etc/samba/smb-shares.conf
		echo "#End DeviceUUID = ${DeviceUUID};" >> /etc/samba/smb-shares.conf
		killall -SIGHUP smbd
		echo ";Begin DeviceUUID = ${DeviceUUID}" >> /etc/afp.conf
		echo "[${ShareName}]" >> /etc/afp.conf
		echo "path = /shares/${ShareName}" >> /etc/afp.conf
		echo "ea = auto" >> /etc/afp.conf
		echo "convert appledouble = no" >> /etc/afp.conf
		echo "stat vol = no" >> /etc/afp.conf
		echo "file perm = 777" >> /etc/afp.conf
		echo "directory perm = 777" >> /etc/afp.conf
		echo "veto files = '/Network Trash Folder/.!@#$recycle/.systemfile/lost+found/Nas_Prog/.!@$mmc/.twonkymedia/.wd-alert/.wdmc/.wdcache/.USB/'" >> /etc/afp.conf
		echo ";End DeviceUUID = ${DeviceUUID}" >> /etc/afp.conf
		killall -SIGHUP netatalk
	fi
	if [ -e /shares/"${ShareName}" ] ; then
		rm /shares/"${ShareName}"
	fi
	ln -sf ${DeviceMountPath} /shares/"${ShareName}"
	if [ -e /var/ftp/"${ShareName}" ]; then
		umount /var/ftp/"${ShareName}"
		rmdir /var/ftp/"${ShareName}"
	fi
	mkdir -p /var/ftp/"${ShareName}"
	chown root:ftp /var/ftp/"${ShareName}"
	chmod 775 /var/ftp/"${ShareName}"
	mount --bind ${DeviceMountPath} /var/ftp/"${ShareName}"
	if [ "${devicefound}" == "MTP" -o "${devicefound}" == "PTP" ] && [ "${DeviceType}" == "USB" ]; then
		/usr/local/sbin/volume_mount.sh mount "${DeviceUUID}" "${DeviceMountPath}" /dev/${DevicePartitionNode} ${DeviceFSType} "${DeviceUUID}" ${StorageType} ${readonlyflag}
		echo "${ShareName}:${DeviceUUID}:${DeviceMountPath}:/dev/${DevicePartitionNode}:${DeviceFSType}:${DeviceUUID}:${USBDeviceVendor}:${USBDeviceProduct}:${USBDeviceSerialNumber}${DeviceNode}:`date +%s`:${DeviceNode}:${StorageType}:${readonlyflag}" > /tmp/${DevicePartitionNode}-info
		
	else
		/usr/local/sbin/volume_mount.sh mount "${DeviceUUID}" "${DeviceMountPath}" /dev/${DevicePartitionNode} ${DeviceFSType} "${DeviceUUID}" ${StorageType} ${readonlyflag}
		echo "${ShareName}:${DeviceUUID}:${DeviceMountPath}:/dev/${DevicePartitionNode}:${DeviceFSType}:${DeviceUUID}:${DeviceVendor}:${DeviceProduct}:${DeviceSerialNumber}${DeviceNode}:`date +%s`:${DeviceNode}:${StorageType}" > /tmp/${DevicePartitionNode}-info
		
	fi
	timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
	if [ "${DeviceType}" == "USB" ]; then
    	echo $timestampDBG ": Autobackup usb event check" >> /tmp/backup.log
    	killall -16 ghelper
    fi
    if [ "${DeviceType}" == "SDcard" ]; then
    	echo $timestampDBG ": Autobackup sd event check" >> /tmp/backup.log
    	killall -10 ghelper
    fi
    
	/usr/local/sbin/wdAutoMountAdm.pm getRealDrives > /tmp/getDrives 2>&1
	/usr/local/sbin/crud_share_db.sh create "${ShareName}" /etc/samba/smb-shares.conf true
	if [ "${DeviceType}" == "SDcard" ]; then
		sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
	fi
	if [ "${DeviceType}" == "USB" ]; then
		sed -i 's/USB_TransferStatus=.*/USB_TransferStatus=completed/' /etc/nas/config/usb-transfer-status.conf
	fi
	/sbin/refresh_contentdirs.sh &
	/sbin/CheckMediaScanStatus.sh init &
	
	if [ "${DeviceType}" == "SDcard" ]; then	
		/usr/local/sbin/incUpdateCount.pm sd_card &
	fi
	if [ "${DeviceType}" == "USB" ]; then
		/usr/local/sbin/incUpdateCount.pm usb &
	fi
	/usr/local/sbin/incUpdateCount.pm share &
	flock -u 300
fi

