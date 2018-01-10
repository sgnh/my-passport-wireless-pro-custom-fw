#!/bin/bash

. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf
. /etc/nas/config/sdcard-param.conf

timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": storage_transfer_cancel_now.sh called:" $@ >> /tmp/backup.log

	
if [ ! -f "/tmp/transfer_state" ]; then
	echo $timestamp ": storage_transfer_cancel_now.sh no state file" >> /tmp/backup.log
	exit 3
fi	
	
function USB_BackupQueueCheck()
{
	USB_status=`cat /etc/nas/config/usb-transfer-status.conf | awk -F= '{print $NF}'`
	echo $timestamp ": storage_transfer_cancel_now.sh USB_BackupQueueCheck" $USB_status >> /tmp/backup.log
	if [ "$USB_status" != "completed" ]; then
		usb_standby=`echo "${USB_status}" | awk -F: '{print $1}'`
		echo $timestamp ": storage_transfer_cancel_now.sh USB_BackupQueueCheck sdstandby:" $sdstandby >> /tmp/backup.log
		sleep 20
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		if [ "$usb_standby" == "standby" ]; then
			triggerMode=`echo "${USB_status}" | awk -F: '{print $2}'`
			if [ "${triggerMode}" == "Button" ]; then
				/sbin/ButtonStorageTransfer.sh USB
			elif [ "${triggerMode}" == "Auto" ]; then
				/sbin/USB_AutoStorageTransfer.sh
			else
				/sbin/ButtonStorageTransfer.sh USB
			fi
		elif [ "$usbstandby" == "checkin" ]; then

			/sbin/ButtonStorageTransfer.sh USB 2>&1 &
		fi
	fi
}	
	
function SD_BackupQueueCheck()
{
	SD_status=`cat /etc/nas/config/sdcard-transfer-status.conf | awk -F= '{print $NF}'`
	echo $timestamp ": storage_transfer_cancel_now.sh SD_BackupQueueCheck SD_status:" $SD_status >> /tmp/backup.log
	if [ "${SD_status}" != "completed" ]; then
		sdstandby=`echo "${SD_status}" | awk -F: '{print $1}'`
		echo $timestamp ": storage_transfer_cancel_now.sh SD_BackupQueueCheck sdstandby:" $sdstandby >> /tmp/backup.log
		sleep 20
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		if [ "$sdstandby" == "standby" ]; then
			triggerMode=`echo "${SD_status}" | awk -F: '{print $2}'`
			if [ "${triggerMode}" == "Button" ]; then	
				/sbin/ButtonStorageTransfer.sh SD
			elif [ "${triggerMode}" == "Auto" ]; then
				/sbin/SDCard_AutoStorageTransfer.sh
			else
				/sbin/ButtonStorageTransfer.sh SD
			fi
		elif [ "$sdstandby" == "checkin" ]; then
			/sbin/ButtonStorageTransfer.sh SD 2>&1 &
		fi
	fi
}
	
handle="${1}"
method=$2

