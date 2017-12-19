/*
 *  This is a driver for the eMMC controller found in Realtek Phoenix 1195
 *  SoCs.
 *
 *  Copyright (C) 2013 Realtek Semiconductors, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#pragma GCC push_options
#pragma GCC optimize ("O2")
//#include "mmc.h"
#include "rtkmmc.h"
#include "dvrboot_inc/sys_reg.h"
#include "dvrboot_inc/util.h"
#include "cache.h"

#define __RTKMMC_C__

unsigned char ext_csd[0x200];
unsigned char dummy_buffer[0x220];
unsigned char * dummy_512B;

#ifdef THIS_IS_FLASH_WRITE_U_ENV
static unsigned int rtkmmc_debug_msg;
static unsigned int rtkmmc_off_error_msg_in_init_flow;
static unsigned int sys_rsp17_addr;
static unsigned char* ptr_ext_csd;
static unsigned int sys_ext_csd_addr;
static UINT8 g_cmd[5]={0};
#else
unsigned int rtkmmc_debug_msg;
unsigned int rtkmmc_off_error_msg_in_init_flow;
#endif

#define ERR_EMMC_SEND_STATUS_RETRY_FAIL 0x60
#define ERR_EMMC_SEND_RW_CMD_RETRY_FAIL 0x61
#define ERR_EMMC_CMD3_FAIL          0x63    /* mmc cmd3 fail present initial process fail */
#define ERR_EMMC_CMD7_FAIL          0x64    /* mmc cmd4 fail present initial process fail */
#define EMMC_MAX_CMD_SEND_RETRY_CNT 20
#define EMMC_MAX_STOP_CMD_RETRY_CNT 10
#define ERR_EMMC_SRAM_DMA_TIME      0x51
static int bErrorRetry_1=0, bErrorRetry_2=0;
static int g_Indicator_RW=0;   //R : 0 , W : 1
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
e_device_type emmc_card;
/**************************************************************************************
 * phoenix cr driver
 **************************************************************************************/
int mmccr_send_status(UINT8* state)
{
    UINT32 rom_resp[4];
    int rom_err = 0;

    rom_err = mmccr_SendCmd(MMC_SEND_STATUS,
                                   emmc_card.rca,
                                   -1,
                                   SD_R1|CRC16_CAL_DIS,
                                   0,
                                   rom_resp);
    if(rom_err){
#ifdef CR_DEBUG
        prints("MMC_SEND_STATUS fail\n");
#endif
    }else{
        UINT8 cur_state = R1_CURRENT_STATE(rom_resp[0]);
        *state = cur_state;

#ifdef CR_DEBUG
            prints("cur_state=");
            prints(state_tlb[cur_state]);
            prints("\n");
#endif
    }

    return rom_err;
}
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
#ifdef FOR_ICE_LOAD
            prints("wait ");
            prints(state_tlb[state]);
            prints(" fail\n");
