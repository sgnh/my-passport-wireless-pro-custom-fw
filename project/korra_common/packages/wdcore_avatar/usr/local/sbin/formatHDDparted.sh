#!/bin/sh
hdd=`cat /tmp/HDDDevNode`

#################################################
#
#	initial
#
#################################################

if [ $# != 1 ] && [ $# != 2 ]; then
	usage
	exit 1
fi

if [ "$1" != "exfat" ] && [ "$1" != "ntfs" ]; then
	usage
	exit 1
fi

if [ $# == 2 ] && [ "$2" != "llf" ]; then
	usage
	exit 1
fi

FS=$1
LLF=false
if [ $# == 2 ]; then
	LLF=false
fi
#############################################
#
#	function
#
#############################################

format(){
	/usr/local/sbin/stopFUSE.sh
#	umount /media/SDcard
	HDD=${hdd:5:7}
	size=`cat /sys/block/$HDD/size`
	wipefs -ap $hdd;
	if [ $size -gt 3984588800 ]; then #big then 2T
		(echo mktable gpt;echo mkpart NTFS 0% 200M;echo set 1 boot on;echo name 1 \"EFI System Partition\";echo mkpart primary NTFS 200M 100%;echo print;echo quit) | parted $hdd

	else
		parted $hdd mktable msdos -s
		parted $hdd mkpart primary NTFS 0% 100% -s
	fi
#	parted $hdd mkpart primary NTFS 0% 100% -s
	echo 0 > /proc/scsi/pmxrtpm
	sleep 3
	echo "add" > /sys/block/sda/uevent
	echo "add" > /sys/block/sda/sda1/uevent
	sleep 5
	case $FS in
		"exfat")
			#echo "y
			#
			#"|mkexfat ${hdd}1 -v:"My Passport";
			if [ $size -gt 3984588800 ]; then
				mkfs.fat -n EFI -F 32 ${hdd}1
				mkexfatfs -n "My Passport" ${hdd}2
			else
				mkexfatfs -n "My Passport" ${hdd}1
			fi
			;;
		"ntfs")
			#echo "y
			#
			#"|mkntfs ${hdd}1 -v:"My Passport";
			if [ $size -gt 3984588800 ]; then
				mkfs.fat -n EFI -F 32 ${hdd}1
				mkntfs ${hdd}2 -v:"My Passport" -f --nodiscard;
			else
				mkntfs ${hdd}1 -v:"My Passport" -f --nodiscard;
			fi
			;;
	esac
	sleep 3;
}

lower_level_format(){
	dataVolumeDevice=`cat /tmp/HDDDevNode`
	blockSize=104857600
	totalBlocks=`df -B ${blockSize} ${dataVolumeDevice} | grep ${dataVolumeDevice} | awk '{print $2}'`
	#echo $totalBlocks
	onePercentBlocks=`expr ${totalBlocks} / 100`

	blockCount=0
	percentCount=0
	percent=1
	while [ ${blockCount} -lt ${totalBlocks} ]
	do
	#	echo blockCount : ${blockCount}  "."  totalBlocks : ${totalBlocks}
		dd bs=${blockSize} seek=${blockCount} count=1 if=/dev/zero of=`cat /tmp/HDDDevNode` 2> /dev/null
	#	sleep 1
	#	echo percentCount : ${percentCount} "." onePercentBlocks : ${onePercentBlocks}	
		if [ "${percentCount}" -gt "${onePercentBlocks}" ]; then
			percentCount=0
			percent=`expr $percent + 1`
			echo "inprogress $percent" > /tmp/wipe-status
		fi
		blockCount=`expr $blockCount + 1`
		percentCount=`expr $percentCount + 1`
	done
	sync

}

usage(){
	echo "$0 exfat|ntfs [llf]"
}

#############################################
#
#	main
#
#############################################

if [ -f /usr/local/sbin/killService.sh ]; then
	/usr/local/sbin/killService.sh hdd
	sleep 10
	[ "$LLF" == "true" ] && lower_level_format
    echo "inprogress 20" > /tmp/wipe-status
	format
	sleep 5
	echo "inprogress 100" > /tmp/wipe-status
    sleep 5
    echo "complete" > /tmp/wipe-status
    sleep 3
fi
exit 0	
