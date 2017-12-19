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


int do_flash_erase (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    int rcode = CMD_RET_SUCCESS;
    unsigned int addr,len;
    void *device;

    int (*do_identify)(void **);
    int (*do_erase)(void  *, UINT32 * , UINT32);
    void (*do_exit)(void *dev);
    int (*do_init)(void *);

    do_identify = do_identify_s;
    do_init = do_init_s;
    do_erase = do_erase_s;
    do_exit = do_exit_s;


    //printf("argc=%d     argv[0]=%s   argv[1]=%s\n",argc,argv[0],argv[1]);

#if 1
    if (argc != 3)
    {
        return CMD_RET_USAGE;
    }
#endif

    addr = simple_strtoul(argv[1], NULL, 16);
    len = simple_strtoul(argv[2], NULL, 16);

    printf("spi flash erase: addr=%x,len=%x   \n",addr,len);
    addr+=0xb8100000;

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

        puts("do_erase\n");//0xb8100000
        if ((*do_erase)(device, (UINT32 *)addr, len) !=0 )
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
cmd_tbl_t __u_boot_cmd_fe __attribute__((unused, section(".u_boot_cmd"), aligned(4))) =
{
    "fe",
    3,
    1,
    do_flash_erase,
    "erase spi nor flash",//"write data to spi nor flash",
    "addr len",
    ((void *)0),
};
#else
U_BOOT_CMD
(
	fe, 3, 1,	do_flash_erase,
	"erase spi nor flash",
	"addr len"
);

#endif