#endif
            break;
        }
        else{
            UINT8 cur_state = R1_CURRENT_STATE(rom_resp[0]);
#ifdef FOR_ICE_LOAD
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
	//mmcinfo("mmccr_set_div; switch to 0x%08x\n", set_div);
    tmp_div = cr_readb(SD_CONFIGURE1) & ~MASK_CLOCK_DIV;
    cr_writeb(tmp_div|set_div,SD_CONFIGURE1);

    if( show_msg )
    {
    	prints("SD_CONFIGURE1 0x18012180 = 0x");
        print_hex(cr_readb(SD_CONFIGURE1));
        prints("\n");
    }
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_bits_width( unsigned int set_bit )
{
    unsigned int tmp_bits;
	mmcinfo("mmccr_set_bits_width; switch to 0x%08x\n",set_bit);
    tmp_bits = cr_readb(SD_CONFIGURE1) & ~MASK_BUS_WIDTH;
    cr_writeb((UINT8)(tmp_bits|set_bit|0x10),SD_CONFIGURE1);
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_speed( unsigned int para )
{
    unsigned int tmp_para;
    tmp_para = cr_readb(SD_CONFIGURE1)& ~SPEED_MOD_HIGH;
    cr_writeb((UINT8)(tmp_para|para),SD_CONFIGURE1);
}

/*******************************************************
 *
 *******************************************************/
void mmccr_set_clk( unsigned int mmc_clk, unsigned int show_msg )
{
    unsigned int tmp_clk = cr_readb(SYS_CLKSEL) & ~EMMC_CLKSEL_MASK;
    //mmcinfo("mmccr_set_clk; switch to 0x%08x\n", mmc_clk);
    cr_writeb(tmp_clk|mmc_clk, SYS_CLKSEL);
    if( mmc_clk > CLOCK_SPEED_GAP ){
        mmccr_set_speed(SPEED_MOD_NORM);
    }
    else{
        mmccr_set_speed(SPEED_MOD_HIGH);
    }

    if( show_msg ) {
    	mmcinfo("0xb8000204=0x%08x\n", cr_readl(SYS_CLKSEL));
    }
}
/*******************************************************
 *
 *******************************************************/
void mmccr_read_rsp( void * rsp, int reg_count )
{
    UINT8 tmpcmd[5]={0};
    UINT32 *ptr = rsp;
    if ( reg_count == 6 ){
        sync();
        mdelay(10);
        tmpcmd[0] = cr_readb(SD_CMD0);
        tmpcmd[1] = cr_readb(SD_CMD1);
        tmpcmd[2] = cr_readb(SD_CMD2);
        tmpcmd[3] = cr_readb(SD_CMD3);
        tmpcmd[4] = cr_readb(SD_CMD4);
        tmpcmd[5] = cr_readb(SD_CMD5);
        //device is big-endian
        REG32(ptr) = (UINT32)((tmpcmd[3]<<24) |
                 (tmpcmd[2]<<16) |
                 (tmpcmd[1]<<8) |
                  tmpcmd[0]) ;
        REG32(ptr+1) = (UINT32)((tmpcmd[5]<<8) |
                                (tmpcmd[4]));
        
        #ifdef FOR_ICE_LOAD
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
        #endif
    }
    else if( reg_count == 17 ){
        #if 0
        rsp[0] = cr_readl(EXT_RSP_0) << 24 |
                 cr_readl(EXT_RSP_1) << 16 |
                 cr_readl(EXT_RSP_2) << 8 |
                 cr_readl(EXT_RSP_3);

        rsp[1] = cr_readl(EXT_RSP_4) << 24 |
                 cr_readl(EXT_RSP_5) << 16 |
                 cr_readl(EXT_RSP_6) << 8 |
                 cr_readl(EXT_RSP_7);

        rsp[2] = cr_readl(EXT_RSP_8) << 24 |
                 cr_readl(EXT_RSP_9) << 16 |
                 cr_readl(EXT_RSP_10) << 8 |
                 cr_readl(EXT_RSP_11);

        rsp[3] = cr_readl(EXT_RSP_12) << 24 |
                 cr_readl(EXT_RSP_13) << 16 |
                 cr_readl(EXT_RSP_14) << 8 |
                 0xff;
	    //128-bit rsp data
	    //mmcinfo("rsp[0]=0x%x\n",rsp[0]);
	    //mmcinfo("rsp[1]=0x%x\n",rsp[1]);
	    //mmcinfo("rsp[2]=0x%x\n",rsp[2]);
	    //mmcinfo("rsp[3]=0x%x\n",rsp[3]);
        #endif
        REG32(ptr+0) = REG32(sys_rsp17_addr+0x00);
        REG32(ptr+1) = REG32(sys_rsp17_addr+0x04);
        REG32(ptr+2) = REG32(sys_rsp17_addr+0x08);
        REG32(ptr+3) = REG32(sys_rsp17_addr+0x0c);
        REG32(ptr+4) = REG32(sys_rsp17_addr+0x10);
        REG32(ptr+5) = REG32(sys_rsp17_addr+0x14);
        REG32(ptr+6) = REG32(sys_rsp17_addr+0x18);
        REG32(ptr+7) = REG32(sys_rsp17_addr+0x1c);

        prints("rsp len 17B :[0] 0x");
        print_hex(REG32(ptr+0));
        prints(" [1] 0x");
        print_hex(REG32(ptr+1));
        prints(" [2] 0x");
        print_hex(REG32(ptr+2));
        prints(" [3] 0x");
        print_hex(REG32(ptr+3));
        prints(" [4] 0x");
        print_hex(REG32(ptr+4));
        prints(" [5] 0x");
        print_hex(REG32(ptr+5));
        prints(" [6] 0x");
        print_hex(REG32(ptr+6));
        prints(" [7] 0x");
        print_hex(REG32(ptr+7));
        prints("\n");
    }
}

UINT32 mmccr_read_sram_dma_data(UINT32 sram_buf, UINT32 block_count)
{
				UINT32 i=0,blk_no=0, fifo_tmp0=0, fifo_tmp1=0;
                INT32 time_cnt=0;
                UINT32 cpu_acc_reg=0, dma_reg=0;
                
                if(sram_buf){
                    #ifdef FOR_ICE_LOAD
                    prints("sram_buf addr: 0x");
                    print_hex(sram_buf);
                    prints("\n");
                    prints("Read data from SRAM FIFO : blk_cnt=0x");
                    print_hex(block_count);
                    prints("\n");
                    #endif
                    while (block_count--)
                    {
                        #ifdef FOR_ICE_LOAD
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
                            #ifdef FOR_ICE_LOAD
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
    #ifdef FOR_ICE_LOAD
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
    #ifdef FOR_ICE_LOAD
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
int mmccr_TriggerXferCmd( unsigned char xferCmdCode, unsigned int cpu_mode )
{
    volatile UINT8 sd_transfer_reg;
    volatile int loops, loops1=0;
    volatile int err=0, timeout_cnt=0;

    //mmcinfo("mmccr_TriggerCmd(0x%02x)\n", xferCmdCode);
    sync();
    CP15DSB;
    CP15ISB;

    cr_writeb((UINT8) (xferCmdCode|START_EN), SD_TRANSFER );

    sync();
    CP15DSB;
    CP15ISB;

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

    sync();
    CP15DSB;
    CP15ISB;

    //check1
    if (g_cmd[0] == 0x41)
    {
     loops = 10;     
     loops1 = 300; 
     while(loops ){
        while(loops1--)
        {

    sync();
    CP15DSB;
    CP15ISB;

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
        
    sync();
    CP15DSB;
    CP15ISB;
                prints("\nSD_CMD1 : 0x");
                print_hex(cr_readb(SD_CMD1));
                prints("\n");

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
	{
            prints("\ncard cmd 1 sent \n");
            return 0;
	}
        
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
            //sd_transfer_reg = cr_readb(SD_TRANSFER);
        	if ((cr_readb(SD_TRANSFER) & (END_STATE|IDLE_STATE))==(END_STATE|IDLE_STATE))
            {
        	    err = 0;
        		break;
        	}
        	if ((cr_readb(SD_TRANSFER) & (ERR_STATUS))==(ERR_STATUS))
            {
        	    err = CR_TRANSFER_TO;
        		break;
        	}
            udelay(500);
            loops--;
        }
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
    sync();
    CP15DSB;
    CP15ISB;
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
        //cpu_acc_reg = REG32(CR_CPU_ACC);
        cr_writel(0x3, CR_CPU_ACC);
        mdelay(50);
        sync();
        loops=20*500*2; //2sec to timeout
    sync();
    CP15DSB;
    CP15ISB;
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
    sync();
    CP15DSB;
    CP15ISB;

        #ifdef FOR_ICE_LOAD
        prints("\ncmd 2 poll cpu_acc/dma to 0x");
        print_hex(REG32(CR_CPU_ACC));
        prints(", 0x");
        print_hex(REG32(CR_DMA_CTL3));
        prints("\n");
        #endif
    }

    //check3
    if (cpu_mode == 1)
    {
      loops = 100*20*3;     
      err = CR_BUF_FULL_TO;
      #ifdef FOR_ICE_LOAD  
      prints("\ncr cpu mode - read\n");
      #endif
    sync();
    CP15DSB;
    CP15ISB;
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
unsigned int mmc_get_rsp_len( unsigned char rsp_para )
{
    //mmcinfo("mmc_get_rsp_len\n");

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

    //mmcinfo("get_rsp_type\n");

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

	if( rtkmmc_debug_msg ) {
	    mmcinfo("cmd_idx(10h)=%u arg(14h-20h)=0x%08x rsp_para2(0Ch)=0x%02x\n"
	            "     byte_count=0x%04x; block_count=0x%04x; phy addr=0x%08x\n",
	            cmd_idx, cmd_arg, rsp_para2, byte_count, block_count, phy_buf_addr);

		switch( xferCmdCode ) {
			case SD_AUTOREAD1:		mmcprintf("     XferCmdCode(08h)=0x%02x, SD_AUTOREAD1\n", xferCmdCode);	break;
			case SD_AUTOWRITE1:		mmcprintf("     XferCmdCode(08h)=0x%02x, SD_AUTOWRITE1\n", xferCmdCode);	break;
			case SD_AUTOREAD2:		mmcprintf("     XferCmdCode(08h)=0x%02x, SD_AUTOREAD2\n", xferCmdCode);	break;
			case SD_AUTOWRITE2:		mmcprintf("     XferCmdCode(08h)=0x%02x, SD_AUTOWRITE2\n", xferCmdCode);	break;
			case SD_NORMALREAD:		mmcprintf("     XferCmdCode(08h)=0x%02x, SD_NORMALREAD\n", xferCmdCode);	break;
			case SD_NORMALWRITE:	mmcprintf("     XferCmdCode(08h)=0x%02x, SD_NORMALWRITE\n", xferCmdCode);	break;
			default:				mmcprintf("     XferCmdCode(08h)=0x%02x, unknown\n", xferCmdCode);
		}
	}

        #ifdef FOR_ICE_LOAD
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
        #endif

    g_cmd[0] = (0x40|cmd_idx);
    g_cmd[1] = (cmd_arg>>24)&0xff;
    g_cmd[2] = (cmd_arg>>16)&0xff;
    g_cmd[3] = (cmd_arg>>8)&0xff;
    g_cmd[4] = cmd_arg&0xff;
    g_cmd[5] = 0x00;

    #ifdef FOR_ICE_LOAD
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
    #endif

    cr_writeb(g_cmd[0], SD_CMD0);
    cr_writeb(g_cmd[1],  SD_CMD1);
    cr_writeb(g_cmd[2],  SD_CMD2);
    cr_writeb(g_cmd[3],   SD_CMD3);
    cr_writeb(g_cmd[4],      SD_CMD4);
    cr_writeb(g_cmd[5],      SD_CMD5);

    cr_writeb(rsp_para1,       SD_CONFIGURE1);     //0x0C
    cr_writeb(rsp_para2,       SD_CONFIGURE2);     //0x0C
    cr_writeb(rsp_para3,       SD_CONFIGURE3);     //0x0C
    cr_writeb((byte_count)&0xff,     SD_BYTE_CNT_L);     //0x24
    cr_writeb((byte_count>>8)&0xff,  SD_BYTE_CNT_H);     //0x28
    cr_writeb((block_count)&0xff,    SD_BLOCK_CNT_L);    //0x2C
    cr_writeb((block_count>>8)&0xff, SD_BLOCK_CNT_H);    //0x30

    prints("xfer_flag : ");
    print_hex(xferCmdCode|START_EN);
    prints("\n");

   	if( cmd_info->xfer_flag & RTK_MMC_DATA_WRITE){
        prints("-----mmc data write-----\n");
        prints("DMA sa = 0x");
        print_hex(phy_buf_addr/8);
        prints("\nDMA len = 0x");
        print_hex(block_count);
        prints("\nDMA set = 0x");
        print_hex(DMA_XFER);
        prints("\n");

        cr_writel( 0, CR_CPU_ACC);
        cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        cr_writel( block_count, CR_DMA_CTL2);
        cr_writel( DMA_XFER, CR_DMA_CTL3);  
    }
    else{
        if( cmd_info->xfer_flag & RTK_MMC_SRAM_READ){
            prints("-----mmc data sram read (cpu mode)-----\n");
            prints("CR_CPU_ACC(0x18012080) = 0x");
            print_hex(CPU_MODE_EN);
            prints("\n");

	    if (cmd_idx == 0x12)
            	cpu_mode = 1;
            cr_writel( 0, CR_CPU_ACC);
            cr_writel( CPU_MODE_EN, CR_CPU_ACC);
            cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        }
        else
        {
            prints("-----mmc data ddr read-----\n");
            cr_writel( 0x00, CR_CPU_ACC);
            cr_writel( phy_buf_addr/8, CR_DMA_CTL1);
        }
        prints("DMA sa = 0x");
        print_hex(phy_buf_addr/8);
        prints("\nDMA len = 0x");
        print_hex(block_count);
        prints("\nDMA set = 0x");
        print_hex(DDR_WR|DMA_XFER);
        cr_writel( block_count, CR_DMA_CTL2);
        cr_writel( DDR_WR|DMA_XFER, CR_DMA_CTL3);  
        prints("\n");
    }

    ret_err = mmccr_TriggerXferCmd( xferCmdCode, cpu_mode );

    if ((cr_readb(SD_STATUS1) & 0x80) == 0x80)
    {
	prints("stream cmd crc7 error \n");
	ret_err = 0x10;
	return ret_err;
    }

    if( !ret_err ){
        if( cr_int_status_reg & RTKCR_INT_DECODE_ERROR )
        {
            mmcinfo("cr_int_status_reg=0x%x\n", cr_int_status_reg);
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
    }

err_out:
	if( ret_err ){
        #ifdef FOR_ICE_LOAD
        prints("ret_err=");
        print_hex(ret_err);
        prints("\n");
        #else
    	mmcinfo("ret_err=%d\n", ret_err);
        #endif
    }
    return ret_err;
}

void sample_ctl_switch(UINT32 bWrite)
{

                bErrorRetry_2 = !bErrorRetry_2;

                if (!bErrorRetry_2)
                {
                    prints("mode switch 1\n");
                    if (bWrite == 0)
		    {
                        cr_writeb( 0x8, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                        cr_writeb( 0x10, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                    	prints("write sample point to 0x8. reg=0x");
			print_hex(cr_readb(SD_SAMPLE_POINT_CTL));
			prints("\n");
		    }
                    else
		    {
                        cr_writeb( 0x10, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                        cr_writeb( 0x8, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                    	prints("write push point to 0x10. reg=0x");
			print_hex(cr_readb(SD_PUSH_POINT_CTL));
			prints("\n");
		    }
                }
                else
                {
                    prints("mode switch 0\n");

                    if (bWrite == 0)
		    {
                        cr_writeb( 0x0, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                        cr_writeb( 0x0, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                    	prints("write sample point to 0x0. reg=0x");
			print_hex(cr_readb(SD_SAMPLE_POINT_CTL));
			prints("\n");
		    }
                    else
		    {
                        cr_writeb( 0x0, SD_PUSH_POINT_CTL );     //output ahead SDCLK /4 
                        cr_writeb( 0x0, SD_SAMPLE_POINT_CTL );    //sample point = SDCLK / 4
                    	prints("write push point to 0x0. reg=0x");
			print_hex(cr_readb(SD_PUSH_POINT_CTL));
			prints("\n");
		    }
                }

                mdelay(5);

                REG8(CR_CARD_STOP) = 0x14;
                prints("write CARD_STOP to 0x14. reg=0x");
		print_hex(cr_readb(CR_CARD_STOP));
		prints("\n");

                mdelay(5);
}

/*******************************************************
 *
 *******************************************************/
int mmc_select_part( e_device_type * card, unsigned int part_idx )
{
	unsigned int new_part_idx;
	// check currents
	//mmc_read_ext_csd( card );

	// select target partition
	new_part_idx = card->ext_csd.part_cfg & ~0x7;
	mmc_update_ext_csd( 179, (new_part_idx|part_idx));

	// check currents again
	//mmc_read_ext_csd( card );

	// return status;
	return 0;
}

/*
 * [31:26] Set to 0
 * [25:24] Access
 * [23:16] Index
 * [15:8] Value
 * [7:3] Set to 0
 * [2:0] Cmd Set
 *
 */
int mmc_update_ext_csd( unsigned int offset, unsigned int value )
{
	int ret_err, counter;
	unsigned int argu;
	unsigned int rsp_buffer[4];
    argu = (MMC_SWITCH_MODE_WRITE_BYTE << 24)|
           (offset << 16)|
           (value << 8)|
           EXT_CSD_CMD_SET_NORMAL;

    ret_err = mmccr_SendCmd( MMC_SWITCH, argu, 0, SD_R1b|CRC16_CAL_DIS, 0, rsp_buffer );
    if( ret_err ) {
        #ifdef FOR_ICE_LOAD
    	prints("update ext csd fail\n");
        #else
        mmcinfo("update ext csd fail\n");
        #endif
        return ret_err;
    }

    /* To wait status change complete */
    ret_err = 0;
    counter = 100;
    do {
        udelay(10);
        counter--;
        ret_err = mmccr_SendCmd( MMC_SEND_STATUS, emmc_card.rca, 0x10, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer );
        if( ret_err ) {
            #ifdef FOR_ICE_LOAD
            prints("update ext csd fail(resd sts error)\n");
            #else
        	mmcprintf("update ext csd fail(resd sts error)\n");
            #endif
            return ret_err;
        }
        if( counter==0 ) {
        	ret_err = -19;
            #ifdef FOR_ICE_LOAD
            prints("update ext csd fail(read sts timeout)\n");
            #else
        	mmcprintf("update ext csd fail(read sts timeout)\n");
            #endif
            break;
        }
    }
    while((R1_CURRENT_STATE(rsp_buffer[0]) == STATE_PRG));

    #ifdef FOR_ICE_LOAD
    prints("update ext csd done\n");
    #endif

    return ret_err;
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

    #ifdef FOR_ICE_LOAD
    prints("mmc_read_ext_csd\n");
    #else
    mmcinfo("mmc_read_ext_csd\n");
    #endif

    cmd_info.cmd= &cmd;
    cmd.arg     = 0;
    cmd.opcode = MMC_SEND_EXT_CSD;

    rsp_type = mmc_get_rsp_type(&cmd);

    mmcinfo("ext_csd ptr 0x%p\n",ext_csd);

    cmd_info.rsp_para1    = 0x10;
    cmd_info.rsp_para2    = rsp_type;
    cmd_info.rsp_para3    = 0x3;
    cmd_info.rsp_len     = mmc_get_rsp_len(rsp_type);
    cmd_info.byte_count  = 0x200;
    cmd_info.block_count = 1;
    //cmd_info.data_buffer = ext_csd;
    cmd_info.data_buffer = sys_ext_csd_addr;
    cmd_info.xfer_flag   = RTK_MMC_DATA_READ; //dma the result to ddr, TODO : dma to sram at ddr un-initial time
    xferCmdCode          = SD_NORMALREAD;

    ret_err = mmccr_Stream_Cmd( xferCmdCode, &cmd_info);

    if(ret_err){
        #ifdef FOR_ICE_LOAD
        prints("unable to read EXT_CSD(ret_err=");
        print_hex(ret_err);
        prints("\n");
        #else
        mmcinfo("unable to read EXT_CSD(ret_err=%d)", ret_err);
        #endif
    }
    else{
    	mmc_show_ext_csd(card, sys_ext_csd_addr);

		card->ext_csd.boot_blk_size = (*(ptr_ext_csd+226)<<8);
        card->csd.csd_ver2 = *(ptr_ext_csd+194);
        card->ext_csd.rev = *(ptr_ext_csd+192);
        card->ext_csd.part_cfg = *(ptr_ext_csd+179);
        card->ext_csd.boot_cfg = *(ptr_ext_csd+178);
        card->ext_csd.boot_wp_sts = *(ptr_ext_csd+174);
        card->ext_csd.boot_wp = *(ptr_ext_csd+173);
		card->curr_part_indx = card->ext_csd.part_cfg & 0x07;

        #ifdef FOR_ICE_LOAD
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
		mmcinfo("emmc:BOOT PART MULTI = 0x%02x, BP_BLKS=0x%08x\n", *(ptr_ext_csd+226), *(ptr_ext_csd+226)<<8);
		mmcinfo("emmc:BOOT PART CFG = 0x%02x(%d)\n", card->ext_csd.part_cfg, card->curr_part_indx);
        #endif

		if (card->ext_csd.rev > 6) {
            #ifdef FOR_ICE_LOAD
            prints("unrecognized EXT_CSD structure version ");
            print_hex(card->ext_csd.rev);
            prints(", please update fw\n", card->ext_csd.rev);
            #else
            mmcinfo("unrecognized EXT_CSD structure version %d, please update fw\n", card->ext_csd.rev);
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
                #ifdef FOR_ICE_LOAD
                prints("card is mmc v4 but does not support any high-speed modes.\n");
                #else
	            mmcinfo("card is mmc v4 but doesn't " "support any high-speed modes.\n");
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
int mmc_send_stop( e_device_type * card )
{
    unsigned int rsp_buffer[4];

    //mmcinfo("mmc_send_stop\n");

    return mmccr_SendCmd(MMC_STOP_TRANSMISSION, card->rca, -1, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
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
    int card_state;
    int err = -1;
    int send_stop_cmd = 0;
    unsigned int rsp_type;

    cmd_info.cmd = &cmd;
    cmd.arg      = address;

    if( xfer_flag & RTK_MMC_DATA_WRITE ){
        xferCmdCode = SD_AUTOWRITE2; // cmd + data
        cmd.opcode = 24;
	g_Indicator_RW = 1;
    }else{
        xferCmdCode = SD_AUTOREAD2; // cmd + data
        cmd.opcode = 17;
	g_Indicator_RW = 0;
    }

    /* multi sector accress opcode */
    if( blk_cnt > 1 ){
        xferCmdCode-=1;
	cmd.opcode++; // 25 or 18 ( multi_block_xxxx )
      }

    rsp_type = mmc_get_rsp_type(&cmd);

    cmd_info.rsp_para1    = 0x0;
    cmd_info.rsp_para2    = rsp_type;
    cmd_info.rsp_para3    = 0x03;
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
int mmc_state_is_transfer_and_ready( e_device_type * card )
{

    unsigned int rsp_buffer[4];
    unsigned int  curr_state;
    int ret_err = 0;
    unsigned int retry_cnt;

	//mmcinfo("mmc_state_is_transfer_and_ready()\n");

	retry_cnt = 0;
	while( retry_cnt++ < 2 ) {
		ret_err = mmccr_SendCmd(MMC_SEND_STATUS, card->rca, -1, SD_R1|CRC16_CAL_DIS, 0, rsp_buffer);
	    if( !ret_err ) {
	    	if( retry_cnt == 2 ) {
		        curr_state = R1_CURRENT_STATE(rsp_buffer[0]);
		        //mmcinfo("curr_state=%d\n", curr_state);
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
int mmccr_SendCmd( unsigned int cmd_idx,
                   unsigned int cmd_arg,
                   unsigned int rsp_para1,
                   unsigned int rsp_para2,
                   unsigned int rsp_para3,
                   void * rsp_buffer )
{
    unsigned int rsp_len;
    int ret_err;
    UINT32 sa=sys_rsp17_addr/8;
    UINT32 byte_count = 0x200, block_count = 1;

RET_CMD:
	rsp_len = mmc_get_rsp_len(rsp_para2);

    if( rtkmmc_debug_msg ) {
        #ifdef FOR_ICE_LOAD
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
		mmcinfo("cmd_idx(10h)=%u arg(14h-20h)=0x%08x rsp_para(0Ch)=0x%02x\n", cmd_idx, cmd_arg, rsp_para2);
        #endif
	}

    if (rsp_para1 != -1)
        cr_writeb(rsp_para1,     SD_CONFIGURE1);
    cr_writeb(rsp_para2,     SD_CONFIGURE2);
    if (rsp_para3 != 0)
        cr_writeb((UINT8)rsp_para3,     SD_CONFIGURE3);

    g_cmd[0] = (0x40|cmd_idx);
    g_cmd[1] = (cmd_arg>>24)&0xff;
    g_cmd[2] = (cmd_arg>>16)&0xff;
    g_cmd[3] = (cmd_arg>>8)&0xff;
    g_cmd[4] = cmd_arg&0xff;
    g_cmd[5] = 0x00;

    #ifdef FOR_ICE_LOAD
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
    #endif

    cr_writeb(g_cmd[0], SD_CMD0);
    cr_writeb(g_cmd[1],  SD_CMD1);
    cr_writeb(g_cmd[2],  SD_CMD2);
    cr_writeb(g_cmd[3],   SD_CMD3);
    cr_writeb(g_cmd[4],      SD_CMD4);
    cr_writeb(g_cmd[5],      SD_CMD5);

    if (RESP_TYPE_17B & rsp_para2)
    {        
    #ifdef FOR_ICE_LOAD
        prints("-----rsp 17B-----");
        prints(" DMA_sa=0x");
        print_hex(sa);
        prints(" DMA_len=0x");
        print_val(1, 2);
        prints(" DMA_setting=0x");
        print_hex(RSP17_SEL|DDR_WR|DMA_XFER);
    #endif
        cr_writeb(byte_count,       SD_BYTE_CNT_L);     //0x24
        cr_writeb(byte_count>>8,    SD_BYTE_CNT_H);     //0x28
        cr_writeb(block_count,      SD_BLOCK_CNT_L);    //0x2C
        cr_writeb(block_count>>8,   SD_BLOCK_CNT_H);    //0x30
        cr_writel( CPU_MODE_EN, CR_CPU_ACC); //enable cpu mode
        cr_writel(sa, CR_DMA_CTL1);   //espeical for R2
        cr_writel(1, CR_DMA_CTL2);   //espeical for R2
        cr_writel((RSP17_SEL|DDR_WR|DMA_XFER)&0x3f, CR_DMA_CTL3);   //espeical for R2
    }    
    #ifdef FOR_ICE_LOAD    
    else if (RESP_TYPE_6B & rsp_para2)
    {        
        prints("-----rsp 6B-----");
        cr_writel( 0x00, CR_CPU_ACC);
    }
    #endif

    ret_err = mmccr_TriggerXferCmd( SD_SENDCMDGETRSP, 0 );


    if( !ret_err ){
        mmccr_read_rsp(rsp_buffer, rsp_len);
    }
    else
    {
#ifdef FOR_ICE_LOAD
        prints("case I : transfer cmd fail - 0x");
        print_hex(ret_err);
        prints("\n");
#endif
    }
    
    return ret_err;
}

/*******************************************************
 *
 *******************************************************/
int mmc_decode_csd( e_device_type * card )
{
    struct rtk_mmc_csd * csd = &card->csd;
    unsigned int e, m;
    unsigned int * resp = card->raw_csd;
    int err = 0;

    #ifdef FOR_ICE_LOAD
    prints("mmc_decode_csd\n");
    #else
    mmcinfo("mmc_decode_csd\n");
    #endif

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

    #ifdef FOR_ICE_LOAD
    prints("C_SIZE      :");
    print_hex(m);
    prints("\n");
    prints("C_SIZE_MULT :");
    print_hex(e);
    prints("\n");
    prints("Block Num   :");
    print_hex(csd->capacity);
    prints("\n");
    prints("Block Len   :");
    print_hex(1<<csd->read_blkbits);
    prints("\n");
    prints("Total Bytes :");
    print_hex(csd->capacity*(1<<csd->read_blkbits));
    prints("\n");
    #else
    mmcinfo("C_SIZE      :%u\n",m);
    mmcinfo("C_SIZE_MULT :%u\n",e);
    mmcinfo("Block Num   :%u\n",csd->capacity);
    mmcinfo("Block Len   :%u\n" ,1<<csd->read_blkbits);
    mmcinfo("Total Bytes :%u\n",csd->capacity*(1<<csd->read_blkbits));
    #endif
err_out:
    return err;
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_ext_csd( e_device_type * card, unsigned char * pext_csd )
{
	int i,j,k;
	unsigned int sec_cnt;
	unsigned int boot_size_mult;
#ifdef FOR_ICE_LOAD
	prints("emmc:EXT CSD\n");
	k = 0;
	for( i = 0; i < 32; i++ ) {
		prints("    : ");
        print_val(i<<4, 3);
		for( j = 0; j < 16; j++ ) {
			prints(" ");
            print_val(pext_csd[k++], 2);
		}
		prints("\n");
	}
	prints("    :k=");
    print_val(k,2);
    prints("\n");
#endif
	boot_size_mult = pext_csd[226];
#ifdef FOR_ICE_LOAD
	prints("emmc:BOOT PART ");
    print_val((boot_size_mult<<7),4);
    prints(" Kbytes(0x");
    print_val(boot_size_mult,4);
    prints(")\n");
#endif
	sec_cnt = pext_csd[215];
	sec_cnt = (sec_cnt<<8) | pext_csd[214];
	sec_cnt = (sec_cnt<<8) | pext_csd[213];
	sec_cnt = (sec_cnt<<8) | pext_csd[212];
#ifdef FOR_ICE_LOAD
	prints("emmc:SEC_COUNT ");
    print_val(sec_cnt, 4);
	prints(" emmc:reserve227 ");
    print_val(pext_csd[227], 2);
	prints(" emmc:reserve240 ");
    print_val(pext_csd[240], 2);
	prints(" emmc:reserve254 ");
    print_val(pext_csd[254], 2);
	prints(" emmc:reserve256 ");
    print_val(pext_csd[256], 2);
	prints(" emmc:reserve493 ");
    print_val(pext_csd[493], 2);
	prints(" emmc:reserve505 ");
    print_val(pext_csd[505], 2);
    prints("\n");
#endif
}

/*******************************************************
 *
 *******************************************************/
int mmc_show_csd( e_device_type * card )
{
	int i;
	unsigned char csd[16];
	for( i = 0; i < 4; i++ ) {
		csd[(i<<2)]   = ( card->raw_csd[i]>>24 ) & 0xFF;
		csd[(i<<2)+1] = ( card->raw_csd[i]>>16 ) & 0xFF;
		csd[(i<<2)+2] = ( card->raw_csd[i]>>8  ) & 0xFF;
		csd[(i<<2)+3] = ( card->raw_csd[i]     ) & 0xFF;
	}
#ifdef EMMC_SHOW_CSD
    #ifdef FOR_ICE_LOAD
    prints("emmc:CSD(hex) ");
    #else
	mmcprintf("emmc:CSD(hex)");
    #endif
	for( i = 0; i < 16; i++ ) {
        #ifdef FOR_ICE_LOAD
        print_hex(csd[i]);
        #else
		mmcprintf(" %02x", csd[i]);
        #endif
	}
    #ifdef FOR_ICE_LOAD
    prints("\n");
    #else
	mmcprintf("\n");
    #endif
#endif
	mmc_decode_csd(card);
}

/*******************************************************
 *
 *******************************************************/
bool is_cr_power_up(void * ocr)
{    
    struct rtk_mmc_ocr_reg *ocr_ptr;
    struct rtk_mmc_ocr *ptr = (struct rtk_mmc_ocr *) ocr;
    ocr_ptr = (struct rtk_mmc_ocr_reg *)&ptr->reg;

    if ((ptr->check1 != 0x3f) || (ptr->check2 != 0x7f))
        return FALSE;

    return ocr_ptr->power_up;
}

int mmc_show_ocr( void * ocr )
{
    struct rtk_mmc_ocr_reg *ocr_ptr;
    struct rtk_mmc_ocr *ptr = (struct rtk_mmc_ocr *) ocr;
    ocr_ptr = (struct rtk_mmc_ocr_reg *)&ptr->reg;

#ifdef FOR_ICE_LOAD
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
#endif
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
    #ifdef FOR_ICE_LOAD
    prints("emmc:CID");
    #else
	mmcprintf("emmc:CID");
    #endif
	for( i = 0; i < 16; i++ ) {
        
        #ifdef FOR_ICE_LOAD
        print_hex(cid[i]);
        #else
		mmcprintf(" %02x", cid[i]);
        #endif
	}
    #ifdef FOR_ICE_LOAD
    prints("\n");
    #else
	mmcprintf("\n");
    #endif
#endif
    #ifdef FOR_ICE_LOAD
    prints("CID     0x");
    print_hex(cid[0]);
    prints("\n");
    #else
	mmcinfo("CID    0x%02x\n", cid[0]);
    #endif
	switch( (cid[1] & 0x3) ) {
		case 0:
            #ifdef FOR_ICE_LOAD
            prints("CBX    Card\n");
            #else
			mmcinfo("CBX    Card\n");
            #endif
            break;
		case 1:
            #ifdef FOR_ICE_LOAD
            prints("CBX    BGA\n");	
            #else
			mmcinfo("CBX    BGA\n");		
            #endif
            break;
		case 2:
            #ifdef FOR_ICE_LOAD
            prints("CBX    POP\n");
            #else
			mmcinfo("CBX    POP\n");		
            #endif
            break;
		case 3:
            #ifdef FOR_ICE_LOAD
            prints("CBX    Unknown\n");
            #else
			mmcinfo("CBX    Unknown\n");	
            #endif
            break;
	}
    #ifdef FOR_ICE_LOAD
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
	mmcinfo("OID    0x%02x\n", cid[2]);
	mmcinfo("PNM    %c%c%c%c%c%c\n", cid[3], cid[4], cid[5], cid[6], cid[7], cid[8]);
	mmcinfo("PRV    %d.%d\n", (cid[9]>>4)&0xf, cid[9]&0xf);
    #endif
	sn = cid[13];
	sn = (sn<<8) | cid[12];
	sn = (sn<<8) | cid[11];
	sn = (sn<<8) | cid[10];
    #ifdef FOR_ICE_LOAD
    prints("PSN    ");
    print_hex(sn);
    prints("\n");
    #else
	mmcinfo("PSN    %u(0x%08x)\n", sn, sn);
    #endif
	if( cid[9] ) {
        #ifdef FOR_ICE_LOAD
		prints("MDT    ");
        print_hex((cid[9]>>4)&0xf);
        print_hex((cid[14]&0xf)+1997);
        prints("\n");
        #else
		mmcinfo("MDT    %02d/%d)", (cid[9]>>4)&0xf, (cid[14]&0xf)+1997);
        #endif
	}
	else {
        #ifdef FOR_ICE_LOAD
        prints("MDT    --/----\n");
        #else
		mmcinfo("MDT    --/----\n", (cid[9]>>4)&0xf, (cid[14]&0xf)+1997);
        #endif
	}
}

int phoenix_cr_init()
{
    #define MAX_CMD_RETRY   10
    unsigned int tmp;
    unsigned int rsp_buffer[4];
    int ret_err=0,i;
    unsigned int counter=0;
    unsigned int arg=0;
    unsigned int cmd_retry_cnt=0;
  
    //1. module / clk select
    #ifdef FPGA
    cr_writel( 0x200000, DUMMY_SYS );
    #endif
    cr_writeb( 0x2, CARD_SELECT );            //select SD

    udelay(100000);

    mmccr_set_div(CLOCK_DIV_256,0);

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
		//1.8v
    		ret_err = mmccr_SendCmd(MMC_SEND_OP_COND, EMMC_VDD_1_8|MMC_SECTOR_ADDR, SD1_R0, SD_R3, 0, (void*)&emmc_card.ocr);
	else	//3.3v
    		ret_err = mmccr_SendCmd(MMC_SEND_OP_COND, (EMMC_VDD_33_34|EMMC_VDD_32_33|EMMC_VDD_31_32|EMMC_VDD_30_31)|MMC_SECTOR_ADDR, SD1_R0, SD_R3, 0, (void*)&emmc_card.ocr);
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
        #ifdef FOR_ICE_LOAD
        prints("cmd10 error\n");
        #else
        mmcinfo("cmd10 error\n");
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
        #ifdef FOR_ICE_LOAD
        prints("cmd7 error\n");
        #else
        mmcinfo("cmd7 error\n");
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
    #ifdef FOR_ICE_LOAD
    prints("cmd8\n");
    #else
    mmcinfo("cmd8\n");
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
        #ifdef FOR_ICE_LOAD
        prints("change to 8bits....\n");
        #else
		mmcinfo("change to 8bits....\n");
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
            #ifdef FOR_ICE_LOAD
            prints("cmd6 fail, ret_err=");
            print_hex(ret_err);
            prints("\n");
            #else
        	mmcinfo("cmd6 fail, ret_err=%d\n", ret_err);
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
                #ifdef FOR_ICE_LOAD
                prints("cmd13 fail, ret_err=");
                print_hex(ret_err);
                prints("\n");
                #else
            	mmcinfo("cmd13 fail, ret_err=%d\n", ret_err);
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
            #ifdef FOR_ICE_LOAD
            prints("cmd6 response error\n");
            #else
            mmcinfo("cmd6 response error\n");
            #endif
            ret_err = -1;
            goto err_out;
        }
        else{
            mmccr_set_bits_width(BUS_WIDTH_8);
        }
    }

    prints("emmc: set the block len to 512B\n");

    prints("emmc: init finish\n");

    return ret_err;
err_out:
    prints("emmc: init error \n");
    return ret_err;
}

int rtk_eMMC_init( void )
{
    unsigned int tmp;
	int ret_err;
	int retry_counter;

	ret_err = -1;
	retry_counter = 3;
	rtkmmc_debug_msg = 1;
	rtkmmc_off_error_msg_in_init_flow = 1;
    sys_rsp17_addr = 0x00010000;   //rsp dma addr : 17B
    sys_ext_csd_addr = 0x00180000; //ext csd dma addr : 512B
    ptr_ext_csd = (UINT8*)sys_ext_csd_addr;
    emmc_card.rca = 1<<16;
    emmc_card.sector_addressing = 1;          

    if (GET_CHIP_REV() >= PHOENIX_REV_B)
    {
	printf("rtk_emmc : detect chip rev. >= B\n");
	REG32(SYS_PLL_EMMC1) = 0xe0003;     //LDO1.8V
	REG32(CR_PAD_CTL) = 0;              //PAD to 1.8V
	mdelay(300);
    }
    #ifdef FOR_ICE_LOAD
    prints("\nemmc : PLL_EMMC1 = 0x");
    print_hex((unsigned int)REG32(SYS_PLL_EMMC1));
    #endif
    // work around for 8-byte alignment
    tmp = ((unsigned int)dummy_buffer)& 0xfffffff8;
    tmp += 0x00000008;
    dummy_512B = (unsigned char *)tmp; // 16-byte aligment

    #ifdef FOR_ICE_LOAD
    prints("\nemmc : dummy_buffer = 0x");
    print_hex((unsigned int)dummy_buffer);
    prints(", dummy_512B = 0x");
    print_hex((unsigned int)dummy_512B);
    prints("\n");
    #else
    UPRINTF("\nemmc:%s(%d) %s %s\n", __FUNCTION__, reset_only, __DATE__, __TIME__);
    mmcprintf("\nemmc:dummy_buffer=0x%08x, dummy_512B=0x%08x\n", (unsigned int)dummy_buffer, (unsigned int)dummy_512B);
    #endif
    
	while( retry_counter-- ) {
		ret_err = phoenix_cr_init();
		if( ret_err ) {
            #ifdef FOR_ICE_LOAD
            prints("emmc: init fail(");
            print_hex(ret_err);
            prints(")\n");
            #else
			UPRINTF("\nemmc: init fail(%d)\n", ret_err);
            #endif
		}
		else {
			return ret_err;
		}
	}
	return ret_err;
}

int rtk_eMMC_write( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer, unsigned int auto_sel_part )
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

    //UPRINTF("\nemmc:%s blk_addr=0x%08x, data_size=0x%08x, buffer=0x%08x, addressing=%d\n", __FUNCTION__, blk_addr, data_size, buffer, card->sector_addressing);

    total_blk_cont = data_size>>9;
    if(data_size & 0x1ff) {
        total_blk_cont+=1;
    }

	curr_blk_addr = blk_addr;
	if( card->sector_addressing ) {
		address = curr_blk_addr;
	}
	else {
		address = curr_blk_addr << 9;
	}

#ifdef EMMC_DEFAULT_BOOT_PART_SEL
	while( total_blk_cont ) {
		if( total_blk_cont > EMMC_MAX_XFER_BLKCNT ) {
			curr_xfer_blk_cont = EMMC_MAX_XFER_BLKCNT;
		}
		else {
			curr_xfer_blk_cont = total_blk_cont;
		}

		if( auto_sel_part ) {
			if( curr_blk_addr >= card->ext_csd.boot_blk_size ) {
				// select back to part 0
				target_part_idx = 0;
			}
			else {
				if( (curr_blk_addr+curr_xfer_blk_cont) > card->ext_csd.boot_blk_size ) {
					curr_xfer_blk_cont = card->ext_csd.boot_blk_size - curr_blk_addr;
				}
				target_part_idx = EMMC_DEFAULT_BOOT_PART_SEL;
			}

			if( target_part_idx != card->curr_part_indx ) {
                #ifdef FOR_ICE_LOAD
				prints("change to part 0x");
                print_hex(target_part_idx);
                prints("\n");
                #else
                mmcprintf("change to part %d\n", target_part_idx);
                #endif
				mmc_select_part( card, target_part_idx );
				card->curr_part_indx = target_part_idx;
			}
		}

		U_FLUSH_CACHE((unsigned long)buffer, curr_xfer_blk_cont << 9);
		ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_DATA_WRITE, buffer );

		if( ret_err ) {
			return 0;
		}

        /* To wait status change complete */
        ret_err = mmccr_wait_status(STATE_TRAN);

		total_blk_cont -= curr_xfer_blk_cont;
		buffer += (curr_xfer_blk_cont<<(9-2));
		if( card->sector_addressing ) {
			address += curr_xfer_blk_cont;
		}
		else {
			address += (curr_xfer_blk_cont<<9);
		}
		curr_blk_addr += curr_xfer_blk_cont;
	}

	total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }
#else
RETRY_RD_CMD:
    U_FLUSH_CACHE((unsigned long)buffer, total_blk_cont << 9);
    ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_DATA_WRITE, buffer );  //tbd : not verify

    if (ret_err)
    {
        if (retry_cnt2%3 == 0)
            sample_ctl_switch(g_Indicator_RW);
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
	    prints("retry - case 1 : sample_point(0x");
	    print_hex(cr_readb(SD_SAMPLE_POINT_CTL));
	    prints("),push_point(0x");
	    print_hex(cr_readb(SD_PUSH_POINT_CTL));
	    prints(")\n");
            if (retry_cnt%5 == 0)
                sample_ctl_switch(g_Indicator_RW);
            if (retry_cnt++ > EMMC_MAX_CMD_SEND_RETRY_CNT)
                return ERR_EMMC_SEND_STATUS_RETRY_FAIL;
            mdelay(1);
            continue;
        }
        //2. get state
        if (ret_state != STATE_TRAN)
        {
	    prints("retry - case 2 : sample_point(0x");
	    print_hex(cr_readb(SD_SAMPLE_POINT_CTL));
	    prints("),push_point(0x");
	    print_hex(cr_readb(SD_PUSH_POINT_CTL));
	    prints(")\n");
            bRetry = 1;
            if (retry_cnt%2 == 0)
                sample_ctl_switch(g_Indicator_RW);
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
	        prints("retry - case 3\n");
                return !ret_err ?  total_blk_cont : 0;
            }
            else
            {
	        prints("retry - case 4\n");
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

int rtk_eMMC_read( unsigned int blk_addr, unsigned int data_size, unsigned int * buffer, unsigned int auto_sel_part )
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

    total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }

	if( card->sector_addressing ) {
		address = blk_addr;
	}
	else {
		address = blk_addr << 9;
	}
#ifdef EMMC_DEFAULT_BOOT_PART_SEL
	while( total_blk_cont ) {
		if( total_blk_cont > EMMC_MAX_XFER_BLKCNT ) {
			curr_xfer_blk_cont = EMMC_MAX_XFER_BLKCNT;
		}
		else {
			curr_xfer_blk_cont = total_blk_cont;
		}

		if( auto_sel_part ) {
			if( curr_blk_addr >= card->ext_csd.boot_blk_size ) {
				// select back to part 0
				target_part_idx = 0;
			}
			else {
				if( (curr_blk_addr+curr_xfer_blk_cont) > card->ext_csd.boot_blk_size ) {
					curr_xfer_blk_cont = card->ext_csd.boot_blk_size - curr_blk_addr;
				}
				target_part_idx = EMMC_DEFAULT_BOOT_PART_SEL;
			}

			if( target_part_idx != card->curr_part_indx ) {
				mmcprintf("change to part %d\n", target_part_idx);
				mmc_select_part( card, target_part_idx );
				card->curr_part_indx = target_part_idx;
			}
		}

		U_FLUSH_CACHE((unsigned long)buffer, curr_xfer_blk_cont << 9);
        if (IS_SRAM_ADDR(buffer))
    		ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_SRAM_READ, buffer );
        else
    		ret_err = mmccr_Stream( address, curr_xfer_blk_cont, RTK_MMC_DATA_READ, buffer );

        /* To wait status change complete */
        ret_err = mmccr_wait_status(STATE_TRAN);

		if( ret_err ) {
			return 0;
		}
		total_blk_cont -= curr_xfer_blk_cont;
		buffer += (curr_xfer_blk_cont<<(9-2));
		if( card->sector_addressing ) {
			address += curr_xfer_blk_cont;
		}
		else {
			address += (curr_xfer_blk_cont<<9);
		}
		curr_blk_addr += curr_xfer_blk_cont;
	}

	total_blk_cont = data_size>>9;
    if( data_size & 0x1ff ) {
        total_blk_cont+=1;
    }

    /* To wait status change complete */
    ret_err = mmccr_wait_status(STATE_TRAN);

    return !ret_err ?  total_blk_cont : 0;
#else
RETRY_RD_CMD:
    U_FLUSH_CACHE((unsigned long)buffer, total_blk_cont << 9);
    if (IS_SRAM_ADDR(buffer))
    	ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_SRAM_READ, buffer );  //tbd : not verify
    else
    	ret_err = mmccr_Stream( address, total_blk_cont, RTK_MMC_DATA_READ, buffer );

    if (ret_err)
    {
        if (retry_cnt2%3 == 0)
            sample_ctl_switch(g_Indicator_RW);
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
                sample_ctl_switch(g_Indicator_RW);
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

int rtk_eMMC_select( unsigned int target_part_idx )
{
    int ret_val = 0;
    e_device_type * card = &emmc_card;

    //UPRINTF("Try to select part %d...\n", target_part_idx);

    if( target_part_idx != card->curr_part_indx ) {
        #ifdef FOR_ICE_LOAD
        prints("change to part 0x");
        print_hex(target_part_idx);
        prints("\n");
        #else
        mmcprintf("change to part %d\n", target_part_idx);
        #endif
        ret_val = mmc_select_part( card, target_part_idx );
        card->curr_part_indx = target_part_idx;
    }
    return ret_val;
}

#pragma GCC pop_options
