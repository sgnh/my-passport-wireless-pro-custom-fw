<?php 
  $test_ip_mac_debugger = "gMACAddr:".$_POST["gRemoteMACAddr"]." - "."clientMACAddr:".$_POST["clientMACAddr"]." - "."gRemoteAddr:".$_POST["gRemoteAddr"]." - "."clientIPAddr:".$_POST["clientIPAddr"]."----".date ("Y-m-d/H:i:s");
  //shell_exec("echo 45676 >> /tmp/Atest.log");
  shell_exec("echo $test_ip_mac_debugger >> /tmp/remodeIP_mac_debugger.log");
  return $test_ip_mac_debugger;
?>