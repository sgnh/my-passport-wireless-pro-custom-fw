#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getShareSize.sh <sharename>
#
#  - returns share size given <sharename>
#  -return format (in du format):
#     <share size in bytes> <share name>
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

share=$1
if [ -L $share ]; then
    volume=`readlink $share`
    df -B 1 | grep $volume | awk '{printf("%i",$3)}'
    echo -e "\t $share"
else
    du -sb $1
fi

