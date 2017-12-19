#!/bin/bash

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

compiling_external_db=`/usr/local/sbin/getMediaCrawlerStatus.sh  | grep "/shares/.USB/usb_$1" | grep -e "\"scanning\"" -e "\"extracting\"" -e "\"transcoding\"" | wc -l`

if [ "${compiling_external_db}" -gt "0" ]; then
    /etc/init.d/S85wdmcserverd stop
    sleep 5
    /etc/init.d/S85wdmcserverd start
fi

convert_db_pid=`ps aux | grep convert | grep "/shares/.USB/usb_$1" | awk '{print $1}'`
if [ "${convert_db_pid}" != "" ]; then
	kill -9 ${convert_db_pid}
fi

exit 0
