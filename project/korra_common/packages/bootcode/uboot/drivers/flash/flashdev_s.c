#include <common.h>
#include <asm/arch/system.h>
//#include <linux/types.h>

#include "flash_spi_list.h"
#include "mis_reg.h"
#include "platform_iso.h"

#undef printf

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;


static void switch_read_mode(void)
{
    //rtd_outl(0xb801a800,0x00000003; //switch flash to read mode
    rtd_outl(0xb801a800, 0x00000003);
    rtd_outl(0xb801a804, 0x00000018); //command cycle
}



#ifdef FAKE_SPI_API
int do_erase_s(void *dev,
               unsigned int* dest,
               unsigned int   rem_size)
{

    return 0;

}


int do_write_s(void *dev,
               unsigned char* array_ptr,
               unsigned int* dest,
               unsigned int   rem_size,
               unsigned int   signature,
               const unsigned int page_offset)
{
    return 0;
}

int do_identify_s(void **dev)
{

    return 0;

}


int do_init_s(void *dev)
{

    return 0;

}
void do_exit_s(void *dev)
{

}

#else
/************************************************************************
 *
 *                          do_erase_s
 *  Description :
 *  -------------
 *  implement the flash erase
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int get_boot_flash_type(void)
{
    int state, boottype;
    int reg_val, tmp;

    //To do: check GPI register from HW

    /* get boot_type (from GPIO) */
    tmp = rtd_inl(GPIO_MUXCFG_22);
    state = rtd_inl(MIS_GP3DIR);
    rtd_outl(GPIO_MUXCFG_22, (tmp |= 0x00f0f000));  // set  mux to GPIO[118:117]
    rtd_outl(MIS_GP3DIR, (state & ~0x600000));      // set GPIO[118:117] as input pin
    reg_val = rtd_inl(MIS_GP3DATI);
    /* get boottype type from GPIO [118:117]*/
    boottype = (reg_val >> 21) & 0x3;
    rtd_outl(MIS_GP3DIR, state);    // restore GPIO[118:17] direction
    rtd_outl(GPIO_MUXCFG_22, tmp); // restore pin mux

    return 0;
#if 0
    switch(boottype)
    {
        case 0:
            return FLASH_TYPE_NAND;
        case 1:
            return FLASH_TYPE_SPI;
        case 2:
            return FLASH_TYPE_EMMC;
        default:    // should be impossible...
            return FLASH_TYPE_SPI;
    }
#endif

}



void set_spi_pin_mux(void)
{
    //use uboot setting
#if 1

    int reg_val;

    // set GPIO_122_ps[15:12] to "  0: SPI_CS_N,<O>"
    // set GPIO_123_ps[7:4] to "    0: SPI_SCLK,<O>"
    reg_val = rtd_inl(GPIO_MUXCFG_23) & 0xffff0f0f;
    rtd_outl(GPIO_MUXCFG_23, reg_val);

    // set GPIO_125_ps[23:20] to "  0: SPI_DI,<I/O>"
    // set GPIO_126_ps[15:12] to "  0: SPI_DO,<I/O>"
    reg_val = rtd_inl(GPIO_MUXCFG_24) & 0xff0f0fff;
    rtd_outl(GPIO_MUXCFG_24, reg_val);
#endif
}
int swap_endian(UINT32 input)
{
    UINT32 output;

    output = (input & 0xff000000)>>24|
             (input & 0x00ff0000)>>8|
             (input & 0x0000ff00)<<8|
             (input & 0x000000ff)<<24;

    return output;
}


void copy_memory(void *dst, void *src, UINT32 size)
{
    UINT32 i;
    for (i=0; i<size; i++)
    {
        rtd_outb((((UINT32)dst) + i) , rtd_inb(((UINT32)src) + i));
    }
}



