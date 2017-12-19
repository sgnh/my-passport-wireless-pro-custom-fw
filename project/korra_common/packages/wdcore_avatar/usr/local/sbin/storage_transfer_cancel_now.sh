#!/bin/bash

. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf
. /etc/nas/config/sdcard-param.conf

timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": storage_transfer_cancel_now.sh" $@ >> /tmp/backup.log

	
if [ ! -f "/tmp/transfer_state" ]; then
	exit 3 
fi	
#if [ `cat /tmp/transfer_state | sed -n 's/.*=//p'` != "running" ]; then
#	exit 3 
#fi
	
function USB_BackupQueueCheck()
{
	#check USB backup process
	#echo "USB_TransferStatus=standby:""$method"
	usbstandby=`echo "${USB_TransferStatus}" | awk -F: '{print $1}'`
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": storage_transfer_cancel_now.sh usbstandby" $usbstandby >> /tmp/backup.log
	if [ "$usbstandby" == "standby" ]; then
		triggerMode=`echo "${TransferStatus}" | awk -F: '{print $2}'`
		if [ "${triggerMode}" == "Button" ]; then
			/sbin/ButtonStorageTransfer.sh USB
		elif [ "${triggerMode}" == "Auto" ]; then
			/sbin/ButtonStorageTransfer.sh USB
		else
			/sbin/USB_StorageTransfer.sh
		fi
	fi
}	
	
function SD_BackupQueueCheck()
{
	sdstandby=`echo "${TransferStatus}" | awk -F: '{print $1}'`
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": storage_transfer_cancel_now.sh sdstandby" $usbstandby >> /tmp/backup.log
	if [ "$sdstandby" == "standby" ]; then
		triggerMode=`echo "${TransferStatus}" | awk -F: '{print $2}'`
		if [ "${triggerMode}" == "Button" ]; then
			/sbin/ButtonStorageTransfer.sh SD
		elif [ "${triggerMode}" == "Auto" ]; then
			/sbin/ButtonStorageTransfer.sh SD
		else
			/sbin/SDCard_StorageTransfer.sh
		fi
	fi
}
	
handle="${1}"
method=$2
	
if [ "$handle" != "" ]; then	
	#if [ "${TransferStatus}" == "completed" ] && [ "${USB_TransferStatus}" == "completed" ]; then
	#	echo "18;0;" > /tmp/MCU_Cmd
	#fi
	#ongoing=`ps aux | grep "SD Card Imports" | grep "${handle}"`
	ongoing=`cat /tmp/mmcblk0*-info | grep "${handle}" `
	if [ "$ongoing" != "" ] && [ "${TransferStatus}" == "process" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": storage_transfer_cancel_now.sh Stop SD Ongoing" $ongoing >> /tmp/backup.log
	
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
		#echo "18;0;" > /tmp/MCU_Cmd
		echo "status=failed" > /tmp/transfer_state
		echo "TransferStatus=completed" > /etc/nas/config/sdcard-transfer-status.conf
		if [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		else
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		fi
		USB_BackupQueueCheck
	elif [ "$ongoing" != "" ]; then
		if [ "${USB_TransferStatus}" != "process" ] && [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		fi
		Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select id from Jobs where jobstate_id=1'`
		if [ "${Waiting}" != "" ]; then
			REST_API_URL="http://localhost/api/1.0/rest/jobs/${Waiting}?auth_username=admin&user_id=admin&auth_password=&rest_method=PUT&action=cancel"
			CRET=`curl -m 3 -sL -w "%{http_code}\\n" $REST_API_URL -o /dev/null`
		fi
		
	fi

	handlehead=`echo "${handle}" | cut -c 1-6`
	#ongoing=`ps aux | grep "USB Imports" | grep "${handle}"`
	ongoing=`cat /tmp/sd*-info | grep "${handlehead}"`
	if [ "$ongoing" != "" ] && [ "${USB_TransferStatus}" == "process" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": storage_transfer_cancel_now.sh Stop USB Ongoing" $ongoing >> /tmp/backup.log
		
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
		#echo "18;0;" > /tmp/MCU_Cmd
		echo "status=failed" > /tmp/transfer_state
		echo "USB_TransferStatus=completed" > /etc/nas/config/usb-transfer-status.conf
		if [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		else
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 0
		fi
		SD_BackupQueueCheck
	elif [ "$ongoing" != "" ]; then
		if [ "${TransferStatus}" != "process" ] && [ "$method" == "eject" ]; then
			/usr/local/sbin/storage_transfer_LED_status.sh stop_error 4
		fi
		Waiting=`sqlite3 /usr/local/nas/orion/jobs.db  'select id from Jobs where jobstate_id=1'`
		if [ "${Waiting}" != "" ]; then
			REST_API_URL="http://localhost/api/1.0/rest/jobs/${Waiting}?auth_username=admin&user_id=admin&auth_password=&rest_method=PUT&action=cancel"
			CRET=`curl -m 3 -sL -w "%{http_code}\\n" $REST_API_URL -o /dev/null`
		fi
		
	fi

else
	if [ "${USB_TransferStatus}" == "process" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": storage_transfer_cancel_now.sh Stop USB Onprocess" >> /tmp/backup.log
		
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
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": storage_transfer_cancel_now.sh Stop SD Onprocess" >> /tmp/backup.log
		
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
	#killall rsync > /dev/null 2>&1
	echo "18;0;" > /tmp/MCU_Cmd
fi
