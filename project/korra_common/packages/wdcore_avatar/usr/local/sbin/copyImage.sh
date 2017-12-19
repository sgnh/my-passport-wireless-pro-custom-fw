#!/bin/sh
#
# (c)  2011 Western Digital Technologies, Inc. All rights reserved.
#
#  copyImage.sh - copy image to partition
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

echo "Running script: $0 ${@}"

if [ "$#" != 5 ]; then
	echo "Usage: copyImage.sh <path_to_image_file> <path_to_destination_partition> <blocksize> <blockcount> <path_to_md5file>"
	exit 1
fi

image_file=$1
dest_part=$2
blocksize=$3
blockcount=$4
md5file=$5

dd if=${image_file} of=${dest_part} 
# > /dev/null 2> /dev/null
echo "Compare checksum"
dd if=${dest_part} bs=${blocksize} count=${blockcount} 2> /dev/null | md5sum -c ${md5file}
checksumOk=$?
echo "ok ${checksumOk}"
 
exit $checksumOk

