#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# queueReboot.sh
#
# script to allow infrastructure code to force a reboot after some amount of time.  This will allow the UI time command a reboot if it needs to provide status information.
#
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

# queue a reboot in 30 seconds.  This will ensure device successfully reboots, incase user closed web browser
( sleep 30; reboot ) &
