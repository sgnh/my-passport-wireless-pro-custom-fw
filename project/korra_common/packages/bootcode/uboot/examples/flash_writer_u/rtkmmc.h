#ifndef __RTKMMC_H__
#define __RTKMMC_H__
#include "dvrboot_inc/util.h"

/************************************************************************
 * BOOT PART CONTROL
 * 0 for normal
 * 1 for boot partition 1
 * 2 for boot partition 2
*************************************************************************/
//#define EMMC_DEFAULT_BOOT_PART_SEL 0

/************************************************************************
 * DEBUG CONTROL
*************************************************************************/
#define EMMC_RTD299X
//#define EMMC_DEBUG
//#define EMMC_DEBUG_SHOWCMD
//#define EMMC_SHOW_CSD
//#define EMMC_SHOW_CID
//#define EMMC_SHOW_EXTCSD
#define EMMC_MAX_XFER_BLKCNT 256

/************************************************************************
 * CLOCK CONTROL
*************************************************************************/
#define EMMC_SOURCE_CLK			CARD_SWITCHCLOCK_49MHZ
#define EMMC_SOURCE_CLK_HI		CARD_SWITCHCLOCK_49MHZ
#define EMMC_INIT_CLOCK_DIV		CLOCK_DIV_256
#define EMMC_NORMAL_CLOCK_DIV	CLOCK_DIV_NON

/************************************************************************
 * PRINT MESSAGE CONTROL
*************************************************************************/
#define THIS_IS_FLASH_WRITE_U_ENV

