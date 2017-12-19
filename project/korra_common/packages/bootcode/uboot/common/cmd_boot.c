/*
 * (C) Copyright 2000-2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Misc boot support
 */
#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/arch/rbus/crt_reg.h>
#include <asm/arch/system.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/panelConfigParameter.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/flash_writer_u/mcp.h>
#include <watchdog.h>
#include <nand.h>
#include <asm/arch/rbus/nand_reg.h>

#ifdef CONFIG_LZMA
#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>
#endif /* CONFIG_LZMA */
#include "linux/lzo.h"

DECLARE_GLOBAL_DATA_PTR;


typedef enum{
	BOOT_FROM_USB_DISABLE,
	BOOT_FROM_USB_UNCOMPRESSED,
	BOOT_FROM_USB_COMPRESSED
}BOOT_FROM_USB_T;

typedef enum{
	BOOT_FROM_FLASH_NORMAL_MODE,
	BOOT_FROM_FLASH_MANUAL_MODE
}BOOT_FROM_FLASH_T;

#if defined(CONFIG_RTD299X) || defined(CONFIG_RTD1195)
uint *uart_reg_base_ptr			= (uint *)MIPS_UART_REG_BASE_ADDR;			/* notify uart reg to A/V CPU */
uint *boot_av_info_ptr			= (uint *)MIPS_BOOT_AV_INFO_PTR_ADDR;		/* copy form darwin *boot_av_info_ptr */
uint *AudioFlag_ptr				= (uint *)MIPS_AUDIO_FLAG_PTR_ADDR;			/* copy from darwin *streamfile_flagA */
uint *AudioFW_entry_ptr			= (uint *)MIPS_AUDIO_FW_ENTRY_PTR_ADDR;		/* copy from darwin *streamfile_ptrA */
uint *shared_printk_buffer_ptr	= (uint *)MIPS_SHARED_PRINTK_BUFFER_ADDR;	/* copy form darwin *shared_printk_buf */

uint blk_state_len;			// length of bootcode block state array
uint nand_bootcode_area_size = 0xc00000;		// NAND bootcode area size //12M
uint eMMC_bootcode_area_size = 0x220000;		// eMMC bootcode area size
uint eMMC_fw_desc_table_start = 0;				// start address of valid fw desc table in emmc
uint nand_fw_desc_table_start = 0;				// start address of valid fw desc table in nand
uchar boot_music_enable = 1;
int boot_power_on_mode = 1;
uint custom_audio1_length = 0;
uint custom_video1_length = 0;
uint custom_audio2_length = 0;
uint custom_video2_length = 0;
uint boot_part = 0; // from layout.txt
uchar sys_logo_enabled = 0;
uchar sys_logo_is_HDMI = 0;
uchar tv_test_enabled = 0;
fw_desc_entry_v1_t *kernel_entry = NULL;
BOOT_FROM_FLASH_T boot_from_flash = BOOT_FROM_FLASH_NORMAL_MODE;
BOOT_FROM_USB_T boot_from_usb = BOOT_FROM_USB_DISABLE;
extern BOOT_MODE boot_mode;
uchar boot_logo_enable;
uint custom_logo_src_width;
uint custom_logo_src_height;
uint custom_logo_dst_width;
uint custom_logo_dst_height;
#ifdef CONFIG_TEE
uint tee_enable=0;
#endif
#endif

#ifdef CONFIG_CMD_GO

#if defined(CONFIG_RTD299X) || defined(CONFIG_RTD1195)

extern void delete_env(void);
extern void enable_clock(uint reg_reset, uint mask_reset, uint reg_clock, uint mask_clock);
extern int rtk_plat_boot_go(bootm_headers_t *images);

extern unsigned int mcp_dscpt_addr;
extern const unsigned int Kh_key_default[4];

int rtk_plat_prepare_fw_image_from_NAND(void);
int rtk_plat_prepare_fw_image_from_eMMC(void);
char *rtk_plat_prepare_fw_image_from_USB(int fw_type);
int rtk_plat_do_boot_linux(void);
int rtk_plat_boot_handler(void);
static int rtk_call_bootm(void);
int decrypt_image(char *src, char *dst, uint length, uint *key);
int rtk_get_secure_boot_type(void);
void rtk_hexdump( const char * str, unsigned char * pcBuf, unsigned int length );

static void reset_shared_memory(void);


static unsigned long do_go_kernel_image(void)
{
    int ret = RTK_PLAT_ERR_OK;

#ifdef CONFIG_SYS_RTK_NAND_FLASH
	ret = rtk_plat_prepare_fw_image_from_NAND();	
#elif defined(CONFIG_SYS_RTK_EMMC_FLASH)
	ret = rtk_plat_prepare_fw_image_from_eMMC();
#endif
	if (ret!= RTK_PLAT_ERR_OK)
		return ret;

	return rtk_plat_do_boot_linux();
}

static unsigned long do_go_audio_fw(void)
{
	printf("Start Audio Firmware ...\n");

	reset_shared_memory();

	*AudioFW_entry_ptr = SWAPEND32(MIPS_AUDIO_FW_ENTRY_ADDR | MIPS_KSEG0BASE);

	flush_dcache_all();

	/* Enable ACPU */
	rtd_setbits(CLOCK_ENABLE2_reg,_BIT4);

	return 0;
}

static unsigned long do_go_all_fw(void)
{
	
	int ret = RTK_PLAT_ERR_OK;

	if (run_command("go a", 0) != 0) {
		printf("go a failed!\n");
		return RTK_PLAT_ERR_BOOT;
	}
	
	if (run_command("go k", 0) != 0) {
		printf("go k failed!\n");
		return RTK_PLAT_ERR_BOOT;
	}

	return ret;
}
#endif 

#ifdef CONFIG_RESCUE_FROM_USB
int rtk_decrypt_rescue_from_usb(char* filename, unsigned int target)
{
	char tmpbuf[128];
	unsigned char ks[16],kh[16],kimg[16];
#ifdef CONFIG_CMD_KEY_BURNING
	unsigned int * Kh_key_ptr = NULL; 
#else
	unsigned int * Kh_key_ptr = Kh_key_default; 
#endif
	unsigned int img_truncated_size = RSA_SIGNATURE_LENGTH; // install_a will append 256-byte signature data to it
	int ret;
	unsigned int image_size=0;
	
	extern unsigned int mcp_dscpt_addr;
	mcp_dscpt_addr = 0;
	
	
	sprintf(tmpbuf, "fatload usb 0:1 %x %s",ENCRYPTED_FW_ADDR,filename);	
	if (run_command(tmpbuf, 0) != 0) {
			return RTK_PLAT_ERR_READ_FW_IMG;
	}
			
	image_size = getenv_ulong("filesize", 16, 0);
	
	memset(ks,0x00,16);
	memset(kh,0x00,16);
	memset(kimg,0x00,16);

#ifdef CONFIG_CMD_KEY_BURNING
	OTP_Get_Byte(OTP_K_S, ks, 16);
	OTP_Get_Byte(OTP_K_H, kh, 16);
	sync();
	flush_cache((unsigned int) ks, 16);
	flush_cache((unsigned int) kh, 16);
#endif
	AES_ECB_encrypt(ks, 16, kimg, kh);
	flush_cache((unsigned int) kimg, 16);
	sync();
	
	Kh_key_ptr = kimg;    
	Kh_key_ptr[0] = swap_endian(Kh_key_ptr[0]);
	Kh_key_ptr[1] = swap_endian(Kh_key_ptr[1]);
	Kh_key_ptr[2] = swap_endian(Kh_key_ptr[2]);
	Kh_key_ptr[3] = swap_endian(Kh_key_ptr[3]);
	flush_cache((unsigned int) kimg, 16);
								
		// decrypt image
	printf("to decrypt...\n");						
	flush_cache((unsigned int) ENCRYPTED_FW_ADDR, image_size);
	if (decrypt_image((char *)ENCRYPTED_FW_ADDR,
		(char *)target,
		image_size,
		Kh_key_ptr))
	{
		printf("decrypt image:%s error!\n", filename);
		return RTK_PLAT_ERR_READ_FW_IMG;
	}
	
	sync();
	memset(ks,0x00,16);
	memset(kh,0x00,16);
	memset(kimg,0x00,16);
		

	flush_cache((unsigned int) target, image_size);
	ret = Verify_SHA256_hash( (unsigned char *)target,
							image_size - img_truncated_size,
							(unsigned char *)(target + image_size - img_truncated_size),
							1 );						  
	if( ret < 0 ) {
		printf("[ERR] %s: verify hash fail(%d)\n", __FUNCTION__, ret );
		return RTK_PLAT_ERR_READ_FW_IMG;
	}
	
	return RTK_PLAT_ERR_OK;
}

int boot_rescue_from_usb(void)
{
	char tmpbuf[128];
	int ret = RTK_PLAT_ERR_OK;
	char *filename;
	unsigned int secure_mode=0;
	
	secure_mode = rtk_get_secure_boot_type();

	run_command("usb start", 0);	/* "usb start" always return 0 */
	if (run_command("usb dev", 0) != 0) {
		printf("No USB device found!\n");
		return RTK_PLAT_ERR_READ_RESCUE_IMG;
	}

	/* DTB */	
	if ((filename = getenv("rescue_dtb")) == NULL) {
		filename =(char*) CONFIG_RESCUE_FROM_USB_DTB;
	}	
	sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("fdt_loadaddr"), filename);
	if (run_command(tmpbuf, 0) != 0) {
		goto loading_failed;
	}

	printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("fdt_loadaddr"));

	/* Linux kernel */
	if ((filename = getenv("rescue_vmlinux")) == NULL) {
		filename =(char*) CONFIG_RESCUE_FROM_USB_VMLINUX;
	}
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (rtk_decrypt_rescue_from_usb(filename,getenv_ulong("kernel_loadaddr", 16, 0)))
		goto loading_failed;	
	}	
	else
	{	
		sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("kernel_loadaddr"), filename);
		if (run_command(tmpbuf, 0) != 0) {
			goto loading_failed;
		}
	}

	printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("kernel_loadaddr"));

	/* rootfs */
	if ((filename = getenv("rescue_rootfs")) == NULL) {
		filename =(char*) CONFIG_RESCUE_FROM_USB_ROOTFS;
	}
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (rtk_decrypt_rescue_from_usb(filename, getenv_ulong("rootfs_loadaddr", 16, 0)))
		goto loading_failed;	
	}	
	else
	{
		sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("rootfs_loadaddr"), filename);
		if (run_command(tmpbuf, 0) != 0) {
			goto loading_failed;
		}
	}

	printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("rootfs_loadaddr"));

	/* audio firmware */
	if ((filename = getenv("rescue_audio")) == NULL) {
		filename =(char*) CONFIG_RESCUE_FROM_USB_AUDIO_CORE;
	}
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (!rtk_decrypt_rescue_from_usb(filename, MIPS_AUDIO_FW_ENTRY_ADDR))
		{
			printf("Loading \"%s\" to 0x%08x is OK.\n", filename, MIPS_AUDIO_FW_ENTRY_ADDR);
			run_command("go a", 0);
		}
		else
			printf("Loading \"%s\" from USB failed.\n", filename);
			/* Go on without Audio firmware. */	
	}	
	else
	{	
		sprintf(tmpbuf, "fatload usb 0:1 0x%08x %s", MIPS_AUDIO_FW_ENTRY_ADDR, filename);
		if (run_command(tmpbuf, 0) == 0) {
			printf("Loading \"%s\" to 0x%08x is OK.\n", filename, MIPS_AUDIO_FW_ENTRY_ADDR);
			run_command("go a", 0);
		}
		else {
			printf("Loading \"%s\" from USB failed.\n", filename);
			/* Go on without Audio firmware. */
		}
    }
	boot_mode = BOOT_RESCUE_MODE;
	ret = rtk_call_bootm();
	/* Should not reach here */

	return ret;

loading_failed:
	printf("Loading \"%s\" from USB failed.\n", filename);
	return RTK_PLAT_ERR_READ_RESCUE_IMG;	
}
#endif	 /* CONFIG_RESCUE_FROM_USB */

/* Allow ports to override the default behavior */
__attribute__((weak))
unsigned long do_go_exec (ulong (*entry)(int, char * const []), int argc, char * const argv[])
{
	return entry (argc, argv);
}

