#
# This file is subject to the terms and conditions of the GNU General Public
# License.  See the file "COPYING" in the main directory of this archive
# for more details.
# 
# Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
# 

include $(TOPDIR)/config.mk

LIB	=  $(obj)lib$(SOC).o

COBJS	+= hwinit.o
COBJS	+= timer.o
COBJS	+= clocks.o
COBJS-$(CONFIG_SYS_PANEL_SUPPORT) += panel.o
COBJS	+= factorylib.o
COBJS	+= factorylib_ro.o
COBJS	+= bootparam.o
#COBJS-$(CONFIG_SYS_IR_SUPPORT) += ir.o
COBJS	+= ir.o
COBJS	+= mem.o
COBJS	+= mcp.o
COBJS	+= md.o
COBJS	+= big_int.o
COBJS	+= big_util.o

SRCS	:= $(SOBJS:.o=.S) $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS) $(SOBJS))

all:	 $(obj).depend $(LIB)

$(LIB):	$(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
