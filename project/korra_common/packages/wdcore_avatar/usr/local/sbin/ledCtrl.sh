#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# ledCtrl.sh 
#   This file defines generic LED APIs. It should be independent of the hw level. 
#   It implements the LED policies (from PRD/SFS docs) regardless of  LED 
#   access mechanism.
#

#---------------------

# include file that provides LED mechanism (hw dependent)
. /usr/local/sbin/ledConfig.sh

# include LED main functionality
. /usr/local/sbin/ledMain.sh

ledMain $1 $2

