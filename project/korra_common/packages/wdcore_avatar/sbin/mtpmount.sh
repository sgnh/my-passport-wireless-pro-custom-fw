#!/bin/bash

devstr="${1}"
mtpmountpoint=/media/USB
mountSuccess=0
iosdev=0
SamsungGalaxy=0

if [ ! -f "/tmp/rsync_ready" ]; then
	exit 0
fi

timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": $devstr ${PPID} ${ACTION} ${DEVNAME}" >> /tmp/debugmtpdev

if [ -f "/tmp/mtpmountevent" ]; then
	echo $timestamp ": mtpmountevent ongoing" >> /tmp/debugmtpdev
	sleep 3
fi

function MountCheck()
{
	checktype=${1}
	if [ "${checktype}" == "PTP" ]; then
		checkmtpfs=`cat /proc/mounts | grep gphotofs`
		if [ "$checkmtpfs" != "" ]; then
			fusermount -u "${mtpmountpoint}"
			umount -l "${mtpmountpoint}"
			killall gphotofs
			#sleep 2
		fi
		checkmtpfs=`cat /proc/mounts | grep ifuse`
		if [ "${checkmtpfs}" != "" ]; then
			fusermount -u "${mtpmountpoint}"
			umount -l "${mtpmountpoint}"
			killall usbmuxd > /dev/null
			killall ifuse > /dev/null
			#sleep 2
		fi
	elif [ "${checktype}" == "MTP" ]; then
		checkmtpfs=`cat /proc/mounts | grep simple-mtpfs`
		if [ "${checkmtpfs}" != "" ]; then
			fusermount -u "$mtpmountpoint"
			umount -l $mtpmountpoint
			#sleep 1
		fi
	fi
}

if [ "${1}" == "bootingCheck" ]; then
	sleep 5
	devstr="bus/usb"
	ACTION="add"
else
	usbport1=`echo "$devstr" | awk -F\/ '{print $3","$4}'`
	usbbus=`echo "$devstr" | awk -F\/ '{print $3}'`
	usbDev=`echo "$devstr" | awk -F\/ '{print $4}'`
fi

