#!/bin/bash
#
# © 2011 Western Digital Technologies, Inc. All rights reserved.
#
# update dms_descr.xml from /etc/nasdevice.xml
. /etc/system.conf
. /etc/default/upnp_nas

NAS_DEVICE_FILE="${UPNPNAS_SOURCE_DIR:-/etc}/$UPNPNAS_FILE"

[ -e ${NAS_DEVICE_FILE} ] || exit 1

friendlyName=`sed -n -e '/<friendlyName>/s#\(.*<friendlyName>\)\(.*\)\(</friendlyName>.*\)#\2#p' <${NAS_DEVICE_FILE}`
manufacturer=`sed -n -e '/<manufacturer>/s#\(.*<manufacturer>\)\(.*\)\(</manufacturer>.*\)#\2#p' <${NAS_DEVICE_FILE}`
manufacturerURL=`sed -n -e '/<manufacturerURL>/s#\(.*<manufacturerURL>\)\(.*\)\(</manufacturerURL>.*\)#\2#p' <${NAS_DEVICE_FILE}`
modelName=`sed -n -e '/<modelName>/s#\(.*<modelName>\)\(.*\)\(</modelName>.*\)#\2#p' <${NAS_DEVICE_FILE}`
### Xbox kludge
### modelNumber=`sed -n -e '/<modelNumber>/s#\(.*<modelNumber>\)\(.*\)\(</modelNumber>.*\)#\2#p' <${NAS_DEVICE_FILE}`
modelNumber="0.0"
modelURL=`sed -n -e '/<modelURL>/s#\(.*<modelURL>\)\(.*\)\(</modelURL>.*\)#\2#p' <${NAS_DEVICE_FILE}`
serialNumber=`/usr/local/sbin/getSerialNumber.sh`
UDN=`sed -n -e '/<UDN>uuid:/s#\(.*\)\(<UDN>uuid:\)\([0-9A-Fa-f]*-[0-9A-Fa-f]*-[0-9A-Fa-f]*-[0-9A-Fa-f]*-[0-9A-Fa-f]\)\([0-9A-Fa-f]\)\([0-9A-Fa-f]*\)\(</UDN>\)#\32\5#p'  \
     <${NAS_DEVICE_FILE}`
containerId=`sed -n -e '/<df:X_containerId/s#\(.*\)\(<df:X_containerId.*\)#\2#p' <$NAS_DEVICE_FILE`
df_X_modelId=`sed -n -e '/<df:X_modelId/s#\(.*\)\(<df:X_modelId.*\)#\2#p' <$NAS_DEVICE_FILE`
presentationURL=`sed -n -e '/<presentationURL/s#\(.*\)\(<presentationURL.*\)#\2#p' <$NAS_DEVICE_FILE`
##pnpx_X_hardwareId=`sed -n -e '/<pnpx:X_hardwareId/s#\(.*\)\(<pnpx:X_hardwareId.*\)#\2#p' <$NAS_DEVICE_FILE`
pnpx_X_hardwareId="<pnpx:X_hardwareId>${Media_X_hardwareId}</pnpx:X_hardwareId>"

### echo $friendlyName
### echo $manufacturer
### echo $manufacturerURL
### echo $modelName
### echo $modelId
### echo $modelNumber
### echo $modelURL
### echo $UDN
### echo $containerId
### echo $df_X_modelId
### echo $pnpx_X_hardwareId

sed -i \
  -e '/<friendlyName>/s#\(.*<friendlyName>\)\(.*\)\(</friendlyName>.*\)#\1'"$friendlyName"'\3#' \
  -e '/<manufacturer>/s#\(.*<manufacturer>\)\(.*\)\(</manufacturer>.*\)#\1'"$manufacturer"'\3#' \
  -e '/<manufacturerURL>/s#\(.*<manufacturerURL>\)\(.*\)\(</manufacturerURL>.*\)#\1'"$manufacturerURL"'\3#' \
  -e '/<modelName>/s#\(.*<modelName>\)\(.*\)\(</modelName>.*\)#\1'"$modelName"'\3#' \
  -e '/<modelNumber>/s#\(.*<modelNumber>\)\(.*\)\(</modelNumber>.*\)#\1'"$modelNumber"'\3#' \
  -e '/<modelURL>/s#\(.*<modelURL>\)\(.*\)\(</modelURL>.*\)#\1'"$modelURL"'\3#' \
  -e '/<serialNumber>/s#\(.*<serialNumber>\)\(.*\)\(</serialNumber>.*\)#\1'"$serialNumber"'\3#' \
  -e '/<UDN>/s#\(.*<UDN>uuid:\)\(.*\)\(</UDN>.*\)#\1'"$UDN"'\3#' \
  -e '/<df:X_containerId/s#\(.*\)\(<df:X_containerId.*\)#'"$containerId"'#' \
  -e '/<df:X_modelId/s#\(.*\)\(<df:X_modelId.*\)#'"$df_X_modelId"'#' \
  -e '/<presentationURL/s#\(.*\)\(<presentationURL.*\)#'"$presentationURL"'#' \
  -e '/<pnpx:X_hardwareId/s#\(.*\)\(<pnpx:X_hardwareId.*\)#'"$pnpx_X_hardwareId"'#' \
  /usr/local/dlna-access/xml/dms_descr.xml

exit 0
