#ifndef __FLASH_SPI_LIST_H__
#define __FLASH_SPI_LIST_H__

/* hcy modified as forwarding type */
#define	MX_4Mbit			0xc22013//forward 	0x1320c2 
#define MX_25L8006E_8Mbit		0xc22014
#define	MX_25L1605_16Mbit		0xc22015//	0x1520c2
#define MX_25L3206E_32Mbit		0xc22016//	0x1620c2
#define	MX_25L6405D_64Mbit		0xc22017//	0x1720c2
#define	MX_25L12805D_128Mbit		0xc22018//	0x1820c2
#define MX_25L25635E_256Mbit		0xc22019
#define MX_25L6455E_64Mbit		0xc22617
#define MX_25L12855E_128Mbit		0xc22618
#define MX_25L6433F_64Mbit          0xc22017

#define	PMC_4Mbit			0x7f9d7e//	0x7e9d7f

#define	SPANSION_16Mbit			0x010214//	0x140201
#define	SPANSION_32Mbit			0x010215//	0x150201
#define	SPANSION_64Mbit			0x010216//	0x160201
#define	SPANSION_128Mbit		0x012018//	0x182001
#define	SPANSION_128Mbit_64s		0x0301  //	0x0103
#define	SPANSION_128Mbit_256s		0x0300	//      0x0003
#define S25FL129P_64s			0x4d01		// uniform  64KB sector
#define S25FL129P_256s			0x4d00		// uniform 256KB sector
#define S25FL064K_4s                    0xef4017     
#define S25FL016K_4s			0xef4015
#define SPANSION_S25FL164K	     	0x014017
#define SPANSION_S25FL216K			0x014015

#define	SST_8Mbit			0xbf80  //	0x80bf
#define	SST_4Mbit			0xbf258d//	0x8d25bf
#define	SST_16Mbit			0xbf2541//	0x4125bf

#define	STM_64Mbit			0x202017//	0x172020
#define	STM_128Mbit			0x202018//	0x182020
#define STM_N25Q_128Mbit		0x20ba18
#define STM_N25Q064_64Mbit              0x20ba17

#define EON_EN25QH16_16Mbit		0x1c7015//	0x15701c
#define EON_EN25QH16128A_16Mbit	    0x1c7018    // 	0x18701c
#define EON_EN25Q32B_32Mbit		0x1c3016//	0x16301c
#define	EON_EN25Q64_64Mbit		0x1c3017//	0x17301c
#define	EON_EN25F16_16Mbit		0x1c3115
#define EON_EN25Q128_128Mbit		0x1c3018
#define EON_EN25B64_64Mbit		0x1c2017

#define WINBOND_W25Q80BV_8Mbit		0xef4014
#define WINBOND_W325Q128BV_128Mbit	0xef4018

#define ESMT_F25L32PA_32Mbit		0x8c1620

#define GD25Q16B_16Mbit			0xc84015
#define GD25Q64B_64Mbit			0xc84017
#define GD25Q128B_128Mbit		0xc84018

#define A25L040_32Mbit              0x373013

typedef struct 
{
    unsigned int    id ;
    unsigned char   sec_256k_en ;
    unsigned char   sec_64k_en ;
    unsigned char   sec_32k_en ;
    unsigned char   sec_4k_en ;
    unsigned char   page_program ;
    unsigned int    size;
    unsigned char   *string;
} s_device_type;


/**********************************************
************************************************/