if [ "$handle" != "" ]; then
	ongoing=`cat /tmp/mmcblk0*-info | grep "${handle}" `
	if [ "$ongoing" != "" ] && [ "${TransferStatus}" == "process" ]; then
		echo $timestamp ": storage_transfer_cancel_now.sh SD backup still processing:" $ongoing >> /tmp/backup.log
	
		SDmount=`cat /tmp/mmcblk0*-info | grep "${handle}" | awk -F: '{print $3}'`
		StorageVendor=`cat /tmp/mmcblk0*-info | grep "${handle}" | awk -F: '{print $7}'`
		echo "${StorageVendor}" | grep -q -v '[A-Za-z0-9]'
		if [ $? == 0 ]; then
			StorageVendor=SDCard
		fi
		StorageProduct=`cat /tmp/mmcblk0*-info | grep "${handle}" | awk -F: '{print $1}' | sed -e 's/\ //g'`
		SerialNum=`cat /tmp/mmcblk0*-info | grep "${handle}" | awk -F: '{print $6}' | cut -d ' ' -f 2 | awk -F_ '{print $1}'`
		
		sleep 1
		
		if [ -f "/tmp/SDCard_AutoProcessing" ]; then
			rm /tmp/SDCard_AutoProcessing
		fi

		if [ -f "/tmp/SDCard_ButtonProcessing" ]; then
			rm /tmp/SDCard_ButtonProcessing
		fi
	
		rsyncpid=`ps aux | grep rsync | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$rsyncpid" != "" ]; then
			kill -15 "$rsyncpid" > /dev/null 2>&1
		fi
		
		rsyncpid=`ps aux | grep rsync | grep "${SDmount}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$rsyncpid" != "" ]; then
			kill -15 "$rsyncpid" > /dev/null 2>&1
		fi
	
		backupid=`pidof SDCard_StorageTransfer.sh`
		#echo "backupid" $backupid
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi
		
		rsyncCal=`pidof CalTransfer.sh`
		#echo "rsyncCal" $rsyncCal
		if [ "$rsyncCal" != "" ]; then
			kill -15 "$rsyncCal" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -rsw "cp" | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -rsw "mv" | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep "find" | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep "SDCard_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		findpid=`ps aux | grep find | grep "SD Card Imports" | grep "${handle}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$findpid" != "" ]; then
			kill -15 "$findpid" > /dev/null 2>&1
		fi
		
		killall CalTransfer.sh > /dev/null 2>&1
		killall SDCard_StorageTransfer.sh > /dev/null 2>&1
		
		/usr/local/sbin/sendAlert.sh 1605 $StorageVendor $StorageProduct $SerialNum &
		
		sleep 1

		echo "status=failed" > /tmp/transfer_state
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		if [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		else
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		fi
		USB_BackupQueueCheck
	elif [ "$ongoing" != "" ]; then
		/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		echo $timestamp ": storage_transfer_cancel_now.sh not processing, so cancel the waiting jobs id" >> /tmp/backup.log
		
		Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select id from Jobs where jobstate_id=1'`
		if [ "${Waiting}" != "" ]; then
			REST_API_URL="http://localhost/api/1.0/rest/jobs/${Waiting}?auth_username=admin&user_id=admin&auth_password=&rest_method=PUT&action=cancel"
			CRET=`curl -m 3 -sL -w "%{http_code}\\n" $REST_API_URL -o /dev/null`
		fi
		
	fi

	handlehead=`echo "${handle}" | cut -c 1-6`
	ongoing=`cat /tmp/sd*-info | grep "${handlehead}"`
	if [ "$ongoing" != "" ] && [ "${USB_TransferStatus}" == "process" ]; then
		echo $timestamp ": storage_transfer_cancel_now.sh USB backup still processing" $ongoing >> /tmp/backup.log
		
		USBmount=`cat /tmp/sd*-info | grep "${handlehead}" | awk -F: '{print $3}'`
		StorageProduct=`cat /tmp/sd*-info | grep "${handlehead}" | awk -F: '{print $1}' | sed -e 's/\ //g'`
		SerialNum=`cat /tmp/sd*-info | grep "${handlehead}" | awk -F: '{print $6}' | cut -d ' ' -f 2 | awk -F_ '{print $1}'`
	
		if [ -f "/tmp/USB_AutoProcessing" ]; then
			rm /tmp/USB_AutoProcessing
		fi

		if [ -f "/tmp/USB_ButtonProcessing" ]; then
			rm /tmp/USB_ButtonProcessing
		fi
		
		rsyncCal=`pidof CalTransfer.sh`
		if [ "$rsyncCal" != "" ]; then
			kill -15 "$rsyncCal" > /dev/null 2>&1
		fi
		
		rsyncpid=`ps aux | grep rsync | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$rsyncpid" != "" ]; then
			kill -15 "$rsyncpid" > /dev/null 2>&1
		fi
		
		rsyncpid=`ps aux | grep rsync | grep "${USBmount}" | grep "${handlehead}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$rsyncpid" != "" ]; then
			kill -15 "$rsyncpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -rsw "cp" | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -rsw "mv" | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		backupid=`pidof USB_StorageTransfer.sh`
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi	
		methodpid=`ps aux | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		findpid=`ps aux | grep find | grep "USB Imports" | grep "${handlehead}" | awk '{print $1}' `
		#echo "rsyncpid" $rsyncpid
		if [ "$findpid" != "" ]; then
			kill -15 "$findpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep -v "grep" | grep "USB_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		killall CalTransfer.sh > /dev/null 2>&1
		killall USB_StorageTransfer.sh > /dev/null 2>&1
		
		/usr/local/sbin/sendAlert.sh 1606 $StorageVendor $StorageProduct $SerialNum &
		sleep 1
		echo "status=failed" > /tmp/transfer_state
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		if [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		else
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		fi
		SD_BackupQueueCheck
	elif [ "$ongoing" != "" ]; then
		echo $timestamp ": storage_transfer_cancel_now.sh not processing, so cancel the waiting jobs id" >> /tmp/backup.log
		/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		
		Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select id from Jobs where jobstate_id=1'`
		if [ "${Waiting}" != "" ]; then
			REST_API_URL="http://localhost/api/1.0/rest/jobs/${Waiting}?auth_username=admin&user_id=admin&auth_password=&rest_method=PUT&action=cancel"
			CRET=`curl -m 3 -sL -w "%{http_code}\\n" $REST_API_URL -o /dev/null`
		fi
	fi
