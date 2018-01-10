#!/bin/bash

echo "${PPID} $1 $2 $3 $4" >> /tmp/removeDeviceLogs.log

DeviceType=$1
DevicePartitionNode=$2

if [ -f /var/lock/addDevice ] ; then
	exec 300>/var/lock/addDevice
	flock -x 300

	if [ $DeviceType == "SDcard" ] || [ $DeviceType == "USB" ] ; then
		if [ -f /tmp/${DevicePartitionNode}-info ]; then
			ShareName=`cat /tmp/${DevicePartitionNode}-info | cut -f 1 -d ':'`
			VolumeUUID=`cat /tmp/${DevicePartitionNode}-info | cut -f 2 -d ':'`
			DeviceMountPath=`cat /tmp/${DevicePartitionNode}-info | cut -f 3 -d ':'`
			DeviceUUID=`cat /tmp/${DevicePartitionNode}-info | cut -f 6 -d ':'`
			DeviceNode=`cat /tmp/${DevicePartitionNode}-info | cut -f 11 -d ':'`
			DeviceHandle=`cat /tmp/${DevicePartitionNode}-info | cut -f 9 -d ':'`
			#/usr/local/sbin/crud_share_db.sh delete "${ShareName}" /etc/samba/smb-shares.conf
			/usr/local/sbin/volume_mount.sh unmount "${VolumeUUID}"			
			/usr/local/sbin/crud_share_db.sh delete "${ShareName}" /etc/samba/smb-shares.conf
			/usr/local/sbin/storage_transfer_cancel_now.sh ${DeviceHandle} "eject" > /dev/null 2>&1 & 
			/sbin/refresh_contentdirs.sh
			sed -i "/Begin DeviceUUID = ${DeviceUUID}/,/End DeviceUUID = ${DeviceUUID}/d" /etc/samba/smb-shares.conf
			sed -i "/Begin DeviceUUID = ${DeviceUUID}/,/End DeviceUUID = ${DeviceUUID}/d" /etc/afp.conf
			killall -SIGHUP smbd
			killall -SIGHUP netatalk
			if [ $DeviceType == "SDcard" ]; then
				sed -i 's/TransferStatus=.*/TransferStatus=completed/' /etc/nas/config/sdcard-transfer-status.conf
				/usr/local/sbin/incUpdateCount.pm sd_card &
				echo "41;02;" > /tmp/MCU_Cmd
			fi
			if [ $DeviceType == "USB" ]; then
				echo "41;02;" > /tmp/MCU_Cmd
				sed -i 's/USB_TransferStatus=.*/USB_TransferStatus=completed/' /etc/nas/config/usb-transfer-status.conf
				/usr/local/sbin/incUpdateCount.pm usb &
			fi
			if [ -e /shares/"${ShareName}" ]; then
				rm -f /shares/"${ShareName}"
			else
				if [ -L /shares/"${ShareName}" ]; then
					rm -f /shares/"${ShareName}"
				fi
			fi
			#/sbin/refresh_contentdirs.sh
			if [ "$DevicePartitionNode" == "sdmtpfs" -o "$DevicePartitionNode" == "sdptpfs" ]; then
				fusermount -u /var/ftp/"${ShareName}"
				rmdir /var/ftp/"${ShareName}"
			else
				if [ -e /var/ftp/"${ShareName}" ]; then
					ftpmount=`mount | grep -c "/var/ftp/"${ShareName}" type"`
					[ ${ftpmount} -eq 1 ] && fuser -mk /var/ftp/"${ShareName}" 
					umount /var/ftp/"${ShareName}"
					rmdir /var/ftp/"${ShareName}"
				fi
			fi
			/usr/local/sbin/incUpdateCount.pm share &
			/sbin/CheckMediaCrawler.sh "${VolumeUUID}" &
			rm -f /tmp/${DevicePartitionNode}-info
		fi
		rm -f /tmp/"${DeviceNode}"-device
		/usr/local/sbin/wdAutoMountAdm.pm getRealDrives > /tmp/getDrives 2>&1
		if [ ! -f /tmp/HDSerial ]; then
			HDSerial_temp=`hdparm -I \`cat /tmp/HDDDevNode\` | sed -n -e 's/.*Serial Number:\(.*\)/\1/p' | sed -e 's/^[ \t]*//' | awk '{gsub("WD-","",$0); print $0}'`
			HDSerial=${HDSerial_temp// /}
			echo "${HDSerial}" > /tmp/HDSerial
		else
			HDSerial=`cat /tmp/HDSerial`
		fi
		result=`sqlite3 /usr/local/nas/orion/orion.db 'select * from Volumes' | grep "${HDSerial}"_1  | wc -l`
		if [ ${result} == "0" ]; then
			FStype=`cat /proc/mounts | grep "/media/sdb1 " | cut -d " " -f 3`
			echo "${PPID} Detecting Storage Volume removed from orion.db" >> /tmp/removeDeviceLogs.log
			/usr/local/sbin/volume_mount.sh mount "${HDSerial}"_1 "" `cat /tmp/MountedDevNode` ${FStype}
			result=`sqlite3 /usr/local/nas/orion/orion.db 'select * from Volumes' | grep "${HDSerial}"_1  | wc -l`
			if [ ${result} == "0" ]; then
				sleep 1
				/usr/local/sbin/volume_mount.sh mount "${HDSerial}"_1 "" `cat /tmp/MountedDevNode` ${FStype}
			fi
			result=`sqlite3 /usr/local/nas/orion/orion.db 'select * from Volumes' | grep "${HDSerial}"_1  | wc -l`
		fi
	fi
	flock -u 300
fi