int do_go (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ulong	addr, rc;
	int     rcode = 0;
	int     do_cleanup = 0;

	if (argc < 2)
		return CMD_RET_USAGE;

#if defined(CONFIG_RTD299X) || defined(CONFIG_RTD1195)
	if (argv[1][0] == 'a')
	{
		if (argv[1][1] == '\0')	// audio fw
		{
			return do_go_audio_fw();
		}
		else if (argv[1][1] == 'l' && argv[1][2] == 'l')	// all fw
		{
			return do_go_all_fw();
		}
		else
		{
			printf("Unknown command '%s'\n", argv[1]);
			return CMD_RET_USAGE;
		}
	}
	else if (argv[1][0] == 'k')
	{
		if (argv[1][1] == '\0')	// getkernel image from ddr;
		{
			return rtk_plat_do_boot_linux();
		}
		else if (argv[1][1] == 'f')	// get kernel image from flash;
		{
			boot_mode = BOOT_KERNEL_ONLY_MODE;
			return do_go_kernel_image();
		}
		else
		{
			printf("Unknown command '%s'\n", argv[1]);
			return CMD_RET_USAGE;
		}

	}
	else if (argv[1][0] == 'r')
	{
		if (argv[1][1] == '\0') // rescue from flash
		{			
			boot_mode = BOOT_RESCUE_MODE;
			return rtk_plat_boot_handler();			
		}
		else if (argv[1][1] == 'a') // rescue for android
		{
			boot_mode = BOOT_ANDROID_MODE;
			return rtk_plat_boot_handler();					
		}
#ifdef CONFIG_RESCUE_FROM_USB
		else if (argv[1][1] == 'u') // rescue from usb
		{
			return boot_rescue_from_usb();
		}
#endif
		else
		{
			return 0;
		}
	}
#endif

	addr = simple_strtoul(argv[1], NULL, 16);

#ifdef CONFIG_CLEAR_ENV_AFTER_UPDATE_BOOTCODE
	if (addr == DVRBOOT_EXE_BIN_ENTRY_ADDR)
	{
		printf ("Clear env when updating bootcode ...\n");
		delete_env();
	}
#endif

	printf ("Starting application at 0x%08lX ...\n", addr);

	if( strncmp( argv[2], "nocache", 7 ) == 0 ) {
		do_cleanup = 1;
		printf ("Run application w/o any cache\n");
		cleanup_before_dvrbootexe();
	}

	/*
	 * pass address parameter as argv[0] (aka command name),
	 * and all remaining args
	 */
	rc = do_go_exec ((void *)addr, argc - 1 - do_cleanup, argv + 1 + do_cleanup);
	if (rc != 0) rcode = 1;

	printf ("Application terminated, rc = 0x%lX\n", rc);
	return rcode;
}

/* -------------------------------------------------------------------- */

U_BOOT_CMD(
	go, CONFIG_SYS_MAXARGS, 1,	do_go,
	"start application at address 'addr' or start running fw",
	"[addr/a/v/v1/v2/k] [arg ...]\n"
	"\taddr  - start application at address 'addr'\n"
	"\ta     - start audio firmware\n"
	"\tk     - start kernel\n"
	"\tr     - start rescue linux\n"
#ifdef CONFIG_RESCUE_FROM_USB
	"\tru    - start rescue linux from usb\n"
#endif
	"\tall   - start all firmware\n"
	"\t[arg] - passing 'arg' as arguments\n"
);

#endif

U_BOOT_CMD(
	reset, 1, 0,	do_reset,
	"Perform RESET of the CPU",
	""
);

uint get_checksum(uchar *p, uint len) {
	uint checksum = 0;
	uint i;

	for(i = 0; i < len; i++) {
		checksum += *(p+i);

		if (i % 0x200000 == 0)
		{
			EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here
		}
	}
	return checksum;
}


uint get_mem_layout_when_read_image(MEM_LAYOUT_WHEN_READ_IMAGE_T *mem_layout)
{
	if (mem_layout->image_target_addr == 0)
	{
		printf("[ERROR] mem_layout->image_target_addr = 0x%08x\n", mem_layout->image_target_addr);

		return 1;
	}

	if (mem_layout->bIsEncrypted)
	{
#ifdef CONFIG_SYS_RTK_NAND_FLASH
		mem_layout->flash_to_ram_addr = mem_layout->image_target_addr;
#else		
		mem_layout->flash_to_ram_addr = mem_layout->encrpyted_addr = ENCRYPTED_FW_ADDR;
#endif
		if (mem_layout->bIsCompressed)
		{
			mem_layout->decrypted_addr = mem_layout->compressed_addr = COMPRESSED_FW_IMAGE_ADDR;
			mem_layout->decompressed_addr = mem_layout->image_target_addr;
		}
		else
		{
			mem_layout->decrypted_addr = mem_layout->image_target_addr;
		}
	}
	else
	{
		if (mem_layout->bIsCompressed)
		{
			mem_layout->flash_to_ram_addr = mem_layout->compressed_addr = COMPRESSED_FW_IMAGE_ADDR;
			mem_layout->decompressed_addr = mem_layout->image_target_addr;
		}
		else
		{
			mem_layout->flash_to_ram_addr = mem_layout->image_target_addr;
		}
	}

	return 0;
}

int decrypt_image(char *src, char *dst, uint length, uint *key)
{
	int i;
	uint sblock_len;
	uchar *sblock_dst, *sblock_src;

	printf("decrypt from 0x%08x to 0x%08x, len:0x%08x\n", (uint)src, (uint)dst, length);

	// get short block size
	sblock_len = length & 0xf;

	if (AES_CBC_decrypt((uchar *)src, length - sblock_len, (uchar *)dst, key)) {
		printf("%s %d, fail\n", __FUNCTION__, __LINE__);
		return -1;
	}

	// handle short block (<16B)
	if (sblock_len) {
		// take the last 16B of AES CBC result as input, do AES ECB encrypt
		sblock_src = (uchar *)src + (length - sblock_len);
		sblock_dst = (uchar *)dst + (length - sblock_len);
		//printf("sblock_src: 0x%p, sblock_dst: 0x%p\n", sblock_src, sblock_dst);
		if (AES_ECB_encrypt((UINT8 *)(sblock_src - 16), 16, sblock_dst, key)) {
			printf("%s %d, fail\n", __FUNCTION__, __LINE__);
			return -1;
		}

		// XOR with short block data to generate final result
		for (i = 0; i < sblock_len; i++)
			sblock_dst[i] ^= sblock_src[i];
	}

	return 0;
}

//#define DUBUG_FW_DESC_TABLE
#ifdef DUBUG_FW_DESC_TABLE
void dump_fw_desc_table_v1(fw_desc_table_v1_t *fw_desc_table_v1)
{
	if (fw_desc_table_v1 != NULL) {
		printf("## Fw Desc Table ##############################\n");
		printf("## fw_desc_table_v1                = 0x%08x\n", fw_desc_table_v1);
		printf("## fw_desc_table_v1->signature     = %s\n", fw_desc_table_v1->signature);
		printf("## fw_desc_table_v1->checksum      = 0x%08x\n", fw_desc_table_v1->checksum);
		printf("## fw_desc_table_v1->version       = 0x%08x\n", fw_desc_table_v1->version);
		printf("## fw_desc_table_v1->paddings      = 0x%08x\n", fw_desc_table_v1->paddings);
		printf("## fw_desc_table_v1->part_list_len = 0x%08x\n", fw_desc_table_v1->part_list_len);
		printf("## fw_desc_table_v1->fw_list_len   = 0x%08x\n", fw_desc_table_v1->fw_list_len);
		printf("###############################################\n\n");
	}
	else {
		printf("[ERR] %s:%d fw_desc_table_v1 is NULL.\n", __FUNCTION__, __LINE__);
	}
}

void dump_part_desc_entry_v1(part_desc_entry_v1_t *part_entry)
{
	if (part_entry != NULL) {
		printf("## Part Desc Entry ############################\n");
		printf("## part_entry                      = 0x%08x\n", part_entry);
		printf("## part_entry->type                = 0x%08x\n", part_entry->type);
		printf("## part_entry->ro                  = 0x%08x\n", part_entry->ro);
		printf("## part_entry->length              = ");
		printn(part_entry->length,16);
		printf("\n");
		printf("## part_entry->fw_count            = 0x%08x\n", part_entry->fw_count);
		printf("## part_entry->fw_type             = 0x%08x\n", part_entry->fw_type);
		printf("###############################################\n\n");
	}
	else {
		printf("[ERR] %s:%d part_entry is NULL.\n", __FUNCTION__, __LINE__);
	}
}

void dump_fw_desc_entry_v1(fw_desc_entry_v1_t *fw_entry)
{
	if (fw_entry != NULL) {
		printf("## Fw Desc Entry ##############################\n");
		printf("## fw_entry                        = 0x%08x\n", fw_entry);
		printf("## fw_entry->type                  = 0x%08x\n", fw_entry->type);
		printf("## fw_entry->lzma                  = 0x%08x\n", fw_entry->lzma);
		printf("## fw_entry->ro                    = 0x%08x\n", fw_entry->ro);
		printf("## fw_entry->version               = 0x%08x\n", fw_entry->version);
		printf("## fw_entry->target_addr           = 0x%08x\n", fw_entry->target_addr);
		printf("## fw_entry->offset                = 0x%08x\n", fw_entry->offset);
		printf("## fw_entry->length                = 0x%08x\n", fw_entry->length);
		printf("## fw_entry->paddings              = 0x%08x\n", fw_entry->paddings);
		printf("## fw_entry->checksum              = 0x%08x\n", fw_entry->checksum);
		printf("###############################################\n\n");
	}
	else {
		printf("[ERR] %s:%d fw_entry is NULL.\n", __FUNCTION__, __LINE__);
	}
}
#endif

//#define DUBUG_BOOT_AV_INFO
#ifdef DUBUG_BOOT_AV_INFO
void dump_boot_av_info(boot_av_info_t *boot_av)
{
	if (boot_av != NULL) {
		printf("\n");
		printf("## Boot AV Info (0x%08x) ##################\n", boot_av);
		printf("## boot_av->dwMagicNumber          = 0x%08x\n", boot_av->dwMagicNumber);
		printf("## boot_av->dwVideoStreamAddress   = 0x%08x\n", boot_av->dwVideoStreamAddress);
		printf("## boot_av->dwVideoStreamLength    = 0x%08x\n", boot_av->dwVideoStreamLength);
		printf("## boot_av->dwAudioStreamAddress   = 0x%08x\n", boot_av->dwAudioStreamAddress);
		printf("## boot_av->dwAudioStreamLength    = 0x%08x\n", boot_av->dwAudioStreamLength);
		printf("## boot_av->bVideoDone             = 0x%08x\n", boot_av->bVideoDone);
		printf("## boot_av->bAudioDone             = 0x%08x\n", boot_av->bAudioDone);
		printf("## boot_av->bHDMImode              = 0x%08x\n", boot_av->bHDMImode);
		printf("## boot_av->dwAudioStreamVolume    = 0x%08x\n", boot_av->dwAudioStreamVolume);
		printf("## boot_av->dwAudioStreamRepeat    = 0x%08x\n", boot_av->dwAudioStreamRepeat);
		printf("## boot_av->bPowerOnImage          = 0x%08x\n", boot_av->bPowerOnImage);
		printf("## boot_av->bRotate                = 0x%08x\n", boot_av->bRotate);
		printf("## boot_av->dwVideoStreamType      = 0x%08x\n", boot_av->dwVideoStreamType);
		printf("## boot_av->audio_buffer_addr      = 0x%08x\n", boot_av->audio_buffer_addr);
		printf("## boot_av->audio_buffer_size      = 0x%08x\n", boot_av->audio_buffer_size);
		printf("## boot_av->video_buffer_addr      = 0x%08x\n", boot_av->video_buffer_addr);
		printf("## boot_av->video_buffer_size      = 0x%08x\n", boot_av->video_buffer_size);
		printf("## boot_av->last_image_addr        = 0x%08x\n", boot_av->last_image_addr);
		printf("## boot_av->last_image_size        = 0x%08x\n", boot_av->last_image_size);
		printf("###############################################\n\n");
	}
}
#endif

static void reset_shared_memory(void)
{
	boot_av_info_t *boot_av;

	*uart_reg_base_ptr = 0;
	*boot_av_info_ptr = 0;
	*AudioFlag_ptr = 0;
	*AudioFW_entry_ptr = 0;
	memset(shared_printk_buffer_ptr, 0, MIPS_SHARED_PRINTK_BUFFER_SIZE);

	/* clear boot_av_info memory */
	boot_av = (boot_av_info_t *) MIPS_BOOT_AV_INFO_ADDR;
	memset(boot_av, 0, sizeof(boot_av_info_t));
}

/*
 * read Efuse.
 */
int rtk_get_secure_boot_type(void)
{
#ifdef CONFIG_CMD_KEY_BURNING
	if(OTP_JUDGE_BIT(OTP_BIT_SECUREBOOT))
		return RTK_SECURE_BOOT;
#endif	
	//return RTK_SECURE_BOOT;
	return NONE_SECURE_BOOT;
}


