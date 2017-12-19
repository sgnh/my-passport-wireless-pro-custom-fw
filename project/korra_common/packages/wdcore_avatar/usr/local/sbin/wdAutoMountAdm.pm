#!/bin/bash

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

cmd=$1

function USBgetDrive()
{
	DeviceNode=`head -n 1 ${1}`
	timeout -t 5 fdisk -l /dev/${DeviceNode} > /dev/null 2>/dev/null
	accessible=$?
	if [ "${accessible}" == "143" ]; then
		return 0
	fi
	DeviceVendor=`cat ${1} | sed -n -e 's/.*iManufacturer \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceProduct=`cat ${1} | sed -n -e 's/.*iProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceSerialNumber_temp=`cat ${1} | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceSerialNumber=${DeviceSerialNumber_temp//[[:blank:]]/}
	DeviceRev=`cat ${1} | sed -n -e 's/.*bcdDevice \(.*\)/\1/p' | sed -e 's/^[ \t]*//'`
	DeviceidVendor=`cat ${1} | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DeviceidProduct=`cat ${1} | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DevicebUSBVersion=`cat ${1} | sed -n -e 's/.*bcdUSB \(.*\)/\1/p' | head -n 1 | sed -e 's/^[ \t0x]*//' | cut -f 1 -d ' '`
	DeviceCapacity=`fdisk -l /dev/${DeviceNode} | grep "bytes," | cut -f 5 -d ' '`
	DeviceUsed=`df -B 1000000 | grep /dev/${DeviceNode} | grep -rsi /media | awk '{sum +=$3} END {print sum}'`
	if [ "${DeviceSerialNumber}" == "" ]; then
		DeviceSerialNumber="${DeviceidVendor}${DeviceidProduct}"
	fi
	name="${DeviceVendor} ${DeviceProduct}"
	echo "usb_drive"
	echo "name=${name}"
	echo "handle=${DeviceSerialNumber}${DeviceNode}"
	echo "serial_number=${DeviceSerialNumber}"
	echo "vendor=${DeviceVendor}"
	echo "model=${DeviceProduct}"
	echo "revision=${DeviceRev}"
	echo "ptp=false"
	echo "smart_status="
	echo "standby_timer=unsupported"
	echo "lock_state=security_off"
	echo "usage=${DeviceUsed}"
	capacityMB=`expr ${DeviceCapacity} / 1000000`
	echo "capacity=${capacityMB}"
	echo "vendor_id=${DeviceidVendor}"
	echo "product_id=${DeviceidProduct}"
	echo "usb_port=0"
	echo "usb_version=${DevicebUSBVersion}"
	echo "usb_speed=480"
	echo "is_connected=true"
	echo "volumes"
	Volumes=`find /tmp/ -name "${DeviceNode}*-info"`
	for Volume in ${Volumes} ; do
		ShareName=`cat $Volume | cut -f 1 -d ':'`
		VolumeUUID=`cat $Volume | cut -f 2 -d ':'`
		DeviceMountPath=`cat $Volume | cut -f 3 -d ':'`
		DevicePartitionNode=`cat $Volume | cut -f 4 -d ':'`
		DeviceUUID=`cat $Volume | cut -f 6 -d ':'`
		blkid ${DevicePartitionNode} > /dev/null 2>/dev/null 
		DevicePartitionLabel=`blkid ${DevicePartitionNode} | sed -n 's/.*LABEL="\([^"]*\)".*/\1/p'`
		DevicePartitionCapacity=`df -B 1000000 ${DevicePartitionNode} | grep ${DevicePartitionNode} | awk '{print $2}'`
		DevicePartitionUsed=`df -B 1000000 ${DevicePartitionNode} | grep ${DevicePartitionNode} | awk '{print $3}'`
		DevicePartitionMountDate=`cat $Volume | cut -f 10 -d ':'`
		Read_Only=`mount | grep ${DevicePartitionNode} | grep "ro," | wc -l`
		echo "volume"
		echo "volume_id=${VolumeUUID}"
		echo "base_path=/shares/${ShareName}"
		echo "label=${DevicePartitionLabel}"
		echo "mounted_date=${DevicePartitionMountDate}"
		echo "usage=${DevicePartitionUsed}"
		echo "capacity=${DevicePartitionCapacity}"
		if [ ${Read_Only} == "0" ]; then
			echo "read_only=false"
		else
			echo "read_only=true"
		fi
		echo "storage_type=USB"
		echo "shares"
		echo "share=${ShareName}"
		echo ""
		echo ""
	done
	echo ""
	echo ""
}


