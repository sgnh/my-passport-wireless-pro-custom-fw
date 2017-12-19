#!/bin/sh
#
# � 2011 Western Digital Technologies, Inc. All rights reserved.
#
# checkSshLogin.sh
#
# Called whenever user logs in through SSH.  
#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/system.conf
. /etc/nas/config/wd-nas.conf 2>/dev/null

log_msg=${1}

# someone has logged into SSH, set "SSH_LOGIN_STATE"
[ -f ${SSH_LOGIN_TRIGGER} ] && exit 0

[[ "${log_msg}" =~ "Accepted password" ]] && touch ${SSH_LOGIN_TRIGGER}

