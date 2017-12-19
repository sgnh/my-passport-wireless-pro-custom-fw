#!/bin/bash

#---------------------


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/wd-nas.conf 2>/dev/null
logger -s -t "$(basename $0)" "Rebooting Minimal System"

touch ${MINIMAL_TRIGGER}
reboot