int do_erase_s(void *dev,
               unsigned int* dest,
               unsigned int   rem_size)
{
    volatile unsigned char tmp;
    unsigned int size;
    s_device_type *device = (s_device_type *)dev;
    unsigned char *loc;

    loc = (unsigned char *) dest;
    while(rem_size > 0)
    {
        /* show '/' in console */
        rtd_outl(UART0_REG_BASE, 0x2f) ; //cy test

        /* write enable */
        rtd_outl(0xb801a800,0x00520006);
        rtd_outl(0xb801a804,0x00180000);
        //tmp = *loc;
        tmp = rtd_inb(loc);


        //image size >= 256K
        if (rem_size >= 0x40000)
        {
            if (device->sec_256k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x40000;
            }
            else if (device->sec_64k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x10000;
            }
            else if (device->sec_32k_en == 1)
            {
                rtd_outl(0xb801a800,0x00000052);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x8000;
            }
            else if (device->sec_4k_en == 1)
            {
                if (device->id==PMC_4Mbit)
                {
                    rtd_outl(0xb801a800,0x000000d7);
                }
                else
                {
                    rtd_outl(0xb801a800,0x00000020);
                }

                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x1000;
            }
        }
        //256K > image size >= 64K
        else if ((0x40000 > rem_size) && (rem_size >= 0x10000))
        {
            if (device->sec_64k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x10000;
            }
            else if (device->sec_32k_en == 1)
            {
                rtd_outl(0xb801a800,0x00000052);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x8000;
            }
            else if (device->sec_4k_en == 1)
            {
                if (device->id==PMC_4Mbit)
                {
                    rtd_outl(0xb801a800,0x000000d7);
                }
                else
                {
                    rtd_outl(0xb801a800,0x00000020);
                }

                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x1000;
            }
            else if (device->sec_256k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x40000;
            }
        }
        //64K > image size >= 32K
        else if ((0x10000 > rem_size) && (rem_size >= 0x8000))
        {
            if (device->sec_32k_en == 1)
            {
                rtd_outl(0xb801a800,0x00000052);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x8000;
            }
            else if (device->sec_4k_en == 1)
            {
                if (device->id==PMC_4Mbit)
                {
                    rtd_outl(0xb801a800,0x000000d7);
                }
                else
                {
                    rtd_outl(0xb801a800,0x00000020);
                }

                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x1000;
            }
            else if (device->sec_64k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x10000;
            }
            else if (device->sec_256k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x40000;
            }
        }
        //32K > image size
        else if (0x8000 > rem_size)
        {

            if (device->sec_4k_en == 1)
            {
                if (device->id==PMC_4Mbit)
                {
                    rtd_outl(0xb801a800,0x000000d7);
                }
                else
                {
                    rtd_outl(0xb801a800,0x00000020);
                }

                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x1000;
            }
            else if (device->sec_32k_en == 1)
            {
                rtd_outl(0xb801a800,0x00000052);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x8000;
            }
            else if (device->sec_64k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x10000;
            }
            else if (device->sec_256k_en == 1)
            {
                rtd_outl(0xb801a800,0x000000d8);
                rtd_outl(0xb801a804,0x00000008);
                tmp = rtd_inb(loc);
                size = 0x40000;
            }
        }

        /* read status registers until write operation completed*/
        do
        {
            rtd_outl(0xb801a800,0x00000005);
            rtd_outl(0xb801a804,0x00000010);
        }
        while((tmp = rtd_inb(loc))&0x1);

        size = (rem_size > size)? size : rem_size ;
        rem_size-=size;

        loc+=size;
    }

    return 0;
}

int do_read_s (void *dev,unsigned int* src,unsigned char* dst,unsigned int   size)
{
    int i = 0;
    s_device_type *device = (s_device_type *)dev;
    unsigned char *loc;

    loc = (unsigned char *)src;

    //add by angus
    rtd_outl(0xb801a81c,    0x00000106);
    rtd_outl(0xb801a818,    0x00000105);
    rtd_outl(0xb801a80c,    0x00ffffff);

    //issue read command
    rtd_outl(0xb801a800,  0x03);
    rtd_outl(0xb801a804,  0x00000018);

    // if dest address is not on 256 byte boundary, use byte program until reach boundary
    while ((((UINT32)loc) & 0xff) && (size > 0))
    {
        *dst++=rtd_inb(loc++);//rtd_inb(loc++ , *array_ptr++);
        size--;
    }


    //if flash support page program, we can use page program to reduce program time
    if (device->page_program)
    {
        //if writing data greater than one page(256 bytes)
        while(size >= 256)
        {
#ifdef ENABLE_UART_FUNC
            /* show '.' in console */
            if ( !(i++ % 4))
            {
                rtd_outl(UART0_REG_BASE, 0x2f) ;    //cy test
            }
#endif

            copy_memory((UINT8 *)dst, loc, 256);

            /* shift to next page to writing */
            dst+=256;
            loc+=256;
            size-=256;

        }//end of page program

    }//end of page program


    /* left data in-sufficient to one page, we write it using byte program
       or flash doesn't support page program mode */
    while(size--)
    {
#ifdef ENABLE_UART_FUNC
        /* show '.' in console */
        if ((size % 1024 )== 1023)
        {
            rtd_outl(UART0_REG_BASE, 0x2e) ;    //cy test
        }
#endif

        *dst++=rtd_inb(loc++);//rtd_outb(loc++ , *array_ptr++);
    }


    return 0;
}



