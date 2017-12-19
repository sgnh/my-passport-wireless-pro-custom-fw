#!/bin/sh
source /etc/nas/config/wifinetwork-param.conf

specified=$1
specifiedMAC=$2
	
	if [ -f "/tmp/apClients" ]; then
		rm "/tmp/apClients"
	fi
	
	if [ "$AP_CHANNEL_LITE" == "0" ]; then
		arp -i br0 -a > /tmp/apclientARP
	elif [ "$AP_CHANNEL_LITE" == "2" ]; then	
		arp -i "$AP_IFACE" -a > /tmp/apclientARP
	elif [ "$AP_CHANNEL_LITE" == "5" ]; then	
		arp -i "$AP5G_IFACE" -a > /tmp/apclientARP
	fi
		
	AP2G4=`ifconfig | grep ^${AP_IFACE}`
	if [ "$AP2G4" != "" ]; then
		hostapd_cli -i ${AP_IFACE} all_sta | grep "connected_STA"  > /tmp/apclientnum
	
		cat /tmp/apclientnum | while read lineProfile
		do
			wifimac=`echo ${lineProfile} | awk -F= '{ print $1 }' |  tr [:lower:] [:upper:]`
			if [ "${wifimac}" == "" ];then
  				continue
  			fi
  			wifimacd=`echo ${lineProfile} | awk -F= '{ print $1 }'`
  			duplicated=`cat /tmp/apclientARP | grep -rsi "${wifimacd}" | wc -l`
  			if [ "${duplicated}" -ge 2 ]; then
  				cleanCache=1
  			fi
	 		iptmp=`cat /tmp/apclientARP | grep -rsi "${wifimac}" | tail -1`
        	ipclient=`echo "$iptmp" | cut -c 4-17`
  			if [ "$ipclient" != "" ]; then
  				if [ "${cleanCache}" == "1" ]; then
  					arp -i br0 -d "$ipclient"
  				fi
  				if [ "$AP_DHCPD_ENABLE" == "true" ]; then 
  					client=`cat /var/lib/dhcp/dhcpd.leases | grep -A 8 "${ipclient}" | grep client | awk '{ print $2 }'| sort | uniq | sed 's/;*$//'`
					if [ "$client" = "" ]; then
						client="\"\""
					fi
  				else
  					client="\"\""
  				fi
  			else
  				if [ "$AP_DHCPD_ENABLE" == "true" ]; then 
  					client=`cat /var/lib/dhcp/dhcpd.leases | grep -A 8 "${wifimacd}" | grep client | awk '{ print $2 }'| sort | uniq | sed 's/;*$//'`
  				fi
  				if [ "$client" = "" ]; then
					client="\"\""
				fi
  			fi
  		
  			if [ "$specified" == "" ]; then	
  				sta_info="mac:\"$wifimac\" ip:\"$ipclient\" name:$client"
  			elif [ "$specified" == "--mac" ]; then
  				specifiedMAC=`echo "$specifiedMAC" | tr [:lower:] [:upper:]`
  				if [ "$specifiedMAC" == "$wifimac" ]; then
  					sta_info="mac:\"$wifimac\" ip:\"$ipclient\" name:$client"
  					break;
  				fi
  			fi
  	
			connectedTime=`hostapd_cli -i "$AP_IFACE" sta "$wifimac" | tail -1 | awk -F= '{print $NF}'`
			
  			if [ "$connectedTime" != "" ]; then
  				echo ${sta_info} "connected_time:\"$connectedTime\" connected_band:\"2\"" >> /tmp/apClientsTmp
  			else
  				connectedTime=`date +%s`
  				echo ${sta_info} "connected_time:\"$connectedTime\" connected_band:\"2\"" >> /tmp/apClientsTmp
  			fi
		done
	fi
	AP5G=`ifconfig | grep ^${AP5G_IFACE}`
	if [ "$AP5G" != "" ]; then
		hostapd_cli -i ${AP5G_IFACE} all_sta  | grep "connected_STA" > /tmp/apclientnum
		

		cat /tmp/apclientnum | while read lineProfile
		do
			wifimac=`echo ${lineProfile} | awk -F= '{ print $1 }' |  tr [:lower:] [:upper:]`
			if [ "${wifimac}" == "" ];then
  				continue
  			fi
  			wifimacd=`echo ${lineProfile} | awk -F= '{ print $1 }'`
  			duplicated=`cat /tmp/apclientARP | grep -rsi "${wifimacd}" | wc -l`
  			if [ "${duplicated}" -ge 2 ]; then
  				cleanCache=1
  			fi
  			iptmp=`cat /tmp/apclientARP | grep -rsi "${wifimac}" | tail -1`
       	 	ipclient=`echo "$iptmp" | cut -c 4-17`
  			if [ "$ipclient" != "" ]; then
  				if [ "${cleanCache}" == "1" ]; then
  					arp -i br0 -d "$ipclient"
  				fi
  				if [ "$AP_DHCPD_ENABLE" == "true" ]; then 
  					client=`cat /var/lib/dhcp/dhcpd.leases | grep -A 8 "${ipclient}" | grep client | awk '{ print $2 }'| sort | uniq | sed 's/;*$//'`
					if [ "$client" = "" ]; then
						client="\"\""
					fi
  				else
  					client="\"\""
  				fi
  			else
  				if [ "$AP_DHCPD_ENABLE" == "true" ]; then 
  					client=`cat /var/lib/dhcp/dhcpd.leases | grep -A 8 "${wifimacd}" | grep client | awk '{ print $2 }'| sort | uniq | sed 's/;*$//'`
  				fi
  				if [ "$client" = "" ]; then
					client="\"\""
				fi
  			fi
  			if [ "$specified" == "" ]; then	
  				sta_info="mac:\"$wifimac\" ip:\"$ipclient\" name:$client"
  			elif [ "$specified" == "--mac" ]; then
  				specifiedMAC=`echo "$specifiedMAC" | tr [:lower:] [:upper:]`
  				if [ "$specifiedMAC" == "$wifimac" ]; then
  					sta_info="mac:\"$wifimac\" ip:\"$ipclient\" name:$client"
  					break;
  				fi
  			fi
  	
			connectedTime=`hostapd_cli -i "$AP5G_IFACE" sta "$wifimac" | tail -1 | awk -F= '{print $NF}'`
	
  			if [ "$connectedTime" != "" ]; then
  				echo ${sta_info} "connected_time:\"$connectedTime\" connected_band:\"5\"" >> /tmp/apClientsTmp
  			else
  				connectedTime=`date +%s`
  				echo ${sta_info} "connected_time:\"$connectedTime\" connected_band:\"5\"" >> /tmp/apClientsTmp
  			fi
		done
	fi
	
	if [ -f "/tmp/apClientsTmp" ]; then
		sort -t ":" -k 2 -u -f /tmp/apClientsTmp > /tmp/apClients
		if [ -f "/tmp/apClientsTmp" ]; then
			rm "/tmp/apClientsTmp"
		fi
		cat /tmp/apClients
	fi
exit 0

