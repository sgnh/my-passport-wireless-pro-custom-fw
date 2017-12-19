#!/bin/sh
enabled=$1
if [ "${enabled}" == "true" ] || [ "${enabled}" == "false" ]; then
  echo "<?xml version = \"1.0\" encoding = \"UTF-8\"?>" > /tmp/mediacrawler
  echo "<WDMCRequest" >> /tmp/mediacrawler
  echo " Subsystem = \"system\"" >> /tmp/mediacrawler
  echo " RequestName = \"SetPowerMode\"" >> /tmp/mediacrawler
  echo " Requester = \"\">" >> /tmp/mediacrawler
  echo "  <OnBattery>${enabled}</OnBattery>" >> /tmp/mediacrawler
  echo "</WDMCRequest>" >> /tmp/mediacrawler
  /usr/local/wdmcserver/bin/requesttest.sh /tmp/mediacrawler
  exit 0
else
	echo "setMediaCrawlerPowerSource.sh true | false"
	exit 1
fi

