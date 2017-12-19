include $(TOPDIR)/config.mk

LIB	:= $(obj)libqc_verify.o

COBJS-$(CONFIG_QC_VERIFY) += qc_verify.o
COBJS-$(CONFIG_TEST_IP_1) += test_ip_1/test_ip_1.o

COBJS	:= $(COBJS-y)
SRCS	:= $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
