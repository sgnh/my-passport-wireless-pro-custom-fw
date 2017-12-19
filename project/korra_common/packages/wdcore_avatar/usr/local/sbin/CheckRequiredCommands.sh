#!/bin/sh

application_list="addgroup adduser ash awk bash busybox cat chfn chgrp chmod chown chpasswd clear cp crontab curl cut \
date dd delgroup deluser df diff dmesg dnsdomainname dpkg echo egrep env false fgrep file find free getopt \
grep gunzip gzip hdparm head hostname halt ipcalc kill killall ln login ls mkdir mkfifo mknod mktemp more \
mount mv netstat nice nohup passwd pidof ping ping6 printenv ps pwd python readlink reboot rmdir sed \
sh sleep smartctl smbpasswd stat sudo sync sysctl tail tar tee top touch true umount unlink uname \
unzip uptime userdel usermod usleep vi watch wc wget xargs zip ionice iotop start-stop-daemon init-functions"

application_list_adv="addr2line c++filt gdb nm objdump strace"

NotFoundItems=0

for i in $application_list
do
	found=`whereis "$i" | grep / | wc -l`
	if [ $found -eq 0 ]; then
		found=`find / -name $i -type l | wc -l`
		if [ $found -eq 0 ]; then
			found=`find / -name $i -type f | wc -l`
			if [ $found -eq 0 ]; then
				echo "Not find $i";
				NotFoundItems=`expr $NotFoundItems + 1`
			fi
		fi
	fi
done

for i in $application_list_adv
do
	found=`whereis "$i" | grep / | wc -l`
	if [ $found -eq 0 ]; then
		found=`find / -name $i -type l | wc -l`
		if [ $found -eq 0 ]; then
			found=`find / -name $i -type f | wc -l`
			if [ $found -eq 0 ]; then
				echo "[Adv] Not find $i";
				NotFoundItems=`expr $NotFoundItems + 1`
			fi
		fi
	fi
done

if [ $NotFoundItems -gt 0 ]; then
	echo "Check Failed"
else
	echo "Check Pass"
fi
