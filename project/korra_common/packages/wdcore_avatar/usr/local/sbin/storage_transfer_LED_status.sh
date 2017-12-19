#!/bin/bash
#
. /etc/nas/config/sdcard-transfer-status.conf
. /etc/nas/config/usb-transfer-status.conf

timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestampDBG ": storage_transfer_LED_status.sh" $USB_TransferStatus $TransferStatus $1 $2 >> /tmp/backup.log

delay=0
method=$1
if [ "$2" != "" ]; then
	delay=$2
fi

case "$method" in
	starting)
		if [ "$USB_TransferStatus" != "process" ] && [ "$TransferStatus" != "process" ]; then
			echo "18;0;" > /tmp/MCU_Cmd
			echo "18;1;" > /tmp/MCU_Cmd
			echo "42;0;" > /tmp/MCU_Cmd
		fi
		;;
	stop_error)
		sleep $delay
		echo "18;0;" > /tmp/MCU_Cmd
		echo "42;124" > /tmp/MCU_Cmd
		;;
esac