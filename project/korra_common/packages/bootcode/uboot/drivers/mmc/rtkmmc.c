/*
 *  This is a driver for the eMMC controller found in Realtek RTD1195
 *  SoCs.
 *
 *  Copyright (C) 2013 Realtek Semiconductors, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include "rtkmmc.h"
#include <platform_lib/board/gpio.h>
#include <asm/arch/rbus/crt_reg.h>
#define __RTKMMC_C__
#define MAX_CMD_RETRY   10
#define MAX_CMD_RETRY_COUNT    15

/* mmc spec definition */
const unsigned int tran_exp[] = {
    10000, 100000, 1000000, 10000000,
    0,     0,      0,       0
};

const unsigned char tran_mant[] = {
    0,  10, 12, 13, 15, 20, 25, 30,
    35, 40, 45, 50, 55, 60, 70, 80,
};

const unsigned int tacc_exp[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
};

const unsigned int tacc_mant[] = {
    0,  10, 12, 13, 15, 20, 25, 30,
    35, 40, 45, 50, 55, 60, 70, 80,
};

const char *const state_tlb[9] = {
    "STATE_IDLE",
    "STATE_READY",
    "STATE_IDENT",
    "STATE_STBY",
    "STATE_TRAN",
    "STATE_DATA",
    "STATE_RCV",
    "STATE_PRG",
    "STATE_DIS"
};
const char *const bit_tlb[4] = {
    "1bit",
    "4bits",
    "8bits",
    "unknow"
};

const char *const clk_tlb[8] = {
    "30MHz",
    "40MHz",
    "49MHz",
    "49MHz",
    "15MHz",
    "20MHz",
    "24MHz",
    "24MHz"
};

/************************************************************************
 *  global variable
 ************************************************************************/
unsigned cr_int_status_reg;
unsigned int sys_ext_csd_addr;
unsigned int rtkmmc_debug_msg;
unsigned int rtkmmc_off_error_msg_in_init_flow;
static e_device_type emmc_card;
static unsigned int sys_rsp17_addr;
static unsigned char* ptr_ext_csd;
static UINT8 g_cmd[6]={0};
static int bErrorRetry_1=0, bErrorRetry_2=0;
extern int mmc_ready_to_use;
int swap_endian(UINT32 input);

/**************************************************************************************
 * phoenix mmc driver
 **************************************************************************************/
/*******************************************************
 *
 *******************************************************/
