#include <command.h>
#include <common.h>
#include <asm/arch/io.h>

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;


int do_identify_s(void **dev);
int do_init_s(void *dev);
int do_write_s(void *dev,unsigned char* array_ptr, unsigned int* dest,unsigned int   rem_size, unsigned int   signature, const unsigned int page_offset);
void do_exit_s (void *dev);
int do_erase_s(void *dev,unsigned int* dest, unsigned int   rem_size);
extern unsigned long NetBootFileXferSize;

int do_flash_write (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    int rcode = CMD_RET_SUCCESS;
    unsigned int src,dst,len,length;
    void *device;

    int (*do_identify)(void **);
    int (*do_write)(void *, UINT8 *, UINT32 *, UINT32, UINT32, const UINT32);
    void (*do_exit)(void *dev);
    int (*do_init)(void *);
    int (*do_erase)(void  *, UINT32 * , UINT32);

    do_identify = do_identify_s;
    do_init = do_init_s;
    do_write = do_write_s;
    do_exit = do_exit_s;
    do_erase = do_erase_s;


    //printf("argc=%d     argv[0]=%s   argv[1]=%s\n",argc,argv[0],argv[1]);

    if (argc != 4)
    {
        return CMD_RET_USAGE;
    }
    #if 0
    else if (NetBootFileXferSize==0)
    {
        puts("error:    no data transfered by tftp!\n");
        return CMD_RET_USAGE;
    }
    #endif

    src = simple_strtoul(argv[1], NULL, 16);
    dst = simple_strtoul(argv[2], NULL, 16);
    length = simple_strtoul(argv[3], NULL, 16);

    printf("spi flash wrtie  from[%x]  to[%x]   len[%x]\n",src,dst,length);
    dst+=0xb8100000;
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

        //printf("NetBootFileXferSize=        %ld (%lx hex)\n",NetBootFileXferSize,NetBootFileXferSize);

        puts("do_erase\n");//0xb8100000
        len = ((length + 0xFFFF) >> 16); //len = ((NetBootFileXferSize + 0xFFFF) >> 16);
        len <<= 16;
        if ((*do_erase)(device, (UINT32 *)dst, len) !=0 )
        {
            return CMD_RET_FAILURE;
        }

        puts("do_write\n");//0xb8100000
        if ((*do_write)(device, (UINT8 *)src, (UINT32 *)dst, length, 0, 0) !=0 )
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
cmd_tbl_t __u_boot_cmd_fw __attribute__((unused, section(".u_boot_cmd"), aligned(4))) =
{
    "fw",
    3,
    1,
    do_flash_write,
    "write DDR data(\e[1;31msrc\e[0m) to spi nor flash(\e[1;31mdst\e[0m)",//"write data to spi nor flash",
    "src dst",
    ((void *)0),
};
#else
U_BOOT_CMD
(
	fw, 4, 1,	do_flash_write,
	"write DDR data(\e[1;31msrc\e[0m) to spi nor flash(\e[1;31mdst\e[0m)",
	"src dst len"
);

#endif

