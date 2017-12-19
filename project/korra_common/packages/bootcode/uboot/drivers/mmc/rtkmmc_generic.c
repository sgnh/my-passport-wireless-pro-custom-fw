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

#include "rtkmmc_generic.h"
#include "rtkmmc.h"

#define __RTKMMC_GENERIC_C__

int mmc_had_been_initialized;
int mmc_ready_to_use;
static struct mmc mmc_dev[2];

extern unsigned int rtkmmc_debug_msg;
extern unsigned int rtkmmc_off_error_msg_in_init_flow;
extern unsigned int sys_ext_csd_addr;

#ifdef CONFIG_GENERIC_MMC

static int mmc_send_cmd(
			struct mmc * mmc,
			struct mmc_cmd * cmd,
			struct mmc_data * data )
{    
	int ret_err=0;
	unsigned int rsp_para1, rsp_para2, rsp_para3;
    struct rtk_cmd_info cmd_info;

	MMCPRINTF("\n*** %s %s %d, cmdidx=0x%02x(%d), resp_type=0x%08x -------\n", __FILE__, __FUNCTION__, __LINE__, cmd->cmdidx, cmd->cmdidx, cmd->resp_type);
	if( data ) {
		MMCPRINTF("*** %s %s %d, flags=0x%08x(%s), blks=%d, blksize=%d\n", __FILE__, __FUNCTION__, __LINE__, data->flags, (data->flags&MMC_DATA_READ) ? "R" : "W", data->blocks, data->blocksize);
	}
	rsp_para1 = 0;
    rsp_para2 = 0;
	rsp_para3 = 0;
    //correct emmc setting for rtd1195
    switch(cmd->cmdidx)
    {
        case MMC_GO_IDLE_STATE:
            rsp_para1 = SD1_R0;
            rsp_para2 = 0x50|SD_R0;
            rsp_para3 = 0;
            break;
        case MMC_SEND_OP_COND:
            rsp_para1 = SD1_R0;
            rsp_para2 = SD_R3;
            rsp_para3 = 0;
	    if (GET_CHIP_REV() >= PHOENIX_REV_B)
            	cmd->cmdarg = (MMC_SECTOR_ADDR|EMMC_VDD_1_8);
	    else
            	cmd->cmdarg = (MMC_SECTOR_ADDR|EMMC_VDD_33_34|EMMC_VDD_32_33|EMMC_VDD_31_32|EMMC_VDD_30_31);
            break;
        case MMC_ALL_SEND_CID:
            rsp_para1 = SD1_R0;
            rsp_para2 = SD_R2;
            rsp_para3 = SD2_R0;
            break;
        case MMC_SET_RELATIVE_ADDR:
            rsp_para1 = SD1_R0;
            rsp_para2 = SD_R1|CRC16_CAL_DIS;
            rsp_para3 = 0;
            cmd->cmdarg = 0x10000;
            break;
        case MMC_SEND_CSD:
        case MMC_SEND_CID:
            rsp_para1 = 0;
            rsp_para2 = SD_R2;
            rsp_para3 = 0x0;
            cmd->cmdarg = 0x10000;
            break;
        case MMC_SEND_EXT_CSD:
            rsp_para1 = -1;
            rsp_para2 = SD_R1;
            rsp_para3 = -1;
            break;
        case MMC_SELECT_CARD:
            rsp_para1 = 0;
            rsp_para2 = SD_R1b|CRC16_CAL_DIS;
            rsp_para3 = -1;
            cmd->cmdarg = 0x10000;
            break;
        case MMC_SWITCH:
            rsp_para1 = 0;
            rsp_para2 = SD_R1b|CRC16_CAL_DIS;
            rsp_para3 = -1;
            break;
        case MMC_SEND_STATUS:
            rsp_para1 = -1;
            rsp_para2 = SD_R1|CRC16_CAL_DIS;
            rsp_para3 = 0;
            cmd->cmdarg = 0x10000;
            break;
        case MMC_STOP_TRANSMISSION:
            rsp_para1 = -1;
            rsp_para2 = SD_R1|CRC16_CAL_DIS;
            rsp_para3 = -1;
            break;
        default:
            rsp_para1 = -1;     //don't update
            rsp_para3 = -1;     //don't update
            break;            
    }

