#include <command.h>
#include <common.h>
#include <asm/arch/io.h>

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

int do_identify_s(void **dev);
int do_init_s(void *dev);
int do_erase_s (void *dev, unsigned int* dest, unsigned int   rem_size);
void do_exit_s (void *dev);
int do_read_s (void *dev,unsigned int* src,unsigned char* dst,unsigned int   size);


int do_flash_read (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    int rcode = CMD_RET_SUCCESS;
    unsigned int src,dst,len;
    void *device;

    int (*do_identify)(void **);
    int (*do_read) (void *dev,unsigned int* src,unsigned char* dst,unsigned int   size);
    void (*do_exit)(void *dev);
    int (*do_init)(void *);

    do_identify = do_identify_s;
    do_init = do_init_s;
    do_read = do_read_s;
    do_exit = do_exit_s;


    //printf("argc=%d     argv[0]=%s   argv[1]=%s\n",argc,argv[0],argv[1]);

#if 1
    if (argc != 4)
    {
        return CMD_RET_USAGE;
    }
#endif

    src = simple_strtoul(argv[1], NULL, 16);
    dst = simple_strtoul(argv[2], NULL, 16);
    len = simple_strtoul(argv[3], NULL, 16);

    printf("spi flash read:         from[%x]  to[%x]   len=%x \n",src,dst,len);
    src+=0xb8100000;
    //addr+=0xb8100000;
    get_boot_flash_type();

    {
        //dump 'Begin' string to RS232 to notify uset that flash write start to program
        puts("Begin:\n");

        /*******************************************************
         * free SPI control to ACPU
         *******************************************************/
        //print_uart("\nRelease HW semaphore....");
        *((volatile unsigned int *)MIPS_AUDIO_FW_ENTRY_PTR_ADDR) =0;
        rtd_outl(0xb801a000, 0x0);
        udelay(20);
        //rtd_outl(0xb801a000, 0x0);
        puts("Done\n");

        /*******************************************************
         * identyfy flash type and program code to flash device
         *******************************************************/
        set_spi_pin_mux();

        puts("do_identify\n");
        if ((*do_identify)(&device) < 0)
        {
            puts("error identify flash!!\n");
            return CMD_RET_FAILURE;
        }

        puts("do_init\n");
        (*do_init)(device);

        puts("do_read\n");
        if ((*do_read) (device,(UINT32 *) src,(UINT32 *)dst,len) !=0 )
        {
            return CMD_RET_FAILURE;
        }

        /* Reset Command */
        puts("do_exit\n");
        (*do_exit)(device);

        //dump 'Finish' string to RS232
        puts("Finish\n");
    }


    return rcode;
}

#if 0
cmd_tbl_t __u_boot_cmd_fr __attribute__((unused, section(".u_boot_cmd"), aligned(4))) =
{
    "fr",
    4,
    1,
    do_flash_read,
    "read spi nor flash data(\e[1;31msrc\e[0m) to DDR(\e[1;31mdst\e[0m)",//"write data to spi nor flash",
    "src dst len",
    ((void *)0),
};
#else
U_BOOT_CMD
(
	fr, 4, 1,	do_flash_read,
	"read spi nor flash data(\e[1;31msrc\e[0m) to DDR(\e[1;31mdst\e[0m)",
	"src dst len"
);
#endif