if [ "${ACTION}" == "add" ]; then
	touch /tmp/mtpmountevent

	DEV_MANUF=`cat /sys/bus/usb/devices/[345]-1*/manufacturer`
	echo "$DEV_MANUF" >> /tmp/debugmtpdev
	
	DEV_PROD=`cat /sys/bus/usb/devices/[345]-1*/product`
	echo "$DEV_PROD" >> /tmp/debugmtpdev
	
	#DEV_SERIALNUM=`cat /sys/bus/usb/devices/[345]-1*/serial`
	#echo "$DEV_SERIALNUM" >> /tmp/debugmtpdev
	
	DEV_VENDOR=`cat /sys/bus/usb/devices/[345]-1*/idVendor`
	echo "$DEV_VENDOR" >> /tmp/debugmtpdev
	if [ "$DEV_VENDOR" == "2672" ]; then
		echo "45;01;" > /tmp/MCU_Cmd
	fi
	if [ "$DEV_MANUF" == "Apple Inc." ] && [ "$DEV_VENDOR" == "05ac" ]; then
		echo $timestamp ": iOS Device plugin" >> /tmp/debugmtpdev
		iosdev=1
	fi
	
	DEV_IDPROD=`cat /sys/bus/usb/devices/[345]-1*/idProduct`
	echo "$DEV_IDPROD" >> /tmp/debugmtpdev
	if [ "$DEV_MANUF" == "" ] && [ "$DEV_PROD" == "" ] && [ "$DEV_VENDOR" == "" ] && [ "$DEV_IDPROD" == "" ]; then
		echo $timestamp ": No MTP/PTP device info" >> /tmp/debugmtpdev
		rm /tmp/mtpmountevent
		exit 1
	fi

	if [ "${1}" == "bootingCheck" ]; then
		devusb=`lsusb | grep $DEV_VENDOR`
		if [ "${devusb}" != "" ]; then 
			usbbus=`echo "$devusb" | awk '{print $2}'`
			usbDev=`echo "$devusb" | awk '{print $4}' | cut -d ":" -f 1`
			devstr="bus/usb/${usbbus}/${usbDev}"
			usbport1=`echo "$devstr" | awk -F\/ '{print $3","$4}'`
		fi
		echo $timestamp ": device found on " ${devstr} >> /tmp/debugmtpdev
	fi

	if [ "$DEV_VENDOR" == "04e8" ] || [ "$DEV_IDPROD" == "6860" ]; then
		SamsungGalaxy=1
	fi

	existIface=`cat /sys/bus/usb/devices/3-1*/interface | wc -l`
	if [ "${existIface}" -eq 0 ]; then
		cat /sys/bus/usb/devices/4-1*/interface > /tmp/detectInterface
	else
		cat /sys/bus/usb/devices/3-1*/interface > /tmp/detectInterface
	fi
	devicefound=`cat /tmp/detectInterface | grep "MTP"`
	if [ "$devicefound" == "MTP" ]; then
		echo "MTP" > /tmp/detectInterface
		devicefound="MTP"
		echo $timestamp ": MTP Device by mdev" >> /tmp/debugmtpdev
	else
		devinfo=`/usr/bin/mtp-hotplug | grep "$DEV_IDPROD" | grep "$DEV_VENDOR"`
		if [ "$devinfo" != "" ]; then
			echo "MTP" > /tmp/detectInterface
			devicefound="MTP"
			echo $timestamp ": MTP Device by mtp-hotplug" >> /tmp/debugmtpdev
		else
			devinfo=`/usr/bin/gphoto2 -a --port=usb:${usbport1}`
			if [ "$(echo "${devinfo}" | grep "Abilities for camera" | grep "Mass Storage Camera")" != "" ]; then
				echo $timestamp ": Mass Storage by gphoto2, exit" >> /tmp/debugmtpdev
				exit 1
			elif [ "$(echo ${devinfo} | grep "MTP")" != "" ]; then
				echo "MTP" > /tmp/detectInterface
				devicefound="MTP"
				echo $timestamp ": MTP Device by gphoto2" >> /tmp/debugmtpdev
			elif [ "$(echo "${devinfo}" | grep "File preview" | grep "yes")" != "" ] || [ "$(echo "${devinfo}" | grep "PTP")" != "" ] || [ "$(echo "${devinfo}" | grep "Delete selected files on camera" | grep "yes")" != "" ]; then
				echo "PTP" > /tmp/detectInterface
				devicefound="PTP"
				echo $timestamp ": PTP Device by gphoto2" >> /tmp/debugmtpdev
			else
				devinfo=`/usr/bin/mtp-detect | grep "$DEV_IDPROD" | grep "$DEV_VENDOR"`
				if [ "$devinfo" != "" ]; then
					echo "MTP" > /tmp/detectInterface
					devicefound="MTP"
					echo $timestamp ": MTP Device by mtp-detect" >> /tmp/debugmtpdev
				fi
			fi
		fi
	fi

	if [ "$devicefound" == "MTP" ]; then
		MountCheck MTP
		echo "$devinfo" >> /tmp/debugmtpdev
		echo "41;01;" > /tmp/MCU_Cmd
		
		#Samsung MTP screen lock check
		 if [ "$SamsungGalaxy" == "1" ]; then
			echo $timestamp ": SamsungGalaxy needs check mtp again" >> /tmp/debugmtpdev
			mtp-detect | grep -w "make sure the screen is unlocked"
			if [ $? == 0 ]; then
				echo $timestamp ": screen is locked, mount failed." >> /tmp/debugmtpdev
				if [ -f "/tmp/detectInterface" ]; then
					rm -f /tmp/detectInterface
				fi
				exit 1
			fi
		fi

		#echo "$DEV_SERIALNUM" > /tmp/MTPDeviceSerialNumber 	
		if [ ! -d "$mtpmountpoint" ]; then
			mkdir -p "$mtpmountpoint"
		fi

		timeoffset=`cat /etc/timezone_offset`
		if [ "$timeoffset" == "" ]; then
			timeoffset=-8
		fi

		if [ "${timeoffset}" != "" ];then
			timeoffset_min=`dc ${timeoffset} 60 mul 480 add p`
		else
			timeoffset_min=0
		fi
		retryMount=1
		while [ "${retryMount}" != "0" ]
		do
			/usr/bin/simple-mtpfs --time_offset ${timeoffset_min} -o allow_other,umask=0000 "$mtpmountpoint"
			if [ $? == 0 ]; then
				echo $timestamp ": mtp device mounted !!" >> /tmp/debugmtpdev
				break
			fi
			retryMount=`expr ${retryMount} - 1`
			sleep 1
		done

		mtppid=`pidof simple-mtpfs`
		if [ "$mtppid" == "" ]; then
			rm -rf "$mtpmountpoint"
			echo $timestamp ": mtp device mount fail" >> /tmp/debugmtpdev
			rm /tmp/mtpmountevent
			if [ -f "/tmp/detectInterface" ]; then
				rm -f /tmp/detectInterface
			fi
			exit 1
		fi
		/sbin/addDevice.sh USB mtpfs /media/USB mtpfs
		echo $timestamp ": mtp device register addDevice done!" >> /tmp/debugmtpdev
		killall -16 ghelper
		rm /tmp/mtpmountevent
		exit 0

	elif [ "$devicefound" == "PTP" ]; then
		MountCheck PTP
		echo "$devinfo" >> /tmp/debugmtpdev
		echo "41;01;" > /tmp/MCU_Cmd
		if [ ! -d "$mtpmountpoint" ]; then
			mkdir -p "$mtpmountpoint"
		fi

		if [ "${iosdev}" == "1" ]; then
			retryMount=5
			while [ "$retryMount" != 0 ]; do
				StorageInfo=`/usr/bin/gphoto2 --port=usb:${usbport1} --storage-info`
				echo $timestamp ": iphone StorageInfo" $StorageInfo >> /tmp/debugmtpdev
				if [ "$(echo "${StorageInfo}" | grep "error")" != "" ]; then
					sleep 3
					pluginCheck=`lsusb | grep $DEV_VENDOR | grep $usbbus | grep $usbDev`
					if [ "${pluginCheck}" != "" ]; then
						continue
					else
						echo $timestamp ": Could not detect any camera on usb bus: Unknown model" >> /tmp/debugmtpdev
						break
					fi
				elif [ "$(echo "${StorageInfo}" | grep "feedface")" != "" ]; then
					sleep 3
					echo $timestamp ": iphone feedface unlocked" >> /tmp/debugmtpdev
					continue
				elif [ "$(echo "${StorageInfo}" | grep "store_")" != "" ]; then
					usbmuxdpid=`pidof usbmuxd`
					if [ "$usbmuxdpid" == "" ]; then
						/usr/sbin/usbmuxd -z
						sleep 2
					fi
					ActivationState=`/usr/bin/ideviceinfo`
					if [ "$(echo "${ActivationState}" | grep "ActivationState")" != "" ]; then
					#if [ "$ActivationState" != "" ]; then
						/usr/bin/ifuse -o allow_other,umask=0022 "$mtpmountpoint"
						if [ $? == 0 ]; then
							echo $timestamp ": PTP device mounted OK" >> /tmp/debugmtpdev
							break	
						fi
					elif [ "$(echo "${ActivationState}" | grep "No device found")" != "" ] || [ "${ActivationState}" == "" ]; then
						sleep 3
						echo $timestamp ": iphone ActivationState unlocked" >> /tmp/debugmtpdev
						continue
					fi
				fi
				retryMount=`expr "${retryMount}" - 1`
				sleep 1
			done

			ptppid=`pidof ifuse`
			if [ "${ptppid}" == "" ]; then
				rm -rf "$mtpmountpoint"
				killall usbmuxd > /dev/null
				killall ifuse > /dev/null
				echo $timestamp ": ifuse doesn't work! ->" $StorageInfo >> /tmp/debugmtpdev
				rm /tmp/mtpmountevent
				if [ -f "/tmp/detectInterface" ]; then
					rm -f /tmp/detectInterface
				fi
				exit 1
			fi

			if [ -d "/media/USB/DCIM" ]; then
				/sbin/addDevice.sh USB ptpfs /media/USB/DCIM ptpfs
			else
				/sbin/addDevice.sh USB ptpfs /media/USB ptpfs
			fi
			echo $timestamp ": PTP device register addDevice done!" >> /tmp/debugmtpdev
			killall -16 ghelper
			rm /tmp/mtpmountevent
			exit 0
		else
			retryMount=5
			while [ "$retryMount" != 0 ]; do
				StorageInfo=`/usr/bin/gphoto2 --port=usb:${usbport1} --storage-info`
				echo $timestamp ": PTP StorageInfo" $StorageInfo >> /tmp/debugmtpdev
				if [ "$(echo "${StorageInfo}" | grep "error")" != "" ]; then
					sleep 3
					pluginCheck=`lsusb | grep $DEV_VENDOR | grep $usbbus | grep $usbDev`
					if [ "${pluginCheck}" != "" ]; then
						continue
					else
						echo $timestamp ": Could not detect any camera on usb bus: Unknown model" >> /tmp/debugmtpdev
						break
					fi
				elif [ "$(echo "${StorageInfo}" | grep "store_")" != "" ]; then
					timeoffset=`cat /etc/timezone_offset`
					if [ "$timeoffset" == "" ]; then
						timeoffset=-8
					fi

					if [ "${timeoffset}" != "" ];then
						timeoffset_min=`dc ${timeoffset} 60 mul 480 add p`
					else
						timeoffset_min=0
					fi

					/usr/bin/gphotofs --time_offset ${timeoffset_min} --port=usb:${usbport1} -o allow_other,umask=0022 "$mtpmountpoint"
					if [ $? == 0 ]; then
						echo $timestamp ": PTP device mounted OK" >> /tmp/debugmtpdev
						mountSuccess=1
						break	
					fi
				fi
				retryMount=`expr "${retryMount}" - 1`
				sleep 1
			done

			ptppid=`pidof gphotofs`
			if [ "${ptppid}" == "" ]; then
				rm -rf "$mtpmountpoint"	
				killall gphotofs > /dev/null
				echo $timestamp ": PTP device mount fail retry 5: " $StorageInfo >> /tmp/debugmtpdev
				rm /tmp/mtpmountevent
				if [ -f "/tmp/detectInterface" ]; then
					rm -f /tmp/detectInterface
				fi
				exit 1
			fi

			storageNum=`echo "${StorageInfo}" | grep "Storage" | wc -l`
			#echo $timestamp ": PTP storageNum" $storageNum >> /tmp/debugmtpdev
			totalcapacity=0
			tmp=0
			free=0
			while [ "${storageNum}" != "0" ]; do
				tmp=`echo "${StorageInfo}" | grep totalcapacity | sed -n ${storageNum}p | awk -F= '{print $NF}' | awk '{print $1}'`
				#echo $timestamp ": PTP tmp" $tmp >> /tmp/debugmtpdev
				totalcapacity=`expr "$totalcapacity" + "$tmp"`
				#echo $timestamp ": PTP totalcapacity" $totalcapacity >> /tmp/debugmtpdev
				tmp=`echo "${StorageInfo}" | grep free | sed -n ${storageNum}p | awk -F= '{print $NF}' | awk '{print $1}'`
				#echo $timestamp ": PTP tmp" $tmp >> /tmp/debugmtpdev
				free=`expr "$free" + "$tmp"`
				#echo $timestamp ": PTP free" $free >> /tmp/debugmtpdev
				
				baseDIR=`echo "${StorageInfo}" | grep "basedir" | sed -n ${storageNum}p | awk -F\/ '{print $NF}'`
				#echo $timestamp ": PTP baseDIR" $baseDIR >> /tmp/debugmtpdev
				if [ -d "/media/USB/${baseDIR}/DCIM" ]; then
					/sbin/addDevice.sh USB ptpfs /media/USB/${baseDIR}/DCIM ptpfs
				else
					/sbin/addDevice.sh USB ptpfs /media/USB/${baseDIR} ptpfs
				fi
				storageNum=`expr "${storageNum}" - 1`
				echo "$totalcapacity" > /tmp/gphoto2_storage
				echo "$free" >> /tmp/gphoto2_storage
			done
			totalcapacity=`cat /tmp/gphoto2_storage | sed -n '1p'`
			free=`cat /tmp/gphoto2_storage | sed -n '2p'`
			totalcapacity=`expr "${totalcapacity}" / 1000`
			totalfree=`expr "${free}" / 1000`
			totalused=`expr "${totalcapacity}" - "${totalfree}"`
			echo $timestamp ": PTP totalcapacity" $totalcapacity >> /tmp/debugmtpdev
			echo $timestamp ": PTP totalfree" $totalfree >> /tmp/debugmtpdev
			echo $timestamp ": PTP totalused" $totalused >> /tmp/debugmtpdev
			echo $timestamp ": PTP device register addDevice done!" >> /tmp/debugmtpdev

			killall -16 ghelper
			rm /tmp/mtpmountevent
			exit 0
		fi
	else
		echo $timestamp ": No MTP/PTP inteface detect" >> /tmp/debugmtpdev
	fi
