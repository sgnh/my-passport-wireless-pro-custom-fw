interface=wlan1
ctrl_interface=/var/run/hostapd

ssid=Korra_SA_01

# 2.4GHz or 5GHz
hw_mode=a
channel=36

driver=nl80211
beacon_int=100
ignore_broadcast_ssid=0

ieee80211n=1
ht_capab=[HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]

max_num_sta=8


macaddr_acl=0
#bridge=br0

auth_algs=1

# WPA
wpa=0
wpa_passphrase=
wpa_key_mgmt=WPA-PSK
wpa_pairwise=TKIP
rsn_pairwise=CCMP









#WEP
#wep_default_key=0
#wep_key0=qwert