/************************************************************************
 *
 *                          do_write
 *  Description :
 *  -------------
 *  implement the flash write
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int do_write_s(void *dev,
               unsigned char* array_ptr,
               unsigned int* dest,
               unsigned int   rem_size,
               unsigned int   signature,
               const unsigned int page_offset)
{
    int i = 0;
    s_device_type *device = (s_device_type *)dev;
    unsigned char *loc;

    loc = (unsigned char *)dest;

    //add by angus
    rtd_outl(0xb801a81c,    0x00000106);
    rtd_outl(0xb801a818,    0x00000105);
    rtd_outl(0xb801a80c,    0x00ffffff);

    //issue write command
    rtd_outl(0xb801a800,  0x00000002);
    rtd_outl(0xb801a804,  0x00000018);

    // if dest address is not on 256 byte boundary, use byte program until reach boundary
    while ((((UINT32)loc) & 0xff) && (rem_size > 0))
    {
        rtd_outb(loc++ , *array_ptr++);
        rem_size--;
    }



    //if flash support page program, we can use page program to reduce program time
    if (device->page_program)
    {
        //if writing data greater than one page(256 bytes)
        while(rem_size >= 256)
        {
#ifdef ENABLE_UART_FUNC

            /* show '.' in console */
            if ( !(i++ % 4))
            {
                rtd_outl(UART0_REG_BASE, 0x2f) ;    //cy test
            }
#endif

            copy_memory((UINT8 *)loc, array_ptr, 256);

            /* shift to next page to writing */
            array_ptr+=256;
            loc+=256;
            rem_size-=256;

        }//end of page program

    }//end of page program


    /* left data in-sufficient to one page, we write it using byte program
       or flash doesn't support page program mode */
    while(rem_size--)
    {
#ifdef ENABLE_UART_FUNC
        /* show '.' in console */
        if ((rem_size % 1024 )== 1023)
        {
            rtd_outl(UART0_REG_BASE, 0x2e) ;    //cy test
        }
#endif

        rtd_outb(loc++ , *array_ptr++);
    }


    return 0;
}

/************************************************************************
 *
 *                          do_identify_s
 *  Description :
 *  -------------
 *  implement the identyfy flash type
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int do_identify_s(void **dev)
{
    UINT32 id;
    UINT32 idx;

    //UINT8 * temp_ptr = (UINT8 *)0xbfc10000;
    UINT8 * temp_ptr = (UINT8 *)0xb8100000;
    //aaa
    //printf("@drivers/flash:             do_identify_s\n");//puts("@drivers/flash:             do_identify_s\n");


    /* switch to in-order mode */
    asm("DSB");
    //disable w-merge and r-bypass
    rtd_outl(0xb801a018,((rtd_inl(0xb801a018) | 0x80008 ) & ~0x30003));
    asm("DSB");
    rtd_outl(0xb801a018, (rtd_inl(0xb801a018) | 0xc000c));
    asm("DSB");



    rtd_outl(0xb801a814,0x00000001);   //set serial flash controller latch data at rising edge

    //remove this, due to we already set this register at hw-setting
    //rtd_outl(0xb801a808,0x0101000f);   //lowering frequency, setup freq divided no

    rtd_outl(0xb801a80c,0x00090101);   //setup control edge

    /* read Manufacture & device ID */
    rtd_outl(0xb801a800,0x0000009f);
    rtd_outl(0xb801a804,0x00000010);
    id = swap_endian(rtd_inl((UINT32 *)temp_ptr));
    id >>= 8;
    //printf("\nflash id [0x%x]\n", id);
    /* find the match flash brand */
    for (idx = 0; idx < DEV_SIZE_S; idx++)
    {
        if ( s_device[idx].id == id )
        {
            //special case: the same id have two mode, check ext-id
            if (id == SPANSION_128Mbit)
            {
                /* read extended device ID */
                rtd_outl(0xb801a800,0x0000009f);
                rtd_outl(0xb801a804,0x00000013);
                id = rtd_inl((UINT32 *)temp_ptr);
                id >>= 16;
                printf("\textension id [0x%x]\n", id);
                continue;
            }

            *dev = (void *)&s_device[idx];
            return 0;
        }
    }



    //device not found, down freq and try again
    if (idx == DEV_SIZE_S)
    {
        rtd_outl(0xb801a800,0x00000090);  //read id
        rtd_outl(0xb801a804,0x00000010);  //issue command
        id = rtd_inl((UINT32 *)temp_ptr);
        id >>= 16;

        for (idx = 0; idx < DEV_SIZE_S; idx++)
        {
            if ( s_device[idx].id == id )
            {
                //special case: the same id have two mode, check ext-id
                if (id == SPANSION_128Mbit)
                {
                    /* read extended device ID */
                    rtd_outl(0xb801a800,0x00000090);
                    rtd_outl(0xb801a804,0x0000001b);
                    id = rtd_inl((UINT32 *)temp_ptr);
                    id >>= 16;
                    continue;
                }

                *dev = (void *)&s_device[idx];
                return 0;
            }
        }

        if (idx == DEV_SIZE_S)
        {
            *dev = (void *)0x0;
            return -1;
        }
    }

    *dev = (void *)0x0;
    switch_read_mode();
    return -1;
}
/************************************************************************
 *
 *                          do_init_s
 *  Description :
 *  -------------
 *  implement the init flash controller
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int do_init_s(void *dev)
{
    UINT8 tmp;
    UINT8 * temp_ptr = (UINT8 *)0xb8100000;

    /* configure serial flash controller */