function MTPgetDrive()
{
	DeviceNode=`head -n 1 ${1}`
	DeviceVendor=`cat ${1} | sed -n -e 's/.*iManufacturer \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceProduct=`cat ${1} | sed -n -e 's/.*iProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceSerialNumber_temp=`cat ${1} | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceSerialNumber=${DeviceSerialNumber_temp//[[:blank:]]/}
	DeviceRev=`cat ${1} | sed -n -e 's/.*bcdDevice \(.*\)/\1/p' | sed -e 's/^[ \t]*//'`
	DeviceidVendor=`cat ${1} | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DeviceidProduct=`cat ${1} | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DevicebUSBVersion=`cat ${1} | sed -n -e 's/.*bcdUSB \(.*\)/\1/p' | head -n 1 | sed -e 's/^[ \t0x]*//' | cut -f 1 -d ' '`
	DeviceCapacity=`df -B 1000000 | grep simple-mtpfs | head -n 1 |awk '{print $2}'`
	DeviceUsed=`df -B 1000000 | grep simple-mtpfs | head -n 1 |awk '{print $3}'`
	if [ "${DeviceSerialNumber}" == "" ]; then
		DeviceSerialNumber="${DeviceidVendor}${DeviceidProduct}"
	fi
	name="$DeviceVendor $DeviceProduct"
	echo "usb_drive"
	echo "name=${name}"
	echo "handle=${DeviceSerialNumber}${DeviceNode}"
	echo "serial_number=${DeviceSerialNumber}"
	echo "vendor=${DeviceVendor}"
	echo "model=${DeviceProduct}"
	echo "revision=${DeviceRev}"
	echo "ptp=true"
	echo "smart_status=unsupported"
	echo "standby_timer=unsupported"
	echo "lock_state=security_off"
	echo "usage=${DeviceUsed}"
	capacityMB=`expr ${DeviceCapacity}`
	echo "capacity=${capacityMB}"
	echo "vendor_id=${DeviceidVendor}"
	echo "product_id=${DeviceidProduct}"
	echo "usb_port=0"
	echo "usb_version=${DevicebUSBVersion}"
	echo "usb_speed=480"
	echo "is_connected=true"
	echo "volumes"
	Volumes=`find /tmp/ -name "sd${DeviceNode}*-info"`
	for Volume in ${Volumes} ; do
		ShareName=`cat $Volume | cut -f 1 -d ':'`
		VolumeUUID=`cat $Volume | cut -f 2 -d ':'`
		DeviceMountPath=`cat $Volume | cut -f 3 -d ':'`
		DevicePartitionNode=`cat $Volume | cut -f 4 -d ':'`
		DeviceUUID=`cat $Volume | cut -f 6 -d ':'`
		blkid ${DevicePartitionNode} > /dev/null 2>/dev/null 
		DevicePartitionLabel=`blkid ${DevicePartitionNode} | sed -n 's/.*LABEL="\([^"]*\)".*/\1/p'`
		DevicePartitionCapacity=`df -B 1000000 | grep simple-mtpfs | head -n 1 | awk '{print $2}'`
		DevicePartitionUsed=`df -B 1000000 | grep simple-mtpfs | head -n 1 | awk '{print $3}'`
		DevicePartitionMountDate=`cat $Volume | cut -f 10 -d ':'`
		echo "volume"
		echo "volume_id=${VolumeUUID}"
		echo "base_path=/shares/${ShareName}"
		echo "label=${DevicePartitionLabel}"
		echo "mounted_date=${DevicePartitionMountDate}"
		echo "usage=${DevicePartitionUsed}"
		echo "capacity=${DevicePartitionCapacity}"
		echo "read_only=false"
		echo "storage_type=USB"
		echo "shares"
		echo "share=${ShareName}"
		echo ""
		echo ""
	done
	echo ""
	echo ""
}

