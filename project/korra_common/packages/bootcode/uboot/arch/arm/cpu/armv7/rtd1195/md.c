
/***********************************************************************
 *
 *  md.c
 *
 *  Implementation of MD module
 *
 * 
 *
 ************************************************************************/


/************************************************************************
 *  Include files
 ************************************************************************/
#include <common.h>
#include <asm/io.h>
#include <rbus/md_reg.h>
#include <malloc.h>
//#include <md.h>



/************************************************************************
 *  Definitions
 ************************************************************************/
#define SS_BLK_LENGTH              (1024*1024)


/************************************************************************
 *  Public variables
 ************************************************************************/


/************************************************************************
 *  Static variables
 ************************************************************************/


/************************************************************************
 *  Static function prototypes
 ************************************************************************/
unsigned int *allocat_md_cmd(unsigned int num_of_cmd);

/************************************************************************
 *  Implementation : Public functions
 ************************************************************************/
int md_memcpy(void *dst, void *src, unsigned int len)
{
	unsigned int *cmd;
	unsigned int num_of_cmd = len / SS_BLK_LENGTH + 1;
	unsigned int i, ith_len;
	unsigned int ith_dst = dst;
	unsigned int ith_src = src;

	if ((cmd = allocat_md_cmd(num_of_cmd)) == NULL) {
		
		if(dst<0x0000a800)
			printf("Using MD failed.");			
		else
			memcpy(dst, src, len);	// use memcpy instead...		
		return 0;
	}	
             
	
	for (i = 0; i < num_of_cmd; i++) {
		
		ith_len = (len > SS_BLK_LENGTH ? SS_BLK_LENGTH : len);	
		cmd[i*4]   = 0x5;
		cmd[i*4+1] = ith_dst;
		cmd[i*4+2] = ith_src;
		cmd[i*4+3] = ith_len;
		ith_dst += ith_len;
		ith_src += ith_len;
		len -= ith_len;		
	}
   
	flush_cache(cmd,cmd+4* sizeof(unsigned int)*num_of_cmd);
				     
	rtd_outl(MD_SMQ_CNTL,0x6);
	rtd_outl(MD_SMQ_INT_STATUS,0x3e);
	rtd_outl(MD_SMQBASE , (unsigned int)cmd);
	rtd_outl(MD_SMQRDPTR, (unsigned int)cmd);
	rtd_outl(MD_SMQWRPTR,(unsigned int)cmd + num_of_cmd * sizeof(unsigned int) * 4);
	rtd_outl(MD_SMQLIMIT,(rtd_inl(MD_SMQWRPTR) + sizeof(unsigned int) * 4));

	rtd_outl(MD_SMQ_CNTL, 0x7);
#if 0	
	i = 100000;
	while (i--) {
		// check idle
		if (rtd_inl(MD_SMQ_CNTL) & 0x8)
			return 0;
		// check error
		if (rtd_inl(MD_SMQ_INT_STATUS) & 0x2) {
			printf("[ERROR] opcode error\n");
			return -1;
		}

		if (rtd_inl(MD_SMQ_INT_STATUS) & 0x4) {
			printf("[ERROR] length error\n");
			return -2;
		}
	}
	printf("[ERROR] MD no response\n");
#endif
	return -1;
}
/*
void md_flash2mem(void *dst, void *src, UINT32 len)
{
	unsigned int remain = len & 0x3;
	
	// use memcpy instead if not word-aligned addres
	if (((UINT32)dst & 0x3) || ((UINT32)src & 0x3)) {
		memcpy(dst, src, len);
		return;
	}
	
	//printf("[DEBUG] %s(0x%x, 0x%x, 0x%x)\n", __FUNCTION__, (UINT32)dst, (UINT32)src, len);
	// flush cache before DMA
	sys_dcache_flush_all();

	// 1. copy with word-aligned
	REG32(MD_FDMA_DDR_SADDR) = (UINT32)dst;
	REG32(MD_FDMA_FL_SADDR) = (UINT32)src;
	REG32(MD_FDMA_CTRL2) = 0x3c000000 | ((len - remain) & 0x1ffffff);
	sys_sync();
	REG32(MD_FDMA_CTRL1) = 3;	// go
	while ((REG32(MD_FDMA_CTRL1) & 0x1) != 0);
	
	// 2. copy remain
	if (remain)
		memcpy(dst + (len - remain), src + (len - remain), remain);
}*/

unsigned int *allocat_md_cmd(unsigned int num_of_cmd)
{
	unsigned int *cmd;
	unsigned int num_of_bytes = 4 * sizeof(unsigned int) * num_of_cmd;
        
                	
        cmd = (unsigned int*)memalign(16,num_of_bytes); 
        if (!cmd) {
            printf("Can not allocate memory of MD\n");
            free(cmd);
            return NULL;
        }               
        
	memset(cmd, 0, num_of_bytes);
	
	return cmd;
}
