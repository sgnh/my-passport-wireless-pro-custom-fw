#!/bin/bash

#---------------------


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#logger -s -t "$(basename $0)" "begin script: $@"
#. /etc/nas/config/wd-nas.conf 2>/dev/null
#. /etc/nas/config/share-param.conf
. /etc/system.conf

# accept parameter for skipping reformat (noreformat)

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------
#CMD=${1:-"ext4"}

##########################################
# ï¿?2010 Western Digital Technologies, Inc. All rights reserved.
#
# factoryRestore.sh - This script kicks off the factory restore process
##########################################
#echo "$CMD" > ${reformatDataVolume}

#/usr/bin/touch ${RESTORE_SETTINGS_FROM_DIR_TRIGGER}

configFile="/etc/default/factory.conf"


AC_check_50_percent()
{
    echo "12;0;" > /tmp/MCU_Cmd
    AC=`cat /tmp/battery  | awk '{print $1}'`
    BatLevel=`cat /tmp/battery  | awk '{print $2}'`
    if [ ${BatLevel} -lt 25 ]; then # && [ ${AC} == "discharging" ]; then
        echo  "insufficient_power"> /tmp/wipe-status
        exit 11
    fi
}

AC_check()
{
    echo "12;0;" > /tmp/MCU_Cmd
    AC=`cat /tmp/battery  | awk '{print $1}'`
    BatLevel=`cat /tmp/battery  | awk '{print $2}'`
    
    if [ ${AC} == "discharging" ]; then
    	echo  "insufficient_power"> /tmp/wipe-status
    	exit 10
    fi
    if [ ${BatLevel} -lt 25 ]; then
    	echo  "insufficient_power"> /tmp/wipe-status
    	exit 11
    fi
}

