#!/bin/sh

HDDSpace=`df | grep /DataVolume | awk '{print $4}'`
checklink=`ls -l /CacheVolume | grep "/media/sdb1/.wdcache" | wc -l`

if [ "$HDDSpace" == "" ]; then
    exit 1
fi 

if [ "$checklink" == "0" ] && [ $HDDSpace -gt 1124000 ] ; then
    if [ ! -d "/media/sdb1/.wdcache" ]; then
        mkdir -p /media/sdb1/.wdcache
    fi
    mv /CacheVolume/* /media/sdb1/.wdcache/
    rm -Rf /CacheVolume
    ln -sf /media/sdb1/.wdcache /CacheVolume
fi
