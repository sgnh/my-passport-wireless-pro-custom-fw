#!/bin/bash
#
# � 2010, 2012 Western Digital Technologies, Inc. All rights reserved.
#
# cmdMediaServer.sh <rebuild/reset_defaults/rescan>
#    added <start/stop/status> to operate init.d scripts
#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf

[ -x /usr/local/sbin/cmdDlnaServer.sh ] && \
    /usr/local/sbin/cmdDlnaServer.sh "$@"
RC=$?

exit $RC
