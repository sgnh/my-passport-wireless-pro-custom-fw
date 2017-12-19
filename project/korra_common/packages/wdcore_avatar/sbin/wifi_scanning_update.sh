#!/bin/bash
#
# 2014 Western Digital Technologies, Inc. All rights reserved.
#
# wifi_scanning_update.sh
#
#


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ -f "/tmp/WiFiClientApDebugModeEnabledLog" ]; then
	Debugmode=1
else
	Debugmode=0
fi

cmd1="$1"
#if [ "$STA_CLIENT" == "false" ] && [ "$cmd1" != "ACS" ]; then
#	exit 0
#fi
if [ "$cmd1" == "ACS" ]; then
	ap5g=`ls /proc/net/rtl8821au/ | grep wlan | head -1 | awk -F\/ '{print $1}'`
	sed -i 's/AP5G_IFACE=.*/AP5G_IFACE='$ap5g'/' /etc/nas/config/wifinetwork-param.conf
	sta5g=`ls /proc/net/rtl8821au/ | grep wlan | tail -1 | awk -F\/ '{print $1}'`
	sed -i 's/STA_IFACE=.*/STA_IFACE='$sta5g'/' /etc/nas/config/wifinetwork-param.conf
	
	ap2g4=`ls /proc/net/rtl8189es/ | grep wlan | head -1 | awk -F\/ '{print $1}'`
	sed -i 's/AP_IFACE=.*/AP_IFACE='$ap2g4'/' /etc/nas/config/wifinetwork-param.conf
	sta2g4=`ls /proc/net/rtl8189es/ | grep wlan | tail -1 | awk -F\/ '{print $1}'`	
	sed -i 's/STA2G4_IFACE=.*/STA2G4_IFACE='$sta2g4'/' /etc/nas/config/wifinetwork-param.conf
fi
source /etc/nas/config/wifinetwork-param.conf

#if [ "$cmd1" == "Delay" ]; then
#	sleep 3
#fi

if [ "$Debugmode" == "1" ]; then
	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	echo $timestamp ": wifi_scanning_update.sh" $@ >> /tmp/wificlientap.log
fi

wifi2g4=0
wifi5g=0

if [ -f "/tmp/wificlientinterfacebusy" ]; then
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_scanning_update.sh wificlientinterfacebusy exist!!" >> /tmp/wificlientap.log
	fi
	exit 0
    fwstate=`cat /proc/net/rtl8821au/wlan1/fwstate`
    if [ "${fwstate}" == "0x809" ] || [ "${fwstate}" == "0x808" ]; then
	    timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	    echo $timestamp ": wifi_scanning_update.sh busy status" $fwstate >> /tmp/wificlientap.log
	    exit 0
    else
    	processIW=`pidof iw`
		if [ "${processIW}" != "" ]; then
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_scanning_update.sh iw process" ${processIW} >> /tmp/wificlientap.log
			fi
    		kill -15 "${processIW}"
    		#sleep 10
    		exit 2
    	fi
    fi
	
	
	#processIW=`pidof iw`
	#if [ "${processIW}" != "" ]; then
	#	killall iw
	#	rm /tmp/wificlientinterfacebusy
	#	exit 1
	#fi
    #rm /tmp/wificlientinterfacebusy
    exit 1
else
	touch /tmp/wificlientinterfacebusy
fi


if [ -f "/tmp/scan24Gtmp" ]; then
    rm /tmp/scan24Gtmp
fi
if [ -f "/tmp/scan5Gtmp" ]; then
   	rm /tmp/scan5Gtmp
fi

if [ -f "/tmp/uplinkAP" ]; then
	rm /tmp/uplinkAP	
fi
#if [ -f "/tmp/scan_sort" ]; then
#   	rm /tmp/scan_sort
#fi
if [ -f "/tmp/uplinklist_new" ]; then
  	rm /tmp/uplinklist_new
fi

#if [ "$cmd1" == "ACS" ]; then
	#iwpriv wlan1 channel_plan set 0x59
