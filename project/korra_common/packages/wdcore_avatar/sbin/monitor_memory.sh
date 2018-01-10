#!/bin/bash
/usr/bin/ps -e -o pid,user,cpu,size,rss,cmd --sort -size,-rss | head