#if 1
    //asm(".set mips3");
    //asm("sync");
    asm("DSB");
    //asm(".set mips1");
    //disable w-merge and r-bypass
    rtd_outl(0xb801a018,((rtd_inl(0xb801a018) | 0x80008 ) & ~0x30003));
    //asm(".set mips3");
    //asm("sync");
    asm("DSB");
    //asm(".set mips1");
    //enable command inorder
    rtd_outl(0xb801a018, (rtd_inl(0xb801a018) | 0xc000c));
    //asm(".set mips3");
    //asm("sync");
    asm("DSB");
    //asm(".set mips1");

    rtd_outl(0xb801a80c,0x00090101);   //setup control edge

    rtd_outl(0xb801a810,0x00000000);    //disable hardware potection

#endif

    /* enable write status register */
    rtd_outl(0xb801a800,0x00000050);
    //puts("do_init       1\n");

    rtd_outl(0xb801a804,0x00000000);
    //puts("do_init       2\n");

    tmp = rtd_inb(temp_ptr);
    rtd_outb(temp_ptr, 0x0);
    //puts("do_init       3\n");

    /* write status register , no memory protection*/
    rtd_outl(0xb801a800,0x00000001);
    //puts("do_init       4\n");

    rtd_outl(0xb801a804,0x00000010);
    //puts("do_init       5\n");
    rtd_outb(temp_ptr, 0x0);

    return 0;
}
/************************************************************************
 *
 *                          do_exit_s
 *  Description :
 *  -------------
 *  implement the exit flash writing operation
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
void do_exit_s(void *dev)
{
    UINT8 tmp;
    UINT8 * temp_ptr = (UINT8 *)0xb8100000;

    switch_read_mode();

    tmp = rtd_inb(temp_ptr);
}


void do_bdinfo_spi (void)
{
    s_device_type dev;
    s_device_type *device=&dev;
    printf("\n*** bdinfo spi nor flash ***      \n");

    set_spi_pin_mux();

    //s_device_type *device = (s_device_type *)dev;

    #if 0
    *((volatile unsigned int *)MIPS_AUDIO_FW_ENTRY_PTR_ADDR) =0;
    rtd_outl(0xb801a000, 0x0);
    udelay(20);

    set_spi_pin_mux();

    do_init_s(NULL);
    #endif
    do_identify_s(&device);
    printf("SPI FLASH   =  %s   ",device->string);

    if (device->sec_256k_en)
    {
        printf("erase sector   =  256k \n");
    }
    else if (device->sec_64k_en)
    {
        printf("erase sector   =  64k \n");
    }
    else if (device->sec_32k_en)
    {
        printf("erase sector   =  32k \n");
    }
    else if (device->sec_4k_en)
    {
        printf("erase sector   =  4k \n");
    }
}


#endif
