#!/bin/sh
#!/bin/sh
#
# © 2010 Western Digital Technologies, Inc. All rights reserved.
#
# resetButtonAction.sh 
#
# This is called by resetbtnd whenever the reset button has met the criteria for a reset.  This script implements the actions for the reset button.
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

logger "reset button pressed, invoking reset actions"

# remove owner password
owner=`getOwner.sh`
modUserPassword.sh ${owner}

# set root password back to default
echo "root:welc0me" | chpasswd 

# set network to dhcp
setNetworkDhcp.sh

reboot