#define EMMC_DRVNAME "emmc:"
#ifdef THIS_IS_FLASH_WRITE_U_ENV
	#include "sysdefs.h"
	#include "dvrboot_inc/util.h"
	#define UPRINTF(fmt, args...)			\
				if( rtprintf ) {			\
					rtprintf(fmt,## args);	\
				}
	#define EXT_CSD_CMD_SET_NORMAL		(1 << 0)
	#define EXT_CSD_CMD_SET_SECURE		(1 << 1)
	#define EXT_CSD_CMD_SET_CPSECURE	(1 << 2)
	#define EXT_CSD_CARD_TYPE_26		(1 << 0)
	#define EXT_CSD_CARD_TYPE_52		(1 << 1)
	#define EXT_CSD_BUS_WIDTH_1			0
	#define EXT_CSD_BUS_WIDTH_4			1
	#define EXT_CSD_BUS_WIDTH_8			2
#else
	#include <config.h>
	#include <common.h>
	#include <command.h>
	#include <mmc.h>
	#include <part.h>
	#include <malloc.h>
	#include <mmc.h>
	#include <asm/errno.h>
	#include <asm/io.h>
	#define UPRINTF(fmt, args...)			\
				printf(fmt,## args)
#endif

#ifdef EMMC_DEBUG
    #define mmcinfo(fmt, args...) \
               UPRINTF(EMMC_DRVNAME fmt,## args)
	#define mmcprintf(fmt, args...) \
               UPRINTF(fmt,## args)
#else
    #define mmcinfo(fmt, args...)
	#define mmcprintf(fmt, args...)
#endif

#ifdef EMMC_DEBUG_SHOWCMD
	#define mmcinfo_cmd(fmt, args...) \
				UPRINTF(EMMC_DRVNAME fmt,## args)
#else
	#define mmcinfo_cmd(fmt, args...)
#endif

/************************************************************************
 * MMC BIT DATA READING
*************************************************************************/
#define UNSTUFF_BITS(resp,start,size)                   						\
    ({                              											\
        const int __size = size;                								\
        const unsigned short __mask = (__size < 32 ? 1 << __size : 0) - 1; 		\
        const int __off = 3 - ((start) / 32);           						\
        const int __shft = (start) & 31;            							\
        unsigned short __res;                      								\
                                    											\
        __res = resp[__off] >> __shft;              							\
        if (__size + __shft > 32)               								\
            __res |= resp[__off-1] << ((32 - __shft) % 32); 					\
        __res & __mask;                     									\
    })

/************************************************************************
 * REALTEK CONTROL REGISTER ACCESSING METHOD
*************************************************************************/
#define cr_writel(value,addr)   	(*(volatile unsigned int *)(addr) = (value))
#define cr_writeb(value,addr)   	(*(volatile unsigned char *)(addr) = (value))
#define cr_readl(addr)          	REG32(addr)
#define cr_readb(addr)          	REG8(addr)

#define CP15ISB asm volatile ("mcr     p15, 0, %0, c7, c5, 4" : : "r" (0))
#define CP15DSB asm volatile ("mcr     p15, 0, %0, c7, c10, 4" : : "r" (0))
#define CP15DMB asm volatile ("mcr     p15, 0, %0, c7, c10, 5" : : "r" (0))

/************************************************************************
 *
*************************************************************************/
//error
#define CR_TRANSFER_FAIL            0x4
#define CR_TRANSFER_TO              0x1
#define CR_BUF_FULL_TO              0x2
#define CR_DMA_FAIL                 0x3

#define EMMC_VDD_1_8                		0x80        /* VDD voltage 1.8         */
#define EMMC_VDD_30_31  			0x00040000  /* VDD voltage 3.0 ~ 3.1 */
#define EMMC_VDD_31_32  			0x00080000  /* VDD voltage 3.1 ~ 3.2 */
#define EMMC_VDD_32_33  			0x00100000  /* VDD voltage 3.2 ~ 3.3 */
#define EMMC_VDD_33_34  			0x00200000  /* VDD voltage 3.3 ~ 3.4 */
#define EMMC_VDD_34_35  			0x00400000  /* VDD voltage 3.4 ~ 3.5 */
#define EMMC_VDD_35_36  			0x00800000  /* VDD voltage 3.5 ~ 3.6 */
#define MMC_CARD_READY   			0x80000000  /* Card Power up status bit */
#define MMC_SECTOR_ADDR  			0x40000000

#define EMMC_VDD_REQ    			EMMC_VDD_35_36|EMMC_VDD_34_35|EMMC_VDD_33_34|EMMC_VDD_32_33|EMMC_VDD_31_32|EMMC_VDD_30_31

//0x18012080 , CPU_ACC
#define CPU_MODE_EN                 (0x00000001)
#define BUF_SW_RENEW                (0x00000001<<1)
#define BUF_FULL                    (0x00000001<<2)

/* MMC configure1, for SD_CONFIGURE1 */
#define SD1_R0                      (SDCLK_DIV | SDCLK_DIV_256 | RST_RDWR_FIFO)

/* MMC configure3 , for SD_CONFIGURE3 */
#define SD2_R0                      (RESP_TIMEOUT_EN | ADDR_BYTE_MODE)

#define RESP_TIMEOUT            	(0x00000001<<3)
#define RESP_TIMEOUT_EN         	(0x00000001)
#define ADDR_BYTE_MODE              (0x00000001<<1) //byte mode

#define SRAM_BASE_ADDR              0x10000000
#define SRAM_SIZE                   (16*1024)
#define IS_SRAM_ADDR(addr)          ((addr>=SRAM_BASE_ADDR)&&(addr<SRAM_BASE_ADDR+SRAM_SIZE))
/* MMC response type, for SD_CONFIGURE2 */
#define SD_R0                   	RESP_TYPE_NON|CRC7_CHK_DIS|WR_CRC_ERR_DIS
#define SD_R1                   	RESP_TYPE_6B
//#define SD_R1b                  	RESP_TYPE_6B|WAIT_BUSY_EN
#define SD_R1b                  	RESP_TYPE_6B
#define SD_R2                   	RESP_TYPE_17B|CRC16_CAL_DIS
#define SD_R3                   	RESP_TYPE_6B|CRC7_CHK_DIS
//#define SD_R3                   	RESP_TYPE_6B|CRC7_CHK_DIS|WR_CRC_ERR_DIS
#define SD_R4                   	RESP_TYPE_6B
#define SD_R5                   	RESP_TYPE_6B

/* send status event */
#define STATE_IDLE      			0
#define STATE_READY     			1
#define STATE_IDENT     			2
#define STATE_STBY      			3
#define STATE_TRAN      			4
#define STATE_DATA      			5
#define STATE_RCV       			6
#define STATE_PRG       			7
#define STATE_DIS       			8
#define STATE_BTST      			9
#define STATE_SLP       			10

/* eMMC control register definition */
#define CR_BASE_ADDR             	0x18012000
#define DUMMY_SYS                   0x1801042c
#define CR_SRAM_CTL                 (CR_BASE_ADDR)
#define CR_DMA_CTL1                 ( CR_BASE_ADDR + 0x004 )
#define CR_DMA_CTL2                 ( CR_BASE_ADDR + 0x008 )
#define CR_DMA_CTL3                 ( CR_BASE_ADDR + 0x00C )
#define CR_PAD_CTL                  ( CR_BASE_ADDR + 0x074 )
#define CR_CPU_ACC                  ( CR_BASE_ADDR + 0x080 )
#define CR_CARD_STOP                ( CR_BASE_ADDR + 0x103 )
#define CARD_SELECT                 ( CR_BASE_ADDR + 0x10e )
#define CARD_SD_CLK_PAD_DRIVE	    ( CR_BASE_ADDR + 0x130 )
#define CARD_SD_CMD_PAD_DRIVE	    ( CR_BASE_ADDR + 0x131 )
#define CARD_SD_DAT_PAD_DRIVE	    ( CR_BASE_ADDR + 0x132 )
#define SD_CONFIGURE1               ( CR_BASE_ADDR + 0x180 )
#define SD_CONFIGURE2               ( CR_BASE_ADDR + 0x181 )
#define SD_CONFIGURE3               ( CR_BASE_ADDR + 0x182 )
#define SD_STATUS1                  ( CR_BASE_ADDR + 0x183 )
#define SD_STATUS2                  ( CR_BASE_ADDR + 0x184 )
#define SD_BUS_STATUS               ( CR_BASE_ADDR + 0x185 )
#define SD_CMD_MODE                 ( CR_BASE_ADDR + 0x186 )
#define SD_SAMPLE_POINT_CTL         ( CR_BASE_ADDR + 0x187 )
#define SD_PUSH_POINT_CTL           ( CR_BASE_ADDR + 0x188 )
#define SD_CMD0                     ( CR_BASE_ADDR + 0x189 )
#define SD_CMD1                     ( CR_BASE_ADDR + 0x18A )
#define SD_CMD2                     ( CR_BASE_ADDR + 0x18B )
#define SD_CMD3                     ( CR_BASE_ADDR + 0x18C )
#define SD_CMD4                     ( CR_BASE_ADDR + 0x18D )
#define SD_CMD5                     ( CR_BASE_ADDR + 0x18E )
#define SD_BYTE_CNT_L               ( CR_BASE_ADDR + 0x18F )
#define SD_BYTE_CNT_H               ( CR_BASE_ADDR + 0x190 )
#define SD_BLOCK_CNT_L              ( CR_BASE_ADDR + 0x191 )
#define SD_BLOCK_CNT_H              ( CR_BASE_ADDR + 0x192 )
#define SD_TRANSFER                 ( CR_BASE_ADDR + 0x193 )
#define SD_DDR_DETECT_START         ( CR_BASE_ADDR + 0x194 )
#define SD_CMD_STATE                ( CR_BASE_ADDR + 0x195 )
#define SD_DATA_STATE               ( CR_BASE_ADDR + 0x196 )
#define SD_BUS_TA_STATE             ( CR_BASE_ADDR + 0x197 )
#define SD_STOP_SDCLK_CFG           ( CR_BASE_ADDR + 0x197 )
#define SD_AUTO_RST_FIFO            ( CR_BASE_ADDR + 0x197 )
#define SD_DAT_PAD                  ( CR_BASE_ADDR + 0x197 )
#define SD_DUMMY_4                  ( CR_BASE_ADDR + 0x197 )
#define SD_DUMMY_5                  ( CR_BASE_ADDR + 0x197 )
#define SD_DUTY_CTL                 ( CR_BASE_ADDR + 0x197 )
#define SD_SEQ_RW_CTL               ( CR_BASE_ADDR + 0x198 )
#define SD_CONFIGURE4               ( CR_BASE_ADDR + 0x19F )
#define SD_ADDR_L                   ( CR_BASE_ADDR + 0x1A0 )
#define SD_ADDR_H                   ( CR_BASE_ADDR + 0x1A1 )
#define SD_START_ADDR_0             ( CR_BASE_ADDR + 0x1A2 )
#define SD_START_ADDR_1             ( CR_BASE_ADDR + 0x1A3 )
#define SD_START_ADDR_2             ( CR_BASE_ADDR + 0x1A4 )
#define SD_START_ADDR_3             ( CR_BASE_ADDR + 0x1A5 )
#define SD_RSP_MASK_1               ( CR_BASE_ADDR + 0x1A6 )
#define SD_RSP_MASK_2               ( CR_BASE_ADDR + 0x1A7 )
#define SD_RSP_MASK_3               ( CR_BASE_ADDR + 0x1A8 )
#define SD_RSP_MASK_4               ( CR_BASE_ADDR + 0x1A9 )
#define SD_RSP_DATA_1               ( CR_BASE_ADDR + 0x1AA )
#define SD_RSP_DATA_2               ( CR_BASE_ADDR + 0x1AB )
#define SD_RSP_DATA_3               ( CR_BASE_ADDR + 0x1AC )
#define SD_RSP_DATA_4               ( CR_BASE_ADDR + 0x1AD )
#define SD_WRITE_DELAY              ( CR_BASE_ADDR + 0x1AE )
#define SD_READ_DELAY               ( CR_BASE_ADDR + 0x1AF )
#define CR_SRAM_BASE_0              ( CR_BASE_ADDR + 0x200 )
#define CR_SRAM_BASE_1              ( CR_BASE_ADDR + 0x300 )

#if 0
#define CR_IP_RESET_REG			 	0xb8000108						//0xb8000118
#define CR_IP_RESET_REG2		 	0xb8000118						//0xb8000118
#define SD_STAT                 	( CR_BASE_ADDR  + 0x00 )        //0xb8010800
#define SD_CONFIGURE1           	( CR_BASE_ADDR  + 0x04 )        //0xb8010804
#define SD_TRANSFER             	( CR_BASE_ADDR  + 0x08 )        //0xb8010808
#define SD_CONFIGURE2           	( CR_BASE_ADDR  + 0x0c )        //0xb801080c
#define SD_CMD0                 	( CR_BASE_ADDR  + 0x10 )        //0xb8010810
#define SD_CMD1                 	( CR_BASE_ADDR  + 0x14 )        //0xb8010814
#define SD_CMD2                 	( CR_BASE_ADDR  + 0x18 )        //0xb8010818
#define SD_CMD3                 	( CR_BASE_ADDR  + 0x1c )        //0xb801081c
#define SD_CMD4                 	( CR_BASE_ADDR  + 0x20 )        //0xb8010820
#define SD_BYTE_CNT_L           	( CR_BASE_ADDR  + 0x24 )        //0xb8010824
#define SD_BYTE_CNT_H           	( CR_BASE_ADDR  + 0x28 )        //0xb8010828
#define SD_BLOCK_CNT_L          	( CR_BASE_ADDR  + 0x2c )        //0xb801082c
#define SD_BLOCK_CNT_H          	( CR_BASE_ADDR  + 0x30 )        //0xb8010830
#define SDIO_INT_CTRL           	( CR_BASE_ADDR  + 0x34 )        //0xb8010834
#define SD_CONFIGURE3           	( CR_BASE_ADDR  + 0x38 )        //0xb8010838
#define CR_DMA_PTR_STATUS       	( CR_BASE_ADDR  + 0x3c )        //0xb801083c
#define CR_DMA_IN_ADDR          	( CR_BASE_ADDR  + 0x40 )        //0xb8010840
#define CR_DMA_OUT_ADDR         	( CR_BASE_ADDR  + 0x44 )        //0xb8010844
#define CR_INT_STATUS           	( CR_BASE_ADDR  + 0x48 )        //0xb8010848
#define CR_INT_MASK             	( CR_BASE_ADDR  + 0x4c )        //0xb801084c
#define CR_REG_MODE_CTRL        	( CR_BASE_ADDR  + 0x50 )        //0xb8010850
#define CR_DES_MODE_CTRL        	( CR_BASE_ADDR  + 0x54 )        //0xb8010854
#define DES_CMD_WR_PORT         	( CR_BASE_ADDR  + 0x58 )        //0xb8010858
#define CR_BIST_0               	( CR_BASE_ADDR  + 0x5c )        //0xb801085c
#define CR_BIST_1               	( CR_BASE_ADDR  + 0x60 )        //0xb8010860
#define CR_BIST_MODE            	( CR_BASE_ADDR  + 0x64 )        //0xb8010864
#define CR_BIST_DONE            	( CR_BASE_ADDR  + 0x68 )        //0xb8010868
#define CR_BIST_FAIL            	( CR_BASE_ADDR  + 0x6c )        //0xb801086c
#define CR_BIST_DRF_MODE        	( CR_BASE_ADDR  + 0x70 )        //0xb8010870
#define CR_BIST_DRF_RESUME      	( CR_BASE_ADDR  + 0x74 )        //0xb8010874
#define CR_BIST_DRF_DONE        	( CR_BASE_ADDR  + 0x78 )        //0xb8010878
#define CR_BIST_PAUSE           	( CR_BASE_ADDR  + 0x7c )        //0xb801087c
#define CR_BIST_DRF_FAIL        	( CR_BASE_ADDR  + 0x80 )        //0xb8010880
#define CP_CTRL                 	( CR_BASE_ADDR  + 0x84 )        //0xb8010884
#define EXT_RSP_0               	( CR_BASE_ADDR  + 0x88 )        //0xb8010888
#define EXT_RSP_1               	( CR_BASE_ADDR  + 0x8c )        //0xb801088c
#define EXT_RSP_2               	( CR_BASE_ADDR  + 0x90 )        //0xb8010890
#define EXT_RSP_3               	( CR_BASE_ADDR  + 0x94 )        //0xb8010894
#define EXT_RSP_4               	( CR_BASE_ADDR  + 0x98 )        //0xb8010898
#define EXT_RSP_5               	( CR_BASE_ADDR  + 0x9c )        //0xb801089c
#define EXT_RSP_6               	( CR_BASE_ADDR  + 0xa0 )        //0xb80108a0
#define EXT_RSP_7               	( CR_BASE_ADDR  + 0xa4 )        //0xb80108a4
#define EXT_RSP_8               	( CR_BASE_ADDR  + 0xa8 )        //0xb80108a8
#define EXT_RSP_9               	( CR_BASE_ADDR  + 0xac )        //0xb80108ac
#define EXT_RSP_10              	( CR_BASE_ADDR  + 0xb0 )        //0xb80108b0
#define EXT_RSP_11              	( CR_BASE_ADDR  + 0xb4 )        //0xb80108b4
#define EXT_RSP_12              	( CR_BASE_ADDR  + 0xb8 )        //0xb80108b8
#define EXT_RSP_13              	( CR_BASE_ADDR  + 0xbc )        //0xb80108bc
#define EXT_RSP_14              	( CR_BASE_ADDR  + 0xc0 )        //0xb80108c0
#define ARB_STS                 	( CR_BASE_ADDR  + 0xc4 )        //0xb80108c4
#define CR_SRAM_BASE            	( CR_BASE_ADDR  + 0xc8 )        //0xb80108c8

#define CR_CARD_RESP6_0         	SD_CMD0                         //0xb8010810
#define CR_CARD_RESP6_1         	SD_CMD1                         //0xb8010814
#define CR_CARD_RESP6_2         	SD_CMD2                         //0xb8010818
#define CR_CARD_RESP6_3         	SD_CMD3                         //0xb801081c
#define CR_CARD_RESP6_4         	SD_CMD4                         //0xb8010820
#endif

/* SD_CONFIGURE1 0x18012180 */
#define MASK_CLOCK_DIV          	(0x00000003<<6)
#define CLOCK_DIV_NON           	(0x00000000)
#define CLOCK_DIV_256           	(0x00000001<<6)
#define CLOCK_DIV_128           	(0x00000000<<6)

#define SPEED_MOD_HIGH          	(0x00000001<<4)
#define SPEED_MOD_NORM          	(0x00000000)
#define DELAY_PHA_NORM          	(0x00000001<<3)
#define DELAY_PHA_HIGH          	(0x00000001<<2)

#define MASK_BUS_WIDTH          	(0x00000003)
#define BUS_WIDTH_1             	(0x00000000)
#define BUS_WIDTH_4             	(0x00000001)
#define BUS_WIDTH_8             	(0x00000002)

/* SD_TRANSFER 0xb8010808 */
#define START_EN                	(0x00000001<<7)
#define END_STATE               	(0x00000001<<6)
#define IDLE_STATE               	(0x00000001<<5)
#define ERR_STATUS              	(0x00000001<<4)

#define MASK_CMD_CODE           	(0x0000000F)
#define SD_NORMALWRITE          	(0x00000000)
#define SD_AUTOWRITE3           	(0x00000001)
#define SD_AUTOWRITE4           	(0x00000002)
#define SD_AUTOREAD3            	(0x00000005)
#define SD_AUTOREAD4            	(0x00000006)
#define SD_SENDCMDGETRSP        	(0x00000008)
#define SD_AUTOWRITE1           	(0x00000009)
#define SD_AUTOWRITE2           	(0x0000000A)
#define SD_NORMALREAD           	(0x0000000C)
#define SD_AUTOREAD1            	(0x0000000D)
#define SD_AUTOREAD2            	(0x0000000E)

/* SD_CONFIGURE2 0x18012180 */
#define SDCLK_DIV                   (0x00000001<<7)
#define SDCLK_NO_DIV                (0x00000000)
#define SDCLK_DIV_128               (0x00000000)
#define SDCLK_DIV_256               (0x00000001<<6)
#define NO_RST_RDWR_FIFO            (0x00000000)
#define RST_RDWR_FIFO               (0x00000001<<4)
#define BUS_WIDTH_1bit              (0x00000000)
#define BUS_WIDTH_4bit              (0x00000001)
#define BUS_WIDTH_8bit              (0x00000002)


/* SD_CONFIGURE2 0x18012181 */
#define CRC7_CAL_DIS            	(0x00000001<<7)
#define CRC16_CAL_DIS           	(0x00000001<<6)
#define WAIT_BUSY_EN            	(0x00000001<<3)
#define CRC7_CHK_DIS            	(0x00000001<<2)
#define WR_CRC_ERR_DIS              (0x00000005<<4)

#define MASK_RESP_TYPE          	(0x00000003)
#define RESP_TYPE_NON           	(0x00000000)
#define RESP_TYPE_6B            	(0x00000001)
#define RESP_TYPE_17B           	(0x00000002)

/* SD_CONFIGURE3 0x18012182 */
#define RESP_TIMEOUT            	(0x00000001<<3)
#define SDCMD_RSP_CHK_EN         	(0x00000001<<2)
#define RESP_TIMEOUT_EN         	(0x00000001<<0)
#define ADDR_BYTE_MODE              (0x00000001<<1)
//#define IGNORE_WRT_ERR          	(0x00000001<<1)
//#define CLK_TOGGLE_EN           	(0x00000001<<0)

/* DMA_CTL3 0x1801200c */
#define DMA_XFER                    (0x00000001)
#define DDR_WR                      (0x00000002)
#define RSP17_SEL                   (0x00000001 << 4)
#define DAT64_SEL                   (0x00000001 << 5)

/* SD_INT_STATUS 0xb8010848 */
#define RTKCR_INT_WRT_PROTEC    	(1<<5)
#define RTKCR_INT_CARD_DETEC    	(1<<4)
#define RTKCR_INT_DECODE_ERROR  	(1<<2)
#define RTKCR_INT_DECODE_FINISH 	(1<<1)
#define RTKCR_INT_STATUS_CHANGE 	(1<<0)
#define RTKCR_INT_CLEAR_ALL     	(RTKCR_INT_DECODE_ERROR|RTKCR_INT_DECODE_FINISH|RTKCR_INT_STATUS_CHANGE)

/* SD_STAT 0xb8010800 */
#define CRC7_STATUS             	(0x00000001<<7)
#define CRC16_STATUS            	(0x00000001<<6)
#define WRT_ERR_BIT             	(0x00000001<<5)
#define MASK_WRT_ERR_STA        	(0x00000007<<2)
#define DAT0_LEVEL              	(0x00000001<<1)

/* CP_CTRL 0xb8010884 */
#define BOOT_FROM_CR            	(0x00000001<<3)
#define MASK_BUFF_TIMING        	(0x00000003<<1)
#define BUFF_TIMING_0           	(0x00000000<<1)
#define BUFF_TIMING_1           	(0x00000001<<1)
#define BUFF_TIMING_2           	(0x00000002<<1)
#define BUFF_TIMING_3           	(0x00000003<<1)
#define CP_EN                   	(0x00000001)

//CRT spec(RTD299X DesignSpec-CRT)
#define SYS_CLKSEL              	0xB8000204        //0xB8000204
#define EMMC_CLKSEL_MASK        	(0x07<<12)
#define CLOCK_SPEED_GAP         	(0x03<<12)

#define CARD_SWITCHCLOCK_60MHZ  	(0x00<<12)
#define CARD_SWITCHCLOCK_80MHZ  	(0x01<<12)
#define CARD_SWITCHCLOCK_98MHZ  	(0x02<<12)
#define CARD_SWITCHCLOCK_98MHZS 	(0x03<<12)
#define CARD_SWITCHCLOCK_30MHZ  	(0x04<<12)
#define CARD_SWITCHCLOCK_40MHZ  	(0x05<<12)
#define CARD_SWITCHCLOCK_49MHZ  	(0x06<<12)
#define CARD_SWITCHCLOCK_49MHZS 	(0x07<<12)

/* Standard MMC commands (4.1)              type    argument            response */
/* class 1 */
#define MMC_GO_IDLE_STATE           0       /* bc                           */
#define MMC_SEND_OP_COND            1       /* bcr  [31:0] OCR          R3  */
#define MMC_ALL_SEND_CID            2       /* bcr                      R2  */
#define MMC_SET_RELATIVE_ADDR       3       /* ac   [31:16] RCA         R1  */
#define MMC_SET_DSR                 4       /* bc   [31:16] RCA             */
#define MMC_SLEEP_AWAKE             5       /* ac   [31:16] RCA 15:flg  R1b */
#define MMC_SWITCH                  6       /* ac   [31:0] See below    R1b */
#define MMC_SELECT_CARD             7       /* ac   [31:16] RCA         R1  */
#define MMC_SEND_EXT_CSD            8       /* adtc                     R1  */
#define MMC_SEND_CSD                9       /* ac   [31:16] RCA         R2  */
#define MMC_SEND_CID                10      /* ac   [31:16] RCA         R2  */
#define MMC_READ_DAT_UNTIL_STOP     11      /* adtc [31:0] dadr         R1  */
#define MMC_STOP_TRANSMISSION       12      /* ac                       R1b */
#define MMC_SEND_STATUS             13      /* ac   [31:16] RCA         R1  */
#define MMC_GO_INACTIVE_STATE       15      /* ac   [31:16] RCA             */
#define MMC_SPI_READ_OCR            58      /* spi                      spi_R3 */
#define MMC_SPI_CRC_ON_OFF          59      /* spi  [0:0] flag          spi_R1 */

  /* class 2 */
#define MMC_SET_BLOCKLEN            16      /* ac   [31:0] block len    R1  */
#define MMC_READ_SINGLE_BLOCK       17      /* adtc [31:0] data addr    R1  */
#define MMC_READ_MULTIPLE_BLOCK     18      /* adtc [31:0] data addr    R1  */

  /* class 3 */
#define MMC_WRITE_DAT_UNTIL_STOP    20      /* adtc [31:0] data addr    R1  */

  /* class 4 */
#define MMC_SET_BLOCK_COUNT         23      /* adtc [31:0] data addr    R1  */
#define MMC_WRITE_BLOCK             24      /* adtc [31:0] data addr    R1  */
#define MMC_WRITE_MULTIPLE_BLOCK    25      /* adtc                     R1  */
#define MMC_PROGRAM_CID             26      /* adtc                     R1  */
#define MMC_PROGRAM_CSD             27      /* adtc                     R1  */

  /* class 6 */
#define MMC_SET_WRITE_PROT          28      /* ac   [31:0] data addr    R1b */
#define MMC_CLR_WRITE_PROT          29      /* ac   [31:0] data addr    R1b */
#define MMC_SEND_WRITE_PROT         30      /* adtc [31:0] wpdata addr  R1  */

  /* class 5 */
#define MMC_ERASE_GROUP_START       35      /* ac   [31:0] data addr    R1  */
#define MMC_ERASE_GROUP_END         36      /* ac   [31:0] data addr    R1  */
#define MMC_ERASE                   38      /* ac                       R1b */

  /* class 9 */
#define MMC_FAST_IO                 39      /* ac   <Complex>           R4  */
#define MMC_GO_IRQ_STATE            40      /* bcr                      R5  */

  /* class 7 */
#define MMC_LOCK_UNLOCK             42      /* adtc                     R1b */

  /* class 8 */
#define MMC_APP_CMD                 55      /* ac   [31:16] RCA         R1  */
#define MMC_GEN_CMD                 56      /* adtc [0] RD/WR           R1  */

#if 0
#define R1_OUT_OF_RANGE         	(1 << 31)   /* er, c */
#define R1_ADDRESS_ERROR        	(1 << 30)   /* erx, c */
#define R1_BLOCK_LEN_ERROR      	(1 << 29)   /* er, c */
#define R1_ERASE_SEQ_ERROR      	(1 << 28)   /* er, c */
#define R1_ERASE_PARAM          	(1 << 27)   /* ex, c */
#define R1_WP_VIOLATION         	(1 << 26)   /* erx, c */
#define R1_CARD_IS_LOCKED       	(1 << 25)   /* sx, a */
#define R1_LOCK_UNLOCK_FAILED   	(1 << 24)   /* erx, c */
#define R1_COM_CRC_ERROR        	(1 << 23)   /* er, b */
#define R1_ILLEGAL_COMMAND      	(1 << 22)   /* er, b */
#define R1_CARD_ECC_FAILED      	(1 << 21)   /* ex, c */
#define R1_CC_ERROR             	(1 << 20)   /* erx, c */
#define R1_ERROR                	(1 << 19)   /* erx, c */
#define R1_UNDERRUN             	(1 << 18)   /* ex, c */
#define R1_OVERRUN              	(1 << 17)   /* ex, c */
#define R1_CID_CSD_OVERWRITE    	(1 << 16)   /* erx, c, CID/CSD overwrite */
#define R1_WP_ERASE_SKIP        	(1 << 15)   /* sx, c */
#define R1_CARD_ECC_DISABLED    	(1 << 14)   /* sx, a */
#define R1_ERASE_RESET          	(1 << 13)   /* sr, c */
#define R1_STATUS(x)            	(x & 0xFFFFE000)
#define R1_CURRENT_STATE(x)     	((x & 0x00001E00) >> 9) /* sx, b (4 bits) */
#define R1_READY_FOR_DATA       	(1 << 8)    /* sx, a */
#define R1_SWITCH_ERROR         	(1 << 7)    /* sx, c */
#define R1_APP_CMD              	(1 << 5)    /* sr, c */
#else
//word0
#define R1_OUT_OF_RANGE         (1 << 15)   /* 31 */
#define R1_ADDRESS_MISALIGN     (1 << 14)   /* 30 */
#define R1_BLOCK_LEN_ERROR      (1 << 13)   /* 29 */
#define R1_ERASE_SEQ_ERROR      (1 << 12)   /* 28 */
#define R1_ERASE_PARAM          (1 << 11)   /* 27 */
#define R1_WP_VIOLATION         (1 << 10)   /* 26 */
#define R1_DEVICE_IS_BLOCKED    (1 << 9)    /* 25 */
#define R1_LOCK_UNLOCK_FAILED   (1 << 8)    /* 24 */

#define R1_CM_CRC_ERROR         (1 << 23)   /* 23 */
#define R1_ILLEGAL_COMMAND      (1 << 22)   /* 22 */
#define R1_DEVICE_ECC_FAILED    (1 << 21)   /* 21 */
#define R1_CC_ERROR             (1 << 20)   /* 20 */
#define R1_ERROR                (1 << 19)   /* 19 */
//#define R1_                     (1 << 18)   /* 18 */
//#define R1_                     (1 << 17)   /* 17 */
#define R1_CID_CSD_OVERWRITE    (1 << 16)   /* 16 */

#define R1_WP_ERASE_SKIP        (1 << 31)   /* 15 */
//#define R1_                     (1 << 30)   /* 14 */
#define R1_ERASE_RESET          (1 << 29)   /* 13 */
//#define R1_                     (1 << 28)   /* 12 */
//#define R1_                     (1 << 27)   /* 11 */
//#define R1_                     (1 << 26)   /* 10 */
//#define R1_                     (1 << 25)   /* 9 */
#define R1_READY_FOR_DATA       (1 << 24)   /* 8 */

//word1
#define R1_SWITCH_ERROR         (1 << 7)   /* 7 */
#define R1_EXCEPTION_EVENT      (1 << 6)   /* 6 */
#define R1_APP_CMD              (1 << 5)   /* 5 */
//#define R1_                     (1 << 4)   /* 4 */

#define R1_CURRENT_STATE(x)     ((x & 0x1E000000) >> 25) /* sx, b (3 bits, 9-11bits) */
#endif

#define R1_ERR_CUR_WINDOW       	R1_OUT_OF_RANGE         |\
                                	R1_ADDRESS_ERROR        |\
                                	R1_BLOCK_LEN_ERROR      |\
                                	R1_ERASE_SEQ_ERROR      |\
                                	R1_ERASE_PARAM          |\
                                	R1_WP_VIOLATION         |\
                                	R1_LOCK_UNLOCK_FAILED   |\
                                	R1_COM_CRC_ERROR        |\
                                	R1_ILLEGAL_COMMAND      |\
                                	R1_CARD_ECC_FAILED      |\
                                	R1_CC_ERROR             |\
                                	R1_ERROR                |\
                                	R1_UNDERRUN             |\
                                	R1_OVERRUN              |\
                                	R1_CID_CSD_OVERWRITE    |\
                                	R1_WP_ERASE_SKIP        |\
                                	R1_ERASE_RESET


#define R1_ERR_PER_WINDOW      		R1_OUT_OF_RANGE         |\
                               		R1_ADDRESS_ERROR        |\
                               		R1_ERASE_PARAM          |\
                               		R1_WP_VIOLATION         |\
                               		R1_LOCK_UNLOCK_FAILED   |\
                               		R1_CARD_ECC_FAILED      |\
                               		R1_ERROR                |\
                               		R1_UNDERRUN             |\
                               		R1_OVERRUN              |\
                               		R1_CID_CSD_OVERWRITE    |\
                               		R1_WP_ERASE_SKIP


/*
 * EXT_CSD fields
 */
#define EXT_CSD_BUS_WIDTH       	183     /* R/W */
#define EXT_CSD_HS_TIMING       	185     /* R/W */
#define EXT_CSD_CARD_TYPE       	196     /* RO */
#define EXT_CONT_CSD_VER        	194     /* RO */
#define EXT_CSD_REV             	192     /* RO */
#define EXT_CSD_SEC_CNT         	212     /* RO, 4 bytes */
#define EXT_CSD_S_A_TIMEOUT     	217

/*
 * MMC_SWITCH access modes
 */
#define MMC_SWITCH_MODE_CMD_SET     0x00    /* Change the command set */
#define MMC_SWITCH_MODE_SET_BITS    0x01    /* Set bits which are 1 in value */
#define MMC_SWITCH_MODE_CLEAR_BITS  0x02    /* Clear bits which are 1 in value */
#define MMC_SWITCH_MODE_WRITE_BYTE  0x03    /* Set target to value */

/************************************************************************
 *  Structure
 ************************************************************************/
struct rtk_mmc_command {
    unsigned int opcode;
    unsigned int arg;
    unsigned int resp[4];
};


struct rtk_cmd_info {
    struct rtk_mmc_command * 		cmd;
    unsigned char *          		data_buffer;
    unsigned int      		 		byte_count;
    unsigned int      		 		block_count;
    unsigned int      		 		xfer_flag;
		#define RTK_MMC_DATA_DIR_MASK   (3 << 6)    /* bit 6~7 */
		#define RTK_MMC_DATA_SRAM       (1 << 7)
		#define RTK_MMC_DATA_WRITE      (1 << 6)
		#define RTK_MMC_DATA_READ       (0 << 6)    /* can't use this flag to check status, because its value is zero */
		#define RTK_MMC_SRAM_WRITE      RTK_MMC_DATA_SRAM | RTK_MMC_DATA_WRITE
		#define RTK_MMC_SRAM_READ       RTK_MMC_DATA_SRAM | RTK_MMC_DATA_READ
		#define RTK_MMC_DATA_DIR(pkt)  (pkt->xfer_flag & RTK_MMC_DATA_DIR_MASK)
    unsigned int       				rsp_para1;
    unsigned int       				rsp_para2;
    unsigned int       				rsp_para3;
    unsigned int       				rsp_len;
};

/*
 * emmc profile
 */

struct rtk_mmc_ocr_reg {
    unsigned char lowV:1;   //1.7v to 1.95v
    unsigned char reserved1:7;
//    unsigned short highV:9;   //2.7v to 3.6v
//    unsigned short midV:7;   //2.0v to 2.6v
    unsigned char val1;
    unsigned char val2;
    unsigned char reserved2:5;
    unsigned char access_mode:2;
    unsigned char power_up:1;
};
struct rtk_mmc_ocr {
    unsigned char check1:6;
    unsigned char start:1;
    unsigned char transmission:1;
    unsigned char reg[4];
//    struct rtk_mmc_ocr_reg reg;
    unsigned char end:1;
    unsigned char check2:7;
};



struct rtk_mmc_cid {
	unsigned int					manfid;
	char			    			prod_name[8];
	unsigned int					serial;
	unsigned int					oemid;
	unsigned int					year;
	unsigned char					hwrev;
	unsigned char					fwrev;
	unsigned char					month;
};

struct rtk_mmc_csd {
	unsigned char					csd_ver;
	unsigned char					csd_ver2;// from EXT_CSD
	unsigned char					mmca_vsn;
	unsigned short					cmdclass;
	unsigned short					tacc_clks;
	unsigned int					tacc_ns;
	unsigned int					r2w_factor;
	unsigned int					max_dtr;
	unsigned int					read_blkbits;
	unsigned int					write_blkbits;
	unsigned int					capacity;
	unsigned int					read_partial:1,
				        			read_misalign:1,
				        			write_partial:1,
				        			write_misalign:1;
};

struct rtk_mmc_ext_csd {
	unsigned int 					rev;
	unsigned char					part_cfg;
	unsigned char					boot_cfg;
	unsigned char					boot_wp_sts;
	unsigned char					boot_wp;
	unsigned char					user_wp;
	unsigned char					rpmb_size_mult;
	unsigned char					partitioning_support;
	unsigned int 					boot_blk_size;
	unsigned int 					sa_timeout;
	unsigned int 					hs_max_dtr;
	unsigned int 					sectors;
};

typedef struct {
	unsigned int					sector_addressing;
	unsigned int 					curr_part_indx;
	unsigned int					rca;		    		/* relative card address of device */
	unsigned int					raw_cid[7];	            /* raw card CID */
	unsigned int					raw_csd[4];	            /* raw card CSD */
	struct rtk_mmc_ocr	    		ocr;					/* card identification */
	struct rtk_mmc_cid	    		cid;					/* card identification */
	struct rtk_mmc_csd	    		csd;					/* card specific */
	struct rtk_mmc_ext_csd  		ext_csd;				/* mmc v4 extended card specific */
} e_device_type;

#ifdef __RTKMMC_C__
	#define EXTERN_CALL
#else
	#define EXTERN_CALL extern
#endif

EXTERN_CALL e_device_type emmc_card;
EXTERN_CALL void mmccr_set_bits_width( unsigned int set_bit );
EXTERN_CALL int rtk_eMMC_init( void );
EXTERN_CALL int rtk_eMMC_write( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer, unsigned int auto_sel_part );
EXTERN_CALL int rtk_eMMC_read( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer, unsigned int auto_sel_part );

#endif /* end of file */
