#!/bin/sh
# Create Swapfile
#

HDDSpace=`df | grep "/dev/root" | awk '{print $4}'`

if [ ! -f /swapfile ] && [ $HDDSpace -gt 384000 ]; then
    dd if=/dev/zero of=/swapfile bs=1M count=128
    /sbin/mkswap /swapfile
    /sbin/swapon /swapfile
fi

