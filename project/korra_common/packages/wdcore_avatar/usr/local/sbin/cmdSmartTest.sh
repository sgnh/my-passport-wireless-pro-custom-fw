#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# cmdSmartTest.sh <short/long/abort>
#
#
#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
#source /usr/local/sbin/data-volume-config_helper.sh
source /etc/system.conf
source /etc/standby.conf

cmd=$1

#Get list of drives
#numMissingDrives=(`missingDrivesExpectedPartitions md0 missing`)
#driveList=(`internalDrives`)
#if [ $numMissingDrives  -ne 0 ]; then
#    echo "$0: Missing drives=${numMissingDrives}"
    #If no drives, exit with error
#    if [ "${#driveList[@]}" -eq 0 ]; then
#    	exit 1
#    fi
#fi

doSmartCtlTest ()
{
    # Stop ext4 lazy-init if currently active on DataVolume
    mount | grep -q $dataVolumeDevice
    mount_status=$?
    if [ $mount_status -eq 0 ] && [ ! -z "$dataVolumeLazyInitMountOpt" ]; then
        logger -s "disable lazy init"
        mount -o remount,noinit_itable $dataVolumeDevice
    fi
    # test each drive in driveList    
    #for drive in "${driveList[@]}"
    #do
    #    smartctl -t ${cmd} ${drive} > /dev/null
    #done
    smartctl -d sat -t ${cmd} ${dataVolumeDevice} > /dev/null    
    
    
    # Resume lazy inits on DataVolume
    if [ $mount_status -eq 0 ] && [ ! -z "$dataVolumeLazyInitMountOpt" ]; then
        mount -o remount,$dataVolumeLazyInitMountOpt $dataVolumeDevice
    fi
}

case ${cmd} in
    short)
        doSmartCtlTest
        rm -f /tmp/SMARTDone /tmp/SMARTGood /tmp/ScandiskSetup /tmp/ScandiskSetup /tmp/StartScandisk /tmp/ScandiskProcessing /tmp/ScandiskProcessingDone /tmp/ScandiskDone /tmp/ScandiskAborted
        touch /tmp/StartSMART
        echo "39;0" > /tmp/MCU_Cmd &
        exit 0
        ;;
    long)
        doSmartCtlTest
        rm -f /tmp/SMARTDone /tmp/SMARTGood /tmp/ScandiskSetup /tmp/ScandiskSetup /tmp/StartScandisk /tmp/ScandiskProcessing /tmp/ScandiskProcessingDone /tmp/ScandiskDone /tmp/ScandiskAborted
        touch /tmp/StartSMART
        echo "39;0" > /tmp/MCU_Cmd &
        exit 0
        ;;
    abort)
        #for drive in "${driveList[@]}"
        #do
    	#    smartctl -X ${drive} > /dev/null
        #done
        if [ -f /tmp/StartSMART ]; then
            smartctl -d sat -X ${dataVolumeDevice} > /dev/null
            killall monitorchkdisk.sh
            rm -f /tmp/StartSMART
        fi
        if [ -f /tmp/StartScandisk ] || [ -f /tmp/ScandiskSetup ] || [ -f /tmp/ScandiskProcessing ] || [ -f /tmp/ScandiskProcessingDone ]; then
            rm -f /tmp/ScandiskSetup
            rm -f /tmp/StartScandisk
            rm -f /tmp/ScandiskProcessing
            rm -f /tmp/ScandiskProcessingDone
            rm -f /tmp/ScandiskDone
            touch /tmp/ScandiskAborted
        fi
        exit 0
    	;;
    *)
    	echo "usage: cmdSmartTest.sh <short/long/abort>"
    	exit 1
esac
