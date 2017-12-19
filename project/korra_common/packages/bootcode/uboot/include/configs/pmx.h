#ifndef PMX_H
#define PMX_H
#include <common.h>
#include <command.h>
#include <usb.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/system.h>
#include <asm/arch/rbus/crt_reg.h>
#include <configs/pmx_version.h>


#ifdef DEBUG_MODE
#define PMX_DEBUG(format, args...) printf("[%s:%d] "format, __FILE__, __LINE__, ##args)
#else
#define PMX_DEBUG(args...)
#endif

typedef struct{
    char * kernel;
    char * dtb;
	char * rootfs;
}boot_config_t;

typedef enum{
    PMX_BOOTUP_NORMAL = 0 , 
    PMX_BOOTUP_RECOVERY
}PMX_BOOTUP_STATE;

typedef enum{
	PMX_NORMAL_FIRMWARE = 0,
	PMX_RECOVERY_USB2_FIRMWARE,
	PMX_RECOVERY_USB3_FIRMWARE
}PMX_FIRMWARE;

static int pmx_call_bootm(void);
int pmx_check_fw_in_usb_flash(PMX_FIRMWARE f);
char * pmx_get_bootup_partition(void);
int pmx_prepare_config(boot_config_t * configs, PMX_FIRMWARE f);
int pmx_read_fw_from_usb(boot_config_t * configs);
int pmx_do_bootp(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
#endif