else
	if [ "${USB_TransferStatus}" == "process" ]; then
		echo $timestamp ": storage_transfer_cancel_now.sh USB status:" ${USB_TransferStatus} >> /tmp/backup.log
		
		echo "status=failed" > /tmp/transfer_state
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		backupid=`pidof USB_StorageTransfer.sh`
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep "USB_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep "USB_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
		rsyncCal=`pidof CalTransfer.sh`
		if [ "$rsyncCal" != "" ]; then
			kill -15 "$rsyncCal" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux |  grep -v "grep" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep -rsw "cp" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -v "grep" | grep -rsw "mv" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -v "grep" | grep -rsw "cp" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -v "grep" | grep -rsw "mv" | grep "USB Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
		
		backupid=`pidof USB_StorageTransfer.sh`
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi
	
		if [ -f "/tmp/USB_AutoProcessing" ]; then
			rm /tmp/USB_AutoProcessing
		fi

		if [ -f "/tmp/USB_ButtonProcessing" ]; then
			rm /tmp/USB_ButtonProcessing
		fi
		
	fi
	if [ "${TransferStatus}" == "process" ]; then
		echo $timestamp ": storage_transfer_cancel_now.sh SD status:" ${TransferStatus} >> /tmp/backup.log
		
		echo "status=failed" > /tmp/transfer_state
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		backupid=`pidof SDCard_StorageTransfer.sh`
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep "SDCard_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		methodpid=`ps aux | grep -v "grep" | grep "SDCard_StorageTransfer.sh" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
		rsyncCal=`pidof CalTransfer.sh`
		if [ "$rsyncCal" != "" ]; then
			kill -15 "$rsyncCal" > /dev/null 2>&1
		fi
		methodpid=`ps aux |  grep -v "grep" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
		
		methodpid=`ps aux | grep -v "grep" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi	
		
		methodpid=`ps aux | grep -v "grep" | grep -rsw "cp" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi

		methodpid=`ps aux | grep -v "grep" | grep -rsw "mv" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -15 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -v "grep" | grep -rsw "cp" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
	
		methodpid=`ps aux | grep -v "grep" | grep -rsw "mv" | grep "SD Card Imports" | awk '{print $1}' | head -1`
		#echo "methodpid" $methodpid
		if [ "$methodpid" != "" ]; then
			kill -9 "$methodpid" > /dev/null 2>&1
		fi
	
		backupid=`pidof SDCard_StorageTransfer.sh`
		if [ "$backupid" != "" ]; then
			kill -15 "$backupid" > /dev/null 2>&1
		fi
		
		if [ -f "/tmp/SDCard_AutoProcessing" ]; then
			rm /tmp/SDCard_AutoProcessing
		fi

		if [ -f "/tmp/SDCard_ButtonProcessing" ]; then
			rm /tmp/SDCard_ButtonProcessing
		fi	
	fi
	
	echo "18;0;" > /tmp/MCU_Cmd
	echo "42;100" > /tmp/MCU_Cmd
fi