static const s_device_type s_device[] = 
{
#if 1	// add by alan (do not support page_program in FPGA environment)

    {SST_4Mbit,                    0, 1, 1, 1, 0, 0x080000 , "SST 4Mbit"} , 
    {SST_8Mbit,                    0, 0, 1, 1, 0, 0x100000 , "SST 8Mbit"} ,   
    {SST_16Mbit,                   0, 1, 1, 1, 0, 0x200000 , "SST 16Mbit"} , 

    {PMC_4Mbit,                    0, 1, 0, 1, 0, 0x080000 , "PMC 4Mbit"} ,  

    {MX_4Mbit,                     0, 1, 0, 0, 0, 0x080000 , "MX 4Mbit"} ,
    {MX_25L8006E_8Mbit,            0, 1, 0, 1, 1, 0x100000 , "MX 8Mbit"} ,
    {MX_25L1605_16Mbit,            0, 1, 0, 0, 0, 0x200000 , "MX 16Mbit"} ,
    {MX_25L3206E_32Mbit,           0, 1, 0, 1, 1, 0x400000 , "MX 32Mbit"} ,
    {MX_25L6405D_64Mbit,           0, 1, 0, 0, 1, 0x800000 , "MX 64Mbit"} ,
    {MX_25L12805D_128Mbit,         0, 1, 0, 0, 1, 0x1000000, "MX 128Mbit"},
    {MX_25L25635E_256Mbit,         0, 1, 0, 0, 1, 0x1000000, "MX 256Mbit"}, /* now we use 16Mbytes(128Mbits) */
    {MX_25L6455E_64Mbit,           0, 1, 1, 1, 1, 0x800000 , "MX 64Mbit"},
    {MX_25L12855E_128Mbit,         0, 1, 1, 1, 1, 0x1000000, "MX 128Mbit"},
    {MX_25L6433F_64Mbit,           0, 1, 1, 1, 1, 0x800000 ,"MX 64Mbit"} ,

    {SPANSION_16Mbit,              0, 1, 0, 0, 1, 0x200000 , "SPANSION 16Mbit"} ,
    {SPANSION_32Mbit,              0, 1, 0, 0, 0, 0x400000 , "SPANSION 32Mbit"} ,
    {SPANSION_64Mbit,              0, 1, 0, 0, 1, 0x800000 , "SPANSION_64Mbit"} ,
    {SPANSION_128Mbit,             0, 1, 0, 0, 0, 0x1000000, "SPANSION_128Mbit"},
    {SPANSION_128Mbit_64s,         0, 1, 0, 0, 1, 0x1000000, "SPANSION_128Mbit_s64"},
    {SPANSION_128Mbit_256s,        1, 0, 0, 0, 1, 0x1000000, "SPANSION_128Mbit_s256"},
    {S25FL129P_64s,                0, 1, 0, 0, 1, 0x1000000, "SPANSION_128Mbit_s64"},
    {S25FL129P_256s,               1, 0, 0, 0, 1, 0x1000000, "SPANSION_128Mbit_s256"},
    {S25FL064K_4s,                 0, 1, 1, 1, 1, 0x800000 , "S25FL064K_4s"},
    {S25FL016K_4s,                 0, 1, 1, 1, 1, 0x200000 , "S25FL016K_4s"},
    {SPANSION_S25FL164K,           0, 1, 0, 1, 1 ,0x800000, "SPANSION_S25FL164K_64Mbit"} , 
	{SPANSION_S25FL216K,           0, 1, 0, 1, 1 ,0x1000000, "SPANSION_S25FL216K"}, 

    {STM_64Mbit,                   0, 1, 0, 0, 1, 0x800000 , "STMicron_64Mbit"} ,
    {STM_128Mbit,                  1, 1, 0, 0, 1, 0x1000000, "STMicron_128Mbit"},
    {STM_N25Q_128Mbit,             0, 1, 0, 0, 1, 0x1000000, "STMicron_N25Q_128Mbit"},
    {STM_N25Q064_64Mbit,           0, 1, 0, 1, 1, 0x800000 , "STMicron_N25Q064_64Mbit"},

    {EON_EN25QH16_16Mbit,          0, 1, 0, 1, 1, 0x200000 , "EON_EN25QH16_16Mbit"} ,
    {EON_EN25QH16128A_16Mbit,      0, 1, 1, 1, 1 ,0x1000000, "EON_EN25QH16_16Mbit"} ,
    {EON_EN25Q32B_32Mbit,          0, 1, 0, 1, 1, 0x400000 , "EON_EN25Q32B_32Mbit"} ,
    {EON_EN25Q64_64Mbit,           0, 1, 0, 0, 1, 0x800000 , "EON_EN25Q64_64Mbit"} ,
    {EON_EN25F16_16Mbit,           0, 1, 0, 0, 1, 0x200000 , "EON_EN25F16_16Mbit"},
    {EON_EN25Q128_128Mbit,         0, 1, 0, 0, 1, 0x1000000, "EON_EN25Q128_128Mbit"},
    {EON_EN25B64_64Mbit,           0, 1, 0, 0, 1, 0x800000 , "EON_EN25B64_64Mbit"},

    {WINBOND_W25Q80BV_8Mbit,	   0, 1, 1, 1, 1, 0x100000 , "WINBOND_W25Q80BV_8Mbit"},
    {WINBOND_W325Q128BV_128Mbit,   0, 1, 1, 1, 1, 0x1000000, "WINBOND_W325Q128BV_128Mbit"},

    {ESMT_F25L32PA_32Mbit,         0, 1, 0, 1, 1, 0x400000 , "ESMT_F25L32PA_32Mbit"} ,

    {GD25Q16B_16Mbit,              0, 1, 1, 1, 1 , 0x200000  , "GD25Q16B_16Mbit"} ,
    {GD25Q64B_64Mbit,              0, 1, 1, 1, 1 , 0x800000  , "GD25Q64B_64Mbit"} ,
    {GD25Q128B_128Mbit,            0, 1, 1, 1, 1 , 0x1000000 , "GD25Q128B_128Mbit"} ,
    {A25L040_32Mbit,               0, 1, 0, 1, 1, 0x400000, "AMIC 32Mbit"} ,
#else

    {SST_4Mbit,                    0, 1, 1, 1, 0, 0x080000 , "SST 4Mbit"} , 
    {SST_8Mbit,                    0, 0, 1, 1, 0, 0x100000 , "SST 8Mbit"} ,   
    {SST_16Mbit,                   0, 1, 1, 1, 0, 0x200000 , "SST 16Mbit"} , 

    {PMC_4Mbit,                    0, 1, 0, 1, 0, 0x080000 , "PMC 4Mbit"} ,  

    {MX_4Mbit,                     0, 1, 0, 0, 0, 0x080000 , "MX 4Mbit"} ,
    {MX_25L1605_16Mbit,            0, 1, 0, 0, 0, 0x200000 , "MX 16Mbit"} ,
    {MX_25L3206E_32Mbit,           0, 1, 0, 1, 0, 0x400000 , "MX 32Mbit"} ,
    {MX_25L6405D_64Mbit,           0, 1, 0, 0, 0, 0x800000 , "MX 64Mbit"} ,
    {MX_25L12805D_128Mbit,         0, 1, 0, 0, 0, 0x1000000, "MX 128Mbit"},
    {MX_25L25635E_256Mbit,         0, 1, 0, 0, 0, 0x1000000, "MX 256Mbit"}, /* now we use 16Mbytes(128Mbits) */
    {MX_25L6455E_64Mbit,           0, 1, 1, 1, 0, 0x800000 , "MX 64Mbit"},
    {MX_25L12855E_128Mbit,         0, 1, 1, 1, 0, 0x1000000, "MX 128Mbit"},

    {SPANSION_16Mbit,              0, 1, 0, 0, 0, 0x200000 , "SPANSION 16Mbit"} ,
    {SPANSION_32Mbit,              0, 1, 0, 0, 0, 0x400000 , "SPANSION 32Mbit"} ,
    {SPANSION_64Mbit,              0, 1, 0, 0, 0, 0x800000 , "SPANSION_64Mbit"} ,
    {SPANSION_128Mbit,             0, 1, 0, 0, 0, 0x1000000, "SPANSION_128Mbit"},
    {SPANSION_128Mbit_64s,         0, 1, 0, 0, 0, 0x1000000, "SPANSION_128Mbit_s64"},
    {SPANSION_128Mbit_256s,        1, 0, 0, 0, 0, 0x1000000, "SPANSION_128Mbit_s256"},
    {S25FL129P_64s,                0, 1, 0, 0, 0, 0x1000000, "SPANSION_128Mbit_s64"},
    {S25FL129P_256s,               1, 0, 0, 0, 0, 0x1000000, "SPANSION_128Mbit_s256"},
    {S25FL064K_4s,                 0, 1, 1, 1, 0, 0x800000 , "S25FL064K_4s"},
    {S25FL016K_4s,                 0, 1, 1, 1, 0, 0x200000 , "S25FL016K_4s"},

    {STM_64Mbit,                   0, 1, 0, 0, 0, 0x800000 , "STMicron_64Mbit"} ,
    {STM_128Mbit,                  1, 1, 0, 0, 0, 0x1000000, "STMicron_128Mbit"},
    {STM_N25Q_128Mbit,             0, 1, 0, 0, 0, 0x1000000, "STMicron_N25Q_128Mbit"},
    {STM_N25Q064_64Mbit,           0, 1, 0, 1, 0, 0x800000 , "STMicron_N25Q064_64Mbit"},

    {EON_EN25QH16_16Mbit,          0, 1, 0, 1, 0, 0x200000 , "EON_EN25QH16_16Mbit"} ,
    {EON_EN25Q32B_32Mbit,          0, 1, 0, 1, 0, 0x400000 , "EON_EN25Q32B_32Mbit"} ,
    {EON_EN25Q64_64Mbit,           0, 1, 0, 0, 0, 0x800000 , "EON_EN25Q64_64Mbit"} ,
    {EON_EN25F16_16Mbit,           0, 1, 0, 0, 0, 0x200000 , "EON_EN25F16_16Mbit"},
    {EON_EN25Q128_128Mbit,         0, 1, 0, 0, 0, 0x1000000, "EON_EN25Q128_128Mbit"},

    {WINBOND_W325Q128BV_128Mbit,   0, 1, 1, 1, 0, 0x1000000, "WINBOND_W325Q128BV_128Mbit"},

    {ESMT_F25L32PA_32Mbit,         0, 1, 0, 1, 0, 0x400000 , "ESMT_F25L32PA_32Mbit"} ,

#endif
} ; 


#define DEV_SIZE_S	(sizeof(s_device)/sizeof(s_device_type))

#endif /* __FLASH_SPI_LIST_H__ */
