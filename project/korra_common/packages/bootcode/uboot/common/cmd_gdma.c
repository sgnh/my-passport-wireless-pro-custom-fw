
#include <command.h>
#include <common.h>
#include <asm/arch/flash_writer_u/mcp.h>
#include <asm/arch/factorylib_ro.h>
#include <asm/arch/system.h>
#include <malloc.h>

#define printk printf

typedef struct _GDMA_WIN_NEXT_ADDR
{
    unsigned int addr:31 ;
    unsigned int last:1 ;
} GDMA_WIN_NEXT_ADDR ;

typedef struct _GDMA_WIN_XY
{
    unsigned int x:16 ;
    unsigned int y:16 ;
} GDMA_WIN_XY ;

typedef struct _GDMA_WIN_WH
{
    unsigned int width:16 ;
    unsigned int height:16 ;
} GDMA_WIN_WH ;

typedef struct
{
    unsigned int type:5 ;
    unsigned int reserved2:2 ;
    unsigned int compress:1;
    unsigned int keepPreCLUT:1 ;
    unsigned int littleEndian:1 ;
    unsigned int clut_fmt:1 ;
    unsigned int reserved1:5 ;
    unsigned int alpha:8 ;
    unsigned int objType:1 ;
    unsigned int reserved0:1 ;
    unsigned int alphaEn:1 ;
    unsigned int alphaType:1 ;
    unsigned int rgbOrder:3 ;
    unsigned int extendMode:1 ;
} GDMA_WIN_ATTR ;

typedef struct _GDMA_WIN_KEY
{
    unsigned int key:24 ;
    unsigned int keyEn:1 ;
    unsigned int reserved:7 ;
} GDMA_WIN_KEY ;

typedef struct _GDMA_WIN_INIT
{
    unsigned int objXoffset:16 ;
    unsigned int objYoffset:16 ;
} GDMA_WIN_INIT ;

typedef struct
{
    unsigned int reserved:6 ;
    unsigned int id:8 ;
    unsigned int previd:8 ;
    unsigned int nextid:8 ;
    unsigned int drawn:1 ;
    unsigned int occupied:1 ;
} GDMA_WIN_CTRL ;

typedef struct
{
    GDMA_WIN_NEXT_ADDR nxtAddr ;

    GDMA_WIN_XY winXY ;
    GDMA_WIN_WH winWH ;

    GDMA_WIN_ATTR attr ;
    unsigned int CLUT_addr ;
    GDMA_WIN_KEY colorKey ;
    unsigned int top_addr ;
    unsigned int bot_addr ;
    unsigned int pitch ;
    GDMA_WIN_INIT objOffset ;

    GDMA_WIN_CTRL ctrl __attribute__((aligned(16))) ;
    unsigned int srcImg[2] ;
    unsigned short srcPitch[2] ;
    unsigned short dst_x;
    unsigned short dst_y;
    unsigned int dst_width;
    unsigned int dst_height;
} GDMA_WIN ;

//magellan
#if 1
#define GDMA_OSD1_reg  0xB802F204
#define GDMA_OSD2_reg  0xB802F304
#define OSDOVL_MIXER_CTRL2_VADDR 0xb802b000

#define GDMA_OSD1_CTRL_reg 0xB802F200
#define GDMA_OSD1_WI_reg 0xB802F210
#define GDMA_OSD1_SIZE_reg 0xB802F218
#define GDMA_CTRL_reg 0xB802F004
#define GDMA_INTST_reg 0xB802F484

//mac
#else
#endif

GDMA_WIN OSDwin;
unsigned int fillcolor1[1920*1080];
GDMA_WIN *win = &OSDwin ; /* update picture info to register */
static int width=1920;
static int height=1080;

int gdma_ddr (void)
{
    int ret, i, iloop, jloop ;
    for(iloop=0; iloop<width*height; iloop++)
    {
        jloop = iloop%1920;
        if(jloop<400)
        {
            fillcolor1[iloop] = 0xffff0000;    //Red
        }
        else if((jloop>=400)&&(jloop<800))
        {
            fillcolor1[iloop] = 0xff00ff00;    //Green
        }
        else if((jloop>=800)&&(jloop<1200))
        {
            fillcolor1[iloop] = 0xff0000ff;    //Blue
        }
        else if((jloop>=1200)&&(jloop<1600))
        {
            fillcolor1[iloop] = 0xffffff00;    //yellow
        }
        else if((jloop>=1600)&&(jloop<1920))
        {
            fillcolor1[iloop] = 0xffff00ff;    //Green
        }
    }
    return 0;
}

