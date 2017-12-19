#!/bin/bash
#
#timestampDBG=$(date "+%Y.%m.%d-%H.%M.%S")
#echo $timestampDBG ": storage_transfer_status.sh" $@ >> /tmp/backup.log
if [ ! -f "/tmp/getStorageTransferStatus" ] ;then
	touch /tmp/getStorageTransferStatus
fi

if [ `cat /tmp/transfer_state | sed -n 's/.*=//p'` == "completed" ]; then
    total=`cat /tmp/transfer_size_total  | sed -n '1p' | sed -n 's/.*=//p'`
    sed -i "s/transferred_size_in_bytes=.*/transferred_size_in_bytes=$total/" /tmp/transfer_size
fi
cat /tmp/transfer_size_total
cat /tmp/transfer_size
cat /tmp/transfer_state