	if( cmd->resp_type & MMC_RSP_PRESENT ) {
		if( cmd->resp_type & MMC_RSP_136 ) {
			rsp_para2 |= 0x02;  // RESP_TYPE_17B
		}
		else {
			rsp_para2 |= 0x01; // RESP_TYPE_6B
		}
		if( cmd->resp_type & MMC_RSP_CRC ) {

		}
		else {
			rsp_para2 |= ( /*(1<<7) |*/ (1<<2) ); // CRC7_CHK_DIS
		}
		if( cmd->resp_type & MMC_RSP_BUSY ) {
			rsp_para2 |= (1<<3); // WAIT_BUSY_EN
		}
	}

    if (data)
    {
        switch(cmd->cmdidx)
        {
            case MMC_READ_SINGLE_BLOCK :
            case MMC_READ_MULTIPLE_BLOCK :
                MMCPRINTF("*** %s %s %d - blocks = %08x, blocksize = %08x***\n", __FILE__, __FUNCTION__, __LINE__, data->blocks, data->blocksize);
                ret_err = rtk_eMMC_read(cmd->cmdarg/EMMC_BLK_SIZE, data->blocks*EMMC_BLK_SIZE, (unsigned int *)data->dest);
                break;
            case MMC_WRITE_BLOCK :
            case MMC_WRITE_MULTIPLE_BLOCK :
                MMCPRINTF("*** %s %s %d - blocks = %08x, blocksize = %08x***\n", __FILE__, __FUNCTION__, __LINE__, data->blocks, data->blocksize);
                ret_err = rtk_eMMC_write(cmd->cmdarg/mmc->write_bl_len, data->blocks*EMMC_BLK_SIZE, (unsigned int *)data->dest);
                break;
            default:
                MMCPRINTF("*** %s %s %d ***\n", __FILE__, __FUNCTION__, __LINE__);
                cmd_info.cmd= &cmd;
                cmd->cmdarg = 0;
                cmd_info.cmd->arg=0;
                cmd_info.cmd->opcode = cmd->cmdidx;
                cmd_info.rsp_para1    = rsp_para1;
                cmd_info.rsp_para2    = rsp_para2;
                cmd_info.rsp_para3    = rsp_para3;
                cmd_info.rsp_len     = mmc_get_rsp_len(rsp_para2);
                cmd_info.byte_count  = 0x200;
                cmd_info.block_count = 1;
                cmd_info.data_buffer = sys_ext_csd_addr;
                cmd_info.xfer_flag   = RTK_MMC_DATA_READ; //dma the result to ddr
                ret_err = mmccr_Stream_Cmd( SD_NORMALREAD, &cmd_info);
                memcpy(data->dest, sys_ext_csd_addr, 512);
                flush_cache(data->dest, 512);
                break;
        }
	}
    else
    	ret_err = mmccr_SendCmd( cmd->cmdidx, cmd->cmdarg, rsp_para1, rsp_para2, rsp_para3, cmd->response );

    

	// work around, data xfer error if clock is too slow
	if( cmd->cmdidx == MMC_SELECT_CARD ) {
		mmccr_set_div(EMMC_NORMAL_CLOCK_DIV, 0);
	}

	return ret_err;
}

static void mmc_set_ios(struct mmc * mmc)
{
	MMCPRINTF("*** %s %s %d, bw=%d, clk=%d\n", __FILE__, __FUNCTION__, __LINE__, mmc->bus_width, mmc->clock);

	// mmc->clock
	if( mmc->clock <= 400000 ) {
		mmccr_set_div(EMMC_INIT_CLOCK_DIV, 0);
	}
	else {
		mmccr_set_div(EMMC_NORMAL_CLOCK_DIV, 0);
		if( mmc->clock > 25000000 ) {
			UPRINTF("emmc: warning, clock(%d) not support\n", mmc->clock );
		}
	}
	if( mmc->bus_width == 1 ) {
		mmccr_set_bits_width(BUS_WIDTH_1);
		mmccr_set_speed(2); //low speed
	}
	else if( mmc->bus_width == 4 ) {
		mmccr_set_bits_width(BUS_WIDTH_4);
		mmccr_set_div(EMMC_NORMAL_CLOCK_DIV, 0); // hardware issue, read data timeout if clock is too slow
		mmccr_set_speed(1); //mid speed
	}
	else if( mmc->bus_width == 8 ) {
        mmccr_change_to_DDR50(); //DDR50
		mmccr_set_bits_width(BUS_WIDTH_8);
		mmccr_set_div(EMMC_NORMAL_CLOCK_DIV, 0); // hardware issue, read data timeout if clock is too slow
		mmccr_set_speed(0); //high speed
	}
	else {
		UPRINTF("*** %s %s %d, ERR bw=%d, clk=%d\n", __FILE__, __FUNCTION__, __LINE__, mmc->bus_width, mmc->clock);
	}
}

