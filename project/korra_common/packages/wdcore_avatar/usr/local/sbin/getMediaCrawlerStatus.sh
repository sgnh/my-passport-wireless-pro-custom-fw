#!/bin/sh
echo "<?xml version = \"1.0\" encoding = \"UTF-8\"?>" > /tmp/mediacrawler
echo "<WDMCRequest" >> /tmp/mediacrawler
echo " Subsystem = \"system\"" >> /tmp/mediacrawler
echo " RequestName = \"GetStatus\"" >> /tmp/mediacrawler
echo " Requester = \"\"/>" >> /tmp/mediacrawler
/usr/local/wdmcserver/bin/requesttest.sh /tmp/mediacrawler

