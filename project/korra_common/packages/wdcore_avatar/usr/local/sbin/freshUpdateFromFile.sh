#!/bin/bash
#
# � 2013 Western Digital Technologies, Inc. All rights reserved.
#
# freshUpdateFromFile.sh <filename>"
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
touch /tmp/fresh_update
updateFirmwareFromFile.sh $@