#fi
if [ "$STA_CHANNEL_LITE" == "0" ]; then
	AP5G=`ifconfig | grep ^$STA_IFACE`
	if [ "$AP5G" == "" ]; then
		/sbin/ifconfig $STA_IFACE up > /dev/null 
	fi
	
	AP2G4=`ifconfig | grep ^$STA2G4_IFACE`
	if [ "$AP2G4" == "" ]; then
		/sbin/ifconfig $STA2G4_IFACE up > /dev/null 
	fi
	
	if [ "$cmd1" == "ACS" ]; then
		iwlist $STA_IFACE scan > /dev/null
		iwlist $STA2G4_IFACE scan > /dev/null
		#iw dev "${STA_IFACE}" scan > /dev/null
	else
		for ((index=1; index<4; index++ )); do
			iwlist "${STA_IFACE}" scan > /tmp/iwlist
			iwlist "${STA2G4_IFACE}" scan >> /tmp/iwlist
			#iw dev "${STA_IFACE}" scan > /tmp/iwscan
			NumSTA=`cat /tmp/iwlist | grep $STA_IFACE | wc -l`
			if [ "$NumSTA" != "0" ]; then
				break
			else
				if [ "$Debugmode" == "1" ]; then
					timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
					echo $timestamp ": wifi_scanning_update.sh scan busy!!" >> /tmp/wificlientap.log
				fi
			fi
		done
	fi	
		
elif [ "$STA_CHANNEL_LITE" == "2" ]; then
	AP2G4=`ifconfig | grep ^$STA2G4_IFACE`
	if [ "$AP2G4" == "" ]; then
		/sbin/ifconfig $STA2G4_IFACE up > /dev/null 
	fi
	
	if [ "$cmd1" == "ACS" ]; then
		iwlist $STA_IFACE scan > /dev/null
		#iw dev "${STA2G4_IFACE}" scan > /dev/null
	else
	for ((index=1; index<4; index++ )); do
		iwlist $STA2G4_IFACE scan > /tmp/iwlist
		#iw dev "${STA2G4_IFACE}" scan >  /tmp/iwscan
		NumSTA=`cat /tmp/iwlist | grep $STA2G4_IFACE | wc -l`
		if [ "$NumSTA" != "0" ]; then
			break
		else
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_scanning_update.sh scan busy!!" >> /tmp/wificlientap.log
			fi
		fi	
	done
	fi
elif [ "$STA_CHANNEL_LITE" == "5" ]; then
	AP5G=`ifconfig | grep ^$STA_IFACE`
	if [ "$AP5G" == "" ]; then
		/sbin/ifconfig $STA_IFACE up > /dev/null 
	fi
	if [ "$cmd1" == "ACS" ]; then
		iwlist $STA_IFACE scan > /dev/null
		#iw dev "${STA_IFACE}" scan > /dev/null
	else
	      for ((index=1; index<4; index++ )); do
		iwlist $STA_IFACE scan > /tmp/iwlist
		#iw dev "${STA_IFACE}" scan >  /tmp/iwscan
		NumSTA=`cat /tmp/iwlist | grep $STA_IFACE | wc -l`
		if [ "$NumSTA" != "0" ]; then
			break
		else
			if [ "$Debugmode" == "1" ]; then
				timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
				echo $timestamp ": wifi_scanning_update.sh scan busy!!" >> /tmp/wificlientap.log
			fi
		fi	
	        done
        fi
fi

if [ "$STA_CLIENT" == "false" ] && [ "$cmd1" == "ACS" ]; then
	#if [ "$cmd1" == "ACS" ]; then
		#iwpriv wlan1 channel_plan set 0x7F
		#cat /proc/net/rtl8821au/wlan1/best_channel
	#fi
	
	if [ "$STA_CLIENT" == "false" ]; then
		if [ "$STA_CHANNEL_LITE" == "0" ]; then
			/sbin/ifdown $STA_IFACE 
			/sbin/ifconfig $STA_IFACE down > /dev/null
			/sbin/ifdown $STA2G4_IFACE 
			/sbin/ifconfig $STA2G4_IFACE down > /dev/null
		elif [ "$STA_CHANNEL_LITE" == "2" ]; then
			/sbin/ifdown $STA2G4_IFACE
			/sbin/ifconfig $STA2G4_IFACE down > /dev/null 
		elif [ "$STA_CHANNEL_LITE" == "5" ]; then
			/sbin/ifdown $STA_IFACE 
			/sbin/ifconfig $STA_IFACE down > /dev/null
		fi
	fi
	rm /tmp/wificlientinterfacebusy
	exit 0
