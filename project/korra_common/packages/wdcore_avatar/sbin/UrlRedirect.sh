#!/bin/sh
source /etc/nas/config/wifinetwork-param.conf

method=${1}

if [ "${method}" == "AddRule" ]; then
	iptables -t mangle -N internet
	iptables -t mangle -A PREROUTING -i br0 -p tcp -m tcp --dport 0:65535 -j internet
	iptables -t mangle -A PREROUTING -i br0 -p udp -m udp --dport 0:65535 -j internet
	iptables -t mangle -A internet -j MARK --set-mark 1
	iptables -t nat -A PREROUTING -p tcp -m tcp --dport 80 -j DNAT --to-destination ${AP_IP}:80
	iptables -t nat -A PREROUTING -p tcp -m tcp --dport 443 -j DNAT --to-destination ${AP_IP}:443
	iptables -t nat -A PREROUTING -p udp -m udp --dport 53 -j DNAT --to-destination ${AP_IP}:53

	iptables --append FORWARD --in-interface br0 -j ACCEPT
	iptables -t nat -A POSTROUTING -o wlan1 -j MASQUERADE
elif [ "${method}" == "DelRule" ]; then
	/usr/sbin/iptables -t nat -F
	if [ "$STA_CHANNEL" == "5" ]; then
    	/usr/sbin/iptables -t nat -A POSTROUTING -o $STA_IFACE -j MASQUERADE
    else
    	/usr/sbin/iptables -t nat -A POSTROUTING -o $STA2G4_IFACE -j MASQUERADE
    fi
fi
