#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

LOAD_ADDR = 0x01500000
STATIC_LIB = 	../../static_lib/libefuse.a 			\
		../../static_lib/libobfuse.a			\
		../../lib/div64.o				\
		../../lib/time.o				\
		../../$(CPUDIR)/$(SOC)/mcp.o		\
		../../$(CPUDIR)/$(SOC)/timer.o	\
		../../$(CPUDIR)/$(SOC)/big_int.o	\
		../../$(CPUDIR)/$(SOC)/big_util.o	\
		../../$(CPUDIR)/cache_v7.o

# ********************************************************************
# Detect compiling environment.
# ********************************************************************
UNAME = $(shell uname)
LINUX_ENV = "LINUX"
CYGWIN_ENV = "CYGWIN"
ENV = $(CYGWIN_ENV)	# default

ifneq "$(filter Linux%,$(UNAME))" ""
ENV = $(LINUX_ENV)
endif

ifneq "$(filter CYGWIN%,$(UNAME))" ""
ENV = $(CYGWIN_ENV)
endif

# ********************************************************************
# Directories specifics.
# ********************************************************************


PERL    = perl
RM      = rm -rf
CD      = cd
CAT     = cat
CP      = cp

TOP_DIR         = $(shell cd .; pwd)
INCLUDE_DIR     = $(TOP_DIR)/include

OBFUSECATOR = $(TOP_DIR)/obfuse
RTSSL_EXE = $(TOP_DIR)/../../examples/flash_writer_u/tools/RtSSL/RtSSL
STR2BIN_PL = $(TOP_DIR)/../../examples/flash_writer_u/tools/script/str2bin.pl
REVERSE_PL = $(TOP_DIR)/../../examples/flash_writer_u/tools/script/reverse.pl
RSA_KEY_FILE = $(TOP_DIR)/../../examples/flash_writer_u/image/rsa_key_2048.pem
RSA_PUB_BIN = $(TOP_DIR)/secure_key/rsa_pub.bin
RSA_PUB_REV_BIN = $(TOP_DIR)/secure_key/rsa_pub_rev.bin
AES_KEY_TARGET = $(TOP_DIR)/../../examples/flash_writer_u/image/aes_128bit_key.bin
AES_SEED_TARGET = $(TOP_DIR)/../../examples/flash_writer_u/image/aes_128bit_seed.bin
AES_KEY_ENC = $(TOP_DIR)/secure_key/aes_128bit_key.bin
AES_SEED_ENC = $(TOP_DIR)/secure_key/aes_128bit_seed.bin
CUST_DATA = $(TOP_DIR)/../../examples/flash_writer_u/image/cust_data.bin

BIN_ARGS      = "rsa_pub_key="$(RSA_PUB_REV_BIN)
BIN_ARGS         += "aes_key="$(AES_KEY_ENC)
BIN_ARGS         += "aes_seed="$(AES_SEED_ENC)
BIN_ARGS         += "cust_data="$(CUST_DATA)

#TARGET_EXE        = $(TOP_DIR)/efuse_programmer
#TARGET_BIN        = $(TOP_DIR)/$(TARGET_NAME).bin
#TARGET_DIS        = $(TOP_DIR)/$(TARGET_NAME).dis


#-------------------------------------------------
TOPDIR  := $(shell /bin/pwd)
include $(TOPDIR)/../../config.mk

ELF-y        := efuse_programmer

#
# Some versions of make do not handle trailing white spaces properly;
# leading to build failures. The problem was found with GNU Make 3.80.
# Using 'strip' as a workaround for the problem.
#
ELF := $(strip $(ELF-y))

SREC := $(addsuffix .srec,$(ELF))
BIN  := $(addsuffix .bin,$(ELF))
DIS  := $(addsuffix .dis,$(ELF))


SOBJS	:= temp_target_array.o
SOBJS	+= start.o
COBJS	:= efusemain.o util.o  strlen.o strstr.o strtoul.o ctype.o
LIB	= $(obj)

LIBCOBJS = 

LIBOBJS	= $(addprefix $(obj),$(LIBAOBJS) $(LIBCOBJS))

SRCS	:= $(COBJS:.o=.c) $(LIBCOBJS:.o=.c) $(LIBAOBJS:.o=.S) $(SOBJS:.o=.S)
OBJS	:= $(addprefix $(obj),$(COBJS))
SSOBJS	:= $(addprefix $(obj),$(SOBJS))


gcclibdir := $(shell dirname `$(CC) -print-libgcc-file-name`)

CPPFLAGS += -I.. -I$(INCLUDE_DIR) -I$(TOP_DIR)/include
INCDIRS =  -I$(TOP_DIR)/../../include -I.. -I$(INCLUDE_DIR) 

# For PowerPC there's no need to compile standalone applications as a
# relocatable executable.  The relocation data is not needed, and
# also causes the entry point of the standalone application to be
# inconsistent.
ifeq ($(ARCH),powerpc)
AFLAGS := $(filter-out $(RELFLAGS),$(AFLAGS))
CFLAGS := $(filter-out $(RELFLAGS),$(CFLAGS))
CPPFLAGS := $(filter-out $(RELFLAGS),$(CPPFLAGS))
endif

# We don't want gcc reordering functions if possible.  This ensures that an
# application's entry point will be the first function in the application's
# source file.
CFLAGS = -g -O2 -fno-common -fzero-initialized-in-bss -msoft-float -mthumb-interwork -D__KERNEL__ -fno-builtin -ffreestanding -nostdinc -isystem $(gcclibdir)/../include -pipe -DCONFIG_ARM -D__ARM__ -marm -mabi=aapcs-linux -march=armv7-a -D__EL__
CFLAGS += $(INCDIRS)
#all:	clean b2a $(obj).depend $(OBJS) $(SSOBJS) $(LIB) $(ELF) $(SREC) $(BIN)
all:	clean gen_key b2a $(OBJS) $(SSOBJS) $(LIB) $(ELF) $(SREC) $(BIN)

gen_key:
	$(STR2BIN_PL) `$(RTSSL_EXE) rsa -print -modulous -i $(RSA_KEY_FILE)` > $(RSA_PUB_BIN)
	$(REVERSE_PL) $(RSA_PUB_BIN) > $(RSA_PUB_REV_BIN)
	$(OBFUSECATOR) 1 $(AES_KEY_TARGET) $(AES_SEED_TARGET) $(AES_KEY_ENC) $(AES_SEED_ENC)

b2a:
	./bin2ascii $(BIN_ARGS) > temp_target_array.h

clean:
	-rm -f $(ELF) *.o temp_target_array.h *.bin *.map *.dis *.srec
	
#########################################################################
$(LIB):	$(obj).depend $(LIBOBJS)
	$(call cmd_link_o_target, $(LIBOBJS))

$(ELF): 	$(LIB) 
		$(LD) $(LDFLAGS) -g -Ttext $(LOAD_ADDR) \
			-o $@ -e start $(SOBJS) $(COBJS) $(LIB) $(STATIC_LIB) \
			-L$(gcclibdir) -lgcc -Map efuse_programmer.map

$(SREC):
$(obj)%.srec:	$(obj)%
		$(OBJCOPY) -O srec $< $@ 2>/dev/null

$(BIN):
$(obj)%.bin:	$(obj)%
		$(OBJCOPY) -O binary $< $@ 2>/dev/null
		$(OBJDUMP) -DS $<  >$(DIS)

#########################################################################


# defines $(obj).depend target
#include $(SRCTREE)/rules.mk

#sinclude $(obj).depend

#########################################################################

