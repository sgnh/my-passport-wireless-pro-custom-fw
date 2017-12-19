#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# encodes url for proper transmission
#
# usage: url_encode [string]
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------

# usage exit for too many parameters
[ $# -gt 1 ] && { echo >&2 "usage: url_encode [string]"; return 1; }

# self call when an argument is given, else handle stdin
[ $# -eq 1 ] && { echo -n "$1" | urlEncode.sh; exit $?; }
	
# first create alternating lines of hex code and ascii characters
# then remember the hex value,
# convert spaces to +,
# keep some selected characters unchanged
# and use the hexvalue prefixed with a % for the rest
##od -t x1c -w1 -v -An |
##LANG=C awk '
##  NR % 2                  { hex=$1;               next    }
##  /^ *$/                  { printf("%s", "+");    next    }
##  /^ *[a-zA-Z0-9.*()-]$/  { printf("%s", $1);     next    }
##  /^ *\//                 { printf("%s", $1);     next    }
##                          { printf("%%%s", hex)           }
##'
hexdump -v -e '1/1 "%02x\t"' -e '1/1 "%_c\n"' |
LANG=C awk '
	$1 == "20"                      { printf("%s",      "+");   next    }
	$2 ~  /^[a-zA-Z0-9.*()\/-]$/    { printf("%s",      $2);    next    }
									{ printf("%%%s",    $1)             }
'

#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}
