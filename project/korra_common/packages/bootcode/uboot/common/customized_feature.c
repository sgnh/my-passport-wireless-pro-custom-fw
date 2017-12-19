#include <common.h>
#include <command.h>
#include <environment.h>
#include <linux/stddef.h>
#include <search.h>
#include <errno.h>
#include <malloc.h>
#include <asm/arch/system.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/factorylib.h>
#include <asm/arch/factorylib_ro.h>


#define BOOT_LETENV_FILE_NAME		FACTORY_HEADER_FILE_NAME"letvenv.txt"

struct hsearch_data env_htab_customized;


int env_import_customized(const char *buf, int check)
{
	env_t *ep = (env_t *)buf;

	if (check) {
		uint32_t crc;

		memcpy(&crc, &ep->crc, sizeof(crc));

		if (crc32(0, ep->data, ENV_SIZE) != crc) {
			set_default_env(NULL); // ck modify that prevent serious error messages
			return 0;
		}
	}

	if (himport_r(&env_htab_customized, (char *)ep->data, ENV_SIZE, '\0', 0)) {
		return 1;
	}

	printf("%s failed\n",__FUNCTION__);

	return 0;
}

/*
 * Look up variable from environment,
 * return address of storage for that variable,
 * or NULL if not found
 */
char *getenv_customized(const char *name)
{	
		ENTRY e, *ep;
		
		e.key	= name;
		e.data	= NULL;
		hsearch_r(e, FIND, &ep, &env_htab_customized);

		return ep ? ep->data : NULL;
}

void env_handler_customized(char *str)
{
	char *dst_addr= (char*)malloc(0x20000*sizeof(char));;
	char *retAddr;
	int dst_length;	
	
	printf("%s:\n", str);

	if (factory_read(BOOT_LETENV_FILE_NAME, &dst_addr, &dst_length)) {
		printf("------------can't find %s\n", BOOT_LETENV_FILE_NAME);
		
	}
	else {
		printf("------------%s found\n", BOOT_LETENV_FILE_NAME);

		//printf("dst_addr=%x\n, dst_length=%d\n",dst_addr,dst_length);
			
		env_import_customized(dst_addr,1);
		
		setenv("ethaddr",getenv_customized("ethaddr"));
			
	}
}

#define MISC_START_ADDRESS 0x638000

typedef struct _bootloader_message
{
    char command[32];
    char status[32];
    char recovery[1024];
} bootloader_message;

int detect_recovery_flag(char *str)
{
#ifdef CONFIG_SYS_RTK_EMMC_FLASH
	uint block_no;
	uint imageSize = 0;
	char *tmp_data = NULL;
	unsigned int misc_start_add=0;
	int i;
	
	printf("%s:\n", str);
	
	imageSize= sizeof(bootloader_message);
	
	if((misc_start_add = getenv_ulong("misc_add", 16, 0)) != 0)	
		block_no = misc_start_add / EMMC_BLOCK_SIZE ;
	else
		block_no = MISC_START_ADDRESS / EMMC_BLOCK_SIZE ;
	
	if (imageSize&(EMMC_BLOCK_SIZE-1)) {
		imageSize &= ~(EMMC_BLOCK_SIZE-1);
		imageSize += EMMC_BLOCK_SIZE;
	}
	
	tmp_data = (char*)malloc(imageSize);
                                
	if (!rtk_eMMC_read(block_no, imageSize, (uint *)tmp_data))
	{		
		printf("read MISC partition failed\n");
		return 0;
	}
	
	if(!memcmp(tmp_data,"boot-recovery",13))	
		return 1;	
	else
	{
		printf("dump misc info(32bytes):");
		for(i=0;i<32;i++)
			printf("%c",*(tmp_data+i));
		printf("\n");	
	}
	
	free(tmp_data);	
#endif	
	return 0;
}

#ifdef CONFIG_RESCUE_FROM_USB

#define RESCUE_DTB_FILENAME_IN_INSTALL_IMG		"package5/"CONFIG_RESCUE_FROM_USB_DTB
#define RESCUE_ROOTFS_FILENAME_IN_INSTALL_IMG	"package5/"CONFIG_RESCUE_FROM_USB_ROOTFS
#define RESCUE_KERNEL_FILENAME_IN_INSTALL_IMG	"package5/"CONFIG_RESCUE_FROM_USB_VMLINUX
#define RESCUE_FW_FILENAME_IN_INSTALL_IMG		"package5/"CONFIG_RESCUE_FROM_USB_AUDIO_CORE
#define RESCUE_COMPRESSED_INSTALL_IMG_TMP_BUFFER 0x20000000

