#!/bin/bash

source /etc/power.conf
devstr=$1
mtpmountpoint=/media/USB
realmtp=/media/sdb1/.wdmtp/

if [ ! -f "/tmp/rsync_ready" ]; then
	exit 0
fi

timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": $devstr ${PPID} ${ACTION} ${DEVNAME}" >> /tmp/debugmtpdev

function PTPmountCheck()
{
	checkmtpfs=`cat /proc/mounts | grep gphotofs`
	if [ "$checkmtpfs" != "" ]; then
		fusermount -u "${mtpmountpoint}"
		umount -l "${mtpmountpoint}"
		killall gphotofs
		sleep 2
	fi
	checkmtpfs=`cat /proc/mounts | grep ifuse`
	if [ "$checkmtpfs" != "" ]; then
		fusermount -u "${mtpmountpoint}"
		umount -l "${mtpmountpoint}"
		killall usbmuxd > /dev/null
		killall ifuse > /dev/null
		sleep 2
	fi
}

if [ "${1}" == "bootingCheck" ]; then
	sleep 5
	devstr="bus/usb"	
fi
usbdev=`echo "$devstr" | grep "bus\/usb"`
usbport1=`echo "$devstr" | awk -F\/ '{print $3","$4}'`


if [ "$usbdev" != "" ]; then
	echo "Check!!!"
	DEV_MANUF=`cat /sys/bus/usb/devices/[345]-1*/manufacturer`
	echo "$DEV_MANUF" >> /tmp/debugmtpdev
	
	DEV_PROD=`cat /sys/bus/usb/devices/[345]-1*/product`
	echo "$DEV_PROD" >> /tmp/debugmtpdev
	
	DEV_SERIALNUM=`cat /sys/bus/usb/devices/[345]-1*/serial`
	echo "$DEV_SERIALNUM" >> /tmp/debugmtpdev
	
	DEV_VENDOR=`cat /sys/bus/usb/devices/[345]-1*/idVendor`
	echo "$DEV_VENDOR" >> /tmp/debugmtpdev
	
	DEV_IDPROD=`cat /sys/bus/usb/devices/[345]-1*/idProduct`
	echo "$DEV_IDPROD" >> /tmp/debugmtpdev
	
	if [ "$DEV_MANUF" == "" ] && [ "$DEV_PROD" == "" ] && [ "$DEV_SERIALNUM" == "" ] && [ "$DEV_VENDOR" == "" ] && [ "$DEV_IDPROD" == "" ]; then
		if [ "${ACTION}" == "remove" ]; then
			echo "41;02;" > /tmp/MCU_Cmd
		fi
		mtppid=`pidof simple-mtpfs`
		if [ "$mtppid" != "" ] || [ -f /tmp/MTPDeviceEjected ]; then
			/sbin/removeDevice.sh USB sdmtpfs
			umount -l $mtpmountpoint
			if [ $? != 0 ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": MTP device umount fail" >> /tmp/debugmtpdev
				kill -9 $mtppid
				killall simple-mtpfs > /dev/null
			fi
			if [ -f /tmp/MTPDeviceEjected ]; then
				rm -f /tmp/MTPDeviceEjected
			fi
			rm -rf  $mtpmountpoint
			echo $timestamp ": MTP device umount" >> /tmp/debugmtpdev
			
		fi
	
		ptppid=`pidof ifuse`
		ptppid2=`pidof gphotofs`
		usbmuxdpid=`pidof usbmuxd`   
		if [ "${ptppid}" != "" ] || [ "${ptppid2}" != "" ] || [ -f "/tmp/PTPDeviceEjected" ]; then
			/sbin/removeDevice.sh USB sdptpfs
			umount -l $mtpmountpoint
			kill -15 $usbmuxdpid
			if [ $? != 0 ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": PTP device umount fail" >> /tmp/debugmtpdev
				if [ "${ptppid}" != "" ]; then
					kill -9 $ptppid
					kill -9 $usbmuxdpid
					killall usbmuxd > /dev/null
					killall ifuse > /dev/null
				fi
				if [ "${ptppid2}" != "" ]; then
					kill -9 $ptppid2
					killall gphotofs
				fi
			fi
			if [ -f /tmp/PTPDeviceEjected ]; then
				rm -f /tmp/PTPDeviceEjected
			fi
			if [ "${ptppid}" != "" ]; then
				killall usbmuxd > /dev/null
			fi
			rm -rf  $mtpmountpoint
			echo $timestamp ": PTP device umount" >> /tmp/debugmtpdev
		fi
		echo $timestamp ": no usb storage device detect-${ACTION}" >> /tmp/debugmtpdev
		if [ -f "/tmp/detectInterface" ]; then
			rm /tmp/detectInterface
		fi		
		exit 1
	fi
	
	
	NdetectInterface=`cat /sys/bus/usb/devices/3-1*/interface | wc -l`
	if [ ${NdetectInterface} -eq 0 ]; then
		cat /sys/bus/usb/devices/4-1*/interface > /tmp/detectInterface
	else
		cat /sys/bus/usb/devices/3-1*/interface > /tmp/detectInterface
	fi
	devicefound=`cat /tmp/detectInterface | grep "MTP"`
	if [ "$devicefound" == "MTP" ]; then
		echo "MTP" > /tmp/detectInterface
		devicefound="MTP"
		echo $timestamp ": MTP Device ${DEVNAME} detected by interface" >> /tmp/debugmtpdev
	else
		hotplug=`/usr/bin/mtp-hotplug | grep "$DEV_IDPROD" | grep "$DEV_VENDOR"`
		if [ "$hotplug" != "" ]; then
			echo "MTP" > /tmp/detectInterface
			devicefound="MTP"
			echo $timestamp ": MTP Device detected by mtp-hotplug" >> /tmp/debugmtpdev
		else
			/usr/bin/gphoto2 -a --port=usb:${usbport1} >> /tmp/debugmtpdev
			if [ "$(/usr/bin/gphoto2 -a --port=usb:${usbport1} | grep "File preview" | grep "yes")" != "" ] || [ "$(/usr/bin/gphoto2 -a --port=usb:${usbport1} | grep "PTP")" != "" ]; then
				echo "PTP" > /tmp/detectInterface		
				devicefound="PTP"
				echo $timestamp ": PTP Device ${DEVNAME} detected by gphoto2" >> /tmp/debugmtpdev
			else
				if [ "$(/usr/bin/gphoto2 -a --port=usb:${usbport1} | grep "USB support" | grep "yes")" != "" ]; then
					echo "PTP" > /tmp/detectInterface
					devicefound="PTP"
					echo $timestamp ": PTP Device ${DEVNAME} detected by gphoto2" >> /tmp/debugmtpdev
				else 
					echo $timestamp ": no usb storage device detect" >> /tmp/debugmtpdev
					exit 1
				fi
			fi 
		fi
	fi

	


	if [ "$devicefound" == "MTP" ]; then
		echo "41;01;" > /tmp/MCU_Cmd
		
		echo "$DEV_SERIALNUM" > /tmp/MTPDeviceSerialNumber 	
		#if [ ! -d "$realmtp" ]; then
		#	mkdir -p "$realmtp"
		#fi
		#	ln -s "$realmtp" "$mtpmountpoint"
		#fi
		
		if [ ! -d "$mtpmountpoint" ]; then
			mkdir -p "$mtpmountpoint"
		fi
		
		checkmtpfs=`cat /proc/mounts | grep simple-mtpfs`
		if [ "$checkmtpfs" != "" ]; then
			#fusermount -u "$mtpmountpoint"
			umount -l $mtpmountpoint
			sleep 2
		fi

		/usr/bin/simple-mtpfs -o allow_other,umask=0000 "$mtpmountpoint"
		if [ $? != 0 ]; then
			rm -rf "$mtpmountpoint"
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": mtp device mount fail" >> /tmp/debugmtpdev
			if [ "$DEV_VENDOR" == "2672" ]; then
				echo $timestamp ": mtp device mount fail but GoPro detect" >> /tmp/addDeviceLogs.log
				echo "45;01;" > /tmp/MCU_Cmd
			fi
			exit 0
		fi
		/sbin/addDevice.sh USB mtpfs /media/USB mtpfs
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": mtp device mounted !!" >> /tmp/debugmtpdev
		killall -16 ghelper
	elif [ "$devicefound" == "PTP" ]; then
		echo "41;01;" > /tmp/MCU_Cmd
		
		if [ "$DEV_MANUF" == "Apple Inc." ] && [ "$DEV_VENDOR" == "05ac" ]; then
			echo $timestamp ": iOS Device PTP mode" >> /tmp/debugmtpdev
			#if [ ! -d "$realmtp" ]; then
			#	mkdir -p "$realmtp"
			#fi
			
			if [ ! -d "$mtpmountpoint" ]; then
				mkdir -p "$mtpmountpoint"
			fi
			#ln -s "$realmtp" "$mtpmountpoint"
			PTPmountCheck
			
			count=5
			while [ "$count" != 0 ]; do
				StorageInfo=`/usr/bin/gphoto2 --port=usb:${usbport1} --storage-info`
				echo $timestamp ": iphone StorageInfo" $StorageInfo >> /tmp/debugmtpdev
				if [ "$(echo "${StorageInfo}" | grep "error")" != "" ]; then
					if [ "$(/usr/bin/gphoto2 -a --port=usb:${usbport1} | grep "File preview" | grep "yes")" == "" ] || [ "$(/usr/bin/gphoto2 -a --port=usb:${usbport1} | grep "PTP")" == "" ]; then
						echo $timestamp ": No camera found" >> /tmp/debugmtpdev
						usbmuxdpid=`pidof usbmuxd`
						if [ "$usbmuxdpid" != "" ]; then
							kill -15 $usbmuxdpid
						fi
						echo "41;02;" > /tmp/MCU_Cmd
						exit 1
					fi
				elif [ "$(echo "${StorageInfo}" | grep "store_")" != "" ]; then
					count=`expr "${count}" - 1`
					if [ "$count" -le 3 ]; then
						timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
						echo $timestamp ": iOS Device PTP mode Trust" $count >> /tmp/debugmtpdev
						usbmuxdpid=`pidof usbmuxd`
						if [ "$usbmuxdpid" == "" ]; then
							/usr/sbin/usbmuxd -z
						fi
						sleep 3
						for ((index=1; index<=3; index++ )); do
							ActivationState=`/usr/bin/ideviceinfo | grep "ActivationState"`
							if [ "$ActivationState" != "" ]; then
								sleep 1
								/usr/bin/ifuse -o allow_other,umask=0022 "/media/USB"
								timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
								if [ $? != 0 ]; then
									echo $timestamp ": PTP device mounted fail" $index >> /tmp/debugmtpdev
									
								else
									echo $timestamp ": PTP device mounted OK" >> /tmp/debugmtpdev
							
									sleep 1
									if [ -d /media/USB/DCIM ]; then
										/sbin/addDevice.sh USB ptpfs /media/USB/DCIM ptpfs
									else
										/sbin/addDevice.sh USB ptpfs /media/USB ptpfs
									fi
									killall -16 ghelper
									exit 0
								fi
							else
								count=`expr "${count}" + 1`
								break
							fi
							sleep 5
						done
					fi
				fi
				sleep 1
			done
			
			ptppid=`pidof ifuse`
			if [ "${ptppid}" == "" ]; then
				rm -rf "$mtpmountpoint"	
				killall usbmuxd > /dev/null
				killall ifuse > /dev/null
				if [ "$DEV_VENDOR" == "2672" ]; then
					echo $timestamp ": ptp device mount fail but GoPro detect" >> /tmp/addDeviceLogs.log
					echo "45;01;" > /tmp/MCU_Cmd
				fi
				exit 1
			fi
			
		else
			#if [ ! -d "$realmtp" ]; then
			#	mkdir -p "$realmtp"
			#fi
			if [ ! -d "$mtpmountpoint" ]; then
				mkdir -p "$mtpmountpoint"
			fi
			#ln -s "$realmtp" "$mtpmountpoint"
		
			PTPmountCheck
		
			/usr/bin/gphoto2 --port=usb:${usbport1} --storage-info > /tmp/gphoto2
			/usr/bin/gphoto2 --port=usb:${usbport1} --storage-info >> /tmp/debugmtpdev
			
			for ((index=1; index<=3; index++ )); do
				/usr/bin/gphotofs --port=usb:${usbport1} -o allow_other,umask=0022 "$mtpmountpoint"
				if [ $? != 0 ]; then
					echo $timestamp ": PTP device mounted fail $index" >> /tmp/debugmtpdev
					sleep 5
				fi
			done
			sleep 1
			storageNum=`cat /tmp/gphoto2 | grep "Storage" | wc -l`
			echo $timestamp ": PTP storageNum" $storageNum >> /tmp/debugmtpdev
			totalcapacity=0
			tmp=0
			free=0
			while [ "${storageNum}" != "0" ]; do
				tmp=`cat /tmp/gphoto2 | grep totalcapacity | sed -n ${storageNum}p | awk -F= '{print $NF}' | awk '{print $1}'`
				echo $timestamp ": PTP tmp" $tmp >> /tmp/debugmtpdev
				totalcapacity=`expr "$totalcapacity" + "$tmp"`
				echo $timestamp ": PTP totalcapacity" $totalcapacity >> /tmp/debugmtpdev
				tmp=`cat /tmp/gphoto2 | grep free | sed -n ${storageNum}p | awk -F= '{print $NF}' | awk '{print $1}'`
				echo $timestamp ": PTP tmp" $tmp >> /tmp/debugmtpdev
				free=`expr "$free" + "$tmp"`
				echo $timestamp ": PTP free" $free >> /tmp/debugmtpdev
				
				baseDIR=`cat /tmp/gphoto2 | grep "basedir" | sed -n ${storageNum}p | awk -F\/ '{print $NF}'`
				echo $timestamp ": PTP baseDIR" $baseDIR >> /tmp/debugmtpdev
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

			sleep 1
			ptppid=`pidof gphotofs`
			if [ "${ptppid}" == "" ]; then
				rm -rf "$mtpmountpoint"	
				killall gphotofs > /dev/null
				if [ "$DEV_VENDOR" == "2672" ]; then
					echo $timestamp ": ptp device mount fail but GoPro detect" >> /tmp/addDeviceLogs.log
					echo "45;01;" > /tmp/MCU_Cmd
				fi
				exit 1
			fi		
			killall -16 ghelper
		fi
	fi
else
	echo $timestamp ": no usb dev detect" >> /tmp/debugmtpdev
fi
