#include <linux/ctype.h>
#include <linux/string.h>
#include <linux/stddef.h>
#include <asm/arch/io.h>
#include <asm/arch/system.h>

#include <common.h>
#include <parse_h.h>
#include <asm/arch/bootparam.h>
#include <factorylib.h>
#include <asm/arch/fw_info.h>

bootparam_t bootparam;

#define DEBUG(msg,arg...)   do { printf("[%s %3d]:", __FILE__, __LINE__); printf(msg,##arg); } while(0)
//#define DEBUG(msg,arg...)

#define BOOT_PARAM_FILE_NAME	FACTORY_HEADER_FILE_NAME"000BootParam.h"
#define BOOT_PART_FILE_NAME		FACTORY_HEADER_FILE_NAME"layout.txt"
#define BOOT_TVSYSTEM_FILE_NAME		FACTORY_HEADER_FILE_NAME"video_rpc.bin"
#define BOOT_CHECKSUM_FILE_NAME		FACTORY_HEADER_FILE_NAME"edid_checksum.bin"

extern int boot_power_on_mode;
extern uchar boot_ac_on;
extern uchar boot_music_enable;
extern uchar boot_logo_enable;
extern uint custom_video1_leng;
extern uint custom_video2_leng;
extern uint custom_audio1_leng;
extern uint custom_audio2_leng;

extern uint  custom_audio1_length ;
extern uint  custom_video1_length ;
extern uint  custom_audio2_length ;
extern uint  custom_video2_length ;

extern uint custom_logo_src_width;
extern uint custom_logo_src_height;
extern uint custom_logo_dst_width;
extern uint custom_logo_dst_height;

extern uint boot_part;

extern uchar checksum_128;
extern uchar checksum_256;