extern BOOT_MODE boot_mode;

int boot_rescue_from_usb_OTA(char *str)
{
	char tmpbuf[128];
	int ret = RTK_PLAT_ERR_OK;
	char *filename;
	
	uint target_addr = 0;
	uint data_bytes = 0;
	char *dst_addr = NULL;
	uint dst_length = 0;
	uint tmp = 0;	
	char *bootm_argv[] = { "bootm", NULL, "-", NULL, NULL };
	int argc=4;
	
	printf("%s:\n", str);
	
	target_addr = RESCUE_COMPRESSED_INSTALL_IMG_TMP_BUFFER;
	
	filename="install.img";
	run_command("usb start", 0);
	sprintf(tmpbuf, "fatload usb 0:1 %x %s",RESCUE_COMPRESSED_INSTALL_IMG_TMP_BUFFER,filename);
	if (run_command(tmpbuf, 0) != 0) {
		goto loading_failed;
	}

	printf("Loading %s to 0x%x is OK.\n", filename,RESCUE_COMPRESSED_INSTALL_IMG_TMP_BUFFER);
	
	data_bytes = getenv_ulong("filesize", 16, 0);
	
	//copy rescue dtb	
	ret = tar_read(RESCUE_DTB_FILENAME_IN_INSTALL_IMG, target_addr, data_bytes, &dst_addr, &dst_length);
	
	if(ret>0)
	{	
		tmp = getenv_ulong("fdt_loadaddr", 16, 0);
		memcpy((char *)tmp, dst_addr, dst_length);
		printf("untar rescue dtb to 0x%x ok.\n",tmp);
	}
	else
	{
		filename="rescue dtb";
		goto untar_failed;		
	}
		
	//copy kernel		
	ret = tar_read(RESCUE_KERNEL_FILENAME_IN_INSTALL_IMG, target_addr, data_bytes, &dst_addr, &dst_length);
	
	if(ret>0)
	{	
		tmp = getenv_ulong("kernel_loadaddr", 16, 0);
		memcpy((char *)tmp, dst_addr, dst_length);
		printf("untar kernel to 0x%x ok.\n",tmp);
	}
	else
	{
		filename="kernel";
		goto untar_failed;		
	}	
			
	//copy rescue rootfs
	ret = tar_read(RESCUE_ROOTFS_FILENAME_IN_INSTALL_IMG, target_addr, data_bytes, &dst_addr, &dst_length);
	
	if(ret>0)
	{	
		tmp = getenv_ulong("rootfs_loadaddr", 16, 0);
		memcpy((char *)tmp, dst_addr, dst_length);
		printf("untar rescue rootfs to 0x%x ok.\n", tmp);
	}
	else
	{
		filename="rescue rootfs";
		goto untar_failed;		
	}

	//copy fw	
	ret = tar_read(RESCUE_FW_FILENAME_IN_INSTALL_IMG, target_addr, data_bytes, &dst_addr, &dst_length);
	
	if(ret>0)
	{	
		tmp = MIPS_AUDIO_FW_ENTRY_ADDR;
		memcpy((char *)tmp, dst_addr, dst_length);
		printf("untar fw to 0x%x ok.\n",tmp);
		run_command("go a", 0);
	}
	else
		printf("untar fw to %x failed.\n",tmp);	
	
			
	boot_mode = BOOT_RESCUE_MODE;
	
	if ((bootm_argv[1] = getenv("kernel_loadaddr")) == NULL) {
		bootm_argv[1] =(char*) CONFIG_KERNEL_LOADADDR;
	}

	if ((bootm_argv[3] = getenv("fdt_loadaddr")) == NULL) {
		bootm_argv[3] =(char*) CONFIG_FDT_LOADADDR;
	}


	ret = do_bootm(find_cmd("do_bootm"), 0, argc,bootm_argv);


	if (ret) {
		printf("ERROR do_bootm failed!\n");
		return -1;
	}

	/* Should not reach here */
	return 1;
	
	
untar_failed:
	printf("untar %s failed.\n\n", filename);	
	return RTK_PLAT_ERR_READ_RESCUE_IMG;	
	
loading_failed:
	printf("Loading \"%s\" from USB failed.\n", filename);
	return RTK_PLAT_ERR_READ_RESCUE_IMG;	

}
#endif




