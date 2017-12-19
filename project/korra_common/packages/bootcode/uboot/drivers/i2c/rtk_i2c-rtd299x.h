#ifndef __RTK_I2C_RTD299X_H__
#define __RTK_I2C_RTD299X_H__

#include "asm/arch/rbus/misc_reg.h"

#define RTK_I2C_CNT               3

#define IC0_CON                 		0xb8062200
#define IC0_TAR                 		0xb8062204
#define IC0_SAR                 		0xb8062208
#define IC0_HS_MADDR            		0xb806220C
#define IC0_DATA_CMD            		0xb8062210
#define IC0_SS_SCL_HCNT         		0xb8062214
#define IC0_SS_SCL_LCNT         		0xb8062218
#define IC0_FS_SCL_HCNT         		0xb806221C
#define IC0_FS_SCL_LCNT         		0xb8062220
#define IC0_INTR_STAT           		0xb806222C
#define IC0_INTR_MASK           		0xb8062230
#define IC0_RAW_INTR_STAT       		0xb8062234
#define IC0_RX_TL               		0xb8062238
#define IC0_TX_TL               		0xb806223C
#define IC0_CLR_INTR            		0xb8062240
#define IC0_CLR_RX_UNDER       		    0xb8062244
#define IC0_CLR_RX_OVER         		0xb8062248
#define IC0_CLR_TX_OVER         		0xb806224C
#define IC0_CLR_RD_REQ          		0xb8062250
#define IC0_CLR_TX_ABRT         		0xb8062254
#define IC0_CLR_RX_DONE         		0xb8062258
#define IC0_CLR_ACTIVITY       		    0xb806225C
#define IC0_CLR_STOP_DET        		0xb8062260
#define IC0_CLR_START_DET       		0xb8062264
#define IC0_CLR_GEN_CALL        		0xb8062268
#define IC0_ENABLE              		0xb806226C
#define IC0_STATUS              		0xb8062270
#define IC0_TXFLR               		0xb8062274
#define IC0_RXFLR               		0xb8062278
#define IC0_TX_ABRT_SOURCE      		0xb8062280
#define IC0_DMA_CR              		0xb8062288
#define IC0_DMA_TDLR            		0xb806228C
#define IC0_DMA_RDLR            		0xb8062290
#define IC0_COMP_PARAM_1       		    0xb80622F4
#define IC0_COMP_VERSION        		0xb80622F8
#define IC0_COMP_TYPE           		0xb80622FC
#define IC0_SDA_OUTPUT_DELAY_CTRL 	    0xb8062118

