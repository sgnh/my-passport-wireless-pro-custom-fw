BEGIN { OFS = " "; } # OFS is a field separator used for "print"
/\<Cell/ {
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
/\<ESSID:/ {
    essid = substr($0, 27);
    #essid = substr($0, index($0, ":") + 1);
    essid = substr(essid, 2, length(essid) - 2);  # discard quotes
    gsub(/\\/,"\\\\",essid);
    if(essid == " ")
        essid = 0;
}
	
/\<Protocol:/ {
        wifiMode = substr($0, 30);
        #print essid 
        #print wifiMode
        #if(wifiMode == "IEEE 802.11b"){
        #       essid = 1;      
        #}
}
	
/\<Address:/ {
    macaddr = substr($0,30);
        gsub(/\ /,"",macaddr);
}

/\<Frequency:/ {
    band0 = substr($0, index($0, ":") + 1);
    band = substr(band0,0, 1);
}
	
/\<Quality=/ {
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
    split($3, q, "[:=]"); # after split: q[1] -> "level", q[2] -> quality value
    split(q[2], qvalues, "/");
    if (qvalues[2]) {
        quality = int(qvalues[1] / qvalues[2] * 100); # we have both parts, divide
    } else {
        quality = qvalues[1]; # we have only one part, use it as-is
    }
}
/\<Encryption key:(o|O)n/ { wep = 1 }
/\<IE: WPA Version 1/ { wpa = 1 }
/\<IE: IEEE 802.11i\/WPA2 Version 1/ { wpa2 = 1 }
/\<Pairwise Ciphers \(1\) : CCMP/ { aes = 1;}
/\<Pairwise Ciphers \(1\) : TKIP/ { tkip = 1;}  
/\<Pairwise Ciphers \(2\) : CCMP TKIP/ { tkipaes = 1;}  
/\<Pairwise Ciphers \(2\) : TKIP CCMP/ { tkipaes = 1;}  
/\<IE: WPS Version: / { wps = 1;}               
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