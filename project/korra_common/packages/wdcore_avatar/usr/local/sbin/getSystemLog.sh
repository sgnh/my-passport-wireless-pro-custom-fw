#!/bin/bash
#
# � 2014 Western Digital Technologies, Inc. All rights reserved.
#
# getSystemLog.sh  <option>
#
#  option - "dlna" : add dlna db to log
#
# returns: 
#   Path to  system log file.
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#. /usr/local/sbin/data-volume-config_helper.sh 2>/dev/null
. /etc/system.conf

{

option=disk
date_stamp=`date +%d%H%M%s`
serial_num=`getSerialNumber.sh`
logname="systemLog_${serial_num}_${date_stamp}"
logfiledir=/CacheVolume

logfile=${logfiledir}/${logname}.zip

# collect log information
mkdir -p /CacheVolume/${logname}/current_config/etc
mkdir -p /CacheVolume/${logname}/current_config/etc/nas/config
mkdir -p /CacheVolume/${logname}/current_config/CacheVolume
mkdir -p /CacheVolume/${logname}/current_config/shares
mkdir -p /CacheVolume/${logname}/current_status

cp -a /var/log/*.log /CacheVolume/${logname}
cp -a /var/log/scan* /CacheVolume/${logname}
cp -a /var/log/ready /CacheVolume/${logname}
cp -a /var/log/cronlog /CacheVolume/${logname}
cp -a /var/log/maillog /CacheVolume/${logname}
cp -a /var/log/messages /CacheVolume/${logname}
cp -a /var/log/messages.0 /CacheVolume/${logname}
cp -a /var/log/rsysmessages /CacheVolume/${logname}
cp -a /CacheVolume/.twonkymedia/*.txt /CacheVolume/${logname}
cp -a /CacheVolume/.wd-alert/wd-alert.db /CacheVolume/${logname}
cp -Ra "/CacheVolume/.plexmediaserver/Application Support/Plex Media Server/Logs" /CacheVolume/${logname}/
cp -Ra "/CacheVolume/.plexmediaserver/Application Support/Plex Media Server/Crash Reports" /CacheVolume/${logname}/

# collect current status
cp -a /tmp/ApCliRetry /CacheVolume/${logname}/current_status
cp -a /tmp/ConnectionMode /CacheVolume/${logname}/current_status
cp -a /tmp/CurrentChannel /CacheVolume/${logname}/current_status
cp -a /tmp/HDDDevNode /CacheVolume/${logname}/current_status
cp -a /tmp/HDSerial /CacheVolume/${logname}/current_status
cp -a /tmp/HddPercent /CacheVolume/${logname}/current_status
cp -a /tmp/MountedDevNode /CacheVolume/${logname}/current_status
cp -a /tmp/SDDevNode /CacheVolume/${logname}/current_status
cp -a /tmp/TmpfsPercent /CacheVolume/${logname}/current_status
cp -a /tmp/Volumes.xml /CacheVolume/${logname}/current_status
cp -a /tmp/WPS_APstatus /CacheVolume/${logname}/current_status
cp -a /tmp/apclientnum /CacheVolume/${logname}/current_status
cp -a /tmp/battery /CacheVolume/${logname}/current_status
cp -a /tmp/batterymV /CacheVolume/${logname}/current_status
cp -a /tmp/mcuTemperature /CacheVolume/${logname}/current_status
cp -a /tmp/transfer_size /CacheVolume/${logname}/current_status
cp -a /tmp/transfer_size_total /CacheVolume/${logname}/current_status
cp -a /tmp/transfer_state /CacheVolume/${logname}/current_status
cp -a /tmp/debugmtpdev /CacheVolume/${logname}/current_status
cp -a /tmp/apache_* /CacheVolume/${logname}/current_status
cp -a /tmp/dhcpd.leases /CacheVolume/${logname}/current_status
cp -a /tmp/hybrid_list /CacheVolume/${logname}/current_status
cp -a /etc/nas/hybrid_list /CacheVolume/${logname}/current_status
cp -a /tmp/remodeIP_mac_debugger.log /CacheVolume/${logname}/current_status
cp -a /tmp/getDrives /CacheVolume/${logname}/current_status

getCurrentFirmwareDesc.sh > /CacheVolume/${logname}/version_info
cp -a /etc/version.packages /CacheVolume/${logname}/version_package_info
if [ -f /CacheVolume/update.log ]; then
	cp /CacheVolume/update.log /CacheVolume/${logname}
fi

drive=`cat /tmp/HDDDevNode`
smartctl -d sat -a ${drive} >> /CacheVolume/${logname}/smart_info
hdparm -I ${drive} >> /CacheVolume/${logname}/hdparm_info

# get current  configuration
copySaveSettingsToDir.sh /CacheVolume/${logname}/current_config
cat /etc/saveconfigfiles.txt | xargs tar cvf /CacheVolume/${logname}/current_config/saveconfigfiles.tar
#cp -a /CacheVolume/.orion /CacheVolume/${logname}/current_config/CacheVolume/
#cp -a /CacheVolume/WDPROT /CacheVolume/${logname}/current_config/CacheVolume/
#cp -a /CacheVolume/.mediacrawler /CacheVolume/${logname}/current_config/CacheVolume/
#cp -a /shares/.mediacrawler /CacheVolume/${logname}/current_config/shares

# save Access DLNA information
if [ ${option} == "dlna" ]; then
    if [ -f /etc/init.d/access ]; then
	access_dir="/CacheVolume/${logname}/access-dlna"
	mkdir -p ${access_dir}
	find /shares -type d -name .nflc_data -print | xargs -I {} find {} -maxdepth 1 -type f -print | tar cf ${access_dir}/access.tar --files-from=- 2>/dev/null
	cp /usr/local/dlna-access/xml/pg_device_list.xml ${access_dir}
    fi
    if [ -f /etc/init.d/twonky ]; then
	mkdir -p /CacheVolume/${logname}/twonky-dlna
	cp -a /CacheVolume/.twonkymedia/twonkymedia-log.txt /CacheVolume/${logname}/twonky-dlna
    fi
fi


#config_file=`saveConfigFile.sh`
#mv $config_file /CacheVolume/${logname}/current_status
ps aux > /CacheVolume/${logname}/current_status/process_list
free > /CacheVolume/${logname}/current_status/free_output
df -h > /CacheVolume/${logname}/current_status/df_output
df -hi > /CacheVolume/${logname}/current_status/df_hi_output
mount > /CacheVolume/${logname}/current_status/mount_output
ifconfig > /CacheVolume/${logname}/current_status/ifconfig_output
iwconfig > /CacheVolume/${logname}/current_status/iwconfig_output
blkid > /CacheVolume/${logname}/current_status/blkid_output
/usr/local/sbin/get_wifi_ap_clients.sh > /CacheVolume/${logname}/current_status/connected_clients
#tracert www.wdc.com > /CacheVolume/${logname}/current_status/traceroute-wdc.com.txt
#tracert www.wd2go.com > /CacheVolume/${logname}/current_status/traceroute-wd2go.com.txt

cp /root/.bash_history /CacheVolume/${logname}/bash_history
cp /home/root/.ash_history /CacheVolume/${logname}/ash_history

#####################Configuration############################
#cp /etc/nas/config/*.conf /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/wifinetworkinfo /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/networking-general.conf /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/sdcard-param.conf /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/sdcard-transfer-status.conf /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/usb-transfer-status.conf /CacheVolume/${logname}/current_config/etc/nas/config
cp /etc/nas/config/wd-nas.conf /CacheVolume/${logname}/current_config/etc/nas/config
cat /etc/nas/config/wifinetwork-remembered.conf | awk 'BEGIN {FS="security_key="} {print $1}' > /CacheVolume/${logname}/current_config/etc/nas/config/wifinetwork-remembered.conf
cat /etc/nas/config/wifinetwork-param.conf | sed '49d' | sed '28d' | sed '9d' > /CacheVolume/${logname}/current_config/etc/nas/config/wifinetwork-param.conf

#cp /usr/local/nas/orion/*.db /CacheVolume/${logname}/current_status
#cp /var/www/rest-api/config/dynamicconfig.ini /CacheVolume/${logname}/current_status
cp -Ra /proc/net/rtl8* /CacheVolume/${logname}/current_status/
#cp /etc/*.conf /CacheVolume/${logname}/current_config/etc
cp -Ra $(ls /etc/*.conf | grep -v 'wpa') /CacheVolume/${logname}/current_config/etc
cat /etc/wpa_supplicant.conf | grep -v "psk" | grep -v "wep_key0" > /CacheVolume/${logname}/current_config/etc/wpa_supplicant.conf
cat /etc/wpa2G4_supplicant.conf | grep -v "psk" | grep -v "wep_key0" > /CacheVolume/${logname}/current_config/etc/wpa2G4_supplicant.conf
/bin/journalctl > /CacheVolume/${logname}/system-journalctl.log
#find / -mount -type f -newer /etc/version -print > /CacheVolume/${logname}/changed_file_list_since_update 
#cp /etc/cs_case_number /CacheVolume/${logname}/

cd /CacheVolume; zip -l -r ${logfile} ${logname} > /dev/null 2> /dev/null
echo "zip"
if [ -e "/CacheVolume/${logname}" ]; then
    rm -rf "/CacheVolume/${logname}"
fi

# dump all stdout and stderr so that it does not interfere with the filepath echo below..
} > /dev/null 2> /dev/null

echo ${logfile}

