#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
output_string="+A|/Storage,"
echo "${output_string::-1}" > /etc/contentdir
/usr/local/sbin/writeTwonkyContentDir.sh
IFS=$SAVEIFS

