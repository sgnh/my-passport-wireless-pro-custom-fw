#!/bin/bash
#
#
# languageChange.sh <language>
# Change Vendor Language Setting

## section: main script

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

language=${1}

if [ $# -lt 1 ]; then
    echo "usage: languageChange.sh <languagename>"
    exit 1
else
    echo ${language} > /etc/language_vendor.conf
    exit 0
fi
