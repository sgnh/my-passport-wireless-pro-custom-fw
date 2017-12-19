BEGIN { OFS = " "; } # OFS is a field separator used for "print"
/\<wlan1/ {
    # New cell description has started, so we need to print a previous one.
    # Detect security mode first.
        if (wpa || wpa2) {if (wpa) {if (tkip){ security = "WPAPSK/TKIP"} if (aes) {security = "WPAPSK/AES"} if (tkipaes) {security = "WPAPSK/TKIPAES"}}  \
        if (wpa2) {if (tkip){ security = "WPA2PSK/TKIP"} if (aes) {security = "WPA2PSK/AES"} if (tkipaes) {security = "WPA2PSK/TKIPAES" }}\
    if(wpa && wpa2){ if (tkip) {security = "WPAPSK1WPAPSK2/TKIP"} if (aes) {security = "WPAPSK1WPAPSK2/AES"} if (tkipaes) {security = "WPAPSK1WPAPSK2/TKIPAES"}}} else { if (wep) { security = "WEP" } else { security = "NONE" }}
    if (wpa || wpa2 || wep) { secured = "true" } else { secured = "false" }
        if (wps) {wpsmode = "true" } else { wpsmode = "false" }
    if (essid) print "ssid=\""essid"\"","mac=\""macaddr"\"", "signal_strength=\""quality"\"", "auto_join=\"false\" trusted=\"false\"", "security_mode=\""security"\"", "connected=\"false\" remembered=\"false\"", "secured=\""secured"\"", "wps_enabled=\""wpsmode"\"",\
         "dhcp_enabled=\"true\" ip=\"\" netmask=\"\" gateway=\"\" dns0=\"\" dns1=\"\" dns2=\"\" mac_clone_enable=\"false\" cloned_mac_address=\"\" bssi/dmap=0 Frequency=\""band"\" security_key=";
    # Reset security flags.
    wep = 0; wpa = 0; wpa2 = 0; tkipaes=0; tkip=0; aes=0; wps=0; band=2;
}

/\<SSID:/ {
    #essid = substr($0, 27);
    essid = substr($0, index($0, ":") + 2);
    #print essid
    #essid = substr(essid, 2, length(essid) - 2);  # discard quotes
    #gsub(/\\/,"\\\\",essid);
    if(essid == " ")
        essid = 0;
    if(essid == "\\x00")
        essid = 0;
        
}

/\<freq:/ {
    band0 = substr($0, index($0, ":") + 2);
    band = substr(band0,0, 1);
}

/\<wlan1/ {
    macaddr = toupper(substr($0,index($0, " ") + 1, 17));
        #gsub(/\ /,"",macaddr);
}

/\<Supported rates:/ {
        #wifiMode = substr($0, 30);
        #aaa = match($0,"54.0")
        #print aaa
}

/\<signal:/ {
    # We should support several output formats from iwlist scan (from
    # wireless_tools package):
    #
    # 1) Quality:30/70
    # 2) Quality=20/100
    # 3) Quality:60
    #
    # Quality might be separated with '=' or with ':' and we might have maximal
    # value present or not. This depends on the driver used.
    #
    #split($0, q, "[:=]"); # after split: q[1] -> "level", q[2] -> quality value
    #if (qvalues[2]) {
    #    quality = int(qvalues[1] / qvalues[2] * 100); # we have both parts, divide
    #} else {
    #    quality = qvalues[1]; # we have only one part, use it as-is
    #}
    qvalues = substr($0, index($0, ":") + 3, 5);
    quality = int(qvalues * 1.5);
    if(quality >= 100)
        quality = 100
    #print quality
}

/\<WPA:/ { 
        wpa = 1 
}
/\<RSN:/ { 
        wpa2 = 1 
}

/\<Pairwise ciphers: TKIP/ { tkip = 1;}
/\<Pairwise ciphers: CCMP/ { aes = 1;}  
/\<Pairwise ciphers: CCMP TKIP/ { tkipaes = 1;} 
/\<Pairwise ciphers: TKIP CCMP/ { tkipaes = 1;}
/\<WPS:/ { wps = 1;}

/\<capability:/ { 
        if (wpa == 0 && wpa2 == 0){
                aaa = match($0,"Privacy")
                if(aaa != 0){
                        wep = 1 
                }
        }
}

END {
    # handle last cell
        if (wpa || wpa2) {if (wpa) {if (tkip){ security = "WPAPSK/TKIP"} if (aes) {security = "WPAPSK/AES"} if (tkipaes) {security = "WPAPSK/TKIPAES"}}  \
        if (wpa2) {if (tkip){ security = "WPA2PSK/TKIP"} if (aes) {security = "WPA2PSK/AES"} if (tkipaes) {security = "WPA2PSK/TKIPAES" }}\
    if (wpa && wpa2){ if (tkip) {security = "WPAPSK1WPAPSK2/TKIP"} if (aes) {security = "WPAPSK1WPAPSK2/AES"} if (tkipaes) {security = "WPAPSK1WPAPSK2/TKIPAES"}}} else { if (wep) { security = "WEP" } else { security = "NONE" }}
    if (wps) {wpsmode = "true" } else { wpsmode = "false" }
    if (wpa || wpa2 || wep) { secured = "true" } else { secured = "false" }
    if (essid) print "ssid=\""essid"\"","mac=\""macaddr"\"", "signal_strength=\""quality"\"", "auto_join=\"false\" trusted=\"false\"", "security_mode=\""security"\"", "connected=\"false\" remembered=\"false\"", "secured=\""secured"\"", "wps_enabled=\""wpsmode"\"", \
        "dhcp_enabled=\"true\" ip=\"\" netmask=\"\" gateway=\"\" dns0=\"\" dns1=\"\" dns2=\"\" mac_clone_enable=\"false\" cloned_mac_address=\"\" bssi/dmap=0 Frequency=\""band"\" security_key=";
	    #if (wpa) { security = "wpa" } else { if (wep) { security = "wep" } else { security = "none" }}
	    #if (essid) print "ssid:"essid,"mac:\""macaddr"\"", "signal_strength:"quality, security;   
	}