#include <configs/pmx.h>

#ifdef CONFIG_BOOTCODE2
#include <rtkspi.h>
#include <fwdescriptor.h>
#endif

#ifdef CONFIG_PMX_SPI
#define BUF_MAX 256

extern char usb_started; // from usb.c
extern void enable_clock(uint reg_reset, uint mask_reset, uint reg_clock, uint mask_clock);
extern uint *AudioFW_entry_ptr;
extern unsigned int spiflash_size;
extern char spiboot_failed;

#ifdef CONFIG_BOOTCODE2
DECLARE_GLOBAL_DATA_PTR;

wd_fw_desc_table_t fwtable;

void spi_read_fwtable(void)
{
    unsigned int _iSPI_base_addr;
    memset( &fwtable, 0, sizeof(wd_fw_desc_table_t));

    _iSPI_base_addr = SPI_RBUS_BASE_ADDR + 0xFF000;

    //Read fwtable
    rtkspi_read32( (unsigned int)&fwtable, _iSPI_base_addr, sizeof(wd_fw_desc_table_t));

}

#endif

static int pmx_call_bootm(void)
{
	char *bootm_argv[] = { "bootm", NULL, "-", NULL, NULL };
	int ret = 0;
	int j;
	int argc=4;
	char buf[BUF_MAX];

	bootm_argv[1] = (char*) malloc(sizeof(char) * 32);
	snprintf(bootm_argv[1], BUF_MAX, "%x", CONFIG_KERNEL_LOADADDR);
	bootm_argv[3] = (char*) malloc(sizeof(char) * 32);
	snprintf(bootm_argv[3], BUF_MAX, "%x", CONFIG_FDT_LOADADDR);

	debug("bootm_argv ={ ");
	for (j = 0; j < argc; j++)
			printf("%s,",bootm_argv[j]);
	printf("}\n");
	debug("[PMX] : Bootargs = %s\n", getenv("bootargs"));
	
	ret = do_bootm(find_cmd("do_bootm"), 0, argc,bootm_argv);


	if (ret) {
		printf("ERROR do_bootm failed!\n");
		return -1;
	}

	return 1;
}
int pmx_check_fw_in_usb_flash(PMX_FIRMWARE f){
	char tmpcmdline[BUF_MAX];
	char * tmp_addr;
	boot_config_t configs;

	pmx_prepare_config(&configs, f);
	if(!usb_started){
		if(run_command("usb start", 0) != 0){
			return -1;
		}
	}
	if (configs.kernel != NULL){
		printf("[PMX] : Check kernel...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_KERNEL_LOADADDR, configs.kernel);
		if(run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	if (configs.dtb != NULL){
		printf("[PMX] : Check DTB...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_FDT_LOADADDR, configs.dtb);
		if (run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	if (configs.rootfs != NULL){
		printf("[PMX] : Check Rootfs...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_ROOTFS_LOADADDR, configs.rootfs);
		if(run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	return 0;
}

char * pmx_get_bootup_partition(void){
    char * partition;
    partition = (char *)malloc(sizeof(char) * 4);
#ifdef CONFIG_BOOTCODE2
    snprintf(partition, 4, "2:1");
#else
    snprintf(partition, 4, "0:1");
#endif
    return partition;
}

int pmx_prepare_config(boot_config_t * configs, PMX_FIRMWARE f){
	switch(f){
		case PMX_NORMAL_FIRMWARE:
			printf("[PMX] : prepare normal firemware config...\n");
			configs->kernel = CONFIG_NORMAL_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_NORMAL_FROM_USB_DTB;
			configs->rootfs = NULL;
			break;
#ifdef CONFIG_BOOTCODE2
		case PMX_RECOVERY_USB3_FIRMWARE:
			printf("[PMX] : prepare recovery config...\n");
			configs->kernel = CONFIG_RESCUE_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_RESCUE_FROM_USB_DTB;
			//configs->rootfs = CONFIG_RESCUE_FROM_USB_ROOTFS;
			configs->rootfs = NULL;
			break;
#endif
#ifdef CONFIG_BOOTCODE
		case PMX_RECOVERY_USB2_FIRMWARE:
			printf("[PMX] : prepare recovery config...\n");
			configs->kernel = CONFIG_RECOVERY_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_RECOVERY_FROM_USB_DTB;
			//configs->rootfs = CONFIG_RECOVERY_FROM_USB_ROOTFS;
			configs->rootfs = NULL;
			break;
#endif
		default:
			configs->kernel = NULL;
			configs->dtb = NULL;
			configs->rootfs = NULL;
	}
	return 0;
}

int pmx_read_fw_from_usb(boot_config_t * configs){
    char buf[BUF_MAX];

	if(!usb_started){
		if(run_command("usb start", 0) != 0){
			return -1;
		}
	}
	if (configs->dtb != NULL){
    	PMX_DEBUG("[PMX] : fatload usb %s %x %s\n", 
    		pmx_get_bootup_partition(), CONFIG_FDT_LOADADDR, configs->dtb)
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
    		pmx_get_bootup_partition(), CONFIG_FDT_LOADADDR, configs->dtb);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
    	PMX_DEBUG("[PMX] : Load DTB \"%s\" to address 0x%08x\n", configs->dtb, CONFIG_FDT_LOADADDR)
	}
	if (configs->kernel != NULL){
    	PMX_DEBUG("[PMX] : fatload usb %s %x %s\n", 
            pmx_get_bootup_partition(), CONFIG_KERNEL_LOADADDR, configs->kernel)
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
            pmx_get_bootup_partition(), CONFIG_KERNEL_LOADADDR, configs->kernel);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
		PMX_DEBUG("[PMX] : Load Kernel \"%s\" to address 0x%08x\n", configs->kernel, CONFIG_KERNEL_LOADADDR)
	}
	if (configs->rootfs != NULL){
    	PMX_DEBUG("[PMX] : fatload usb %s %x %s", 
            pmx_get_bootup_partition(), CONFIG_ROOTFS_LOADADDR, configs->rootfs)
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
            pmx_get_bootup_partition(), CONFIG_ROOTFS_LOADADDR, configs->rootfs);
		if(run_command(buf, 0) != 0){
			return -1;
    	}
		PMX_DEBUG("[PMX] : Load Rootfs \"%s\" to address 0x%08x\n", configs->kernel, CONFIG_ROOTFS_LOADADDR)
	}
    PMX_DEBUG("[PMX] : fatload usb %s %x %s\n", 
		pmx_get_bootup_partition(), 0x1b00000, "bluecore.audio")
    snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
        pmx_get_bootup_partition(), 0x1b00000, "bluecore.audio");
	if(run_command(buf, 0) != 0){
		printf("[PMX] : Could not load bluecore.audio\n");
    }

    return 0;
}

#ifdef CONFIG_BOOTCODE2

unsigned int g_UiCRCTab[256];

unsigned long getcrc32(unsigned char *buffer, int dwSize)
{
    unsigned long  crc = 0xffffffff;
    int len;

    len = dwSize;
    while(len--)
        crc = (crc >> 8) ^ g_UiCRCTab[(crc & 0xFF) ^ *buffer++];

    return crc^0xffffffff;
}

unsigned long Reflect(unsigned long ref, unsigned char ch)
{
    unsigned long value = 0;
    int i;

    for(i = 1; i < (ch + 1); i++)
    {
        if(ref & 1)
            value |= 1 << (ch - i);
        ref >>= 1;
    }
    return value;
}

void crc32_init(void)
{
    unsigned long ulPolynomial = 0x04c11db7; // It's a constant value from CRC32 rule.
    int i,j;

    for(i = 0; i <= 0xFF; i++)
    {
        g_UiCRCTab[i] = Reflect(i, 8) << 24;
        for (j = 0; j < 8; j++)
            g_UiCRCTab[i] = (g_UiCRCTab[i] << 1) ^ (g_UiCRCTab[i] & (1 << 31) ? ulPolynomial : 0);
        g_UiCRCTab[i] = Reflect(g_UiCRCTab[i], 32);
    }
}

int pmx_prepare_fw_from_spi(PMX_BOOTUP_STATE s){
    char buf[BUF_MAX];
    unsigned long fwtable_crc32 = 0;
    
    spi_read_fwtable();
    if( !memcmp(fwtable.signature,WDCKORRA_SIGN,sizeof(wd_fw_desc_table_t)))
    {
        printf("Invalid signature: %02x %02x %02x %02x %02x %02x %02x %02x\n",fwtable.signature[0],fwtable.signature[1],fwtable.signature[2],fwtable.signature[3],
		                                                                      fwtable.signature[4],fwtable.signature[5],fwtable.signature[6],fwtable.signature[7]);
        return -1;
    }
    
    printf("Firmware Version: %s\n",fwtable.version);
    crc32_init();
    fwtable_crc32 = getcrc32((unsigned char *)&fwtable, sizeof(wd_fw_desc_table_t)-4);

    if ( fwtable_crc32 != fwtable.checksum )
    {
        printf("FWtable CheckSum error: fwtable_crc32[%08lx], fwtable.checksum[%08lx]\n",fwtable_crc32,fwtable.checksum);
        return -1;
    }
	switch(s){
		case PMX_BOOTUP_NORMAL:
			PMX_DEBUG("[PMX] : rtkspi dual_read %lx %x %lx\n", 
				fwtable.normaldtboff, CONFIG_FDT_LOADADDR, fwtable.normaldtbsize)
			snprintf(buf, BUF_MAX, "rtkspi dual_read %lx %x %lx\n", 
				fwtable.normaldtboff, CONFIG_FDT_LOADADDR, fwtable.normaldtbsize);
			if(run_command(buf, 0) != 0)
				return -1;
			PMX_DEBUG("[PMX] : rtkspi dual_read %lx %x %lx\n", 
				fwtable.normallinuxoff, CONFIG_KERNEL_LOADADDR, fwtable.normallinuxsize)
			snprintf(buf, BUF_MAX, "rtkspi dual_read %lx %x %lx\n", 
				fwtable.normallinuxoff, CONFIG_KERNEL_LOADADDR, fwtable.normallinuxsize);
			if(run_command(buf, 0) != 0)
				return -1;
			break;
		case PMX_BOOTUP_RECOVERY:
			PMX_DEBUG("[PMX] : rtkspi dual_read %lx %x %lx\n", 
				fwtable.rescuedtboff, CONFIG_FDT_LOADADDR, fwtable.rescuedtbsize)
			snprintf(buf, BUF_MAX, "rtkspi dual_read %lx %x %lx\n", 
				fwtable.rescuedtboff, CONFIG_FDT_LOADADDR, fwtable.rescuedtbsize);
			if(run_command(buf, 0) != 0)
				return -1;
			PMX_DEBUG("[PMX] : rtkspi dual_read %lx %x %lx\n", 
				fwtable.rescuelinuxoff, CONFIG_KERNEL_LOADADDR, fwtable.rescuelinuxsize)
			snprintf(buf, BUF_MAX, "rtkspi dual_read %lx %x %lx\n", 
				fwtable.rescuelinuxoff, CONFIG_KERNEL_LOADADDR, fwtable.rescuelinuxsize);
			if(run_command(buf, 0) != 0)
				return -1;
			break;
	}
	
	PMX_DEBUG("[PMX] : rtkspi dual_read %lx %x %lx\n", 
		fwtable.blueaudiooff, CONFIG_FW_LOADADDR, fwtable.blueaudionsize)
	snprintf(buf, BUF_MAX, "rtkspi dual_read %lx %x %lx\n", 
		fwtable.blueaudiooff, CONFIG_FW_LOADADDR, fwtable.rescuelinuxsize);
	if(run_command(buf, 0) != 0)
		return -1;

    if (fwtable.rootfilesystem == 1 || fwtable.rootfilesystem == 2){
	    if (fwtable.debuglevel > 4){
            printf("[PMX] : Boot root filesystem sdd%ld, with debuglevel:%ld\n", fwtable.rootfilesystem,fwtable.debuglevel);
            snprintf(buf, BUF_MAX, "console=ttyS0,115200 earlyprintk loglevel=%ld root=/dev/sdd%ld rootfstype=ext4 rw rootwait rootflags=commit=3600 panic=10 ubv=%s", fwtable.debuglevel, fwtable.rootfilesystem, PMX_LOADER_VERSION);            
        }else{
            printf("[PMX] : Boot root filesystem sdd%ld\n", fwtable.rootfilesystem);
            snprintf(buf, BUF_MAX, "console=ttyS0,115200 earlyprintk loglevel=4 root=/dev/sdd%ld rootfstype=ext4 rw rootwait rootflags=commit=3600 panic=10 ubv=%s", fwtable.rootfilesystem, PMX_LOADER_VERSION);
		}
        setenv("bootargs", buf);
    }else{
        printf("[PMX] : SPI Detect bootup root filesystem fail\n");
        return -1;
    }
    return 0;
}

#endif

int pmx_prepare_fw_from_usb(PMX_BOOTUP_STATE s){
    boot_config_t configs;    

	switch(s){
		case PMX_BOOTUP_NORMAL:
			pmx_prepare_config(&configs, PMX_NORMAL_FIRMWARE);
			break;
		case PMX_BOOTUP_RECOVERY:
#ifdef CONFIG_BOOTCODE
			pmx_prepare_config(&configs, PMX_RECOVERY_USB2_FIRMWARE);
#endif
#ifdef CONFIG_BOOTCODE2
			pmx_prepare_config(&configs, PMX_RECOVERY_USB3_FIRMWARE);
#endif
			break;
	}
	
    if(pmx_read_fw_from_usb(&configs) != 0){
        return -1;
    }
    return 0;
}

int pmx_do_bootp(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret;
	char buf[BUF_MAX];
	if (argc == 1){
#ifdef CONFIG_BOOTCODE2
		if ( spiflash_size >= 0x800000 && spiboot_failed == 0 ){
			ret = pmx_prepare_fw_from_spi(PMX_BOOTUP_NORMAL);
			if (ret != 0){
				printf("[PMX] : prepare firmware form USB fail\n");
				return CMD_RET_FAILURE; 
			}			
		}
		else{
			ret = pmx_prepare_fw_from_usb(PMX_BOOTUP_NORMAL);
			if (ret != 0){
				printf("[PMX] : prepare firmware form USB fail\n");
				return CMD_RET_FAILURE; 
			}
#ifdef CONFIG_PMX_BOOTUP_FROM_USB
			char * pmx_dev_flag = getenv("pmx_dev");
			if (pmx_dev_flag == NULL || !strcmp("0", pmx_dev_flag)){
				int bootup_partition = -1;
				if (bootup_partition == -1){
					debug("[PMX] : fatload usb %s %x %s\n", 
							pmx_get_bootup_partition(), 0x1500000, "1"); 
					snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
							pmx_get_bootup_partition(), 0x1500000, "1"); 
					if(run_command(buf, 0) == 0){ 
						bootup_partition = 1;   		
					}   
				}
				if (bootup_partition == -1){
					debug("[PMX] : fatload usb %s %x %s\n", 
							pmx_get_bootup_partition(), 0x1500000, "2"); 
					snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
							pmx_get_bootup_partition(), 0x1500000, "2"); 
					if(run_command(buf, 0) == 0){ 
						bootup_partition = 2;   		
					}
				}   
				if (bootup_partition == 1 || bootup_partition == 2){
						printf("[PMX] : Boot root filesystem sdd%d\n", bootup_partition);
						snprintf(buf, BUF_MAX, "console=ttyS0,115200 earlyprintk loglevel=4 root=/dev/sdd%d rootfstype=ext4 rw rootwait rootflags=commit=3600 panic=10 ubv=%s", bootup_partition, PMX_LOADER_VERSION);
						setenv("bootargs", buf);
				}
				else{
					printf("[PMX] : Detect bootup root filesystem fail\n");
					goto ERR;
				}
			}
#endif
		}
#else
		return CMD_RET_USAGE;
#endif

	}
	else if (argc == 2){
		if (argv[1][0] == 'r'){
			ret = pmx_prepare_fw_from_usb(PMX_BOOTUP_RECOVERY);
			if (ret != 0){
				printf("[PMX] : recovery fail\n");
				return CMD_RET_FAILURE; 
			}
		}
#ifdef CONFIG_BOOTCODE2
		if (argv[1][0] == 's'){
			ret = pmx_prepare_fw_from_spi(PMX_BOOTUP_RECOVERY);
			if (ret != 0){
				printf("[PMX] : recovery fail\n");
				return CMD_RET_FAILURE; 
			}
		}
#endif
	}
	else{
		return CMD_RET_USAGE;
	}

	printf("[PMX] : Enable ACPU\n");
	*AudioFW_entry_ptr = SWAPEND32(MIPS_AUDIO_FW_ENTRY_ADDR | MIPS_KSEG1BASE);
	flush_dcache_all();
	enable_clock(SOFT_RESET2_reg, _BIT0, CLOCK_ENABLE2_reg, _BIT4);
	
	pmx_call_bootm();

ERR:

	return CMD_RET_FAILURE; 
}
U_BOOT_CMD(
	bootp, 2, 0,	pmx_do_bootp, 
	"boot from hard disk",
	"\tr	- boot from recovery\n"
);
#endif

#ifdef CONFIG_PMX_NANDFLASH
#define BUF_MAX 256

extern char usb_started; // from usb.c

static int pmx_call_bootm(void)
{
	char *bootm_argv[] = { "bootm", NULL, "-", NULL, NULL };
	int ret = 0;
	int j;
	int argc=4;
	char buf[BUF_MAX];

	bootm_argv[1] = (char*) malloc(sizeof(char) * 32);
	snprintf(bootm_argv[1], BUF_MAX, "%x", CONFIG_KERNEL_LOADADDR);
	bootm_argv[3] = (char*) malloc(sizeof(char) * 32);
	snprintf(bootm_argv[3], BUF_MAX, "%x", CONFIG_FDT_LOADADDR);

	printf("bootm_argv ={ ");
	for (j = 0; j < argc; j++)
			printf("%s,",bootm_argv[j]);
	printf("}\n");
	
	ret = do_bootm(find_cmd("do_bootm"), 0, argc,bootm_argv);


	if (ret) {
		printf("ERROR do_bootm failed!\n");
		return -1;
	}
    
    /* Should not reach here*/
	return 1;
}
int pmx_check_fw_in_usb_flash(PMX_FIRMWARE f){
	char tmpcmdline[BUF_MAX];
	char * tmp_addr;
	boot_config_t configs;

	pmx_prepare_config(&configs, f);
	if(!usb_started){
		if(run_command("usb start", 0) != 0){
			return -1;
		}
	}
	if (configs.kernel != NULL){
		printf("[PMX] Check kernel...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_KERNEL_LOADADDR, configs.kernel);
		if(run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	if (configs.dtb != NULL){
		printf("[PMX] Check DTB...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_FDT_LOADADDR, configs.dtb);
		if (run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	if (configs.rootfs != NULL){
		printf("[PMX] Check Rootfs...\n");
		snprintf(tmpcmdline, BUF_MAX, "fatload usb 0:1 %x %s", CONFIG_ROOTFS_LOADADDR, configs.rootfs);
		if(run_command(tmpcmdline, 0) != 0)
			return -1;
	}
	return 0;
}

char * pmx_get_bootup_partition(void){
    char * partition;
    partition = (char *)malloc(sizeof(char) * 4);
    snprintf(partition, 4, "2:1");
    return partition;
}

int pmx_prepare_config(boot_config_t * configs, PMX_FIRMWARE f){
	switch(f){
		case PMX_NORMAL_FIRMWARE:
			printf("[PMX] prepare normal firemware config...\n");
			configs->kernel = CONFIG_NORMAL_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_NORMAL_FROM_USB_DTB;
			configs->rootfs = NULL;
			break;
#ifdef CONFIG_BOOTCODE2
		case PMX_RECOVERY_USB3_FIRMWARE:
			printf("[PMX] prepare recovery config...\n");
			configs->kernel = CONFIG_RESCUE_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_RESCUE_FROM_USB_DTB;
			configs->rootfs = CONFIG_RESCUE_FROM_USB_ROOTFS;
			break;
#endif
#ifdef CONFIG_BOOTCODE
		case PMX_RECOVERY_USB2_FIRMWARE:
			configs->kernel = CONFIG_RECOVERY_FROM_USB_VMLINUX;
			configs->dtb = CONFIG_RECOVERY_FROM_USB_DTB;
			configs->rootfs = CONFIG_RECOVERY_FROM_USB_ROOTFS;
			break;
#endif
		default:
			configs->kernel = NULL;
			configs->dtb = NULL;
			configs->rootfs = NULL;
	}
	return 0;
}

int pmx_read_fw_from_usb(boot_config_t * configs){
    char buf[BUF_MAX];

	if(!usb_started){
		if(run_command("usb start", 0) != 0){
			return -1;
		}
	}
	if (configs->dtb != NULL){
    	printf("fatload usb %s %x %s", 
    		pmx_get_bootup_partition(), CONFIG_FDT_LOADADDR, configs->dtb);
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
    		pmx_get_bootup_partition(), CONFIG_FDT_LOADADDR, configs->dtb);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
    	PMX_DEBUG("load DTB from %s to address %x", configs->dtb, CONFIG_FDT_LOADADDR)
	}
	if (configs->kernel != NULL){
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
            pmx_get_bootup_partition(), CONFIG_KERNEL_LOADADDR, configs->kernel);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
    PMX_DEBUG("load DTB from %s to address %x", configs->kernel, CONFIG_KERNEL_LOADADDR)
	}
	if (configs->rootfs != NULL){
    	snprintf(buf, BUF_MAX, "fatload usb %s %x %s", 
            pmx_get_bootup_partition(), CONFIG_ROOTFS_LOADADDR, configs->rootfs);
		if(run_command(buf, 0) != 0){
			return -1;
    	}
    PMX_DEBUG("load DTB from %s to address %x", configs->kernel, CONFIG_ROOTFS_LOADADDR)
	}
    return 0;
}

int pmx_prepare_fw_from_usb(PMX_BOOTUP_STATE s){
    boot_config_t configs;    

	switch(s){
		case PMX_BOOTUP_NORMAL:
			pmx_prepare_config(&configs, PMX_NORMAL_FIRMWARE);
			break;
		case PMX_BOOTUP_RECOVERY:
			pmx_prepare_config(&configs, PMX_RECOVERY_USB2_FIRMWARE);
			break;
	}
	
    if(pmx_read_fw_from_usb(&configs) != 0){
        return -1;
    }
    return 0;
}

int pmx_prepare_fw_from_nand(PMX_BOOTUP_STATE s){
    boot_config_t configs;    
	char buf[BUF_MAX];
	switch(s){
		case PMX_BOOTUP_NORMAL:
    	snprintf(buf, BUF_MAX, "nand read %x 1580000 20000", 
    		CONFIG_FDT_LOADADDR);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
    	snprintf(buf, BUF_MAX, "nand read %x 15a0000 460000", 
    		CONFIG_KERNEL_LOADADDR);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
			break;
		case PMX_BOOTUP_RECOVERY:
    	snprintf(buf, BUF_MAX, "nand read %x d80000 20000", 
    		CONFIG_FDT_LOADADDR);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}
    	snprintf(buf, BUF_MAX, "nand read %x da0000 7E0000", 
    		CONFIG_KERNEL_LOADADDR);
    	if(run_command(buf, 0) != 0){
        	return -1;
    	}    	
			break;
	}
	return 0;
}

int pmx_do_bootp(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    int ret = -1; 

	printf("[PMX] %d \n", argc);
	if (argc == 2){
		if (argv[1][0] == 'r'){
			ret = pmx_prepare_fw_from_nand(PMX_BOOTUP_RECOVERY);
		}
		else if (argv[1][0] == 'g'){
			ret = pmx_prepare_fw_from_nand(PMX_BOOTUP_NORMAL);
		}
		else if (argv[1][0] == 'u'){
			ret = pmx_prepare_fw_from_usb(PMX_BOOTUP_RECOVERY);
		}
	}
	else{
		return CMD_RET_USAGE;
	}
    if (ret != 0){
        return ret; 
    }
	pmx_call_bootm();

	return ret;
}
U_BOOT_CMD(
	bootp, 2, 0,	pmx_do_bootp, 
	"boot from nandflash or usb",
    "[r/g/u]\n"
	"\tr	- boot from recovery\n"
	"\tg	- boot from normal\n"
	"\tu	- boot from usb\n"
);
#endif
