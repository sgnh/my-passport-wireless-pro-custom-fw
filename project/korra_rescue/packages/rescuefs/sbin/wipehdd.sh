#!/bin/sh
if [ "$1" != "" ]; then
    dd if=/dev/zero of=$1 bs=1M
else
    echo "Usage: wipehdd.sh /dev/sdb"
fi