static int mmc_init_setup(struct mmc * mmc)
{
	MMCPRINTF("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	mmccr_init_setup();
	return 0;
}

int board_mmc_init(bd_t * bis)
{
	int ret_err;
	struct mmc * pmmc;

    MMCPRINTF("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    
	mmc_had_been_initialized = 0;
	mmc_ready_to_use = 0;

#if 0 // directly check eMMC device by customized init flow ( only for eMMC )
	rtkmmc_debug_msg = 1; // 1: enable debug message
	rtkmmc_off_error_msg_in_init_flow = 0; // 1: not show error message in initial stage
	ret_err = rtk_eMMC_init();
#else
	rtkmmc_debug_msg = 1; // 1: enable debug message
	rtkmmc_off_error_msg_in_init_flow = 1; // 1: not show error message in initial stage
	mmc_initial(1);
	ret_err = 0;
#endif
	if( !ret_err ) {
		pmmc = &mmc_dev[0];
		sprintf(pmmc->name, "RTD1195 eMMC");
		pmmc->send_cmd = mmc_send_cmd;
		pmmc->set_ios = mmc_set_ios;
		pmmc->init = mmc_init_setup;
		pmmc->getcd = NULL;
		pmmc->priv = NULL;
		pmmc->voltages = MMC_VDD_32_33 | MMC_VDD_33_34 | MMC_VDD_165_195;
#ifdef CONFIG_MMC_MODE_4BIT
		pmmc->host_caps = (MMC_MODE_4BIT | MMC_MODE_HS_52MHz | MMC_MODE_HS | MMC_MODE_HC);
#else
		pmmc->host_caps = (MMC_MODE_8BIT | MMC_MODE_HS_52MHz | MMC_MODE_HS | MMC_MODE_HC);
#endif

		pmmc->f_min = 400000;
		pmmc->f_max = 25000000;
		pmmc->b_max = 256; // max transfer block size
		mmc_register(pmmc);
	}

	return ret_err;
}

int bringup_mmc_driver( void )
{
	int ret_err;
	struct mmc * mmc;
	int total_device_num = -1;
	int curr_device;

    MMCPRINTF("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    
	total_device_num = get_mmc_num();
	if ( total_device_num < 0 ) {
		printf("no registed mmc device\n");
		return curr_device;
	}
	
	if( mmc_had_been_initialized ) {
		return 0; // alwasy use slot 0
	}

	curr_device = 0; // alwasy use slot 0
	rtkmmc_debug_msg = 1; // 1: enable debug message
	rtkmmc_off_error_msg_in_init_flow = 1; // 1: not show error message in initial stage
	mmc = find_mmc_device(curr_device);
	if( mmc ) {
                EXECUTE_CUSTOMIZE_FUNC(0);
		mmc_init(mmc);
                EXECUTE_CUSTOMIZE_FUNC(0);
		printf("Device: %s\n", mmc->name);
		printf("Manufacturer ID: %x\n", mmc->cid[0] >> 24);
		printf("OEM: %x\n", (mmc->cid[0] >> 8) & 0xffff);
		printf("Name: %c%c%c%c%c \n", (mmc->cid[0] & 0xff),
		                              (mmc->cid[1] >> 24) & 0xff,
		                              (mmc->cid[1] >> 16) & 0xff,
				                      (mmc->cid[1] >> 8) & 0xff,
				                      (mmc->cid[1] >> 0) & 0xff);
		printf("Tran Speed: %llx\n", (unsigned long long) mmc->tran_speed);
		printf("Rd Block Len: %d\n", mmc->read_bl_len);
		printf("%s version %d.%d\n", IS_SD(mmc) ? "SD" : "MMC", (mmc->version >> 4) & 0xf, mmc->version & 0xf);
		printf("High Capacity: %s\n", mmc->high_capacity ? "Yes" : "No");
		puts("Capacity: ");
		print_size(mmc->capacity, "\n");
		printf("Bus Width: %d-bit\n", mmc->bus_width);
		ret_err = curr_device;
		
		mmc_had_been_initialized = 1;
		if( mmc->capacity ) {
			mmc_ready_to_use = 1;
		}
		else {
			mmc_ready_to_use = 0;	
		}
	}
	else {
		printf("no mmc device at slot %x\n", curr_device);
		ret_err = -999;
	}
	rtkmmc_debug_msg = 0; // 0: off cmd message
	rtkmmc_off_error_msg_in_init_flow = 0; // 0: show error message after init done
	return ret_err;
}

#endif // end of CONFIG_GENERIC_MMC
