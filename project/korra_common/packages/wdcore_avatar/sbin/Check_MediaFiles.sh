#!/bin/bash

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

total_files=`/usr/local/sbin/getMediaCrawlerStatus.sh  |grep -i -e "\"1\"" -e "\"2\"" -e "\"3\"" | cut -d " " -f 10 | sed -e 's/^"//'  -e 's/"$//' | awk '{ sum += $1 } END
 { print sum }'`

if [ "$total_files" == "" ]; then
    exit 1
fi
     
if [ "$total_files" -gt "500000" ]; then
    /usr/local/sbin/sendAlert.sh 2005
fi

exit 0
