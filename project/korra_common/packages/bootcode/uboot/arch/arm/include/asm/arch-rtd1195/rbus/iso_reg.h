/**************************************************************
// Spec Version                  : 0.39
// Parser Version                : DVR_Parser_6.3
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/6/18 10:41:17
***************************************************************/


#ifndef _ISO_REG_H_INCLUDED_
#define _ISO_REG_H_INCLUDED_
#ifdef  _ISO_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     CEC_INT:1;
unsigned int     reserved_1:1;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     VFD_ARDSWDA_INT:1;
unsigned int     VFD_ARDSWA_INT:1;
unsigned int     VFD_ARDKPADDA_INT:1;
unsigned int     VFD_ARDKPADA_INT:1;
unsigned int     VFD_WDONE_INT:1;
unsigned int     RTC_ALARM_INT:1;
unsigned int     RTC_HSEC_INT:1;
unsigned int     reserved_2:1;
unsigned int     I2C6_INT:1;
unsigned int     TC4_INT:1;
unsigned int     I2C0_INT:1;
unsigned int     WDOG_NMI_INT:1;
unsigned int     reserved_3:1;
unsigned int     IRDA_INT:1;
unsigned int     reserved_4:2;
unsigned int     UR0_INT:1;
unsigned int     TC3_INT:1;
unsigned int     write_data:1;
}ISR;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     VFD_ARDSWDA_INT:1;
unsigned int     VFD_ARDSWA_INT:1;
unsigned int     VFD_ARDKPADDA_INT:1;
unsigned int     VFD_ARDKPADA_INT:1;
unsigned int     VFD_WDONE_INT:1;
unsigned int     RTC_ALARM_INT:1;
unsigned int     RTC_HSEC_INT:1;
unsigned int     reserved_1:2;
unsigned int     TC4_INT:1;
unsigned int     reserved_2:1;
unsigned int     WDOG_NMI_INT:1;
unsigned int     reserved_3:1;
unsigned int     IRDA_INT:1;
unsigned int     reserved_4:3;
unsigned int     TC3_INT:1;
unsigned int     write_data:1;
}ISO_UMSK_ISR;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     INT20_A:1;
unsigned int     INT19_A:1;
unsigned int     INT18_A:1;
unsigned int     INT17_A:1;
unsigned int     INT16_A:1;
unsigned int     INT15_A:1;
unsigned int     INT14_A:1;
unsigned int     INT13_A:1;
unsigned int     INT12_A:1;
unsigned int     INT11_A:1;
unsigned int     INT10_A:1;
unsigned int     INT9_A:1;
unsigned int     INT8_A:1;
unsigned int     INT7_A:1;
unsigned int     INT6_A:1;
unsigned int     INT5_A:1;
unsigned int     INT4_A:1;
unsigned int     INT3_A:1;
unsigned int     INT2_A:1;
unsigned int     INT1_A:1;
unsigned int     INT0_A:1;
unsigned int     write_data:1;
}UMSK_ISR_GPA;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     INT20_DA:1;
unsigned int     INT19_DA:1;
unsigned int     INT18_DA:1;
unsigned int     INT17_DA:1;
unsigned int     INT16_DA:1;
unsigned int     INT15_DA:1;
unsigned int     INT14_DA:1;
unsigned int     INT13_DA:1;
unsigned int     INT12_DA:1;
unsigned int     INT11_DA:1;
unsigned int     INT10_DA:1;
unsigned int     INT9_DA:1;
unsigned int     INT8_DA:1;
unsigned int     INT7_DA:1;
unsigned int     INT6_DA:1;
unsigned int     INT5_DA:1;
unsigned int     INT4_DA:1;
unsigned int     INT3_DA:1;
unsigned int     INT2_DA:1;
unsigned int     INT1_DA:1;
unsigned int     INT0_DA:1;
unsigned int     write_data:1;
}UMSK_ISR_GPDA;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     INT47:1;
unsigned int     INT46:1;
unsigned int     INT45:1;
unsigned int     INT44:1;
unsigned int     INT43:1;
unsigned int     INT42:1;
unsigned int     INT41:1;
unsigned int     INT40:1;
unsigned int     INT39:1;
unsigned int     INT38:1;
unsigned int     INT37:1;
unsigned int     INT36:1;
unsigned int     INT35:1;
unsigned int     INT34:1;
unsigned int     INT33:1;
unsigned int     INT32:1;
unsigned int     INT31:1;
unsigned int     INT30:1;
unsigned int     INT29:1;
unsigned int     INT28:1;
unsigned int     reserved_1:3;
unsigned int     write_data:1;
}UMSK_ISR_KPADAH;

typedef struct 
{
unsigned int     INT27:1;
unsigned int     INT26:1;
unsigned int     INT25:1;
unsigned int     INT24:1;
unsigned int     INT23:1;
unsigned int     INT22:1;
unsigned int     INT21:1;
unsigned int     INT20:1;
unsigned int     INT19:1;
unsigned int     INT18:1;
unsigned int     INT17:1;
unsigned int     INT16:1;
unsigned int     INT15:1;
unsigned int     INT14:1;
unsigned int     INT13:1;
unsigned int     INT12:1;
unsigned int     INT11:1;
unsigned int     INT10:1;
unsigned int     INT9:1;
unsigned int     INT8:1;
unsigned int     INT7:1;
unsigned int     INT6:1;
unsigned int     INT5:1;
unsigned int     INT4:1;
unsigned int     INT3:1;
unsigned int     INT2:1;
unsigned int     INT1:1;
unsigned int     INT0:1;
unsigned int     reserved_0:3;
unsigned int     write_data:1;
}UMSK_ISR_KPADAL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     INT47:1;
unsigned int     INT46:1;
unsigned int     INT45:1;
unsigned int     INT44:1;
unsigned int     INT43:1;
unsigned int     INT42:1;
unsigned int     INT41:1;
unsigned int     INT40:1;
unsigned int     INT39:1;
unsigned int     INT38:1;
unsigned int     INT37:1;
unsigned int     INT36:1;
unsigned int     INT35:1;
unsigned int     INT34:1;
unsigned int     INT33:1;
unsigned int     INT32:1;
unsigned int     INT31:1;
unsigned int     INT30:1;
unsigned int     INT29:1;
unsigned int     INT28:1;
unsigned int     reserved_1:3;
unsigned int     write_data:1;
}UMSK_ISR_KPADDAH;

typedef struct 
{
unsigned int     INT27:1;
unsigned int     INT26:1;
unsigned int     INT25:1;
unsigned int     INT24:1;
unsigned int     INT23:1;
unsigned int     INT22:1;
unsigned int     INT21:1;
unsigned int     INT20:1;
unsigned int     INT19:1;
unsigned int     INT18:1;
unsigned int     INT17:1;
unsigned int     INT16:1;
unsigned int     INT15:1;
unsigned int     INT14:1;
unsigned int     INT13:1;
unsigned int     INT12:1;
unsigned int     INT11:1;
unsigned int     INT10:1;
unsigned int     INT9:1;
unsigned int     INT8:1;
unsigned int     INT7:1;
unsigned int     INT6:1;
unsigned int     INT5:1;
unsigned int     INT4:1;
unsigned int     INT3:1;
unsigned int     INT2:1;
unsigned int     INT1:1;
unsigned int     INT0:1;
unsigned int     reserved_0:3;
unsigned int     write_data:1;
}UMSK_ISR_KPADDAL;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     DA_INT3:1;
unsigned int     DA_INT2:1;
unsigned int     DA_INT1:1;
unsigned int     DA_INT0:1;
unsigned int     A_INT3:1;
unsigned int     A_INT2:1;
unsigned int     A_INT1:1;
unsigned int     A_INT0:1;
unsigned int     reserved_1:3;
unsigned int     write_data:1;
}UMSK_ISR_SW;

typedef struct 
{
unsigned int     write_en5:1;
unsigned int     reserved_0:2;
unsigned int     standby_dbg_sel:5;
unsigned int     write_en4:1;
unsigned int     reserved_1:2;
unsigned int     standby_dbg_en:1;
unsigned int     write_en3:1;
unsigned int     reserved_2:3;
unsigned int     sel1:4;
unsigned int     write_en2:1;
unsigned int     reserved_3:3;
unsigned int     sel0:4;
unsigned int     write_en1:1;
unsigned int     reserved_4:2;
unsigned int     enable:1;
}ISO_DBG;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     testmode:1;
unsigned int     boot_sel:1;
unsigned int     bound_opt:13;
}CHIP_INFO1;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     pow_latch:19;
}ISO_CHIP_INFO2;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_en9:1;
unsigned int     iso_rst_wd_mask:1;
unsigned int     write_en8:1;
unsigned int     dc_phy_cke_pd:1;
unsigned int     write_en7:1;
unsigned int     iso_mis_clk_en:1;
unsigned int     write_en6:1;
unsigned int     iso_rbus_sel:1;
unsigned int     write_en5:1;
unsigned int     iso_rst_mask:1;
unsigned int     write_en4:1;
unsigned int     clk_osc_on_en:1;
unsigned int     write_en3:1;
unsigned int     crt_sw_rstn:1;
unsigned int     write_en2:1;
unsigned int     iso_clk_sel:1;
unsigned int     write_en1:1;
unsigned int     ejtag_en:1;
}CTRL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     hsec_int_en:1;
unsigned int     alarm_int_en:1;
}RTC;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     iso_ctrl_en1:1;
unsigned int     iso_ctrl_en0:1;
}CELL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     top_vdd_on:1;
unsigned int     scpu_vdd_on:1;
}POWER;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     CEC:1;
unsigned int     reserved_1:1;
unsigned int     GPIODA:1;
unsigned int     GPIOA:1;
unsigned int     VFD_ARDSWDA:1;
unsigned int     VFD_ARDSWA:1;
unsigned int     VFD_ARDKPADDA:1;
unsigned int     VFD_ARDKPADA:1;
unsigned int     VFD_WDONE:1;
unsigned int     RTC_ALARM:1;
unsigned int     RTC_HSEC:1;
unsigned int     reserved_2:1;
unsigned int     I2C6:1;
unsigned int     reserved_3:1;
unsigned int     I2C0:1;
unsigned int     reserved_4:2;
unsigned int     IRDA:1;
unsigned int     reserved_5:2;
unsigned int     UR0:1;
unsigned int     reserved_6:2;
}ISO_SCPU_INT_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DCP_CTRL1:1;
unsigned int     DCP_CTRL0:1;
}USB;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     CEC:1;
unsigned int     reserved_1:1;
unsigned int     GPIODA:1;
unsigned int     GPIOA:1;
unsigned int     VFD_ARDSWDA:1;
unsigned int     VFD_ARDSWA:1;
unsigned int     VFD_ARDKPADDA:1;
unsigned int     VFD_ARDKPADA:1;
unsigned int     VFD_WDONE:1;
unsigned int     RTC_ALARM:1;
unsigned int     RTC_HSEC:1;
unsigned int     reserved_2:1;
unsigned int     I2C6:1;
unsigned int     reserved_3:1;
unsigned int     I2C0:1;
unsigned int     reserved_4:2;
unsigned int     IRDA:1;
unsigned int     reserved_5:2;
unsigned int     UR0:1;
unsigned int     reserved_6:2;
}ACPU_INT_EN;

typedef struct 
{
unsigned int     acpu_boot_info:32;
}CPU_ST1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     acpu_boot_info_valid:1;
}CPU_ST1V;

typedef struct 
{
unsigned int     rvd31:1;
unsigned int     rvd30:1;
unsigned int     rvd29:1;
unsigned int     rvd28:1;
unsigned int     rvd27:1;
unsigned int     rvd26:1;
unsigned int     rvd25:1;
unsigned int     rvd24:1;
unsigned int     rvd23:1;
unsigned int     rvd22:1;
unsigned int     rvd21:1;
unsigned int     rvd20:1;
unsigned int     rvd19:1;
unsigned int     rvd18:1;
unsigned int     rvd17:1;
unsigned int     rvd16:1;
unsigned int     rvd15:1;
unsigned int     rvd14:1;
unsigned int     rvd13:1;
unsigned int     rvd12:1;
unsigned int     rvd11:1;
unsigned int     rvd10:1;
unsigned int     rvd9:1;
unsigned int     rvd8:1;
unsigned int     rvd7:1;
unsigned int     rvd6:1;
unsigned int     rvd5:1;
unsigned int     rvd4:1;
unsigned int     rvd3:1;
unsigned int     rvd2:1;
unsigned int     rvd1:1;
unsigned int     rvd0:1;
}ISO_DUMMY1;

typedef struct 
{
unsigned int     rvd31:1;
unsigned int     rvd30:1;
unsigned int     rvd29:1;
unsigned int     rvd28:1;
unsigned int     rvd27:1;
unsigned int     rvd26:1;
unsigned int     rvd25:1;
unsigned int     rvd24:1;
unsigned int     rvd23:1;
unsigned int     rvd22:1;
unsigned int     rvd21:1;
unsigned int     rvd20:1;
unsigned int     rvd19:1;
unsigned int     rvd18:1;
unsigned int     rvd17:1;
unsigned int     rvd16:1;
unsigned int     rvd15:1;
unsigned int     rvd14:1;
unsigned int     rvd13:1;
unsigned int     rvd12:1;
unsigned int     rvd11:1;
unsigned int     rvd10:1;
unsigned int     rvd9:1;
unsigned int     rvd8:1;
unsigned int     rvd7:1;
unsigned int     rvd6:1;
unsigned int     rvd5:1;
unsigned int     rvd4:1;
unsigned int     rvd3:1;
unsigned int     rvd2:1;
unsigned int     rvd1:1;
unsigned int     rvd0:1;
}DUMMY2;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     powercut_ana_d2a_isolate_b:1;
unsigned int     powercut_ana_a2d_isolate_b:1;
}POWERCUT_ETN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     etn_bpsgphy_mode:1;
unsigned int     etn_ocd_mode:1;
}ETN_TESTIO;

typedef struct 
{
unsigned int     DMY:32;
}RESERVED_USE_0;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     IR_TX:1;
unsigned int     IR_RAW:1;
}LPI;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     cnt_wait_pwr:16;
}WD;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     PLLETN_WDOUT:1;
}ISO_PLL_WDOUT;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     PLLETN_OEB:1;
unsigned int     PLLETN_RSTB:1;
unsigned int     PLLETN_O:4;
unsigned int     PLLETN_M:7;
unsigned int     PLLETN_LDO_POW:1;
unsigned int     PLLETN_POW:1;
unsigned int     PLLETN_LDO_SEL:2;
unsigned int     PLLETN_WDMODE:2;
unsigned int     PLLETN_N:2;
unsigned int     PLLETN_LF_RS:2;
unsigned int     PLLETN_LF_CP:2;
unsigned int     PLLETN_IP:3;
}PLL_ETN;

typedef struct 
{
unsigned int     DMY:32;
}RESERVED_USE_1;

typedef struct 
{
unsigned int     DMY:32;
}RESERVED_USE_2;

typedef struct 
{
unsigned int     DMY:32;
}RESERVED_USE_3;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C0_SDA_DEL;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     rstn_cbus:1;
unsigned int     rstn_i2c_6:1;
unsigned int     rstn_i2c_0:1;
unsigned int     rstn_gphy:1;
unsigned int     rstn_gmac:1;
unsigned int     rstn_ur0:1;
unsigned int     rstn_efuse:1;
unsigned int     rstn_cbusrx:1;
unsigned int     rstn_cbustx:1;
unsigned int     rstn_dp:1;
unsigned int     rstn_cec1:1;
unsigned int     rstn_cec0:1;
unsigned int     rstn_ir:1;
unsigned int     rstn_vfd:1;
}SOFT_RESET;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     clk_en_etn_sys:1;
unsigned int     clk_en_etn_250m:1;
unsigned int     clk_en_i2c6:1;
unsigned int     clk_en_i2c0:1;
unsigned int     clk_en_misc_ur0:1;
unsigned int     clk_en_misc_ir:1;
unsigned int     clk_en_cbus_osc:1;
unsigned int     clk_en_cbus_sys:1;
unsigned int     clk_en_cbustx_sys:1;
unsigned int     clk_en_cbusrx_sys:1;
unsigned int     clk_en_misc_cec0:1;
unsigned int     clk_en_misc_vfd:1;
unsigned int     clk_en_misc_mix:1;
}CLOCK_ENABLE;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     rd_only_0_en:1;
unsigned int     reserved_1:2;
unsigned int     blk_protect_0_wpro_en:1;
unsigned int     reserved_2:2;
unsigned int     blk_protect_0_en:1;
unsigned int     reserved_3:8;
unsigned int     protect_0_wpro_en:1;
unsigned int     reserved_4:8;
unsigned int     protect_0_en:1;
}DC_0;

typedef struct 
{
unsigned int     mem_saddr0:20;
unsigned int     reserved_0:12;
}DC_1;

typedef struct 
{
unsigned int     mem_eaddr0:20;
unsigned int     reserved_0:12;
}DC_2;

typedef struct 
{
unsigned int     blk_saddr0:20;
unsigned int     reserved_0:12;
}DC_3;

typedef struct 
{
unsigned int     blk_eaddr0:20;
unsigned int     reserved_0:12;
}DC_4;

typedef struct 
{
unsigned int     ro_saddr0:20;
unsigned int     reserved_0:12;
}DC_5;

typedef struct 
{
unsigned int     ro_eaddr0:20;
unsigned int     reserved_0:12;
}DC_6;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     md_tee_protect_en:1;
unsigned int     reserved_1:7;
unsigned int     cp_tee_protect_en:1;
unsigned int     reserved_2:7;
unsigned int     vo_protect_en:1;
unsigned int     reserved_3:7;
unsigned int     nf_tee_protect_en:1;
}DC_7;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     scpu_tee_protect_en:1;
unsigned int     reserved_1:7;
unsigned int     acpu_protect_en:1;
unsigned int     reserved_2:7;
unsigned int     video_protect_en:1;
unsigned int     reserved_3:7;
unsigned int     audio_protect_en:1;
}DC_8;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     scpu_tee_blk_protect_en:1;
unsigned int     reserved_1:1;
unsigned int     acpu_blk_protect_en:1;
unsigned int     reserved_2:1;
unsigned int     video_blk_protect_en:1;
unsigned int     reserved_3:1;
unsigned int     audio_blk_protect_en:1;
unsigned int     reserved_4:1;
unsigned int     md_tee_blk_protect_en:1;
unsigned int     reserved_5:1;
unsigned int     cp_tee_blk_protect_en:1;
unsigned int     reserved_6:1;
unsigned int     vo_blk_protect_en:1;
unsigned int     reserved_7:1;
unsigned int     nf_tee_blk_protect_en:1;
}DC_9;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     scpu_tee_ro_protect_en:1;
unsigned int     reserved_1:3;
unsigned int     acpu_ro_protect_en:1;
unsigned int     reserved_2:3;
unsigned int     video_ro_protect_en:1;
unsigned int     reserved_3:3;
unsigned int     audio_ro_protect_en:1;
unsigned int     reserved_4:3;
unsigned int     md_tee_ro_protect_en:1;
unsigned int     reserved_5:3;
unsigned int     cp_tee_ro_protect_en:1;
unsigned int     reserved_6:3;
unsigned int     vo_ro_protect_en:1;
unsigned int     reserved_7:3;
unsigned int     nf_tee_ro_protect_en:1;
}DC_A;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     XTAL_PAD_DRV:2;
}PLL_XTAL_CTRL;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C6_SDA_DEL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     int_option:1;
}HDMI_RX;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     i2c6_mis_mux:1;
}I2C6_MUX;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     usb2sram_ctrl:1;
unsigned int     ve_encode_block_nwc:1;
unsigned int     ve_block_nwc:1;
unsigned int     vo_block_nwc:1;
unsigned int     dc_mem_port_lock:1;
unsigned int     secure_rbus:1;
}SB2_0;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GPDIR:21;
}GPDIR;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GPDATO:21;
}GPDATO;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GPDATI:21;
}GPDATI;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GP:21;
}GPIE;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     GPHA:21;
}GPDP;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     write_en1:1;
unsigned int     CLK1:3;
}ISO_GPDEB;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     KPADEN:1;
unsigned int     SWEN:1;
unsigned int     CLKSEL:1;
unsigned int     ENVFD:1;
}VFD_CTL;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     NACT_CSN:1;
unsigned int     B3C:1;
unsigned int     B2C:1;
unsigned int     B1C:1;
unsigned int     B0C:1;
unsigned int     ENB3:1;
unsigned int     ENB2:1;
unsigned int     ENB1:1;
unsigned int     ENB0:1;
unsigned int     reserved_1:2;
unsigned int     WD:1;
unsigned int     WDIE:1;
}VFD_WRCTL;

typedef struct 
{
unsigned int     BYTE3:8;
unsigned int     BYTE2:8;
unsigned int     BYTE1:8;
unsigned int     BYTE0:8;
}VFDO;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     KPADBN:3;
unsigned int     reserved_1:2;
unsigned int     SWHA:1;
unsigned int     KPADHA:1;
unsigned int     reserved_2:2;
unsigned int     ARDP:2;
}VFD_ARDCTL;

typedef struct 
{
unsigned int     KPADIE:32;
}VFD_KPADLIE;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     KPADIE:16;
}VFD_KPADHIE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     SWIE:4;
}VFD_SWIE;

typedef struct 
{
unsigned int     ST_31_24:8;
unsigned int     ST_23_16:8;
unsigned int     ST_15_8:8;
unsigned int     ST_7_0:8;
}VFD_ARDKPADL;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     ST_15_8:8;
unsigned int     ST_7_0:8;
}VFD_ARDKPADH;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     RvdA:12;
unsigned int     ST:4;
}VFD_ARDSW;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     CLKSEL_1:1;
unsigned int     Tclk_csn:8;
unsigned int     Twait1:8;
}VFD_CTL1;

typedef struct 
{
unsigned int     i2c_scl_0_smt:1;
unsigned int     i2c_scl_0_e2:1;
unsigned int     i2c_scl_0_pud_en:1;
unsigned int     i2c_scl_0_pud_sel:1;
unsigned int     i2c_sda_0_smt:1;
unsigned int     i2c_sda_0_e2:1;
unsigned int     i2c_sda_0_pud_en:1;
unsigned int     i2c_sda_0_pud_sel:1;
unsigned int     vfd_d_smt:1;
unsigned int     vfd_d_e2:1;
unsigned int     vfd_d_pud_en:1;
unsigned int     vfd_d_pud_sel:1;
unsigned int     vfd_clk_smt:1;
unsigned int     vfd_clk_e2:1;
unsigned int     vfd_clk_pud_en:1;
unsigned int     vfd_clk_pud_sel:1;
unsigned int     vfd_cs_n_smt:1;
unsigned int     vfd_cs_n_e2:1;
unsigned int     vfd_cs_n_pud_en:1;
unsigned int     vfd_cs_n_pud_sel:1;
unsigned int     ir_rx_smt:1;
unsigned int     ir_rx_e2:1;
unsigned int     ir_rx_pud_en:1;
unsigned int     ir_rx_pud_sel:1;
unsigned int     usb_ovrcur_flag_n_1_smt:1;
unsigned int     usb_ovrcur_flag_n_1_e2:1;
unsigned int     usb_ovrcur_flag_n_1_pud_en:1;
unsigned int     usb_ovrcur_flag_n_1_pud_sel:1;
unsigned int     usb_ovrcur_flag_n_0_smt:1;
unsigned int     usb_ovrcur_flag_n_0_e2:1;
unsigned int     usb_ovrcur_flag_n_0_pud_en:1;
unsigned int     usb_ovrcur_flag_n_0_pud_sel:1;
}PFUNC0;

typedef struct 
{
unsigned int     etn_led_rxtx_smt:1;
unsigned int     etn_led_rxtx_e2:1;
unsigned int     etn_led_rxtx_pud_en:1;
unsigned int     etn_led_rxtx_pud_sel:1;
unsigned int     etn_led_link_smt:1;
unsigned int     etn_led_link_e2:1;
unsigned int     etn_led_link_pud_en:1;
unsigned int     etn_led_link_pud_sel:1;
unsigned int     ur0_tx_smt:1;
unsigned int     ur0_tx_e2:1;
unsigned int     ur0_tx_pud_en:1;
unsigned int     ur0_tx_pud_sel:1;
unsigned int     ur0_rx_smt:1;
unsigned int     ur0_rx_e2:1;
unsigned int     ur0_rx_pud_en:1;
unsigned int     ur0_rx_pud_sel:1;
unsigned int     ur1_cts_n_smt:1;
unsigned int     ur1_cts_n_e2:1;
unsigned int     ur1_cts_n_pud_en:1;
unsigned int     ur1_cts_n_pud_sel:1;
unsigned int     ur1_rts_n_smt:1;
unsigned int     ur1_rts_n_e2:1;
unsigned int     ur1_rts_n_pud_en:1;
unsigned int     ur1_rts_n_pud_sel:1;
unsigned int     ur1_tx_smt:1;
unsigned int     ur1_tx_e2:1;
unsigned int     ur1_tx_pud_en:1;
unsigned int     ur1_tx_pud_sel:1;
unsigned int     ur1_rx_smt:1;
unsigned int     ur1_rx_e2:1;
unsigned int     ur1_rx_pud_en:1;
unsigned int     ur1_rx_pud_sel:1;
}PFUNC1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     ir_tx_smt:1;
unsigned int     ir_tx_e2:1;
unsigned int     ir_tx_pud_en:1;
unsigned int     ir_tx_pud_sel:1;
unsigned int     i2c_scl_6_smt:1;
unsigned int     i2c_scl_6_e2:1;
unsigned int     i2c_scl_6_pud_en:1;
unsigned int     i2c_scl_6_pud_sel:1;
unsigned int     i2c_sda_6_smt:1;
unsigned int     i2c_sda_6_e2:1;
unsigned int     i2c_sda_6_pud_en:1;
unsigned int     i2c_sda_6_pud_sel:1;
unsigned int     boot_sel_pud_en:1;
unsigned int     boot_sel_pud_sel:1;
unsigned int     testmode_pud_en:1;
unsigned int     testmode_pud_sel:1;
unsigned int     standby1_smt:1;
unsigned int     standby1_e2:1;
unsigned int     standby1_pud_en:1;
unsigned int     standby1_pud_sel:1;
unsigned int     standby_smt:1;
unsigned int     standby_e2:1;
unsigned int     standby_pud_en:1;
unsigned int     standby_pud_sel:1;
}PFUNC2;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     boption12_en:1;
unsigned int     boption12_sel:1;
unsigned int     boption11_en:1;
unsigned int     boption11_sel:1;
unsigned int     boption10_en:1;
unsigned int     boption10_sel:1;
unsigned int     boption2_en:1;
unsigned int     boption2_sel:1;
}PFUNC3;

typedef struct 
{
unsigned int     etn_led_rxtx:2;
unsigned int     etn_led_link:2;
unsigned int     i2c_sda_0:2;
unsigned int     i2c_scl_0:2;
unsigned int     ur0_tx:2;
unsigned int     ur0_rx:2;
unsigned int     ur1_cts_n:2;
unsigned int     ur1_rts_n:2;
unsigned int     ur1_tx:2;
unsigned int     ur1_rx:2;
unsigned int     usb1:2;
unsigned int     usb0:2;
unsigned int     ir_rx:2;
unsigned int     vfd_cs_n:2;
unsigned int     vfd_clk:2;
unsigned int     vfd_d:2;
}MUXPAD0;

typedef struct 
{
unsigned int     ai_loc:2;
unsigned int     ejtag_avcpu_loc:2;
unsigned int     ur1_loc:2;
unsigned int     pwm_01_open_drain_switch:1;
unsigned int     pwm_23_open_drain_switch:1;
unsigned int     reserved_0:18;
unsigned int     ir_tx:2;
unsigned int     i2c_sda_6:2;
unsigned int     i2c_scl_6:2;
}MUXPAD1;

typedef struct 
{
unsigned int     IRRBL:8;
unsigned int     IRRML:8;
unsigned int     IRRDZL:8;
unsigned int     IRRDOL:8;
}IR_PSR;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     IRRDL:6;
unsigned int     IRRRL:8;
unsigned int     IRRSL:8;
}IR_PER;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IRFD:16;
}IR_SF;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IRIOTCDP:16;
}IR_DPIR;

typedef struct 
{
unsigned int     IRSR:1;
unsigned int     reserved_0:5;
unsigned int     rcmm_en:1;
unsigned int     toshiba_en:1;
unsigned int     IREDNM:1;
unsigned int     reserved_1:1;
unsigned int     IREDN:6;
unsigned int     reserved_2:1;
unsigned int     raw_fifo_ov:1;
unsigned int     raw_fifo_val:1;
unsigned int     RAW_EN:1;
unsigned int     MLAE:1;
unsigned int     IRIE:1;
unsigned int     IRRES:1;
unsigned int     IRUE:1;
unsigned int     IRCM:1;
unsigned int     IRBME:1;
unsigned int     IRDPM:1;
unsigned int     IRDN:5;
}IR_CR;

typedef struct 
{
unsigned int     IRRP:32;
}IR_RP;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     slen_big:1;
unsigned int     blen_big:1;
unsigned int     raw_fifo_ov:1;
unsigned int     raw_fifo_val:1;
unsigned int     IRRF:1;
unsigned int     IRDVF:1;
}IR_SR;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     stop_sample:1;
unsigned int     stop_time:16;
unsigned int     reserved_1:1;
unsigned int     write_en1:1;
unsigned int     fifo_thr:6;
}IR_RAW_CTRL;

typedef struct 
{
unsigned int     DAT:32;
}IR_RAW_FF;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     CNT:16;
}IR_RAW_SAMPLE_TIME;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     VAL:6;
}IR_RAW_WL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     LEN:8;
unsigned int     CLK:16;
}IR_RAW_DEB;

typedef struct 
{
unsigned int     IRRBL:8;
unsigned int     IRRML:8;
unsigned int     IRRDZL:8;
unsigned int     IRRDOL:8;
}IR_PSR_UP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IRRRL:8;
unsigned int     IRRSL:8;
}IR_PER_UP;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     RC6_EN:1;
unsigned int     IRTR:8;
}IR_CTRL_RC6;

typedef struct 
{
unsigned int     IRRP:32;
}IR_RP2;

typedef struct 
{
unsigned int     IRTX_EN:1;
unsigned int     reserved_0:20;
unsigned int     IACT_LVL:1;
unsigned int     MODULATION:1;
unsigned int     ENDIAN:1;
unsigned int     Dummy:2;
unsigned int     FIFOOUT_INV:1;
unsigned int     IRTXOUT_INV:1;
unsigned int     reserved_1:3;
unsigned int     START:1;
}IRTX_CFG;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IRTX_FD:16;
}IRTX_TIM;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     PWM_CLKSRC_DIV:4;
unsigned int     PWM_CLK_DUTY:8;
unsigned int     PWM_CLK_DIV:8;
}IRTX_PWM_SETTING;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     DATA_THR:6;
unsigned int     reserved_1:6;
unsigned int     EMP_EN:1;
unsigned int     REQ_EN:1;
}IRTX_INT_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     EMP_FLAG:1;
unsigned int     REQ_FLAG:1;
}IRTX_INT_ST;

typedef struct 
{
unsigned int     FIFO_RST:1;
unsigned int     reserved_0:19;
unsigned int     VALID_LEN:4;
unsigned int     WRP:4;
unsigned int     RDP:4;
}IRTX_FIFO_ST;

typedef struct 
{
unsigned int     DATA:32;
}IRTX_FIFO;

typedef struct 
{
unsigned int     LEN_11:8;
unsigned int     LEN_10:8;
unsigned int     LEN_01:8;
unsigned int     LEN_00:8;
}IRRCMM_TIMING;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     dec_by_min_max:1;
}IR_CR1;

typedef struct 
{
unsigned int     CEC_Mode:2;
unsigned int     reserved_0:1;
unsigned int     test_mode_pad_en:1;
unsigned int     logical_addr0:4;
unsigned int     timer_div:8;
unsigned int     Pre_div:8;
unsigned int     unreg_ack_en:1;
unsigned int     reserved_1:1;
unsigned int     Cdc_arbitration_en:1;
unsigned int     test_mode_pad_data:5;
}CEC_CR0;

typedef struct 
{
unsigned int     cec_pad_in:1;
unsigned int     dummy0:3;
unsigned int     logical_addr3:4;
unsigned int     logical_addr2:4;
unsigned int     logical_addr1:4;
unsigned int     dummy1:4;
unsigned int     clear_cec_int:1;
unsigned int     wt_cnt:6;
unsigned int     lattest:1;
unsigned int     retry_no:4;
}CEC_RTCR0;

typedef struct 
{
unsigned int     Broadcast_addr:1;
unsigned int     reserved_0:11;
unsigned int     dest_addr:4;
unsigned int     rx_en:1;
unsigned int     rx_rst:1;
unsigned int     rx_continuous:1;
unsigned int     rx_int_en:1;
unsigned int     init_addr:4;
unsigned int     rx_eom:1;
unsigned int     rx_int:1;
unsigned int     rx_fifo_ov:1;
unsigned int     rx_fifo_cnt:5;
}CEC_RXCR0;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     tx_addr_en:1;
unsigned int     tx_addr:4;
unsigned int     tx_en:1;
unsigned int     tx_rst:1;
unsigned int     tx_continuous:1;
unsigned int     tx_int_en:1;
unsigned int     dest_addr:4;
unsigned int     tx_eom:1;
unsigned int     tx_int:1;
unsigned int     tx_fifo_ud:1;
unsigned int     tx_fifo_cnt:5;
}CEC_TXCR0;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     tx_add_cnt:1;
unsigned int     rx_sub_cnt:1;
unsigned int     fifo_cnt:5;
}CEC_TXDR0;

typedef struct 
{
unsigned int     tx_fifo_0:8;
unsigned int     tx_fifo_1:8;
unsigned int     tx_fifo_2:8;
unsigned int     tx_fifo_3:8;
}CEC_TXDR1;

typedef struct 
{
unsigned int     tx_fifo_4:8;
unsigned int     tx_fifo_5:8;
unsigned int     tx_fifo_6:8;
unsigned int     tx_fifo_7:8;
}CEC_TXDR2;

typedef struct 
{
unsigned int     tx_fifo_8:8;
unsigned int     tx_fifo_9:8;
unsigned int     tx_fifo_A:8;
unsigned int     tx_fifo_B:8;
}CEC_TXDR3;

typedef struct 
{
unsigned int     tx_fifo_C:8;
unsigned int     tx_fifo_D:8;
unsigned int     tx_fifo_E:8;
unsigned int     tx_fifo_F:8;
}CEC_TXDR4;

typedef struct 
{
unsigned int     rx_fifo_0:8;
unsigned int     rx_fifo_1:8;
unsigned int     rx_fifo_2:8;
unsigned int     rx_fifo_3:8;
}CEC_RXDR1;

typedef struct 
{
unsigned int     rx_fifo_4:8;
unsigned int     rx_fifo_5:8;
unsigned int     rx_fifo_6:8;
unsigned int     rx_fifo_7:8;
}CEC_RXDR2;

typedef struct 
{
unsigned int     rx_fifo_8:8;
unsigned int     rx_fifo_9:8;
unsigned int     rx_fifo_A:8;
unsigned int     rx_fifo_B:8;
}CEC_RXDR3;

typedef struct 
{
unsigned int     rx_fifo_C:8;
unsigned int     rx_fifo_D:8;
unsigned int     rx_fifo_E:8;
unsigned int     rx_fifo_F:8;
}CEC_RXDR4;

typedef struct 
{
unsigned int     rx_start_low:8;
unsigned int     rx_start_period:8;
unsigned int     rx_data_sample:8;
unsigned int     rx_data_period:8;
}CEC_RXTCR0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     tx_start_low:8;
unsigned int     tx_start_high:8;
}CEC_TXTCR0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     tx_data_low:8;
unsigned int     tx_data_01:8;
unsigned int     tx_data_high:8;
}CEC_TXTCR1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_01:8;
}GDI_CEC_COMPARE_OPCODE_01;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Send_opcode_01:8;
}GDI_CEC_SEND_OPCODE_01;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     Operand_number_01:2;
}GDI_CEC_SEND_OPRAND_NUMBER_01;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_01:8;
}GDI_CEC_OPRAND_01;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_02:8;
}GDI_CEC_OPRAND_02;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_03:8;
}GDI_CEC_OPRAND_03;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_02:8;
}GDI_CEC_COMPARE_OPCODE_02;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Send_opcode_02:8;
}GDI_CEC_SEND_OPCODE_02;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     Operand_number_02:2;
}GDI_CEC_SEND_OPRAND_NUMBER_02;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_04:8;
}GDI_CEC_OPRAND_04;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_05:8;
}GDI_CEC_OPRAND_05;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_06:8;
}GDI_CEC_OPRAND_06;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_03:8;
}GDI_CEC_COMPARE_OPCODE_03;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Send_opcode_03:8;
}GDI_CEC_SEND_OPCODE_03;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     Operand_number_03:2;
}GDI_CEC_SEND_OPRAND_NUMBER_03;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_07:8;
}GDI_CEC_OPRAND_07;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_08:8;
}GDI_CEC_OPRAND_08;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_09:8;
}GDI_CEC_OPRAND_09;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_04:8;
}GDI_CEC_COMPARE_OPCODE_04;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Send_opcode_04:8;
}GDI_CEC_SEND_OPCODE_04;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     Operand_number_04:2;
}GDI_CEC_SEND_OPRAND_NUMBER_04;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_10:8;
}GDI_CEC_OPRAND_10;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_11:8;
}GDI_CEC_OPRAND_11;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Operand_12:8;
}GDI_CEC_OPRAND_12;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_05:8;
}GDI_CEC_COMPARE_OPCODE_05;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_06:8;
}GDI_CEC_COMPARE_OPCODE_06;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_07:8;
}GDI_CEC_COMPARE_OPCODE_07;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_08:8;
}GDI_CEC_COMPARE_OPCODE_08;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_09:8;
}GDI_CEC_COMPARE_OPCODE_09;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_10:8;
}GDI_CEC_COMPARE_OPCODE_10;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_11:8;
}GDI_CEC_COMPARE_OPCODE_11;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_12:8;
}GDI_CEC_COMPARE_OPCODE_12;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_13:8;
}GDI_CEC_COMPARE_OPCODE_13;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_14:8;
}GDI_CEC_COMPARE_OPCODE_14;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Compare_opcode_15:8;
}GDI_CEC_COMPARE_OPCODE_15;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     EN_compare_opcode_15:1;
unsigned int     EN_compare_opcode_14:1;
unsigned int     EN_compare_opcode_13:1;
unsigned int     EN_compare_opcode_12:1;
unsigned int     EN_compare_opcode_11:1;
unsigned int     EN_compare_opcode_10:1;
unsigned int     EN_compare_opcode_09:1;
unsigned int     EN_compare_opcode_08:1;
unsigned int     EN_compare_opcode_07:1;
unsigned int     EN_compare_opcode_06:1;
unsigned int     EN_compare_opcode_05:1;
unsigned int     EN_compare_opcode_04:1;
unsigned int     EN_compare_opcode_03:1;
unsigned int     EN_compare_opcode_02:1;
unsigned int     EN_compare_opcode_01:1;
}GDI_CEC_OPCODE_ENABLE;

typedef struct 
{
unsigned int     Irq_pending:1;
unsigned int     reserved_0:5;
unsigned int     Cec_msg_status_01:1;
unsigned int     Cec_msg_status_02:1;
unsigned int     reserved_1:15;
unsigned int     Irq_by_cec_receive_special_cmd:1;
unsigned int     reserved_2:8;
}GDI_POWER_SAVING_MODE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     REG_CEC_RPU_EN:1;
unsigned int     REG_CEC_RSEL:3;
}CEC_ANALOG;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SET:1;
}DRM_ST;

typedef struct 
{
unsigned int     VAL:32;
}DRM_SECURE_CLK;

typedef struct 
{
unsigned int     VAL:32;
}DRM_ELAPSED;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST1;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST2;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     clk_div_en:1;
unsigned int     clk_sel:1;
}DRM_CTRL;

typedef struct 
{
unsigned int     init:32;
}DRM_CLK_DIV;

typedef struct 
{
unsigned int     TC3TVR:32;
}TC3TVR;

typedef struct 
{
unsigned int     TC3CVR:32;
}TC3CVR;

typedef struct 
{
unsigned int     TC3En:1;
unsigned int     TC3Mode:1;
unsigned int     TC3Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}TC3CR;

typedef struct 
{
unsigned int     TC3IE:1;
unsigned int     reserved_0:31;
}TC3ICR;

typedef struct 
{
unsigned int     TC4TVR:32;
}TC4TVR;

typedef struct 
{
unsigned int     TC4CVR:32;
}TC4CVR;

typedef struct 
{
unsigned int     TC4En:1;
unsigned int     TC4Mode:1;
unsigned int     TC4Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}TC4CR;

typedef struct 
{
unsigned int     TC4IE:1;
unsigned int     reserved_0:31;
}TC4ICR;

typedef struct 
{
unsigned int     dat:32;
}NORST;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST3;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST4;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST5;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST6;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST7;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST8;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST9;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST10;

typedef struct 
{
unsigned int     WD_INT_EN:1;
unsigned int     reserved_0:15;
unsigned int     NMIC:4;
unsigned int     WDC:4;
unsigned int     WDEN:8;
}ISO_TCWCR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     WDCLR:1;
}ISO_TCWTR;

typedef struct 
{
unsigned int     SEL:32;
}ISO_TCWNMI;

typedef struct 
{
unsigned int     SEL:32;
}ISO_TCWOV;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SET:1;
}DRM_ST_SWC;

typedef struct 
{
unsigned int     VAL:32;
}DRM_SECURE_CLK_SWC;

typedef struct 
{
unsigned int     VAL:32;
}DRM_ELAPSED_SWC;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     clk_div_en:1;
unsigned int     clk_sel:1;
}DRM_CTRL_SWC;

typedef struct 
{
unsigned int     init:32;
}DRM_CLK_DIV_SWC;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST_SWC;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST1_SWC;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST2_SWC;

typedef struct 
{
unsigned int     VAL:32;
}COLD_RST3_SWC;

typedef struct 
{
unsigned int     dat:32;
}NORST_SWC;

typedef struct 
{
unsigned int     dat:32;
}NORST1_SWC;

typedef struct 
{
unsigned int     dat:32;
}NORST2_SWC;

typedef struct 
{
unsigned int     SEL:32;
}TCWOV_RSTB_CNT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_boot_info_valid:1;
}CPU_ST2V;

typedef struct 
{
unsigned int     scpu_boot_info:32;
}CPU_ST2;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     write_enable3:1;
unsigned int     sel1:5;
unsigned int     write_enable2:1;
unsigned int     sel0:5;
unsigned int     write_enable1:1;
unsigned int     enable:1;
}ACPU_DBG;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     analogy_mode_in:1;
}ISO_ANLG;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DLL:8;
}U0RBR_THR_DLL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DLH:8;
}U0IER_DLH;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FIFO16:2;
unsigned int     reserved_1:2;
unsigned int     IID:4;
}U0IIR_FCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DLAB:1;
unsigned int     BRK:1;
unsigned int     reserved_1:1;
unsigned int     EPS:1;
unsigned int     PEN:1;
unsigned int     STB:1;
unsigned int     WLS:2;
}U0LCR;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     AFCE:1;
unsigned int     LOOP:1;
unsigned int     reserved_1:2;
unsigned int     RTS:1;
unsigned int     DTR:1;
}U0MCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RFE:1;
unsigned int     TEMT:1;
unsigned int     THRE:1;
unsigned int     BI:1;
unsigned int     FE:1;
unsigned int     PE:1;
unsigned int     OE:1;
unsigned int     DR:1;
}U0LSR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DCD:1;
unsigned int     RI:1;
unsigned int     DSR:1;
unsigned int     CTS:1;
unsigned int     DDCD:1;
unsigned int     TERI:1;
unsigned int     DDSR:1;
unsigned int     DCTS:1;
}U0MSR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SCR:8;
}U0SCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RBD:8;
}U0SRBR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     FAR:1;
}U0FAR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FAR:8;
}U0TFR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     RFFE:1;
unsigned int     RFPF:1;
unsigned int     RFWD:8;
}U0RFW;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     RFF:1;
unsigned int     RFNE:1;
unsigned int     TFE:1;
unsigned int     TFNF:1;
unsigned int     BUSY:1;
}U0USR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TFL:8;
}U0TFL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RFL:8;
}U0RFL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     XFR:1;
unsigned int     RFR:1;
unsigned int     UR:1;
}U0SRR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SBCR:1;
}U0SBCR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SDMAM:1;
}U0SDMAM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SFE:1;
}U0SFE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     SRT:2;
}U0SRT;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     STET:2;
}U0STET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     HTX:1;
}U0HTX;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DMASA:1;
}U0DMASA;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     FIFO_MODE:8;
unsigned int     reserved_1:2;
unsigned int     DMA_EXTRA:1;
unsigned int     UART_ADD_ENCODED_PARAMS:1;
unsigned int     SHADOW:1;
unsigned int     FIFO_STAT:1;
unsigned int     FIFO_ACCESS:1;
unsigned int     ADDITIONAL_FEAT:1;
unsigned int     SIR_LP_MODE:1;
unsigned int     SIR_MODE:1;
unsigned int     THRE_MODE:1;
unsigned int     AFCE_MODE:1;
unsigned int     reserved_2:2;
unsigned int     APB_DATA_WIDTH:2;
}U0CPR;

typedef struct 
{
unsigned int     UCV:32;
}U0UCV;

typedef struct 
{
unsigned int     CTR:32;
}U0CTR;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC0_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC0_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC0_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC0_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC0_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC0_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC0_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC0_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC0_FS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     R_GEN_CALL:1;
unsigned int     R_START_DET:1;
unsigned int     R_STOP_DET:1;
unsigned int     R_ACTIVITY:1;
unsigned int     R_RX_DONE:1;
unsigned int     R_TX_ABRT:1;
unsigned int     R_RD_REQ:1;
unsigned int     R_TX_EMPTY:1;
unsigned int     R_TX_OVER:1;
unsigned int     R_RX_FULL:1;
unsigned int     R_RX_OVER:1;
unsigned int     R_RX_UNDER:1;
}IC0_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     M_GEN_CALL:1;
unsigned int     M_START_DET:1;
unsigned int     M_STOP_DET:1;
unsigned int     M_ACTIVITY:1;
unsigned int     M_RX_DONE:1;
unsigned int     M_TX_ABRT:1;
unsigned int     M_RD_REQ:1;
unsigned int     M_TX_EMPTY:1;
unsigned int     M_TX_OVER:1;
unsigned int     M_RX_FULL:1;
unsigned int     M_RX_OVER:1;
unsigned int     M_RX_UNDER:1;
}IC0_INTR_MASK;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     GEN_CALL:1;
unsigned int     START_DET:1;
unsigned int     STOP_DET:1;
unsigned int     ACTIVITY:1;
unsigned int     RX_DONE:1;
unsigned int     TX_ABRT:1;
unsigned int     RD_REQ:1;
unsigned int     TX_EMPTY:1;
unsigned int     TX_OVER:1;
unsigned int     RX_FULL:1;
unsigned int     RX_OVER:1;
unsigned int     RX_UNDER:1;
}IC0_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC0_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC0_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC0_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC0_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC0_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC0_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC0_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC0_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC0_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC0_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC0_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC0_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC0_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC0_ENABLE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     SLV_ACTIVITY:1;
unsigned int     MST_ACTIVITY:1;
unsigned int     RFF:1;
unsigned int     RFNE:1;
unsigned int     TFE:1;
unsigned int     TFNF:1;
unsigned int     ACTIVITY:1;
}IC0_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC0_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC0_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SDA_HOLD:16;
}IC0_SDA_HOLD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     ABRT_SLVRD_INTX:1;
unsigned int     ABRT_SLV_ARBLOST:1;
unsigned int     ABRT_SLVFLUSH_TXFIFO:1;
unsigned int     ARB_LOST:1;
unsigned int     ARB_MASTER_DIS:1;
unsigned int     ABRT_10B_RD_NORSTRT:1;
unsigned int     ABRT_SBYTE_NORSTRT:1;
unsigned int     ABRT_HS_NORSTRT:1;
unsigned int     ABRT_SBYTE_ACKDET:1;
unsigned int     ABRT_HS_ACKDET:1;
unsigned int     ABRT_GCALL_READ:1;
unsigned int     ABRT_GCALL_NOACK:1;
unsigned int     ABRT_TXDATA_NOACK:1;
unsigned int     ABRT_10ADDR2_NOACK:1;
unsigned int     ABRT_10ADDR1_NOACK:1;
unsigned int     ABRT_7B_ADDR_NOACK:1;
}IC0_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC0_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC0_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC0_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC0_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC0_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC0_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC0_ENABLE_STATUS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     TX_BUFFER_DEPTH:8;
unsigned int     RX_BUFFER_DEPTH:8;
unsigned int     ADD_ENCODED_PARAMS:1;
unsigned int     HAS_DMA:1;
unsigned int     INTR_IO:1;
unsigned int     HC_COUNT_VALUES:1;
unsigned int     MAX_SPEED_MODE:2;
unsigned int     APB_DATA_WIDTH:2;
}IC0_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC0_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC0_COMP_TYPE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC6_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC6_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC6_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC6_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC6_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC6_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC6_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC6_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC6_FS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     R_GEN_CALL:1;
unsigned int     R_START_DET:1;
unsigned int     R_STOP_DET:1;
unsigned int     R_ACTIVITY:1;
unsigned int     R_RX_DONE:1;
unsigned int     R_TX_ABRT:1;
unsigned int     R_RD_REQ:1;
unsigned int     R_TX_EMPTY:1;
unsigned int     R_TX_OVER:1;
unsigned int     R_RX_FULL:1;
unsigned int     R_RX_OVER:1;
unsigned int     R_RX_UNDER:1;
}IC6_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     M_GEN_CALL:1;
unsigned int     M_START_DET:1;
unsigned int     M_STOP_DET:1;
unsigned int     M_ACTIVITY:1;
unsigned int     M_RX_DONE:1;
unsigned int     M_TX_ABRT:1;
unsigned int     M_RD_REQ:1;
unsigned int     M_TX_EMPTY:1;
unsigned int     M_TX_OVER:1;
unsigned int     M_RX_FULL:1;
unsigned int     M_RX_OVER:1;
unsigned int     M_RX_UNDER:1;
}IC6_INTR_MASK;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     GEN_CALL:1;
unsigned int     START_DET:1;
unsigned int     STOP_DET:1;
unsigned int     ACTIVITY:1;
unsigned int     RX_DONE:1;
unsigned int     TX_ABRT:1;
unsigned int     RD_REQ:1;
unsigned int     TX_EMPTY:1;
unsigned int     TX_OVER:1;
unsigned int     RX_FULL:1;
unsigned int     RX_OVER:1;
unsigned int     RX_UNDER:1;
}IC6_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC6_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC6_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC6_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC6_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC6_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC6_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC6_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC6_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC6_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC6_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC6_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC6_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC6_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC6_ENABLE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     SLV_ACTIVITY:1;
unsigned int     MST_ACTIVITY:1;
unsigned int     RFF:1;
unsigned int     RFNE:1;
unsigned int     TFE:1;
unsigned int     TFNF:1;
unsigned int     ACTIVITY:1;
}IC6_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC6_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC6_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SDA_HOLD:16;
}IC6_SDA_HOLD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     ABRT_SLVRD_INTX:1;
unsigned int     ABRT_SLV_ARBLOST:1;
unsigned int     ABRT_SLVFLUSH_TXFIFO:1;
unsigned int     ARB_LOST:1;
unsigned int     ARB_MASTER_DIS:1;
unsigned int     ABRT_10B_RD_NORSTRT:1;
unsigned int     ABRT_SBYTE_NORSTRT:1;
unsigned int     ABRT_HS_NORSTRT:1;
unsigned int     ABRT_SBYTE_ACKDET:1;
unsigned int     ABRT_HS_ACKDET:1;
unsigned int     ABRT_GCALL_READ:1;
unsigned int     ABRT_GCALL_NOACK:1;
unsigned int     ABRT_TXDATA_NOACK:1;
unsigned int     ABRT_10ADDR2_NOACK:1;
unsigned int     ABRT_10ADDR1_NOACK:1;
unsigned int     ABRT_7B_ADDR_NOACK:1;
}IC6_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC6_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC6_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC6_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC6_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC6_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC6_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC6_ENABLE_STATUS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     TX_BUFFER_DEPTH:8;
unsigned int     RX_BUFFER_DEPTH:8;
unsigned int     ADD_ENCODED_PARAMS:1;
unsigned int     HAS_DMA:1;
unsigned int     INTR_IO:1;
unsigned int     HC_COUNT_VALUES:1;
unsigned int     MAX_SPEED_MODE:2;
unsigned int     APB_DATA_WIDTH:2;
}IC6_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC6_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC6_COMP_TYPE;

typedef struct 
{
unsigned int     3:8;
unsigned int     2:8;
unsigned int     1:8;
unsigned int     0:8;
}PWM_OCD;

typedef struct 
{
unsigned int     3:8;
unsigned int     2:8;
unsigned int     1:8;
unsigned int     0:8;
}PWM_CD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     3:4;
unsigned int     2:4;
unsigned int     1:4;
unsigned int     0:4;
}PWM_CSD;

#endif

#define ISO_ISR                                                                          0x18007000
#define ISO_ISR_reg_addr                                                                 "0x18007000"
#define ISO_ISR_reg                                                                      0x18007000
#define ISO_set_ISR_reg(data)   (*((volatile unsigned int*) ISR_reg)=data)
#define ISO_get_ISR_reg   (*((volatile unsigned int*) ISR_reg))
#define ISO_ISR_inst_adr                                                                 "0x0000"
#define ISO_ISR_inst                                                                     0x0000
#define ISR_CEC_INT_shift                                                            (22)
#define ISR_CEC_INT_mask                                                             (0x00400000)
#define ISR_CEC_INT(data)                                                            (0x00400000&((data)<<22))
#define ISR_CEC_INT_src(data)                                                        ((0x00400000&(data))>>22)
#define ISR_get_CEC_INT(data)                                                        ((0x00400000&(data))>>22)
#define ISR_GPIODA_INT_shift                                                         (20)
#define ISR_GPIODA_INT_mask                                                          (0x00100000)
#define ISR_GPIODA_INT(data)                                                         (0x00100000&((data)<<20))
#define ISR_GPIODA_INT_src(data)                                                     ((0x00100000&(data))>>20)
#define ISR_get_GPIODA_INT(data)                                                     ((0x00100000&(data))>>20)
#define ISR_GPIOA_INT_shift                                                          (19)
#define ISR_GPIOA_INT_mask                                                           (0x00080000)
#define ISR_GPIOA_INT(data)                                                          (0x00080000&((data)<<19))
#define ISR_GPIOA_INT_src(data)                                                      ((0x00080000&(data))>>19)
#define ISR_get_GPIOA_INT(data)                                                      ((0x00080000&(data))>>19)
#define ISR_VFD_ARDSWDA_INT_shift                                                    (18)
#define ISR_VFD_ARDSWDA_INT_mask                                                     (0x00040000)
#define ISR_VFD_ARDSWDA_INT(data)                                                    (0x00040000&((data)<<18))
#define ISR_VFD_ARDSWDA_INT_src(data)                                                ((0x00040000&(data))>>18)
#define ISR_get_VFD_ARDSWDA_INT(data)                                                ((0x00040000&(data))>>18)
#define ISR_VFD_ARDSWA_INT_shift                                                     (17)
#define ISR_VFD_ARDSWA_INT_mask                                                      (0x00020000)
#define ISR_VFD_ARDSWA_INT(data)                                                     (0x00020000&((data)<<17))
#define ISR_VFD_ARDSWA_INT_src(data)                                                 ((0x00020000&(data))>>17)
#define ISR_get_VFD_ARDSWA_INT(data)                                                 ((0x00020000&(data))>>17)
#define ISR_VFD_ARDKPADDA_INT_shift                                                  (16)
#define ISR_VFD_ARDKPADDA_INT_mask                                                   (0x00010000)
#define ISR_VFD_ARDKPADDA_INT(data)                                                  (0x00010000&((data)<<16))
#define ISR_VFD_ARDKPADDA_INT_src(data)                                              ((0x00010000&(data))>>16)
#define ISR_get_VFD_ARDKPADDA_INT(data)                                              ((0x00010000&(data))>>16)
#define ISR_VFD_ARDKPADA_INT_shift                                                   (15)
#define ISR_VFD_ARDKPADA_INT_mask                                                    (0x00008000)
#define ISR_VFD_ARDKPADA_INT(data)                                                   (0x00008000&((data)<<15))
#define ISR_VFD_ARDKPADA_INT_src(data)                                               ((0x00008000&(data))>>15)
#define ISR_get_VFD_ARDKPADA_INT(data)                                               ((0x00008000&(data))>>15)
#define ISR_VFD_WDONE_INT_shift                                                      (14)
#define ISR_VFD_WDONE_INT_mask                                                       (0x00004000)
#define ISR_VFD_WDONE_INT(data)                                                      (0x00004000&((data)<<14))
#define ISR_VFD_WDONE_INT_src(data)                                                  ((0x00004000&(data))>>14)
#define ISR_get_VFD_WDONE_INT(data)                                                  ((0x00004000&(data))>>14)
#define ISR_RTC_ALARM_INT_shift                                                      (13)
#define ISR_RTC_ALARM_INT_mask                                                       (0x00002000)
#define ISR_RTC_ALARM_INT(data)                                                      (0x00002000&((data)<<13))
#define ISR_RTC_ALARM_INT_src(data)                                                  ((0x00002000&(data))>>13)
#define ISR_get_RTC_ALARM_INT(data)                                                  ((0x00002000&(data))>>13)
#define ISO_ISR_RTC_HSEC_INT_shift                                                       (12)
#define ISO_ISR_RTC_HSEC_INT_mask                                                        (0x00001000)
#define ISO_ISR_RTC_HSEC_INT(data)                                                       (0x00001000&((data)<<12))
#define ISO_ISR_RTC_HSEC_INT_src(data)                                                   ((0x00001000&(data))>>12)
#define ISO_ISR_get_RTC_HSEC_INT(data)                                                   ((0x00001000&(data))>>12)
#define ISR_I2C6_INT_shift                                                           (10)
#define ISR_I2C6_INT_mask                                                            (0x00000400)
#define ISR_I2C6_INT(data)                                                           (0x00000400&((data)<<10))
#define ISR_I2C6_INT_src(data)                                                       ((0x00000400&(data))>>10)
#define ISR_get_I2C6_INT(data)                                                       ((0x00000400&(data))>>10)
#define ISR_TC4_INT_shift                                                            (9)
#define ISR_TC4_INT_mask                                                             (0x00000200)
#define ISR_TC4_INT(data)                                                            (0x00000200&((data)<<9))
#define ISR_TC4_INT_src(data)                                                        ((0x00000200&(data))>>9)
#define ISR_get_TC4_INT(data)                                                        ((0x00000200&(data))>>9)
#define ISR_I2C0_INT_shift                                                           (8)
#define ISR_I2C0_INT_mask                                                            (0x00000100)
#define ISR_I2C0_INT(data)                                                           (0x00000100&((data)<<8))
#define ISR_I2C0_INT_src(data)                                                       ((0x00000100&(data))>>8)
#define ISR_get_I2C0_INT(data)                                                       ((0x00000100&(data))>>8)
#define ISO_ISR_WDOG_NMI_INT_shift                                                       (7)
#define ISO_ISR_WDOG_NMI_INT_mask                                                        (0x00000080)
#define ISO_ISR_WDOG_NMI_INT(data)                                                       (0x00000080&((data)<<7))
#define ISO_ISR_WDOG_NMI_INT_src(data)                                                   ((0x00000080&(data))>>7)
#define ISO_ISR_get_WDOG_NMI_INT(data)                                                   ((0x00000080&(data))>>7)
#define ISR_IRDA_INT_shift                                                           (5)
#define ISR_IRDA_INT_mask                                                            (0x00000020)
#define ISR_IRDA_INT(data)                                                           (0x00000020&((data)<<5))
#define ISR_IRDA_INT_src(data)                                                       ((0x00000020&(data))>>5)
#define ISR_get_IRDA_INT(data)                                                       ((0x00000020&(data))>>5)
#define ISR_UR0_INT_shift                                                            (2)
#define ISR_UR0_INT_mask                                                             (0x00000004)
#define ISR_UR0_INT(data)                                                            (0x00000004&((data)<<2))
#define ISR_UR0_INT_src(data)                                                        ((0x00000004&(data))>>2)
#define ISR_get_UR0_INT(data)                                                        ((0x00000004&(data))>>2)
#define ISR_TC3_INT_shift                                                            (1)
#define ISR_TC3_INT_mask                                                             (0x00000002)
#define ISR_TC3_INT(data)                                                            (0x00000002&((data)<<1))
#define ISR_TC3_INT_src(data)                                                        ((0x00000002&(data))>>1)
#define ISR_get_TC3_INT(data)                                                        ((0x00000002&(data))>>1)
#define ISR_write_data_shift                                                         (0)
#define ISR_write_data_mask                                                          (0x00000001)
#define ISR_write_data(data)                                                         (0x00000001&((data)<<0))
#define ISR_write_data_src(data)                                                     ((0x00000001&(data))>>0)
#define ISR_get_write_data(data)                                                     ((0x00000001&(data))>>0)


#define ISO_UMSK_ISR                                                                  0x18007004
#define ISO_UMSK_ISR_reg_addr                                                         "0x18007004"
#define ISO_UMSK_ISR_reg                                                              0x18007004
#define ISO_set_UMSK_ISR_reg(data)   (*((volatile unsigned int*) UMSK_ISR_reg)=data)
#define ISO_get_UMSK_ISR_reg   (*((volatile unsigned int*) UMSK_ISR_reg))
#define ISO_UMSK_ISR_inst_adr                                                         "0x0001"
#define ISO_UMSK_ISR_inst                                                             0x0001
#define UMSK_ISR_GPIODA_INT_shift                                                    (20)
#define UMSK_ISR_GPIODA_INT_mask                                                     (0x00100000)
#define UMSK_ISR_GPIODA_INT(data)                                                    (0x00100000&((data)<<20))
#define UMSK_ISR_GPIODA_INT_src(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_get_GPIODA_INT(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_GPIOA_INT_shift                                                     (19)
#define UMSK_ISR_GPIOA_INT_mask                                                      (0x00080000)
#define UMSK_ISR_GPIOA_INT(data)                                                     (0x00080000&((data)<<19))
#define UMSK_ISR_GPIOA_INT_src(data)                                                 ((0x00080000&(data))>>19)
#define UMSK_ISR_get_GPIOA_INT(data)                                                 ((0x00080000&(data))>>19)
#define UMSK_ISR_VFD_ARDSWDA_INT_shift                                               (18)
#define UMSK_ISR_VFD_ARDSWDA_INT_mask                                                (0x00040000)
#define UMSK_ISR_VFD_ARDSWDA_INT(data)                                               (0x00040000&((data)<<18))
#define UMSK_ISR_VFD_ARDSWDA_INT_src(data)                                           ((0x00040000&(data))>>18)
#define UMSK_ISR_get_VFD_ARDSWDA_INT(data)                                           ((0x00040000&(data))>>18)
#define UMSK_ISR_VFD_ARDSWA_INT_shift                                                (17)
#define UMSK_ISR_VFD_ARDSWA_INT_mask                                                 (0x00020000)
#define UMSK_ISR_VFD_ARDSWA_INT(data)                                                (0x00020000&((data)<<17))
#define UMSK_ISR_VFD_ARDSWA_INT_src(data)                                            ((0x00020000&(data))>>17)
#define UMSK_ISR_get_VFD_ARDSWA_INT(data)                                            ((0x00020000&(data))>>17)
#define UMSK_ISR_VFD_ARDKPADDA_INT_shift                                             (16)
#define UMSK_ISR_VFD_ARDKPADDA_INT_mask                                              (0x00010000)
#define UMSK_ISR_VFD_ARDKPADDA_INT(data)                                             (0x00010000&((data)<<16))
#define UMSK_ISR_VFD_ARDKPADDA_INT_src(data)                                         ((0x00010000&(data))>>16)
#define UMSK_ISR_get_VFD_ARDKPADDA_INT(data)                                         ((0x00010000&(data))>>16)
#define UMSK_ISR_VFD_ARDKPADA_INT_shift                                              (15)
#define UMSK_ISR_VFD_ARDKPADA_INT_mask                                               (0x00008000)
#define UMSK_ISR_VFD_ARDKPADA_INT(data)                                              (0x00008000&((data)<<15))
#define UMSK_ISR_VFD_ARDKPADA_INT_src(data)                                          ((0x00008000&(data))>>15)
#define UMSK_ISR_get_VFD_ARDKPADA_INT(data)                                          ((0x00008000&(data))>>15)
#define UMSK_ISR_VFD_WDONE_INT_shift                                                 (14)
#define UMSK_ISR_VFD_WDONE_INT_mask                                                  (0x00004000)
#define UMSK_ISR_VFD_WDONE_INT(data)                                                 (0x00004000&((data)<<14))
#define UMSK_ISR_VFD_WDONE_INT_src(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_get_VFD_WDONE_INT(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_RTC_ALARM_INT_shift                                                 (13)
#define UMSK_ISR_RTC_ALARM_INT_mask                                                  (0x00002000)
#define UMSK_ISR_RTC_ALARM_INT(data)                                                 (0x00002000&((data)<<13))
#define UMSK_ISR_RTC_ALARM_INT_src(data)                                             ((0x00002000&(data))>>13)
#define UMSK_ISR_get_RTC_ALARM_INT(data)                                             ((0x00002000&(data))>>13)
#define ISO_UMSK_ISR_RTC_HSEC_INT_shift                                              (12)
#define ISO_UMSK_ISR_RTC_HSEC_INT_mask                                               (0x00001000)
#define ISO_UMSK_ISR_RTC_HSEC_INT(data)                                              (0x00001000&((data)<<12))
#define ISO_UMSK_ISR_RTC_HSEC_INT_src(data)                                          ((0x00001000&(data))>>12)
#define ISO_UMSK_ISR_get_RTC_HSEC_INT(data)                                          ((0x00001000&(data))>>12)
#define UMSK_ISR_TC4_INT_shift                                                       (9)
#define UMSK_ISR_TC4_INT_mask                                                        (0x00000200)
#define UMSK_ISR_TC4_INT(data)                                                       (0x00000200&((data)<<9))
#define UMSK_ISR_TC4_INT_src(data)                                                   ((0x00000200&(data))>>9)
#define UMSK_ISR_get_TC4_INT(data)                                                   ((0x00000200&(data))>>9)
#define ISO_UMSK_ISR_WDOG_NMI_INT_shift                                              (7)
#define ISO_UMSK_ISR_WDOG_NMI_INT_mask                                               (0x00000080)
#define ISO_UMSK_ISR_WDOG_NMI_INT(data)                                              (0x00000080&((data)<<7))
#define ISO_UMSK_ISR_WDOG_NMI_INT_src(data)                                          ((0x00000080&(data))>>7)
#define ISO_UMSK_ISR_get_WDOG_NMI_INT(data)                                          ((0x00000080&(data))>>7)
#define UMSK_ISR_IRDA_INT_shift                                                      (5)
#define UMSK_ISR_IRDA_INT_mask                                                       (0x00000020)
#define UMSK_ISR_IRDA_INT(data)                                                      (0x00000020&((data)<<5))
#define UMSK_ISR_IRDA_INT_src(data)                                                  ((0x00000020&(data))>>5)
#define UMSK_ISR_get_IRDA_INT(data)                                                  ((0x00000020&(data))>>5)
#define UMSK_ISR_TC3_INT_shift                                                       (1)
#define UMSK_ISR_TC3_INT_mask                                                        (0x00000002)
#define UMSK_ISR_TC3_INT(data)                                                       (0x00000002&((data)<<1))
#define UMSK_ISR_TC3_INT_src(data)                                                   ((0x00000002&(data))>>1)
#define UMSK_ISR_get_TC3_INT(data)                                                   ((0x00000002&(data))>>1)
#define UMSK_ISR_write_data_shift                                                    (0)
#define UMSK_ISR_write_data_mask                                                     (0x00000001)
#define UMSK_ISR_write_data(data)                                                    (0x00000001&((data)<<0))
#define UMSK_ISR_write_data_src(data)                                                ((0x00000001&(data))>>0)
#define UMSK_ISR_get_write_data(data)                                                ((0x00000001&(data))>>0)


#define UMSK_ISR_GPA                                                                 0x18007008
#define UMSK_ISR_GPA_reg_addr                                                        "0x18007008"
#define UMSK_ISR_GPA_reg                                                             0x18007008
#define set_UMSK_ISR_GPA_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GPA_reg)=data)
#define get_UMSK_ISR_GPA_reg   (*((volatile unsigned int*) UMSK_ISR_GPA_reg))
#define UMSK_ISR_GPA_inst_adr                                                        "0x0002"
#define UMSK_ISR_GPA_inst                                                            0x0002
#define UMSK_ISR_GPA_INT20_A_shift                                                   (21)
#define UMSK_ISR_GPA_INT20_A_mask                                                    (0x00200000)
#define UMSK_ISR_GPA_INT20_A(data)                                                   (0x00200000&((data)<<21))
#define UMSK_ISR_GPA_INT20_A_src(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GPA_get_INT20_A(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GPA_INT19_A_shift                                                   (20)
#define UMSK_ISR_GPA_INT19_A_mask                                                    (0x00100000)
#define UMSK_ISR_GPA_INT19_A(data)                                                   (0x00100000&((data)<<20))
#define UMSK_ISR_GPA_INT19_A_src(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GPA_get_INT19_A(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GPA_INT18_A_shift                                                   (19)
#define UMSK_ISR_GPA_INT18_A_mask                                                    (0x00080000)
#define UMSK_ISR_GPA_INT18_A(data)                                                   (0x00080000&((data)<<19))
#define UMSK_ISR_GPA_INT18_A_src(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GPA_get_INT18_A(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GPA_INT17_A_shift                                                   (18)
#define UMSK_ISR_GPA_INT17_A_mask                                                    (0x00040000)
#define UMSK_ISR_GPA_INT17_A(data)                                                   (0x00040000&((data)<<18))
#define UMSK_ISR_GPA_INT17_A_src(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GPA_get_INT17_A(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GPA_INT16_A_shift                                                   (17)
#define UMSK_ISR_GPA_INT16_A_mask                                                    (0x00020000)
#define UMSK_ISR_GPA_INT16_A(data)                                                   (0x00020000&((data)<<17))
#define UMSK_ISR_GPA_INT16_A_src(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GPA_get_INT16_A(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GPA_INT15_A_shift                                                   (16)
#define UMSK_ISR_GPA_INT15_A_mask                                                    (0x00010000)
#define UMSK_ISR_GPA_INT15_A(data)                                                   (0x00010000&((data)<<16))
#define UMSK_ISR_GPA_INT15_A_src(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GPA_get_INT15_A(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GPA_INT14_A_shift                                                   (15)
#define UMSK_ISR_GPA_INT14_A_mask                                                    (0x00008000)
#define UMSK_ISR_GPA_INT14_A(data)                                                   (0x00008000&((data)<<15))
#define UMSK_ISR_GPA_INT14_A_src(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GPA_get_INT14_A(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GPA_INT13_A_shift                                                   (14)
#define UMSK_ISR_GPA_INT13_A_mask                                                    (0x00004000)
#define UMSK_ISR_GPA_INT13_A(data)                                                   (0x00004000&((data)<<14))
#define UMSK_ISR_GPA_INT13_A_src(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GPA_get_INT13_A(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GPA_INT12_A_shift                                                   (13)
#define UMSK_ISR_GPA_INT12_A_mask                                                    (0x00002000)
#define UMSK_ISR_GPA_INT12_A(data)                                                   (0x00002000&((data)<<13))
#define UMSK_ISR_GPA_INT12_A_src(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GPA_get_INT12_A(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GPA_INT11_A_shift                                                   (12)
#define UMSK_ISR_GPA_INT11_A_mask                                                    (0x00001000)
#define UMSK_ISR_GPA_INT11_A(data)                                                   (0x00001000&((data)<<12))
#define UMSK_ISR_GPA_INT11_A_src(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GPA_get_INT11_A(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GPA_INT10_A_shift                                                   (11)
#define UMSK_ISR_GPA_INT10_A_mask                                                    (0x00000800)
#define UMSK_ISR_GPA_INT10_A(data)                                                   (0x00000800&((data)<<11))
#define UMSK_ISR_GPA_INT10_A_src(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GPA_get_INT10_A(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GPA_INT9_A_shift                                                    (10)
#define UMSK_ISR_GPA_INT9_A_mask                                                     (0x00000400)
#define UMSK_ISR_GPA_INT9_A(data)                                                    (0x00000400&((data)<<10))
#define UMSK_ISR_GPA_INT9_A_src(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GPA_get_INT9_A(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GPA_INT8_A_shift                                                    (9)
#define UMSK_ISR_GPA_INT8_A_mask                                                     (0x00000200)
#define UMSK_ISR_GPA_INT8_A(data)                                                    (0x00000200&((data)<<9))
#define UMSK_ISR_GPA_INT8_A_src(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GPA_get_INT8_A(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GPA_INT7_A_shift                                                    (8)
#define UMSK_ISR_GPA_INT7_A_mask                                                     (0x00000100)
#define UMSK_ISR_GPA_INT7_A(data)                                                    (0x00000100&((data)<<8))
#define UMSK_ISR_GPA_INT7_A_src(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GPA_get_INT7_A(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GPA_INT6_A_shift                                                    (7)
#define UMSK_ISR_GPA_INT6_A_mask                                                     (0x00000080)
#define UMSK_ISR_GPA_INT6_A(data)                                                    (0x00000080&((data)<<7))
#define UMSK_ISR_GPA_INT6_A_src(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GPA_get_INT6_A(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GPA_INT5_A_shift                                                    (6)
#define UMSK_ISR_GPA_INT5_A_mask                                                     (0x00000040)
#define UMSK_ISR_GPA_INT5_A(data)                                                    (0x00000040&((data)<<6))
#define UMSK_ISR_GPA_INT5_A_src(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GPA_get_INT5_A(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GPA_INT4_A_shift                                                    (5)
#define UMSK_ISR_GPA_INT4_A_mask                                                     (0x00000020)
#define UMSK_ISR_GPA_INT4_A(data)                                                    (0x00000020&((data)<<5))
#define UMSK_ISR_GPA_INT4_A_src(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GPA_get_INT4_A(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GPA_INT3_A_shift                                                    (4)
#define UMSK_ISR_GPA_INT3_A_mask                                                     (0x00000010)
#define UMSK_ISR_GPA_INT3_A(data)                                                    (0x00000010&((data)<<4))
#define UMSK_ISR_GPA_INT3_A_src(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GPA_get_INT3_A(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GPA_INT2_A_shift                                                    (3)
#define UMSK_ISR_GPA_INT2_A_mask                                                     (0x00000008)
#define UMSK_ISR_GPA_INT2_A(data)                                                    (0x00000008&((data)<<3))
#define UMSK_ISR_GPA_INT2_A_src(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GPA_get_INT2_A(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GPA_INT1_A_shift                                                    (2)
#define UMSK_ISR_GPA_INT1_A_mask                                                     (0x00000004)
#define UMSK_ISR_GPA_INT1_A(data)                                                    (0x00000004&((data)<<2))
#define UMSK_ISR_GPA_INT1_A_src(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GPA_get_INT1_A(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GPA_INT0_A_shift                                                    (1)
#define UMSK_ISR_GPA_INT0_A_mask                                                     (0x00000002)
#define UMSK_ISR_GPA_INT0_A(data)                                                    (0x00000002&((data)<<1))
#define UMSK_ISR_GPA_INT0_A_src(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GPA_get_INT0_A(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GPA_write_data_shift                                                (0)
#define UMSK_ISR_GPA_write_data_mask                                                 (0x00000001)
#define UMSK_ISR_GPA_write_data(data)                                                (0x00000001&((data)<<0))
#define UMSK_ISR_GPA_write_data_src(data)                                            ((0x00000001&(data))>>0)
#define UMSK_ISR_GPA_get_write_data(data)                                            ((0x00000001&(data))>>0)


#define UMSK_ISR_GPDA                                                                0x1800700C
#define UMSK_ISR_GPDA_reg_addr                                                       "0x1800700C"
#define UMSK_ISR_GPDA_reg                                                            0x1800700C
#define set_UMSK_ISR_GPDA_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GPDA_reg)=data)
#define get_UMSK_ISR_GPDA_reg   (*((volatile unsigned int*) UMSK_ISR_GPDA_reg))
#define UMSK_ISR_GPDA_inst_adr                                                       "0x0003"
#define UMSK_ISR_GPDA_inst                                                           0x0003
#define UMSK_ISR_GPDA_INT20_DA_shift                                                 (21)
#define UMSK_ISR_GPDA_INT20_DA_mask                                                  (0x00200000)
#define UMSK_ISR_GPDA_INT20_DA(data)                                                 (0x00200000&((data)<<21))
#define UMSK_ISR_GPDA_INT20_DA_src(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_GPDA_get_INT20_DA(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_GPDA_INT19_DA_shift                                                 (20)
#define UMSK_ISR_GPDA_INT19_DA_mask                                                  (0x00100000)
#define UMSK_ISR_GPDA_INT19_DA(data)                                                 (0x00100000&((data)<<20))
#define UMSK_ISR_GPDA_INT19_DA_src(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_GPDA_get_INT19_DA(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_GPDA_INT18_DA_shift                                                 (19)
#define UMSK_ISR_GPDA_INT18_DA_mask                                                  (0x00080000)
#define UMSK_ISR_GPDA_INT18_DA(data)                                                 (0x00080000&((data)<<19))
#define UMSK_ISR_GPDA_INT18_DA_src(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_GPDA_get_INT18_DA(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_GPDA_INT17_DA_shift                                                 (18)
#define UMSK_ISR_GPDA_INT17_DA_mask                                                  (0x00040000)
#define UMSK_ISR_GPDA_INT17_DA(data)                                                 (0x00040000&((data)<<18))
#define UMSK_ISR_GPDA_INT17_DA_src(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_GPDA_get_INT17_DA(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_GPDA_INT16_DA_shift                                                 (17)
#define UMSK_ISR_GPDA_INT16_DA_mask                                                  (0x00020000)
#define UMSK_ISR_GPDA_INT16_DA(data)                                                 (0x00020000&((data)<<17))
#define UMSK_ISR_GPDA_INT16_DA_src(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_GPDA_get_INT16_DA(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_GPDA_INT15_DA_shift                                                 (16)
#define UMSK_ISR_GPDA_INT15_DA_mask                                                  (0x00010000)
#define UMSK_ISR_GPDA_INT15_DA(data)                                                 (0x00010000&((data)<<16))
#define UMSK_ISR_GPDA_INT15_DA_src(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_GPDA_get_INT15_DA(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_GPDA_INT14_DA_shift                                                 (15)
#define UMSK_ISR_GPDA_INT14_DA_mask                                                  (0x00008000)
#define UMSK_ISR_GPDA_INT14_DA(data)                                                 (0x00008000&((data)<<15))
#define UMSK_ISR_GPDA_INT14_DA_src(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_GPDA_get_INT14_DA(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_GPDA_INT13_DA_shift                                                 (14)
#define UMSK_ISR_GPDA_INT13_DA_mask                                                  (0x00004000)
#define UMSK_ISR_GPDA_INT13_DA(data)                                                 (0x00004000&((data)<<14))
#define UMSK_ISR_GPDA_INT13_DA_src(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_GPDA_get_INT13_DA(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_GPDA_INT12_DA_shift                                                 (13)
#define UMSK_ISR_GPDA_INT12_DA_mask                                                  (0x00002000)
#define UMSK_ISR_GPDA_INT12_DA(data)                                                 (0x00002000&((data)<<13))
#define UMSK_ISR_GPDA_INT12_DA_src(data)                                             ((0x00002000&(data))>>13)
#define UMSK_ISR_GPDA_get_INT12_DA(data)                                             ((0x00002000&(data))>>13)
#define UMSK_ISR_GPDA_INT11_DA_shift                                                 (12)
#define UMSK_ISR_GPDA_INT11_DA_mask                                                  (0x00001000)
#define UMSK_ISR_GPDA_INT11_DA(data)                                                 (0x00001000&((data)<<12))
#define UMSK_ISR_GPDA_INT11_DA_src(data)                                             ((0x00001000&(data))>>12)
#define UMSK_ISR_GPDA_get_INT11_DA(data)                                             ((0x00001000&(data))>>12)
#define UMSK_ISR_GPDA_INT10_DA_shift                                                 (11)
#define UMSK_ISR_GPDA_INT10_DA_mask                                                  (0x00000800)
#define UMSK_ISR_GPDA_INT10_DA(data)                                                 (0x00000800&((data)<<11))
#define UMSK_ISR_GPDA_INT10_DA_src(data)                                             ((0x00000800&(data))>>11)
#define UMSK_ISR_GPDA_get_INT10_DA(data)                                             ((0x00000800&(data))>>11)
#define UMSK_ISR_GPDA_INT9_DA_shift                                                  (10)
#define UMSK_ISR_GPDA_INT9_DA_mask                                                   (0x00000400)
#define UMSK_ISR_GPDA_INT9_DA(data)                                                  (0x00000400&((data)<<10))
#define UMSK_ISR_GPDA_INT9_DA_src(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_GPDA_get_INT9_DA(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_GPDA_INT8_DA_shift                                                  (9)
#define UMSK_ISR_GPDA_INT8_DA_mask                                                   (0x00000200)
#define UMSK_ISR_GPDA_INT8_DA(data)                                                  (0x00000200&((data)<<9))
#define UMSK_ISR_GPDA_INT8_DA_src(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_GPDA_get_INT8_DA(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_GPDA_INT7_DA_shift                                                  (8)
#define UMSK_ISR_GPDA_INT7_DA_mask                                                   (0x00000100)
#define UMSK_ISR_GPDA_INT7_DA(data)                                                  (0x00000100&((data)<<8))
#define UMSK_ISR_GPDA_INT7_DA_src(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_GPDA_get_INT7_DA(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_GPDA_INT6_DA_shift                                                  (7)
#define UMSK_ISR_GPDA_INT6_DA_mask                                                   (0x00000080)
#define UMSK_ISR_GPDA_INT6_DA(data)                                                  (0x00000080&((data)<<7))
#define UMSK_ISR_GPDA_INT6_DA_src(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_GPDA_get_INT6_DA(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_GPDA_INT5_DA_shift                                                  (6)
#define UMSK_ISR_GPDA_INT5_DA_mask                                                   (0x00000040)
#define UMSK_ISR_GPDA_INT5_DA(data)                                                  (0x00000040&((data)<<6))
#define UMSK_ISR_GPDA_INT5_DA_src(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_GPDA_get_INT5_DA(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_GPDA_INT4_DA_shift                                                  (5)
#define UMSK_ISR_GPDA_INT4_DA_mask                                                   (0x00000020)
#define UMSK_ISR_GPDA_INT4_DA(data)                                                  (0x00000020&((data)<<5))
#define UMSK_ISR_GPDA_INT4_DA_src(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_GPDA_get_INT4_DA(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_GPDA_INT3_DA_shift                                                  (4)
#define UMSK_ISR_GPDA_INT3_DA_mask                                                   (0x00000010)
#define UMSK_ISR_GPDA_INT3_DA(data)                                                  (0x00000010&((data)<<4))
#define UMSK_ISR_GPDA_INT3_DA_src(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_GPDA_get_INT3_DA(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_GPDA_INT2_DA_shift                                                  (3)
#define UMSK_ISR_GPDA_INT2_DA_mask                                                   (0x00000008)
#define UMSK_ISR_GPDA_INT2_DA(data)                                                  (0x00000008&((data)<<3))
#define UMSK_ISR_GPDA_INT2_DA_src(data)                                              ((0x00000008&(data))>>3)
#define UMSK_ISR_GPDA_get_INT2_DA(data)                                              ((0x00000008&(data))>>3)
#define UMSK_ISR_GPDA_INT1_DA_shift                                                  (2)
#define UMSK_ISR_GPDA_INT1_DA_mask                                                   (0x00000004)
#define UMSK_ISR_GPDA_INT1_DA(data)                                                  (0x00000004&((data)<<2))
#define UMSK_ISR_GPDA_INT1_DA_src(data)                                              ((0x00000004&(data))>>2)
#define UMSK_ISR_GPDA_get_INT1_DA(data)                                              ((0x00000004&(data))>>2)
#define UMSK_ISR_GPDA_INT0_DA_shift                                                  (1)
#define UMSK_ISR_GPDA_INT0_DA_mask                                                   (0x00000002)
#define UMSK_ISR_GPDA_INT0_DA(data)                                                  (0x00000002&((data)<<1))
#define UMSK_ISR_GPDA_INT0_DA_src(data)                                              ((0x00000002&(data))>>1)
#define UMSK_ISR_GPDA_get_INT0_DA(data)                                              ((0x00000002&(data))>>1)
#define UMSK_ISR_GPDA_write_data_shift                                               (0)
#define UMSK_ISR_GPDA_write_data_mask                                                (0x00000001)
#define UMSK_ISR_GPDA_write_data(data)                                               (0x00000001&((data)<<0))
#define UMSK_ISR_GPDA_write_data_src(data)                                           ((0x00000001&(data))>>0)
#define UMSK_ISR_GPDA_get_write_data(data)                                           ((0x00000001&(data))>>0)


#define UMSK_ISR_KPADAH                                                              0x18007010
#define UMSK_ISR_KPADAH_reg_addr                                                     "0x18007010"
#define UMSK_ISR_KPADAH_reg                                                          0x18007010
#define set_UMSK_ISR_KPADAH_reg(data)   (*((volatile unsigned int*) UMSK_ISR_KPADAH_reg)=data)
#define get_UMSK_ISR_KPADAH_reg   (*((volatile unsigned int*) UMSK_ISR_KPADAH_reg))
#define UMSK_ISR_KPADAH_inst_adr                                                     "0x0004"
#define UMSK_ISR_KPADAH_inst                                                         0x0004
#define UMSK_ISR_KPADAH_INT47_shift                                                  (23)
#define UMSK_ISR_KPADAH_INT47_mask                                                   (0x00800000)
#define UMSK_ISR_KPADAH_INT47(data)                                                  (0x00800000&((data)<<23))
#define UMSK_ISR_KPADAH_INT47_src(data)                                              ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADAH_get_INT47(data)                                              ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADAH_INT46_shift                                                  (22)
#define UMSK_ISR_KPADAH_INT46_mask                                                   (0x00400000)
#define UMSK_ISR_KPADAH_INT46(data)                                                  (0x00400000&((data)<<22))
#define UMSK_ISR_KPADAH_INT46_src(data)                                              ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADAH_get_INT46(data)                                              ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADAH_INT45_shift                                                  (21)
#define UMSK_ISR_KPADAH_INT45_mask                                                   (0x00200000)
#define UMSK_ISR_KPADAH_INT45(data)                                                  (0x00200000&((data)<<21))
#define UMSK_ISR_KPADAH_INT45_src(data)                                              ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADAH_get_INT45(data)                                              ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADAH_INT44_shift                                                  (20)
#define UMSK_ISR_KPADAH_INT44_mask                                                   (0x00100000)
#define UMSK_ISR_KPADAH_INT44(data)                                                  (0x00100000&((data)<<20))
#define UMSK_ISR_KPADAH_INT44_src(data)                                              ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADAH_get_INT44(data)                                              ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADAH_INT43_shift                                                  (19)
#define UMSK_ISR_KPADAH_INT43_mask                                                   (0x00080000)
#define UMSK_ISR_KPADAH_INT43(data)                                                  (0x00080000&((data)<<19))
#define UMSK_ISR_KPADAH_INT43_src(data)                                              ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADAH_get_INT43(data)                                              ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADAH_INT42_shift                                                  (18)
#define UMSK_ISR_KPADAH_INT42_mask                                                   (0x00040000)
#define UMSK_ISR_KPADAH_INT42(data)                                                  (0x00040000&((data)<<18))
#define UMSK_ISR_KPADAH_INT42_src(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADAH_get_INT42(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADAH_INT41_shift                                                  (17)
#define UMSK_ISR_KPADAH_INT41_mask                                                   (0x00020000)
#define UMSK_ISR_KPADAH_INT41(data)                                                  (0x00020000&((data)<<17))
#define UMSK_ISR_KPADAH_INT41_src(data)                                              ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADAH_get_INT41(data)                                              ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADAH_INT40_shift                                                  (16)
#define UMSK_ISR_KPADAH_INT40_mask                                                   (0x00010000)
#define UMSK_ISR_KPADAH_INT40(data)                                                  (0x00010000&((data)<<16))
#define UMSK_ISR_KPADAH_INT40_src(data)                                              ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADAH_get_INT40(data)                                              ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADAH_INT39_shift                                                  (15)
#define UMSK_ISR_KPADAH_INT39_mask                                                   (0x00008000)
#define UMSK_ISR_KPADAH_INT39(data)                                                  (0x00008000&((data)<<15))
#define UMSK_ISR_KPADAH_INT39_src(data)                                              ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADAH_get_INT39(data)                                              ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADAH_INT38_shift                                                  (14)
#define UMSK_ISR_KPADAH_INT38_mask                                                   (0x00004000)
#define UMSK_ISR_KPADAH_INT38(data)                                                  (0x00004000&((data)<<14))
#define UMSK_ISR_KPADAH_INT38_src(data)                                              ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADAH_get_INT38(data)                                              ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADAH_INT37_shift                                                  (13)
#define UMSK_ISR_KPADAH_INT37_mask                                                   (0x00002000)
#define UMSK_ISR_KPADAH_INT37(data)                                                  (0x00002000&((data)<<13))
#define UMSK_ISR_KPADAH_INT37_src(data)                                              ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADAH_get_INT37(data)                                              ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADAH_INT36_shift                                                  (12)
#define UMSK_ISR_KPADAH_INT36_mask                                                   (0x00001000)
#define UMSK_ISR_KPADAH_INT36(data)                                                  (0x00001000&((data)<<12))
#define UMSK_ISR_KPADAH_INT36_src(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADAH_get_INT36(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADAH_INT35_shift                                                  (11)
#define UMSK_ISR_KPADAH_INT35_mask                                                   (0x00000800)
#define UMSK_ISR_KPADAH_INT35(data)                                                  (0x00000800&((data)<<11))
#define UMSK_ISR_KPADAH_INT35_src(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADAH_get_INT35(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADAH_INT34_shift                                                  (10)
#define UMSK_ISR_KPADAH_INT34_mask                                                   (0x00000400)
#define UMSK_ISR_KPADAH_INT34(data)                                                  (0x00000400&((data)<<10))
#define UMSK_ISR_KPADAH_INT34_src(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADAH_get_INT34(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADAH_INT33_shift                                                  (9)
#define UMSK_ISR_KPADAH_INT33_mask                                                   (0x00000200)
#define UMSK_ISR_KPADAH_INT33(data)                                                  (0x00000200&((data)<<9))
#define UMSK_ISR_KPADAH_INT33_src(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADAH_get_INT33(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADAH_INT32_shift                                                  (8)
#define UMSK_ISR_KPADAH_INT32_mask                                                   (0x00000100)
#define UMSK_ISR_KPADAH_INT32(data)                                                  (0x00000100&((data)<<8))
#define UMSK_ISR_KPADAH_INT32_src(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADAH_get_INT32(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADAH_INT31_shift                                                  (7)
#define UMSK_ISR_KPADAH_INT31_mask                                                   (0x00000080)
#define UMSK_ISR_KPADAH_INT31(data)                                                  (0x00000080&((data)<<7))
#define UMSK_ISR_KPADAH_INT31_src(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADAH_get_INT31(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADAH_INT30_shift                                                  (6)
#define UMSK_ISR_KPADAH_INT30_mask                                                   (0x00000040)
#define UMSK_ISR_KPADAH_INT30(data)                                                  (0x00000040&((data)<<6))
#define UMSK_ISR_KPADAH_INT30_src(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADAH_get_INT30(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADAH_INT29_shift                                                  (5)
#define UMSK_ISR_KPADAH_INT29_mask                                                   (0x00000020)
#define UMSK_ISR_KPADAH_INT29(data)                                                  (0x00000020&((data)<<5))
#define UMSK_ISR_KPADAH_INT29_src(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADAH_get_INT29(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADAH_INT28_shift                                                  (4)
#define UMSK_ISR_KPADAH_INT28_mask                                                   (0x00000010)
#define UMSK_ISR_KPADAH_INT28(data)                                                  (0x00000010&((data)<<4))
#define UMSK_ISR_KPADAH_INT28_src(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADAH_get_INT28(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADAH_write_data_shift                                             (0)
#define UMSK_ISR_KPADAH_write_data_mask                                              (0x00000001)
#define UMSK_ISR_KPADAH_write_data(data)                                             (0x00000001&((data)<<0))
#define UMSK_ISR_KPADAH_write_data_src(data)                                         ((0x00000001&(data))>>0)
#define UMSK_ISR_KPADAH_get_write_data(data)                                         ((0x00000001&(data))>>0)


#define UMSK_ISR_KPADAL                                                              0x18007014
#define UMSK_ISR_KPADAL_reg_addr                                                     "0x18007014"
#define UMSK_ISR_KPADAL_reg                                                          0x18007014
#define set_UMSK_ISR_KPADAL_reg(data)   (*((volatile unsigned int*) UMSK_ISR_KPADAL_reg)=data)
#define get_UMSK_ISR_KPADAL_reg   (*((volatile unsigned int*) UMSK_ISR_KPADAL_reg))
#define UMSK_ISR_KPADAL_inst_adr                                                     "0x0005"
#define UMSK_ISR_KPADAL_inst                                                         0x0005
#define UMSK_ISR_KPADAL_INT27_shift                                                  (31)
#define UMSK_ISR_KPADAL_INT27_mask                                                   (0x80000000)
#define UMSK_ISR_KPADAL_INT27(data)                                                  (0x80000000&((data)<<31))
#define UMSK_ISR_KPADAL_INT27_src(data)                                              ((0x80000000&(data))>>31)
#define UMSK_ISR_KPADAL_get_INT27(data)                                              ((0x80000000&(data))>>31)
#define UMSK_ISR_KPADAL_INT26_shift                                                  (30)
#define UMSK_ISR_KPADAL_INT26_mask                                                   (0x40000000)
#define UMSK_ISR_KPADAL_INT26(data)                                                  (0x40000000&((data)<<30))
#define UMSK_ISR_KPADAL_INT26_src(data)                                              ((0x40000000&(data))>>30)
#define UMSK_ISR_KPADAL_get_INT26(data)                                              ((0x40000000&(data))>>30)
#define UMSK_ISR_KPADAL_INT25_shift                                                  (29)
#define UMSK_ISR_KPADAL_INT25_mask                                                   (0x20000000)
#define UMSK_ISR_KPADAL_INT25(data)                                                  (0x20000000&((data)<<29))
#define UMSK_ISR_KPADAL_INT25_src(data)                                              ((0x20000000&(data))>>29)
#define UMSK_ISR_KPADAL_get_INT25(data)                                              ((0x20000000&(data))>>29)
#define UMSK_ISR_KPADAL_INT24_shift                                                  (28)
#define UMSK_ISR_KPADAL_INT24_mask                                                   (0x10000000)
#define UMSK_ISR_KPADAL_INT24(data)                                                  (0x10000000&((data)<<28))
#define UMSK_ISR_KPADAL_INT24_src(data)                                              ((0x10000000&(data))>>28)
#define UMSK_ISR_KPADAL_get_INT24(data)                                              ((0x10000000&(data))>>28)
#define UMSK_ISR_KPADAL_INT23_shift                                                  (27)
#define UMSK_ISR_KPADAL_INT23_mask                                                   (0x08000000)
#define UMSK_ISR_KPADAL_INT23(data)                                                  (0x08000000&((data)<<27))
#define UMSK_ISR_KPADAL_INT23_src(data)                                              ((0x08000000&(data))>>27)
#define UMSK_ISR_KPADAL_get_INT23(data)                                              ((0x08000000&(data))>>27)
#define UMSK_ISR_KPADAL_INT22_shift                                                  (26)
#define UMSK_ISR_KPADAL_INT22_mask                                                   (0x04000000)
#define UMSK_ISR_KPADAL_INT22(data)                                                  (0x04000000&((data)<<26))
#define UMSK_ISR_KPADAL_INT22_src(data)                                              ((0x04000000&(data))>>26)
#define UMSK_ISR_KPADAL_get_INT22(data)                                              ((0x04000000&(data))>>26)
#define UMSK_ISR_KPADAL_INT21_shift                                                  (25)
#define UMSK_ISR_KPADAL_INT21_mask                                                   (0x02000000)
#define UMSK_ISR_KPADAL_INT21(data)                                                  (0x02000000&((data)<<25))
#define UMSK_ISR_KPADAL_INT21_src(data)                                              ((0x02000000&(data))>>25)
#define UMSK_ISR_KPADAL_get_INT21(data)                                              ((0x02000000&(data))>>25)
#define UMSK_ISR_KPADAL_INT20_shift                                                  (24)
#define UMSK_ISR_KPADAL_INT20_mask                                                   (0x01000000)
#define UMSK_ISR_KPADAL_INT20(data)                                                  (0x01000000&((data)<<24))
#define UMSK_ISR_KPADAL_INT20_src(data)                                              ((0x01000000&(data))>>24)
#define UMSK_ISR_KPADAL_get_INT20(data)                                              ((0x01000000&(data))>>24)
#define UMSK_ISR_KPADAL_INT19_shift                                                  (23)
#define UMSK_ISR_KPADAL_INT19_mask                                                   (0x00800000)
#define UMSK_ISR_KPADAL_INT19(data)                                                  (0x00800000&((data)<<23))
#define UMSK_ISR_KPADAL_INT19_src(data)                                              ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADAL_get_INT19(data)                                              ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADAL_INT18_shift                                                  (22)
#define UMSK_ISR_KPADAL_INT18_mask                                                   (0x00400000)
#define UMSK_ISR_KPADAL_INT18(data)                                                  (0x00400000&((data)<<22))
#define UMSK_ISR_KPADAL_INT18_src(data)                                              ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADAL_get_INT18(data)                                              ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADAL_INT17_shift                                                  (21)
#define UMSK_ISR_KPADAL_INT17_mask                                                   (0x00200000)
#define UMSK_ISR_KPADAL_INT17(data)                                                  (0x00200000&((data)<<21))
#define UMSK_ISR_KPADAL_INT17_src(data)                                              ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADAL_get_INT17(data)                                              ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADAL_INT16_shift                                                  (20)
#define UMSK_ISR_KPADAL_INT16_mask                                                   (0x00100000)
#define UMSK_ISR_KPADAL_INT16(data)                                                  (0x00100000&((data)<<20))
#define UMSK_ISR_KPADAL_INT16_src(data)                                              ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADAL_get_INT16(data)                                              ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADAL_INT15_shift                                                  (19)
#define UMSK_ISR_KPADAL_INT15_mask                                                   (0x00080000)
#define UMSK_ISR_KPADAL_INT15(data)                                                  (0x00080000&((data)<<19))
#define UMSK_ISR_KPADAL_INT15_src(data)                                              ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADAL_get_INT15(data)                                              ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADAL_INT14_shift                                                  (18)
#define UMSK_ISR_KPADAL_INT14_mask                                                   (0x00040000)
#define UMSK_ISR_KPADAL_INT14(data)                                                  (0x00040000&((data)<<18))
#define UMSK_ISR_KPADAL_INT14_src(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADAL_get_INT14(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADAL_INT13_shift                                                  (17)
#define UMSK_ISR_KPADAL_INT13_mask                                                   (0x00020000)
#define UMSK_ISR_KPADAL_INT13(data)                                                  (0x00020000&((data)<<17))
#define UMSK_ISR_KPADAL_INT13_src(data)                                              ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADAL_get_INT13(data)                                              ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADAL_INT12_shift                                                  (16)
#define UMSK_ISR_KPADAL_INT12_mask                                                   (0x00010000)
#define UMSK_ISR_KPADAL_INT12(data)                                                  (0x00010000&((data)<<16))
#define UMSK_ISR_KPADAL_INT12_src(data)                                              ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADAL_get_INT12(data)                                              ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADAL_INT11_shift                                                  (15)
#define UMSK_ISR_KPADAL_INT11_mask                                                   (0x00008000)
#define UMSK_ISR_KPADAL_INT11(data)                                                  (0x00008000&((data)<<15))
#define UMSK_ISR_KPADAL_INT11_src(data)                                              ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADAL_get_INT11(data)                                              ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADAL_INT10_shift                                                  (14)
#define UMSK_ISR_KPADAL_INT10_mask                                                   (0x00004000)
#define UMSK_ISR_KPADAL_INT10(data)                                                  (0x00004000&((data)<<14))
#define UMSK_ISR_KPADAL_INT10_src(data)                                              ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADAL_get_INT10(data)                                              ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADAL_INT9_shift                                                   (13)
#define UMSK_ISR_KPADAL_INT9_mask                                                    (0x00002000)
#define UMSK_ISR_KPADAL_INT9(data)                                                   (0x00002000&((data)<<13))
#define UMSK_ISR_KPADAL_INT9_src(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADAL_get_INT9(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADAL_INT8_shift                                                   (12)
#define UMSK_ISR_KPADAL_INT8_mask                                                    (0x00001000)
#define UMSK_ISR_KPADAL_INT8(data)                                                   (0x00001000&((data)<<12))
#define UMSK_ISR_KPADAL_INT8_src(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADAL_get_INT8(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADAL_INT7_shift                                                   (11)
#define UMSK_ISR_KPADAL_INT7_mask                                                    (0x00000800)
#define UMSK_ISR_KPADAL_INT7(data)                                                   (0x00000800&((data)<<11))
#define UMSK_ISR_KPADAL_INT7_src(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADAL_get_INT7(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADAL_INT6_shift                                                   (10)
#define UMSK_ISR_KPADAL_INT6_mask                                                    (0x00000400)
#define UMSK_ISR_KPADAL_INT6(data)                                                   (0x00000400&((data)<<10))
#define UMSK_ISR_KPADAL_INT6_src(data)                                               ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADAL_get_INT6(data)                                               ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADAL_INT5_shift                                                   (9)
#define UMSK_ISR_KPADAL_INT5_mask                                                    (0x00000200)
#define UMSK_ISR_KPADAL_INT5(data)                                                   (0x00000200&((data)<<9))
#define UMSK_ISR_KPADAL_INT5_src(data)                                               ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADAL_get_INT5(data)                                               ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADAL_INT4_shift                                                   (8)
#define UMSK_ISR_KPADAL_INT4_mask                                                    (0x00000100)
#define UMSK_ISR_KPADAL_INT4(data)                                                   (0x00000100&((data)<<8))
#define UMSK_ISR_KPADAL_INT4_src(data)                                               ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADAL_get_INT4(data)                                               ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADAL_INT3_shift                                                   (7)
#define UMSK_ISR_KPADAL_INT3_mask                                                    (0x00000080)
#define UMSK_ISR_KPADAL_INT3(data)                                                   (0x00000080&((data)<<7))
#define UMSK_ISR_KPADAL_INT3_src(data)                                               ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADAL_get_INT3(data)                                               ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADAL_INT2_shift                                                   (6)
#define UMSK_ISR_KPADAL_INT2_mask                                                    (0x00000040)
#define UMSK_ISR_KPADAL_INT2(data)                                                   (0x00000040&((data)<<6))
#define UMSK_ISR_KPADAL_INT2_src(data)                                               ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADAL_get_INT2(data)                                               ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADAL_INT1_shift                                                   (5)
#define UMSK_ISR_KPADAL_INT1_mask                                                    (0x00000020)
#define UMSK_ISR_KPADAL_INT1(data)                                                   (0x00000020&((data)<<5))
#define UMSK_ISR_KPADAL_INT1_src(data)                                               ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADAL_get_INT1(data)                                               ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADAL_INT0_shift                                                   (4)
#define UMSK_ISR_KPADAL_INT0_mask                                                    (0x00000010)
#define UMSK_ISR_KPADAL_INT0(data)                                                   (0x00000010&((data)<<4))
#define UMSK_ISR_KPADAL_INT0_src(data)                                               ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADAL_get_INT0(data)                                               ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADAL_write_data_shift                                             (0)
#define UMSK_ISR_KPADAL_write_data_mask                                              (0x00000001)
#define UMSK_ISR_KPADAL_write_data(data)                                             (0x00000001&((data)<<0))
#define UMSK_ISR_KPADAL_write_data_src(data)                                         ((0x00000001&(data))>>0)
#define UMSK_ISR_KPADAL_get_write_data(data)                                         ((0x00000001&(data))>>0)


#define UMSK_ISR_KPADDAH                                                             0x18007018
#define UMSK_ISR_KPADDAH_reg_addr                                                    "0x18007018"
#define UMSK_ISR_KPADDAH_reg                                                         0x18007018
#define set_UMSK_ISR_KPADDAH_reg(data)   (*((volatile unsigned int*) UMSK_ISR_KPADDAH_reg)=data)
#define get_UMSK_ISR_KPADDAH_reg   (*((volatile unsigned int*) UMSK_ISR_KPADDAH_reg))
#define UMSK_ISR_KPADDAH_inst_adr                                                    "0x0006"
#define UMSK_ISR_KPADDAH_inst                                                        0x0006
#define UMSK_ISR_KPADDAH_INT47_shift                                                 (23)
#define UMSK_ISR_KPADDAH_INT47_mask                                                  (0x00800000)
#define UMSK_ISR_KPADDAH_INT47(data)                                                 (0x00800000&((data)<<23))
#define UMSK_ISR_KPADDAH_INT47_src(data)                                             ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADDAH_get_INT47(data)                                             ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADDAH_INT46_shift                                                 (22)
#define UMSK_ISR_KPADDAH_INT46_mask                                                  (0x00400000)
#define UMSK_ISR_KPADDAH_INT46(data)                                                 (0x00400000&((data)<<22))
#define UMSK_ISR_KPADDAH_INT46_src(data)                                             ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADDAH_get_INT46(data)                                             ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADDAH_INT45_shift                                                 (21)
#define UMSK_ISR_KPADDAH_INT45_mask                                                  (0x00200000)
#define UMSK_ISR_KPADDAH_INT45(data)                                                 (0x00200000&((data)<<21))
#define UMSK_ISR_KPADDAH_INT45_src(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADDAH_get_INT45(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADDAH_INT44_shift                                                 (20)
#define UMSK_ISR_KPADDAH_INT44_mask                                                  (0x00100000)
#define UMSK_ISR_KPADDAH_INT44(data)                                                 (0x00100000&((data)<<20))
#define UMSK_ISR_KPADDAH_INT44_src(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADDAH_get_INT44(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADDAH_INT43_shift                                                 (19)
#define UMSK_ISR_KPADDAH_INT43_mask                                                  (0x00080000)
#define UMSK_ISR_KPADDAH_INT43(data)                                                 (0x00080000&((data)<<19))
#define UMSK_ISR_KPADDAH_INT43_src(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADDAH_get_INT43(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADDAH_INT42_shift                                                 (18)
#define UMSK_ISR_KPADDAH_INT42_mask                                                  (0x00040000)
#define UMSK_ISR_KPADDAH_INT42(data)                                                 (0x00040000&((data)<<18))
#define UMSK_ISR_KPADDAH_INT42_src(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADDAH_get_INT42(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADDAH_INT41_shift                                                 (17)
#define UMSK_ISR_KPADDAH_INT41_mask                                                  (0x00020000)
#define UMSK_ISR_KPADDAH_INT41(data)                                                 (0x00020000&((data)<<17))
#define UMSK_ISR_KPADDAH_INT41_src(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADDAH_get_INT41(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADDAH_INT40_shift                                                 (16)
#define UMSK_ISR_KPADDAH_INT40_mask                                                  (0x00010000)
#define UMSK_ISR_KPADDAH_INT40(data)                                                 (0x00010000&((data)<<16))
#define UMSK_ISR_KPADDAH_INT40_src(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADDAH_get_INT40(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADDAH_INT39_shift                                                 (15)
#define UMSK_ISR_KPADDAH_INT39_mask                                                  (0x00008000)
#define UMSK_ISR_KPADDAH_INT39(data)                                                 (0x00008000&((data)<<15))
#define UMSK_ISR_KPADDAH_INT39_src(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADDAH_get_INT39(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADDAH_INT38_shift                                                 (14)
#define UMSK_ISR_KPADDAH_INT38_mask                                                  (0x00004000)
#define UMSK_ISR_KPADDAH_INT38(data)                                                 (0x00004000&((data)<<14))
#define UMSK_ISR_KPADDAH_INT38_src(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADDAH_get_INT38(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADDAH_INT37_shift                                                 (13)
#define UMSK_ISR_KPADDAH_INT37_mask                                                  (0x00002000)
#define UMSK_ISR_KPADDAH_INT37(data)                                                 (0x00002000&((data)<<13))
#define UMSK_ISR_KPADDAH_INT37_src(data)                                             ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADDAH_get_INT37(data)                                             ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADDAH_INT36_shift                                                 (12)
#define UMSK_ISR_KPADDAH_INT36_mask                                                  (0x00001000)
#define UMSK_ISR_KPADDAH_INT36(data)                                                 (0x00001000&((data)<<12))
#define UMSK_ISR_KPADDAH_INT36_src(data)                                             ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADDAH_get_INT36(data)                                             ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADDAH_INT35_shift                                                 (11)
#define UMSK_ISR_KPADDAH_INT35_mask                                                  (0x00000800)
#define UMSK_ISR_KPADDAH_INT35(data)                                                 (0x00000800&((data)<<11))
#define UMSK_ISR_KPADDAH_INT35_src(data)                                             ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADDAH_get_INT35(data)                                             ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADDAH_INT34_shift                                                 (10)
#define UMSK_ISR_KPADDAH_INT34_mask                                                  (0x00000400)
#define UMSK_ISR_KPADDAH_INT34(data)                                                 (0x00000400&((data)<<10))
#define UMSK_ISR_KPADDAH_INT34_src(data)                                             ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADDAH_get_INT34(data)                                             ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADDAH_INT33_shift                                                 (9)
#define UMSK_ISR_KPADDAH_INT33_mask                                                  (0x00000200)
#define UMSK_ISR_KPADDAH_INT33(data)                                                 (0x00000200&((data)<<9))
#define UMSK_ISR_KPADDAH_INT33_src(data)                                             ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADDAH_get_INT33(data)                                             ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADDAH_INT32_shift                                                 (8)
#define UMSK_ISR_KPADDAH_INT32_mask                                                  (0x00000100)
#define UMSK_ISR_KPADDAH_INT32(data)                                                 (0x00000100&((data)<<8))
#define UMSK_ISR_KPADDAH_INT32_src(data)                                             ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADDAH_get_INT32(data)                                             ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADDAH_INT31_shift                                                 (7)
#define UMSK_ISR_KPADDAH_INT31_mask                                                  (0x00000080)
#define UMSK_ISR_KPADDAH_INT31(data)                                                 (0x00000080&((data)<<7))
#define UMSK_ISR_KPADDAH_INT31_src(data)                                             ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADDAH_get_INT31(data)                                             ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADDAH_INT30_shift                                                 (6)
#define UMSK_ISR_KPADDAH_INT30_mask                                                  (0x00000040)
#define UMSK_ISR_KPADDAH_INT30(data)                                                 (0x00000040&((data)<<6))
#define UMSK_ISR_KPADDAH_INT30_src(data)                                             ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADDAH_get_INT30(data)                                             ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADDAH_INT29_shift                                                 (5)
#define UMSK_ISR_KPADDAH_INT29_mask                                                  (0x00000020)
#define UMSK_ISR_KPADDAH_INT29(data)                                                 (0x00000020&((data)<<5))
#define UMSK_ISR_KPADDAH_INT29_src(data)                                             ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADDAH_get_INT29(data)                                             ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADDAH_INT28_shift                                                 (4)
#define UMSK_ISR_KPADDAH_INT28_mask                                                  (0x00000010)
#define UMSK_ISR_KPADDAH_INT28(data)                                                 (0x00000010&((data)<<4))
#define UMSK_ISR_KPADDAH_INT28_src(data)                                             ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADDAH_get_INT28(data)                                             ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADDAH_write_data_shift                                            (0)
#define UMSK_ISR_KPADDAH_write_data_mask                                             (0x00000001)
#define UMSK_ISR_KPADDAH_write_data(data)                                            (0x00000001&((data)<<0))
#define UMSK_ISR_KPADDAH_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define UMSK_ISR_KPADDAH_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define UMSK_ISR_KPADDAL                                                             0x1800701C
#define UMSK_ISR_KPADDAL_reg_addr                                                    "0x1800701C"
#define UMSK_ISR_KPADDAL_reg                                                         0x1800701C
#define set_UMSK_ISR_KPADDAL_reg(data)   (*((volatile unsigned int*) UMSK_ISR_KPADDAL_reg)=data)
#define get_UMSK_ISR_KPADDAL_reg   (*((volatile unsigned int*) UMSK_ISR_KPADDAL_reg))
#define UMSK_ISR_KPADDAL_inst_adr                                                    "0x0007"
#define UMSK_ISR_KPADDAL_inst                                                        0x0007
#define UMSK_ISR_KPADDAL_INT27_shift                                                 (31)
#define UMSK_ISR_KPADDAL_INT27_mask                                                  (0x80000000)
#define UMSK_ISR_KPADDAL_INT27(data)                                                 (0x80000000&((data)<<31))
#define UMSK_ISR_KPADDAL_INT27_src(data)                                             ((0x80000000&(data))>>31)
#define UMSK_ISR_KPADDAL_get_INT27(data)                                             ((0x80000000&(data))>>31)
#define UMSK_ISR_KPADDAL_INT26_shift                                                 (30)
#define UMSK_ISR_KPADDAL_INT26_mask                                                  (0x40000000)
#define UMSK_ISR_KPADDAL_INT26(data)                                                 (0x40000000&((data)<<30))
#define UMSK_ISR_KPADDAL_INT26_src(data)                                             ((0x40000000&(data))>>30)
#define UMSK_ISR_KPADDAL_get_INT26(data)                                             ((0x40000000&(data))>>30)
#define UMSK_ISR_KPADDAL_INT25_shift                                                 (29)
#define UMSK_ISR_KPADDAL_INT25_mask                                                  (0x20000000)
#define UMSK_ISR_KPADDAL_INT25(data)                                                 (0x20000000&((data)<<29))
#define UMSK_ISR_KPADDAL_INT25_src(data)                                             ((0x20000000&(data))>>29)
#define UMSK_ISR_KPADDAL_get_INT25(data)                                             ((0x20000000&(data))>>29)
#define UMSK_ISR_KPADDAL_INT24_shift                                                 (28)
#define UMSK_ISR_KPADDAL_INT24_mask                                                  (0x10000000)
#define UMSK_ISR_KPADDAL_INT24(data)                                                 (0x10000000&((data)<<28))
#define UMSK_ISR_KPADDAL_INT24_src(data)                                             ((0x10000000&(data))>>28)
#define UMSK_ISR_KPADDAL_get_INT24(data)                                             ((0x10000000&(data))>>28)
#define UMSK_ISR_KPADDAL_INT23_shift                                                 (27)
#define UMSK_ISR_KPADDAL_INT23_mask                                                  (0x08000000)
#define UMSK_ISR_KPADDAL_INT23(data)                                                 (0x08000000&((data)<<27))
#define UMSK_ISR_KPADDAL_INT23_src(data)                                             ((0x08000000&(data))>>27)
#define UMSK_ISR_KPADDAL_get_INT23(data)                                             ((0x08000000&(data))>>27)
#define UMSK_ISR_KPADDAL_INT22_shift                                                 (26)
#define UMSK_ISR_KPADDAL_INT22_mask                                                  (0x04000000)
#define UMSK_ISR_KPADDAL_INT22(data)                                                 (0x04000000&((data)<<26))
#define UMSK_ISR_KPADDAL_INT22_src(data)                                             ((0x04000000&(data))>>26)
#define UMSK_ISR_KPADDAL_get_INT22(data)                                             ((0x04000000&(data))>>26)
#define UMSK_ISR_KPADDAL_INT21_shift                                                 (25)
#define UMSK_ISR_KPADDAL_INT21_mask                                                  (0x02000000)
#define UMSK_ISR_KPADDAL_INT21(data)                                                 (0x02000000&((data)<<25))
#define UMSK_ISR_KPADDAL_INT21_src(data)                                             ((0x02000000&(data))>>25)
#define UMSK_ISR_KPADDAL_get_INT21(data)                                             ((0x02000000&(data))>>25)
#define UMSK_ISR_KPADDAL_INT20_shift                                                 (24)
#define UMSK_ISR_KPADDAL_INT20_mask                                                  (0x01000000)
#define UMSK_ISR_KPADDAL_INT20(data)                                                 (0x01000000&((data)<<24))
#define UMSK_ISR_KPADDAL_INT20_src(data)                                             ((0x01000000&(data))>>24)
#define UMSK_ISR_KPADDAL_get_INT20(data)                                             ((0x01000000&(data))>>24)
#define UMSK_ISR_KPADDAL_INT19_shift                                                 (23)
#define UMSK_ISR_KPADDAL_INT19_mask                                                  (0x00800000)
#define UMSK_ISR_KPADDAL_INT19(data)                                                 (0x00800000&((data)<<23))
#define UMSK_ISR_KPADDAL_INT19_src(data)                                             ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADDAL_get_INT19(data)                                             ((0x00800000&(data))>>23)
#define UMSK_ISR_KPADDAL_INT18_shift                                                 (22)
#define UMSK_ISR_KPADDAL_INT18_mask                                                  (0x00400000)
#define UMSK_ISR_KPADDAL_INT18(data)                                                 (0x00400000&((data)<<22))
#define UMSK_ISR_KPADDAL_INT18_src(data)                                             ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADDAL_get_INT18(data)                                             ((0x00400000&(data))>>22)
#define UMSK_ISR_KPADDAL_INT17_shift                                                 (21)
#define UMSK_ISR_KPADDAL_INT17_mask                                                  (0x00200000)
#define UMSK_ISR_KPADDAL_INT17(data)                                                 (0x00200000&((data)<<21))
#define UMSK_ISR_KPADDAL_INT17_src(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADDAL_get_INT17(data)                                             ((0x00200000&(data))>>21)
#define UMSK_ISR_KPADDAL_INT16_shift                                                 (20)
#define UMSK_ISR_KPADDAL_INT16_mask                                                  (0x00100000)
#define UMSK_ISR_KPADDAL_INT16(data)                                                 (0x00100000&((data)<<20))
#define UMSK_ISR_KPADDAL_INT16_src(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADDAL_get_INT16(data)                                             ((0x00100000&(data))>>20)
#define UMSK_ISR_KPADDAL_INT15_shift                                                 (19)
#define UMSK_ISR_KPADDAL_INT15_mask                                                  (0x00080000)
#define UMSK_ISR_KPADDAL_INT15(data)                                                 (0x00080000&((data)<<19))
#define UMSK_ISR_KPADDAL_INT15_src(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADDAL_get_INT15(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISR_KPADDAL_INT14_shift                                                 (18)
#define UMSK_ISR_KPADDAL_INT14_mask                                                  (0x00040000)
#define UMSK_ISR_KPADDAL_INT14(data)                                                 (0x00040000&((data)<<18))
#define UMSK_ISR_KPADDAL_INT14_src(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADDAL_get_INT14(data)                                             ((0x00040000&(data))>>18)
#define UMSK_ISR_KPADDAL_INT13_shift                                                 (17)
#define UMSK_ISR_KPADDAL_INT13_mask                                                  (0x00020000)
#define UMSK_ISR_KPADDAL_INT13(data)                                                 (0x00020000&((data)<<17))
#define UMSK_ISR_KPADDAL_INT13_src(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADDAL_get_INT13(data)                                             ((0x00020000&(data))>>17)
#define UMSK_ISR_KPADDAL_INT12_shift                                                 (16)
#define UMSK_ISR_KPADDAL_INT12_mask                                                  (0x00010000)
#define UMSK_ISR_KPADDAL_INT12(data)                                                 (0x00010000&((data)<<16))
#define UMSK_ISR_KPADDAL_INT12_src(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADDAL_get_INT12(data)                                             ((0x00010000&(data))>>16)
#define UMSK_ISR_KPADDAL_INT11_shift                                                 (15)
#define UMSK_ISR_KPADDAL_INT11_mask                                                  (0x00008000)
#define UMSK_ISR_KPADDAL_INT11(data)                                                 (0x00008000&((data)<<15))
#define UMSK_ISR_KPADDAL_INT11_src(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADDAL_get_INT11(data)                                             ((0x00008000&(data))>>15)
#define UMSK_ISR_KPADDAL_INT10_shift                                                 (14)
#define UMSK_ISR_KPADDAL_INT10_mask                                                  (0x00004000)
#define UMSK_ISR_KPADDAL_INT10(data)                                                 (0x00004000&((data)<<14))
#define UMSK_ISR_KPADDAL_INT10_src(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADDAL_get_INT10(data)                                             ((0x00004000&(data))>>14)
#define UMSK_ISR_KPADDAL_INT9_shift                                                  (13)
#define UMSK_ISR_KPADDAL_INT9_mask                                                   (0x00002000)
#define UMSK_ISR_KPADDAL_INT9(data)                                                  (0x00002000&((data)<<13))
#define UMSK_ISR_KPADDAL_INT9_src(data)                                              ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADDAL_get_INT9(data)                                              ((0x00002000&(data))>>13)
#define UMSK_ISR_KPADDAL_INT8_shift                                                  (12)
#define UMSK_ISR_KPADDAL_INT8_mask                                                   (0x00001000)
#define UMSK_ISR_KPADDAL_INT8(data)                                                  (0x00001000&((data)<<12))
#define UMSK_ISR_KPADDAL_INT8_src(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADDAL_get_INT8(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_KPADDAL_INT7_shift                                                  (11)
#define UMSK_ISR_KPADDAL_INT7_mask                                                   (0x00000800)
#define UMSK_ISR_KPADDAL_INT7(data)                                                  (0x00000800&((data)<<11))
#define UMSK_ISR_KPADDAL_INT7_src(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADDAL_get_INT7(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_KPADDAL_INT6_shift                                                  (10)
#define UMSK_ISR_KPADDAL_INT6_mask                                                   (0x00000400)
#define UMSK_ISR_KPADDAL_INT6(data)                                                  (0x00000400&((data)<<10))
#define UMSK_ISR_KPADDAL_INT6_src(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADDAL_get_INT6(data)                                              ((0x00000400&(data))>>10)
#define UMSK_ISR_KPADDAL_INT5_shift                                                  (9)
#define UMSK_ISR_KPADDAL_INT5_mask                                                   (0x00000200)
#define UMSK_ISR_KPADDAL_INT5(data)                                                  (0x00000200&((data)<<9))
#define UMSK_ISR_KPADDAL_INT5_src(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADDAL_get_INT5(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_KPADDAL_INT4_shift                                                  (8)
#define UMSK_ISR_KPADDAL_INT4_mask                                                   (0x00000100)
#define UMSK_ISR_KPADDAL_INT4(data)                                                  (0x00000100&((data)<<8))
#define UMSK_ISR_KPADDAL_INT4_src(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADDAL_get_INT4(data)                                              ((0x00000100&(data))>>8)
#define UMSK_ISR_KPADDAL_INT3_shift                                                  (7)
#define UMSK_ISR_KPADDAL_INT3_mask                                                   (0x00000080)
#define UMSK_ISR_KPADDAL_INT3(data)                                                  (0x00000080&((data)<<7))
#define UMSK_ISR_KPADDAL_INT3_src(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADDAL_get_INT3(data)                                              ((0x00000080&(data))>>7)
#define UMSK_ISR_KPADDAL_INT2_shift                                                  (6)
#define UMSK_ISR_KPADDAL_INT2_mask                                                   (0x00000040)
#define UMSK_ISR_KPADDAL_INT2(data)                                                  (0x00000040&((data)<<6))
#define UMSK_ISR_KPADDAL_INT2_src(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADDAL_get_INT2(data)                                              ((0x00000040&(data))>>6)
#define UMSK_ISR_KPADDAL_INT1_shift                                                  (5)
#define UMSK_ISR_KPADDAL_INT1_mask                                                   (0x00000020)
#define UMSK_ISR_KPADDAL_INT1(data)                                                  (0x00000020&((data)<<5))
#define UMSK_ISR_KPADDAL_INT1_src(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADDAL_get_INT1(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISR_KPADDAL_INT0_shift                                                  (4)
#define UMSK_ISR_KPADDAL_INT0_mask                                                   (0x00000010)
#define UMSK_ISR_KPADDAL_INT0(data)                                                  (0x00000010&((data)<<4))
#define UMSK_ISR_KPADDAL_INT0_src(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADDAL_get_INT0(data)                                              ((0x00000010&(data))>>4)
#define UMSK_ISR_KPADDAL_write_data_shift                                            (0)
#define UMSK_ISR_KPADDAL_write_data_mask                                             (0x00000001)
#define UMSK_ISR_KPADDAL_write_data(data)                                            (0x00000001&((data)<<0))
#define UMSK_ISR_KPADDAL_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define UMSK_ISR_KPADDAL_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define UMSK_ISR_SW                                                                  0x18007020
#define UMSK_ISR_SW_reg_addr                                                         "0x18007020"
#define UMSK_ISR_SW_reg                                                              0x18007020
#define set_UMSK_ISR_SW_reg(data)   (*((volatile unsigned int*) UMSK_ISR_SW_reg)=data)
#define get_UMSK_ISR_SW_reg   (*((volatile unsigned int*) UMSK_ISR_SW_reg))
#define UMSK_ISR_SW_inst_adr                                                         "0x0008"
#define UMSK_ISR_SW_inst                                                             0x0008
#define UMSK_ISR_SW_DA_INT3_shift                                                    (11)
#define UMSK_ISR_SW_DA_INT3_mask                                                     (0x00000800)
#define UMSK_ISR_SW_DA_INT3(data)                                                    (0x00000800&((data)<<11))
#define UMSK_ISR_SW_DA_INT3_src(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_SW_get_DA_INT3(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_SW_DA_INT2_shift                                                    (10)
#define UMSK_ISR_SW_DA_INT2_mask                                                     (0x00000400)
#define UMSK_ISR_SW_DA_INT2(data)                                                    (0x00000400&((data)<<10))
#define UMSK_ISR_SW_DA_INT2_src(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_SW_get_DA_INT2(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_SW_DA_INT1_shift                                                    (9)
#define UMSK_ISR_SW_DA_INT1_mask                                                     (0x00000200)
#define UMSK_ISR_SW_DA_INT1(data)                                                    (0x00000200&((data)<<9))
#define UMSK_ISR_SW_DA_INT1_src(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_SW_get_DA_INT1(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_SW_DA_INT0_shift                                                    (8)
#define UMSK_ISR_SW_DA_INT0_mask                                                     (0x00000100)
#define UMSK_ISR_SW_DA_INT0(data)                                                    (0x00000100&((data)<<8))
#define UMSK_ISR_SW_DA_INT0_src(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_SW_get_DA_INT0(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_SW_A_INT3_shift                                                     (7)
#define UMSK_ISR_SW_A_INT3_mask                                                      (0x00000080)
#define UMSK_ISR_SW_A_INT3(data)                                                     (0x00000080&((data)<<7))
#define UMSK_ISR_SW_A_INT3_src(data)                                                 ((0x00000080&(data))>>7)
#define UMSK_ISR_SW_get_A_INT3(data)                                                 ((0x00000080&(data))>>7)
#define UMSK_ISR_SW_A_INT2_shift                                                     (6)
#define UMSK_ISR_SW_A_INT2_mask                                                      (0x00000040)
#define UMSK_ISR_SW_A_INT2(data)                                                     (0x00000040&((data)<<6))
#define UMSK_ISR_SW_A_INT2_src(data)                                                 ((0x00000040&(data))>>6)
#define UMSK_ISR_SW_get_A_INT2(data)                                                 ((0x00000040&(data))>>6)
#define UMSK_ISR_SW_A_INT1_shift                                                     (5)
#define UMSK_ISR_SW_A_INT1_mask                                                      (0x00000020)
#define UMSK_ISR_SW_A_INT1(data)                                                     (0x00000020&((data)<<5))
#define UMSK_ISR_SW_A_INT1_src(data)                                                 ((0x00000020&(data))>>5)
#define UMSK_ISR_SW_get_A_INT1(data)                                                 ((0x00000020&(data))>>5)
#define UMSK_ISR_SW_A_INT0_shift                                                     (4)
#define UMSK_ISR_SW_A_INT0_mask                                                      (0x00000010)
#define UMSK_ISR_SW_A_INT0(data)                                                     (0x00000010&((data)<<4))
#define UMSK_ISR_SW_A_INT0_src(data)                                                 ((0x00000010&(data))>>4)
#define UMSK_ISR_SW_get_A_INT0(data)                                                 ((0x00000010&(data))>>4)
#define UMSK_ISR_SW_write_data_shift                                                 (0)
#define UMSK_ISR_SW_write_data_mask                                                  (0x00000001)
#define UMSK_ISR_SW_write_data(data)                                                 (0x00000001&((data)<<0))
#define UMSK_ISR_SW_write_data_src(data)                                             ((0x00000001&(data))>>0)
#define UMSK_ISR_SW_get_write_data(data)                                             ((0x00000001&(data))>>0)


#define ISO_DBG                                                                          0x18007024
#define ISO_DBG_reg_addr                                                                 "0x18007024"
#define ISO_DBG_reg                                                                      0x18007024
#define ISO_set_DBG_reg(data)   (*((volatile unsigned int*) DBG_reg)=data)
#define ISO_get_DBG_reg   (*((volatile unsigned int*) DBG_reg))
#define ISO_DBG_inst_adr                                                                 "0x0009"
#define ISO_DBG_inst                                                                     0x0009
#define ISO_DBG_write_en5_shift                                                          (31)
#define ISO_DBG_write_en5_mask                                                           (0x80000000)
#define ISO_DBG_write_en5(data)                                                          (0x80000000&((data)<<31))
#define ISO_DBG_write_en5_src(data)                                                      ((0x80000000&(data))>>31)
#define ISO_DBG_get_write_en5(data)                                                      ((0x80000000&(data))>>31)
#define ISO_DBG_standby_dbg_sel_shift                                                    (24)
#define ISO_DBG_standby_dbg_sel_mask                                                     (0x1F000000)
#define ISO_DBG_standby_dbg_sel(data)                                                    (0x1F000000&((data)<<24))
#define ISO_DBG_standby_dbg_sel_src(data)                                                ((0x1F000000&(data))>>24)
#define ISO_DBG_get_standby_dbg_sel(data)                                                ((0x1F000000&(data))>>24)
#define ISO_DBG_write_en4_shift                                                          (23)
#define ISO_DBG_write_en4_mask                                                           (0x00800000)
#define ISO_DBG_write_en4(data)                                                          (0x00800000&((data)<<23))
#define ISO_DBG_write_en4_src(data)                                                      ((0x00800000&(data))>>23)
#define ISO_DBG_get_write_en4(data)                                                      ((0x00800000&(data))>>23)
#define ISO_DBG_standby_dbg_en_shift                                                     (20)
#define ISO_DBG_standby_dbg_en_mask                                                      (0x00100000)
#define ISO_DBG_standby_dbg_en(data)                                                     (0x00100000&((data)<<20))
#define ISO_DBG_standby_dbg_en_src(data)                                                 ((0x00100000&(data))>>20)
#define ISO_DBG_get_standby_dbg_en(data)                                                 ((0x00100000&(data))>>20)
#define ISO_DBG_write_en3_shift                                                          (19)
#define ISO_DBG_write_en3_mask                                                           (0x00080000)
#define ISO_DBG_write_en3(data)                                                          (0x00080000&((data)<<19))
#define ISO_DBG_write_en3_src(data)                                                      ((0x00080000&(data))>>19)
#define ISO_DBG_get_write_en3(data)                                                      ((0x00080000&(data))>>19)
#define ISO_DBG_sel1_shift                                                               (12)
#define ISO_DBG_sel1_mask                                                                (0x0000F000)
#define ISO_DBG_sel1(data)                                                               (0x0000F000&((data)<<12))
#define ISO_DBG_sel1_src(data)                                                           ((0x0000F000&(data))>>12)
#define ISO_DBG_get_sel1(data)                                                           ((0x0000F000&(data))>>12)
#define ISO_DBG_write_en2_shift                                                          (11)
#define ISO_DBG_write_en2_mask                                                           (0x00000800)
#define ISO_DBG_write_en2(data)                                                          (0x00000800&((data)<<11))
#define ISO_DBG_write_en2_src(data)                                                      ((0x00000800&(data))>>11)
#define ISO_DBG_get_write_en2(data)                                                      ((0x00000800&(data))>>11)
#define ISO_DBG_sel0_shift                                                               (4)
#define ISO_DBG_sel0_mask                                                                (0x000000F0)
#define ISO_DBG_sel0(data)                                                               (0x000000F0&((data)<<4))
#define ISO_DBG_sel0_src(data)                                                           ((0x000000F0&(data))>>4)
#define ISO_DBG_get_sel0(data)                                                           ((0x000000F0&(data))>>4)
#define ISO_DBG_write_en1_shift                                                          (3)
#define ISO_DBG_write_en1_mask                                                           (0x00000008)
#define ISO_DBG_write_en1(data)                                                          (0x00000008&((data)<<3))
#define ISO_DBG_write_en1_src(data)                                                      ((0x00000008&(data))>>3)
#define ISO_DBG_get_write_en1(data)                                                      ((0x00000008&(data))>>3)
#define ISO_DBG_enable_shift                                                             (0)
#define ISO_DBG_enable_mask                                                              (0x00000001)
#define ISO_DBG_enable(data)                                                             (0x00000001&((data)<<0))
#define ISO_DBG_enable_src(data)                                                         ((0x00000001&(data))>>0)
#define ISO_DBG_get_enable(data)                                                         ((0x00000001&(data))>>0)


#define CHIP_INFO1                                                                   0x18007028
#define CHIP_INFO1_reg_addr                                                          "0x18007028"
#define CHIP_INFO1_reg                                                               0x18007028
#define set_CHIP_INFO1_reg(data)   (*((volatile unsigned int*) CHIP_INFO1_reg)=data)
#define get_CHIP_INFO1_reg   (*((volatile unsigned int*) CHIP_INFO1_reg))
#define CHIP_INFO1_inst_adr                                                          "0x000A"
#define CHIP_INFO1_inst                                                              0x000A
#define CHIP_INFO1_testmode_shift                                                    (14)
#define CHIP_INFO1_testmode_mask                                                     (0x00004000)
#define CHIP_INFO1_testmode(data)                                                    (0x00004000&((data)<<14))
#define CHIP_INFO1_testmode_src(data)                                                ((0x00004000&(data))>>14)
#define CHIP_INFO1_get_testmode(data)                                                ((0x00004000&(data))>>14)
#define CHIP_INFO1_boot_sel_shift                                                    (13)
#define CHIP_INFO1_boot_sel_mask                                                     (0x00002000)
#define CHIP_INFO1_boot_sel(data)                                                    (0x00002000&((data)<<13))
#define CHIP_INFO1_boot_sel_src(data)                                                ((0x00002000&(data))>>13)
#define CHIP_INFO1_get_boot_sel(data)                                                ((0x00002000&(data))>>13)
#define CHIP_INFO1_bound_opt_shift                                                   (0)
#define CHIP_INFO1_bound_opt_mask                                                    (0x00001FFF)
#define CHIP_INFO1_bound_opt(data)                                                   (0x00001FFF&((data)<<0))
#define CHIP_INFO1_bound_opt_src(data)                                               ((0x00001FFF&(data))>>0)
#define CHIP_INFO1_get_bound_opt(data)                                               ((0x00001FFF&(data))>>0)


#define ISO_CHIP_INFO2                                                                   0x1800702C
#define ISO_CHIP_INFO2_reg_addr                                                          "0x1800702C"
#define ISO_CHIP_INFO2_reg                                                               0x1800702C
#define ISO_set_CHIP_INFO2_reg(data)   (*((volatile unsigned int*) CHIP_INFO2_reg)=data)
#define ISO_get_CHIP_INFO2_reg   (*((volatile unsigned int*) CHIP_INFO2_reg))
#define ISO_CHIP_INFO2_inst_adr                                                          "0x000B"
#define ISO_CHIP_INFO2_inst                                                              0x000B
#define ISO_CHIP_INFO2_pow_latch_shift                                                   (0)
#define ISO_CHIP_INFO2_pow_latch_mask                                                    (0x0007FFFF)
#define ISO_CHIP_INFO2_pow_latch(data)                                                   (0x0007FFFF&((data)<<0))
#define ISO_CHIP_INFO2_pow_latch_src(data)                                               ((0x0007FFFF&(data))>>0)
#define ISO_CHIP_INFO2_get_pow_latch(data)                                               ((0x0007FFFF&(data))>>0)


#define CTRL                                                                         0x18007030
#define CTRL_reg_addr                                                                "0x18007030"
#define CTRL_reg                                                                     0x18007030
#define set_CTRL_reg(data)   (*((volatile unsigned int*) CTRL_reg)=data)
#define get_CTRL_reg   (*((volatile unsigned int*) CTRL_reg))
#define CTRL_inst_adr                                                                "0x000C"
#define CTRL_inst                                                                    0x000C
#define CTRL_write_en9_shift                                                         (17)
#define CTRL_write_en9_mask                                                          (0x00020000)
#define CTRL_write_en9(data)                                                         (0x00020000&((data)<<17))
#define CTRL_write_en9_src(data)                                                     ((0x00020000&(data))>>17)
#define CTRL_get_write_en9(data)                                                     ((0x00020000&(data))>>17)
#define CTRL_iso_rst_wd_mask_shift                                                   (16)
#define CTRL_iso_rst_wd_mask_mask                                                    (0x00010000)
#define CTRL_iso_rst_wd_mask(data)                                                   (0x00010000&((data)<<16))
#define CTRL_iso_rst_wd_mask_src(data)                                               ((0x00010000&(data))>>16)
#define CTRL_get_iso_rst_wd_mask(data)                                               ((0x00010000&(data))>>16)
#define CTRL_write_en8_shift                                                         (15)
#define CTRL_write_en8_mask                                                          (0x00008000)
#define CTRL_write_en8(data)                                                         (0x00008000&((data)<<15))
#define CTRL_write_en8_src(data)                                                     ((0x00008000&(data))>>15)
#define CTRL_get_write_en8(data)                                                     ((0x00008000&(data))>>15)
#define CTRL_dc_phy_cke_pd_shift                                                     (14)
#define CTRL_dc_phy_cke_pd_mask                                                      (0x00004000)
#define CTRL_dc_phy_cke_pd(data)                                                     (0x00004000&((data)<<14))
#define CTRL_dc_phy_cke_pd_src(data)                                                 ((0x00004000&(data))>>14)
#define CTRL_get_dc_phy_cke_pd(data)                                                 ((0x00004000&(data))>>14)
#define CTRL_write_en7_shift                                                         (13)
#define CTRL_write_en7_mask                                                          (0x00002000)
#define CTRL_write_en7(data)                                                         (0x00002000&((data)<<13))
#define CTRL_write_en7_src(data)                                                     ((0x00002000&(data))>>13)
#define CTRL_get_write_en7(data)                                                     ((0x00002000&(data))>>13)
#define CTRL_iso_mis_clk_en_shift                                                    (12)
#define CTRL_iso_mis_clk_en_mask                                                     (0x00001000)
#define CTRL_iso_mis_clk_en(data)                                                    (0x00001000&((data)<<12))
#define CTRL_iso_mis_clk_en_src(data)                                                ((0x00001000&(data))>>12)
#define CTRL_get_iso_mis_clk_en(data)                                                ((0x00001000&(data))>>12)
#define CTRL_write_en6_shift                                                         (11)
#define CTRL_write_en6_mask                                                          (0x00000800)
#define CTRL_write_en6(data)                                                         (0x00000800&((data)<<11))
#define CTRL_write_en6_src(data)                                                     ((0x00000800&(data))>>11)
#define CTRL_get_write_en6(data)                                                     ((0x00000800&(data))>>11)
#define CTRL_iso_rbus_sel_shift                                                      (10)
#define CTRL_iso_rbus_sel_mask                                                       (0x00000400)
#define CTRL_iso_rbus_sel(data)                                                      (0x00000400&((data)<<10))
#define CTRL_iso_rbus_sel_src(data)                                                  ((0x00000400&(data))>>10)
#define CTRL_get_iso_rbus_sel(data)                                                  ((0x00000400&(data))>>10)
#define CTRL_write_en5_shift                                                         (9)
#define CTRL_write_en5_mask                                                          (0x00000200)
#define CTRL_write_en5(data)                                                         (0x00000200&((data)<<9))
#define CTRL_write_en5_src(data)                                                     ((0x00000200&(data))>>9)
#define CTRL_get_write_en5(data)                                                     ((0x00000200&(data))>>9)
#define CTRL_iso_rst_mask_shift                                                      (8)
#define CTRL_iso_rst_mask_mask                                                       (0x00000100)
#define CTRL_iso_rst_mask(data)                                                      (0x00000100&((data)<<8))
#define CTRL_iso_rst_mask_src(data)                                                  ((0x00000100&(data))>>8)
#define CTRL_get_iso_rst_mask(data)                                                  ((0x00000100&(data))>>8)
#define CTRL_write_en4_shift                                                         (7)
#define CTRL_write_en4_mask                                                          (0x00000080)
#define CTRL_write_en4(data)                                                         (0x00000080&((data)<<7))
#define CTRL_write_en4_src(data)                                                     ((0x00000080&(data))>>7)
#define CTRL_get_write_en4(data)                                                     ((0x00000080&(data))>>7)
#define CTRL_clk_osc_on_en_shift                                                     (6)
#define CTRL_clk_osc_on_en_mask                                                      (0x00000040)
#define CTRL_clk_osc_on_en(data)                                                     (0x00000040&((data)<<6))
#define CTRL_clk_osc_on_en_src(data)                                                 ((0x00000040&(data))>>6)
#define CTRL_get_clk_osc_on_en(data)                                                 ((0x00000040&(data))>>6)
#define CTRL_write_en3_shift                                                         (5)
#define CTRL_write_en3_mask                                                          (0x00000020)
#define CTRL_write_en3(data)                                                         (0x00000020&((data)<<5))
#define CTRL_write_en3_src(data)                                                     ((0x00000020&(data))>>5)
#define CTRL_get_write_en3(data)                                                     ((0x00000020&(data))>>5)
#define CTRL_crt_sw_rstn_shift                                                       (4)
#define CTRL_crt_sw_rstn_mask                                                        (0x00000010)
#define CTRL_crt_sw_rstn(data)                                                       (0x00000010&((data)<<4))
#define CTRL_crt_sw_rstn_src(data)                                                   ((0x00000010&(data))>>4)
#define CTRL_get_crt_sw_rstn(data)                                                   ((0x00000010&(data))>>4)
#define CTRL_write_en2_shift                                                         (3)
#define CTRL_write_en2_mask                                                          (0x00000008)
#define CTRL_write_en2(data)                                                         (0x00000008&((data)<<3))
#define CTRL_write_en2_src(data)                                                     ((0x00000008&(data))>>3)
#define CTRL_get_write_en2(data)                                                     ((0x00000008&(data))>>3)
#define CTRL_iso_clk_sel_shift                                                       (2)
#define CTRL_iso_clk_sel_mask                                                        (0x00000004)
#define CTRL_iso_clk_sel(data)                                                       (0x00000004&((data)<<2))
#define CTRL_iso_clk_sel_src(data)                                                   ((0x00000004&(data))>>2)
#define CTRL_get_iso_clk_sel(data)                                                   ((0x00000004&(data))>>2)
#define CTRL_write_en1_shift                                                         (1)
#define CTRL_write_en1_mask                                                          (0x00000002)
#define CTRL_write_en1(data)                                                         (0x00000002&((data)<<1))
#define CTRL_write_en1_src(data)                                                     ((0x00000002&(data))>>1)
#define CTRL_get_write_en1(data)                                                     ((0x00000002&(data))>>1)
#define CTRL_ejtag_en_shift                                                          (0)
#define CTRL_ejtag_en_mask                                                           (0x00000001)
#define CTRL_ejtag_en(data)                                                          (0x00000001&((data)<<0))
#define CTRL_ejtag_en_src(data)                                                      ((0x00000001&(data))>>0)
#define CTRL_get_ejtag_en(data)                                                      ((0x00000001&(data))>>0)


#define RTC                                                                          0x18007034
#define RTC_reg_addr                                                                 "0x18007034"
#define RTC_reg                                                                      0x18007034
#define set_RTC_reg(data)   (*((volatile unsigned int*) RTC_reg)=data)
#define get_RTC_reg   (*((volatile unsigned int*) RTC_reg))
#define RTC_inst_adr                                                                 "0x000D"
#define RTC_inst                                                                     0x000D
#define RTC_hsec_int_en_shift                                                        (1)
#define RTC_hsec_int_en_mask                                                         (0x00000002)
#define RTC_hsec_int_en(data)                                                        (0x00000002&((data)<<1))
#define RTC_hsec_int_en_src(data)                                                    ((0x00000002&(data))>>1)
#define RTC_get_hsec_int_en(data)                                                    ((0x00000002&(data))>>1)
#define RTC_alarm_int_en_shift                                                       (0)
#define RTC_alarm_int_en_mask                                                        (0x00000001)
#define RTC_alarm_int_en(data)                                                       (0x00000001&((data)<<0))
#define RTC_alarm_int_en_src(data)                                                   ((0x00000001&(data))>>0)
#define RTC_get_alarm_int_en(data)                                                   ((0x00000001&(data))>>0)


#define CELL                                                                         0x18007038
#define CELL_reg_addr                                                                "0x18007038"
#define CELL_reg                                                                     0x18007038
#define set_CELL_reg(data)   (*((volatile unsigned int*) CELL_reg)=data)
#define get_CELL_reg   (*((volatile unsigned int*) CELL_reg))
#define CELL_inst_adr                                                                "0x000E"
#define CELL_inst                                                                    0x000E
#define CELL_iso_ctrl_en1_shift                                                      (1)
#define CELL_iso_ctrl_en1_mask                                                       (0x00000002)
#define CELL_iso_ctrl_en1(data)                                                      (0x00000002&((data)<<1))
#define CELL_iso_ctrl_en1_src(data)                                                  ((0x00000002&(data))>>1)
#define CELL_get_iso_ctrl_en1(data)                                                  ((0x00000002&(data))>>1)
#define CELL_iso_ctrl_en0_shift                                                      (0)
#define CELL_iso_ctrl_en0_mask                                                       (0x00000001)
#define CELL_iso_ctrl_en0(data)                                                      (0x00000001&((data)<<0))
#define CELL_iso_ctrl_en0_src(data)                                                  ((0x00000001&(data))>>0)
#define CELL_get_iso_ctrl_en0(data)                                                  ((0x00000001&(data))>>0)


#define POWER                                                                        0x1800703C
#define POWER_reg_addr                                                               "0x1800703C"
#define POWER_reg                                                                    0x1800703C
#define set_POWER_reg(data)   (*((volatile unsigned int*) POWER_reg)=data)
#define get_POWER_reg   (*((volatile unsigned int*) POWER_reg))
#define POWER_inst_adr                                                               "0x000F"
#define POWER_inst                                                                   0x000F
#define POWER_top_vdd_on_shift                                                       (1)
#define POWER_top_vdd_on_mask                                                        (0x00000002)
#define POWER_top_vdd_on(data)                                                       (0x00000002&((data)<<1))
#define POWER_top_vdd_on_src(data)                                                   ((0x00000002&(data))>>1)
#define POWER_get_top_vdd_on(data)                                                   ((0x00000002&(data))>>1)
#define POWER_scpu_vdd_on_shift                                                      (0)
#define POWER_scpu_vdd_on_mask                                                       (0x00000001)
#define POWER_scpu_vdd_on(data)                                                      (0x00000001&((data)<<0))
#define POWER_scpu_vdd_on_src(data)                                                  ((0x00000001&(data))>>0)
#define POWER_get_scpu_vdd_on(data)                                                  ((0x00000001&(data))>>0)


#define ISO_SCPU_INT_EN                                                                  0x18007040
#define ISO_SCPU_INT_EN_reg_addr                                                         "0x18007040"
#define ISO_SCPU_INT_EN_reg                                                              0x18007040
#define ISO_set_SCPU_INT_EN_reg(data)   (*((volatile unsigned int*) SCPU_INT_EN_reg)=data)
#define ISO_get_SCPU_INT_EN_reg   (*((volatile unsigned int*) SCPU_INT_EN_reg))
#define ISO_SCPU_INT_EN_inst_adr                                                         "0x0010"
#define ISO_SCPU_INT_EN_inst                                                             0x0010
#define SCPU_INT_EN_CEC_shift                                                        (22)
#define SCPU_INT_EN_CEC_mask                                                         (0x00400000)
#define SCPU_INT_EN_CEC(data)                                                        (0x00400000&((data)<<22))
#define SCPU_INT_EN_CEC_src(data)                                                    ((0x00400000&(data))>>22)
#define SCPU_INT_EN_get_CEC(data)                                                    ((0x00400000&(data))>>22)
#define SCPU_INT_EN_GPIODA_shift                                                     (20)
#define SCPU_INT_EN_GPIODA_mask                                                      (0x00100000)
#define SCPU_INT_EN_GPIODA(data)                                                     (0x00100000&((data)<<20))
#define SCPU_INT_EN_GPIODA_src(data)                                                 ((0x00100000&(data))>>20)
#define SCPU_INT_EN_get_GPIODA(data)                                                 ((0x00100000&(data))>>20)
#define SCPU_INT_EN_GPIOA_shift                                                      (19)
#define SCPU_INT_EN_GPIOA_mask                                                       (0x00080000)
#define SCPU_INT_EN_GPIOA(data)                                                      (0x00080000&((data)<<19))
#define SCPU_INT_EN_GPIOA_src(data)                                                  ((0x00080000&(data))>>19)
#define SCPU_INT_EN_get_GPIOA(data)                                                  ((0x00080000&(data))>>19)
#define SCPU_INT_EN_VFD_ARDSWDA_shift                                                (18)
#define SCPU_INT_EN_VFD_ARDSWDA_mask                                                 (0x00040000)
#define SCPU_INT_EN_VFD_ARDSWDA(data)                                                (0x00040000&((data)<<18))
#define SCPU_INT_EN_VFD_ARDSWDA_src(data)                                            ((0x00040000&(data))>>18)
#define SCPU_INT_EN_get_VFD_ARDSWDA(data)                                            ((0x00040000&(data))>>18)
#define SCPU_INT_EN_VFD_ARDSWA_shift                                                 (17)
#define SCPU_INT_EN_VFD_ARDSWA_mask                                                  (0x00020000)
#define SCPU_INT_EN_VFD_ARDSWA(data)                                                 (0x00020000&((data)<<17))
#define SCPU_INT_EN_VFD_ARDSWA_src(data)                                             ((0x00020000&(data))>>17)
#define SCPU_INT_EN_get_VFD_ARDSWA(data)                                             ((0x00020000&(data))>>17)
#define SCPU_INT_EN_VFD_ARDKPADDA_shift                                              (16)
#define SCPU_INT_EN_VFD_ARDKPADDA_mask                                               (0x00010000)
#define SCPU_INT_EN_VFD_ARDKPADDA(data)                                              (0x00010000&((data)<<16))
#define SCPU_INT_EN_VFD_ARDKPADDA_src(data)                                          ((0x00010000&(data))>>16)
#define SCPU_INT_EN_get_VFD_ARDKPADDA(data)                                          ((0x00010000&(data))>>16)
#define SCPU_INT_EN_VFD_ARDKPADA_shift                                               (15)
#define SCPU_INT_EN_VFD_ARDKPADA_mask                                                (0x00008000)
#define SCPU_INT_EN_VFD_ARDKPADA(data)                                               (0x00008000&((data)<<15))
#define SCPU_INT_EN_VFD_ARDKPADA_src(data)                                           ((0x00008000&(data))>>15)
#define SCPU_INT_EN_get_VFD_ARDKPADA(data)                                           ((0x00008000&(data))>>15)
#define SCPU_INT_EN_VFD_WDONE_shift                                                  (14)
#define SCPU_INT_EN_VFD_WDONE_mask                                                   (0x00004000)
#define SCPU_INT_EN_VFD_WDONE(data)                                                  (0x00004000&((data)<<14))
#define SCPU_INT_EN_VFD_WDONE_src(data)                                              ((0x00004000&(data))>>14)
#define SCPU_INT_EN_get_VFD_WDONE(data)                                              ((0x00004000&(data))>>14)
#define SCPU_INT_EN_RTC_ALARM_shift                                                  (13)
#define SCPU_INT_EN_RTC_ALARM_mask                                                   (0x00002000)
#define SCPU_INT_EN_RTC_ALARM(data)                                                  (0x00002000&((data)<<13))
#define SCPU_INT_EN_RTC_ALARM_src(data)                                              ((0x00002000&(data))>>13)
#define SCPU_INT_EN_get_RTC_ALARM(data)                                              ((0x00002000&(data))>>13)
#define SCPU_INT_EN_RTC_HSEC_shift                                                   (12)
#define SCPU_INT_EN_RTC_HSEC_mask                                                    (0x00001000)
#define SCPU_INT_EN_RTC_HSEC(data)                                                   (0x00001000&((data)<<12))
#define SCPU_INT_EN_RTC_HSEC_src(data)                                               ((0x00001000&(data))>>12)
#define SCPU_INT_EN_get_RTC_HSEC(data)                                               ((0x00001000&(data))>>12)
#define SCPU_INT_EN_I2C6_shift                                                       (10)
#define SCPU_INT_EN_I2C6_mask                                                        (0x00000400)
#define SCPU_INT_EN_I2C6(data)                                                       (0x00000400&((data)<<10))
#define SCPU_INT_EN_I2C6_src(data)                                                   ((0x00000400&(data))>>10)
#define SCPU_INT_EN_get_I2C6(data)                                                   ((0x00000400&(data))>>10)
#define SCPU_INT_EN_I2C0_shift                                                       (8)
#define SCPU_INT_EN_I2C0_mask                                                        (0x00000100)
#define SCPU_INT_EN_I2C0(data)                                                       (0x00000100&((data)<<8))
#define SCPU_INT_EN_I2C0_src(data)                                                   ((0x00000100&(data))>>8)
#define SCPU_INT_EN_get_I2C0(data)                                                   ((0x00000100&(data))>>8)
#define SCPU_INT_EN_IRDA_shift                                                       (5)
#define SCPU_INT_EN_IRDA_mask                                                        (0x00000020)
#define SCPU_INT_EN_IRDA(data)                                                       (0x00000020&((data)<<5))
#define SCPU_INT_EN_IRDA_src(data)                                                   ((0x00000020&(data))>>5)
#define SCPU_INT_EN_get_IRDA(data)                                                   ((0x00000020&(data))>>5)
#define SCPU_INT_EN_UR0_shift                                                        (2)
#define SCPU_INT_EN_UR0_mask                                                         (0x00000004)
#define SCPU_INT_EN_UR0(data)                                                        (0x00000004&((data)<<2))
#define SCPU_INT_EN_UR0_src(data)                                                    ((0x00000004&(data))>>2)
#define SCPU_INT_EN_get_UR0(data)                                                    ((0x00000004&(data))>>2)


#define USB                                                                          0x18007044
#define USB_reg_addr                                                                 "0x18007044"
#define USB_reg                                                                      0x18007044
#define set_USB_reg(data)   (*((volatile unsigned int*) USB_reg)=data)
#define get_USB_reg   (*((volatile unsigned int*) USB_reg))
#define USB_inst_adr                                                                 "0x0011"
#define USB_inst                                                                     0x0011
#define USB_DCP_CTRL1_shift                                                          (1)
#define USB_DCP_CTRL1_mask                                                           (0x00000002)
#define USB_DCP_CTRL1(data)                                                          (0x00000002&((data)<<1))
#define USB_DCP_CTRL1_src(data)                                                      ((0x00000002&(data))>>1)
#define USB_get_DCP_CTRL1(data)                                                      ((0x00000002&(data))>>1)
#define USB_DCP_CTRL0_shift                                                          (0)
#define USB_DCP_CTRL0_mask                                                           (0x00000001)
#define USB_DCP_CTRL0(data)                                                          (0x00000001&((data)<<0))
#define USB_DCP_CTRL0_src(data)                                                      ((0x00000001&(data))>>0)
#define USB_get_DCP_CTRL0(data)                                                      ((0x00000001&(data))>>0)


#define ACPU_INT_EN                                                                  0x18007048
#define ACPU_INT_EN_reg_addr                                                         "0x18007048"
#define ACPU_INT_EN_reg                                                              0x18007048
#define set_ACPU_INT_EN_reg(data)   (*((volatile unsigned int*) ACPU_INT_EN_reg)=data)
#define get_ACPU_INT_EN_reg   (*((volatile unsigned int*) ACPU_INT_EN_reg))
#define ACPU_INT_EN_inst_adr                                                         "0x0012"
#define ACPU_INT_EN_inst                                                             0x0012
#define ACPU_INT_EN_CEC_shift                                                        (22)
#define ACPU_INT_EN_CEC_mask                                                         (0x00400000)
#define ACPU_INT_EN_CEC(data)                                                        (0x00400000&((data)<<22))
#define ACPU_INT_EN_CEC_src(data)                                                    ((0x00400000&(data))>>22)
#define ACPU_INT_EN_get_CEC(data)                                                    ((0x00400000&(data))>>22)
#define ACPU_INT_EN_GPIODA_shift                                                     (20)
#define ACPU_INT_EN_GPIODA_mask                                                      (0x00100000)
#define ACPU_INT_EN_GPIODA(data)                                                     (0x00100000&((data)<<20))
#define ACPU_INT_EN_GPIODA_src(data)                                                 ((0x00100000&(data))>>20)
#define ACPU_INT_EN_get_GPIODA(data)                                                 ((0x00100000&(data))>>20)
#define ACPU_INT_EN_GPIOA_shift                                                      (19)
#define ACPU_INT_EN_GPIOA_mask                                                       (0x00080000)
#define ACPU_INT_EN_GPIOA(data)                                                      (0x00080000&((data)<<19))
#define ACPU_INT_EN_GPIOA_src(data)                                                  ((0x00080000&(data))>>19)
#define ACPU_INT_EN_get_GPIOA(data)                                                  ((0x00080000&(data))>>19)
#define ACPU_INT_EN_VFD_ARDSWDA_shift                                                (18)
#define ACPU_INT_EN_VFD_ARDSWDA_mask                                                 (0x00040000)
#define ACPU_INT_EN_VFD_ARDSWDA(data)                                                (0x00040000&((data)<<18))
#define ACPU_INT_EN_VFD_ARDSWDA_src(data)                                            ((0x00040000&(data))>>18)
#define ACPU_INT_EN_get_VFD_ARDSWDA(data)                                            ((0x00040000&(data))>>18)
#define ACPU_INT_EN_VFD_ARDSWA_shift                                                 (17)
#define ACPU_INT_EN_VFD_ARDSWA_mask                                                  (0x00020000)
#define ACPU_INT_EN_VFD_ARDSWA(data)                                                 (0x00020000&((data)<<17))
#define ACPU_INT_EN_VFD_ARDSWA_src(data)                                             ((0x00020000&(data))>>17)
#define ACPU_INT_EN_get_VFD_ARDSWA(data)                                             ((0x00020000&(data))>>17)
#define ACPU_INT_EN_VFD_ARDKPADDA_shift                                              (16)
#define ACPU_INT_EN_VFD_ARDKPADDA_mask                                               (0x00010000)
#define ACPU_INT_EN_VFD_ARDKPADDA(data)                                              (0x00010000&((data)<<16))
#define ACPU_INT_EN_VFD_ARDKPADDA_src(data)                                          ((0x00010000&(data))>>16)
#define ACPU_INT_EN_get_VFD_ARDKPADDA(data)                                          ((0x00010000&(data))>>16)
#define ACPU_INT_EN_VFD_ARDKPADA_shift                                               (15)
#define ACPU_INT_EN_VFD_ARDKPADA_mask                                                (0x00008000)
#define ACPU_INT_EN_VFD_ARDKPADA(data)                                               (0x00008000&((data)<<15))
#define ACPU_INT_EN_VFD_ARDKPADA_src(data)                                           ((0x00008000&(data))>>15)
#define ACPU_INT_EN_get_VFD_ARDKPADA(data)                                           ((0x00008000&(data))>>15)
#define ACPU_INT_EN_VFD_WDONE_shift                                                  (14)
#define ACPU_INT_EN_VFD_WDONE_mask                                                   (0x00004000)
#define ACPU_INT_EN_VFD_WDONE(data)                                                  (0x00004000&((data)<<14))
#define ACPU_INT_EN_VFD_WDONE_src(data)                                              ((0x00004000&(data))>>14)
#define ACPU_INT_EN_get_VFD_WDONE(data)                                              ((0x00004000&(data))>>14)
#define ACPU_INT_EN_RTC_ALARM_shift                                                  (13)
#define ACPU_INT_EN_RTC_ALARM_mask                                                   (0x00002000)
#define ACPU_INT_EN_RTC_ALARM(data)                                                  (0x00002000&((data)<<13))
#define ACPU_INT_EN_RTC_ALARM_src(data)                                              ((0x00002000&(data))>>13)
#define ACPU_INT_EN_get_RTC_ALARM(data)                                              ((0x00002000&(data))>>13)
#define ACPU_INT_EN_RTC_HSEC_shift                                                   (12)
#define ACPU_INT_EN_RTC_HSEC_mask                                                    (0x00001000)
#define ACPU_INT_EN_RTC_HSEC(data)                                                   (0x00001000&((data)<<12))
#define ACPU_INT_EN_RTC_HSEC_src(data)                                               ((0x00001000&(data))>>12)
#define ACPU_INT_EN_get_RTC_HSEC(data)                                               ((0x00001000&(data))>>12)
#define ACPU_INT_EN_I2C6_shift                                                       (10)
#define ACPU_INT_EN_I2C6_mask                                                        (0x00000400)
#define ACPU_INT_EN_I2C6(data)                                                       (0x00000400&((data)<<10))
#define ACPU_INT_EN_I2C6_src(data)                                                   ((0x00000400&(data))>>10)
#define ACPU_INT_EN_get_I2C6(data)                                                   ((0x00000400&(data))>>10)
#define ACPU_INT_EN_I2C0_shift                                                       (8)
#define ACPU_INT_EN_I2C0_mask                                                        (0x00000100)
#define ACPU_INT_EN_I2C0(data)                                                       (0x00000100&((data)<<8))
#define ACPU_INT_EN_I2C0_src(data)                                                   ((0x00000100&(data))>>8)
#define ACPU_INT_EN_get_I2C0(data)                                                   ((0x00000100&(data))>>8)
#define ACPU_INT_EN_IRDA_shift                                                       (5)
#define ACPU_INT_EN_IRDA_mask                                                        (0x00000020)
#define ACPU_INT_EN_IRDA(data)                                                       (0x00000020&((data)<<5))
#define ACPU_INT_EN_IRDA_src(data)                                                   ((0x00000020&(data))>>5)
#define ACPU_INT_EN_get_IRDA(data)                                                   ((0x00000020&(data))>>5)
#define ACPU_INT_EN_UR0_shift                                                        (2)
#define ACPU_INT_EN_UR0_mask                                                         (0x00000004)
#define ACPU_INT_EN_UR0(data)                                                        (0x00000004&((data)<<2))
#define ACPU_INT_EN_UR0_src(data)                                                    ((0x00000004&(data))>>2)
#define ACPU_INT_EN_get_UR0(data)                                                    ((0x00000004&(data))>>2)


#define CPU_ST1                                                                      0x1800704C
#define CPU_ST1_reg_addr                                                             "0x1800704C"
#define CPU_ST1_reg                                                                  0x1800704C
#define set_CPU_ST1_reg(data)   (*((volatile unsigned int*) CPU_ST1_reg)=data)
#define get_CPU_ST1_reg   (*((volatile unsigned int*) CPU_ST1_reg))
#define CPU_ST1_inst_adr                                                             "0x0013"
#define CPU_ST1_inst                                                                 0x0013
#define CPU_ST1_acpu_boot_info_shift                                                 (0)
#define CPU_ST1_acpu_boot_info_mask                                                  (0xFFFFFFFF)
#define CPU_ST1_acpu_boot_info(data)                                                 (0xFFFFFFFF&((data)<<0))
#define CPU_ST1_acpu_boot_info_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define CPU_ST1_get_acpu_boot_info(data)                                             ((0xFFFFFFFF&(data))>>0)


#define CPU_ST1V                                                                     0x18007050
#define CPU_ST1V_reg_addr                                                            "0x18007050"
#define CPU_ST1V_reg                                                                 0x18007050
#define set_CPU_ST1V_reg(data)   (*((volatile unsigned int*) CPU_ST1V_reg)=data)
#define get_CPU_ST1V_reg   (*((volatile unsigned int*) CPU_ST1V_reg))
#define CPU_ST1V_inst_adr                                                            "0x0014"
#define CPU_ST1V_inst                                                                0x0014
#define CPU_ST1V_acpu_boot_info_valid_shift                                          (0)
#define CPU_ST1V_acpu_boot_info_valid_mask                                           (0x00000001)
#define CPU_ST1V_acpu_boot_info_valid(data)                                          (0x00000001&((data)<<0))
#define CPU_ST1V_acpu_boot_info_valid_src(data)                                      ((0x00000001&(data))>>0)
#define CPU_ST1V_get_acpu_boot_info_valid(data)                                      ((0x00000001&(data))>>0)


#define ISO_DUMMY1                                                                       0x18007054
#define ISO_DUMMY1_reg_addr                                                              "0x18007054"
#define ISO_DUMMY1_reg                                                                   0x18007054
#define ISO_set_DUMMY1_reg(data)   (*((volatile unsigned int*) DUMMY1_reg)=data)
#define ISO_get_DUMMY1_reg   (*((volatile unsigned int*) DUMMY1_reg))
#define ISO_DUMMY1_inst_adr                                                              "0x0015"
#define ISO_DUMMY1_inst                                                                  0x0015
#define ISO_DUMMY1_rvd31_shift                                                           (31)
#define ISO_DUMMY1_rvd31_mask                                                            (0x80000000)
#define ISO_DUMMY1_rvd31(data)                                                           (0x80000000&((data)<<31))
#define ISO_DUMMY1_rvd31_src(data)                                                       ((0x80000000&(data))>>31)
#define ISO_DUMMY1_get_rvd31(data)                                                       ((0x80000000&(data))>>31)
#define ISO_DUMMY1_rvd30_shift                                                           (30)
#define ISO_DUMMY1_rvd30_mask                                                            (0x40000000)
#define ISO_DUMMY1_rvd30(data)                                                           (0x40000000&((data)<<30))
#define ISO_DUMMY1_rvd30_src(data)                                                       ((0x40000000&(data))>>30)
#define ISO_DUMMY1_get_rvd30(data)                                                       ((0x40000000&(data))>>30)
#define ISO_DUMMY1_rvd29_shift                                                           (29)
#define ISO_DUMMY1_rvd29_mask                                                            (0x20000000)
#define ISO_DUMMY1_rvd29(data)                                                           (0x20000000&((data)<<29))
#define ISO_DUMMY1_rvd29_src(data)                                                       ((0x20000000&(data))>>29)
#define ISO_DUMMY1_get_rvd29(data)                                                       ((0x20000000&(data))>>29)
#define ISO_DUMMY1_rvd28_shift                                                           (28)
#define ISO_DUMMY1_rvd28_mask                                                            (0x10000000)
#define ISO_DUMMY1_rvd28(data)                                                           (0x10000000&((data)<<28))
#define ISO_DUMMY1_rvd28_src(data)                                                       ((0x10000000&(data))>>28)
#define ISO_DUMMY1_get_rvd28(data)                                                       ((0x10000000&(data))>>28)
#define ISO_DUMMY1_rvd27_shift                                                           (27)
#define ISO_DUMMY1_rvd27_mask                                                            (0x08000000)
#define ISO_DUMMY1_rvd27(data)                                                           (0x08000000&((data)<<27))
#define ISO_DUMMY1_rvd27_src(data)                                                       ((0x08000000&(data))>>27)
#define ISO_DUMMY1_get_rvd27(data)                                                       ((0x08000000&(data))>>27)
#define ISO_DUMMY1_rvd26_shift                                                           (26)
#define ISO_DUMMY1_rvd26_mask                                                            (0x04000000)
#define ISO_DUMMY1_rvd26(data)                                                           (0x04000000&((data)<<26))
#define ISO_DUMMY1_rvd26_src(data)                                                       ((0x04000000&(data))>>26)
#define ISO_DUMMY1_get_rvd26(data)                                                       ((0x04000000&(data))>>26)
#define ISO_DUMMY1_rvd25_shift                                                           (25)
#define ISO_DUMMY1_rvd25_mask                                                            (0x02000000)
#define ISO_DUMMY1_rvd25(data)                                                           (0x02000000&((data)<<25))
#define ISO_DUMMY1_rvd25_src(data)                                                       ((0x02000000&(data))>>25)
#define ISO_DUMMY1_get_rvd25(data)                                                       ((0x02000000&(data))>>25)
#define ISO_DUMMY1_rvd24_shift                                                           (24)
#define ISO_DUMMY1_rvd24_mask                                                            (0x01000000)
#define ISO_DUMMY1_rvd24(data)                                                           (0x01000000&((data)<<24))
#define ISO_DUMMY1_rvd24_src(data)                                                       ((0x01000000&(data))>>24)
#define ISO_DUMMY1_get_rvd24(data)                                                       ((0x01000000&(data))>>24)
#define ISO_DUMMY1_rvd23_shift                                                           (23)
#define ISO_DUMMY1_rvd23_mask                                                            (0x00800000)
#define ISO_DUMMY1_rvd23(data)                                                           (0x00800000&((data)<<23))
#define ISO_DUMMY1_rvd23_src(data)                                                       ((0x00800000&(data))>>23)
#define ISO_DUMMY1_get_rvd23(data)                                                       ((0x00800000&(data))>>23)
#define ISO_DUMMY1_rvd22_shift                                                           (22)
#define ISO_DUMMY1_rvd22_mask                                                            (0x00400000)
#define ISO_DUMMY1_rvd22(data)                                                           (0x00400000&((data)<<22))
#define ISO_DUMMY1_rvd22_src(data)                                                       ((0x00400000&(data))>>22)
#define ISO_DUMMY1_get_rvd22(data)                                                       ((0x00400000&(data))>>22)
#define ISO_DUMMY1_rvd21_shift                                                           (21)
#define ISO_DUMMY1_rvd21_mask                                                            (0x00200000)
#define ISO_DUMMY1_rvd21(data)                                                           (0x00200000&((data)<<21))
#define ISO_DUMMY1_rvd21_src(data)                                                       ((0x00200000&(data))>>21)
#define ISO_DUMMY1_get_rvd21(data)                                                       ((0x00200000&(data))>>21)
#define ISO_DUMMY1_rvd20_shift                                                           (20)
#define ISO_DUMMY1_rvd20_mask                                                            (0x00100000)
#define ISO_DUMMY1_rvd20(data)                                                           (0x00100000&((data)<<20))
#define ISO_DUMMY1_rvd20_src(data)                                                       ((0x00100000&(data))>>20)
#define ISO_DUMMY1_get_rvd20(data)                                                       ((0x00100000&(data))>>20)
#define ISO_DUMMY1_rvd19_shift                                                           (19)
#define ISO_DUMMY1_rvd19_mask                                                            (0x00080000)
#define ISO_DUMMY1_rvd19(data)                                                           (0x00080000&((data)<<19))
#define ISO_DUMMY1_rvd19_src(data)                                                       ((0x00080000&(data))>>19)
#define ISO_DUMMY1_get_rvd19(data)                                                       ((0x00080000&(data))>>19)
#define ISO_DUMMY1_rvd18_shift                                                           (18)
#define ISO_DUMMY1_rvd18_mask                                                            (0x00040000)
#define ISO_DUMMY1_rvd18(data)                                                           (0x00040000&((data)<<18))
#define ISO_DUMMY1_rvd18_src(data)                                                       ((0x00040000&(data))>>18)
#define ISO_DUMMY1_get_rvd18(data)                                                       ((0x00040000&(data))>>18)
#define ISO_DUMMY1_rvd17_shift                                                           (17)
#define ISO_DUMMY1_rvd17_mask                                                            (0x00020000)
#define ISO_DUMMY1_rvd17(data)                                                           (0x00020000&((data)<<17))
#define ISO_DUMMY1_rvd17_src(data)                                                       ((0x00020000&(data))>>17)
#define ISO_DUMMY1_get_rvd17(data)                                                       ((0x00020000&(data))>>17)
#define ISO_DUMMY1_rvd16_shift                                                           (16)
#define ISO_DUMMY1_rvd16_mask                                                            (0x00010000)
#define ISO_DUMMY1_rvd16(data)                                                           (0x00010000&((data)<<16))
#define ISO_DUMMY1_rvd16_src(data)                                                       ((0x00010000&(data))>>16)
#define ISO_DUMMY1_get_rvd16(data)                                                       ((0x00010000&(data))>>16)
#define ISO_DUMMY1_rvd15_shift                                                           (15)
#define ISO_DUMMY1_rvd15_mask                                                            (0x00008000)
#define ISO_DUMMY1_rvd15(data)                                                           (0x00008000&((data)<<15))
#define ISO_DUMMY1_rvd15_src(data)                                                       ((0x00008000&(data))>>15)
#define ISO_DUMMY1_get_rvd15(data)                                                       ((0x00008000&(data))>>15)
#define ISO_DUMMY1_rvd14_shift                                                           (14)
#define ISO_DUMMY1_rvd14_mask                                                            (0x00004000)
#define ISO_DUMMY1_rvd14(data)                                                           (0x00004000&((data)<<14))
#define ISO_DUMMY1_rvd14_src(data)                                                       ((0x00004000&(data))>>14)
#define ISO_DUMMY1_get_rvd14(data)                                                       ((0x00004000&(data))>>14)
#define ISO_DUMMY1_rvd13_shift                                                           (13)
#define ISO_DUMMY1_rvd13_mask                                                            (0x00002000)
#define ISO_DUMMY1_rvd13(data)                                                           (0x00002000&((data)<<13))
#define ISO_DUMMY1_rvd13_src(data)                                                       ((0x00002000&(data))>>13)
#define ISO_DUMMY1_get_rvd13(data)                                                       ((0x00002000&(data))>>13)
#define ISO_DUMMY1_rvd12_shift                                                           (12)
#define ISO_DUMMY1_rvd12_mask                                                            (0x00001000)
#define ISO_DUMMY1_rvd12(data)                                                           (0x00001000&((data)<<12))
#define ISO_DUMMY1_rvd12_src(data)                                                       ((0x00001000&(data))>>12)
#define ISO_DUMMY1_get_rvd12(data)                                                       ((0x00001000&(data))>>12)
#define ISO_DUMMY1_rvd11_shift                                                           (11)
#define ISO_DUMMY1_rvd11_mask                                                            (0x00000800)
#define ISO_DUMMY1_rvd11(data)                                                           (0x00000800&((data)<<11))
#define ISO_DUMMY1_rvd11_src(data)                                                       ((0x00000800&(data))>>11)
#define ISO_DUMMY1_get_rvd11(data)                                                       ((0x00000800&(data))>>11)
#define ISO_DUMMY1_rvd10_shift                                                           (10)
#define ISO_DUMMY1_rvd10_mask                                                            (0x00000400)
#define ISO_DUMMY1_rvd10(data)                                                           (0x00000400&((data)<<10))
#define ISO_DUMMY1_rvd10_src(data)                                                       ((0x00000400&(data))>>10)
#define ISO_DUMMY1_get_rvd10(data)                                                       ((0x00000400&(data))>>10)
#define ISO_DUMMY1_rvd9_shift                                                            (9)
#define ISO_DUMMY1_rvd9_mask                                                             (0x00000200)
#define ISO_DUMMY1_rvd9(data)                                                            (0x00000200&((data)<<9))
#define ISO_DUMMY1_rvd9_src(data)                                                        ((0x00000200&(data))>>9)
#define ISO_DUMMY1_get_rvd9(data)                                                        ((0x00000200&(data))>>9)
#define ISO_DUMMY1_rvd8_shift                                                            (8)
#define ISO_DUMMY1_rvd8_mask                                                             (0x00000100)
#define ISO_DUMMY1_rvd8(data)                                                            (0x00000100&((data)<<8))
#define ISO_DUMMY1_rvd8_src(data)                                                        ((0x00000100&(data))>>8)
#define ISO_DUMMY1_get_rvd8(data)                                                        ((0x00000100&(data))>>8)
#define ISO_DUMMY1_rvd7_shift                                                            (7)
#define ISO_DUMMY1_rvd7_mask                                                             (0x00000080)
#define ISO_DUMMY1_rvd7(data)                                                            (0x00000080&((data)<<7))
#define ISO_DUMMY1_rvd7_src(data)                                                        ((0x00000080&(data))>>7)
#define ISO_DUMMY1_get_rvd7(data)                                                        ((0x00000080&(data))>>7)
#define ISO_DUMMY1_rvd6_shift                                                            (6)
#define ISO_DUMMY1_rvd6_mask                                                             (0x00000040)
#define ISO_DUMMY1_rvd6(data)                                                            (0x00000040&((data)<<6))
#define ISO_DUMMY1_rvd6_src(data)                                                        ((0x00000040&(data))>>6)
#define ISO_DUMMY1_get_rvd6(data)                                                        ((0x00000040&(data))>>6)
#define ISO_DUMMY1_rvd5_shift                                                            (5)
#define ISO_DUMMY1_rvd5_mask                                                             (0x00000020)
#define ISO_DUMMY1_rvd5(data)                                                            (0x00000020&((data)<<5))
#define ISO_DUMMY1_rvd5_src(data)                                                        ((0x00000020&(data))>>5)
#define ISO_DUMMY1_get_rvd5(data)                                                        ((0x00000020&(data))>>5)
#define ISO_DUMMY1_rvd4_shift                                                            (4)
#define ISO_DUMMY1_rvd4_mask                                                             (0x00000010)
#define ISO_DUMMY1_rvd4(data)                                                            (0x00000010&((data)<<4))
#define ISO_DUMMY1_rvd4_src(data)                                                        ((0x00000010&(data))>>4)
#define ISO_DUMMY1_get_rvd4(data)                                                        ((0x00000010&(data))>>4)
#define ISO_DUMMY1_rvd3_shift                                                            (3)
#define ISO_DUMMY1_rvd3_mask                                                             (0x00000008)
#define ISO_DUMMY1_rvd3(data)                                                            (0x00000008&((data)<<3))
#define ISO_DUMMY1_rvd3_src(data)                                                        ((0x00000008&(data))>>3)
#define ISO_DUMMY1_get_rvd3(data)                                                        ((0x00000008&(data))>>3)
#define ISO_DUMMY1_rvd2_shift                                                            (2)
#define ISO_DUMMY1_rvd2_mask                                                             (0x00000004)
#define ISO_DUMMY1_rvd2(data)                                                            (0x00000004&((data)<<2))
#define ISO_DUMMY1_rvd2_src(data)                                                        ((0x00000004&(data))>>2)
#define ISO_DUMMY1_get_rvd2(data)                                                        ((0x00000004&(data))>>2)
#define ISO_DUMMY1_rvd1_shift                                                            (1)
#define ISO_DUMMY1_rvd1_mask                                                             (0x00000002)
#define ISO_DUMMY1_rvd1(data)                                                            (0x00000002&((data)<<1))
#define ISO_DUMMY1_rvd1_src(data)                                                        ((0x00000002&(data))>>1)
#define ISO_DUMMY1_get_rvd1(data)                                                        ((0x00000002&(data))>>1)
#define ISO_DUMMY1_rvd0_shift                                                            (0)
#define ISO_DUMMY1_rvd0_mask                                                             (0x00000001)
#define ISO_DUMMY1_rvd0(data)                                                            (0x00000001&((data)<<0))
#define ISO_DUMMY1_rvd0_src(data)                                                        ((0x00000001&(data))>>0)
#define ISO_DUMMY1_get_rvd0(data)                                                        ((0x00000001&(data))>>0)


#define DUMMY2                                                                       0x18007058
#define DUMMY2_reg_addr                                                              "0x18007058"
#define DUMMY2_reg                                                                   0x18007058
#define set_DUMMY2_reg(data)   (*((volatile unsigned int*) DUMMY2_reg)=data)
#define get_DUMMY2_reg   (*((volatile unsigned int*) DUMMY2_reg))
#define DUMMY2_inst_adr                                                              "0x0016"
#define DUMMY2_inst                                                                  0x0016
#define DUMMY2_rvd31_shift                                                           (31)
#define DUMMY2_rvd31_mask                                                            (0x80000000)
#define DUMMY2_rvd31(data)                                                           (0x80000000&((data)<<31))
#define DUMMY2_rvd31_src(data)                                                       ((0x80000000&(data))>>31)
#define DUMMY2_get_rvd31(data)                                                       ((0x80000000&(data))>>31)
#define DUMMY2_rvd30_shift                                                           (30)
#define DUMMY2_rvd30_mask                                                            (0x40000000)
#define DUMMY2_rvd30(data)                                                           (0x40000000&((data)<<30))
#define DUMMY2_rvd30_src(data)                                                       ((0x40000000&(data))>>30)
#define DUMMY2_get_rvd30(data)                                                       ((0x40000000&(data))>>30)
#define DUMMY2_rvd29_shift                                                           (29)
#define DUMMY2_rvd29_mask                                                            (0x20000000)
#define DUMMY2_rvd29(data)                                                           (0x20000000&((data)<<29))
#define DUMMY2_rvd29_src(data)                                                       ((0x20000000&(data))>>29)
#define DUMMY2_get_rvd29(data)                                                       ((0x20000000&(data))>>29)
#define DUMMY2_rvd28_shift                                                           (28)
#define DUMMY2_rvd28_mask                                                            (0x10000000)
#define DUMMY2_rvd28(data)                                                           (0x10000000&((data)<<28))
#define DUMMY2_rvd28_src(data)                                                       ((0x10000000&(data))>>28)
#define DUMMY2_get_rvd28(data)                                                       ((0x10000000&(data))>>28)
#define DUMMY2_rvd27_shift                                                           (27)
#define DUMMY2_rvd27_mask                                                            (0x08000000)
#define DUMMY2_rvd27(data)                                                           (0x08000000&((data)<<27))
#define DUMMY2_rvd27_src(data)                                                       ((0x08000000&(data))>>27)
#define DUMMY2_get_rvd27(data)                                                       ((0x08000000&(data))>>27)
#define DUMMY2_rvd26_shift                                                           (26)
#define DUMMY2_rvd26_mask                                                            (0x04000000)
#define DUMMY2_rvd26(data)                                                           (0x04000000&((data)<<26))
#define DUMMY2_rvd26_src(data)                                                       ((0x04000000&(data))>>26)
#define DUMMY2_get_rvd26(data)                                                       ((0x04000000&(data))>>26)
#define DUMMY2_rvd25_shift                                                           (25)
#define DUMMY2_rvd25_mask                                                            (0x02000000)
#define DUMMY2_rvd25(data)                                                           (0x02000000&((data)<<25))
#define DUMMY2_rvd25_src(data)                                                       ((0x02000000&(data))>>25)
#define DUMMY2_get_rvd25(data)                                                       ((0x02000000&(data))>>25)
#define DUMMY2_rvd24_shift                                                           (24)
#define DUMMY2_rvd24_mask                                                            (0x01000000)
#define DUMMY2_rvd24(data)                                                           (0x01000000&((data)<<24))
#define DUMMY2_rvd24_src(data)                                                       ((0x01000000&(data))>>24)
#define DUMMY2_get_rvd24(data)                                                       ((0x01000000&(data))>>24)
#define DUMMY2_rvd23_shift                                                           (23)
#define DUMMY2_rvd23_mask                                                            (0x00800000)
#define DUMMY2_rvd23(data)                                                           (0x00800000&((data)<<23))
#define DUMMY2_rvd23_src(data)                                                       ((0x00800000&(data))>>23)
#define DUMMY2_get_rvd23(data)                                                       ((0x00800000&(data))>>23)
#define DUMMY2_rvd22_shift                                                           (22)
#define DUMMY2_rvd22_mask                                                            (0x00400000)
#define DUMMY2_rvd22(data)                                                           (0x00400000&((data)<<22))
#define DUMMY2_rvd22_src(data)                                                       ((0x00400000&(data))>>22)
#define DUMMY2_get_rvd22(data)                                                       ((0x00400000&(data))>>22)
#define DUMMY2_rvd21_shift                                                           (21)
#define DUMMY2_rvd21_mask                                                            (0x00200000)
#define DUMMY2_rvd21(data)                                                           (0x00200000&((data)<<21))
#define DUMMY2_rvd21_src(data)                                                       ((0x00200000&(data))>>21)
#define DUMMY2_get_rvd21(data)                                                       ((0x00200000&(data))>>21)
#define DUMMY2_rvd20_shift                                                           (20)
#define DUMMY2_rvd20_mask                                                            (0x00100000)
#define DUMMY2_rvd20(data)                                                           (0x00100000&((data)<<20))
#define DUMMY2_rvd20_src(data)                                                       ((0x00100000&(data))>>20)
#define DUMMY2_get_rvd20(data)                                                       ((0x00100000&(data))>>20)
#define DUMMY2_rvd19_shift                                                           (19)
#define DUMMY2_rvd19_mask                                                            (0x00080000)
#define DUMMY2_rvd19(data)                                                           (0x00080000&((data)<<19))
#define DUMMY2_rvd19_src(data)                                                       ((0x00080000&(data))>>19)
#define DUMMY2_get_rvd19(data)                                                       ((0x00080000&(data))>>19)
#define DUMMY2_rvd18_shift                                                           (18)
#define DUMMY2_rvd18_mask                                                            (0x00040000)
#define DUMMY2_rvd18(data)                                                           (0x00040000&((data)<<18))
#define DUMMY2_rvd18_src(data)                                                       ((0x00040000&(data))>>18)
#define DUMMY2_get_rvd18(data)                                                       ((0x00040000&(data))>>18)
#define DUMMY2_rvd17_shift                                                           (17)
#define DUMMY2_rvd17_mask                                                            (0x00020000)
#define DUMMY2_rvd17(data)                                                           (0x00020000&((data)<<17))
#define DUMMY2_rvd17_src(data)                                                       ((0x00020000&(data))>>17)
#define DUMMY2_get_rvd17(data)                                                       ((0x00020000&(data))>>17)
#define DUMMY2_rvd16_shift                                                           (16)
#define DUMMY2_rvd16_mask                                                            (0x00010000)
#define DUMMY2_rvd16(data)                                                           (0x00010000&((data)<<16))
#define DUMMY2_rvd16_src(data)                                                       ((0x00010000&(data))>>16)
#define DUMMY2_get_rvd16(data)                                                       ((0x00010000&(data))>>16)
#define DUMMY2_rvd15_shift                                                           (15)
#define DUMMY2_rvd15_mask                                                            (0x00008000)
#define DUMMY2_rvd15(data)                                                           (0x00008000&((data)<<15))
#define DUMMY2_rvd15_src(data)                                                       ((0x00008000&(data))>>15)
#define DUMMY2_get_rvd15(data)                                                       ((0x00008000&(data))>>15)
#define DUMMY2_rvd14_shift                                                           (14)
#define DUMMY2_rvd14_mask                                                            (0x00004000)
#define DUMMY2_rvd14(data)                                                           (0x00004000&((data)<<14))
#define DUMMY2_rvd14_src(data)                                                       ((0x00004000&(data))>>14)
#define DUMMY2_get_rvd14(data)                                                       ((0x00004000&(data))>>14)
#define DUMMY2_rvd13_shift                                                           (13)
#define DUMMY2_rvd13_mask                                                            (0x00002000)
#define DUMMY2_rvd13(data)                                                           (0x00002000&((data)<<13))
#define DUMMY2_rvd13_src(data)                                                       ((0x00002000&(data))>>13)
#define DUMMY2_get_rvd13(data)                                                       ((0x00002000&(data))>>13)
#define DUMMY2_rvd12_shift                                                           (12)
#define DUMMY2_rvd12_mask                                                            (0x00001000)
#define DUMMY2_rvd12(data)                                                           (0x00001000&((data)<<12))
#define DUMMY2_rvd12_src(data)                                                       ((0x00001000&(data))>>12)
#define DUMMY2_get_rvd12(data)                                                       ((0x00001000&(data))>>12)
#define DUMMY2_rvd11_shift                                                           (11)
#define DUMMY2_rvd11_mask                                                            (0x00000800)
#define DUMMY2_rvd11(data)                                                           (0x00000800&((data)<<11))
#define DUMMY2_rvd11_src(data)                                                       ((0x00000800&(data))>>11)
#define DUMMY2_get_rvd11(data)                                                       ((0x00000800&(data))>>11)
#define DUMMY2_rvd10_shift                                                           (10)
#define DUMMY2_rvd10_mask                                                            (0x00000400)
#define DUMMY2_rvd10(data)                                                           (0x00000400&((data)<<10))
#define DUMMY2_rvd10_src(data)                                                       ((0x00000400&(data))>>10)
#define DUMMY2_get_rvd10(data)                                                       ((0x00000400&(data))>>10)
#define DUMMY2_rvd9_shift                                                            (9)
#define DUMMY2_rvd9_mask                                                             (0x00000200)
#define DUMMY2_rvd9(data)                                                            (0x00000200&((data)<<9))
#define DUMMY2_rvd9_src(data)                                                        ((0x00000200&(data))>>9)
#define DUMMY2_get_rvd9(data)                                                        ((0x00000200&(data))>>9)
#define DUMMY2_rvd8_shift                                                            (8)
#define DUMMY2_rvd8_mask                                                             (0x00000100)
#define DUMMY2_rvd8(data)                                                            (0x00000100&((data)<<8))
#define DUMMY2_rvd8_src(data)                                                        ((0x00000100&(data))>>8)
#define DUMMY2_get_rvd8(data)                                                        ((0x00000100&(data))>>8)
#define DUMMY2_rvd7_shift                                                            (7)
#define DUMMY2_rvd7_mask                                                             (0x00000080)
#define DUMMY2_rvd7(data)                                                            (0x00000080&((data)<<7))
#define DUMMY2_rvd7_src(data)                                                        ((0x00000080&(data))>>7)
#define DUMMY2_get_rvd7(data)                                                        ((0x00000080&(data))>>7)
#define DUMMY2_rvd6_shift                                                            (6)
#define DUMMY2_rvd6_mask                                                             (0x00000040)
#define DUMMY2_rvd6(data)                                                            (0x00000040&((data)<<6))
#define DUMMY2_rvd6_src(data)                                                        ((0x00000040&(data))>>6)
#define DUMMY2_get_rvd6(data)                                                        ((0x00000040&(data))>>6)
#define DUMMY2_rvd5_shift                                                            (5)
#define DUMMY2_rvd5_mask                                                             (0x00000020)
#define DUMMY2_rvd5(data)                                                            (0x00000020&((data)<<5))
#define DUMMY2_rvd5_src(data)                                                        ((0x00000020&(data))>>5)
#define DUMMY2_get_rvd5(data)                                                        ((0x00000020&(data))>>5)
#define DUMMY2_rvd4_shift                                                            (4)
#define DUMMY2_rvd4_mask                                                             (0x00000010)
#define DUMMY2_rvd4(data)                                                            (0x00000010&((data)<<4))
#define DUMMY2_rvd4_src(data)                                                        ((0x00000010&(data))>>4)
#define DUMMY2_get_rvd4(data)                                                        ((0x00000010&(data))>>4)
#define DUMMY2_rvd3_shift                                                            (3)
#define DUMMY2_rvd3_mask                                                             (0x00000008)
#define DUMMY2_rvd3(data)                                                            (0x00000008&((data)<<3))
#define DUMMY2_rvd3_src(data)                                                        ((0x00000008&(data))>>3)
#define DUMMY2_get_rvd3(data)                                                        ((0x00000008&(data))>>3)
#define DUMMY2_rvd2_shift                                                            (2)
#define DUMMY2_rvd2_mask                                                             (0x00000004)
#define DUMMY2_rvd2(data)                                                            (0x00000004&((data)<<2))
#define DUMMY2_rvd2_src(data)                                                        ((0x00000004&(data))>>2)
#define DUMMY2_get_rvd2(data)                                                        ((0x00000004&(data))>>2)
#define DUMMY2_rvd1_shift                                                            (1)
#define DUMMY2_rvd1_mask                                                             (0x00000002)
#define DUMMY2_rvd1(data)                                                            (0x00000002&((data)<<1))
#define DUMMY2_rvd1_src(data)                                                        ((0x00000002&(data))>>1)
#define DUMMY2_get_rvd1(data)                                                        ((0x00000002&(data))>>1)
#define DUMMY2_rvd0_shift                                                            (0)
#define DUMMY2_rvd0_mask                                                             (0x00000001)
#define DUMMY2_rvd0(data)                                                            (0x00000001&((data)<<0))
#define DUMMY2_rvd0_src(data)                                                        ((0x00000001&(data))>>0)
#define DUMMY2_get_rvd0(data)                                                        ((0x00000001&(data))>>0)


#define POWERCUT_ETN                                                                 0x1800705C
#define POWERCUT_ETN_reg_addr                                                        "0x1800705C"
#define POWERCUT_ETN_reg                                                             0x1800705C
#define set_POWERCUT_ETN_reg(data)   (*((volatile unsigned int*) POWERCUT_ETN_reg)=data)
#define get_POWERCUT_ETN_reg   (*((volatile unsigned int*) POWERCUT_ETN_reg))
#define POWERCUT_ETN_inst_adr                                                        "0x0017"
#define POWERCUT_ETN_inst                                                            0x0017
#define POWERCUT_ETN_powercut_ana_d2a_isolate_b_shift                                (1)
#define POWERCUT_ETN_powercut_ana_d2a_isolate_b_mask                                 (0x00000002)
#define POWERCUT_ETN_powercut_ana_d2a_isolate_b(data)                                (0x00000002&((data)<<1))
#define POWERCUT_ETN_powercut_ana_d2a_isolate_b_src(data)                            ((0x00000002&(data))>>1)
#define POWERCUT_ETN_get_powercut_ana_d2a_isolate_b(data)                            ((0x00000002&(data))>>1)
#define POWERCUT_ETN_powercut_ana_a2d_isolate_b_shift                                (0)
#define POWERCUT_ETN_powercut_ana_a2d_isolate_b_mask                                 (0x00000001)
#define POWERCUT_ETN_powercut_ana_a2d_isolate_b(data)                                (0x00000001&((data)<<0))
#define POWERCUT_ETN_powercut_ana_a2d_isolate_b_src(data)                            ((0x00000001&(data))>>0)
#define POWERCUT_ETN_get_powercut_ana_a2d_isolate_b(data)                            ((0x00000001&(data))>>0)


#define ETN_TESTIO                                                                   0x18007060
#define ETN_TESTIO_reg_addr                                                          "0x18007060"
#define ETN_TESTIO_reg                                                               0x18007060
#define set_ETN_TESTIO_reg(data)   (*((volatile unsigned int*) ETN_TESTIO_reg)=data)
#define get_ETN_TESTIO_reg   (*((volatile unsigned int*) ETN_TESTIO_reg))
#define ETN_TESTIO_inst_adr                                                          "0x0018"
#define ETN_TESTIO_inst                                                              0x0018
#define ETN_TESTIO_etn_bpsgphy_mode_shift                                            (1)
#define ETN_TESTIO_etn_bpsgphy_mode_mask                                             (0x00000002)
#define ETN_TESTIO_etn_bpsgphy_mode(data)                                            (0x00000002&((data)<<1))
#define ETN_TESTIO_etn_bpsgphy_mode_src(data)                                        ((0x00000002&(data))>>1)
#define ETN_TESTIO_get_etn_bpsgphy_mode(data)                                        ((0x00000002&(data))>>1)
#define ETN_TESTIO_etn_ocd_mode_shift                                                (0)
#define ETN_TESTIO_etn_ocd_mode_mask                                                 (0x00000001)
#define ETN_TESTIO_etn_ocd_mode(data)                                                (0x00000001&((data)<<0))
#define ETN_TESTIO_etn_ocd_mode_src(data)                                            ((0x00000001&(data))>>0)
#define ETN_TESTIO_get_etn_ocd_mode(data)                                            ((0x00000001&(data))>>0)


#define RESERVED_USE_0                                                               0x18007064
#define RESERVED_USE_0_reg_addr                                                      "0x18007064"
#define RESERVED_USE_0_reg                                                           0x18007064
#define set_RESERVED_USE_0_reg(data)   (*((volatile unsigned int*) RESERVED_USE_0_reg)=data)
#define get_RESERVED_USE_0_reg   (*((volatile unsigned int*) RESERVED_USE_0_reg))
#define RESERVED_USE_0_inst_adr                                                      "0x0019"
#define RESERVED_USE_0_inst                                                          0x0019
#define RESERVED_USE_0_DMY_shift                                                     (0)
#define RESERVED_USE_0_DMY_mask                                                      (0xFFFFFFFF)
#define RESERVED_USE_0_DMY(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESERVED_USE_0_DMY_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESERVED_USE_0_get_DMY(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define LPI                                                                          0x18007068
#define LPI_reg_addr                                                                 "0x18007068"
#define LPI_reg                                                                      0x18007068
#define set_LPI_reg(data)   (*((volatile unsigned int*) LPI_reg)=data)
#define get_LPI_reg   (*((volatile unsigned int*) LPI_reg))
#define LPI_inst_adr                                                                 "0x001A"
#define LPI_inst                                                                     0x001A
#define LPI_IR_TX_shift                                                              (1)
#define LPI_IR_TX_mask                                                               (0x00000002)
#define LPI_IR_TX(data)                                                              (0x00000002&((data)<<1))
#define LPI_IR_TX_src(data)                                                          ((0x00000002&(data))>>1)
#define LPI_get_IR_TX(data)                                                          ((0x00000002&(data))>>1)
#define LPI_IR_RAW_shift                                                             (0)
#define LPI_IR_RAW_mask                                                              (0x00000001)
#define LPI_IR_RAW(data)                                                             (0x00000001&((data)<<0))
#define LPI_IR_RAW_src(data)                                                         ((0x00000001&(data))>>0)
#define LPI_get_IR_RAW(data)                                                         ((0x00000001&(data))>>0)


#define WD                                                                           0x1800706C
#define WD_reg_addr                                                                  "0x1800706C"
#define WD_reg                                                                       0x1800706C
#define set_WD_reg(data)   (*((volatile unsigned int*) WD_reg)=data)
#define get_WD_reg   (*((volatile unsigned int*) WD_reg))
#define WD_inst_adr                                                                  "0x001B"
#define WD_inst                                                                      0x001B
#define WD_cnt_wait_pwr_shift                                                        (0)
#define WD_cnt_wait_pwr_mask                                                         (0x0000FFFF)
#define WD_cnt_wait_pwr(data)                                                        (0x0000FFFF&((data)<<0))
#define WD_cnt_wait_pwr_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define WD_get_cnt_wait_pwr(data)                                                    ((0x0000FFFF&(data))>>0)


#define ISO_PLL_WDOUT                                                                    0x18007070
#define ISO_PLL_WDOUT_reg_addr                                                           "0x18007070"
#define ISO_PLL_WDOUT_reg                                                                0x18007070
#define ISO_set_PLL_WDOUT_reg(data)   (*((volatile unsigned int*) PLL_WDOUT_reg)=data)
#define ISO_get_PLL_WDOUT_reg   (*((volatile unsigned int*) PLL_WDOUT_reg))
#define ISO_PLL_WDOUT_inst_adr                                                           "0x001C"
#define ISO_PLL_WDOUT_inst                                                               0x001C
#define ISO_PLL_WDOUT_PLLETN_WDOUT_shift                                                 (0)
#define ISO_PLL_WDOUT_PLLETN_WDOUT_mask                                                  (0x00000001)
#define ISO_PLL_WDOUT_PLLETN_WDOUT(data)                                                 (0x00000001&((data)<<0))
#define ISO_PLL_WDOUT_PLLETN_WDOUT_src(data)                                             ((0x00000001&(data))>>0)
#define ISO_PLL_WDOUT_get_PLLETN_WDOUT(data)                                             ((0x00000001&(data))>>0)


#define PLL_ETN                                                                      0x18007074
#define PLL_ETN_reg_addr                                                             "0x18007074"
#define PLL_ETN_reg                                                                  0x18007074
#define set_PLL_ETN_reg(data)   (*((volatile unsigned int*) PLL_ETN_reg)=data)
#define get_PLL_ETN_reg   (*((volatile unsigned int*) PLL_ETN_reg))
#define PLL_ETN_inst_adr                                                             "0x001D"
#define PLL_ETN_inst                                                                 0x001D
#define PLL_ETN_PLLETN_OEB_shift                                                     (27)
#define PLL_ETN_PLLETN_OEB_mask                                                      (0x08000000)
#define PLL_ETN_PLLETN_OEB(data)                                                     (0x08000000&((data)<<27))
#define PLL_ETN_PLLETN_OEB_src(data)                                                 ((0x08000000&(data))>>27)
#define PLL_ETN_get_PLLETN_OEB(data)                                                 ((0x08000000&(data))>>27)
#define PLL_ETN_PLLETN_RSTB_shift                                                    (26)
#define PLL_ETN_PLLETN_RSTB_mask                                                     (0x04000000)
#define PLL_ETN_PLLETN_RSTB(data)                                                    (0x04000000&((data)<<26))
#define PLL_ETN_PLLETN_RSTB_src(data)                                                ((0x04000000&(data))>>26)
#define PLL_ETN_get_PLLETN_RSTB(data)                                                ((0x04000000&(data))>>26)
#define PLL_ETN_PLLETN_O_shift                                                       (22)
#define PLL_ETN_PLLETN_O_mask                                                        (0x03C00000)
#define PLL_ETN_PLLETN_O(data)                                                       (0x03C00000&((data)<<22))
#define PLL_ETN_PLLETN_O_src(data)                                                   ((0x03C00000&(data))>>22)
#define PLL_ETN_get_PLLETN_O(data)                                                   ((0x03C00000&(data))>>22)
#define PLL_ETN_PLLETN_M_shift                                                       (15)
#define PLL_ETN_PLLETN_M_mask                                                        (0x003F8000)
#define PLL_ETN_PLLETN_M(data)                                                       (0x003F8000&((data)<<15))
#define PLL_ETN_PLLETN_M_src(data)                                                   ((0x003F8000&(data))>>15)
#define PLL_ETN_get_PLLETN_M(data)                                                   ((0x003F8000&(data))>>15)
#define PLL_ETN_PLLETN_LDO_POW_shift                                                 (14)
#define PLL_ETN_PLLETN_LDO_POW_mask                                                  (0x00004000)
#define PLL_ETN_PLLETN_LDO_POW(data)                                                 (0x00004000&((data)<<14))
#define PLL_ETN_PLLETN_LDO_POW_src(data)                                             ((0x00004000&(data))>>14)
#define PLL_ETN_get_PLLETN_LDO_POW(data)                                             ((0x00004000&(data))>>14)
#define PLL_ETN_PLLETN_POW_shift                                                     (13)
#define PLL_ETN_PLLETN_POW_mask                                                      (0x00002000)
#define PLL_ETN_PLLETN_POW(data)                                                     (0x00002000&((data)<<13))
#define PLL_ETN_PLLETN_POW_src(data)                                                 ((0x00002000&(data))>>13)
#define PLL_ETN_get_PLLETN_POW(data)                                                 ((0x00002000&(data))>>13)
#define PLL_ETN_PLLETN_LDO_SEL_shift                                                 (11)
#define PLL_ETN_PLLETN_LDO_SEL_mask                                                  (0x00001800)
#define PLL_ETN_PLLETN_LDO_SEL(data)                                                 (0x00001800&((data)<<11))
#define PLL_ETN_PLLETN_LDO_SEL_src(data)                                             ((0x00001800&(data))>>11)
#define PLL_ETN_get_PLLETN_LDO_SEL(data)                                             ((0x00001800&(data))>>11)
#define PLL_ETN_PLLETN_WDMODE_shift                                                  (9)
#define PLL_ETN_PLLETN_WDMODE_mask                                                   (0x00000600)
#define PLL_ETN_PLLETN_WDMODE(data)                                                  (0x00000600&((data)<<9))
#define PLL_ETN_PLLETN_WDMODE_src(data)                                              ((0x00000600&(data))>>9)
#define PLL_ETN_get_PLLETN_WDMODE(data)                                              ((0x00000600&(data))>>9)
#define PLL_ETN_PLLETN_N_shift                                                       (7)
#define PLL_ETN_PLLETN_N_mask                                                        (0x00000180)
#define PLL_ETN_PLLETN_N(data)                                                       (0x00000180&((data)<<7))
#define PLL_ETN_PLLETN_N_src(data)                                                   ((0x00000180&(data))>>7)
#define PLL_ETN_get_PLLETN_N(data)                                                   ((0x00000180&(data))>>7)
#define PLL_ETN_PLLETN_LF_RS_shift                                                   (5)
#define PLL_ETN_PLLETN_LF_RS_mask                                                    (0x00000060)
#define PLL_ETN_PLLETN_LF_RS(data)                                                   (0x00000060&((data)<<5))
#define PLL_ETN_PLLETN_LF_RS_src(data)                                               ((0x00000060&(data))>>5)
#define PLL_ETN_get_PLLETN_LF_RS(data)                                               ((0x00000060&(data))>>5)
#define PLL_ETN_PLLETN_LF_CP_shift                                                   (3)
#define PLL_ETN_PLLETN_LF_CP_mask                                                    (0x00000018)
#define PLL_ETN_PLLETN_LF_CP(data)                                                   (0x00000018&((data)<<3))
#define PLL_ETN_PLLETN_LF_CP_src(data)                                               ((0x00000018&(data))>>3)
#define PLL_ETN_get_PLLETN_LF_CP(data)                                               ((0x00000018&(data))>>3)
#define PLL_ETN_PLLETN_IP_shift                                                      (0)
#define PLL_ETN_PLLETN_IP_mask                                                       (0x00000007)
#define PLL_ETN_PLLETN_IP(data)                                                      (0x00000007&((data)<<0))
#define PLL_ETN_PLLETN_IP_src(data)                                                  ((0x00000007&(data))>>0)
#define PLL_ETN_get_PLLETN_IP(data)                                                  ((0x00000007&(data))>>0)


#define RESERVED_USE_1                                                               0x18007078
#define RESERVED_USE_1_reg_addr                                                      "0x18007078"
#define RESERVED_USE_1_reg                                                           0x18007078
#define set_RESERVED_USE_1_reg(data)   (*((volatile unsigned int*) RESERVED_USE_1_reg)=data)
#define get_RESERVED_USE_1_reg   (*((volatile unsigned int*) RESERVED_USE_1_reg))
#define RESERVED_USE_1_inst_adr                                                      "0x001E"
#define RESERVED_USE_1_inst                                                          0x001E
#define RESERVED_USE_1_DMY_shift                                                     (0)
#define RESERVED_USE_1_DMY_mask                                                      (0xFFFFFFFF)
#define RESERVED_USE_1_DMY(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESERVED_USE_1_DMY_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESERVED_USE_1_get_DMY(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define RESERVED_USE_2                                                               0x1800707C
#define RESERVED_USE_2_reg_addr                                                      "0x1800707C"
#define RESERVED_USE_2_reg                                                           0x1800707C
#define set_RESERVED_USE_2_reg(data)   (*((volatile unsigned int*) RESERVED_USE_2_reg)=data)
#define get_RESERVED_USE_2_reg   (*((volatile unsigned int*) RESERVED_USE_2_reg))
#define RESERVED_USE_2_inst_adr                                                      "0x001F"
#define RESERVED_USE_2_inst                                                          0x001F
#define RESERVED_USE_2_DMY_shift                                                     (0)
#define RESERVED_USE_2_DMY_mask                                                      (0xFFFFFFFF)
#define RESERVED_USE_2_DMY(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESERVED_USE_2_DMY_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESERVED_USE_2_get_DMY(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define RESERVED_USE_3                                                               0x18007080
#define RESERVED_USE_3_reg_addr                                                      "0x18007080"
#define RESERVED_USE_3_reg                                                           0x18007080
#define set_RESERVED_USE_3_reg(data)   (*((volatile unsigned int*) RESERVED_USE_3_reg)=data)
#define get_RESERVED_USE_3_reg   (*((volatile unsigned int*) RESERVED_USE_3_reg))
#define RESERVED_USE_3_inst_adr                                                      "0x0020"
#define RESERVED_USE_3_inst                                                          0x0020
#define RESERVED_USE_3_DMY_shift                                                     (0)
#define RESERVED_USE_3_DMY_mask                                                      (0xFFFFFFFF)
#define RESERVED_USE_3_DMY(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESERVED_USE_3_DMY_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESERVED_USE_3_get_DMY(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define I2C0_SDA_DEL                                                                 0x18007084
#define I2C0_SDA_DEL_reg_addr                                                        "0x18007084"
#define I2C0_SDA_DEL_reg                                                             0x18007084
#define set_I2C0_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C0_SDA_DEL_reg)=data)
#define get_I2C0_SDA_DEL_reg   (*((volatile unsigned int*) I2C0_SDA_DEL_reg))
#define I2C0_SDA_DEL_inst_adr                                                        "0x0021"
#define I2C0_SDA_DEL_inst                                                            0x0021
#define I2C0_SDA_DEL_dmy1_shift                                                      (12)
#define I2C0_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C0_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C0_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C0_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C0_SDA_DEL_en_shift                                                        (8)
#define I2C0_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C0_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C0_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C0_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C0_SDA_DEL_sel_shift                                                       (0)
#define I2C0_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C0_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C0_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C0_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define SOFT_RESET                                                                   0x18007088
#define SOFT_RESET_reg_addr                                                          "0x18007088"
#define SOFT_RESET_reg                                                               0x18007088
#define set_SOFT_RESET_reg(data)   (*((volatile unsigned int*) SOFT_RESET_reg)=data)
#define get_SOFT_RESET_reg   (*((volatile unsigned int*) SOFT_RESET_reg))
#define SOFT_RESET_inst_adr                                                          "0x0022"
#define SOFT_RESET_inst                                                              0x0022
#define SOFT_RESET_rstn_cbus_shift                                                   (13)
#define SOFT_RESET_rstn_cbus_mask                                                    (0x00002000)
#define SOFT_RESET_rstn_cbus(data)                                                   (0x00002000&((data)<<13))
#define SOFT_RESET_rstn_cbus_src(data)                                               ((0x00002000&(data))>>13)
#define SOFT_RESET_get_rstn_cbus(data)                                               ((0x00002000&(data))>>13)
#define SOFT_RESET_rstn_i2c_6_shift                                                  (12)
#define SOFT_RESET_rstn_i2c_6_mask                                                   (0x00001000)
#define SOFT_RESET_rstn_i2c_6(data)                                                  (0x00001000&((data)<<12))
#define SOFT_RESET_rstn_i2c_6_src(data)                                              ((0x00001000&(data))>>12)
#define SOFT_RESET_get_rstn_i2c_6(data)                                              ((0x00001000&(data))>>12)
#define SOFT_RESET_rstn_i2c_0_shift                                                  (11)
#define SOFT_RESET_rstn_i2c_0_mask                                                   (0x00000800)
#define SOFT_RESET_rstn_i2c_0(data)                                                  (0x00000800&((data)<<11))
#define SOFT_RESET_rstn_i2c_0_src(data)                                              ((0x00000800&(data))>>11)
#define SOFT_RESET_get_rstn_i2c_0(data)                                              ((0x00000800&(data))>>11)
#define SOFT_RESET_rstn_gphy_shift                                                   (10)
#define SOFT_RESET_rstn_gphy_mask                                                    (0x00000400)
#define SOFT_RESET_rstn_gphy(data)                                                   (0x00000400&((data)<<10))
#define SOFT_RESET_rstn_gphy_src(data)                                               ((0x00000400&(data))>>10)
#define SOFT_RESET_get_rstn_gphy(data)                                               ((0x00000400&(data))>>10)
#define SOFT_RESET_rstn_gmac_shift                                                   (9)
#define SOFT_RESET_rstn_gmac_mask                                                    (0x00000200)
#define SOFT_RESET_rstn_gmac(data)                                                   (0x00000200&((data)<<9))
#define SOFT_RESET_rstn_gmac_src(data)                                               ((0x00000200&(data))>>9)
#define SOFT_RESET_get_rstn_gmac(data)                                               ((0x00000200&(data))>>9)
#define SOFT_RESET_rstn_ur0_shift                                                    (8)
#define SOFT_RESET_rstn_ur0_mask                                                     (0x00000100)
#define SOFT_RESET_rstn_ur0(data)                                                    (0x00000100&((data)<<8))
#define SOFT_RESET_rstn_ur0_src(data)                                                ((0x00000100&(data))>>8)
#define SOFT_RESET_get_rstn_ur0(data)                                                ((0x00000100&(data))>>8)
#define SOFT_RESET_rstn_efuse_shift                                                  (7)
#define SOFT_RESET_rstn_efuse_mask                                                   (0x00000080)
#define SOFT_RESET_rstn_efuse(data)                                                  (0x00000080&((data)<<7))
#define SOFT_RESET_rstn_efuse_src(data)                                              ((0x00000080&(data))>>7)
#define SOFT_RESET_get_rstn_efuse(data)                                              ((0x00000080&(data))>>7)
#define SOFT_RESET_rstn_cbusrx_shift                                                 (6)
#define SOFT_RESET_rstn_cbusrx_mask                                                  (0x00000040)
#define SOFT_RESET_rstn_cbusrx(data)                                                 (0x00000040&((data)<<6))
#define SOFT_RESET_rstn_cbusrx_src(data)                                             ((0x00000040&(data))>>6)
#define SOFT_RESET_get_rstn_cbusrx(data)                                             ((0x00000040&(data))>>6)
#define SOFT_RESET_rstn_cbustx_shift                                                 (5)
#define SOFT_RESET_rstn_cbustx_mask                                                  (0x00000020)
#define SOFT_RESET_rstn_cbustx(data)                                                 (0x00000020&((data)<<5))
#define SOFT_RESET_rstn_cbustx_src(data)                                             ((0x00000020&(data))>>5)
#define SOFT_RESET_get_rstn_cbustx(data)                                             ((0x00000020&(data))>>5)
#define SOFT_RESET_rstn_dp_shift                                                     (4)
#define SOFT_RESET_rstn_dp_mask                                                      (0x00000010)
#define SOFT_RESET_rstn_dp(data)                                                     (0x00000010&((data)<<4))
#define SOFT_RESET_rstn_dp_src(data)                                                 ((0x00000010&(data))>>4)
#define SOFT_RESET_get_rstn_dp(data)                                                 ((0x00000010&(data))>>4)
#define SOFT_RESET_rstn_cec1_shift                                                   (3)
#define SOFT_RESET_rstn_cec1_mask                                                    (0x00000008)
#define SOFT_RESET_rstn_cec1(data)                                                   (0x00000008&((data)<<3))
#define SOFT_RESET_rstn_cec1_src(data)                                               ((0x00000008&(data))>>3)
#define SOFT_RESET_get_rstn_cec1(data)                                               ((0x00000008&(data))>>3)
#define SOFT_RESET_rstn_cec0_shift                                                   (2)
#define SOFT_RESET_rstn_cec0_mask                                                    (0x00000004)
#define SOFT_RESET_rstn_cec0(data)                                                   (0x00000004&((data)<<2))
#define SOFT_RESET_rstn_cec0_src(data)                                               ((0x00000004&(data))>>2)
#define SOFT_RESET_get_rstn_cec0(data)                                               ((0x00000004&(data))>>2)
#define SOFT_RESET_rstn_ir_shift                                                     (1)
#define SOFT_RESET_rstn_ir_mask                                                      (0x00000002)
#define SOFT_RESET_rstn_ir(data)                                                     (0x00000002&((data)<<1))
#define SOFT_RESET_rstn_ir_src(data)                                                 ((0x00000002&(data))>>1)
#define SOFT_RESET_get_rstn_ir(data)                                                 ((0x00000002&(data))>>1)
#define SOFT_RESET_rstn_vfd_shift                                                    (0)
#define SOFT_RESET_rstn_vfd_mask                                                     (0x00000001)
#define SOFT_RESET_rstn_vfd(data)                                                    (0x00000001&((data)<<0))
#define SOFT_RESET_rstn_vfd_src(data)                                                ((0x00000001&(data))>>0)
#define SOFT_RESET_get_rstn_vfd(data)                                                ((0x00000001&(data))>>0)


#define CLOCK_ENABLE                                                                 0x1800708C
#define CLOCK_ENABLE_reg_addr                                                        "0x1800708C"
#define CLOCK_ENABLE_reg                                                             0x1800708C
#define set_CLOCK_ENABLE_reg(data)   (*((volatile unsigned int*) CLOCK_ENABLE_reg)=data)
#define get_CLOCK_ENABLE_reg   (*((volatile unsigned int*) CLOCK_ENABLE_reg))
#define CLOCK_ENABLE_inst_adr                                                        "0x0023"
#define CLOCK_ENABLE_inst                                                            0x0023
#define CLOCK_ENABLE_clk_en_etn_sys_shift                                            (12)
#define CLOCK_ENABLE_clk_en_etn_sys_mask                                             (0x00001000)
#define CLOCK_ENABLE_clk_en_etn_sys(data)                                            (0x00001000&((data)<<12))
#define CLOCK_ENABLE_clk_en_etn_sys_src(data)                                        ((0x00001000&(data))>>12)
#define CLOCK_ENABLE_get_clk_en_etn_sys(data)                                        ((0x00001000&(data))>>12)
#define CLOCK_ENABLE_clk_en_etn_250m_shift                                           (11)
#define CLOCK_ENABLE_clk_en_etn_250m_mask                                            (0x00000800)
#define CLOCK_ENABLE_clk_en_etn_250m(data)                                           (0x00000800&((data)<<11))
#define CLOCK_ENABLE_clk_en_etn_250m_src(data)                                       ((0x00000800&(data))>>11)
#define CLOCK_ENABLE_get_clk_en_etn_250m(data)                                       ((0x00000800&(data))>>11)
#define CLOCK_ENABLE_clk_en_i2c6_shift                                               (10)
#define CLOCK_ENABLE_clk_en_i2c6_mask                                                (0x00000400)
#define CLOCK_ENABLE_clk_en_i2c6(data)                                               (0x00000400&((data)<<10))
#define CLOCK_ENABLE_clk_en_i2c6_src(data)                                           ((0x00000400&(data))>>10)
#define CLOCK_ENABLE_get_clk_en_i2c6(data)                                           ((0x00000400&(data))>>10)
#define CLOCK_ENABLE_clk_en_i2c0_shift                                               (9)
#define CLOCK_ENABLE_clk_en_i2c0_mask                                                (0x00000200)
#define CLOCK_ENABLE_clk_en_i2c0(data)                                               (0x00000200&((data)<<9))
#define CLOCK_ENABLE_clk_en_i2c0_src(data)                                           ((0x00000200&(data))>>9)
#define CLOCK_ENABLE_get_clk_en_i2c0(data)                                           ((0x00000200&(data))>>9)
#define CLOCK_ENABLE_clk_en_misc_ur0_shift                                           (8)
#define CLOCK_ENABLE_clk_en_misc_ur0_mask                                            (0x00000100)
#define CLOCK_ENABLE_clk_en_misc_ur0(data)                                           (0x00000100&((data)<<8))
#define CLOCK_ENABLE_clk_en_misc_ur0_src(data)                                       ((0x00000100&(data))>>8)
#define CLOCK_ENABLE_get_clk_en_misc_ur0(data)                                       ((0x00000100&(data))>>8)
#define CLOCK_ENABLE_clk_en_misc_ir_shift                                            (7)
#define CLOCK_ENABLE_clk_en_misc_ir_mask                                             (0x00000080)
#define CLOCK_ENABLE_clk_en_misc_ir(data)                                            (0x00000080&((data)<<7))
#define CLOCK_ENABLE_clk_en_misc_ir_src(data)                                        ((0x00000080&(data))>>7)
#define CLOCK_ENABLE_get_clk_en_misc_ir(data)                                        ((0x00000080&(data))>>7)
#define CLOCK_ENABLE_clk_en_cbus_osc_shift                                           (6)
#define CLOCK_ENABLE_clk_en_cbus_osc_mask                                            (0x00000040)
#define CLOCK_ENABLE_clk_en_cbus_osc(data)                                           (0x00000040&((data)<<6))
#define CLOCK_ENABLE_clk_en_cbus_osc_src(data)                                       ((0x00000040&(data))>>6)
#define CLOCK_ENABLE_get_clk_en_cbus_osc(data)                                       ((0x00000040&(data))>>6)
#define CLOCK_ENABLE_clk_en_cbus_sys_shift                                           (5)
#define CLOCK_ENABLE_clk_en_cbus_sys_mask                                            (0x00000020)
#define CLOCK_ENABLE_clk_en_cbus_sys(data)                                           (0x00000020&((data)<<5))
#define CLOCK_ENABLE_clk_en_cbus_sys_src(data)                                       ((0x00000020&(data))>>5)
#define CLOCK_ENABLE_get_clk_en_cbus_sys(data)                                       ((0x00000020&(data))>>5)
#define CLOCK_ENABLE_clk_en_cbustx_sys_shift                                         (4)
#define CLOCK_ENABLE_clk_en_cbustx_sys_mask                                          (0x00000010)
#define CLOCK_ENABLE_clk_en_cbustx_sys(data)                                         (0x00000010&((data)<<4))
#define CLOCK_ENABLE_clk_en_cbustx_sys_src(data)                                     ((0x00000010&(data))>>4)
#define CLOCK_ENABLE_get_clk_en_cbustx_sys(data)                                     ((0x00000010&(data))>>4)
#define CLOCK_ENABLE_clk_en_cbusrx_sys_shift                                         (3)
#define CLOCK_ENABLE_clk_en_cbusrx_sys_mask                                          (0x00000008)
#define CLOCK_ENABLE_clk_en_cbusrx_sys(data)                                         (0x00000008&((data)<<3))
#define CLOCK_ENABLE_clk_en_cbusrx_sys_src(data)                                     ((0x00000008&(data))>>3)
#define CLOCK_ENABLE_get_clk_en_cbusrx_sys(data)                                     ((0x00000008&(data))>>3)
#define CLOCK_ENABLE_clk_en_misc_cec0_shift                                          (2)
#define CLOCK_ENABLE_clk_en_misc_cec0_mask                                           (0x00000004)
#define CLOCK_ENABLE_clk_en_misc_cec0(data)                                          (0x00000004&((data)<<2))
#define CLOCK_ENABLE_clk_en_misc_cec0_src(data)                                      ((0x00000004&(data))>>2)
#define CLOCK_ENABLE_get_clk_en_misc_cec0(data)                                      ((0x00000004&(data))>>2)
#define CLOCK_ENABLE_clk_en_misc_vfd_shift                                           (1)
#define CLOCK_ENABLE_clk_en_misc_vfd_mask                                            (0x00000002)
#define CLOCK_ENABLE_clk_en_misc_vfd(data)                                           (0x00000002&((data)<<1))
#define CLOCK_ENABLE_clk_en_misc_vfd_src(data)                                       ((0x00000002&(data))>>1)
#define CLOCK_ENABLE_get_clk_en_misc_vfd(data)                                       ((0x00000002&(data))>>1)
#define CLOCK_ENABLE_clk_en_misc_mix_shift                                           (0)
#define CLOCK_ENABLE_clk_en_misc_mix_mask                                            (0x00000001)
#define CLOCK_ENABLE_clk_en_misc_mix(data)                                           (0x00000001&((data)<<0))
#define CLOCK_ENABLE_clk_en_misc_mix_src(data)                                       ((0x00000001&(data))>>0)
#define CLOCK_ENABLE_get_clk_en_misc_mix(data)                                       ((0x00000001&(data))>>0)


#define DC_0                                                                         0x18007090
#define DC_0_reg_addr                                                                "0x18007090"
#define DC_0_reg                                                                     0x18007090
#define set_DC_0_reg(data)   (*((volatile unsigned int*) DC_0_reg)=data)
#define get_DC_0_reg   (*((volatile unsigned int*) DC_0_reg))
#define DC_0_inst_adr                                                                "0x0024"
#define DC_0_inst                                                                    0x0024
#define DC_0_rd_only_0_en_shift                                                      (24)
#define DC_0_rd_only_0_en_mask                                                       (0x01000000)
#define DC_0_rd_only_0_en(data)                                                      (0x01000000&((data)<<24))
#define DC_0_rd_only_0_en_src(data)                                                  ((0x01000000&(data))>>24)
#define DC_0_get_rd_only_0_en(data)                                                  ((0x01000000&(data))>>24)
#define DC_0_blk_protect_0_wpro_en_shift                                             (21)
#define DC_0_blk_protect_0_wpro_en_mask                                              (0x00200000)
#define DC_0_blk_protect_0_wpro_en(data)                                             (0x00200000&((data)<<21))
#define DC_0_blk_protect_0_wpro_en_src(data)                                         ((0x00200000&(data))>>21)
#define DC_0_get_blk_protect_0_wpro_en(data)                                         ((0x00200000&(data))>>21)
#define DC_0_blk_protect_0_en_shift                                                  (18)
#define DC_0_blk_protect_0_en_mask                                                   (0x00040000)
#define DC_0_blk_protect_0_en(data)                                                  (0x00040000&((data)<<18))
#define DC_0_blk_protect_0_en_src(data)                                              ((0x00040000&(data))>>18)
#define DC_0_get_blk_protect_0_en(data)                                              ((0x00040000&(data))>>18)
#define DC_0_protect_0_wpro_en_shift                                                 (9)
#define DC_0_protect_0_wpro_en_mask                                                  (0x00000200)
#define DC_0_protect_0_wpro_en(data)                                                 (0x00000200&((data)<<9))
#define DC_0_protect_0_wpro_en_src(data)                                             ((0x00000200&(data))>>9)
#define DC_0_get_protect_0_wpro_en(data)                                             ((0x00000200&(data))>>9)
#define DC_0_protect_0_en_shift                                                      (0)
#define DC_0_protect_0_en_mask                                                       (0x00000001)
#define DC_0_protect_0_en(data)                                                      (0x00000001&((data)<<0))
#define DC_0_protect_0_en_src(data)                                                  ((0x00000001&(data))>>0)
#define DC_0_get_protect_0_en(data)                                                  ((0x00000001&(data))>>0)


#define DC_1                                                                         0x18007094
#define DC_1_reg_addr                                                                "0x18007094"
#define DC_1_reg                                                                     0x18007094
#define set_DC_1_reg(data)   (*((volatile unsigned int*) DC_1_reg)=data)
#define get_DC_1_reg   (*((volatile unsigned int*) DC_1_reg))
#define DC_1_inst_adr                                                                "0x0025"
#define DC_1_inst                                                                    0x0025
#define DC_1_mem_saddr0_shift                                                        (12)
#define DC_1_mem_saddr0_mask                                                         (0xFFFFF000)
#define DC_1_mem_saddr0(data)                                                        (0xFFFFF000&((data)<<12))
#define DC_1_mem_saddr0_src(data)                                                    ((0xFFFFF000&(data))>>12)
#define DC_1_get_mem_saddr0(data)                                                    ((0xFFFFF000&(data))>>12)


#define DC_2                                                                         0x18007098
#define DC_2_reg_addr                                                                "0x18007098"
#define DC_2_reg                                                                     0x18007098
#define set_DC_2_reg(data)   (*((volatile unsigned int*) DC_2_reg)=data)
#define get_DC_2_reg   (*((volatile unsigned int*) DC_2_reg))
#define DC_2_inst_adr                                                                "0x0026"
#define DC_2_inst                                                                    0x0026
#define DC_2_mem_eaddr0_shift                                                        (12)
#define DC_2_mem_eaddr0_mask                                                         (0xFFFFF000)
#define DC_2_mem_eaddr0(data)                                                        (0xFFFFF000&((data)<<12))
#define DC_2_mem_eaddr0_src(data)                                                    ((0xFFFFF000&(data))>>12)
#define DC_2_get_mem_eaddr0(data)                                                    ((0xFFFFF000&(data))>>12)


#define DC_3                                                                         0x1800709C
#define DC_3_reg_addr                                                                "0x1800709C"
#define DC_3_reg                                                                     0x1800709C
#define set_DC_3_reg(data)   (*((volatile unsigned int*) DC_3_reg)=data)
#define get_DC_3_reg   (*((volatile unsigned int*) DC_3_reg))
#define DC_3_inst_adr                                                                "0x0027"
#define DC_3_inst                                                                    0x0027
#define DC_3_blk_saddr0_shift                                                        (12)
#define DC_3_blk_saddr0_mask                                                         (0xFFFFF000)
#define DC_3_blk_saddr0(data)                                                        (0xFFFFF000&((data)<<12))
#define DC_3_blk_saddr0_src(data)                                                    ((0xFFFFF000&(data))>>12)
#define DC_3_get_blk_saddr0(data)                                                    ((0xFFFFF000&(data))>>12)


#define DC_4                                                                         0x180070A0
#define DC_4_reg_addr                                                                "0x180070A0"
#define DC_4_reg                                                                     0x180070A0
#define set_DC_4_reg(data)   (*((volatile unsigned int*) DC_4_reg)=data)
#define get_DC_4_reg   (*((volatile unsigned int*) DC_4_reg))
#define DC_4_inst_adr                                                                "0x0028"
#define DC_4_inst                                                                    0x0028
#define DC_4_blk_eaddr0_shift                                                        (12)
#define DC_4_blk_eaddr0_mask                                                         (0xFFFFF000)
#define DC_4_blk_eaddr0(data)                                                        (0xFFFFF000&((data)<<12))
#define DC_4_blk_eaddr0_src(data)                                                    ((0xFFFFF000&(data))>>12)
#define DC_4_get_blk_eaddr0(data)                                                    ((0xFFFFF000&(data))>>12)


#define DC_5                                                                         0x180070A4
#define DC_5_reg_addr                                                                "0x180070A4"
#define DC_5_reg                                                                     0x180070A4
#define set_DC_5_reg(data)   (*((volatile unsigned int*) DC_5_reg)=data)
#define get_DC_5_reg   (*((volatile unsigned int*) DC_5_reg))
#define DC_5_inst_adr                                                                "0x0029"
#define DC_5_inst                                                                    0x0029
#define DC_5_ro_saddr0_shift                                                         (12)
#define DC_5_ro_saddr0_mask                                                          (0xFFFFF000)
#define DC_5_ro_saddr0(data)                                                         (0xFFFFF000&((data)<<12))
#define DC_5_ro_saddr0_src(data)                                                     ((0xFFFFF000&(data))>>12)
#define DC_5_get_ro_saddr0(data)                                                     ((0xFFFFF000&(data))>>12)


#define DC_6                                                                         0x180070A8
#define DC_6_reg_addr                                                                "0x180070A8"
#define DC_6_reg                                                                     0x180070A8
#define set_DC_6_reg(data)   (*((volatile unsigned int*) DC_6_reg)=data)
#define get_DC_6_reg   (*((volatile unsigned int*) DC_6_reg))
#define DC_6_inst_adr                                                                "0x002A"
#define DC_6_inst                                                                    0x002A
#define DC_6_ro_eaddr0_shift                                                         (12)
#define DC_6_ro_eaddr0_mask                                                          (0xFFFFF000)
#define DC_6_ro_eaddr0(data)                                                         (0xFFFFF000&((data)<<12))
#define DC_6_ro_eaddr0_src(data)                                                     ((0xFFFFF000&(data))>>12)
#define DC_6_get_ro_eaddr0(data)                                                     ((0xFFFFF000&(data))>>12)


#define DC_7                                                                         0x180070AC
#define DC_7_reg_addr                                                                "0x180070AC"
#define DC_7_reg                                                                     0x180070AC
#define set_DC_7_reg(data)   (*((volatile unsigned int*) DC_7_reg)=data)
#define get_DC_7_reg   (*((volatile unsigned int*) DC_7_reg))
#define DC_7_inst_adr                                                                "0x002B"
#define DC_7_inst                                                                    0x002B
#define DC_7_md_tee_protect_en_shift                                                 (24)
#define DC_7_md_tee_protect_en_mask                                                  (0x01000000)
#define DC_7_md_tee_protect_en(data)                                                 (0x01000000&((data)<<24))
#define DC_7_md_tee_protect_en_src(data)                                             ((0x01000000&(data))>>24)
#define DC_7_get_md_tee_protect_en(data)                                             ((0x01000000&(data))>>24)
#define DC_7_cp_tee_protect_en_shift                                                 (16)
#define DC_7_cp_tee_protect_en_mask                                                  (0x00010000)
#define DC_7_cp_tee_protect_en(data)                                                 (0x00010000&((data)<<16))
#define DC_7_cp_tee_protect_en_src(data)                                             ((0x00010000&(data))>>16)
#define DC_7_get_cp_tee_protect_en(data)                                             ((0x00010000&(data))>>16)
#define DC_7_vo_protect_en_shift                                                     (8)
#define DC_7_vo_protect_en_mask                                                      (0x00000100)
#define DC_7_vo_protect_en(data)                                                     (0x00000100&((data)<<8))
#define DC_7_vo_protect_en_src(data)                                                 ((0x00000100&(data))>>8)
#define DC_7_get_vo_protect_en(data)                                                 ((0x00000100&(data))>>8)
#define DC_7_nf_tee_protect_en_shift                                                 (0)
#define DC_7_nf_tee_protect_en_mask                                                  (0x00000001)
#define DC_7_nf_tee_protect_en(data)                                                 (0x00000001&((data)<<0))
#define DC_7_nf_tee_protect_en_src(data)                                             ((0x00000001&(data))>>0)
#define DC_7_get_nf_tee_protect_en(data)                                             ((0x00000001&(data))>>0)


#define DC_8                                                                         0x180070B0
#define DC_8_reg_addr                                                                "0x180070B0"
#define DC_8_reg                                                                     0x180070B0
#define set_DC_8_reg(data)   (*((volatile unsigned int*) DC_8_reg)=data)
#define get_DC_8_reg   (*((volatile unsigned int*) DC_8_reg))
#define DC_8_inst_adr                                                                "0x002C"
#define DC_8_inst                                                                    0x002C
#define DC_8_scpu_tee_protect_en_shift                                               (24)
#define DC_8_scpu_tee_protect_en_mask                                                (0x01000000)
#define DC_8_scpu_tee_protect_en(data)                                               (0x01000000&((data)<<24))
#define DC_8_scpu_tee_protect_en_src(data)                                           ((0x01000000&(data))>>24)
#define DC_8_get_scpu_tee_protect_en(data)                                           ((0x01000000&(data))>>24)
#define DC_8_acpu_protect_en_shift                                                   (16)
#define DC_8_acpu_protect_en_mask                                                    (0x00010000)
#define DC_8_acpu_protect_en(data)                                                   (0x00010000&((data)<<16))
#define DC_8_acpu_protect_en_src(data)                                               ((0x00010000&(data))>>16)
#define DC_8_get_acpu_protect_en(data)                                               ((0x00010000&(data))>>16)
#define DC_8_video_protect_en_shift                                                  (8)
#define DC_8_video_protect_en_mask                                                   (0x00000100)
#define DC_8_video_protect_en(data)                                                  (0x00000100&((data)<<8))
#define DC_8_video_protect_en_src(data)                                              ((0x00000100&(data))>>8)
#define DC_8_get_video_protect_en(data)                                              ((0x00000100&(data))>>8)
#define DC_8_audio_protect_en_shift                                                  (0)
#define DC_8_audio_protect_en_mask                                                   (0x00000001)
#define DC_8_audio_protect_en(data)                                                  (0x00000001&((data)<<0))
#define DC_8_audio_protect_en_src(data)                                              ((0x00000001&(data))>>0)
#define DC_8_get_audio_protect_en(data)                                              ((0x00000001&(data))>>0)


#define DC_9                                                                         0x180070B4
#define DC_9_reg_addr                                                                "0x180070B4"
#define DC_9_reg                                                                     0x180070B4
#define set_DC_9_reg(data)   (*((volatile unsigned int*) DC_9_reg)=data)
#define get_DC_9_reg   (*((volatile unsigned int*) DC_9_reg))
#define DC_9_inst_adr                                                                "0x002D"
#define DC_9_inst                                                                    0x002D
#define DC_9_scpu_tee_blk_protect_en_shift                                           (14)
#define DC_9_scpu_tee_blk_protect_en_mask                                            (0x00004000)
#define DC_9_scpu_tee_blk_protect_en(data)                                           (0x00004000&((data)<<14))
#define DC_9_scpu_tee_blk_protect_en_src(data)                                       ((0x00004000&(data))>>14)
#define DC_9_get_scpu_tee_blk_protect_en(data)                                       ((0x00004000&(data))>>14)
#define DC_9_acpu_blk_protect_en_shift                                               (12)
#define DC_9_acpu_blk_protect_en_mask                                                (0x00001000)
#define DC_9_acpu_blk_protect_en(data)                                               (0x00001000&((data)<<12))
#define DC_9_acpu_blk_protect_en_src(data)                                           ((0x00001000&(data))>>12)
#define DC_9_get_acpu_blk_protect_en(data)                                           ((0x00001000&(data))>>12)
#define DC_9_video_blk_protect_en_shift                                              (10)
#define DC_9_video_blk_protect_en_mask                                               (0x00000400)
#define DC_9_video_blk_protect_en(data)                                              (0x00000400&((data)<<10))
#define DC_9_video_blk_protect_en_src(data)                                          ((0x00000400&(data))>>10)
#define DC_9_get_video_blk_protect_en(data)                                          ((0x00000400&(data))>>10)
#define DC_9_audio_blk_protect_en_shift                                              (8)
#define DC_9_audio_blk_protect_en_mask                                               (0x00000100)
#define DC_9_audio_blk_protect_en(data)                                              (0x00000100&((data)<<8))
#define DC_9_audio_blk_protect_en_src(data)                                          ((0x00000100&(data))>>8)
#define DC_9_get_audio_blk_protect_en(data)                                          ((0x00000100&(data))>>8)
#define DC_9_md_tee_blk_protect_en_shift                                             (6)
#define DC_9_md_tee_blk_protect_en_mask                                              (0x00000040)
#define DC_9_md_tee_blk_protect_en(data)                                             (0x00000040&((data)<<6))
#define DC_9_md_tee_blk_protect_en_src(data)                                         ((0x00000040&(data))>>6)
#define DC_9_get_md_tee_blk_protect_en(data)                                         ((0x00000040&(data))>>6)
#define DC_9_cp_tee_blk_protect_en_shift                                             (4)
#define DC_9_cp_tee_blk_protect_en_mask                                              (0x00000010)
#define DC_9_cp_tee_blk_protect_en(data)                                             (0x00000010&((data)<<4))
#define DC_9_cp_tee_blk_protect_en_src(data)                                         ((0x00000010&(data))>>4)
#define DC_9_get_cp_tee_blk_protect_en(data)                                         ((0x00000010&(data))>>4)
#define DC_9_vo_blk_protect_en_shift                                                 (2)
#define DC_9_vo_blk_protect_en_mask                                                  (0x00000004)
#define DC_9_vo_blk_protect_en(data)                                                 (0x00000004&((data)<<2))
#define DC_9_vo_blk_protect_en_src(data)                                             ((0x00000004&(data))>>2)
#define DC_9_get_vo_blk_protect_en(data)                                             ((0x00000004&(data))>>2)
#define DC_9_nf_tee_blk_protect_en_shift                                             (0)
#define DC_9_nf_tee_blk_protect_en_mask                                              (0x00000001)
#define DC_9_nf_tee_blk_protect_en(data)                                             (0x00000001&((data)<<0))
#define DC_9_nf_tee_blk_protect_en_src(data)                                         ((0x00000001&(data))>>0)
#define DC_9_get_nf_tee_blk_protect_en(data)                                         ((0x00000001&(data))>>0)


#define DC_A                                                                         0x180070B8
#define DC_A_reg_addr                                                                "0x180070B8"
#define DC_A_reg                                                                     0x180070B8
#define set_DC_A_reg(data)   (*((volatile unsigned int*) DC_A_reg)=data)
#define get_DC_A_reg   (*((volatile unsigned int*) DC_A_reg))
#define DC_A_inst_adr                                                                "0x002E"
#define DC_A_inst                                                                    0x002E
#define DC_A_scpu_tee_ro_protect_en_shift                                            (28)
#define DC_A_scpu_tee_ro_protect_en_mask                                             (0x10000000)
#define DC_A_scpu_tee_ro_protect_en(data)                                            (0x10000000&((data)<<28))
#define DC_A_scpu_tee_ro_protect_en_src(data)                                        ((0x10000000&(data))>>28)
#define DC_A_get_scpu_tee_ro_protect_en(data)                                        ((0x10000000&(data))>>28)
#define DC_A_acpu_ro_protect_en_shift                                                (24)
#define DC_A_acpu_ro_protect_en_mask                                                 (0x01000000)
#define DC_A_acpu_ro_protect_en(data)                                                (0x01000000&((data)<<24))
#define DC_A_acpu_ro_protect_en_src(data)                                            ((0x01000000&(data))>>24)
#define DC_A_get_acpu_ro_protect_en(data)                                            ((0x01000000&(data))>>24)
#define DC_A_video_ro_protect_en_shift                                               (20)
#define DC_A_video_ro_protect_en_mask                                                (0x00100000)
#define DC_A_video_ro_protect_en(data)                                               (0x00100000&((data)<<20))
#define DC_A_video_ro_protect_en_src(data)                                           ((0x00100000&(data))>>20)
#define DC_A_get_video_ro_protect_en(data)                                           ((0x00100000&(data))>>20)
#define DC_A_audio_ro_protect_en_shift                                               (16)
#define DC_A_audio_ro_protect_en_mask                                                (0x00010000)
#define DC_A_audio_ro_protect_en(data)                                               (0x00010000&((data)<<16))
#define DC_A_audio_ro_protect_en_src(data)                                           ((0x00010000&(data))>>16)
#define DC_A_get_audio_ro_protect_en(data)                                           ((0x00010000&(data))>>16)
#define DC_A_md_tee_ro_protect_en_shift                                              (12)
#define DC_A_md_tee_ro_protect_en_mask                                               (0x00001000)
#define DC_A_md_tee_ro_protect_en(data)                                              (0x00001000&((data)<<12))
#define DC_A_md_tee_ro_protect_en_src(data)                                          ((0x00001000&(data))>>12)
#define DC_A_get_md_tee_ro_protect_en(data)                                          ((0x00001000&(data))>>12)
#define DC_A_cp_tee_ro_protect_en_shift                                              (8)
#define DC_A_cp_tee_ro_protect_en_mask                                               (0x00000100)
#define DC_A_cp_tee_ro_protect_en(data)                                              (0x00000100&((data)<<8))
#define DC_A_cp_tee_ro_protect_en_src(data)                                          ((0x00000100&(data))>>8)
#define DC_A_get_cp_tee_ro_protect_en(data)                                          ((0x00000100&(data))>>8)
#define DC_A_vo_ro_protect_en_shift                                                  (4)
#define DC_A_vo_ro_protect_en_mask                                                   (0x00000010)
#define DC_A_vo_ro_protect_en(data)                                                  (0x00000010&((data)<<4))
#define DC_A_vo_ro_protect_en_src(data)                                              ((0x00000010&(data))>>4)
#define DC_A_get_vo_ro_protect_en(data)                                              ((0x00000010&(data))>>4)
#define DC_A_nf_tee_ro_protect_en_shift                                              (0)
#define DC_A_nf_tee_ro_protect_en_mask                                               (0x00000001)
#define DC_A_nf_tee_ro_protect_en(data)                                              (0x00000001&((data)<<0))
#define DC_A_nf_tee_ro_protect_en_src(data)                                          ((0x00000001&(data))>>0)
#define DC_A_get_nf_tee_ro_protect_en(data)                                          ((0x00000001&(data))>>0)


#define PLL_XTAL_CTRL                                                                0x180070BC
#define PLL_XTAL_CTRL_reg_addr                                                       "0x180070BC"
#define PLL_XTAL_CTRL_reg                                                            0x180070BC
#define set_PLL_XTAL_CTRL_reg(data)   (*((volatile unsigned int*) PLL_XTAL_CTRL_reg)=data)
#define get_PLL_XTAL_CTRL_reg   (*((volatile unsigned int*) PLL_XTAL_CTRL_reg))
#define PLL_XTAL_CTRL_inst_adr                                                       "0x002F"
#define PLL_XTAL_CTRL_inst                                                           0x002F
#define PLL_XTAL_CTRL_XTAL_PAD_DRV_shift                                             (0)
#define PLL_XTAL_CTRL_XTAL_PAD_DRV_mask                                              (0x00000003)
#define PLL_XTAL_CTRL_XTAL_PAD_DRV(data)                                             (0x00000003&((data)<<0))
#define PLL_XTAL_CTRL_XTAL_PAD_DRV_src(data)                                         ((0x00000003&(data))>>0)
#define PLL_XTAL_CTRL_get_XTAL_PAD_DRV(data)                                         ((0x00000003&(data))>>0)


#define I2C6_SDA_DEL                                                                 0x180070C0
#define I2C6_SDA_DEL_reg_addr                                                        "0x180070C0"
#define I2C6_SDA_DEL_reg                                                             0x180070C0
#define set_I2C6_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C6_SDA_DEL_reg)=data)
#define get_I2C6_SDA_DEL_reg   (*((volatile unsigned int*) I2C6_SDA_DEL_reg))
#define I2C6_SDA_DEL_inst_adr                                                        "0x0030"
#define I2C6_SDA_DEL_inst                                                            0x0030
#define I2C6_SDA_DEL_dmy1_shift                                                      (12)
#define I2C6_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C6_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C6_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C6_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C6_SDA_DEL_en_shift                                                        (8)
#define I2C6_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C6_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C6_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C6_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C6_SDA_DEL_sel_shift                                                       (0)
#define I2C6_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C6_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C6_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C6_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define HDMI_RX                                                                      0x180070C4
#define HDMI_RX_reg_addr                                                             "0x180070C4"
#define HDMI_RX_reg                                                                  0x180070C4
#define set_HDMI_RX_reg(data)   (*((volatile unsigned int*) HDMI_RX_reg)=data)
#define get_HDMI_RX_reg   (*((volatile unsigned int*) HDMI_RX_reg))
#define HDMI_RX_inst_adr                                                             "0x0031"
#define HDMI_RX_inst                                                                 0x0031
#define HDMI_RX_int_option_shift                                                     (0)
#define HDMI_RX_int_option_mask                                                      (0x00000001)
#define HDMI_RX_int_option(data)                                                     (0x00000001&((data)<<0))
#define HDMI_RX_int_option_src(data)                                                 ((0x00000001&(data))>>0)
#define HDMI_RX_get_int_option(data)                                                 ((0x00000001&(data))>>0)


#define I2C6_MUX                                                                     0x180070C8
#define I2C6_MUX_reg_addr                                                            "0x180070C8"
#define I2C6_MUX_reg                                                                 0x180070C8
#define set_I2C6_MUX_reg(data)   (*((volatile unsigned int*) I2C6_MUX_reg)=data)
#define get_I2C6_MUX_reg   (*((volatile unsigned int*) I2C6_MUX_reg))
#define I2C6_MUX_inst_adr                                                            "0x0032"
#define I2C6_MUX_inst                                                                0x0032
#define I2C6_MUX_i2c6_mis_mux_shift                                                  (0)
#define I2C6_MUX_i2c6_mis_mux_mask                                                   (0x00000001)
#define I2C6_MUX_i2c6_mis_mux(data)                                                  (0x00000001&((data)<<0))
#define I2C6_MUX_i2c6_mis_mux_src(data)                                              ((0x00000001&(data))>>0)
#define I2C6_MUX_get_i2c6_mis_mux(data)                                              ((0x00000001&(data))>>0)


#define SB2_0                                                                        0x18007F00
#define SB2_0_reg_addr                                                               "0x18007F00"
#define SB2_0_reg                                                                    0x18007F00
#define set_SB2_0_reg(data)   (*((volatile unsigned int*) SB2_0_reg)=data)
#define get_SB2_0_reg   (*((volatile unsigned int*) SB2_0_reg))
#define SB2_0_inst_adr                                                               "0x00C0"
#define SB2_0_inst                                                                   0x00C0
#define SB2_0_usb2sram_ctrl_shift                                                    (5)
#define SB2_0_usb2sram_ctrl_mask                                                     (0x00000020)
#define SB2_0_usb2sram_ctrl(data)                                                    (0x00000020&((data)<<5))
#define SB2_0_usb2sram_ctrl_src(data)                                                ((0x00000020&(data))>>5)
#define SB2_0_get_usb2sram_ctrl(data)                                                ((0x00000020&(data))>>5)
#define SB2_0_ve_encode_block_nwc_shift                                              (4)
#define SB2_0_ve_encode_block_nwc_mask                                               (0x00000010)
#define SB2_0_ve_encode_block_nwc(data)                                              (0x00000010&((data)<<4))
#define SB2_0_ve_encode_block_nwc_src(data)                                          ((0x00000010&(data))>>4)
#define SB2_0_get_ve_encode_block_nwc(data)                                          ((0x00000010&(data))>>4)
#define SB2_0_ve_block_nwc_shift                                                     (3)
#define SB2_0_ve_block_nwc_mask                                                      (0x00000008)
#define SB2_0_ve_block_nwc(data)                                                     (0x00000008&((data)<<3))
#define SB2_0_ve_block_nwc_src(data)                                                 ((0x00000008&(data))>>3)
#define SB2_0_get_ve_block_nwc(data)                                                 ((0x00000008&(data))>>3)
#define SB2_0_vo_block_nwc_shift                                                     (2)
#define SB2_0_vo_block_nwc_mask                                                      (0x00000004)
#define SB2_0_vo_block_nwc(data)                                                     (0x00000004&((data)<<2))
#define SB2_0_vo_block_nwc_src(data)                                                 ((0x00000004&(data))>>2)
#define SB2_0_get_vo_block_nwc(data)                                                 ((0x00000004&(data))>>2)
#define SB2_0_dc_mem_port_lock_shift                                                 (1)
#define SB2_0_dc_mem_port_lock_mask                                                  (0x00000002)
#define SB2_0_dc_mem_port_lock(data)                                                 (0x00000002&((data)<<1))
#define SB2_0_dc_mem_port_lock_src(data)                                             ((0x00000002&(data))>>1)
#define SB2_0_get_dc_mem_port_lock(data)                                             ((0x00000002&(data))>>1)
#define SB2_0_secure_rbus_shift                                                      (0)
#define SB2_0_secure_rbus_mask                                                       (0x00000001)
#define SB2_0_secure_rbus(data)                                                      (0x00000001&((data)<<0))
#define SB2_0_secure_rbus_src(data)                                                  ((0x00000001&(data))>>0)
#define SB2_0_get_secure_rbus(data)                                                  ((0x00000001&(data))>>0)


#define GPDIR                                                                        0x18007100
#define GPDIR_reg_addr                                                               "0x18007100"
#define GPDIR_reg                                                                    0x18007100
#define set_GPDIR_reg(data)   (*((volatile unsigned int*) GPDIR_reg)=data)
#define get_GPDIR_reg   (*((volatile unsigned int*) GPDIR_reg))
#define GPDIR_inst_adr                                                               "0x0040"
#define GPDIR_inst                                                                   0x0040
#define GPDIR_GPDIR_shift                                                            (0)
#define GPDIR_GPDIR_mask                                                             (0x001FFFFF)
#define GPDIR_GPDIR(data)                                                            (0x001FFFFF&((data)<<0))
#define GPDIR_GPDIR_src(data)                                                        ((0x001FFFFF&(data))>>0)
#define GPDIR_get_GPDIR(data)                                                        ((0x001FFFFF&(data))>>0)


#define GPDATO                                                                       0x18007104
#define GPDATO_reg_addr                                                              "0x18007104"
#define GPDATO_reg                                                                   0x18007104
#define set_GPDATO_reg(data)   (*((volatile unsigned int*) GPDATO_reg)=data)
#define get_GPDATO_reg   (*((volatile unsigned int*) GPDATO_reg))
#define GPDATO_inst_adr                                                              "0x0041"
#define GPDATO_inst                                                                  0x0041
#define GPDATO_GPDATO_shift                                                          (0)
#define GPDATO_GPDATO_mask                                                           (0x001FFFFF)
#define GPDATO_GPDATO(data)                                                          (0x001FFFFF&((data)<<0))
#define GPDATO_GPDATO_src(data)                                                      ((0x001FFFFF&(data))>>0)
#define GPDATO_get_GPDATO(data)                                                      ((0x001FFFFF&(data))>>0)


#define GPDATI                                                                       0x18007108
#define GPDATI_reg_addr                                                              "0x18007108"
#define GPDATI_reg                                                                   0x18007108
#define set_GPDATI_reg(data)   (*((volatile unsigned int*) GPDATI_reg)=data)
#define get_GPDATI_reg   (*((volatile unsigned int*) GPDATI_reg))
#define GPDATI_inst_adr                                                              "0x0042"
#define GPDATI_inst                                                                  0x0042
#define GPDATI_GPDATI_shift                                                          (0)
#define GPDATI_GPDATI_mask                                                           (0x001FFFFF)
#define GPDATI_GPDATI(data)                                                          (0x001FFFFF&((data)<<0))
#define GPDATI_GPDATI_src(data)                                                      ((0x001FFFFF&(data))>>0)
#define GPDATI_get_GPDATI(data)                                                      ((0x001FFFFF&(data))>>0)


#define GPIE                                                                         0x1800710C
#define GPIE_reg_addr                                                                "0x1800710C"
#define GPIE_reg                                                                     0x1800710C
#define set_GPIE_reg(data)   (*((volatile unsigned int*) GPIE_reg)=data)
#define get_GPIE_reg   (*((volatile unsigned int*) GPIE_reg))
#define GPIE_inst_adr                                                                "0x0043"
#define GPIE_inst                                                                    0x0043
#define GPIE_GP_shift                                                                (0)
#define GPIE_GP_mask                                                                 (0x001FFFFF)
#define GPIE_GP(data)                                                                (0x001FFFFF&((data)<<0))
#define GPIE_GP_src(data)                                                            ((0x001FFFFF&(data))>>0)
#define GPIE_get_GP(data)                                                            ((0x001FFFFF&(data))>>0)


#define GPDP                                                                         0x18007110
#define GPDP_reg_addr                                                                "0x18007110"
#define GPDP_reg                                                                     0x18007110
#define set_GPDP_reg(data)   (*((volatile unsigned int*) GPDP_reg)=data)
#define get_GPDP_reg   (*((volatile unsigned int*) GPDP_reg))
#define GPDP_inst_adr                                                                "0x0044"
#define GPDP_inst                                                                    0x0044
#define GPDP_GPHA_shift                                                              (0)
#define GPDP_GPHA_mask                                                               (0x001FFFFF)
#define GPDP_GPHA(data)                                                              (0x001FFFFF&((data)<<0))
#define GPDP_GPHA_src(data)                                                          ((0x001FFFFF&(data))>>0)
#define GPDP_get_GPHA(data)                                                          ((0x001FFFFF&(data))>>0)


#define ISO_GPDEB                                                                        0x18007114
#define ISO_GPDEB_reg_addr                                                               "0x18007114"
#define ISO_GPDEB_reg                                                                    0x18007114
#define ISO_set_GPDEB_reg(data)   (*((volatile unsigned int*) GPDEB_reg)=data)
#define ISO_get_GPDEB_reg   (*((volatile unsigned int*) GPDEB_reg))
#define ISO_GPDEB_inst_adr                                                               "0x0045"
#define ISO_GPDEB_inst                                                                   0x0045
#define ISO_GPDEB_write_en1_shift                                                        (3)
#define ISO_GPDEB_write_en1_mask                                                         (0x00000008)
#define ISO_GPDEB_write_en1(data)                                                        (0x00000008&((data)<<3))
#define ISO_GPDEB_write_en1_src(data)                                                    ((0x00000008&(data))>>3)
#define ISO_GPDEB_get_write_en1(data)                                                    ((0x00000008&(data))>>3)
#define ISO_GPDEB_CLK1_shift                                                             (0)
#define ISO_GPDEB_CLK1_mask                                                              (0x00000007)
#define ISO_GPDEB_CLK1(data)                                                             (0x00000007&((data)<<0))
#define ISO_GPDEB_CLK1_src(data)                                                         ((0x00000007&(data))>>0)
#define ISO_GPDEB_get_CLK1(data)                                                         ((0x00000007&(data))>>0)


#define VFD_CTL                                                                      0x18007200
#define VFD_CTL_reg_addr                                                             "0x18007200"
#define VFD_CTL_reg                                                                  0x18007200
#define set_VFD_CTL_reg(data)   (*((volatile unsigned int*) VFD_CTL_reg)=data)
#define get_VFD_CTL_reg   (*((volatile unsigned int*) VFD_CTL_reg))
#define VFD_CTL_inst_adr                                                             "0x0080"
#define VFD_CTL_inst                                                                 0x0080
#define VFD_CTL_KPADEN_shift                                                         (3)
#define VFD_CTL_KPADEN_mask                                                          (0x00000008)
#define VFD_CTL_KPADEN(data)                                                         (0x00000008&((data)<<3))
#define VFD_CTL_KPADEN_src(data)                                                     ((0x00000008&(data))>>3)
#define VFD_CTL_get_KPADEN(data)                                                     ((0x00000008&(data))>>3)
#define VFD_CTL_SWEN_shift                                                           (2)
#define VFD_CTL_SWEN_mask                                                            (0x00000004)
#define VFD_CTL_SWEN(data)                                                           (0x00000004&((data)<<2))
#define VFD_CTL_SWEN_src(data)                                                       ((0x00000004&(data))>>2)
#define VFD_CTL_get_SWEN(data)                                                       ((0x00000004&(data))>>2)
#define VFD_CTL_CLKSEL_shift                                                         (1)
#define VFD_CTL_CLKSEL_mask                                                          (0x00000002)
#define VFD_CTL_CLKSEL(data)                                                         (0x00000002&((data)<<1))
#define VFD_CTL_CLKSEL_src(data)                                                     ((0x00000002&(data))>>1)
#define VFD_CTL_get_CLKSEL(data)                                                     ((0x00000002&(data))>>1)
#define VFD_CTL_ENVFD_shift                                                          (0)
#define VFD_CTL_ENVFD_mask                                                           (0x00000001)
#define VFD_CTL_ENVFD(data)                                                          (0x00000001&((data)<<0))
#define VFD_CTL_ENVFD_src(data)                                                      ((0x00000001&(data))>>0)
#define VFD_CTL_get_ENVFD(data)                                                      ((0x00000001&(data))>>0)


#define VFD_WRCTL                                                                    0x18007204
#define VFD_WRCTL_reg_addr                                                           "0x18007204"
#define VFD_WRCTL_reg                                                                0x18007204
#define set_VFD_WRCTL_reg(data)   (*((volatile unsigned int*) VFD_WRCTL_reg)=data)
#define get_VFD_WRCTL_reg   (*((volatile unsigned int*) VFD_WRCTL_reg))
#define VFD_WRCTL_inst_adr                                                           "0x0081"
#define VFD_WRCTL_inst                                                               0x0081
#define VFD_WRCTL_NACT_CSN_shift                                                     (12)
#define VFD_WRCTL_NACT_CSN_mask                                                      (0x00001000)
#define VFD_WRCTL_NACT_CSN(data)                                                     (0x00001000&((data)<<12))
#define VFD_WRCTL_NACT_CSN_src(data)                                                 ((0x00001000&(data))>>12)
#define VFD_WRCTL_get_NACT_CSN(data)                                                 ((0x00001000&(data))>>12)
#define VFD_WRCTL_B3C_shift                                                          (11)
#define VFD_WRCTL_B3C_mask                                                           (0x00000800)
#define VFD_WRCTL_B3C(data)                                                          (0x00000800&((data)<<11))
#define VFD_WRCTL_B3C_src(data)                                                      ((0x00000800&(data))>>11)
#define VFD_WRCTL_get_B3C(data)                                                      ((0x00000800&(data))>>11)
#define VFD_WRCTL_B2C_shift                                                          (10)
#define VFD_WRCTL_B2C_mask                                                           (0x00000400)
#define VFD_WRCTL_B2C(data)                                                          (0x00000400&((data)<<10))
#define VFD_WRCTL_B2C_src(data)                                                      ((0x00000400&(data))>>10)
#define VFD_WRCTL_get_B2C(data)                                                      ((0x00000400&(data))>>10)
#define VFD_WRCTL_B1C_shift                                                          (9)
#define VFD_WRCTL_B1C_mask                                                           (0x00000200)
#define VFD_WRCTL_B1C(data)                                                          (0x00000200&((data)<<9))
#define VFD_WRCTL_B1C_src(data)                                                      ((0x00000200&(data))>>9)
#define VFD_WRCTL_get_B1C(data)                                                      ((0x00000200&(data))>>9)
#define VFD_WRCTL_B0C_shift                                                          (8)
#define VFD_WRCTL_B0C_mask                                                           (0x00000100)
#define VFD_WRCTL_B0C(data)                                                          (0x00000100&((data)<<8))
#define VFD_WRCTL_B0C_src(data)                                                      ((0x00000100&(data))>>8)
#define VFD_WRCTL_get_B0C(data)                                                      ((0x00000100&(data))>>8)
#define VFD_WRCTL_ENB3_shift                                                         (7)
#define VFD_WRCTL_ENB3_mask                                                          (0x00000080)
#define VFD_WRCTL_ENB3(data)                                                         (0x00000080&((data)<<7))
#define VFD_WRCTL_ENB3_src(data)                                                     ((0x00000080&(data))>>7)
#define VFD_WRCTL_get_ENB3(data)                                                     ((0x00000080&(data))>>7)
#define VFD_WRCTL_ENB2_shift                                                         (6)
#define VFD_WRCTL_ENB2_mask                                                          (0x00000040)
#define VFD_WRCTL_ENB2(data)                                                         (0x00000040&((data)<<6))
#define VFD_WRCTL_ENB2_src(data)                                                     ((0x00000040&(data))>>6)
#define VFD_WRCTL_get_ENB2(data)                                                     ((0x00000040&(data))>>6)
#define VFD_WRCTL_ENB1_shift                                                         (5)
#define VFD_WRCTL_ENB1_mask                                                          (0x00000020)
#define VFD_WRCTL_ENB1(data)                                                         (0x00000020&((data)<<5))
#define VFD_WRCTL_ENB1_src(data)                                                     ((0x00000020&(data))>>5)
#define VFD_WRCTL_get_ENB1(data)                                                     ((0x00000020&(data))>>5)
#define VFD_WRCTL_ENB0_shift                                                         (4)
#define VFD_WRCTL_ENB0_mask                                                          (0x00000010)
#define VFD_WRCTL_ENB0(data)                                                         (0x00000010&((data)<<4))
#define VFD_WRCTL_ENB0_src(data)                                                     ((0x00000010&(data))>>4)
#define VFD_WRCTL_get_ENB0(data)                                                     ((0x00000010&(data))>>4)
#define VFD_WRCTL_WD_shift                                                           (1)
#define VFD_WRCTL_WD_mask                                                            (0x00000002)
#define VFD_WRCTL_WD(data)                                                           (0x00000002&((data)<<1))
#define VFD_WRCTL_WD_src(data)                                                       ((0x00000002&(data))>>1)
#define VFD_WRCTL_get_WD(data)                                                       ((0x00000002&(data))>>1)
#define VFD_WRCTL_WDIE_shift                                                         (0)
#define VFD_WRCTL_WDIE_mask                                                          (0x00000001)
#define VFD_WRCTL_WDIE(data)                                                         (0x00000001&((data)<<0))
#define VFD_WRCTL_WDIE_src(data)                                                     ((0x00000001&(data))>>0)
#define VFD_WRCTL_get_WDIE(data)                                                     ((0x00000001&(data))>>0)


#define VFDO                                                                         0x18007208
#define VFDO_reg_addr                                                                "0x18007208"
#define VFDO_reg                                                                     0x18007208
#define set_VFDO_reg(data)   (*((volatile unsigned int*) VFDO_reg)=data)
#define get_VFDO_reg   (*((volatile unsigned int*) VFDO_reg))
#define VFDO_inst_adr                                                                "0x0082"
#define VFDO_inst                                                                    0x0082
#define VFDO_BYTE3_shift                                                             (24)
#define VFDO_BYTE3_mask                                                              (0xFF000000)
#define VFDO_BYTE3(data)                                                             (0xFF000000&((data)<<24))
#define VFDO_BYTE3_src(data)                                                         ((0xFF000000&(data))>>24)
#define VFDO_get_BYTE3(data)                                                         ((0xFF000000&(data))>>24)
#define VFDO_BYTE2_shift                                                             (16)
#define VFDO_BYTE2_mask                                                              (0x00FF0000)
#define VFDO_BYTE2(data)                                                             (0x00FF0000&((data)<<16))
#define VFDO_BYTE2_src(data)                                                         ((0x00FF0000&(data))>>16)
#define VFDO_get_BYTE2(data)                                                         ((0x00FF0000&(data))>>16)
#define VFDO_BYTE1_shift                                                             (8)
#define VFDO_BYTE1_mask                                                              (0x0000FF00)
#define VFDO_BYTE1(data)                                                             (0x0000FF00&((data)<<8))
#define VFDO_BYTE1_src(data)                                                         ((0x0000FF00&(data))>>8)
#define VFDO_get_BYTE1(data)                                                         ((0x0000FF00&(data))>>8)
#define VFDO_BYTE0_shift                                                             (0)
#define VFDO_BYTE0_mask                                                              (0x000000FF)
#define VFDO_BYTE0(data)                                                             (0x000000FF&((data)<<0))
#define VFDO_BYTE0_src(data)                                                         ((0x000000FF&(data))>>0)
#define VFDO_get_BYTE0(data)                                                         ((0x000000FF&(data))>>0)


#define VFD_ARDCTL                                                                   0x1800720C
#define VFD_ARDCTL_reg_addr                                                          "0x1800720C"
#define VFD_ARDCTL_reg                                                               0x1800720C
#define set_VFD_ARDCTL_reg(data)   (*((volatile unsigned int*) VFD_ARDCTL_reg)=data)
#define get_VFD_ARDCTL_reg   (*((volatile unsigned int*) VFD_ARDCTL_reg))
#define VFD_ARDCTL_inst_adr                                                          "0x0083"
#define VFD_ARDCTL_inst                                                              0x0083
#define VFD_ARDCTL_KPADBN_shift                                                      (8)
#define VFD_ARDCTL_KPADBN_mask                                                       (0x00000700)
#define VFD_ARDCTL_KPADBN(data)                                                      (0x00000700&((data)<<8))
#define VFD_ARDCTL_KPADBN_src(data)                                                  ((0x00000700&(data))>>8)
#define VFD_ARDCTL_get_KPADBN(data)                                                  ((0x00000700&(data))>>8)
#define VFD_ARDCTL_SWHA_shift                                                        (5)
#define VFD_ARDCTL_SWHA_mask                                                         (0x00000020)
#define VFD_ARDCTL_SWHA(data)                                                        (0x00000020&((data)<<5))
#define VFD_ARDCTL_SWHA_src(data)                                                    ((0x00000020&(data))>>5)
#define VFD_ARDCTL_get_SWHA(data)                                                    ((0x00000020&(data))>>5)
#define VFD_ARDCTL_KPADHA_shift                                                      (4)
#define VFD_ARDCTL_KPADHA_mask                                                       (0x00000010)
#define VFD_ARDCTL_KPADHA(data)                                                      (0x00000010&((data)<<4))
#define VFD_ARDCTL_KPADHA_src(data)                                                  ((0x00000010&(data))>>4)
#define VFD_ARDCTL_get_KPADHA(data)                                                  ((0x00000010&(data))>>4)
#define VFD_ARDCTL_ARDP_shift                                                        (0)
#define VFD_ARDCTL_ARDP_mask                                                         (0x00000003)
#define VFD_ARDCTL_ARDP(data)                                                        (0x00000003&((data)<<0))
#define VFD_ARDCTL_ARDP_src(data)                                                    ((0x00000003&(data))>>0)
#define VFD_ARDCTL_get_ARDP(data)                                                    ((0x00000003&(data))>>0)


#define VFD_KPADLIE                                                                  0x18007210
#define VFD_KPADLIE_reg_addr                                                         "0x18007210"
#define VFD_KPADLIE_reg                                                              0x18007210
#define set_VFD_KPADLIE_reg(data)   (*((volatile unsigned int*) VFD_KPADLIE_reg)=data)
#define get_VFD_KPADLIE_reg   (*((volatile unsigned int*) VFD_KPADLIE_reg))
#define VFD_KPADLIE_inst_adr                                                         "0x0084"
#define VFD_KPADLIE_inst                                                             0x0084
#define VFD_KPADLIE_KPADIE_shift                                                     (0)
#define VFD_KPADLIE_KPADIE_mask                                                      (0xFFFFFFFF)
#define VFD_KPADLIE_KPADIE(data)                                                     (0xFFFFFFFF&((data)<<0))
#define VFD_KPADLIE_KPADIE_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define VFD_KPADLIE_get_KPADIE(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define VFD_KPADHIE                                                                  0x18007214
#define VFD_KPADHIE_reg_addr                                                         "0x18007214"
#define VFD_KPADHIE_reg                                                              0x18007214
#define set_VFD_KPADHIE_reg(data)   (*((volatile unsigned int*) VFD_KPADHIE_reg)=data)
#define get_VFD_KPADHIE_reg   (*((volatile unsigned int*) VFD_KPADHIE_reg))
#define VFD_KPADHIE_inst_adr                                                         "0x0085"
#define VFD_KPADHIE_inst                                                             0x0085
#define VFD_KPADHIE_KPADIE_shift                                                     (0)
#define VFD_KPADHIE_KPADIE_mask                                                      (0x0000FFFF)
#define VFD_KPADHIE_KPADIE(data)                                                     (0x0000FFFF&((data)<<0))
#define VFD_KPADHIE_KPADIE_src(data)                                                 ((0x0000FFFF&(data))>>0)
#define VFD_KPADHIE_get_KPADIE(data)                                                 ((0x0000FFFF&(data))>>0)


#define VFD_SWIE                                                                     0x18007218
#define VFD_SWIE_reg_addr                                                            "0x18007218"
#define VFD_SWIE_reg                                                                 0x18007218
#define set_VFD_SWIE_reg(data)   (*((volatile unsigned int*) VFD_SWIE_reg)=data)
#define get_VFD_SWIE_reg   (*((volatile unsigned int*) VFD_SWIE_reg))
#define VFD_SWIE_inst_adr                                                            "0x0086"
#define VFD_SWIE_inst                                                                0x0086
#define VFD_SWIE_SWIE_shift                                                          (0)
#define VFD_SWIE_SWIE_mask                                                           (0x0000000F)
#define VFD_SWIE_SWIE(data)                                                          (0x0000000F&((data)<<0))
#define VFD_SWIE_SWIE_src(data)                                                      ((0x0000000F&(data))>>0)
#define VFD_SWIE_get_SWIE(data)                                                      ((0x0000000F&(data))>>0)


#define VFD_ARDKPADL                                                                 0x1800721C
#define VFD_ARDKPADL_reg_addr                                                        "0x1800721C"
#define VFD_ARDKPADL_reg                                                             0x1800721C
#define set_VFD_ARDKPADL_reg(data)   (*((volatile unsigned int*) VFD_ARDKPADL_reg)=data)
#define get_VFD_ARDKPADL_reg   (*((volatile unsigned int*) VFD_ARDKPADL_reg))
#define VFD_ARDKPADL_inst_adr                                                        "0x0087"
#define VFD_ARDKPADL_inst                                                            0x0087
#define VFD_ARDKPADL_ST_31_24_shift                                                  (24)
#define VFD_ARDKPADL_ST_31_24_mask                                                   (0xFF000000)
#define VFD_ARDKPADL_ST_31_24(data)                                                  (0xFF000000&((data)<<24))
#define VFD_ARDKPADL_ST_31_24_src(data)                                              ((0xFF000000&(data))>>24)
#define VFD_ARDKPADL_get_ST_31_24(data)                                              ((0xFF000000&(data))>>24)
#define VFD_ARDKPADL_ST_23_16_shift                                                  (16)
#define VFD_ARDKPADL_ST_23_16_mask                                                   (0x00FF0000)
#define VFD_ARDKPADL_ST_23_16(data)                                                  (0x00FF0000&((data)<<16))
#define VFD_ARDKPADL_ST_23_16_src(data)                                              ((0x00FF0000&(data))>>16)
#define VFD_ARDKPADL_get_ST_23_16(data)                                              ((0x00FF0000&(data))>>16)
#define VFD_ARDKPADL_ST_15_8_shift                                                   (8)
#define VFD_ARDKPADL_ST_15_8_mask                                                    (0x0000FF00)
#define VFD_ARDKPADL_ST_15_8(data)                                                   (0x0000FF00&((data)<<8))
#define VFD_ARDKPADL_ST_15_8_src(data)                                               ((0x0000FF00&(data))>>8)
#define VFD_ARDKPADL_get_ST_15_8(data)                                               ((0x0000FF00&(data))>>8)
#define VFD_ARDKPADL_ST_7_0_shift                                                    (0)
#define VFD_ARDKPADL_ST_7_0_mask                                                     (0x000000FF)
#define VFD_ARDKPADL_ST_7_0(data)                                                    (0x000000FF&((data)<<0))
#define VFD_ARDKPADL_ST_7_0_src(data)                                                ((0x000000FF&(data))>>0)
#define VFD_ARDKPADL_get_ST_7_0(data)                                                ((0x000000FF&(data))>>0)


#define VFD_ARDKPADH                                                                 0x18007220
#define VFD_ARDKPADH_reg_addr                                                        "0x18007220"
#define VFD_ARDKPADH_reg                                                             0x18007220
#define set_VFD_ARDKPADH_reg(data)   (*((volatile unsigned int*) VFD_ARDKPADH_reg)=data)
#define get_VFD_ARDKPADH_reg   (*((volatile unsigned int*) VFD_ARDKPADH_reg))
#define VFD_ARDKPADH_inst_adr                                                        "0x0088"
#define VFD_ARDKPADH_inst                                                            0x0088
#define VFD_ARDKPADH_ST_15_8_shift                                                   (8)
#define VFD_ARDKPADH_ST_15_8_mask                                                    (0x0000FF00)
#define VFD_ARDKPADH_ST_15_8(data)                                                   (0x0000FF00&((data)<<8))
#define VFD_ARDKPADH_ST_15_8_src(data)                                               ((0x0000FF00&(data))>>8)
#define VFD_ARDKPADH_get_ST_15_8(data)                                               ((0x0000FF00&(data))>>8)
#define VFD_ARDKPADH_ST_7_0_shift                                                    (0)
#define VFD_ARDKPADH_ST_7_0_mask                                                     (0x000000FF)
#define VFD_ARDKPADH_ST_7_0(data)                                                    (0x000000FF&((data)<<0))
#define VFD_ARDKPADH_ST_7_0_src(data)                                                ((0x000000FF&(data))>>0)
#define VFD_ARDKPADH_get_ST_7_0(data)                                                ((0x000000FF&(data))>>0)


#define VFD_ARDSW                                                                    0x18007224
#define VFD_ARDSW_reg_addr                                                           "0x18007224"
#define VFD_ARDSW_reg                                                                0x18007224
#define set_VFD_ARDSW_reg(data)   (*((volatile unsigned int*) VFD_ARDSW_reg)=data)
#define get_VFD_ARDSW_reg   (*((volatile unsigned int*) VFD_ARDSW_reg))
#define VFD_ARDSW_inst_adr                                                           "0x0089"
#define VFD_ARDSW_inst                                                               0x0089
#define VFD_ARDSW_RvdA_shift                                                         (4)
#define VFD_ARDSW_RvdA_mask                                                          (0x0000FFF0)
#define VFD_ARDSW_RvdA(data)                                                         (0x0000FFF0&((data)<<4))
#define VFD_ARDSW_RvdA_src(data)                                                     ((0x0000FFF0&(data))>>4)
#define VFD_ARDSW_get_RvdA(data)                                                     ((0x0000FFF0&(data))>>4)
#define VFD_ARDSW_ST_shift                                                           (0)
#define VFD_ARDSW_ST_mask                                                            (0x0000000F)
#define VFD_ARDSW_ST(data)                                                           (0x0000000F&((data)<<0))
#define VFD_ARDSW_ST_src(data)                                                       ((0x0000000F&(data))>>0)
#define VFD_ARDSW_get_ST(data)                                                       ((0x0000000F&(data))>>0)


#define VFD_CTL1                                                                     0x18007228
#define VFD_CTL1_reg_addr                                                            "0x18007228"
#define VFD_CTL1_reg                                                                 0x18007228
#define set_VFD_CTL1_reg(data)   (*((volatile unsigned int*) VFD_CTL1_reg)=data)
#define get_VFD_CTL1_reg   (*((volatile unsigned int*) VFD_CTL1_reg))
#define VFD_CTL1_inst_adr                                                            "0x008A"
#define VFD_CTL1_inst                                                                0x008A
#define VFD_CTL1_CLKSEL_1_shift                                                      (16)
#define VFD_CTL1_CLKSEL_1_mask                                                       (0x00010000)
#define VFD_CTL1_CLKSEL_1(data)                                                      (0x00010000&((data)<<16))
#define VFD_CTL1_CLKSEL_1_src(data)                                                  ((0x00010000&(data))>>16)
#define VFD_CTL1_get_CLKSEL_1(data)                                                  ((0x00010000&(data))>>16)
#define VFD_CTL1_Tclk_csn_shift                                                      (8)
#define VFD_CTL1_Tclk_csn_mask                                                       (0x0000FF00)
#define VFD_CTL1_Tclk_csn(data)                                                      (0x0000FF00&((data)<<8))
#define VFD_CTL1_Tclk_csn_src(data)                                                  ((0x0000FF00&(data))>>8)
#define VFD_CTL1_get_Tclk_csn(data)                                                  ((0x0000FF00&(data))>>8)
#define VFD_CTL1_Twait1_shift                                                        (0)
#define VFD_CTL1_Twait1_mask                                                         (0x000000FF)
#define VFD_CTL1_Twait1(data)                                                        (0x000000FF&((data)<<0))
#define VFD_CTL1_Twait1_src(data)                                                    ((0x000000FF&(data))>>0)
#define VFD_CTL1_get_Twait1(data)                                                    ((0x000000FF&(data))>>0)


#define PFUNC0                                                                       0x18007300
#define PFUNC0_reg_addr                                                              "0x18007300"
#define PFUNC0_reg                                                                   0x18007300
#define set_PFUNC0_reg(data)   (*((volatile unsigned int*) PFUNC0_reg)=data)
#define get_PFUNC0_reg   (*((volatile unsigned int*) PFUNC0_reg))
#define PFUNC0_inst_adr                                                              "0x00C0"
#define PFUNC0_inst                                                                  0x00C0
#define PFUNC0_i2c_scl_0_smt_shift                                                   (31)
#define PFUNC0_i2c_scl_0_smt_mask                                                    (0x80000000)
#define PFUNC0_i2c_scl_0_smt(data)                                                   (0x80000000&((data)<<31))
#define PFUNC0_i2c_scl_0_smt_src(data)                                               ((0x80000000&(data))>>31)
#define PFUNC0_get_i2c_scl_0_smt(data)                                               ((0x80000000&(data))>>31)
#define PFUNC0_i2c_scl_0_e2_shift                                                    (30)
#define PFUNC0_i2c_scl_0_e2_mask                                                     (0x40000000)
#define PFUNC0_i2c_scl_0_e2(data)                                                    (0x40000000&((data)<<30))
#define PFUNC0_i2c_scl_0_e2_src(data)                                                ((0x40000000&(data))>>30)
#define PFUNC0_get_i2c_scl_0_e2(data)                                                ((0x40000000&(data))>>30)
#define PFUNC0_i2c_scl_0_pud_en_shift                                                (29)
#define PFUNC0_i2c_scl_0_pud_en_mask                                                 (0x20000000)
#define PFUNC0_i2c_scl_0_pud_en(data)                                                (0x20000000&((data)<<29))
#define PFUNC0_i2c_scl_0_pud_en_src(data)                                            ((0x20000000&(data))>>29)
#define PFUNC0_get_i2c_scl_0_pud_en(data)                                            ((0x20000000&(data))>>29)
#define PFUNC0_i2c_scl_0_pud_sel_shift                                               (28)
#define PFUNC0_i2c_scl_0_pud_sel_mask                                                (0x10000000)
#define PFUNC0_i2c_scl_0_pud_sel(data)                                               (0x10000000&((data)<<28))
#define PFUNC0_i2c_scl_0_pud_sel_src(data)                                           ((0x10000000&(data))>>28)
#define PFUNC0_get_i2c_scl_0_pud_sel(data)                                           ((0x10000000&(data))>>28)
#define PFUNC0_i2c_sda_0_smt_shift                                                   (27)
#define PFUNC0_i2c_sda_0_smt_mask                                                    (0x08000000)
#define PFUNC0_i2c_sda_0_smt(data)                                                   (0x08000000&((data)<<27))
#define PFUNC0_i2c_sda_0_smt_src(data)                                               ((0x08000000&(data))>>27)
#define PFUNC0_get_i2c_sda_0_smt(data)                                               ((0x08000000&(data))>>27)
#define PFUNC0_i2c_sda_0_e2_shift                                                    (26)
#define PFUNC0_i2c_sda_0_e2_mask                                                     (0x04000000)
#define PFUNC0_i2c_sda_0_e2(data)                                                    (0x04000000&((data)<<26))
#define PFUNC0_i2c_sda_0_e2_src(data)                                                ((0x04000000&(data))>>26)
#define PFUNC0_get_i2c_sda_0_e2(data)                                                ((0x04000000&(data))>>26)
#define PFUNC0_i2c_sda_0_pud_en_shift                                                (25)
#define PFUNC0_i2c_sda_0_pud_en_mask                                                 (0x02000000)
#define PFUNC0_i2c_sda_0_pud_en(data)                                                (0x02000000&((data)<<25))
#define PFUNC0_i2c_sda_0_pud_en_src(data)                                            ((0x02000000&(data))>>25)
#define PFUNC0_get_i2c_sda_0_pud_en(data)                                            ((0x02000000&(data))>>25)
#define PFUNC0_i2c_sda_0_pud_sel_shift                                               (24)
#define PFUNC0_i2c_sda_0_pud_sel_mask                                                (0x01000000)
#define PFUNC0_i2c_sda_0_pud_sel(data)                                               (0x01000000&((data)<<24))
#define PFUNC0_i2c_sda_0_pud_sel_src(data)                                           ((0x01000000&(data))>>24)
#define PFUNC0_get_i2c_sda_0_pud_sel(data)                                           ((0x01000000&(data))>>24)
#define PFUNC0_vfd_d_smt_shift                                                       (23)
#define PFUNC0_vfd_d_smt_mask                                                        (0x00800000)
#define PFUNC0_vfd_d_smt(data)                                                       (0x00800000&((data)<<23))
#define PFUNC0_vfd_d_smt_src(data)                                                   ((0x00800000&(data))>>23)
#define PFUNC0_get_vfd_d_smt(data)                                                   ((0x00800000&(data))>>23)
#define PFUNC0_vfd_d_e2_shift                                                        (22)
#define PFUNC0_vfd_d_e2_mask                                                         (0x00400000)
#define PFUNC0_vfd_d_e2(data)                                                        (0x00400000&((data)<<22))
#define PFUNC0_vfd_d_e2_src(data)                                                    ((0x00400000&(data))>>22)
#define PFUNC0_get_vfd_d_e2(data)                                                    ((0x00400000&(data))>>22)
#define PFUNC0_vfd_d_pud_en_shift                                                    (21)
#define PFUNC0_vfd_d_pud_en_mask                                                     (0x00200000)
#define PFUNC0_vfd_d_pud_en(data)                                                    (0x00200000&((data)<<21))
#define PFUNC0_vfd_d_pud_en_src(data)                                                ((0x00200000&(data))>>21)
#define PFUNC0_get_vfd_d_pud_en(data)                                                ((0x00200000&(data))>>21)
#define PFUNC0_vfd_d_pud_sel_shift                                                   (20)
#define PFUNC0_vfd_d_pud_sel_mask                                                    (0x00100000)
#define PFUNC0_vfd_d_pud_sel(data)                                                   (0x00100000&((data)<<20))
#define PFUNC0_vfd_d_pud_sel_src(data)                                               ((0x00100000&(data))>>20)
#define PFUNC0_get_vfd_d_pud_sel(data)                                               ((0x00100000&(data))>>20)
#define PFUNC0_vfd_clk_smt_shift                                                     (19)
#define PFUNC0_vfd_clk_smt_mask                                                      (0x00080000)
#define PFUNC0_vfd_clk_smt(data)                                                     (0x00080000&((data)<<19))
#define PFUNC0_vfd_clk_smt_src(data)                                                 ((0x00080000&(data))>>19)
#define PFUNC0_get_vfd_clk_smt(data)                                                 ((0x00080000&(data))>>19)
#define PFUNC0_vfd_clk_e2_shift                                                      (18)
#define PFUNC0_vfd_clk_e2_mask                                                       (0x00040000)
#define PFUNC0_vfd_clk_e2(data)                                                      (0x00040000&((data)<<18))
#define PFUNC0_vfd_clk_e2_src(data)                                                  ((0x00040000&(data))>>18)
#define PFUNC0_get_vfd_clk_e2(data)                                                  ((0x00040000&(data))>>18)
#define PFUNC0_vfd_clk_pud_en_shift                                                  (17)
#define PFUNC0_vfd_clk_pud_en_mask                                                   (0x00020000)
#define PFUNC0_vfd_clk_pud_en(data)                                                  (0x00020000&((data)<<17))
#define PFUNC0_vfd_clk_pud_en_src(data)                                              ((0x00020000&(data))>>17)
#define PFUNC0_get_vfd_clk_pud_en(data)                                              ((0x00020000&(data))>>17)
#define PFUNC0_vfd_clk_pud_sel_shift                                                 (16)
#define PFUNC0_vfd_clk_pud_sel_mask                                                  (0x00010000)
#define PFUNC0_vfd_clk_pud_sel(data)                                                 (0x00010000&((data)<<16))
#define PFUNC0_vfd_clk_pud_sel_src(data)                                             ((0x00010000&(data))>>16)
#define PFUNC0_get_vfd_clk_pud_sel(data)                                             ((0x00010000&(data))>>16)
#define PFUNC0_vfd_cs_n_smt_shift                                                    (15)
#define PFUNC0_vfd_cs_n_smt_mask                                                     (0x00008000)
#define PFUNC0_vfd_cs_n_smt(data)                                                    (0x00008000&((data)<<15))
#define PFUNC0_vfd_cs_n_smt_src(data)                                                ((0x00008000&(data))>>15)
#define PFUNC0_get_vfd_cs_n_smt(data)                                                ((0x00008000&(data))>>15)
#define PFUNC0_vfd_cs_n_e2_shift                                                     (14)
#define PFUNC0_vfd_cs_n_e2_mask                                                      (0x00004000)
#define PFUNC0_vfd_cs_n_e2(data)                                                     (0x00004000&((data)<<14))
#define PFUNC0_vfd_cs_n_e2_src(data)                                                 ((0x00004000&(data))>>14)
#define PFUNC0_get_vfd_cs_n_e2(data)                                                 ((0x00004000&(data))>>14)
#define PFUNC0_vfd_cs_n_pud_en_shift                                                 (13)
#define PFUNC0_vfd_cs_n_pud_en_mask                                                  (0x00002000)
#define PFUNC0_vfd_cs_n_pud_en(data)                                                 (0x00002000&((data)<<13))
#define PFUNC0_vfd_cs_n_pud_en_src(data)                                             ((0x00002000&(data))>>13)
#define PFUNC0_get_vfd_cs_n_pud_en(data)                                             ((0x00002000&(data))>>13)
#define PFUNC0_vfd_cs_n_pud_sel_shift                                                (12)
#define PFUNC0_vfd_cs_n_pud_sel_mask                                                 (0x00001000)
#define PFUNC0_vfd_cs_n_pud_sel(data)                                                (0x00001000&((data)<<12))
#define PFUNC0_vfd_cs_n_pud_sel_src(data)                                            ((0x00001000&(data))>>12)
#define PFUNC0_get_vfd_cs_n_pud_sel(data)                                            ((0x00001000&(data))>>12)
#define PFUNC0_ir_rx_smt_shift                                                       (11)
#define PFUNC0_ir_rx_smt_mask                                                        (0x00000800)
#define PFUNC0_ir_rx_smt(data)                                                       (0x00000800&((data)<<11))
#define PFUNC0_ir_rx_smt_src(data)                                                   ((0x00000800&(data))>>11)
#define PFUNC0_get_ir_rx_smt(data)                                                   ((0x00000800&(data))>>11)
#define PFUNC0_ir_rx_e2_shift                                                        (10)
#define PFUNC0_ir_rx_e2_mask                                                         (0x00000400)
#define PFUNC0_ir_rx_e2(data)                                                        (0x00000400&((data)<<10))
#define PFUNC0_ir_rx_e2_src(data)                                                    ((0x00000400&(data))>>10)
#define PFUNC0_get_ir_rx_e2(data)                                                    ((0x00000400&(data))>>10)
#define PFUNC0_ir_rx_pud_en_shift                                                    (9)
#define PFUNC0_ir_rx_pud_en_mask                                                     (0x00000200)
#define PFUNC0_ir_rx_pud_en(data)                                                    (0x00000200&((data)<<9))
#define PFUNC0_ir_rx_pud_en_src(data)                                                ((0x00000200&(data))>>9)
#define PFUNC0_get_ir_rx_pud_en(data)                                                ((0x00000200&(data))>>9)
#define PFUNC0_ir_rx_pud_sel_shift                                                   (8)
#define PFUNC0_ir_rx_pud_sel_mask                                                    (0x00000100)
#define PFUNC0_ir_rx_pud_sel(data)                                                   (0x00000100&((data)<<8))
#define PFUNC0_ir_rx_pud_sel_src(data)                                               ((0x00000100&(data))>>8)
#define PFUNC0_get_ir_rx_pud_sel(data)                                               ((0x00000100&(data))>>8)
#define PFUNC0_usb_ovrcur_flag_n_1_smt_shift                                         (7)
#define PFUNC0_usb_ovrcur_flag_n_1_smt_mask                                          (0x00000080)
#define PFUNC0_usb_ovrcur_flag_n_1_smt(data)                                         (0x00000080&((data)<<7))
#define PFUNC0_usb_ovrcur_flag_n_1_smt_src(data)                                     ((0x00000080&(data))>>7)
#define PFUNC0_get_usb_ovrcur_flag_n_1_smt(data)                                     ((0x00000080&(data))>>7)
#define PFUNC0_usb_ovrcur_flag_n_1_e2_shift                                          (6)
#define PFUNC0_usb_ovrcur_flag_n_1_e2_mask                                           (0x00000040)
#define PFUNC0_usb_ovrcur_flag_n_1_e2(data)                                          (0x00000040&((data)<<6))
#define PFUNC0_usb_ovrcur_flag_n_1_e2_src(data)                                      ((0x00000040&(data))>>6)
#define PFUNC0_get_usb_ovrcur_flag_n_1_e2(data)                                      ((0x00000040&(data))>>6)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_en_shift                                      (5)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_en_mask                                       (0x00000020)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_en(data)                                      (0x00000020&((data)<<5))
#define PFUNC0_usb_ovrcur_flag_n_1_pud_en_src(data)                                  ((0x00000020&(data))>>5)
#define PFUNC0_get_usb_ovrcur_flag_n_1_pud_en(data)                                  ((0x00000020&(data))>>5)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_sel_shift                                     (4)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_sel_mask                                      (0x00000010)
#define PFUNC0_usb_ovrcur_flag_n_1_pud_sel(data)                                     (0x00000010&((data)<<4))
#define PFUNC0_usb_ovrcur_flag_n_1_pud_sel_src(data)                                 ((0x00000010&(data))>>4)
#define PFUNC0_get_usb_ovrcur_flag_n_1_pud_sel(data)                                 ((0x00000010&(data))>>4)
#define PFUNC0_usb_ovrcur_flag_n_0_smt_shift                                         (3)
#define PFUNC0_usb_ovrcur_flag_n_0_smt_mask                                          (0x00000008)
#define PFUNC0_usb_ovrcur_flag_n_0_smt(data)                                         (0x00000008&((data)<<3))
#define PFUNC0_usb_ovrcur_flag_n_0_smt_src(data)                                     ((0x00000008&(data))>>3)
#define PFUNC0_get_usb_ovrcur_flag_n_0_smt(data)                                     ((0x00000008&(data))>>3)
#define PFUNC0_usb_ovrcur_flag_n_0_e2_shift                                          (2)
#define PFUNC0_usb_ovrcur_flag_n_0_e2_mask                                           (0x00000004)
#define PFUNC0_usb_ovrcur_flag_n_0_e2(data)                                          (0x00000004&((data)<<2))
#define PFUNC0_usb_ovrcur_flag_n_0_e2_src(data)                                      ((0x00000004&(data))>>2)
#define PFUNC0_get_usb_ovrcur_flag_n_0_e2(data)                                      ((0x00000004&(data))>>2)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_en_shift                                      (1)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_en_mask                                       (0x00000002)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_en(data)                                      (0x00000002&((data)<<1))
#define PFUNC0_usb_ovrcur_flag_n_0_pud_en_src(data)                                  ((0x00000002&(data))>>1)
#define PFUNC0_get_usb_ovrcur_flag_n_0_pud_en(data)                                  ((0x00000002&(data))>>1)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_sel_shift                                     (0)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_sel_mask                                      (0x00000001)
#define PFUNC0_usb_ovrcur_flag_n_0_pud_sel(data)                                     (0x00000001&((data)<<0))
#define PFUNC0_usb_ovrcur_flag_n_0_pud_sel_src(data)                                 ((0x00000001&(data))>>0)
#define PFUNC0_get_usb_ovrcur_flag_n_0_pud_sel(data)                                 ((0x00000001&(data))>>0)


#define PFUNC1                                                                       0x18007304
#define PFUNC1_reg_addr                                                              "0x18007304"
#define PFUNC1_reg                                                                   0x18007304
#define set_PFUNC1_reg(data)   (*((volatile unsigned int*) PFUNC1_reg)=data)
#define get_PFUNC1_reg   (*((volatile unsigned int*) PFUNC1_reg))
#define PFUNC1_inst_adr                                                              "0x00C1"
#define PFUNC1_inst                                                                  0x00C1
#define PFUNC1_etn_led_rxtx_smt_shift                                                (31)
#define PFUNC1_etn_led_rxtx_smt_mask                                                 (0x80000000)
#define PFUNC1_etn_led_rxtx_smt(data)                                                (0x80000000&((data)<<31))
#define PFUNC1_etn_led_rxtx_smt_src(data)                                            ((0x80000000&(data))>>31)
#define PFUNC1_get_etn_led_rxtx_smt(data)                                            ((0x80000000&(data))>>31)
#define PFUNC1_etn_led_rxtx_e2_shift                                                 (30)
#define PFUNC1_etn_led_rxtx_e2_mask                                                  (0x40000000)
#define PFUNC1_etn_led_rxtx_e2(data)                                                 (0x40000000&((data)<<30))
#define PFUNC1_etn_led_rxtx_e2_src(data)                                             ((0x40000000&(data))>>30)
#define PFUNC1_get_etn_led_rxtx_e2(data)                                             ((0x40000000&(data))>>30)
#define PFUNC1_etn_led_rxtx_pud_en_shift                                             (29)
#define PFUNC1_etn_led_rxtx_pud_en_mask                                              (0x20000000)
#define PFUNC1_etn_led_rxtx_pud_en(data)                                             (0x20000000&((data)<<29))
#define PFUNC1_etn_led_rxtx_pud_en_src(data)                                         ((0x20000000&(data))>>29)
#define PFUNC1_get_etn_led_rxtx_pud_en(data)                                         ((0x20000000&(data))>>29)
#define PFUNC1_etn_led_rxtx_pud_sel_shift                                            (28)
#define PFUNC1_etn_led_rxtx_pud_sel_mask                                             (0x10000000)
#define PFUNC1_etn_led_rxtx_pud_sel(data)                                            (0x10000000&((data)<<28))
#define PFUNC1_etn_led_rxtx_pud_sel_src(data)                                        ((0x10000000&(data))>>28)
#define PFUNC1_get_etn_led_rxtx_pud_sel(data)                                        ((0x10000000&(data))>>28)
#define PFUNC1_etn_led_link_smt_shift                                                (27)
#define PFUNC1_etn_led_link_smt_mask                                                 (0x08000000)
#define PFUNC1_etn_led_link_smt(data)                                                (0x08000000&((data)<<27))
#define PFUNC1_etn_led_link_smt_src(data)                                            ((0x08000000&(data))>>27)
#define PFUNC1_get_etn_led_link_smt(data)                                            ((0x08000000&(data))>>27)
#define PFUNC1_etn_led_link_e2_shift                                                 (26)
#define PFUNC1_etn_led_link_e2_mask                                                  (0x04000000)
#define PFUNC1_etn_led_link_e2(data)                                                 (0x04000000&((data)<<26))
#define PFUNC1_etn_led_link_e2_src(data)                                             ((0x04000000&(data))>>26)
#define PFUNC1_get_etn_led_link_e2(data)                                             ((0x04000000&(data))>>26)
#define PFUNC1_etn_led_link_pud_en_shift                                             (25)
#define PFUNC1_etn_led_link_pud_en_mask                                              (0x02000000)
#define PFUNC1_etn_led_link_pud_en(data)                                             (0x02000000&((data)<<25))
#define PFUNC1_etn_led_link_pud_en_src(data)                                         ((0x02000000&(data))>>25)
#define PFUNC1_get_etn_led_link_pud_en(data)                                         ((0x02000000&(data))>>25)
#define PFUNC1_etn_led_link_pud_sel_shift                                            (24)
#define PFUNC1_etn_led_link_pud_sel_mask                                             (0x01000000)
#define PFUNC1_etn_led_link_pud_sel(data)                                            (0x01000000&((data)<<24))
#define PFUNC1_etn_led_link_pud_sel_src(data)                                        ((0x01000000&(data))>>24)
#define PFUNC1_get_etn_led_link_pud_sel(data)                                        ((0x01000000&(data))>>24)
#define PFUNC1_ur0_tx_smt_shift                                                      (23)
#define PFUNC1_ur0_tx_smt_mask                                                       (0x00800000)
#define PFUNC1_ur0_tx_smt(data)                                                      (0x00800000&((data)<<23))
#define PFUNC1_ur0_tx_smt_src(data)                                                  ((0x00800000&(data))>>23)
#define PFUNC1_get_ur0_tx_smt(data)                                                  ((0x00800000&(data))>>23)
#define PFUNC1_ur0_tx_e2_shift                                                       (22)
#define PFUNC1_ur0_tx_e2_mask                                                        (0x00400000)
#define PFUNC1_ur0_tx_e2(data)                                                       (0x00400000&((data)<<22))
#define PFUNC1_ur0_tx_e2_src(data)                                                   ((0x00400000&(data))>>22)
#define PFUNC1_get_ur0_tx_e2(data)                                                   ((0x00400000&(data))>>22)
#define PFUNC1_ur0_tx_pud_en_shift                                                   (21)
#define PFUNC1_ur0_tx_pud_en_mask                                                    (0x00200000)
#define PFUNC1_ur0_tx_pud_en(data)                                                   (0x00200000&((data)<<21))
#define PFUNC1_ur0_tx_pud_en_src(data)                                               ((0x00200000&(data))>>21)
#define PFUNC1_get_ur0_tx_pud_en(data)                                               ((0x00200000&(data))>>21)
#define PFUNC1_ur0_tx_pud_sel_shift                                                  (20)
#define PFUNC1_ur0_tx_pud_sel_mask                                                   (0x00100000)
#define PFUNC1_ur0_tx_pud_sel(data)                                                  (0x00100000&((data)<<20))
#define PFUNC1_ur0_tx_pud_sel_src(data)                                              ((0x00100000&(data))>>20)
#define PFUNC1_get_ur0_tx_pud_sel(data)                                              ((0x00100000&(data))>>20)
#define PFUNC1_ur0_rx_smt_shift                                                      (19)
#define PFUNC1_ur0_rx_smt_mask                                                       (0x00080000)
#define PFUNC1_ur0_rx_smt(data)                                                      (0x00080000&((data)<<19))
#define PFUNC1_ur0_rx_smt_src(data)                                                  ((0x00080000&(data))>>19)
#define PFUNC1_get_ur0_rx_smt(data)                                                  ((0x00080000&(data))>>19)
#define PFUNC1_ur0_rx_e2_shift                                                       (18)
#define PFUNC1_ur0_rx_e2_mask                                                        (0x00040000)
#define PFUNC1_ur0_rx_e2(data)                                                       (0x00040000&((data)<<18))
#define PFUNC1_ur0_rx_e2_src(data)                                                   ((0x00040000&(data))>>18)
#define PFUNC1_get_ur0_rx_e2(data)                                                   ((0x00040000&(data))>>18)
#define PFUNC1_ur0_rx_pud_en_shift                                                   (17)
#define PFUNC1_ur0_rx_pud_en_mask                                                    (0x00020000)
#define PFUNC1_ur0_rx_pud_en(data)                                                   (0x00020000&((data)<<17))
#define PFUNC1_ur0_rx_pud_en_src(data)                                               ((0x00020000&(data))>>17)
#define PFUNC1_get_ur0_rx_pud_en(data)                                               ((0x00020000&(data))>>17)
#define PFUNC1_ur0_rx_pud_sel_shift                                                  (16)
#define PFUNC1_ur0_rx_pud_sel_mask                                                   (0x00010000)
#define PFUNC1_ur0_rx_pud_sel(data)                                                  (0x00010000&((data)<<16))
#define PFUNC1_ur0_rx_pud_sel_src(data)                                              ((0x00010000&(data))>>16)
#define PFUNC1_get_ur0_rx_pud_sel(data)                                              ((0x00010000&(data))>>16)
#define PFUNC1_ur1_cts_n_smt_shift                                                   (15)
#define PFUNC1_ur1_cts_n_smt_mask                                                    (0x00008000)
#define PFUNC1_ur1_cts_n_smt(data)                                                   (0x00008000&((data)<<15))
#define PFUNC1_ur1_cts_n_smt_src(data)                                               ((0x00008000&(data))>>15)
#define PFUNC1_get_ur1_cts_n_smt(data)                                               ((0x00008000&(data))>>15)
#define PFUNC1_ur1_cts_n_e2_shift                                                    (14)
#define PFUNC1_ur1_cts_n_e2_mask                                                     (0x00004000)
#define PFUNC1_ur1_cts_n_e2(data)                                                    (0x00004000&((data)<<14))
#define PFUNC1_ur1_cts_n_e2_src(data)                                                ((0x00004000&(data))>>14)
#define PFUNC1_get_ur1_cts_n_e2(data)                                                ((0x00004000&(data))>>14)
#define PFUNC1_ur1_cts_n_pud_en_shift                                                (13)
#define PFUNC1_ur1_cts_n_pud_en_mask                                                 (0x00002000)
#define PFUNC1_ur1_cts_n_pud_en(data)                                                (0x00002000&((data)<<13))
#define PFUNC1_ur1_cts_n_pud_en_src(data)                                            ((0x00002000&(data))>>13)
#define PFUNC1_get_ur1_cts_n_pud_en(data)                                            ((0x00002000&(data))>>13)
#define PFUNC1_ur1_cts_n_pud_sel_shift                                               (12)
#define PFUNC1_ur1_cts_n_pud_sel_mask                                                (0x00001000)
#define PFUNC1_ur1_cts_n_pud_sel(data)                                               (0x00001000&((data)<<12))
#define PFUNC1_ur1_cts_n_pud_sel_src(data)                                           ((0x00001000&(data))>>12)
#define PFUNC1_get_ur1_cts_n_pud_sel(data)                                           ((0x00001000&(data))>>12)
#define PFUNC1_ur1_rts_n_smt_shift                                                   (11)
#define PFUNC1_ur1_rts_n_smt_mask                                                    (0x00000800)
#define PFUNC1_ur1_rts_n_smt(data)                                                   (0x00000800&((data)<<11))
#define PFUNC1_ur1_rts_n_smt_src(data)                                               ((0x00000800&(data))>>11)
#define PFUNC1_get_ur1_rts_n_smt(data)                                               ((0x00000800&(data))>>11)
#define PFUNC1_ur1_rts_n_e2_shift                                                    (10)
#define PFUNC1_ur1_rts_n_e2_mask                                                     (0x00000400)
#define PFUNC1_ur1_rts_n_e2(data)                                                    (0x00000400&((data)<<10))
#define PFUNC1_ur1_rts_n_e2_src(data)                                                ((0x00000400&(data))>>10)
#define PFUNC1_get_ur1_rts_n_e2(data)                                                ((0x00000400&(data))>>10)
#define PFUNC1_ur1_rts_n_pud_en_shift                                                (9)
#define PFUNC1_ur1_rts_n_pud_en_mask                                                 (0x00000200)
#define PFUNC1_ur1_rts_n_pud_en(data)                                                (0x00000200&((data)<<9))
#define PFUNC1_ur1_rts_n_pud_en_src(data)                                            ((0x00000200&(data))>>9)
#define PFUNC1_get_ur1_rts_n_pud_en(data)                                            ((0x00000200&(data))>>9)
#define PFUNC1_ur1_rts_n_pud_sel_shift                                               (8)
#define PFUNC1_ur1_rts_n_pud_sel_mask                                                (0x00000100)
#define PFUNC1_ur1_rts_n_pud_sel(data)                                               (0x00000100&((data)<<8))
#define PFUNC1_ur1_rts_n_pud_sel_src(data)                                           ((0x00000100&(data))>>8)
#define PFUNC1_get_ur1_rts_n_pud_sel(data)                                           ((0x00000100&(data))>>8)
#define PFUNC1_ur1_tx_smt_shift                                                      (7)
#define PFUNC1_ur1_tx_smt_mask                                                       (0x00000080)
#define PFUNC1_ur1_tx_smt(data)                                                      (0x00000080&((data)<<7))
#define PFUNC1_ur1_tx_smt_src(data)                                                  ((0x00000080&(data))>>7)
#define PFUNC1_get_ur1_tx_smt(data)                                                  ((0x00000080&(data))>>7)
#define PFUNC1_ur1_tx_e2_shift                                                       (6)
#define PFUNC1_ur1_tx_e2_mask                                                        (0x00000040)
#define PFUNC1_ur1_tx_e2(data)                                                       (0x00000040&((data)<<6))
#define PFUNC1_ur1_tx_e2_src(data)                                                   ((0x00000040&(data))>>6)
#define PFUNC1_get_ur1_tx_e2(data)                                                   ((0x00000040&(data))>>6)
#define PFUNC1_ur1_tx_pud_en_shift                                                   (5)
#define PFUNC1_ur1_tx_pud_en_mask                                                    (0x00000020)
#define PFUNC1_ur1_tx_pud_en(data)                                                   (0x00000020&((data)<<5))
#define PFUNC1_ur1_tx_pud_en_src(data)                                               ((0x00000020&(data))>>5)
#define PFUNC1_get_ur1_tx_pud_en(data)                                               ((0x00000020&(data))>>5)
#define PFUNC1_ur1_tx_pud_sel_shift                                                  (4)
#define PFUNC1_ur1_tx_pud_sel_mask                                                   (0x00000010)
#define PFUNC1_ur1_tx_pud_sel(data)                                                  (0x00000010&((data)<<4))
#define PFUNC1_ur1_tx_pud_sel_src(data)                                              ((0x00000010&(data))>>4)
#define PFUNC1_get_ur1_tx_pud_sel(data)                                              ((0x00000010&(data))>>4)
#define PFUNC1_ur1_rx_smt_shift                                                      (3)
#define PFUNC1_ur1_rx_smt_mask                                                       (0x00000008)
#define PFUNC1_ur1_rx_smt(data)                                                      (0x00000008&((data)<<3))
#define PFUNC1_ur1_rx_smt_src(data)                                                  ((0x00000008&(data))>>3)
#define PFUNC1_get_ur1_rx_smt(data)                                                  ((0x00000008&(data))>>3)
#define PFUNC1_ur1_rx_e2_shift                                                       (2)
#define PFUNC1_ur1_rx_e2_mask                                                        (0x00000004)
#define PFUNC1_ur1_rx_e2(data)                                                       (0x00000004&((data)<<2))
#define PFUNC1_ur1_rx_e2_src(data)                                                   ((0x00000004&(data))>>2)
#define PFUNC1_get_ur1_rx_e2(data)                                                   ((0x00000004&(data))>>2)
#define PFUNC1_ur1_rx_pud_en_shift                                                   (1)
#define PFUNC1_ur1_rx_pud_en_mask                                                    (0x00000002)
#define PFUNC1_ur1_rx_pud_en(data)                                                   (0x00000002&((data)<<1))
#define PFUNC1_ur1_rx_pud_en_src(data)                                               ((0x00000002&(data))>>1)
#define PFUNC1_get_ur1_rx_pud_en(data)                                               ((0x00000002&(data))>>1)
#define PFUNC1_ur1_rx_pud_sel_shift                                                  (0)
#define PFUNC1_ur1_rx_pud_sel_mask                                                   (0x00000001)
#define PFUNC1_ur1_rx_pud_sel(data)                                                  (0x00000001&((data)<<0))
#define PFUNC1_ur1_rx_pud_sel_src(data)                                              ((0x00000001&(data))>>0)
#define PFUNC1_get_ur1_rx_pud_sel(data)                                              ((0x00000001&(data))>>0)


#define PFUNC2                                                                       0x18007308
#define PFUNC2_reg_addr                                                              "0x18007308"
#define PFUNC2_reg                                                                   0x18007308
#define set_PFUNC2_reg(data)   (*((volatile unsigned int*) PFUNC2_reg)=data)
#define get_PFUNC2_reg   (*((volatile unsigned int*) PFUNC2_reg))
#define PFUNC2_inst_adr                                                              "0x00C2"
#define PFUNC2_inst                                                                  0x00C2
#define PFUNC2_ir_tx_smt_shift                                                       (23)
#define PFUNC2_ir_tx_smt_mask                                                        (0x00800000)
#define PFUNC2_ir_tx_smt(data)                                                       (0x00800000&((data)<<23))
#define PFUNC2_ir_tx_smt_src(data)                                                   ((0x00800000&(data))>>23)
#define PFUNC2_get_ir_tx_smt(data)                                                   ((0x00800000&(data))>>23)
#define PFUNC2_ir_tx_e2_shift                                                        (22)
#define PFUNC2_ir_tx_e2_mask                                                         (0x00400000)
#define PFUNC2_ir_tx_e2(data)                                                        (0x00400000&((data)<<22))
#define PFUNC2_ir_tx_e2_src(data)                                                    ((0x00400000&(data))>>22)
#define PFUNC2_get_ir_tx_e2(data)                                                    ((0x00400000&(data))>>22)
#define PFUNC2_ir_tx_pud_en_shift                                                    (21)
#define PFUNC2_ir_tx_pud_en_mask                                                     (0x00200000)
#define PFUNC2_ir_tx_pud_en(data)                                                    (0x00200000&((data)<<21))
#define PFUNC2_ir_tx_pud_en_src(data)                                                ((0x00200000&(data))>>21)
#define PFUNC2_get_ir_tx_pud_en(data)                                                ((0x00200000&(data))>>21)
#define PFUNC2_ir_tx_pud_sel_shift                                                   (20)
#define PFUNC2_ir_tx_pud_sel_mask                                                    (0x00100000)
#define PFUNC2_ir_tx_pud_sel(data)                                                   (0x00100000&((data)<<20))
#define PFUNC2_ir_tx_pud_sel_src(data)                                               ((0x00100000&(data))>>20)
#define PFUNC2_get_ir_tx_pud_sel(data)                                               ((0x00100000&(data))>>20)
#define PFUNC2_i2c_scl_6_smt_shift                                                   (19)
#define PFUNC2_i2c_scl_6_smt_mask                                                    (0x00080000)
#define PFUNC2_i2c_scl_6_smt(data)                                                   (0x00080000&((data)<<19))
#define PFUNC2_i2c_scl_6_smt_src(data)                                               ((0x00080000&(data))>>19)
#define PFUNC2_get_i2c_scl_6_smt(data)                                               ((0x00080000&(data))>>19)
#define PFUNC2_i2c_scl_6_e2_shift                                                    (18)
#define PFUNC2_i2c_scl_6_e2_mask                                                     (0x00040000)
#define PFUNC2_i2c_scl_6_e2(data)                                                    (0x00040000&((data)<<18))
#define PFUNC2_i2c_scl_6_e2_src(data)                                                ((0x00040000&(data))>>18)
#define PFUNC2_get_i2c_scl_6_e2(data)                                                ((0x00040000&(data))>>18)
#define PFUNC2_i2c_scl_6_pud_en_shift                                                (17)
#define PFUNC2_i2c_scl_6_pud_en_mask                                                 (0x00020000)
#define PFUNC2_i2c_scl_6_pud_en(data)                                                (0x00020000&((data)<<17))
#define PFUNC2_i2c_scl_6_pud_en_src(data)                                            ((0x00020000&(data))>>17)
#define PFUNC2_get_i2c_scl_6_pud_en(data)                                            ((0x00020000&(data))>>17)
#define PFUNC2_i2c_scl_6_pud_sel_shift                                               (16)
#define PFUNC2_i2c_scl_6_pud_sel_mask                                                (0x00010000)
#define PFUNC2_i2c_scl_6_pud_sel(data)                                               (0x00010000&((data)<<16))
#define PFUNC2_i2c_scl_6_pud_sel_src(data)                                           ((0x00010000&(data))>>16)
#define PFUNC2_get_i2c_scl_6_pud_sel(data)                                           ((0x00010000&(data))>>16)
#define PFUNC2_i2c_sda_6_smt_shift                                                   (15)
#define PFUNC2_i2c_sda_6_smt_mask                                                    (0x00008000)
#define PFUNC2_i2c_sda_6_smt(data)                                                   (0x00008000&((data)<<15))
#define PFUNC2_i2c_sda_6_smt_src(data)                                               ((0x00008000&(data))>>15)
#define PFUNC2_get_i2c_sda_6_smt(data)                                               ((0x00008000&(data))>>15)
#define PFUNC2_i2c_sda_6_e2_shift                                                    (14)
#define PFUNC2_i2c_sda_6_e2_mask                                                     (0x00004000)
#define PFUNC2_i2c_sda_6_e2(data)                                                    (0x00004000&((data)<<14))
#define PFUNC2_i2c_sda_6_e2_src(data)                                                ((0x00004000&(data))>>14)
#define PFUNC2_get_i2c_sda_6_e2(data)                                                ((0x00004000&(data))>>14)
#define PFUNC2_i2c_sda_6_pud_en_shift                                                (13)
#define PFUNC2_i2c_sda_6_pud_en_mask                                                 (0x00002000)
#define PFUNC2_i2c_sda_6_pud_en(data)                                                (0x00002000&((data)<<13))
#define PFUNC2_i2c_sda_6_pud_en_src(data)                                            ((0x00002000&(data))>>13)
#define PFUNC2_get_i2c_sda_6_pud_en(data)                                            ((0x00002000&(data))>>13)
#define PFUNC2_i2c_sda_6_pud_sel_shift                                               (12)
#define PFUNC2_i2c_sda_6_pud_sel_mask                                                (0x00001000)
#define PFUNC2_i2c_sda_6_pud_sel(data)                                               (0x00001000&((data)<<12))
#define PFUNC2_i2c_sda_6_pud_sel_src(data)                                           ((0x00001000&(data))>>12)
#define PFUNC2_get_i2c_sda_6_pud_sel(data)                                           ((0x00001000&(data))>>12)
#define PFUNC2_boot_sel_pud_en_shift                                                 (11)
#define PFUNC2_boot_sel_pud_en_mask                                                  (0x00000800)
#define PFUNC2_boot_sel_pud_en(data)                                                 (0x00000800&((data)<<11))
#define PFUNC2_boot_sel_pud_en_src(data)                                             ((0x00000800&(data))>>11)
#define PFUNC2_get_boot_sel_pud_en(data)                                             ((0x00000800&(data))>>11)
#define PFUNC2_boot_sel_pud_sel_shift                                                (10)
#define PFUNC2_boot_sel_pud_sel_mask                                                 (0x00000400)
#define PFUNC2_boot_sel_pud_sel(data)                                                (0x00000400&((data)<<10))
#define PFUNC2_boot_sel_pud_sel_src(data)                                            ((0x00000400&(data))>>10)
#define PFUNC2_get_boot_sel_pud_sel(data)                                            ((0x00000400&(data))>>10)
#define PFUNC2_testmode_pud_en_shift                                                 (9)
#define PFUNC2_testmode_pud_en_mask                                                  (0x00000200)
#define PFUNC2_testmode_pud_en(data)                                                 (0x00000200&((data)<<9))
#define PFUNC2_testmode_pud_en_src(data)                                             ((0x00000200&(data))>>9)
#define PFUNC2_get_testmode_pud_en(data)                                             ((0x00000200&(data))>>9)
#define PFUNC2_testmode_pud_sel_shift                                                (8)
#define PFUNC2_testmode_pud_sel_mask                                                 (0x00000100)
#define PFUNC2_testmode_pud_sel(data)                                                (0x00000100&((data)<<8))
#define PFUNC2_testmode_pud_sel_src(data)                                            ((0x00000100&(data))>>8)
#define PFUNC2_get_testmode_pud_sel(data)                                            ((0x00000100&(data))>>8)
#define PFUNC2_standby1_smt_shift                                                    (7)
#define PFUNC2_standby1_smt_mask                                                     (0x00000080)
#define PFUNC2_standby1_smt(data)                                                    (0x00000080&((data)<<7))
#define PFUNC2_standby1_smt_src(data)                                                ((0x00000080&(data))>>7)
#define PFUNC2_get_standby1_smt(data)                                                ((0x00000080&(data))>>7)
#define PFUNC2_standby1_e2_shift                                                     (6)
#define PFUNC2_standby1_e2_mask                                                      (0x00000040)
#define PFUNC2_standby1_e2(data)                                                     (0x00000040&((data)<<6))
#define PFUNC2_standby1_e2_src(data)                                                 ((0x00000040&(data))>>6)
#define PFUNC2_get_standby1_e2(data)                                                 ((0x00000040&(data))>>6)
#define PFUNC2_standby1_pud_en_shift                                                 (5)
#define PFUNC2_standby1_pud_en_mask                                                  (0x00000020)
#define PFUNC2_standby1_pud_en(data)                                                 (0x00000020&((data)<<5))
#define PFUNC2_standby1_pud_en_src(data)                                             ((0x00000020&(data))>>5)
#define PFUNC2_get_standby1_pud_en(data)                                             ((0x00000020&(data))>>5)
#define PFUNC2_standby1_pud_sel_shift                                                (4)
#define PFUNC2_standby1_pud_sel_mask                                                 (0x00000010)
#define PFUNC2_standby1_pud_sel(data)                                                (0x00000010&((data)<<4))
#define PFUNC2_standby1_pud_sel_src(data)                                            ((0x00000010&(data))>>4)
#define PFUNC2_get_standby1_pud_sel(data)                                            ((0x00000010&(data))>>4)
#define PFUNC2_standby_smt_shift                                                     (3)
#define PFUNC2_standby_smt_mask                                                      (0x00000008)
#define PFUNC2_standby_smt(data)                                                     (0x00000008&((data)<<3))
#define PFUNC2_standby_smt_src(data)                                                 ((0x00000008&(data))>>3)
#define PFUNC2_get_standby_smt(data)                                                 ((0x00000008&(data))>>3)
#define PFUNC2_standby_e2_shift                                                      (2)
#define PFUNC2_standby_e2_mask                                                       (0x00000004)
#define PFUNC2_standby_e2(data)                                                      (0x00000004&((data)<<2))
#define PFUNC2_standby_e2_src(data)                                                  ((0x00000004&(data))>>2)
#define PFUNC2_get_standby_e2(data)                                                  ((0x00000004&(data))>>2)
#define PFUNC2_standby_pud_en_shift                                                  (1)
#define PFUNC2_standby_pud_en_mask                                                   (0x00000002)
#define PFUNC2_standby_pud_en(data)                                                  (0x00000002&((data)<<1))
#define PFUNC2_standby_pud_en_src(data)                                              ((0x00000002&(data))>>1)
#define PFUNC2_get_standby_pud_en(data)                                              ((0x00000002&(data))>>1)
#define PFUNC2_standby_pud_sel_shift                                                 (0)
#define PFUNC2_standby_pud_sel_mask                                                  (0x00000001)
#define PFUNC2_standby_pud_sel(data)                                                 (0x00000001&((data)<<0))
#define PFUNC2_standby_pud_sel_src(data)                                             ((0x00000001&(data))>>0)
#define PFUNC2_get_standby_pud_sel(data)                                             ((0x00000001&(data))>>0)


#define PFUNC3                                                                       0x1800730C
#define PFUNC3_reg_addr                                                              "0x1800730C"
#define PFUNC3_reg                                                                   0x1800730C
#define set_PFUNC3_reg(data)   (*((volatile unsigned int*) PFUNC3_reg)=data)
#define get_PFUNC3_reg   (*((volatile unsigned int*) PFUNC3_reg))
#define PFUNC3_inst_adr                                                              "0x00C3"
#define PFUNC3_inst                                                                  0x00C3
#define PFUNC3_boption12_en_shift                                                    (7)
#define PFUNC3_boption12_en_mask                                                     (0x00000080)
#define PFUNC3_boption12_en(data)                                                    (0x00000080&((data)<<7))
#define PFUNC3_boption12_en_src(data)                                                ((0x00000080&(data))>>7)
#define PFUNC3_get_boption12_en(data)                                                ((0x00000080&(data))>>7)
#define PFUNC3_boption12_sel_shift                                                   (6)
#define PFUNC3_boption12_sel_mask                                                    (0x00000040)
#define PFUNC3_boption12_sel(data)                                                   (0x00000040&((data)<<6))
#define PFUNC3_boption12_sel_src(data)                                               ((0x00000040&(data))>>6)
#define PFUNC3_get_boption12_sel(data)                                               ((0x00000040&(data))>>6)
#define PFUNC3_boption11_en_shift                                                    (5)
#define PFUNC3_boption11_en_mask                                                     (0x00000020)
#define PFUNC3_boption11_en(data)                                                    (0x00000020&((data)<<5))
#define PFUNC3_boption11_en_src(data)                                                ((0x00000020&(data))>>5)
#define PFUNC3_get_boption11_en(data)                                                ((0x00000020&(data))>>5)
#define PFUNC3_boption11_sel_shift                                                   (4)
#define PFUNC3_boption11_sel_mask                                                    (0x00000010)
#define PFUNC3_boption11_sel(data)                                                   (0x00000010&((data)<<4))
#define PFUNC3_boption11_sel_src(data)                                               ((0x00000010&(data))>>4)
#define PFUNC3_get_boption11_sel(data)                                               ((0x00000010&(data))>>4)
#define PFUNC3_boption10_en_shift                                                    (3)
#define PFUNC3_boption10_en_mask                                                     (0x00000008)
#define PFUNC3_boption10_en(data)                                                    (0x00000008&((data)<<3))
#define PFUNC3_boption10_en_src(data)                                                ((0x00000008&(data))>>3)
#define PFUNC3_get_boption10_en(data)                                                ((0x00000008&(data))>>3)
#define PFUNC3_boption10_sel_shift                                                   (2)
#define PFUNC3_boption10_sel_mask                                                    (0x00000004)
#define PFUNC3_boption10_sel(data)                                                   (0x00000004&((data)<<2))
#define PFUNC3_boption10_sel_src(data)                                               ((0x00000004&(data))>>2)
#define PFUNC3_get_boption10_sel(data)                                               ((0x00000004&(data))>>2)
#define PFUNC3_boption2_en_shift                                                     (1)
#define PFUNC3_boption2_en_mask                                                      (0x00000002)
#define PFUNC3_boption2_en(data)                                                     (0x00000002&((data)<<1))
#define PFUNC3_boption2_en_src(data)                                                 ((0x00000002&(data))>>1)
#define PFUNC3_get_boption2_en(data)                                                 ((0x00000002&(data))>>1)
#define PFUNC3_boption2_sel_shift                                                    (0)
#define PFUNC3_boption2_sel_mask                                                     (0x00000001)
#define PFUNC3_boption2_sel(data)                                                    (0x00000001&((data)<<0))
#define PFUNC3_boption2_sel_src(data)                                                ((0x00000001&(data))>>0)
#define PFUNC3_get_boption2_sel(data)                                                ((0x00000001&(data))>>0)


#define MUXPAD0                                                                      0x18007310
#define MUXPAD0_reg_addr                                                             "0x18007310"
#define MUXPAD0_reg                                                                  0x18007310
#define set_MUXPAD0_reg(data)   (*((volatile unsigned int*) MUXPAD0_reg)=data)
#define get_MUXPAD0_reg   (*((volatile unsigned int*) MUXPAD0_reg))
#define MUXPAD0_inst_adr                                                             "0x00C4"
#define MUXPAD0_inst                                                                 0x00C4
#define MUXPAD0_etn_led_rxtx_shift                                                   (30)
#define MUXPAD0_etn_led_rxtx_mask                                                    (0xC0000000)
#define MUXPAD0_etn_led_rxtx(data)                                                   (0xC0000000&((data)<<30))
#define MUXPAD0_etn_led_rxtx_src(data)                                               ((0xC0000000&(data))>>30)
#define MUXPAD0_get_etn_led_rxtx(data)                                               ((0xC0000000&(data))>>30)
#define MUXPAD0_etn_led_link_shift                                                   (28)
#define MUXPAD0_etn_led_link_mask                                                    (0x30000000)
#define MUXPAD0_etn_led_link(data)                                                   (0x30000000&((data)<<28))
#define MUXPAD0_etn_led_link_src(data)                                               ((0x30000000&(data))>>28)
#define MUXPAD0_get_etn_led_link(data)                                               ((0x30000000&(data))>>28)
#define MUXPAD0_i2c_sda_0_shift                                                      (26)
#define MUXPAD0_i2c_sda_0_mask                                                       (0x0C000000)
#define MUXPAD0_i2c_sda_0(data)                                                      (0x0C000000&((data)<<26))
#define MUXPAD0_i2c_sda_0_src(data)                                                  ((0x0C000000&(data))>>26)
#define MUXPAD0_get_i2c_sda_0(data)                                                  ((0x0C000000&(data))>>26)
#define MUXPAD0_i2c_scl_0_shift                                                      (24)
#define MUXPAD0_i2c_scl_0_mask                                                       (0x03000000)
#define MUXPAD0_i2c_scl_0(data)                                                      (0x03000000&((data)<<24))
#define MUXPAD0_i2c_scl_0_src(data)                                                  ((0x03000000&(data))>>24)
#define MUXPAD0_get_i2c_scl_0(data)                                                  ((0x03000000&(data))>>24)
#define MUXPAD0_ur0_tx_shift                                                         (22)
#define MUXPAD0_ur0_tx_mask                                                          (0x00C00000)
#define MUXPAD0_ur0_tx(data)                                                         (0x00C00000&((data)<<22))
#define MUXPAD0_ur0_tx_src(data)                                                     ((0x00C00000&(data))>>22)
#define MUXPAD0_get_ur0_tx(data)                                                     ((0x00C00000&(data))>>22)
#define MUXPAD0_ur0_rx_shift                                                         (20)
#define MUXPAD0_ur0_rx_mask                                                          (0x00300000)
#define MUXPAD0_ur0_rx(data)                                                         (0x00300000&((data)<<20))
#define MUXPAD0_ur0_rx_src(data)                                                     ((0x00300000&(data))>>20)
#define MUXPAD0_get_ur0_rx(data)                                                     ((0x00300000&(data))>>20)
#define MUXPAD0_ur1_cts_n_shift                                                      (18)
#define MUXPAD0_ur1_cts_n_mask                                                       (0x000C0000)
#define MUXPAD0_ur1_cts_n(data)                                                      (0x000C0000&((data)<<18))
#define MUXPAD0_ur1_cts_n_src(data)                                                  ((0x000C0000&(data))>>18)
#define MUXPAD0_get_ur1_cts_n(data)                                                  ((0x000C0000&(data))>>18)
#define MUXPAD0_ur1_rts_n_shift                                                      (16)
#define MUXPAD0_ur1_rts_n_mask                                                       (0x00030000)
#define MUXPAD0_ur1_rts_n(data)                                                      (0x00030000&((data)<<16))
#define MUXPAD0_ur1_rts_n_src(data)                                                  ((0x00030000&(data))>>16)
#define MUXPAD0_get_ur1_rts_n(data)                                                  ((0x00030000&(data))>>16)
#define MUXPAD0_ur1_tx_shift                                                         (14)
#define MUXPAD0_ur1_tx_mask                                                          (0x0000C000)
#define MUXPAD0_ur1_tx(data)                                                         (0x0000C000&((data)<<14))
#define MUXPAD0_ur1_tx_src(data)                                                     ((0x0000C000&(data))>>14)
#define MUXPAD0_get_ur1_tx(data)                                                     ((0x0000C000&(data))>>14)
#define MUXPAD0_ur1_rx_shift                                                         (12)
#define MUXPAD0_ur1_rx_mask                                                          (0x00003000)
#define MUXPAD0_ur1_rx(data)                                                         (0x00003000&((data)<<12))
#define MUXPAD0_ur1_rx_src(data)                                                     ((0x00003000&(data))>>12)
#define MUXPAD0_get_ur1_rx(data)                                                     ((0x00003000&(data))>>12)
#define MUXPAD0_usb1_shift                                                           (10)
#define MUXPAD0_usb1_mask                                                            (0x00000C00)
#define MUXPAD0_usb1(data)                                                           (0x00000C00&((data)<<10))
#define MUXPAD0_usb1_src(data)                                                       ((0x00000C00&(data))>>10)
#define MUXPAD0_get_usb1(data)                                                       ((0x00000C00&(data))>>10)
#define MUXPAD0_usb0_shift                                                           (8)
#define MUXPAD0_usb0_mask                                                            (0x00000300)
#define MUXPAD0_usb0(data)                                                           (0x00000300&((data)<<8))
#define MUXPAD0_usb0_src(data)                                                       ((0x00000300&(data))>>8)
#define MUXPAD0_get_usb0(data)                                                       ((0x00000300&(data))>>8)
#define MUXPAD0_ir_rx_shift                                                          (6)
#define MUXPAD0_ir_rx_mask                                                           (0x000000C0)
#define MUXPAD0_ir_rx(data)                                                          (0x000000C0&((data)<<6))
#define MUXPAD0_ir_rx_src(data)                                                      ((0x000000C0&(data))>>6)
#define MUXPAD0_get_ir_rx(data)                                                      ((0x000000C0&(data))>>6)
#define MUXPAD0_vfd_cs_n_shift                                                       (4)
#define MUXPAD0_vfd_cs_n_mask                                                        (0x00000030)
#define MUXPAD0_vfd_cs_n(data)                                                       (0x00000030&((data)<<4))
#define MUXPAD0_vfd_cs_n_src(data)                                                   ((0x00000030&(data))>>4)
#define MUXPAD0_get_vfd_cs_n(data)                                                   ((0x00000030&(data))>>4)
#define MUXPAD0_vfd_clk_shift                                                        (2)
#define MUXPAD0_vfd_clk_mask                                                         (0x0000000C)
#define MUXPAD0_vfd_clk(data)                                                        (0x0000000C&((data)<<2))
#define MUXPAD0_vfd_clk_src(data)                                                    ((0x0000000C&(data))>>2)
#define MUXPAD0_get_vfd_clk(data)                                                    ((0x0000000C&(data))>>2)
#define MUXPAD0_vfd_d_shift                                                          (0)
#define MUXPAD0_vfd_d_mask                                                           (0x00000003)
#define MUXPAD0_vfd_d(data)                                                          (0x00000003&((data)<<0))
#define MUXPAD0_vfd_d_src(data)                                                      ((0x00000003&(data))>>0)
#define MUXPAD0_get_vfd_d(data)                                                      ((0x00000003&(data))>>0)


#define MUXPAD1                                                                      0x18007314
#define MUXPAD1_reg_addr                                                             "0x18007314"
#define MUXPAD1_reg                                                                  0x18007314
#define set_MUXPAD1_reg(data)   (*((volatile unsigned int*) MUXPAD1_reg)=data)
#define get_MUXPAD1_reg   (*((volatile unsigned int*) MUXPAD1_reg))
#define MUXPAD1_inst_adr                                                             "0x00C5"
#define MUXPAD1_inst                                                                 0x00C5
#define MUXPAD1_ai_loc_shift                                                         (30)
#define MUXPAD1_ai_loc_mask                                                          (0xC0000000)
#define MUXPAD1_ai_loc(data)                                                         (0xC0000000&((data)<<30))
#define MUXPAD1_ai_loc_src(data)                                                     ((0xC0000000&(data))>>30)
#define MUXPAD1_get_ai_loc(data)                                                     ((0xC0000000&(data))>>30)
#define MUXPAD1_ejtag_avcpu_loc_shift                                                (28)
#define MUXPAD1_ejtag_avcpu_loc_mask                                                 (0x30000000)
#define MUXPAD1_ejtag_avcpu_loc(data)                                                (0x30000000&((data)<<28))
#define MUXPAD1_ejtag_avcpu_loc_src(data)                                            ((0x30000000&(data))>>28)
#define MUXPAD1_get_ejtag_avcpu_loc(data)                                            ((0x30000000&(data))>>28)
#define MUXPAD1_ur1_loc_shift                                                        (26)
#define MUXPAD1_ur1_loc_mask                                                         (0x0C000000)
#define MUXPAD1_ur1_loc(data)                                                        (0x0C000000&((data)<<26))
#define MUXPAD1_ur1_loc_src(data)                                                    ((0x0C000000&(data))>>26)
#define MUXPAD1_get_ur1_loc(data)                                                    ((0x0C000000&(data))>>26)
#define MUXPAD1_pwm_01_open_drain_switch_shift                                       (25)
#define MUXPAD1_pwm_01_open_drain_switch_mask                                        (0x02000000)
#define MUXPAD1_pwm_01_open_drain_switch(data)                                       (0x02000000&((data)<<25))
#define MUXPAD1_pwm_01_open_drain_switch_src(data)                                   ((0x02000000&(data))>>25)
#define MUXPAD1_get_pwm_01_open_drain_switch(data)                                   ((0x02000000&(data))>>25)
#define MUXPAD1_pwm_23_open_drain_switch_shift                                       (24)
#define MUXPAD1_pwm_23_open_drain_switch_mask                                        (0x01000000)
#define MUXPAD1_pwm_23_open_drain_switch(data)                                       (0x01000000&((data)<<24))
#define MUXPAD1_pwm_23_open_drain_switch_src(data)                                   ((0x01000000&(data))>>24)
#define MUXPAD1_get_pwm_23_open_drain_switch(data)                                   ((0x01000000&(data))>>24)
#define MUXPAD1_ir_tx_shift                                                          (4)
#define MUXPAD1_ir_tx_mask                                                           (0x00000030)
#define MUXPAD1_ir_tx(data)                                                          (0x00000030&((data)<<4))
#define MUXPAD1_ir_tx_src(data)                                                      ((0x00000030&(data))>>4)
#define MUXPAD1_get_ir_tx(data)                                                      ((0x00000030&(data))>>4)
#define MUXPAD1_i2c_sda_6_shift                                                      (2)
#define MUXPAD1_i2c_sda_6_mask                                                       (0x0000000C)
#define MUXPAD1_i2c_sda_6(data)                                                      (0x0000000C&((data)<<2))
#define MUXPAD1_i2c_sda_6_src(data)                                                  ((0x0000000C&(data))>>2)
#define MUXPAD1_get_i2c_sda_6(data)                                                  ((0x0000000C&(data))>>2)
#define MUXPAD1_i2c_scl_6_shift                                                      (0)
#define MUXPAD1_i2c_scl_6_mask                                                       (0x00000003)
#define MUXPAD1_i2c_scl_6(data)                                                      (0x00000003&((data)<<0))
#define MUXPAD1_i2c_scl_6_src(data)                                                  ((0x00000003&(data))>>0)
#define MUXPAD1_get_i2c_scl_6(data)                                                  ((0x00000003&(data))>>0)


#define IR_PSR                                                                       0x18007400
#define IR_PSR_reg_addr                                                              "0x18007400"
#define IR_PSR_reg                                                                   0x18007400
#define set_IR_PSR_reg(data)   (*((volatile unsigned int*) IR_PSR_reg)=data)
#define get_IR_PSR_reg   (*((volatile unsigned int*) IR_PSR_reg))
#define IR_PSR_inst_adr                                                              "0x0000"
#define IR_PSR_inst                                                                  0x0000
#define IR_PSR_IRRBL_shift                                                           (24)
#define IR_PSR_IRRBL_mask                                                            (0xFF000000)
#define IR_PSR_IRRBL(data)                                                           (0xFF000000&((data)<<24))
#define IR_PSR_IRRBL_src(data)                                                       ((0xFF000000&(data))>>24)
#define IR_PSR_get_IRRBL(data)                                                       ((0xFF000000&(data))>>24)
#define IR_PSR_IRRML_shift                                                           (16)
#define IR_PSR_IRRML_mask                                                            (0x00FF0000)
#define IR_PSR_IRRML(data)                                                           (0x00FF0000&((data)<<16))
#define IR_PSR_IRRML_src(data)                                                       ((0x00FF0000&(data))>>16)
#define IR_PSR_get_IRRML(data)                                                       ((0x00FF0000&(data))>>16)
#define IR_PSR_IRRDZL_shift                                                          (8)
#define IR_PSR_IRRDZL_mask                                                           (0x0000FF00)
#define IR_PSR_IRRDZL(data)                                                          (0x0000FF00&((data)<<8))
#define IR_PSR_IRRDZL_src(data)                                                      ((0x0000FF00&(data))>>8)
#define IR_PSR_get_IRRDZL(data)                                                      ((0x0000FF00&(data))>>8)
#define IR_PSR_IRRDOL_shift                                                          (0)
#define IR_PSR_IRRDOL_mask                                                           (0x000000FF)
#define IR_PSR_IRRDOL(data)                                                          (0x000000FF&((data)<<0))
#define IR_PSR_IRRDOL_src(data)                                                      ((0x000000FF&(data))>>0)
#define IR_PSR_get_IRRDOL(data)                                                      ((0x000000FF&(data))>>0)


#define IR_PER                                                                       0x18007404
#define IR_PER_reg_addr                                                              "0x18007404"
#define IR_PER_reg                                                                   0x18007404
#define set_IR_PER_reg(data)   (*((volatile unsigned int*) IR_PER_reg)=data)
#define get_IR_PER_reg   (*((volatile unsigned int*) IR_PER_reg))
#define IR_PER_inst_adr                                                              "0x0001"
#define IR_PER_inst                                                                  0x0001
#define IR_PER_IRRDL_shift                                                           (16)
#define IR_PER_IRRDL_mask                                                            (0x003F0000)
#define IR_PER_IRRDL(data)                                                           (0x003F0000&((data)<<16))
#define IR_PER_IRRDL_src(data)                                                       ((0x003F0000&(data))>>16)
#define IR_PER_get_IRRDL(data)                                                       ((0x003F0000&(data))>>16)
#define IR_PER_IRRRL_shift                                                           (8)
#define IR_PER_IRRRL_mask                                                            (0x0000FF00)
#define IR_PER_IRRRL(data)                                                           (0x0000FF00&((data)<<8))
#define IR_PER_IRRRL_src(data)                                                       ((0x0000FF00&(data))>>8)
#define IR_PER_get_IRRRL(data)                                                       ((0x0000FF00&(data))>>8)
#define IR_PER_IRRSL_shift                                                           (0)
#define IR_PER_IRRSL_mask                                                            (0x000000FF)
#define IR_PER_IRRSL(data)                                                           (0x000000FF&((data)<<0))
#define IR_PER_IRRSL_src(data)                                                       ((0x000000FF&(data))>>0)
#define IR_PER_get_IRRSL(data)                                                       ((0x000000FF&(data))>>0)


#define IR_SF                                                                        0x18007408
#define IR_SF_reg_addr                                                               "0x18007408"
#define IR_SF_reg                                                                    0x18007408
#define set_IR_SF_reg(data)   (*((volatile unsigned int*) IR_SF_reg)=data)
#define get_IR_SF_reg   (*((volatile unsigned int*) IR_SF_reg))
#define IR_SF_inst_adr                                                               "0x0002"
#define IR_SF_inst                                                                   0x0002
#define IR_SF_IRFD_shift                                                             (0)
#define IR_SF_IRFD_mask                                                              (0x0000FFFF)
#define IR_SF_IRFD(data)                                                             (0x0000FFFF&((data)<<0))
#define IR_SF_IRFD_src(data)                                                         ((0x0000FFFF&(data))>>0)
#define IR_SF_get_IRFD(data)                                                         ((0x0000FFFF&(data))>>0)


#define IR_DPIR                                                                      0x1800740C
#define IR_DPIR_reg_addr                                                             "0x1800740C"
#define IR_DPIR_reg                                                                  0x1800740C
#define set_IR_DPIR_reg(data)   (*((volatile unsigned int*) IR_DPIR_reg)=data)
#define get_IR_DPIR_reg   (*((volatile unsigned int*) IR_DPIR_reg))
#define IR_DPIR_inst_adr                                                             "0x0003"
#define IR_DPIR_inst                                                                 0x0003
#define IR_DPIR_IRIOTCDP_shift                                                       (0)
#define IR_DPIR_IRIOTCDP_mask                                                        (0x0000FFFF)
#define IR_DPIR_IRIOTCDP(data)                                                       (0x0000FFFF&((data)<<0))
#define IR_DPIR_IRIOTCDP_src(data)                                                   ((0x0000FFFF&(data))>>0)
#define IR_DPIR_get_IRIOTCDP(data)                                                   ((0x0000FFFF&(data))>>0)


#define IR_CR                                                                        0x18007410
#define IR_CR_reg_addr                                                               "0x18007410"
#define IR_CR_reg                                                                    0x18007410
#define set_IR_CR_reg(data)   (*((volatile unsigned int*) IR_CR_reg)=data)
#define get_IR_CR_reg   (*((volatile unsigned int*) IR_CR_reg))
#define IR_CR_inst_adr                                                               "0x0004"
#define IR_CR_inst                                                                   0x0004
#define IR_CR_IRSR_shift                                                             (31)
#define IR_CR_IRSR_mask                                                              (0x80000000)
#define IR_CR_IRSR(data)                                                             (0x80000000&((data)<<31))
#define IR_CR_IRSR_src(data)                                                         ((0x80000000&(data))>>31)
#define IR_CR_get_IRSR(data)                                                         ((0x80000000&(data))>>31)
#define IR_CR_rcmm_en_shift                                                          (25)
#define IR_CR_rcmm_en_mask                                                           (0x02000000)
#define IR_CR_rcmm_en(data)                                                          (0x02000000&((data)<<25))
#define IR_CR_rcmm_en_src(data)                                                      ((0x02000000&(data))>>25)
#define IR_CR_get_rcmm_en(data)                                                      ((0x02000000&(data))>>25)
#define IR_CR_toshiba_en_shift                                                       (24)
#define IR_CR_toshiba_en_mask                                                        (0x01000000)
#define IR_CR_toshiba_en(data)                                                       (0x01000000&((data)<<24))
#define IR_CR_toshiba_en_src(data)                                                   ((0x01000000&(data))>>24)
#define IR_CR_get_toshiba_en(data)                                                   ((0x01000000&(data))>>24)
#define IR_CR_IREDNM_shift                                                           (23)
#define IR_CR_IREDNM_mask                                                            (0x00800000)
#define IR_CR_IREDNM(data)                                                           (0x00800000&((data)<<23))
#define IR_CR_IREDNM_src(data)                                                       ((0x00800000&(data))>>23)
#define IR_CR_get_IREDNM(data)                                                       ((0x00800000&(data))>>23)
#define IR_CR_IREDN_shift                                                            (16)
#define IR_CR_IREDN_mask                                                             (0x003F0000)
#define IR_CR_IREDN(data)                                                            (0x003F0000&((data)<<16))
#define IR_CR_IREDN_src(data)                                                        ((0x003F0000&(data))>>16)
#define IR_CR_get_IREDN(data)                                                        ((0x003F0000&(data))>>16)
#define IR_CR_raw_fifo_ov_shift                                                      (14)
#define IR_CR_raw_fifo_ov_mask                                                       (0x00004000)
#define IR_CR_raw_fifo_ov(data)                                                      (0x00004000&((data)<<14))
#define IR_CR_raw_fifo_ov_src(data)                                                  ((0x00004000&(data))>>14)
#define IR_CR_get_raw_fifo_ov(data)                                                  ((0x00004000&(data))>>14)
#define IR_CR_raw_fifo_val_shift                                                     (13)
#define IR_CR_raw_fifo_val_mask                                                      (0x00002000)
#define IR_CR_raw_fifo_val(data)                                                     (0x00002000&((data)<<13))
#define IR_CR_raw_fifo_val_src(data)                                                 ((0x00002000&(data))>>13)
#define IR_CR_get_raw_fifo_val(data)                                                 ((0x00002000&(data))>>13)
#define IR_CR_RAW_EN_shift                                                           (12)
#define IR_CR_RAW_EN_mask                                                            (0x00001000)
#define IR_CR_RAW_EN(data)                                                           (0x00001000&((data)<<12))
#define IR_CR_RAW_EN_src(data)                                                       ((0x00001000&(data))>>12)
#define IR_CR_get_RAW_EN(data)                                                       ((0x00001000&(data))>>12)
#define IR_CR_MLAE_shift                                                             (11)
#define IR_CR_MLAE_mask                                                              (0x00000800)
#define IR_CR_MLAE(data)                                                             (0x00000800&((data)<<11))
#define IR_CR_MLAE_src(data)                                                         ((0x00000800&(data))>>11)
#define IR_CR_get_MLAE(data)                                                         ((0x00000800&(data))>>11)
#define IR_CR_IRIE_shift                                                             (10)
#define IR_CR_IRIE_mask                                                              (0x00000400)
#define IR_CR_IRIE(data)                                                             (0x00000400&((data)<<10))
#define IR_CR_IRIE_src(data)                                                         ((0x00000400&(data))>>10)
#define IR_CR_get_IRIE(data)                                                         ((0x00000400&(data))>>10)
#define IR_CR_IRRES_shift                                                            (9)
#define IR_CR_IRRES_mask                                                             (0x00000200)
#define IR_CR_IRRES(data)                                                            (0x00000200&((data)<<9))
#define IR_CR_IRRES_src(data)                                                        ((0x00000200&(data))>>9)
#define IR_CR_get_IRRES(data)                                                        ((0x00000200&(data))>>9)
#define IR_CR_IRUE_shift                                                             (8)
#define IR_CR_IRUE_mask                                                              (0x00000100)
#define IR_CR_IRUE(data)                                                             (0x00000100&((data)<<8))
#define IR_CR_IRUE_src(data)                                                         ((0x00000100&(data))>>8)
#define IR_CR_get_IRUE(data)                                                         ((0x00000100&(data))>>8)
#define IR_CR_IRCM_shift                                                             (7)
#define IR_CR_IRCM_mask                                                              (0x00000080)
#define IR_CR_IRCM(data)                                                             (0x00000080&((data)<<7))
#define IR_CR_IRCM_src(data)                                                         ((0x00000080&(data))>>7)
#define IR_CR_get_IRCM(data)                                                         ((0x00000080&(data))>>7)
#define IR_CR_IRBME_shift                                                            (6)
#define IR_CR_IRBME_mask                                                             (0x00000040)
#define IR_CR_IRBME(data)                                                            (0x00000040&((data)<<6))
#define IR_CR_IRBME_src(data)                                                        ((0x00000040&(data))>>6)
#define IR_CR_get_IRBME(data)                                                        ((0x00000040&(data))>>6)
#define IR_CR_IRDPM_shift                                                            (5)
#define IR_CR_IRDPM_mask                                                             (0x00000020)
#define IR_CR_IRDPM(data)                                                            (0x00000020&((data)<<5))
#define IR_CR_IRDPM_src(data)                                                        ((0x00000020&(data))>>5)
#define IR_CR_get_IRDPM(data)                                                        ((0x00000020&(data))>>5)
#define IR_CR_IRDN_shift                                                             (0)
#define IR_CR_IRDN_mask                                                              (0x0000001F)
#define IR_CR_IRDN(data)                                                             (0x0000001F&((data)<<0))
#define IR_CR_IRDN_src(data)                                                         ((0x0000001F&(data))>>0)
#define IR_CR_get_IRDN(data)                                                         ((0x0000001F&(data))>>0)


#define IR_RP                                                                        0x18007414
#define IR_RP_reg_addr                                                               "0x18007414"
#define IR_RP_reg                                                                    0x18007414
#define set_IR_RP_reg(data)   (*((volatile unsigned int*) IR_RP_reg)=data)
#define get_IR_RP_reg   (*((volatile unsigned int*) IR_RP_reg))
#define IR_RP_inst_adr                                                               "0x0005"
#define IR_RP_inst                                                                   0x0005
#define IR_RP_IRRP_shift                                                             (0)
#define IR_RP_IRRP_mask                                                              (0xFFFFFFFF)
#define IR_RP_IRRP(data)                                                             (0xFFFFFFFF&((data)<<0))
#define IR_RP_IRRP_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define IR_RP_get_IRRP(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define IR_SR                                                                        0x18007418
#define IR_SR_reg_addr                                                               "0x18007418"
#define IR_SR_reg                                                                    0x18007418
#define set_IR_SR_reg(data)   (*((volatile unsigned int*) IR_SR_reg)=data)
#define get_IR_SR_reg   (*((volatile unsigned int*) IR_SR_reg))
#define IR_SR_inst_adr                                                               "0x0006"
#define IR_SR_inst                                                                   0x0006
#define IR_SR_slen_big_shift                                                         (5)
#define IR_SR_slen_big_mask                                                          (0x00000020)
#define IR_SR_slen_big(data)                                                         (0x00000020&((data)<<5))
#define IR_SR_slen_big_src(data)                                                     ((0x00000020&(data))>>5)
#define IR_SR_get_slen_big(data)                                                     ((0x00000020&(data))>>5)
#define IR_SR_blen_big_shift                                                         (4)
#define IR_SR_blen_big_mask                                                          (0x00000010)
#define IR_SR_blen_big(data)                                                         (0x00000010&((data)<<4))
#define IR_SR_blen_big_src(data)                                                     ((0x00000010&(data))>>4)
#define IR_SR_get_blen_big(data)                                                     ((0x00000010&(data))>>4)
#define IR_SR_raw_fifo_ov_shift                                                      (3)
#define IR_SR_raw_fifo_ov_mask                                                       (0x00000008)
#define IR_SR_raw_fifo_ov(data)                                                      (0x00000008&((data)<<3))
#define IR_SR_raw_fifo_ov_src(data)                                                  ((0x00000008&(data))>>3)
#define IR_SR_get_raw_fifo_ov(data)                                                  ((0x00000008&(data))>>3)
#define IR_SR_raw_fifo_val_shift                                                     (2)
#define IR_SR_raw_fifo_val_mask                                                      (0x00000004)
#define IR_SR_raw_fifo_val(data)                                                     (0x00000004&((data)<<2))
#define IR_SR_raw_fifo_val_src(data)                                                 ((0x00000004&(data))>>2)
#define IR_SR_get_raw_fifo_val(data)                                                 ((0x00000004&(data))>>2)
#define IR_SR_IRRF_shift                                                             (1)
#define IR_SR_IRRF_mask                                                              (0x00000002)
#define IR_SR_IRRF(data)                                                             (0x00000002&((data)<<1))
#define IR_SR_IRRF_src(data)                                                         ((0x00000002&(data))>>1)
#define IR_SR_get_IRRF(data)                                                         ((0x00000002&(data))>>1)
#define IR_SR_IRDVF_shift                                                            (0)
#define IR_SR_IRDVF_mask                                                             (0x00000001)
#define IR_SR_IRDVF(data)                                                            (0x00000001&((data)<<0))
#define IR_SR_IRDVF_src(data)                                                        ((0x00000001&(data))>>0)
#define IR_SR_get_IRDVF(data)                                                        ((0x00000001&(data))>>0)


#define IR_RAW_CTRL                                                                  0x1800741C
#define IR_RAW_CTRL_reg_addr                                                         "0x1800741C"
#define IR_RAW_CTRL_reg                                                              0x1800741C
#define set_IR_RAW_CTRL_reg(data)   (*((volatile unsigned int*) IR_RAW_CTRL_reg)=data)
#define get_IR_RAW_CTRL_reg   (*((volatile unsigned int*) IR_RAW_CTRL_reg))
#define IR_RAW_CTRL_inst_adr                                                         "0x0007"
#define IR_RAW_CTRL_inst                                                             0x0007
#define IR_RAW_CTRL_write_en2_shift                                                  (25)
#define IR_RAW_CTRL_write_en2_mask                                                   (0x02000000)
#define IR_RAW_CTRL_write_en2(data)                                                  (0x02000000&((data)<<25))
#define IR_RAW_CTRL_write_en2_src(data)                                              ((0x02000000&(data))>>25)
#define IR_RAW_CTRL_get_write_en2(data)                                              ((0x02000000&(data))>>25)
#define IR_RAW_CTRL_stop_sample_shift                                                (24)
#define IR_RAW_CTRL_stop_sample_mask                                                 (0x01000000)
#define IR_RAW_CTRL_stop_sample(data)                                                (0x01000000&((data)<<24))
#define IR_RAW_CTRL_stop_sample_src(data)                                            ((0x01000000&(data))>>24)
#define IR_RAW_CTRL_get_stop_sample(data)                                            ((0x01000000&(data))>>24)
#define IR_RAW_CTRL_stop_time_shift                                                  (8)
#define IR_RAW_CTRL_stop_time_mask                                                   (0x00FFFF00)
#define IR_RAW_CTRL_stop_time(data)                                                  (0x00FFFF00&((data)<<8))
#define IR_RAW_CTRL_stop_time_src(data)                                              ((0x00FFFF00&(data))>>8)
#define IR_RAW_CTRL_get_stop_time(data)                                              ((0x00FFFF00&(data))>>8)
#define IR_RAW_CTRL_write_en1_shift                                                  (6)
#define IR_RAW_CTRL_write_en1_mask                                                   (0x00000040)
#define IR_RAW_CTRL_write_en1(data)                                                  (0x00000040&((data)<<6))
#define IR_RAW_CTRL_write_en1_src(data)                                              ((0x00000040&(data))>>6)
#define IR_RAW_CTRL_get_write_en1(data)                                              ((0x00000040&(data))>>6)
#define IR_RAW_CTRL_fifo_thr_shift                                                   (0)
#define IR_RAW_CTRL_fifo_thr_mask                                                    (0x0000003F)
#define IR_RAW_CTRL_fifo_thr(data)                                                   (0x0000003F&((data)<<0))
#define IR_RAW_CTRL_fifo_thr_src(data)                                               ((0x0000003F&(data))>>0)
#define IR_RAW_CTRL_get_fifo_thr(data)                                               ((0x0000003F&(data))>>0)


#define IR_RAW_FF                                                                    0x18007420
#define IR_RAW_FF_reg_addr                                                           "0x18007420"
#define IR_RAW_FF_reg                                                                0x18007420
#define set_IR_RAW_FF_reg(data)   (*((volatile unsigned int*) IR_RAW_FF_reg)=data)
#define get_IR_RAW_FF_reg   (*((volatile unsigned int*) IR_RAW_FF_reg))
#define IR_RAW_FF_inst_adr                                                           "0x0008"
#define IR_RAW_FF_inst                                                               0x0008
#define IR_RAW_FF_DAT_shift                                                          (0)
#define IR_RAW_FF_DAT_mask                                                           (0xFFFFFFFF)
#define IR_RAW_FF_DAT(data)                                                          (0xFFFFFFFF&((data)<<0))
#define IR_RAW_FF_DAT_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define IR_RAW_FF_get_DAT(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define IR_RAW_SAMPLE_TIME                                                           0x18007424
#define IR_RAW_SAMPLE_TIME_reg_addr                                                  "0x18007424"
#define IR_RAW_SAMPLE_TIME_reg                                                       0x18007424
#define set_IR_RAW_SAMPLE_TIME_reg(data)   (*((volatile unsigned int*) IR_RAW_SAMPLE_TIME_reg)=data)
#define get_IR_RAW_SAMPLE_TIME_reg   (*((volatile unsigned int*) IR_RAW_SAMPLE_TIME_reg))
#define IR_RAW_SAMPLE_TIME_inst_adr                                                  "0x0009"
#define IR_RAW_SAMPLE_TIME_inst                                                      0x0009
#define IR_RAW_SAMPLE_TIME_CNT_shift                                                 (0)
#define IR_RAW_SAMPLE_TIME_CNT_mask                                                  (0x0000FFFF)
#define IR_RAW_SAMPLE_TIME_CNT(data)                                                 (0x0000FFFF&((data)<<0))
#define IR_RAW_SAMPLE_TIME_CNT_src(data)                                             ((0x0000FFFF&(data))>>0)
#define IR_RAW_SAMPLE_TIME_get_CNT(data)                                             ((0x0000FFFF&(data))>>0)


#define IR_RAW_WL                                                                    0x18007428
#define IR_RAW_WL_reg_addr                                                           "0x18007428"
#define IR_RAW_WL_reg                                                                0x18007428
#define set_IR_RAW_WL_reg(data)   (*((volatile unsigned int*) IR_RAW_WL_reg)=data)
#define get_IR_RAW_WL_reg   (*((volatile unsigned int*) IR_RAW_WL_reg))
#define IR_RAW_WL_inst_adr                                                           "0x000A"
#define IR_RAW_WL_inst                                                               0x000A
#define IR_RAW_WL_VAL_shift                                                          (0)
#define IR_RAW_WL_VAL_mask                                                           (0x0000003F)
#define IR_RAW_WL_VAL(data)                                                          (0x0000003F&((data)<<0))
#define IR_RAW_WL_VAL_src(data)                                                      ((0x0000003F&(data))>>0)
#define IR_RAW_WL_get_VAL(data)                                                      ((0x0000003F&(data))>>0)


#define IR_RAW_DEB                                                                   0x1800742C
#define IR_RAW_DEB_reg_addr                                                          "0x1800742C"
#define IR_RAW_DEB_reg                                                               0x1800742C
#define set_IR_RAW_DEB_reg(data)   (*((volatile unsigned int*) IR_RAW_DEB_reg)=data)
#define get_IR_RAW_DEB_reg   (*((volatile unsigned int*) IR_RAW_DEB_reg))
#define IR_RAW_DEB_inst_adr                                                          "0x000B"
#define IR_RAW_DEB_inst                                                              0x000B
#define IR_RAW_DEB_LEN_shift                                                         (16)
#define IR_RAW_DEB_LEN_mask                                                          (0x00FF0000)
#define IR_RAW_DEB_LEN(data)                                                         (0x00FF0000&((data)<<16))
#define IR_RAW_DEB_LEN_src(data)                                                     ((0x00FF0000&(data))>>16)
#define IR_RAW_DEB_get_LEN(data)                                                     ((0x00FF0000&(data))>>16)
#define IR_RAW_DEB_CLK_shift                                                         (0)
#define IR_RAW_DEB_CLK_mask                                                          (0x0000FFFF)
#define IR_RAW_DEB_CLK(data)                                                         (0x0000FFFF&((data)<<0))
#define IR_RAW_DEB_CLK_src(data)                                                     ((0x0000FFFF&(data))>>0)
#define IR_RAW_DEB_get_CLK(data)                                                     ((0x0000FFFF&(data))>>0)


#define IR_PSR_UP                                                                    0x18007430
#define IR_PSR_UP_reg_addr                                                           "0x18007430"
#define IR_PSR_UP_reg                                                                0x18007430
#define set_IR_PSR_UP_reg(data)   (*((volatile unsigned int*) IR_PSR_UP_reg)=data)
#define get_IR_PSR_UP_reg   (*((volatile unsigned int*) IR_PSR_UP_reg))
#define IR_PSR_UP_inst_adr                                                           "0x000C"
#define IR_PSR_UP_inst                                                               0x000C
#define IR_PSR_UP_IRRBL_shift                                                        (24)
#define IR_PSR_UP_IRRBL_mask                                                         (0xFF000000)
#define IR_PSR_UP_IRRBL(data)                                                        (0xFF000000&((data)<<24))
#define IR_PSR_UP_IRRBL_src(data)                                                    ((0xFF000000&(data))>>24)
#define IR_PSR_UP_get_IRRBL(data)                                                    ((0xFF000000&(data))>>24)
#define IR_PSR_UP_IRRML_shift                                                        (16)
#define IR_PSR_UP_IRRML_mask                                                         (0x00FF0000)
#define IR_PSR_UP_IRRML(data)                                                        (0x00FF0000&((data)<<16))
#define IR_PSR_UP_IRRML_src(data)                                                    ((0x00FF0000&(data))>>16)
#define IR_PSR_UP_get_IRRML(data)                                                    ((0x00FF0000&(data))>>16)
#define IR_PSR_UP_IRRDZL_shift                                                       (8)
#define IR_PSR_UP_IRRDZL_mask                                                        (0x0000FF00)
#define IR_PSR_UP_IRRDZL(data)                                                       (0x0000FF00&((data)<<8))
#define IR_PSR_UP_IRRDZL_src(data)                                                   ((0x0000FF00&(data))>>8)
#define IR_PSR_UP_get_IRRDZL(data)                                                   ((0x0000FF00&(data))>>8)
#define IR_PSR_UP_IRRDOL_shift                                                       (0)
#define IR_PSR_UP_IRRDOL_mask                                                        (0x000000FF)
#define IR_PSR_UP_IRRDOL(data)                                                       (0x000000FF&((data)<<0))
#define IR_PSR_UP_IRRDOL_src(data)                                                   ((0x000000FF&(data))>>0)
#define IR_PSR_UP_get_IRRDOL(data)                                                   ((0x000000FF&(data))>>0)


#define IR_PER_UP                                                                    0x18007434
#define IR_PER_UP_reg_addr                                                           "0x18007434"
#define IR_PER_UP_reg                                                                0x18007434
#define set_IR_PER_UP_reg(data)   (*((volatile unsigned int*) IR_PER_UP_reg)=data)
#define get_IR_PER_UP_reg   (*((volatile unsigned int*) IR_PER_UP_reg))
#define IR_PER_UP_inst_adr                                                           "0x000D"
#define IR_PER_UP_inst                                                               0x000D
#define IR_PER_UP_IRRRL_shift                                                        (8)
#define IR_PER_UP_IRRRL_mask                                                         (0x0000FF00)
#define IR_PER_UP_IRRRL(data)                                                        (0x0000FF00&((data)<<8))
#define IR_PER_UP_IRRRL_src(data)                                                    ((0x0000FF00&(data))>>8)
#define IR_PER_UP_get_IRRRL(data)                                                    ((0x0000FF00&(data))>>8)
#define IR_PER_UP_IRRSL_shift                                                        (0)
#define IR_PER_UP_IRRSL_mask                                                         (0x000000FF)
#define IR_PER_UP_IRRSL(data)                                                        (0x000000FF&((data)<<0))
#define IR_PER_UP_IRRSL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IR_PER_UP_get_IRRSL(data)                                                    ((0x000000FF&(data))>>0)


#define IR_CTRL_RC6                                                                  0x18007438
#define IR_CTRL_RC6_reg_addr                                                         "0x18007438"
#define IR_CTRL_RC6_reg                                                              0x18007438
#define set_IR_CTRL_RC6_reg(data)   (*((volatile unsigned int*) IR_CTRL_RC6_reg)=data)
#define get_IR_CTRL_RC6_reg   (*((volatile unsigned int*) IR_CTRL_RC6_reg))
#define IR_CTRL_RC6_inst_adr                                                         "0x000E"
#define IR_CTRL_RC6_inst                                                             0x000E
#define IR_CTRL_RC6_RC6_EN_shift                                                     (8)
#define IR_CTRL_RC6_RC6_EN_mask                                                      (0x00000100)
#define IR_CTRL_RC6_RC6_EN(data)                                                     (0x00000100&((data)<<8))
#define IR_CTRL_RC6_RC6_EN_src(data)                                                 ((0x00000100&(data))>>8)
#define IR_CTRL_RC6_get_RC6_EN(data)                                                 ((0x00000100&(data))>>8)
#define IR_CTRL_RC6_IRTR_shift                                                       (0)
#define IR_CTRL_RC6_IRTR_mask                                                        (0x000000FF)
#define IR_CTRL_RC6_IRTR(data)                                                       (0x000000FF&((data)<<0))
#define IR_CTRL_RC6_IRTR_src(data)                                                   ((0x000000FF&(data))>>0)
#define IR_CTRL_RC6_get_IRTR(data)                                                   ((0x000000FF&(data))>>0)


#define IR_RP2                                                                       0x1800743C
#define IR_RP2_reg_addr                                                              "0x1800743C"
#define IR_RP2_reg                                                                   0x1800743C
#define set_IR_RP2_reg(data)   (*((volatile unsigned int*) IR_RP2_reg)=data)
#define get_IR_RP2_reg   (*((volatile unsigned int*) IR_RP2_reg))
#define IR_RP2_inst_adr                                                              "0x000F"
#define IR_RP2_inst                                                                  0x000F
#define IR_RP2_IRRP_shift                                                            (0)
#define IR_RP2_IRRP_mask                                                             (0xFFFFFFFF)
#define IR_RP2_IRRP(data)                                                            (0xFFFFFFFF&((data)<<0))
#define IR_RP2_IRRP_src(data)                                                        ((0xFFFFFFFF&(data))>>0)
#define IR_RP2_get_IRRP(data)                                                        ((0xFFFFFFFF&(data))>>0)


#define IRTX_CFG                                                                     0x18007440
#define IRTX_CFG_reg_addr                                                            "0x18007440"
#define IRTX_CFG_reg                                                                 0x18007440
#define set_IRTX_CFG_reg(data)   (*((volatile unsigned int*) IRTX_CFG_reg)=data)
#define get_IRTX_CFG_reg   (*((volatile unsigned int*) IRTX_CFG_reg))
#define IRTX_CFG_inst_adr                                                            "0x0010"
#define IRTX_CFG_inst                                                                0x0010
#define IRTX_CFG_IRTX_EN_shift                                                       (31)
#define IRTX_CFG_IRTX_EN_mask                                                        (0x80000000)
#define IRTX_CFG_IRTX_EN(data)                                                       (0x80000000&((data)<<31))
#define IRTX_CFG_IRTX_EN_src(data)                                                   ((0x80000000&(data))>>31)
#define IRTX_CFG_get_IRTX_EN(data)                                                   ((0x80000000&(data))>>31)
#define IRTX_CFG_IACT_LVL_shift                                                      (10)
#define IRTX_CFG_IACT_LVL_mask                                                       (0x00000400)
#define IRTX_CFG_IACT_LVL(data)                                                      (0x00000400&((data)<<10))
#define IRTX_CFG_IACT_LVL_src(data)                                                  ((0x00000400&(data))>>10)
#define IRTX_CFG_get_IACT_LVL(data)                                                  ((0x00000400&(data))>>10)
#define IRTX_CFG_MODULATION_shift                                                    (9)
#define IRTX_CFG_MODULATION_mask                                                     (0x00000200)
#define IRTX_CFG_MODULATION(data)                                                    (0x00000200&((data)<<9))
#define IRTX_CFG_MODULATION_src(data)                                                ((0x00000200&(data))>>9)
#define IRTX_CFG_get_MODULATION(data)                                                ((0x00000200&(data))>>9)
#define IRTX_CFG_ENDIAN_shift                                                        (8)
#define IRTX_CFG_ENDIAN_mask                                                         (0x00000100)
#define IRTX_CFG_ENDIAN(data)                                                        (0x00000100&((data)<<8))
#define IRTX_CFG_ENDIAN_src(data)                                                    ((0x00000100&(data))>>8)
#define IRTX_CFG_get_ENDIAN(data)                                                    ((0x00000100&(data))>>8)
#define IRTX_CFG_Dummy_shift                                                         (6)
#define IRTX_CFG_Dummy_mask                                                          (0x000000C0)
#define IRTX_CFG_Dummy(data)                                                         (0x000000C0&((data)<<6))
#define IRTX_CFG_Dummy_src(data)                                                     ((0x000000C0&(data))>>6)
#define IRTX_CFG_get_Dummy(data)                                                     ((0x000000C0&(data))>>6)
#define IRTX_CFG_FIFOOUT_INV_shift                                                   (5)
#define IRTX_CFG_FIFOOUT_INV_mask                                                    (0x00000020)
#define IRTX_CFG_FIFOOUT_INV(data)                                                   (0x00000020&((data)<<5))
#define IRTX_CFG_FIFOOUT_INV_src(data)                                               ((0x00000020&(data))>>5)
#define IRTX_CFG_get_FIFOOUT_INV(data)                                               ((0x00000020&(data))>>5)
#define IRTX_CFG_IRTXOUT_INV_shift                                                   (4)
#define IRTX_CFG_IRTXOUT_INV_mask                                                    (0x00000010)
#define IRTX_CFG_IRTXOUT_INV(data)                                                   (0x00000010&((data)<<4))
#define IRTX_CFG_IRTXOUT_INV_src(data)                                               ((0x00000010&(data))>>4)
#define IRTX_CFG_get_IRTXOUT_INV(data)                                               ((0x00000010&(data))>>4)
#define IRTX_CFG_START_shift                                                         (0)
#define IRTX_CFG_START_mask                                                          (0x00000001)
#define IRTX_CFG_START(data)                                                         (0x00000001&((data)<<0))
#define IRTX_CFG_START_src(data)                                                     ((0x00000001&(data))>>0)
#define IRTX_CFG_get_START(data)                                                     ((0x00000001&(data))>>0)


#define IRTX_TIM                                                                     0x18007444
#define IRTX_TIM_reg_addr                                                            "0x18007444"
#define IRTX_TIM_reg                                                                 0x18007444
#define set_IRTX_TIM_reg(data)   (*((volatile unsigned int*) IRTX_TIM_reg)=data)
#define get_IRTX_TIM_reg   (*((volatile unsigned int*) IRTX_TIM_reg))
#define IRTX_TIM_inst_adr                                                            "0x0011"
#define IRTX_TIM_inst                                                                0x0011
#define IRTX_TIM_IRTX_FD_shift                                                       (0)
#define IRTX_TIM_IRTX_FD_mask                                                        (0x0000FFFF)
#define IRTX_TIM_IRTX_FD(data)                                                       (0x0000FFFF&((data)<<0))
#define IRTX_TIM_IRTX_FD_src(data)                                                   ((0x0000FFFF&(data))>>0)
#define IRTX_TIM_get_IRTX_FD(data)                                                   ((0x0000FFFF&(data))>>0)


#define IRTX_PWM_SETTING                                                             0x18007448
#define IRTX_PWM_SETTING_reg_addr                                                    "0x18007448"
#define IRTX_PWM_SETTING_reg                                                         0x18007448
#define set_IRTX_PWM_SETTING_reg(data)   (*((volatile unsigned int*) IRTX_PWM_SETTING_reg)=data)
#define get_IRTX_PWM_SETTING_reg   (*((volatile unsigned int*) IRTX_PWM_SETTING_reg))
#define IRTX_PWM_SETTING_inst_adr                                                    "0x0012"
#define IRTX_PWM_SETTING_inst                                                        0x0012
#define IRTX_PWM_SETTING_PWM_CLKSRC_DIV_shift                                        (16)
#define IRTX_PWM_SETTING_PWM_CLKSRC_DIV_mask                                         (0x000F0000)
#define IRTX_PWM_SETTING_PWM_CLKSRC_DIV(data)                                        (0x000F0000&((data)<<16))
#define IRTX_PWM_SETTING_PWM_CLKSRC_DIV_src(data)                                    ((0x000F0000&(data))>>16)
#define IRTX_PWM_SETTING_get_PWM_CLKSRC_DIV(data)                                    ((0x000F0000&(data))>>16)
#define IRTX_PWM_SETTING_PWM_CLK_DUTY_shift                                          (8)
#define IRTX_PWM_SETTING_PWM_CLK_DUTY_mask                                           (0x0000FF00)
#define IRTX_PWM_SETTING_PWM_CLK_DUTY(data)                                          (0x0000FF00&((data)<<8))
#define IRTX_PWM_SETTING_PWM_CLK_DUTY_src(data)                                      ((0x0000FF00&(data))>>8)
#define IRTX_PWM_SETTING_get_PWM_CLK_DUTY(data)                                      ((0x0000FF00&(data))>>8)
#define IRTX_PWM_SETTING_PWM_CLK_DIV_shift                                           (0)
#define IRTX_PWM_SETTING_PWM_CLK_DIV_mask                                            (0x000000FF)
#define IRTX_PWM_SETTING_PWM_CLK_DIV(data)                                           (0x000000FF&((data)<<0))
#define IRTX_PWM_SETTING_PWM_CLK_DIV_src(data)                                       ((0x000000FF&(data))>>0)
#define IRTX_PWM_SETTING_get_PWM_CLK_DIV(data)                                       ((0x000000FF&(data))>>0)


#define IRTX_INT_EN                                                                  0x1800744C
#define IRTX_INT_EN_reg_addr                                                         "0x1800744C"
#define IRTX_INT_EN_reg                                                              0x1800744C
#define set_IRTX_INT_EN_reg(data)   (*((volatile unsigned int*) IRTX_INT_EN_reg)=data)
#define get_IRTX_INT_EN_reg   (*((volatile unsigned int*) IRTX_INT_EN_reg))
#define IRTX_INT_EN_inst_adr                                                         "0x0013"
#define IRTX_INT_EN_inst                                                             0x0013
#define IRTX_INT_EN_DATA_THR_shift                                                   (8)
#define IRTX_INT_EN_DATA_THR_mask                                                    (0x00003F00)
#define IRTX_INT_EN_DATA_THR(data)                                                   (0x00003F00&((data)<<8))
#define IRTX_INT_EN_DATA_THR_src(data)                                               ((0x00003F00&(data))>>8)
#define IRTX_INT_EN_get_DATA_THR(data)                                               ((0x00003F00&(data))>>8)
#define IRTX_INT_EN_EMP_EN_shift                                                     (1)
#define IRTX_INT_EN_EMP_EN_mask                                                      (0x00000002)
#define IRTX_INT_EN_EMP_EN(data)                                                     (0x00000002&((data)<<1))
#define IRTX_INT_EN_EMP_EN_src(data)                                                 ((0x00000002&(data))>>1)
#define IRTX_INT_EN_get_EMP_EN(data)                                                 ((0x00000002&(data))>>1)
#define IRTX_INT_EN_REQ_EN_shift                                                     (0)
#define IRTX_INT_EN_REQ_EN_mask                                                      (0x00000001)
#define IRTX_INT_EN_REQ_EN(data)                                                     (0x00000001&((data)<<0))
#define IRTX_INT_EN_REQ_EN_src(data)                                                 ((0x00000001&(data))>>0)
#define IRTX_INT_EN_get_REQ_EN(data)                                                 ((0x00000001&(data))>>0)


#define IRTX_INT_ST                                                                  0x18007450
#define IRTX_INT_ST_reg_addr                                                         "0x18007450"
#define IRTX_INT_ST_reg                                                              0x18007450
#define set_IRTX_INT_ST_reg(data)   (*((volatile unsigned int*) IRTX_INT_ST_reg)=data)
#define get_IRTX_INT_ST_reg   (*((volatile unsigned int*) IRTX_INT_ST_reg))
#define IRTX_INT_ST_inst_adr                                                         "0x0014"
#define IRTX_INT_ST_inst                                                             0x0014
#define IRTX_INT_ST_EMP_FLAG_shift                                                   (1)
#define IRTX_INT_ST_EMP_FLAG_mask                                                    (0x00000002)
#define IRTX_INT_ST_EMP_FLAG(data)                                                   (0x00000002&((data)<<1))
#define IRTX_INT_ST_EMP_FLAG_src(data)                                               ((0x00000002&(data))>>1)
#define IRTX_INT_ST_get_EMP_FLAG(data)                                               ((0x00000002&(data))>>1)
#define IRTX_INT_ST_REQ_FLAG_shift                                                   (0)
#define IRTX_INT_ST_REQ_FLAG_mask                                                    (0x00000001)
#define IRTX_INT_ST_REQ_FLAG(data)                                                   (0x00000001&((data)<<0))
#define IRTX_INT_ST_REQ_FLAG_src(data)                                               ((0x00000001&(data))>>0)
#define IRTX_INT_ST_get_REQ_FLAG(data)                                               ((0x00000001&(data))>>0)


#define IRTX_FIFO_ST                                                                 0x18007454
#define IRTX_FIFO_ST_reg_addr                                                        "0x18007454"
#define IRTX_FIFO_ST_reg                                                             0x18007454
#define set_IRTX_FIFO_ST_reg(data)   (*((volatile unsigned int*) IRTX_FIFO_ST_reg)=data)
#define get_IRTX_FIFO_ST_reg   (*((volatile unsigned int*) IRTX_FIFO_ST_reg))
#define IRTX_FIFO_ST_inst_adr                                                        "0x0015"
#define IRTX_FIFO_ST_inst                                                            0x0015
#define IRTX_FIFO_ST_FIFO_RST_shift                                                  (31)
#define IRTX_FIFO_ST_FIFO_RST_mask                                                   (0x80000000)
#define IRTX_FIFO_ST_FIFO_RST(data)                                                  (0x80000000&((data)<<31))
#define IRTX_FIFO_ST_FIFO_RST_src(data)                                              ((0x80000000&(data))>>31)
#define IRTX_FIFO_ST_get_FIFO_RST(data)                                              ((0x80000000&(data))>>31)
#define IRTX_FIFO_ST_VALID_LEN_shift                                                 (8)
#define IRTX_FIFO_ST_VALID_LEN_mask                                                  (0x00000F00)
#define IRTX_FIFO_ST_VALID_LEN(data)                                                 (0x00000F00&((data)<<8))
#define IRTX_FIFO_ST_VALID_LEN_src(data)                                             ((0x00000F00&(data))>>8)
#define IRTX_FIFO_ST_get_VALID_LEN(data)                                             ((0x00000F00&(data))>>8)
#define IRTX_FIFO_ST_WRP_shift                                                       (4)
#define IRTX_FIFO_ST_WRP_mask                                                        (0x000000F0)
#define IRTX_FIFO_ST_WRP(data)                                                       (0x000000F0&((data)<<4))
#define IRTX_FIFO_ST_WRP_src(data)                                                   ((0x000000F0&(data))>>4)
#define IRTX_FIFO_ST_get_WRP(data)                                                   ((0x000000F0&(data))>>4)
#define IRTX_FIFO_ST_RDP_shift                                                       (0)
#define IRTX_FIFO_ST_RDP_mask                                                        (0x0000000F)
#define IRTX_FIFO_ST_RDP(data)                                                       (0x0000000F&((data)<<0))
#define IRTX_FIFO_ST_RDP_src(data)                                                   ((0x0000000F&(data))>>0)
#define IRTX_FIFO_ST_get_RDP(data)                                                   ((0x0000000F&(data))>>0)


#define IRTX_FIFO                                                                    0x18007458
#define IRTX_FIFO_reg_addr                                                           "0x18007458"
#define IRTX_FIFO_reg                                                                0x18007458
#define set_IRTX_FIFO_reg(data)   (*((volatile unsigned int*) IRTX_FIFO_reg)=data)
#define get_IRTX_FIFO_reg   (*((volatile unsigned int*) IRTX_FIFO_reg))
#define IRTX_FIFO_inst_adr                                                           "0x0016"
#define IRTX_FIFO_inst                                                               0x0016
#define IRTX_FIFO_DATA_shift                                                         (0)
#define IRTX_FIFO_DATA_mask                                                          (0xFFFFFFFF)
#define IRTX_FIFO_DATA(data)                                                         (0xFFFFFFFF&((data)<<0))
#define IRTX_FIFO_DATA_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define IRTX_FIFO_get_DATA(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define IRRCMM_TIMING                                                                0x18007460
#define IRRCMM_TIMING_reg_addr                                                       "0x18007460"
#define IRRCMM_TIMING_reg                                                            0x18007460
#define set_IRRCMM_TIMING_reg(data)   (*((volatile unsigned int*) IRRCMM_TIMING_reg)=data)
#define get_IRRCMM_TIMING_reg   (*((volatile unsigned int*) IRRCMM_TIMING_reg))
#define IRRCMM_TIMING_inst_adr                                                       "0x0018"
#define IRRCMM_TIMING_inst                                                           0x0018
#define IRRCMM_TIMING_LEN_11_shift                                                   (24)
#define IRRCMM_TIMING_LEN_11_mask                                                    (0xFF000000)
#define IRRCMM_TIMING_LEN_11(data)                                                   (0xFF000000&((data)<<24))
#define IRRCMM_TIMING_LEN_11_src(data)                                               ((0xFF000000&(data))>>24)
#define IRRCMM_TIMING_get_LEN_11(data)                                               ((0xFF000000&(data))>>24)
#define IRRCMM_TIMING_LEN_10_shift                                                   (16)
#define IRRCMM_TIMING_LEN_10_mask                                                    (0x00FF0000)
#define IRRCMM_TIMING_LEN_10(data)                                                   (0x00FF0000&((data)<<16))
#define IRRCMM_TIMING_LEN_10_src(data)                                               ((0x00FF0000&(data))>>16)
#define IRRCMM_TIMING_get_LEN_10(data)                                               ((0x00FF0000&(data))>>16)
#define IRRCMM_TIMING_LEN_01_shift                                                   (8)
#define IRRCMM_TIMING_LEN_01_mask                                                    (0x0000FF00)
#define IRRCMM_TIMING_LEN_01(data)                                                   (0x0000FF00&((data)<<8))
#define IRRCMM_TIMING_LEN_01_src(data)                                               ((0x0000FF00&(data))>>8)
#define IRRCMM_TIMING_get_LEN_01(data)                                               ((0x0000FF00&(data))>>8)
#define IRRCMM_TIMING_LEN_00_shift                                                   (0)
#define IRRCMM_TIMING_LEN_00_mask                                                    (0x000000FF)
#define IRRCMM_TIMING_LEN_00(data)                                                   (0x000000FF&((data)<<0))
#define IRRCMM_TIMING_LEN_00_src(data)                                               ((0x000000FF&(data))>>0)
#define IRRCMM_TIMING_get_LEN_00(data)                                               ((0x000000FF&(data))>>0)


#define IR_CR1                                                                       0x18007464
#define IR_CR1_reg_addr                                                              "0x18007464"
#define IR_CR1_reg                                                                   0x18007464
#define set_IR_CR1_reg(data)   (*((volatile unsigned int*) IR_CR1_reg)=data)
#define get_IR_CR1_reg   (*((volatile unsigned int*) IR_CR1_reg))
#define IR_CR1_inst_adr                                                              "0x0019"
#define IR_CR1_inst                                                                  0x0019
#define IR_CR1_dec_by_min_max_shift                                                  (0)
#define IR_CR1_dec_by_min_max_mask                                                   (0x00000001)
#define IR_CR1_dec_by_min_max(data)                                                  (0x00000001&((data)<<0))
#define IR_CR1_dec_by_min_max_src(data)                                              ((0x00000001&(data))>>0)
#define IR_CR1_get_dec_by_min_max(data)                                              ((0x00000001&(data))>>0)


#define CEC_CR0                                                                      0x18007500
#define CEC_CR0_reg_addr                                                             "0x18007500"
#define CEC_CR0_reg                                                                  0x18007500
#define set_CEC_CR0_reg(data)   (*((volatile unsigned int*) CEC_CR0_reg)=data)
#define get_CEC_CR0_reg   (*((volatile unsigned int*) CEC_CR0_reg))
#define CEC_CR0_inst_adr                                                             "0x0040"
#define CEC_CR0_inst                                                                 0x0040
#define CEC_CR0_CEC_Mode_shift                                                       (30)
#define CEC_CR0_CEC_Mode_mask                                                        (0xC0000000)
#define CEC_CR0_CEC_Mode(data)                                                       (0xC0000000&((data)<<30))
#define CEC_CR0_CEC_Mode_src(data)                                                   ((0xC0000000&(data))>>30)
#define CEC_CR0_get_CEC_Mode(data)                                                   ((0xC0000000&(data))>>30)
#define CEC_CR0_test_mode_pad_en_shift                                               (28)
#define CEC_CR0_test_mode_pad_en_mask                                                (0x10000000)
#define CEC_CR0_test_mode_pad_en(data)                                               (0x10000000&((data)<<28))
#define CEC_CR0_test_mode_pad_en_src(data)                                           ((0x10000000&(data))>>28)
#define CEC_CR0_get_test_mode_pad_en(data)                                           ((0x10000000&(data))>>28)
#define CEC_CR0_logical_addr0_shift                                                  (24)
#define CEC_CR0_logical_addr0_mask                                                   (0x0F000000)
#define CEC_CR0_logical_addr0(data)                                                  (0x0F000000&((data)<<24))
#define CEC_CR0_logical_addr0_src(data)                                              ((0x0F000000&(data))>>24)
#define CEC_CR0_get_logical_addr0(data)                                              ((0x0F000000&(data))>>24)
#define CEC_CR0_timer_div_shift                                                      (16)
#define CEC_CR0_timer_div_mask                                                       (0x00FF0000)
#define CEC_CR0_timer_div(data)                                                      (0x00FF0000&((data)<<16))
#define CEC_CR0_timer_div_src(data)                                                  ((0x00FF0000&(data))>>16)
#define CEC_CR0_get_timer_div(data)                                                  ((0x00FF0000&(data))>>16)
#define CEC_CR0_Pre_div_shift                                                        (8)
#define CEC_CR0_Pre_div_mask                                                         (0x0000FF00)
#define CEC_CR0_Pre_div(data)                                                        (0x0000FF00&((data)<<8))
#define CEC_CR0_Pre_div_src(data)                                                    ((0x0000FF00&(data))>>8)
#define CEC_CR0_get_Pre_div(data)                                                    ((0x0000FF00&(data))>>8)
#define CEC_CR0_unreg_ack_en_shift                                                   (7)
#define CEC_CR0_unreg_ack_en_mask                                                    (0x00000080)
#define CEC_CR0_unreg_ack_en(data)                                                   (0x00000080&((data)<<7))
#define CEC_CR0_unreg_ack_en_src(data)                                               ((0x00000080&(data))>>7)
#define CEC_CR0_get_unreg_ack_en(data)                                               ((0x00000080&(data))>>7)
#define CEC_CR0_Cdc_arbitration_en_shift                                             (5)
#define CEC_CR0_Cdc_arbitration_en_mask                                              (0x00000020)
#define CEC_CR0_Cdc_arbitration_en(data)                                             (0x00000020&((data)<<5))
#define CEC_CR0_Cdc_arbitration_en_src(data)                                         ((0x00000020&(data))>>5)
#define CEC_CR0_get_Cdc_arbitration_en(data)                                         ((0x00000020&(data))>>5)
#define CEC_CR0_test_mode_pad_data_shift                                             (0)
#define CEC_CR0_test_mode_pad_data_mask                                              (0x0000001F)
#define CEC_CR0_test_mode_pad_data(data)                                             (0x0000001F&((data)<<0))
#define CEC_CR0_test_mode_pad_data_src(data)                                         ((0x0000001F&(data))>>0)
#define CEC_CR0_get_test_mode_pad_data(data)                                         ((0x0000001F&(data))>>0)


#define CEC_RTCR0                                                                    0x18007504
#define CEC_RTCR0_reg_addr                                                           "0x18007504"
#define CEC_RTCR0_reg                                                                0x18007504
#define set_CEC_RTCR0_reg(data)   (*((volatile unsigned int*) CEC_RTCR0_reg)=data)
#define get_CEC_RTCR0_reg   (*((volatile unsigned int*) CEC_RTCR0_reg))
#define CEC_RTCR0_inst_adr                                                           "0x0041"
#define CEC_RTCR0_inst                                                               0x0041
#define CEC_RTCR0_cec_pad_in_shift                                                   (31)
#define CEC_RTCR0_cec_pad_in_mask                                                    (0x80000000)
#define CEC_RTCR0_cec_pad_in(data)                                                   (0x80000000&((data)<<31))
#define CEC_RTCR0_cec_pad_in_src(data)                                               ((0x80000000&(data))>>31)
#define CEC_RTCR0_get_cec_pad_in(data)                                               ((0x80000000&(data))>>31)
#define CEC_RTCR0_dummy0_shift                                                       (28)
#define CEC_RTCR0_dummy0_mask                                                        (0x70000000)
#define CEC_RTCR0_dummy0(data)                                                       (0x70000000&((data)<<28))
#define CEC_RTCR0_dummy0_src(data)                                                   ((0x70000000&(data))>>28)
#define CEC_RTCR0_get_dummy0(data)                                                   ((0x70000000&(data))>>28)
#define CEC_RTCR0_logical_addr3_shift                                                (24)
#define CEC_RTCR0_logical_addr3_mask                                                 (0x0F000000)
#define CEC_RTCR0_logical_addr3(data)                                                (0x0F000000&((data)<<24))
#define CEC_RTCR0_logical_addr3_src(data)                                            ((0x0F000000&(data))>>24)
#define CEC_RTCR0_get_logical_addr3(data)                                            ((0x0F000000&(data))>>24)
#define CEC_RTCR0_logical_addr2_shift                                                (20)
#define CEC_RTCR0_logical_addr2_mask                                                 (0x00F00000)
#define CEC_RTCR0_logical_addr2(data)                                                (0x00F00000&((data)<<20))
#define CEC_RTCR0_logical_addr2_src(data)                                            ((0x00F00000&(data))>>20)
#define CEC_RTCR0_get_logical_addr2(data)                                            ((0x00F00000&(data))>>20)
#define CEC_RTCR0_logical_addr1_shift                                                (16)
#define CEC_RTCR0_logical_addr1_mask                                                 (0x000F0000)
#define CEC_RTCR0_logical_addr1(data)                                                (0x000F0000&((data)<<16))
#define CEC_RTCR0_logical_addr1_src(data)                                            ((0x000F0000&(data))>>16)
#define CEC_RTCR0_get_logical_addr1(data)                                            ((0x000F0000&(data))>>16)
#define CEC_RTCR0_dummy1_shift                                                       (12)
#define CEC_RTCR0_dummy1_mask                                                        (0x0000F000)
#define CEC_RTCR0_dummy1(data)                                                       (0x0000F000&((data)<<12))
#define CEC_RTCR0_dummy1_src(data)                                                   ((0x0000F000&(data))>>12)
#define CEC_RTCR0_get_dummy1(data)                                                   ((0x0000F000&(data))>>12)
#define CEC_RTCR0_clear_cec_int_shift                                                (11)
#define CEC_RTCR0_clear_cec_int_mask                                                 (0x00000800)
#define CEC_RTCR0_clear_cec_int(data)                                                (0x00000800&((data)<<11))
#define CEC_RTCR0_clear_cec_int_src(data)                                            ((0x00000800&(data))>>11)
#define CEC_RTCR0_get_clear_cec_int(data)                                            ((0x00000800&(data))>>11)
#define CEC_RTCR0_wt_cnt_shift                                                       (5)
#define CEC_RTCR0_wt_cnt_mask                                                        (0x000007E0)
#define CEC_RTCR0_wt_cnt(data)                                                       (0x000007E0&((data)<<5))
#define CEC_RTCR0_wt_cnt_src(data)                                                   ((0x000007E0&(data))>>5)
#define CEC_RTCR0_get_wt_cnt(data)                                                   ((0x000007E0&(data))>>5)
#define CEC_RTCR0_lattest_shift                                                      (4)
#define CEC_RTCR0_lattest_mask                                                       (0x00000010)
#define CEC_RTCR0_lattest(data)                                                      (0x00000010&((data)<<4))
#define CEC_RTCR0_lattest_src(data)                                                  ((0x00000010&(data))>>4)
#define CEC_RTCR0_get_lattest(data)                                                  ((0x00000010&(data))>>4)
#define CEC_RTCR0_retry_no_shift                                                     (0)
#define CEC_RTCR0_retry_no_mask                                                      (0x0000000F)
#define CEC_RTCR0_retry_no(data)                                                     (0x0000000F&((data)<<0))
#define CEC_RTCR0_retry_no_src(data)                                                 ((0x0000000F&(data))>>0)
#define CEC_RTCR0_get_retry_no(data)                                                 ((0x0000000F&(data))>>0)


#define CEC_RXCR0                                                                    0x18007508
#define CEC_RXCR0_reg_addr                                                           "0x18007508"
#define CEC_RXCR0_reg                                                                0x18007508
#define set_CEC_RXCR0_reg(data)   (*((volatile unsigned int*) CEC_RXCR0_reg)=data)
#define get_CEC_RXCR0_reg   (*((volatile unsigned int*) CEC_RXCR0_reg))
#define CEC_RXCR0_inst_adr                                                           "0x0042"
#define CEC_RXCR0_inst                                                               0x0042
#define CEC_RXCR0_Broadcast_addr_shift                                               (31)
#define CEC_RXCR0_Broadcast_addr_mask                                                (0x80000000)
#define CEC_RXCR0_Broadcast_addr(data)                                               (0x80000000&((data)<<31))
#define CEC_RXCR0_Broadcast_addr_src(data)                                           ((0x80000000&(data))>>31)
#define CEC_RXCR0_get_Broadcast_addr(data)                                           ((0x80000000&(data))>>31)
#define CEC_RXCR0_dest_addr_shift                                                    (16)
#define CEC_RXCR0_dest_addr_mask                                                     (0x000F0000)
#define CEC_RXCR0_dest_addr(data)                                                    (0x000F0000&((data)<<16))
#define CEC_RXCR0_dest_addr_src(data)                                                ((0x000F0000&(data))>>16)
#define CEC_RXCR0_get_dest_addr(data)                                                ((0x000F0000&(data))>>16)
#define CEC_RXCR0_rx_en_shift                                                        (15)
#define CEC_RXCR0_rx_en_mask                                                         (0x00008000)
#define CEC_RXCR0_rx_en(data)                                                        (0x00008000&((data)<<15))
#define CEC_RXCR0_rx_en_src(data)                                                    ((0x00008000&(data))>>15)
#define CEC_RXCR0_get_rx_en(data)                                                    ((0x00008000&(data))>>15)
#define CEC_RXCR0_rx_rst_shift                                                       (14)
#define CEC_RXCR0_rx_rst_mask                                                        (0x00004000)
#define CEC_RXCR0_rx_rst(data)                                                       (0x00004000&((data)<<14))
#define CEC_RXCR0_rx_rst_src(data)                                                   ((0x00004000&(data))>>14)
#define CEC_RXCR0_get_rx_rst(data)                                                   ((0x00004000&(data))>>14)
#define CEC_RXCR0_rx_continuous_shift                                                (13)
#define CEC_RXCR0_rx_continuous_mask                                                 (0x00002000)
#define CEC_RXCR0_rx_continuous(data)                                                (0x00002000&((data)<<13))
#define CEC_RXCR0_rx_continuous_src(data)                                            ((0x00002000&(data))>>13)
#define CEC_RXCR0_get_rx_continuous(data)                                            ((0x00002000&(data))>>13)
#define CEC_RXCR0_rx_int_en_shift                                                    (12)
#define CEC_RXCR0_rx_int_en_mask                                                     (0x00001000)
#define CEC_RXCR0_rx_int_en(data)                                                    (0x00001000&((data)<<12))
#define CEC_RXCR0_rx_int_en_src(data)                                                ((0x00001000&(data))>>12)
#define CEC_RXCR0_get_rx_int_en(data)                                                ((0x00001000&(data))>>12)
#define CEC_RXCR0_init_addr_shift                                                    (8)
#define CEC_RXCR0_init_addr_mask                                                     (0x00000F00)
#define CEC_RXCR0_init_addr(data)                                                    (0x00000F00&((data)<<8))
#define CEC_RXCR0_init_addr_src(data)                                                ((0x00000F00&(data))>>8)
#define CEC_RXCR0_get_init_addr(data)                                                ((0x00000F00&(data))>>8)
#define CEC_RXCR0_rx_eom_shift                                                       (7)
#define CEC_RXCR0_rx_eom_mask                                                        (0x00000080)
#define CEC_RXCR0_rx_eom(data)                                                       (0x00000080&((data)<<7))
#define CEC_RXCR0_rx_eom_src(data)                                                   ((0x00000080&(data))>>7)
#define CEC_RXCR0_get_rx_eom(data)                                                   ((0x00000080&(data))>>7)
#define CEC_RXCR0_rx_int_shift                                                       (6)
#define CEC_RXCR0_rx_int_mask                                                        (0x00000040)
#define CEC_RXCR0_rx_int(data)                                                       (0x00000040&((data)<<6))
#define CEC_RXCR0_rx_int_src(data)                                                   ((0x00000040&(data))>>6)
#define CEC_RXCR0_get_rx_int(data)                                                   ((0x00000040&(data))>>6)
#define CEC_RXCR0_rx_fifo_ov_shift                                                   (5)
#define CEC_RXCR0_rx_fifo_ov_mask                                                    (0x00000020)
#define CEC_RXCR0_rx_fifo_ov(data)                                                   (0x00000020&((data)<<5))
#define CEC_RXCR0_rx_fifo_ov_src(data)                                               ((0x00000020&(data))>>5)
#define CEC_RXCR0_get_rx_fifo_ov(data)                                               ((0x00000020&(data))>>5)
#define CEC_RXCR0_rx_fifo_cnt_shift                                                  (0)
#define CEC_RXCR0_rx_fifo_cnt_mask                                                   (0x0000001F)
#define CEC_RXCR0_rx_fifo_cnt(data)                                                  (0x0000001F&((data)<<0))
#define CEC_RXCR0_rx_fifo_cnt_src(data)                                              ((0x0000001F&(data))>>0)
#define CEC_RXCR0_get_rx_fifo_cnt(data)                                              ((0x0000001F&(data))>>0)


#define CEC_TXCR0                                                                    0x1800750C
#define CEC_TXCR0_reg_addr                                                           "0x1800750C"
#define CEC_TXCR0_reg                                                                0x1800750C
#define set_CEC_TXCR0_reg(data)   (*((volatile unsigned int*) CEC_TXCR0_reg)=data)
#define get_CEC_TXCR0_reg   (*((volatile unsigned int*) CEC_TXCR0_reg))
#define CEC_TXCR0_inst_adr                                                           "0x0043"
#define CEC_TXCR0_inst                                                               0x0043
#define CEC_TXCR0_tx_addr_en_shift                                                   (20)
#define CEC_TXCR0_tx_addr_en_mask                                                    (0x00100000)
#define CEC_TXCR0_tx_addr_en(data)                                                   (0x00100000&((data)<<20))
#define CEC_TXCR0_tx_addr_en_src(data)                                               ((0x00100000&(data))>>20)
#define CEC_TXCR0_get_tx_addr_en(data)                                               ((0x00100000&(data))>>20)
#define CEC_TXCR0_tx_addr_shift                                                      (16)
#define CEC_TXCR0_tx_addr_mask                                                       (0x000F0000)
#define CEC_TXCR0_tx_addr(data)                                                      (0x000F0000&((data)<<16))
#define CEC_TXCR0_tx_addr_src(data)                                                  ((0x000F0000&(data))>>16)
#define CEC_TXCR0_get_tx_addr(data)                                                  ((0x000F0000&(data))>>16)
#define CEC_TXCR0_tx_en_shift                                                        (15)
#define CEC_TXCR0_tx_en_mask                                                         (0x00008000)
#define CEC_TXCR0_tx_en(data)                                                        (0x00008000&((data)<<15))
#define CEC_TXCR0_tx_en_src(data)                                                    ((0x00008000&(data))>>15)
#define CEC_TXCR0_get_tx_en(data)                                                    ((0x00008000&(data))>>15)
#define CEC_TXCR0_tx_rst_shift                                                       (14)
#define CEC_TXCR0_tx_rst_mask                                                        (0x00004000)
#define CEC_TXCR0_tx_rst(data)                                                       (0x00004000&((data)<<14))
#define CEC_TXCR0_tx_rst_src(data)                                                   ((0x00004000&(data))>>14)
#define CEC_TXCR0_get_tx_rst(data)                                                   ((0x00004000&(data))>>14)
#define CEC_TXCR0_tx_continuous_shift                                                (13)
#define CEC_TXCR0_tx_continuous_mask                                                 (0x00002000)
#define CEC_TXCR0_tx_continuous(data)                                                (0x00002000&((data)<<13))
#define CEC_TXCR0_tx_continuous_src(data)                                            ((0x00002000&(data))>>13)
#define CEC_TXCR0_get_tx_continuous(data)                                            ((0x00002000&(data))>>13)
#define CEC_TXCR0_tx_int_en_shift                                                    (12)
#define CEC_TXCR0_tx_int_en_mask                                                     (0x00001000)
#define CEC_TXCR0_tx_int_en(data)                                                    (0x00001000&((data)<<12))
#define CEC_TXCR0_tx_int_en_src(data)                                                ((0x00001000&(data))>>12)
#define CEC_TXCR0_get_tx_int_en(data)                                                ((0x00001000&(data))>>12)
#define CEC_TXCR0_dest_addr_shift                                                    (8)
#define CEC_TXCR0_dest_addr_mask                                                     (0x00000F00)
#define CEC_TXCR0_dest_addr(data)                                                    (0x00000F00&((data)<<8))
#define CEC_TXCR0_dest_addr_src(data)                                                ((0x00000F00&(data))>>8)
#define CEC_TXCR0_get_dest_addr(data)                                                ((0x00000F00&(data))>>8)
#define CEC_TXCR0_tx_eom_shift                                                       (7)
#define CEC_TXCR0_tx_eom_mask                                                        (0x00000080)
#define CEC_TXCR0_tx_eom(data)                                                       (0x00000080&((data)<<7))
#define CEC_TXCR0_tx_eom_src(data)                                                   ((0x00000080&(data))>>7)
#define CEC_TXCR0_get_tx_eom(data)                                                   ((0x00000080&(data))>>7)
#define CEC_TXCR0_tx_int_shift                                                       (6)
#define CEC_TXCR0_tx_int_mask                                                        (0x00000040)
#define CEC_TXCR0_tx_int(data)                                                       (0x00000040&((data)<<6))
#define CEC_TXCR0_tx_int_src(data)                                                   ((0x00000040&(data))>>6)
#define CEC_TXCR0_get_tx_int(data)                                                   ((0x00000040&(data))>>6)
#define CEC_TXCR0_tx_fifo_ud_shift                                                   (5)
#define CEC_TXCR0_tx_fifo_ud_mask                                                    (0x00000020)
#define CEC_TXCR0_tx_fifo_ud(data)                                                   (0x00000020&((data)<<5))
#define CEC_TXCR0_tx_fifo_ud_src(data)                                               ((0x00000020&(data))>>5)
#define CEC_TXCR0_get_tx_fifo_ud(data)                                               ((0x00000020&(data))>>5)
#define CEC_TXCR0_tx_fifo_cnt_shift                                                  (0)
#define CEC_TXCR0_tx_fifo_cnt_mask                                                   (0x0000001F)
#define CEC_TXCR0_tx_fifo_cnt(data)                                                  (0x0000001F&((data)<<0))
#define CEC_TXCR0_tx_fifo_cnt_src(data)                                              ((0x0000001F&(data))>>0)
#define CEC_TXCR0_get_tx_fifo_cnt(data)                                              ((0x0000001F&(data))>>0)


#define CEC_TXDR0                                                                    0x18007510
#define CEC_TXDR0_reg_addr                                                           "0x18007510"
#define CEC_TXDR0_reg                                                                0x18007510
#define set_CEC_TXDR0_reg(data)   (*((volatile unsigned int*) CEC_TXDR0_reg)=data)
#define get_CEC_TXDR0_reg   (*((volatile unsigned int*) CEC_TXDR0_reg))
#define CEC_TXDR0_inst_adr                                                           "0x0044"
#define CEC_TXDR0_inst                                                               0x0044
#define CEC_TXDR0_tx_add_cnt_shift                                                   (6)
#define CEC_TXDR0_tx_add_cnt_mask                                                    (0x00000040)
#define CEC_TXDR0_tx_add_cnt(data)                                                   (0x00000040&((data)<<6))
#define CEC_TXDR0_tx_add_cnt_src(data)                                               ((0x00000040&(data))>>6)
#define CEC_TXDR0_get_tx_add_cnt(data)                                               ((0x00000040&(data))>>6)
#define CEC_TXDR0_rx_sub_cnt_shift                                                   (5)
#define CEC_TXDR0_rx_sub_cnt_mask                                                    (0x00000020)
#define CEC_TXDR0_rx_sub_cnt(data)                                                   (0x00000020&((data)<<5))
#define CEC_TXDR0_rx_sub_cnt_src(data)                                               ((0x00000020&(data))>>5)
#define CEC_TXDR0_get_rx_sub_cnt(data)                                               ((0x00000020&(data))>>5)
#define CEC_TXDR0_fifo_cnt_shift                                                     (0)
#define CEC_TXDR0_fifo_cnt_mask                                                      (0x0000001F)
#define CEC_TXDR0_fifo_cnt(data)                                                     (0x0000001F&((data)<<0))
#define CEC_TXDR0_fifo_cnt_src(data)                                                 ((0x0000001F&(data))>>0)
#define CEC_TXDR0_get_fifo_cnt(data)                                                 ((0x0000001F&(data))>>0)


#define CEC_TXDR1                                                                    0x18007514
#define CEC_TXDR1_reg_addr                                                           "0x18007514"
#define CEC_TXDR1_reg                                                                0x18007514
#define set_CEC_TXDR1_reg(data)   (*((volatile unsigned int*) CEC_TXDR1_reg)=data)
#define get_CEC_TXDR1_reg   (*((volatile unsigned int*) CEC_TXDR1_reg))
#define CEC_TXDR1_inst_adr                                                           "0x0045"
#define CEC_TXDR1_inst                                                               0x0045
#define CEC_TXDR1_tx_fifo_0_shift                                                    (24)
#define CEC_TXDR1_tx_fifo_0_mask                                                     (0xFF000000)
#define CEC_TXDR1_tx_fifo_0(data)                                                    (0xFF000000&((data)<<24))
#define CEC_TXDR1_tx_fifo_0_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR1_get_tx_fifo_0(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR1_tx_fifo_1_shift                                                    (16)
#define CEC_TXDR1_tx_fifo_1_mask                                                     (0x00FF0000)
#define CEC_TXDR1_tx_fifo_1(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_TXDR1_tx_fifo_1_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR1_get_tx_fifo_1(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR1_tx_fifo_2_shift                                                    (8)
#define CEC_TXDR1_tx_fifo_2_mask                                                     (0x0000FF00)
#define CEC_TXDR1_tx_fifo_2(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_TXDR1_tx_fifo_2_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR1_get_tx_fifo_2(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR1_tx_fifo_3_shift                                                    (0)
#define CEC_TXDR1_tx_fifo_3_mask                                                     (0x000000FF)
#define CEC_TXDR1_tx_fifo_3(data)                                                    (0x000000FF&((data)<<0))
#define CEC_TXDR1_tx_fifo_3_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_TXDR1_get_tx_fifo_3(data)                                                ((0x000000FF&(data))>>0)


#define CEC_TXDR2                                                                    0x18007518
#define CEC_TXDR2_reg_addr                                                           "0x18007518"
#define CEC_TXDR2_reg                                                                0x18007518
#define set_CEC_TXDR2_reg(data)   (*((volatile unsigned int*) CEC_TXDR2_reg)=data)
#define get_CEC_TXDR2_reg   (*((volatile unsigned int*) CEC_TXDR2_reg))
#define CEC_TXDR2_inst_adr                                                           "0x0046"
#define CEC_TXDR2_inst                                                               0x0046
#define CEC_TXDR2_tx_fifo_4_shift                                                    (24)
#define CEC_TXDR2_tx_fifo_4_mask                                                     (0xFF000000)
#define CEC_TXDR2_tx_fifo_4(data)                                                    (0xFF000000&((data)<<24))
#define CEC_TXDR2_tx_fifo_4_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR2_get_tx_fifo_4(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR2_tx_fifo_5_shift                                                    (16)
#define CEC_TXDR2_tx_fifo_5_mask                                                     (0x00FF0000)
#define CEC_TXDR2_tx_fifo_5(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_TXDR2_tx_fifo_5_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR2_get_tx_fifo_5(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR2_tx_fifo_6_shift                                                    (8)
#define CEC_TXDR2_tx_fifo_6_mask                                                     (0x0000FF00)
#define CEC_TXDR2_tx_fifo_6(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_TXDR2_tx_fifo_6_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR2_get_tx_fifo_6(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR2_tx_fifo_7_shift                                                    (0)
#define CEC_TXDR2_tx_fifo_7_mask                                                     (0x000000FF)
#define CEC_TXDR2_tx_fifo_7(data)                                                    (0x000000FF&((data)<<0))
#define CEC_TXDR2_tx_fifo_7_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_TXDR2_get_tx_fifo_7(data)                                                ((0x000000FF&(data))>>0)


#define CEC_TXDR3                                                                    0x1800751C
#define CEC_TXDR3_reg_addr                                                           "0x1800751C"
#define CEC_TXDR3_reg                                                                0x1800751C
#define set_CEC_TXDR3_reg(data)   (*((volatile unsigned int*) CEC_TXDR3_reg)=data)
#define get_CEC_TXDR3_reg   (*((volatile unsigned int*) CEC_TXDR3_reg))
#define CEC_TXDR3_inst_adr                                                           "0x0047"
#define CEC_TXDR3_inst                                                               0x0047
#define CEC_TXDR3_tx_fifo_8_shift                                                    (24)
#define CEC_TXDR3_tx_fifo_8_mask                                                     (0xFF000000)
#define CEC_TXDR3_tx_fifo_8(data)                                                    (0xFF000000&((data)<<24))
#define CEC_TXDR3_tx_fifo_8_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR3_get_tx_fifo_8(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR3_tx_fifo_9_shift                                                    (16)
#define CEC_TXDR3_tx_fifo_9_mask                                                     (0x00FF0000)
#define CEC_TXDR3_tx_fifo_9(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_TXDR3_tx_fifo_9_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR3_get_tx_fifo_9(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR3_tx_fifo_A_shift                                                    (8)
#define CEC_TXDR3_tx_fifo_A_mask                                                     (0x0000FF00)
#define CEC_TXDR3_tx_fifo_A(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_TXDR3_tx_fifo_A_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR3_get_tx_fifo_A(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR3_tx_fifo_B_shift                                                    (0)
#define CEC_TXDR3_tx_fifo_B_mask                                                     (0x000000FF)
#define CEC_TXDR3_tx_fifo_B(data)                                                    (0x000000FF&((data)<<0))
#define CEC_TXDR3_tx_fifo_B_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_TXDR3_get_tx_fifo_B(data)                                                ((0x000000FF&(data))>>0)


#define CEC_TXDR4                                                                    0x18007520
#define CEC_TXDR4_reg_addr                                                           "0x18007520"
#define CEC_TXDR4_reg                                                                0x18007520
#define set_CEC_TXDR4_reg(data)   (*((volatile unsigned int*) CEC_TXDR4_reg)=data)
#define get_CEC_TXDR4_reg   (*((volatile unsigned int*) CEC_TXDR4_reg))
#define CEC_TXDR4_inst_adr                                                           "0x0048"
#define CEC_TXDR4_inst                                                               0x0048
#define CEC_TXDR4_tx_fifo_C_shift                                                    (24)
#define CEC_TXDR4_tx_fifo_C_mask                                                     (0xFF000000)
#define CEC_TXDR4_tx_fifo_C(data)                                                    (0xFF000000&((data)<<24))
#define CEC_TXDR4_tx_fifo_C_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR4_get_tx_fifo_C(data)                                                ((0xFF000000&(data))>>24)
#define CEC_TXDR4_tx_fifo_D_shift                                                    (16)
#define CEC_TXDR4_tx_fifo_D_mask                                                     (0x00FF0000)
#define CEC_TXDR4_tx_fifo_D(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_TXDR4_tx_fifo_D_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR4_get_tx_fifo_D(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_TXDR4_tx_fifo_E_shift                                                    (8)
#define CEC_TXDR4_tx_fifo_E_mask                                                     (0x0000FF00)
#define CEC_TXDR4_tx_fifo_E(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_TXDR4_tx_fifo_E_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR4_get_tx_fifo_E(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_TXDR4_tx_fifo_F_shift                                                    (0)
#define CEC_TXDR4_tx_fifo_F_mask                                                     (0x000000FF)
#define CEC_TXDR4_tx_fifo_F(data)                                                    (0x000000FF&((data)<<0))
#define CEC_TXDR4_tx_fifo_F_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_TXDR4_get_tx_fifo_F(data)                                                ((0x000000FF&(data))>>0)


#define CEC_RXDR1                                                                    0x18007524
#define CEC_RXDR1_reg_addr                                                           "0x18007524"
#define CEC_RXDR1_reg                                                                0x18007524
#define set_CEC_RXDR1_reg(data)   (*((volatile unsigned int*) CEC_RXDR1_reg)=data)
#define get_CEC_RXDR1_reg   (*((volatile unsigned int*) CEC_RXDR1_reg))
#define CEC_RXDR1_inst_adr                                                           "0x0049"
#define CEC_RXDR1_inst                                                               0x0049
#define CEC_RXDR1_rx_fifo_0_shift                                                    (24)
#define CEC_RXDR1_rx_fifo_0_mask                                                     (0xFF000000)
#define CEC_RXDR1_rx_fifo_0(data)                                                    (0xFF000000&((data)<<24))
#define CEC_RXDR1_rx_fifo_0_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR1_get_rx_fifo_0(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR1_rx_fifo_1_shift                                                    (16)
#define CEC_RXDR1_rx_fifo_1_mask                                                     (0x00FF0000)
#define CEC_RXDR1_rx_fifo_1(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_RXDR1_rx_fifo_1_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR1_get_rx_fifo_1(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR1_rx_fifo_2_shift                                                    (8)
#define CEC_RXDR1_rx_fifo_2_mask                                                     (0x0000FF00)
#define CEC_RXDR1_rx_fifo_2(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_RXDR1_rx_fifo_2_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR1_get_rx_fifo_2(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR1_rx_fifo_3_shift                                                    (0)
#define CEC_RXDR1_rx_fifo_3_mask                                                     (0x000000FF)
#define CEC_RXDR1_rx_fifo_3(data)                                                    (0x000000FF&((data)<<0))
#define CEC_RXDR1_rx_fifo_3_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_RXDR1_get_rx_fifo_3(data)                                                ((0x000000FF&(data))>>0)


#define CEC_RXDR2                                                                    0x18007528
#define CEC_RXDR2_reg_addr                                                           "0x18007528"
#define CEC_RXDR2_reg                                                                0x18007528
#define set_CEC_RXDR2_reg(data)   (*((volatile unsigned int*) CEC_RXDR2_reg)=data)
#define get_CEC_RXDR2_reg   (*((volatile unsigned int*) CEC_RXDR2_reg))
#define CEC_RXDR2_inst_adr                                                           "0x004A"
#define CEC_RXDR2_inst                                                               0x004A
#define CEC_RXDR2_rx_fifo_4_shift                                                    (24)
#define CEC_RXDR2_rx_fifo_4_mask                                                     (0xFF000000)
#define CEC_RXDR2_rx_fifo_4(data)                                                    (0xFF000000&((data)<<24))
#define CEC_RXDR2_rx_fifo_4_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR2_get_rx_fifo_4(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR2_rx_fifo_5_shift                                                    (16)
#define CEC_RXDR2_rx_fifo_5_mask                                                     (0x00FF0000)
#define CEC_RXDR2_rx_fifo_5(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_RXDR2_rx_fifo_5_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR2_get_rx_fifo_5(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR2_rx_fifo_6_shift                                                    (8)
#define CEC_RXDR2_rx_fifo_6_mask                                                     (0x0000FF00)
#define CEC_RXDR2_rx_fifo_6(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_RXDR2_rx_fifo_6_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR2_get_rx_fifo_6(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR2_rx_fifo_7_shift                                                    (0)
#define CEC_RXDR2_rx_fifo_7_mask                                                     (0x000000FF)
#define CEC_RXDR2_rx_fifo_7(data)                                                    (0x000000FF&((data)<<0))
#define CEC_RXDR2_rx_fifo_7_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_RXDR2_get_rx_fifo_7(data)                                                ((0x000000FF&(data))>>0)


#define CEC_RXDR3                                                                    0x1800752C
#define CEC_RXDR3_reg_addr                                                           "0x1800752C"
#define CEC_RXDR3_reg                                                                0x1800752C
#define set_CEC_RXDR3_reg(data)   (*((volatile unsigned int*) CEC_RXDR3_reg)=data)
#define get_CEC_RXDR3_reg   (*((volatile unsigned int*) CEC_RXDR3_reg))
#define CEC_RXDR3_inst_adr                                                           "0x004B"
#define CEC_RXDR3_inst                                                               0x004B
#define CEC_RXDR3_rx_fifo_8_shift                                                    (24)
#define CEC_RXDR3_rx_fifo_8_mask                                                     (0xFF000000)
#define CEC_RXDR3_rx_fifo_8(data)                                                    (0xFF000000&((data)<<24))
#define CEC_RXDR3_rx_fifo_8_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR3_get_rx_fifo_8(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR3_rx_fifo_9_shift                                                    (16)
#define CEC_RXDR3_rx_fifo_9_mask                                                     (0x00FF0000)
#define CEC_RXDR3_rx_fifo_9(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_RXDR3_rx_fifo_9_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR3_get_rx_fifo_9(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR3_rx_fifo_A_shift                                                    (8)
#define CEC_RXDR3_rx_fifo_A_mask                                                     (0x0000FF00)
#define CEC_RXDR3_rx_fifo_A(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_RXDR3_rx_fifo_A_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR3_get_rx_fifo_A(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR3_rx_fifo_B_shift                                                    (0)
#define CEC_RXDR3_rx_fifo_B_mask                                                     (0x000000FF)
#define CEC_RXDR3_rx_fifo_B(data)                                                    (0x000000FF&((data)<<0))
#define CEC_RXDR3_rx_fifo_B_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_RXDR3_get_rx_fifo_B(data)                                                ((0x000000FF&(data))>>0)


#define CEC_RXDR4                                                                    0x18007530
#define CEC_RXDR4_reg_addr                                                           "0x18007530"
#define CEC_RXDR4_reg                                                                0x18007530
#define set_CEC_RXDR4_reg(data)   (*((volatile unsigned int*) CEC_RXDR4_reg)=data)
#define get_CEC_RXDR4_reg   (*((volatile unsigned int*) CEC_RXDR4_reg))
#define CEC_RXDR4_inst_adr                                                           "0x004C"
#define CEC_RXDR4_inst                                                               0x004C
#define CEC_RXDR4_rx_fifo_C_shift                                                    (24)
#define CEC_RXDR4_rx_fifo_C_mask                                                     (0xFF000000)
#define CEC_RXDR4_rx_fifo_C(data)                                                    (0xFF000000&((data)<<24))
#define CEC_RXDR4_rx_fifo_C_src(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR4_get_rx_fifo_C(data)                                                ((0xFF000000&(data))>>24)
#define CEC_RXDR4_rx_fifo_D_shift                                                    (16)
#define CEC_RXDR4_rx_fifo_D_mask                                                     (0x00FF0000)
#define CEC_RXDR4_rx_fifo_D(data)                                                    (0x00FF0000&((data)<<16))
#define CEC_RXDR4_rx_fifo_D_src(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR4_get_rx_fifo_D(data)                                                ((0x00FF0000&(data))>>16)
#define CEC_RXDR4_rx_fifo_E_shift                                                    (8)
#define CEC_RXDR4_rx_fifo_E_mask                                                     (0x0000FF00)
#define CEC_RXDR4_rx_fifo_E(data)                                                    (0x0000FF00&((data)<<8))
#define CEC_RXDR4_rx_fifo_E_src(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR4_get_rx_fifo_E(data)                                                ((0x0000FF00&(data))>>8)
#define CEC_RXDR4_rx_fifo_F_shift                                                    (0)
#define CEC_RXDR4_rx_fifo_F_mask                                                     (0x000000FF)
#define CEC_RXDR4_rx_fifo_F(data)                                                    (0x000000FF&((data)<<0))
#define CEC_RXDR4_rx_fifo_F_src(data)                                                ((0x000000FF&(data))>>0)
#define CEC_RXDR4_get_rx_fifo_F(data)                                                ((0x000000FF&(data))>>0)


#define CEC_RXTCR0                                                                   0x18007534
#define CEC_RXTCR0_reg_addr                                                          "0x18007534"
#define CEC_RXTCR0_reg                                                               0x18007534
#define set_CEC_RXTCR0_reg(data)   (*((volatile unsigned int*) CEC_RXTCR0_reg)=data)
#define get_CEC_RXTCR0_reg   (*((volatile unsigned int*) CEC_RXTCR0_reg))
#define CEC_RXTCR0_inst_adr                                                          "0x004D"
#define CEC_RXTCR0_inst                                                              0x004D
#define CEC_RXTCR0_rx_start_low_shift                                                (24)
#define CEC_RXTCR0_rx_start_low_mask                                                 (0xFF000000)
#define CEC_RXTCR0_rx_start_low(data)                                                (0xFF000000&((data)<<24))
#define CEC_RXTCR0_rx_start_low_src(data)                                            ((0xFF000000&(data))>>24)
#define CEC_RXTCR0_get_rx_start_low(data)                                            ((0xFF000000&(data))>>24)
#define CEC_RXTCR0_rx_start_period_shift                                             (16)
#define CEC_RXTCR0_rx_start_period_mask                                              (0x00FF0000)
#define CEC_RXTCR0_rx_start_period(data)                                             (0x00FF0000&((data)<<16))
#define CEC_RXTCR0_rx_start_period_src(data)                                         ((0x00FF0000&(data))>>16)
#define CEC_RXTCR0_get_rx_start_period(data)                                         ((0x00FF0000&(data))>>16)
#define CEC_RXTCR0_rx_data_sample_shift                                              (8)
#define CEC_RXTCR0_rx_data_sample_mask                                               (0x0000FF00)
#define CEC_RXTCR0_rx_data_sample(data)                                              (0x0000FF00&((data)<<8))
#define CEC_RXTCR0_rx_data_sample_src(data)                                          ((0x0000FF00&(data))>>8)
#define CEC_RXTCR0_get_rx_data_sample(data)                                          ((0x0000FF00&(data))>>8)
#define CEC_RXTCR0_rx_data_period_shift                                              (0)
#define CEC_RXTCR0_rx_data_period_mask                                               (0x000000FF)
#define CEC_RXTCR0_rx_data_period(data)                                              (0x000000FF&((data)<<0))
#define CEC_RXTCR0_rx_data_period_src(data)                                          ((0x000000FF&(data))>>0)
#define CEC_RXTCR0_get_rx_data_period(data)                                          ((0x000000FF&(data))>>0)


#define CEC_TXTCR0                                                                   0x18007538
#define CEC_TXTCR0_reg_addr                                                          "0x18007538"
#define CEC_TXTCR0_reg                                                               0x18007538
#define set_CEC_TXTCR0_reg(data)   (*((volatile unsigned int*) CEC_TXTCR0_reg)=data)
#define get_CEC_TXTCR0_reg   (*((volatile unsigned int*) CEC_TXTCR0_reg))
#define CEC_TXTCR0_inst_adr                                                          "0x004E"
#define CEC_TXTCR0_inst                                                              0x004E
#define CEC_TXTCR0_tx_start_low_shift                                                (8)
#define CEC_TXTCR0_tx_start_low_mask                                                 (0x0000FF00)
#define CEC_TXTCR0_tx_start_low(data)                                                (0x0000FF00&((data)<<8))
#define CEC_TXTCR0_tx_start_low_src(data)                                            ((0x0000FF00&(data))>>8)
#define CEC_TXTCR0_get_tx_start_low(data)                                            ((0x0000FF00&(data))>>8)
#define CEC_TXTCR0_tx_start_high_shift                                               (0)
#define CEC_TXTCR0_tx_start_high_mask                                                (0x000000FF)
#define CEC_TXTCR0_tx_start_high(data)                                               (0x000000FF&((data)<<0))
#define CEC_TXTCR0_tx_start_high_src(data)                                           ((0x000000FF&(data))>>0)
#define CEC_TXTCR0_get_tx_start_high(data)                                           ((0x000000FF&(data))>>0)


#define CEC_TXTCR1                                                                   0x1800753C
#define CEC_TXTCR1_reg_addr                                                          "0x1800753C"
#define CEC_TXTCR1_reg                                                               0x1800753C
#define set_CEC_TXTCR1_reg(data)   (*((volatile unsigned int*) CEC_TXTCR1_reg)=data)
#define get_CEC_TXTCR1_reg   (*((volatile unsigned int*) CEC_TXTCR1_reg))
#define CEC_TXTCR1_inst_adr                                                          "0x004F"
#define CEC_TXTCR1_inst                                                              0x004F
#define CEC_TXTCR1_tx_data_low_shift                                                 (16)
#define CEC_TXTCR1_tx_data_low_mask                                                  (0x00FF0000)
#define CEC_TXTCR1_tx_data_low(data)                                                 (0x00FF0000&((data)<<16))
#define CEC_TXTCR1_tx_data_low_src(data)                                             ((0x00FF0000&(data))>>16)
#define CEC_TXTCR1_get_tx_data_low(data)                                             ((0x00FF0000&(data))>>16)
#define CEC_TXTCR1_tx_data_01_shift                                                  (8)
#define CEC_TXTCR1_tx_data_01_mask                                                   (0x0000FF00)
#define CEC_TXTCR1_tx_data_01(data)                                                  (0x0000FF00&((data)<<8))
#define CEC_TXTCR1_tx_data_01_src(data)                                              ((0x0000FF00&(data))>>8)
#define CEC_TXTCR1_get_tx_data_01(data)                                              ((0x0000FF00&(data))>>8)
#define CEC_TXTCR1_tx_data_high_shift                                                (0)
#define CEC_TXTCR1_tx_data_high_mask                                                 (0x000000FF)
#define CEC_TXTCR1_tx_data_high(data)                                                (0x000000FF&((data)<<0))
#define CEC_TXTCR1_tx_data_high_src(data)                                            ((0x000000FF&(data))>>0)
#define CEC_TXTCR1_get_tx_data_high(data)                                            ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_01                                                    0x18007540
#define GDI_CEC_COMPARE_OPCODE_01_reg_addr                                           "0x18007540"
#define GDI_CEC_COMPARE_OPCODE_01_reg                                                0x18007540
#define set_GDI_CEC_COMPARE_OPCODE_01_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_01_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_01_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_01_reg))
#define GDI_CEC_COMPARE_OPCODE_01_inst_adr                                           "0x0050"
#define GDI_CEC_COMPARE_OPCODE_01_inst                                               0x0050
#define GDI_CEC_COMPARE_OPCODE_01_Compare_opcode_01_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_01_Compare_opcode_01_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_01_Compare_opcode_01(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_01_Compare_opcode_01_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_01_get_Compare_opcode_01(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPCODE_01                                                       0x18007544
#define GDI_CEC_SEND_OPCODE_01_reg_addr                                              "0x18007544"
#define GDI_CEC_SEND_OPCODE_01_reg                                                   0x18007544
#define set_GDI_CEC_SEND_OPCODE_01_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_01_reg)=data)
#define get_GDI_CEC_SEND_OPCODE_01_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_01_reg))
#define GDI_CEC_SEND_OPCODE_01_inst_adr                                              "0x0051"
#define GDI_CEC_SEND_OPCODE_01_inst                                                  0x0051
#define GDI_CEC_SEND_OPCODE_01_Send_opcode_01_shift                                  (0)
#define GDI_CEC_SEND_OPCODE_01_Send_opcode_01_mask                                   (0x000000FF)
#define GDI_CEC_SEND_OPCODE_01_Send_opcode_01(data)                                  (0x000000FF&((data)<<0))
#define GDI_CEC_SEND_OPCODE_01_Send_opcode_01_src(data)                              ((0x000000FF&(data))>>0)
#define GDI_CEC_SEND_OPCODE_01_get_Send_opcode_01(data)                              ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPRAND_NUMBER_01                                                0x18007548
#define GDI_CEC_SEND_OPRAND_NUMBER_01_reg_addr                                       "0x18007548"
#define GDI_CEC_SEND_OPRAND_NUMBER_01_reg                                            0x18007548
#define set_GDI_CEC_SEND_OPRAND_NUMBER_01_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_01_reg)=data)
#define get_GDI_CEC_SEND_OPRAND_NUMBER_01_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_01_reg))
#define GDI_CEC_SEND_OPRAND_NUMBER_01_inst_adr                                       "0x0052"
#define GDI_CEC_SEND_OPRAND_NUMBER_01_inst                                           0x0052
#define GDI_CEC_SEND_OPRAND_NUMBER_01_Operand_number_01_shift                        (0)
#define GDI_CEC_SEND_OPRAND_NUMBER_01_Operand_number_01_mask                         (0x00000003)
#define GDI_CEC_SEND_OPRAND_NUMBER_01_Operand_number_01(data)                        (0x00000003&((data)<<0))
#define GDI_CEC_SEND_OPRAND_NUMBER_01_Operand_number_01_src(data)                    ((0x00000003&(data))>>0)
#define GDI_CEC_SEND_OPRAND_NUMBER_01_get_Operand_number_01(data)                    ((0x00000003&(data))>>0)


#define GDI_CEC_OPRAND_01                                                            0x1800754C
#define GDI_CEC_OPRAND_01_reg_addr                                                   "0x1800754C"
#define GDI_CEC_OPRAND_01_reg                                                        0x1800754C
#define set_GDI_CEC_OPRAND_01_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_01_reg)=data)
#define get_GDI_CEC_OPRAND_01_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_01_reg))
#define GDI_CEC_OPRAND_01_inst_adr                                                   "0x0053"
#define GDI_CEC_OPRAND_01_inst                                                       0x0053
#define GDI_CEC_OPRAND_01_Operand_01_shift                                           (0)
#define GDI_CEC_OPRAND_01_Operand_01_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_01_Operand_01(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_01_Operand_01_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_01_get_Operand_01(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_02                                                            0x18007550
#define GDI_CEC_OPRAND_02_reg_addr                                                   "0x18007550"
#define GDI_CEC_OPRAND_02_reg                                                        0x18007550
#define set_GDI_CEC_OPRAND_02_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_02_reg)=data)
#define get_GDI_CEC_OPRAND_02_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_02_reg))
#define GDI_CEC_OPRAND_02_inst_adr                                                   "0x0054"
#define GDI_CEC_OPRAND_02_inst                                                       0x0054
#define GDI_CEC_OPRAND_02_Operand_02_shift                                           (0)
#define GDI_CEC_OPRAND_02_Operand_02_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_02_Operand_02(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_02_Operand_02_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_02_get_Operand_02(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_03                                                            0x18007554
#define GDI_CEC_OPRAND_03_reg_addr                                                   "0x18007554"
#define GDI_CEC_OPRAND_03_reg                                                        0x18007554
#define set_GDI_CEC_OPRAND_03_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_03_reg)=data)
#define get_GDI_CEC_OPRAND_03_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_03_reg))
#define GDI_CEC_OPRAND_03_inst_adr                                                   "0x0055"
#define GDI_CEC_OPRAND_03_inst                                                       0x0055
#define GDI_CEC_OPRAND_03_Operand_03_shift                                           (0)
#define GDI_CEC_OPRAND_03_Operand_03_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_03_Operand_03(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_03_Operand_03_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_03_get_Operand_03(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_02                                                    0x18007558
#define GDI_CEC_COMPARE_OPCODE_02_reg_addr                                           "0x18007558"
#define GDI_CEC_COMPARE_OPCODE_02_reg                                                0x18007558
#define set_GDI_CEC_COMPARE_OPCODE_02_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_02_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_02_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_02_reg))
#define GDI_CEC_COMPARE_OPCODE_02_inst_adr                                           "0x0056"
#define GDI_CEC_COMPARE_OPCODE_02_inst                                               0x0056
#define GDI_CEC_COMPARE_OPCODE_02_Compare_opcode_02_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_02_Compare_opcode_02_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_02_Compare_opcode_02(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_02_Compare_opcode_02_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_02_get_Compare_opcode_02(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPCODE_02                                                       0x1800755C
#define GDI_CEC_SEND_OPCODE_02_reg_addr                                              "0x1800755C"
#define GDI_CEC_SEND_OPCODE_02_reg                                                   0x1800755C
#define set_GDI_CEC_SEND_OPCODE_02_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_02_reg)=data)
#define get_GDI_CEC_SEND_OPCODE_02_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_02_reg))
#define GDI_CEC_SEND_OPCODE_02_inst_adr                                              "0x0057"
#define GDI_CEC_SEND_OPCODE_02_inst                                                  0x0057
#define GDI_CEC_SEND_OPCODE_02_Send_opcode_02_shift                                  (0)
#define GDI_CEC_SEND_OPCODE_02_Send_opcode_02_mask                                   (0x000000FF)
#define GDI_CEC_SEND_OPCODE_02_Send_opcode_02(data)                                  (0x000000FF&((data)<<0))
#define GDI_CEC_SEND_OPCODE_02_Send_opcode_02_src(data)                              ((0x000000FF&(data))>>0)
#define GDI_CEC_SEND_OPCODE_02_get_Send_opcode_02(data)                              ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPRAND_NUMBER_02                                                0x18007560
#define GDI_CEC_SEND_OPRAND_NUMBER_02_reg_addr                                       "0x18007560"
#define GDI_CEC_SEND_OPRAND_NUMBER_02_reg                                            0x18007560
#define set_GDI_CEC_SEND_OPRAND_NUMBER_02_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_02_reg)=data)
#define get_GDI_CEC_SEND_OPRAND_NUMBER_02_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_02_reg))
#define GDI_CEC_SEND_OPRAND_NUMBER_02_inst_adr                                       "0x0058"
#define GDI_CEC_SEND_OPRAND_NUMBER_02_inst                                           0x0058
#define GDI_CEC_SEND_OPRAND_NUMBER_02_Operand_number_02_shift                        (0)
#define GDI_CEC_SEND_OPRAND_NUMBER_02_Operand_number_02_mask                         (0x00000003)
#define GDI_CEC_SEND_OPRAND_NUMBER_02_Operand_number_02(data)                        (0x00000003&((data)<<0))
#define GDI_CEC_SEND_OPRAND_NUMBER_02_Operand_number_02_src(data)                    ((0x00000003&(data))>>0)
#define GDI_CEC_SEND_OPRAND_NUMBER_02_get_Operand_number_02(data)                    ((0x00000003&(data))>>0)


#define GDI_CEC_OPRAND_04                                                            0x18007564
#define GDI_CEC_OPRAND_04_reg_addr                                                   "0x18007564"
#define GDI_CEC_OPRAND_04_reg                                                        0x18007564
#define set_GDI_CEC_OPRAND_04_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_04_reg)=data)
#define get_GDI_CEC_OPRAND_04_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_04_reg))
#define GDI_CEC_OPRAND_04_inst_adr                                                   "0x0059"
#define GDI_CEC_OPRAND_04_inst                                                       0x0059
#define GDI_CEC_OPRAND_04_Operand_04_shift                                           (0)
#define GDI_CEC_OPRAND_04_Operand_04_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_04_Operand_04(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_04_Operand_04_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_04_get_Operand_04(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_05                                                            0x18007568
#define GDI_CEC_OPRAND_05_reg_addr                                                   "0x18007568"
#define GDI_CEC_OPRAND_05_reg                                                        0x18007568
#define set_GDI_CEC_OPRAND_05_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_05_reg)=data)
#define get_GDI_CEC_OPRAND_05_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_05_reg))
#define GDI_CEC_OPRAND_05_inst_adr                                                   "0x005A"
#define GDI_CEC_OPRAND_05_inst                                                       0x005A
#define GDI_CEC_OPRAND_05_Operand_05_shift                                           (0)
#define GDI_CEC_OPRAND_05_Operand_05_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_05_Operand_05(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_05_Operand_05_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_05_get_Operand_05(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_06                                                            0x1800756C
#define GDI_CEC_OPRAND_06_reg_addr                                                   "0x1800756C"
#define GDI_CEC_OPRAND_06_reg                                                        0x1800756C
#define set_GDI_CEC_OPRAND_06_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_06_reg)=data)
#define get_GDI_CEC_OPRAND_06_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_06_reg))
#define GDI_CEC_OPRAND_06_inst_adr                                                   "0x005B"
#define GDI_CEC_OPRAND_06_inst                                                       0x005B
#define GDI_CEC_OPRAND_06_Operand_06_shift                                           (0)
#define GDI_CEC_OPRAND_06_Operand_06_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_06_Operand_06(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_06_Operand_06_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_06_get_Operand_06(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_03                                                    0x18007570
#define GDI_CEC_COMPARE_OPCODE_03_reg_addr                                           "0x18007570"
#define GDI_CEC_COMPARE_OPCODE_03_reg                                                0x18007570
#define set_GDI_CEC_COMPARE_OPCODE_03_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_03_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_03_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_03_reg))
#define GDI_CEC_COMPARE_OPCODE_03_inst_adr                                           "0x005C"
#define GDI_CEC_COMPARE_OPCODE_03_inst                                               0x005C
#define GDI_CEC_COMPARE_OPCODE_03_Compare_opcode_03_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_03_Compare_opcode_03_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_03_Compare_opcode_03(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_03_Compare_opcode_03_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_03_get_Compare_opcode_03(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPCODE_03                                                       0x18007574
#define GDI_CEC_SEND_OPCODE_03_reg_addr                                              "0x18007574"
#define GDI_CEC_SEND_OPCODE_03_reg                                                   0x18007574
#define set_GDI_CEC_SEND_OPCODE_03_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_03_reg)=data)
#define get_GDI_CEC_SEND_OPCODE_03_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_03_reg))
#define GDI_CEC_SEND_OPCODE_03_inst_adr                                              "0x005D"
#define GDI_CEC_SEND_OPCODE_03_inst                                                  0x005D
#define GDI_CEC_SEND_OPCODE_03_Send_opcode_03_shift                                  (0)
#define GDI_CEC_SEND_OPCODE_03_Send_opcode_03_mask                                   (0x000000FF)
#define GDI_CEC_SEND_OPCODE_03_Send_opcode_03(data)                                  (0x000000FF&((data)<<0))
#define GDI_CEC_SEND_OPCODE_03_Send_opcode_03_src(data)                              ((0x000000FF&(data))>>0)
#define GDI_CEC_SEND_OPCODE_03_get_Send_opcode_03(data)                              ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPRAND_NUMBER_03                                                0x18007578
#define GDI_CEC_SEND_OPRAND_NUMBER_03_reg_addr                                       "0x18007578"
#define GDI_CEC_SEND_OPRAND_NUMBER_03_reg                                            0x18007578
#define set_GDI_CEC_SEND_OPRAND_NUMBER_03_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_03_reg)=data)
#define get_GDI_CEC_SEND_OPRAND_NUMBER_03_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_03_reg))
#define GDI_CEC_SEND_OPRAND_NUMBER_03_inst_adr                                       "0x005E"
#define GDI_CEC_SEND_OPRAND_NUMBER_03_inst                                           0x005E
#define GDI_CEC_SEND_OPRAND_NUMBER_03_Operand_number_03_shift                        (0)
#define GDI_CEC_SEND_OPRAND_NUMBER_03_Operand_number_03_mask                         (0x00000003)
#define GDI_CEC_SEND_OPRAND_NUMBER_03_Operand_number_03(data)                        (0x00000003&((data)<<0))
#define GDI_CEC_SEND_OPRAND_NUMBER_03_Operand_number_03_src(data)                    ((0x00000003&(data))>>0)
#define GDI_CEC_SEND_OPRAND_NUMBER_03_get_Operand_number_03(data)                    ((0x00000003&(data))>>0)


#define GDI_CEC_OPRAND_07                                                            0x1800757C
#define GDI_CEC_OPRAND_07_reg_addr                                                   "0x1800757C"
#define GDI_CEC_OPRAND_07_reg                                                        0x1800757C
#define set_GDI_CEC_OPRAND_07_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_07_reg)=data)
#define get_GDI_CEC_OPRAND_07_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_07_reg))
#define GDI_CEC_OPRAND_07_inst_adr                                                   "0x005F"
#define GDI_CEC_OPRAND_07_inst                                                       0x005F
#define GDI_CEC_OPRAND_07_Operand_07_shift                                           (0)
#define GDI_CEC_OPRAND_07_Operand_07_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_07_Operand_07(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_07_Operand_07_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_07_get_Operand_07(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_08                                                            0x18007580
#define GDI_CEC_OPRAND_08_reg_addr                                                   "0x18007580"
#define GDI_CEC_OPRAND_08_reg                                                        0x18007580
#define set_GDI_CEC_OPRAND_08_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_08_reg)=data)
#define get_GDI_CEC_OPRAND_08_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_08_reg))
#define GDI_CEC_OPRAND_08_inst_adr                                                   "0x0060"
#define GDI_CEC_OPRAND_08_inst                                                       0x0060
#define GDI_CEC_OPRAND_08_Operand_08_shift                                           (0)
#define GDI_CEC_OPRAND_08_Operand_08_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_08_Operand_08(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_08_Operand_08_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_08_get_Operand_08(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_09                                                            0x18007584
#define GDI_CEC_OPRAND_09_reg_addr                                                   "0x18007584"
#define GDI_CEC_OPRAND_09_reg                                                        0x18007584
#define set_GDI_CEC_OPRAND_09_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_09_reg)=data)
#define get_GDI_CEC_OPRAND_09_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_09_reg))
#define GDI_CEC_OPRAND_09_inst_adr                                                   "0x0061"
#define GDI_CEC_OPRAND_09_inst                                                       0x0061
#define GDI_CEC_OPRAND_09_Operand_09_shift                                           (0)
#define GDI_CEC_OPRAND_09_Operand_09_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_09_Operand_09(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_09_Operand_09_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_09_get_Operand_09(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_04                                                    0x18007588
#define GDI_CEC_COMPARE_OPCODE_04_reg_addr                                           "0x18007588"
#define GDI_CEC_COMPARE_OPCODE_04_reg                                                0x18007588
#define set_GDI_CEC_COMPARE_OPCODE_04_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_04_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_04_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_04_reg))
#define GDI_CEC_COMPARE_OPCODE_04_inst_adr                                           "0x0062"
#define GDI_CEC_COMPARE_OPCODE_04_inst                                               0x0062
#define GDI_CEC_COMPARE_OPCODE_04_Compare_opcode_04_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_04_Compare_opcode_04_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_04_Compare_opcode_04(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_04_Compare_opcode_04_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_04_get_Compare_opcode_04(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPCODE_04                                                       0x1800758C
#define GDI_CEC_SEND_OPCODE_04_reg_addr                                              "0x1800758C"
#define GDI_CEC_SEND_OPCODE_04_reg                                                   0x1800758C
#define set_GDI_CEC_SEND_OPCODE_04_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_04_reg)=data)
#define get_GDI_CEC_SEND_OPCODE_04_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPCODE_04_reg))
#define GDI_CEC_SEND_OPCODE_04_inst_adr                                              "0x0063"
#define GDI_CEC_SEND_OPCODE_04_inst                                                  0x0063
#define GDI_CEC_SEND_OPCODE_04_Send_opcode_04_shift                                  (0)
#define GDI_CEC_SEND_OPCODE_04_Send_opcode_04_mask                                   (0x000000FF)
#define GDI_CEC_SEND_OPCODE_04_Send_opcode_04(data)                                  (0x000000FF&((data)<<0))
#define GDI_CEC_SEND_OPCODE_04_Send_opcode_04_src(data)                              ((0x000000FF&(data))>>0)
#define GDI_CEC_SEND_OPCODE_04_get_Send_opcode_04(data)                              ((0x000000FF&(data))>>0)


#define GDI_CEC_SEND_OPRAND_NUMBER_04                                                0x18007590
#define GDI_CEC_SEND_OPRAND_NUMBER_04_reg_addr                                       "0x18007590"
#define GDI_CEC_SEND_OPRAND_NUMBER_04_reg                                            0x18007590
#define set_GDI_CEC_SEND_OPRAND_NUMBER_04_reg(data)   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_04_reg)=data)
#define get_GDI_CEC_SEND_OPRAND_NUMBER_04_reg   (*((volatile unsigned int*) GDI_CEC_SEND_OPRAND_NUMBER_04_reg))
#define GDI_CEC_SEND_OPRAND_NUMBER_04_inst_adr                                       "0x0064"
#define GDI_CEC_SEND_OPRAND_NUMBER_04_inst                                           0x0064
#define GDI_CEC_SEND_OPRAND_NUMBER_04_Operand_number_04_shift                        (0)
#define GDI_CEC_SEND_OPRAND_NUMBER_04_Operand_number_04_mask                         (0x00000003)
#define GDI_CEC_SEND_OPRAND_NUMBER_04_Operand_number_04(data)                        (0x00000003&((data)<<0))
#define GDI_CEC_SEND_OPRAND_NUMBER_04_Operand_number_04_src(data)                    ((0x00000003&(data))>>0)
#define GDI_CEC_SEND_OPRAND_NUMBER_04_get_Operand_number_04(data)                    ((0x00000003&(data))>>0)


#define GDI_CEC_OPRAND_10                                                            0x18007594
#define GDI_CEC_OPRAND_10_reg_addr                                                   "0x18007594"
#define GDI_CEC_OPRAND_10_reg                                                        0x18007594
#define set_GDI_CEC_OPRAND_10_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_10_reg)=data)
#define get_GDI_CEC_OPRAND_10_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_10_reg))
#define GDI_CEC_OPRAND_10_inst_adr                                                   "0x0065"
#define GDI_CEC_OPRAND_10_inst                                                       0x0065
#define GDI_CEC_OPRAND_10_Operand_10_shift                                           (0)
#define GDI_CEC_OPRAND_10_Operand_10_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_10_Operand_10(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_10_Operand_10_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_10_get_Operand_10(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_11                                                            0x18007598
#define GDI_CEC_OPRAND_11_reg_addr                                                   "0x18007598"
#define GDI_CEC_OPRAND_11_reg                                                        0x18007598
#define set_GDI_CEC_OPRAND_11_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_11_reg)=data)
#define get_GDI_CEC_OPRAND_11_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_11_reg))
#define GDI_CEC_OPRAND_11_inst_adr                                                   "0x0066"
#define GDI_CEC_OPRAND_11_inst                                                       0x0066
#define GDI_CEC_OPRAND_11_Operand_11_shift                                           (0)
#define GDI_CEC_OPRAND_11_Operand_11_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_11_Operand_11(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_11_Operand_11_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_11_get_Operand_11(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_OPRAND_12                                                            0x1800759C
#define GDI_CEC_OPRAND_12_reg_addr                                                   "0x1800759C"
#define GDI_CEC_OPRAND_12_reg                                                        0x1800759C
#define set_GDI_CEC_OPRAND_12_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPRAND_12_reg)=data)
#define get_GDI_CEC_OPRAND_12_reg   (*((volatile unsigned int*) GDI_CEC_OPRAND_12_reg))
#define GDI_CEC_OPRAND_12_inst_adr                                                   "0x0067"
#define GDI_CEC_OPRAND_12_inst                                                       0x0067
#define GDI_CEC_OPRAND_12_Operand_12_shift                                           (0)
#define GDI_CEC_OPRAND_12_Operand_12_mask                                            (0x000000FF)
#define GDI_CEC_OPRAND_12_Operand_12(data)                                           (0x000000FF&((data)<<0))
#define GDI_CEC_OPRAND_12_Operand_12_src(data)                                       ((0x000000FF&(data))>>0)
#define GDI_CEC_OPRAND_12_get_Operand_12(data)                                       ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_05                                                    0x180075A0
#define GDI_CEC_COMPARE_OPCODE_05_reg_addr                                           "0x180075A0"
#define GDI_CEC_COMPARE_OPCODE_05_reg                                                0x180075A0
#define set_GDI_CEC_COMPARE_OPCODE_05_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_05_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_05_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_05_reg))
#define GDI_CEC_COMPARE_OPCODE_05_inst_adr                                           "0x0068"
#define GDI_CEC_COMPARE_OPCODE_05_inst                                               0x0068
#define GDI_CEC_COMPARE_OPCODE_05_Compare_opcode_05_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_05_Compare_opcode_05_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_05_Compare_opcode_05(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_05_Compare_opcode_05_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_05_get_Compare_opcode_05(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_06                                                    0x180075A4
#define GDI_CEC_COMPARE_OPCODE_06_reg_addr                                           "0x180075A4"
#define GDI_CEC_COMPARE_OPCODE_06_reg                                                0x180075A4
#define set_GDI_CEC_COMPARE_OPCODE_06_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_06_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_06_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_06_reg))
#define GDI_CEC_COMPARE_OPCODE_06_inst_adr                                           "0x0069"
#define GDI_CEC_COMPARE_OPCODE_06_inst                                               0x0069
#define GDI_CEC_COMPARE_OPCODE_06_Compare_opcode_06_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_06_Compare_opcode_06_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_06_Compare_opcode_06(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_06_Compare_opcode_06_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_06_get_Compare_opcode_06(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_07                                                    0x180075A8
#define GDI_CEC_COMPARE_OPCODE_07_reg_addr                                           "0x180075A8"
#define GDI_CEC_COMPARE_OPCODE_07_reg                                                0x180075A8
#define set_GDI_CEC_COMPARE_OPCODE_07_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_07_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_07_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_07_reg))
#define GDI_CEC_COMPARE_OPCODE_07_inst_adr                                           "0x006A"
#define GDI_CEC_COMPARE_OPCODE_07_inst                                               0x006A
#define GDI_CEC_COMPARE_OPCODE_07_Compare_opcode_07_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_07_Compare_opcode_07_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_07_Compare_opcode_07(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_07_Compare_opcode_07_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_07_get_Compare_opcode_07(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_08                                                    0x180075AC
#define GDI_CEC_COMPARE_OPCODE_08_reg_addr                                           "0x180075AC"
#define GDI_CEC_COMPARE_OPCODE_08_reg                                                0x180075AC
#define set_GDI_CEC_COMPARE_OPCODE_08_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_08_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_08_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_08_reg))
#define GDI_CEC_COMPARE_OPCODE_08_inst_adr                                           "0x006B"
#define GDI_CEC_COMPARE_OPCODE_08_inst                                               0x006B
#define GDI_CEC_COMPARE_OPCODE_08_Compare_opcode_08_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_08_Compare_opcode_08_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_08_Compare_opcode_08(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_08_Compare_opcode_08_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_08_get_Compare_opcode_08(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_09                                                    0x180075B0
#define GDI_CEC_COMPARE_OPCODE_09_reg_addr                                           "0x180075B0"
#define GDI_CEC_COMPARE_OPCODE_09_reg                                                0x180075B0
#define set_GDI_CEC_COMPARE_OPCODE_09_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_09_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_09_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_09_reg))
#define GDI_CEC_COMPARE_OPCODE_09_inst_adr                                           "0x006C"
#define GDI_CEC_COMPARE_OPCODE_09_inst                                               0x006C
#define GDI_CEC_COMPARE_OPCODE_09_Compare_opcode_09_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_09_Compare_opcode_09_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_09_Compare_opcode_09(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_09_Compare_opcode_09_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_09_get_Compare_opcode_09(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_10                                                    0x180075B4
#define GDI_CEC_COMPARE_OPCODE_10_reg_addr                                           "0x180075B4"
#define GDI_CEC_COMPARE_OPCODE_10_reg                                                0x180075B4
#define set_GDI_CEC_COMPARE_OPCODE_10_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_10_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_10_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_10_reg))
#define GDI_CEC_COMPARE_OPCODE_10_inst_adr                                           "0x006D"
#define GDI_CEC_COMPARE_OPCODE_10_inst                                               0x006D
#define GDI_CEC_COMPARE_OPCODE_10_Compare_opcode_10_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_10_Compare_opcode_10_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_10_Compare_opcode_10(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_10_Compare_opcode_10_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_10_get_Compare_opcode_10(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_11                                                    0x180075B8
#define GDI_CEC_COMPARE_OPCODE_11_reg_addr                                           "0x180075B8"
#define GDI_CEC_COMPARE_OPCODE_11_reg                                                0x180075B8
#define set_GDI_CEC_COMPARE_OPCODE_11_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_11_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_11_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_11_reg))
#define GDI_CEC_COMPARE_OPCODE_11_inst_adr                                           "0x006E"
#define GDI_CEC_COMPARE_OPCODE_11_inst                                               0x006E
#define GDI_CEC_COMPARE_OPCODE_11_Compare_opcode_11_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_11_Compare_opcode_11_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_11_Compare_opcode_11(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_11_Compare_opcode_11_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_11_get_Compare_opcode_11(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_12                                                    0x180075BC
#define GDI_CEC_COMPARE_OPCODE_12_reg_addr                                           "0x180075BC"
#define GDI_CEC_COMPARE_OPCODE_12_reg                                                0x180075BC
#define set_GDI_CEC_COMPARE_OPCODE_12_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_12_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_12_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_12_reg))
#define GDI_CEC_COMPARE_OPCODE_12_inst_adr                                           "0x006F"
#define GDI_CEC_COMPARE_OPCODE_12_inst                                               0x006F
#define GDI_CEC_COMPARE_OPCODE_12_Compare_opcode_12_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_12_Compare_opcode_12_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_12_Compare_opcode_12(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_12_Compare_opcode_12_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_12_get_Compare_opcode_12(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_13                                                    0x180075C0
#define GDI_CEC_COMPARE_OPCODE_13_reg_addr                                           "0x180075C0"
#define GDI_CEC_COMPARE_OPCODE_13_reg                                                0x180075C0
#define set_GDI_CEC_COMPARE_OPCODE_13_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_13_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_13_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_13_reg))
#define GDI_CEC_COMPARE_OPCODE_13_inst_adr                                           "0x0070"
#define GDI_CEC_COMPARE_OPCODE_13_inst                                               0x0070
#define GDI_CEC_COMPARE_OPCODE_13_Compare_opcode_13_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_13_Compare_opcode_13_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_13_Compare_opcode_13(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_13_Compare_opcode_13_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_13_get_Compare_opcode_13(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_14                                                    0x180075C4
#define GDI_CEC_COMPARE_OPCODE_14_reg_addr                                           "0x180075C4"
#define GDI_CEC_COMPARE_OPCODE_14_reg                                                0x180075C4
#define set_GDI_CEC_COMPARE_OPCODE_14_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_14_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_14_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_14_reg))
#define GDI_CEC_COMPARE_OPCODE_14_inst_adr                                           "0x0071"
#define GDI_CEC_COMPARE_OPCODE_14_inst                                               0x0071
#define GDI_CEC_COMPARE_OPCODE_14_Compare_opcode_14_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_14_Compare_opcode_14_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_14_Compare_opcode_14(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_14_Compare_opcode_14_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_14_get_Compare_opcode_14(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_COMPARE_OPCODE_15                                                    0x180075C8
#define GDI_CEC_COMPARE_OPCODE_15_reg_addr                                           "0x180075C8"
#define GDI_CEC_COMPARE_OPCODE_15_reg                                                0x180075C8
#define set_GDI_CEC_COMPARE_OPCODE_15_reg(data)   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_15_reg)=data)
#define get_GDI_CEC_COMPARE_OPCODE_15_reg   (*((volatile unsigned int*) GDI_CEC_COMPARE_OPCODE_15_reg))
#define GDI_CEC_COMPARE_OPCODE_15_inst_adr                                           "0x0072"
#define GDI_CEC_COMPARE_OPCODE_15_inst                                               0x0072
#define GDI_CEC_COMPARE_OPCODE_15_Compare_opcode_15_shift                            (0)
#define GDI_CEC_COMPARE_OPCODE_15_Compare_opcode_15_mask                             (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_15_Compare_opcode_15(data)                            (0x000000FF&((data)<<0))
#define GDI_CEC_COMPARE_OPCODE_15_Compare_opcode_15_src(data)                        ((0x000000FF&(data))>>0)
#define GDI_CEC_COMPARE_OPCODE_15_get_Compare_opcode_15(data)                        ((0x000000FF&(data))>>0)


#define GDI_CEC_OPCODE_ENABLE                                                        0x180075CC
#define GDI_CEC_OPCODE_ENABLE_reg_addr                                               "0x180075CC"
#define GDI_CEC_OPCODE_ENABLE_reg                                                    0x180075CC
#define set_GDI_CEC_OPCODE_ENABLE_reg(data)   (*((volatile unsigned int*) GDI_CEC_OPCODE_ENABLE_reg)=data)
#define get_GDI_CEC_OPCODE_ENABLE_reg   (*((volatile unsigned int*) GDI_CEC_OPCODE_ENABLE_reg))
#define GDI_CEC_OPCODE_ENABLE_inst_adr                                               "0x0073"
#define GDI_CEC_OPCODE_ENABLE_inst                                                   0x0073
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_15_shift                             (14)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_15_mask                              (0x00004000)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_15(data)                             (0x00004000&((data)<<14))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_15_src(data)                         ((0x00004000&(data))>>14)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_15(data)                         ((0x00004000&(data))>>14)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_14_shift                             (13)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_14_mask                              (0x00002000)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_14(data)                             (0x00002000&((data)<<13))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_14_src(data)                         ((0x00002000&(data))>>13)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_14(data)                         ((0x00002000&(data))>>13)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_13_shift                             (12)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_13_mask                              (0x00001000)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_13(data)                             (0x00001000&((data)<<12))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_13_src(data)                         ((0x00001000&(data))>>12)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_13(data)                         ((0x00001000&(data))>>12)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_12_shift                             (11)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_12_mask                              (0x00000800)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_12(data)                             (0x00000800&((data)<<11))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_12_src(data)                         ((0x00000800&(data))>>11)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_12(data)                         ((0x00000800&(data))>>11)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_11_shift                             (10)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_11_mask                              (0x00000400)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_11(data)                             (0x00000400&((data)<<10))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_11_src(data)                         ((0x00000400&(data))>>10)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_11(data)                         ((0x00000400&(data))>>10)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_10_shift                             (9)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_10_mask                              (0x00000200)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_10(data)                             (0x00000200&((data)<<9))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_10_src(data)                         ((0x00000200&(data))>>9)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_10(data)                         ((0x00000200&(data))>>9)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_09_shift                             (8)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_09_mask                              (0x00000100)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_09(data)                             (0x00000100&((data)<<8))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_09_src(data)                         ((0x00000100&(data))>>8)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_09(data)                         ((0x00000100&(data))>>8)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_08_shift                             (7)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_08_mask                              (0x00000080)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_08(data)                             (0x00000080&((data)<<7))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_08_src(data)                         ((0x00000080&(data))>>7)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_08(data)                         ((0x00000080&(data))>>7)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_07_shift                             (6)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_07_mask                              (0x00000040)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_07(data)                             (0x00000040&((data)<<6))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_07_src(data)                         ((0x00000040&(data))>>6)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_07(data)                         ((0x00000040&(data))>>6)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_06_shift                             (5)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_06_mask                              (0x00000020)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_06(data)                             (0x00000020&((data)<<5))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_06_src(data)                         ((0x00000020&(data))>>5)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_06(data)                         ((0x00000020&(data))>>5)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_05_shift                             (4)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_05_mask                              (0x00000010)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_05(data)                             (0x00000010&((data)<<4))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_05_src(data)                         ((0x00000010&(data))>>4)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_05(data)                         ((0x00000010&(data))>>4)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_04_shift                             (3)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_04_mask                              (0x00000008)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_04(data)                             (0x00000008&((data)<<3))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_04_src(data)                         ((0x00000008&(data))>>3)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_04(data)                         ((0x00000008&(data))>>3)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_03_shift                             (2)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_03_mask                              (0x00000004)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_03(data)                             (0x00000004&((data)<<2))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_03_src(data)                         ((0x00000004&(data))>>2)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_03(data)                         ((0x00000004&(data))>>2)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_02_shift                             (1)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_02_mask                              (0x00000002)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_02(data)                             (0x00000002&((data)<<1))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_02_src(data)                         ((0x00000002&(data))>>1)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_02(data)                         ((0x00000002&(data))>>1)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_01_shift                             (0)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_01_mask                              (0x00000001)
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_01(data)                             (0x00000001&((data)<<0))
#define GDI_CEC_OPCODE_ENABLE_EN_compare_opcode_01_src(data)                         ((0x00000001&(data))>>0)
#define GDI_CEC_OPCODE_ENABLE_get_EN_compare_opcode_01(data)                         ((0x00000001&(data))>>0)


#define GDI_POWER_SAVING_MODE                                                        0x180075D0
#define GDI_POWER_SAVING_MODE_reg_addr                                               "0x180075D0"
#define GDI_POWER_SAVING_MODE_reg                                                    0x180075D0
#define set_GDI_POWER_SAVING_MODE_reg(data)   (*((volatile unsigned int*) GDI_POWER_SAVING_MODE_reg)=data)
#define get_GDI_POWER_SAVING_MODE_reg   (*((volatile unsigned int*) GDI_POWER_SAVING_MODE_reg))
#define GDI_POWER_SAVING_MODE_inst_adr                                               "0x0074"
#define GDI_POWER_SAVING_MODE_inst                                                   0x0074
#define GDI_POWER_SAVING_MODE_Irq_pending_shift                                      (31)
#define GDI_POWER_SAVING_MODE_Irq_pending_mask                                       (0x80000000)
#define GDI_POWER_SAVING_MODE_Irq_pending(data)                                      (0x80000000&((data)<<31))
#define GDI_POWER_SAVING_MODE_Irq_pending_src(data)                                  ((0x80000000&(data))>>31)
#define GDI_POWER_SAVING_MODE_get_Irq_pending(data)                                  ((0x80000000&(data))>>31)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_01_shift                                (25)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_01_mask                                 (0x02000000)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_01(data)                                (0x02000000&((data)<<25))
#define GDI_POWER_SAVING_MODE_Cec_msg_status_01_src(data)                            ((0x02000000&(data))>>25)
#define GDI_POWER_SAVING_MODE_get_Cec_msg_status_01(data)                            ((0x02000000&(data))>>25)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_02_shift                                (24)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_02_mask                                 (0x01000000)
#define GDI_POWER_SAVING_MODE_Cec_msg_status_02(data)                                (0x01000000&((data)<<24))
#define GDI_POWER_SAVING_MODE_Cec_msg_status_02_src(data)                            ((0x01000000&(data))>>24)
#define GDI_POWER_SAVING_MODE_get_Cec_msg_status_02(data)                            ((0x01000000&(data))>>24)
#define GDI_POWER_SAVING_MODE_Irq_by_cec_receive_special_cmd_shift                   (8)
#define GDI_POWER_SAVING_MODE_Irq_by_cec_receive_special_cmd_mask                    (0x00000100)
#define GDI_POWER_SAVING_MODE_Irq_by_cec_receive_special_cmd(data)                   (0x00000100&((data)<<8))
#define GDI_POWER_SAVING_MODE_Irq_by_cec_receive_special_cmd_src(data)               ((0x00000100&(data))>>8)
#define GDI_POWER_SAVING_MODE_get_Irq_by_cec_receive_special_cmd(data)               ((0x00000100&(data))>>8)


#define CEC_ANALOG                                                                   0x180075E0
#define CEC_ANALOG_reg_addr                                                          "0x180075E0"
#define CEC_ANALOG_reg                                                               0x180075E0
#define set_CEC_ANALOG_reg(data)   (*((volatile unsigned int*) CEC_ANALOG_reg)=data)
#define get_CEC_ANALOG_reg   (*((volatile unsigned int*) CEC_ANALOG_reg))
#define CEC_ANALOG_inst_adr                                                          "0x0078"
#define CEC_ANALOG_inst                                                              0x0078
#define CEC_ANALOG_REG_CEC_RPU_EN_shift                                              (3)
#define CEC_ANALOG_REG_CEC_RPU_EN_mask                                               (0x00000008)
#define CEC_ANALOG_REG_CEC_RPU_EN(data)                                              (0x00000008&((data)<<3))
#define CEC_ANALOG_REG_CEC_RPU_EN_src(data)                                          ((0x00000008&(data))>>3)
#define CEC_ANALOG_get_REG_CEC_RPU_EN(data)                                          ((0x00000008&(data))>>3)
#define CEC_ANALOG_REG_CEC_RSEL_shift                                                (0)
#define CEC_ANALOG_REG_CEC_RSEL_mask                                                 (0x00000007)
#define CEC_ANALOG_REG_CEC_RSEL(data)                                                (0x00000007&((data)<<0))
#define CEC_ANALOG_REG_CEC_RSEL_src(data)                                            ((0x00000007&(data))>>0)
#define CEC_ANALOG_get_REG_CEC_RSEL(data)                                            ((0x00000007&(data))>>0)


#define DRM_ST                                                                       0x18007600
#define DRM_ST_reg_addr                                                              "0x18007600"
#define DRM_ST_reg                                                                   0x18007600
#define set_DRM_ST_reg(data)   (*((volatile unsigned int*) DRM_ST_reg)=data)
#define get_DRM_ST_reg   (*((volatile unsigned int*) DRM_ST_reg))
#define DRM_ST_inst_adr                                                              "0x0080"
#define DRM_ST_inst                                                                  0x0080
#define DRM_ST_SET_shift                                                             (0)
#define DRM_ST_SET_mask                                                              (0x00000001)
#define DRM_ST_SET(data)                                                             (0x00000001&((data)<<0))
#define DRM_ST_SET_src(data)                                                         ((0x00000001&(data))>>0)
#define DRM_ST_get_SET(data)                                                         ((0x00000001&(data))>>0)


#define DRM_SECURE_CLK                                                               0x18007604
#define DRM_SECURE_CLK_reg_addr                                                      "0x18007604"
#define DRM_SECURE_CLK_reg                                                           0x18007604
#define set_DRM_SECURE_CLK_reg(data)   (*((volatile unsigned int*) DRM_SECURE_CLK_reg)=data)
#define get_DRM_SECURE_CLK_reg   (*((volatile unsigned int*) DRM_SECURE_CLK_reg))
#define DRM_SECURE_CLK_inst_adr                                                      "0x0081"
#define DRM_SECURE_CLK_inst                                                          0x0081
#define DRM_SECURE_CLK_VAL_shift                                                     (0)
#define DRM_SECURE_CLK_VAL_mask                                                      (0xFFFFFFFF)
#define DRM_SECURE_CLK_VAL(data)                                                     (0xFFFFFFFF&((data)<<0))
#define DRM_SECURE_CLK_VAL_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define DRM_SECURE_CLK_get_VAL(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define DRM_ELAPSED                                                                  0x18007608
#define DRM_ELAPSED_reg_addr                                                         "0x18007608"
#define DRM_ELAPSED_reg                                                              0x18007608
#define set_DRM_ELAPSED_reg(data)   (*((volatile unsigned int*) DRM_ELAPSED_reg)=data)
#define get_DRM_ELAPSED_reg   (*((volatile unsigned int*) DRM_ELAPSED_reg))
#define DRM_ELAPSED_inst_adr                                                         "0x0082"
#define DRM_ELAPSED_inst                                                             0x0082
#define DRM_ELAPSED_VAL_shift                                                        (0)
#define DRM_ELAPSED_VAL_mask                                                         (0xFFFFFFFF)
#define DRM_ELAPSED_VAL(data)                                                        (0xFFFFFFFF&((data)<<0))
#define DRM_ELAPSED_VAL_src(data)                                                    ((0xFFFFFFFF&(data))>>0)
#define DRM_ELAPSED_get_VAL(data)                                                    ((0xFFFFFFFF&(data))>>0)


#define COLD_RST                                                                     0x1800760C
#define COLD_RST_reg_addr                                                            "0x1800760C"
#define COLD_RST_reg                                                                 0x1800760C
#define set_COLD_RST_reg(data)   (*((volatile unsigned int*) COLD_RST_reg)=data)
#define get_COLD_RST_reg   (*((volatile unsigned int*) COLD_RST_reg))
#define COLD_RST_inst_adr                                                            "0x0083"
#define COLD_RST_inst                                                                0x0083
#define COLD_RST_VAL_shift                                                           (0)
#define COLD_RST_VAL_mask                                                            (0xFFFFFFFF)
#define COLD_RST_VAL(data)                                                           (0xFFFFFFFF&((data)<<0))
#define COLD_RST_VAL_src(data)                                                       ((0xFFFFFFFF&(data))>>0)
#define COLD_RST_get_VAL(data)                                                       ((0xFFFFFFFF&(data))>>0)


#define COLD_RST1                                                                    0x18007610
#define COLD_RST1_reg_addr                                                           "0x18007610"
#define COLD_RST1_reg                                                                0x18007610
#define set_COLD_RST1_reg(data)   (*((volatile unsigned int*) COLD_RST1_reg)=data)
#define get_COLD_RST1_reg   (*((volatile unsigned int*) COLD_RST1_reg))
#define COLD_RST1_inst_adr                                                           "0x0084"
#define COLD_RST1_inst                                                               0x0084
#define COLD_RST1_VAL_shift                                                          (0)
#define COLD_RST1_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST1_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST1_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST1_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST2                                                                    0x18007614
#define COLD_RST2_reg_addr                                                           "0x18007614"
#define COLD_RST2_reg                                                                0x18007614
#define set_COLD_RST2_reg(data)   (*((volatile unsigned int*) COLD_RST2_reg)=data)
#define get_COLD_RST2_reg   (*((volatile unsigned int*) COLD_RST2_reg))
#define COLD_RST2_inst_adr                                                           "0x0085"
#define COLD_RST2_inst                                                               0x0085
#define COLD_RST2_VAL_shift                                                          (0)
#define COLD_RST2_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST2_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST2_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST2_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define DRM_CTRL                                                                     0x18007618
#define DRM_CTRL_reg_addr                                                            "0x18007618"
#define DRM_CTRL_reg                                                                 0x18007618
#define set_DRM_CTRL_reg(data)   (*((volatile unsigned int*) DRM_CTRL_reg)=data)
#define get_DRM_CTRL_reg   (*((volatile unsigned int*) DRM_CTRL_reg))
#define DRM_CTRL_inst_adr                                                            "0x0086"
#define DRM_CTRL_inst                                                                0x0086
#define DRM_CTRL_clk_div_en_shift                                                    (1)
#define DRM_CTRL_clk_div_en_mask                                                     (0x00000002)
#define DRM_CTRL_clk_div_en(data)                                                    (0x00000002&((data)<<1))
#define DRM_CTRL_clk_div_en_src(data)                                                ((0x00000002&(data))>>1)
#define DRM_CTRL_get_clk_div_en(data)                                                ((0x00000002&(data))>>1)
#define DRM_CTRL_clk_sel_shift                                                       (0)
#define DRM_CTRL_clk_sel_mask                                                        (0x00000001)
#define DRM_CTRL_clk_sel(data)                                                       (0x00000001&((data)<<0))
#define DRM_CTRL_clk_sel_src(data)                                                   ((0x00000001&(data))>>0)
#define DRM_CTRL_get_clk_sel(data)                                                   ((0x00000001&(data))>>0)


#define DRM_CLK_DIV                                                                  0x1800761c
#define DRM_CLK_DIV_reg_addr                                                         "0x1800761C"
#define DRM_CLK_DIV_reg                                                              0x1800761C
#define set_DRM_CLK_DIV_reg(data)   (*((volatile unsigned int*) DRM_CLK_DIV_reg)=data)
#define get_DRM_CLK_DIV_reg   (*((volatile unsigned int*) DRM_CLK_DIV_reg))
#define DRM_CLK_DIV_inst_adr                                                         "0x0087"
#define DRM_CLK_DIV_inst                                                             0x0087
#define DRM_CLK_DIV_init_shift                                                       (0)
#define DRM_CLK_DIV_init_mask                                                        (0xFFFFFFFF)
#define DRM_CLK_DIV_init(data)                                                       (0xFFFFFFFF&((data)<<0))
#define DRM_CLK_DIV_init_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define DRM_CLK_DIV_get_init(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define TC3TVR                                                                       0x18007620
#define TC3TVR_reg_addr                                                              "0x18007620"
#define TC3TVR_reg                                                                   0x18007620
#define set_TC3TVR_reg(data)   (*((volatile unsigned int*) TC3TVR_reg)=data)
#define get_TC3TVR_reg   (*((volatile unsigned int*) TC3TVR_reg))
#define TC3TVR_inst_adr                                                              "0x0088"
#define TC3TVR_inst                                                                  0x0088
#define TC3TVR_TC3TVR_shift                                                          (0)
#define TC3TVR_TC3TVR_mask                                                           (0xFFFFFFFF)
#define TC3TVR_TC3TVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC3TVR_TC3TVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC3TVR_get_TC3TVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC3CVR                                                                       0x18007624
#define TC3CVR_reg_addr                                                              "0x18007624"
#define TC3CVR_reg                                                                   0x18007624
#define set_TC3CVR_reg(data)   (*((volatile unsigned int*) TC3CVR_reg)=data)
#define get_TC3CVR_reg   (*((volatile unsigned int*) TC3CVR_reg))
#define TC3CVR_inst_adr                                                              "0x0089"
#define TC3CVR_inst                                                                  0x0089
#define TC3CVR_TC3CVR_shift                                                          (0)
#define TC3CVR_TC3CVR_mask                                                           (0xFFFFFFFF)
#define TC3CVR_TC3CVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC3CVR_TC3CVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC3CVR_get_TC3CVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC3CR                                                                        0x18007628
#define TC3CR_reg_addr                                                               "0x18007628"
#define TC3CR_reg                                                                    0x18007628
#define set_TC3CR_reg(data)   (*((volatile unsigned int*) TC3CR_reg)=data)
#define get_TC3CR_reg   (*((volatile unsigned int*) TC3CR_reg))
#define TC3CR_inst_adr                                                               "0x008A"
#define TC3CR_inst                                                                   0x008A
#define TC3CR_TC3En_shift                                                            (31)
#define TC3CR_TC3En_mask                                                             (0x80000000)
#define TC3CR_TC3En(data)                                                            (0x80000000&((data)<<31))
#define TC3CR_TC3En_src(data)                                                        ((0x80000000&(data))>>31)
#define TC3CR_get_TC3En(data)                                                        ((0x80000000&(data))>>31)
#define TC3CR_TC3Mode_shift                                                          (30)
#define TC3CR_TC3Mode_mask                                                           (0x40000000)
#define TC3CR_TC3Mode(data)                                                          (0x40000000&((data)<<30))
#define TC3CR_TC3Mode_src(data)                                                      ((0x40000000&(data))>>30)
#define TC3CR_get_TC3Mode(data)                                                      ((0x40000000&(data))>>30)
#define TC3CR_TC3Pause_shift                                                         (29)
#define TC3CR_TC3Pause_mask                                                          (0x20000000)
#define TC3CR_TC3Pause(data)                                                         (0x20000000&((data)<<29))
#define TC3CR_TC3Pause_src(data)                                                     ((0x20000000&(data))>>29)
#define TC3CR_get_TC3Pause(data)                                                     ((0x20000000&(data))>>29)
#define TC3CR_RvdA_shift                                                             (24)
#define TC3CR_RvdA_mask                                                              (0x1F000000)
#define TC3CR_RvdA(data)                                                             (0x1F000000&((data)<<24))
#define TC3CR_RvdA_src(data)                                                         ((0x1F000000&(data))>>24)
#define TC3CR_get_RvdA(data)                                                         ((0x1F000000&(data))>>24)


#define TC3ICR                                                                       0x1800762C
#define TC3ICR_reg_addr                                                              "0x1800762C"
#define TC3ICR_reg                                                                   0x1800762C
#define set_TC3ICR_reg(data)   (*((volatile unsigned int*) TC3ICR_reg)=data)
#define get_TC3ICR_reg   (*((volatile unsigned int*) TC3ICR_reg))
#define TC3ICR_inst_adr                                                              "0x008B"
#define TC3ICR_inst                                                                  0x008B
#define TC3ICR_TC3IE_shift                                                           (31)
#define TC3ICR_TC3IE_mask                                                            (0x80000000)
#define TC3ICR_TC3IE(data)                                                           (0x80000000&((data)<<31))
#define TC3ICR_TC3IE_src(data)                                                       ((0x80000000&(data))>>31)
#define TC3ICR_get_TC3IE(data)                                                       ((0x80000000&(data))>>31)


#define TC4TVR                                                                       0x18007630
#define TC4TVR_reg_addr                                                              "0x18007630"
#define TC4TVR_reg                                                                   0x18007630
#define set_TC4TVR_reg(data)   (*((volatile unsigned int*) TC4TVR_reg)=data)
#define get_TC4TVR_reg   (*((volatile unsigned int*) TC4TVR_reg))
#define TC4TVR_inst_adr                                                              "0x008C"
#define TC4TVR_inst                                                                  0x008C
#define TC4TVR_TC4TVR_shift                                                          (0)
#define TC4TVR_TC4TVR_mask                                                           (0xFFFFFFFF)
#define TC4TVR_TC4TVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC4TVR_TC4TVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC4TVR_get_TC4TVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC4CVR                                                                       0x18007634
#define TC4CVR_reg_addr                                                              "0x18007634"
#define TC4CVR_reg                                                                   0x18007634
#define set_TC4CVR_reg(data)   (*((volatile unsigned int*) TC4CVR_reg)=data)
#define get_TC4CVR_reg   (*((volatile unsigned int*) TC4CVR_reg))
#define TC4CVR_inst_adr                                                              "0x008D"
#define TC4CVR_inst                                                                  0x008D
#define TC4CVR_TC4CVR_shift                                                          (0)
#define TC4CVR_TC4CVR_mask                                                           (0xFFFFFFFF)
#define TC4CVR_TC4CVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC4CVR_TC4CVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC4CVR_get_TC4CVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC4CR                                                                        0x18007638
#define TC4CR_reg_addr                                                               "0x18007638"
#define TC4CR_reg                                                                    0x18007638
#define set_TC4CR_reg(data)   (*((volatile unsigned int*) TC4CR_reg)=data)
#define get_TC4CR_reg   (*((volatile unsigned int*) TC4CR_reg))
#define TC4CR_inst_adr                                                               "0x008E"
#define TC4CR_inst                                                                   0x008E
#define TC4CR_TC4En_shift                                                            (31)
#define TC4CR_TC4En_mask                                                             (0x80000000)
#define TC4CR_TC4En(data)                                                            (0x80000000&((data)<<31))
#define TC4CR_TC4En_src(data)                                                        ((0x80000000&(data))>>31)
#define TC4CR_get_TC4En(data)                                                        ((0x80000000&(data))>>31)
#define TC4CR_TC4Mode_shift                                                          (30)
#define TC4CR_TC4Mode_mask                                                           (0x40000000)
#define TC4CR_TC4Mode(data)                                                          (0x40000000&((data)<<30))
#define TC4CR_TC4Mode_src(data)                                                      ((0x40000000&(data))>>30)
#define TC4CR_get_TC4Mode(data)                                                      ((0x40000000&(data))>>30)
#define TC4CR_TC4Pause_shift                                                         (29)
#define TC4CR_TC4Pause_mask                                                          (0x20000000)
#define TC4CR_TC4Pause(data)                                                         (0x20000000&((data)<<29))
#define TC4CR_TC4Pause_src(data)                                                     ((0x20000000&(data))>>29)
#define TC4CR_get_TC4Pause(data)                                                     ((0x20000000&(data))>>29)
#define TC4CR_RvdA_shift                                                             (24)
#define TC4CR_RvdA_mask                                                              (0x1F000000)
#define TC4CR_RvdA(data)                                                             (0x1F000000&((data)<<24))
#define TC4CR_RvdA_src(data)                                                         ((0x1F000000&(data))>>24)
#define TC4CR_get_RvdA(data)                                                         ((0x1F000000&(data))>>24)


#define TC4ICR                                                                       0x1800763C
#define TC4ICR_reg_addr                                                              "0x1800763C"
#define TC4ICR_reg                                                                   0x1800763C
#define set_TC4ICR_reg(data)   (*((volatile unsigned int*) TC4ICR_reg)=data)
#define get_TC4ICR_reg   (*((volatile unsigned int*) TC4ICR_reg))
#define TC4ICR_inst_adr                                                              "0x008F"
#define TC4ICR_inst                                                                  0x008F
#define TC4ICR_TC4IE_shift                                                           (31)
#define TC4ICR_TC4IE_mask                                                            (0x80000000)
#define TC4ICR_TC4IE(data)                                                           (0x80000000&((data)<<31))
#define TC4ICR_TC4IE_src(data)                                                       ((0x80000000&(data))>>31)
#define TC4ICR_get_TC4IE(data)                                                       ((0x80000000&(data))>>31)


#define NORST_0                                                                      0x18007640
#define NORST_1                                                                      0x18007644
#define NORST_2                                                                      0x18007648
#define NORST_3                                                                      0x1800764C
#define NORST_4                                                                      0x18007650
#define NORST_5                                                                      0x18007654
#define NORST_6                                                                      0x18007658
#define NORST_7                                                                      0x1800765C
#define NORST_0_reg_addr                                                             "0x18007640"
#define NORST_1_reg_addr                                                             "0x18007644"
#define NORST_2_reg_addr                                                             "0x18007648"
#define NORST_3_reg_addr                                                             "0x1800764C"
#define NORST_4_reg_addr                                                             "0x18007650"
#define NORST_5_reg_addr                                                             "0x18007654"
#define NORST_6_reg_addr                                                             "0x18007658"
#define NORST_7_reg_addr                                                             "0x1800765C"
#define NORST_0_reg                                                                  0x18007640
#define NORST_1_reg                                                                  0x18007644
#define NORST_2_reg                                                                  0x18007648
#define NORST_3_reg                                                                  0x1800764C
#define NORST_4_reg                                                                  0x18007650
#define NORST_5_reg                                                                  0x18007654
#define NORST_6_reg                                                                  0x18007658
#define NORST_7_reg                                                                  0x1800765C
#define set_NORST_0_reg(data)   (*((volatile unsigned int*) NORST_0_reg)=data)
#define set_NORST_1_reg(data)   (*((volatile unsigned int*) NORST_1_reg)=data)
#define set_NORST_2_reg(data)   (*((volatile unsigned int*) NORST_2_reg)=data)
#define set_NORST_3_reg(data)   (*((volatile unsigned int*) NORST_3_reg)=data)
#define set_NORST_4_reg(data)   (*((volatile unsigned int*) NORST_4_reg)=data)
#define set_NORST_5_reg(data)   (*((volatile unsigned int*) NORST_5_reg)=data)
#define set_NORST_6_reg(data)   (*((volatile unsigned int*) NORST_6_reg)=data)
#define set_NORST_7_reg(data)   (*((volatile unsigned int*) NORST_7_reg)=data)
#define get_NORST_0_reg   (*((volatile unsigned int*) NORST_0_reg))
#define get_NORST_1_reg   (*((volatile unsigned int*) NORST_1_reg))
#define get_NORST_2_reg   (*((volatile unsigned int*) NORST_2_reg))
#define get_NORST_3_reg   (*((volatile unsigned int*) NORST_3_reg))
#define get_NORST_4_reg   (*((volatile unsigned int*) NORST_4_reg))
#define get_NORST_5_reg   (*((volatile unsigned int*) NORST_5_reg))
#define get_NORST_6_reg   (*((volatile unsigned int*) NORST_6_reg))
#define get_NORST_7_reg   (*((volatile unsigned int*) NORST_7_reg))
#define NORST_0_inst_adr                                                             "0x0090"
#define NORST_1_inst_adr                                                             "0x0091"
#define NORST_2_inst_adr                                                             "0x0092"
#define NORST_3_inst_adr                                                             "0x0093"
#define NORST_4_inst_adr                                                             "0x0094"
#define NORST_5_inst_adr                                                             "0x0095"
#define NORST_6_inst_adr                                                             "0x0096"
#define NORST_7_inst_adr                                                             "0x0097"
#define NORST_0_inst                                                                 0x0090
#define NORST_1_inst                                                                 0x0091
#define NORST_2_inst                                                                 0x0092
#define NORST_3_inst                                                                 0x0093
#define NORST_4_inst                                                                 0x0094
#define NORST_5_inst                                                                 0x0095
#define NORST_6_inst                                                                 0x0096
#define NORST_7_inst                                                                 0x0097
#define NORST_dat_shift                                                              (0)
#define NORST_dat_mask                                                               (0xFFFFFFFF)
#define NORST_dat(data)                                                              (0xFFFFFFFF&((data)<<0))
#define NORST_dat_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define NORST_get_dat(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define COLD_RST3                                                                    0x18007660
#define COLD_RST3_reg_addr                                                           "0x18007660"
#define COLD_RST3_reg                                                                0x18007660
#define set_COLD_RST3_reg(data)   (*((volatile unsigned int*) COLD_RST3_reg)=data)
#define get_COLD_RST3_reg   (*((volatile unsigned int*) COLD_RST3_reg))
#define COLD_RST3_inst_adr                                                           "0x0098"
#define COLD_RST3_inst                                                               0x0098
#define COLD_RST3_VAL_shift                                                          (0)
#define COLD_RST3_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST3_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST3_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST3_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST4                                                                    0x18007664
#define COLD_RST4_reg_addr                                                           "0x18007664"
#define COLD_RST4_reg                                                                0x18007664
#define set_COLD_RST4_reg(data)   (*((volatile unsigned int*) COLD_RST4_reg)=data)
#define get_COLD_RST4_reg   (*((volatile unsigned int*) COLD_RST4_reg))
#define COLD_RST4_inst_adr                                                           "0x0099"
#define COLD_RST4_inst                                                               0x0099
#define COLD_RST4_VAL_shift                                                          (0)
#define COLD_RST4_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST4_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST4_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST4_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST5                                                                    0x18007668
#define COLD_RST5_reg_addr                                                           "0x18007668"
#define COLD_RST5_reg                                                                0x18007668
#define set_COLD_RST5_reg(data)   (*((volatile unsigned int*) COLD_RST5_reg)=data)
#define get_COLD_RST5_reg   (*((volatile unsigned int*) COLD_RST5_reg))
#define COLD_RST5_inst_adr                                                           "0x009A"
#define COLD_RST5_inst                                                               0x009A
#define COLD_RST5_VAL_shift                                                          (0)
#define COLD_RST5_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST5_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST5_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST5_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST6                                                                    0x1800766C
#define COLD_RST6_reg_addr                                                           "0x1800766C"
#define COLD_RST6_reg                                                                0x1800766C
#define set_COLD_RST6_reg(data)   (*((volatile unsigned int*) COLD_RST6_reg)=data)
#define get_COLD_RST6_reg   (*((volatile unsigned int*) COLD_RST6_reg))
#define COLD_RST6_inst_adr                                                           "0x009B"
#define COLD_RST6_inst                                                               0x009B
#define COLD_RST6_VAL_shift                                                          (0)
#define COLD_RST6_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST6_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST6_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST6_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST7                                                                    0x18007670
#define COLD_RST7_reg_addr                                                           "0x18007670"
#define COLD_RST7_reg                                                                0x18007670
#define set_COLD_RST7_reg(data)   (*((volatile unsigned int*) COLD_RST7_reg)=data)
#define get_COLD_RST7_reg   (*((volatile unsigned int*) COLD_RST7_reg))
#define COLD_RST7_inst_adr                                                           "0x009C"
#define COLD_RST7_inst                                                               0x009C
#define COLD_RST7_VAL_shift                                                          (0)
#define COLD_RST7_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST7_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST7_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST7_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST8                                                                    0x18007674
#define COLD_RST8_reg_addr                                                           "0x18007674"
#define COLD_RST8_reg                                                                0x18007674
#define set_COLD_RST8_reg(data)   (*((volatile unsigned int*) COLD_RST8_reg)=data)
#define get_COLD_RST8_reg   (*((volatile unsigned int*) COLD_RST8_reg))
#define COLD_RST8_inst_adr                                                           "0x009D"
#define COLD_RST8_inst                                                               0x009D
#define COLD_RST8_VAL_shift                                                          (0)
#define COLD_RST8_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST8_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST8_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST8_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST9                                                                    0x18007678
#define COLD_RST9_reg_addr                                                           "0x18007678"
#define COLD_RST9_reg                                                                0x18007678
#define set_COLD_RST9_reg(data)   (*((volatile unsigned int*) COLD_RST9_reg)=data)
#define get_COLD_RST9_reg   (*((volatile unsigned int*) COLD_RST9_reg))
#define COLD_RST9_inst_adr                                                           "0x009E"
#define COLD_RST9_inst                                                               0x009E
#define COLD_RST9_VAL_shift                                                          (0)
#define COLD_RST9_VAL_mask                                                           (0xFFFFFFFF)
#define COLD_RST9_VAL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define COLD_RST9_VAL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define COLD_RST9_get_VAL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define COLD_RST10                                                                   0x1800767C
#define COLD_RST10_reg_addr                                                          "0x1800767C"
#define COLD_RST10_reg                                                               0x1800767C
#define set_COLD_RST10_reg(data)   (*((volatile unsigned int*) COLD_RST10_reg)=data)
#define get_COLD_RST10_reg   (*((volatile unsigned int*) COLD_RST10_reg))
#define COLD_RST10_inst_adr                                                          "0x009F"
#define COLD_RST10_inst                                                              0x009F
#define COLD_RST10_VAL_shift                                                         (0)
#define COLD_RST10_VAL_mask                                                          (0xFFFFFFFF)
#define COLD_RST10_VAL(data)                                                         (0xFFFFFFFF&((data)<<0))
#define COLD_RST10_VAL_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define COLD_RST10_get_VAL(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define ISO_TCWCR                                                                        0x18007680
#define ISO_TCWCR_reg_addr                                                               "0x18007680"
#define ISO_TCWCR_reg                                                                    0x18007680
#define ISO_set_TCWCR_reg(data)   (*((volatile unsigned int*) TCWCR_reg)=data)
#define ISO_get_TCWCR_reg   (*((volatile unsigned int*) TCWCR_reg))
#define ISO_TCWCR_inst_adr                                                               "0x00A0"
#define ISO_TCWCR_inst                                                                   0x00A0
#define ISO_TCWCR_WD_INT_EN_shift                                                        (31)
#define ISO_TCWCR_WD_INT_EN_mask                                                         (0x80000000)
#define ISO_TCWCR_WD_INT_EN(data)                                                        (0x80000000&((data)<<31))
#define ISO_TCWCR_WD_INT_EN_src(data)                                                    ((0x80000000&(data))>>31)
#define ISO_TCWCR_get_WD_INT_EN(data)                                                    ((0x80000000&(data))>>31)
#define ISO_TCWCR_NMIC_shift                                                             (12)
#define ISO_TCWCR_NMIC_mask                                                              (0x0000F000)
#define ISO_TCWCR_NMIC(data)                                                             (0x0000F000&((data)<<12))
#define ISO_TCWCR_NMIC_src(data)                                                         ((0x0000F000&(data))>>12)
#define ISO_TCWCR_get_NMIC(data)                                                         ((0x0000F000&(data))>>12)
#define ISO_TCWCR_WDC_shift                                                              (8)
#define ISO_TCWCR_WDC_mask                                                               (0x00000F00)
#define ISO_TCWCR_WDC(data)                                                              (0x00000F00&((data)<<8))
#define ISO_TCWCR_WDC_src(data)                                                          ((0x00000F00&(data))>>8)
#define ISO_TCWCR_get_WDC(data)                                                          ((0x00000F00&(data))>>8)
#define ISO_TCWCR_WDEN_shift                                                             (0)
#define ISO_TCWCR_WDEN_mask                                                              (0x000000FF)
#define ISO_TCWCR_WDEN(data)                                                             (0x000000FF&((data)<<0))
#define ISO_TCWCR_WDEN_src(data)                                                         ((0x000000FF&(data))>>0)
#define ISO_TCWCR_get_WDEN(data)                                                         ((0x000000FF&(data))>>0)


#define ISO_TCWTR                                                                        0x18007684
#define ISO_TCWTR_reg_addr                                                               "0x18007684"
#define ISO_TCWTR_reg                                                                    0x18007684
#define ISO_set_TCWTR_reg(data)   (*((volatile unsigned int*) TCWTR_reg)=data)
#define ISO_get_TCWTR_reg   (*((volatile unsigned int*) TCWTR_reg))
#define ISO_TCWTR_inst_adr                                                               "0x00A1"
#define ISO_TCWTR_inst                                                                   0x00A1
#define ISO_TCWTR_WDCLR_shift                                                            (0)
#define ISO_TCWTR_WDCLR_mask                                                             (0x00000001)
#define ISO_TCWTR_WDCLR(data)                                                            (0x00000001&((data)<<0))
#define ISO_TCWTR_WDCLR_src(data)                                                        ((0x00000001&(data))>>0)
#define ISO_TCWTR_get_WDCLR(data)                                                        ((0x00000001&(data))>>0)


#define ISO_TCWNMI                                                                       0x18007688
#define ISO_TCWNMI_reg_addr                                                              "0x18007688"
#define ISO_TCWNMI_reg                                                                   0x18007688
#define ISO_set_TCWNMI_reg(data)   (*((volatile unsigned int*) TCWNMI_reg)=data)
#define ISO_get_TCWNMI_reg   (*((volatile unsigned int*) TCWNMI_reg))
#define ISO_TCWNMI_inst_adr                                                              "0x00A2"
#define ISO_TCWNMI_inst                                                                  0x00A2
#define ISO_TCWNMI_SEL_shift                                                             (0)
#define ISO_TCWNMI_SEL_mask                                                              (0xFFFFFFFF)
#define ISO_TCWNMI_SEL(data)                                                             (0xFFFFFFFF&((data)<<0))
#define ISO_TCWNMI_SEL_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define ISO_TCWNMI_get_SEL(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define ISO_TCWOV                                                                        0x1800768C
#define ISO_TCWOV_reg_addr                                                               "0x1800768C"
#define ISO_TCWOV_reg                                                                    0x1800768C
#define ISO_set_TCWOV_reg(data)   (*((volatile unsigned int*) TCWOV_reg)=data)
#define ISO_get_TCWOV_reg   (*((volatile unsigned int*) TCWOV_reg))
#define ISO_TCWOV_inst_adr                                                               "0x00A3"
#define ISO_TCWOV_inst                                                                   0x00A3
#define ISO_TCWOV_SEL_shift                                                              (0)
#define ISO_TCWOV_SEL_mask                                                               (0xFFFFFFFF)
#define ISO_TCWOV_SEL(data)                                                              (0xFFFFFFFF&((data)<<0))
#define ISO_TCWOV_SEL_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define ISO_TCWOV_get_SEL(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define DRM_ST_SWC                                                                   0x18007690
#define DRM_ST_SWC_reg_addr                                                          "0x18007690"
#define DRM_ST_SWC_reg                                                               0x18007690
#define set_DRM_ST_SWC_reg(data)   (*((volatile unsigned int*) DRM_ST_SWC_reg)=data)
#define get_DRM_ST_SWC_reg   (*((volatile unsigned int*) DRM_ST_SWC_reg))
#define DRM_ST_SWC_inst_adr                                                          "0x00A4"
#define DRM_ST_SWC_inst                                                              0x00A4
#define DRM_ST_SWC_SET_shift                                                         (0)
#define DRM_ST_SWC_SET_mask                                                          (0x00000001)
#define DRM_ST_SWC_SET(data)                                                         (0x00000001&((data)<<0))
#define DRM_ST_SWC_SET_src(data)                                                     ((0x00000001&(data))>>0)
#define DRM_ST_SWC_get_SET(data)                                                     ((0x00000001&(data))>>0)


#define DRM_SECURE_CLK_SWC                                                           0x18007694
#define DRM_SECURE_CLK_SWC_reg_addr                                                  "0x18007694"
#define DRM_SECURE_CLK_SWC_reg                                                       0x18007694
#define set_DRM_SECURE_CLK_SWC_reg(data)   (*((volatile unsigned int*) DRM_SECURE_CLK_SWC_reg)=data)
#define get_DRM_SECURE_CLK_SWC_reg   (*((volatile unsigned int*) DRM_SECURE_CLK_SWC_reg))
#define DRM_SECURE_CLK_SWC_inst_adr                                                  "0x00A5"
#define DRM_SECURE_CLK_SWC_inst                                                      0x00A5
#define DRM_SECURE_CLK_SWC_VAL_shift                                                 (0)
#define DRM_SECURE_CLK_SWC_VAL_mask                                                  (0xFFFFFFFF)
#define DRM_SECURE_CLK_SWC_VAL(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DRM_SECURE_CLK_SWC_VAL_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DRM_SECURE_CLK_SWC_get_VAL(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DRM_ELAPSED_SWC                                                              0x18007698
#define DRM_ELAPSED_SWC_reg_addr                                                     "0x18007698"
#define DRM_ELAPSED_SWC_reg                                                          0x18007698
#define set_DRM_ELAPSED_SWC_reg(data)   (*((volatile unsigned int*) DRM_ELAPSED_SWC_reg)=data)
#define get_DRM_ELAPSED_SWC_reg   (*((volatile unsigned int*) DRM_ELAPSED_SWC_reg))
#define DRM_ELAPSED_SWC_inst_adr                                                     "0x00A6"
#define DRM_ELAPSED_SWC_inst                                                         0x00A6
#define DRM_ELAPSED_SWC_VAL_shift                                                    (0)
#define DRM_ELAPSED_SWC_VAL_mask                                                     (0xFFFFFFFF)
#define DRM_ELAPSED_SWC_VAL(data)                                                    (0xFFFFFFFF&((data)<<0))
#define DRM_ELAPSED_SWC_VAL_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define DRM_ELAPSED_SWC_get_VAL(data)                                                ((0xFFFFFFFF&(data))>>0)


#define DRM_CTRL_SWC                                                                 0x1800769C
#define DRM_CTRL_SWC_reg_addr                                                        "0x1800769C"
#define DRM_CTRL_SWC_reg                                                             0x1800769C
#define set_DRM_CTRL_SWC_reg(data)   (*((volatile unsigned int*) DRM_CTRL_SWC_reg)=data)
#define get_DRM_CTRL_SWC_reg   (*((volatile unsigned int*) DRM_CTRL_SWC_reg))
#define DRM_CTRL_SWC_inst_adr                                                        "0x00A7"
#define DRM_CTRL_SWC_inst                                                            0x00A7
#define DRM_CTRL_SWC_clk_div_en_shift                                                (1)
#define DRM_CTRL_SWC_clk_div_en_mask                                                 (0x00000002)
#define DRM_CTRL_SWC_clk_div_en(data)                                                (0x00000002&((data)<<1))
#define DRM_CTRL_SWC_clk_div_en_src(data)                                            ((0x00000002&(data))>>1)
#define DRM_CTRL_SWC_get_clk_div_en(data)                                            ((0x00000002&(data))>>1)
#define DRM_CTRL_SWC_clk_sel_shift                                                   (0)
#define DRM_CTRL_SWC_clk_sel_mask                                                    (0x00000001)
#define DRM_CTRL_SWC_clk_sel(data)                                                   (0x00000001&((data)<<0))
#define DRM_CTRL_SWC_clk_sel_src(data)                                               ((0x00000001&(data))>>0)
#define DRM_CTRL_SWC_get_clk_sel(data)                                               ((0x00000001&(data))>>0)


#define DRM_CLK_DIV_SWC                                                              0x180076A0
#define DRM_CLK_DIV_SWC_reg_addr                                                     "0x180076A0"
#define DRM_CLK_DIV_SWC_reg                                                          0x180076A0
#define set_DRM_CLK_DIV_SWC_reg(data)   (*((volatile unsigned int*) DRM_CLK_DIV_SWC_reg)=data)
#define get_DRM_CLK_DIV_SWC_reg   (*((volatile unsigned int*) DRM_CLK_DIV_SWC_reg))
#define DRM_CLK_DIV_SWC_inst_adr                                                     "0x00A8"
#define DRM_CLK_DIV_SWC_inst                                                         0x00A8
#define DRM_CLK_DIV_SWC_init_shift                                                   (0)
#define DRM_CLK_DIV_SWC_init_mask                                                    (0xFFFFFFFF)
#define DRM_CLK_DIV_SWC_init(data)                                                   (0xFFFFFFFF&((data)<<0))
#define DRM_CLK_DIV_SWC_init_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define DRM_CLK_DIV_SWC_get_init(data)                                               ((0xFFFFFFFF&(data))>>0)


#define COLD_RST_SWC                                                                 0x180076A4
#define COLD_RST_SWC_reg_addr                                                        "0x180076A4"
#define COLD_RST_SWC_reg                                                             0x180076A4
#define set_COLD_RST_SWC_reg(data)   (*((volatile unsigned int*) COLD_RST_SWC_reg)=data)
#define get_COLD_RST_SWC_reg   (*((volatile unsigned int*) COLD_RST_SWC_reg))
#define COLD_RST_SWC_inst_adr                                                        "0x00A9"
#define COLD_RST_SWC_inst                                                            0x00A9
#define COLD_RST_SWC_VAL_shift                                                       (0)
#define COLD_RST_SWC_VAL_mask                                                        (0xFFFFFFFF)
#define COLD_RST_SWC_VAL(data)                                                       (0xFFFFFFFF&((data)<<0))
#define COLD_RST_SWC_VAL_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define COLD_RST_SWC_get_VAL(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define COLD_RST1_SWC                                                                0x180076A8
#define COLD_RST1_SWC_reg_addr                                                       "0x180076A8"
#define COLD_RST1_SWC_reg                                                            0x180076A8
#define set_COLD_RST1_SWC_reg(data)   (*((volatile unsigned int*) COLD_RST1_SWC_reg)=data)
#define get_COLD_RST1_SWC_reg   (*((volatile unsigned int*) COLD_RST1_SWC_reg))
#define COLD_RST1_SWC_inst_adr                                                       "0x00AA"
#define COLD_RST1_SWC_inst                                                           0x00AA
#define COLD_RST1_SWC_VAL_shift                                                      (0)
#define COLD_RST1_SWC_VAL_mask                                                       (0xFFFFFFFF)
#define COLD_RST1_SWC_VAL(data)                                                      (0xFFFFFFFF&((data)<<0))
#define COLD_RST1_SWC_VAL_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define COLD_RST1_SWC_get_VAL(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define COLD_RST2_SWC                                                                0x180076AC
#define COLD_RST2_SWC_reg_addr                                                       "0x180076AC"
#define COLD_RST2_SWC_reg                                                            0x180076AC
#define set_COLD_RST2_SWC_reg(data)   (*((volatile unsigned int*) COLD_RST2_SWC_reg)=data)
#define get_COLD_RST2_SWC_reg   (*((volatile unsigned int*) COLD_RST2_SWC_reg))
#define COLD_RST2_SWC_inst_adr                                                       "0x00AB"
#define COLD_RST2_SWC_inst                                                           0x00AB
#define COLD_RST2_SWC_VAL_shift                                                      (0)
#define COLD_RST2_SWC_VAL_mask                                                       (0xFFFFFFFF)
#define COLD_RST2_SWC_VAL(data)                                                      (0xFFFFFFFF&((data)<<0))
#define COLD_RST2_SWC_VAL_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define COLD_RST2_SWC_get_VAL(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define COLD_RST3_SWC                                                                0x180076B0
#define COLD_RST3_SWC_reg_addr                                                       "0x180076B0"
#define COLD_RST3_SWC_reg                                                            0x180076B0
#define set_COLD_RST3_SWC_reg(data)   (*((volatile unsigned int*) COLD_RST3_SWC_reg)=data)
#define get_COLD_RST3_SWC_reg   (*((volatile unsigned int*) COLD_RST3_SWC_reg))
#define COLD_RST3_SWC_inst_adr                                                       "0x00AC"
#define COLD_RST3_SWC_inst                                                           0x00AC
#define COLD_RST3_SWC_VAL_shift                                                      (0)
#define COLD_RST3_SWC_VAL_mask                                                       (0xFFFFFFFF)
#define COLD_RST3_SWC_VAL(data)                                                      (0xFFFFFFFF&((data)<<0))
#define COLD_RST3_SWC_VAL_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define COLD_RST3_SWC_get_VAL(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define NORST_SWC                                                                    0x180076B4
#define NORST_SWC_reg_addr                                                           "0x180076B4"
#define NORST_SWC_reg                                                                0x180076B4
#define set_NORST_SWC_reg(data)   (*((volatile unsigned int*) NORST_SWC_reg)=data)
#define get_NORST_SWC_reg   (*((volatile unsigned int*) NORST_SWC_reg))
#define NORST_SWC_inst_adr                                                           "0x00AD"
#define NORST_SWC_inst                                                               0x00AD
#define NORST_SWC_dat_shift                                                          (0)
#define NORST_SWC_dat_mask                                                           (0xFFFFFFFF)
#define NORST_SWC_dat(data)                                                          (0xFFFFFFFF&((data)<<0))
#define NORST_SWC_dat_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define NORST_SWC_get_dat(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define NORST1_SWC                                                                   0x180076B8
#define NORST1_SWC_reg_addr                                                          "0x180076B8"
#define NORST1_SWC_reg                                                               0x180076B8
#define set_NORST1_SWC_reg(data)   (*((volatile unsigned int*) NORST1_SWC_reg)=data)
#define get_NORST1_SWC_reg   (*((volatile unsigned int*) NORST1_SWC_reg))
#define NORST1_SWC_inst_adr                                                          "0x00AE"
#define NORST1_SWC_inst                                                              0x00AE
#define NORST1_SWC_dat_shift                                                         (0)
#define NORST1_SWC_dat_mask                                                          (0xFFFFFFFF)
#define NORST1_SWC_dat(data)                                                         (0xFFFFFFFF&((data)<<0))
#define NORST1_SWC_dat_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define NORST1_SWC_get_dat(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define NORST2_SWC                                                                   0x180076BC
#define NORST2_SWC_reg_addr                                                          "0x180076BC"
#define NORST2_SWC_reg                                                               0x180076BC
#define set_NORST2_SWC_reg(data)   (*((volatile unsigned int*) NORST2_SWC_reg)=data)
#define get_NORST2_SWC_reg   (*((volatile unsigned int*) NORST2_SWC_reg))
#define NORST2_SWC_inst_adr                                                          "0x00AF"
#define NORST2_SWC_inst                                                              0x00AF
#define NORST2_SWC_dat_shift                                                         (0)
#define NORST2_SWC_dat_mask                                                          (0xFFFFFFFF)
#define NORST2_SWC_dat(data)                                                         (0xFFFFFFFF&((data)<<0))
#define NORST2_SWC_dat_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define NORST2_SWC_get_dat(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define TCWOV_RSTB_CNT                                                               0x180076C0
#define TCWOV_RSTB_CNT_reg_addr                                                      "0x180076C0"
#define TCWOV_RSTB_CNT_reg                                                           0x180076C0
#define set_TCWOV_RSTB_CNT_reg(data)   (*((volatile unsigned int*) TCWOV_RSTB_CNT_reg)=data)
#define get_TCWOV_RSTB_CNT_reg   (*((volatile unsigned int*) TCWOV_RSTB_CNT_reg))
#define TCWOV_RSTB_CNT_inst_adr                                                      "0x00B0"
#define TCWOV_RSTB_CNT_inst                                                          0x00B0
#define TCWOV_RSTB_CNT_SEL_shift                                                     (0)
#define TCWOV_RSTB_CNT_SEL_mask                                                      (0xFFFFFFFF)
#define TCWOV_RSTB_CNT_SEL(data)                                                     (0xFFFFFFFF&((data)<<0))
#define TCWOV_RSTB_CNT_SEL_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define TCWOV_RSTB_CNT_get_SEL(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define CPU_ST2V                                                                     0x18007738
#define CPU_ST2V_reg_addr                                                            "0x18007738"
#define CPU_ST2V_reg                                                                 0x18007738
#define set_CPU_ST2V_reg(data)   (*((volatile unsigned int*) CPU_ST2V_reg)=data)
#define get_CPU_ST2V_reg   (*((volatile unsigned int*) CPU_ST2V_reg))
#define CPU_ST2V_inst_adr                                                            "0x00CE"
#define CPU_ST2V_inst                                                                0x00CE
#define CPU_ST2V_scpu_boot_info_valid_shift                                          (0)
#define CPU_ST2V_scpu_boot_info_valid_mask                                           (0x00000001)
#define CPU_ST2V_scpu_boot_info_valid(data)                                          (0x00000001&((data)<<0))
#define CPU_ST2V_scpu_boot_info_valid_src(data)                                      ((0x00000001&(data))>>0)
#define CPU_ST2V_get_scpu_boot_info_valid(data)                                      ((0x00000001&(data))>>0)


#define CPU_ST2                                                                      0x1800773C
#define CPU_ST2_reg_addr                                                             "0x1800773C"
#define CPU_ST2_reg                                                                  0x1800773C
#define set_CPU_ST2_reg(data)   (*((volatile unsigned int*) CPU_ST2_reg)=data)
#define get_CPU_ST2_reg   (*((volatile unsigned int*) CPU_ST2_reg))
#define CPU_ST2_inst_adr                                                             "0x00CF"
#define CPU_ST2_inst                                                                 0x00CF
#define CPU_ST2_scpu_boot_info_shift                                                 (0)
#define CPU_ST2_scpu_boot_info_mask                                                  (0xFFFFFFFF)
#define CPU_ST2_scpu_boot_info(data)                                                 (0xFFFFFFFF&((data)<<0))
#define CPU_ST2_scpu_boot_info_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define CPU_ST2_get_scpu_boot_info(data)                                             ((0xFFFFFFFF&(data))>>0)


#define ACPU_DBG                                                                     0x18007740
#define ACPU_DBG_reg_addr                                                            "0x18007740"
#define ACPU_DBG_reg                                                                 0x18007740
#define set_ACPU_DBG_reg(data)   (*((volatile unsigned int*) ACPU_DBG_reg)=data)
#define get_ACPU_DBG_reg   (*((volatile unsigned int*) ACPU_DBG_reg))
#define ACPU_DBG_inst_adr                                                            "0x00D0"
#define ACPU_DBG_inst                                                                0x00D0
#define ACPU_DBG_write_enable3_shift                                                 (13)
#define ACPU_DBG_write_enable3_mask                                                  (0x00002000)
#define ACPU_DBG_write_enable3(data)                                                 (0x00002000&((data)<<13))
#define ACPU_DBG_write_enable3_src(data)                                             ((0x00002000&(data))>>13)
#define ACPU_DBG_get_write_enable3(data)                                             ((0x00002000&(data))>>13)
#define ACPU_DBG_sel1_shift                                                          (8)
#define ACPU_DBG_sel1_mask                                                           (0x00001F00)
#define ACPU_DBG_sel1(data)                                                          (0x00001F00&((data)<<8))
#define ACPU_DBG_sel1_src(data)                                                      ((0x00001F00&(data))>>8)
#define ACPU_DBG_get_sel1(data)                                                      ((0x00001F00&(data))>>8)
#define ACPU_DBG_write_enable2_shift                                                 (7)
#define ACPU_DBG_write_enable2_mask                                                  (0x00000080)
#define ACPU_DBG_write_enable2(data)                                                 (0x00000080&((data)<<7))
#define ACPU_DBG_write_enable2_src(data)                                             ((0x00000080&(data))>>7)
#define ACPU_DBG_get_write_enable2(data)                                             ((0x00000080&(data))>>7)
#define ACPU_DBG_sel0_shift                                                          (2)
#define ACPU_DBG_sel0_mask                                                           (0x0000007C)
#define ACPU_DBG_sel0(data)                                                          (0x0000007C&((data)<<2))
#define ACPU_DBG_sel0_src(data)                                                      ((0x0000007C&(data))>>2)
#define ACPU_DBG_get_sel0(data)                                                      ((0x0000007C&(data))>>2)
#define ACPU_DBG_write_enable1_shift                                                 (1)
#define ACPU_DBG_write_enable1_mask                                                  (0x00000002)
#define ACPU_DBG_write_enable1(data)                                                 (0x00000002&((data)<<1))
#define ACPU_DBG_write_enable1_src(data)                                             ((0x00000002&(data))>>1)
#define ACPU_DBG_get_write_enable1(data)                                             ((0x00000002&(data))>>1)
#define ACPU_DBG_enable_shift                                                        (0)
#define ACPU_DBG_enable_mask                                                         (0x00000001)
#define ACPU_DBG_enable(data)                                                        (0x00000001&((data)<<0))
#define ACPU_DBG_enable_src(data)                                                    ((0x00000001&(data))>>0)
#define ACPU_DBG_get_enable(data)                                                    ((0x00000001&(data))>>0)


#define ISO_ANLG                                                                         0x18007744
#define ISO_ANLG_reg_addr                                                                "0x18007744"
#define ISO_ANLG_reg                                                                     0x18007744
#define ISO_set_ANLG_reg(data)   (*((volatile unsigned int*) ANLG_reg)=data)
#define ISO_get_ANLG_reg   (*((volatile unsigned int*) ANLG_reg))
#define ISO_ANLG_inst_adr                                                                "0x00D1"
#define ISO_ANLG_inst                                                                    0x00D1
#define ISO_ANLG_analogy_mode_in_shift                                                   (0)
#define ISO_ANLG_analogy_mode_in_mask                                                    (0x00000001)
#define ISO_ANLG_analogy_mode_in(data)                                                   (0x00000001&((data)<<0))
#define ISO_ANLG_analogy_mode_in_src(data)                                               ((0x00000001&(data))>>0)
#define ISO_ANLG_get_analogy_mode_in(data)                                               ((0x00000001&(data))>>0)


#define U0RBR_THR_DLL                                                                0x18007800
#define U0RBR_THR_DLL_reg_addr                                                       "0x18007800"
#define U0RBR_THR_DLL_reg                                                            0x18007800
#define set_U0RBR_THR_DLL_reg(data)   (*((volatile unsigned int*) U0RBR_THR_DLL_reg)=data)
#define get_U0RBR_THR_DLL_reg   (*((volatile unsigned int*) U0RBR_THR_DLL_reg))
#define U0RBR_THR_DLL_inst_adr                                                       "0x0000"
#define U0RBR_THR_DLL_inst                                                           0x0000
#define U0RBR_THR_DLL_DLL_shift                                                      (0)
#define U0RBR_THR_DLL_DLL_mask                                                       (0x000000FF)
#define U0RBR_THR_DLL_DLL(data)                                                      (0x000000FF&((data)<<0))
#define U0RBR_THR_DLL_DLL_src(data)                                                  ((0x000000FF&(data))>>0)
#define U0RBR_THR_DLL_get_DLL(data)                                                  ((0x000000FF&(data))>>0)


#define U0IER_DLH                                                                    0x18007804
#define U0IER_DLH_reg_addr                                                           "0x18007804"
#define U0IER_DLH_reg                                                                0x18007804
#define set_U0IER_DLH_reg(data)   (*((volatile unsigned int*) U0IER_DLH_reg)=data)
#define get_U0IER_DLH_reg   (*((volatile unsigned int*) U0IER_DLH_reg))
#define U0IER_DLH_inst_adr                                                           "0x0001"
#define U0IER_DLH_inst                                                               0x0001
#define U0IER_DLH_DLH_shift                                                          (0)
#define U0IER_DLH_DLH_mask                                                           (0x000000FF)
#define U0IER_DLH_DLH(data)                                                          (0x000000FF&((data)<<0))
#define U0IER_DLH_DLH_src(data)                                                      ((0x000000FF&(data))>>0)
#define U0IER_DLH_get_DLH(data)                                                      ((0x000000FF&(data))>>0)


#define U0IIR_FCR                                                                    0x18007808
#define U0IIR_FCR_reg_addr                                                           "0x18007808"
#define U0IIR_FCR_reg                                                                0x18007808
#define set_U0IIR_FCR_reg(data)   (*((volatile unsigned int*) U0IIR_FCR_reg)=data)
#define get_U0IIR_FCR_reg   (*((volatile unsigned int*) U0IIR_FCR_reg))
#define U0IIR_FCR_inst_adr                                                           "0x0002"
#define U0IIR_FCR_inst                                                               0x0002
#define U0IIR_FCR_FIFO16_shift                                                       (6)
#define U0IIR_FCR_FIFO16_mask                                                        (0x000000C0)
#define U0IIR_FCR_FIFO16(data)                                                       (0x000000C0&((data)<<6))
#define U0IIR_FCR_FIFO16_src(data)                                                   ((0x000000C0&(data))>>6)
#define U0IIR_FCR_get_FIFO16(data)                                                   ((0x000000C0&(data))>>6)
#define U0IIR_FCR_IID_shift                                                          (0)
#define U0IIR_FCR_IID_mask                                                           (0x0000000F)
#define U0IIR_FCR_IID(data)                                                          (0x0000000F&((data)<<0))
#define U0IIR_FCR_IID_src(data)                                                      ((0x0000000F&(data))>>0)
#define U0IIR_FCR_get_IID(data)                                                      ((0x0000000F&(data))>>0)


#define U0LCR                                                                        0x1800780C
#define U0LCR_reg_addr                                                               "0x1800780C"
#define U0LCR_reg                                                                    0x1800780C
#define set_U0LCR_reg(data)   (*((volatile unsigned int*) U0LCR_reg)=data)
#define get_U0LCR_reg   (*((volatile unsigned int*) U0LCR_reg))
#define U0LCR_inst_adr                                                               "0x0003"
#define U0LCR_inst                                                                   0x0003
#define U0LCR_DLAB_shift                                                             (7)
#define U0LCR_DLAB_mask                                                              (0x00000080)
#define U0LCR_DLAB(data)                                                             (0x00000080&((data)<<7))
#define U0LCR_DLAB_src(data)                                                         ((0x00000080&(data))>>7)
#define U0LCR_get_DLAB(data)                                                         ((0x00000080&(data))>>7)
#define U0LCR_BRK_shift                                                              (6)
#define U0LCR_BRK_mask                                                               (0x00000040)
#define U0LCR_BRK(data)                                                              (0x00000040&((data)<<6))
#define U0LCR_BRK_src(data)                                                          ((0x00000040&(data))>>6)
#define U0LCR_get_BRK(data)                                                          ((0x00000040&(data))>>6)
#define U0LCR_EPS_shift                                                              (4)
#define U0LCR_EPS_mask                                                               (0x00000010)
#define U0LCR_EPS(data)                                                              (0x00000010&((data)<<4))
#define U0LCR_EPS_src(data)                                                          ((0x00000010&(data))>>4)
#define U0LCR_get_EPS(data)                                                          ((0x00000010&(data))>>4)
#define U0LCR_PEN_shift                                                              (3)
#define U0LCR_PEN_mask                                                               (0x00000008)
#define U0LCR_PEN(data)                                                              (0x00000008&((data)<<3))
#define U0LCR_PEN_src(data)                                                          ((0x00000008&(data))>>3)
#define U0LCR_get_PEN(data)                                                          ((0x00000008&(data))>>3)
#define U0LCR_STB_shift                                                              (2)
#define U0LCR_STB_mask                                                               (0x00000004)
#define U0LCR_STB(data)                                                              (0x00000004&((data)<<2))
#define U0LCR_STB_src(data)                                                          ((0x00000004&(data))>>2)
#define U0LCR_get_STB(data)                                                          ((0x00000004&(data))>>2)
#define U0LCR_WLS_shift                                                              (0)
#define U0LCR_WLS_mask                                                               (0x00000003)
#define U0LCR_WLS(data)                                                              (0x00000003&((data)<<0))
#define U0LCR_WLS_src(data)                                                          ((0x00000003&(data))>>0)
#define U0LCR_get_WLS(data)                                                          ((0x00000003&(data))>>0)


#define U0MCR                                                                        0x18007810
#define U0MCR_reg_addr                                                               "0x18007810"
#define U0MCR_reg                                                                    0x18007810
#define set_U0MCR_reg(data)   (*((volatile unsigned int*) U0MCR_reg)=data)
#define get_U0MCR_reg   (*((volatile unsigned int*) U0MCR_reg))
#define U0MCR_inst_adr                                                               "0x0004"
#define U0MCR_inst                                                                   0x0004
#define U0MCR_AFCE_shift                                                             (5)
#define U0MCR_AFCE_mask                                                              (0x00000020)
#define U0MCR_AFCE(data)                                                             (0x00000020&((data)<<5))
#define U0MCR_AFCE_src(data)                                                         ((0x00000020&(data))>>5)
#define U0MCR_get_AFCE(data)                                                         ((0x00000020&(data))>>5)
#define U0MCR_LOOP_shift                                                             (4)
#define U0MCR_LOOP_mask                                                              (0x00000010)
#define U0MCR_LOOP(data)                                                             (0x00000010&((data)<<4))
#define U0MCR_LOOP_src(data)                                                         ((0x00000010&(data))>>4)
#define U0MCR_get_LOOP(data)                                                         ((0x00000010&(data))>>4)
#define U0MCR_RTS_shift                                                              (1)
#define U0MCR_RTS_mask                                                               (0x00000002)
#define U0MCR_RTS(data)                                                              (0x00000002&((data)<<1))
#define U0MCR_RTS_src(data)                                                          ((0x00000002&(data))>>1)
#define U0MCR_get_RTS(data)                                                          ((0x00000002&(data))>>1)
#define U0MCR_DTR_shift                                                              (0)
#define U0MCR_DTR_mask                                                               (0x00000001)
#define U0MCR_DTR(data)                                                              (0x00000001&((data)<<0))
#define U0MCR_DTR_src(data)                                                          ((0x00000001&(data))>>0)
#define U0MCR_get_DTR(data)                                                          ((0x00000001&(data))>>0)


#define U0LSR                                                                        0x18007814
#define U0LSR_reg_addr                                                               "0x18007814"
#define U0LSR_reg                                                                    0x18007814
#define set_U0LSR_reg(data)   (*((volatile unsigned int*) U0LSR_reg)=data)
#define get_U0LSR_reg   (*((volatile unsigned int*) U0LSR_reg))
#define U0LSR_inst_adr                                                               "0x0005"
#define U0LSR_inst                                                                   0x0005
#define U0LSR_RFE_shift                                                              (7)
#define U0LSR_RFE_mask                                                               (0x00000080)
#define U0LSR_RFE(data)                                                              (0x00000080&((data)<<7))
#define U0LSR_RFE_src(data)                                                          ((0x00000080&(data))>>7)
#define U0LSR_get_RFE(data)                                                          ((0x00000080&(data))>>7)
#define U0LSR_TEMT_shift                                                             (6)
#define U0LSR_TEMT_mask                                                              (0x00000040)
#define U0LSR_TEMT(data)                                                             (0x00000040&((data)<<6))
#define U0LSR_TEMT_src(data)                                                         ((0x00000040&(data))>>6)
#define U0LSR_get_TEMT(data)                                                         ((0x00000040&(data))>>6)
#define U0LSR_THRE_shift                                                             (5)
#define U0LSR_THRE_mask                                                              (0x00000020)
#define U0LSR_THRE(data)                                                             (0x00000020&((data)<<5))
#define U0LSR_THRE_src(data)                                                         ((0x00000020&(data))>>5)
#define U0LSR_get_THRE(data)                                                         ((0x00000020&(data))>>5)
#define U0LSR_BI_shift                                                               (4)
#define U0LSR_BI_mask                                                                (0x00000010)
#define U0LSR_BI(data)                                                               (0x00000010&((data)<<4))
#define U0LSR_BI_src(data)                                                           ((0x00000010&(data))>>4)
#define U0LSR_get_BI(data)                                                           ((0x00000010&(data))>>4)
#define U0LSR_FE_shift                                                               (3)
#define U0LSR_FE_mask                                                                (0x00000008)
#define U0LSR_FE(data)                                                               (0x00000008&((data)<<3))
#define U0LSR_FE_src(data)                                                           ((0x00000008&(data))>>3)
#define U0LSR_get_FE(data)                                                           ((0x00000008&(data))>>3)
#define U0LSR_PE_shift                                                               (2)
#define U0LSR_PE_mask                                                                (0x00000004)
#define U0LSR_PE(data)                                                               (0x00000004&((data)<<2))
#define U0LSR_PE_src(data)                                                           ((0x00000004&(data))>>2)
#define U0LSR_get_PE(data)                                                           ((0x00000004&(data))>>2)
#define U0LSR_OE_shift                                                               (1)
#define U0LSR_OE_mask                                                                (0x00000002)
#define U0LSR_OE(data)                                                               (0x00000002&((data)<<1))
#define U0LSR_OE_src(data)                                                           ((0x00000002&(data))>>1)
#define U0LSR_get_OE(data)                                                           ((0x00000002&(data))>>1)
#define U0LSR_DR_shift                                                               (0)
#define U0LSR_DR_mask                                                                (0x00000001)
#define U0LSR_DR(data)                                                               (0x00000001&((data)<<0))
#define U0LSR_DR_src(data)                                                           ((0x00000001&(data))>>0)
#define U0LSR_get_DR(data)                                                           ((0x00000001&(data))>>0)


#define U0MSR                                                                        0x18007818
#define U0MSR_reg_addr                                                               "0x18007818"
#define U0MSR_reg                                                                    0x18007818
#define set_U0MSR_reg(data)   (*((volatile unsigned int*) U0MSR_reg)=data)
#define get_U0MSR_reg   (*((volatile unsigned int*) U0MSR_reg))
#define U0MSR_inst_adr                                                               "0x0006"
#define U0MSR_inst                                                                   0x0006
#define U0MSR_DCD_shift                                                              (7)
#define U0MSR_DCD_mask                                                               (0x00000080)
#define U0MSR_DCD(data)                                                              (0x00000080&((data)<<7))
#define U0MSR_DCD_src(data)                                                          ((0x00000080&(data))>>7)
#define U0MSR_get_DCD(data)                                                          ((0x00000080&(data))>>7)
#define U0MSR_RI_shift                                                               (6)
#define U0MSR_RI_mask                                                                (0x00000040)
#define U0MSR_RI(data)                                                               (0x00000040&((data)<<6))
#define U0MSR_RI_src(data)                                                           ((0x00000040&(data))>>6)
#define U0MSR_get_RI(data)                                                           ((0x00000040&(data))>>6)
#define U0MSR_DSR_shift                                                              (5)
#define U0MSR_DSR_mask                                                               (0x00000020)
#define U0MSR_DSR(data)                                                              (0x00000020&((data)<<5))
#define U0MSR_DSR_src(data)                                                          ((0x00000020&(data))>>5)
#define U0MSR_get_DSR(data)                                                          ((0x00000020&(data))>>5)
#define U0MSR_CTS_shift                                                              (4)
#define U0MSR_CTS_mask                                                               (0x00000010)
#define U0MSR_CTS(data)                                                              (0x00000010&((data)<<4))
#define U0MSR_CTS_src(data)                                                          ((0x00000010&(data))>>4)
#define U0MSR_get_CTS(data)                                                          ((0x00000010&(data))>>4)
#define U0MSR_DDCD_shift                                                             (3)
#define U0MSR_DDCD_mask                                                              (0x00000008)
#define U0MSR_DDCD(data)                                                             (0x00000008&((data)<<3))
#define U0MSR_DDCD_src(data)                                                         ((0x00000008&(data))>>3)
#define U0MSR_get_DDCD(data)                                                         ((0x00000008&(data))>>3)
#define U0MSR_TERI_shift                                                             (2)
#define U0MSR_TERI_mask                                                              (0x00000004)
#define U0MSR_TERI(data)                                                             (0x00000004&((data)<<2))
#define U0MSR_TERI_src(data)                                                         ((0x00000004&(data))>>2)
#define U0MSR_get_TERI(data)                                                         ((0x00000004&(data))>>2)
#define U0MSR_DDSR_shift                                                             (1)
#define U0MSR_DDSR_mask                                                              (0x00000002)
#define U0MSR_DDSR(data)                                                             (0x00000002&((data)<<1))
#define U0MSR_DDSR_src(data)                                                         ((0x00000002&(data))>>1)
#define U0MSR_get_DDSR(data)                                                         ((0x00000002&(data))>>1)
#define U0MSR_DCTS_shift                                                             (0)
#define U0MSR_DCTS_mask                                                              (0x00000001)
#define U0MSR_DCTS(data)                                                             (0x00000001&((data)<<0))
#define U0MSR_DCTS_src(data)                                                         ((0x00000001&(data))>>0)
#define U0MSR_get_DCTS(data)                                                         ((0x00000001&(data))>>0)


#define U0SCR                                                                        0x1800781C
#define U0SCR_reg_addr                                                               "0x1800781C"
#define U0SCR_reg                                                                    0x1800781C
#define set_U0SCR_reg(data)   (*((volatile unsigned int*) U0SCR_reg)=data)
#define get_U0SCR_reg   (*((volatile unsigned int*) U0SCR_reg))
#define U0SCR_inst_adr                                                               "0x0007"
#define U0SCR_inst                                                                   0x0007
#define U0SCR_SCR_shift                                                              (0)
#define U0SCR_SCR_mask                                                               (0x000000FF)
#define U0SCR_SCR(data)                                                              (0x000000FF&((data)<<0))
#define U0SCR_SCR_src(data)                                                          ((0x000000FF&(data))>>0)
#define U0SCR_get_SCR(data)                                                          ((0x000000FF&(data))>>0)


#define U0SRBR_0                                                                     0x18007830
#define U0SRBR_1                                                                     0x18007834
#define U0SRBR_2                                                                     0x18007838
#define U0SRBR_3                                                                     0x1800783C
#define U0SRBR_4                                                                     0x18007840
#define U0SRBR_5                                                                     0x18007844
#define U0SRBR_6                                                                     0x18007848
#define U0SRBR_7                                                                     0x1800784C
#define U0SRBR_8                                                                     0x18007850
#define U0SRBR_9                                                                     0x18007854
#define U0SRBR_10                                                                     0x18007858
#define U0SRBR_11                                                                     0x1800785C
#define U0SRBR_12                                                                     0x18007860
#define U0SRBR_13                                                                     0x18007864
#define U0SRBR_14                                                                     0x18007868
#define U0SRBR_15                                                                     0x1800786C
#define U0SRBR_0_reg_addr                                                            "0x18007830"
#define U0SRBR_1_reg_addr                                                            "0x18007834"
#define U0SRBR_2_reg_addr                                                            "0x18007838"
#define U0SRBR_3_reg_addr                                                            "0x1800783C"
#define U0SRBR_4_reg_addr                                                            "0x18007840"
#define U0SRBR_5_reg_addr                                                            "0x18007844"
#define U0SRBR_6_reg_addr                                                            "0x18007848"
#define U0SRBR_7_reg_addr                                                            "0x1800784C"
#define U0SRBR_8_reg_addr                                                            "0x18007850"
#define U0SRBR_9_reg_addr                                                            "0x18007854"
#define U0SRBR_10_reg_addr                                                            "0x18007858"
#define U0SRBR_11_reg_addr                                                            "0x1800785C"
#define U0SRBR_12_reg_addr                                                            "0x18007860"
#define U0SRBR_13_reg_addr                                                            "0x18007864"
#define U0SRBR_14_reg_addr                                                            "0x18007868"
#define U0SRBR_15_reg_addr                                                            "0x1800786C"
#define U0SRBR_0_reg                                                                 0x18007830
#define U0SRBR_1_reg                                                                 0x18007834
#define U0SRBR_2_reg                                                                 0x18007838
#define U0SRBR_3_reg                                                                 0x1800783C
#define U0SRBR_4_reg                                                                 0x18007840
#define U0SRBR_5_reg                                                                 0x18007844
#define U0SRBR_6_reg                                                                 0x18007848
#define U0SRBR_7_reg                                                                 0x1800784C
#define U0SRBR_8_reg                                                                 0x18007850
#define U0SRBR_9_reg                                                                 0x18007854
#define U0SRBR_10_reg                                                                 0x18007858
#define U0SRBR_11_reg                                                                 0x1800785C
#define U0SRBR_12_reg                                                                 0x18007860
#define U0SRBR_13_reg                                                                 0x18007864
#define U0SRBR_14_reg                                                                 0x18007868
#define U0SRBR_15_reg                                                                 0x1800786C
#define set_U0SRBR_0_reg(data)   (*((volatile unsigned int*) U0SRBR_0_reg)=data)
#define set_U0SRBR_1_reg(data)   (*((volatile unsigned int*) U0SRBR_1_reg)=data)
#define set_U0SRBR_2_reg(data)   (*((volatile unsigned int*) U0SRBR_2_reg)=data)
#define set_U0SRBR_3_reg(data)   (*((volatile unsigned int*) U0SRBR_3_reg)=data)
#define set_U0SRBR_4_reg(data)   (*((volatile unsigned int*) U0SRBR_4_reg)=data)
#define set_U0SRBR_5_reg(data)   (*((volatile unsigned int*) U0SRBR_5_reg)=data)
#define set_U0SRBR_6_reg(data)   (*((volatile unsigned int*) U0SRBR_6_reg)=data)
#define set_U0SRBR_7_reg(data)   (*((volatile unsigned int*) U0SRBR_7_reg)=data)
#define set_U0SRBR_8_reg(data)   (*((volatile unsigned int*) U0SRBR_8_reg)=data)
#define set_U0SRBR_9_reg(data)   (*((volatile unsigned int*) U0SRBR_9_reg)=data)
#define set_U0SRBR_10_reg(data)   (*((volatile unsigned int*) U0SRBR_10_reg)=data)
#define set_U0SRBR_11_reg(data)   (*((volatile unsigned int*) U0SRBR_11_reg)=data)
#define set_U0SRBR_12_reg(data)   (*((volatile unsigned int*) U0SRBR_12_reg)=data)
#define set_U0SRBR_13_reg(data)   (*((volatile unsigned int*) U0SRBR_13_reg)=data)
#define set_U0SRBR_14_reg(data)   (*((volatile unsigned int*) U0SRBR_14_reg)=data)
#define set_U0SRBR_15_reg(data)   (*((volatile unsigned int*) U0SRBR_15_reg)=data)
#define get_U0SRBR_0_reg   (*((volatile unsigned int*) U0SRBR_0_reg))
#define get_U0SRBR_1_reg   (*((volatile unsigned int*) U0SRBR_1_reg))
#define get_U0SRBR_2_reg   (*((volatile unsigned int*) U0SRBR_2_reg))
#define get_U0SRBR_3_reg   (*((volatile unsigned int*) U0SRBR_3_reg))
#define get_U0SRBR_4_reg   (*((volatile unsigned int*) U0SRBR_4_reg))
#define get_U0SRBR_5_reg   (*((volatile unsigned int*) U0SRBR_5_reg))
#define get_U0SRBR_6_reg   (*((volatile unsigned int*) U0SRBR_6_reg))
#define get_U0SRBR_7_reg   (*((volatile unsigned int*) U0SRBR_7_reg))
#define get_U0SRBR_8_reg   (*((volatile unsigned int*) U0SRBR_8_reg))
#define get_U0SRBR_9_reg   (*((volatile unsigned int*) U0SRBR_9_reg))
#define get_U0SRBR_10_reg   (*((volatile unsigned int*) U0SRBR_10_reg))
#define get_U0SRBR_11_reg   (*((volatile unsigned int*) U0SRBR_11_reg))
#define get_U0SRBR_12_reg   (*((volatile unsigned int*) U0SRBR_12_reg))
#define get_U0SRBR_13_reg   (*((volatile unsigned int*) U0SRBR_13_reg))
#define get_U0SRBR_14_reg   (*((volatile unsigned int*) U0SRBR_14_reg))
#define get_U0SRBR_15_reg   (*((volatile unsigned int*) U0SRBR_15_reg))
#define U0SRBR_0_inst_adr                                                            "0x000C"
#define U0SRBR_1_inst_adr                                                            "0x000D"
#define U0SRBR_2_inst_adr                                                            "0x000E"
#define U0SRBR_3_inst_adr                                                            "0x000F"
#define U0SRBR_4_inst_adr                                                            "0x0010"
#define U0SRBR_5_inst_adr                                                            "0x0011"
#define U0SRBR_6_inst_adr                                                            "0x0012"
#define U0SRBR_7_inst_adr                                                            "0x0013"
#define U0SRBR_8_inst_adr                                                            "0x0014"
#define U0SRBR_9_inst_adr                                                            "0x0015"
#define U0SRBR_10_inst_adr                                                            "0x0016"
#define U0SRBR_11_inst_adr                                                            "0x0017"
#define U0SRBR_12_inst_adr                                                            "0x0018"
#define U0SRBR_13_inst_adr                                                            "0x0019"
#define U0SRBR_14_inst_adr                                                            "0x001A"
#define U0SRBR_15_inst_adr                                                            "0x001B"
#define U0SRBR_0_inst                                                                0x000C
#define U0SRBR_1_inst                                                                0x000D
#define U0SRBR_2_inst                                                                0x000E
#define U0SRBR_3_inst                                                                0x000F
#define U0SRBR_4_inst                                                                0x0010
#define U0SRBR_5_inst                                                                0x0011
#define U0SRBR_6_inst                                                                0x0012
#define U0SRBR_7_inst                                                                0x0013
#define U0SRBR_8_inst                                                                0x0014
#define U0SRBR_9_inst                                                                0x0015
#define U0SRBR_10_inst                                                                0x0016
#define U0SRBR_11_inst                                                                0x0017
#define U0SRBR_12_inst                                                                0x0018
#define U0SRBR_13_inst                                                                0x0019
#define U0SRBR_14_inst                                                                0x001A
#define U0SRBR_15_inst                                                                0x001B
#define U0SRBR_RBD_shift                                                             (0)
#define U0SRBR_RBD_mask                                                              (0x000000FF)
#define U0SRBR_RBD(data)                                                             (0x000000FF&((data)<<0))
#define U0SRBR_RBD_src(data)                                                         ((0x000000FF&(data))>>0)
#define U0SRBR_get_RBD(data)                                                         ((0x000000FF&(data))>>0)


#define U0FAR                                                                        0x18007870
#define U0FAR_reg_addr                                                               "0x18007870"
#define U0FAR_reg                                                                    0x18007870
#define set_U0FAR_reg(data)   (*((volatile unsigned int*) U0FAR_reg)=data)
#define get_U0FAR_reg   (*((volatile unsigned int*) U0FAR_reg))
#define U0FAR_inst_adr                                                               "0x001C"
#define U0FAR_inst                                                                   0x001C
#define U0FAR_FAR_shift                                                              (0)
#define U0FAR_FAR_mask                                                               (0x00000001)
#define U0FAR_FAR(data)                                                              (0x00000001&((data)<<0))
#define U0FAR_FAR_src(data)                                                          ((0x00000001&(data))>>0)
#define U0FAR_get_FAR(data)                                                          ((0x00000001&(data))>>0)


#define U0TFR                                                                        0x18007874
#define U0TFR_reg_addr                                                               "0x18007874"
#define U0TFR_reg                                                                    0x18007874
#define set_U0TFR_reg(data)   (*((volatile unsigned int*) U0TFR_reg)=data)
#define get_U0TFR_reg   (*((volatile unsigned int*) U0TFR_reg))
#define U0TFR_inst_adr                                                               "0x001D"
#define U0TFR_inst                                                                   0x001D
#define U0TFR_FAR_shift                                                              (0)
#define U0TFR_FAR_mask                                                               (0x000000FF)
#define U0TFR_FAR(data)                                                              (0x000000FF&((data)<<0))
#define U0TFR_FAR_src(data)                                                          ((0x000000FF&(data))>>0)
#define U0TFR_get_FAR(data)                                                          ((0x000000FF&(data))>>0)


#define U0RFW                                                                        0x18007878
#define U0RFW_reg_addr                                                               "0x18007878"
#define U0RFW_reg                                                                    0x18007878
#define set_U0RFW_reg(data)   (*((volatile unsigned int*) U0RFW_reg)=data)
#define get_U0RFW_reg   (*((volatile unsigned int*) U0RFW_reg))
#define U0RFW_inst_adr                                                               "0x001E"
#define U0RFW_inst                                                                   0x001E
#define U0RFW_RFFE_shift                                                             (9)
#define U0RFW_RFFE_mask                                                              (0x00000200)
#define U0RFW_RFFE(data)                                                             (0x00000200&((data)<<9))
#define U0RFW_RFFE_src(data)                                                         ((0x00000200&(data))>>9)
#define U0RFW_get_RFFE(data)                                                         ((0x00000200&(data))>>9)
#define U0RFW_RFPF_shift                                                             (8)
#define U0RFW_RFPF_mask                                                              (0x00000100)
#define U0RFW_RFPF(data)                                                             (0x00000100&((data)<<8))
#define U0RFW_RFPF_src(data)                                                         ((0x00000100&(data))>>8)
#define U0RFW_get_RFPF(data)                                                         ((0x00000100&(data))>>8)
#define U0RFW_RFWD_shift                                                             (0)
#define U0RFW_RFWD_mask                                                              (0x000000FF)
#define U0RFW_RFWD(data)                                                             (0x000000FF&((data)<<0))
#define U0RFW_RFWD_src(data)                                                         ((0x000000FF&(data))>>0)
#define U0RFW_get_RFWD(data)                                                         ((0x000000FF&(data))>>0)


#define U0USR                                                                        0x1800787C
#define U0USR_reg_addr                                                               "0x1800787C"
#define U0USR_reg                                                                    0x1800787C
#define set_U0USR_reg(data)   (*((volatile unsigned int*) U0USR_reg)=data)
#define get_U0USR_reg   (*((volatile unsigned int*) U0USR_reg))
#define U0USR_inst_adr                                                               "0x001F"
#define U0USR_inst                                                                   0x001F
#define U0USR_RFF_shift                                                              (4)
#define U0USR_RFF_mask                                                               (0x00000010)
#define U0USR_RFF(data)                                                              (0x00000010&((data)<<4))
#define U0USR_RFF_src(data)                                                          ((0x00000010&(data))>>4)
#define U0USR_get_RFF(data)                                                          ((0x00000010&(data))>>4)
#define U0USR_RFNE_shift                                                             (3)
#define U0USR_RFNE_mask                                                              (0x00000008)
#define U0USR_RFNE(data)                                                             (0x00000008&((data)<<3))
#define U0USR_RFNE_src(data)                                                         ((0x00000008&(data))>>3)
#define U0USR_get_RFNE(data)                                                         ((0x00000008&(data))>>3)
#define U0USR_TFE_shift                                                              (2)
#define U0USR_TFE_mask                                                               (0x00000004)
#define U0USR_TFE(data)                                                              (0x00000004&((data)<<2))
#define U0USR_TFE_src(data)                                                          ((0x00000004&(data))>>2)
#define U0USR_get_TFE(data)                                                          ((0x00000004&(data))>>2)
#define U0USR_TFNF_shift                                                             (1)
#define U0USR_TFNF_mask                                                              (0x00000002)
#define U0USR_TFNF(data)                                                             (0x00000002&((data)<<1))
#define U0USR_TFNF_src(data)                                                         ((0x00000002&(data))>>1)
#define U0USR_get_TFNF(data)                                                         ((0x00000002&(data))>>1)
#define U0USR_BUSY_shift                                                             (0)
#define U0USR_BUSY_mask                                                              (0x00000001)
#define U0USR_BUSY(data)                                                             (0x00000001&((data)<<0))
#define U0USR_BUSY_src(data)                                                         ((0x00000001&(data))>>0)
#define U0USR_get_BUSY(data)                                                         ((0x00000001&(data))>>0)


#define U0TFL                                                                        0x18007880
#define U0TFL_reg_addr                                                               "0x18007880"
#define U0TFL_reg                                                                    0x18007880
#define set_U0TFL_reg(data)   (*((volatile unsigned int*) U0TFL_reg)=data)
#define get_U0TFL_reg   (*((volatile unsigned int*) U0TFL_reg))
#define U0TFL_inst_adr                                                               "0x0020"
#define U0TFL_inst                                                                   0x0020
#define U0TFL_TFL_shift                                                              (0)
#define U0TFL_TFL_mask                                                               (0x000000FF)
#define U0TFL_TFL(data)                                                              (0x000000FF&((data)<<0))
#define U0TFL_TFL_src(data)                                                          ((0x000000FF&(data))>>0)
#define U0TFL_get_TFL(data)                                                          ((0x000000FF&(data))>>0)


#define U0RFL                                                                        0x18007884
#define U0RFL_reg_addr                                                               "0x18007884"
#define U0RFL_reg                                                                    0x18007884
#define set_U0RFL_reg(data)   (*((volatile unsigned int*) U0RFL_reg)=data)
#define get_U0RFL_reg   (*((volatile unsigned int*) U0RFL_reg))
#define U0RFL_inst_adr                                                               "0x0021"
#define U0RFL_inst                                                                   0x0021
#define U0RFL_RFL_shift                                                              (0)
#define U0RFL_RFL_mask                                                               (0x000000FF)
#define U0RFL_RFL(data)                                                              (0x000000FF&((data)<<0))
#define U0RFL_RFL_src(data)                                                          ((0x000000FF&(data))>>0)
#define U0RFL_get_RFL(data)                                                          ((0x000000FF&(data))>>0)


#define U0SRR                                                                        0x18007888
#define U0SRR_reg_addr                                                               "0x18007888"
#define U0SRR_reg                                                                    0x18007888
#define set_U0SRR_reg(data)   (*((volatile unsigned int*) U0SRR_reg)=data)
#define get_U0SRR_reg   (*((volatile unsigned int*) U0SRR_reg))
#define U0SRR_inst_adr                                                               "0x0022"
#define U0SRR_inst                                                                   0x0022
#define U0SRR_XFR_shift                                                              (2)
#define U0SRR_XFR_mask                                                               (0x00000004)
#define U0SRR_XFR(data)                                                              (0x00000004&((data)<<2))
#define U0SRR_XFR_src(data)                                                          ((0x00000004&(data))>>2)
#define U0SRR_get_XFR(data)                                                          ((0x00000004&(data))>>2)
#define U0SRR_RFR_shift                                                              (1)
#define U0SRR_RFR_mask                                                               (0x00000002)
#define U0SRR_RFR(data)                                                              (0x00000002&((data)<<1))
#define U0SRR_RFR_src(data)                                                          ((0x00000002&(data))>>1)
#define U0SRR_get_RFR(data)                                                          ((0x00000002&(data))>>1)
#define U0SRR_UR_shift                                                               (0)
#define U0SRR_UR_mask                                                                (0x00000001)
#define U0SRR_UR(data)                                                               (0x00000001&((data)<<0))
#define U0SRR_UR_src(data)                                                           ((0x00000001&(data))>>0)
#define U0SRR_get_UR(data)                                                           ((0x00000001&(data))>>0)


#define U0SBCR                                                                       0x18007890
#define U0SBCR_reg_addr                                                              "0x18007890"
#define U0SBCR_reg                                                                   0x18007890
#define set_U0SBCR_reg(data)   (*((volatile unsigned int*) U0SBCR_reg)=data)
#define get_U0SBCR_reg   (*((volatile unsigned int*) U0SBCR_reg))
#define U0SBCR_inst_adr                                                              "0x0024"
#define U0SBCR_inst                                                                  0x0024
#define U0SBCR_SBCR_shift                                                            (0)
#define U0SBCR_SBCR_mask                                                             (0x00000001)
#define U0SBCR_SBCR(data)                                                            (0x00000001&((data)<<0))
#define U0SBCR_SBCR_src(data)                                                        ((0x00000001&(data))>>0)
#define U0SBCR_get_SBCR(data)                                                        ((0x00000001&(data))>>0)


#define U0SDMAM                                                                      0x18007894
#define U0SDMAM_reg_addr                                                             "0x18007894"
#define U0SDMAM_reg                                                                  0x18007894
#define set_U0SDMAM_reg(data)   (*((volatile unsigned int*) U0SDMAM_reg)=data)
#define get_U0SDMAM_reg   (*((volatile unsigned int*) U0SDMAM_reg))
#define U0SDMAM_inst_adr                                                             "0x0025"
#define U0SDMAM_inst                                                                 0x0025
#define U0SDMAM_SDMAM_shift                                                          (0)
#define U0SDMAM_SDMAM_mask                                                           (0x00000001)
#define U0SDMAM_SDMAM(data)                                                          (0x00000001&((data)<<0))
#define U0SDMAM_SDMAM_src(data)                                                      ((0x00000001&(data))>>0)
#define U0SDMAM_get_SDMAM(data)                                                      ((0x00000001&(data))>>0)


#define U0SFE                                                                        0x18007898
#define U0SFE_reg_addr                                                               "0x18007898"
#define U0SFE_reg                                                                    0x18007898
#define set_U0SFE_reg(data)   (*((volatile unsigned int*) U0SFE_reg)=data)
#define get_U0SFE_reg   (*((volatile unsigned int*) U0SFE_reg))
#define U0SFE_inst_adr                                                               "0x0026"
#define U0SFE_inst                                                                   0x0026
#define U0SFE_SFE_shift                                                              (0)
#define U0SFE_SFE_mask                                                               (0x00000001)
#define U0SFE_SFE(data)                                                              (0x00000001&((data)<<0))
#define U0SFE_SFE_src(data)                                                          ((0x00000001&(data))>>0)
#define U0SFE_get_SFE(data)                                                          ((0x00000001&(data))>>0)


#define U0SRT                                                                        0x1800789C
#define U0SRT_reg_addr                                                               "0x1800789C"
#define U0SRT_reg                                                                    0x1800789C
#define set_U0SRT_reg(data)   (*((volatile unsigned int*) U0SRT_reg)=data)
#define get_U0SRT_reg   (*((volatile unsigned int*) U0SRT_reg))
#define U0SRT_inst_adr                                                               "0x0027"
#define U0SRT_inst                                                                   0x0027
#define U0SRT_SRT_shift                                                              (0)
#define U0SRT_SRT_mask                                                               (0x00000003)
#define U0SRT_SRT(data)                                                              (0x00000003&((data)<<0))
#define U0SRT_SRT_src(data)                                                          ((0x00000003&(data))>>0)
#define U0SRT_get_SRT(data)                                                          ((0x00000003&(data))>>0)


#define U0STET                                                                       0x180078A0
#define U0STET_reg_addr                                                              "0x180078A0"
#define U0STET_reg                                                                   0x180078A0
#define set_U0STET_reg(data)   (*((volatile unsigned int*) U0STET_reg)=data)
#define get_U0STET_reg   (*((volatile unsigned int*) U0STET_reg))
#define U0STET_inst_adr                                                              "0x0028"
#define U0STET_inst                                                                  0x0028
#define U0STET_STET_shift                                                            (0)
#define U0STET_STET_mask                                                             (0x00000003)
#define U0STET_STET(data)                                                            (0x00000003&((data)<<0))
#define U0STET_STET_src(data)                                                        ((0x00000003&(data))>>0)
#define U0STET_get_STET(data)                                                        ((0x00000003&(data))>>0)


#define U0HTX                                                                        0x180078A4
#define U0HTX_reg_addr                                                               "0x180078A4"
#define U0HTX_reg                                                                    0x180078A4
#define set_U0HTX_reg(data)   (*((volatile unsigned int*) U0HTX_reg)=data)
#define get_U0HTX_reg   (*((volatile unsigned int*) U0HTX_reg))
#define U0HTX_inst_adr                                                               "0x0029"
#define U0HTX_inst                                                                   0x0029
#define U0HTX_HTX_shift                                                              (0)
#define U0HTX_HTX_mask                                                               (0x00000001)
#define U0HTX_HTX(data)                                                              (0x00000001&((data)<<0))
#define U0HTX_HTX_src(data)                                                          ((0x00000001&(data))>>0)
#define U0HTX_get_HTX(data)                                                          ((0x00000001&(data))>>0)


#define U0DMASA                                                                      0x180078A8
#define U0DMASA_reg_addr                                                             "0x180078A8"
#define U0DMASA_reg                                                                  0x180078A8
#define set_U0DMASA_reg(data)   (*((volatile unsigned int*) U0DMASA_reg)=data)
#define get_U0DMASA_reg   (*((volatile unsigned int*) U0DMASA_reg))
#define U0DMASA_inst_adr                                                             "0x002A"
#define U0DMASA_inst                                                                 0x002A
#define U0DMASA_DMASA_shift                                                          (0)
#define U0DMASA_DMASA_mask                                                           (0x00000001)
#define U0DMASA_DMASA(data)                                                          (0x00000001&((data)<<0))
#define U0DMASA_DMASA_src(data)                                                      ((0x00000001&(data))>>0)
#define U0DMASA_get_DMASA(data)                                                      ((0x00000001&(data))>>0)


#define U0CPR                                                                        0x180078F4
#define U0CPR_reg_addr                                                               "0x180078F4"
#define U0CPR_reg                                                                    0x180078F4
#define set_U0CPR_reg(data)   (*((volatile unsigned int*) U0CPR_reg)=data)
#define get_U0CPR_reg   (*((volatile unsigned int*) U0CPR_reg))
#define U0CPR_inst_adr                                                               "0x003D"
#define U0CPR_inst                                                                   0x003D
#define U0CPR_FIFO_MODE_shift                                                        (16)
#define U0CPR_FIFO_MODE_mask                                                         (0x00FF0000)
#define U0CPR_FIFO_MODE(data)                                                        (0x00FF0000&((data)<<16))
#define U0CPR_FIFO_MODE_src(data)                                                    ((0x00FF0000&(data))>>16)
#define U0CPR_get_FIFO_MODE(data)                                                    ((0x00FF0000&(data))>>16)
#define U0CPR_DMA_EXTRA_shift                                                        (13)
#define U0CPR_DMA_EXTRA_mask                                                         (0x00002000)
#define U0CPR_DMA_EXTRA(data)                                                        (0x00002000&((data)<<13))
#define U0CPR_DMA_EXTRA_src(data)                                                    ((0x00002000&(data))>>13)
#define U0CPR_get_DMA_EXTRA(data)                                                    ((0x00002000&(data))>>13)
#define U0CPR_UART_ADD_ENCODED_PARAMS_shift                                          (12)
#define U0CPR_UART_ADD_ENCODED_PARAMS_mask                                           (0x00001000)
#define U0CPR_UART_ADD_ENCODED_PARAMS(data)                                          (0x00001000&((data)<<12))
#define U0CPR_UART_ADD_ENCODED_PARAMS_src(data)                                      ((0x00001000&(data))>>12)
#define U0CPR_get_UART_ADD_ENCODED_PARAMS(data)                                      ((0x00001000&(data))>>12)
#define U0CPR_SHADOW_shift                                                           (11)
#define U0CPR_SHADOW_mask                                                            (0x00000800)
#define U0CPR_SHADOW(data)                                                           (0x00000800&((data)<<11))
#define U0CPR_SHADOW_src(data)                                                       ((0x00000800&(data))>>11)
#define U0CPR_get_SHADOW(data)                                                       ((0x00000800&(data))>>11)
#define U0CPR_FIFO_STAT_shift                                                        (10)
#define U0CPR_FIFO_STAT_mask                                                         (0x00000400)
#define U0CPR_FIFO_STAT(data)                                                        (0x00000400&((data)<<10))
#define U0CPR_FIFO_STAT_src(data)                                                    ((0x00000400&(data))>>10)
#define U0CPR_get_FIFO_STAT(data)                                                    ((0x00000400&(data))>>10)
#define U0CPR_FIFO_ACCESS_shift                                                      (9)
#define U0CPR_FIFO_ACCESS_mask                                                       (0x00000200)
#define U0CPR_FIFO_ACCESS(data)                                                      (0x00000200&((data)<<9))
#define U0CPR_FIFO_ACCESS_src(data)                                                  ((0x00000200&(data))>>9)
#define U0CPR_get_FIFO_ACCESS(data)                                                  ((0x00000200&(data))>>9)
#define U0CPR_ADDITIONAL_FEAT_shift                                                  (8)
#define U0CPR_ADDITIONAL_FEAT_mask                                                   (0x00000100)
#define U0CPR_ADDITIONAL_FEAT(data)                                                  (0x00000100&((data)<<8))
#define U0CPR_ADDITIONAL_FEAT_src(data)                                              ((0x00000100&(data))>>8)
#define U0CPR_get_ADDITIONAL_FEAT(data)                                              ((0x00000100&(data))>>8)
#define U0CPR_SIR_LP_MODE_shift                                                      (7)
#define U0CPR_SIR_LP_MODE_mask                                                       (0x00000080)
#define U0CPR_SIR_LP_MODE(data)                                                      (0x00000080&((data)<<7))
#define U0CPR_SIR_LP_MODE_src(data)                                                  ((0x00000080&(data))>>7)
#define U0CPR_get_SIR_LP_MODE(data)                                                  ((0x00000080&(data))>>7)
#define U0CPR_SIR_MODE_shift                                                         (6)
#define U0CPR_SIR_MODE_mask                                                          (0x00000040)
#define U0CPR_SIR_MODE(data)                                                         (0x00000040&((data)<<6))
#define U0CPR_SIR_MODE_src(data)                                                     ((0x00000040&(data))>>6)
#define U0CPR_get_SIR_MODE(data)                                                     ((0x00000040&(data))>>6)
#define U0CPR_THRE_MODE_shift                                                        (5)
#define U0CPR_THRE_MODE_mask                                                         (0x00000020)
#define U0CPR_THRE_MODE(data)                                                        (0x00000020&((data)<<5))
#define U0CPR_THRE_MODE_src(data)                                                    ((0x00000020&(data))>>5)
#define U0CPR_get_THRE_MODE(data)                                                    ((0x00000020&(data))>>5)
#define U0CPR_AFCE_MODE_shift                                                        (4)
#define U0CPR_AFCE_MODE_mask                                                         (0x00000010)
#define U0CPR_AFCE_MODE(data)                                                        (0x00000010&((data)<<4))
#define U0CPR_AFCE_MODE_src(data)                                                    ((0x00000010&(data))>>4)
#define U0CPR_get_AFCE_MODE(data)                                                    ((0x00000010&(data))>>4)
#define U0CPR_APB_DATA_WIDTH_shift                                                   (0)
#define U0CPR_APB_DATA_WIDTH_mask                                                    (0x00000003)
#define U0CPR_APB_DATA_WIDTH(data)                                                   (0x00000003&((data)<<0))
#define U0CPR_APB_DATA_WIDTH_src(data)                                               ((0x00000003&(data))>>0)
#define U0CPR_get_APB_DATA_WIDTH(data)                                               ((0x00000003&(data))>>0)


#define U0UCV                                                                        0x180078F8
#define U0UCV_reg_addr                                                               "0x180078F8"
#define U0UCV_reg                                                                    0x180078F8
#define set_U0UCV_reg(data)   (*((volatile unsigned int*) U0UCV_reg)=data)
#define get_U0UCV_reg   (*((volatile unsigned int*) U0UCV_reg))
#define U0UCV_inst_adr                                                               "0x003E"
#define U0UCV_inst                                                                   0x003E
#define U0UCV_UCV_shift                                                              (0)
#define U0UCV_UCV_mask                                                               (0xFFFFFFFF)
#define U0UCV_UCV(data)                                                              (0xFFFFFFFF&((data)<<0))
#define U0UCV_UCV_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define U0UCV_get_UCV(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define U0CTR                                                                        0x180078FC
#define U0CTR_reg_addr                                                               "0x180078FC"
#define U0CTR_reg                                                                    0x180078FC
#define set_U0CTR_reg(data)   (*((volatile unsigned int*) U0CTR_reg)=data)
#define get_U0CTR_reg   (*((volatile unsigned int*) U0CTR_reg))
#define U0CTR_inst_adr                                                               "0x003F"
#define U0CTR_inst                                                                   0x003F
#define U0CTR_CTR_shift                                                              (0)
#define U0CTR_CTR_mask                                                               (0xFFFFFFFF)
#define U0CTR_CTR(data)                                                              (0xFFFFFFFF&((data)<<0))
#define U0CTR_CTR_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define U0CTR_get_CTR(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define IC0_CON                                                                      0x18007D00
#define IC0_CON_reg_addr                                                             "0x18007D00"
#define IC0_CON_reg                                                                  0x18007D00
#define set_IC0_CON_reg(data)   (*((volatile unsigned int*) IC0_CON_reg)=data)
#define get_IC0_CON_reg   (*((volatile unsigned int*) IC0_CON_reg))
#define IC0_CON_inst_adr                                                             "0x0040"
#define IC0_CON_inst                                                                 0x0040
#define IC0_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC0_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC0_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC0_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC0_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC0_CON_IC_RESTART_EN_shift                                                  (5)
#define IC0_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC0_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC0_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC0_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC0_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC0_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC0_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC0_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC0_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC0_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC0_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC0_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC0_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC0_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC0_CON_SPEED_shift                                                          (1)
#define IC0_CON_SPEED_mask                                                           (0x00000006)
#define IC0_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC0_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC0_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC0_CON_MASTER_MODE_shift                                                    (0)
#define IC0_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC0_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC0_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC0_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC0_TAR                                                                      0x18007D04
#define IC0_TAR_reg_addr                                                             "0x18007D04"
#define IC0_TAR_reg                                                                  0x18007D04
#define set_IC0_TAR_reg(data)   (*((volatile unsigned int*) IC0_TAR_reg)=data)
#define get_IC0_TAR_reg   (*((volatile unsigned int*) IC0_TAR_reg))
#define IC0_TAR_inst_adr                                                             "0x0041"
#define IC0_TAR_inst                                                                 0x0041
#define IC0_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC0_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC0_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC0_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC0_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC0_TAR_SPECIAL_shift                                                        (11)
#define IC0_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC0_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC0_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC0_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC0_TAR_GC_OR_START_shift                                                    (10)
#define IC0_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC0_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC0_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC0_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC0_TAR_IC_TAR_shift                                                         (0)
#define IC0_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC0_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC0_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC0_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC0_SAR                                                                      0x18007D08
#define IC0_SAR_reg_addr                                                             "0x18007D08"
#define IC0_SAR_reg                                                                  0x18007D08
#define set_IC0_SAR_reg(data)   (*((volatile unsigned int*) IC0_SAR_reg)=data)
#define get_IC0_SAR_reg   (*((volatile unsigned int*) IC0_SAR_reg))
#define IC0_SAR_inst_adr                                                             "0x0042"
#define IC0_SAR_inst                                                                 0x0042
#define IC0_SAR_IC_SAR_shift                                                         (0)
#define IC0_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC0_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC0_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC0_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC0_HS_MADDR                                                                 0x18007D0C
#define IC0_HS_MADDR_reg_addr                                                        "0x18007D0C"
#define IC0_HS_MADDR_reg                                                             0x18007D0C
#define set_IC0_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC0_HS_MADDR_reg)=data)
#define get_IC0_HS_MADDR_reg   (*((volatile unsigned int*) IC0_HS_MADDR_reg))
#define IC0_HS_MADDR_inst_adr                                                        "0x0043"
#define IC0_HS_MADDR_inst                                                            0x0043
#define IC0_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC0_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC0_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC0_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC0_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC0_DATA_CMD                                                                 0x18007D10
#define IC0_DATA_CMD_reg_addr                                                        "0x18007D10"
#define IC0_DATA_CMD_reg                                                             0x18007D10
#define set_IC0_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC0_DATA_CMD_reg)=data)
#define get_IC0_DATA_CMD_reg   (*((volatile unsigned int*) IC0_DATA_CMD_reg))
#define IC0_DATA_CMD_inst_adr                                                        "0x0044"
#define IC0_DATA_CMD_inst                                                            0x0044
#define IC0_DATA_CMD_RESTART_shift                                                   (10)
#define IC0_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC0_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC0_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC0_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC0_DATA_CMD_STOP_shift                                                      (9)
#define IC0_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC0_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC0_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC0_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC0_DATA_CMD_CMD_shift                                                       (8)
#define IC0_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC0_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC0_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC0_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC0_DATA_CMD_DAT_shift                                                       (0)
#define IC0_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC0_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC0_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC0_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC0_SS_SCL_HCNT                                                              0x18007D14
#define IC0_SS_SCL_HCNT_reg_addr                                                     "0x18007D14"
#define IC0_SS_SCL_HCNT_reg                                                          0x18007D14
#define set_IC0_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC0_SS_SCL_HCNT_reg)=data)
#define get_IC0_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC0_SS_SCL_HCNT_reg))
#define IC0_SS_SCL_HCNT_inst_adr                                                     "0x0045"
#define IC0_SS_SCL_HCNT_inst                                                         0x0045
#define IC0_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC0_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC0_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC0_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC0_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC0_SS_SCL_LCNT                                                              0x18007D18
#define IC0_SS_SCL_LCNT_reg_addr                                                     "0x18007D18"
#define IC0_SS_SCL_LCNT_reg                                                          0x18007D18
#define set_IC0_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC0_SS_SCL_LCNT_reg)=data)
#define get_IC0_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC0_SS_SCL_LCNT_reg))
#define IC0_SS_SCL_LCNT_inst_adr                                                     "0x0046"
#define IC0_SS_SCL_LCNT_inst                                                         0x0046
#define IC0_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC0_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC0_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC0_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC0_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC0_FS_SCL_HCNT                                                              0x18007D1C
#define IC0_FS_SCL_HCNT_reg_addr                                                     "0x18007D1C"
#define IC0_FS_SCL_HCNT_reg                                                          0x18007D1C
#define set_IC0_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC0_FS_SCL_HCNT_reg)=data)
#define get_IC0_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC0_FS_SCL_HCNT_reg))
#define IC0_FS_SCL_HCNT_inst_adr                                                     "0x0047"
#define IC0_FS_SCL_HCNT_inst                                                         0x0047
#define IC0_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC0_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC0_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC0_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC0_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC0_FS_SCL_LCNT                                                              0x18007D20
#define IC0_FS_SCL_LCNT_reg_addr                                                     "0x18007D20"
#define IC0_FS_SCL_LCNT_reg                                                          0x18007D20
#define set_IC0_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC0_FS_SCL_LCNT_reg)=data)
#define get_IC0_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC0_FS_SCL_LCNT_reg))
#define IC0_FS_SCL_LCNT_inst_adr                                                     "0x0048"
#define IC0_FS_SCL_LCNT_inst                                                         0x0048
#define IC0_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC0_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC0_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC0_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC0_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC0_INTR_STAT                                                                0x18007D2C
#define IC0_INTR_STAT_reg_addr                                                       "0x18007D2C"
#define IC0_INTR_STAT_reg                                                            0x18007D2C
#define set_IC0_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC0_INTR_STAT_reg)=data)
#define get_IC0_INTR_STAT_reg   (*((volatile unsigned int*) IC0_INTR_STAT_reg))
#define IC0_INTR_STAT_inst_adr                                                       "0x004B"
#define IC0_INTR_STAT_inst                                                           0x004B
#define IC0_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC0_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC0_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC0_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC0_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC0_INTR_STAT_R_START_DET_shift                                              (10)
#define IC0_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC0_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC0_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC0_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC0_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC0_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC0_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC0_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC0_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC0_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC0_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC0_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC0_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC0_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC0_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC0_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC0_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC0_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC0_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC0_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC0_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC0_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC0_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC0_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC0_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC0_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC0_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC0_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC0_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC0_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC0_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC0_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC0_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC0_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC0_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC0_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC0_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC0_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC0_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC0_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC0_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC0_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC0_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC0_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC0_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC0_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC0_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC0_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC0_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC0_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC0_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC0_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC0_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC0_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC0_INTR_MASK                                                                0x18007D30
#define IC0_INTR_MASK_reg_addr                                                       "0x18007D30"
#define IC0_INTR_MASK_reg                                                            0x18007D30
#define set_IC0_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC0_INTR_MASK_reg)=data)
#define get_IC0_INTR_MASK_reg   (*((volatile unsigned int*) IC0_INTR_MASK_reg))
#define IC0_INTR_MASK_inst_adr                                                       "0x004C"
#define IC0_INTR_MASK_inst                                                           0x004C
#define IC0_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC0_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC0_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC0_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC0_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC0_INTR_MASK_M_START_DET_shift                                              (10)
#define IC0_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC0_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC0_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC0_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC0_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC0_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC0_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC0_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC0_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC0_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC0_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC0_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC0_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC0_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC0_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC0_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC0_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC0_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC0_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC0_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC0_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC0_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC0_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC0_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC0_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC0_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC0_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC0_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC0_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC0_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC0_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC0_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC0_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC0_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC0_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC0_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC0_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC0_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC0_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC0_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC0_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC0_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC0_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC0_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC0_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC0_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC0_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC0_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC0_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC0_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC0_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC0_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC0_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC0_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC0_RAW_INTR_STAT                                                            0x18007D34
#define IC0_RAW_INTR_STAT_reg_addr                                                   "0x18007D34"
#define IC0_RAW_INTR_STAT_reg                                                        0x18007D34
#define set_IC0_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC0_RAW_INTR_STAT_reg)=data)
#define get_IC0_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC0_RAW_INTR_STAT_reg))
#define IC0_RAW_INTR_STAT_inst_adr                                                   "0x004D"
#define IC0_RAW_INTR_STAT_inst                                                       0x004D
#define IC0_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC0_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC0_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC0_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC0_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC0_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC0_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC0_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC0_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC0_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC0_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC0_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC0_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC0_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC0_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC0_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC0_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC0_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC0_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC0_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC0_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC0_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC0_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC0_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC0_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC0_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC0_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC0_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC0_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC0_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC0_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC0_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC0_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC0_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC0_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC0_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC0_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC0_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC0_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC0_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC0_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC0_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC0_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC0_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC0_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC0_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC0_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC0_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC0_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC0_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC0_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC0_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC0_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC0_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC0_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC0_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC0_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC0_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC0_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC0_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC0_RX_TL                                                                    0x18007D38
#define IC0_RX_TL_reg_addr                                                           "0x18007D38"
#define IC0_RX_TL_reg                                                                0x18007D38
#define set_IC0_RX_TL_reg(data)   (*((volatile unsigned int*) IC0_RX_TL_reg)=data)
#define get_IC0_RX_TL_reg   (*((volatile unsigned int*) IC0_RX_TL_reg))
#define IC0_RX_TL_inst_adr                                                           "0x004E"
#define IC0_RX_TL_inst                                                               0x004E
#define IC0_RX_TL_RX_TL_shift                                                        (0)
#define IC0_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC0_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC0_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC0_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC0_TX_TL                                                                    0x18007D3C
#define IC0_TX_TL_reg_addr                                                           "0x18007D3C"
#define IC0_TX_TL_reg                                                                0x18007D3C
#define set_IC0_TX_TL_reg(data)   (*((volatile unsigned int*) IC0_TX_TL_reg)=data)
#define get_IC0_TX_TL_reg   (*((volatile unsigned int*) IC0_TX_TL_reg))
#define IC0_TX_TL_inst_adr                                                           "0x004F"
#define IC0_TX_TL_inst                                                               0x004F
#define IC0_TX_TL_TX_TL_shift                                                        (0)
#define IC0_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC0_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC0_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC0_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC0_CLR_INTR                                                                 0x18007D40
#define IC0_CLR_INTR_reg_addr                                                        "0x18007D40"
#define IC0_CLR_INTR_reg                                                             0x18007D40
#define set_IC0_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC0_CLR_INTR_reg)=data)
#define get_IC0_CLR_INTR_reg   (*((volatile unsigned int*) IC0_CLR_INTR_reg))
#define IC0_CLR_INTR_inst_adr                                                        "0x0050"
#define IC0_CLR_INTR_inst                                                            0x0050
#define IC0_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC0_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC0_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC0_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC0_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC0_CLR_RX_UNDER                                                             0x18007D44
#define IC0_CLR_RX_UNDER_reg_addr                                                    "0x18007D44"
#define IC0_CLR_RX_UNDER_reg                                                         0x18007D44
#define set_IC0_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC0_CLR_RX_UNDER_reg)=data)
#define get_IC0_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC0_CLR_RX_UNDER_reg))
#define IC0_CLR_RX_UNDER_inst_adr                                                    "0x0051"
#define IC0_CLR_RX_UNDER_inst                                                        0x0051
#define IC0_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC0_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC0_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC0_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC0_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC0_CLR_RX_OVER                                                              0x18007D48
#define IC0_CLR_RX_OVER_reg_addr                                                     "0x18007D48"
#define IC0_CLR_RX_OVER_reg                                                          0x18007D48
#define set_IC0_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC0_CLR_RX_OVER_reg)=data)
#define get_IC0_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC0_CLR_RX_OVER_reg))
#define IC0_CLR_RX_OVER_inst_adr                                                     "0x0052"
#define IC0_CLR_RX_OVER_inst                                                         0x0052
#define IC0_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC0_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC0_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC0_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC0_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC0_CLR_TX_OVER                                                              0x18007D4C
#define IC0_CLR_TX_OVER_reg_addr                                                     "0x18007D4C"
#define IC0_CLR_TX_OVER_reg                                                          0x18007D4C
#define set_IC0_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC0_CLR_TX_OVER_reg)=data)
#define get_IC0_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC0_CLR_TX_OVER_reg))
#define IC0_CLR_TX_OVER_inst_adr                                                     "0x0053"
#define IC0_CLR_TX_OVER_inst                                                         0x0053
#define IC0_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC0_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC0_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC0_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC0_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC0_CLR_RD_REQ                                                               0x18007D50
#define IC0_CLR_RD_REQ_reg_addr                                                      "0x18007D50"
#define IC0_CLR_RD_REQ_reg                                                           0x18007D50
#define set_IC0_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC0_CLR_RD_REQ_reg)=data)
#define get_IC0_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC0_CLR_RD_REQ_reg))
#define IC0_CLR_RD_REQ_inst_adr                                                      "0x0054"
#define IC0_CLR_RD_REQ_inst                                                          0x0054
#define IC0_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC0_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC0_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC0_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC0_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC0_CLR_TX_ABRT                                                              0x18007D54
#define IC0_CLR_TX_ABRT_reg_addr                                                     "0x18007D54"
#define IC0_CLR_TX_ABRT_reg                                                          0x18007D54
#define set_IC0_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC0_CLR_TX_ABRT_reg)=data)
#define get_IC0_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC0_CLR_TX_ABRT_reg))
#define IC0_CLR_TX_ABRT_inst_adr                                                     "0x0055"
#define IC0_CLR_TX_ABRT_inst                                                         0x0055
#define IC0_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC0_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC0_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC0_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC0_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC0_CLR_RX_DONE                                                              0x18007D58
#define IC0_CLR_RX_DONE_reg_addr                                                     "0x18007D58"
#define IC0_CLR_RX_DONE_reg                                                          0x18007D58
#define set_IC0_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC0_CLR_RX_DONE_reg)=data)
#define get_IC0_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC0_CLR_RX_DONE_reg))
#define IC0_CLR_RX_DONE_inst_adr                                                     "0x0056"
#define IC0_CLR_RX_DONE_inst                                                         0x0056
#define IC0_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC0_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC0_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC0_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC0_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC0_CLR_ACTIVITY                                                             0x18007D5C
#define IC0_CLR_ACTIVITY_reg_addr                                                    "0x18007D5C"
#define IC0_CLR_ACTIVITY_reg                                                         0x18007D5C
#define set_IC0_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC0_CLR_ACTIVITY_reg)=data)
#define get_IC0_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC0_CLR_ACTIVITY_reg))
#define IC0_CLR_ACTIVITY_inst_adr                                                    "0x0057"
#define IC0_CLR_ACTIVITY_inst                                                        0x0057
#define IC0_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC0_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC0_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC0_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC0_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC0_CLR_STOP_DET                                                             0x18007D60
#define IC0_CLR_STOP_DET_reg_addr                                                    "0x18007D60"
#define IC0_CLR_STOP_DET_reg                                                         0x18007D60
#define set_IC0_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC0_CLR_STOP_DET_reg)=data)
#define get_IC0_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC0_CLR_STOP_DET_reg))
#define IC0_CLR_STOP_DET_inst_adr                                                    "0x0058"
#define IC0_CLR_STOP_DET_inst                                                        0x0058
#define IC0_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC0_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC0_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC0_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC0_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC0_CLR_START_DET                                                            0x18007D64
#define IC0_CLR_START_DET_reg_addr                                                   "0x18007D64"
#define IC0_CLR_START_DET_reg                                                        0x18007D64
#define set_IC0_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC0_CLR_START_DET_reg)=data)
#define get_IC0_CLR_START_DET_reg   (*((volatile unsigned int*) IC0_CLR_START_DET_reg))
#define IC0_CLR_START_DET_inst_adr                                                   "0x0059"
#define IC0_CLR_START_DET_inst                                                       0x0059
#define IC0_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC0_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC0_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC0_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC0_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC0_CLR_GEN_CALL                                                             0x18007D68
#define IC0_CLR_GEN_CALL_reg_addr                                                    "0x18007D68"
#define IC0_CLR_GEN_CALL_reg                                                         0x18007D68
#define set_IC0_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC0_CLR_GEN_CALL_reg)=data)
#define get_IC0_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC0_CLR_GEN_CALL_reg))
#define IC0_CLR_GEN_CALL_inst_adr                                                    "0x005A"
#define IC0_CLR_GEN_CALL_inst                                                        0x005A
#define IC0_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC0_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC0_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC0_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC0_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC0_ENABLE                                                                   0x18007D6C
#define IC0_ENABLE_reg_addr                                                          "0x18007D6C"
#define IC0_ENABLE_reg                                                               0x18007D6C
#define set_IC0_ENABLE_reg(data)   (*((volatile unsigned int*) IC0_ENABLE_reg)=data)
#define get_IC0_ENABLE_reg   (*((volatile unsigned int*) IC0_ENABLE_reg))
#define IC0_ENABLE_inst_adr                                                          "0x005B"
#define IC0_ENABLE_inst                                                              0x005B
#define IC0_ENABLE_ENABLE_shift                                                      (0)
#define IC0_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC0_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC0_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC0_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC0_STATUS                                                                   0x18007D70
#define IC0_STATUS_reg_addr                                                          "0x18007D70"
#define IC0_STATUS_reg                                                               0x18007D70
#define set_IC0_STATUS_reg(data)   (*((volatile unsigned int*) IC0_STATUS_reg)=data)
#define get_IC0_STATUS_reg   (*((volatile unsigned int*) IC0_STATUS_reg))
#define IC0_STATUS_inst_adr                                                          "0x005C"
#define IC0_STATUS_inst                                                              0x005C
#define IC0_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC0_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC0_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC0_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC0_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC0_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC0_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC0_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC0_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC0_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC0_STATUS_RFF_shift                                                         (4)
#define IC0_STATUS_RFF_mask                                                          (0x00000010)
#define IC0_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC0_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC0_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC0_STATUS_RFNE_shift                                                        (3)
#define IC0_STATUS_RFNE_mask                                                         (0x00000008)
#define IC0_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC0_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC0_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC0_STATUS_TFE_shift                                                         (2)
#define IC0_STATUS_TFE_mask                                                          (0x00000004)
#define IC0_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC0_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC0_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC0_STATUS_TFNF_shift                                                        (1)
#define IC0_STATUS_TFNF_mask                                                         (0x00000002)
#define IC0_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC0_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC0_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC0_STATUS_ACTIVITY_shift                                                    (0)
#define IC0_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC0_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC0_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC0_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC0_TXFLR                                                                    0x18007D74
#define IC0_TXFLR_reg_addr                                                           "0x18007D74"
#define IC0_TXFLR_reg                                                                0x18007D74
#define set_IC0_TXFLR_reg(data)   (*((volatile unsigned int*) IC0_TXFLR_reg)=data)
#define get_IC0_TXFLR_reg   (*((volatile unsigned int*) IC0_TXFLR_reg))
#define IC0_TXFLR_inst_adr                                                           "0x005D"
#define IC0_TXFLR_inst                                                               0x005D
#define IC0_TXFLR_TXFLR_shift                                                        (0)
#define IC0_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC0_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC0_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC0_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC0_RXFLR                                                                    0x18007D78
#define IC0_RXFLR_reg_addr                                                           "0x18007D78"
#define IC0_RXFLR_reg                                                                0x18007D78
#define set_IC0_RXFLR_reg(data)   (*((volatile unsigned int*) IC0_RXFLR_reg)=data)
#define get_IC0_RXFLR_reg   (*((volatile unsigned int*) IC0_RXFLR_reg))
#define IC0_RXFLR_inst_adr                                                           "0x005E"
#define IC0_RXFLR_inst                                                               0x005E
#define IC0_RXFLR_RXFLR_shift                                                        (0)
#define IC0_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC0_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC0_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC0_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC0_SDA_HOLD                                                                 0x18007D7C
#define IC0_SDA_HOLD_reg_addr                                                        "0x18007D7C"
#define IC0_SDA_HOLD_reg                                                             0x18007D7C
#define set_IC0_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC0_SDA_HOLD_reg)=data)
#define get_IC0_SDA_HOLD_reg   (*((volatile unsigned int*) IC0_SDA_HOLD_reg))
#define IC0_SDA_HOLD_inst_adr                                                        "0x005F"
#define IC0_SDA_HOLD_inst                                                            0x005F
#define IC0_SDA_HOLD_IC_SDA_HOLD_shift                                               (0)
#define IC0_SDA_HOLD_IC_SDA_HOLD_mask                                                (0x0000FFFF)
#define IC0_SDA_HOLD_IC_SDA_HOLD(data)                                               (0x0000FFFF&((data)<<0))
#define IC0_SDA_HOLD_IC_SDA_HOLD_src(data)                                           ((0x0000FFFF&(data))>>0)
#define IC0_SDA_HOLD_get_IC_SDA_HOLD(data)                                           ((0x0000FFFF&(data))>>0)


#define IC0_TX_ABRT_SOURCE                                                           0x18007D80
#define IC0_TX_ABRT_SOURCE_reg_addr                                                  "0x18007D80"
#define IC0_TX_ABRT_SOURCE_reg                                                       0x18007D80
#define set_IC0_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC0_TX_ABRT_SOURCE_reg)=data)
#define get_IC0_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC0_TX_ABRT_SOURCE_reg))
#define IC0_TX_ABRT_SOURCE_inst_adr                                                  "0x0060"
#define IC0_TX_ABRT_SOURCE_inst                                                      0x0060
#define IC0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC0_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC0_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC0_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC0_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC0_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC0_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC0_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC0_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC0_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC0_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC0_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC0_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC0_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC0_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC0_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC0_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC0_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC0_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC0_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC0_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC0_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC0_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC0_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC0_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC0_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC0_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC0_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC0_SLV_DATA_NACK_ONLY                                                       0x18007D84
#define IC0_SLV_DATA_NACK_ONLY_reg_addr                                              "0x18007D84"
#define IC0_SLV_DATA_NACK_ONLY_reg                                                   0x18007D84
#define set_IC0_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC0_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC0_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC0_SLV_DATA_NACK_ONLY_reg))
#define IC0_SLV_DATA_NACK_ONLY_inst_adr                                              "0x0061"
#define IC0_SLV_DATA_NACK_ONLY_inst                                                  0x0061
#define IC0_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC0_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC0_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC0_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC0_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC0_DMA_CR                                                                   0x18007D88
#define IC0_DMA_CR_reg_addr                                                          "0x18007D88"
#define IC0_DMA_CR_reg                                                               0x18007D88
#define set_IC0_DMA_CR_reg(data)   (*((volatile unsigned int*) IC0_DMA_CR_reg)=data)
#define get_IC0_DMA_CR_reg   (*((volatile unsigned int*) IC0_DMA_CR_reg))
#define IC0_DMA_CR_inst_adr                                                          "0x0062"
#define IC0_DMA_CR_inst                                                              0x0062
#define IC0_DMA_CR_TDMAE_shift                                                       (1)
#define IC0_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC0_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC0_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC0_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC0_DMA_CR_RDMAE_shift                                                       (0)
#define IC0_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC0_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC0_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC0_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC0_DMA_TDLR                                                                 0x18007D8C
#define IC0_DMA_TDLR_reg_addr                                                        "0x18007D8C"
#define IC0_DMA_TDLR_reg                                                             0x18007D8C
#define set_IC0_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC0_DMA_TDLR_reg)=data)
#define get_IC0_DMA_TDLR_reg   (*((volatile unsigned int*) IC0_DMA_TDLR_reg))
#define IC0_DMA_TDLR_inst_adr                                                        "0x0063"
#define IC0_DMA_TDLR_inst                                                            0x0063
#define IC0_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC0_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC0_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC0_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC0_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC0_DMA_RDLR                                                                 0x18007D90
#define IC0_DMA_RDLR_reg_addr                                                        "0x18007D90"
#define IC0_DMA_RDLR_reg                                                             0x18007D90
#define set_IC0_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC0_DMA_RDLR_reg)=data)
#define get_IC0_DMA_RDLR_reg   (*((volatile unsigned int*) IC0_DMA_RDLR_reg))
#define IC0_DMA_RDLR_inst_adr                                                        "0x0064"
#define IC0_DMA_RDLR_inst                                                            0x0064
#define IC0_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC0_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC0_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC0_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC0_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC0_SDA_SETUP                                                                0x18007D94
#define IC0_SDA_SETUP_reg_addr                                                       "0x18007D94"
#define IC0_SDA_SETUP_reg                                                            0x18007D94
#define set_IC0_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC0_SDA_SETUP_reg)=data)
#define get_IC0_SDA_SETUP_reg   (*((volatile unsigned int*) IC0_SDA_SETUP_reg))
#define IC0_SDA_SETUP_inst_adr                                                       "0x0065"
#define IC0_SDA_SETUP_inst                                                           0x0065
#define IC0_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC0_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC0_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC0_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC0_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC0_ACK_GENERAL_CALL                                                         0x18007D98
#define IC0_ACK_GENERAL_CALL_reg_addr                                                "0x18007D98"
#define IC0_ACK_GENERAL_CALL_reg                                                     0x18007D98
#define set_IC0_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC0_ACK_GENERAL_CALL_reg)=data)
#define get_IC0_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC0_ACK_GENERAL_CALL_reg))
#define IC0_ACK_GENERAL_CALL_inst_adr                                                "0x0066"
#define IC0_ACK_GENERAL_CALL_inst                                                    0x0066
#define IC0_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC0_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC0_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC0_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC0_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC0_ENABLE_STATUS                                                            0x18007D9C
#define IC0_ENABLE_STATUS_reg_addr                                                   "0x18007D9C"
#define IC0_ENABLE_STATUS_reg                                                        0x18007D9C
#define set_IC0_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC0_ENABLE_STATUS_reg)=data)
#define get_IC0_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC0_ENABLE_STATUS_reg))
#define IC0_ENABLE_STATUS_inst_adr                                                   "0x0067"
#define IC0_ENABLE_STATUS_inst                                                       0x0067
#define IC0_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC0_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC0_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC0_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC0_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC0_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC0_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC0_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC0_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC0_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC0_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC0_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC0_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC0_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC0_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC0_COMP_PARAM_1                                                             0x18007DF4
#define IC0_COMP_PARAM_1_reg_addr                                                    "0x18007DF4"
#define IC0_COMP_PARAM_1_reg                                                         0x18007DF4
#define set_IC0_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC0_COMP_PARAM_1_reg)=data)
#define get_IC0_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC0_COMP_PARAM_1_reg))
#define IC0_COMP_PARAM_1_inst_adr                                                    "0x007D"
#define IC0_COMP_PARAM_1_inst                                                        0x007D
#define IC0_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC0_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC0_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC0_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC0_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC0_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC0_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC0_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC0_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC0_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC0_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC0_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC0_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC0_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC0_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC0_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC0_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC0_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC0_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC0_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC0_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC0_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC0_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC0_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC0_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC0_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC0_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC0_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC0_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC0_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC0_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC0_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC0_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC0_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC0_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC0_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC0_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC0_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC0_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC0_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC0_COMP_VERSION                                                             0x18007DF8
#define IC0_COMP_VERSION_reg_addr                                                    "0x18007DF8"
#define IC0_COMP_VERSION_reg                                                         0x18007DF8
#define set_IC0_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC0_COMP_VERSION_reg)=data)
#define get_IC0_COMP_VERSION_reg   (*((volatile unsigned int*) IC0_COMP_VERSION_reg))
#define IC0_COMP_VERSION_inst_adr                                                    "0x007E"
#define IC0_COMP_VERSION_inst                                                        0x007E
#define IC0_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC0_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC0_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC0_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC0_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC0_COMP_TYPE                                                                0x18007DFC
#define IC0_COMP_TYPE_reg_addr                                                       "0x18007DFC"
#define IC0_COMP_TYPE_reg                                                            0x18007DFC
#define set_IC0_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC0_COMP_TYPE_reg)=data)
#define get_IC0_COMP_TYPE_reg   (*((volatile unsigned int*) IC0_COMP_TYPE_reg))
#define IC0_COMP_TYPE_inst_adr                                                       "0x007F"
#define IC0_COMP_TYPE_inst                                                           0x007F
#define IC0_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC0_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC0_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC0_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC0_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IC6_CON                                                                      0x18007E00
#define IC6_CON_reg_addr                                                             "0x18007E00"
#define IC6_CON_reg                                                                  0x18007E00
#define set_IC6_CON_reg(data)   (*((volatile unsigned int*) IC6_CON_reg)=data)
#define get_IC6_CON_reg   (*((volatile unsigned int*) IC6_CON_reg))
#define IC6_CON_inst_adr                                                             "0x0080"
#define IC6_CON_inst                                                                 0x0080
#define IC6_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC6_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC6_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC6_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC6_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC6_CON_IC_RESTART_EN_shift                                                  (5)
#define IC6_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC6_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC6_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC6_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC6_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC6_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC6_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC6_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC6_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC6_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC6_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC6_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC6_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC6_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC6_CON_SPEED_shift                                                          (1)
#define IC6_CON_SPEED_mask                                                           (0x00000006)
#define IC6_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC6_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC6_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC6_CON_MASTER_MODE_shift                                                    (0)
#define IC6_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC6_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC6_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC6_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC6_TAR                                                                      0x18007E04
#define IC6_TAR_reg_addr                                                             "0x18007E04"
#define IC6_TAR_reg                                                                  0x18007E04
#define set_IC6_TAR_reg(data)   (*((volatile unsigned int*) IC6_TAR_reg)=data)
#define get_IC6_TAR_reg   (*((volatile unsigned int*) IC6_TAR_reg))
#define IC6_TAR_inst_adr                                                             "0x0081"
#define IC6_TAR_inst                                                                 0x0081
#define IC6_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC6_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC6_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC6_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC6_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC6_TAR_SPECIAL_shift                                                        (11)
#define IC6_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC6_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC6_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC6_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC6_TAR_GC_OR_START_shift                                                    (10)
#define IC6_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC6_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC6_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC6_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC6_TAR_IC_TAR_shift                                                         (0)
#define IC6_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC6_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC6_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC6_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC6_SAR                                                                      0x18007E08
#define IC6_SAR_reg_addr                                                             "0x18007E08"
#define IC6_SAR_reg                                                                  0x18007E08
#define set_IC6_SAR_reg(data)   (*((volatile unsigned int*) IC6_SAR_reg)=data)
#define get_IC6_SAR_reg   (*((volatile unsigned int*) IC6_SAR_reg))
#define IC6_SAR_inst_adr                                                             "0x0082"
#define IC6_SAR_inst                                                                 0x0082
#define IC6_SAR_IC_SAR_shift                                                         (0)
#define IC6_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC6_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC6_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC6_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC6_HS_MADDR                                                                 0x18007E0C
#define IC6_HS_MADDR_reg_addr                                                        "0x18007E0C"
#define IC6_HS_MADDR_reg                                                             0x18007E0C
#define set_IC6_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC6_HS_MADDR_reg)=data)
#define get_IC6_HS_MADDR_reg   (*((volatile unsigned int*) IC6_HS_MADDR_reg))
#define IC6_HS_MADDR_inst_adr                                                        "0x0083"
#define IC6_HS_MADDR_inst                                                            0x0083
#define IC6_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC6_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC6_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC6_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC6_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC6_DATA_CMD                                                                 0x18007E10
#define IC6_DATA_CMD_reg_addr                                                        "0x18007E10"
#define IC6_DATA_CMD_reg                                                             0x18007E10
#define set_IC6_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC6_DATA_CMD_reg)=data)
#define get_IC6_DATA_CMD_reg   (*((volatile unsigned int*) IC6_DATA_CMD_reg))
#define IC6_DATA_CMD_inst_adr                                                        "0x0084"
#define IC6_DATA_CMD_inst                                                            0x0084
#define IC6_DATA_CMD_RESTART_shift                                                   (10)
#define IC6_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC6_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC6_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC6_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC6_DATA_CMD_STOP_shift                                                      (9)
#define IC6_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC6_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC6_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC6_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC6_DATA_CMD_CMD_shift                                                       (8)
#define IC6_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC6_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC6_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC6_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC6_DATA_CMD_DAT_shift                                                       (0)
#define IC6_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC6_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC6_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC6_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC6_SS_SCL_HCNT                                                              0x18007E14
#define IC6_SS_SCL_HCNT_reg_addr                                                     "0x18007E14"
#define IC6_SS_SCL_HCNT_reg                                                          0x18007E14
#define set_IC6_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC6_SS_SCL_HCNT_reg)=data)
#define get_IC6_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC6_SS_SCL_HCNT_reg))
#define IC6_SS_SCL_HCNT_inst_adr                                                     "0x0085"
#define IC6_SS_SCL_HCNT_inst                                                         0x0085
#define IC6_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC6_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC6_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC6_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC6_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC6_SS_SCL_LCNT                                                              0x18007E18
#define IC6_SS_SCL_LCNT_reg_addr                                                     "0x18007E18"
#define IC6_SS_SCL_LCNT_reg                                                          0x18007E18
#define set_IC6_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC6_SS_SCL_LCNT_reg)=data)
#define get_IC6_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC6_SS_SCL_LCNT_reg))
#define IC6_SS_SCL_LCNT_inst_adr                                                     "0x0086"
#define IC6_SS_SCL_LCNT_inst                                                         0x0086
#define IC6_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC6_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC6_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC6_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC6_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC6_FS_SCL_HCNT                                                              0x18007E1C
#define IC6_FS_SCL_HCNT_reg_addr                                                     "0x18007E1C"
#define IC6_FS_SCL_HCNT_reg                                                          0x18007E1C
#define set_IC6_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC6_FS_SCL_HCNT_reg)=data)
#define get_IC6_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC6_FS_SCL_HCNT_reg))
#define IC6_FS_SCL_HCNT_inst_adr                                                     "0x0087"
#define IC6_FS_SCL_HCNT_inst                                                         0x0087
#define IC6_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC6_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC6_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC6_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC6_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC6_FS_SCL_LCNT                                                              0x18007E20
#define IC6_FS_SCL_LCNT_reg_addr                                                     "0x18007E20"
#define IC6_FS_SCL_LCNT_reg                                                          0x18007E20
#define set_IC6_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC6_FS_SCL_LCNT_reg)=data)
#define get_IC6_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC6_FS_SCL_LCNT_reg))
#define IC6_FS_SCL_LCNT_inst_adr                                                     "0x0088"
#define IC6_FS_SCL_LCNT_inst                                                         0x0088
#define IC6_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC6_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC6_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC6_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC6_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC6_INTR_STAT                                                                0x18007E2C
#define IC6_INTR_STAT_reg_addr                                                       "0x18007E2C"
#define IC6_INTR_STAT_reg                                                            0x18007E2C
#define set_IC6_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC6_INTR_STAT_reg)=data)
#define get_IC6_INTR_STAT_reg   (*((volatile unsigned int*) IC6_INTR_STAT_reg))
#define IC6_INTR_STAT_inst_adr                                                       "0x008B"
#define IC6_INTR_STAT_inst                                                           0x008B
#define IC6_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC6_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC6_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC6_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC6_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC6_INTR_STAT_R_START_DET_shift                                              (10)
#define IC6_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC6_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC6_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC6_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC6_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC6_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC6_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC6_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC6_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC6_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC6_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC6_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC6_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC6_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC6_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC6_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC6_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC6_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC6_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC6_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC6_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC6_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC6_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC6_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC6_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC6_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC6_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC6_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC6_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC6_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC6_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC6_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC6_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC6_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC6_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC6_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC6_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC6_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC6_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC6_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC6_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC6_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC6_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC6_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC6_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC6_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC6_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC6_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC6_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC6_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC6_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC6_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC6_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC6_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC6_INTR_MASK                                                                0x18007E30
#define IC6_INTR_MASK_reg_addr                                                       "0x18007E30"
#define IC6_INTR_MASK_reg                                                            0x18007E30
#define set_IC6_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC6_INTR_MASK_reg)=data)
#define get_IC6_INTR_MASK_reg   (*((volatile unsigned int*) IC6_INTR_MASK_reg))
#define IC6_INTR_MASK_inst_adr                                                       "0x008C"
#define IC6_INTR_MASK_inst                                                           0x008C
#define IC6_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC6_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC6_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC6_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC6_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC6_INTR_MASK_M_START_DET_shift                                              (10)
#define IC6_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC6_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC6_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC6_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC6_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC6_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC6_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC6_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC6_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC6_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC6_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC6_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC6_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC6_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC6_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC6_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC6_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC6_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC6_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC6_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC6_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC6_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC6_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC6_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC6_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC6_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC6_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC6_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC6_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC6_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC6_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC6_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC6_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC6_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC6_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC6_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC6_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC6_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC6_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC6_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC6_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC6_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC6_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC6_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC6_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC6_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC6_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC6_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC6_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC6_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC6_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC6_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC6_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC6_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC6_RAW_INTR_STAT                                                            0x18007E34
#define IC6_RAW_INTR_STAT_reg_addr                                                   "0x18007E34"
#define IC6_RAW_INTR_STAT_reg                                                        0x18007E34
#define set_IC6_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC6_RAW_INTR_STAT_reg)=data)
#define get_IC6_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC6_RAW_INTR_STAT_reg))
#define IC6_RAW_INTR_STAT_inst_adr                                                   "0x008D"
#define IC6_RAW_INTR_STAT_inst                                                       0x008D
#define IC6_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC6_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC6_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC6_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC6_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC6_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC6_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC6_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC6_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC6_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC6_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC6_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC6_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC6_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC6_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC6_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC6_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC6_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC6_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC6_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC6_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC6_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC6_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC6_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC6_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC6_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC6_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC6_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC6_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC6_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC6_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC6_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC6_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC6_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC6_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC6_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC6_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC6_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC6_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC6_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC6_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC6_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC6_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC6_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC6_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC6_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC6_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC6_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC6_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC6_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC6_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC6_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC6_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC6_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC6_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC6_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC6_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC6_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC6_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC6_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC6_RX_TL                                                                    0x18007E38
#define IC6_RX_TL_reg_addr                                                           "0x18007E38"
#define IC6_RX_TL_reg                                                                0x18007E38
#define set_IC6_RX_TL_reg(data)   (*((volatile unsigned int*) IC6_RX_TL_reg)=data)
#define get_IC6_RX_TL_reg   (*((volatile unsigned int*) IC6_RX_TL_reg))
#define IC6_RX_TL_inst_adr                                                           "0x008E"
#define IC6_RX_TL_inst                                                               0x008E
#define IC6_RX_TL_RX_TL_shift                                                        (0)
#define IC6_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC6_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC6_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC6_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC6_TX_TL                                                                    0x18007E3C
#define IC6_TX_TL_reg_addr                                                           "0x18007E3C"
#define IC6_TX_TL_reg                                                                0x18007E3C
#define set_IC6_TX_TL_reg(data)   (*((volatile unsigned int*) IC6_TX_TL_reg)=data)
#define get_IC6_TX_TL_reg   (*((volatile unsigned int*) IC6_TX_TL_reg))
#define IC6_TX_TL_inst_adr                                                           "0x008F"
#define IC6_TX_TL_inst                                                               0x008F
#define IC6_TX_TL_TX_TL_shift                                                        (0)
#define IC6_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC6_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC6_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC6_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC6_CLR_INTR                                                                 0x18007E40
#define IC6_CLR_INTR_reg_addr                                                        "0x18007E40"
#define IC6_CLR_INTR_reg                                                             0x18007E40
#define set_IC6_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC6_CLR_INTR_reg)=data)
#define get_IC6_CLR_INTR_reg   (*((volatile unsigned int*) IC6_CLR_INTR_reg))
#define IC6_CLR_INTR_inst_adr                                                        "0x0090"
#define IC6_CLR_INTR_inst                                                            0x0090
#define IC6_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC6_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC6_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC6_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC6_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC6_CLR_RX_UNDER                                                             0x18007E44
#define IC6_CLR_RX_UNDER_reg_addr                                                    "0x18007E44"
#define IC6_CLR_RX_UNDER_reg                                                         0x18007E44
#define set_IC6_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC6_CLR_RX_UNDER_reg)=data)
#define get_IC6_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC6_CLR_RX_UNDER_reg))
#define IC6_CLR_RX_UNDER_inst_adr                                                    "0x0091"
#define IC6_CLR_RX_UNDER_inst                                                        0x0091
#define IC6_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC6_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC6_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC6_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC6_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC6_CLR_RX_OVER                                                              0x18007E48
#define IC6_CLR_RX_OVER_reg_addr                                                     "0x18007E48"
#define IC6_CLR_RX_OVER_reg                                                          0x18007E48
#define set_IC6_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC6_CLR_RX_OVER_reg)=data)
#define get_IC6_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC6_CLR_RX_OVER_reg))
#define IC6_CLR_RX_OVER_inst_adr                                                     "0x0092"
#define IC6_CLR_RX_OVER_inst                                                         0x0092
#define IC6_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC6_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC6_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC6_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC6_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC6_CLR_TX_OVER                                                              0x18007E4C
#define IC6_CLR_TX_OVER_reg_addr                                                     "0x18007E4C"
#define IC6_CLR_TX_OVER_reg                                                          0x18007E4C
#define set_IC6_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC6_CLR_TX_OVER_reg)=data)
#define get_IC6_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC6_CLR_TX_OVER_reg))
#define IC6_CLR_TX_OVER_inst_adr                                                     "0x0093"
#define IC6_CLR_TX_OVER_inst                                                         0x0093
#define IC6_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC6_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC6_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC6_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC6_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC6_CLR_RD_REQ                                                               0x18007E50
#define IC6_CLR_RD_REQ_reg_addr                                                      "0x18007E50"
#define IC6_CLR_RD_REQ_reg                                                           0x18007E50
#define set_IC6_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC6_CLR_RD_REQ_reg)=data)
#define get_IC6_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC6_CLR_RD_REQ_reg))
#define IC6_CLR_RD_REQ_inst_adr                                                      "0x0094"
#define IC6_CLR_RD_REQ_inst                                                          0x0094
#define IC6_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC6_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC6_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC6_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC6_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC6_CLR_TX_ABRT                                                              0x18007E54
#define IC6_CLR_TX_ABRT_reg_addr                                                     "0x18007E54"
#define IC6_CLR_TX_ABRT_reg                                                          0x18007E54
#define set_IC6_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC6_CLR_TX_ABRT_reg)=data)
#define get_IC6_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC6_CLR_TX_ABRT_reg))
#define IC6_CLR_TX_ABRT_inst_adr                                                     "0x0095"
#define IC6_CLR_TX_ABRT_inst                                                         0x0095
#define IC6_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC6_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC6_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC6_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC6_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC6_CLR_RX_DONE                                                              0x18007E58
#define IC6_CLR_RX_DONE_reg_addr                                                     "0x18007E58"
#define IC6_CLR_RX_DONE_reg                                                          0x18007E58
#define set_IC6_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC6_CLR_RX_DONE_reg)=data)
#define get_IC6_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC6_CLR_RX_DONE_reg))
#define IC6_CLR_RX_DONE_inst_adr                                                     "0x0096"
#define IC6_CLR_RX_DONE_inst                                                         0x0096
#define IC6_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC6_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC6_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC6_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC6_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC6_CLR_ACTIVITY                                                             0x18007E5C
#define IC6_CLR_ACTIVITY_reg_addr                                                    "0x18007E5C"
#define IC6_CLR_ACTIVITY_reg                                                         0x18007E5C
#define set_IC6_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC6_CLR_ACTIVITY_reg)=data)
#define get_IC6_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC6_CLR_ACTIVITY_reg))
#define IC6_CLR_ACTIVITY_inst_adr                                                    "0x0097"
#define IC6_CLR_ACTIVITY_inst                                                        0x0097
#define IC6_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC6_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC6_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC6_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC6_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC6_CLR_STOP_DET                                                             0x18007E60
#define IC6_CLR_STOP_DET_reg_addr                                                    "0x18007E60"
#define IC6_CLR_STOP_DET_reg                                                         0x18007E60
#define set_IC6_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC6_CLR_STOP_DET_reg)=data)
#define get_IC6_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC6_CLR_STOP_DET_reg))
#define IC6_CLR_STOP_DET_inst_adr                                                    "0x0098"
#define IC6_CLR_STOP_DET_inst                                                        0x0098
#define IC6_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC6_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC6_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC6_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC6_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC6_CLR_START_DET                                                            0x18007E64
#define IC6_CLR_START_DET_reg_addr                                                   "0x18007E64"
#define IC6_CLR_START_DET_reg                                                        0x18007E64
#define set_IC6_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC6_CLR_START_DET_reg)=data)
#define get_IC6_CLR_START_DET_reg   (*((volatile unsigned int*) IC6_CLR_START_DET_reg))
#define IC6_CLR_START_DET_inst_adr                                                   "0x0099"
#define IC6_CLR_START_DET_inst                                                       0x0099
#define IC6_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC6_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC6_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC6_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC6_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC6_CLR_GEN_CALL                                                             0x18007E68
#define IC6_CLR_GEN_CALL_reg_addr                                                    "0x18007E68"
#define IC6_CLR_GEN_CALL_reg                                                         0x18007E68
#define set_IC6_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC6_CLR_GEN_CALL_reg)=data)
#define get_IC6_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC6_CLR_GEN_CALL_reg))
#define IC6_CLR_GEN_CALL_inst_adr                                                    "0x009A"
#define IC6_CLR_GEN_CALL_inst                                                        0x009A
#define IC6_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC6_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC6_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC6_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC6_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC6_ENABLE                                                                   0x18007E6C
#define IC6_ENABLE_reg_addr                                                          "0x18007E6C"
#define IC6_ENABLE_reg                                                               0x18007E6C
#define set_IC6_ENABLE_reg(data)   (*((volatile unsigned int*) IC6_ENABLE_reg)=data)
#define get_IC6_ENABLE_reg   (*((volatile unsigned int*) IC6_ENABLE_reg))
#define IC6_ENABLE_inst_adr                                                          "0x009B"
#define IC6_ENABLE_inst                                                              0x009B
#define IC6_ENABLE_ENABLE_shift                                                      (0)
#define IC6_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC6_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC6_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC6_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC6_STATUS                                                                   0x18007E70
#define IC6_STATUS_reg_addr                                                          "0x18007E70"
#define IC6_STATUS_reg                                                               0x18007E70
#define set_IC6_STATUS_reg(data)   (*((volatile unsigned int*) IC6_STATUS_reg)=data)
#define get_IC6_STATUS_reg   (*((volatile unsigned int*) IC6_STATUS_reg))
#define IC6_STATUS_inst_adr                                                          "0x009C"
#define IC6_STATUS_inst                                                              0x009C
#define IC6_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC6_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC6_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC6_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC6_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC6_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC6_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC6_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC6_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC6_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC6_STATUS_RFF_shift                                                         (4)
#define IC6_STATUS_RFF_mask                                                          (0x00000010)
#define IC6_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC6_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC6_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC6_STATUS_RFNE_shift                                                        (3)
#define IC6_STATUS_RFNE_mask                                                         (0x00000008)
#define IC6_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC6_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC6_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC6_STATUS_TFE_shift                                                         (2)
#define IC6_STATUS_TFE_mask                                                          (0x00000004)
#define IC6_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC6_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC6_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC6_STATUS_TFNF_shift                                                        (1)
#define IC6_STATUS_TFNF_mask                                                         (0x00000002)
#define IC6_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC6_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC6_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC6_STATUS_ACTIVITY_shift                                                    (0)
#define IC6_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC6_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC6_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC6_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC6_TXFLR                                                                    0x18007E74
#define IC6_TXFLR_reg_addr                                                           "0x18007E74"
#define IC6_TXFLR_reg                                                                0x18007E74
#define set_IC6_TXFLR_reg(data)   (*((volatile unsigned int*) IC6_TXFLR_reg)=data)
#define get_IC6_TXFLR_reg   (*((volatile unsigned int*) IC6_TXFLR_reg))
#define IC6_TXFLR_inst_adr                                                           "0x009D"
#define IC6_TXFLR_inst                                                               0x009D
#define IC6_TXFLR_TXFLR_shift                                                        (0)
#define IC6_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC6_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC6_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC6_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC6_RXFLR                                                                    0x18007E78
#define IC6_RXFLR_reg_addr                                                           "0x18007E78"
#define IC6_RXFLR_reg                                                                0x18007E78
#define set_IC6_RXFLR_reg(data)   (*((volatile unsigned int*) IC6_RXFLR_reg)=data)
#define get_IC6_RXFLR_reg   (*((volatile unsigned int*) IC6_RXFLR_reg))
#define IC6_RXFLR_inst_adr                                                           "0x009E"
#define IC6_RXFLR_inst                                                               0x009E
#define IC6_RXFLR_RXFLR_shift                                                        (0)
#define IC6_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC6_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC6_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC6_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC6_SDA_HOLD                                                                 0x18007E7C
#define IC6_SDA_HOLD_reg_addr                                                        "0x18007E7C"
#define IC6_SDA_HOLD_reg                                                             0x18007E7C
#define set_IC6_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC6_SDA_HOLD_reg)=data)
#define get_IC6_SDA_HOLD_reg   (*((volatile unsigned int*) IC6_SDA_HOLD_reg))
#define IC6_SDA_HOLD_inst_adr                                                        "0x009F"
#define IC6_SDA_HOLD_inst                                                            0x009F
#define IC6_SDA_HOLD_IC_SDA_HOLD_shift                                               (0)
#define IC6_SDA_HOLD_IC_SDA_HOLD_mask                                                (0x0000FFFF)
#define IC6_SDA_HOLD_IC_SDA_HOLD(data)                                               (0x0000FFFF&((data)<<0))
#define IC6_SDA_HOLD_IC_SDA_HOLD_src(data)                                           ((0x0000FFFF&(data))>>0)
#define IC6_SDA_HOLD_get_IC_SDA_HOLD(data)                                           ((0x0000FFFF&(data))>>0)


#define IC6_TX_ABRT_SOURCE                                                           0x18007E80
#define IC6_TX_ABRT_SOURCE_reg_addr                                                  "0x18007E80"
#define IC6_TX_ABRT_SOURCE_reg                                                       0x18007E80
#define set_IC6_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC6_TX_ABRT_SOURCE_reg)=data)
#define get_IC6_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC6_TX_ABRT_SOURCE_reg))
#define IC6_TX_ABRT_SOURCE_inst_adr                                                  "0x00A0"
#define IC6_TX_ABRT_SOURCE_inst                                                      0x00A0
#define IC6_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC6_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC6_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC6_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC6_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC6_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC6_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC6_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC6_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC6_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC6_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC6_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC6_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC6_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC6_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC6_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC6_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC6_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC6_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC6_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC6_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC6_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC6_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC6_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC6_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC6_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC6_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC6_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC6_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC6_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC6_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC6_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC6_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC6_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC6_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC6_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC6_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC6_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC6_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC6_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC6_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC6_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC6_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC6_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC6_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC6_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC6_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC6_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC6_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC6_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC6_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC6_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC6_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC6_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC6_SLV_DATA_NACK_ONLY                                                       0x18007E84
#define IC6_SLV_DATA_NACK_ONLY_reg_addr                                              "0x18007E84"
#define IC6_SLV_DATA_NACK_ONLY_reg                                                   0x18007E84
#define set_IC6_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC6_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC6_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC6_SLV_DATA_NACK_ONLY_reg))
#define IC6_SLV_DATA_NACK_ONLY_inst_adr                                              "0x00A1"
#define IC6_SLV_DATA_NACK_ONLY_inst                                                  0x00A1
#define IC6_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC6_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC6_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC6_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC6_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC6_DMA_CR                                                                   0x18007E88
#define IC6_DMA_CR_reg_addr                                                          "0x18007E88"
#define IC6_DMA_CR_reg                                                               0x18007E88
#define set_IC6_DMA_CR_reg(data)   (*((volatile unsigned int*) IC6_DMA_CR_reg)=data)
#define get_IC6_DMA_CR_reg   (*((volatile unsigned int*) IC6_DMA_CR_reg))
#define IC6_DMA_CR_inst_adr                                                          "0x00A2"
#define IC6_DMA_CR_inst                                                              0x00A2
#define IC6_DMA_CR_TDMAE_shift                                                       (1)
#define IC6_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC6_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC6_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC6_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC6_DMA_CR_RDMAE_shift                                                       (0)
#define IC6_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC6_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC6_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC6_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC6_DMA_TDLR                                                                 0x18007E8C
#define IC6_DMA_TDLR_reg_addr                                                        "0x18007E8C"
#define IC6_DMA_TDLR_reg                                                             0x18007E8C
#define set_IC6_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC6_DMA_TDLR_reg)=data)
#define get_IC6_DMA_TDLR_reg   (*((volatile unsigned int*) IC6_DMA_TDLR_reg))
#define IC6_DMA_TDLR_inst_adr                                                        "0x00A3"
#define IC6_DMA_TDLR_inst                                                            0x00A3
#define IC6_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC6_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC6_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC6_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC6_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC6_DMA_RDLR                                                                 0x18007E90
#define IC6_DMA_RDLR_reg_addr                                                        "0x18007E90"
#define IC6_DMA_RDLR_reg                                                             0x18007E90
#define set_IC6_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC6_DMA_RDLR_reg)=data)
#define get_IC6_DMA_RDLR_reg   (*((volatile unsigned int*) IC6_DMA_RDLR_reg))
#define IC6_DMA_RDLR_inst_adr                                                        "0x00A4"
#define IC6_DMA_RDLR_inst                                                            0x00A4
#define IC6_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC6_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC6_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC6_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC6_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC6_SDA_SETUP                                                                0x18007E94
#define IC6_SDA_SETUP_reg_addr                                                       "0x18007E94"
#define IC6_SDA_SETUP_reg                                                            0x18007E94
#define set_IC6_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC6_SDA_SETUP_reg)=data)
#define get_IC6_SDA_SETUP_reg   (*((volatile unsigned int*) IC6_SDA_SETUP_reg))
#define IC6_SDA_SETUP_inst_adr                                                       "0x00A5"
#define IC6_SDA_SETUP_inst                                                           0x00A5
#define IC6_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC6_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC6_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC6_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC6_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC6_ACK_GENERAL_CALL                                                         0x18007E98
#define IC6_ACK_GENERAL_CALL_reg_addr                                                "0x18007E98"
#define IC6_ACK_GENERAL_CALL_reg                                                     0x18007E98
#define set_IC6_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC6_ACK_GENERAL_CALL_reg)=data)
#define get_IC6_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC6_ACK_GENERAL_CALL_reg))
#define IC6_ACK_GENERAL_CALL_inst_adr                                                "0x00A6"
#define IC6_ACK_GENERAL_CALL_inst                                                    0x00A6
#define IC6_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC6_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC6_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC6_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC6_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC6_ENABLE_STATUS                                                            0x18007E9C
#define IC6_ENABLE_STATUS_reg_addr                                                   "0x18007E9C"
#define IC6_ENABLE_STATUS_reg                                                        0x18007E9C
#define set_IC6_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC6_ENABLE_STATUS_reg)=data)
#define get_IC6_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC6_ENABLE_STATUS_reg))
#define IC6_ENABLE_STATUS_inst_adr                                                   "0x00A7"
#define IC6_ENABLE_STATUS_inst                                                       0x00A7
#define IC6_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC6_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC6_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC6_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC6_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC6_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC6_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC6_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC6_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC6_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC6_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC6_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC6_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC6_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC6_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC6_COMP_PARAM_1                                                             0x18007EF4
#define IC6_COMP_PARAM_1_reg_addr                                                    "0x18007EF4"
#define IC6_COMP_PARAM_1_reg                                                         0x18007EF4
#define set_IC6_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC6_COMP_PARAM_1_reg)=data)
#define get_IC6_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC6_COMP_PARAM_1_reg))
#define IC6_COMP_PARAM_1_inst_adr                                                    "0x00BD"
#define IC6_COMP_PARAM_1_inst                                                        0x00BD
#define IC6_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC6_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC6_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC6_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC6_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC6_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC6_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC6_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC6_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC6_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC6_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC6_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC6_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC6_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC6_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC6_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC6_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC6_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC6_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC6_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC6_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC6_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC6_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC6_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC6_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC6_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC6_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC6_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC6_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC6_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC6_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC6_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC6_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC6_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC6_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC6_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC6_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC6_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC6_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC6_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC6_COMP_VERSION                                                             0x18007EF8
#define IC6_COMP_VERSION_reg_addr                                                    "0x18007EF8"
#define IC6_COMP_VERSION_reg                                                         0x18007EF8
#define set_IC6_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC6_COMP_VERSION_reg)=data)
#define get_IC6_COMP_VERSION_reg   (*((volatile unsigned int*) IC6_COMP_VERSION_reg))
#define IC6_COMP_VERSION_inst_adr                                                    "0x00BE"
#define IC6_COMP_VERSION_inst                                                        0x00BE
#define IC6_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC6_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC6_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC6_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC6_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC6_COMP_TYPE                                                                0x18007EFC
#define IC6_COMP_TYPE_reg_addr                                                       "0x18007EFC"
#define IC6_COMP_TYPE_reg                                                            0x18007EFC
#define set_IC6_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC6_COMP_TYPE_reg)=data)
#define get_IC6_COMP_TYPE_reg   (*((volatile unsigned int*) IC6_COMP_TYPE_reg))
#define IC6_COMP_TYPE_inst_adr                                                       "0x00BF"
#define IC6_COMP_TYPE_inst                                                           0x00BF
#define IC6_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC6_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC6_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC6_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC6_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define PWM_OCD                                                                      0x180070D0
#define PWM_OCD_reg_addr                                                             "0x180070D0"
#define PWM_OCD_reg                                                                  0x180070D0
#define set_PWM_OCD_reg(data)   (*((volatile unsigned int*) PWM_OCD_reg)=data)
#define get_PWM_OCD_reg   (*((volatile unsigned int*) PWM_OCD_reg))
#define PWM_OCD_inst_adr                                                             "0x0034"
#define PWM_OCD_inst                                                                 0x0034
#define PWM_OCD_3_shift                                                              (24)
#define PWM_OCD_3_mask                                                               (0xFF000000)
#define PWM_OCD_3(data)                                                              (0xFF000000&((data)<<24))
#define PWM_OCD_3_src(data)                                                          ((0xFF000000&(data))>>24)
#define PWM_OCD_get_3(data)                                                          ((0xFF000000&(data))>>24)
#define PWM_OCD_2_shift                                                              (16)
#define PWM_OCD_2_mask                                                               (0x00FF0000)
#define PWM_OCD_2(data)                                                              (0x00FF0000&((data)<<16))
#define PWM_OCD_2_src(data)                                                          ((0x00FF0000&(data))>>16)
#define PWM_OCD_get_2(data)                                                          ((0x00FF0000&(data))>>16)
#define PWM_OCD_1_shift                                                              (8)
#define PWM_OCD_1_mask                                                               (0x0000FF00)
#define PWM_OCD_1(data)                                                              (0x0000FF00&((data)<<8))
#define PWM_OCD_1_src(data)                                                          ((0x0000FF00&(data))>>8)
#define PWM_OCD_get_1(data)                                                          ((0x0000FF00&(data))>>8)
#define PWM_OCD_0_shift                                                              (0)
#define PWM_OCD_0_mask                                                               (0x000000FF)
#define PWM_OCD_0(data)                                                              (0x000000FF&((data)<<0))
#define PWM_OCD_0_src(data)                                                          ((0x000000FF&(data))>>0)
#define PWM_OCD_get_0(data)                                                          ((0x000000FF&(data))>>0)


#define PWM_CD                                                                       0x180070D4
#define PWM_CD_reg_addr                                                              "0x180070D4"
#define PWM_CD_reg                                                                   0x180070D4
#define set_PWM_CD_reg(data)   (*((volatile unsigned int*) PWM_CD_reg)=data)
#define get_PWM_CD_reg   (*((volatile unsigned int*) PWM_CD_reg))
#define PWM_CD_inst_adr                                                              "0x0035"
#define PWM_CD_inst                                                                  0x0035
#define PWM_CD_3_shift                                                               (24)
#define PWM_CD_3_mask                                                                (0xFF000000)
#define PWM_CD_3(data)                                                               (0xFF000000&((data)<<24))
#define PWM_CD_3_src(data)                                                           ((0xFF000000&(data))>>24)
#define PWM_CD_get_3(data)                                                           ((0xFF000000&(data))>>24)
#define PWM_CD_2_shift                                                               (16)
#define PWM_CD_2_mask                                                                (0x00FF0000)
#define PWM_CD_2(data)                                                               (0x00FF0000&((data)<<16))
#define PWM_CD_2_src(data)                                                           ((0x00FF0000&(data))>>16)
#define PWM_CD_get_2(data)                                                           ((0x00FF0000&(data))>>16)
#define PWM_CD_1_shift                                                               (8)
#define PWM_CD_1_mask                                                                (0x0000FF00)
#define PWM_CD_1(data)                                                               (0x0000FF00&((data)<<8))
#define PWM_CD_1_src(data)                                                           ((0x0000FF00&(data))>>8)
#define PWM_CD_get_1(data)                                                           ((0x0000FF00&(data))>>8)
#define PWM_CD_0_shift                                                               (0)
#define PWM_CD_0_mask                                                                (0x000000FF)
#define PWM_CD_0(data)                                                               (0x000000FF&((data)<<0))
#define PWM_CD_0_src(data)                                                           ((0x000000FF&(data))>>0)
#define PWM_CD_get_0(data)                                                           ((0x000000FF&(data))>>0)


#define PWM_CSD                                                                      0x180070D8
#define PWM_CSD_reg_addr                                                             "0x180070D8"
#define PWM_CSD_reg                                                                  0x180070D8
#define set_PWM_CSD_reg(data)   (*((volatile unsigned int*) PWM_CSD_reg)=data)
#define get_PWM_CSD_reg   (*((volatile unsigned int*) PWM_CSD_reg))
#define PWM_CSD_inst_adr                                                             "0x0036"
#define PWM_CSD_inst                                                                 0x0036
#define PWM_CSD_3_shift                                                              (12)
#define PWM_CSD_3_mask                                                               (0x0000F000)
#define PWM_CSD_3(data)                                                              (0x0000F000&((data)<<12))
#define PWM_CSD_3_src(data)                                                          ((0x0000F000&(data))>>12)
#define PWM_CSD_get_3(data)                                                          ((0x0000F000&(data))>>12)
#define PWM_CSD_2_shift                                                              (8)
#define PWM_CSD_2_mask                                                               (0x00000F00)
#define PWM_CSD_2(data)                                                              (0x00000F00&((data)<<8))
#define PWM_CSD_2_src(data)                                                          ((0x00000F00&(data))>>8)
#define PWM_CSD_get_2(data)                                                          ((0x00000F00&(data))>>8)
#define PWM_CSD_1_shift                                                              (4)
#define PWM_CSD_1_mask                                                               (0x000000F0)
#define PWM_CSD_1(data)                                                              (0x000000F0&((data)<<4))
#define PWM_CSD_1_src(data)                                                          ((0x000000F0&(data))>>4)
#define PWM_CSD_get_1(data)                                                          ((0x000000F0&(data))>>4)
#define PWM_CSD_0_shift                                                              (0)
#define PWM_CSD_0_mask                                                               (0x0000000F)
#define PWM_CSD_0(data)                                                              (0x0000000F&((data)<<0))
#define PWM_CSD_0_src(data)                                                          ((0x0000000F&(data))>>0)
#define PWM_CSD_get_0(data)                                                          ((0x0000000F&(data))>>0)


#endif
