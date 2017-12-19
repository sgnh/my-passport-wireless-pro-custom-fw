#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
contentdirs=`ls -F -c -r /shares/`
for contentdir in ${contentdirs}  ; do
	output_strig="${output_strig}+A|/"${contentdir::-1}","
done
echo "${output_strig::-1}" > /etc/contentdir
/usr/local/sbin/writeTwonkyContentDir.sh
IFS=$SAVEIFS