function PTPgetDrive()
{
	DeviceNode=`head -n 1 ${1}`
	DeviceVendor=`cat ${1} | sed -n -e 's/.*iManufacturer \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceProduct=`cat ${1} | sed -n -e 's/.*iProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceSerialNumber=`cat ${1} | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
	DeviceRev=`cat ${1} | sed -n -e 's/.*bcdDevice \(.*\)/\1/p' | sed -e 's/^[ \t]*//'`
	DeviceidVendor=`cat ${1} | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DeviceidProduct=`cat ${1} | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
	DeviceCapacity=`df -B 1000000 | grep gphotofs | head -n 1 |awk '{print $2}'`
	DeviceUsed=`df -B 1000000 | grep gphotofs | head -n 1 |awk '{print $3}'`
	if [ "${DeviceSerialNumber}" == "" ]; then
		DeviceSerialNumber="${DeviceidVendor}${DeviceidProduct}"
	fi
	if [ "${DeviceCapacity}" == "" ] && [ "${DeviceUsed}" == "" ]; then
		DeviceCapacity=`df -B 1000000 | grep ifuse | head -n 1 |awk '{print $2}'`
		DeviceUsed=`df -B 1000000 | grep ifuse | head -n 1 |awk '{print $3}'`
		if [ "${DeviceCapacity}" == "" ] && [ "${DeviceUsed}" == "" ]; then
			DeviceCapacity=`cat "/tmp/gphoto2_storage" | sed -n '1p'`
			DeviceUsed=`cat "/tmp/gphoto2_storage" | sed -n '2p'`
		fi
	fi
	name="$DeviceVendor $DeviceProduct"
	echo "usb_drive"
	echo "name=${name}"
	echo "handle=${DeviceSerialNumber}${DeviceNode}"
	echo "serial_number=${DeviceSerialNumber}"
	echo "vendor=${DeviceVendor}"
	echo "model=${DeviceProduct}"
	echo "revision=${DeviceRev}"
	echo "ptp=true"
	echo "smart_status=unsupported"
	echo "standby_timer=unsupported"
	echo "lock_state=security_off"
	echo "usage=${DeviceUsed}"
	capacityMB=`expr ${DeviceCapacity}`
	echo "capacity=${capacityMB}"
	echo "vendor_id=${DeviceidVendor}"
	echo "product_id=${DeviceidProduct}"
	echo "usb_port=0"
	echo "usb_version=${DevicebUSBVersion}"
	echo "usb_speed=480"
	echo "is_connected=true"
	echo "volumes"
	Volumes=`find /tmp/ -name "sd${DeviceNode}*-info"`
	for Volume in ${Volumes} ; do
		ShareName=`cat $Volume | cut -f 1 -d ':'`
		VolumeUUID=`cat $Volume | cut -f 2 -d ':'`
		DeviceMountPath=`cat $Volume | cut -f 3 -d ':'`
		DevicePartitionNode=`cat $Volume | cut -f 4 -d ':'`
		DeviceUUID=`cat $Volume | cut -f 6 -d ':'`
		blkid ${DevicePartitionNode} > /dev/null 2>/dev/null 
		DevicePartitionLabel=`blkid ${DevicePartitionNode} | sed -n 's/.*LABEL="\([^"]*\)".*/\1/p'`
		DevicePartitionCapacity=`df -B 1000000 | grep gphotofs | head -n 1 | awk '{print $2}'`
		DevicePartitionUsed=`df -B 1000000 | grep gphotofs | head -n 1 | awk '{print $3}'`
		if [ "${DeviceCapacity}" == "" ] && [ "${DeviceUsed}" == "" ]; then
			DevicePartitionCapacity=`df -B 1000000 | grep ifuse | head -n 1 | awk '{print $2}'`
			DevicePartitionUsed=`df -B 1000000 | grep ifuse | head -n 1 | awk '{print $3}'`
		fi
		DevicePartitionMountDate=`cat $Volume | cut -f 10 -d ':'`
		echo "volume"
		echo "volume_id=${VolumeUUID}"
		echo "base_path=/shares/${ShareName}"
		echo "label=${DevicePartitionLabel}"
		echo "mounted_date=${DevicePartitionMountDate}"
		echo "usage=${DevicePartitionUsed}"
		echo "capacity=${DevicePartitionCapacity}"
		echo "read_only=false"
		echo "storage_type=USB"
		echo "shares"
		echo "share=${ShareName}"
		echo ""
		echo ""
	done
	echo ""
	echo ""
}

