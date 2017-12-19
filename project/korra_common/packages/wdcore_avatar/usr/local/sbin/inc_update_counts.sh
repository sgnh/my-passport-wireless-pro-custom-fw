#!/bin/bash

if [ -f /var/lock/updateCounts ] ; then
    exec 200>/var/lock/updateCounts
    flock -x 200
    countName=$1
    counterVal=`cat /tmp/updateCounts/$countName`
    counterVal=`expr $counterVal + 1` 
    echo "$counterVal" > /tmp/updateCounts/$countName
    flock -u 200
else
    echo "Unable to aquire lock to the file in location /var/lock/updateCounts"
fi

