#!/bin/sh
pwd
cp etc/default/saveconfigfiles.txt .
cat saveconfigfiles.txt | xargs tar cvf factory.conf
cp -a factory.conf etc/default/factory.conf
rm -f factory.conf saveconfigfiles.txt