function MMCgetDrive()
{
	DeviceNode=`cat ${1} | cut -f 1 -d ':'`
	timeout -t 5 fdisk -l /dev/${DeviceNode} > /dev/null 2>/dev/null
	accessible=$?
	if [ "${accessible}" == "143" ]; then
		return 0
	fi
	DeviceVendor=`cat ${1} | cut -f 2 -d ':'`
	DeviceProduct=`cat ${1} | cut -f 3 -d ':'`
	DeviceSerialNumber=`cat ${1} | cut -f 4 -d ':'`
	DeviceRev=`cat ${1} | cut -f 5 -d ':'`
	DeviceidVendor=`cat ${1} | cut -f 2 -d ':'`
	DeviceLock=`cat ${1} | cut -f 6 -d ':'`
	DeviceCapacity=`fdisk -l /dev/${DeviceNode} | grep "bytes," | cut -f 5 -d ' '`
	DeviceUsed=`df -B 1000000 | grep /dev/${DeviceNode} | grep -rsi /media | awk '{sum +=$3} END {print sum}'`
	name="$DeviceVendor $DeviceProduct"
	echo "usb_drive"
	echo "name=${DeviceVendor} ${DeviceProduct}"
	echo "handle=${DeviceSerialNumber}${DeviceNode}"
	echo "serial_number=${DeviceSerialNumber}"
	echo "vendor=${DeviceVendor}"
	echo "model=${DeviceProduct}"
	echo "revision=${DeviceRev}"
	echo "ptp=false"
	echo "smart_status=unsupported"
	echo "standby_timer=unsupported"
	echo "lock_state=${DeviceLock}"
	echo "usage=${DeviceUsed}"
	capacityMB=`expr ${DeviceCapacity} / 1000000`
	echo "capacity=${capacityMB}"
	echo "vendor_id=${DeviceidVendor}"
	echo "product_id=unsupported"
	echo "usb_port=unsupported"
	echo "usb_version=unsupported"
	echo "usb_speed=unsupported"
	echo "is_connected=true"
	echo "volumes"
	Volumes=`find /tmp/ -name "${DeviceNode}*-info"`
	for Volume in ${Volumes} ; do
		ShareName=`cat ${Volume} | cut -f 1 -d ':'`
		VolumeUUID=`cat ${Volume} | cut -f 2 -d ':'`
		DeviceMountPath=`cat ${Volume} | cut -f 3 -d ':'`
		DevicePartitionNode=`cat ${Volume} | cut -f 4 -d ':'`
		DeviceUUID=`cat ${Volume} | cut -f 6 -d ':'`
		blkid ${DevicePartitionNode} > /dev/null 2>/dev/null 
		DevicePartitionLabel=`blkid ${DevicePartitionNode} | sed -n 's/.*LABEL="\([^"]*\)".*/\1/p'`
		DevicePartitionCapacity=`df -B 1000000 ${DevicePartitionNode} | grep ${DevicePartitionNode} | awk '{print $2}'`
		DevicePartitionUsed=`df -B 1000000 ${DevicePartitionNode} | grep ${DevicePartitionNode} | awk '{print $3}'`
		DevicePartitionMountDate=`cat ${Volume} | cut -f 10 -d ':'`
		Read_Only=`mount | grep ${DevicePartitionNode} | grep "ro," | wc -l`
		echo "volume"
		echo "volume_id=${VolumeUUID}"
		echo "base_path=/shares/${ShareName}"
		echo "label=${DevicePartitionLabel}"
		echo "mounted_date=${DevicePartitionMountDate}"
		echo "usage=${DevicePartitionUsed}"
		echo "capacity=${DevicePartitionCapacity}"
		if [ ${Read_Only} == "0" ]; then
			echo "read_only=false"
		else
			echo "read_only=true"
		fi
		echo "storage_type=SDCARD"
		echo "shares"
		echo "share=${ShareName}"
		echo ""
		echo ""
	done
	echo ""
	echo ""
}