elif [ "${ACTION}" == "remove" ]; then
	touch /tmp/mtpmountevent
	echo "41;02;" > /tmp/MCU_Cmd
	if [ -f "/tmp/detectInterface" ]; then
		rm -f /tmp/detectInterface
	fi		

	mtppid=`pidof simple-mtpfs`
	if [ "$mtppid" != "" ] || [ -f "/tmp/MTPDeviceEjected" ] || [ -f "/tmp/sdmtpfs-info" ]; then
		fusermount -u "$mtpmountpoint"
		if [ $? != 0 ]; then
			umount -l $mtpmountpoint
			echo $timestamp ": MTP device umount fail" >> /tmp/debugmtpdev
			kill -9 $mtppid
		fi
		
			
		if [ -f "/tmp/MTPDeviceEjected" ]; then
			rm -f /tmp/MTPDeviceEjected
		fi
		echo $timestamp ": MTP device umount" >> /tmp/debugmtpdev
			
		/sbin/removeDevice.sh USB sdmtpfs
		killall simple-mtpfs > /dev/null
		rm -rf  $mtpmountpoint
		rm /tmp/mtpmountevent
		exit 0
	else
		echo $timestamp ": MTP device umount fail, because no pid, not tmp files" >> /tmp/debugmtpdev
	fi
		
	ptppid=`pidof ifuse`
	ptppid2=`pidof gphotofs`
	if [ "${ptppid}" != "" ] || [ "${ptppid2}" != "" ] || [ -f "/tmp/PTPDeviceEjected" ] || [ -f "/tmp/sdptpfs-info" ]; then
		fusermount -u "${mtpmountpoint}"
		if [ $? != 0 ]; then
			umount -l $mtpmountpoint
			echo $timestamp ": PTP device umount fail" >> /tmp/debugmtpdev
			if [ "${ptppid}" != "" ]; then
				kill -9 $ptppid
				
			fi
			if [ "${ptppid2}" != "" ]; then
				kill -9 $ptppid2
			fi
		fi
		if [ -f "/tmp/PTPDeviceEjected" ]; then
			rm -f /tmp/PTPDeviceEjected
		fi	
	
		rm -rf $mtpmountpoint
		/sbin/removeDevice.sh USB sdptpfs
		killall gphotofs > /dev/null
		killall ifuse > /dev/null
			
		echo $timestamp ": PTP device umount" >> /tmp/debugmtpdev
		rm /tmp/mtpmountevent
		exit 0
	else
		echo $timestamp ": PTP device umount fail, because no pid, not tmp files" >> /tmp/debugmtpdev
	fi
else
	echo $timestamp ": no usb dev detect" >> /tmp/debugmtpdev
fi

exit 0