// I2C
unsigned int IC_CON[]             = {IC0_CON            , IC1_CON            , IC2_CON              };
unsigned int IC_TAR[]             = {IC0_TAR            , IC1_TAR            , IC2_TAR              };
unsigned int IC_SAR[]             = {IC0_SAR            , IC1_SAR            , IC2_SAR              };
unsigned int IC_HS_MADDR[]        = {IC0_HS_MADDR       , IC1_HS_MADDR       , IC2_HS_MADDR         };
unsigned int IC_DATA_CMD[]        = {IC0_DATA_CMD       , IC1_DATA_CMD       , IC2_DATA_CMD         };
unsigned int IC_SS_SCL_HCNT[]     = {IC0_SS_SCL_HCNT    , IC1_SS_SCL_HCNT    , IC2_SS_SCL_HCNT      };
unsigned int IC_SS_SCL_LCNT[]     = {IC0_SS_SCL_LCNT    , IC1_SS_SCL_LCNT    , IC2_SS_SCL_LCNT      };
unsigned int IC_FS_SCL_HCNT[]     = {IC0_FS_SCL_HCNT    , IC1_FS_SCL_HCNT    , IC2_FS_SCL_HCNT      };
unsigned int IC_FS_SCL_LCNT[]     = {IC0_FS_SCL_LCNT    , IC1_FS_SCL_LCNT    , IC2_FS_SCL_LCNT      };
unsigned int IC_INTR_STAT[]       = {IC0_INTR_STAT      , IC1_INTR_STAT      , IC2_INTR_STAT        };
unsigned int IC_INTR_MASK[]       = {IC0_INTR_MASK      , IC1_INTR_MASK      , IC2_INTR_MASK        };
unsigned int IC_RAW_INTR_STAT[]   = {IC0_RAW_INTR_STAT  , IC1_RAW_INTR_STAT  , IC2_RAW_INTR_STAT    };
unsigned int IC_RX_TL[]           = {IC0_RX_TL          , IC1_RX_TL          , IC2_RX_TL            };
unsigned int IC_TX_TL[]           = {IC0_TX_TL          , IC1_TX_TL          , IC2_TX_TL            };
unsigned int IC_CLR_INTR[]        = {IC0_CLR_INTR       , IC1_CLR_INTR       , IC2_CLR_INTR         };
unsigned int IC_CLR_RX_UNDER[]    = {IC0_CLR_RX_UNDER   , IC1_CLR_RX_UNDER   , IC2_CLR_RX_UNDER     };
unsigned int IC_CLR_RX_OVER[]     = {IC0_CLR_RX_OVER    , IC1_CLR_RX_OVER    , IC2_CLR_RX_OVER      };
unsigned int IC_CLR_TX_OVER[]     = {IC0_CLR_TX_OVER    , IC1_CLR_TX_OVER    , IC2_CLR_TX_OVER      };
unsigned int IC_CLR_RD_REQ[]      = {IC0_CLR_RD_REQ     , IC1_CLR_RD_REQ     , IC2_CLR_RD_REQ       };
unsigned int IC_CLR_TX_ABRT[]     = {IC0_CLR_TX_ABRT    , IC1_CLR_TX_ABRT    , IC2_CLR_TX_ABRT      };
unsigned int IC_CLR_RX_DONE[]     = {IC0_CLR_RX_DONE    , IC1_CLR_RX_DONE    , IC2_CLR_RX_DONE      };
unsigned int IC_CLR_ACTIVITY[]    = {IC0_CLR_ACTIVITY   , IC1_CLR_ACTIVITY   , IC2_CLR_ACTIVITY     };
unsigned int IC_CLR_STOP_DET[]    = {IC0_CLR_STOP_DET   , IC1_CLR_STOP_DET   , IC2_CLR_STOP_DET     };
unsigned int IC_CLR_START_DET[]   = {IC0_CLR_START_DET  , IC1_CLR_START_DET  , IC2_CLR_START_DET    };
unsigned int IC_CLR_GEN_CALL[]    = {IC0_CLR_GEN_CALL   , IC1_CLR_GEN_CALL   , IC2_CLR_GEN_CALL     };
unsigned int IC_ENABLE[]          = {IC0_ENABLE         , IC1_ENABLE         , IC2_ENABLE           };
unsigned int IC_STATUS[]          = {IC0_STATUS         , IC1_STATUS         , IC2_STATUS           };
unsigned int IC_TXFLR[]           = {IC0_TXFLR          , IC1_TXFLR          , IC2_TXFLR            };
unsigned int IC_RXFLR[]           = {IC0_RXFLR          , IC1_RXFLR          , IC2_RXFLR            };
unsigned int IC_TX_ABRT_SOURCE[]  = {IC0_TX_ABRT_SOURCE , IC1_TX_ABRT_SOURCE , IC2_TX_ABRT_SOURCE   };
unsigned int IC_DMA_CR[]          = {IC0_DMA_CR         , IC1_DMA_CR         , IC2_DMA_CR           };
unsigned int IC_DMA_TDLR[]        = {IC0_DMA_TDLR       , IC1_DMA_TDLR       , IC2_DMA_TDLR         };
unsigned int IC_DMA_RDLR[]        = {IC0_DMA_RDLR       , IC1_DMA_RDLR       , IC2_DMA_RDLR         };
unsigned int IC_COMP_PARAM_1[]    = {IC0_COMP_PARAM_1   , IC1_COMP_PARAM_1   , IC2_COMP_PARAM_1     };
unsigned int IC_COMP_VERSION[]    = {IC0_COMP_VERSION   , IC1_COMP_VERSION   , IC2_COMP_VERSION     };
unsigned int IC_COMP_TYPE[]       = {IC0_COMP_TYPE      , IC1_COMP_TYPE      , IC2_COMP_TYPE        };

//IC_CON
#define IC_SLAVE_DISABLE    0x0040
#define IC_RESTART_EN       0x0020
#define IC_10BITADDR_MASTER 0x0010
#define IC_10BITADDR_SLAVE  0x0008
#define IC_MASTER_MODE      0x0001

#define IC_SPEED            0x0006
#define SPEED_SS            0x0002
#define SPEED_FS            0x0004
#define SPEED_HS            0x0006

//ID_DATA
#define READ_CMD            0x0100

// INT
#define GEN_CALL_BIT        0x800
#define START_DET_BIT       0x400
#define STOP_DET_BIT        0x200
#define ACTIVITY_BIT        0x100
#define RX_DONE_BIT         0x080
#define TX_ABRT_BIT         0x040
#define RD_REQ_BIT          0x020
#define TX_EMPTY_BIT        0x010
#define TX_OVER_BIT         0x008
#define RX_FULL_BIT         0x004
#define RX_OVER_BIT         0x002
#define RX_UNDER_BIT        0x001

// STATUS
#define ST_RFF_BIT          0x10
#define ST_RFNE_BIT         0x08
#define ST_TFE_BIT          0x04
#define ST_TFNF_BIT         0x02
#define ST_ACTIVITY_BIT     0x01

// MIS_ISR
#define I2C0_INT                    (0x00000001<<4)
#define I2C1_INT                    (0x00000001<<26)

// IC_TX_ABRT_SOURCE
#define ABRT_SLVRD_INTX             0x8000
#define ABRT_SLV_ARB_LOST           0x4000
#define ABRT_SLV_FLUSH_TX_FIFO      0x2000
#define ABRT_ARB_LOST               0x1000
#define ABR_MASTER_DIS              0x0800
#define ABRT_10B_RD_NORSTRT         0x0400
#define ABRT_SBYTE_NORSTRT          0x0200
#define ABRT_HS_NORSTRT             0x0100
#define ABRT_SBYTE_ACKDET           0x0080
#define ABRT_HS_ACKDET              0x0040
#define ABRT_GCALL_READ             0x0020
#define ABRT_GCALL_NOACK            0x0010
#define ABRT_TXDATA_NOACK           0x0008
#define ABRT_10ADDR2_NOACK          0x0004
#define ABRT_10ADDR1_NOACK          0x0002
#define ABRT_7ADDR_NOACK            0x0001

#endif