/*
 * Support boot from NAND or eMMC on squashfs/ext4 partition.
 */
#ifdef NAS_ENABLE
#define NAS_ROOT "/"
#define NAS_ETC "etc"
int rtk_plat_set_boot_flag_from_part_desc(
        part_desc_entry_v1_t* part_entry, int part_count)
{
    if(boot_mode == BOOT_RESCUE_MODE)
        return RTK_PLAT_ERR_OK;

    int major_num = -1;
    if (BOOT_EMMC == boot_flash_type)
        major_num = 179;
    else if (BOOT_NAND == boot_flash_type)
        major_num = 31;

    if (major_num < 0)
        return RTK_PLAT_ERR_BOOT;

    char *tmp_cmdline = NULL;
    tmp_cmdline = (char*)malloc(64);
    if (!tmp_cmdline) {
        printf("%s: Malloc failed\n", __func__);
        return RTK_PLAT_ERR_BOOT;
    }
    memset(tmp_cmdline, 0, 64);

    unsigned char empty_mount[sizeof(part_entry->mount_point)];
    memset(empty_mount, 0, sizeof(empty_mount));

    int i;
    for(i = 0; i < part_count; i++) {
        if (memcmp(empty_mount, part_entry[i].mount_point, sizeof(empty_mount)) != 0) {
            if (0 == strcmp(part_entry[i].mount_point, NAS_ROOT)){
                int minor_num = i;
                if (i >= 3 && BOOT_EMMC == boot_flash_type)
                    minor_num += 1;

                int cmd_len = strlen(tmp_cmdline);
                char *rootfstype = "";
                char *opts = "";
                switch (part_entry[i].fw_type)
                {
                    case FS_TYPE_SQUASH:
                        rootfstype = "squashfs";
                        break;
                    case FS_TYPE_EXT4:
                        rootfstype = "ext4";
                        opts = " ro";
                        break;
                    case FS_TYPE_UBIFS:
                        rootfstype = "ubifs";
                        opts = " rw rootwait ubi.mtd=/";
                        break;
                    default:
                        free(tmp_cmdline);
                        return RTK_PLAT_ERR_PARSE_FW_DESC;
                }

                if(FS_TYPE_UBIFS == part_entry[i].fw_type){
                snprintf(tmp_cmdline+cmd_len, 63-cmd_len,
                        "root=ubi0:rootfs%s rootfstype=%s ",
                        opts,rootfstype);
                }
                else{
                    snprintf(tmp_cmdline+cmd_len, 63-cmd_len,
                            "root=%d:%02d%s rootfstype=%s ",
                            major_num,minor_num,opts,rootfstype);
                }
                debug("NASROOT found. cmd:%s\n", tmp_cmdline);
            }
            else if (0 == strcmp(part_entry[i].mount_point, NAS_ETC)
                    && FS_TYPE_UBIFS == part_entry[i].fw_type){
                int cmd_len = strlen(tmp_cmdline);
                snprintf(tmp_cmdline+cmd_len, 63-cmd_len,
                        "ubi.mtd=etc ");
                debug("NASETC found. cmd:%s\n", tmp_cmdline);
            }
        }
    }
    setenv("nas_part", tmp_cmdline);
    free(tmp_cmdline);

    return RTK_PLAT_ERR_OK;
}
#endif

/*
 * Use firmware description table to read images from usb.
 */
int rtk_plat_read_fw_image_from_USB(int skip)
{
#ifdef CONFIG_BOOT_FROM_USB 
	char tmpbuf[128];
	int ret = RTK_PLAT_ERR_OK;
	char *filename;
	unsigned int secure_mode=0;
	
	secure_mode = rtk_get_secure_boot_type();

	run_command("usb start", 0);	/* "usb start" always return 0 */
	if (run_command("usb dev", 0) != 0) {
		printf("No USB device found!\n");
		return RTK_PLAT_ERR_READ_RESCUE_IMG;
	}
		
	if(!skip) /* dtb */
	{		
		if(boot_mode == BOOT_RESCUE_MODE || boot_mode == BOOT_ANDROID_MODE)
			filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_RESCUE_DT);
		else
			filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_KERNEL_DT);
		if(secure_mode == RTK_SECURE_BOOT)
		{	
			if (rtk_decrypt_rescue_from_usb(filename, getenv_ulong("fdt_loadaddr", 16, 0)))
			goto loading_failed;	
		}	
		else
		{
			sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("fdt_loadaddr"), filename);
			if (run_command(tmpbuf, 0) != 0) {
				goto loading_failed;
			}
		}	
		
		printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("fdt_loadaddr"));
	}

	/* Linux kernel */
	filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_KERNEL);
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (rtk_decrypt_rescue_from_usb(filename,getenv_ulong("kernel_loadaddr", 16, 0)))
		goto loading_failed;	
	}	
	else
	{	
		sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("kernel_loadaddr"), filename);
		if (run_command(tmpbuf, 0) != 0) {
			goto loading_failed;
		}
	}

	printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("kernel_loadaddr"));

	/* rootfs */
	if(boot_mode == BOOT_RESCUE_MODE || boot_mode == BOOT_ANDROID_MODE)
		filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_RESCUE_ROOTFS);
	else
#ifdef NAS_ENABLE
	{
		filename = "nas_uuid";
		/* Use the second partition of HDD as root partition */
		if (run_command("usb uuid 0 2", 0) != 0) {
		//setenv("nas_part", "root=/dev/sda2 rootfstype=ext4 rootwait rw ");
			printf("Failed to find NAS boot partition UUID!\n\n");
			goto loading_failed;
		}
		else{
			sprintf(tmpbuf, "root=PARTUUID=%s rootfstype=ext4 rootwait rw ", getenv("nas_boot_uuid"));
			setenv("nas_part", tmpbuf);
		}
	}
#else
		/* No initrd on NAS normal boot */
		filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_KERNEL_ROOTFS);
#endif
#ifdef NAS_ENABLE
	if(strncmp(filename, "nas_uuid", 9))
#endif
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (rtk_decrypt_rescue_from_usb(filename, getenv_ulong("rootfs_loadaddr", 16, 0)))
		goto loading_failed;	
	}	
	else
	{
		sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("rootfs_loadaddr"), filename);
		if (run_command(tmpbuf, 0) != 0) {
			goto loading_failed;
		}
	}

	printf("Loading \"%s\" to %s is OK.\n\n", filename, getenv("rootfs_loadaddr"));

	/* audio firmware */
	filename = rtk_plat_prepare_fw_image_from_USB(FW_TYPE_AUDIO);
	if(secure_mode == RTK_SECURE_BOOT)
	{	
		if (!rtk_decrypt_rescue_from_usb(filename, MIPS_AUDIO_FW_ENTRY_ADDR))
		{
			printf("Loading \"%s\" to 0x%08x is OK.\n", filename, MIPS_AUDIO_FW_ENTRY_ADDR);
			run_command("go a", 0);
		}
		else
			printf("Loading \"%s\" from USB failed.\n", filename);
			/* Go on without Audio firmware. */	
	}	
	else
	{	
		sprintf(tmpbuf, "fatload usb 0:1 0x%08x %s", MIPS_AUDIO_FW_ENTRY_ADDR, filename);
		if (run_command(tmpbuf, 0) == 0) {
			printf("Loading \"%s\" to 0x%08x is OK.\n", filename, MIPS_AUDIO_FW_ENTRY_ADDR);
			run_command("go a", 0);
		}
		else {
			printf("Loading \"%s\" from USB failed.\n", filename);
			/* Go on without Audio firmware. */
		}
    }	
	ret = rtk_call_bootm();
	/* Should not reach here */

	return ret;

loading_failed:
	printf("Loading \"%s\" from USB failed.\n", filename);
	return RTK_PLAT_ERR_READ_RESCUE_IMG;
	
#endif

	return RTK_PLAT_ERR_OK;
}


int rtk_plat_get_dtb_target_address(int dtb_address)
{
	if( (CONFIG_FDT_LOADADDR<= dtb_address) && (dtb_address < CONFIG_LOGO_LOADADDR))	
		return dtb_address;
	else
		{
			printf("original DT address=%x\n",dtb_address);
			return CONFIG_FDT_LOADADDR;
		}
}

/*
 * Use firmware description table to read images from eMMC flash.
 */
