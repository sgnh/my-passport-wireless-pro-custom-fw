#!/bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#

###########################################
# share setup files
###########################################
trustees=/etc/trustees.conf
sambaOverallShare=/etc/samba/overall_share
hostsConfig=/etc/hosts
networkConfig=/etc/network/interfaces
dnsConfig=/etc/resolv.conf
dhclientConfig=/etc/dhcp/dhclient.conf
ntpConfig=/etc/default/ntpdate
smbConfig=/etc/samba/smb.conf
remoteAccessConfig=/etc/remote_access.conf
itunesConfig=/etc/forked-daapd.conf
upgrade_link=/tmp/fw_upgrade_link
nssConfig=/etc/nsswitch.conf

userConfig=/etc/passwd
passwdConfig=/etc/shadow
smbpasswdConfig=/etc/samba/smbpasswd

ownerUid=999
adminDefaultAlias="admin-dfalias-wd"

# 3G required for F/W update
fwUpdateSpace="3000000"

fileTally=/var/local/nas_file_tally
twonky_dir=/usr/local/twonkymedia-7

# bash scripts logging for debugging use.. currently not all scripts are instrumented.
# SYSTEM_SCRIPTS_LOG="/var/log/wdscripts.log"