function getRealDrives()
{
	if [ ! -f "/tmp/getRealDrives" ]; then
		touch "/tmp/getRealDrives"
		USBdevices=`find /tmp/ -name "sd*-device"`
		echo "usb_drives" > "/tmp/getDrivesTmp"
		for usbdevice in ${USBdevices} ; do
			USBgetDrive ${usbdevice} >> "/tmp/getDrivesTmp"
		done
		if [ -f /tmp/mtpfs-device ]; then
			MTPgetDrive /tmp/mtpfs-device >> "/tmp/getDrivesTmp"
		fi
		if [ -f /tmp/ptpfs-device ]; then
			PTPgetDrive /tmp/ptpfs-device >> "/tmp/getDrivesTmp"
		fi
		MMCdevices=`find /tmp/ -name "mmc*-device"`
		for mmcdevice in ${MMCdevices} ; do
			MMCgetDrive ${mmcdevice} >> "/tmp/getDrivesTmp"
		done
		echo "" >> "/tmp/getDrivesTmp"
		
		cp "/tmp/getDrivesTmp" "/tmp/getDrives"
		rm "/tmp/getRealDrives" 
	fi
	exit 0
}

function getDrives()
{
	if [ -f "/tmp/getDrives" ]; then
		cat "/tmp/getDrives"
		
		wdAutoMountAdm.pm getRealDrives > /dev/null 2>&1 &
	else
		USBdevices=`find /tmp/ -name "sd*-device"`
		echo "usb_drives"
		for usbdevice in ${USBdevices} ; do
			USBgetDrive ${usbdevice}
		done
		if [ -f /tmp/mtpfs-device ]; then
			MTPgetDrive /tmp/mtpfs-device
		fi
		if [ -f /tmp/ptpfs-device ]; then
			PTPgetDrive /tmp/ptpfs-device
		fi
		MMCdevices=`find /tmp/ -name "mmc*-device"`
		for mmcdevice in ${MMCdevices} ; do
			MMCgetDrive ${mmcdevice}
		done
		echo ""
		exit 0
	fi
}

