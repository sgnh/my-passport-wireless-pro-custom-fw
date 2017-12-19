#!/bin/bash

ExternalDevices=`/usr/local/sbin/wdAutoMountAdm.pm getDrives | grep handle | sed -n -e 's/^.*handle=//p'`
NoExternalDevices=`/usr/local/sbin/wdAutoMountAdm.pm getDrives | grep handle | sed -n -e 's/^.*handle=//p'| wc -l`

if [ ${NoExternalDevices} == "0" ]; then
	exit 0
fi

for ExternalDevice in ${ExternalDevices} ; do
        /usr/local/sbin/wdAutoMountAdm.pm ejectDrive ${ExternalDevice}
        sleep 1
done

