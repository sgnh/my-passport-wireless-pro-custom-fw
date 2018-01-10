#!/bin/bash

smartTestStatus()
{
    smartctl -d sat -c "${1}" | grep "Self-test execution status" | awk '
BEGIN {
        FS="(";
}
{
        code=int(substr($2, 2, 3));
        if (code == 0) {
                system("touch /tmp/SMARTDone");
                system("touch /tmp/SMARTGood");
        }
        else if (code >= 240 && code < 250) {
                percent = (10-(code - 240)) * 5;
        }
        else if (code >= 16 && code < 27) {
                system(touch /tmp/SMARTDone);
        }
        else {
                system("touch /tmp/SMARTDone");
        }
}
'
}

while [ ! -f /tmp/SMARTDone ]
do
    smartTestStatus /dev/sda 
    sleep 10
done
if [ -f /tmp/SMARTDone ] && [ -f /tmp/SMARTGood ]; then
    touch /tmp/ScandiskSetup
    rm -f /tmp/StartSMART
    MountDevNode=`cat /tmp/MountedDevNode`
    fstype=`blkid ${MountDevNode} | sed -n 's/.* TYPE="\([^"]*\)".*/\1/p'`
    /usr/local/sbin/killService.sh hdd
    umount -l ${MountDevNode}
    touch /tmp/StartScandisk
    rm -f /tmp/ScandiskSetup
    /usr/local/sbin/stopFUSE.sh
    touch /tmp/ScandiskProcessing
    rm -f /tmp/StartScandisk
    if [ "$fstype" == "exfat" ] || [ "$fstype" == "ntfs" ] || [ "$fstype" == "hfsplus" ]; then
        chkufsd -f ${MountDevNode} > /tmp/chkdisk.log
    fi
    if [ "$fstype" == "vfat" ]; then
        fsck.fat -aw ${MountDevNode} > /tmp/chkdisk.log
    fi
    touch /tmp/ScandiskProcessingDone
    rm -f /tmp/ScandiskProcessing
    /usr/local/sbin/killService.sh hddup
    if [ ! -f /tmp/ScandiskAborted ]; then 
        touch /tmp/ScandiskDone
    fi
    rm -f /tmp/ScandiskProcessingDone
fi