fi


if [ ! -f "/tmp/wifiprofileupdate" ]; then 
	touch /tmp/wifiprofileupdate

	#cat /tmp/iwscan | awk -f /usr/sbin/parse-iw.awk > /tmp/scan_temp
	cat /tmp/iwlist | awk -f /usr/sbin/parse-iwlist.awk > /tmp/scan_temp
	if [ -f "/tmp/scan_temp_1" ]; then
		rm /tmp/scan_temp_1
	fi

	NumSTA=`cat /tmp/scan_temp | wc -l`
	if [ "${NumSTA}" == "0" ]; then
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_scanning_update.sh scan no result!!" >> /tmp/wificlientap.log
		fi
		rm /tmp/wificlientinterfacebusy
		if [ -f "/tmp/scan_sort" ]; then
   			rm /tmp/scan_sort
		fi
		if [ "$Debugmode" == "1" ]; then
			timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
			echo $timestamp ": wifi_scanning_update.sh NO update profile" >> /tmp/wificlientap.log
		fi
		rm /tmp/wifiprofileupdate
		exit 1
	fi
	
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_scanning_update.sh start update profile" >> /tmp/wificlientap.log
	fi
	cp -a /tmp/scan_temp /tmp/scan_temp_1
	#ExcludeSSid=`grep -rsnw "\"${AP_SSID_NAME}(2.4GHz)\"" /tmp/scan_temp | head -1` #remove self 2.4G ssid	
	#ExcludeSSid=`grep -rsnw "\"${AP_SSID_NAME}\"" /tmp/scan_temp | head -1` #remove self 2.4G ssid	
	if [ "$AP_CHANNEL_LITE" == "0" ] || [ "$AP_CHANNEL_LITE" == "2" ]; then
		Macaddr=`iw dev "${AP_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`
	else
		Macaddr=`iw dev "${AP5G_IFACE}" info | grep "addr" | awk '{print $2}' | tr [:lower:] [:upper:]`
	fi

	cat /tmp/scan_temp_1 | grep -v "${Macaddr}" > /tmp/scan_temp

	ExcludeSSid=`cat /tmp/scan_temp | grep -rsni "${Macaddr}" ` #remove self 2.4G ssid	
	if [ "${ExcludeSSid}" != "" ]; then
		SelfssidNum=`echo "$ExcludeSSid" | cut -d ':' -f 1`
		#sed "${SelfssidNum}"d /tmp/scan_temp
		sed "${SelfssidNum}"d /tmp/scan_temp > /tmp/RemoveSelfSSID
		cat /tmp/RemoveSelfSSID > /tmp/scan_temp
		rm /tmp/RemoveSelfSSID					
	fi
	if [ -f "/tmp/connected" ]; then 
		cat /tmp/connected >> /tmp/scan_temp
	fi
	cp -a /etc/nas/config/wifinetwork-remembered.conf /tmp/uplinklist
	sed -i 's/connected="true"./connected="false" /' /tmp/uplinklist
	RememberNum=`cat /tmp/uplinklist | wc -l`
	#if [ "$Debugmode" == "1" ]; then
	#	timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
	#	profileleft=`cat /tmp/uplinklist`
	#	echo $timestamp ": wifi_client_ap_scan.sh uplinklist:" $RememberNum >> /tmp/wificlientap.log
	#	echo $timestamp ": wifi_client_ap_scan.sh" $profileleft >> /tmp/wificlientap.log
	#fi
	if [ "$RememberNum" != "0" ]; then
		cat /tmp/uplinklist | while read RemProfile
		do
			echo "${RemProfile}" > /tmp/uplinkAP
			rememberSsid=`echo "${RemProfile}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
			rememberMAC=`echo "${RemProfile}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
			rememberSignal=`echo "${RemProfile}" | awk 'BEGIN{FS="signal_strength=" } {print $NF}' | cut -d '"' -f 2`
			rememberbssid=`echo ${RemProfile} | awk 'BEGIN{FS="bssi\/dmap=" } {print $NF}' | cut -d ' ' -f 1`
			rememberband=`echo "${RemProfile}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
			#echo "rememberSsid" $rememberSsid
			#echo "rememberMAC" $rememberMAC
			#echo "rememberbssid" $rememberbssid
			if [ "${rememberbssid}" == "1" ]; then
				sed -i 's/signal_strength='\""$rememberSignal"\"'./signal_strength="0" /' /tmp/uplinkAP
				#echo "rememberSsid" $rememberSsid
				matchssid=`cat /tmp/scan_temp | grep -rsw "${rememberSsid}" | head -1`
				scanSsid=`echo "${matchssid}" | awk 'BEGIN{FS="ssid=" }{print $NF}' | cut -d '"' -f 2`
				scanMAC=`echo "${matchssid}" | awk 'BEGIN{FS="mac=" } {print $NF}' | cut -d '"' -f 2`
				#echo "matchssid" $matchssid
				#echo "scanSsid" $scanSsid
				#echo "scanMAC" $scanMAC
				#if [ "${rememberSsid}" == "${scanSsid}" ] && [ "${rememberMAC}" == "${scanMAC}" ]; then
				if [ "${rememberSsid}" == "${scanSsid}" ]; then
					lineNum=`cat /tmp/scan_temp | grep -rswn "${matchssid}" | cut -d ':' -f 1`
					#lineNum=`echo "$matchssid" | cut -d ':' -f 1`
					#echo "lineNum" $lineNum
					#cat /tmp/scan_temp | sed -n "$lineNum"p
					ApSignal=`echo "${matchssid}" | awk 'BEGIN{FS=" signal_strength=" }{print $2}' | cut -d '"' -f 2`
					Apband=`echo "${matchssid}" | awk 'BEGIN {FS="Frequency="} {print $NF}' | cut -d '"' -f 2`
					#echo "ApSignal" $ApSignal
					sed -i 's/signal_strength="0"./signal_strength='\""$ApSignal"\"' /' /tmp/uplinkAP
					sed -i 's/Frequency='\""$rememberband"\"'./Frequency='\""$Apband"\"' /' /tmp/uplinkAP
					if [ "${rememberMAC}" != "${scanMAC}" ]; then
						sed -i 's/mac='\""$rememberMAC"\"'./mac='\""$scanMAC"\"' /' /tmp/uplinkAP
					fi
					execmd="sed -i '"${lineNum}"d' /tmp/scan_temp"
					#echo "execmd" $execmd
					eval $execmd
					#sed -i '"${lineNum}"'d /tmp/scan_temp > /tmp/ScanFile
					#cp /tmp/ScanFile /tmp/scan_temp
					#cat /tmp/scan_temp | grep -v "${rememberSsid}" > /tmp/scan_temp_1
					#cp -a /tmp/scan_temp_1 /tmp/scan_temp
				fi
			else
				matchssid=`cat /tmp/iwlist | grep -rsi "${rememberMAC}" | head -1`
				if [ "${matchssid}" == "" ]; then
					sed -i 's/signal_strength='\""$rememberSignal"\"'./signal_strength="0" /' /tmp/uplinkAP
				else
					sed -i 's/signal_strength="0"./signal_strength="80" /' /tmp/uplinkAP
				fi
			fi
			cat /tmp/uplinkAP >> /tmp/uplinklist_new
			cat /tmp/uplinkAP >> /tmp/scan_temp
		done
	fi
	
	#if [ -f "/tmp/ScanFile" ]; then
	#   	rm /tmp/ScanFile
	#fi
	
	if [ -f "/tmp/uplinklist" ]; then
	   	rm /tmp/uplinklist
	fi
	
	if [ -f "/tmp/uplinklist_new" ]; then
		cp -a /tmp/uplinklist_new /etc/nas/config/wifinetwork-remembered.conf
	fi
		
	if [ -f "/tmp/scan_result" ]; then
		rm /tmp/scan_result
	fi
			
	if [ "$STA_CHANNEL_LITE" == "2" ]; then
		cat /tmp/scan_temp | grep 'Frequency="2"' > /tmp/scan24Gtmp
		sort -t '"' -k 6 -r -n /tmp/scan24Gtmp > /tmp/scan_sort
		sort -t "=" -k 1,2 -u -f /tmp/scan_sort > /tmp/scan_result
		
		#cp -a /tmp/scan_result /tmp/scanlist
		#cp -a /tmp/scanlist /tmp/scan_result 
	elif [ "$STA_CHANNEL_LITE" == "5" ]; then	
		cat /tmp/scan_temp | grep 'Frequency="5"' > /tmp/scan5Gtmp
		sort -t '"' -k 6 -r -n /tmp/scan5Gtmp > /tmp/scan_sort
		sort -t "=" -k 1,2 -u -f /tmp/scan_sort >> /tmp/scan_result
		
		#cp -a /tmp/scan_result /tmp/scanlist
		#cp -a /tmp/scanlist /tmp/scan_result 
	else
		cat /tmp/scan_temp | grep 'Frequency="5"' > /tmp/scan5Gtmp
		sort -t '"' -k 6 -r -n /tmp/scan5Gtmp > /tmp/scan_sort
		#sort -t "=" -k 1,2 -u -f /tmp/scan_sort > /tmp/scan_result
	
		cat /tmp/scan_temp | grep 'Frequency="2"' > /tmp/scan24Gtmp
		sort -t '"' -k 6 -r -n /tmp/scan24Gtmp >> /tmp/scan_sort
		sort -t "=" -k 1,2 -u -f /tmp/scan_sort >> /tmp/scan_result
		
		#cp -a /tmp/scan_result /tmp/scanlist
		#cp -a /tmp/scanlist /tmp/scan_result 
		
		#echo "END:"
		#cat /tmp/scan_result
	fi
	
	#cat /tmp/scanlist | awk 'BEGIN {FS="bssi/dmap="} {print $1}'
	
	if [ -f "/tmp/scan24Gtmp" ]; then
	   	rm /tmp/scan24Gtmp
	fi
	if [ -f "/tmp/scan5Gtmp" ]; then
	  	rm /tmp/scan5Gtmp
	fi
	
	if [ -f "/tmp/uplinklist_new" ]; then
	  	rm /tmp/uplinklist_new
	fi
	
	if [ "$STA_CLIENT" == "false" ]; then
		if [ "$STA_CHANNEL_LITE" == "0" ]; then
			/sbin/ifdown $STA_IFACE 
			/sbin/ifconfig $STA_IFACE down > /dev/null
			/sbin/ifdown $STA2G4_IFACE 
			/sbin/ifconfig $STA2G4_IFACE down > /dev/null
		elif [ "$STA_CHANNEL_LITE" == "2" ]; then
			/sbin/ifdown $STA2G4_IFACE
			/sbin/ifconfig $STA2G4_IFACE down > /dev/null 
		elif [ "$STA_CHANNEL_LITE" == "5" ]; then
			/sbin/ifdown $STA_IFACE 
			/sbin/ifconfig $STA_IFACE down > /dev/null
		fi
	fi
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_scanning_update.sh End update profile" >> /tmp/wificlientap.log
	fi
	rm /tmp/wifiprofileupdate
else
	if [ "$Debugmode" == "1" ]; then
		timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
		echo $timestamp ": wifi_scanning_update.sh wifiprofileupdate!!" >> /tmp/wificlientap.log
	fi
fi
rm /tmp/wificlientinterfacebusy
exit 0

# EOF