if [ $# -eq 0 ]; then
	AC_check
	/usr/local/sbin/wipeFactoryRestore.sh nocheckpower &
	if [ $? -eq 0 ]; then
		exit 0
	else
		exit 1
	fi
fi

if [ "$1" != "noreformat" ]; then
	exit 1
fi

AC_check_50_percent
if [ -f $configFile ] && [ ! -f /tmp/reset_done ]; then
   
    [ -f /etc/nas/config/wifinetwork-param.conf ] && rm -f /etc/nas/config/wifinetwork-param.conf
    tar -xvf $configFile -C / >/dev/null 2>&1
    [ $? == "0" ] && echo "compeleted" > /etc/FacRestore
    
    cp -a /etc/nas/config/wifinetwork-param.conf.korra /etc/nas/config/wifinetwork-param.conf
    #ln -s /etc/nas/config/wifinetwork-param.default.conf.korra /etc/nas/config/wifinetwork-param.default.conf
    source /etc/nas/config/wifinetwork-param.conf
    SN=`/usr/local/sbin/getSerialNumber.sh | cut -c 5-12`
    if [ "${SN}" != "" ] && [ `expr $(echo "$SN" | wc -m) - 1` -ge 8 ]; then
    	SSID2G4="${AP_SSID_NAME} - `iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:] | awk -F: '{print $4$5$6}'`"
		SSID25G="${AP5G_SSID_NAME} - `iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:] | awk -F: '{print $4$5$6}'`"
    
    	sed -i 's/AP_SSID_NAME=.*/AP_SSID_NAME='\""${SSID2G4}"\"'/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP5G_SSID_NAME=.*/AP5G_SSID_NAME='\""${SSID25G}"\"'/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP5G_ENCRYPTION_KEY=.*/AP5G_ENCRYPTION_KEY='\""${SN}"\"'/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP_ENCRYPTION_KEY=.*/AP_ENCRYPTION_KEY='\""${SN}"\"'/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP5G_ENCRYPTION_TYPE=.*/AP5G_ENCRYPTION_TYPE=WPA2PSK/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP5G_CIPHER_TYPE=.*/AP5G_CIPHER_TYPE=TKIPAES/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP_ENCRYPTION_TYPE=.*/AP_ENCRYPTION_TYPE=WPA2PSK/' /etc/nas/config/wifinetwork-param.conf
    	sed -i 's/AP_CIPHER_TYPE=.*/AP_CIPHER_TYPE=TKIPAES/' /etc/nas/config/wifinetwork-param.conf
   	fi
   	sed -i 's/AP_AVAILABLE_CHANNEL=.*/AP_AVAILABLE_CHANNEL=/' /etc/nas/config/wifinetwork-param.conf
    sed -i 's/AP5G_AVAILABLE_CHANNEL=.*/AP5G_AVAILABLE_CHANNEL=/' /etc/nas/config/wifinetwork-param.conf
   
    #-----------------------------------
    plan_2g=`rtwpriv $AP_IFACE efuse_get rmap,b8,1 | awk -F'efuse_get:' '{print $2}' | cut -c 3-4`
    plan_5g=`rtwpriv $AP5G_IFACE efuse_get rmap,b8,1 | awk -F'efuse_get:' '{print $2}' | cut -c 3-4`
					
    #echo "plan_2g $plan_2g" > /tmp/wifi_adaptivity.log
    #echo "plan_5g $plan_5g" >> /tmp/wifi_adaptivity.log
							
    if [ "$plan_2g" == "21" ]; then
        echo "plan_2g adaptivity 1" >> /tmp/wifi_adaptivity.log
		sed -i 's/AP_ADAPTIVITY=.*/AP_ADAPTIVITY=1/' /etc/nas/config/wifinetwork-param.conf
	fi
												
	if [ "$plan_5g" == "42" ] || [ "$plan_5g" == "26" ]; then
		echo "plan_5g adaptivity 1" >> /tmp/wifi_adaptivity.log
		sed -i 's/AP5G_ADAPTIVITY=.*/AP5G_ADAPTIVITY=1/' /etc/nas/config/wifinetwork-param.conf
	fi
	if [ "$plan_5g" == "54" ]; then
		sed -i 's/AP5G_CHANL_WIDTH=.*/AP5G_CHANL_WIDTH=20/' /etc/nas/config/wifinetwork-param.conf
	fi 
	#-----------------------------------

    /usr/local/sbin/killService.sh network >/dev/null 2>&1
    sleep 1

    [ -f "/etc/language.conf" ] && rm -f /etc/language.conf

    if [ -f /etc/.eula_accepted ]; then
        rm /etc/.eula_accepted
    fi
    if [ -f "/etc/nas/hybrid_list" ]; then
        rm /etc/nas/hybrid_list
        touch /etc/nas/hybrid_list
    fi
    rm -Rf /etc/updateCounts
    if [ -f /usr/local/nas/orion/orion.db ]; then
        rm -f /usr/local/nas/orion/orion.db
    fi
    if [ -f /usr/local/nas/orion/jobs.db ]; then
        rm -f /usr/local/nas/orion/jobs.db
    fi
    if [ -f /CacheVolume/.twonkymedia/twonkyserver.ini ]; then
        rm -f /CacheVolume/.twonkymedia/twonkyserver.ini
        rm -f /CacheVolume/.twonkymedia/twonky.dat
        rm -f /CacheVolume/.twonkymedia/twonky.roles
        rm -f /CacheVolume/.twonkymedia/twonky.users
        rm -f /CacheVolume/.twonkymedia/twonky-locations-70.db
    fi
    if [ -f /etc/installed_packages/plexmediaserver ]; then
        /usr/local/sbin/packages/plexmediaserver-uninstall.sh
        sed -i 's/installed/downloaded/g' /etc/installed_packages/plexmediaserver
    fi
    if [ ! -f "/etc/.device_Unconfigured" ]; then
    	touch /etc/.device_Unconfigured
    fi
    /usr/local/sbin/device_security_set_config.sh false &
    if [ -f "/etc/nas/.product_improvement_opt_in" ]; then
        rm -f /etc/nas/.product_improvement_opt_in
    fi
    echo "0" > /tmp/reset_done
else
    exit 1
fi
rm -f /etc/wd-alert/*
modAutoFirmwareUpdateConfig.sh disable 0 3
/usr/local/sbin/middleware_startup.sh
sqlite3 /CacheVolume/.wd-alert/wd-alert.db "DELETE FROM AlertHistory where 1"
modAutoFirmwareUpdateConfig.sh disable 0 3
exit 0

#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}