/************************************************************************
**
** get boot info in factory area of flash
**
*************************************************************************/
void get_bootparam(void)
{
	char *dst_addr;
	char *retAddr;
	int dst_length;
	uint retVal;

	printf("%s:\n", __FUNCTION__);

//	display_evaluate_time("get_bootparam-0");

	memset(&bootparam, 0, sizeof(bootparam));

#if 1
    bootparam.prev_power_state = POWER_STATE_ON;
    bootparam.boot_music_enable = 1;
    bootparam.boot_logo_enable = 1;
    bootparam.backlight_value = 50;

#else

	if (factory_read(BOOT_PARAM_FILE_NAME, &dst_addr, &dst_length)) {
		printf("------------can't find %s\n", BOOT_PARAM_FILE_NAME);
		bootparam.prev_power_state = POWER_STATE_ON;
		bootparam.boot_music_enable = 1;
		bootparam.boot_logo_enable = 1;
		bootparam.backlight_value = 50;
	}
	else {
		printf("------------%s found\n", BOOT_PARAM_FILE_NAME);

		if (parse_h("BOOT_POWER_ON_MODE", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.prev_power_state = retVal;
			printf("BOOT_POWER_ON_MODE=%d\n", retVal);
                        EXECUTE_CUSTOMIZE_FUNC(0);
		}
		else {
			DEBUG("can't find power state\n");
		}

	    if (parse_h("BOOT_LOGO_ENABLE", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.boot_logo_enable = retVal;
			boot_logo_enable = retVal;
			printf("BOOT_LOGO_ENABLE=%d\n", retVal);
		}
		else {
			DEBUG("can't find boot_logo_enable\n");
		}

	    if (parse_h("CUSTOM_VIDEO1_LENG", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.custom_video1_leng = retVal;
			printf("CUSTOM_VIDEO1_LENG=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_video1_leng\n");
		}

	    if (parse_h("CUSTOM_VIDEO2_LENG", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.custom_video2_leng = retVal;
			printf("CUSTOM_VIDEO2_LENG=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_video2_leng\n");
		}

		if (parse_h("BOOT_MUSIC_ENABLE", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.boot_music_enable = retVal;
			printf("BOOT_MUSIC_ENABLE=%d\n", retVal);
		}
		else {
			DEBUG("can't find music enable state\n");
		}

		if (parse_h("CUSTOM_AUDIO1_LENG", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.custom_audio1_leng = retVal;
			printf("CUSTOM_AUDIO1_LENG=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_audio1_leng\n");
		}

		if (parse_h("CUSTOM_AUDIO2_LENG", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			bootparam.custom_audio2_leng = retVal;
			printf("CUSTOM_AUDIO2_LENG=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_audio2_leng\n");
		}
		
		/****** for logo display ******/	
		//source
		if (parse_h("CUSTOM_LOGO_SRC_WIDTH", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			custom_logo_src_width = retVal;
			printf("CUSTOM_LOGO_SRC_WIDTH=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_logo_src_width\n");
		}
		
		if (parse_h("CUSTOM_LOGO_SRC_HEIGHT", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			custom_logo_src_height = retVal;
			printf("CUSTOM_LOGO_SRC_HEIGHT=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_logo_src_height\n");
		}
		
		//destination
		if (parse_h("CUSTOM_LOGO_DST_WIDTH", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			custom_logo_dst_width = retVal;
			printf("CUSTOM_LOGO_DST_WIDTH=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_logo_dst_width\n");
		}
		
		if (parse_h("CUSTOM_LOGO_DST_HEIGHT", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			custom_logo_dst_height = retVal;
			printf("CUSTOM_LOGO_DST_HEIGHT=%d\n", retVal);
		}
		else {
			DEBUG("can't find custom_logo_dst_height\n");
		}
		/****** for logo display ******/
	}

#endif

#ifdef Board_NAND_default
	if(bootparam.prev_power_state == 0 && boot_ac_on)
		boot_power_on_mode = 0;
	boot_music_enable = bootparam.boot_music_enable;
	boot_logo_enable = bootparam.boot_logo_enable;
	custom_video1_leng = bootparam.custom_video1_leng;
	custom_video2_leng = bootparam.custom_video2_leng;
	custom_audio1_leng = bootparam.custom_audio1_leng;
	custom_audio2_leng = bootparam.custom_audio2_leng;
#endif

#ifdef CONFIG_SYS_RTK_EMMC_FLASH
	if(bootparam.prev_power_state == 0 && boot_ac_on)
		boot_power_on_mode = 0;
    
	boot_music_enable = bootparam.boot_music_enable;
	boot_logo_enable = bootparam.boot_logo_enable;
    
	custom_video1_length = bootparam.custom_video1_leng;
	custom_video2_length = bootparam.custom_video2_leng;
	custom_audio1_length = bootparam.custom_audio1_leng;
	custom_audio2_length = bootparam.custom_audio2_leng;
#endif

//	display_evaluate_time("get_bootparam-1");
}

/************************************************************************
**
** get layout.txt in factory area of flash
**
*************************************************************************/
void get_layout(void)
{
	char *dst_addr;
	char *retAddr;
	int dst_length;
	uint retVal;

	printf("%s:\n", __FUNCTION__);

//	display_evaluate_time("get_layout-0");

	if (factory_read(BOOT_PART_FILE_NAME, &dst_addr, &dst_length)) {
		printf("------------can't find %s\n", BOOT_PART_FILE_NAME);
		boot_part = 0;
	}
	else {
		printf("------------%s found\n", BOOT_PART_FILE_NAME);

		if (parse_h("BOOTPART", dst_addr, (uint)dst_length, &retVal, &retAddr) == 0) {
			boot_part = retVal;
			printf("BOOTPART=%d\n", retVal);
		}
		else {
			DEBUG("can't find boot part\n");
		}
	}

//	display_evaluate_time("get_layout-1");
}

#ifdef CONFIG_SYS_AUTO_DETECT

/************************************************************************
**
** get video_rpc.bin in factory area of flash
**
*************************************************************************/
int get_one_step_info(void)
{
	char *dst_addr,*dst_addr_chk;
	int dst_length,dst_length_chk;

	//printf("%s:\n", __FUNCTION__);

	if (factory_read(BOOT_TVSYSTEM_FILE_NAME, &dst_addr, &dst_length)) {
		printf("------------can't find %s\n", BOOT_TVSYSTEM_FILE_NAME);
		//printf("dst_addr=%x\n, dst_length=%d\n",dst_addr,dst_length);
		return 0;
	}
	else {
		printf("------------%s found\n", BOOT_TVSYSTEM_FILE_NAME);
		
		rtd_outl( MIPS_ONE_STEP_INFO_ADDR , SWAPEND32(VO_RESOLUTION)) ; /* tell video firmware where we put the info. 0xa000b0c8*/
    	rtd_outl( VO_RESOLUTION, 0xee0bdec0); /* set magic pattern in first word */
		memcpy(VO_RESOLUTION+4, dst_addr ,dst_length);
		flush_cache(MIPS_ONE_STEP_INFO_ADDR, sizeof(unsigned int));
		flush_cache(VO_RESOLUTION, 4+ dst_length);
		
		
		if (factory_read(BOOT_CHECKSUM_FILE_NAME, &dst_addr_chk, &dst_length_chk)) 
		{
			printf("------------can't find %s\n", BOOT_CHECKSUM_FILE_NAME);
			//printf("dst_addr=%x\n, dst_length=%d\n",dst_addr,dst_length);
			return 0;
		}
		else
		{				
			memcpy(&checksum_128, dst_addr_chk ,sizeof(unsigned char));
			memcpy(&checksum_256, dst_addr_chk+sizeof(unsigned char),sizeof(unsigned char));	
			if(checksum_128==0 && checksum_256==0)
				return 0;			
		}
		
		return 1;
	}


}
#endif

