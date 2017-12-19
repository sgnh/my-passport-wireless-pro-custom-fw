#########################################################################
# Path Setting
#########################################################################
#PRJ_ROOT=../../..
#RSDK=$(PRJ_ROOT)/tmp/asdk-4.4.7-armv7-EL-3.7-0.9.33-a32ft-130123/bin

# object directories
OBJ_DIR=.

#########################################################################
# MPU specific arguments
#########################################################################
#GCCVER=$(RSDK)
#CC=$(GCCVER)/arm-linux-gcc
#LD=$(GCCVER)/arm-linux-ld
#NM=$(GCCVER)/arm-linux-nm
#AR=$(GCCVER)/arm-linux-ar

GCC_INC_DIR := $(shell $(CC) -print-file-name=include)
GCC_LIB_DIR := $(shell $(CC) -print-libgcc-file-name)


#CC=$(RSDK)/asdk-linux-gcc
ASM=$(CC)
#OBJDUMP=$(RSDK)/asdk-linux-objdump
#OBJCOPY=$(RSDK)/asdk-linux-objcopy
#LD=$(RSDK)/asdk-linux-ld

INC_PATH = -I./include/ 
#CFLAGS :=
#CFLAGS += -mcpu=cortex-a9
#CFLAGS += $(INC_PATH) -D__KERNEL__ -g -Os -fno-common -ffixed-r8 -msoft-float -fno-builtin -ffreestanding -nostdinc -pipe -marm -mno-thumb-interwork -mabi=aapcs-linux -march=armv7-a  -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -mno-thumb-interwork
#ASFLAGS = -D__ASSEMBLY__ $(CFLAGS)
#LDFLAGS = -L $(PRJ_ROOT)/tmp/asdk-4.4.7-armv7-EL-3.0-0.9.33-a32-120510/lib/gcc/arm-linux-gnueabi/4.4.7/armv7 -lgcc

CFLAGS :=
CFLAGS += -gdwarf-2
CFLAGS += -Os
CFLAGS += -DUSE_GNU_GCC
CFLAGS += -fomit-frame-pointer
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
CFLAGS += -mlong-calls
CFLAGS += -nostdinc
CFLAGS += -I.

LDFLAGS :=
LDFLAGS += -EL -Bstatic
LDFLAGS += $(GCC_LIB_DIR)


LINK_SCR = new_link.ld


#########################################################################
# Sources
#########################################################################
C_SOURCE = 

ASM_SOURCE = new_start.S new_start2.S

#########################################################################
# Objects
#########################################################################
C_OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(C_SOURCE))
ASM_OBJS := $(patsubst %.S,$(OBJ_DIR)/%.o,$(ASM_SOURCE))
APP_NAME := redirect

#########################################################################
# D flags
#########################################################################
DFLAGS =  

#########################################################################
# Rules
#########################################################################
.PHONY: all clean

all: $(APP_NAME).elf do_pack

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c  $< -o $@

$(OBJ_DIR)/%.o: %.S
	$(ASM) $(ASFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	$(ASM) $(ASFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@


$(APP_NAME).elf:$(ASM_OBJS) $(C_OBJS)
	$(LD) -Tnew_link.lds -o $(APP_NAME).elf $(C_OBJS) $(LDFLAGS) 
	$(OBJDUMP) -DS $(APP_NAME).elf > $(APP_NAME).text
	$(OBJCOPY) -O binary $(APP_NAME).elf  $(APP_NAME).bin

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f *.elf
	rm -f *.map
	rm -f *.text
	rm -f *.bin

do_pack:
	perl packer.pl $(APP_NAME)
#########################################################################
# End
#########################################################################
#	$(LD) $^ -Tnew_link.lds $(LINK_SCR)  -o $(APP_NAME).elf $(LDFLAGS) -Map $(APP_NAME).map
#	$(LD) -Tnew_link.lds -o $(APP_NAME).elf $(C_OBJS) $(LDFLAGS) 
