#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
. /usr/local/sbin/data-volume-config_helper.sh

# MyBookLiveDuo:/usr/local/sbin# hdparm -i /dev/sda

# /dev/sda:

#  Model=WDC WD30EZRX-00MMMB0                    , FwRev=80.00A80, SerialNo=     WD-WCAWZ0672422
#  Config={ HardSect NotMFM HdSw>15uSec SpinMotCtl Fixed DTR>5Mbs FmtGapReq }
#  RawCHS=16383/16/63, TrkSize=0, SectSize=0, ECCbytes=50
#  BuffType=unknown, BuffSize=0kB, MaxMultSect=16, MultSect=?0?
#  CurCHS=16383/16/63, CurSects=16514064, LBA=yes, LBAsects=5860533168
#  IORDY=on/off, tPIO={min:120,w/IORDY:120}, tDMA={min:120,rec:120}
#  PIO modes:  pio0 pio3 pio4 
#  DMA modes:  mdma0 mdma1 mdma2 
#  UDMA modes: udma0 udma1 udma2 udma3 udma4 udma5 *udma6 
#  AdvancedPM=no WriteCache=enabled
#  Drive conforms to: Unspecified:  ATA/ATAPI-1,2,3,4,5,6,7

#  * signifies the current active mode

# MyBookLiveDuo:/usr/local/sbin# 


#For as many internal drives as there are present
driveList=( `internalDrives` )
for drive in "${driveList[@]}"
do
    model=
    serialNumber=
    driveSize=
    smart=

    cmd="hdparm -i $drive"
    stdOut=`$cmd`
    result=$?

    if [ $result -ne 0 ]; then
        logger  -p local2.notice "$0: $cmd returned $result"
    fi

    loc=`SATALocation $drive`
    cabinetLoc=`cabinetLabel $loc`

    model=`cat /sys/block/"${drive##*/}"/device/model`
    serialNumber=`echo "$stdOut" | sed -n -e '/^[ \t]*Model/s/.*SerialNo=[ \t]*\([^ /t]*\).*/\1/p'`
    driveSize=`cat /sys/block/"${drive##*/}"/size`

    #Convert to MB
    driveSize=`expr $driveSize \* 512`
    driveSize=`expr $driveSize \/ 1000000`
    
    smartctl -d ata -H $drive | grep -q PASSED
    if [ $? -eq 0 ]; then
        smart=PASS
    else
        smart=FAIL
    fi

    #Output record
    echo "$cabinetLoc:$model:$serialNumber:$driveSize:$smart"
done

exit 0