int mmc_data_sync( struct mmc * mmc )
{
    MMCPRINTF("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    
    mmc->rca = emmc_card.rca;
    mmc->high_capacity = emmc_card.sector_addressing ? 1 : 0;
	return 0;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_send_status(UINT8* state)
{
    UINT32 rom_resp[4];
    int rom_err = 0;

    MMCPRINTF("*** %s %s %d - rca : %08x, rca addr : %08x\n", __FILE__, __FUNCTION__, __LINE__, emmc_card.rca, &emmc_card.rca);
    
    rom_err = mmccr_SendCmd(MMC_SEND_STATUS,
                                   emmc_card.rca,
                                   -1,
                                   SD_R1|CRC16_CAL_DIS,
                                   0,
                                   rom_resp);
    if(rom_err){
#ifdef THIS_IS_FLASH_WRITE_U_ENV
        MMCPRINTF("MMC_SEND_STATUS fail\n");
#else
        MMCPRINTF("MMC_SEND_STATUS fail\n");
#endif
    }else{
        UINT8 cur_state = R1_CURRENT_STATE(rom_resp[0]);
        *state = cur_state;

#ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("cur_state=");
            prints(state_tlb[cur_state]);
            prints("\n");
#else
            MMCPRINTF("cur_state=");
            MMCPRINTF(state_tlb[cur_state]);
            MMCPRINTF("\n");
#endif
}

    return rom_err;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_wait_status(UINT8 state)
{
    UINT32 rom_resp[4];
    UINT32 timeend;
    int rom_err = 0;

    timeend = 150;

    while(timeend--)
     {
        sync();
        rom_err = mmccr_SendCmd(MMC_SEND_STATUS,
                                       emmc_card.rca,
                                       0x10,
                                       SD_R1|CRC16_CAL_DIS,
                                       0,
                                       rom_resp);

        if(rom_err){
#ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("wait ");
            prints(state_tlb[state]);
            prints(" fail\n");
#endif
            break;
        }
        else{
            UINT8 cur_state = R1_CURRENT_STATE(rom_resp[0]);
#ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("cur_state=");
            prints(state_tlb[cur_state]);
            prints("\n");
#endif
            rom_err = -10;
            if(cur_state == state){
                if(rom_resp[0] & R1_READY_FOR_DATA){
                    rom_err = 0;
                    break;
                }
            }
        }
        mdelay(1);
    }

    return rom_err;
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_div( unsigned int set_div, unsigned int show_msg )
{
    unsigned int tmp_div;
    
	MMCPRINTF("mmccr_set_div; switch to 0x%08x\n", set_div);
    
    tmp_div = cr_readb(SD_CONFIGURE1) & ~MASK_CLOCK_DIV;
    cr_writeb(tmp_div|set_div,SD_CONFIGURE1);

    if( show_msg )
    	MMCPRINTF("0x18012180=0x%08x\n", cr_readb(SD_CONFIGURE1));
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_bits_width( unsigned int set_bit )
{
    unsigned int tmp_bits;
	MMCPRINTF("mmccr_set_bits_width; switch to 0x%08x\n",set_bit);
    tmp_bits = cr_readb(SD_CONFIGURE1) & ~MASK_BUS_WIDTH;
    cr_writeb((UINT8)(tmp_bits|set_bit|0x10),SD_CONFIGURE1);
}

/*******************************************************
 *
 *******************************************************/
int mmccr_change_to_DDR50()
{
    int ret_err=0;
    int arg=0;
    unsigned int rsp_buffer[4];

    MMCPRINTF("%s - start\n", __func__);

    arg = (MMC_SWITCH_MODE_WRITE_BYTE << 24)|
          (EXT_CSD_HS_TIMING          << 16)|
          (EXT_CSD_HS_TIME_1          << 8)|
           0x00;    

    ret_err = mmccr_SendCmd(MMC_SWITCH, arg, -1, SD_R3, RESP_TIMEOUT_EN|ADDR_BYTE_MODE , rsp_buffer);
    if(ret_err) {
        MMCPRINTF("cmd6 fail, ret_err=%d\n", ret_err);
    }
    return ret_err;
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_speed( unsigned int para )
{
    cr_writeb(0x66,CARD_PAD_DRV);
    cr_writeb(0x64,CMD_PAD_DRV);
    cr_writeb(0x66,DATA_PAD_DRV);
    //cr_writel(0x40,SD_SAMPLE_POINT_CTL); //3.3v , fixed 1/4
    
    switch(para)
    {
        case 0: //DDR50
            cr_writel(0x2100,CR_DIV);
            break;
        case 1:
            cr_writel(0x2101,CR_DIV);
            break;
        case 2:
        default :
            cr_writel(0x2102,CR_DIV);
            break;          
    }
    sync();
}

/*******************************************************
 *
 *******************************************************/
void mmccr_read_rsp( void * rsp, int reg_count )
{
    UINT8 tmpcmd[5]={0};
    UINT32 *ptr = rsp;
    uchar *pRSP, *pRSP1;
    int i;
    
    if ( reg_count == 6 ){
        sync();
        
        tmpcmd[0] = cr_readb(SD_CMD0);
        tmpcmd[1] = cr_readb(SD_CMD1);
        tmpcmd[2] = cr_readb(SD_CMD2);
        tmpcmd[3] = cr_readb(SD_CMD3);
        tmpcmd[4] = cr_readb(SD_CMD4);
        tmpcmd[5] = cr_readb(SD_CMD5);
        //device is big-endian
        REG32(ptr) = (UINT32)((tmpcmd[0]<<24) |
                 (tmpcmd[1]<<16) |
                 (tmpcmd[2]<<8) |
                  tmpcmd[3]) ;
        REG32(ptr+1) = (UINT32)((tmpcmd[5]<<24) |
                                (tmpcmd[4]<<16));
        
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("rsp len 6 : ");
        prints("cmd0: ");
        print_val(tmpcmd[0],2);
        prints(" cmd1: ");
        print_val(tmpcmd[1],2);
        prints(" cmd2: ");
        print_val(tmpcmd[2],2);
        prints(" cmd3: ");
        print_val(tmpcmd[3],2);
        prints(" cmd4: ");
        print_val(tmpcmd[4],2);
        prints(" cmd5: ");
        print_val(tmpcmd[5],2);
        prints(" ptr0: ");
        print_hex(REG32(ptr));
        prints(" ptr1: ");
        print_hex(REG32(ptr+1));
        prints("\n");
        #else
        MMCPRINTF("rsp 6 : 0 = 0x%08x , 1 = 0x%08x\n", *ptr, *(ptr+1));
        #endif
        
    }
    else if( reg_count == 17 ){
        REG32(ptr+0) = REG32(sys_rsp17_addr+0x00);
        REG32(ptr+1) = REG32(sys_rsp17_addr+0x04);
        REG32(ptr+2) = REG32(sys_rsp17_addr+0x08);
        REG32(ptr+3) = REG32(sys_rsp17_addr+0x0c);

        pRSP = sys_rsp17_addr;
        pRSP1 = ptr;
        for(i=0;i<15;i++)
        {
            *(uchar*)(pRSP1+i) = *(uchar*)(pRSP+i+1);
        }

        flush_cache(pRSP1, 16);
        REG32(ptr+0) = swap_endian(REG32(ptr+0));
        REG32(ptr+1) = swap_endian(REG32(ptr+1));
        REG32(ptr+2) = swap_endian(REG32(ptr+2));
        REG32(ptr+3) = swap_endian(REG32(ptr+3));
        MMCPRINTF("csd1 :%08x %08x %08x %08x\n", REG32(ptr+0),REG32(ptr+1),REG32(ptr+2),REG32(ptr+3));
    
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("rsp len 17B :[0] 0x");
        print_hex(REG32(ptr+0));
        prints(" [1] 0x");
        print_hex(REG32(ptr+1));
        prints(" [2] 0x");
        print_hex(REG32(ptr+2));
        prints(" [3] 0x");
        print_hex(REG32(ptr+3));
        prints("\n");
        #else
        MMCPRINTF("rsp 17 : [0]0x%08x , [1]0x%08x\n",*(ptr+0), *(ptr+1));
        MMCPRINTF("rsp 17 : [2]0x%08x , [3]0x%08x\n",*(ptr+2), *(ptr+3));
        #endif
    }
    
}

/*******************************************************
 *
 *******************************************************/
UINT32 mmccr_read_sram_dma_data(UINT32 sram_buf, UINT32 block_count)
{
				UINT32 i=0,blk_no=0, fifo_tmp0=0, fifo_tmp1=0;
                INT32 time_cnt=0;
                UINT32 cpu_acc_reg=0, dma_reg=0;
                
                if(sram_buf){
                    #ifdef THIS_IS_FLASH_WRITE_U_ENV
                    prints("sram_buf addr: 0x");
                    print_hex(sram_buf);
                    prints("\n");
                    prints("Read data from SRAM FIFO : blk_cnt=0x");
                    print_hex(block_count);
                    prints("\n");
                    #endif
                    while (block_count--)
                    {
                        #ifdef THIS_IS_FLASH_WRITE_U_ENV
                        prints("\n[blk no. ");
                        print_val(block_count+1, 2);
                        prints(" \n");
                        #endif
                        //1st half blk
                        for( i=0; i<512/4; i+=2 ){
                            fifo_tmp0 = cr_readl(CR_SRAM_BASE_0+i*4);
                            fifo_tmp1 = cr_readl(CR_SRAM_BASE_0+(i+1)*4);
                            REG32(sram_buf+(blk_no*0x200)+(i*4))= swap_endian(fifo_tmp1);
                            REG32(sram_buf+(blk_no*0x200)+(i+1)*4) = swap_endian(fifo_tmp0);
                            #ifdef THIS_IS_FLASH_WRITE_U_ENV
                            prints(" 0x");
                            print_hex(REG32(sram_buf+(blk_no*0x200)+(i*4)));
                            prints(" 0x");
                            print_hex(REG32(sram_buf+(blk_no*0x200)+(i+1)*4));
                            if ((i%10 == 0)&&(i!=0))
                                prints("\n");
                            #endif
                        }
                        if (block_count==0)
                        {
                            time_cnt=10*500; //1sec to timeout
                            for(i=time_cnt;i<=0;i--)
                            {
                                if ((REG8(SD_TRANSFER) & END_STATE) == END_STATE)
                                    break;
                                udelay(100);
                            }
                            if (i <= 0)
                                return ERR_EMMC_SRAM_DMA_TIME; 
                        }
                        if (block_count>=0)
                        {
                            //get next block
                            cpu_acc_reg = REG32(CR_CPU_ACC);
                            REG32(CR_CPU_ACC) = cpu_acc_reg|0x3;
                            time_cnt=10*1000; //1sec to timeout
                            for(i=time_cnt;i<=0;i--)
                            {
                                cpu_acc_reg = REG32(CR_CPU_ACC);
                                if ((cpu_acc_reg & BUF_FULL) == BUF_FULL)
                                    break;
                                udelay(100);
                            }
                            if (i <= 0)
                                return ERR_EMMC_SRAM_DMA_TIME; 
                            blk_no++;
                        }
                    }
                }
    //polling the buf_full to 0
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("polling buf_full to 0\n");
    #endif
    cpu_acc_reg = REG32(CR_CPU_ACC);
    time_cnt=10*500; //1sec to timeout
    for(i=time_cnt;i<=0;i--)
    {
        cpu_acc_reg = REG32(CR_CPU_ACC);
        if ((cpu_acc_reg & BUF_FULL) == 0x00)
            break;
        udelay(100);
    }
    if (i <= 0)
        return ERR_EMMC_SRAM_DMA_TIME; 

    //polling dma to 0
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("polling dma ctl3 to 0\n");
    #endif
    time_cnt=10*500; //1sec to timeout
    for(i=time_cnt;i<=0;i--)
    {
        dma_reg = REG32(CR_DMA_CTL3);
        if ((dma_reg  & DMA_XFER) == 0x00)
            break;
        udelay(100);
    }
    if (i <= 0)
        return ERR_EMMC_SRAM_DMA_TIME; 
    
    return 0;
}

/*******************************************************
 *
 *******************************************************/
int mmc_state_is_transfer_and_ready( e_device_type * card )
{

    unsigned int rsp_buffer[4];
    unsigned int  curr_state;
    int ret_err = 0;
    unsigned int retry_cnt;

	MMCPRINTF("mmc_state_is_transfer_and_ready()\n");

	retry_cnt = 0;
	while( retry_cnt++ < 2 ) {
		ret_err = mmccr_SendCmd(MMC_SEND_STATUS, card->rca, -1, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
	    if( !ret_err ) {
	    	if( retry_cnt == 2 ) {
		        curr_state = R1_CURRENT_STATE(rsp_buffer[0]);
		        MMCPRINTF("curr_state=%d\n", curr_state);
		        if( curr_state == STATE_TRAN /*4*/ ) {
		        	if(rsp_buffer[0] & R1_READY_FOR_DATA){
		                return 1;
		            }
		        }
		        else {
		        	return 0;
		        }
		    }
	    }
    	else {
    		return -1;
    	}
	}
    return -1;
}

/*******************************************************
 *
 *******************************************************/
unsigned int mmc_get_rsp_len( unsigned char rsp_para )
{
    switch (rsp_para & 0x3) {
	    case 0:
	        return 0; // hw bug ??
	    case 1:
	        return 6;
	    case 2:
	        return 17;
	    default:
	        return 0;
    }
}

/*******************************************************
 *
 *******************************************************/
unsigned int mmc_get_rsp_type( struct rtk_mmc_command * cmd )
{
    unsigned int rsp_type = 0;

    /* the marked case are used. */
    switch( cmd->opcode )
    {
        case 3:
        case 7:
        case 13:
        case 16:
        case 23:
        case 35:
        case 36:
        case 55:
            rsp_type |= CRC16_CAL_DIS;
        case 8:
        case 11:
        case 14:
        case 19:
        case 17:
        case 18:
        case 20:
        case 24:
        case 25:
        case 26:
        case 27:
        case 30:
        case 42:
        case 56:
            rsp_type |= SD_R1;
            break;
        case 6:
        case 12:
        case 28:
        case 29:
        case 38:
            rsp_type = SD_R1b|CRC16_CAL_DIS;
            break;
        case 2:
        case 9:
        case 10:
            rsp_type = SD_R2;
            break;
        case 1:
            rsp_type = SD_R3;
            break;
        default:
            rsp_type = SD_R0;
            break;
    }
    return rsp_type;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_TriggerXferCmd( unsigned char xferCmdCode, unsigned int cpu_mode )
{
    volatile UINT8 sd_transfer_reg;
    volatile int loops, loops1=0;
    volatile int err=0, timeout_cnt=0;

    sync(); 
    cr_writeb((UINT8) (xferCmdCode|START_EN), SD_TRANSFER );
    sync(); 

    if ((cr_readb(SD_TRANSFER) & ERR_STATUS) != 0x0) //transfer error
    {
        #ifdef FOR_ICE_LOAD  
        prints("\ncard trans err1 : 0x");
        print_hex(cr_readb(SD_TRANSFER));
        prints("st1 : 0x");
        print_hex(cr_readb(SD_STATUS1));
        prints("st2 : 0x");
        print_hex(cr_readb(SD_STATUS2));
        prints("bus st : 0x");
        print_hex(cr_readb(SD_BUS_STATUS));
        
        prints("\n");
        #endif        
        return CR_TRANSFER_FAIL;
    }

    //check1
    if (g_cmd[0] == 0x41)
    {
     loops = 10;     
     loops1 = 300; 
     while(loops ){
        while(loops1--)
        {
            if ((cr_readb(SD_TRANSFER) & ERR_STATUS) != 0x0) //transfer error
            {
                #ifdef FOR_ICE_LOAD  
                prints("\ncard trans err2 : 0x");
                print_hex(cr_readb(SD_TRANSFER));
                prints("\n");
                #endif
                
                return CR_TRANSFER_FAIL;
            }
            if ((cr_readb(SD_TRANSFER) & (END_STATE|IDLE_STATE))==(END_STATE|IDLE_STATE))
            {
                #ifdef FOR_ICE_LOAD  
                prints("\ncard transferred \n");
                #endif
                
                err = 0;
                break;
            }
            mdelay(1);
        }
        
        //card busy ??
        if ((cr_readb(SD_CMD1)&0x80)!=0x80)
        {
            //resend cmd again
            cr_writeb(g_cmd[0], SD_CMD0);
            cr_writeb(g_cmd[1],  SD_CMD1);
            cr_writeb(g_cmd[2],  SD_CMD2);
            cr_writeb(g_cmd[3],   SD_CMD3);
            cr_writeb(g_cmd[4],      SD_CMD4);
            cr_writeb(g_cmd[5],      SD_CMD5);
            sd_transfer_reg = (xferCmdCode|START_EN);
            cr_writeb(sd_transfer_reg , SD_TRANSFER );   
     	    loops1 = 300; 

            #ifdef FOR_ICE_LOAD  
            prints("\ncard busy : retry cmd = 0x");
            print_hex(g_cmd[0]);
            prints("\n");
            #endif
        }
        else
            break;
        
        mdelay(5);
        loops--;
     }
    }
    else
    {
        //check1
        loops = 100*20*3;     
        err = CR_TRANSFER_TO;
        while(loops ){
		if ((cpu_mode == 1)&&(((REG8(SD_BLOCK_CNT_H)<<8)|REG8(SD_BLOCK_CNT_L))>1))
            {
        	    err = 0;
        		break;
        	}
        	if ((cr_readb(SD_TRANSFER) & (END_STATE|IDLE_STATE))==(END_STATE|IDLE_STATE))
            {
        	    err = 0;
        		break;
        	}
        	if ((cr_readb(SD_TRANSFER) & (ERR_STATUS))==(ERR_STATUS))
            {
                RDPRINTF("\nsd transfer error (2193/status1/status2/bus_status) : \n\t0x%08x 0x%08x 0x%08x 0x%08x\n", cr_readb(SD_TRANSFER), cr_readb(SD_STATUS1), cr_readb(SD_STATUS2), cr_readb(SD_BUS_STATUS));
        	    err = CR_TRANSFER_TO;
        		break;
        	}
            udelay(500);
            loops--;
        }
        if (err == CR_TRANSFER_TO)
            RDPRINTF("\nsd transfer error (2193/status1/status2/bus_status) : \n\t0x%08x 0x%08x 0x%08x 0x%08x\n", cr_readb(SD_TRANSFER), cr_readb(SD_STATUS1), cr_readb(SD_STATUS2), cr_readb(SD_BUS_STATUS));
        	    
        #ifdef FOR_ICE_LOAD
        if (loops <= 0)
        {
            prints("\nwait sd transfer done timeout (0x18012193) : 0x");
            print_hex(cr_readb(SD_TRANSFER));
            prints("\nwait sd transfer done timeout (0x18012183) : 0x");
            print_hex(cr_readb(SD_STATUS1));
            prints("\nwait sd transfer done timeout (0x18012184) : 0x");
            print_hex(cr_readb(SD_STATUS2));
            prints("\nwait sd transfer done timeout (0x18012185) : 0x");
            print_hex(cr_readb(SD_BUS_STATUS));
            prints("\n");
        }
        #endif
    }
    
    //work around for cpu mode that dma status always high, user has to clear it
    if (g_cmd[0] == 0x42)
    {
        if (cpu_mode == 0)
        {
            timeout_cnt = 0;
            while (REG32(CR_DMA_CTL3) & DMA_XFER)
            {
                mdelay(3);
                if (timeout_cnt++ > 1000)
                {
                    #ifdef FOR_ICE_LOAD
                    prints("\ncmd 2 wait BUF_FULL to 0 fail. 0x");
                    print_hex(REG32(CR_CPU_ACC));
                    prints("\n");
                    #endif
                    return CR_DMA_FAIL;
                }
            }
            return 0;
        }
        timeout_cnt = 0;
        //polling the buf in 
        while (!(REG32(CR_CPU_ACC) & BUF_FULL))
        {
            mdelay(1);
            if (timeout_cnt++ > 1000)
            {
                #ifdef FOR_ICE_LOAD
                prints("\ncmd 2 wait BUF_FULL to 1 fail. 0x");
                print_hex(REG32(CR_CPU_ACC));
                prints("\n");
                #endif
                return CR_BUF_FULL_TO;
            }
        }

        //polling the buf_full to 0
        cr_writel(0x3, CR_CPU_ACC);
        mdelay(50);
        sync();
        loops=20*500*2; //2sec to timeout
        while(loops--)
        {
            if ((REG32(CR_CPU_ACC) & BUF_FULL) == 0x00)
                break;
            udelay(100);
        }
        if (loops <= 0)
        {
            #ifdef FOR_ICE_LOAD
            prints("\ncmd 2 poll cpu_acc timeout : 0x");
            print_hex(REG32(CR_CPU_ACC));
            prints("\n");
            #endif
            return 11; 
        }
        
        REG32(CR_DMA_CTL3) = 0x00; 

        #ifdef FOR_ICE_LOAD
        prints("\ncmd 2 poll cpu_acc/dma to 0x");
        print_hex(REG32(CR_CPU_ACC));
        prints(", 0x");
        print_hex(REG32(CR_DMA_CTL3));
        prints("\n");
        #endif
    }

    if (g_cmd[0] == 0x49)
    {
            timeout_cnt = 0;
            while (REG32(CR_DMA_CTL3) & DMA_XFER)
            {
                mdelay(3);
                if (timeout_cnt++ > 1000)
                {
                    #ifdef FOR_ICE_LOAD
                    prints("\ncmd 2 wait BUF_FULL to 0 fail. 0x");
                    print_hex(REG32(CR_CPU_ACC));
                    prints("\n");
                    #endif
                    return CR_DMA_FAIL;
                }
            }
            return 0;        
    }

    //check3
    if (cpu_mode == 1)
    {
      loops = 100*20*3;     
      err = CR_BUF_FULL_TO;
      #ifdef FOR_ICE_LOAD  
      prints("\ncr cpu mode - read\n");
      #endif
      while(loops ){
    	if ((cr_readl(CR_CPU_ACC) & BUF_FULL) == BUF_FULL)
        {
    	    return 0;
    	}
        udelay(500);
        loops--;
      }
      return 3;
    }

    cr_int_status_reg = 0;
    
    return err;
}


/*******************************************************
 *
 *******************************************************/
UINT32 IsAddressSRAM(UINT32 addr)
{
    if ((addr<0x10000000) || (addr > 0x10003FFF))
        //ddr address
        return 0;
    else
        //secureRam addr
        return 1;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_SendCmd( unsigned int cmd_idx,
                   unsigned int cmd_arg,
                   unsigned int rsp_para1,
                   unsigned int rsp_para2,
                   unsigned int rsp_para3,
                   void * rsp_buffer )
{
    unsigned int rsp_len;
    int ret_err;
    UINT32 sa;
    UINT32 byte_count = 0x200, block_count = 1;
    UINT32 cpu_mode=0;
    static UINT32 retry_count=0;

    if (cmd_idx == 0x9)
    {
         sys_rsp17_addr += 0x200;       
    }
    sa = sys_rsp17_addr / 8;
    cpu_mode = IsAddressSRAM(sys_rsp17_addr);

RET_CMD:
	rsp_len = mmc_get_rsp_len(rsp_para2);

    if( rtkmmc_debug_msg ) {
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("cmd_idx=0x");
        print_hex(cmd_idx);
        prints(" cmd_arg=0x");
        print_hex(cmd_arg);
        prints(" rsp_para1=0x");
        print_hex(rsp_para1);
        prints(" rsp_para2=0x");
        print_hex(rsp_para2);
        prints(" rsp_para3=0x");
        print_hex(rsp_para3);
        prints(" rsp_len=0x");
        print_val(rsp_len, 2);
        prints("\n");
        #else
		MMCPRINTF("cmd_idx=0x%08x cmd_arg=0x%08x rsp_para1=0x%02x rsp_para2=0x%02x \n\trsp_para3=0x%02x rsp_len=0x%02x cpu_mode=0x%02x\n", cmd_idx, cmd_arg, rsp_para1,rsp_para2,rsp_para3,rsp_len,cpu_mode);
        #endif
	}

    if (rsp_para1 != -1)
        cr_writeb(rsp_para1,     SD_CONFIGURE1);
    cr_writeb(rsp_para2,     SD_CONFIGURE2);
    if (rsp_para3 != -1)
        cr_writeb((UINT8)rsp_para3,     SD_CONFIGURE3);

    g_cmd[0] = (0x40|cmd_idx);
    g_cmd[1] = (cmd_arg>>24)&0xff;
    g_cmd[2] = (cmd_arg>>16)&0xff;
    g_cmd[3] = (cmd_arg>>8)&0xff;
    g_cmd[4] = cmd_arg&0xff;
    g_cmd[5] = 0x00;

    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("cmd0:");
    print_val(g_cmd[0],2);
    prints(" cmd1:");
    print_val(g_cmd[1],2);
    prints(" cmd2:");
    print_val(g_cmd[2],2);
    prints(" cmd3:");
    print_val(g_cmd[3],2);
    prints(" cmd4:");
    print_val(g_cmd[4],2);
    prints(" cmd5:");
    print_val(g_cmd[5],2);
    prints("\n");
    #else
    MMCPRINTF("cmd0:0x%02x cmd1:0x%02x cmd2:0x%02x cmd3:0x%02x cmd4:0x%02x cmd5:0x%02x\n",g_cmd[0],g_cmd[1],g_cmd[2],g_cmd[3],g_cmd[4],g_cmd[5]);
    #endif

    sync();
    flush_cache((unsigned long)g_cmd, 6);
    mdelay(10);
    
    cr_writeb(g_cmd[0], SD_CMD0);
    cr_writeb(g_cmd[1],  SD_CMD1);
    cr_writeb(g_cmd[2],  SD_CMD2);
    cr_writeb(g_cmd[3],   SD_CMD3);
    cr_writeb(g_cmd[4],      SD_CMD4);
    cr_writeb(g_cmd[5],      SD_CMD5);

    if (RESP_TYPE_17B & rsp_para2)
    {        
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("-----rsp 17B-----");
        prints(" DMA_sa=0x");
        print_hex(sa);
        prints(" DMA_len=0x");
        print_val(1, 2);
        prints(" DMA_setting=0x");
        print_hex(RSP17_SEL|DDR_WR|DMA_XFER);
    #else
        MMCPRINTF("-----rsp 17B-----\n DMA_sa=0x%08x DMA_len=0x%08x DMA_setting=0x%08x\n", sa,1,RSP17_SEL|DDR_WR|DMA_XFER);
    #endif
        cr_writeb(byte_count,       SD_BYTE_CNT_L);     //0x24
        cr_writeb(byte_count>>8,    SD_BYTE_CNT_H);     //0x28
        cr_writeb(block_count,      SD_BLOCK_CNT_L);    //0x2C
        cr_writeb(block_count>>8,   SD_BLOCK_CNT_H);    //0x30
        if (cpu_mode)
            cr_writel( CPU_MODE_EN, CR_CPU_ACC); //enable cpu mode
        else
            cr_writel( 0, CR_CPU_ACC);
        cr_writel(sa, CR_DMA_CTL1);   //espeical for R2
        cr_writel(1, CR_DMA_CTL2);   //espeical for R2
        cr_writel((RSP17_SEL|DDR_WR|DMA_XFER)&0x3f, CR_DMA_CTL3);   //espeical for R2
    }        
    else if (RESP_TYPE_6B & rsp_para2)
    {   
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("-----rsp 6B-----\n");
        #else
        MMCPRINTF("-----rsp 6B-----\n");
        #endif
        cr_writel( 0x00, CR_CPU_ACC);
    }

    flush_cache((unsigned long)rsp_buffer, 16);
    ret_err = mmccr_TriggerXferCmd( SD_SENDCMDGETRSP, cpu_mode );
    

    if( !ret_err ){
        mmccr_read_rsp(rsp_buffer, rsp_len);
    }
    else
    {
#ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("case I : transfer cmd fail - 0x");
        print_hex(ret_err);
        prints("\n");
#else
        MMCPRINTF("case I : transfer cmd fail - 0x%08x\n", ret_err);
#endif
	if (retry_count++ < MAX_CMD_RETRY_COUNT)
	{
		sample_ctl_switch(0);
		goto RET_CMD;
	}
    }
    
    return ret_err;
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_ocr( void * ocr )
{
    struct rtk_mmc_ocr_reg *ocr_ptr;
    struct rtk_mmc_ocr *ptr = (struct rtk_mmc_ocr *) ocr;
    ocr_ptr = (struct rtk_mmc_ocr_reg *)&ptr->reg;

#ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("emmc: OCR\n");
    prints(" - start bit : ");
    print_val(ptr->start, 1);
    prints("\n");
    prints(" - transmission bit : ");
    print_val(ptr->transmission, 1);
    prints("\n");
    prints(" - check bits : ");
    print_val(ptr->check1, 2);
    prints("\n");
    prints(" - OCR register : \n");
    prints("   - 1.7v to 1.95v : ");
    print_val(ocr_ptr->lowV, 1);
    prints("\n   - 2.0v to 2.6v : ");
    print_val(ocr_ptr->val1, 2);
    prints("\n   - 2.7v to 3.6v : ");
    print_val(ocr_ptr->val2, 2);
    prints("\n   - access mode : ");
    print_val(ocr_ptr->access_mode, 1);
    prints("\n   - power up status : ");
    print_val(ocr_ptr->power_up, 1);
    prints("\n");
    prints(" - check bits : ");
    print_val(ptr->check2, 2);
    prints("\n");
    prints(" - end bit : ");
    print_val(ptr->end, 1);
    prints("\n");
#else
    MMCPRINTF("emmc: OCR\n");
    MMCPRINTF("- start bit : 0x%x\n", ptr->start);
    MMCPRINTF(" - transmission bit : 0x%x\n", ptr->transmission);
    MMCPRINTF(" - check bit : 0x%x\n", ptr->check1);
    MMCPRINTF(" - OCR register : \n");
    MMCPRINTF("   - 1.7v to 1.95v : 0x%x\n", ocr_ptr->lowV);
    MMCPRINTF("   - 2.0v to 2.6v : 0x%x\n", ocr_ptr->val1);
    MMCPRINTF("   - 2.7v to 3.6v : 0x%x\n", ocr_ptr->val2);
    MMCPRINTF("   - access mode : 0x%x\n", ocr_ptr->access_mode);
    MMCPRINTF("   - power up status : 0x%x\n", ocr_ptr->power_up);
    MMCPRINTF(" - check bits : 0x%x\n", ptr->check2);
    MMCPRINTF(" - end bits : 0x%x\n", ptr->end);
#endif
}

/*******************************************************
 *
 *******************************************************/
int mmc_send_stop( e_device_type * card )
{
    unsigned int rsp_buffer[4];

    MMCPRINTF("mmc_send_stop\n");

    return mmccr_SendCmd(MMC_STOP_TRANSMISSION, card->rca, -1, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
}

/*******************************************************
 *
 *******************************************************/
int mmccr_Stream_Cmd( unsigned int xferCmdCode, struct rtk_cmd_info * cmd_info )
{
    unsigned int cmd_idx      = cmd_info->cmd->opcode;
    unsigned int cmd_arg      = cmd_info->cmd->arg;
    unsigned int * rsp        = cmd_info->cmd->resp;
    unsigned int rsp_para1     = cmd_info->rsp_para1;
    unsigned int rsp_para2     = cmd_info->rsp_para2;
    unsigned int rsp_para3     = cmd_info->rsp_para3;
    int rsp_len         	  = cmd_info->rsp_len;
    unsigned int byte_count   = cmd_info->byte_count;
    unsigned int block_count  = cmd_info->block_count;
    unsigned int phy_buf_addr = (unsigned int) cmd_info->data_buffer;
    unsigned int timeout;
    int ret_err=1;
    UINT32 cpu_mode=0;
    unsigned int retry_count=0;

STREAM_CMD_RET:
	if( rtkmmc_debug_msg ) {
	    RDPRINTF("cmd_idx=0x%08x arg=0x%08x rsp_para1=0x%02x rsp_para2=0x%02x \nrsp_para3=0x%02x"
	            "     byte_count=0x%04x; block_count=0x%04x; phy addr=0x%08x\n",
	            cmd_idx, cmd_arg, rsp_para1, rsp_para2, rsp_para3, byte_count, block_count, phy_buf_addr);

		switch( xferCmdCode ) {
			case SD_AUTOREAD1:		RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_AUTOREAD1\n", xferCmdCode);	break;
			case SD_AUTOWRITE1:		RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_AUTOWRITE1\n", xferCmdCode);	break;
			case SD_AUTOREAD2:		RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_AUTOREAD2\n", xferCmdCode);	break;
			case SD_AUTOWRITE2:		RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_AUTOWRITE2\n", xferCmdCode);	break;
			case SD_NORMALREAD:		RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_NORMALREAD\n", xferCmdCode);	break;
			case SD_NORMALWRITE:	RDPRINTF("     XferCmdCode(08h)=0x%02x, SD_NORMALWRITE\n", xferCmdCode);	break;
			default:				RDPRINTF("     XferCmdCode(08h)=0x%02x, unknown\n", xferCmdCode);
		}
	}

        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("cmd_idx=0x");
        print_hex(cmd_idx);
        prints(" cmd_arg=0x");
        print_hex(cmd_arg);
        prints(" rsp_para1=0x");
        print_hex(rsp_para1);
        prints(" rsp_para2=0x");
        print_hex(rsp_para2);
        prints(" rsp_para3=0x");
        print_hex(rsp_para3);
        prints("\n");
        prints(" byte_count=0x");
        print_hex(byte_count);
        prints(" block_count=0x");
        print_hex(block_count);
        prints("\n");
        #else
        RDPRINTF("cmd_idx=0x%08x arg=0x%08x rsp_para1=0x%02x rsp_para2=0x%02x \nrsp_para3=0x%02x"
	    "     byte_count=0x%04x; block_count=0x%04x; phy addr=0x%08x\n",
	    cmd_idx, cmd_arg, rsp_para1, rsp_para2, rsp_para3, byte_count, block_count, phy_buf_addr);
        #endif

    g_cmd[0] = (0x40|cmd_idx);
    g_cmd[1] = (cmd_arg>>24)&0xff;
    g_cmd[2] = (cmd_arg>>16)&0xff;
    g_cmd[3] = (cmd_arg>>8)&0xff;
    g_cmd[4] = cmd_arg&0xff;
    g_cmd[5] = 0x00;

    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("cmd0:");
    print_val(g_cmd[0],2);
    prints(" cmd1:");
    print_val(g_cmd[1],2);
    prints(" cmd2:");
    print_val(g_cmd[2],2);
    prints(" cmd3:");
    print_val(g_cmd[3],2);
    prints(" cmd4:");
    print_val(g_cmd[4],2);
    prints(" cmd5:");
    print_val(g_cmd[5],2);
    prints(" conf1:");
    print_val(rsp_para1&0xff,2);
    prints(" conf2:");
    print_val(rsp_para2&0xff,2);
    prints(" conf3:");
    print_val(rsp_para3&0xff,2);
    prints("\n");
    #else
    RDPRINTF("cmd0:0x%02x cmd1:0x%02x cmd2:0x%02x cmd3:0x%02x cmd4:0x%02x cmd5:0x%02x\n",g_cmd[0], g_cmd[1], g_cmd[2], g_cmd[3], g_cmd[4], g_cmd[5]);
    #endif

    cr_writeb(g_cmd[0], SD_CMD0);
    cr_writeb(g_cmd[1],  SD_CMD1);
    cr_writeb(g_cmd[2],  SD_CMD2);
    cr_writeb(g_cmd[3],   SD_CMD3);
    cr_writeb(g_cmd[4],      SD_CMD4);
    cr_writeb(g_cmd[5],      SD_CMD5);

    if (rsp_para1 != -1)
        cr_writeb(rsp_para1,       SD_CONFIGURE1);     //0x0C
    cr_writeb(rsp_para2,       SD_CONFIGURE2);     //0x0C
    if (rsp_para3 != -1)
        cr_writeb(rsp_para3,       SD_CONFIGURE3);     //0x0C
    cr_writeb((byte_count)&0xff,     SD_BYTE_CNT_L);     //0x24
    cr_writeb((byte_count>>8)&0xff,  SD_BYTE_CNT_H);     //0x28
    cr_writeb((block_count)&0xff,    SD_BLOCK_CNT_L);    //0x2C
    cr_writeb((block_count>>8)&0xff, SD_BLOCK_CNT_H);    //0x30

    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("xfer_flag : ");
    print_hex(xferCmdCode|START_EN);
    prints("\n");
    #else
    RDPRINTF("xfer_flag : %x\n", xferCmdCode|START_EN);
    #endif

   	if( cmd_info->xfer_flag & RTK_MMC_DATA_WRITE){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("-----mmc data write-----\n");
        prints("DMA sa = 0x");
        print_hex(phy_buf_addr/8);
        prints("\nDMA len = 0x");
        print_hex(block_count);
        prints("\nDMA set = 0x");
        print_hex(DMA_XFER);
        prints("\n");
        #else
        RDPRINTF("-----mmc data write-----\n");
        RDPRINTF("DMA sa = 0x%x\nDMA len = 0x%x\nDMA set = 0x%x\n", phy_buf_addr/8, block_count, DMA_XFER);
        #endif

        cr_writel( 0, CR_CPU_ACC);
        cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        cr_writel( block_count, CR_DMA_CTL2);
        cr_writel( DMA_XFER, CR_DMA_CTL3);  
    }
    else{
        if( cmd_info->xfer_flag & RTK_MMC_SRAM_READ){
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("-----mmc data sram read (cpu mode)-----\n");
            prints("CR_CPU_ACC(0x18012080) = 0x");
            print_hex(CPU_MODE_EN);
            prints("\n");
            #else
            RDPRINTF("-----mmc data sram read (cpu mode)-----\n");
            RDPRINTF("CR_CPU_ACC(0x18012080) = 0x%x\n", CPU_MODE_EN);
            #endif

            if (cmd_idx == MMC_READ_MULTIPLE_BLOCK)
                cpu_mode = 1;
            cr_writel( 0, CR_CPU_ACC);
            cr_writel( CPU_MODE_EN, CR_CPU_ACC);
            cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        }
        else
        {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("-----mmc data ddr read-----\n");
            #else
            RDPRINTF("-----mmc data ddr read-----\n");
            #endif
            cr_writel( 0x00, CR_CPU_ACC);
            cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        }
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("DMA sa = 0x");
        print_hex(phy_buf_addr/8);
        prints("\nDMA len = 0x");
        print_hex(block_count);
        prints("\nDMA set = 0x");
        print_hex(DDR_WR|DMA_XFER);
        prints("\n");
        #else
        RDPRINTF("DMA sa = 0x%x\nDMA len = 0x%x\nDMA set = 0x%x\n", phy_buf_addr/8, block_count, DDR_WR|DMA_XFER);
        #endif
        cr_writel( block_count, CR_DMA_CTL2);
        cr_writel( DDR_WR|DMA_XFER, CR_DMA_CTL3);
    }

    ret_err = mmccr_TriggerXferCmd( xferCmdCode, cpu_mode );

#if 0
    if ((cr_readb(SD_STATUS1) & 0x80) == 0x80)
    {
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
	    prints("stream cmd crc7 error \n");
        #else
        RDPRINTF("stream cmd crc7 error \n");
        #endif
	    ret_err = 0x10;
	    return ret_err;
    }
#endif
    if( !ret_err ){
        if( cr_int_status_reg & RTKCR_INT_DECODE_ERROR )
        {
            RDPRINTF("cr_int_status_reg=0x%x\n", cr_int_status_reg);
            ret_err = -1;
        }
        else{
            if( cmd_info->xfer_flag == RTK_MMC_SRAM_READ ) {
                if ((ret_err = mmccr_read_sram_dma_data(phy_buf_addr, block_count)) == ERR_EMMC_SRAM_DMA_TIME)
                    return ret_err;
                udelay(1000);
            }
            else
                mmccr_read_rsp(rsp, rsp_len);
		}
        RDPRINTF("---stream cmd done---\n");
    }

err_out:
	if( ret_err ){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("ret_err=");
        print_hex(ret_err);
        prints("\n");
        #else
    	RDPRINTF("ret_err=%d\n", ret_err);
        #endif
	if (retry_count++ < MAX_CMD_RETRY_COUNT)
	{
		sample_ctl_switch(0);
		goto STREAM_CMD_RET;
	}
    }
    return ret_err;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_Stream( unsigned int address,
                  unsigned int blk_cnt,
                  unsigned int xfer_flag,
                  unsigned int * data_buffer )
{
    struct rtk_cmd_info cmd_info;
    struct rtk_mmc_command  cmd;
    unsigned int xferCmdCode;
    unsigned int cmd_retry_cnt;
    unsigned int counter;
    int rw_cmd_err;
    int card_state;
    int err = -1;
    int send_stop_cmd = 0;
    unsigned int rsp_type;
    cmd_info.cmd = &cmd;
    cmd.arg      = address;

    if( xfer_flag & RTK_MMC_DATA_WRITE ){
        xferCmdCode = SD_AUTOWRITE2; // cmd + data
        cmd.opcode = MMC_WRITE_BLOCK;
    }else{
        xferCmdCode = SD_AUTOREAD2; // cmd + data
        cmd.opcode = MMC_READ_SINGLE_BLOCK;
    }

    /* multi sector accress opcode */
    if( blk_cnt > 1 ){
        xferCmdCode-=1;
        cmd.opcode++; // 25 or 18 ( multi_block_xxxx )
      }

    rsp_type = mmc_get_rsp_type(&cmd);

    cmd_info.rsp_para1    = -1;
    cmd_info.rsp_para2    = rsp_type;
    switch(cmd.opcode)
    {
        case 18:
            cmd_info.rsp_para3    = 0x04;
            break;
        case 25:
            cmd_info.rsp_para3    = 0x03;
            break;
        default:
            cmd_info.rsp_para3    = -1;
            break;

    }
    cmd_info.rsp_len     = mmc_get_rsp_len(rsp_type);
    cmd_info.byte_count  = 0x200;
    cmd_info.block_count = blk_cnt;
    cmd_info.data_buffer = data_buffer;
    cmd_info.xfer_flag   = xfer_flag;

    err = mmccr_Stream_Cmd( xferCmdCode, &cmd_info );

    //reset cmd0
    g_cmd[0] = 0x00;

    return err;
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_cid( e_device_type *card )
{
	int i;
	unsigned int sn;
	unsigned char cid[16];
	for( i = 0; i < 4; i++ ) {
		cid[(i<<2)]   = ( card->raw_cid[i]>>24 ) & 0xFF;
		cid[(i<<2)+1] = ( card->raw_cid[i]>>16 ) & 0xFF;
		cid[(i<<2)+2] = ( card->raw_cid[i]>>8  ) & 0xFF;
		cid[(i<<2)+3] = ( card->raw_cid[i]     ) & 0xFF;
	}
#ifdef EMMC_SHOW_CID
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("emmc:CID");
    #else
	MMCPRINTF("emmc:CID");
    #endif
	for( i = 0; i < 16; i++ ) {
        
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        print_hex(cid[i]);
        #else
		MMCPRINTF(" %02x", cid[i]);
        #endif
	}
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("\n");
    #else
	MMCPRINTF("\n");
    #endif
#endif
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("CID     0x");
    print_hex(cid[0]);
    prints("\n");
    #else
	MMCPRINTF("CID    0x%02x\n", cid[0]);
    #endif
	switch( (cid[1] & 0x3) ) {
		case 0:
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("CBX    Card\n");
            #else
			MMCPRINTF("CBX    Card\n");
            #endif
            break;
		case 1:
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("CBX    BGA\n");	
            #else
			MMCPRINTF("CBX    BGA\n");		
            #endif
            break;
		case 2:
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("CBX    POP\n");
            #else
			MMCPRINTF("CBX    POP\n");		
            #endif
            break;
		case 3:
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("CBX    Unknown\n");
            #else
			MMCPRINTF("CBX    Unknown\n");	
            #endif
            break;
	}
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("OID    0x");
    print_val(cid[2],2);
    prints("\n");
    prints("PNM    0x");
    print_val(cid[3],2);
    print_val(cid[4],2);
    print_val(cid[5],2);
    print_val(cid[6],2);
    print_val(cid[7],2);
    print_val(cid[8],2);
    prints("\n");
    prints("PRV    0x");
    print_val((cid[9]>>4)&0xf,2);
    print_val(cid[9]&0xf,2);
    prints("\n");
    #else
	MMCPRINTF("OID    0x%02x\n", cid[2]);
	MMCPRINTF("PNM    %c%c%c%c%c%c\n", cid[3], cid[4], cid[5], cid[6], cid[7], cid[8]);
	MMCPRINTF("PRV    %d.%d\n", (cid[9]>>4)&0xf, cid[9]&0xf);
    #endif
	sn = cid[13];
	sn = (sn<<8) | cid[12];
	sn = (sn<<8) | cid[11];
	sn = (sn<<8) | cid[10];
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("PSN    ");
    print_hex(sn);
    prints("\n");
    #else
	MMCPRINTF("PSN    %u(0x%08x)\n", sn, sn);
    #endif
	if( cid[9] ) {
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
		prints("MDT    ");
        print_hex((cid[9]>>4)&0xf);
        print_hex((cid[14]&0xf)+1997);
        prints("\n");
        #else
		MMCPRINTF("MDT    %02d/%d)", (cid[9]>>4)&0xf, (cid[14]&0xf)+1997);
        #endif
	}
	else {
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("MDT    --/----\n");
        #else
		MMCPRINTF("MDT    --/----\n", (cid[9]>>4)&0xf, (cid[14]&0xf)+1997);
        #endif
	}
}


/*******************************************************
 *
 *******************************************************/
int mmc_decode_csd( struct mmc* mmc )
{
    struct rtk_mmc_csd vcsd;
    struct rtk_mmc_csd *csd = (struct rtk_mmc_csd*)&vcsd;
    unsigned int e, m;
    unsigned int * resp = mmc->csd;
    int err = 0;

    printf("mmc_decode_csd\n");
    memset(&vcsd, 0x00, sizeof(struct rtk_mmc_csd));

  /*
     * We only understand CSD structure v1.1 and v1.2.
     * v1.2 has extra information in bits 15, 11 and 10.
     * We also support eMMC v4.4 & v4.41.
     */
    csd->csd_ver2 = 0xff;
    csd->csd_ver = UNSTUFF_BITS(resp, 126, 2);

    // 0, CSD Ver. 1.0
    // 1, CSD Ver. 1.1
    // 2, CSD Ver. 1.2, define in spec. 4.1-4.3
    // 3, CSD Ver define in EXT_CSD[194]
    //    EXT_CSD[194] 0, CSD Ver. 1.0
    //                 1, CSD Ver. 1.1
    //                 2, CSD Ver. 1.2, define in spec. 4.1-4.51
    //                 others, RSV

    csd->mmca_vsn       = UNSTUFF_BITS(resp, 122, 4);
    m = UNSTUFF_BITS(resp, 115, 4);
    e = UNSTUFF_BITS(resp, 112, 3);
    csd->tacc_ns        = (tacc_exp[e] * tacc_mant[m] + 9) / 10;
    csd->tacc_clks      = UNSTUFF_BITS(resp, 104, 8) * 100;

    m = UNSTUFF_BITS(resp, 99, 4);
    e = UNSTUFF_BITS(resp, 96, 3);
    csd->max_dtr        = tran_exp[e] * tran_mant[m];
    csd->cmdclass       = UNSTUFF_BITS(resp, 84, 12);

    m = UNSTUFF_BITS(resp, 62, 12);
    e = UNSTUFF_BITS(resp, 47, 3);
    csd->capacity       = (1 + m) << (e + 2);
    csd->read_blkbits   = UNSTUFF_BITS(resp, 80, 4);
    csd->read_partial   = UNSTUFF_BITS(resp, 79, 1);
    csd->write_misalign = UNSTUFF_BITS(resp, 78, 1);
    csd->read_misalign  = UNSTUFF_BITS(resp, 77, 1);
    csd->r2w_factor     = UNSTUFF_BITS(resp, 26, 3);
    csd->write_blkbits  = UNSTUFF_BITS(resp, 22, 4);
    csd->write_partial  = UNSTUFF_BITS(resp, 21, 1);

    printf("CSD_STRUCTURE :%02x\n", csd->csd_ver);
    printf("SPEC_VERS   :%02x\n", csd->mmca_vsn);
    printf("TRAN_SPEED  :%02x\n", UNSTUFF_BITS(resp, 96, 8));
    printf("C_SIZE      :%08x\n",m);
    printf("C_SIZE_MULT :%08x\n",e);
    printf("Block Num   :%08x\n",csd->capacity);
    printf("Block Len   :%08x\n" ,1<<csd->read_blkbits);
    printf("Total Bytes :%08x\n",csd->capacity*(1<<csd->read_blkbits));
err_out:
    return err;
}

/*******************************************************
 *
 *******************************************************/
int mmc_decode_cid( struct mmc * rcard )
{
    e_device_type card;
    unsigned int * resp = rcard->cid;
    unsigned int * resp1 = rcard->csd;
    uint vsn = UNSTUFF_BITS(resp1, 122, 4);

    printf("mmc_decode_cid\n");
    /*
     * The selection of the format here is based upon published
     * specs from sandisk and from what people have reported.
     */
    switch (vsn) {
    case 0: /* MMC v1.0 - v1.2 */
    case 1: /* MMC v1.4 */
        card.cid.manfid        = UNSTUFF_BITS(resp, 104, 24);
        card.cid.prod_name[0]  = UNSTUFF_BITS(resp, 96, 8);
        card.cid.prod_name[1]  = UNSTUFF_BITS(resp, 88, 8);
        card.cid.prod_name[2]  = UNSTUFF_BITS(resp, 80, 8);
        card.cid.prod_name[3]  = UNSTUFF_BITS(resp, 72, 8);
        card.cid.prod_name[4]  = UNSTUFF_BITS(resp, 64, 8);
        card.cid.prod_name[5]  = UNSTUFF_BITS(resp, 56, 8);
        card.cid.prod_name[6]  = UNSTUFF_BITS(resp, 48, 8);
        card.cid.hwrev         = UNSTUFF_BITS(resp, 44, 4);
        card.cid.fwrev         = UNSTUFF_BITS(resp, 40, 4);
        card.cid.serial        = UNSTUFF_BITS(resp, 16, 24);
        card.cid.month         = UNSTUFF_BITS(resp, 12, 4);
        card.cid.year          = UNSTUFF_BITS(resp, 8,  4) + 1997;
        printf("cid v_1.0-1.4, manfid=%02x\n", card.cid.manfid);
        break;

    case 2: /* MMC v2.0 - v2.2 */
    case 3: /* MMC v3.1 - v3.3 */
    case 4: /* MMC v4 */
        card.cid.manfid        = UNSTUFF_BITS(resp, 120, 8);
        card.cid.oemid         = UNSTUFF_BITS(resp, 104, 16);
        card.cid.prod_name[0]  = UNSTUFF_BITS(resp, 96, 8);
        card.cid.prod_name[1]  = UNSTUFF_BITS(resp, 88, 8);
        card.cid.prod_name[2]  = UNSTUFF_BITS(resp, 80, 8);
        card.cid.prod_name[3]  = UNSTUFF_BITS(resp, 72, 8);
        card.cid.prod_name[4]  = UNSTUFF_BITS(resp, 64, 8);
        card.cid.prod_name[5]  = UNSTUFF_BITS(resp, 56, 8);
        card.cid.serial        = UNSTUFF_BITS(resp, 16, 32);
        card.cid.month         = UNSTUFF_BITS(resp, 12, 4);
        card.cid.year          = UNSTUFF_BITS(resp, 8, 4) + 1997;
        printf("cid v_2.0-4, manfid=%02x, cbx=%02x\n", card.cid.manfid, UNSTUFF_BITS(resp, 112, 2));
        break;

    default:
        printf("card has unknown MMCA version %d\n",
                card.csd.mmca_vsn);
        return -1;
    }

    return 0;
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_csd( struct mmc* card )
{
	int i;
	unsigned char csd[16];
	for( i = 0; i < 4; i++ ) {
		csd[(i<<2)]   = ( card->csd[i]>>24 ) & 0xFF;
		csd[(i<<2)+1] = ( card->csd[i]>>16 ) & 0xFF;
		csd[(i<<2)+2] = ( card->csd[i]>>8  ) & 0xFF;
		csd[(i<<2)+3] = ( card->csd[i]     ) & 0xFF;
	}
#ifdef MMC_DEBUG
	printf("emmc:CSD(hex)");
	for( i = 0; i < 16; i++ ) {
		printf(" %02x", csd[i]);
	}
	printf("\n");
#endif
	mmc_decode_csd(card);
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_ext_csd( unsigned char * pext_csd )
{
	int i,j,k;
	unsigned int sec_cnt;
	unsigned int boot_size_mult;

	printf("emmc:EXT CSD\n");
	k = 0;
	for( i = 0; i < 32; i++ ) {
		printf("    : %03x", i<<4);
		for( j = 0; j < 16; j++ ) {
			printf(" %02x ", pext_csd[k++]);
		}
		printf("\n");
	}
	printf("    :k=%02x\n",k);

	boot_size_mult = pext_csd[226];
    
	printf("emmc:BOOT PART %04x ",boot_size_mult<<7);
    printf(" Kbytes(%04x)\n", boot_size_mult);
    
	sec_cnt = pext_csd[215];
	sec_cnt = (sec_cnt<<8) | pext_csd[214];
	sec_cnt = (sec_cnt<<8) | pext_csd[213];
	sec_cnt = (sec_cnt<<8) | pext_csd[212];

	printf("emmc:SEC_COUNT %04x\n", sec_cnt);
	printf(" emmc:reserve227 %02x\n", pext_csd[227]);
	printf(" emmc:reserve240 %02x\n", pext_csd[240]);
	printf(" emmc:reserve254 %02x\n", pext_csd[254]);
	printf(" emmc:reserve256 %02x\n", pext_csd[256]);
	printf(" emmc:reserve493 %02x\n", pext_csd[493]);
	printf(" emmc:reserve505 %02x\n", pext_csd[505]);
}


/*******************************************************
 *
 *******************************************************/
int mmc_read_ext_csd( e_device_type * card )
{
    struct rtk_cmd_info cmd_info;
    struct rtk_mmc_command  cmd;
    unsigned int xferCmdCode;
    unsigned int rsp_type;
    int ret_err;

    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("mmc_read_ext_csd\n");
    #else
    MMCPRINTF("mmc_read_ext_csd\n");
    #endif

    cmd_info.cmd= &cmd;
    cmd.arg     = 0;
    cmd.opcode = MMC_SEND_EXT_CSD;

    rsp_type = mmc_get_rsp_type(&cmd);

    MMCPRINTF("ext_csd ptr 0x%p\n",sys_ext_csd_addr);

    cmd_info.rsp_para1    = 0x10;
    cmd_info.rsp_para2    = rsp_type;
    cmd_info.rsp_para3    = 0x3;
    cmd_info.rsp_len     = mmc_get_rsp_len(rsp_type);
    cmd_info.byte_count  = 0x200;
    cmd_info.block_count = 1;
    cmd_info.data_buffer = sys_ext_csd_addr;
    cmd_info.xfer_flag   = RTK_MMC_DATA_READ;
    xferCmdCode          = SD_NORMALREAD;

    ret_err = mmccr_Stream_Cmd( xferCmdCode, &cmd_info);

    if(ret_err){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("unable to read EXT_CSD(ret_err=");
        print_hex(ret_err);
        prints("\n");
        #else
        MMCPRINTF("unable to read EXT_CSD(ret_err=%d)", ret_err);
        #endif
    }
    else{
    	mmc_show_ext_csd(sys_ext_csd_addr);

		card->ext_csd.boot_blk_size = (*(ptr_ext_csd+226)<<8);
        card->csd.csd_ver2 = *(ptr_ext_csd+194);
        card->ext_csd.rev = *(ptr_ext_csd+192);
        card->ext_csd.part_cfg = *(ptr_ext_csd+179);
        card->ext_csd.boot_cfg = *(ptr_ext_csd+178);
        card->ext_csd.boot_wp_sts = *(ptr_ext_csd+174);
        card->ext_csd.boot_wp = *(ptr_ext_csd+173);
		card->curr_part_indx = card->ext_csd.part_cfg & 0x07;

        #ifdef THIS_IS_FLASH_WRITE_U_ENV
		prints("emmc:BOOT PART MULTI = 0x");
        print_hex(*(ptr_ext_csd+226));
        prints(", BP_BLKS=0x");
        print_hex(*(ptr_ext_csd+226)<<8);
        prints("\n");
		prints("emmc:BOOT PART CFG = 0x");
        print_hex(card->ext_csd.part_cfg);
        prints("(0x");
        print_hex(card->curr_part_indx);
        prints(")\n");
        #else
		MMCPRINTF("emmc:BOOT PART MULTI = 0x%02x, BP_BLKS=0x%08x\n", *(ptr_ext_csd+226), *(ptr_ext_csd+226)<<8);
		MMCPRINTF("emmc:BOOT PART CFG = 0x%02x(%d)\n", card->ext_csd.part_cfg, card->curr_part_indx);
        #endif

		if (card->ext_csd.rev > 6) {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("unrecognized EXT_CSD structure version ");
            print_hex(card->ext_csd.rev);
            prints(", please update fw\n", card->ext_csd.rev);
            #else
            MMCPRINTF("unrecognized EXT_CSD structure version %d, please update fw\n", card->ext_csd.rev);
            #endif
        }

        if (card->ext_csd.rev >= 2) {
            card->ext_csd.sectors = *((unsigned int *)(ptr_ext_csd+EXT_CSD_SEC_CNT));
        }

        switch (*(ptr_ext_csd+EXT_CSD_CARD_TYPE) & (EXT_CSD_CARD_TYPE_26|EXT_CSD_CARD_TYPE_52)) {
	        case EXT_CSD_CARD_TYPE_52 | EXT_CSD_CARD_TYPE_26:
	            card->ext_csd.hs_max_dtr = 52000000;
	            break;
	        case EXT_CSD_CARD_TYPE_26:
	            card->ext_csd.hs_max_dtr = 26000000;
	            break;
	        default:
	            /* MMC v4 spec says this cannot happen */
                #ifdef THIS_IS_FLASH_WRITE_U_ENV
                prints("card is mmc v4 but does not support any high-speed modes.\n");
                #else
	            MMCPRINTF("card is mmc v4 but doesn't " "support any high-speed modes.\n");
                #endif
        }

        if (card->ext_csd.rev >= 3) {
            unsigned int sa_shift = *(ptr_ext_csd+EXT_CSD_S_A_TIMEOUT);
            /* Sleep / awake timeout in 100ns units */
            if (sa_shift > 0 && sa_shift <= 0x17){
                card->ext_csd.sa_timeout = 1 << *(ptr_ext_csd+EXT_CSD_S_A_TIMEOUT);
            }
        }
    }

    return ret_err;
}


/*******************************************************
 *
 *******************************************************/
int mmc_send_csd( e_device_type * card )
{
    MMCPRINTF("mmc_send_csd\n");

    /* Read CSD ==> CMD9 */
    return mmccr_SendCmd(MMC_SEND_CSD, emmc_card.rca, 0, SD_R2, SD2_R0, emmc_card.raw_csd);
}

/*******************************************************
 *
 *******************************************************/
int mmccr_hw_reset_signal( void )
{
	unsigned int tmp_mux;
	unsigned int tmp_dir;
	unsigned int tmp_dat;

	#define PIN_MUX_REG		(0xb8000814UL)
	#define PIN_DIR_REG		(0xb801bc00UL)
	#define PIN_DAT_REG		(0xb801bc18UL)

	tmp_mux = cr_readl( PIN_MUX_REG );
	tmp_dir = cr_readl( PIN_DIR_REG );
	tmp_dat = cr_readl( PIN_DAT_REG );

	cr_writel( tmp_dat|(1<<20), PIN_DAT_REG );
	cr_writel( tmp_dir|(1<<20), PIN_DIR_REG );
	cr_writel( tmp_dat|(1<<20), PIN_DAT_REG ); // high

	cr_writel( tmp_mux|(0xF<<28), PIN_MUX_REG );

	cr_writel( tmp_dat&~(1<<20), PIN_DAT_REG );  // low
	udelay(10);
	cr_writel( tmp_dat|(1<<20), PIN_DAT_REG ); // high

	cr_writel( tmp_mux, PIN_MUX_REG ); // restore original status

	return 0;
}

void set_emmc_pin_mux(void)
{
        //1195
        //set default i/f to cr
        unsigned int reg_val=0;
        reg_val = REG32(SYS_muxpad0);
    reg_val &= ~0xFFFF0FFF;
        reg_val |= 0xaaaa0aa8;
        REG32(SYS_muxpad0) = reg_val;
}

/*******************************************************
 *
 *******************************************************/
int mmccr_init_setup( void )
{   
    set_emmc_pin_mux();
    
	rtkmmc_debug_msg = 1;
	rtkmmc_off_error_msg_in_init_flow = 1;
    sys_rsp17_addr = S_RSP17_ADDR;   //set rsp buffer addr
    sys_ext_csd_addr = S_EXT_CSD_ADDR;
    ptr_ext_csd = (UINT8*)sys_ext_csd_addr;
	emmc_card.rca = 1<<16;
    emmc_card.sector_addressing = 0;

    if (GET_CHIP_REV() >= PHOENIX_REV_B)
    {
	printf("rtk_emmc : Detect chip rev. >= B\n");
    	REG32(PLL_EMMC1) = 0xe0003;     //LDO1.8V
    	REG32(CR_PAD_CTL) = 0;              //PAD to 1.8V
    }

    #ifdef CONFIG_BOARD_FPGA_RTD1195_EMMC
    cr_writel( 0x200000, DUMMY_SYS );
    #endif
    cr_writeb( 0x2, CARD_SELECT );            //select SD

	udelay(100000);

    mmccr_set_div(EMMC_INIT_CLOCK_DIV, 0);
	return 0;
}

/*******************************************************
 *
 *******************************************************/
 //emmc init flow that for fast init purpose. (for romcode)
int mmc_initial( int reset_only )
{
    unsigned int tmp;
    unsigned int rsp_buffer[4];
    int ret_err=0,i;
    unsigned int counter=0;
    unsigned int arg=0;
    unsigned int cmd_retry_cnt=0;

    //1. module / clk select
    //move to setup
    if (reset_only)
    {
        mmccr_init_setup();
        return 0;
    }

    mdelay(10);
    sync();

    //2. go
RE_IDLE:
   if (bErrorRetry_1)
    {
        cr_writeb( 0x8, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
        cr_writeb( 0x10, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
    }
    else
    {
        cr_writeb( 0x0, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
        cr_writeb( 0x0, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
    }
	
    mdelay(100);
    
	/* Reset command ==> CMD0 */
    mmccr_SendCmd(MMC_GO_IDLE_STATE, 0, SD1_R0, SD_R0, 0, rsp_buffer);

    /* Idle state ==> CMD1 */
    ret_err = 0;
    counter = 10;
    for(i=0;i<counter;i++)
    {
	if (GET_CHIP_REV() >= PHOENIX_REV_B)
    		ret_err = mmccr_SendCmd(MMC_SEND_OP_COND, (MMC_SECTOR_ADDR|EMMC_VDD_1_8), SD1_R0, SD_R3, 0, (void*)&emmc_card.ocr);
	else
    		ret_err = mmccr_SendCmd(MMC_SEND_OP_COND, (MMC_SECTOR_ADDR|EMMC_VDD_33_34|EMMC_VDD_32_33|EMMC_VDD_31_32|EMMC_VDD_30_31), SD1_R0, SD_R3, 0, (void*)&emmc_card.ocr);
    	if (ret_err)
    	{
		bErrorRetry_1 = !bErrorRetry_1;
    	}
        else
            break;
    }
#if 0
    if (!(is_cr_power_up((void*)&emmc_card.ocr) && (ret_err == 0)))
    {
	bErrorRetry_1 = !bErrorRetry_1;
        goto RE_IDLE;
    }
#endif
    mmc_show_ocr((void*)&emmc_card.ocr);

    /* Ready state ==> CMD2 */
    udelay(100);
    ret_err = 0;
    ret_err = mmccr_SendCmd(MMC_ALL_SEND_CID, 0, SD1_R0, SD_R2, 0x10|SD2_R0, emmc_card.raw_cid);
    if(ret_err)
    {
        if (cmd_retry_cnt++ <= MAX_CMD_RETRY)
	{
	    bErrorRetry_1 = !bErrorRetry_1;
            goto RE_IDLE;
        }
        goto err_out;
    }

#if 0
	mmc_show_cid(&emmc_card);
#endif

	/* Indentification state ==> CMD3 */
    udelay(100);
    ret_err = 0;
    ret_err = mmccr_SendCmd(MMC_SET_RELATIVE_ADDR, emmc_card.rca, SD1_R0, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
    if(ret_err)
    {
        if (cmd_retry_cnt++ <= MAX_CMD_RETRY)
	{
	    bErrorRetry_1 = !bErrorRetry_1;
            goto RE_IDLE;
        }
        goto err_out;
    }
    
#if 0 // just for debuging, CMD9's RSP data will be shift left 1 if clock is too quickly.
    /* card initial done, apply for higher clock */
    mmccr_set_div(EMMC_NORMAL_CLOCK_DIV, 1);
#endif

#if 0
    /* Send CSD  ==> CMD9 */
    udelay(100);
    ret_err = 0;
    ret_err = mmccr_SendCmd(MMC_SEND_CSD, emmc_card.rca, 0, SD_R2, SD2_R0, emmc_card.raw_csd);
    if(ret_err)
        goto err_out;

	mmc_show_csd(&emmc_card);
#endif

    /* card initial done, apply for higher clock */
    mmccr_set_div(CLOCK_DIV_NON, 1);
    //seems could be ignore
#if 0
    /* Send CID ==> CMD10 */
    udelay(100);
    ret_err = 0;
    ret_err = mmccr_SendCmd(MMC_SEND_CID, emmc_card.rca, 0, SD_R2, SD2_R0, rsp_buffer);
    if(ret_err){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("cmd10 error\n");
        #else
        MMCPRINTF("cmd10 error\n");
        #endif
        goto err_out;
    }
#endif
    /* reset sample ctl */
    if (bErrorRetry_2)
    {
        cr_writeb( 0x8, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
        cr_writeb( 0x10, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
    }
    else
    {
        cr_writeb( 0x0, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
        cr_writeb( 0x0, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
    }        

    /* Enter Transfer State ==> CMD7 */
    //TODO: phoneix sample : 0x18012181 = 0x41 not 0x49 ?
    udelay(100);
    ret_err = 0;
    ret_err = mmccr_SendCmd(MMC_SELECT_CARD, emmc_card.rca, 0, SD_R1b|CRC16_CAL_DIS, 0, rsp_buffer);
    if(ret_err){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("cmd7 error\n");
        #else
        MMCPRINTF("cmd7 error\n");
        #endif        
        if (cmd_retry_cnt++ <= MAX_CMD_RETRY)
	{
	    bErrorRetry_2 = !bErrorRetry_2;
            goto RE_IDLE;
	}
        goto err_out;
    }

#if 0
    /* Read Ext CSD ==> cmd8 */
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("cmd8\n");
    #else
    MMCPRINTF("cmd8\n");
    #endif
    udelay(100);
    ret_err = 0;
    ret_err = mmc_read_ext_csd(&emmc_card);
    if(ret_err){
        goto err_out;
    }
#endif

    /* change to 8bits width ==> CMD6 */
    if(0){
        #ifdef THIS_IS_FLASH_WRITE_U_ENV
        prints("change to 8bits....\n");
        #else
		MMCPRINTF("change to 8bits....\n");
        #endif
        udelay(100);
        ret_err = 0;
        arg = (MMC_SWITCH_MODE_WRITE_BYTE << 24)|
              (EXT_CSD_BUS_WIDTH          << 16)|
              (EXT_CSD_BUS_WIDTH_8        << 8)|
               0x00;
        //TODO : not 0x41 but 0x49 ??
        ret_err = mmccr_SendCmd(MMC_SWITCH, arg, 0, SD_R1b|CRC16_CAL_DIS, 0, rsp_buffer);
        if(ret_err) {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("cmd6 fail, ret_err=");
            print_hex(ret_err);
            prints("\n");
            #else
        	MMCPRINTF("cmd6 fail, ret_err=%d\n", ret_err);
            #endif
            goto err_out;
        }

        /* To wait status change complete */
        ret_err = 0;
        counter = 100;
        do {
            udelay(1000);
            ret_err = mmccr_SendCmd(MMC_SEND_STATUS, emmc_card.rca, 0x10, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
            if(ret_err) {
                #ifdef THIS_IS_FLASH_WRITE_U_ENV
                prints("cmd13 fail, ret_err=");
                print_hex(ret_err);
                prints("\n");
                #else
            	MMCPRINTF("cmd13 fail, ret_err=%d\n", ret_err);
                #endif
                goto err_out;
            }

            counter--;
        }
        while((R1_CURRENT_STATE( rsp_buffer[0] ) == STATE_PRG) && counter);

        prints("send status rsp : ");
        print_hex(rsp_buffer[0]);
        prints("\n");

        if( ( rsp_buffer[0] & R1_SWITCH_ERROR ) || ( counter == 0 ) )
        {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("cmd6 response error\n");
            #else
            MMCPRINTF("cmd6 response error\n");
            #endif
            ret_err = -1;
            goto err_out;
        }
        else{
            mmccr_set_bits_width(BUS_WIDTH_8);
        }
    }

    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("emmc: set the block len to 512B\n");
    prints("emmc: init finish\n");
    #else
    MMCPRINTF("emmc: set the block len to 512B\n");
    MMCPRINTF("emmc: init finish\n");
    #endif

    return ret_err;
err_out:
    #ifdef THIS_IS_FLASH_WRITE_U_ENV
    prints("emmc: init error \n");
    #else
    MMCPRINTF("emmc: init error \n");
    #endif
    return ret_err;

}

/*******************************************************
 *
 *******************************************************/
void sample_ctl_switch(UINT32 bWrite)
{
                bErrorRetry_2 = !bErrorRetry_2;

                if (!bErrorRetry_2)
                {
                    #ifdef THIS_IS_FLASH_WRITE_U_ENV
                    prints("mode switch 1\n");
                    #else
                    MMCPRINTF("mode switch 1\n");
                    #endif
                    cr_writeb( 0x8, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                    cr_writeb( 0x10, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                }
                else
                {
                    #ifdef THIS_IS_FLASH_WRITE_U_ENV
                    prints("mode switch 0\n");
                    #else
                    MMCPRINTF("mode switch 0\n");
                    #endif
                    cr_writeb( 0x0, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                    cr_writeb( 0x0, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                }
                mdelay(5);
                REG8(CR_CARD_STOP) = 0x14;
                mdelay(5);
}

/*******************************************************
 *
 *******************************************************/
int rtk_eMMC_init( void )
{
    unsigned int tmp;
	int ret_err;
	int retry_counter;

	ret_err = -1;
	retry_counter = 3;
    emmc_card.rca = 1<<16;
    emmc_card.sector_addressing = 1;          

	while( retry_counter-- ) {
		ret_err = mmc_initial(1);
		if( ret_err ) {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
            prints("emmc: init fail(");
            print_hex(ret_err);
            prints(")\n");
            #else
			MMCPRINTF("\nemmc: init fail(%d)\n", ret_err);
            #endif
		}
		else {
			return ret_err;
		}
	}
	return ret_err;
}

/*******************************************************
 *
 *******************************************************/
int rtk_eMMC_write( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer )
{
    int ret_err = 0;
    unsigned int total_blk_cont;
    unsigned int curr_xfer_blk_cont;
    unsigned int address;
    unsigned int curr_blk_addr;
    unsigned int target_part_idx;
    e_device_type * card = &emmc_card;
    unsigned int counter;
    unsigned int rsp_buffer[4];
    UINT8 ret_state=0;
    UINT32 tar_dest=0, bRetry=0;
    UINT32 retry_cnt=0, retry_cnt1=0, retry_cnt2=0, retry_cnt3=0;
    int err = 0, err1=0;

    RDPRINTF("\nemmc:%s blk_addr=0x%08x, data_size=0x%08x, buffer=0x%08x, addressing=%d\n", __FUNCTION__, blk_addr, data_size, buffer, card->sector_addressing);

    if( !mmc_ready_to_use ) {
         MMCPRINTF("emmc: not ready to use\n");
    }

    total_blk_cont = data_size>>9;
    if(data_size & 0x1ff) {
        total_blk_cont+=1;
    }

	curr_blk_addr = blk_addr;
#ifndef FORCE_SECTOR_MODE
	if( card->sector_addressing ) {
		address = curr_blk_addr;
	}
	else {
		address = curr_blk_addr << 9;
	}
#else
    address = curr_blk_addr;
#endif

#ifdef EMMC_SPLIT_BLK
	while( total_blk_cont ) {
		if( total_blk_cont > EMMC_MAX_XFER_BLKCNT ) {
			curr_xfer_blk_cont = EMMC_MAX_XFER_BLKCNT;
		}
		else {
			curr_xfer_blk_cont = total_blk_cont;
		}

		flush_cache((unsigned long)buffer, curr_xfer_blk_cont << 9);
		ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_DATA_WRITE, buffer );

		if( ret_err ) {
			return 0;
		}
		total_blk_cont -= curr_xfer_blk_cont;
		buffer += (curr_xfer_blk_cont<<(9-2));
		address += curr_xfer_blk_cont;
	}

	total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }

    return total_blk_cont;
#else
RETRY_RD_CMD:
    flush_cache((unsigned long)buffer, data_size);

    ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_DATA_WRITE, buffer );  //tbd : not verify


    if (ret_err)
    {
        if (retry_cnt2%3 == 0)
            sample_ctl_switch(1);
        if (retry_cnt2++ < EMMC_MAX_STOP_CMD_RETRY_CNT)
            goto RETRY_RD_CMD;
        return ret_err;
    }

    /* To wait status change complete */
    bRetry=0;
    retry_cnt=0;
    retry_cnt1=0;
    while(1)
    {
        err1 = mmccr_send_status(&ret_state);
        //1. if cmd sent error, try again
        if (err1)
        {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
	        prints("retry - case 1\n");
            #else
            MMCPRINTF("retry - case 1\n");
            #endif
            if (retry_cnt%5 == 0)
                sample_ctl_switch(1);
            if (retry_cnt++ > EMMC_MAX_CMD_SEND_RETRY_CNT)
                return ERR_EMMC_SEND_STATUS_RETRY_FAIL;
            mdelay(1);
            continue;
        }
        //2. get state
        if (ret_state != STATE_TRAN)
        {
            #ifdef THIS_IS_FLASH_WRITE_U_ENV
	        prints("retry - case 2\n");
            #else
            MMCPRINTF("retry - case 2\n");
            #endif
            bRetry = 1;
            if (retry_cnt1++ > EMMC_MAX_STOP_CMD_RETRY_CNT)
                return ERR_EMMC_SEND_RW_CMD_RETRY_FAIL;
            mmc_send_stop(&emmc_card);
            mdelay(1000);
        }
        else
        {
            //out peaceful
            if (bRetry == 0)
            {
                #ifdef THIS_IS_FLASH_WRITE_U_ENV
	            prints("retry - case 3\n");
                #else
                MMCPRINTF("retry - case 3\n");
                #endif
                return !ret_err ?  total_blk_cont : 0;
            }
            else
            {
                #ifdef THIS_IS_FLASH_WRITE_U_ENV
	            prints("retry - case 4\n");
                #else
                MMCPRINTF("retry - case 4\n");
                #endif
                retry_cnt2 = 0;
                if (retry_cnt3++ > EMMC_MAX_STOP_CMD_RETRY_CNT)
                    return ERR_EMMC_SEND_RW_CMD_RETRY_FAIL;
                goto RETRY_RD_CMD;
            }
        }
    }

#endif

    return !ret_err ?  total_blk_cont : 0;
}

/*******************************************************
 *
 *******************************************************/
int rtk_eMMC_read( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer )
{
    int ret_err = 0;
    unsigned int total_blk_cont;
    unsigned int curr_xfer_blk_cont;
    unsigned int address;
    unsigned int curr_blk_addr;
    unsigned int target_part_idx;
    e_device_type * card = &emmc_card;
    unsigned int counter;
    unsigned int rsp_buffer[4];
    UINT8 ret_state=0;
    UINT32 tar_dest=0, bRetry=0;
    UINT32 retry_cnt=0, retry_cnt1=0, retry_cnt2=0, retry_cnt3=0;
    int err = 0, err1=0;

    RDPRINTF("\nemmc:%s blk_addr=0x%08x, data_size=0x%08x, buffer=0x%08x, addressing=%d\n", __FUNCTION__, blk_addr, data_size, buffer, card->sector_addressing);

    if( !mmc_ready_to_use ) {
         RDPRINTF("emmc: not ready to use\n");
    }

    total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }

#ifndef FORCE_SECTOR_MODE
	if( card->sector_addressing ) {
		address = blk_addr;
	}
	else {
		address = blk_addr << 9;
	}
#else
    address = blk_addr;
#endif
#ifdef EMMC_SPLIT_BLK
	while( total_blk_cont ) {
		if( total_blk_cont > EMMC_MAX_XFER_BLKCNT ) {
			curr_xfer_blk_cont = EMMC_MAX_XFER_BLKCNT;
		}
		else {
			curr_xfer_blk_cont = total_blk_cont;
		}

		flush_cache((unsigned long)buffer, curr_xfer_blk_cont << 9);
        if (IS_SRAM_ADDR(buffer))
        	ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_SRAM_READ, buffer ); 
        else
        	ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_DATA_READ, buffer );
        
		if( ret_err ) {
			return 0;
		}
		total_blk_cont -= curr_xfer_blk_cont;
		buffer += (curr_xfer_blk_cont<<(9-2));
		address += curr_xfer_blk_cont;

		//EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

	}

	total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }
	return total_blk_cont;
#else
RETRY_RD_CMD:
    flush_cache((unsigned long)buffer, data_size);

    if (IS_SRAM_ADDR(buffer))
    	ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_SRAM_READ, buffer ); 
    else
    	ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_DATA_READ, buffer );


    if (ret_err)
    {
        if (retry_cnt2%3 == 0)
            sample_ctl_switch(0);
        if (retry_cnt2++ < EMMC_MAX_STOP_CMD_RETRY_CNT)
            goto RETRY_RD_CMD;
        return ret_err;
    }
    
    /* To wait status change complete */
    bRetry=0;
    retry_cnt=0;
    retry_cnt1=0;
    while(1)
    {
        err1 = mmccr_send_status(&ret_state);
        //1. if cmd sent error, try again
        if (err1)
        {
            if (retry_cnt%5 == 0)
                sample_ctl_switch(0);
            if (retry_cnt++ > EMMC_MAX_CMD_SEND_RETRY_CNT)
                return ERR_EMMC_SEND_STATUS_RETRY_FAIL;
            mdelay(1);
            continue;
        }
        //2. get state
        if (ret_state != STATE_TRAN) 
        {
            bRetry = 1;
            if (retry_cnt1++ > EMMC_MAX_STOP_CMD_RETRY_CNT)
                return ERR_EMMC_SEND_RW_CMD_RETRY_FAIL;
            mmc_send_stop(&emmc_card);
            mdelay(1000);
        }
        else
        {
            //out peaceful
            if (bRetry == 0)
                return !ret_err ?  total_blk_cont : 0;
            else
            {
                retry_cnt2 = 0;
                if (retry_cnt3++ > EMMC_MAX_STOP_CMD_RETRY_CNT)
                    return ERR_EMMC_SEND_RW_CMD_RETRY_FAIL;
                goto RETRY_RD_CMD;
            }
        }
    }
#endif

    return !ret_err ?  total_blk_cont : 0;
}

/*******************************************************
 *
 *******************************************************/
int do_rtkmmc (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret = CMD_RET_USAGE;
	unsigned int blk_addr, byte_size;
	void * mem_addr;

	if( argc == 5 ) {
		mem_addr   = (void *)simple_strtoul(argv[2], NULL, 16);
		blk_addr   = simple_strtoul(argv[3], NULL, 16);
		byte_size  = simple_strtoul(argv[4], NULL, 16);
		if( strncmp( argv[1], "read", 4 ) == 0 ) {
			ret = rtk_eMMC_read( blk_addr, byte_size, mem_addr);
			return (ret ? 0 : 1);
		}
		else if( strncmp( argv[1], "write", 5 ) == 0 ) {
			ret = rtk_eMMC_write( blk_addr, byte_size, mem_addr);
			return (ret ? 0 : 1);
		}
	}

	return  ret;	
}

/*******************************************************
 *
 *******************************************************/
U_BOOT_CMD(
	rtkmmc, 5, 0, do_rtkmmc,
	"RTK MMC direct read function",
	"          - rtkmmc read/write\n"
	"rtkmmc read addr blk_addr byte_size\n"
	"rtkmmc write addr blk_addr byte_size\n"
	""
);