int do_gdma_1 (void)
{
    printk("testGDMA 2k1k\n");

    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_OSD1_reg )  =0x10001;// *((u32*)&gdma->GDMA_osd); 0xB802F204

    /* enable OSD1/OSD2 on Mixer */
    *(volatile u32*)GET_MAPPED_RBUS_ADDR(OSDOVL_MIXER_CTRL2_VADDR )= 0x1111;//*(volatile u32*)&mixer_ctrl2;  0xb802b000

    win->nxtAddr.addr = 0 ;
    win->nxtAddr.last = 1 ;
    win->winXY.x = 0;
    win->winXY.y = 0;
    win->winWH.width = width ;
    win->winWH.height = height ;
    win->attr.extendMode = 0 ;
    win->attr.rgbOrder = 0 ;
    win->attr.objType = 0 ;
    win->attr.type =7;
    win->attr.littleEndian = 1 ;
    win->attr.alphaEn = 0 ;
    win->pitch = 0x1e00 ;
    win->objOffset.objXoffset =0 ;
    win->objOffset.objYoffset = 0 ;

    win->attr.compress = 0;

    win->colorKey.keyEn = 0 ;
    win->colorKey.key = 0xffffff ;
    win->top_addr = fillcolor1 ;        //win->top_addr = dvr_to_phys(picObj->address) + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch ;

    //__asm__ __volatile__ ("dsb" : : : "memory");

    //udelay (5000000);//5s

    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_OSD1_CTRL_reg )  = ~1 ;
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_OSD1_CTRL_reg )  =
        (0x00000001&((1)<<0)) | (0x00000002&((1)<<1)) |(0x00000008&((0)<<3)) | (0x00000004&((0)<<2)) | (0x00000100&((0)<<8));

    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_OSD1_WI_reg )    = (unsigned int) win  ;
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_OSD1_SIZE_reg )  = (0x1FFF0000&((width)<<16)) | (0x00001FFF&((height)<<0));
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( GDMA_CTRL_reg ) =(0x00000001&((1)<<0)) | (0x00000040&((1)<<6));

    return CMD_RET_SUCCESS;
}


int do_gdma_2 (void)
{

    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F204 )  =0x10001;// *((u32*)&gdma->GDMA_osd); 0xB802F204
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F304 )  = 0x10001;//*((u32*)&gdma->GDMA_osd);0xB802F304

    /* enable OSD1/OSD2 on Mixer */
    *(volatile u32*)GET_MAPPED_RBUS_ADDR(0xb802b000 )= 0x1111;//*(volatile u32*)&mixer_ctrl2;  0xb802b000
    //printk("GDMA_OSD1_reg=%x\n",*((u32*)&gdma->GDMA_osd));
    __asm__ __volatile__ ("dsb" : : : "memory");

    
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F200 )  = ~1 ;
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F200 )  =
        (0x00000001&((1)<<0)) | (0x00000002&((1)<<1)) |(0x00000008&((0)<<3)) | (0x00000004&((0)<<2)) |
        (0x00000100&((0)<<8));


    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F218 )  = (0x1FFF0000&((1920)<<16)) | (0x00001FFF&((1080)<<0));
    *(volatile u32*)GET_MAPPED_RBUS_ADDR( 0xB802F004 ) =(0x00000001&((1)<<0)) | (0x00000040&((1)<<6));
    *(volatile u32*)GET_MAPPED_RBUS_ADDR(0xB802F484 ) =  (0x00000001&((0)<<0)) | (0x00000080&((1)<<7)) ;

    return CMD_RET_SUCCESS;
}


int do_gdma (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    gdma_ddr();
    do_gdma_1();
    gdma_ddr();

    //do_gdma_1();
    return CMD_RET_SUCCESS;
}

U_BOOT_CMD
(
    gdma, 2, 1,   do_gdma,
    "gdma test",
    "gdma\n"
);