function getDrive()
{
	USBdevices=`find /tmp/ -name "sd*-device"`
	for usbdevice in ${USBdevices} ; do
		DeviceNode=`head -n 1 ${usbdevice}`
		DeviceHandle_temp=`cat ${usbdevice} | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}${DeviceNode}"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat ${usbdevice} | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat ${usbdevice} | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}${DeviceNode}"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			USBgetDrive ${usbdevice}
			exit 0
		fi
	done
	if [ -f /tmp/mtpfs-device ]; then
		DeviceHandle_temp=`cat /tmp/mtpfs-device | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}mtpfs"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat /tmp/mtpfs-device | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat /tmp/mtpfs-device | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}mtpfs"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			MTPgetDrive /tmp/mtpfs-device
			exit 0
		fi
	fi
	if [ -f /tmp/ptpfs-device ]; then
		DeviceHandle_temp=`cat /tmp/ptpfs-device | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}ptpfs"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat /tmp/ptpfs-device | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat /tmp/ptpfs-device | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}ptpfs"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			PTPgetDrive /tmp/ptpfs-device
			exit 0
		fi
	fi	
	MMCdevices=`find /tmp/ -name "mmc*-device"`
	for mmcdevice in ${MMCdevices} ; do
		DeviceNode=`cat ${mmcdevice} | cut -f 1 -d ':'`
		DeviceHandle="`cat ${mmcdevice} | cut -f 4 -d ':'`${DeviceNode}"
		if [ "${DeviceHandle}" == "${1}" ]; then
			MMCgetDrive ${mmcdevice}
			exit 0
		fi
	done
	exit 2
}

function USBejectDrive()
{
	USBMountDeviceNodes=`df | grep "/dev/$1" |  awk '{print $1}' | uniq`
	#echo "${USBMountVolumes=}, ${USBMountDeviceNodes}"
	for USBMountDeviceNode in ${USBMountDeviceNodes} ; do
			DeviceNode=`echo "${USBMountDeviceNode}" | cut -c 6-`
			/sbin/removeDevice.sh USB "${DeviceNode}"
	done
	USBMountVolumes=`df | grep "/dev/$1" |  awk '{print $6}'`
	for USBMountVolume in ${USBMountVolumes} ; do
			sleep 1
			if [[ "${USBMountVolume}" == "/media/"* ]] ; then
				fuser -mk "${USBMountVolume}"
				sync
				sync
				sync
				echo "umount ${USBMountVolume}"
				umount "${USBMountVolume}"
				rmdir "${USBMountVolume}"
			fi
	done

}

function MTPejectDrive()
{
	DeviceMountPath=`cat /tmp/sdmtpfs-info | cut -f 3 -d ':'`
	/sbin/removeDevice.sh USB sdmtpfs
	mtppid=`pidof simple-mtpfs`
	if [ "${mtppid}" != "" ]; then
			#fusermount -u ${DeviceMountPath}
			if [[ ${DeviceMountPath} == "/media/"* ]] ; then
				fuser -mk ${DeviceMountPath}
				sync
				sync
				sync
				umount "${DeviceMountPath}"
				if [ $? != 0 ]; then
					echo "mtp device umount fail" >> /tmp/debugmtpdev
					kill -9 ${mtppid}
					killall simple-mtpfs
				fi
				rmdir ${DeviceMountPath}
				touch /tmp/MTPDeviceEjected
			fi
	fi
}

function PTPejectDrive()
{
	DeviceMountPath=`cat /tmp/sdptpfs-info | cut -f 3 -d ':'`
	DeviceMountPath=/media/USB
	/sbin/removeDevice.sh USB sdptpfs
	ptppid=`pidof gphotofs`
	if [ "${ptppid}" != "" ]; then
			#fusermount -u ${DeviceMountPath}
			sync
			sync
			sync
			umount -f ${DeviceMountPath}
			if [ $? != 0 ]; then
					echo "ptp device umount fail" >> /tmp/debugmtpdev
					kill -9 ${ptppid}
					killall gphotofs
			fi
			rmdir ${DeviceMountPath}
			touch /tmp/PTPDeviceEjected
	fi
	ptppid=`pidof ifuse`
	if [ "${ptppid}" != "" ]; then
		#fusermount -u ${DeviceMountPath}
		sync
		sync
		sync
		umount -f ${DeviceMountPath}
		if [ $? != 0 ]; then
			echo "ptp device umount fail" >> /tmp/debugmtpdev
			kill -9 ${ptppid}
			killall ifuse
		fi
		killall usbmuxd
		rmdir ${DeviceMountPath}
		touch /tmp/PTPDeviceEjected
	fi
}

function MMCejectDrive()
{
	MMCMountDeviceNodes=`df | grep "/dev/$1" |  awk '{print $1}' | uniq`
	#echo "${MMCMountVolumes=}, ${MMCMountDeviceNodes}"
	for MMCMountDeviceNode in ${MMCMountDeviceNodes} ; do
			DeviceNode=`echo "${MMCMountDeviceNode}" | cut -c 6-`
			/sbin/removeDevice.sh SDcard ${DeviceNode}
	done
	MMCMountVolumes=`df | grep "/dev/$1" |  awk '{print $6}'`
	for MMCMountVolume in ${MMCMountVolumes} ; do
			sleep 2
			if [[ ${MMCMountVolumes} == "/media/"* ]] ; then
				fuser -mk ${MMCMountVolume}
				sync
				sync
				sync
				umount "${MMCMountVolume}"
				rmdir "${MMCMountVolume}"
			fi
	done
}

function ejectDrive()
{
	USBdevices=`find /tmp/ -name "sd*-device"`
	for usbdevice in ${USBdevices} ; do
		DeviceNode=`head -n 1 ${usbdevice}`
		DeviceHandle_temp=`cat ${usbdevice} | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}${DeviceNode}"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat ${usbdevice} | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat ${usbdevice} | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}${DeviceNode}"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			#/usr/local/sbin/storage_transfer_cancel_now.sh ${1}
			USBejectDrive ${DeviceNode}
			exit 0
		fi
	done
	if [ -f /tmp/mtpfs-device ]; then
		DeviceHandle_temp=`cat /tmp/mtpfs-device | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}mtpfs"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat /tmp/mtpfs-device  | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat /tmp/mtpfs-device  | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}mtpfs"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			#/usr/local/sbin/storage_transfer_cancel_now.sh ${1}
			MTPejectDrive
			exit 0
		fi
	fi
        if [ -f /tmp/ptpfs-device ]; then
		DeviceHandle_temp=`cat /tmp/ptpfs-device | sed -n -e 's/.*iSerial \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -c 3-`
		DeviceHandle="${DeviceHandle_temp//[[:blank:]]/}ptpfs"
		if [ "${DeviceHandle_temp}" == "" ]; then
			DeviceidVendor=`cat /tmp/ptpfs-device | sed -n -e 's/.*idVendor \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceidProduct=`cat /tmp/ptpfs-device | sed -n -e 's/.*idProduct \(.*\)/\1/p' | sed -e 's/^[ \t]*//' | cut -f 1 -d ' ' | sed -e 's/^0x//'`
			DeviceHandle="${DeviceidVendor}${DeviceidProduct}ptpfs"
		fi
		if [ "${DeviceHandle}" == "${1}" ]; then
			/usr/local/sbin/storage_transfer_cancel_now.sh ${1}
			PTPejectDrive
			exit 0
		fi
	fi		
	MMCdevices=`find /tmp/ -name "mmc*-device"`
	for mmcdevice in ${MMCdevices} ; do
		DeviceNode=`cat ${mmcdevice} | cut -f 1 -d ':'`
		DeviceHandle="`cat ${mmcdevice} | cut -f 4 -d ':'`${DeviceNode}"
		if [ "${DeviceHandle}" == "${1}" ]; then 
			#/usr/local/sbin/storage_transfer_cancel_now.sh ${1}
			MMCejectDrive ${DeviceNode}
			exit 0
		fi
	done
	exit 2
}

case ${cmd} in
getDrives)
	getDrives
	;;
getRealDrives)
	getRealDrives
	;;
getDrive)
	getDrive $2
	;;
ejectDrive)
	ejectDrive $2
	;;
unlockDrive)
	;;
setStandbyTimer)
	;;
*)
	echo "usage: wdAutoMountAdm.pm [getDrive <device_handle> | getDrives | setStandByTimer <device_handle> <timer> | unlockDrive <device_handle> <password> <save> | ejectDrive <device_handle>]"
	exit 1
esac
	
