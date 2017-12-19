/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 * prototype of system related functions for RTD299X
 */

#ifndef _SYS_PROTO_H_
#define _SYS_PROTO_H_

#include <asm/io.h>

struct rtd299x_sysinfo {
	char *board_string;
};
extern const struct rtd299x_sysinfo sysinfo;

#endif