int rtk_plat_read_fw_image_from_eMMC(
		uint fw_desc_table_base, part_desc_entry_v1_t* part_entry, int part_count,
		void* fw_entry, int fw_count,
		uchar version)
{
#ifdef CONFIG_SYS_RTK_EMMC_FLASH
#ifdef NAS_ENABLE
	rtk_plat_set_boot_flag_from_part_desc(part_entry, part_count);
#endif
	fw_desc_entry_v1_t *this_entry;
	fw_desc_entry_v11_t *v11_entry;
	fw_desc_entry_v21_t *v21_entry;
	int i;
	uint unit_len;
	char buf[64];
	uint fw_checksum = 0;
#if 0 // mark secure boot
	char str_phash[256];
#if defined(Config_Secure_RSA_TRUE)
	char *checksum, *signature;
#endif
	char sha1_hash[SHA1_SIZE];
	char *hash_str;
#endif
	unsigned int secure_mode;
	unsigned char ks[16],kh[16],kimg[16];
#ifdef CONFIG_CMD_KEY_BURNING
	unsigned int * Kh_key_ptr = NULL; 
#else
	unsigned int * Kh_key_ptr = Kh_key_default; 
#endif
	unsigned int img_truncated_size; // install_a will append 256-byte signature data to it
	int ret;
	boot_av_info_t *boot_av;
//	uint source_addr;
//	uint target_addr;
	uint block_no;
	MEM_LAYOUT_WHEN_READ_IMAGE_T mem_layout;
	uint imageSize = 0;
	uint decompressedSize = 0;

	// extern variable
	extern unsigned int mcp_dscpt_addr;
	mcp_dscpt_addr = 0;

	secure_mode = rtk_get_secure_boot_type();
	img_truncated_size = RSA_SIGNATURE_LENGTH;
	
	unsigned char str[16];// old array size is 5, change to 16. To avoid the risk in memory overlap.

	/* find fw_entry structure according to version */
	switch (version)
	{
		case FW_DESC_TABLE_V1_T_VERSION_1:
			unit_len = sizeof(fw_desc_entry_v1_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_11:
			unit_len = sizeof(fw_desc_entry_v11_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_21:
			unit_len = sizeof(fw_desc_entry_v21_t);
			break;

		default:
			return RTK_PLAT_ERR_READ_FW_IMG;
	}

#if 0 // mark secure boot
#if defined(Config_Secure_RSA_TRUE)
	checksum = (char *)alloc_freemem(sizeof(v21_entry->RSA_sign));
	signature = (char *)alloc_freemem(sizeof(v21_entry->RSA_sign)+1);

	// set RSA key to env variable
	if (env_split_and_save("RSA_KEY_MODULUS", Config_Secure_RSA_MODULUS, 96) != OK)
		return NULL;
#endif


	if (secure_mode == RTK_SECURE_BOOT)
	{
		// set AES img key to env variable
		setenv( "AES_IMG_KEY", SECURE_KH_KEY_STR);
	}

	//	memset(str_phash, 0, 256);
#endif
	/* clear boot_av_info memory */
	boot_av = (boot_av_info_t *) MIPS_BOOT_AV_INFO_ADDR;
	memset(boot_av, 0, sizeof(boot_av_info_t));
	
	/* parse each fw_entry */
	for (i = 0; i < fw_count; i++)
	{
		EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

		this_entry = (fw_desc_entry_v1_t *)(fw_entry + unit_len * i);

				/* parse each fw_entry */
	for (i = 0; i < fw_count; i++)
	{
		EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

		this_entry = (fw_desc_entry_v1_t *)(fw_entry + unit_len * i);

		if (this_entry->target_addr)
		{
			if (boot_mode == BOOT_RESCUE_MODE || boot_mode == BOOT_ANDROID_MODE)
			{
				switch(this_entry->type)
				{
					case FW_TYPE_KERNEL:
						//kernel_entry = this_entry;
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("kernel_loadaddr", str);
						printf("Kernel:\n");
						break;

					case FW_TYPE_RESCUE_DT:
						this_entry->target_addr = rtk_plat_get_dtb_target_address(this_entry->target_addr);
						//printf("this_entry->target_addr =%x\n",this_entry->target_addr);
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("fdt_loadaddr", str);
						printf("Rescue DT:\n");
						break;

					case FW_TYPE_RESCUE_ROOTFS:
						printf("Rescue ROOTFS:\n");
						break;

					case FW_TYPE_TEE:
#ifdef CONFIG_TEE
						printf("TEE:\n");
						tee_enable=1;
						break;
#else
						continue;
#endif
					case FW_TYPE_AUDIO:
						if(boot_mode == BOOT_KERNEL_ONLY_MODE)
							continue;
						else
						{
							*AudioFW_entry_ptr = CPU_TO_BE32(this_entry->target_addr | MIPS_KSEG0BASE);
							printf("Audio FW:\n");
						}	
						break;

					default:
						//printf("Unknown FW (%d):\n", this_entry->type);
						continue;
				}
			}
			else
			{
				switch(this_entry->type)
				{
					case FW_TYPE_BOOTCODE:
						printf("Boot Code:\n");
						break;

					case FW_TYPE_KERNEL:
						//kernel_entry = this_entry;
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("kernel_loadaddr", str);
						printf("Kernel:\n");
						break;

					case FW_TYPE_KERNEL_DT:					
						this_entry->target_addr = rtk_plat_get_dtb_target_address(this_entry->target_addr);
						//printf("this_entry->target_addr =%x\n",this_entry->target_addr);
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("fdt_loadaddr", str);				
						printf("DT:\n");
						break;

					case FW_TYPE_KERNEL_ROOTFS:
						printf("ROOTFS:\n");
						break;

					case FW_TYPE_TEE:
#ifdef CONFIG_TEE						
						printf("TEE:\n");
						tee_enable=1;
						break;
#else
						continue;
#endif
					
					case FW_TYPE_AUDIO:
						if(boot_mode == BOOT_KERNEL_ONLY_MODE)
							continue;
						else
						{
							*AudioFW_entry_ptr = CPU_TO_BE32(this_entry->target_addr  | MIPS_KSEG0BASE );
							printf("Audio FW:\n");
						}
						break;

					case FW_TYPE_JFFS2:
						printf("JFFS2 Image:\n");
						break;

					case FW_TYPE_SQUASH:
						printf("Squash Image:\n");
						break;

					case FW_TYPE_EXT3:
						printf("EXT3 Image:\n");
						break;

					case FW_TYPE_ODD:
						printf("ODD Image:\n");
						break;

					case FW_TYPE_YAFFS2:
						printf("YAFFS2 Image:\n");
						break;

					case FW_TYPE_AUDIO_FILE:
						//this_entry->target_addr = (POWER_ON_MUSIC_STREAM_ADDR | MIPS_KSEG0BASE);

						/* if enable boot music, need to assign boot_av structure */
						//boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						//boot_av->dwAudioStreamAddress = SWAPEND32(this_entry->target_addr);
						//boot_av->dwAudioStreamLength = SWAPEND32(this_entry->length);
						//boot_av->dwAudioStreamVolume = (-17);
						break;

					case FW_TYPE_VIDEO_FILE:

						/* if enable boot video/jpeg, need to assign boot_av structure */
						//boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						//boot_av->dwVideoStreamAddress = SWAPEND32(this_entry->target_addr);
						//boot_av->bPowerOnImage = 0;
						//boot_av->dwVideoStreamLength = SWAPEND32(this_entry->length);
						break;

					case FW_TYPE_IMAGE_FILE:
						printf("IMAGE FILE:\n");

						/* assign boot_av structure */
						boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						if(boot_logo_enable)
						{
							boot_av-> logo_enable = boot_logo_enable;
							boot_av-> logo_addr = CPU_TO_BE32(this_entry->target_addr);
							boot_av-> src_width = CPU_TO_BE32(custom_logo_src_width);
							boot_av-> src_height = CPU_TO_BE32(custom_logo_src_height);
							boot_av-> dst_width = CPU_TO_BE32(custom_logo_dst_width);
							boot_av-> dst_height = CPU_TO_BE32(custom_logo_dst_height);
						}

						break;

					default:
						//printf("Unknown FW (%d):\n", this_entry->type);
						continue;
				}
			}
			printf("\t FW Image to 0x%08x, size=0x%08x, 0x%x blocks (0x%08x)\n", this_entry->target_addr, 
																				 this_entry->length, 
																				(this_entry->length%EMMC_BLOCK_SIZE)?(this_entry->length/EMMC_BLOCK_SIZE)+1:(this_entry->length/EMMC_BLOCK_SIZE),
																				 this_entry->target_addr + this_entry->length);

			printf("\t FW Image fr 0x%08x, fr block 0x%x %s\n", eMMC_fw_desc_table_start + this_entry->offset,
															    (eMMC_fw_desc_table_start + this_entry->offset)/EMMC_BLOCK_SIZE,
															    this_entry->lzma ? "(lzma)" : "(non-lzma)");

			WATCHDOG_KICK();

				/* secure mode and lzma will only apply to fw image */
				if (this_entry->type == FW_TYPE_KERNEL ||
					this_entry->type == FW_TYPE_KERNEL_ROOTFS ||
					this_entry->type == FW_TYPE_RESCUE_ROOTFS ||
					this_entry->type == FW_TYPE_AUDIO )
				{
					/* get memory layout before copy fw image */
					mem_layout.bIsEncrypted = (secure_mode != NONE_SECURE_BOOT);
					mem_layout.bIsCompressed = this_entry->lzma;
					mem_layout.image_target_addr = this_entry->target_addr & (~MIPS_KSEG_MSK);
				}
				else
				{
					/* get memory layout before copy other image */
					mem_layout.bIsEncrypted = 0;
					mem_layout.bIsCompressed = 0;
					mem_layout.image_target_addr = this_entry->target_addr & (~MIPS_KSEG_MSK);
				}

				get_mem_layout_when_read_image(&mem_layout);

				imageSize = this_entry->length;

				// 512B aligned
				if (imageSize&(EMMC_BLOCK_SIZE-1)) {
					imageSize &= ~(EMMC_BLOCK_SIZE-1);
					imageSize += EMMC_BLOCK_SIZE;
				}
								
				block_no = (eMMC_fw_desc_table_start + this_entry->offset) / EMMC_BLOCK_SIZE ;
                                
				if (!rtk_eMMC_read(block_no, imageSize, (uint *)mem_layout.flash_to_ram_addr))
				{
					printf("[ERR] Read fw error (type:%d)!\n", this_entry->type);

					return RTK_PLAT_ERR_READ_FW_IMG;
				}
#if 1
				/* Check checksum */
				fw_checksum = get_checksum((uchar *)mem_layout.flash_to_ram_addr, this_entry->length);

				if (this_entry->checksum != fw_checksum && secure_mode!= RTK_SECURE_BOOT)
				{
					printf("\t FW Image checksum FAILED\n");
					printf("\t FW Image entry  checksum=0x%08x\n", this_entry->checksum);
					printf("\t FW Image result checksum=0x%08x\n", fw_checksum);
					return RTK_PLAT_ERR_READ_FW_IMG;
				}
#endif
				/* if secure mode, do AES CBC decrypt */
				if (mem_layout.bIsEncrypted)
				{
					if (secure_mode == RTK_SECURE_BOOT)
					{       
						//rtk_hexdump("the first 32-byte encrypted data", (unsigned char *)mem_layout.encrpyted_addr, 32);
						//rtk_hexdump("the last 512-byte encrypted data", (unsigned char *)(ENCRYPTED_LINUX_KERNEL_ADDR+this_entry->length-512), 512);

                        memset(ks,0x00,16);
                        memset(kh,0x00,16);
                        memset(kimg,0x00,16);

#ifdef CONFIG_CMD_KEY_BURNING
                        OTP_Get_Byte(OTP_K_S, ks, 16);
                        OTP_Get_Byte(OTP_K_H, kh, 16);
                        sync();
						flush_cache((unsigned int) ks, 16);
						flush_cache((unsigned int) kh, 16);
#endif
                        AES_ECB_encrypt(ks, 16, kimg, kh);
						flush_cache((unsigned int) kimg, 16);
                        sync();

                        Kh_key_ptr = kimg;
                        //rtk_hexdump("kimg key : ", (unsigned char *)kimg, 16);
                        Kh_key_ptr[0] = swap_endian(Kh_key_ptr[0]);
                        Kh_key_ptr[1] = swap_endian(Kh_key_ptr[1]);
                        Kh_key_ptr[2] = swap_endian(Kh_key_ptr[2]);
                        Kh_key_ptr[3] = swap_endian(Kh_key_ptr[3]);
                        //rtk_hexdump("Kh_key_ptr : ", (unsigned char *)Kh_key_ptr, 16);
						flush_cache((unsigned int) kimg, 16);
                                                
						// decrypt image
						printf("to decrypt...\n");						
						flush_cache((unsigned int) mem_layout.encrpyted_addr, this_entry->length);
						if (decrypt_image((char *)mem_layout.encrpyted_addr,
							(char *)mem_layout.decrypted_addr,
							this_entry->length,
							Kh_key_ptr))
						{
							printf("decrypt image(%d) error!\n", this_entry->type);
							return RTK_PLAT_ERR_READ_FW_IMG;
						}

						sync();
                        memset(ks,0x00,16);
                        memset(kh,0x00,16);
                        memset(kimg,0x00,16);

						//rtk_hexdump("the first 32-byte decrypted data", (unsigned char *)mem_layout.decrypted_addr, 32);

						//reverse_signature( (unsigned char *)(mem_layout.decrypted_addr + imageSize - img_truncated_size) );

						flush_cache((unsigned int) mem_layout.decrypted_addr, this_entry->length);
						ret = Verify_SHA256_hash( (unsigned char *)mem_layout.decrypted_addr,
												  this_entry->length - img_truncated_size,
												  (unsigned char *)(mem_layout.decrypted_addr + this_entry->length - img_truncated_size),
												  1 );						  
						if( ret < 0 ) {
							printf("[ERR] %s: verify hash fail(%d)\n", __FUNCTION__, ret );
							return RTK_PLAT_ERR_READ_FW_IMG;
						}

						imageSize = imageSize - img_truncated_size - SHA256_SIZE;
					}
				}

				/* if lzma type, decompress image */
				if (mem_layout.bIsCompressed)
				{
					if (lzmaBuffToBuffDecompress((uchar*)mem_layout.decompressed_addr, &decompressedSize, (uchar*)mem_layout.compressed_addr, imageSize) != 0)
					{
						printf("[ERR] %s:Decompress using LZMA error!!\n", __FUNCTION__);

						return RTK_PLAT_ERR_READ_FW_IMG;
					}
				}
			}
		}

		if (version == FW_DESC_TABLE_V1_T_VERSION_11)
		{
			v11_entry = (fw_desc_entry_v11_t*) (fw_entry + unit_len * i);

			if (v11_entry->act_size != 0)
			{
				// string format: "part_num:act_size:hash,"
				memset(buf, 0, sizeof(buf));
				sprintf(buf, "%d:%d:", v11_entry->part_num, v11_entry->act_size);
//				strncat(str_phash, buf, strlen(buf));
				memset(buf, 0, sizeof(buf));
				memcpy(buf, v11_entry->hash, sizeof(v11_entry->hash));
				buf[sizeof(v11_entry->hash)] = ',';
//				strncat(str_phash, buf, strlen(buf));
			}
		}
		else if (version == FW_DESC_TABLE_V1_T_VERSION_21)
		{
			v21_entry = (fw_desc_entry_v21_t *)this_entry;

#if defined(Config_Secure_RSA_TRUE)
			// exclude partition 0 (contain bootcode/kernel/audio/video image)
			if ( (v21_entry->part_num != PART_TYPE_RESERVED) &&
				(v21_entry->act_size != 0) ){
				// recover hash value from signature
				memset(checksum, 0, sizeof(v21_entry->RSA_sign));
				memset(signature, 0, sizeof(v21_entry->RSA_sign)+1);
				memcpy(signature, v21_entry->RSA_sign, sizeof(v21_entry->RSA_sign));

				rsa_verify(signature, Config_Secure_RSA_MODULUS, checksum);

				// string format: "part_num:act_size:hash,"
				memset(buf, 0, sizeof(buf));
				sprintf(buf, "%d:%d:%s,", v21_entry->part_num, v21_entry->act_size, checksum);
//				strncat(str_phash, buf, strlen(buf));
				//printf("[DEBUG_MSG] part_num:%x, act_size:%x, recovered hash:%s\n", v21_entry->part_num, v21_entry->act_size, checksum);
			}
#endif	/* defined(Config_Secure_RSA_TRUE) */
		}
	}





	/* set boot_av_info_ptr */
	if (boot_av->dwMagicNumber == SWAPEND32(BOOT_AV_INFO_MAGICNO))
	{
		boot_av->bHDMImode = sys_logo_is_HDMI;

		// enable audio sound
		if (boot_av->dwAudioStreamLength != 0)
		{
			;
		}

		*boot_av_info_ptr = SWAPEND32((uint) boot_av);

		#ifdef DUBUG_BOOT_AV_INFO
		dump_boot_av_info(boot_av);
		#endif
	}

	/* Flush caches */
	flush_dcache_all();

#endif /* CONFIG_SYS_RTK_EMMC_FLASH */
	return RTK_PLAT_ERR_OK;
}


/*
 * Use firmware description table to read images from NAND flash.
 */
int rtk_plat_read_fw_image_from_NAND(
		uint fw_desc_table_base, part_desc_entry_v1_t* part_entry, int part_count,
		void* fw_entry, int fw_count,
		uchar version)
{
#ifdef CONFIG_SYS_RTK_NAND_FLASH
#ifdef NAS_ENABLE
	rtk_plat_set_boot_flag_from_part_desc(part_entry, part_count);
#endif
	int ret = RTK_PLAT_ERR_OK;
	fw_desc_entry_v1_t *this_entry;
	fw_desc_entry_v11_t *v11_entry;
	fw_desc_entry_v21_t *v21_entry;
	int i;
	int videoFileNum=0, audioFileNum=0;
	uint unit_len;
	char buf[64];
	uint fw_checksum = 0;

	unsigned int secure_mode;
	unsigned int * Kh_key_ptr = DEFAULT_KEY_PTR;
	unsigned int img_truncated_size; // install_a will append 256-byte signature data to it
	boot_av_info_t *boot_av;
	MEM_LAYOUT_WHEN_READ_IMAGE_T mem_layout;
	uint imageSize = 0;
	uint decompressedSize = 0;

	// extern variable
	extern unsigned int mcp_dscpt_addr;
	mcp_dscpt_addr = 0;

	secure_mode = rtk_get_secure_boot_type();
	img_truncated_size = RSA_SIGNATURE_LENGTH;

	struct mtd_info *mtd = &nand_info[nand_curr_device];
	size_t rwsize;
	unsigned char str[16];// old array size is 5, change to 16. To avoid the risk in memory overlap.

	/* find fw_entry structure according to version */
	switch (version)
	{
		case FW_DESC_TABLE_V1_T_VERSION_1:
			unit_len = sizeof(fw_desc_entry_v1_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_11:
			unit_len = sizeof(fw_desc_entry_v11_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_21:
			unit_len = sizeof(fw_desc_entry_v21_t);
			break;

		default:
			return RTK_PLAT_ERR_READ_FW_IMG;
	}

	/* clear boot_av_info memory */
	boot_av = (boot_av_info_t *) MIPS_BOOT_AV_INFO_ADDR;
	memset(boot_av, 0, sizeof(boot_av_info_t));
	
	/* parse each fw_entry */
	for (i = 0; i < fw_count; i++)
	{
		EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

		this_entry = (fw_desc_entry_v1_t *)(fw_entry + unit_len * i);

		if (this_entry->target_addr)
		{
			if (boot_mode == BOOT_RESCUE_MODE || boot_mode == BOOT_ANDROID_MODE)
			{
				switch(this_entry->type)
				{
					case FW_TYPE_KERNEL:
						//kernel_entry = this_entry;
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("kernel_loadaddr", str);						
						printf("Kernel:\n");
						break;

					case FW_TYPE_RESCUE_DT:
						this_entry->target_addr = rtk_plat_get_dtb_target_address(this_entry->target_addr);
						//printf("this_entry->target_addr =%x\n",this_entry->target_addr);
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("fdt_loadaddr", str);
						printf("Rescue DT:\n");
						break;

					case FW_TYPE_RESCUE_ROOTFS:
						printf("Rescue ROOTFS:\n");
						break;

					case FW_TYPE_TEE:
#ifdef CONFIG_TEE			
						printf("TEE:\n");
						tee_enable=1;
						break;
#else
						continue;
#endif
					
					case FW_TYPE_AUDIO:
						if(boot_mode == BOOT_KERNEL_ONLY_MODE)
							continue;
						else
						{
							*AudioFW_entry_ptr = CPU_TO_BE32(this_entry->target_addr | MIPS_KSEG0BASE);
							printf("Audio FW:\n");
						}
						break;

					default:
						//printf("Unknown FW (%d):\n", this_entry->type);
						continue;
				}
			}
			else
			{
				switch(this_entry->type)
				{
					case FW_TYPE_BOOTCODE:
						printf("Boot Code:\n");
						break;

					case FW_TYPE_KERNEL:
						//kernel_entry = this_entry;
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("kernel_loadaddr", str);						
						printf("Kernel:\n");
						break;

					case FW_TYPE_KERNEL_DT:
						this_entry->target_addr = rtk_plat_get_dtb_target_address(this_entry->target_addr);
						//printf("this_entry->target_addr =%x\n",this_entry->target_addr);
						memset(str, 0, sizeof(str));
						sprintf(str, "%x", this_entry->target_addr); /* write entry-point into string */
						setenv("fdt_loadaddr", str);
						printf("DT:\n");
						break;

					case FW_TYPE_KERNEL_ROOTFS:
						printf("ROOTFS:\n");
						break;

					case FW_TYPE_AUDIO:
						if(boot_mode == BOOT_KERNEL_ONLY_MODE)
							continue;
						else
						{
							*AudioFW_entry_ptr = CPU_TO_BE32(this_entry->target_addr | MIPS_KSEG0BASE);
							printf("Audio FW:\n");
						}
						break;

					case FW_TYPE_TEE:
#ifdef CONFIG_TEE						
						printf("TEE:\n");
						tee_enable=1;
						break;
#else
						continue;
#endif
						
					case FW_TYPE_JFFS2:
						printf("JFFS2 Image:\n");
						break;

					case FW_TYPE_SQUASH:
						printf("Squash Image:\n");
						break;

					case FW_TYPE_EXT3:
						printf("EXT3 Image:\n");
						break;

					case FW_TYPE_ODD:
						printf("ODD Image:\n");
						break;

					case FW_TYPE_YAFFS2:
						printf("YAFFS2 Image:\n");
						break;

					case FW_TYPE_AUDIO_FILE:
						//this_entry->target_addr = (POWER_ON_MUSIC_STREAM_ADDR | MIPS_KSEG0BASE);

						/* if enable boot music, need to assign boot_av structure */
						//boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						//boot_av->dwAudioStreamAddress = SWAPEND32(this_entry->target_addr);
						//boot_av->dwAudioStreamLength = SWAPEND32(this_entry->length);
						//boot_av->dwAudioStreamVolume = (-17);
						break;

					case FW_TYPE_VIDEO_FILE:

						/* if enable boot video/jpeg, need to assign boot_av structure */
						//boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						//boot_av->dwVideoStreamAddress = SWAPEND32(this_entry->target_addr);
						//boot_av->bPowerOnImage = 0;
						//boot_av->dwVideoStreamLength = SWAPEND32(this_entry->length);
						break;

					case FW_TYPE_IMAGE_FILE:
						printf("IMAGE FILE:\n");

						/* assign boot_av structure */
						boot_av->dwMagicNumber = SWAPEND32(BOOT_AV_INFO_MAGICNO);
						if(boot_logo_enable)
						{
							boot_av-> logo_enable = boot_logo_enable;
							boot_av-> logo_addr = CPU_TO_BE32(this_entry->target_addr);
							boot_av-> src_width = CPU_TO_BE32(custom_logo_src_width);
							boot_av-> src_height = CPU_TO_BE32(custom_logo_src_height);
							boot_av-> dst_width = CPU_TO_BE32(custom_logo_dst_width);
							boot_av-> dst_height = CPU_TO_BE32(custom_logo_dst_height);
						}

						break;
					default:
						//printf("Unknown FW (%d):\n", this_entry->type);
						continue;
				}
			}

			printf("\t FW Image to 0x%08x, size=0x%08x (0x%08x)\n",
				this_entry->target_addr, this_entry->length, this_entry->target_addr + this_entry->length);

			printf("\t FW Image fr 0x%08x %s\n", nand_fw_desc_table_start + this_entry->offset, this_entry->lzma ? "(lzma)" : "(non-lzma)");

			WATCHDOG_KICK();

				/* secure mode and lzma will only apply to fw image */
				if (this_entry->type == FW_TYPE_AUDIO || 
					this_entry->type == FW_TYPE_KERNEL_ROOTFS || 
					this_entry->type == FW_TYPE_KERNEL  ||
					this_entry->type == FW_TYPE_RESCUE_ROOTFS )
				{
					/* get memory layout before copy fw image */
					mem_layout.bIsEncrypted = (secure_mode != NONE_SECURE_BOOT);
					mem_layout.bIsCompressed = this_entry->lzma;
					mem_layout.image_target_addr = this_entry->target_addr & (~MIPS_KSEG_MSK);					
				}
				else
				{
					/* get memory layout before copy other image */
					mem_layout.bIsEncrypted = 0;
					mem_layout.bIsCompressed = 0;
					mem_layout.image_target_addr = this_entry->target_addr & (~MIPS_KSEG_MSK);					
				}

				get_mem_layout_when_read_image(&mem_layout);

				/* read image from flash */			
				imageSize = this_entry->length;
		
				rwsize = this_entry->length; 			
				if (rwsize&(mtd->oobblock-1))  // page aligned
				{
					rwsize &= ~(mtd->oobblock-1);
					rwsize += mtd->oobblock;					
				}				
			  				
				if(mem_layout.bIsEncrypted)
					ret = nand_read_skip_bad_on_the_fly(mtd, nand_fw_desc_table_start + this_entry->offset, &rwsize, (uint *)mem_layout.flash_to_ram_addr,CP_NF_AES_CBC_128);					
				else					 
					ret = nand_read_skip_bad(mtd, nand_fw_desc_table_start + this_entry->offset, &rwsize, (uint *)mem_layout.flash_to_ram_addr);						 
				
				if(ret){
					printf("[ERR] Read fw error (type:%d)!\n", this_entry->type);
					return RTK_PLAT_ERR_READ_FW_IMG;	
				}	
			
				/* Check checksum */
				fw_checksum = get_checksum((uchar *)mem_layout.flash_to_ram_addr, this_entry->length);

				if (this_entry->checksum != fw_checksum && secure_mode!= RTK_SECURE_BOOT)
				{
					printf("\t FW Image checksum FAILED\n");
					printf("\t FW Image entry  checksum=0x%08x\n", this_entry->checksum);
					printf("\t FW Image result checksum=0x%08x\n", fw_checksum);
					return RTK_PLAT_ERR_READ_FW_IMG; 
				}
									
				/* if secure mode, do AES CBC decrypt */
				if (mem_layout.bIsEncrypted)				
				{
					if (secure_mode == RTK_SECURE_BOOT)					
					{						
						ret = Verify_SHA256_hash( (unsigned char *)mem_layout.flash_to_ram_addr,
												  this_entry->length - img_truncated_size,												  
												  (unsigned char *)(mem_layout.flash_to_ram_addr + this_entry->length - img_truncated_size),
												  1 );
						if( ret < 0 ) {
							printf("[ERR] %s: verify hash fail(%d)\n", __FUNCTION__, ret );
							return RTK_PLAT_ERR_READ_FW_IMG;
						}
						//imageSize = imageSize - img_truncated_size - SHA256_SIZE;
					}
				}

				/* if lzma type, decompress image */
				if (mem_layout.bIsCompressed)
				{
					if (lzmaBuffToBuffDecompress((uchar*)mem_layout.decompressed_addr, &decompressedSize, (uchar*)mem_layout.compressed_addr, imageSize) != 0)
					{
						printf("[ERR] %s:Decompress using LZMA error!!\n", __FUNCTION__);

						return RTK_PLAT_ERR_READ_FW_IMG;
					}
				}
		}

		if (version == FW_DESC_TABLE_V1_T_VERSION_11)
		{
			v11_entry = (fw_desc_entry_v11_t*) (fw_entry + unit_len * i);

			if (v11_entry->act_size != 0)
			{
				// string format: "part_num:act_size:hash,"
				memset(buf, 0, sizeof(buf));
				sprintf(buf, "%d:%d:", v11_entry->part_num, v11_entry->act_size);
//				strncat(str_phash, buf, strlen(buf));
				memset(buf, 0, sizeof(buf));
				memcpy(buf, v11_entry->hash, sizeof(v11_entry->hash));
				buf[sizeof(v11_entry->hash)] = ',';
//				strncat(str_phash, buf, strlen(buf));
			}
		}
		else if (version == FW_DESC_TABLE_V1_T_VERSION_21)
		{
			v21_entry = (fw_desc_entry_v21_t *)this_entry;
		}
	}

	

	/* set boot_av_info_ptr */
	if (boot_av->dwMagicNumber == SWAPEND32(BOOT_AV_INFO_MAGICNO))
	{
		boot_av->bHDMImode = sys_logo_is_HDMI;

		// enable audio sound
		if (boot_av->dwAudioStreamLength != 0)
		{
			printf("skip enable audio sound\n ");
		}

		*boot_av_info_ptr = SWAPEND32((uint) boot_av);

		#ifdef DUBUG_BOOT_AV_INFO
		dump_boot_av_info(boot_av);
		#endif
	}

	/* Flush caches */
	flush_dcache_all();

#endif /* CONFIG_SYS_RTK_NAND_FLASH */

	return RTK_PLAT_ERR_OK;
}

/*
 * Use firmware description table to read images from SPI flash.
 */
int rtk_plat_read_fw_image_from_SPI(void)
{
#if defined(CONFIG_SYS_RTK_SPI_FLASH) && defined (CONFIG_DTB_IN_SPI_NOR)
	unsigned int ret;
	// load DTS	
	if (boot_mode == BOOT_RESCUE_MODE || boot_mode == BOOT_ANDROID_MODE)
	{
		ret = rtkspi_load_DT_for_rescure_android(0);
		if( ret ) {
			printf("Rescue DT:\n");
			printf("          fdt addr = 0x%08x, len = 0x%08x\n", CONFIG_FDT_LOADADDR, ret);
		}
		else {
			printf("Rescue DT: not found\n");
			return RTK_PLAT_ERR_PARSE_FW_DESC;
		}
	}
	else if (boot_mode == BOOT_MANUAL_MODE || boot_mode == BOOT_NORMAL_MODE || boot_mode == BOOT_CONSOLE_MODE)
	{
		ret = rtkspi_load_DT_for_kernel(0);
		if( ret ) {
			printf("DT:\n");
			printf("          fdt addr = 0x%08x, len = 0x%08x\n", CONFIG_FDT_LOADADDR, ret);
		}
		else {
			printf("DT: not found\n");
			return RTK_PLAT_ERR_PARSE_FW_DESC;
		}
	}
	else
	{
		printf("[TODO] boot from SPI is not ready! (boot mode=%d)\n", boot_mode);
		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
		
#endif	

	return RTK_PLAT_ERR_OK;
}



char *rtk_plat_prepare_fw_image_from_USB(int fw_type)
{
#ifdef CONFIG_BOOT_FROM_USB 
	char *filename=NULL;
	
	switch(fw_type)
	{
		case FW_TYPE_KERNEL: /* Linux kernel */
			filename = getenv("rescue_vmlinux");
			return (filename==NULL)?(char*) CONFIG_RESCUE_FROM_USB_VMLINUX:filename;
		
		case FW_TYPE_RESCUE_ROOTFS:		
			filename = getenv("rescue_rootfs");
			return (filename==NULL)?(char*) CONFIG_RESCUE_FROM_USB_ROOTFS:filename;

		case FW_TYPE_KERNEL_ROOTFS:
			filename = getenv("rootfs");
			return (filename==NULL)?(char*) CONFIG_NORMAL_FROM_USB_ROOTFS:filename;
			
		case FW_TYPE_RESCUE_DT:
			filename = getenv("rescue_dtb");
			return (filename==NULL)?(char*) CONFIG_RESCUE_FROM_USB_DTB:filename;
			
		case FW_TYPE_KERNEL_DT:
			filename = getenv("dtb");
			return (filename==NULL)?(char*) CONFIG_NORMAL_FROM_USB_DTB:filename;			
			
		case FW_TYPE_AUDIO:
			filename = getenv("rescue_audio");
			return (filename==NULL)?(char*) CONFIG_RESCUE_FROM_USB_AUDIO_CORE:filename;	
			
		default:
			printf("Unknown FW (%d):\n", fw_type);
			return NULL;			
	}
#endif	
	return NULL; 
}

/*
 * Parse firmware description table and read all data from eMMC flash to ram except kernel image.
 */
int rtk_plat_prepare_fw_image_from_eMMC(void)
{
	int ret = RTK_PLAT_ERR_OK;
#ifdef CONFIG_SYS_RTK_EMMC_FLASH
	fw_desc_table_v1_t fw_desc_table_v1;
	part_desc_entry_v1_t *part_entry;
	fw_desc_entry_v1_t *fw_entry, *fw_entry_v1;
	fw_desc_entry_v11_t *fw_entry_v11;
	fw_desc_entry_v21_t *fw_entry_v21;
	uint part_count = 0;
	uint fw_total_len;
	uint fw_total_paddings;
	uint fw_entry_num = 0;
	uint fw_desc_table_base;
	uint fw_desc_table_blk;	// block no of firmware description table
	uint checksum;
	int i;

	eMMC_fw_desc_table_start = eMMC_bootcode_area_size + CONFIG_FACTORY_SIZE;
	fw_desc_table_base = FIRMWARE_DESCRIPTION_TABLE_ADDR;

	/* Firmware Description Table is right behind bootcode blocks */
	fw_desc_table_blk = eMMC_fw_desc_table_start / EMMC_BLOCK_SIZE;

	/* copy Firmware Description Table Header from flash */
	if (!rtk_eMMC_read(fw_desc_table_blk, sizeof(fw_desc_table_v1_t), (uint *)fw_desc_table_base))
	{
		printf("[ERR] %s:Read fw_desc_table_v1_t error! (0x%x, 0x%x, 0x%x)\n",
			__FUNCTION__, fw_desc_table_blk, sizeof(fw_desc_table_v1_t), fw_desc_table_base);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
	else
	{
		memcpy(&fw_desc_table_v1, (void*)fw_desc_table_base, sizeof(fw_desc_table_v1_t));
	}

	/* Check signature first! */
	if (strncmp((const char *)fw_desc_table_v1.signature,
			FIRMWARE_DESCRIPTION_TABLE_SIGNATURE,
			sizeof(fw_desc_table_v1.signature)) != 0)
	{
		printf("[ERR] %s:Signature(%s) error!\n", __FUNCTION__, fw_desc_table_v1.signature);
		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}

	fw_desc_table_v1.checksum = BE32_TO_CPU(fw_desc_table_v1.checksum);
	fw_desc_table_v1.paddings = BE32_TO_CPU(fw_desc_table_v1.paddings);
	fw_desc_table_v1.part_list_len = BE32_TO_CPU(fw_desc_table_v1.part_list_len);
	fw_desc_table_v1.fw_list_len = BE32_TO_CPU(fw_desc_table_v1.fw_list_len);

#ifdef DUBUG_FW_DESC_TABLE
	dump_fw_desc_table_v1(&fw_desc_table_v1);
#endif

	/* copy Firmware Description/Partition/Fw_entry Tables from flash */
	if (!rtk_eMMC_read(fw_desc_table_blk, fw_desc_table_v1.paddings, (uint *)fw_desc_table_base))
	{
		printf("[ERR] %s:Read all fw tables error! (0x%x, 0x%x, 0x%x)\n",
			__FUNCTION__, fw_desc_table_blk, fw_desc_table_v1.paddings, fw_desc_table_base);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}

	/* Check checksum */
	checksum = get_checksum((uchar*)fw_desc_table_base +
			offsetof(fw_desc_table_v1_t, version),
			sizeof(fw_desc_table_v1_t) -
			offsetof(fw_desc_table_v1_t, version) +
			fw_desc_table_v1.part_list_len +
			fw_desc_table_v1.fw_list_len);

	if (fw_desc_table_v1.checksum != checksum)
	{
		printf("[ERR] %s:Checksum not match(0x%x != 0x%x)\n", __FUNCTION__,
			fw_desc_table_v1.checksum, checksum);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}

	/* Check partition existence */
	if (fw_desc_table_v1.part_list_len == 0)
	{
		printf("[ERR] %s:No partition found!\n", __FUNCTION__);
		//return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
	else
	{
		part_count = fw_desc_table_v1.part_list_len / sizeof(part_desc_entry_v1_t);
	}

	fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v1_t);
	printf("[INFO] fw desc table base: 0x%08x, count: %d\n", eMMC_fw_desc_table_start, fw_entry_num);

	part_entry = (part_desc_entry_v1_t *)(fw_desc_table_base + sizeof(fw_desc_table_v1_t));
	fw_entry = (fw_desc_entry_v1_t *)(fw_desc_table_base +
			sizeof(fw_desc_table_v1_t) +
			fw_desc_table_v1.part_list_len);

	for (i = 0; i < part_count; i++)
	{
		part_entry[i].length = BE32_TO_CPU(part_entry[i].length);

#ifdef DUBUG_FW_DESC_TABLE
		dump_part_desc_entry_v1(&(part_entry[i]));
#endif
	}

	/* Check partition type */
    /*  It so weired that we use part_entry for checking fw count? So we mark it
	if (part_entry[0].type != PART_TYPE_FW)
	{
		printf("[ERR] %s:No firmware partition found!\n", __FUNCTION__);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
*/
	fw_total_len = 0;
	fw_total_paddings = 0;

	/* Parse firmware entries and compute fw_total_len */
	switch (fw_desc_table_v1.version)
	{
		case FW_DESC_TABLE_V1_T_VERSION_1:
			fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v1_t);

			for (i = 0; i < fw_entry_num; i++)
			{
				fw_entry[i].version = BE32_TO_CPU(fw_entry[i].version);
				fw_entry[i].target_addr = BE32_TO_CPU(fw_entry[i].target_addr);
				fw_entry[i].offset = BE32_TO_CPU(fw_entry[i].offset) - eMMC_fw_desc_table_start;	/* offset from fw_desc_table_base */
				fw_entry[i].length = BE32_TO_CPU(fw_entry[i].length);
				fw_entry[i].paddings = BE32_TO_CPU(fw_entry[i].paddings);
				fw_entry[i].checksum = BE32_TO_CPU(fw_entry[i].checksum);

//				printf("[OK] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x)\n",
//					i, fw_entry[i].offset, fw_entry[i].length, fw_entry[i].paddings);

#ifdef DUBUG_FW_DESC_TABLE
				dump_fw_desc_entry_v1(&(fw_entry[i]));
#endif

				fw_total_len += fw_entry[i].length;
				fw_total_paddings += fw_entry[i].paddings;
			}


			break;

		case FW_DESC_TABLE_V1_T_VERSION_11:
			fw_entry_v11 = (fw_desc_entry_v11_t*)fw_entry;
                              fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v11_t);
			for(i = 0; i < fw_entry_num; i++) {
				fw_entry_v1 = &fw_entry_v11[i].v1;
				fw_entry_v1->version = BE32_TO_CPU(fw_entry_v1->version);
				fw_entry_v1->target_addr = BE32_TO_CPU(fw_entry_v1->target_addr);
				fw_entry_v1->offset = BE32_TO_CPU(fw_entry_v1->offset) - eMMC_fw_desc_table_start;	/* offset from fw_desc_table_base */
				fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
				fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
				fw_entry_v1->checksum = BE32_TO_CPU(fw_entry_v1->checksum);

				printf("[OK] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x) act_size = %d part_num = %d\n",
					i, fw_entry_v1->offset, fw_entry_v1->length, fw_entry_v1->paddings, fw_entry_v11[i].act_size, fw_entry_v11[i].part_num);

#ifdef DUBUG_FW_DESC_TABLE
				dump_fw_desc_entry_v1(&(fw_entry[i]));
#endif

				fw_total_len += fw_entry_v1->length;
				fw_total_paddings += fw_entry_v1->paddings;
			}


			break;

		case FW_DESC_TABLE_V1_T_VERSION_21:
			fw_entry_v21 = (fw_desc_entry_v21_t*)fw_entry;
                              fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v21_t);
			for(i = 0; i < fw_entry_num; i++) {
				fw_entry_v1 = &fw_entry_v21[i].v1;
				fw_entry_v1->version = BE32_TO_CPU(fw_entry_v1->version);
				fw_entry_v1->target_addr = BE32_TO_CPU(fw_entry_v1->target_addr);
				fw_entry_v1->offset = BE32_TO_CPU(fw_entry_v1->offset) - eMMC_fw_desc_table_start;	/* offset from fw_desc_table_base */
				fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
				fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
				fw_entry_v1->checksum = BE32_TO_CPU(fw_entry_v1->checksum);

				printf("[OK] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x) act_size = %d part_num = %d\n",
					i, fw_entry_v1->offset, fw_entry_v1->length, fw_entry_v1->paddings, fw_entry_v21[i].act_size, fw_entry_v21[i].part_num);

#ifdef DUBUG_FW_DESC_TABLE
				dump_fw_desc_entry_v1(&(fw_entry[i]));
#endif

				fw_total_len += fw_entry_v1->length;
				fw_total_paddings += fw_entry_v1->paddings;
			}


			break;

		default:
			printf("[ERR] %s:unknown version:%d\n", __FUNCTION__, fw_desc_table_v1.version);
			return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
	
		printf("Normal boot fw follow...\n");
		ret = rtk_plat_read_fw_image_from_eMMC(
			fw_desc_table_base, part_entry, part_count,
			fw_entry, fw_entry_num,
			fw_desc_table_v1.version);
	
#endif

	return ret;
}

int rtk_plat_get_fw_desc_table_start(void)
{
#ifdef CONFIG_SYS_RTK_NAND_FLASH
	struct mtd_info *mtd = &nand_info[nand_curr_device];
	int uboot_512KB = 0x80000;
#ifdef NAS_ENABLE
	int factory_8MB = CONFIG_FACTORY_SIZE;
#else
	int factory_8MB = 0x800000;
#endif
	int reservedSize;

	reservedSize = 6* mtd->erasesize;  //NF profile + BBT
	reservedSize += 1*4* mtd->erasesize; //Hw_setting*4
	reservedSize += rtd_size_aligned(uboot_512KB ,mtd->erasesize)*4;
	reservedSize += rtd_size_aligned(factory_8MB ,mtd->erasesize);

	// add extra 20% space for safety.
	reservedSize = rtd_size_aligned(reservedSize*1.2 ,mtd->erasesize);

	return reservedSize;
#endif
	return 0;
}

/*
 * Parse firmware description table and read all data from NAND flash to ram except kernel image.
 */
int rtk_plat_prepare_fw_image_from_NAND(void)
{
	int ret = RTK_PLAT_ERR_OK;
#ifdef CONFIG_SYS_RTK_NAND_FLASH	
	fw_desc_table_v1_t fw_desc_table_v1;
	part_desc_entry_v1_t *part_entry;
	fw_desc_entry_v1_t *fw_entry, *fw_entry_v1;
	fw_desc_entry_v11_t *fw_entry_v11;
	fw_desc_entry_v21_t *fw_entry_v21;
	uint part_count = 0;
	uint fw_total_len;
	uint fw_total_paddings;
	uint fw_entry_num = 0;
	uint fw_desc_table_base;
	uint checksum;
	int i;
	struct mtd_info *mtd = &nand_info[nand_curr_device];
	size_t rwsize;
	unsigned char empty_mount[sizeof(part_entry->mount_point)];
	unsigned char buf[64];
	unsigned char tmp[16];
	char *tmp_cmdline = NULL;
	u64 size;

#ifdef CONFIG_PROTECTED_AREA_OLD_LAYOUT
        //protected area:512 pages*31
	nand_fw_desc_table_start = (mtd->oobblock)*512*31;
#else
	if((nand_fw_desc_table_start = rtk_plat_get_fw_desc_table_start()) == RTK_PLAT_ERR_PARSE_FW_DESC)
		return RTK_PLAT_ERR_PARSE_FW_DESC;
#endif
	debug("nand_fw_desc_table_start=0x%x\n",nand_fw_desc_table_start);
	fw_desc_table_base = FIRMWARE_DESCRIPTION_TABLE_ADDR;

	/* copy Firmware Description Table from flash */
	// Firmware Description Table is right behind bootcode blockS
	rwsize= mtd->oobblock;
	/* copy Firmware Description Table Header from flash */
	if (nand_read_skip_bad(mtd,nand_fw_desc_table_start,&rwsize, (uint *)fw_desc_table_base)!=0)
	{
		printf("[ERR] %s:Read fw_desc_table_v1_t error! (0x%x, 0x%x, 0x%x)\n",
			__FUNCTION__, nand_fw_desc_table_start, sizeof(fw_desc_table_v1_t), fw_desc_table_base);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}
	else
	{
		memcpy(&fw_desc_table_v1, (void*)fw_desc_table_base, sizeof(fw_desc_table_v1_t));
	}


	/* Check signature first! */
	if(strncmp((const char *)fw_desc_table_v1.signature,
			FIRMWARE_DESCRIPTION_TABLE_SIGNATURE,
			sizeof(fw_desc_table_v1.signature)) != 0) {

		printf("[ERR] %s:Signature(%s) error!\n", __FUNCTION__, fw_desc_table_v1.signature);
		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}

	fw_desc_table_v1.checksum = BE32_TO_CPU(fw_desc_table_v1.checksum);
	fw_desc_table_v1.paddings = BE32_TO_CPU(fw_desc_table_v1.paddings);
	fw_desc_table_v1.part_list_len = BE32_TO_CPU(fw_desc_table_v1.part_list_len);
	fw_desc_table_v1.fw_list_len = BE32_TO_CPU(fw_desc_table_v1.fw_list_len);


#ifdef DUBUG_FW_DESC_TABLE
	dump_fw_desc_table_v1(&fw_desc_table_v1);
#endif


	/* copy Firmware Description/Partition/Fw_entry Tables from flash */
	rwsize= mtd->oobblock;
	if (nand_read_skip_bad(mtd,nand_fw_desc_table_start,&rwsize, (uint *)fw_desc_table_base)!=0)
	{
		printf("[ERR] %s:Read all fw tables error! (0x%x, 0x%x, 0x%x)\n",
			__FUNCTION__, nand_fw_desc_table_start, fw_desc_table_v1.paddings, fw_desc_table_base);

		return RTK_PLAT_ERR_PARSE_FW_DESC;
	}

	/* Check checksum */
	checksum = get_checksum((uchar*)fw_desc_table_base +
			offsetof(fw_desc_table_v1_t, version),
			sizeof(fw_desc_table_v1_t) -
			offsetof(fw_desc_table_v1_t, version) +
			fw_desc_table_v1.part_list_len +
			fw_desc_table_v1.fw_list_len);

	if(fw_desc_table_v1.checksum != checksum) {
		printf("Checksum not match(0x%x != 0x%x), Entering rescue linux...\n",
			fw_desc_table_v1.checksum, checksum);

		return RTK_PLAT_ERR_PARSE_FW_DESC;

	}

	if(fw_desc_table_v1.part_list_len == 0) {
		printf("[ERR] %s:No partition found!\n", __FUNCTION__);

		return RTK_PLAT_ERR_PARSE_FW_DESC;

	} else {
		part_count = fw_desc_table_v1.part_list_len /
					sizeof(part_desc_entry_v1_t);
	}

	part_entry = (part_desc_entry_v1_t *)(fw_desc_table_base + sizeof(fw_desc_table_v1_t));
	fw_entry = (fw_desc_entry_v1_t *)(fw_desc_table_base +
			sizeof(fw_desc_table_v1_t) +
			fw_desc_table_v1.part_list_len);

	for(i = 0; i < part_count; i++) {
		part_entry[i].length = BE64_TO_CPU(part_entry[i].length);
#ifdef DUBUG_FW_DESC_TABLE
		dump_part_desc_entry_v1(&(part_entry[i]));
#endif
	}
	if(part_entry[0].type != PART_TYPE_FW) {
		printf("[ERR] %s:No firmware partition found!\n", __FUNCTION__);
		return RTK_PLAT_ERR_PARSE_FW_DESC;

	}

	fw_total_len = 0;
	fw_total_paddings = 0;

	switch (fw_desc_table_v1.version) {
		case FW_DESC_TABLE_V1_T_VERSION_1:
			for(i = 0; i < part_entry[0].fw_count; i++) {
				fw_entry[i].offset = BE32_TO_CPU(fw_entry[i].offset);
				fw_entry[i].length = BE32_TO_CPU(fw_entry[i].length);
				fw_entry[i].paddings = BE32_TO_CPU(fw_entry[i].paddings);
				//printf("[DEBUG_MSG] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x)\n",
				//		i, fw_entry[i].offset, fw_entry[i].length, fw_entry[i].paddings);
				fw_total_len += fw_entry[i].length;
				fw_total_paddings += fw_entry[i].paddings;
			}

			fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v1_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_11:
			fw_entry_v11 = (fw_desc_entry_v11_t*)fw_entry;
			for(i = 0; i < part_entry[0].fw_count; i++) {
				fw_entry_v1 = &fw_entry_v11[i].v1;
				fw_entry_v1->offset = BE32_TO_CPU(fw_entry_v1->offset);
				fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
				fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
				printf("[DEBUG_MSG] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x) act_size = %d part_num = %d\n",
					i, fw_entry_v1->offset, fw_entry_v1->length, fw_entry_v1->paddings, fw_entry_v11[i].act_size, fw_entry_v11[i].part_num);

				fw_total_len += fw_entry_v1->length;
				fw_total_paddings += fw_entry_v1->paddings;
			}

			fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v11_t);
			break;

		case FW_DESC_TABLE_V1_T_VERSION_21:
				fw_entry_v21 = (fw_desc_entry_v21_t*)fw_entry;
				for(i = 0; i < part_entry[0].fw_count; i++) {
					fw_entry_v1 = &fw_entry_v21[i].v1;
					fw_entry_v1->offset = BE32_TO_CPU(fw_entry_v1->offset);
					fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
					fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
					printf("[DEBUG_MSG] fw_entry[%d] offset = 0x%x length = 0x%x (paddings = 0x%x) act_size = %d part_num = %d\n",
						i, fw_entry_v1->offset, fw_entry_v1->length, fw_entry_v1->paddings, fw_entry_v21[i].act_size, fw_entry_v21[i].part_num);

					fw_total_len += fw_entry_v1->length;
					fw_total_paddings += fw_entry_v1->paddings;
				}

				fw_entry_num = fw_desc_table_v1.fw_list_len / sizeof(fw_desc_entry_v21_t);
				break;

			default:
				printf("unknown version:%d\n", fw_desc_table_v1.version);

				return RTK_PLAT_ERR_PARSE_FW_DESC;

		}

		memset(empty_mount, 0, sizeof(empty_mount));
		/* convert endian? */
		for(i = 0; i < part_count; i++) {
			part_entry[i].length =BE64_TO_CPU(part_entry[i].length);
			size=(part_entry[i].length >> 10);

			memset(buf, 0, sizeof(buf));
			memset(tmp, 0, sizeof(tmp));
			sprintn(size,10,tmp);

			if (memcmp(empty_mount, part_entry[i].mount_point, sizeof(empty_mount)) != 0) {
				sprintf(buf, "%sk(%s%s",tmp, part_entry[i].mount_point,i == part_count-1? ")" :"),");
			}
			else {
				sprintf(buf, "%s%s",tmp,i == part_count-1? "k" :"k,");
			}
			//printf("buf=%s\n",buf);
			tmp_cmdline = (char *)malloc(strlen(getenv("mtd_part")) + 60);
			if (!tmp_cmdline) {
				printf("%s: Malloc failed\n", __func__);
			}
			else {
				sprintf(tmp_cmdline, "%s%s", getenv("mtd_part"),buf);
				setenv("mtd_part", tmp_cmdline);
				free(tmp_cmdline);
			}
			//printf(">%s\n",getenv("mtd_part"));
		}

		switch (fw_desc_table_v1.version) {
			case FW_DESC_TABLE_V1_T_VERSION_1:
				for(i = 0; i < part_entry[0].fw_count; i++) {
					fw_entry[i].version = BE32_TO_CPU(fw_entry[i].version);
					fw_entry[i].target_addr = BE32_TO_CPU(fw_entry[i].target_addr);
					fw_entry[i].offset =(BE32_TO_CPU(fw_entry[i].offset) - nand_fw_desc_table_start);
					fw_entry[i].length = BE32_TO_CPU(fw_entry[i].length);
					fw_entry[i].paddings = BE32_TO_CPU(fw_entry[i].paddings);
					fw_entry[i].checksum = BE32_TO_CPU(fw_entry[i].checksum);
				}
				break;

			case FW_DESC_TABLE_V1_T_VERSION_11:
				fw_entry_v11 = (fw_desc_entry_v11_t*)fw_entry;
				for(i = 0; i < part_entry[0].fw_count; i++) {
					fw_entry_v1 = &fw_entry_v11[i].v1;
					fw_entry_v1->version = BE32_TO_CPU(fw_entry_v1->version);
					fw_entry_v1->target_addr = BE32_TO_CPU(fw_entry_v1->target_addr);
					fw_entry_v1->offset = (BE32_TO_CPU(fw_entry_v1->offset) - nand_fw_desc_table_start);
					fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
					fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
					fw_entry_v1->checksum = BE32_TO_CPU(fw_entry_v1->checksum);
				}
				break;

			case FW_DESC_TABLE_V1_T_VERSION_21:
				fw_entry_v21 = (fw_desc_entry_v21_t*)fw_entry;
				for(i = 0; i < part_entry[0].fw_count; i++) {
					fw_entry_v1 = &fw_entry_v21[i].v1;
					fw_entry_v1->version = BE32_TO_CPU(fw_entry_v1->version);
					fw_entry_v1->target_addr = BE32_TO_CPU(fw_entry_v1->target_addr);
					fw_entry_v1->offset = (BE32_TO_CPU(fw_entry_v1->offset) - nand_fw_desc_table_start);
					fw_entry_v1->length = BE32_TO_CPU(fw_entry_v1->length);
					fw_entry_v1->paddings = BE32_TO_CPU(fw_entry_v1->paddings);
					fw_entry_v1->checksum = BE32_TO_CPU(fw_entry_v1->checksum);
				}
				break;

			default:
				printf("unknown version:%d\n", fw_desc_table_v1.version);

				return RTK_PLAT_ERR_PARSE_FW_DESC;

		}

		ret = rtk_plat_read_fw_image_from_NAND(
				fw_desc_table_base, part_entry, part_count,
				fw_entry, fw_entry_num,
				fw_desc_table_v1.version);
#endif

	return ret;
}

/*
 * Parse firmware description table and read all data from SPI flash to ram except kernel image.
 */
int rtk_plat_prepare_fw_image_from_SPI(void)
{
	int ret = RTK_PLAT_ERR_OK;

#if 0 // for nor
	/* Get flash size. */
	if((rcode = SYSCON_read(SYSCON_BOARD_MONITORFLASH_SIZE_ID,
				&flash_size, sizeof(flash_size))) != OK) {
		printf("get flash size fail!!\n");
		return NULL;
	}

	flash_end_addr = 0xbec00000 + flash_size ;

	/* SCIT signature address */
	scit_signature_addr = (void*)0xbec00000 + 0x100000 + 0x10000 - 0x100;


	memcpy(&fw_desc_table, (void*)(flash_end_addr - sizeof(fw_desc_table)), sizeof(fw_desc_table));
	fw_desc_table.checksum = BE32_TO_CPU(fw_desc_table.checksum);
	memcpy(fw_desc_entry, (void*)(flash_end_addr - sizeof(fw_desc_table) -sizeof(fw_desc_entry)),
					sizeof(fw_desc_entry));

	checksum = get_checksum((uchar*)&fw_desc_table +
			offsetof(fw_desc_table_t, version),
			sizeof(fw_desc_table_t) - offsetof(fw_desc_table_t, version));
	checksum += get_checksum((uchar*)fw_desc_entry, sizeof(fw_desc_entry));

	memcpy(signature_str_buf, fw_desc_table.signature, sizeof(fw_desc_table.signature));

	/* Check checksum and signature. */
	if(fw_desc_table.checksum != checksum ||
			strncmp(fw_desc_table.signature,
			FIRMWARE_DESCRIPTION_TABLE_SIGNATURE,
			sizeof(fw_desc_table.signature)) != 0) {
		printf("Checksum(0x%x) or signature(%s) error! Entering rescue linux...\n",
			fw_desc_table.checksum, signature_str_buf);
#if defined(Rescue_Source_USB) && defined(Board_USB_Driver_Enabled)
		return run_rescue_from_usb(RESCUE_LINUX_FILE_NAME);
#elif defined(Rescue_Source_FLASH)
#if defined(Logo_Source_FLASH)
#if defined(Logo6_Source_FLASH)
		LOGO_DISP_change(5);
#endif
#endif
		return run_rescue_from_flash();
#else
		return NULL;
#endif /* defined(Rescue_Source_USB) && defined(Board_USB_Driver_Enabled) */
	}


	if(strncmp((char*)scit_signature_addr, VERONA_SCIT_SIGNATURE_STRING,
			strlen(VERONA_SCIT_SIGNATURE_STRING)) != 0) {
		printf("Can not find signature string, \"%s\"! Entering rescue linux...\n",
			VERONA_SCIT_SIGNATURE_STRING);
#if defined(Rescue_Source_USB) && defined(Board_USB_Driver_Enabled)
		return run_rescue_from_usb(rescue_file);
#elif defined(Rescue_Source_FLASH)
#if defined(Logo_Source_FLASH)
#if defined(Logo6_Source_FLASH)
		LOGO_DISP_change(5);
#endif
#endif
		return run_rescue_from_flash();
#else
		return NULL;
#endif /* defined(Rescue_Source_USB) && defined(Board_USB_Driver_Enabled) */
	}

	fw_desc_table.length = BE32_TO_CPU(fw_desc_table.length);

	for(i = 0; i < (int)ARRAY_COUNT(fw_desc_entry); i++) {
		fw_desc_entry[i].version =
			BE32_TO_CPU(fw_desc_entry[i].version);
		fw_desc_entry[i].target_addr =
			BE32_TO_CPU(fw_desc_entry[i].target_addr);
		fw_desc_entry[i].offset = BE32_TO_CPU(fw_desc_entry[i].offset);
		fw_desc_entry[i].length = BE32_TO_CPU(fw_desc_entry[i].length);
		fw_desc_entry[i].paddings = BE32_TO_CPU(fw_desc_entry[i].paddings);
		fw_desc_entry[i].checksum = BE32_TO_CPU(fw_desc_entry[i].checksum);
	}

	return run_kernel_from_flash(0x9ec00000, flash_size,
			fw_desc_entry, ARRAY_COUNT(fw_desc_entry));
#endif

	ret = rtk_plat_read_fw_image_from_SPI();

	return ret;
}


//#define DEBUG_SKIP_BOOT_ALL
//#define DEBUG_SKIP_BOOT_LINUX
//#define DEBUG_SKIP_BOOT_AV


/* Calls bootm with the parameters given */
static int rtk_call_bootm(void)
{
	char *bootm_argv[] = { "bootm", NULL, "-", NULL, NULL };
	int ret = 0;
	int j;
	int argc=4;


	if ((bootm_argv[1] = getenv("kernel_loadaddr")) == NULL) {
		bootm_argv[1] =(char*) CONFIG_KERNEL_LOADADDR;
	}

	if ((bootm_argv[3] = getenv("fdt_loadaddr")) == NULL) {
		bootm_argv[3] =(char*) CONFIG_FDT_LOADADDR;
	}

	/*
	 * - do the work -
	 * exec subcommands of do_bootm to init the images
	 * data structure
	 */
	debug("bootm_argv ={ ");
	for (j = 0; j < argc; j++)
			debug("%s,",bootm_argv[j]);
	debug("}\n");


	ret = do_bootm(find_cmd("do_bootm"), 0, argc,bootm_argv);


	if (ret) {
		printf("ERROR do_bootm failed!\n");
		return -1;
	}

	return 1;
}

int rtk_plat_set_fw(void)
{
	int ret = RTK_PLAT_ERR_OK;
	char cmd[16];

	printf("Start Boot Setup ... ");

	/* reset some shared memory */
	reset_shared_memory();

#ifdef DEBUG_SKIP_BOOT_ALL // Skip by CK
	printf("(CK skip)\n");
	return RTK_PLAT_ERR_PARSE_FW_DESC;
#else
	printf("\n");
#endif
	if (boot_from_usb != BOOT_FROM_USB_DISABLE) // workaround path that read fw img from usb
	{			
		ret = rtk_plat_read_fw_image_from_USB(0);
	}
	else
	{
		/* parse fw_desc_table, and read all data from flash to ram except kernel image */
		if (boot_flash_type == BOOT_EMMC)
		{
			/* For eMMC */
			ret = rtk_plat_prepare_fw_image_from_eMMC();
		}
		else if (boot_flash_type == BOOT_NAND)
		{
			/* For NAND */
			ret = rtk_plat_prepare_fw_image_from_NAND();
		}
		else
		{
			/* For SPI */
			ret = rtk_plat_prepare_fw_image_from_SPI();
#ifdef CONFIG_BOOT_FROM_USB			
			if(ret == RTK_PLAT_ERR_OK)			
				ret = rtk_plat_read_fw_image_from_USB(0);
#endif				
		}
	}

#ifndef DEBUG_SKIP_BOOT_AV // mark for boot linux kernel only
	if (boot_from_flash == BOOT_FROM_FLASH_NORMAL_MODE)
	{
		if (ret == RTK_PLAT_ERR_OK)
		{
			/* Enable ACPU */
			if (*AudioFW_entry_ptr != 0){
				printf("Start A/V Firmware ...\n");
				flush_dcache_all();
				rtd_setbits(CLOCK_ENABLE2_reg,_BIT4);
			}
		}
	}
	else
	{
		printf("[Skip A] boot manual mode\n");
	}
#endif

	return ret;
}

//all standard boot_cmd entry.
int rtk_plat_do_boot_linux(void)
{

	rtk_call_bootm();

	/* Reached here means jump to kernel entry flow failed */

	return RTK_PLAT_ERR_BOOT;

}
/*
 ************************************************************************
 *
 * This is the final part before booting Linux in realtek platform:
 * we need to move audio/video firmware and stream files
 * from flash to ram. We will also decompress or decrypt image files,
 * if necessary, which depends on the information from flash writer.
 *
 ************************************************************************
 */
int  rtk_plat_boot_handler(void)
{
	int ret = RTK_PLAT_ERR_OK;

	/* copy audio/video firmware and stream files from flash to ram */
	ret = rtk_plat_set_fw();

	if (ret == RTK_PLAT_ERR_OK)
	{
#ifndef DEBUG_SKIP_BOOT_LINUX
		if (boot_from_flash == BOOT_FROM_FLASH_NORMAL_MODE)
		{
			/* go Linux */
#ifdef CONFIG_REALTEK_WATCHDOG
			WATCHDOG_KICK();
#else
			WATCHDOG_DISABLE();
#endif

			EXECUTE_CUSTOMIZE_FUNC(1); // insert execute customer callback at here

			ret = rtk_plat_do_boot_linux ();
		}
		else
		{
			printf("[Skip K] boot manual mode (execute \"go all\")\n");
		}
#endif
	}

	return ret;
}

int rtk_plat_do_bootr(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret = RTK_PLAT_ERR_OK;

	/* reset boot flags */
	boot_from_flash = BOOT_FROM_FLASH_NORMAL_MODE;
	boot_from_usb = BOOT_FROM_USB_DISABLE;

	/* parse option */
	if (argc == 1)
	{
		boot_from_usb = BOOT_FROM_USB_DISABLE;
	}
	else if (argc == 2 && argv[1][0] == 'u')
	{
		if (argv[1][1] == 'z')
		{
			boot_from_usb = BOOT_FROM_USB_COMPRESSED;
		}
		else if (argv[1][1] == '\0')
		{
			boot_from_usb = BOOT_FROM_USB_UNCOMPRESSED;
		}
		else
		{
			return CMD_RET_USAGE;
		}
	}
	else if (argc == 2 && argv[1][0] == 'm')
	{
		boot_from_flash = BOOT_FROM_FLASH_MANUAL_MODE;
	}
	else
	{
		return CMD_RET_USAGE;
	}

	WATCHDOG_KICK();
	ret = rtk_plat_boot_handler();

#ifdef CONFIG_RESCUE_FROM_USB
	if (ret != RTK_PLAT_ERR_OK) {
		ret = boot_rescue_from_usb();
	}
#endif /* CONFIG_RESCUE_FROM_USB */

	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
	bootr, 2, 0,	rtk_plat_do_bootr,
	"boot realtek platform",
	"[u/uz]\n"
	"\tu   - boot from usb\n"
	"\tuz  - boot from usb (use lzma image)\n"
	"\tm   - read fw from flash but boot manually (go all)\n"
);
#if 0

int pmx_do_boothd(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    char tmpbuf[128];
	char *filename;
    int ret = 1;
	

	run_command("usb start", 0);	/* "usb start" always return 0 */
	if (run_command("usb dev", 0) != 0) {
		printf("No USB device found!\n");
        return 1;
	}

	/* DTB */	
	if ((filename = getenv("hdboot_dtb")) == NULL) {
		return 1;
	}	
	sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("fdt_loadaddr"), filename);
	if (run_command(tmpbuf, 0) != 0) {
		return 1;
	}

	printf("[PMX] Loading \"%s\" to %s -  OK.\n\n", filename, getenv("fdt_loadaddr"));

	/* Linux kernel */
	if ((filename = getenv("hdboot_kernel")) == NULL) {
		return 1;
	}
	sprintf(tmpbuf, "fatload usb 0:1 %s %s", getenv("kernel_loadaddr"), filename);
	if (run_command(tmpbuf, 0) != 0) {
        return 1;
	}

	printf("[PMX] Loading \"%s\" to %s - OK.\n\n", filename, getenv("kernel_loadaddr"));

	ret = rtk_call_bootm();
	/* Should not reach here */

	return ret;
}
U_BOOT_CMD(
	boothd, 1, 0,	pmx_do_boothd, 
	"boot from hard disk",
    ""
);
#endif
