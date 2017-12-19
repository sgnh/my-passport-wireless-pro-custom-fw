/**************************************************************
// Spec Version                  : 0.12
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/14 14:19:27
***************************************************************/


#ifndef _ISO_REG_H_INCLUDED_
#define _ISO_REG_H_INCLUDED_
#ifdef  _ISO_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     DDC0_INT:1;
unsigned int     reserved_4:1;
unsigned int     reserved_5:1;
unsigned int     reserved_6:1;
unsigned int     reserved_7:1;
unsigned int     reserved_8:1;
unsigned int     reserved_9:1;
unsigned int     reserved_10:1;
unsigned int     LSADC_INT:1;
unsigned int     reserved_11:4;
unsigned int     IRDA_INT:1;
unsigned int     reserved_12:1;
unsigned int     ISO_TC0_INT:1;
unsigned int     reserved_13:1;
unsigned int     reserved_14:1;
unsigned int     write_data:1;
}ISO_ISR;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     DDC0_INT:1;
unsigned int     reserved_4:7;
unsigned int     LSADC_INT:1;
unsigned int     reserved_5:4;
unsigned int     IRDA_INT:1;
unsigned int     reserved_6:1;
unsigned int     ISO_TC0_INT:1;
unsigned int     reserved_7:1;
unsigned int     reserved_8:1;
unsigned int     write_data:1;
}UMSK_ISO_ISR;

typedef struct 
{
unsigned int     INT30_A:1;
unsigned int     INT29_A:1;
unsigned int     INT28_A:1;
unsigned int     INT27_A:1;
unsigned int     INT26_A:1;
unsigned int     INT25_A:1;
unsigned int     INT24_A:1;
unsigned int     INT23_A:1;
unsigned int     INT22_A:1;
unsigned int     INT21_A:1;
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
}UMSK_ISR_GP_ASSERT;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     INT39_A:1;
unsigned int     INT38_A:1;
unsigned int     INT37_A:1;
unsigned int     INT36_A:1;
unsigned int     INT35_A:1;
unsigned int     INT34_A:1;
unsigned int     INT33_A:1;
unsigned int     INT32_A:1;
unsigned int     INT31_A:1;
unsigned int     write_data:1;
}UMSK_ISR_GP_ASSERT_1;

typedef struct 
{
unsigned int     INT30_DA:1;
unsigned int     INT29_DA:1;
unsigned int     INT28_DA:1;
unsigned int     INT27_DA:1;
unsigned int     INT26_DA:1;
unsigned int     INT25_DA:1;
unsigned int     INT24_DA:1;
unsigned int     INT23_DA:1;
unsigned int     INT22_DA:1;
unsigned int     INT21_DA:1;
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
}UMSK_ISR_GP_DEASSERT;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     INT39_DA:1;
unsigned int     INT38_DA:1;
unsigned int     INT37_DA:1;
unsigned int     INT36_DA:1;
unsigned int     INT35_DA:1;
unsigned int     INT34_DA:1;
unsigned int     INT33_DA:1;
unsigned int     INT32_DA:1;
unsigned int     INT31_DA:1;
unsigned int     write_data:1;
}UMSK_ISR_GP_DEASSERT_1;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_en3:1;
unsigned int     sel1:4;
unsigned int     write_en2:1;
unsigned int     sel0:4;
unsigned int     write_en1:1;
unsigned int     enable:1;
}ISO_DBG;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     Rvd2:13;
unsigned int     Irdarxdetec:1;
unsigned int     DDCdataindetect:1;
unsigned int     write_en1:1;
unsigned int     Rvd1:15;
}ISO_DUMMY1;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     testmode:1;
unsigned int     nf_sel:1;
unsigned int     reserved_1:2;
unsigned int     bound_opt:10;
}CHIP_INFO1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     DDC0_INT:1;
unsigned int     reserved_4:1;
unsigned int     reserved_5:1;
unsigned int     reserved_6:1;
unsigned int     reserved_7:1;
unsigned int     reserved_8:1;
unsigned int     reserved_9:1;
unsigned int     reserved_10:1;
unsigned int     LSADC_INT:1;
unsigned int     reserved_11:4;
unsigned int     IRDA_INT:1;
unsigned int     reserved_12:1;
unsigned int     TC0_INT:1;
unsigned int     reserved_13:1;
unsigned int     reserved_14:1;
unsigned int     write_data:1;
}ISO_SCPU_INT_EN;

typedef struct 
{
unsigned int     GPDIR:32;
}GPDIR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     GPDIR:8;
}GPDIR_1;

typedef struct 
{
unsigned int     GPDATO:32;
}GPDATO;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     GPDATO:8;
}GPDATO_1;

typedef struct 
{
unsigned int     GPDATI:32;
}GPDATI;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     GPDATI:8;
}GPDATI_1;

typedef struct 
{
unsigned int     GP:32;
}GPIE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     GP:8;
}GPIE_1;

typedef struct 
{
unsigned int     GPHA:32;
}GPDP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     GPHA:8;
}GPDP_1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     write_en2:1;
unsigned int     CLK2:3;
unsigned int     write_en1:1;
unsigned int     CLK1:3;
}ISO_GPDEB;

typedef struct 
{
unsigned int     MIS_PWM_W_DB_EN:1;
unsigned int     MIS_PWM_DB_RSEL:1;
unsigned int     MIS_PWM_W_DB_WR:1;
unsigned int     MIS_PWM_W_DB_MODE:1;
unsigned int     reserved_0:28;
}MIS_PWM_DB_CTRL;

typedef struct 
{
unsigned int     MIS_PWM0L:1;
unsigned int     MIS_PWM0_CK:1;
unsigned int     MIS_PWM0_EN:1;
unsigned int     MIS_PWM0_VS_RST_EN:1;
unsigned int     MIS_PWM0_DUT_8B:1;
unsigned int     reserved_0:22;
unsigned int     reserved_1:4;
unsigned int     MIS_PWM_WIDTH_SEL:1;
}MIS_PWM0_CTRL;

typedef struct 
{
unsigned int     MIS_PWM0_CNT_MODE:1;
unsigned int     MIS_PWM0_CK_SEL_HS:1;
unsigned int     MIS_PWM0_CK_SEL:1;
unsigned int     reserved_0:1;
unsigned int     MIS_PWM0_CYCLE_MAX:4;
unsigned int     reserved_1:10;
unsigned int     MIS_PWM0_M:2;
unsigned int     MIS_PWM0_N:12;
}MIS_PWM0_TIMING_CTRL;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     MIS_PWM0_DUT:12;
unsigned int     reserved_1:4;
unsigned int     MIS_PWM0_TOTALCNT:12;
}MIS_PWM0_DUTY_SET;

typedef struct 
{
unsigned int     MIS_PWM1L:1;
unsigned int     MIS_PWM1_CK:1;
unsigned int     MIS_PWM1_EN:1;
unsigned int     MIS_PWM1_VS_RST_EN:1;
unsigned int     MIS_PWM1_DUT_8B:1;
unsigned int     reserved_0:22;
unsigned int     reserved_1:5;
}MIS_PWM1_CTRL;

typedef struct 
{
unsigned int     MIS_PWM1_CNT_MODE:1;
unsigned int     MIS_PWM1_CK_SEL_HS:1;
unsigned int     MIS_PWM1_CK_SEL:1;
unsigned int     reserved_0:1;
unsigned int     MIS_PWM1_CYCLE_MAX:4;
unsigned int     reserved_1:10;
unsigned int     MIS_PWM1_M:2;
unsigned int     MIS_PWM1_N:12;
}MIS_PWM1_TIMING_CTRL;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     MIS_PWM1_DUT:12;
unsigned int     reserved_1:4;
unsigned int     MIS_PWM1_TOTALCNT:12;
}MIS_PWM1_DUTY_SET;

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
unsigned int     IRIT:8;
unsigned int     IROCT:8;
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
unsigned int     reserved_0:7;
unsigned int     IREDNM:1;
unsigned int     RC5_RC6commonmodeenable:1;
unsigned int     IREDN:6;
unsigned int     burst_len_check:1;
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
unsigned int     reserved_0:25;
unsigned int     leader_wrong:1;
unsigned int     data_still_toggle:1;
unsigned int     rmt_big:1;
unsigned int     raw_fifo_ov:1;
unsigned int     raw_fifo_val:1;
unsigned int     IRRF:1;
unsigned int     IRDVF:1;
}IR_SR;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en3:1;
unsigned int     Data_store_in_DRAM:1;
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
unsigned int     reserved_0:22;
unsigned int     toshiba_en:1;
unsigned int     RC6_EN:1;
unsigned int     IRTR:8;
}IR_CTRL_RC6;

typedef struct 
{
unsigned int     IRRP:32;
}IR_RP2;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IRRAWFD:16;
}IR_RAW_SF;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RP_NUM:4;
unsigned int     reserved_1:3;
unsigned int     EXT_RP_EN:1;
}IR_EXT_RP_CF;

typedef struct 
{
unsigned int     RP_BURST:8;
unsigned int     RP_SILENCE:8;
unsigned int     RP_TAIL_BURST:8;
unsigned int     RP_TAIL_SILENCE:8;
}IR_EXT_RP_TIMING;

typedef struct 
{
unsigned int     RP_BURST:8;
unsigned int     RP_SILENCE:8;
unsigned int     RP_TAIL_BURST:8;
unsigned int     RP_TAIL_SILENCE:8;
}IR_EXT_RP_TIMING_UP;

typedef struct 
{
unsigned int     D_ADDR:32;
}IR_RAW_MODE_DBUS_ADDR;

typedef struct 
{
unsigned int     IRRBL_:8;
unsigned int     IRRML:8;
unsigned int     IRRDZL:8;
unsigned int     IRRDOL:8;
}IR_PSR_RC5_RC6;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     IRRDL:6;
unsigned int     IRRRL:8;
unsigned int     IRRSL:8;
}IR_PER_RC5_RC6;

typedef struct 
{
unsigned int     HW_decode_data0L:32;
}HW_DECODE_DATA0_L;

typedef struct 
{
unsigned int     HW_decode_data0H:32;
}HW_DECODE_DATA0_H;

typedef struct 
{
unsigned int     Decode_Mask_data0L:32;
}DECODE_MASK_DATA0_L;

typedef struct 
{
unsigned int     Decode_Mask_data0H:32;
}DECODE_MASK_DATA0_H;

typedef struct 
{
unsigned int     HW_decode_data1L:32;
}HW_DECODE_DATA1_L;

typedef struct 
{
unsigned int     HW_decode_data1H:32;
}HW_DECODE_DATA1_H;

typedef struct 
{
unsigned int     Decode_Mask_data1L:32;
}DECODE_MASK_DATA1_L;

typedef struct 
{
unsigned int     Decode_Mask_data1H:32;
}DECODE_MASK_DATA1_H;

typedef struct 
{
unsigned int     HW_decode_data2L:32;
}HW_DECODE_DATA2_L;

typedef struct 
{
unsigned int     HW_decode_data2H:32;
}HW_DECODE_DATA2_H;

typedef struct 
{
unsigned int     Decode_Mask_data2L:32;
}DECODE_MASK_DATA2_L;

typedef struct 
{
unsigned int     Decode_Mask_data2H:32;
}DECODE_MASK_DATA2_H;

typedef struct 
{
unsigned int     HW_decode_data3L:32;
}HW_DECODE_DATA3_L;

typedef struct 
{
unsigned int     HW_decode_data3H:32;
}HW_DECODE_DATA3_H;

typedef struct 
{
unsigned int     Decode_Mask_data3L:32;
}DECODE_MASK_DATA3_L;

typedef struct 
{
unsigned int     Decode_Mask_data3H:32;
}DECODE_MASK_DATA3_H;

typedef struct 
{
unsigned int     HW_decode_data4L:32;
}HW_DECODE_DATA4_L;

typedef struct 
{
unsigned int     HW_decode_data4H:32;
}HW_DECODE_DATA4_H;

typedef struct 
{
unsigned int     Decode_Mask_data4L:32;
}DECODE_MASK_DATA4_L;

typedef struct 
{
unsigned int     Decode_Mask_data4H:32;
}DECODE_MASK_DATA4_H;

typedef struct 
{
unsigned int     HW_decode_data5L:32;
}HW_DECODE_DATA5_L;

typedef struct 
{
unsigned int     HW_decode_data5H:32;
}HW_DECODE_DATA5_H;

typedef struct 
{
unsigned int     Decode_Mask_data5L:32;
}DECODE_MASK_DATA5_L;

typedef struct 
{
unsigned int     Decode_Mask_data5H:32;
}DECODE_MASK_DATA5_H;

typedef struct 
{
unsigned int     HW_decode_data6L:32;
}HW_DECODE_DATA6_L;

typedef struct 
{
unsigned int     HW_decode_data62H:32;
}HW_DECODE_DATA6_H;

typedef struct 
{
unsigned int     Decode_Mask_data6L:32;
}DECODE_MASK_DATA6_L;

typedef struct 
{
unsigned int     Decode_Mask_data6H:32;
}DECODE_MASK_DATA6_H;

typedef struct 
{
unsigned int     HW_decode_data7L:32;
}HW_DECODE_DATA7_L;

typedef struct 
{
unsigned int     HW_decode_data7H:32;
}HW_DECODE_DATA7_H;

typedef struct 
{
unsigned int     Decode_Mask_data7L:32;
}DECODE_MASK_DATA7_L;

typedef struct 
{
unsigned int     Decode_Mask_data7H:32;
}DECODE_MASK_DATA7_H;

typedef struct 
{
unsigned int     Compare7_enable:1;
unsigned int     Compare6_enable:1;
unsigned int     Compare5_enable:1;
unsigned int     Compare4_enable:1;
unsigned int     Compare3_enable:1;
unsigned int     Compare2_enable:1;
unsigned int     Compare1_enable:1;
unsigned int     Compare0_enable:1;
unsigned int     INT_latchdata:8;
unsigned int     Compare7_INT_en:1;
unsigned int     Compare6_INT_en:1;
unsigned int     Compare5_INT_en:1;
unsigned int     Compare4_INT_en:1;
unsigned int     Compare3_INT_en:1;
unsigned int     Compare2_INT_en:1;
unsigned int     Compare1_INT_en:1;
unsigned int     Compare0_INT_en:1;
unsigned int     Compare7_INT_status:1;
unsigned int     Compare6_INT_status:1;
unsigned int     Compare5_INT_status:1;
unsigned int     Compare4_INT_status:1;
unsigned int     Compare3_INT_status:1;
unsigned int     Compare2_INT_status:1;
unsigned int     Compare1_INT_status:1;
unsigned int     Compare0_INT_status:1;
}INT_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     Test_mode_en:1;
}COMPARE_TEST_MODE;

typedef struct 
{
unsigned int     Test_mode_dataL:32;
}COMPARE_TEST_MODE_DATA7_L;

typedef struct 
{
unsigned int     Test_mode_dataH:32;
}COMPARE_TEST_MODE_DATA7_H;

typedef struct 
{
unsigned int     pad0_active:1;
unsigned int     reserved_0:7;
unsigned int     pad0_thred:8;
unsigned int     pad0_sw:4;
unsigned int     reserved_1:3;
unsigned int     pad0_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val0:6;
}ST_PAD0;

typedef struct 
{
unsigned int     pad1_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad1_thred:8;
unsigned int     Pad1_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad1_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     50:6;
}ST_PAD1;

typedef struct 
{
unsigned int     Pad2_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad2_thred:8;
unsigned int     Pad2_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad2_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val2:6;
}ST_PAD2;

typedef struct 
{
unsigned int     Pad3_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad3_thred:8;
unsigned int     Pad3_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad3_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val3:6;
}ST_PAD3;

typedef struct 
{
unsigned int     Pad4_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad4_thred:8;
unsigned int     Pad4_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad4_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val4:6;
}ST_PAD4;

typedef struct 
{
unsigned int     Pad5_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad5_thred:8;
unsigned int     Pad5_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad5_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val5:6;
}ST_PAD5;

typedef struct 
{
unsigned int     Pad6_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad6_thred:8;
unsigned int     Pad6_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad6_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val6:6;
}ST_PAD6;

typedef struct 
{
unsigned int     Pad7_active:1;
unsigned int     reserved_0:7;
unsigned int     Pad7_thred:8;
unsigned int     Pad7_sw:4;
unsigned int     reserved_1:3;
unsigned int     Pad7_ctrl:1;
unsigned int     reserved_2:2;
unsigned int     adc_val7:6;
}ST_PAD7;

typedef struct 
{
unsigned int     Sel_wait:4;
unsigned int     Sel_adc_ck:4;
unsigned int     Debounce_cnt:4;
unsigned int     reserved_0:4;
unsigned int     Dout_Test_IN:8;
unsigned int     reserved_1:6;
unsigned int     Test_en:1;
unsigned int     Enable:1;
}ST_LSADC_CTRL;

typedef struct 
{
unsigned int     IRQ_En:8;
unsigned int     PAD_CNT:4;
unsigned int     ADC_busy:1;
unsigned int     reserved_0:2;
unsigned int     pad_ctrl:5;
unsigned int     reserved_1:4;
unsigned int     Pad7_status:1;
unsigned int     Pad6_status:1;
unsigned int     Pad5_status:1;
unsigned int     Pad4_status:1;
unsigned int     Pad3_status:1;
unsigned int     Pad2_status:1;
unsigned int     Pad1_status:1;
unsigned int     Pad0_status:1;
}ST_LSADC_STATUS;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     JD_sbias:2;
unsigned int     reserved_1:2;
unsigned int     JD_adsbias:2;
unsigned int     JD_DUMMY:2;
unsigned int     reserved_2:1;
unsigned int     JD_svr:1;
unsigned int     reserved_3:3;
unsigned int     JD_adcksel:1;
unsigned int     reserved_4:3;
unsigned int     JD_power:1;
}ST_LSADC_ANALOG_CTRL;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     Lsadc_2_ifd_data_sel:3;
unsigned int     reserved_1:1;
unsigned int     Powersaving_enable:1;
unsigned int     Powersavingcycletime:3;
unsigned int     Powersaving:3;
unsigned int     peri_top_debug:8;
}ST_LSADC_PERI_TOP_DEBUG;

typedef struct 
{
unsigned int     Level_0_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block0_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en0:1;
unsigned int     INT_pending_bit0:1;
}LSADC_PAD5_LEVEL_SET0;

typedef struct 
{
unsigned int     Level_1_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block1_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en1:1;
unsigned int     INT_pending_bit1:1;
}LSADC_PAD5_LEVEL_SET1;

typedef struct 
{
unsigned int     Level_2_top_bound:8;
unsigned int     Level_2_low_bound:8;
unsigned int     Block2_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en2:1;
unsigned int     INT_pending_bit2:1;
}LSADC_PAD5_LEVEL_SET2;

typedef struct 
{
unsigned int     Level_3_top_bound:8;
unsigned int     Level_3_low_bound:8;
unsigned int     Block3_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en3:1;
unsigned int     INT_pending_bit3:1;
}LSADC_PAD5_LEVEL_SET3;

typedef struct 
{
unsigned int     Level_4_top_bound:8;
unsigned int     Level_4_low_bound:8;
unsigned int     Block4_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en4:1;
unsigned int     INT_pending_bit4:1;
}LSADC_PAD5_LEVEL_SET4;

typedef struct 
{
unsigned int     Level_5_top_bound:8;
unsigned int     Level_5_low_bound:8;
unsigned int     Block5_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en5:1;
unsigned int     INT_pending_bit5:1;
}LSADC_PAD5_LEVEL_SET5;

typedef struct 
{
unsigned int     Level_0_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block0_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en0:1;
unsigned int     INT_pending_bit0:1;
}LSADC_PAD6_LEVEL_SET0;

typedef struct 
{
unsigned int     Level_1_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block1_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en1:1;
unsigned int     INT_pending_bit1:1;
}LSADC_PAD6_LEVEL_SET1;

typedef struct 
{
unsigned int     Level_2_top_bound:8;
unsigned int     Level_2_low_bound:8;
unsigned int     Block2_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en2:1;
unsigned int     INT_pending_bit2:1;
}LSADC_PAD6_LEVEL_SET2;

typedef struct 
{
unsigned int     Level_3_top_bound:8;
unsigned int     Level_3_low_bound:8;
unsigned int     Block3_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en3:1;
unsigned int     INT_pending_bit3:1;
}LSADC_PAD6_LEVEL_SET3;

typedef struct 
{
unsigned int     Level_4_top_bound:8;
unsigned int     Level_4_low_bound:8;
unsigned int     Block4_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en4:1;
unsigned int     INT_pending_bit4:1;
}LSADC_PAD6_LEVEL_SET4;

typedef struct 
{
unsigned int     Level_5_top_bound:8;
unsigned int     Level_5_low_bound:8;
unsigned int     Block5_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en5:1;
unsigned int     INT_pending_bit5:1;
}LSADC_PAD6_LEVEL_SET5;

typedef struct 
{
unsigned int     Level_0_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block0_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en0:1;
unsigned int     INT_pending_bit0:1;
}LSADC_PAD7_LEVEL_SET0;

typedef struct 
{
unsigned int     Level_1_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block1_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en1:1;
unsigned int     INT_pending_bit1:1;
}LSADC_PAD7_LEVEL_SET1;

typedef struct 
{
unsigned int     Level_2_top_bound:8;
unsigned int     Level_2_low_bound:8;
unsigned int     Block2_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en2:1;
unsigned int     INT_pending_bit2:1;
}LSADC_PAD7_LEVEL_SET2;

typedef struct 
{
unsigned int     Level_3_top_bound:8;
unsigned int     Level_3_low_bound:8;
unsigned int     Block3_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en3:1;
unsigned int     INT_pending_bit3:1;
}LSADC_PAD7_LEVEL_SET3;

typedef struct 
{
unsigned int     Level_4_top_bound:8;
unsigned int     Level_4_low_bound:8;
unsigned int     Block4_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en4:1;
unsigned int     INT_pending_bit4:1;
}LSADC_PAD7_LEVEL_SET4;

typedef struct 
{
unsigned int     Level_5_top_bound:8;
unsigned int     Level_5_low_bound:8;
unsigned int     Block5_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en5:1;
unsigned int     INT_pending_bit5:1;
}LSADC_PAD7_LEVEL_SET5;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:2;
unsigned int     ADC_value5latch:6;
unsigned int     reserved_2:7;
unsigned int     INT_latchstatus:1;
}LSADC_INT_PAD5;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:2;
unsigned int     ADC_value6latch:6;
unsigned int     reserved_2:7;
unsigned int     INT_latchstatus:1;
}LSADC_INT_PAD6;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:2;
unsigned int     ADC_value7latch:6;
unsigned int     reserved_2:7;
unsigned int     INT_latchstatus:1;
}LSADC_INT_PAD7;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     CMDERR_IE:1;
unsigned int     TIMEOUT_EN:1;
unsigned int     DEBOUNCE_MODE:2;
unsigned int     TIMEOUT_IE:1;
unsigned int     RETIME_M:3;
}ST_I2C_CR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     CMDERR:1;
unsigned int     reserved_1:2;
unsigned int     Finish:1;
unsigned int     timeout:1;
unsigned int     reserved_2:3;
}ST_I2C_SR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     timeout_val:8;
}ST_I2C_TR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EDID_ADDRESS:3;
unsigned int     FINISH_INT_EN:1;
unsigned int     DDC1_FORCE:1;
unsigned int     DDC2B_FORCE:1;
unsigned int     EDID_SRWEN:1;
unsigned int     EDID_EN:1;
}ST_EDID_CR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DDC1_VCount:8;
}ST_DDC_VCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EDID_SADR:8;
}ST_EDID_IMSWSAR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EDID_EADR:8;
}ST_EDID_IMSWEAR;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     EDIDMODE:1;
unsigned int     EDIDSUBADDRESS:1;
unsigned int     EDIDSTOP:1;
unsigned int     I2C_M_RD_ST_IE:1;
unsigned int     I2C_M_RD_SP_IE:1;
unsigned int     EDIDSUBADDRESS_IE:1;
unsigned int     EDIDSTOP_IE:1;
}ST_EDID_IR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EDIDAP:8;
}ST_DDC_SIR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EDIDDP:8;
}ST_DDC_SAP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:3;
unsigned int     DDC_BIST_RME:1;
unsigned int     DDC_BIST_RM:4;
}ST_DDC_BISTCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SEGPT_LATIE:1;
unsigned int     Dataoutputdelay_sel:3;
unsigned int     reserved_1:1;
unsigned int     I2C_M_RD_ST_STS:1;
unsigned int     I2C_M_RD_SP_STS:1;
unsigned int     SGID_EN:1;
}ST_DDC_SCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SGID_ADDRESS:7;
unsigned int     SGID_DTRDEN:1;
}ST_DDC_SSAR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SEGPT_LATCHED:1;
unsigned int     SEG_PT:7;
}ST_DDC_SPR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     SPECIAL_MODE:1;
unsigned int     DOFFPT_RESET:1;
unsigned int     DIFFPT_RESET:1;
unsigned int     CIID_EN:1;
}ST_DDC_SFCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     CIID_ADDRESS:7;
unsigned int     CIRWS_CURRENT:1;
}ST_DDC_SFSAR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     CIIDDP:8;
}ST_DDC_SFDR;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     CIRWS_2ND:1;
unsigned int     CIRWS_1ST:1;
unsigned int     CIPPT_2ND:1;
unsigned int     CISPT_2ND:1;
unsigned int     CIPPT_1ST:1;
unsigned int     CISPT_1ST:1;
}ST_DDC_SFBSR;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     FFDI_DLEN:5;
}ST_DDC_SFIBLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DIFF_WPT:4;
unsigned int     DIFF_RPT:4;
}ST_DDC_SFIBRWPR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DIFFSTOP_PT:4;
}ST_DDC_SFIBSWPR;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     FFDO_DLEN:5;
}ST_DDC_SFOBSR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DOFF_WPT:4;
unsigned int     DOFF_RPT:4;
}ST_DDC_SFOBRWPR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FFDOUF_ST:1;
unsigned int     FFDIOF_ST:1;
unsigned int     FFDONF_ST:1;
unsigned int     FFDOET_ST:1;
unsigned int     FFDIFU_ST:1;
unsigned int     FFDINE_ST:1;
unsigned int     reserved_1:2;
}ST_DDC_SFSR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FFDOUF_IE:1;
unsigned int     FFDIOF_IE:1;
unsigned int     FFDONF_IE:1;
unsigned int     FFDOET_IE:1;
unsigned int     FFDIFU_IE:1;
unsigned int     FFDINE_IE:1;
unsigned int     CIPPT_IE:1;
unsigned int     CISPT_IE:1;
}ST_DDC_SFIR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     CMDFSM_ST:8;
}ST_DDC_FSMS;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     Dummy:8;
}ST_DDC_DUMMY;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:2;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:2;
unsigned int     START_IRQ_EN:1;
unsigned int     STOP_IRQ_EN:1;
}ST_DDC_EDID_SRAM_READ_IRQ_EN;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:2;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:2;
unsigned int     START:1;
unsigned int     STOP:1;
}ST_DDC_EDID_SRAM_READ_AUX;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_BIST_MODE:1;
}ST_DDC_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_BIST_DONE:1;
}ST_DDC_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_BIST_FAIL:1;
}ST_DDC_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_DRF_MODE:1;
}ST_DDC_DRF_MODE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_DRF_RESUME:1;
}ST_DDC_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_DRF_DONE:1;
}ST_DDC_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_DRF_PAUSE:1;
}ST_DDC_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DDC_DRF_FAIL:1;
}ST_DDC_DRF_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     RTCSEC:7;
}RTCSEC;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     RTCMIN:6;
}RTCMIN;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     RTCHR:5;
}RTCHR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RTCDATE1:8;
}RTCDATE1;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     RTCDATE2:7;
}RTCDATE2;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ALMMIN:6;
}ALMMIN;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ALMHR:5;
}ALMHR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ALMDATE1:8;
}ALMDATE1;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ALMDATE2:7;
}ALMDATE2;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     27Mclk_en:1;
unsigned int     VREF:2;
unsigned int     RTCSTOP:1;
}RTCSTOP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RTCPWR:1;
unsigned int     CO:2;
unsigned int     CI:2;
unsigned int     CLKSEL:1;
unsigned int     BC:2;
}RTCACR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RTCEN:8;
}RTCEN;

typedef struct 
{
unsigned int     rtc_alarm_int_status:1;
unsigned int     rtc_date_int_status:1;
unsigned int     rtc_hour_int_status:1;
unsigned int     rtc_min_int_status:1;
unsigned int     rtc_hsec_int_status:1;
unsigned int     reserved_0:20;
unsigned int     RTCRST:1;
unsigned int     reserved_1:1;
unsigned int     ALARMINTE:1;
unsigned int     DAINTE:1;
unsigned int     HUINTE:1;
unsigned int     MUINTE:1;
unsigned int     HSUINTE:1;
}RTCCR;

typedef struct 
{
unsigned int     TC0TVR:32;
}ISO_TC0TVR;

typedef struct 
{
unsigned int     TC0CVR:32;
}ISO_TC0CVR;

typedef struct 
{
unsigned int     TC0En:1;
unsigned int     TC0Mode:1;
unsigned int     TC0Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}ISO_TC0CR;

typedef struct 
{
unsigned int     TC0IE:1;
unsigned int     reserved_0:31;
}ISO_TC0ICR;

#endif

#define ISO_ISR                                                                      0x18061000
#define ISO_ISR_reg_addr                                                             "0xB8061000"
#define ISO_ISR_reg                                                                  0xB8061000
#define set_ISO_ISR_reg(data)   (*((volatile unsigned int*) ISO_ISR_reg)=data)
#define get_ISO_ISR_reg   (*((volatile unsigned int*) ISO_ISR_reg))
#define ISO_ISR_inst_adr                                                             "0x0000"
#define ISO_ISR_inst                                                                 0x0000
#define ISO_ISR_GPIODA_INT_shift                                                     (20)
#define ISO_ISR_GPIODA_INT_mask                                                      (0x00100000)
#define ISO_ISR_GPIODA_INT(data)                                                     (0x00100000&((data)<<20))
#define ISO_ISR_GPIODA_INT_src(data)                                                 ((0x00100000&(data))>>20)
#define ISO_ISR_get_GPIODA_INT(data)                                                 ((0x00100000&(data))>>20)
#define ISO_ISR_GPIOA_INT_shift                                                      (19)
#define ISO_ISR_GPIOA_INT_mask                                                       (0x00080000)
#define ISO_ISR_GPIOA_INT(data)                                                      (0x00080000&((data)<<19))
#define ISO_ISR_GPIOA_INT_src(data)                                                  ((0x00080000&(data))>>19)
#define ISO_ISR_get_GPIOA_INT(data)                                                  ((0x00080000&(data))>>19)
#define ISO_ISR_DDC0_INT_shift                                                       (18)
#define ISO_ISR_DDC0_INT_mask                                                        (0x00040000)
#define ISO_ISR_DDC0_INT(data)                                                       (0x00040000&((data)<<18))
#define ISO_ISR_DDC0_INT_src(data)                                                   ((0x00040000&(data))>>18)
#define ISO_ISR_get_DDC0_INT(data)                                                   ((0x00040000&(data))>>18)
#define ISO_ISR_LSADC_INT_shift                                                      (10)
#define ISO_ISR_LSADC_INT_mask                                                       (0x00000400)
#define ISO_ISR_LSADC_INT(data)                                                      (0x00000400&((data)<<10))
#define ISO_ISR_LSADC_INT_src(data)                                                  ((0x00000400&(data))>>10)
#define ISO_ISR_get_LSADC_INT(data)                                                  ((0x00000400&(data))>>10)
#define ISO_ISR_IRDA_INT_shift                                                       (5)
#define ISO_ISR_IRDA_INT_mask                                                        (0x00000020)
#define ISO_ISR_IRDA_INT(data)                                                       (0x00000020&((data)<<5))
#define ISO_ISR_IRDA_INT_src(data)                                                   ((0x00000020&(data))>>5)
#define ISO_ISR_get_IRDA_INT(data)                                                   ((0x00000020&(data))>>5)
#define ISO_ISR_ISO_TC0_INT_shift                                                    (3)
#define ISO_ISR_ISO_TC0_INT_mask                                                     (0x00000008)
#define ISO_ISR_ISO_TC0_INT(data)                                                    (0x00000008&((data)<<3))
#define ISO_ISR_ISO_TC0_INT_src(data)                                                ((0x00000008&(data))>>3)
#define ISO_ISR_get_ISO_TC0_INT(data)                                                ((0x00000008&(data))>>3)
#define ISO_ISR_write_data_shift                                                     (0)
#define ISO_ISR_write_data_mask                                                      (0x00000001)
#define ISO_ISR_write_data(data)                                                     (0x00000001&((data)<<0))
#define ISO_ISR_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define ISO_ISR_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define UMSK_ISO_ISR                                                                 0x18061004
#define UMSK_ISO_ISR_reg_addr                                                        "0xB8061004"
#define UMSK_ISO_ISR_reg                                                             0xB8061004
#define set_UMSK_ISO_ISR_reg(data)   (*((volatile unsigned int*) UMSK_ISO_ISR_reg)=data)
#define get_UMSK_ISO_ISR_reg   (*((volatile unsigned int*) UMSK_ISO_ISR_reg))
#define UMSK_ISO_ISR_inst_adr                                                        "0x0001"
#define UMSK_ISO_ISR_inst                                                            0x0001
#define UMSK_ISO_ISR_GPIODA_INT_shift                                                (20)
#define UMSK_ISO_ISR_GPIODA_INT_mask                                                 (0x00100000)
#define UMSK_ISO_ISR_GPIODA_INT(data)                                                (0x00100000&((data)<<20))
#define UMSK_ISO_ISR_GPIODA_INT_src(data)                                            ((0x00100000&(data))>>20)
#define UMSK_ISO_ISR_get_GPIODA_INT(data)                                            ((0x00100000&(data))>>20)
#define UMSK_ISO_ISR_GPIOA_INT_shift                                                 (19)
#define UMSK_ISO_ISR_GPIOA_INT_mask                                                  (0x00080000)
#define UMSK_ISO_ISR_GPIOA_INT(data)                                                 (0x00080000&((data)<<19))
#define UMSK_ISO_ISR_GPIOA_INT_src(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISO_ISR_get_GPIOA_INT(data)                                             ((0x00080000&(data))>>19)
#define UMSK_ISO_ISR_DDC0_INT_shift                                                  (18)
#define UMSK_ISO_ISR_DDC0_INT_mask                                                   (0x00040000)
#define UMSK_ISO_ISR_DDC0_INT(data)                                                  (0x00040000&((data)<<18))
#define UMSK_ISO_ISR_DDC0_INT_src(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISO_ISR_get_DDC0_INT(data)                                              ((0x00040000&(data))>>18)
#define UMSK_ISO_ISR_LSADC_INT_shift                                                 (10)
#define UMSK_ISO_ISR_LSADC_INT_mask                                                  (0x00000400)
#define UMSK_ISO_ISR_LSADC_INT(data)                                                 (0x00000400&((data)<<10))
#define UMSK_ISO_ISR_LSADC_INT_src(data)                                             ((0x00000400&(data))>>10)
#define UMSK_ISO_ISR_get_LSADC_INT(data)                                             ((0x00000400&(data))>>10)
#define UMSK_ISO_ISR_IRDA_INT_shift                                                  (5)
#define UMSK_ISO_ISR_IRDA_INT_mask                                                   (0x00000020)
#define UMSK_ISO_ISR_IRDA_INT(data)                                                  (0x00000020&((data)<<5))
#define UMSK_ISO_ISR_IRDA_INT_src(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISO_ISR_get_IRDA_INT(data)                                              ((0x00000020&(data))>>5)
#define UMSK_ISO_ISR_ISO_TC0_INT_shift                                               (3)
#define UMSK_ISO_ISR_ISO_TC0_INT_mask                                                (0x00000008)
#define UMSK_ISO_ISR_ISO_TC0_INT(data)                                               (0x00000008&((data)<<3))
#define UMSK_ISO_ISR_ISO_TC0_INT_src(data)                                           ((0x00000008&(data))>>3)
#define UMSK_ISO_ISR_get_ISO_TC0_INT(data)                                           ((0x00000008&(data))>>3)
#define UMSK_ISO_ISR_write_data_shift                                                (0)
#define UMSK_ISO_ISR_write_data_mask                                                 (0x00000001)
#define UMSK_ISO_ISR_write_data(data)                                                (0x00000001&((data)<<0))
#define UMSK_ISO_ISR_write_data_src(data)                                            ((0x00000001&(data))>>0)
#define UMSK_ISO_ISR_get_write_data(data)                                            ((0x00000001&(data))>>0)


#define UMSK_ISR_GP_ASSERT                                                           0x18061008
#define UMSK_ISR_GP_ASSERT_reg_addr                                                  "0xB8061008"
#define UMSK_ISR_GP_ASSERT_reg                                                       0xB8061008
#define set_UMSK_ISR_GP_ASSERT_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP_ASSERT_reg)=data)
#define get_UMSK_ISR_GP_ASSERT_reg   (*((volatile unsigned int*) UMSK_ISR_GP_ASSERT_reg))
#define UMSK_ISR_GP_ASSERT_inst_adr                                                  "0x0002"
#define UMSK_ISR_GP_ASSERT_inst                                                      0x0002
#define UMSK_ISR_GP_ASSERT_INT30_A_shift                                             (31)
#define UMSK_ISR_GP_ASSERT_INT30_A_mask                                              (0x80000000)
#define UMSK_ISR_GP_ASSERT_INT30_A(data)                                             (0x80000000&((data)<<31))
#define UMSK_ISR_GP_ASSERT_INT30_A_src(data)                                         ((0x80000000&(data))>>31)
#define UMSK_ISR_GP_ASSERT_get_INT30_A(data)                                         ((0x80000000&(data))>>31)
#define UMSK_ISR_GP_ASSERT_INT29_A_shift                                             (30)
#define UMSK_ISR_GP_ASSERT_INT29_A_mask                                              (0x40000000)
#define UMSK_ISR_GP_ASSERT_INT29_A(data)                                             (0x40000000&((data)<<30))
#define UMSK_ISR_GP_ASSERT_INT29_A_src(data)                                         ((0x40000000&(data))>>30)
#define UMSK_ISR_GP_ASSERT_get_INT29_A(data)                                         ((0x40000000&(data))>>30)
#define UMSK_ISR_GP_ASSERT_INT28_A_shift                                             (29)
#define UMSK_ISR_GP_ASSERT_INT28_A_mask                                              (0x20000000)
#define UMSK_ISR_GP_ASSERT_INT28_A(data)                                             (0x20000000&((data)<<29))
#define UMSK_ISR_GP_ASSERT_INT28_A_src(data)                                         ((0x20000000&(data))>>29)
#define UMSK_ISR_GP_ASSERT_get_INT28_A(data)                                         ((0x20000000&(data))>>29)
#define UMSK_ISR_GP_ASSERT_INT27_A_shift                                             (28)
#define UMSK_ISR_GP_ASSERT_INT27_A_mask                                              (0x10000000)
#define UMSK_ISR_GP_ASSERT_INT27_A(data)                                             (0x10000000&((data)<<28))
#define UMSK_ISR_GP_ASSERT_INT27_A_src(data)                                         ((0x10000000&(data))>>28)
#define UMSK_ISR_GP_ASSERT_get_INT27_A(data)                                         ((0x10000000&(data))>>28)
#define UMSK_ISR_GP_ASSERT_INT26_A_shift                                             (27)
#define UMSK_ISR_GP_ASSERT_INT26_A_mask                                              (0x08000000)
#define UMSK_ISR_GP_ASSERT_INT26_A(data)                                             (0x08000000&((data)<<27))
#define UMSK_ISR_GP_ASSERT_INT26_A_src(data)                                         ((0x08000000&(data))>>27)
#define UMSK_ISR_GP_ASSERT_get_INT26_A(data)                                         ((0x08000000&(data))>>27)
#define UMSK_ISR_GP_ASSERT_INT25_A_shift                                             (26)
#define UMSK_ISR_GP_ASSERT_INT25_A_mask                                              (0x04000000)
#define UMSK_ISR_GP_ASSERT_INT25_A(data)                                             (0x04000000&((data)<<26))
#define UMSK_ISR_GP_ASSERT_INT25_A_src(data)                                         ((0x04000000&(data))>>26)
#define UMSK_ISR_GP_ASSERT_get_INT25_A(data)                                         ((0x04000000&(data))>>26)
#define UMSK_ISR_GP_ASSERT_INT24_A_shift                                             (25)
#define UMSK_ISR_GP_ASSERT_INT24_A_mask                                              (0x02000000)
#define UMSK_ISR_GP_ASSERT_INT24_A(data)                                             (0x02000000&((data)<<25))
#define UMSK_ISR_GP_ASSERT_INT24_A_src(data)                                         ((0x02000000&(data))>>25)
#define UMSK_ISR_GP_ASSERT_get_INT24_A(data)                                         ((0x02000000&(data))>>25)
#define UMSK_ISR_GP_ASSERT_INT23_A_shift                                             (24)
#define UMSK_ISR_GP_ASSERT_INT23_A_mask                                              (0x01000000)
#define UMSK_ISR_GP_ASSERT_INT23_A(data)                                             (0x01000000&((data)<<24))
#define UMSK_ISR_GP_ASSERT_INT23_A_src(data)                                         ((0x01000000&(data))>>24)
#define UMSK_ISR_GP_ASSERT_get_INT23_A(data)                                         ((0x01000000&(data))>>24)
#define UMSK_ISR_GP_ASSERT_INT22_A_shift                                             (23)
#define UMSK_ISR_GP_ASSERT_INT22_A_mask                                              (0x00800000)
#define UMSK_ISR_GP_ASSERT_INT22_A(data)                                             (0x00800000&((data)<<23))
#define UMSK_ISR_GP_ASSERT_INT22_A_src(data)                                         ((0x00800000&(data))>>23)
#define UMSK_ISR_GP_ASSERT_get_INT22_A(data)                                         ((0x00800000&(data))>>23)
#define UMSK_ISR_GP_ASSERT_INT21_A_shift                                             (22)
#define UMSK_ISR_GP_ASSERT_INT21_A_mask                                              (0x00400000)
#define UMSK_ISR_GP_ASSERT_INT21_A(data)                                             (0x00400000&((data)<<22))
#define UMSK_ISR_GP_ASSERT_INT21_A_src(data)                                         ((0x00400000&(data))>>22)
#define UMSK_ISR_GP_ASSERT_get_INT21_A(data)                                         ((0x00400000&(data))>>22)
#define UMSK_ISR_GP_ASSERT_INT20_A_shift                                             (21)
#define UMSK_ISR_GP_ASSERT_INT20_A_mask                                              (0x00200000)
#define UMSK_ISR_GP_ASSERT_INT20_A(data)                                             (0x00200000&((data)<<21))
#define UMSK_ISR_GP_ASSERT_INT20_A_src(data)                                         ((0x00200000&(data))>>21)
#define UMSK_ISR_GP_ASSERT_get_INT20_A(data)                                         ((0x00200000&(data))>>21)
#define UMSK_ISR_GP_ASSERT_INT19_A_shift                                             (20)
#define UMSK_ISR_GP_ASSERT_INT19_A_mask                                              (0x00100000)
#define UMSK_ISR_GP_ASSERT_INT19_A(data)                                             (0x00100000&((data)<<20))
#define UMSK_ISR_GP_ASSERT_INT19_A_src(data)                                         ((0x00100000&(data))>>20)
#define UMSK_ISR_GP_ASSERT_get_INT19_A(data)                                         ((0x00100000&(data))>>20)
#define UMSK_ISR_GP_ASSERT_INT18_A_shift                                             (19)
#define UMSK_ISR_GP_ASSERT_INT18_A_mask                                              (0x00080000)
#define UMSK_ISR_GP_ASSERT_INT18_A(data)                                             (0x00080000&((data)<<19))
#define UMSK_ISR_GP_ASSERT_INT18_A_src(data)                                         ((0x00080000&(data))>>19)
#define UMSK_ISR_GP_ASSERT_get_INT18_A(data)                                         ((0x00080000&(data))>>19)
#define UMSK_ISR_GP_ASSERT_INT17_A_shift                                             (18)
#define UMSK_ISR_GP_ASSERT_INT17_A_mask                                              (0x00040000)
#define UMSK_ISR_GP_ASSERT_INT17_A(data)                                             (0x00040000&((data)<<18))
#define UMSK_ISR_GP_ASSERT_INT17_A_src(data)                                         ((0x00040000&(data))>>18)
#define UMSK_ISR_GP_ASSERT_get_INT17_A(data)                                         ((0x00040000&(data))>>18)
#define UMSK_ISR_GP_ASSERT_INT16_A_shift                                             (17)
#define UMSK_ISR_GP_ASSERT_INT16_A_mask                                              (0x00020000)
#define UMSK_ISR_GP_ASSERT_INT16_A(data)                                             (0x00020000&((data)<<17))
#define UMSK_ISR_GP_ASSERT_INT16_A_src(data)                                         ((0x00020000&(data))>>17)
#define UMSK_ISR_GP_ASSERT_get_INT16_A(data)                                         ((0x00020000&(data))>>17)
#define UMSK_ISR_GP_ASSERT_INT15_A_shift                                             (16)
#define UMSK_ISR_GP_ASSERT_INT15_A_mask                                              (0x00010000)
#define UMSK_ISR_GP_ASSERT_INT15_A(data)                                             (0x00010000&((data)<<16))
#define UMSK_ISR_GP_ASSERT_INT15_A_src(data)                                         ((0x00010000&(data))>>16)
#define UMSK_ISR_GP_ASSERT_get_INT15_A(data)                                         ((0x00010000&(data))>>16)
#define UMSK_ISR_GP_ASSERT_INT14_A_shift                                             (15)
#define UMSK_ISR_GP_ASSERT_INT14_A_mask                                              (0x00008000)
#define UMSK_ISR_GP_ASSERT_INT14_A(data)                                             (0x00008000&((data)<<15))
#define UMSK_ISR_GP_ASSERT_INT14_A_src(data)                                         ((0x00008000&(data))>>15)
#define UMSK_ISR_GP_ASSERT_get_INT14_A(data)                                         ((0x00008000&(data))>>15)
#define UMSK_ISR_GP_ASSERT_INT13_A_shift                                             (14)
#define UMSK_ISR_GP_ASSERT_INT13_A_mask                                              (0x00004000)
#define UMSK_ISR_GP_ASSERT_INT13_A(data)                                             (0x00004000&((data)<<14))
#define UMSK_ISR_GP_ASSERT_INT13_A_src(data)                                         ((0x00004000&(data))>>14)
#define UMSK_ISR_GP_ASSERT_get_INT13_A(data)                                         ((0x00004000&(data))>>14)
#define UMSK_ISR_GP_ASSERT_INT12_A_shift                                             (13)
#define UMSK_ISR_GP_ASSERT_INT12_A_mask                                              (0x00002000)
#define UMSK_ISR_GP_ASSERT_INT12_A(data)                                             (0x00002000&((data)<<13))
#define UMSK_ISR_GP_ASSERT_INT12_A_src(data)                                         ((0x00002000&(data))>>13)
#define UMSK_ISR_GP_ASSERT_get_INT12_A(data)                                         ((0x00002000&(data))>>13)
#define UMSK_ISR_GP_ASSERT_INT11_A_shift                                             (12)
#define UMSK_ISR_GP_ASSERT_INT11_A_mask                                              (0x00001000)
#define UMSK_ISR_GP_ASSERT_INT11_A(data)                                             (0x00001000&((data)<<12))
#define UMSK_ISR_GP_ASSERT_INT11_A_src(data)                                         ((0x00001000&(data))>>12)
#define UMSK_ISR_GP_ASSERT_get_INT11_A(data)                                         ((0x00001000&(data))>>12)
#define UMSK_ISR_GP_ASSERT_INT10_A_shift                                             (11)
#define UMSK_ISR_GP_ASSERT_INT10_A_mask                                              (0x00000800)
#define UMSK_ISR_GP_ASSERT_INT10_A(data)                                             (0x00000800&((data)<<11))
#define UMSK_ISR_GP_ASSERT_INT10_A_src(data)                                         ((0x00000800&(data))>>11)
#define UMSK_ISR_GP_ASSERT_get_INT10_A(data)                                         ((0x00000800&(data))>>11)
#define UMSK_ISR_GP_ASSERT_INT9_A_shift                                              (10)
#define UMSK_ISR_GP_ASSERT_INT9_A_mask                                               (0x00000400)
#define UMSK_ISR_GP_ASSERT_INT9_A(data)                                              (0x00000400&((data)<<10))
#define UMSK_ISR_GP_ASSERT_INT9_A_src(data)                                          ((0x00000400&(data))>>10)
#define UMSK_ISR_GP_ASSERT_get_INT9_A(data)                                          ((0x00000400&(data))>>10)
#define UMSK_ISR_GP_ASSERT_INT8_A_shift                                              (9)
#define UMSK_ISR_GP_ASSERT_INT8_A_mask                                               (0x00000200)
#define UMSK_ISR_GP_ASSERT_INT8_A(data)                                              (0x00000200&((data)<<9))
#define UMSK_ISR_GP_ASSERT_INT8_A_src(data)                                          ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_ASSERT_get_INT8_A(data)                                          ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_ASSERT_INT7_A_shift                                              (8)
#define UMSK_ISR_GP_ASSERT_INT7_A_mask                                               (0x00000100)
#define UMSK_ISR_GP_ASSERT_INT7_A(data)                                              (0x00000100&((data)<<8))
#define UMSK_ISR_GP_ASSERT_INT7_A_src(data)                                          ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_ASSERT_get_INT7_A(data)                                          ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_ASSERT_INT6_A_shift                                              (7)
#define UMSK_ISR_GP_ASSERT_INT6_A_mask                                               (0x00000080)
#define UMSK_ISR_GP_ASSERT_INT6_A(data)                                              (0x00000080&((data)<<7))
#define UMSK_ISR_GP_ASSERT_INT6_A_src(data)                                          ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_ASSERT_get_INT6_A(data)                                          ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_ASSERT_INT5_A_shift                                              (6)
#define UMSK_ISR_GP_ASSERT_INT5_A_mask                                               (0x00000040)
#define UMSK_ISR_GP_ASSERT_INT5_A(data)                                              (0x00000040&((data)<<6))
#define UMSK_ISR_GP_ASSERT_INT5_A_src(data)                                          ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_ASSERT_get_INT5_A(data)                                          ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_ASSERT_INT4_A_shift                                              (5)
#define UMSK_ISR_GP_ASSERT_INT4_A_mask                                               (0x00000020)
#define UMSK_ISR_GP_ASSERT_INT4_A(data)                                              (0x00000020&((data)<<5))
#define UMSK_ISR_GP_ASSERT_INT4_A_src(data)                                          ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_ASSERT_get_INT4_A(data)                                          ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_ASSERT_INT3_A_shift                                              (4)
#define UMSK_ISR_GP_ASSERT_INT3_A_mask                                               (0x00000010)
#define UMSK_ISR_GP_ASSERT_INT3_A(data)                                              (0x00000010&((data)<<4))
#define UMSK_ISR_GP_ASSERT_INT3_A_src(data)                                          ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_ASSERT_get_INT3_A(data)                                          ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_ASSERT_INT2_A_shift                                              (3)
#define UMSK_ISR_GP_ASSERT_INT2_A_mask                                               (0x00000008)
#define UMSK_ISR_GP_ASSERT_INT2_A(data)                                              (0x00000008&((data)<<3))
#define UMSK_ISR_GP_ASSERT_INT2_A_src(data)                                          ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_ASSERT_get_INT2_A(data)                                          ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_ASSERT_INT1_A_shift                                              (2)
#define UMSK_ISR_GP_ASSERT_INT1_A_mask                                               (0x00000004)
#define UMSK_ISR_GP_ASSERT_INT1_A(data)                                              (0x00000004&((data)<<2))
#define UMSK_ISR_GP_ASSERT_INT1_A_src(data)                                          ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_ASSERT_get_INT1_A(data)                                          ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_ASSERT_INT0_A_shift                                              (1)
#define UMSK_ISR_GP_ASSERT_INT0_A_mask                                               (0x00000002)
#define UMSK_ISR_GP_ASSERT_INT0_A(data)                                              (0x00000002&((data)<<1))
#define UMSK_ISR_GP_ASSERT_INT0_A_src(data)                                          ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_ASSERT_get_INT0_A(data)                                          ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_ASSERT_write_data_shift                                          (0)
#define UMSK_ISR_GP_ASSERT_write_data_mask                                           (0x00000001)
#define UMSK_ISR_GP_ASSERT_write_data(data)                                          (0x00000001&((data)<<0))
#define UMSK_ISR_GP_ASSERT_write_data_src(data)                                      ((0x00000001&(data))>>0)
#define UMSK_ISR_GP_ASSERT_get_write_data(data)                                      ((0x00000001&(data))>>0)


#define UMSK_ISR_GP_ASSERT_1                                                         0x1806100C
#define UMSK_ISR_GP_ASSERT_1_reg_addr                                                "0xB806100C"
#define UMSK_ISR_GP_ASSERT_1_reg                                                     0xB806100C
#define set_UMSK_ISR_GP_ASSERT_1_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP_ASSERT_1_reg)=data)
#define get_UMSK_ISR_GP_ASSERT_1_reg   (*((volatile unsigned int*) UMSK_ISR_GP_ASSERT_1_reg))
#define UMSK_ISR_GP_ASSERT_1_inst_adr                                                "0x0003"
#define UMSK_ISR_GP_ASSERT_1_inst                                                    0x0003
#define UMSK_ISR_GP_ASSERT_1_INT39_A_shift                                           (9)
#define UMSK_ISR_GP_ASSERT_1_INT39_A_mask                                            (0x00000200)
#define UMSK_ISR_GP_ASSERT_1_INT39_A(data)                                           (0x00000200&((data)<<9))
#define UMSK_ISR_GP_ASSERT_1_INT39_A_src(data)                                       ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_ASSERT_1_get_INT39_A(data)                                       ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_ASSERT_1_INT38_A_shift                                           (8)
#define UMSK_ISR_GP_ASSERT_1_INT38_A_mask                                            (0x00000100)
#define UMSK_ISR_GP_ASSERT_1_INT38_A(data)                                           (0x00000100&((data)<<8))
#define UMSK_ISR_GP_ASSERT_1_INT38_A_src(data)                                       ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_ASSERT_1_get_INT38_A(data)                                       ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_ASSERT_1_INT37_A_shift                                           (7)
#define UMSK_ISR_GP_ASSERT_1_INT37_A_mask                                            (0x00000080)
#define UMSK_ISR_GP_ASSERT_1_INT37_A(data)                                           (0x00000080&((data)<<7))
#define UMSK_ISR_GP_ASSERT_1_INT37_A_src(data)                                       ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_ASSERT_1_get_INT37_A(data)                                       ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_ASSERT_1_INT36_A_shift                                           (6)
#define UMSK_ISR_GP_ASSERT_1_INT36_A_mask                                            (0x00000040)
#define UMSK_ISR_GP_ASSERT_1_INT36_A(data)                                           (0x00000040&((data)<<6))
#define UMSK_ISR_GP_ASSERT_1_INT36_A_src(data)                                       ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_ASSERT_1_get_INT36_A(data)                                       ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_ASSERT_1_INT35_A_shift                                           (5)
#define UMSK_ISR_GP_ASSERT_1_INT35_A_mask                                            (0x00000020)
#define UMSK_ISR_GP_ASSERT_1_INT35_A(data)                                           (0x00000020&((data)<<5))
#define UMSK_ISR_GP_ASSERT_1_INT35_A_src(data)                                       ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_ASSERT_1_get_INT35_A(data)                                       ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_ASSERT_1_INT34_A_shift                                           (4)
#define UMSK_ISR_GP_ASSERT_1_INT34_A_mask                                            (0x00000010)
#define UMSK_ISR_GP_ASSERT_1_INT34_A(data)                                           (0x00000010&((data)<<4))
#define UMSK_ISR_GP_ASSERT_1_INT34_A_src(data)                                       ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_ASSERT_1_get_INT34_A(data)                                       ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_ASSERT_1_INT33_A_shift                                           (3)
#define UMSK_ISR_GP_ASSERT_1_INT33_A_mask                                            (0x00000008)
#define UMSK_ISR_GP_ASSERT_1_INT33_A(data)                                           (0x00000008&((data)<<3))
#define UMSK_ISR_GP_ASSERT_1_INT33_A_src(data)                                       ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_ASSERT_1_get_INT33_A(data)                                       ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_ASSERT_1_INT32_A_shift                                           (2)
#define UMSK_ISR_GP_ASSERT_1_INT32_A_mask                                            (0x00000004)
#define UMSK_ISR_GP_ASSERT_1_INT32_A(data)                                           (0x00000004&((data)<<2))
#define UMSK_ISR_GP_ASSERT_1_INT32_A_src(data)                                       ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_ASSERT_1_get_INT32_A(data)                                       ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_ASSERT_1_INT31_A_shift                                           (1)
#define UMSK_ISR_GP_ASSERT_1_INT31_A_mask                                            (0x00000002)
#define UMSK_ISR_GP_ASSERT_1_INT31_A(data)                                           (0x00000002&((data)<<1))
#define UMSK_ISR_GP_ASSERT_1_INT31_A_src(data)                                       ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_ASSERT_1_get_INT31_A(data)                                       ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_ASSERT_1_write_data_shift                                        (0)
#define UMSK_ISR_GP_ASSERT_1_write_data_mask                                         (0x00000001)
#define UMSK_ISR_GP_ASSERT_1_write_data(data)                                        (0x00000001&((data)<<0))
#define UMSK_ISR_GP_ASSERT_1_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define UMSK_ISR_GP_ASSERT_1_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define UMSK_ISR_GP_DEASSERT                                                         0x18061010
#define UMSK_ISR_GP_DEASSERT_reg_addr                                                "0xB8061010"
#define UMSK_ISR_GP_DEASSERT_reg                                                     0xB8061010
#define set_UMSK_ISR_GP_DEASSERT_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP_DEASSERT_reg)=data)
#define get_UMSK_ISR_GP_DEASSERT_reg   (*((volatile unsigned int*) UMSK_ISR_GP_DEASSERT_reg))
#define UMSK_ISR_GP_DEASSERT_inst_adr                                                "0x0004"
#define UMSK_ISR_GP_DEASSERT_inst                                                    0x0004
#define UMSK_ISR_GP_DEASSERT_INT30_DA_shift                                          (31)
#define UMSK_ISR_GP_DEASSERT_INT30_DA_mask                                           (0x80000000)
#define UMSK_ISR_GP_DEASSERT_INT30_DA(data)                                          (0x80000000&((data)<<31))
#define UMSK_ISR_GP_DEASSERT_INT30_DA_src(data)                                      ((0x80000000&(data))>>31)
#define UMSK_ISR_GP_DEASSERT_get_INT30_DA(data)                                      ((0x80000000&(data))>>31)
#define UMSK_ISR_GP_DEASSERT_INT29_DA_shift                                          (30)
#define UMSK_ISR_GP_DEASSERT_INT29_DA_mask                                           (0x40000000)
#define UMSK_ISR_GP_DEASSERT_INT29_DA(data)                                          (0x40000000&((data)<<30))
#define UMSK_ISR_GP_DEASSERT_INT29_DA_src(data)                                      ((0x40000000&(data))>>30)
#define UMSK_ISR_GP_DEASSERT_get_INT29_DA(data)                                      ((0x40000000&(data))>>30)
#define UMSK_ISR_GP_DEASSERT_INT28_DA_shift                                          (29)
#define UMSK_ISR_GP_DEASSERT_INT28_DA_mask                                           (0x20000000)
#define UMSK_ISR_GP_DEASSERT_INT28_DA(data)                                          (0x20000000&((data)<<29))
#define UMSK_ISR_GP_DEASSERT_INT28_DA_src(data)                                      ((0x20000000&(data))>>29)
#define UMSK_ISR_GP_DEASSERT_get_INT28_DA(data)                                      ((0x20000000&(data))>>29)
#define UMSK_ISR_GP_DEASSERT_INT27_DA_shift                                          (28)
#define UMSK_ISR_GP_DEASSERT_INT27_DA_mask                                           (0x10000000)
#define UMSK_ISR_GP_DEASSERT_INT27_DA(data)                                          (0x10000000&((data)<<28))
#define UMSK_ISR_GP_DEASSERT_INT27_DA_src(data)                                      ((0x10000000&(data))>>28)
#define UMSK_ISR_GP_DEASSERT_get_INT27_DA(data)                                      ((0x10000000&(data))>>28)
#define UMSK_ISR_GP_DEASSERT_INT26_DA_shift                                          (27)
#define UMSK_ISR_GP_DEASSERT_INT26_DA_mask                                           (0x08000000)
#define UMSK_ISR_GP_DEASSERT_INT26_DA(data)                                          (0x08000000&((data)<<27))
#define UMSK_ISR_GP_DEASSERT_INT26_DA_src(data)                                      ((0x08000000&(data))>>27)
#define UMSK_ISR_GP_DEASSERT_get_INT26_DA(data)                                      ((0x08000000&(data))>>27)
#define UMSK_ISR_GP_DEASSERT_INT25_DA_shift                                          (26)
#define UMSK_ISR_GP_DEASSERT_INT25_DA_mask                                           (0x04000000)
#define UMSK_ISR_GP_DEASSERT_INT25_DA(data)                                          (0x04000000&((data)<<26))
#define UMSK_ISR_GP_DEASSERT_INT25_DA_src(data)                                      ((0x04000000&(data))>>26)
#define UMSK_ISR_GP_DEASSERT_get_INT25_DA(data)                                      ((0x04000000&(data))>>26)
#define UMSK_ISR_GP_DEASSERT_INT24_DA_shift                                          (25)
#define UMSK_ISR_GP_DEASSERT_INT24_DA_mask                                           (0x02000000)
#define UMSK_ISR_GP_DEASSERT_INT24_DA(data)                                          (0x02000000&((data)<<25))
#define UMSK_ISR_GP_DEASSERT_INT24_DA_src(data)                                      ((0x02000000&(data))>>25)
#define UMSK_ISR_GP_DEASSERT_get_INT24_DA(data)                                      ((0x02000000&(data))>>25)
#define UMSK_ISR_GP_DEASSERT_INT23_DA_shift                                          (24)
#define UMSK_ISR_GP_DEASSERT_INT23_DA_mask                                           (0x01000000)
#define UMSK_ISR_GP_DEASSERT_INT23_DA(data)                                          (0x01000000&((data)<<24))
#define UMSK_ISR_GP_DEASSERT_INT23_DA_src(data)                                      ((0x01000000&(data))>>24)
#define UMSK_ISR_GP_DEASSERT_get_INT23_DA(data)                                      ((0x01000000&(data))>>24)
#define UMSK_ISR_GP_DEASSERT_INT22_DA_shift                                          (23)
#define UMSK_ISR_GP_DEASSERT_INT22_DA_mask                                           (0x00800000)
#define UMSK_ISR_GP_DEASSERT_INT22_DA(data)                                          (0x00800000&((data)<<23))
#define UMSK_ISR_GP_DEASSERT_INT22_DA_src(data)                                      ((0x00800000&(data))>>23)
#define UMSK_ISR_GP_DEASSERT_get_INT22_DA(data)                                      ((0x00800000&(data))>>23)
#define UMSK_ISR_GP_DEASSERT_INT21_DA_shift                                          (22)
#define UMSK_ISR_GP_DEASSERT_INT21_DA_mask                                           (0x00400000)
#define UMSK_ISR_GP_DEASSERT_INT21_DA(data)                                          (0x00400000&((data)<<22))
#define UMSK_ISR_GP_DEASSERT_INT21_DA_src(data)                                      ((0x00400000&(data))>>22)
#define UMSK_ISR_GP_DEASSERT_get_INT21_DA(data)                                      ((0x00400000&(data))>>22)
#define UMSK_ISR_GP_DEASSERT_INT20_DA_shift                                          (21)
#define UMSK_ISR_GP_DEASSERT_INT20_DA_mask                                           (0x00200000)
#define UMSK_ISR_GP_DEASSERT_INT20_DA(data)                                          (0x00200000&((data)<<21))
#define UMSK_ISR_GP_DEASSERT_INT20_DA_src(data)                                      ((0x00200000&(data))>>21)
#define UMSK_ISR_GP_DEASSERT_get_INT20_DA(data)                                      ((0x00200000&(data))>>21)
#define UMSK_ISR_GP_DEASSERT_INT19_DA_shift                                          (20)
#define UMSK_ISR_GP_DEASSERT_INT19_DA_mask                                           (0x00100000)
#define UMSK_ISR_GP_DEASSERT_INT19_DA(data)                                          (0x00100000&((data)<<20))
#define UMSK_ISR_GP_DEASSERT_INT19_DA_src(data)                                      ((0x00100000&(data))>>20)
#define UMSK_ISR_GP_DEASSERT_get_INT19_DA(data)                                      ((0x00100000&(data))>>20)
#define UMSK_ISR_GP_DEASSERT_INT18_DA_shift                                          (19)
#define UMSK_ISR_GP_DEASSERT_INT18_DA_mask                                           (0x00080000)
#define UMSK_ISR_GP_DEASSERT_INT18_DA(data)                                          (0x00080000&((data)<<19))
#define UMSK_ISR_GP_DEASSERT_INT18_DA_src(data)                                      ((0x00080000&(data))>>19)
#define UMSK_ISR_GP_DEASSERT_get_INT18_DA(data)                                      ((0x00080000&(data))>>19)
#define UMSK_ISR_GP_DEASSERT_INT17_DA_shift                                          (18)
#define UMSK_ISR_GP_DEASSERT_INT17_DA_mask                                           (0x00040000)
#define UMSK_ISR_GP_DEASSERT_INT17_DA(data)                                          (0x00040000&((data)<<18))
#define UMSK_ISR_GP_DEASSERT_INT17_DA_src(data)                                      ((0x00040000&(data))>>18)
#define UMSK_ISR_GP_DEASSERT_get_INT17_DA(data)                                      ((0x00040000&(data))>>18)
#define UMSK_ISR_GP_DEASSERT_INT16_DA_shift                                          (17)
#define UMSK_ISR_GP_DEASSERT_INT16_DA_mask                                           (0x00020000)
#define UMSK_ISR_GP_DEASSERT_INT16_DA(data)                                          (0x00020000&((data)<<17))
#define UMSK_ISR_GP_DEASSERT_INT16_DA_src(data)                                      ((0x00020000&(data))>>17)
#define UMSK_ISR_GP_DEASSERT_get_INT16_DA(data)                                      ((0x00020000&(data))>>17)
#define UMSK_ISR_GP_DEASSERT_INT15_DA_shift                                          (16)
#define UMSK_ISR_GP_DEASSERT_INT15_DA_mask                                           (0x00010000)
#define UMSK_ISR_GP_DEASSERT_INT15_DA(data)                                          (0x00010000&((data)<<16))
#define UMSK_ISR_GP_DEASSERT_INT15_DA_src(data)                                      ((0x00010000&(data))>>16)
#define UMSK_ISR_GP_DEASSERT_get_INT15_DA(data)                                      ((0x00010000&(data))>>16)
#define UMSK_ISR_GP_DEASSERT_INT14_DA_shift                                          (15)
#define UMSK_ISR_GP_DEASSERT_INT14_DA_mask                                           (0x00008000)
#define UMSK_ISR_GP_DEASSERT_INT14_DA(data)                                          (0x00008000&((data)<<15))
#define UMSK_ISR_GP_DEASSERT_INT14_DA_src(data)                                      ((0x00008000&(data))>>15)
#define UMSK_ISR_GP_DEASSERT_get_INT14_DA(data)                                      ((0x00008000&(data))>>15)
#define UMSK_ISR_GP_DEASSERT_INT13_DA_shift                                          (14)
#define UMSK_ISR_GP_DEASSERT_INT13_DA_mask                                           (0x00004000)
#define UMSK_ISR_GP_DEASSERT_INT13_DA(data)                                          (0x00004000&((data)<<14))
#define UMSK_ISR_GP_DEASSERT_INT13_DA_src(data)                                      ((0x00004000&(data))>>14)
#define UMSK_ISR_GP_DEASSERT_get_INT13_DA(data)                                      ((0x00004000&(data))>>14)
#define UMSK_ISR_GP_DEASSERT_INT12_DA_shift                                          (13)
#define UMSK_ISR_GP_DEASSERT_INT12_DA_mask                                           (0x00002000)
#define UMSK_ISR_GP_DEASSERT_INT12_DA(data)                                          (0x00002000&((data)<<13))
#define UMSK_ISR_GP_DEASSERT_INT12_DA_src(data)                                      ((0x00002000&(data))>>13)
#define UMSK_ISR_GP_DEASSERT_get_INT12_DA(data)                                      ((0x00002000&(data))>>13)
#define UMSK_ISR_GP_DEASSERT_INT11_DA_shift                                          (12)
#define UMSK_ISR_GP_DEASSERT_INT11_DA_mask                                           (0x00001000)
#define UMSK_ISR_GP_DEASSERT_INT11_DA(data)                                          (0x00001000&((data)<<12))
#define UMSK_ISR_GP_DEASSERT_INT11_DA_src(data)                                      ((0x00001000&(data))>>12)
#define UMSK_ISR_GP_DEASSERT_get_INT11_DA(data)                                      ((0x00001000&(data))>>12)
#define UMSK_ISR_GP_DEASSERT_INT10_DA_shift                                          (11)
#define UMSK_ISR_GP_DEASSERT_INT10_DA_mask                                           (0x00000800)
#define UMSK_ISR_GP_DEASSERT_INT10_DA(data)                                          (0x00000800&((data)<<11))
#define UMSK_ISR_GP_DEASSERT_INT10_DA_src(data)                                      ((0x00000800&(data))>>11)
#define UMSK_ISR_GP_DEASSERT_get_INT10_DA(data)                                      ((0x00000800&(data))>>11)
#define UMSK_ISR_GP_DEASSERT_INT9_DA_shift                                           (10)
#define UMSK_ISR_GP_DEASSERT_INT9_DA_mask                                            (0x00000400)
#define UMSK_ISR_GP_DEASSERT_INT9_DA(data)                                           (0x00000400&((data)<<10))
#define UMSK_ISR_GP_DEASSERT_INT9_DA_src(data)                                       ((0x00000400&(data))>>10)
#define UMSK_ISR_GP_DEASSERT_get_INT9_DA(data)                                       ((0x00000400&(data))>>10)
#define UMSK_ISR_GP_DEASSERT_INT8_DA_shift                                           (9)
#define UMSK_ISR_GP_DEASSERT_INT8_DA_mask                                            (0x00000200)
#define UMSK_ISR_GP_DEASSERT_INT8_DA(data)                                           (0x00000200&((data)<<9))
#define UMSK_ISR_GP_DEASSERT_INT8_DA_src(data)                                       ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_DEASSERT_get_INT8_DA(data)                                       ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_DEASSERT_INT7_DA_shift                                           (8)
#define UMSK_ISR_GP_DEASSERT_INT7_DA_mask                                            (0x00000100)
#define UMSK_ISR_GP_DEASSERT_INT7_DA(data)                                           (0x00000100&((data)<<8))
#define UMSK_ISR_GP_DEASSERT_INT7_DA_src(data)                                       ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_DEASSERT_get_INT7_DA(data)                                       ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_DEASSERT_INT6_DA_shift                                           (7)
#define UMSK_ISR_GP_DEASSERT_INT6_DA_mask                                            (0x00000080)
#define UMSK_ISR_GP_DEASSERT_INT6_DA(data)                                           (0x00000080&((data)<<7))
#define UMSK_ISR_GP_DEASSERT_INT6_DA_src(data)                                       ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_DEASSERT_get_INT6_DA(data)                                       ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_DEASSERT_INT5_DA_shift                                           (6)
#define UMSK_ISR_GP_DEASSERT_INT5_DA_mask                                            (0x00000040)
#define UMSK_ISR_GP_DEASSERT_INT5_DA(data)                                           (0x00000040&((data)<<6))
#define UMSK_ISR_GP_DEASSERT_INT5_DA_src(data)                                       ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_DEASSERT_get_INT5_DA(data)                                       ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_DEASSERT_INT4_DA_shift                                           (5)
#define UMSK_ISR_GP_DEASSERT_INT4_DA_mask                                            (0x00000020)
#define UMSK_ISR_GP_DEASSERT_INT4_DA(data)                                           (0x00000020&((data)<<5))
#define UMSK_ISR_GP_DEASSERT_INT4_DA_src(data)                                       ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_DEASSERT_get_INT4_DA(data)                                       ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_DEASSERT_INT3_DA_shift                                           (4)
#define UMSK_ISR_GP_DEASSERT_INT3_DA_mask                                            (0x00000010)
#define UMSK_ISR_GP_DEASSERT_INT3_DA(data)                                           (0x00000010&((data)<<4))
#define UMSK_ISR_GP_DEASSERT_INT3_DA_src(data)                                       ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_DEASSERT_get_INT3_DA(data)                                       ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_DEASSERT_INT2_DA_shift                                           (3)
#define UMSK_ISR_GP_DEASSERT_INT2_DA_mask                                            (0x00000008)
#define UMSK_ISR_GP_DEASSERT_INT2_DA(data)                                           (0x00000008&((data)<<3))
#define UMSK_ISR_GP_DEASSERT_INT2_DA_src(data)                                       ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_DEASSERT_get_INT2_DA(data)                                       ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_DEASSERT_INT1_DA_shift                                           (2)
#define UMSK_ISR_GP_DEASSERT_INT1_DA_mask                                            (0x00000004)
#define UMSK_ISR_GP_DEASSERT_INT1_DA(data)                                           (0x00000004&((data)<<2))
#define UMSK_ISR_GP_DEASSERT_INT1_DA_src(data)                                       ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_DEASSERT_get_INT1_DA(data)                                       ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_DEASSERT_INT0_DA_shift                                           (1)
#define UMSK_ISR_GP_DEASSERT_INT0_DA_mask                                            (0x00000002)
#define UMSK_ISR_GP_DEASSERT_INT0_DA(data)                                           (0x00000002&((data)<<1))
#define UMSK_ISR_GP_DEASSERT_INT0_DA_src(data)                                       ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_DEASSERT_get_INT0_DA(data)                                       ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_DEASSERT_write_data_shift                                        (0)
#define UMSK_ISR_GP_DEASSERT_write_data_mask                                         (0x00000001)
#define UMSK_ISR_GP_DEASSERT_write_data(data)                                        (0x00000001&((data)<<0))
#define UMSK_ISR_GP_DEASSERT_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define UMSK_ISR_GP_DEASSERT_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define UMSK_ISR_GP_DEASSERT_1                                                       0x18061014
#define UMSK_ISR_GP_DEASSERT_1_reg_addr                                              "0xB8061014"
#define UMSK_ISR_GP_DEASSERT_1_reg                                                   0xB8061014
#define set_UMSK_ISR_GP_DEASSERT_1_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP_DEASSERT_1_reg)=data)
#define get_UMSK_ISR_GP_DEASSERT_1_reg   (*((volatile unsigned int*) UMSK_ISR_GP_DEASSERT_1_reg))
#define UMSK_ISR_GP_DEASSERT_1_inst_adr                                              "0x0005"
#define UMSK_ISR_GP_DEASSERT_1_inst                                                  0x0005
#define UMSK_ISR_GP_DEASSERT_1_INT39_DA_shift                                        (9)
#define UMSK_ISR_GP_DEASSERT_1_INT39_DA_mask                                         (0x00000200)
#define UMSK_ISR_GP_DEASSERT_1_INT39_DA(data)                                        (0x00000200&((data)<<9))
#define UMSK_ISR_GP_DEASSERT_1_INT39_DA_src(data)                                    ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_DEASSERT_1_get_INT39_DA(data)                                    ((0x00000200&(data))>>9)
#define UMSK_ISR_GP_DEASSERT_1_INT38_DA_shift                                        (8)
#define UMSK_ISR_GP_DEASSERT_1_INT38_DA_mask                                         (0x00000100)
#define UMSK_ISR_GP_DEASSERT_1_INT38_DA(data)                                        (0x00000100&((data)<<8))
#define UMSK_ISR_GP_DEASSERT_1_INT38_DA_src(data)                                    ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_DEASSERT_1_get_INT38_DA(data)                                    ((0x00000100&(data))>>8)
#define UMSK_ISR_GP_DEASSERT_1_INT37_DA_shift                                        (7)
#define UMSK_ISR_GP_DEASSERT_1_INT37_DA_mask                                         (0x00000080)
#define UMSK_ISR_GP_DEASSERT_1_INT37_DA(data)                                        (0x00000080&((data)<<7))
#define UMSK_ISR_GP_DEASSERT_1_INT37_DA_src(data)                                    ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_DEASSERT_1_get_INT37_DA(data)                                    ((0x00000080&(data))>>7)
#define UMSK_ISR_GP_DEASSERT_1_INT36_DA_shift                                        (6)
#define UMSK_ISR_GP_DEASSERT_1_INT36_DA_mask                                         (0x00000040)
#define UMSK_ISR_GP_DEASSERT_1_INT36_DA(data)                                        (0x00000040&((data)<<6))
#define UMSK_ISR_GP_DEASSERT_1_INT36_DA_src(data)                                    ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_DEASSERT_1_get_INT36_DA(data)                                    ((0x00000040&(data))>>6)
#define UMSK_ISR_GP_DEASSERT_1_INT35_DA_shift                                        (5)
#define UMSK_ISR_GP_DEASSERT_1_INT35_DA_mask                                         (0x00000020)
#define UMSK_ISR_GP_DEASSERT_1_INT35_DA(data)                                        (0x00000020&((data)<<5))
#define UMSK_ISR_GP_DEASSERT_1_INT35_DA_src(data)                                    ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_DEASSERT_1_get_INT35_DA(data)                                    ((0x00000020&(data))>>5)
#define UMSK_ISR_GP_DEASSERT_1_INT34_DA_shift                                        (4)
#define UMSK_ISR_GP_DEASSERT_1_INT34_DA_mask                                         (0x00000010)
#define UMSK_ISR_GP_DEASSERT_1_INT34_DA(data)                                        (0x00000010&((data)<<4))
#define UMSK_ISR_GP_DEASSERT_1_INT34_DA_src(data)                                    ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_DEASSERT_1_get_INT34_DA(data)                                    ((0x00000010&(data))>>4)
#define UMSK_ISR_GP_DEASSERT_1_INT33_DA_shift                                        (3)
#define UMSK_ISR_GP_DEASSERT_1_INT33_DA_mask                                         (0x00000008)
#define UMSK_ISR_GP_DEASSERT_1_INT33_DA(data)                                        (0x00000008&((data)<<3))
#define UMSK_ISR_GP_DEASSERT_1_INT33_DA_src(data)                                    ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_DEASSERT_1_get_INT33_DA(data)                                    ((0x00000008&(data))>>3)
#define UMSK_ISR_GP_DEASSERT_1_INT32_DA_shift                                        (2)
#define UMSK_ISR_GP_DEASSERT_1_INT32_DA_mask                                         (0x00000004)
#define UMSK_ISR_GP_DEASSERT_1_INT32_DA(data)                                        (0x00000004&((data)<<2))
#define UMSK_ISR_GP_DEASSERT_1_INT32_DA_src(data)                                    ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_DEASSERT_1_get_INT32_DA(data)                                    ((0x00000004&(data))>>2)
#define UMSK_ISR_GP_DEASSERT_1_INT31_DA_shift                                        (1)
#define UMSK_ISR_GP_DEASSERT_1_INT31_DA_mask                                         (0x00000002)
#define UMSK_ISR_GP_DEASSERT_1_INT31_DA(data)                                        (0x00000002&((data)<<1))
#define UMSK_ISR_GP_DEASSERT_1_INT31_DA_src(data)                                    ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_DEASSERT_1_get_INT31_DA(data)                                    ((0x00000002&(data))>>1)
#define UMSK_ISR_GP_DEASSERT_1_write_data_shift                                      (0)
#define UMSK_ISR_GP_DEASSERT_1_write_data_mask                                       (0x00000001)
#define UMSK_ISR_GP_DEASSERT_1_write_data(data)                                      (0x00000001&((data)<<0))
#define UMSK_ISR_GP_DEASSERT_1_write_data_src(data)                                  ((0x00000001&(data))>>0)
#define UMSK_ISR_GP_DEASSERT_1_get_write_data(data)                                  ((0x00000001&(data))>>0)


#define ISO_DBG                                                                      0x18061018
#define ISO_DBG_reg_addr                                                             "0xB8061018"
#define ISO_DBG_reg                                                                  0xB8061018
#define set_ISO_DBG_reg(data)   (*((volatile unsigned int*) ISO_DBG_reg)=data)
#define get_ISO_DBG_reg   (*((volatile unsigned int*) ISO_DBG_reg))
#define ISO_DBG_inst_adr                                                             "0x0006"
#define ISO_DBG_inst                                                                 0x0006
#define ISO_DBG_write_en3_shift                                                      (11)
#define ISO_DBG_write_en3_mask                                                       (0x00000800)
#define ISO_DBG_write_en3(data)                                                      (0x00000800&((data)<<11))
#define ISO_DBG_write_en3_src(data)                                                  ((0x00000800&(data))>>11)
#define ISO_DBG_get_write_en3(data)                                                  ((0x00000800&(data))>>11)
#define ISO_DBG_sel1_shift                                                           (7)
#define ISO_DBG_sel1_mask                                                            (0x00000780)
#define ISO_DBG_sel1(data)                                                           (0x00000780&((data)<<7))
#define ISO_DBG_sel1_src(data)                                                       ((0x00000780&(data))>>7)
#define ISO_DBG_get_sel1(data)                                                       ((0x00000780&(data))>>7)
#define ISO_DBG_write_en2_shift                                                      (6)
#define ISO_DBG_write_en2_mask                                                       (0x00000040)
#define ISO_DBG_write_en2(data)                                                      (0x00000040&((data)<<6))
#define ISO_DBG_write_en2_src(data)                                                  ((0x00000040&(data))>>6)
#define ISO_DBG_get_write_en2(data)                                                  ((0x00000040&(data))>>6)
#define ISO_DBG_sel0_shift                                                           (2)
#define ISO_DBG_sel0_mask                                                            (0x0000003C)
#define ISO_DBG_sel0(data)                                                           (0x0000003C&((data)<<2))
#define ISO_DBG_sel0_src(data)                                                       ((0x0000003C&(data))>>2)
#define ISO_DBG_get_sel0(data)                                                       ((0x0000003C&(data))>>2)
#define ISO_DBG_write_en1_shift                                                      (1)
#define ISO_DBG_write_en1_mask                                                       (0x00000002)
#define ISO_DBG_write_en1(data)                                                      (0x00000002&((data)<<1))
#define ISO_DBG_write_en1_src(data)                                                  ((0x00000002&(data))>>1)
#define ISO_DBG_get_write_en1(data)                                                  ((0x00000002&(data))>>1)
#define ISO_DBG_enable_shift                                                         (0)
#define ISO_DBG_enable_mask                                                          (0x00000001)
#define ISO_DBG_enable(data)                                                         (0x00000001&((data)<<0))
#define ISO_DBG_enable_src(data)                                                     ((0x00000001&(data))>>0)
#define ISO_DBG_get_enable(data)                                                     ((0x00000001&(data))>>0)


#define ISO_DUMMY1                                                                   0x1806101C
#define ISO_DUMMY1_reg_addr                                                          "0xB806101C"
#define ISO_DUMMY1_reg                                                               0xB806101C
#define set_ISO_DUMMY1_reg(data)   (*((volatile unsigned int*) ISO_DUMMY1_reg)=data)
#define get_ISO_DUMMY1_reg   (*((volatile unsigned int*) ISO_DUMMY1_reg))
#define ISO_DUMMY1_inst_adr                                                          "0x0007"
#define ISO_DUMMY1_inst                                                              0x0007
#define ISO_DUMMY1_write_en2_shift                                                   (31)
#define ISO_DUMMY1_write_en2_mask                                                    (0x80000000)
#define ISO_DUMMY1_write_en2(data)                                                   (0x80000000&((data)<<31))
#define ISO_DUMMY1_write_en2_src(data)                                               ((0x80000000&(data))>>31)
#define ISO_DUMMY1_get_write_en2(data)                                               ((0x80000000&(data))>>31)
#define ISO_DUMMY1_Rvd2_shift                                                        (18)
#define ISO_DUMMY1_Rvd2_mask                                                         (0x7FFC0000)
#define ISO_DUMMY1_Rvd2(data)                                                        (0x7FFC0000&((data)<<18))
#define ISO_DUMMY1_Rvd2_src(data)                                                    ((0x7FFC0000&(data))>>18)
#define ISO_DUMMY1_get_Rvd2(data)                                                    ((0x7FFC0000&(data))>>18)
#define ISO_DUMMY1_Irdarxdetec_shift                                                 (17)
#define ISO_DUMMY1_Irdarxdetec_mask                                                  (0x00020000)
#define ISO_DUMMY1_Irdarxdetec(data)                                                 (0x00020000&((data)<<17))
#define ISO_DUMMY1_Irdarxdetec_src(data)                                             ((0x00020000&(data))>>17)
#define ISO_DUMMY1_get_Irdarxdetec(data)                                             ((0x00020000&(data))>>17)
#define ISO_DUMMY1_DDCdataindetect_shift                                             (16)
#define ISO_DUMMY1_DDCdataindetect_mask                                              (0x00010000)
#define ISO_DUMMY1_DDCdataindetect(data)                                             (0x00010000&((data)<<16))
#define ISO_DUMMY1_DDCdataindetect_src(data)                                         ((0x00010000&(data))>>16)
#define ISO_DUMMY1_get_DDCdataindetect(data)                                         ((0x00010000&(data))>>16)
#define ISO_DUMMY1_write_en1_shift                                                   (15)
#define ISO_DUMMY1_write_en1_mask                                                    (0x00008000)
#define ISO_DUMMY1_write_en1(data)                                                   (0x00008000&((data)<<15))
#define ISO_DUMMY1_write_en1_src(data)                                               ((0x00008000&(data))>>15)
#define ISO_DUMMY1_get_write_en1(data)                                               ((0x00008000&(data))>>15)
#define ISO_DUMMY1_Rvd1_shift                                                        (0)
#define ISO_DUMMY1_Rvd1_mask                                                         (0x00007FFF)
#define ISO_DUMMY1_Rvd1(data)                                                        (0x00007FFF&((data)<<0))
#define ISO_DUMMY1_Rvd1_src(data)                                                    ((0x00007FFF&(data))>>0)
#define ISO_DUMMY1_get_Rvd1(data)                                                    ((0x00007FFF&(data))>>0)


#define CHIP_INFO1                                                                   0x18061020
#define CHIP_INFO1_reg_addr                                                          "0xB8061020"
#define CHIP_INFO1_reg                                                               0xB8061020
#define set_CHIP_INFO1_reg(data)   (*((volatile unsigned int*) CHIP_INFO1_reg)=data)
#define get_CHIP_INFO1_reg   (*((volatile unsigned int*) CHIP_INFO1_reg))
#define CHIP_INFO1_inst_adr                                                          "0x0008"
#define CHIP_INFO1_inst                                                              0x0008
#define CHIP_INFO1_testmode_shift                                                    (13)
#define CHIP_INFO1_testmode_mask                                                     (0x00002000)
#define CHIP_INFO1_testmode(data)                                                    (0x00002000&((data)<<13))
#define CHIP_INFO1_testmode_src(data)                                                ((0x00002000&(data))>>13)
#define CHIP_INFO1_get_testmode(data)                                                ((0x00002000&(data))>>13)
#define CHIP_INFO1_nf_sel_shift                                                      (12)
#define CHIP_INFO1_nf_sel_mask                                                       (0x00001000)
#define CHIP_INFO1_nf_sel(data)                                                      (0x00001000&((data)<<12))
#define CHIP_INFO1_nf_sel_src(data)                                                  ((0x00001000&(data))>>12)
#define CHIP_INFO1_get_nf_sel(data)                                                  ((0x00001000&(data))>>12)
#define CHIP_INFO1_bound_opt_shift                                                   (0)
#define CHIP_INFO1_bound_opt_mask                                                    (0x000003FF)
#define CHIP_INFO1_bound_opt(data)                                                   (0x000003FF&((data)<<0))
#define CHIP_INFO1_bound_opt_src(data)                                               ((0x000003FF&(data))>>0)
#define CHIP_INFO1_get_bound_opt(data)                                               ((0x000003FF&(data))>>0)


#define ISO_SCPU_INT_EN                                                              0x18061024
#define ISO_SCPU_INT_EN_reg_addr                                                     "0xB8061024"
#define ISO_SCPU_INT_EN_reg                                                          0xB8061024
#define set_ISO_SCPU_INT_EN_reg(data)   (*((volatile unsigned int*) ISO_SCPU_INT_EN_reg)=data)
#define get_ISO_SCPU_INT_EN_reg   (*((volatile unsigned int*) ISO_SCPU_INT_EN_reg))
#define ISO_SCPU_INT_EN_inst_adr                                                     "0x0009"
#define ISO_SCPU_INT_EN_inst                                                         0x0009
#define ISO_SCPU_INT_EN_GPIODA_INT_shift                                             (20)
#define ISO_SCPU_INT_EN_GPIODA_INT_mask                                              (0x00100000)
#define ISO_SCPU_INT_EN_GPIODA_INT(data)                                             (0x00100000&((data)<<20))
#define ISO_SCPU_INT_EN_GPIODA_INT_src(data)                                         ((0x00100000&(data))>>20)
#define ISO_SCPU_INT_EN_get_GPIODA_INT(data)                                         ((0x00100000&(data))>>20)
#define ISO_SCPU_INT_EN_GPIOA_INT_shift                                              (19)
#define ISO_SCPU_INT_EN_GPIOA_INT_mask                                               (0x00080000)
#define ISO_SCPU_INT_EN_GPIOA_INT(data)                                              (0x00080000&((data)<<19))
#define ISO_SCPU_INT_EN_GPIOA_INT_src(data)                                          ((0x00080000&(data))>>19)
#define ISO_SCPU_INT_EN_get_GPIOA_INT(data)                                          ((0x00080000&(data))>>19)
#define ISO_SCPU_INT_EN_DDC0_INT_shift                                               (18)
#define ISO_SCPU_INT_EN_DDC0_INT_mask                                                (0x00040000)
#define ISO_SCPU_INT_EN_DDC0_INT(data)                                               (0x00040000&((data)<<18))
#define ISO_SCPU_INT_EN_DDC0_INT_src(data)                                           ((0x00040000&(data))>>18)
#define ISO_SCPU_INT_EN_get_DDC0_INT(data)                                           ((0x00040000&(data))>>18)
#define ISO_SCPU_INT_EN_LSADC_INT_shift                                              (10)
#define ISO_SCPU_INT_EN_LSADC_INT_mask                                               (0x00000400)
#define ISO_SCPU_INT_EN_LSADC_INT(data)                                              (0x00000400&((data)<<10))
#define ISO_SCPU_INT_EN_LSADC_INT_src(data)                                          ((0x00000400&(data))>>10)
#define ISO_SCPU_INT_EN_get_LSADC_INT(data)                                          ((0x00000400&(data))>>10)
#define ISO_SCPU_INT_EN_IRDA_INT_shift                                               (5)
#define ISO_SCPU_INT_EN_IRDA_INT_mask                                                (0x00000020)
#define ISO_SCPU_INT_EN_IRDA_INT(data)                                               (0x00000020&((data)<<5))
#define ISO_SCPU_INT_EN_IRDA_INT_src(data)                                           ((0x00000020&(data))>>5)
#define ISO_SCPU_INT_EN_get_IRDA_INT(data)                                           ((0x00000020&(data))>>5)
#define ISO_SCPU_INT_EN_TC0_INT_shift                                                (3)
#define ISO_SCPU_INT_EN_TC0_INT_mask                                                 (0x00000008)
#define ISO_SCPU_INT_EN_TC0_INT(data)                                                (0x00000008&((data)<<3))
#define ISO_SCPU_INT_EN_TC0_INT_src(data)                                            ((0x00000008&(data))>>3)
#define ISO_SCPU_INT_EN_get_TC0_INT(data)                                            ((0x00000008&(data))>>3)
#define ISO_SCPU_INT_EN_write_data_shift                                             (0)
#define ISO_SCPU_INT_EN_write_data_mask                                              (0x00000001)
#define ISO_SCPU_INT_EN_write_data(data)                                             (0x00000001&((data)<<0))
#define ISO_SCPU_INT_EN_write_data_src(data)                                         ((0x00000001&(data))>>0)
#define ISO_SCPU_INT_EN_get_write_data(data)                                         ((0x00000001&(data))>>0)


#define GPDIR                                                                        0x18061100
#define GPDIR_reg_addr                                                               "0xB8061100"
#define GPDIR_reg                                                                    0xB8061100
#define set_GPDIR_reg(data)   (*((volatile unsigned int*) GPDIR_reg)=data)
#define get_GPDIR_reg   (*((volatile unsigned int*) GPDIR_reg))
#define GPDIR_inst_adr                                                               "0x0040"
#define GPDIR_inst                                                                   0x0040
#define GPDIR_GPDIR_shift                                                            (0)
#define GPDIR_GPDIR_mask                                                             (0xFFFFFFFF)
#define GPDIR_GPDIR(data)                                                            (0xFFFFFFFF&((data)<<0))
#define GPDIR_GPDIR_src(data)                                                        ((0xFFFFFFFF&(data))>>0)
#define GPDIR_get_GPDIR(data)                                                        ((0xFFFFFFFF&(data))>>0)


#define GPDIR_1                                                                      0x18061104
#define GPDIR_1_reg_addr                                                             "0xB8061104"
#define GPDIR_1_reg                                                                  0xB8061104
#define set_GPDIR_1_reg(data)   (*((volatile unsigned int*) GPDIR_1_reg)=data)
#define get_GPDIR_1_reg   (*((volatile unsigned int*) GPDIR_1_reg))
#define GPDIR_1_inst_adr                                                             "0x0041"
#define GPDIR_1_inst                                                                 0x0041
#define GPDIR_1_GPDIR_shift                                                          (0)
#define GPDIR_1_GPDIR_mask                                                           (0x000000FF)
#define GPDIR_1_GPDIR(data)                                                          (0x000000FF&((data)<<0))
#define GPDIR_1_GPDIR_src(data)                                                      ((0x000000FF&(data))>>0)
#define GPDIR_1_get_GPDIR(data)                                                      ((0x000000FF&(data))>>0)


#define GPDATO                                                                       0x18061108
#define GPDATO_reg_addr                                                              "0xB8061108"
#define GPDATO_reg                                                                   0xB8061108
#define set_GPDATO_reg(data)   (*((volatile unsigned int*) GPDATO_reg)=data)
#define get_GPDATO_reg   (*((volatile unsigned int*) GPDATO_reg))
#define GPDATO_inst_adr                                                              "0x0042"
#define GPDATO_inst                                                                  0x0042
#define GPDATO_GPDATO_shift                                                          (0)
#define GPDATO_GPDATO_mask                                                           (0xFFFFFFFF)
#define GPDATO_GPDATO(data)                                                          (0xFFFFFFFF&((data)<<0))
#define GPDATO_GPDATO_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define GPDATO_get_GPDATO(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define GPDATO_1                                                                     0x1806110C
#define GPDATO_1_reg_addr                                                            "0xB806110C"
#define GPDATO_1_reg                                                                 0xB806110C
#define set_GPDATO_1_reg(data)   (*((volatile unsigned int*) GPDATO_1_reg)=data)
#define get_GPDATO_1_reg   (*((volatile unsigned int*) GPDATO_1_reg))
#define GPDATO_1_inst_adr                                                            "0x0043"
#define GPDATO_1_inst                                                                0x0043
#define GPDATO_1_GPDATO_shift                                                        (0)
#define GPDATO_1_GPDATO_mask                                                         (0x000000FF)
#define GPDATO_1_GPDATO(data)                                                        (0x000000FF&((data)<<0))
#define GPDATO_1_GPDATO_src(data)                                                    ((0x000000FF&(data))>>0)
#define GPDATO_1_get_GPDATO(data)                                                    ((0x000000FF&(data))>>0)


#define GPDATI                                                                       0x18061110
#define GPDATI_reg_addr                                                              "0xB8061110"
#define GPDATI_reg                                                                   0xB8061110
#define set_GPDATI_reg(data)   (*((volatile unsigned int*) GPDATI_reg)=data)
#define get_GPDATI_reg   (*((volatile unsigned int*) GPDATI_reg))
#define GPDATI_inst_adr                                                              "0x0044"
#define GPDATI_inst                                                                  0x0044
#define GPDATI_GPDATI_shift                                                          (0)
#define GPDATI_GPDATI_mask                                                           (0xFFFFFFFF)
#define GPDATI_GPDATI(data)                                                          (0xFFFFFFFF&((data)<<0))
#define GPDATI_GPDATI_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define GPDATI_get_GPDATI(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define GPDATI_1                                                                     0x18061114
#define GPDATI_1_reg_addr                                                            "0xB8061114"
#define GPDATI_1_reg                                                                 0xB8061114
#define set_GPDATI_1_reg(data)   (*((volatile unsigned int*) GPDATI_1_reg)=data)
#define get_GPDATI_1_reg   (*((volatile unsigned int*) GPDATI_1_reg))
#define GPDATI_1_inst_adr                                                            "0x0045"
#define GPDATI_1_inst                                                                0x0045
#define GPDATI_1_GPDATI_shift                                                        (0)
#define GPDATI_1_GPDATI_mask                                                         (0x000000FF)
#define GPDATI_1_GPDATI(data)                                                        (0x000000FF&((data)<<0))
#define GPDATI_1_GPDATI_src(data)                                                    ((0x000000FF&(data))>>0)
#define GPDATI_1_get_GPDATI(data)                                                    ((0x000000FF&(data))>>0)


#define GPIE                                                                         0x18061118
#define GPIE_reg_addr                                                                "0xB8061118"
#define GPIE_reg                                                                     0xB8061118
#define set_GPIE_reg(data)   (*((volatile unsigned int*) GPIE_reg)=data)
#define get_GPIE_reg   (*((volatile unsigned int*) GPIE_reg))
#define GPIE_inst_adr                                                                "0x0046"
#define GPIE_inst                                                                    0x0046
#define GPIE_GP_shift                                                                (0)
#define GPIE_GP_mask                                                                 (0xFFFFFFFF)
#define GPIE_GP(data)                                                                (0xFFFFFFFF&((data)<<0))
#define GPIE_GP_src(data)                                                            ((0xFFFFFFFF&(data))>>0)
#define GPIE_get_GP(data)                                                            ((0xFFFFFFFF&(data))>>0)


#define GPIE_1                                                                       0x1806111C
#define GPIE_1_reg_addr                                                              "0xB806111C"
#define GPIE_1_reg                                                                   0xB806111C
#define set_GPIE_1_reg(data)   (*((volatile unsigned int*) GPIE_1_reg)=data)
#define get_GPIE_1_reg   (*((volatile unsigned int*) GPIE_1_reg))
#define GPIE_1_inst_adr                                                              "0x0047"
#define GPIE_1_inst                                                                  0x0047
#define GPIE_1_GP_shift                                                              (0)
#define GPIE_1_GP_mask                                                               (0x000000FF)
#define GPIE_1_GP(data)                                                              (0x000000FF&((data)<<0))
#define GPIE_1_GP_src(data)                                                          ((0x000000FF&(data))>>0)
#define GPIE_1_get_GP(data)                                                          ((0x000000FF&(data))>>0)


#define GPDP                                                                         0x18061120
#define GPDP_reg_addr                                                                "0xB8061120"
#define GPDP_reg                                                                     0xB8061120
#define set_GPDP_reg(data)   (*((volatile unsigned int*) GPDP_reg)=data)
#define get_GPDP_reg   (*((volatile unsigned int*) GPDP_reg))
#define GPDP_inst_adr                                                                "0x0048"
#define GPDP_inst                                                                    0x0048
#define GPDP_GPHA_shift                                                              (0)
#define GPDP_GPHA_mask                                                               (0xFFFFFFFF)
#define GPDP_GPHA(data)                                                              (0xFFFFFFFF&((data)<<0))
#define GPDP_GPHA_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define GPDP_get_GPHA(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define GPDP_1                                                                       0x18061124
#define GPDP_1_reg_addr                                                              "0xB8061124"
#define GPDP_1_reg                                                                   0xB8061124
#define set_GPDP_1_reg(data)   (*((volatile unsigned int*) GPDP_1_reg)=data)
#define get_GPDP_1_reg   (*((volatile unsigned int*) GPDP_1_reg))
#define GPDP_1_inst_adr                                                              "0x0049"
#define GPDP_1_inst                                                                  0x0049
#define GPDP_1_GPHA_shift                                                            (0)
#define GPDP_1_GPHA_mask                                                             (0x000000FF)
#define GPDP_1_GPHA(data)                                                            (0x000000FF&((data)<<0))
#define GPDP_1_GPHA_src(data)                                                        ((0x000000FF&(data))>>0)
#define GPDP_1_get_GPHA(data)                                                        ((0x000000FF&(data))>>0)


#define ISO_GPDEB                                                                    0x18061128
#define ISO_GPDEB_reg_addr                                                           "0xB8061128"
#define ISO_GPDEB_reg                                                                0xB8061128
#define set_ISO_GPDEB_reg(data)   (*((volatile unsigned int*) ISO_GPDEB_reg)=data)
#define get_ISO_GPDEB_reg   (*((volatile unsigned int*) ISO_GPDEB_reg))
#define ISO_GPDEB_inst_adr                                                           "0x004A"
#define ISO_GPDEB_inst                                                               0x004A
#define ISO_GPDEB_write_en2_shift                                                    (7)
#define ISO_GPDEB_write_en2_mask                                                     (0x00000080)
#define ISO_GPDEB_write_en2(data)                                                    (0x00000080&((data)<<7))
#define ISO_GPDEB_write_en2_src(data)                                                ((0x00000080&(data))>>7)
#define ISO_GPDEB_get_write_en2(data)                                                ((0x00000080&(data))>>7)
#define ISO_GPDEB_CLK2_shift                                                         (4)
#define ISO_GPDEB_CLK2_mask                                                          (0x00000070)
#define ISO_GPDEB_CLK2(data)                                                         (0x00000070&((data)<<4))
#define ISO_GPDEB_CLK2_src(data)                                                     ((0x00000070&(data))>>4)
#define ISO_GPDEB_get_CLK2(data)                                                     ((0x00000070&(data))>>4)
#define ISO_GPDEB_write_en1_shift                                                    (3)
#define ISO_GPDEB_write_en1_mask                                                     (0x00000008)
#define ISO_GPDEB_write_en1(data)                                                    (0x00000008&((data)<<3))
#define ISO_GPDEB_write_en1_src(data)                                                ((0x00000008&(data))>>3)
#define ISO_GPDEB_get_write_en1(data)                                                ((0x00000008&(data))>>3)
#define ISO_GPDEB_CLK1_shift                                                         (0)
#define ISO_GPDEB_CLK1_mask                                                          (0x00000007)
#define ISO_GPDEB_CLK1(data)                                                         (0x00000007&((data)<<0))
#define ISO_GPDEB_CLK1_src(data)                                                     ((0x00000007&(data))>>0)
#define ISO_GPDEB_get_CLK1(data)                                                     ((0x00000007&(data))>>0)


#define MIS_PWM_DB_CTRL                                                              0x18061180
#define MIS_PWM_DB_CTRL_reg_addr                                                     "0xB8061180"
#define MIS_PWM_DB_CTRL_reg                                                          0xB8061180
#define set_MIS_PWM_DB_CTRL_reg(data)   (*((volatile unsigned int*) MIS_PWM_DB_CTRL_reg)=data)
#define get_MIS_PWM_DB_CTRL_reg   (*((volatile unsigned int*) MIS_PWM_DB_CTRL_reg))
#define MIS_PWM_DB_CTRL_inst_adr                                                     "0x0060"
#define MIS_PWM_DB_CTRL_inst                                                         0x0060
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_EN_shift                                        (31)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_EN_mask                                         (0x80000000)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_EN(data)                                        (0x80000000&((data)<<31))
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_EN_src(data)                                    ((0x80000000&(data))>>31)
#define MIS_PWM_DB_CTRL_get_MIS_PWM_W_DB_EN(data)                                    ((0x80000000&(data))>>31)
#define MIS_PWM_DB_CTRL_MIS_PWM_DB_RSEL_shift                                        (30)
#define MIS_PWM_DB_CTRL_MIS_PWM_DB_RSEL_mask                                         (0x40000000)
#define MIS_PWM_DB_CTRL_MIS_PWM_DB_RSEL(data)                                        (0x40000000&((data)<<30))
#define MIS_PWM_DB_CTRL_MIS_PWM_DB_RSEL_src(data)                                    ((0x40000000&(data))>>30)
#define MIS_PWM_DB_CTRL_get_MIS_PWM_DB_RSEL(data)                                    ((0x40000000&(data))>>30)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_WR_shift                                        (29)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_WR_mask                                         (0x20000000)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_WR(data)                                        (0x20000000&((data)<<29))
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_WR_src(data)                                    ((0x20000000&(data))>>29)
#define MIS_PWM_DB_CTRL_get_MIS_PWM_W_DB_WR(data)                                    ((0x20000000&(data))>>29)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_MODE_shift                                      (28)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_MODE_mask                                       (0x10000000)
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_MODE(data)                                      (0x10000000&((data)<<28))
#define MIS_PWM_DB_CTRL_MIS_PWM_W_DB_MODE_src(data)                                  ((0x10000000&(data))>>28)
#define MIS_PWM_DB_CTRL_get_MIS_PWM_W_DB_MODE(data)                                  ((0x10000000&(data))>>28)


#define MIS_PWM0_CTRL                                                                0x18061184
#define MIS_PWM0_CTRL_reg_addr                                                       "0xB8061184"
#define MIS_PWM0_CTRL_reg                                                            0xB8061184
#define set_MIS_PWM0_CTRL_reg(data)   (*((volatile unsigned int*) MIS_PWM0_CTRL_reg)=data)
#define get_MIS_PWM0_CTRL_reg   (*((volatile unsigned int*) MIS_PWM0_CTRL_reg))
#define MIS_PWM0_CTRL_inst_adr                                                       "0x0061"
#define MIS_PWM0_CTRL_inst                                                           0x0061
#define MIS_PWM0_CTRL_MIS_PWM0L_shift                                                (31)
#define MIS_PWM0_CTRL_MIS_PWM0L_mask                                                 (0x80000000)
#define MIS_PWM0_CTRL_MIS_PWM0L(data)                                                (0x80000000&((data)<<31))
#define MIS_PWM0_CTRL_MIS_PWM0L_src(data)                                            ((0x80000000&(data))>>31)
#define MIS_PWM0_CTRL_get_MIS_PWM0L(data)                                            ((0x80000000&(data))>>31)
#define MIS_PWM0_CTRL_MIS_PWM0_CK_shift                                              (30)
#define MIS_PWM0_CTRL_MIS_PWM0_CK_mask                                               (0x40000000)
#define MIS_PWM0_CTRL_MIS_PWM0_CK(data)                                              (0x40000000&((data)<<30))
#define MIS_PWM0_CTRL_MIS_PWM0_CK_src(data)                                          ((0x40000000&(data))>>30)
#define MIS_PWM0_CTRL_get_MIS_PWM0_CK(data)                                          ((0x40000000&(data))>>30)
#define MIS_PWM0_CTRL_MIS_PWM0_EN_shift                                              (29)
#define MIS_PWM0_CTRL_MIS_PWM0_EN_mask                                               (0x20000000)
#define MIS_PWM0_CTRL_MIS_PWM0_EN(data)                                              (0x20000000&((data)<<29))
#define MIS_PWM0_CTRL_MIS_PWM0_EN_src(data)                                          ((0x20000000&(data))>>29)
#define MIS_PWM0_CTRL_get_MIS_PWM0_EN(data)                                          ((0x20000000&(data))>>29)
#define MIS_PWM0_CTRL_MIS_PWM0_VS_RST_EN_shift                                       (28)
#define MIS_PWM0_CTRL_MIS_PWM0_VS_RST_EN_mask                                        (0x10000000)
#define MIS_PWM0_CTRL_MIS_PWM0_VS_RST_EN(data)                                       (0x10000000&((data)<<28))
#define MIS_PWM0_CTRL_MIS_PWM0_VS_RST_EN_src(data)                                   ((0x10000000&(data))>>28)
#define MIS_PWM0_CTRL_get_MIS_PWM0_VS_RST_EN(data)                                   ((0x10000000&(data))>>28)
#define MIS_PWM0_CTRL_MIS_PWM0_DUT_8B_shift                                          (27)
#define MIS_PWM0_CTRL_MIS_PWM0_DUT_8B_mask                                           (0x08000000)
#define MIS_PWM0_CTRL_MIS_PWM0_DUT_8B(data)                                          (0x08000000&((data)<<27))
#define MIS_PWM0_CTRL_MIS_PWM0_DUT_8B_src(data)                                      ((0x08000000&(data))>>27)
#define MIS_PWM0_CTRL_get_MIS_PWM0_DUT_8B(data)                                      ((0x08000000&(data))>>27)
#define MIS_PWM0_CTRL_MIS_PWM_WIDTH_SEL_shift                                        (0)
#define MIS_PWM0_CTRL_MIS_PWM_WIDTH_SEL_mask                                         (0x00000001)
#define MIS_PWM0_CTRL_MIS_PWM_WIDTH_SEL(data)                                        (0x00000001&((data)<<0))
#define MIS_PWM0_CTRL_MIS_PWM_WIDTH_SEL_src(data)                                    ((0x00000001&(data))>>0)
#define MIS_PWM0_CTRL_get_MIS_PWM_WIDTH_SEL(data)                                    ((0x00000001&(data))>>0)


#define MIS_PWM0_TIMING_CTRL                                                         0x18061188
#define MIS_PWM0_TIMING_CTRL_reg_addr                                                "0xB8061188"
#define MIS_PWM0_TIMING_CTRL_reg                                                     0xB8061188
#define set_MIS_PWM0_TIMING_CTRL_reg(data)   (*((volatile unsigned int*) MIS_PWM0_TIMING_CTRL_reg)=data)
#define get_MIS_PWM0_TIMING_CTRL_reg   (*((volatile unsigned int*) MIS_PWM0_TIMING_CTRL_reg))
#define MIS_PWM0_TIMING_CTRL_inst_adr                                                "0x0062"
#define MIS_PWM0_TIMING_CTRL_inst                                                    0x0062
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CNT_MODE_shift                                 (31)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CNT_MODE_mask                                  (0x80000000)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CNT_MODE(data)                                 (0x80000000&((data)<<31))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CNT_MODE_src(data)                             ((0x80000000&(data))>>31)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_CNT_MODE(data)                             ((0x80000000&(data))>>31)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_HS_shift                                (30)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_HS_mask                                 (0x40000000)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_HS(data)                                (0x40000000&((data)<<30))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_HS_src(data)                            ((0x40000000&(data))>>30)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_CK_SEL_HS(data)                            ((0x40000000&(data))>>30)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_shift                                   (29)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_mask                                    (0x20000000)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL(data)                                   (0x20000000&((data)<<29))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CK_SEL_src(data)                               ((0x20000000&(data))>>29)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_CK_SEL(data)                               ((0x20000000&(data))>>29)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CYCLE_MAX_shift                                (24)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CYCLE_MAX_mask                                 (0x0F000000)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CYCLE_MAX(data)                                (0x0F000000&((data)<<24))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_CYCLE_MAX_src(data)                            ((0x0F000000&(data))>>24)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_CYCLE_MAX(data)                            ((0x0F000000&(data))>>24)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_M_shift                                        (12)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_M_mask                                         (0x00003000)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_M(data)                                        (0x00003000&((data)<<12))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_M_src(data)                                    ((0x00003000&(data))>>12)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_M(data)                                    ((0x00003000&(data))>>12)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_N_shift                                        (0)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_N_mask                                         (0x00000FFF)
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_N(data)                                        (0x00000FFF&((data)<<0))
#define MIS_PWM0_TIMING_CTRL_MIS_PWM0_N_src(data)                                    ((0x00000FFF&(data))>>0)
#define MIS_PWM0_TIMING_CTRL_get_MIS_PWM0_N(data)                                    ((0x00000FFF&(data))>>0)


#define MIS_PWM0_DUTY_SET                                                            0x1806118C
#define MIS_PWM0_DUTY_SET_reg_addr                                                   "0xB806118C"
#define MIS_PWM0_DUTY_SET_reg                                                        0xB806118C
#define set_MIS_PWM0_DUTY_SET_reg(data)   (*((volatile unsigned int*) MIS_PWM0_DUTY_SET_reg)=data)
#define get_MIS_PWM0_DUTY_SET_reg   (*((volatile unsigned int*) MIS_PWM0_DUTY_SET_reg))
#define MIS_PWM0_DUTY_SET_inst_adr                                                   "0x0063"
#define MIS_PWM0_DUTY_SET_inst                                                       0x0063
#define MIS_PWM0_DUTY_SET_MIS_PWM0_DUT_shift                                         (16)
#define MIS_PWM0_DUTY_SET_MIS_PWM0_DUT_mask                                          (0x0FFF0000)
#define MIS_PWM0_DUTY_SET_MIS_PWM0_DUT(data)                                         (0x0FFF0000&((data)<<16))
#define MIS_PWM0_DUTY_SET_MIS_PWM0_DUT_src(data)                                     ((0x0FFF0000&(data))>>16)
#define MIS_PWM0_DUTY_SET_get_MIS_PWM0_DUT(data)                                     ((0x0FFF0000&(data))>>16)
#define MIS_PWM0_DUTY_SET_MIS_PWM0_TOTALCNT_shift                                    (0)
#define MIS_PWM0_DUTY_SET_MIS_PWM0_TOTALCNT_mask                                     (0x00000FFF)
#define MIS_PWM0_DUTY_SET_MIS_PWM0_TOTALCNT(data)                                    (0x00000FFF&((data)<<0))
#define MIS_PWM0_DUTY_SET_MIS_PWM0_TOTALCNT_src(data)                                ((0x00000FFF&(data))>>0)
#define MIS_PWM0_DUTY_SET_get_MIS_PWM0_TOTALCNT(data)                                ((0x00000FFF&(data))>>0)


#define MIS_PWM1_CTRL                                                                0x18061190
#define MIS_PWM1_CTRL_reg_addr                                                       "0xB8061190"
#define MIS_PWM1_CTRL_reg                                                            0xB8061190
#define set_MIS_PWM1_CTRL_reg(data)   (*((volatile unsigned int*) MIS_PWM1_CTRL_reg)=data)
#define get_MIS_PWM1_CTRL_reg   (*((volatile unsigned int*) MIS_PWM1_CTRL_reg))
#define MIS_PWM1_CTRL_inst_adr                                                       "0x0064"
#define MIS_PWM1_CTRL_inst                                                           0x0064
#define MIS_PWM1_CTRL_MIS_PWM1L_shift                                                (31)
#define MIS_PWM1_CTRL_MIS_PWM1L_mask                                                 (0x80000000)
#define MIS_PWM1_CTRL_MIS_PWM1L(data)                                                (0x80000000&((data)<<31))
#define MIS_PWM1_CTRL_MIS_PWM1L_src(data)                                            ((0x80000000&(data))>>31)
#define MIS_PWM1_CTRL_get_MIS_PWM1L(data)                                            ((0x80000000&(data))>>31)
#define MIS_PWM1_CTRL_MIS_PWM1_CK_shift                                              (30)
#define MIS_PWM1_CTRL_MIS_PWM1_CK_mask                                               (0x40000000)
#define MIS_PWM1_CTRL_MIS_PWM1_CK(data)                                              (0x40000000&((data)<<30))
#define MIS_PWM1_CTRL_MIS_PWM1_CK_src(data)                                          ((0x40000000&(data))>>30)
#define MIS_PWM1_CTRL_get_MIS_PWM1_CK(data)                                          ((0x40000000&(data))>>30)
#define MIS_PWM1_CTRL_MIS_PWM1_EN_shift                                              (29)
#define MIS_PWM1_CTRL_MIS_PWM1_EN_mask                                               (0x20000000)
#define MIS_PWM1_CTRL_MIS_PWM1_EN(data)                                              (0x20000000&((data)<<29))
#define MIS_PWM1_CTRL_MIS_PWM1_EN_src(data)                                          ((0x20000000&(data))>>29)
#define MIS_PWM1_CTRL_get_MIS_PWM1_EN(data)                                          ((0x20000000&(data))>>29)
#define MIS_PWM1_CTRL_MIS_PWM1_VS_RST_EN_shift                                       (28)
#define MIS_PWM1_CTRL_MIS_PWM1_VS_RST_EN_mask                                        (0x10000000)
#define MIS_PWM1_CTRL_MIS_PWM1_VS_RST_EN(data)                                       (0x10000000&((data)<<28))
#define MIS_PWM1_CTRL_MIS_PWM1_VS_RST_EN_src(data)                                   ((0x10000000&(data))>>28)
#define MIS_PWM1_CTRL_get_MIS_PWM1_VS_RST_EN(data)                                   ((0x10000000&(data))>>28)
#define MIS_PWM1_CTRL_MIS_PWM1_DUT_8B_shift                                          (27)
#define MIS_PWM1_CTRL_MIS_PWM1_DUT_8B_mask                                           (0x08000000)
#define MIS_PWM1_CTRL_MIS_PWM1_DUT_8B(data)                                          (0x08000000&((data)<<27))
#define MIS_PWM1_CTRL_MIS_PWM1_DUT_8B_src(data)                                      ((0x08000000&(data))>>27)
#define MIS_PWM1_CTRL_get_MIS_PWM1_DUT_8B(data)                                      ((0x08000000&(data))>>27)


#define MIS_PWM1_TIMING_CTRL                                                         0x18061194
#define MIS_PWM1_TIMING_CTRL_reg_addr                                                "0xB8061194"
#define MIS_PWM1_TIMING_CTRL_reg                                                     0xB8061194
#define set_MIS_PWM1_TIMING_CTRL_reg(data)   (*((volatile unsigned int*) MIS_PWM1_TIMING_CTRL_reg)=data)
#define get_MIS_PWM1_TIMING_CTRL_reg   (*((volatile unsigned int*) MIS_PWM1_TIMING_CTRL_reg))
#define MIS_PWM1_TIMING_CTRL_inst_adr                                                "0x0065"
#define MIS_PWM1_TIMING_CTRL_inst                                                    0x0065
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CNT_MODE_shift                                 (31)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CNT_MODE_mask                                  (0x80000000)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CNT_MODE(data)                                 (0x80000000&((data)<<31))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CNT_MODE_src(data)                             ((0x80000000&(data))>>31)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_CNT_MODE(data)                             ((0x80000000&(data))>>31)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_HS_shift                                (30)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_HS_mask                                 (0x40000000)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_HS(data)                                (0x40000000&((data)<<30))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_HS_src(data)                            ((0x40000000&(data))>>30)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_CK_SEL_HS(data)                            ((0x40000000&(data))>>30)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_shift                                   (29)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_mask                                    (0x20000000)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL(data)                                   (0x20000000&((data)<<29))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CK_SEL_src(data)                               ((0x20000000&(data))>>29)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_CK_SEL(data)                               ((0x20000000&(data))>>29)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CYCLE_MAX_shift                                (24)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CYCLE_MAX_mask                                 (0x0F000000)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CYCLE_MAX(data)                                (0x0F000000&((data)<<24))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_CYCLE_MAX_src(data)                            ((0x0F000000&(data))>>24)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_CYCLE_MAX(data)                            ((0x0F000000&(data))>>24)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_M_shift                                        (12)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_M_mask                                         (0x00003000)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_M(data)                                        (0x00003000&((data)<<12))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_M_src(data)                                    ((0x00003000&(data))>>12)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_M(data)                                    ((0x00003000&(data))>>12)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_N_shift                                        (0)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_N_mask                                         (0x00000FFF)
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_N(data)                                        (0x00000FFF&((data)<<0))
#define MIS_PWM1_TIMING_CTRL_MIS_PWM1_N_src(data)                                    ((0x00000FFF&(data))>>0)
#define MIS_PWM1_TIMING_CTRL_get_MIS_PWM1_N(data)                                    ((0x00000FFF&(data))>>0)


#define MIS_PWM1_DUTY_SET                                                            0x18061198
#define MIS_PWM1_DUTY_SET_reg_addr                                                   "0xB8061198"
#define MIS_PWM1_DUTY_SET_reg                                                        0xB8061198
#define set_MIS_PWM1_DUTY_SET_reg(data)   (*((volatile unsigned int*) MIS_PWM1_DUTY_SET_reg)=data)
#define get_MIS_PWM1_DUTY_SET_reg   (*((volatile unsigned int*) MIS_PWM1_DUTY_SET_reg))
#define MIS_PWM1_DUTY_SET_inst_adr                                                   "0x0066"
#define MIS_PWM1_DUTY_SET_inst                                                       0x0066
#define MIS_PWM1_DUTY_SET_MIS_PWM1_DUT_shift                                         (16)
#define MIS_PWM1_DUTY_SET_MIS_PWM1_DUT_mask                                          (0x0FFF0000)
#define MIS_PWM1_DUTY_SET_MIS_PWM1_DUT(data)                                         (0x0FFF0000&((data)<<16))
#define MIS_PWM1_DUTY_SET_MIS_PWM1_DUT_src(data)                                     ((0x0FFF0000&(data))>>16)
#define MIS_PWM1_DUTY_SET_get_MIS_PWM1_DUT(data)                                     ((0x0FFF0000&(data))>>16)
#define MIS_PWM1_DUTY_SET_MIS_PWM1_TOTALCNT_shift                                    (0)
#define MIS_PWM1_DUTY_SET_MIS_PWM1_TOTALCNT_mask                                     (0x00000FFF)
#define MIS_PWM1_DUTY_SET_MIS_PWM1_TOTALCNT(data)                                    (0x00000FFF&((data)<<0))
#define MIS_PWM1_DUTY_SET_MIS_PWM1_TOTALCNT_src(data)                                ((0x00000FFF&(data))>>0)
#define MIS_PWM1_DUTY_SET_get_MIS_PWM1_TOTALCNT(data)                                ((0x00000FFF&(data))>>0)


#define IR_PSR                                                                       0x18061400
#define IR_PSR_reg_addr                                                              "0xB8061400"
#define IR_PSR_reg                                                                   0xB8061400
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


#define IR_PER                                                                       0x18061404
#define IR_PER_reg_addr                                                              "0xB8061404"
#define IR_PER_reg                                                                   0xB8061404
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


#define IR_SF                                                                        0x18061408
#define IR_SF_reg_addr                                                               "0xB8061408"
#define IR_SF_reg                                                                    0xB8061408
#define set_IR_SF_reg(data)   (*((volatile unsigned int*) IR_SF_reg)=data)
#define get_IR_SF_reg   (*((volatile unsigned int*) IR_SF_reg))
#define IR_SF_inst_adr                                                               "0x0002"
#define IR_SF_inst                                                                   0x0002
#define IR_SF_IRIT_shift                                                             (24)
#define IR_SF_IRIT_mask                                                              (0xFF000000)
#define IR_SF_IRIT(data)                                                             (0xFF000000&((data)<<24))
#define IR_SF_IRIT_src(data)                                                         ((0xFF000000&(data))>>24)
#define IR_SF_get_IRIT(data)                                                         ((0xFF000000&(data))>>24)
#define IR_SF_IROCT_shift                                                            (16)
#define IR_SF_IROCT_mask                                                             (0x00FF0000)
#define IR_SF_IROCT(data)                                                            (0x00FF0000&((data)<<16))
#define IR_SF_IROCT_src(data)                                                        ((0x00FF0000&(data))>>16)
#define IR_SF_get_IROCT(data)                                                        ((0x00FF0000&(data))>>16)
#define IR_SF_IRFD_shift                                                             (0)
#define IR_SF_IRFD_mask                                                              (0x0000FFFF)
#define IR_SF_IRFD(data)                                                             (0x0000FFFF&((data)<<0))
#define IR_SF_IRFD_src(data)                                                         ((0x0000FFFF&(data))>>0)
#define IR_SF_get_IRFD(data)                                                         ((0x0000FFFF&(data))>>0)


#define IR_DPIR                                                                      0x1806140C
#define IR_DPIR_reg_addr                                                             "0xB806140C"
#define IR_DPIR_reg                                                                  0xB806140C
#define set_IR_DPIR_reg(data)   (*((volatile unsigned int*) IR_DPIR_reg)=data)
#define get_IR_DPIR_reg   (*((volatile unsigned int*) IR_DPIR_reg))
#define IR_DPIR_inst_adr                                                             "0x0003"
#define IR_DPIR_inst                                                                 0x0003
#define IR_DPIR_IRIOTCDP_shift                                                       (0)
#define IR_DPIR_IRIOTCDP_mask                                                        (0x0000FFFF)
#define IR_DPIR_IRIOTCDP(data)                                                       (0x0000FFFF&((data)<<0))
#define IR_DPIR_IRIOTCDP_src(data)                                                   ((0x0000FFFF&(data))>>0)
#define IR_DPIR_get_IRIOTCDP(data)                                                   ((0x0000FFFF&(data))>>0)


#define IR_CR                                                                        0x18061410
#define IR_CR_reg_addr                                                               "0xB8061410"
#define IR_CR_reg                                                                    0xB8061410
#define set_IR_CR_reg(data)   (*((volatile unsigned int*) IR_CR_reg)=data)
#define get_IR_CR_reg   (*((volatile unsigned int*) IR_CR_reg))
#define IR_CR_inst_adr                                                               "0x0004"
#define IR_CR_inst                                                                   0x0004
#define IR_CR_IRSR_shift                                                             (31)
#define IR_CR_IRSR_mask                                                              (0x80000000)
#define IR_CR_IRSR(data)                                                             (0x80000000&((data)<<31))
#define IR_CR_IRSR_src(data)                                                         ((0x80000000&(data))>>31)
#define IR_CR_get_IRSR(data)                                                         ((0x80000000&(data))>>31)
#define IR_CR_IREDNM_shift                                                           (23)
#define IR_CR_IREDNM_mask                                                            (0x00800000)
#define IR_CR_IREDNM(data)                                                           (0x00800000&((data)<<23))
#define IR_CR_IREDNM_src(data)                                                       ((0x00800000&(data))>>23)
#define IR_CR_get_IREDNM(data)                                                       ((0x00800000&(data))>>23)
#define IR_CR_RC5_RC6commonmodeenable_shift                                          (22)
#define IR_CR_RC5_RC6commonmodeenable_mask                                           (0x00400000)
#define IR_CR_RC5_RC6commonmodeenable(data)                                          (0x00400000&((data)<<22))
#define IR_CR_RC5_RC6commonmodeenable_src(data)                                      ((0x00400000&(data))>>22)
#define IR_CR_get_RC5_RC6commonmodeenable(data)                                      ((0x00400000&(data))>>22)
#define IR_CR_IREDN_shift                                                            (16)
#define IR_CR_IREDN_mask                                                             (0x003F0000)
#define IR_CR_IREDN(data)                                                            (0x003F0000&((data)<<16))
#define IR_CR_IREDN_src(data)                                                        ((0x003F0000&(data))>>16)
#define IR_CR_get_IREDN(data)                                                        ((0x003F0000&(data))>>16)
#define IR_CR_burst_len_check_shift                                                  (15)
#define IR_CR_burst_len_check_mask                                                   (0x00008000)
#define IR_CR_burst_len_check(data)                                                  (0x00008000&((data)<<15))
#define IR_CR_burst_len_check_src(data)                                              ((0x00008000&(data))>>15)
#define IR_CR_get_burst_len_check(data)                                              ((0x00008000&(data))>>15)
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


#define IR_RP                                                                        0x18061414
#define IR_RP_reg_addr                                                               "0xB8061414"
#define IR_RP_reg                                                                    0xB8061414
#define set_IR_RP_reg(data)   (*((volatile unsigned int*) IR_RP_reg)=data)
#define get_IR_RP_reg   (*((volatile unsigned int*) IR_RP_reg))
#define IR_RP_inst_adr                                                               "0x0005"
#define IR_RP_inst                                                                   0x0005
#define IR_RP_IRRP_shift                                                             (0)
#define IR_RP_IRRP_mask                                                              (0xFFFFFFFF)
#define IR_RP_IRRP(data)                                                             (0xFFFFFFFF&((data)<<0))
#define IR_RP_IRRP_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define IR_RP_get_IRRP(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define IR_SR                                                                        0x18061418
#define IR_SR_reg_addr                                                               "0xB8061418"
#define IR_SR_reg                                                                    0xB8061418
#define set_IR_SR_reg(data)   (*((volatile unsigned int*) IR_SR_reg)=data)
#define get_IR_SR_reg   (*((volatile unsigned int*) IR_SR_reg))
#define IR_SR_inst_adr                                                               "0x0006"
#define IR_SR_inst                                                                   0x0006
#define IR_SR_leader_wrong_shift                                                     (6)
#define IR_SR_leader_wrong_mask                                                      (0x00000040)
#define IR_SR_leader_wrong(data)                                                     (0x00000040&((data)<<6))
#define IR_SR_leader_wrong_src(data)                                                 ((0x00000040&(data))>>6)
#define IR_SR_get_leader_wrong(data)                                                 ((0x00000040&(data))>>6)
#define IR_SR_data_still_toggle_shift                                                (5)
#define IR_SR_data_still_toggle_mask                                                 (0x00000020)
#define IR_SR_data_still_toggle(data)                                                (0x00000020&((data)<<5))
#define IR_SR_data_still_toggle_src(data)                                            ((0x00000020&(data))>>5)
#define IR_SR_get_data_still_toggle(data)                                            ((0x00000020&(data))>>5)
#define IR_SR_rmt_big_shift                                                          (4)
#define IR_SR_rmt_big_mask                                                           (0x00000010)
#define IR_SR_rmt_big(data)                                                          (0x00000010&((data)<<4))
#define IR_SR_rmt_big_src(data)                                                      ((0x00000010&(data))>>4)
#define IR_SR_get_rmt_big(data)                                                      ((0x00000010&(data))>>4)
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


#define IR_RAW_CTRL                                                                  0x1806141C
#define IR_RAW_CTRL_reg_addr                                                         "0xB806141C"
#define IR_RAW_CTRL_reg                                                              0xB806141C
#define set_IR_RAW_CTRL_reg(data)   (*((volatile unsigned int*) IR_RAW_CTRL_reg)=data)
#define get_IR_RAW_CTRL_reg   (*((volatile unsigned int*) IR_RAW_CTRL_reg))
#define IR_RAW_CTRL_inst_adr                                                         "0x0007"
#define IR_RAW_CTRL_inst                                                             0x0007
#define IR_RAW_CTRL_write_en3_shift                                                  (27)
#define IR_RAW_CTRL_write_en3_mask                                                   (0x08000000)
#define IR_RAW_CTRL_write_en3(data)                                                  (0x08000000&((data)<<27))
#define IR_RAW_CTRL_write_en3_src(data)                                              ((0x08000000&(data))>>27)
#define IR_RAW_CTRL_get_write_en3(data)                                              ((0x08000000&(data))>>27)
#define IR_RAW_CTRL_Data_store_in_DRAM_shift                                         (26)
#define IR_RAW_CTRL_Data_store_in_DRAM_mask                                          (0x04000000)
#define IR_RAW_CTRL_Data_store_in_DRAM(data)                                         (0x04000000&((data)<<26))
#define IR_RAW_CTRL_Data_store_in_DRAM_src(data)                                     ((0x04000000&(data))>>26)
#define IR_RAW_CTRL_get_Data_store_in_DRAM(data)                                     ((0x04000000&(data))>>26)
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


#define IR_RAW_FF                                                                    0x18061420
#define IR_RAW_FF_reg_addr                                                           "0xB8061420"
#define IR_RAW_FF_reg                                                                0xB8061420
#define set_IR_RAW_FF_reg(data)   (*((volatile unsigned int*) IR_RAW_FF_reg)=data)
#define get_IR_RAW_FF_reg   (*((volatile unsigned int*) IR_RAW_FF_reg))
#define IR_RAW_FF_inst_adr                                                           "0x0008"
#define IR_RAW_FF_inst                                                               0x0008
#define IR_RAW_FF_DAT_shift                                                          (0)
#define IR_RAW_FF_DAT_mask                                                           (0xFFFFFFFF)
#define IR_RAW_FF_DAT(data)                                                          (0xFFFFFFFF&((data)<<0))
#define IR_RAW_FF_DAT_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define IR_RAW_FF_get_DAT(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define IR_RAW_SAMPLE_TIME                                                           0x18061424
#define IR_RAW_SAMPLE_TIME_reg_addr                                                  "0xB8061424"
#define IR_RAW_SAMPLE_TIME_reg                                                       0xB8061424
#define set_IR_RAW_SAMPLE_TIME_reg(data)   (*((volatile unsigned int*) IR_RAW_SAMPLE_TIME_reg)=data)
#define get_IR_RAW_SAMPLE_TIME_reg   (*((volatile unsigned int*) IR_RAW_SAMPLE_TIME_reg))
#define IR_RAW_SAMPLE_TIME_inst_adr                                                  "0x0009"
#define IR_RAW_SAMPLE_TIME_inst                                                      0x0009
#define IR_RAW_SAMPLE_TIME_CNT_shift                                                 (0)
#define IR_RAW_SAMPLE_TIME_CNT_mask                                                  (0x0000FFFF)
#define IR_RAW_SAMPLE_TIME_CNT(data)                                                 (0x0000FFFF&((data)<<0))
#define IR_RAW_SAMPLE_TIME_CNT_src(data)                                             ((0x0000FFFF&(data))>>0)
#define IR_RAW_SAMPLE_TIME_get_CNT(data)                                             ((0x0000FFFF&(data))>>0)


#define IR_RAW_WL                                                                    0x18061428
#define IR_RAW_WL_reg_addr                                                           "0xB8061428"
#define IR_RAW_WL_reg                                                                0xB8061428
#define set_IR_RAW_WL_reg(data)   (*((volatile unsigned int*) IR_RAW_WL_reg)=data)
#define get_IR_RAW_WL_reg   (*((volatile unsigned int*) IR_RAW_WL_reg))
#define IR_RAW_WL_inst_adr                                                           "0x000A"
#define IR_RAW_WL_inst                                                               0x000A
#define IR_RAW_WL_VAL_shift                                                          (0)
#define IR_RAW_WL_VAL_mask                                                           (0x0000003F)
#define IR_RAW_WL_VAL(data)                                                          (0x0000003F&((data)<<0))
#define IR_RAW_WL_VAL_src(data)                                                      ((0x0000003F&(data))>>0)
#define IR_RAW_WL_get_VAL(data)                                                      ((0x0000003F&(data))>>0)


#define IR_RAW_DEB                                                                   0x1806142C
#define IR_RAW_DEB_reg_addr                                                          "0xB806142C"
#define IR_RAW_DEB_reg                                                               0xB806142C
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


#define IR_PSR_UP                                                                    0x18061430
#define IR_PSR_UP_reg_addr                                                           "0xB8061430"
#define IR_PSR_UP_reg                                                                0xB8061430
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


#define IR_PER_UP                                                                    0x18061434
#define IR_PER_UP_reg_addr                                                           "0xB8061434"
#define IR_PER_UP_reg                                                                0xB8061434
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


#define IR_CTRL_RC6                                                                  0x18061438
#define IR_CTRL_RC6_reg_addr                                                         "0xB8061438"
#define IR_CTRL_RC6_reg                                                              0xB8061438
#define set_IR_CTRL_RC6_reg(data)   (*((volatile unsigned int*) IR_CTRL_RC6_reg)=data)
#define get_IR_CTRL_RC6_reg   (*((volatile unsigned int*) IR_CTRL_RC6_reg))
#define IR_CTRL_RC6_inst_adr                                                         "0x000E"
#define IR_CTRL_RC6_inst                                                             0x000E
#define IR_CTRL_RC6_toshiba_en_shift                                                 (9)
#define IR_CTRL_RC6_toshiba_en_mask                                                  (0x00000200)
#define IR_CTRL_RC6_toshiba_en(data)                                                 (0x00000200&((data)<<9))
#define IR_CTRL_RC6_toshiba_en_src(data)                                             ((0x00000200&(data))>>9)
#define IR_CTRL_RC6_get_toshiba_en(data)                                             ((0x00000200&(data))>>9)
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


#define IR_RP2                                                                       0x1806143C
#define IR_RP2_reg_addr                                                              "0xB806143C"
#define IR_RP2_reg                                                                   0xB806143C
#define set_IR_RP2_reg(data)   (*((volatile unsigned int*) IR_RP2_reg)=data)
#define get_IR_RP2_reg   (*((volatile unsigned int*) IR_RP2_reg))
#define IR_RP2_inst_adr                                                              "0x000F"
#define IR_RP2_inst                                                                  0x000F
#define IR_RP2_IRRP_shift                                                            (0)
#define IR_RP2_IRRP_mask                                                             (0xFFFFFFFF)
#define IR_RP2_IRRP(data)                                                            (0xFFFFFFFF&((data)<<0))
#define IR_RP2_IRRP_src(data)                                                        ((0xFFFFFFFF&(data))>>0)
#define IR_RP2_get_IRRP(data)                                                        ((0xFFFFFFFF&(data))>>0)


#define IR_RAW_SF                                                                    0x18061440
#define IR_RAW_SF_reg_addr                                                           "0xB8061440"
#define IR_RAW_SF_reg                                                                0xB8061440
#define set_IR_RAW_SF_reg(data)   (*((volatile unsigned int*) IR_RAW_SF_reg)=data)
#define get_IR_RAW_SF_reg   (*((volatile unsigned int*) IR_RAW_SF_reg))
#define IR_RAW_SF_inst_adr                                                           "0x0010"
#define IR_RAW_SF_inst                                                               0x0010
#define IR_RAW_SF_IRRAWFD_shift                                                      (0)
#define IR_RAW_SF_IRRAWFD_mask                                                       (0x0000FFFF)
#define IR_RAW_SF_IRRAWFD(data)                                                      (0x0000FFFF&((data)<<0))
#define IR_RAW_SF_IRRAWFD_src(data)                                                  ((0x0000FFFF&(data))>>0)
#define IR_RAW_SF_get_IRRAWFD(data)                                                  ((0x0000FFFF&(data))>>0)


#define IR_EXT_RP_CF                                                                 0x18061444
#define IR_EXT_RP_CF_reg_addr                                                        "0xB8061444"
#define IR_EXT_RP_CF_reg                                                             0xB8061444
#define set_IR_EXT_RP_CF_reg(data)   (*((volatile unsigned int*) IR_EXT_RP_CF_reg)=data)
#define get_IR_EXT_RP_CF_reg   (*((volatile unsigned int*) IR_EXT_RP_CF_reg))
#define IR_EXT_RP_CF_inst_adr                                                        "0x0011"
#define IR_EXT_RP_CF_inst                                                            0x0011
#define IR_EXT_RP_CF_RP_NUM_shift                                                    (4)
#define IR_EXT_RP_CF_RP_NUM_mask                                                     (0x000000F0)
#define IR_EXT_RP_CF_RP_NUM(data)                                                    (0x000000F0&((data)<<4))
#define IR_EXT_RP_CF_RP_NUM_src(data)                                                ((0x000000F0&(data))>>4)
#define IR_EXT_RP_CF_get_RP_NUM(data)                                                ((0x000000F0&(data))>>4)
#define IR_EXT_RP_CF_EXT_RP_EN_shift                                                 (0)
#define IR_EXT_RP_CF_EXT_RP_EN_mask                                                  (0x00000001)
#define IR_EXT_RP_CF_EXT_RP_EN(data)                                                 (0x00000001&((data)<<0))
#define IR_EXT_RP_CF_EXT_RP_EN_src(data)                                             ((0x00000001&(data))>>0)
#define IR_EXT_RP_CF_get_EXT_RP_EN(data)                                             ((0x00000001&(data))>>0)


#define IR_EXT_RP_TIMING                                                             0x18061448
#define IR_EXT_RP_TIMING_reg_addr                                                    "0xB8061448"
#define IR_EXT_RP_TIMING_reg                                                         0xB8061448
#define set_IR_EXT_RP_TIMING_reg(data)   (*((volatile unsigned int*) IR_EXT_RP_TIMING_reg)=data)
#define get_IR_EXT_RP_TIMING_reg   (*((volatile unsigned int*) IR_EXT_RP_TIMING_reg))
#define IR_EXT_RP_TIMING_inst_adr                                                    "0x0012"
#define IR_EXT_RP_TIMING_inst                                                        0x0012
#define IR_EXT_RP_TIMING_RP_BURST_shift                                              (24)
#define IR_EXT_RP_TIMING_RP_BURST_mask                                               (0xFF000000)
#define IR_EXT_RP_TIMING_RP_BURST(data)                                              (0xFF000000&((data)<<24))
#define IR_EXT_RP_TIMING_RP_BURST_src(data)                                          ((0xFF000000&(data))>>24)
#define IR_EXT_RP_TIMING_get_RP_BURST(data)                                          ((0xFF000000&(data))>>24)
#define IR_EXT_RP_TIMING_RP_SILENCE_shift                                            (16)
#define IR_EXT_RP_TIMING_RP_SILENCE_mask                                             (0x00FF0000)
#define IR_EXT_RP_TIMING_RP_SILENCE(data)                                            (0x00FF0000&((data)<<16))
#define IR_EXT_RP_TIMING_RP_SILENCE_src(data)                                        ((0x00FF0000&(data))>>16)
#define IR_EXT_RP_TIMING_get_RP_SILENCE(data)                                        ((0x00FF0000&(data))>>16)
#define IR_EXT_RP_TIMING_RP_TAIL_BURST_shift                                         (8)
#define IR_EXT_RP_TIMING_RP_TAIL_BURST_mask                                          (0x0000FF00)
#define IR_EXT_RP_TIMING_RP_TAIL_BURST(data)                                         (0x0000FF00&((data)<<8))
#define IR_EXT_RP_TIMING_RP_TAIL_BURST_src(data)                                     ((0x0000FF00&(data))>>8)
#define IR_EXT_RP_TIMING_get_RP_TAIL_BURST(data)                                     ((0x0000FF00&(data))>>8)
#define IR_EXT_RP_TIMING_RP_TAIL_SILENCE_shift                                       (0)
#define IR_EXT_RP_TIMING_RP_TAIL_SILENCE_mask                                        (0x000000FF)
#define IR_EXT_RP_TIMING_RP_TAIL_SILENCE(data)                                       (0x000000FF&((data)<<0))
#define IR_EXT_RP_TIMING_RP_TAIL_SILENCE_src(data)                                   ((0x000000FF&(data))>>0)
#define IR_EXT_RP_TIMING_get_RP_TAIL_SILENCE(data)                                   ((0x000000FF&(data))>>0)


#define IR_EXT_RP_TIMING_UP                                                          0x1806144C
#define IR_EXT_RP_TIMING_UP_reg_addr                                                 "0xB806144C"
#define IR_EXT_RP_TIMING_UP_reg                                                      0xB806144C
#define set_IR_EXT_RP_TIMING_UP_reg(data)   (*((volatile unsigned int*) IR_EXT_RP_TIMING_UP_reg)=data)
#define get_IR_EXT_RP_TIMING_UP_reg   (*((volatile unsigned int*) IR_EXT_RP_TIMING_UP_reg))
#define IR_EXT_RP_TIMING_UP_inst_adr                                                 "0x0013"
#define IR_EXT_RP_TIMING_UP_inst                                                     0x0013
#define IR_EXT_RP_TIMING_UP_RP_BURST_shift                                           (24)
#define IR_EXT_RP_TIMING_UP_RP_BURST_mask                                            (0xFF000000)
#define IR_EXT_RP_TIMING_UP_RP_BURST(data)                                           (0xFF000000&((data)<<24))
#define IR_EXT_RP_TIMING_UP_RP_BURST_src(data)                                       ((0xFF000000&(data))>>24)
#define IR_EXT_RP_TIMING_UP_get_RP_BURST(data)                                       ((0xFF000000&(data))>>24)
#define IR_EXT_RP_TIMING_UP_RP_SILENCE_shift                                         (16)
#define IR_EXT_RP_TIMING_UP_RP_SILENCE_mask                                          (0x00FF0000)
#define IR_EXT_RP_TIMING_UP_RP_SILENCE(data)                                         (0x00FF0000&((data)<<16))
#define IR_EXT_RP_TIMING_UP_RP_SILENCE_src(data)                                     ((0x00FF0000&(data))>>16)
#define IR_EXT_RP_TIMING_UP_get_RP_SILENCE(data)                                     ((0x00FF0000&(data))>>16)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_BURST_shift                                      (8)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_BURST_mask                                       (0x0000FF00)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_BURST(data)                                      (0x0000FF00&((data)<<8))
#define IR_EXT_RP_TIMING_UP_RP_TAIL_BURST_src(data)                                  ((0x0000FF00&(data))>>8)
#define IR_EXT_RP_TIMING_UP_get_RP_TAIL_BURST(data)                                  ((0x0000FF00&(data))>>8)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_SILENCE_shift                                    (0)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_SILENCE_mask                                     (0x000000FF)
#define IR_EXT_RP_TIMING_UP_RP_TAIL_SILENCE(data)                                    (0x000000FF&((data)<<0))
#define IR_EXT_RP_TIMING_UP_RP_TAIL_SILENCE_src(data)                                ((0x000000FF&(data))>>0)
#define IR_EXT_RP_TIMING_UP_get_RP_TAIL_SILENCE(data)                                ((0x000000FF&(data))>>0)


#define IR_RAW_MODE_DBUS_ADDR                                                        0x18061450
#define IR_RAW_MODE_DBUS_ADDR_reg_addr                                               "0xB8061450"
#define IR_RAW_MODE_DBUS_ADDR_reg                                                    0xB8061450
#define set_IR_RAW_MODE_DBUS_ADDR_reg(data)   (*((volatile unsigned int*) IR_RAW_MODE_DBUS_ADDR_reg)=data)
#define get_IR_RAW_MODE_DBUS_ADDR_reg   (*((volatile unsigned int*) IR_RAW_MODE_DBUS_ADDR_reg))
#define IR_RAW_MODE_DBUS_ADDR_inst_adr                                               "0x0014"
#define IR_RAW_MODE_DBUS_ADDR_inst                                                   0x0014
#define IR_RAW_MODE_DBUS_ADDR_D_ADDR_shift                                           (0)
#define IR_RAW_MODE_DBUS_ADDR_D_ADDR_mask                                            (0xFFFFFFFF)
#define IR_RAW_MODE_DBUS_ADDR_D_ADDR(data)                                           (0xFFFFFFFF&((data)<<0))
#define IR_RAW_MODE_DBUS_ADDR_D_ADDR_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define IR_RAW_MODE_DBUS_ADDR_get_D_ADDR(data)                                       ((0xFFFFFFFF&(data))>>0)


#define IR_PSR_RC5_RC6                                                               0x18061454
#define IR_PSR_RC5_RC6_reg_addr                                                      "0xB8061454"
#define IR_PSR_RC5_RC6_reg                                                           0xB8061454
#define set_IR_PSR_RC5_RC6_reg(data)   (*((volatile unsigned int*) IR_PSR_RC5_RC6_reg)=data)
#define get_IR_PSR_RC5_RC6_reg   (*((volatile unsigned int*) IR_PSR_RC5_RC6_reg))
#define IR_PSR_RC5_RC6_inst_adr                                                      "0x0015"
#define IR_PSR_RC5_RC6_inst                                                          0x0015
#define IR_PSR_RC5_RC6_IRRBL__shift                                                  (24)
#define IR_PSR_RC5_RC6_IRRBL__mask                                                   (0xFF000000)
#define IR_PSR_RC5_RC6_IRRBL_(data)                                                  (0xFF000000&((data)<<24))
#define IR_PSR_RC5_RC6_IRRBL__src(data)                                              ((0xFF000000&(data))>>24)
#define IR_PSR_RC5_RC6_get_IRRBL_(data)                                              ((0xFF000000&(data))>>24)
#define IR_PSR_RC5_RC6_IRRML_shift                                                   (16)
#define IR_PSR_RC5_RC6_IRRML_mask                                                    (0x00FF0000)
#define IR_PSR_RC5_RC6_IRRML(data)                                                   (0x00FF0000&((data)<<16))
#define IR_PSR_RC5_RC6_IRRML_src(data)                                               ((0x00FF0000&(data))>>16)
#define IR_PSR_RC5_RC6_get_IRRML(data)                                               ((0x00FF0000&(data))>>16)
#define IR_PSR_RC5_RC6_IRRDZL_shift                                                  (8)
#define IR_PSR_RC5_RC6_IRRDZL_mask                                                   (0x0000FF00)
#define IR_PSR_RC5_RC6_IRRDZL(data)                                                  (0x0000FF00&((data)<<8))
#define IR_PSR_RC5_RC6_IRRDZL_src(data)                                              ((0x0000FF00&(data))>>8)
#define IR_PSR_RC5_RC6_get_IRRDZL(data)                                              ((0x0000FF00&(data))>>8)
#define IR_PSR_RC5_RC6_IRRDOL_shift                                                  (0)
#define IR_PSR_RC5_RC6_IRRDOL_mask                                                   (0x000000FF)
#define IR_PSR_RC5_RC6_IRRDOL(data)                                                  (0x000000FF&((data)<<0))
#define IR_PSR_RC5_RC6_IRRDOL_src(data)                                              ((0x000000FF&(data))>>0)
#define IR_PSR_RC5_RC6_get_IRRDOL(data)                                              ((0x000000FF&(data))>>0)


#define IR_PER_RC5_RC6                                                               0x18061458
#define IR_PER_RC5_RC6_reg_addr                                                      "0xB8061458"
#define IR_PER_RC5_RC6_reg                                                           0xB8061458
#define set_IR_PER_RC5_RC6_reg(data)   (*((volatile unsigned int*) IR_PER_RC5_RC6_reg)=data)
#define get_IR_PER_RC5_RC6_reg   (*((volatile unsigned int*) IR_PER_RC5_RC6_reg))
#define IR_PER_RC5_RC6_inst_adr                                                      "0x0016"
#define IR_PER_RC5_RC6_inst                                                          0x0016
#define IR_PER_RC5_RC6_IRRDL_shift                                                   (16)
#define IR_PER_RC5_RC6_IRRDL_mask                                                    (0x003F0000)
#define IR_PER_RC5_RC6_IRRDL(data)                                                   (0x003F0000&((data)<<16))
#define IR_PER_RC5_RC6_IRRDL_src(data)                                               ((0x003F0000&(data))>>16)
#define IR_PER_RC5_RC6_get_IRRDL(data)                                               ((0x003F0000&(data))>>16)
#define IR_PER_RC5_RC6_IRRRL_shift                                                   (8)
#define IR_PER_RC5_RC6_IRRRL_mask                                                    (0x0000FF00)
#define IR_PER_RC5_RC6_IRRRL(data)                                                   (0x0000FF00&((data)<<8))
#define IR_PER_RC5_RC6_IRRRL_src(data)                                               ((0x0000FF00&(data))>>8)
#define IR_PER_RC5_RC6_get_IRRRL(data)                                               ((0x0000FF00&(data))>>8)
#define IR_PER_RC5_RC6_IRRSL_shift                                                   (0)
#define IR_PER_RC5_RC6_IRRSL_mask                                                    (0x000000FF)
#define IR_PER_RC5_RC6_IRRSL(data)                                                   (0x000000FF&((data)<<0))
#define IR_PER_RC5_RC6_IRRSL_src(data)                                               ((0x000000FF&(data))>>0)
#define IR_PER_RC5_RC6_get_IRRSL(data)                                               ((0x000000FF&(data))>>0)


#define HW_DECODE_DATA0_L                                                            0x18061460
#define HW_DECODE_DATA0_L_reg_addr                                                   "0xB8061460"
#define HW_DECODE_DATA0_L_reg                                                        0xB8061460
#define set_HW_DECODE_DATA0_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA0_L_reg)=data)
#define get_HW_DECODE_DATA0_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA0_L_reg))
#define HW_DECODE_DATA0_L_inst_adr                                                   "0x0018"
#define HW_DECODE_DATA0_L_inst                                                       0x0018
#define HW_DECODE_DATA0_L_HW_decode_data0L_shift                                     (0)
#define HW_DECODE_DATA0_L_HW_decode_data0L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA0_L_HW_decode_data0L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA0_L_HW_decode_data0L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA0_L_get_HW_decode_data0L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA0_H                                                            0x18061464
#define HW_DECODE_DATA0_H_reg_addr                                                   "0xB8061464"
#define HW_DECODE_DATA0_H_reg                                                        0xB8061464
#define set_HW_DECODE_DATA0_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA0_H_reg)=data)
#define get_HW_DECODE_DATA0_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA0_H_reg))
#define HW_DECODE_DATA0_H_inst_adr                                                   "0x0019"
#define HW_DECODE_DATA0_H_inst                                                       0x0019
#define HW_DECODE_DATA0_H_HW_decode_data0H_shift                                     (0)
#define HW_DECODE_DATA0_H_HW_decode_data0H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA0_H_HW_decode_data0H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA0_H_HW_decode_data0H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA0_H_get_HW_decode_data0H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA0_L                                                          0x18061468
#define DECODE_MASK_DATA0_L_reg_addr                                                 "0xB8061468"
#define DECODE_MASK_DATA0_L_reg                                                      0xB8061468
#define set_DECODE_MASK_DATA0_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA0_L_reg)=data)
#define get_DECODE_MASK_DATA0_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA0_L_reg))
#define DECODE_MASK_DATA0_L_inst_adr                                                 "0x001A"
#define DECODE_MASK_DATA0_L_inst                                                     0x001A
#define DECODE_MASK_DATA0_L_Decode_Mask_data0L_shift                                 (0)
#define DECODE_MASK_DATA0_L_Decode_Mask_data0L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA0_L_Decode_Mask_data0L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA0_L_Decode_Mask_data0L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA0_L_get_Decode_Mask_data0L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA0_H                                                          0x1806146C
#define DECODE_MASK_DATA0_H_reg_addr                                                 "0xB806146C"
#define DECODE_MASK_DATA0_H_reg                                                      0xB806146C
#define set_DECODE_MASK_DATA0_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA0_H_reg)=data)
#define get_DECODE_MASK_DATA0_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA0_H_reg))
#define DECODE_MASK_DATA0_H_inst_adr                                                 "0x001B"
#define DECODE_MASK_DATA0_H_inst                                                     0x001B
#define DECODE_MASK_DATA0_H_Decode_Mask_data0H_shift                                 (0)
#define DECODE_MASK_DATA0_H_Decode_Mask_data0H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA0_H_Decode_Mask_data0H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA0_H_Decode_Mask_data0H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA0_H_get_Decode_Mask_data0H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA1_L                                                            0x18061470
#define HW_DECODE_DATA1_L_reg_addr                                                   "0xB8061470"
#define HW_DECODE_DATA1_L_reg                                                        0xB8061470
#define set_HW_DECODE_DATA1_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA1_L_reg)=data)
#define get_HW_DECODE_DATA1_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA1_L_reg))
#define HW_DECODE_DATA1_L_inst_adr                                                   "0x001C"
#define HW_DECODE_DATA1_L_inst                                                       0x001C
#define HW_DECODE_DATA1_L_HW_decode_data1L_shift                                     (0)
#define HW_DECODE_DATA1_L_HW_decode_data1L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA1_L_HW_decode_data1L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA1_L_HW_decode_data1L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA1_L_get_HW_decode_data1L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA1_H                                                            0x18061474
#define HW_DECODE_DATA1_H_reg_addr                                                   "0xB8061474"
#define HW_DECODE_DATA1_H_reg                                                        0xB8061474
#define set_HW_DECODE_DATA1_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA1_H_reg)=data)
#define get_HW_DECODE_DATA1_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA1_H_reg))
#define HW_DECODE_DATA1_H_inst_adr                                                   "0x001D"
#define HW_DECODE_DATA1_H_inst                                                       0x001D
#define HW_DECODE_DATA1_H_HW_decode_data1H_shift                                     (0)
#define HW_DECODE_DATA1_H_HW_decode_data1H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA1_H_HW_decode_data1H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA1_H_HW_decode_data1H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA1_H_get_HW_decode_data1H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA1_L                                                          0x18061478
#define DECODE_MASK_DATA1_L_reg_addr                                                 "0xB8061478"
#define DECODE_MASK_DATA1_L_reg                                                      0xB8061478
#define set_DECODE_MASK_DATA1_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA1_L_reg)=data)
#define get_DECODE_MASK_DATA1_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA1_L_reg))
#define DECODE_MASK_DATA1_L_inst_adr                                                 "0x001E"
#define DECODE_MASK_DATA1_L_inst                                                     0x001E
#define DECODE_MASK_DATA1_L_Decode_Mask_data1L_shift                                 (0)
#define DECODE_MASK_DATA1_L_Decode_Mask_data1L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA1_L_Decode_Mask_data1L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA1_L_Decode_Mask_data1L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA1_L_get_Decode_Mask_data1L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA1_H                                                          0x1806147C
#define DECODE_MASK_DATA1_H_reg_addr                                                 "0xB806147C"
#define DECODE_MASK_DATA1_H_reg                                                      0xB806147C
#define set_DECODE_MASK_DATA1_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA1_H_reg)=data)
#define get_DECODE_MASK_DATA1_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA1_H_reg))
#define DECODE_MASK_DATA1_H_inst_adr                                                 "0x001F"
#define DECODE_MASK_DATA1_H_inst                                                     0x001F
#define DECODE_MASK_DATA1_H_Decode_Mask_data1H_shift                                 (0)
#define DECODE_MASK_DATA1_H_Decode_Mask_data1H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA1_H_Decode_Mask_data1H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA1_H_Decode_Mask_data1H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA1_H_get_Decode_Mask_data1H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA2_L                                                            0x18061480
#define HW_DECODE_DATA2_L_reg_addr                                                   "0xB8061480"
#define HW_DECODE_DATA2_L_reg                                                        0xB8061480
#define set_HW_DECODE_DATA2_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA2_L_reg)=data)
#define get_HW_DECODE_DATA2_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA2_L_reg))
#define HW_DECODE_DATA2_L_inst_adr                                                   "0x0020"
#define HW_DECODE_DATA2_L_inst                                                       0x0020
#define HW_DECODE_DATA2_L_HW_decode_data2L_shift                                     (0)
#define HW_DECODE_DATA2_L_HW_decode_data2L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA2_L_HW_decode_data2L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA2_L_HW_decode_data2L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA2_L_get_HW_decode_data2L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA2_H                                                            0x18061484
#define HW_DECODE_DATA2_H_reg_addr                                                   "0xB8061484"
#define HW_DECODE_DATA2_H_reg                                                        0xB8061484
#define set_HW_DECODE_DATA2_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA2_H_reg)=data)
#define get_HW_DECODE_DATA2_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA2_H_reg))
#define HW_DECODE_DATA2_H_inst_adr                                                   "0x0021"
#define HW_DECODE_DATA2_H_inst                                                       0x0021
#define HW_DECODE_DATA2_H_HW_decode_data2H_shift                                     (0)
#define HW_DECODE_DATA2_H_HW_decode_data2H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA2_H_HW_decode_data2H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA2_H_HW_decode_data2H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA2_H_get_HW_decode_data2H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA2_L                                                          0x18061488
#define DECODE_MASK_DATA2_L_reg_addr                                                 "0xB8061488"
#define DECODE_MASK_DATA2_L_reg                                                      0xB8061488
#define set_DECODE_MASK_DATA2_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA2_L_reg)=data)
#define get_DECODE_MASK_DATA2_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA2_L_reg))
#define DECODE_MASK_DATA2_L_inst_adr                                                 "0x0022"
#define DECODE_MASK_DATA2_L_inst                                                     0x0022
#define DECODE_MASK_DATA2_L_Decode_Mask_data2L_shift                                 (0)
#define DECODE_MASK_DATA2_L_Decode_Mask_data2L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA2_L_Decode_Mask_data2L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA2_L_Decode_Mask_data2L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA2_L_get_Decode_Mask_data2L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA2_H                                                          0x1806148C
#define DECODE_MASK_DATA2_H_reg_addr                                                 "0xB806148C"
#define DECODE_MASK_DATA2_H_reg                                                      0xB806148C
#define set_DECODE_MASK_DATA2_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA2_H_reg)=data)
#define get_DECODE_MASK_DATA2_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA2_H_reg))
#define DECODE_MASK_DATA2_H_inst_adr                                                 "0x0023"
#define DECODE_MASK_DATA2_H_inst                                                     0x0023
#define DECODE_MASK_DATA2_H_Decode_Mask_data2H_shift                                 (0)
#define DECODE_MASK_DATA2_H_Decode_Mask_data2H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA2_H_Decode_Mask_data2H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA2_H_Decode_Mask_data2H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA2_H_get_Decode_Mask_data2H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA3_L                                                            0x18061490
#define HW_DECODE_DATA3_L_reg_addr                                                   "0xB8061490"
#define HW_DECODE_DATA3_L_reg                                                        0xB8061490
#define set_HW_DECODE_DATA3_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA3_L_reg)=data)
#define get_HW_DECODE_DATA3_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA3_L_reg))
#define HW_DECODE_DATA3_L_inst_adr                                                   "0x0024"
#define HW_DECODE_DATA3_L_inst                                                       0x0024
#define HW_DECODE_DATA3_L_HW_decode_data3L_shift                                     (0)
#define HW_DECODE_DATA3_L_HW_decode_data3L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA3_L_HW_decode_data3L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA3_L_HW_decode_data3L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA3_L_get_HW_decode_data3L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA3_H                                                            0x18061494
#define HW_DECODE_DATA3_H_reg_addr                                                   "0xB8061494"
#define HW_DECODE_DATA3_H_reg                                                        0xB8061494
#define set_HW_DECODE_DATA3_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA3_H_reg)=data)
#define get_HW_DECODE_DATA3_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA3_H_reg))
#define HW_DECODE_DATA3_H_inst_adr                                                   "0x0025"
#define HW_DECODE_DATA3_H_inst                                                       0x0025
#define HW_DECODE_DATA3_H_HW_decode_data3H_shift                                     (0)
#define HW_DECODE_DATA3_H_HW_decode_data3H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA3_H_HW_decode_data3H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA3_H_HW_decode_data3H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA3_H_get_HW_decode_data3H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA3_L                                                          0x18061498
#define DECODE_MASK_DATA3_L_reg_addr                                                 "0xB8061498"
#define DECODE_MASK_DATA3_L_reg                                                      0xB8061498
#define set_DECODE_MASK_DATA3_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA3_L_reg)=data)
#define get_DECODE_MASK_DATA3_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA3_L_reg))
#define DECODE_MASK_DATA3_L_inst_adr                                                 "0x0026"
#define DECODE_MASK_DATA3_L_inst                                                     0x0026
#define DECODE_MASK_DATA3_L_Decode_Mask_data3L_shift                                 (0)
#define DECODE_MASK_DATA3_L_Decode_Mask_data3L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA3_L_Decode_Mask_data3L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA3_L_Decode_Mask_data3L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA3_L_get_Decode_Mask_data3L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA3_H                                                          0x1806149C
#define DECODE_MASK_DATA3_H_reg_addr                                                 "0xB806149C"
#define DECODE_MASK_DATA3_H_reg                                                      0xB806149C
#define set_DECODE_MASK_DATA3_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA3_H_reg)=data)
#define get_DECODE_MASK_DATA3_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA3_H_reg))
#define DECODE_MASK_DATA3_H_inst_adr                                                 "0x0027"
#define DECODE_MASK_DATA3_H_inst                                                     0x0027
#define DECODE_MASK_DATA3_H_Decode_Mask_data3H_shift                                 (0)
#define DECODE_MASK_DATA3_H_Decode_Mask_data3H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA3_H_Decode_Mask_data3H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA3_H_Decode_Mask_data3H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA3_H_get_Decode_Mask_data3H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA4_L                                                            0x180614A0
#define HW_DECODE_DATA4_L_reg_addr                                                   "0xB80614A0"
#define HW_DECODE_DATA4_L_reg                                                        0xB80614A0
#define set_HW_DECODE_DATA4_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA4_L_reg)=data)
#define get_HW_DECODE_DATA4_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA4_L_reg))
#define HW_DECODE_DATA4_L_inst_adr                                                   "0x0028"
#define HW_DECODE_DATA4_L_inst                                                       0x0028
#define HW_DECODE_DATA4_L_HW_decode_data4L_shift                                     (0)
#define HW_DECODE_DATA4_L_HW_decode_data4L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA4_L_HW_decode_data4L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA4_L_HW_decode_data4L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA4_L_get_HW_decode_data4L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA4_H                                                            0x180614A4
#define HW_DECODE_DATA4_H_reg_addr                                                   "0xB80614A4"
#define HW_DECODE_DATA4_H_reg                                                        0xB80614A4
#define set_HW_DECODE_DATA4_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA4_H_reg)=data)
#define get_HW_DECODE_DATA4_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA4_H_reg))
#define HW_DECODE_DATA4_H_inst_adr                                                   "0x0029"
#define HW_DECODE_DATA4_H_inst                                                       0x0029
#define HW_DECODE_DATA4_H_HW_decode_data4H_shift                                     (0)
#define HW_DECODE_DATA4_H_HW_decode_data4H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA4_H_HW_decode_data4H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA4_H_HW_decode_data4H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA4_H_get_HW_decode_data4H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA4_L                                                          0x180614A8
#define DECODE_MASK_DATA4_L_reg_addr                                                 "0xB80614A8"
#define DECODE_MASK_DATA4_L_reg                                                      0xB80614A8
#define set_DECODE_MASK_DATA4_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA4_L_reg)=data)
#define get_DECODE_MASK_DATA4_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA4_L_reg))
#define DECODE_MASK_DATA4_L_inst_adr                                                 "0x002A"
#define DECODE_MASK_DATA4_L_inst                                                     0x002A
#define DECODE_MASK_DATA4_L_Decode_Mask_data4L_shift                                 (0)
#define DECODE_MASK_DATA4_L_Decode_Mask_data4L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA4_L_Decode_Mask_data4L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA4_L_Decode_Mask_data4L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA4_L_get_Decode_Mask_data4L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA4_H                                                          0x180614AC
#define DECODE_MASK_DATA4_H_reg_addr                                                 "0xB80614AC"
#define DECODE_MASK_DATA4_H_reg                                                      0xB80614AC
#define set_DECODE_MASK_DATA4_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA4_H_reg)=data)
#define get_DECODE_MASK_DATA4_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA4_H_reg))
#define DECODE_MASK_DATA4_H_inst_adr                                                 "0x002B"
#define DECODE_MASK_DATA4_H_inst                                                     0x002B
#define DECODE_MASK_DATA4_H_Decode_Mask_data4H_shift                                 (0)
#define DECODE_MASK_DATA4_H_Decode_Mask_data4H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA4_H_Decode_Mask_data4H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA4_H_Decode_Mask_data4H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA4_H_get_Decode_Mask_data4H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA5_L                                                            0x180614B0
#define HW_DECODE_DATA5_L_reg_addr                                                   "0xB80614B0"
#define HW_DECODE_DATA5_L_reg                                                        0xB80614B0
#define set_HW_DECODE_DATA5_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA5_L_reg)=data)
#define get_HW_DECODE_DATA5_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA5_L_reg))
#define HW_DECODE_DATA5_L_inst_adr                                                   "0x002C"
#define HW_DECODE_DATA5_L_inst                                                       0x002C
#define HW_DECODE_DATA5_L_HW_decode_data5L_shift                                     (0)
#define HW_DECODE_DATA5_L_HW_decode_data5L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA5_L_HW_decode_data5L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA5_L_HW_decode_data5L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA5_L_get_HW_decode_data5L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA5_H                                                            0x180614B4
#define HW_DECODE_DATA5_H_reg_addr                                                   "0xB80614B4"
#define HW_DECODE_DATA5_H_reg                                                        0xB80614B4
#define set_HW_DECODE_DATA5_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA5_H_reg)=data)
#define get_HW_DECODE_DATA5_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA5_H_reg))
#define HW_DECODE_DATA5_H_inst_adr                                                   "0x002D"
#define HW_DECODE_DATA5_H_inst                                                       0x002D
#define HW_DECODE_DATA5_H_HW_decode_data5H_shift                                     (0)
#define HW_DECODE_DATA5_H_HW_decode_data5H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA5_H_HW_decode_data5H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA5_H_HW_decode_data5H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA5_H_get_HW_decode_data5H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA5_L                                                          0x180614B8
#define DECODE_MASK_DATA5_L_reg_addr                                                 "0xB80614B8"
#define DECODE_MASK_DATA5_L_reg                                                      0xB80614B8
#define set_DECODE_MASK_DATA5_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA5_L_reg)=data)
#define get_DECODE_MASK_DATA5_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA5_L_reg))
#define DECODE_MASK_DATA5_L_inst_adr                                                 "0x002E"
#define DECODE_MASK_DATA5_L_inst                                                     0x002E
#define DECODE_MASK_DATA5_L_Decode_Mask_data5L_shift                                 (0)
#define DECODE_MASK_DATA5_L_Decode_Mask_data5L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA5_L_Decode_Mask_data5L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA5_L_Decode_Mask_data5L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA5_L_get_Decode_Mask_data5L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA5_H                                                          0x180614BC
#define DECODE_MASK_DATA5_H_reg_addr                                                 "0xB80614BC"
#define DECODE_MASK_DATA5_H_reg                                                      0xB80614BC
#define set_DECODE_MASK_DATA5_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA5_H_reg)=data)
#define get_DECODE_MASK_DATA5_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA5_H_reg))
#define DECODE_MASK_DATA5_H_inst_adr                                                 "0x002F"
#define DECODE_MASK_DATA5_H_inst                                                     0x002F
#define DECODE_MASK_DATA5_H_Decode_Mask_data5H_shift                                 (0)
#define DECODE_MASK_DATA5_H_Decode_Mask_data5H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA5_H_Decode_Mask_data5H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA5_H_Decode_Mask_data5H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA5_H_get_Decode_Mask_data5H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA6_L                                                            0x180614C0
#define HW_DECODE_DATA6_L_reg_addr                                                   "0xB80614C0"
#define HW_DECODE_DATA6_L_reg                                                        0xB80614C0
#define set_HW_DECODE_DATA6_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA6_L_reg)=data)
#define get_HW_DECODE_DATA6_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA6_L_reg))
#define HW_DECODE_DATA6_L_inst_adr                                                   "0x0030"
#define HW_DECODE_DATA6_L_inst                                                       0x0030
#define HW_DECODE_DATA6_L_HW_decode_data6L_shift                                     (0)
#define HW_DECODE_DATA6_L_HW_decode_data6L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA6_L_HW_decode_data6L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA6_L_HW_decode_data6L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA6_L_get_HW_decode_data6L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA6_H                                                            0x180614C4
#define HW_DECODE_DATA6_H_reg_addr                                                   "0xB80614C4"
#define HW_DECODE_DATA6_H_reg                                                        0xB80614C4
#define set_HW_DECODE_DATA6_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA6_H_reg)=data)
#define get_HW_DECODE_DATA6_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA6_H_reg))
#define HW_DECODE_DATA6_H_inst_adr                                                   "0x0031"
#define HW_DECODE_DATA6_H_inst                                                       0x0031
#define HW_DECODE_DATA6_H_HW_decode_data62H_shift                                    (0)
#define HW_DECODE_DATA6_H_HW_decode_data62H_mask                                     (0xFFFFFFFF)
#define HW_DECODE_DATA6_H_HW_decode_data62H(data)                                    (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA6_H_HW_decode_data62H_src(data)                                ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA6_H_get_HW_decode_data62H(data)                                ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA6_L                                                          0x180614C8
#define DECODE_MASK_DATA6_L_reg_addr                                                 "0xB80614C8"
#define DECODE_MASK_DATA6_L_reg                                                      0xB80614C8
#define set_DECODE_MASK_DATA6_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA6_L_reg)=data)
#define get_DECODE_MASK_DATA6_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA6_L_reg))
#define DECODE_MASK_DATA6_L_inst_adr                                                 "0x0032"
#define DECODE_MASK_DATA6_L_inst                                                     0x0032
#define DECODE_MASK_DATA6_L_Decode_Mask_data6L_shift                                 (0)
#define DECODE_MASK_DATA6_L_Decode_Mask_data6L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA6_L_Decode_Mask_data6L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA6_L_Decode_Mask_data6L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA6_L_get_Decode_Mask_data6L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA6_H                                                          0x180614CC
#define DECODE_MASK_DATA6_H_reg_addr                                                 "0xB80614CC"
#define DECODE_MASK_DATA6_H_reg                                                      0xB80614CC
#define set_DECODE_MASK_DATA6_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA6_H_reg)=data)
#define get_DECODE_MASK_DATA6_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA6_H_reg))
#define DECODE_MASK_DATA6_H_inst_adr                                                 "0x0033"
#define DECODE_MASK_DATA6_H_inst                                                     0x0033
#define DECODE_MASK_DATA6_H_Decode_Mask_data6H_shift                                 (0)
#define DECODE_MASK_DATA6_H_Decode_Mask_data6H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA6_H_Decode_Mask_data6H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA6_H_Decode_Mask_data6H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA6_H_get_Decode_Mask_data6H(data)                             ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA7_L                                                            0x180614D0
#define HW_DECODE_DATA7_L_reg_addr                                                   "0xB80614D0"
#define HW_DECODE_DATA7_L_reg                                                        0xB80614D0
#define set_HW_DECODE_DATA7_L_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA7_L_reg)=data)
#define get_HW_DECODE_DATA7_L_reg   (*((volatile unsigned int*) HW_DECODE_DATA7_L_reg))
#define HW_DECODE_DATA7_L_inst_adr                                                   "0x0034"
#define HW_DECODE_DATA7_L_inst                                                       0x0034
#define HW_DECODE_DATA7_L_HW_decode_data7L_shift                                     (0)
#define HW_DECODE_DATA7_L_HW_decode_data7L_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA7_L_HW_decode_data7L(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA7_L_HW_decode_data7L_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA7_L_get_HW_decode_data7L(data)                                 ((0xFFFFFFFF&(data))>>0)


#define HW_DECODE_DATA7_H                                                            0x180614D4
#define HW_DECODE_DATA7_H_reg_addr                                                   "0xB80614D4"
#define HW_DECODE_DATA7_H_reg                                                        0xB80614D4
#define set_HW_DECODE_DATA7_H_reg(data)   (*((volatile unsigned int*) HW_DECODE_DATA7_H_reg)=data)
#define get_HW_DECODE_DATA7_H_reg   (*((volatile unsigned int*) HW_DECODE_DATA7_H_reg))
#define HW_DECODE_DATA7_H_inst_adr                                                   "0x0035"
#define HW_DECODE_DATA7_H_inst                                                       0x0035
#define HW_DECODE_DATA7_H_HW_decode_data7H_shift                                     (0)
#define HW_DECODE_DATA7_H_HW_decode_data7H_mask                                      (0xFFFFFFFF)
#define HW_DECODE_DATA7_H_HW_decode_data7H(data)                                     (0xFFFFFFFF&((data)<<0))
#define HW_DECODE_DATA7_H_HW_decode_data7H_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define HW_DECODE_DATA7_H_get_HW_decode_data7H(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA7_L                                                          0x180614D8
#define DECODE_MASK_DATA7_L_reg_addr                                                 "0xB80614D8"
#define DECODE_MASK_DATA7_L_reg                                                      0xB80614D8
#define set_DECODE_MASK_DATA7_L_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA7_L_reg)=data)
#define get_DECODE_MASK_DATA7_L_reg   (*((volatile unsigned int*) DECODE_MASK_DATA7_L_reg))
#define DECODE_MASK_DATA7_L_inst_adr                                                 "0x0036"
#define DECODE_MASK_DATA7_L_inst                                                     0x0036
#define DECODE_MASK_DATA7_L_Decode_Mask_data7L_shift                                 (0)
#define DECODE_MASK_DATA7_L_Decode_Mask_data7L_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA7_L_Decode_Mask_data7L(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA7_L_Decode_Mask_data7L_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA7_L_get_Decode_Mask_data7L(data)                             ((0xFFFFFFFF&(data))>>0)


#define DECODE_MASK_DATA7_H                                                          0x180614DC
#define DECODE_MASK_DATA7_H_reg_addr                                                 "0xB80614DC"
#define DECODE_MASK_DATA7_H_reg                                                      0xB80614DC
#define set_DECODE_MASK_DATA7_H_reg(data)   (*((volatile unsigned int*) DECODE_MASK_DATA7_H_reg)=data)
#define get_DECODE_MASK_DATA7_H_reg   (*((volatile unsigned int*) DECODE_MASK_DATA7_H_reg))
#define DECODE_MASK_DATA7_H_inst_adr                                                 "0x0037"
#define DECODE_MASK_DATA7_H_inst                                                     0x0037
#define DECODE_MASK_DATA7_H_Decode_Mask_data7H_shift                                 (0)
#define DECODE_MASK_DATA7_H_Decode_Mask_data7H_mask                                  (0xFFFFFFFF)
#define DECODE_MASK_DATA7_H_Decode_Mask_data7H(data)                                 (0xFFFFFFFF&((data)<<0))
#define DECODE_MASK_DATA7_H_Decode_Mask_data7H_src(data)                             ((0xFFFFFFFF&(data))>>0)
#define DECODE_MASK_DATA7_H_get_Decode_Mask_data7H(data)                             ((0xFFFFFFFF&(data))>>0)


#define INT_CTRL                                                                     0x180614E0
#define INT_CTRL_reg_addr                                                            "0xB80614E0"
#define INT_CTRL_reg                                                                 0xB80614E0
#define set_INT_CTRL_reg(data)   (*((volatile unsigned int*) INT_CTRL_reg)=data)
#define get_INT_CTRL_reg   (*((volatile unsigned int*) INT_CTRL_reg))
#define INT_CTRL_inst_adr                                                            "0x0038"
#define INT_CTRL_inst                                                                0x0038
#define INT_CTRL_Compare7_enable_shift                                               (31)
#define INT_CTRL_Compare7_enable_mask                                                (0x80000000)
#define INT_CTRL_Compare7_enable(data)                                               (0x80000000&((data)<<31))
#define INT_CTRL_Compare7_enable_src(data)                                           ((0x80000000&(data))>>31)
#define INT_CTRL_get_Compare7_enable(data)                                           ((0x80000000&(data))>>31)
#define INT_CTRL_Compare6_enable_shift                                               (30)
#define INT_CTRL_Compare6_enable_mask                                                (0x40000000)
#define INT_CTRL_Compare6_enable(data)                                               (0x40000000&((data)<<30))
#define INT_CTRL_Compare6_enable_src(data)                                           ((0x40000000&(data))>>30)
#define INT_CTRL_get_Compare6_enable(data)                                           ((0x40000000&(data))>>30)
#define INT_CTRL_Compare5_enable_shift                                               (29)
#define INT_CTRL_Compare5_enable_mask                                                (0x20000000)
#define INT_CTRL_Compare5_enable(data)                                               (0x20000000&((data)<<29))
#define INT_CTRL_Compare5_enable_src(data)                                           ((0x20000000&(data))>>29)
#define INT_CTRL_get_Compare5_enable(data)                                           ((0x20000000&(data))>>29)
#define INT_CTRL_Compare4_enable_shift                                               (28)
#define INT_CTRL_Compare4_enable_mask                                                (0x10000000)
#define INT_CTRL_Compare4_enable(data)                                               (0x10000000&((data)<<28))
#define INT_CTRL_Compare4_enable_src(data)                                           ((0x10000000&(data))>>28)
#define INT_CTRL_get_Compare4_enable(data)                                           ((0x10000000&(data))>>28)
#define INT_CTRL_Compare3_enable_shift                                               (27)
#define INT_CTRL_Compare3_enable_mask                                                (0x08000000)
#define INT_CTRL_Compare3_enable(data)                                               (0x08000000&((data)<<27))
#define INT_CTRL_Compare3_enable_src(data)                                           ((0x08000000&(data))>>27)
#define INT_CTRL_get_Compare3_enable(data)                                           ((0x08000000&(data))>>27)
#define INT_CTRL_Compare2_enable_shift                                               (26)
#define INT_CTRL_Compare2_enable_mask                                                (0x04000000)
#define INT_CTRL_Compare2_enable(data)                                               (0x04000000&((data)<<26))
#define INT_CTRL_Compare2_enable_src(data)                                           ((0x04000000&(data))>>26)
#define INT_CTRL_get_Compare2_enable(data)                                           ((0x04000000&(data))>>26)
#define INT_CTRL_Compare1_enable_shift                                               (25)
#define INT_CTRL_Compare1_enable_mask                                                (0x02000000)
#define INT_CTRL_Compare1_enable(data)                                               (0x02000000&((data)<<25))
#define INT_CTRL_Compare1_enable_src(data)                                           ((0x02000000&(data))>>25)
#define INT_CTRL_get_Compare1_enable(data)                                           ((0x02000000&(data))>>25)
#define INT_CTRL_Compare0_enable_shift                                               (24)
#define INT_CTRL_Compare0_enable_mask                                                (0x01000000)
#define INT_CTRL_Compare0_enable(data)                                               (0x01000000&((data)<<24))
#define INT_CTRL_Compare0_enable_src(data)                                           ((0x01000000&(data))>>24)
#define INT_CTRL_get_Compare0_enable(data)                                           ((0x01000000&(data))>>24)
#define INT_CTRL_INT_latchdata_shift                                                 (16)
#define INT_CTRL_INT_latchdata_mask                                                  (0x00FF0000)
#define INT_CTRL_INT_latchdata(data)                                                 (0x00FF0000&((data)<<16))
#define INT_CTRL_INT_latchdata_src(data)                                             ((0x00FF0000&(data))>>16)
#define INT_CTRL_get_INT_latchdata(data)                                             ((0x00FF0000&(data))>>16)
#define INT_CTRL_Compare7_INT_en_shift                                               (15)
#define INT_CTRL_Compare7_INT_en_mask                                                (0x00008000)
#define INT_CTRL_Compare7_INT_en(data)                                               (0x00008000&((data)<<15))
#define INT_CTRL_Compare7_INT_en_src(data)                                           ((0x00008000&(data))>>15)
#define INT_CTRL_get_Compare7_INT_en(data)                                           ((0x00008000&(data))>>15)
#define INT_CTRL_Compare6_INT_en_shift                                               (14)
#define INT_CTRL_Compare6_INT_en_mask                                                (0x00004000)
#define INT_CTRL_Compare6_INT_en(data)                                               (0x00004000&((data)<<14))
#define INT_CTRL_Compare6_INT_en_src(data)                                           ((0x00004000&(data))>>14)
#define INT_CTRL_get_Compare6_INT_en(data)                                           ((0x00004000&(data))>>14)
#define INT_CTRL_Compare5_INT_en_shift                                               (13)
#define INT_CTRL_Compare5_INT_en_mask                                                (0x00002000)
#define INT_CTRL_Compare5_INT_en(data)                                               (0x00002000&((data)<<13))
#define INT_CTRL_Compare5_INT_en_src(data)                                           ((0x00002000&(data))>>13)
#define INT_CTRL_get_Compare5_INT_en(data)                                           ((0x00002000&(data))>>13)
#define INT_CTRL_Compare4_INT_en_shift                                               (12)
#define INT_CTRL_Compare4_INT_en_mask                                                (0x00001000)
#define INT_CTRL_Compare4_INT_en(data)                                               (0x00001000&((data)<<12))
#define INT_CTRL_Compare4_INT_en_src(data)                                           ((0x00001000&(data))>>12)
#define INT_CTRL_get_Compare4_INT_en(data)                                           ((0x00001000&(data))>>12)
#define INT_CTRL_Compare3_INT_en_shift                                               (11)
#define INT_CTRL_Compare3_INT_en_mask                                                (0x00000800)
#define INT_CTRL_Compare3_INT_en(data)                                               (0x00000800&((data)<<11))
#define INT_CTRL_Compare3_INT_en_src(data)                                           ((0x00000800&(data))>>11)
#define INT_CTRL_get_Compare3_INT_en(data)                                           ((0x00000800&(data))>>11)
#define INT_CTRL_Compare2_INT_en_shift                                               (10)
#define INT_CTRL_Compare2_INT_en_mask                                                (0x00000400)
#define INT_CTRL_Compare2_INT_en(data)                                               (0x00000400&((data)<<10))
#define INT_CTRL_Compare2_INT_en_src(data)                                           ((0x00000400&(data))>>10)
#define INT_CTRL_get_Compare2_INT_en(data)                                           ((0x00000400&(data))>>10)
#define INT_CTRL_Compare1_INT_en_shift                                               (9)
#define INT_CTRL_Compare1_INT_en_mask                                                (0x00000200)
#define INT_CTRL_Compare1_INT_en(data)                                               (0x00000200&((data)<<9))
#define INT_CTRL_Compare1_INT_en_src(data)                                           ((0x00000200&(data))>>9)
#define INT_CTRL_get_Compare1_INT_en(data)                                           ((0x00000200&(data))>>9)
#define INT_CTRL_Compare0_INT_en_shift                                               (8)
#define INT_CTRL_Compare0_INT_en_mask                                                (0x00000100)
#define INT_CTRL_Compare0_INT_en(data)                                               (0x00000100&((data)<<8))
#define INT_CTRL_Compare0_INT_en_src(data)                                           ((0x00000100&(data))>>8)
#define INT_CTRL_get_Compare0_INT_en(data)                                           ((0x00000100&(data))>>8)
#define INT_CTRL_Compare7_INT_status_shift                                           (7)
#define INT_CTRL_Compare7_INT_status_mask                                            (0x00000080)
#define INT_CTRL_Compare7_INT_status(data)                                           (0x00000080&((data)<<7))
#define INT_CTRL_Compare7_INT_status_src(data)                                       ((0x00000080&(data))>>7)
#define INT_CTRL_get_Compare7_INT_status(data)                                       ((0x00000080&(data))>>7)
#define INT_CTRL_Compare6_INT_status_shift                                           (6)
#define INT_CTRL_Compare6_INT_status_mask                                            (0x00000040)
#define INT_CTRL_Compare6_INT_status(data)                                           (0x00000040&((data)<<6))
#define INT_CTRL_Compare6_INT_status_src(data)                                       ((0x00000040&(data))>>6)
#define INT_CTRL_get_Compare6_INT_status(data)                                       ((0x00000040&(data))>>6)
#define INT_CTRL_Compare5_INT_status_shift                                           (5)
#define INT_CTRL_Compare5_INT_status_mask                                            (0x00000020)
#define INT_CTRL_Compare5_INT_status(data)                                           (0x00000020&((data)<<5))
#define INT_CTRL_Compare5_INT_status_src(data)                                       ((0x00000020&(data))>>5)
#define INT_CTRL_get_Compare5_INT_status(data)                                       ((0x00000020&(data))>>5)
#define INT_CTRL_Compare4_INT_status_shift                                           (4)
#define INT_CTRL_Compare4_INT_status_mask                                            (0x00000010)
#define INT_CTRL_Compare4_INT_status(data)                                           (0x00000010&((data)<<4))
#define INT_CTRL_Compare4_INT_status_src(data)                                       ((0x00000010&(data))>>4)
#define INT_CTRL_get_Compare4_INT_status(data)                                       ((0x00000010&(data))>>4)
#define INT_CTRL_Compare3_INT_status_shift                                           (3)
#define INT_CTRL_Compare3_INT_status_mask                                            (0x00000008)
#define INT_CTRL_Compare3_INT_status(data)                                           (0x00000008&((data)<<3))
#define INT_CTRL_Compare3_INT_status_src(data)                                       ((0x00000008&(data))>>3)
#define INT_CTRL_get_Compare3_INT_status(data)                                       ((0x00000008&(data))>>3)
#define INT_CTRL_Compare2_INT_status_shift                                           (2)
#define INT_CTRL_Compare2_INT_status_mask                                            (0x00000004)
#define INT_CTRL_Compare2_INT_status(data)                                           (0x00000004&((data)<<2))
#define INT_CTRL_Compare2_INT_status_src(data)                                       ((0x00000004&(data))>>2)
#define INT_CTRL_get_Compare2_INT_status(data)                                       ((0x00000004&(data))>>2)
#define INT_CTRL_Compare1_INT_status_shift                                           (1)
#define INT_CTRL_Compare1_INT_status_mask                                            (0x00000002)
#define INT_CTRL_Compare1_INT_status(data)                                           (0x00000002&((data)<<1))
#define INT_CTRL_Compare1_INT_status_src(data)                                       ((0x00000002&(data))>>1)
#define INT_CTRL_get_Compare1_INT_status(data)                                       ((0x00000002&(data))>>1)
#define INT_CTRL_Compare0_INT_status_shift                                           (0)
#define INT_CTRL_Compare0_INT_status_mask                                            (0x00000001)
#define INT_CTRL_Compare0_INT_status(data)                                           (0x00000001&((data)<<0))
#define INT_CTRL_Compare0_INT_status_src(data)                                       ((0x00000001&(data))>>0)
#define INT_CTRL_get_Compare0_INT_status(data)                                       ((0x00000001&(data))>>0)


#define COMPARE_TEST_MODE                                                            0x180614E4
#define COMPARE_TEST_MODE_reg_addr                                                   "0xB80614E4"
#define COMPARE_TEST_MODE_reg                                                        0xB80614E4
#define set_COMPARE_TEST_MODE_reg(data)   (*((volatile unsigned int*) COMPARE_TEST_MODE_reg)=data)
#define get_COMPARE_TEST_MODE_reg   (*((volatile unsigned int*) COMPARE_TEST_MODE_reg))
#define COMPARE_TEST_MODE_inst_adr                                                   "0x0039"
#define COMPARE_TEST_MODE_inst                                                       0x0039
#define COMPARE_TEST_MODE_Test_mode_en_shift                                         (0)
#define COMPARE_TEST_MODE_Test_mode_en_mask                                          (0x00000001)
#define COMPARE_TEST_MODE_Test_mode_en(data)                                         (0x00000001&((data)<<0))
#define COMPARE_TEST_MODE_Test_mode_en_src(data)                                     ((0x00000001&(data))>>0)
#define COMPARE_TEST_MODE_get_Test_mode_en(data)                                     ((0x00000001&(data))>>0)


#define COMPARE_TEST_MODE_DATA7_L                                                    0x180614E8
#define COMPARE_TEST_MODE_DATA7_L_reg_addr                                           "0xB80614E8"
#define COMPARE_TEST_MODE_DATA7_L_reg                                                0xB80614E8
#define set_COMPARE_TEST_MODE_DATA7_L_reg(data)   (*((volatile unsigned int*) COMPARE_TEST_MODE_DATA7_L_reg)=data)
#define get_COMPARE_TEST_MODE_DATA7_L_reg   (*((volatile unsigned int*) COMPARE_TEST_MODE_DATA7_L_reg))
#define COMPARE_TEST_MODE_DATA7_L_inst_adr                                           "0x003A"
#define COMPARE_TEST_MODE_DATA7_L_inst                                               0x003A
#define COMPARE_TEST_MODE_DATA7_L_Test_mode_dataL_shift                              (0)
#define COMPARE_TEST_MODE_DATA7_L_Test_mode_dataL_mask                               (0xFFFFFFFF)
#define COMPARE_TEST_MODE_DATA7_L_Test_mode_dataL(data)                              (0xFFFFFFFF&((data)<<0))
#define COMPARE_TEST_MODE_DATA7_L_Test_mode_dataL_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define COMPARE_TEST_MODE_DATA7_L_get_Test_mode_dataL(data)                          ((0xFFFFFFFF&(data))>>0)


#define COMPARE_TEST_MODE_DATA7_H                                                    0x180614EC
#define COMPARE_TEST_MODE_DATA7_H_reg_addr                                           "0xB80614EC"
#define COMPARE_TEST_MODE_DATA7_H_reg                                                0xB80614EC
#define set_COMPARE_TEST_MODE_DATA7_H_reg(data)   (*((volatile unsigned int*) COMPARE_TEST_MODE_DATA7_H_reg)=data)
#define get_COMPARE_TEST_MODE_DATA7_H_reg   (*((volatile unsigned int*) COMPARE_TEST_MODE_DATA7_H_reg))
#define COMPARE_TEST_MODE_DATA7_H_inst_adr                                           "0x003B"
#define COMPARE_TEST_MODE_DATA7_H_inst                                               0x003B
#define COMPARE_TEST_MODE_DATA7_H_Test_mode_dataH_shift                              (0)
#define COMPARE_TEST_MODE_DATA7_H_Test_mode_dataH_mask                               (0xFFFFFFFF)
#define COMPARE_TEST_MODE_DATA7_H_Test_mode_dataH(data)                              (0xFFFFFFFF&((data)<<0))
#define COMPARE_TEST_MODE_DATA7_H_Test_mode_dataH_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define COMPARE_TEST_MODE_DATA7_H_get_Test_mode_dataH(data)                          ((0xFFFFFFFF&(data))>>0)


#define ST_PAD0                                                                      0x18061500
#define ST_PAD0_reg_addr                                                             "0xB8061500"
#define ST_PAD0_reg                                                                  0xB8061500
#define set_ST_PAD0_reg(data)   (*((volatile unsigned int*) ST_PAD0_reg)=data)
#define get_ST_PAD0_reg   (*((volatile unsigned int*) ST_PAD0_reg))
#define ST_PAD0_inst_adr                                                             "0x0040"
#define ST_PAD0_inst                                                                 0x0040
#define ST_PAD0_pad0_active_shift                                                    (31)
#define ST_PAD0_pad0_active_mask                                                     (0x80000000)
#define ST_PAD0_pad0_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD0_pad0_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD0_get_pad0_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD0_pad0_thred_shift                                                     (16)
#define ST_PAD0_pad0_thred_mask                                                      (0x00FF0000)
#define ST_PAD0_pad0_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD0_pad0_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD0_get_pad0_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD0_pad0_sw_shift                                                        (12)
#define ST_PAD0_pad0_sw_mask                                                         (0x0000F000)
#define ST_PAD0_pad0_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD0_pad0_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD0_get_pad0_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD0_pad0_ctrl_shift                                                      (8)
#define ST_PAD0_pad0_ctrl_mask                                                       (0x00000100)
#define ST_PAD0_pad0_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD0_pad0_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD0_get_pad0_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD0_adc_val0_shift                                                       (0)
#define ST_PAD0_adc_val0_mask                                                        (0x0000003F)
#define ST_PAD0_adc_val0(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD0_adc_val0_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD0_get_adc_val0(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD1                                                                      0x18061504
#define ST_PAD1_reg_addr                                                             "0xB8061504"
#define ST_PAD1_reg                                                                  0xB8061504
#define set_ST_PAD1_reg(data)   (*((volatile unsigned int*) ST_PAD1_reg)=data)
#define get_ST_PAD1_reg   (*((volatile unsigned int*) ST_PAD1_reg))
#define ST_PAD1_inst_adr                                                             "0x0041"
#define ST_PAD1_inst                                                                 0x0041
#define ST_PAD1_pad1_active_shift                                                    (31)
#define ST_PAD1_pad1_active_mask                                                     (0x80000000)
#define ST_PAD1_pad1_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD1_pad1_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD1_get_pad1_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD1_Pad1_thred_shift                                                     (16)
#define ST_PAD1_Pad1_thred_mask                                                      (0x00FF0000)
#define ST_PAD1_Pad1_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD1_Pad1_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD1_get_Pad1_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD1_Pad1_sw_shift                                                        (12)
#define ST_PAD1_Pad1_sw_mask                                                         (0x0000F000)
#define ST_PAD1_Pad1_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD1_Pad1_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD1_get_Pad1_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD1_Pad1_ctrl_shift                                                      (8)
#define ST_PAD1_Pad1_ctrl_mask                                                       (0x00000100)
#define ST_PAD1_Pad1_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD1_Pad1_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD1_get_Pad1_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD1_50_shift                                                             (0)
#define ST_PAD1_50_mask                                                              (0x0000003F)
#define ST_PAD1_50(data)                                                             (0x0000003F&((data)<<0))
#define ST_PAD1_50_src(data)                                                         ((0x0000003F&(data))>>0)
#define ST_PAD1_get_50(data)                                                         ((0x0000003F&(data))>>0)


#define ST_PAD2                                                                      0x18061508
#define ST_PAD2_reg_addr                                                             "0xB8061508"
#define ST_PAD2_reg                                                                  0xB8061508
#define set_ST_PAD2_reg(data)   (*((volatile unsigned int*) ST_PAD2_reg)=data)
#define get_ST_PAD2_reg   (*((volatile unsigned int*) ST_PAD2_reg))
#define ST_PAD2_inst_adr                                                             "0x0042"
#define ST_PAD2_inst                                                                 0x0042
#define ST_PAD2_Pad2_active_shift                                                    (31)
#define ST_PAD2_Pad2_active_mask                                                     (0x80000000)
#define ST_PAD2_Pad2_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD2_Pad2_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD2_get_Pad2_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD2_Pad2_thred_shift                                                     (16)
#define ST_PAD2_Pad2_thred_mask                                                      (0x00FF0000)
#define ST_PAD2_Pad2_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD2_Pad2_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD2_get_Pad2_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD2_Pad2_sw_shift                                                        (12)
#define ST_PAD2_Pad2_sw_mask                                                         (0x0000F000)
#define ST_PAD2_Pad2_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD2_Pad2_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD2_get_Pad2_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD2_Pad2_ctrl_shift                                                      (8)
#define ST_PAD2_Pad2_ctrl_mask                                                       (0x00000100)
#define ST_PAD2_Pad2_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD2_Pad2_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD2_get_Pad2_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD2_adc_val2_shift                                                       (0)
#define ST_PAD2_adc_val2_mask                                                        (0x0000003F)
#define ST_PAD2_adc_val2(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD2_adc_val2_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD2_get_adc_val2(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD3                                                                      0x1806150C
#define ST_PAD3_reg_addr                                                             "0xB806150C"
#define ST_PAD3_reg                                                                  0xB806150C
#define set_ST_PAD3_reg(data)   (*((volatile unsigned int*) ST_PAD3_reg)=data)
#define get_ST_PAD3_reg   (*((volatile unsigned int*) ST_PAD3_reg))
#define ST_PAD3_inst_adr                                                             "0x0043"
#define ST_PAD3_inst                                                                 0x0043
#define ST_PAD3_Pad3_active_shift                                                    (31)
#define ST_PAD3_Pad3_active_mask                                                     (0x80000000)
#define ST_PAD3_Pad3_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD3_Pad3_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD3_get_Pad3_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD3_Pad3_thred_shift                                                     (16)
#define ST_PAD3_Pad3_thred_mask                                                      (0x00FF0000)
#define ST_PAD3_Pad3_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD3_Pad3_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD3_get_Pad3_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD3_Pad3_sw_shift                                                        (12)
#define ST_PAD3_Pad3_sw_mask                                                         (0x0000F000)
#define ST_PAD3_Pad3_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD3_Pad3_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD3_get_Pad3_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD3_Pad3_ctrl_shift                                                      (8)
#define ST_PAD3_Pad3_ctrl_mask                                                       (0x00000100)
#define ST_PAD3_Pad3_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD3_Pad3_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD3_get_Pad3_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD3_adc_val3_shift                                                       (0)
#define ST_PAD3_adc_val3_mask                                                        (0x0000003F)
#define ST_PAD3_adc_val3(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD3_adc_val3_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD3_get_adc_val3(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD4                                                                      0x18061510
#define ST_PAD4_reg_addr                                                             "0xB8061510"
#define ST_PAD4_reg                                                                  0xB8061510
#define set_ST_PAD4_reg(data)   (*((volatile unsigned int*) ST_PAD4_reg)=data)
#define get_ST_PAD4_reg   (*((volatile unsigned int*) ST_PAD4_reg))
#define ST_PAD4_inst_adr                                                             "0x0044"
#define ST_PAD4_inst                                                                 0x0044
#define ST_PAD4_Pad4_active_shift                                                    (31)
#define ST_PAD4_Pad4_active_mask                                                     (0x80000000)
#define ST_PAD4_Pad4_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD4_Pad4_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD4_get_Pad4_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD4_Pad4_thred_shift                                                     (16)
#define ST_PAD4_Pad4_thred_mask                                                      (0x00FF0000)
#define ST_PAD4_Pad4_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD4_Pad4_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD4_get_Pad4_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD4_Pad4_sw_shift                                                        (12)
#define ST_PAD4_Pad4_sw_mask                                                         (0x0000F000)
#define ST_PAD4_Pad4_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD4_Pad4_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD4_get_Pad4_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD4_Pad4_ctrl_shift                                                      (8)
#define ST_PAD4_Pad4_ctrl_mask                                                       (0x00000100)
#define ST_PAD4_Pad4_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD4_Pad4_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD4_get_Pad4_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD4_adc_val4_shift                                                       (0)
#define ST_PAD4_adc_val4_mask                                                        (0x0000003F)
#define ST_PAD4_adc_val4(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD4_adc_val4_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD4_get_adc_val4(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD5                                                                      0x18061514
#define ST_PAD5_reg_addr                                                             "0xB8061514"
#define ST_PAD5_reg                                                                  0xB8061514
#define set_ST_PAD5_reg(data)   (*((volatile unsigned int*) ST_PAD5_reg)=data)
#define get_ST_PAD5_reg   (*((volatile unsigned int*) ST_PAD5_reg))
#define ST_PAD5_inst_adr                                                             "0x0045"
#define ST_PAD5_inst                                                                 0x0045
#define ST_PAD5_Pad5_active_shift                                                    (31)
#define ST_PAD5_Pad5_active_mask                                                     (0x80000000)
#define ST_PAD5_Pad5_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD5_Pad5_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD5_get_Pad5_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD5_Pad5_thred_shift                                                     (16)
#define ST_PAD5_Pad5_thred_mask                                                      (0x00FF0000)
#define ST_PAD5_Pad5_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD5_Pad5_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD5_get_Pad5_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD5_Pad5_sw_shift                                                        (12)
#define ST_PAD5_Pad5_sw_mask                                                         (0x0000F000)
#define ST_PAD5_Pad5_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD5_Pad5_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD5_get_Pad5_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD5_Pad5_ctrl_shift                                                      (8)
#define ST_PAD5_Pad5_ctrl_mask                                                       (0x00000100)
#define ST_PAD5_Pad5_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD5_Pad5_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD5_get_Pad5_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD5_adc_val5_shift                                                       (0)
#define ST_PAD5_adc_val5_mask                                                        (0x0000003F)
#define ST_PAD5_adc_val5(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD5_adc_val5_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD5_get_adc_val5(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD6                                                                      0x18061518
#define ST_PAD6_reg_addr                                                             "0xB8061518"
#define ST_PAD6_reg                                                                  0xB8061518
#define set_ST_PAD6_reg(data)   (*((volatile unsigned int*) ST_PAD6_reg)=data)
#define get_ST_PAD6_reg   (*((volatile unsigned int*) ST_PAD6_reg))
#define ST_PAD6_inst_adr                                                             "0x0046"
#define ST_PAD6_inst                                                                 0x0046
#define ST_PAD6_Pad6_active_shift                                                    (31)
#define ST_PAD6_Pad6_active_mask                                                     (0x80000000)
#define ST_PAD6_Pad6_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD6_Pad6_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD6_get_Pad6_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD6_Pad6_thred_shift                                                     (16)
#define ST_PAD6_Pad6_thred_mask                                                      (0x00FF0000)
#define ST_PAD6_Pad6_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD6_Pad6_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD6_get_Pad6_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD6_Pad6_sw_shift                                                        (12)
#define ST_PAD6_Pad6_sw_mask                                                         (0x0000F000)
#define ST_PAD6_Pad6_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD6_Pad6_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD6_get_Pad6_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD6_Pad6_ctrl_shift                                                      (8)
#define ST_PAD6_Pad6_ctrl_mask                                                       (0x00000100)
#define ST_PAD6_Pad6_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD6_Pad6_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD6_get_Pad6_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD6_adc_val6_shift                                                       (0)
#define ST_PAD6_adc_val6_mask                                                        (0x0000003F)
#define ST_PAD6_adc_val6(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD6_adc_val6_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD6_get_adc_val6(data)                                                   ((0x0000003F&(data))>>0)


#define ST_PAD7                                                                      0x1806151C
#define ST_PAD7_reg_addr                                                             "0xB806151C"
#define ST_PAD7_reg                                                                  0xB806151C
#define set_ST_PAD7_reg(data)   (*((volatile unsigned int*) ST_PAD7_reg)=data)
#define get_ST_PAD7_reg   (*((volatile unsigned int*) ST_PAD7_reg))
#define ST_PAD7_inst_adr                                                             "0x0047"
#define ST_PAD7_inst                                                                 0x0047
#define ST_PAD7_Pad7_active_shift                                                    (31)
#define ST_PAD7_Pad7_active_mask                                                     (0x80000000)
#define ST_PAD7_Pad7_active(data)                                                    (0x80000000&((data)<<31))
#define ST_PAD7_Pad7_active_src(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD7_get_Pad7_active(data)                                                ((0x80000000&(data))>>31)
#define ST_PAD7_Pad7_thred_shift                                                     (16)
#define ST_PAD7_Pad7_thred_mask                                                      (0x00FF0000)
#define ST_PAD7_Pad7_thred(data)                                                     (0x00FF0000&((data)<<16))
#define ST_PAD7_Pad7_thred_src(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD7_get_Pad7_thred(data)                                                 ((0x00FF0000&(data))>>16)
#define ST_PAD7_Pad7_sw_shift                                                        (12)
#define ST_PAD7_Pad7_sw_mask                                                         (0x0000F000)
#define ST_PAD7_Pad7_sw(data)                                                        (0x0000F000&((data)<<12))
#define ST_PAD7_Pad7_sw_src(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD7_get_Pad7_sw(data)                                                    ((0x0000F000&(data))>>12)
#define ST_PAD7_Pad7_ctrl_shift                                                      (8)
#define ST_PAD7_Pad7_ctrl_mask                                                       (0x00000100)
#define ST_PAD7_Pad7_ctrl(data)                                                      (0x00000100&((data)<<8))
#define ST_PAD7_Pad7_ctrl_src(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD7_get_Pad7_ctrl(data)                                                  ((0x00000100&(data))>>8)
#define ST_PAD7_adc_val7_shift                                                       (0)
#define ST_PAD7_adc_val7_mask                                                        (0x0000003F)
#define ST_PAD7_adc_val7(data)                                                       (0x0000003F&((data)<<0))
#define ST_PAD7_adc_val7_src(data)                                                   ((0x0000003F&(data))>>0)
#define ST_PAD7_get_adc_val7(data)                                                   ((0x0000003F&(data))>>0)


#define ST_LSADC_CTRL                                                                0x18061520
#define ST_LSADC_CTRL_reg_addr                                                       "0xB8061520"
#define ST_LSADC_CTRL_reg                                                            0xB8061520
#define set_ST_LSADC_CTRL_reg(data)   (*((volatile unsigned int*) ST_LSADC_CTRL_reg)=data)
#define get_ST_LSADC_CTRL_reg   (*((volatile unsigned int*) ST_LSADC_CTRL_reg))
#define ST_LSADC_CTRL_inst_adr                                                       "0x0048"
#define ST_LSADC_CTRL_inst                                                           0x0048
#define ST_LSADC_CTRL_Sel_wait_shift                                                 (28)
#define ST_LSADC_CTRL_Sel_wait_mask                                                  (0xF0000000)
#define ST_LSADC_CTRL_Sel_wait(data)                                                 (0xF0000000&((data)<<28))
#define ST_LSADC_CTRL_Sel_wait_src(data)                                             ((0xF0000000&(data))>>28)
#define ST_LSADC_CTRL_get_Sel_wait(data)                                             ((0xF0000000&(data))>>28)
#define ST_LSADC_CTRL_Sel_adc_ck_shift                                               (24)
#define ST_LSADC_CTRL_Sel_adc_ck_mask                                                (0x0F000000)
#define ST_LSADC_CTRL_Sel_adc_ck(data)                                               (0x0F000000&((data)<<24))
#define ST_LSADC_CTRL_Sel_adc_ck_src(data)                                           ((0x0F000000&(data))>>24)
#define ST_LSADC_CTRL_get_Sel_adc_ck(data)                                           ((0x0F000000&(data))>>24)
#define ST_LSADC_CTRL_Debounce_cnt_shift                                             (20)
#define ST_LSADC_CTRL_Debounce_cnt_mask                                              (0x00F00000)
#define ST_LSADC_CTRL_Debounce_cnt(data)                                             (0x00F00000&((data)<<20))
#define ST_LSADC_CTRL_Debounce_cnt_src(data)                                         ((0x00F00000&(data))>>20)
#define ST_LSADC_CTRL_get_Debounce_cnt(data)                                         ((0x00F00000&(data))>>20)
#define ST_LSADC_CTRL_Dout_Test_IN_shift                                             (8)
#define ST_LSADC_CTRL_Dout_Test_IN_mask                                              (0x0000FF00)
#define ST_LSADC_CTRL_Dout_Test_IN(data)                                             (0x0000FF00&((data)<<8))
#define ST_LSADC_CTRL_Dout_Test_IN_src(data)                                         ((0x0000FF00&(data))>>8)
#define ST_LSADC_CTRL_get_Dout_Test_IN(data)                                         ((0x0000FF00&(data))>>8)
#define ST_LSADC_CTRL_Test_en_shift                                                  (1)
#define ST_LSADC_CTRL_Test_en_mask                                                   (0x00000002)
#define ST_LSADC_CTRL_Test_en(data)                                                  (0x00000002&((data)<<1))
#define ST_LSADC_CTRL_Test_en_src(data)                                              ((0x00000002&(data))>>1)
#define ST_LSADC_CTRL_get_Test_en(data)                                              ((0x00000002&(data))>>1)
#define ST_LSADC_CTRL_Enable_shift                                                   (0)
#define ST_LSADC_CTRL_Enable_mask                                                    (0x00000001)
#define ST_LSADC_CTRL_Enable(data)                                                   (0x00000001&((data)<<0))
#define ST_LSADC_CTRL_Enable_src(data)                                               ((0x00000001&(data))>>0)
#define ST_LSADC_CTRL_get_Enable(data)                                               ((0x00000001&(data))>>0)


#define ST_LSADC_STATUS                                                              0x18061524
#define ST_LSADC_STATUS_reg_addr                                                     "0xB8061524"
#define ST_LSADC_STATUS_reg                                                          0xB8061524
#define set_ST_LSADC_STATUS_reg(data)   (*((volatile unsigned int*) ST_LSADC_STATUS_reg)=data)
#define get_ST_LSADC_STATUS_reg   (*((volatile unsigned int*) ST_LSADC_STATUS_reg))
#define ST_LSADC_STATUS_inst_adr                                                     "0x0049"
#define ST_LSADC_STATUS_inst                                                         0x0049
#define ST_LSADC_STATUS_IRQ_En_shift                                                 (24)
#define ST_LSADC_STATUS_IRQ_En_mask                                                  (0xFF000000)
#define ST_LSADC_STATUS_IRQ_En(data)                                                 (0xFF000000&((data)<<24))
#define ST_LSADC_STATUS_IRQ_En_src(data)                                             ((0xFF000000&(data))>>24)
#define ST_LSADC_STATUS_get_IRQ_En(data)                                             ((0xFF000000&(data))>>24)
#define ST_LSADC_STATUS_PAD_CNT_shift                                                (20)
#define ST_LSADC_STATUS_PAD_CNT_mask                                                 (0x00F00000)
#define ST_LSADC_STATUS_PAD_CNT(data)                                                (0x00F00000&((data)<<20))
#define ST_LSADC_STATUS_PAD_CNT_src(data)                                            ((0x00F00000&(data))>>20)
#define ST_LSADC_STATUS_get_PAD_CNT(data)                                            ((0x00F00000&(data))>>20)
#define ST_LSADC_STATUS_ADC_busy_shift                                               (19)
#define ST_LSADC_STATUS_ADC_busy_mask                                                (0x00080000)
#define ST_LSADC_STATUS_ADC_busy(data)                                               (0x00080000&((data)<<19))
#define ST_LSADC_STATUS_ADC_busy_src(data)                                           ((0x00080000&(data))>>19)
#define ST_LSADC_STATUS_get_ADC_busy(data)                                           ((0x00080000&(data))>>19)
#define ST_LSADC_STATUS_pad_ctrl_shift                                               (12)
#define ST_LSADC_STATUS_pad_ctrl_mask                                                (0x0001F000)
#define ST_LSADC_STATUS_pad_ctrl(data)                                               (0x0001F000&((data)<<12))
#define ST_LSADC_STATUS_pad_ctrl_src(data)                                           ((0x0001F000&(data))>>12)
#define ST_LSADC_STATUS_get_pad_ctrl(data)                                           ((0x0001F000&(data))>>12)
#define ST_LSADC_STATUS_Pad7_status_shift                                            (7)
#define ST_LSADC_STATUS_Pad7_status_mask                                             (0x00000080)
#define ST_LSADC_STATUS_Pad7_status(data)                                            (0x00000080&((data)<<7))
#define ST_LSADC_STATUS_Pad7_status_src(data)                                        ((0x00000080&(data))>>7)
#define ST_LSADC_STATUS_get_Pad7_status(data)                                        ((0x00000080&(data))>>7)
#define ST_LSADC_STATUS_Pad6_status_shift                                            (6)
#define ST_LSADC_STATUS_Pad6_status_mask                                             (0x00000040)
#define ST_LSADC_STATUS_Pad6_status(data)                                            (0x00000040&((data)<<6))
#define ST_LSADC_STATUS_Pad6_status_src(data)                                        ((0x00000040&(data))>>6)
#define ST_LSADC_STATUS_get_Pad6_status(data)                                        ((0x00000040&(data))>>6)
#define ST_LSADC_STATUS_Pad5_status_shift                                            (5)
#define ST_LSADC_STATUS_Pad5_status_mask                                             (0x00000020)
#define ST_LSADC_STATUS_Pad5_status(data)                                            (0x00000020&((data)<<5))
#define ST_LSADC_STATUS_Pad5_status_src(data)                                        ((0x00000020&(data))>>5)
#define ST_LSADC_STATUS_get_Pad5_status(data)                                        ((0x00000020&(data))>>5)
#define ST_LSADC_STATUS_Pad4_status_shift                                            (4)
#define ST_LSADC_STATUS_Pad4_status_mask                                             (0x00000010)
#define ST_LSADC_STATUS_Pad4_status(data)                                            (0x00000010&((data)<<4))
#define ST_LSADC_STATUS_Pad4_status_src(data)                                        ((0x00000010&(data))>>4)
#define ST_LSADC_STATUS_get_Pad4_status(data)                                        ((0x00000010&(data))>>4)
#define ST_LSADC_STATUS_Pad3_status_shift                                            (3)
#define ST_LSADC_STATUS_Pad3_status_mask                                             (0x00000008)
#define ST_LSADC_STATUS_Pad3_status(data)                                            (0x00000008&((data)<<3))
#define ST_LSADC_STATUS_Pad3_status_src(data)                                        ((0x00000008&(data))>>3)
#define ST_LSADC_STATUS_get_Pad3_status(data)                                        ((0x00000008&(data))>>3)
#define ST_LSADC_STATUS_Pad2_status_shift                                            (2)
#define ST_LSADC_STATUS_Pad2_status_mask                                             (0x00000004)
#define ST_LSADC_STATUS_Pad2_status(data)                                            (0x00000004&((data)<<2))
#define ST_LSADC_STATUS_Pad2_status_src(data)                                        ((0x00000004&(data))>>2)
#define ST_LSADC_STATUS_get_Pad2_status(data)                                        ((0x00000004&(data))>>2)
#define ST_LSADC_STATUS_Pad1_status_shift                                            (1)
#define ST_LSADC_STATUS_Pad1_status_mask                                             (0x00000002)
#define ST_LSADC_STATUS_Pad1_status(data)                                            (0x00000002&((data)<<1))
#define ST_LSADC_STATUS_Pad1_status_src(data)                                        ((0x00000002&(data))>>1)
#define ST_LSADC_STATUS_get_Pad1_status(data)                                        ((0x00000002&(data))>>1)
#define ST_LSADC_STATUS_Pad0_status_shift                                            (0)
#define ST_LSADC_STATUS_Pad0_status_mask                                             (0x00000001)
#define ST_LSADC_STATUS_Pad0_status(data)                                            (0x00000001&((data)<<0))
#define ST_LSADC_STATUS_Pad0_status_src(data)                                        ((0x00000001&(data))>>0)
#define ST_LSADC_STATUS_get_Pad0_status(data)                                        ((0x00000001&(data))>>0)


#define ST_LSADC_ANALOG_CTRL                                                         0x18061528
#define ST_LSADC_ANALOG_CTRL_reg_addr                                                "0xB8061528"
#define ST_LSADC_ANALOG_CTRL_reg                                                     0xB8061528
#define set_ST_LSADC_ANALOG_CTRL_reg(data)   (*((volatile unsigned int*) ST_LSADC_ANALOG_CTRL_reg)=data)
#define get_ST_LSADC_ANALOG_CTRL_reg   (*((volatile unsigned int*) ST_LSADC_ANALOG_CTRL_reg))
#define ST_LSADC_ANALOG_CTRL_inst_adr                                                "0x004A"
#define ST_LSADC_ANALOG_CTRL_inst                                                    0x004A
#define ST_LSADC_ANALOG_CTRL_JD_sbias_shift                                          (16)
#define ST_LSADC_ANALOG_CTRL_JD_sbias_mask                                           (0x00030000)
#define ST_LSADC_ANALOG_CTRL_JD_sbias(data)                                          (0x00030000&((data)<<16))
#define ST_LSADC_ANALOG_CTRL_JD_sbias_src(data)                                      ((0x00030000&(data))>>16)
#define ST_LSADC_ANALOG_CTRL_get_JD_sbias(data)                                      ((0x00030000&(data))>>16)
#define ST_LSADC_ANALOG_CTRL_JD_adsbias_shift                                        (12)
#define ST_LSADC_ANALOG_CTRL_JD_adsbias_mask                                         (0x00003000)
#define ST_LSADC_ANALOG_CTRL_JD_adsbias(data)                                        (0x00003000&((data)<<12))
#define ST_LSADC_ANALOG_CTRL_JD_adsbias_src(data)                                    ((0x00003000&(data))>>12)
#define ST_LSADC_ANALOG_CTRL_get_JD_adsbias(data)                                    ((0x00003000&(data))>>12)
#define ST_LSADC_ANALOG_CTRL_JD_DUMMY_shift                                          (10)
#define ST_LSADC_ANALOG_CTRL_JD_DUMMY_mask                                           (0x00000C00)
#define ST_LSADC_ANALOG_CTRL_JD_DUMMY(data)                                          (0x00000C00&((data)<<10))
#define ST_LSADC_ANALOG_CTRL_JD_DUMMY_src(data)                                      ((0x00000C00&(data))>>10)
#define ST_LSADC_ANALOG_CTRL_get_JD_DUMMY(data)                                      ((0x00000C00&(data))>>10)
#define ST_LSADC_ANALOG_CTRL_JD_svr_shift                                            (8)
#define ST_LSADC_ANALOG_CTRL_JD_svr_mask                                             (0x00000100)
#define ST_LSADC_ANALOG_CTRL_JD_svr(data)                                            (0x00000100&((data)<<8))
#define ST_LSADC_ANALOG_CTRL_JD_svr_src(data)                                        ((0x00000100&(data))>>8)
#define ST_LSADC_ANALOG_CTRL_get_JD_svr(data)                                        ((0x00000100&(data))>>8)
#define ST_LSADC_ANALOG_CTRL_JD_adcksel_shift                                        (4)
#define ST_LSADC_ANALOG_CTRL_JD_adcksel_mask                                         (0x00000010)
#define ST_LSADC_ANALOG_CTRL_JD_adcksel(data)                                        (0x00000010&((data)<<4))
#define ST_LSADC_ANALOG_CTRL_JD_adcksel_src(data)                                    ((0x00000010&(data))>>4)
#define ST_LSADC_ANALOG_CTRL_get_JD_adcksel(data)                                    ((0x00000010&(data))>>4)
#define ST_LSADC_ANALOG_CTRL_JD_power_shift                                          (0)
#define ST_LSADC_ANALOG_CTRL_JD_power_mask                                           (0x00000001)
#define ST_LSADC_ANALOG_CTRL_JD_power(data)                                          (0x00000001&((data)<<0))
#define ST_LSADC_ANALOG_CTRL_JD_power_src(data)                                      ((0x00000001&(data))>>0)
#define ST_LSADC_ANALOG_CTRL_get_JD_power(data)                                      ((0x00000001&(data))>>0)


#define ST_LSADC_PERI_TOP_DEBUG                                                      0x1806152C
#define ST_LSADC_PERI_TOP_DEBUG_reg_addr                                             "0xB806152C"
#define ST_LSADC_PERI_TOP_DEBUG_reg                                                  0xB806152C
#define set_ST_LSADC_PERI_TOP_DEBUG_reg(data)   (*((volatile unsigned int*) ST_LSADC_PERI_TOP_DEBUG_reg)=data)
#define get_ST_LSADC_PERI_TOP_DEBUG_reg   (*((volatile unsigned int*) ST_LSADC_PERI_TOP_DEBUG_reg))
#define ST_LSADC_PERI_TOP_DEBUG_inst_adr                                             "0x004B"
#define ST_LSADC_PERI_TOP_DEBUG_inst                                                 0x004B
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_shift                           (16)
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_mask                            (0x00070000)
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel(data)                           (0x00070000&((data)<<16))
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_src(data)                       ((0x00070000&(data))>>16)
#define ST_LSADC_PERI_TOP_DEBUG_get_Lsadc_2_ifd_data_sel(data)                       ((0x00070000&(data))>>16)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_enable_shift                             (14)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_enable_mask                              (0x00004000)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_enable(data)                             (0x00004000&((data)<<14))
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_enable_src(data)                         ((0x00004000&(data))>>14)
#define ST_LSADC_PERI_TOP_DEBUG_get_Powersaving_enable(data)                         ((0x00004000&(data))>>14)
#define ST_LSADC_PERI_TOP_DEBUG_Powersavingcycletime_shift                           (11)
#define ST_LSADC_PERI_TOP_DEBUG_Powersavingcycletime_mask                            (0x00003800)
#define ST_LSADC_PERI_TOP_DEBUG_Powersavingcycletime(data)                           (0x00003800&((data)<<11))
#define ST_LSADC_PERI_TOP_DEBUG_Powersavingcycletime_src(data)                       ((0x00003800&(data))>>11)
#define ST_LSADC_PERI_TOP_DEBUG_get_Powersavingcycletime(data)                       ((0x00003800&(data))>>11)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_shift                                    (8)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_mask                                     (0x00000700)
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving(data)                                    (0x00000700&((data)<<8))
#define ST_LSADC_PERI_TOP_DEBUG_Powersaving_src(data)                                ((0x00000700&(data))>>8)
#define ST_LSADC_PERI_TOP_DEBUG_get_Powersaving(data)                                ((0x00000700&(data))>>8)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_shift                                 (0)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_mask                                  (0x000000FF)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug(data)                                 (0x000000FF&((data)<<0))
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_src(data)                             ((0x000000FF&(data))>>0)
#define ST_LSADC_PERI_TOP_DEBUG_get_peri_top_debug(data)                             ((0x000000FF&(data))>>0)


#define LSADC_PAD5_LEVEL_SET0                                                        0x18061530
#define LSADC_PAD5_LEVEL_SET0_reg_addr                                               "0xB8061530"
#define LSADC_PAD5_LEVEL_SET0_reg                                                    0xB8061530
#define set_LSADC_PAD5_LEVEL_SET0_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET0_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET0_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET0_reg))
#define LSADC_PAD5_LEVEL_SET0_inst_adr                                               "0x004C"
#define LSADC_PAD5_LEVEL_SET0_inst                                                   0x004C
#define LSADC_PAD5_LEVEL_SET0_Level_0_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET0_Level_0_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET0_Level_0_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET0_Level_0_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET0_get_Level_0_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET0_Level_0_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET0_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET0_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET0_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET0_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET0_Block0_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET0_Block0_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET0_Block0_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET0_Block0_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET0_get_Block0_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET0_INT_en0_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET0_INT_en0_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET0_INT_en0(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET0_INT_en0_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET0_get_INT_en0(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET0_INT_pending_bit0_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET0_INT_pending_bit0_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET0_INT_pending_bit0(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET0_INT_pending_bit0_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET0_get_INT_pending_bit0(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD5_LEVEL_SET1                                                        0x18061534
#define LSADC_PAD5_LEVEL_SET1_reg_addr                                               "0xB8061534"
#define LSADC_PAD5_LEVEL_SET1_reg                                                    0xB8061534
#define set_LSADC_PAD5_LEVEL_SET1_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET1_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET1_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET1_reg))
#define LSADC_PAD5_LEVEL_SET1_inst_adr                                               "0x004D"
#define LSADC_PAD5_LEVEL_SET1_inst                                                   0x004D
#define LSADC_PAD5_LEVEL_SET1_Level_1_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET1_Level_1_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET1_Level_1_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET1_Level_1_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET1_get_Level_1_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET1_Level_0_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET1_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET1_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET1_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET1_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET1_Block1_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET1_Block1_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET1_Block1_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET1_Block1_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET1_get_Block1_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET1_INT_en1_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET1_INT_en1_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET1_INT_en1(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET1_INT_en1_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET1_get_INT_en1(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET1_INT_pending_bit1_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET1_INT_pending_bit1_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET1_INT_pending_bit1(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET1_INT_pending_bit1_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET1_get_INT_pending_bit1(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD5_LEVEL_SET2                                                        0x18061538
#define LSADC_PAD5_LEVEL_SET2_reg_addr                                               "0xB8061538"
#define LSADC_PAD5_LEVEL_SET2_reg                                                    0xB8061538
#define set_LSADC_PAD5_LEVEL_SET2_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET2_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET2_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET2_reg))
#define LSADC_PAD5_LEVEL_SET2_inst_adr                                               "0x004E"
#define LSADC_PAD5_LEVEL_SET2_inst                                                   0x004E
#define LSADC_PAD5_LEVEL_SET2_Level_2_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET2_Level_2_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET2_Level_2_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET2_Level_2_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET2_get_Level_2_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET2_Level_2_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET2_Level_2_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET2_Level_2_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET2_Level_2_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET2_get_Level_2_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET2_Block2_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET2_Block2_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET2_Block2_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET2_Block2_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET2_get_Block2_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET2_INT_en2_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET2_INT_en2_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET2_INT_en2(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET2_INT_en2_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET2_get_INT_en2(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET2_INT_pending_bit2_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET2_INT_pending_bit2_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET2_INT_pending_bit2(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET2_INT_pending_bit2_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET2_get_INT_pending_bit2(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD5_LEVEL_SET3                                                        0x1806153C
#define LSADC_PAD5_LEVEL_SET3_reg_addr                                               "0xB806153C"
#define LSADC_PAD5_LEVEL_SET3_reg                                                    0xB806153C
#define set_LSADC_PAD5_LEVEL_SET3_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET3_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET3_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET3_reg))
#define LSADC_PAD5_LEVEL_SET3_inst_adr                                               "0x004F"
#define LSADC_PAD5_LEVEL_SET3_inst                                                   0x004F
#define LSADC_PAD5_LEVEL_SET3_Level_3_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET3_Level_3_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET3_Level_3_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET3_Level_3_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET3_get_Level_3_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET3_Level_3_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET3_Level_3_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET3_Level_3_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET3_Level_3_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET3_get_Level_3_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET3_Block3_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET3_Block3_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET3_Block3_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET3_Block3_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET3_get_Block3_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET3_INT_en3_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET3_INT_en3_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET3_INT_en3(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET3_INT_en3_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET3_get_INT_en3(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET3_INT_pending_bit3_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET3_INT_pending_bit3_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET3_INT_pending_bit3(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET3_INT_pending_bit3_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET3_get_INT_pending_bit3(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD5_LEVEL_SET4                                                        0x18061540
#define LSADC_PAD5_LEVEL_SET4_reg_addr                                               "0xB8061540"
#define LSADC_PAD5_LEVEL_SET4_reg                                                    0xB8061540
#define set_LSADC_PAD5_LEVEL_SET4_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET4_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET4_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET4_reg))
#define LSADC_PAD5_LEVEL_SET4_inst_adr                                               "0x0050"
#define LSADC_PAD5_LEVEL_SET4_inst                                                   0x0050
#define LSADC_PAD5_LEVEL_SET4_Level_4_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET4_Level_4_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET4_Level_4_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET4_Level_4_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET4_get_Level_4_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET4_Level_4_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET4_Level_4_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET4_Level_4_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET4_Level_4_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET4_get_Level_4_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET4_Block4_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET4_Block4_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET4_Block4_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET4_Block4_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET4_get_Block4_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET4_INT_en4_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET4_INT_en4_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET4_INT_en4(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET4_INT_en4_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET4_get_INT_en4(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET4_INT_pending_bit4_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET4_INT_pending_bit4_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET4_INT_pending_bit4(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET4_INT_pending_bit4_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET4_get_INT_pending_bit4(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD5_LEVEL_SET5                                                        0x18061544
#define LSADC_PAD5_LEVEL_SET5_reg_addr                                               "0xB8061544"
#define LSADC_PAD5_LEVEL_SET5_reg                                                    0xB8061544
#define set_LSADC_PAD5_LEVEL_SET5_reg(data)   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET5_reg)=data)
#define get_LSADC_PAD5_LEVEL_SET5_reg   (*((volatile unsigned int*) LSADC_PAD5_LEVEL_SET5_reg))
#define LSADC_PAD5_LEVEL_SET5_inst_adr                                               "0x0051"
#define LSADC_PAD5_LEVEL_SET5_inst                                                   0x0051
#define LSADC_PAD5_LEVEL_SET5_Level_5_top_bound_shift                                (24)
#define LSADC_PAD5_LEVEL_SET5_Level_5_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD5_LEVEL_SET5_Level_5_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET5_Level_5_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET5_get_Level_5_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET5_Level_5_low_bound_shift                                (16)
#define LSADC_PAD5_LEVEL_SET5_Level_5_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET5_Level_5_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET5_Level_5_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET5_get_Level_5_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET5_Block5_en_shift                                        (15)
#define LSADC_PAD5_LEVEL_SET5_Block5_en_mask                                         (0x00008000)
#define LSADC_PAD5_LEVEL_SET5_Block5_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET5_Block5_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET5_get_Block5_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET5_INT_en5_shift                                          (1)
#define LSADC_PAD5_LEVEL_SET5_INT_en5_mask                                           (0x00000002)
#define LSADC_PAD5_LEVEL_SET5_INT_en5(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET5_INT_en5_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET5_get_INT_en5(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET5_INT_pending_bit5_shift                                 (0)
#define LSADC_PAD5_LEVEL_SET5_INT_pending_bit5_mask                                  (0x00000001)
#define LSADC_PAD5_LEVEL_SET5_INT_pending_bit5(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD5_LEVEL_SET5_INT_pending_bit5_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD5_LEVEL_SET5_get_INT_pending_bit5(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET0                                                        0x18061548
#define LSADC_PAD6_LEVEL_SET0_reg_addr                                               "0xB8061548"
#define LSADC_PAD6_LEVEL_SET0_reg                                                    0xB8061548
#define set_LSADC_PAD6_LEVEL_SET0_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET0_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET0_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET0_reg))
#define LSADC_PAD6_LEVEL_SET0_inst_adr                                               "0x0052"
#define LSADC_PAD6_LEVEL_SET0_inst                                                   0x0052
#define LSADC_PAD6_LEVEL_SET0_Level_0_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET0_Level_0_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET0_Level_0_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET0_Level_0_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET0_get_Level_0_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET0_Level_0_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET0_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET0_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET0_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET0_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET0_Block0_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET0_Block0_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET0_Block0_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET0_Block0_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET0_get_Block0_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET0_INT_en0_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET0_INT_en0_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET0_INT_en0(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET0_INT_en0_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET0_get_INT_en0(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET0_INT_pending_bit0_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET0_INT_pending_bit0_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET0_INT_pending_bit0(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET0_INT_pending_bit0_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET0_get_INT_pending_bit0(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET1                                                        0x1806154C
#define LSADC_PAD6_LEVEL_SET1_reg_addr                                               "0xB806154C"
#define LSADC_PAD6_LEVEL_SET1_reg                                                    0xB806154C
#define set_LSADC_PAD6_LEVEL_SET1_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET1_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET1_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET1_reg))
#define LSADC_PAD6_LEVEL_SET1_inst_adr                                               "0x0053"
#define LSADC_PAD6_LEVEL_SET1_inst                                                   0x0053
#define LSADC_PAD6_LEVEL_SET1_Level_1_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET1_Level_1_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET1_Level_1_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET1_Level_1_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET1_get_Level_1_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET1_Level_0_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET1_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET1_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET1_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET1_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET1_Block1_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET1_Block1_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET1_Block1_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET1_Block1_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET1_get_Block1_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET1_INT_en1_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET1_INT_en1_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET1_INT_en1(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET1_INT_en1_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET1_get_INT_en1(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET1_INT_pending_bit1_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET1_INT_pending_bit1_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET1_INT_pending_bit1(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET1_INT_pending_bit1_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET1_get_INT_pending_bit1(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET2                                                        0x18061550
#define LSADC_PAD6_LEVEL_SET2_reg_addr                                               "0xB8061550"
#define LSADC_PAD6_LEVEL_SET2_reg                                                    0xB8061550
#define set_LSADC_PAD6_LEVEL_SET2_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET2_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET2_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET2_reg))
#define LSADC_PAD6_LEVEL_SET2_inst_adr                                               "0x0054"
#define LSADC_PAD6_LEVEL_SET2_inst                                                   0x0054
#define LSADC_PAD6_LEVEL_SET2_Level_2_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET2_Level_2_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET2_Level_2_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET2_Level_2_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET2_get_Level_2_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET2_Level_2_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET2_Level_2_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET2_Level_2_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET2_Level_2_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET2_get_Level_2_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET2_Block2_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET2_Block2_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET2_Block2_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET2_Block2_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET2_get_Block2_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET2_INT_en2_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET2_INT_en2_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET2_INT_en2(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET2_INT_en2_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET2_get_INT_en2(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET2_INT_pending_bit2_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET2_INT_pending_bit2_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET2_INT_pending_bit2(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET2_INT_pending_bit2_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET2_get_INT_pending_bit2(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET3                                                        0x18061554
#define LSADC_PAD6_LEVEL_SET3_reg_addr                                               "0xB8061554"
#define LSADC_PAD6_LEVEL_SET3_reg                                                    0xB8061554
#define set_LSADC_PAD6_LEVEL_SET3_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET3_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET3_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET3_reg))
#define LSADC_PAD6_LEVEL_SET3_inst_adr                                               "0x0055"
#define LSADC_PAD6_LEVEL_SET3_inst                                                   0x0055
#define LSADC_PAD6_LEVEL_SET3_Level_3_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET3_Level_3_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET3_Level_3_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET3_Level_3_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET3_get_Level_3_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET3_Level_3_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET3_Level_3_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET3_Level_3_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET3_Level_3_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET3_get_Level_3_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET3_Block3_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET3_Block3_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET3_Block3_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET3_Block3_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET3_get_Block3_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET3_INT_en3_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET3_INT_en3_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET3_INT_en3(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET3_INT_en3_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET3_get_INT_en3(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET3_INT_pending_bit3_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET3_INT_pending_bit3_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET3_INT_pending_bit3(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET3_INT_pending_bit3_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET3_get_INT_pending_bit3(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET4                                                        0x18061558
#define LSADC_PAD6_LEVEL_SET4_reg_addr                                               "0xB8061558"
#define LSADC_PAD6_LEVEL_SET4_reg                                                    0xB8061558
#define set_LSADC_PAD6_LEVEL_SET4_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET4_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET4_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET4_reg))
#define LSADC_PAD6_LEVEL_SET4_inst_adr                                               "0x0056"
#define LSADC_PAD6_LEVEL_SET4_inst                                                   0x0056
#define LSADC_PAD6_LEVEL_SET4_Level_4_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET4_Level_4_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET4_Level_4_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET4_Level_4_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET4_get_Level_4_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET4_Level_4_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET4_Level_4_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET4_Level_4_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET4_Level_4_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET4_get_Level_4_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET4_Block4_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET4_Block4_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET4_Block4_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET4_Block4_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET4_get_Block4_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET4_INT_en4_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET4_INT_en4_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET4_INT_en4(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET4_INT_en4_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET4_get_INT_en4(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET4_INT_pending_bit4_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET4_INT_pending_bit4_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET4_INT_pending_bit4(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET4_INT_pending_bit4_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET4_get_INT_pending_bit4(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD6_LEVEL_SET5                                                        0x1806155C
#define LSADC_PAD6_LEVEL_SET5_reg_addr                                               "0xB806155C"
#define LSADC_PAD6_LEVEL_SET5_reg                                                    0xB806155C
#define set_LSADC_PAD6_LEVEL_SET5_reg(data)   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET5_reg)=data)
#define get_LSADC_PAD6_LEVEL_SET5_reg   (*((volatile unsigned int*) LSADC_PAD6_LEVEL_SET5_reg))
#define LSADC_PAD6_LEVEL_SET5_inst_adr                                               "0x0057"
#define LSADC_PAD6_LEVEL_SET5_inst                                                   0x0057
#define LSADC_PAD6_LEVEL_SET5_Level_5_top_bound_shift                                (24)
#define LSADC_PAD6_LEVEL_SET5_Level_5_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD6_LEVEL_SET5_Level_5_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET5_Level_5_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET5_get_Level_5_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET5_Level_5_low_bound_shift                                (16)
#define LSADC_PAD6_LEVEL_SET5_Level_5_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET5_Level_5_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET5_Level_5_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET5_get_Level_5_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET5_Block5_en_shift                                        (15)
#define LSADC_PAD6_LEVEL_SET5_Block5_en_mask                                         (0x00008000)
#define LSADC_PAD6_LEVEL_SET5_Block5_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET5_Block5_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET5_get_Block5_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET5_INT_en5_shift                                          (1)
#define LSADC_PAD6_LEVEL_SET5_INT_en5_mask                                           (0x00000002)
#define LSADC_PAD6_LEVEL_SET5_INT_en5(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET5_INT_en5_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET5_get_INT_en5(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET5_INT_pending_bit5_shift                                 (0)
#define LSADC_PAD6_LEVEL_SET5_INT_pending_bit5_mask                                  (0x00000001)
#define LSADC_PAD6_LEVEL_SET5_INT_pending_bit5(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD6_LEVEL_SET5_INT_pending_bit5_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD6_LEVEL_SET5_get_INT_pending_bit5(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET0                                                        0x18061560
#define LSADC_PAD7_LEVEL_SET0_reg_addr                                               "0xB8061560"
#define LSADC_PAD7_LEVEL_SET0_reg                                                    0xB8061560
#define set_LSADC_PAD7_LEVEL_SET0_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET0_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET0_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET0_reg))
#define LSADC_PAD7_LEVEL_SET0_inst_adr                                               "0x0058"
#define LSADC_PAD7_LEVEL_SET0_inst                                                   0x0058
#define LSADC_PAD7_LEVEL_SET0_Level_0_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET0_Level_0_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET0_Level_0_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET0_Level_0_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET0_get_Level_0_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET0_Level_0_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET0_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET0_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET0_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET0_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET0_Block0_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET0_Block0_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET0_Block0_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET0_Block0_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET0_get_Block0_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET0_INT_en0_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET0_INT_en0_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET0_INT_en0(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET0_INT_en0_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET0_get_INT_en0(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET0_INT_pending_bit0_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET0_INT_pending_bit0_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET0_INT_pending_bit0(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET0_INT_pending_bit0_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET0_get_INT_pending_bit0(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET1                                                        0x18061564
#define LSADC_PAD7_LEVEL_SET1_reg_addr                                               "0xB8061564"
#define LSADC_PAD7_LEVEL_SET1_reg                                                    0xB8061564
#define set_LSADC_PAD7_LEVEL_SET1_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET1_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET1_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET1_reg))
#define LSADC_PAD7_LEVEL_SET1_inst_adr                                               "0x0059"
#define LSADC_PAD7_LEVEL_SET1_inst                                                   0x0059
#define LSADC_PAD7_LEVEL_SET1_Level_1_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET1_Level_1_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET1_Level_1_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET1_Level_1_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET1_get_Level_1_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET1_Level_0_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET1_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET1_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET1_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET1_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET1_Block1_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET1_Block1_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET1_Block1_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET1_Block1_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET1_get_Block1_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET1_INT_en1_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET1_INT_en1_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET1_INT_en1(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET1_INT_en1_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET1_get_INT_en1(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET1_INT_pending_bit1_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET1_INT_pending_bit1_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET1_INT_pending_bit1(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET1_INT_pending_bit1_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET1_get_INT_pending_bit1(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET2                                                        0x18061568
#define LSADC_PAD7_LEVEL_SET2_reg_addr                                               "0xB8061568"
#define LSADC_PAD7_LEVEL_SET2_reg                                                    0xB8061568
#define set_LSADC_PAD7_LEVEL_SET2_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET2_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET2_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET2_reg))
#define LSADC_PAD7_LEVEL_SET2_inst_adr                                               "0x005A"
#define LSADC_PAD7_LEVEL_SET2_inst                                                   0x005A
#define LSADC_PAD7_LEVEL_SET2_Level_2_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET2_Level_2_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET2_Level_2_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET2_Level_2_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET2_get_Level_2_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET2_Level_2_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET2_Level_2_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET2_Level_2_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET2_Level_2_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET2_get_Level_2_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET2_Block2_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET2_Block2_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET2_Block2_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET2_Block2_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET2_get_Block2_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET2_INT_en2_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET2_INT_en2_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET2_INT_en2(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET2_INT_en2_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET2_get_INT_en2(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET2_INT_pending_bit2_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET2_INT_pending_bit2_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET2_INT_pending_bit2(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET2_INT_pending_bit2_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET2_get_INT_pending_bit2(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET3                                                        0x1806156C
#define LSADC_PAD7_LEVEL_SET3_reg_addr                                               "0xB806156C"
#define LSADC_PAD7_LEVEL_SET3_reg                                                    0xB806156C
#define set_LSADC_PAD7_LEVEL_SET3_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET3_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET3_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET3_reg))
#define LSADC_PAD7_LEVEL_SET3_inst_adr                                               "0x005B"
#define LSADC_PAD7_LEVEL_SET3_inst                                                   0x005B
#define LSADC_PAD7_LEVEL_SET3_Level_3_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET3_Level_3_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET3_Level_3_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET3_Level_3_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET3_get_Level_3_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET3_Level_3_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET3_Level_3_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET3_Level_3_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET3_Level_3_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET3_get_Level_3_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET3_Block3_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET3_Block3_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET3_Block3_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET3_Block3_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET3_get_Block3_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET3_INT_en3_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET3_INT_en3_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET3_INT_en3(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET3_INT_en3_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET3_get_INT_en3(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET3_INT_pending_bit3_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET3_INT_pending_bit3_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET3_INT_pending_bit3(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET3_INT_pending_bit3_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET3_get_INT_pending_bit3(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET4                                                        0x18061570
#define LSADC_PAD7_LEVEL_SET4_reg_addr                                               "0xB8061570"
#define LSADC_PAD7_LEVEL_SET4_reg                                                    0xB8061570
#define set_LSADC_PAD7_LEVEL_SET4_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET4_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET4_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET4_reg))
#define LSADC_PAD7_LEVEL_SET4_inst_adr                                               "0x005C"
#define LSADC_PAD7_LEVEL_SET4_inst                                                   0x005C
#define LSADC_PAD7_LEVEL_SET4_Level_4_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET4_Level_4_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET4_Level_4_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET4_Level_4_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET4_get_Level_4_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET4_Level_4_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET4_Level_4_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET4_Level_4_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET4_Level_4_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET4_get_Level_4_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET4_Block4_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET4_Block4_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET4_Block4_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET4_Block4_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET4_get_Block4_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET4_INT_en4_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET4_INT_en4_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET4_INT_en4(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET4_INT_en4_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET4_get_INT_en4(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET4_INT_pending_bit4_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET4_INT_pending_bit4_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET4_INT_pending_bit4(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET4_INT_pending_bit4_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET4_get_INT_pending_bit4(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD7_LEVEL_SET5                                                        0x18061574
#define LSADC_PAD7_LEVEL_SET5_reg_addr                                               "0xB8061574"
#define LSADC_PAD7_LEVEL_SET5_reg                                                    0xB8061574
#define set_LSADC_PAD7_LEVEL_SET5_reg(data)   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET5_reg)=data)
#define get_LSADC_PAD7_LEVEL_SET5_reg   (*((volatile unsigned int*) LSADC_PAD7_LEVEL_SET5_reg))
#define LSADC_PAD7_LEVEL_SET5_inst_adr                                               "0x005D"
#define LSADC_PAD7_LEVEL_SET5_inst                                                   0x005D
#define LSADC_PAD7_LEVEL_SET5_Level_5_top_bound_shift                                (24)
#define LSADC_PAD7_LEVEL_SET5_Level_5_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD7_LEVEL_SET5_Level_5_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET5_Level_5_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET5_get_Level_5_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET5_Level_5_low_bound_shift                                (16)
#define LSADC_PAD7_LEVEL_SET5_Level_5_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET5_Level_5_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET5_Level_5_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET5_get_Level_5_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET5_Block5_en_shift                                        (15)
#define LSADC_PAD7_LEVEL_SET5_Block5_en_mask                                         (0x00008000)
#define LSADC_PAD7_LEVEL_SET5_Block5_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET5_Block5_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET5_get_Block5_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET5_INT_en5_shift                                          (1)
#define LSADC_PAD7_LEVEL_SET5_INT_en5_mask                                           (0x00000002)
#define LSADC_PAD7_LEVEL_SET5_INT_en5(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET5_INT_en5_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET5_get_INT_en5(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET5_INT_pending_bit5_shift                                 (0)
#define LSADC_PAD7_LEVEL_SET5_INT_pending_bit5_mask                                  (0x00000001)
#define LSADC_PAD7_LEVEL_SET5_INT_pending_bit5(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD7_LEVEL_SET5_INT_pending_bit5_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD7_LEVEL_SET5_get_INT_pending_bit5(data)                             ((0x00000001&(data))>>0)


#define LSADC_INT_PAD5                                                               0x18061578
#define LSADC_INT_PAD5_reg_addr                                                      "0xB8061578"
#define LSADC_INT_PAD5_reg                                                           0xB8061578
#define set_LSADC_INT_PAD5_reg(data)   (*((volatile unsigned int*) LSADC_INT_PAD5_reg)=data)
#define get_LSADC_INT_PAD5_reg   (*((volatile unsigned int*) LSADC_INT_PAD5_reg))
#define LSADC_INT_PAD5_inst_adr                                                      "0x005E"
#define LSADC_INT_PAD5_inst                                                          0x005E
#define LSADC_INT_PAD5_ADC_value5latch_shift                                         (8)
#define LSADC_INT_PAD5_ADC_value5latch_mask                                          (0x00003F00)
#define LSADC_INT_PAD5_ADC_value5latch(data)                                         (0x00003F00&((data)<<8))
#define LSADC_INT_PAD5_ADC_value5latch_src(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD5_get_ADC_value5latch(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD5_INT_latchstatus_shift                                         (0)
#define LSADC_INT_PAD5_INT_latchstatus_mask                                          (0x00000001)
#define LSADC_INT_PAD5_INT_latchstatus(data)                                         (0x00000001&((data)<<0))
#define LSADC_INT_PAD5_INT_latchstatus_src(data)                                     ((0x00000001&(data))>>0)
#define LSADC_INT_PAD5_get_INT_latchstatus(data)                                     ((0x00000001&(data))>>0)


#define LSADC_INT_PAD6                                                               0x1806157C
#define LSADC_INT_PAD6_reg_addr                                                      "0xB806157C"
#define LSADC_INT_PAD6_reg                                                           0xB806157C
#define set_LSADC_INT_PAD6_reg(data)   (*((volatile unsigned int*) LSADC_INT_PAD6_reg)=data)
#define get_LSADC_INT_PAD6_reg   (*((volatile unsigned int*) LSADC_INT_PAD6_reg))
#define LSADC_INT_PAD6_inst_adr                                                      "0x005F"
#define LSADC_INT_PAD6_inst                                                          0x005F
#define LSADC_INT_PAD6_ADC_value6latch_shift                                         (8)
#define LSADC_INT_PAD6_ADC_value6latch_mask                                          (0x00003F00)
#define LSADC_INT_PAD6_ADC_value6latch(data)                                         (0x00003F00&((data)<<8))
#define LSADC_INT_PAD6_ADC_value6latch_src(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD6_get_ADC_value6latch(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD6_INT_latchstatus_shift                                         (0)
#define LSADC_INT_PAD6_INT_latchstatus_mask                                          (0x00000001)
#define LSADC_INT_PAD6_INT_latchstatus(data)                                         (0x00000001&((data)<<0))
#define LSADC_INT_PAD6_INT_latchstatus_src(data)                                     ((0x00000001&(data))>>0)
#define LSADC_INT_PAD6_get_INT_latchstatus(data)                                     ((0x00000001&(data))>>0)


#define LSADC_INT_PAD7                                                               0x18061580
#define LSADC_INT_PAD7_reg_addr                                                      "0xB8061580"
#define LSADC_INT_PAD7_reg                                                           0xB8061580
#define set_LSADC_INT_PAD7_reg(data)   (*((volatile unsigned int*) LSADC_INT_PAD7_reg)=data)
#define get_LSADC_INT_PAD7_reg   (*((volatile unsigned int*) LSADC_INT_PAD7_reg))
#define LSADC_INT_PAD7_inst_adr                                                      "0x0060"
#define LSADC_INT_PAD7_inst                                                          0x0060
#define LSADC_INT_PAD7_ADC_value7latch_shift                                         (8)
#define LSADC_INT_PAD7_ADC_value7latch_mask                                          (0x00003F00)
#define LSADC_INT_PAD7_ADC_value7latch(data)                                         (0x00003F00&((data)<<8))
#define LSADC_INT_PAD7_ADC_value7latch_src(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD7_get_ADC_value7latch(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD7_INT_latchstatus_shift                                         (0)
#define LSADC_INT_PAD7_INT_latchstatus_mask                                          (0x00000001)
#define LSADC_INT_PAD7_INT_latchstatus(data)                                         (0x00000001&((data)<<0))
#define LSADC_INT_PAD7_INT_latchstatus_src(data)                                     ((0x00000001&(data))>>0)
#define LSADC_INT_PAD7_get_INT_latchstatus(data)                                     ((0x00000001&(data))>>0)


#define ST_I2C_CR                                                                    0x18061A00
#define ST_I2C_CR_reg_addr                                                           "0xB8061A00"
#define ST_I2C_CR_reg                                                                0xB8061A00
#define set_ST_I2C_CR_reg(data)   (*((volatile unsigned int*) ST_I2C_CR_reg)=data)
#define get_ST_I2C_CR_reg   (*((volatile unsigned int*) ST_I2C_CR_reg))
#define ST_I2C_CR_inst_adr                                                           "0x0080"
#define ST_I2C_CR_inst                                                               0x0080
#define ST_I2C_CR_CMDERR_IE_shift                                                    (7)
#define ST_I2C_CR_CMDERR_IE_mask                                                     (0x00000080)
#define ST_I2C_CR_CMDERR_IE(data)                                                    (0x00000080&((data)<<7))
#define ST_I2C_CR_CMDERR_IE_src(data)                                                ((0x00000080&(data))>>7)
#define ST_I2C_CR_get_CMDERR_IE(data)                                                ((0x00000080&(data))>>7)
#define ST_I2C_CR_TIMEOUT_EN_shift                                                   (6)
#define ST_I2C_CR_TIMEOUT_EN_mask                                                    (0x00000040)
#define ST_I2C_CR_TIMEOUT_EN(data)                                                   (0x00000040&((data)<<6))
#define ST_I2C_CR_TIMEOUT_EN_src(data)                                               ((0x00000040&(data))>>6)
#define ST_I2C_CR_get_TIMEOUT_EN(data)                                               ((0x00000040&(data))>>6)
#define ST_I2C_CR_DEBOUNCE_MODE_shift                                                (4)
#define ST_I2C_CR_DEBOUNCE_MODE_mask                                                 (0x00000030)
#define ST_I2C_CR_DEBOUNCE_MODE(data)                                                (0x00000030&((data)<<4))
#define ST_I2C_CR_DEBOUNCE_MODE_src(data)                                            ((0x00000030&(data))>>4)
#define ST_I2C_CR_get_DEBOUNCE_MODE(data)                                            ((0x00000030&(data))>>4)
#define ST_I2C_CR_TIMEOUT_IE_shift                                                   (3)
#define ST_I2C_CR_TIMEOUT_IE_mask                                                    (0x00000008)
#define ST_I2C_CR_TIMEOUT_IE(data)                                                   (0x00000008&((data)<<3))
#define ST_I2C_CR_TIMEOUT_IE_src(data)                                               ((0x00000008&(data))>>3)
#define ST_I2C_CR_get_TIMEOUT_IE(data)                                               ((0x00000008&(data))>>3)
#define ST_I2C_CR_RETIME_M_shift                                                     (0)
#define ST_I2C_CR_RETIME_M_mask                                                      (0x00000007)
#define ST_I2C_CR_RETIME_M(data)                                                     (0x00000007&((data)<<0))
#define ST_I2C_CR_RETIME_M_src(data)                                                 ((0x00000007&(data))>>0)
#define ST_I2C_CR_get_RETIME_M(data)                                                 ((0x00000007&(data))>>0)


#define ST_I2C_SR                                                                    0x18061A04
#define ST_I2C_SR_reg_addr                                                           "0xB8061A04"
#define ST_I2C_SR_reg                                                                0xB8061A04
#define set_ST_I2C_SR_reg(data)   (*((volatile unsigned int*) ST_I2C_SR_reg)=data)
#define get_ST_I2C_SR_reg   (*((volatile unsigned int*) ST_I2C_SR_reg))
#define ST_I2C_SR_inst_adr                                                           "0x0081"
#define ST_I2C_SR_inst                                                               0x0081
#define ST_I2C_SR_CMDERR_shift                                                       (7)
#define ST_I2C_SR_CMDERR_mask                                                        (0x00000080)
#define ST_I2C_SR_CMDERR(data)                                                       (0x00000080&((data)<<7))
#define ST_I2C_SR_CMDERR_src(data)                                                   ((0x00000080&(data))>>7)
#define ST_I2C_SR_get_CMDERR(data)                                                   ((0x00000080&(data))>>7)
#define ST_I2C_SR_Finish_shift                                                       (4)
#define ST_I2C_SR_Finish_mask                                                        (0x00000010)
#define ST_I2C_SR_Finish(data)                                                       (0x00000010&((data)<<4))
#define ST_I2C_SR_Finish_src(data)                                                   ((0x00000010&(data))>>4)
#define ST_I2C_SR_get_Finish(data)                                                   ((0x00000010&(data))>>4)
#define ST_I2C_SR_timeout_shift                                                      (3)
#define ST_I2C_SR_timeout_mask                                                       (0x00000008)
#define ST_I2C_SR_timeout(data)                                                      (0x00000008&((data)<<3))
#define ST_I2C_SR_timeout_src(data)                                                  ((0x00000008&(data))>>3)
#define ST_I2C_SR_get_timeout(data)                                                  ((0x00000008&(data))>>3)


#define ST_I2C_TR                                                                    0x18061A08
#define ST_I2C_TR_reg_addr                                                           "0xB8061A08"
#define ST_I2C_TR_reg                                                                0xB8061A08
#define set_ST_I2C_TR_reg(data)   (*((volatile unsigned int*) ST_I2C_TR_reg)=data)
#define get_ST_I2C_TR_reg   (*((volatile unsigned int*) ST_I2C_TR_reg))
#define ST_I2C_TR_inst_adr                                                           "0x0082"
#define ST_I2C_TR_inst                                                               0x0082
#define ST_I2C_TR_timeout_val_shift                                                  (0)
#define ST_I2C_TR_timeout_val_mask                                                   (0x000000FF)
#define ST_I2C_TR_timeout_val(data)                                                  (0x000000FF&((data)<<0))
#define ST_I2C_TR_timeout_val_src(data)                                              ((0x000000FF&(data))>>0)
#define ST_I2C_TR_get_timeout_val(data)                                              ((0x000000FF&(data))>>0)


#define ST_EDID_CR                                                                   0x18061A0C
#define ST_EDID_CR_reg_addr                                                          "0xB8061A0C"
#define ST_EDID_CR_reg                                                               0xB8061A0C
#define set_ST_EDID_CR_reg(data)   (*((volatile unsigned int*) ST_EDID_CR_reg)=data)
#define get_ST_EDID_CR_reg   (*((volatile unsigned int*) ST_EDID_CR_reg))
#define ST_EDID_CR_inst_adr                                                          "0x0083"
#define ST_EDID_CR_inst                                                              0x0083
#define ST_EDID_CR_EDID_ADDRESS_shift                                                (5)
#define ST_EDID_CR_EDID_ADDRESS_mask                                                 (0x000000E0)
#define ST_EDID_CR_EDID_ADDRESS(data)                                                (0x000000E0&((data)<<5))
#define ST_EDID_CR_EDID_ADDRESS_src(data)                                            ((0x000000E0&(data))>>5)
#define ST_EDID_CR_get_EDID_ADDRESS(data)                                            ((0x000000E0&(data))>>5)
#define ST_EDID_CR_FINISH_INT_EN_shift                                               (4)
#define ST_EDID_CR_FINISH_INT_EN_mask                                                (0x00000010)
#define ST_EDID_CR_FINISH_INT_EN(data)                                               (0x00000010&((data)<<4))
#define ST_EDID_CR_FINISH_INT_EN_src(data)                                           ((0x00000010&(data))>>4)
#define ST_EDID_CR_get_FINISH_INT_EN(data)                                           ((0x00000010&(data))>>4)
#define ST_EDID_CR_DDC1_FORCE_shift                                                  (3)
#define ST_EDID_CR_DDC1_FORCE_mask                                                   (0x00000008)
#define ST_EDID_CR_DDC1_FORCE(data)                                                  (0x00000008&((data)<<3))
#define ST_EDID_CR_DDC1_FORCE_src(data)                                              ((0x00000008&(data))>>3)
#define ST_EDID_CR_get_DDC1_FORCE(data)                                              ((0x00000008&(data))>>3)
#define ST_EDID_CR_DDC2B_FORCE_shift                                                 (2)
#define ST_EDID_CR_DDC2B_FORCE_mask                                                  (0x00000004)
#define ST_EDID_CR_DDC2B_FORCE(data)                                                 (0x00000004&((data)<<2))
#define ST_EDID_CR_DDC2B_FORCE_src(data)                                             ((0x00000004&(data))>>2)
#define ST_EDID_CR_get_DDC2B_FORCE(data)                                             ((0x00000004&(data))>>2)
#define ST_EDID_CR_EDID_SRWEN_shift                                                  (1)
#define ST_EDID_CR_EDID_SRWEN_mask                                                   (0x00000002)
#define ST_EDID_CR_EDID_SRWEN(data)                                                  (0x00000002&((data)<<1))
#define ST_EDID_CR_EDID_SRWEN_src(data)                                              ((0x00000002&(data))>>1)
#define ST_EDID_CR_get_EDID_SRWEN(data)                                              ((0x00000002&(data))>>1)
#define ST_EDID_CR_EDID_EN_shift                                                     (0)
#define ST_EDID_CR_EDID_EN_mask                                                      (0x00000001)
#define ST_EDID_CR_EDID_EN(data)                                                     (0x00000001&((data)<<0))
#define ST_EDID_CR_EDID_EN_src(data)                                                 ((0x00000001&(data))>>0)
#define ST_EDID_CR_get_EDID_EN(data)                                                 ((0x00000001&(data))>>0)


#define ST_DDC_VCR                                                                   0x18061A10
#define ST_DDC_VCR_reg_addr                                                          "0xB8061A10"
#define ST_DDC_VCR_reg                                                               0xB8061A10
#define set_ST_DDC_VCR_reg(data)   (*((volatile unsigned int*) ST_DDC_VCR_reg)=data)
#define get_ST_DDC_VCR_reg   (*((volatile unsigned int*) ST_DDC_VCR_reg))
#define ST_DDC_VCR_inst_adr                                                          "0x0084"
#define ST_DDC_VCR_inst                                                              0x0084
#define ST_DDC_VCR_DDC1_VCount_shift                                                 (0)
#define ST_DDC_VCR_DDC1_VCount_mask                                                  (0x000000FF)
#define ST_DDC_VCR_DDC1_VCount(data)                                                 (0x000000FF&((data)<<0))
#define ST_DDC_VCR_DDC1_VCount_src(data)                                             ((0x000000FF&(data))>>0)
#define ST_DDC_VCR_get_DDC1_VCount(data)                                             ((0x000000FF&(data))>>0)


#define ST_EDID_IMSWSAR                                                              0x18061A14
#define ST_EDID_IMSWSAR_reg_addr                                                     "0xB8061A14"
#define ST_EDID_IMSWSAR_reg                                                          0xB8061A14
#define set_ST_EDID_IMSWSAR_reg(data)   (*((volatile unsigned int*) ST_EDID_IMSWSAR_reg)=data)
#define get_ST_EDID_IMSWSAR_reg   (*((volatile unsigned int*) ST_EDID_IMSWSAR_reg))
#define ST_EDID_IMSWSAR_inst_adr                                                     "0x0085"
#define ST_EDID_IMSWSAR_inst                                                         0x0085
#define ST_EDID_IMSWSAR_EDID_SADR_shift                                              (0)
#define ST_EDID_IMSWSAR_EDID_SADR_mask                                               (0x000000FF)
#define ST_EDID_IMSWSAR_EDID_SADR(data)                                              (0x000000FF&((data)<<0))
#define ST_EDID_IMSWSAR_EDID_SADR_src(data)                                          ((0x000000FF&(data))>>0)
#define ST_EDID_IMSWSAR_get_EDID_SADR(data)                                          ((0x000000FF&(data))>>0)


#define ST_EDID_IMSWEAR                                                              0x18061A18
#define ST_EDID_IMSWEAR_reg_addr                                                     "0xB8061A18"
#define ST_EDID_IMSWEAR_reg                                                          0xB8061A18
#define set_ST_EDID_IMSWEAR_reg(data)   (*((volatile unsigned int*) ST_EDID_IMSWEAR_reg)=data)
#define get_ST_EDID_IMSWEAR_reg   (*((volatile unsigned int*) ST_EDID_IMSWEAR_reg))
#define ST_EDID_IMSWEAR_inst_adr                                                     "0x0086"
#define ST_EDID_IMSWEAR_inst                                                         0x0086
#define ST_EDID_IMSWEAR_EDID_EADR_shift                                              (0)
#define ST_EDID_IMSWEAR_EDID_EADR_mask                                               (0x000000FF)
#define ST_EDID_IMSWEAR_EDID_EADR(data)                                              (0x000000FF&((data)<<0))
#define ST_EDID_IMSWEAR_EDID_EADR_src(data)                                          ((0x000000FF&(data))>>0)
#define ST_EDID_IMSWEAR_get_EDID_EADR(data)                                          ((0x000000FF&(data))>>0)


#define ST_EDID_IR                                                                   0x18061A1C
#define ST_EDID_IR_reg_addr                                                          "0xB8061A1C"
#define ST_EDID_IR_reg                                                               0xB8061A1C
#define set_ST_EDID_IR_reg(data)   (*((volatile unsigned int*) ST_EDID_IR_reg)=data)
#define get_ST_EDID_IR_reg   (*((volatile unsigned int*) ST_EDID_IR_reg))
#define ST_EDID_IR_inst_adr                                                          "0x0087"
#define ST_EDID_IR_inst                                                              0x0087
#define ST_EDID_IR_EDIDMODE_shift                                                    (6)
#define ST_EDID_IR_EDIDMODE_mask                                                     (0x00000040)
#define ST_EDID_IR_EDIDMODE(data)                                                    (0x00000040&((data)<<6))
#define ST_EDID_IR_EDIDMODE_src(data)                                                ((0x00000040&(data))>>6)
#define ST_EDID_IR_get_EDIDMODE(data)                                                ((0x00000040&(data))>>6)
#define ST_EDID_IR_EDIDSUBADDRESS_shift                                              (5)
#define ST_EDID_IR_EDIDSUBADDRESS_mask                                               (0x00000020)
#define ST_EDID_IR_EDIDSUBADDRESS(data)                                              (0x00000020&((data)<<5))
#define ST_EDID_IR_EDIDSUBADDRESS_src(data)                                          ((0x00000020&(data))>>5)
#define ST_EDID_IR_get_EDIDSUBADDRESS(data)                                          ((0x00000020&(data))>>5)
#define ST_EDID_IR_EDIDSTOP_shift                                                    (4)
#define ST_EDID_IR_EDIDSTOP_mask                                                     (0x00000010)
#define ST_EDID_IR_EDIDSTOP(data)                                                    (0x00000010&((data)<<4))
#define ST_EDID_IR_EDIDSTOP_src(data)                                                ((0x00000010&(data))>>4)
#define ST_EDID_IR_get_EDIDSTOP(data)                                                ((0x00000010&(data))>>4)
#define ST_EDID_IR_I2C_M_RD_ST_IE_shift                                              (3)
#define ST_EDID_IR_I2C_M_RD_ST_IE_mask                                               (0x00000008)
#define ST_EDID_IR_I2C_M_RD_ST_IE(data)                                              (0x00000008&((data)<<3))
#define ST_EDID_IR_I2C_M_RD_ST_IE_src(data)                                          ((0x00000008&(data))>>3)
#define ST_EDID_IR_get_I2C_M_RD_ST_IE(data)                                          ((0x00000008&(data))>>3)
#define ST_EDID_IR_I2C_M_RD_SP_IE_shift                                              (2)
#define ST_EDID_IR_I2C_M_RD_SP_IE_mask                                               (0x00000004)
#define ST_EDID_IR_I2C_M_RD_SP_IE(data)                                              (0x00000004&((data)<<2))
#define ST_EDID_IR_I2C_M_RD_SP_IE_src(data)                                          ((0x00000004&(data))>>2)
#define ST_EDID_IR_get_I2C_M_RD_SP_IE(data)                                          ((0x00000004&(data))>>2)
#define ST_EDID_IR_EDIDSUBADDRESS_IE_shift                                           (1)
#define ST_EDID_IR_EDIDSUBADDRESS_IE_mask                                            (0x00000002)
#define ST_EDID_IR_EDIDSUBADDRESS_IE(data)                                           (0x00000002&((data)<<1))
#define ST_EDID_IR_EDIDSUBADDRESS_IE_src(data)                                       ((0x00000002&(data))>>1)
#define ST_EDID_IR_get_EDIDSUBADDRESS_IE(data)                                       ((0x00000002&(data))>>1)
#define ST_EDID_IR_EDIDSTOP_IE_shift                                                 (0)
#define ST_EDID_IR_EDIDSTOP_IE_mask                                                  (0x00000001)
#define ST_EDID_IR_EDIDSTOP_IE(data)                                                 (0x00000001&((data)<<0))
#define ST_EDID_IR_EDIDSTOP_IE_src(data)                                             ((0x00000001&(data))>>0)
#define ST_EDID_IR_get_EDIDSTOP_IE(data)                                             ((0x00000001&(data))>>0)


#define ST_DDC_SIR                                                                   0x18061A20
#define ST_DDC_SIR_reg_addr                                                          "0xB8061A20"
#define ST_DDC_SIR_reg                                                               0xB8061A20
#define set_ST_DDC_SIR_reg(data)   (*((volatile unsigned int*) ST_DDC_SIR_reg)=data)
#define get_ST_DDC_SIR_reg   (*((volatile unsigned int*) ST_DDC_SIR_reg))
#define ST_DDC_SIR_inst_adr                                                          "0x0088"
#define ST_DDC_SIR_inst                                                              0x0088
#define ST_DDC_SIR_EDIDAP_shift                                                      (0)
#define ST_DDC_SIR_EDIDAP_mask                                                       (0x000000FF)
#define ST_DDC_SIR_EDIDAP(data)                                                      (0x000000FF&((data)<<0))
#define ST_DDC_SIR_EDIDAP_src(data)                                                  ((0x000000FF&(data))>>0)
#define ST_DDC_SIR_get_EDIDAP(data)                                                  ((0x000000FF&(data))>>0)


#define ST_DDC_SAP                                                                   0x18061A24
#define ST_DDC_SAP_reg_addr                                                          "0xB8061A24"
#define ST_DDC_SAP_reg                                                               0xB8061A24
#define set_ST_DDC_SAP_reg(data)   (*((volatile unsigned int*) ST_DDC_SAP_reg)=data)
#define get_ST_DDC_SAP_reg   (*((volatile unsigned int*) ST_DDC_SAP_reg))
#define ST_DDC_SAP_inst_adr                                                          "0x0089"
#define ST_DDC_SAP_inst                                                              0x0089
#define ST_DDC_SAP_EDIDDP_shift                                                      (0)
#define ST_DDC_SAP_EDIDDP_mask                                                       (0x000000FF)
#define ST_DDC_SAP_EDIDDP(data)                                                      (0x000000FF&((data)<<0))
#define ST_DDC_SAP_EDIDDP_src(data)                                                  ((0x000000FF&(data))>>0)
#define ST_DDC_SAP_get_EDIDDP(data)                                                  ((0x000000FF&(data))>>0)


#define ST_DDC_BISTCR                                                                0x18061A28
#define ST_DDC_BISTCR_reg_addr                                                       "0xB8061A28"
#define ST_DDC_BISTCR_reg                                                            0xB8061A28
#define set_ST_DDC_BISTCR_reg(data)   (*((volatile unsigned int*) ST_DDC_BISTCR_reg)=data)
#define get_ST_DDC_BISTCR_reg   (*((volatile unsigned int*) ST_DDC_BISTCR_reg))
#define ST_DDC_BISTCR_inst_adr                                                       "0x008A"
#define ST_DDC_BISTCR_inst                                                           0x008A
#define ST_DDC_BISTCR_DDC_BIST_RME_shift                                             (4)
#define ST_DDC_BISTCR_DDC_BIST_RME_mask                                              (0x00000010)
#define ST_DDC_BISTCR_DDC_BIST_RME(data)                                             (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_DDC_BIST_RME_src(data)                                         ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_get_DDC_BIST_RME(data)                                         ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_DDC_BIST_RM_shift                                              (0)
#define ST_DDC_BISTCR_DDC_BIST_RM_mask                                               (0x0000000F)
#define ST_DDC_BISTCR_DDC_BIST_RM(data)                                              (0x0000000F&((data)<<0))
#define ST_DDC_BISTCR_DDC_BIST_RM_src(data)                                          ((0x0000000F&(data))>>0)
#define ST_DDC_BISTCR_get_DDC_BIST_RM(data)                                          ((0x0000000F&(data))>>0)


#define ST_DDC_SCR                                                                   0x18061A2C
#define ST_DDC_SCR_reg_addr                                                          "0xB8061A2C"
#define ST_DDC_SCR_reg                                                               0xB8061A2C
#define set_ST_DDC_SCR_reg(data)   (*((volatile unsigned int*) ST_DDC_SCR_reg)=data)
#define get_ST_DDC_SCR_reg   (*((volatile unsigned int*) ST_DDC_SCR_reg))
#define ST_DDC_SCR_inst_adr                                                          "0x008B"
#define ST_DDC_SCR_inst                                                              0x008B
#define ST_DDC_SCR_SEGPT_LATIE_shift                                                 (7)
#define ST_DDC_SCR_SEGPT_LATIE_mask                                                  (0x00000080)
#define ST_DDC_SCR_SEGPT_LATIE(data)                                                 (0x00000080&((data)<<7))
#define ST_DDC_SCR_SEGPT_LATIE_src(data)                                             ((0x00000080&(data))>>7)
#define ST_DDC_SCR_get_SEGPT_LATIE(data)                                             ((0x00000080&(data))>>7)
#define ST_DDC_SCR_Dataoutputdelay_sel_shift                                         (4)
#define ST_DDC_SCR_Dataoutputdelay_sel_mask                                          (0x00000070)
#define ST_DDC_SCR_Dataoutputdelay_sel(data)                                         (0x00000070&((data)<<4))
#define ST_DDC_SCR_Dataoutputdelay_sel_src(data)                                     ((0x00000070&(data))>>4)
#define ST_DDC_SCR_get_Dataoutputdelay_sel(data)                                     ((0x00000070&(data))>>4)
#define ST_DDC_SCR_I2C_M_RD_ST_STS_shift                                             (2)
#define ST_DDC_SCR_I2C_M_RD_ST_STS_mask                                              (0x00000004)
#define ST_DDC_SCR_I2C_M_RD_ST_STS(data)                                             (0x00000004&((data)<<2))
#define ST_DDC_SCR_I2C_M_RD_ST_STS_src(data)                                         ((0x00000004&(data))>>2)
#define ST_DDC_SCR_get_I2C_M_RD_ST_STS(data)                                         ((0x00000004&(data))>>2)
#define ST_DDC_SCR_I2C_M_RD_SP_STS_shift                                             (1)
#define ST_DDC_SCR_I2C_M_RD_SP_STS_mask                                              (0x00000002)
#define ST_DDC_SCR_I2C_M_RD_SP_STS(data)                                             (0x00000002&((data)<<1))
#define ST_DDC_SCR_I2C_M_RD_SP_STS_src(data)                                         ((0x00000002&(data))>>1)
#define ST_DDC_SCR_get_I2C_M_RD_SP_STS(data)                                         ((0x00000002&(data))>>1)
#define ST_DDC_SCR_SGID_EN_shift                                                     (0)
#define ST_DDC_SCR_SGID_EN_mask                                                      (0x00000001)
#define ST_DDC_SCR_SGID_EN(data)                                                     (0x00000001&((data)<<0))
#define ST_DDC_SCR_SGID_EN_src(data)                                                 ((0x00000001&(data))>>0)
#define ST_DDC_SCR_get_SGID_EN(data)                                                 ((0x00000001&(data))>>0)


#define ST_DDC_SSAR                                                                  0x18061A30
#define ST_DDC_SSAR_reg_addr                                                         "0xB8061A30"
#define ST_DDC_SSAR_reg                                                              0xB8061A30
#define set_ST_DDC_SSAR_reg(data)   (*((volatile unsigned int*) ST_DDC_SSAR_reg)=data)
#define get_ST_DDC_SSAR_reg   (*((volatile unsigned int*) ST_DDC_SSAR_reg))
#define ST_DDC_SSAR_inst_adr                                                         "0x008C"
#define ST_DDC_SSAR_inst                                                             0x008C
#define ST_DDC_SSAR_SGID_ADDRESS_shift                                               (1)
#define ST_DDC_SSAR_SGID_ADDRESS_mask                                                (0x000000FE)
#define ST_DDC_SSAR_SGID_ADDRESS(data)                                               (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_SGID_ADDRESS_src(data)                                           ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_get_SGID_ADDRESS(data)                                           ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_SGID_DTRDEN_shift                                                (0)
#define ST_DDC_SSAR_SGID_DTRDEN_mask                                                 (0x00000001)
#define ST_DDC_SSAR_SGID_DTRDEN(data)                                                (0x00000001&((data)<<0))
#define ST_DDC_SSAR_SGID_DTRDEN_src(data)                                            ((0x00000001&(data))>>0)
#define ST_DDC_SSAR_get_SGID_DTRDEN(data)                                            ((0x00000001&(data))>>0)


#define ST_DDC_SPR                                                                   0x18061A34
#define ST_DDC_SPR_reg_addr                                                          "0xB8061A34"
#define ST_DDC_SPR_reg                                                               0xB8061A34
#define set_ST_DDC_SPR_reg(data)   (*((volatile unsigned int*) ST_DDC_SPR_reg)=data)
#define get_ST_DDC_SPR_reg   (*((volatile unsigned int*) ST_DDC_SPR_reg))
#define ST_DDC_SPR_inst_adr                                                          "0x008D"
#define ST_DDC_SPR_inst                                                              0x008D
#define ST_DDC_SPR_SEGPT_LATCHED_shift                                               (7)
#define ST_DDC_SPR_SEGPT_LATCHED_mask                                                (0x00000080)
#define ST_DDC_SPR_SEGPT_LATCHED(data)                                               (0x00000080&((data)<<7))
#define ST_DDC_SPR_SEGPT_LATCHED_src(data)                                           ((0x00000080&(data))>>7)
#define ST_DDC_SPR_get_SEGPT_LATCHED(data)                                           ((0x00000080&(data))>>7)
#define ST_DDC_SPR_SEG_PT_shift                                                      (0)
#define ST_DDC_SPR_SEG_PT_mask                                                       (0x0000007F)
#define ST_DDC_SPR_SEG_PT(data)                                                      (0x0000007F&((data)<<0))
#define ST_DDC_SPR_SEG_PT_src(data)                                                  ((0x0000007F&(data))>>0)
#define ST_DDC_SPR_get_SEG_PT(data)                                                  ((0x0000007F&(data))>>0)


#define ST_DDC_SFCR                                                                  0x18061A38
#define ST_DDC_SFCR_reg_addr                                                         "0xB8061A38"
#define ST_DDC_SFCR_reg                                                              0xB8061A38
#define set_ST_DDC_SFCR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFCR_reg)=data)
#define get_ST_DDC_SFCR_reg   (*((volatile unsigned int*) ST_DDC_SFCR_reg))
#define ST_DDC_SFCR_inst_adr                                                         "0x008E"
#define ST_DDC_SFCR_inst                                                             0x008E
#define ST_DDC_SFCR_SPECIAL_MODE_shift                                               (3)
#define ST_DDC_SFCR_SPECIAL_MODE_mask                                                (0x00000008)
#define ST_DDC_SFCR_SPECIAL_MODE(data)                                               (0x00000008&((data)<<3))
#define ST_DDC_SFCR_SPECIAL_MODE_src(data)                                           ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_get_SPECIAL_MODE(data)                                           ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_DOFFPT_RESET_shift                                               (2)
#define ST_DDC_SFCR_DOFFPT_RESET_mask                                                (0x00000004)
#define ST_DDC_SFCR_DOFFPT_RESET(data)                                               (0x00000004&((data)<<2))
#define ST_DDC_SFCR_DOFFPT_RESET_src(data)                                           ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_get_DOFFPT_RESET(data)                                           ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_DIFFPT_RESET_shift                                               (1)
#define ST_DDC_SFCR_DIFFPT_RESET_mask                                                (0x00000002)
#define ST_DDC_SFCR_DIFFPT_RESET(data)                                               (0x00000002&((data)<<1))
#define ST_DDC_SFCR_DIFFPT_RESET_src(data)                                           ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_get_DIFFPT_RESET(data)                                           ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_CIID_EN_shift                                                    (0)
#define ST_DDC_SFCR_CIID_EN_mask                                                     (0x00000001)
#define ST_DDC_SFCR_CIID_EN(data)                                                    (0x00000001&((data)<<0))
#define ST_DDC_SFCR_CIID_EN_src(data)                                                ((0x00000001&(data))>>0)
#define ST_DDC_SFCR_get_CIID_EN(data)                                                ((0x00000001&(data))>>0)


#define ST_DDC_SFSAR                                                                 0x18061A3C
#define ST_DDC_SFSAR_reg_addr                                                        "0xB8061A3C"
#define ST_DDC_SFSAR_reg                                                             0xB8061A3C
#define set_ST_DDC_SFSAR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFSAR_reg)=data)
#define get_ST_DDC_SFSAR_reg   (*((volatile unsigned int*) ST_DDC_SFSAR_reg))
#define ST_DDC_SFSAR_inst_adr                                                        "0x008F"
#define ST_DDC_SFSAR_inst                                                            0x008F
#define ST_DDC_SFSAR_CIID_ADDRESS_shift                                              (1)
#define ST_DDC_SFSAR_CIID_ADDRESS_mask                                               (0x000000FE)
#define ST_DDC_SFSAR_CIID_ADDRESS(data)                                              (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_CIID_ADDRESS_src(data)                                          ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_get_CIID_ADDRESS(data)                                          ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_CIRWS_CURRENT_shift                                             (0)
#define ST_DDC_SFSAR_CIRWS_CURRENT_mask                                              (0x00000001)
#define ST_DDC_SFSAR_CIRWS_CURRENT(data)                                             (0x00000001&((data)<<0))
#define ST_DDC_SFSAR_CIRWS_CURRENT_src(data)                                         ((0x00000001&(data))>>0)
#define ST_DDC_SFSAR_get_CIRWS_CURRENT(data)                                         ((0x00000001&(data))>>0)


#define ST_DDC_SFDR                                                                  0x18061A40
#define ST_DDC_SFDR_reg_addr                                                         "0xB8061A40"
#define ST_DDC_SFDR_reg                                                              0xB8061A40
#define set_ST_DDC_SFDR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFDR_reg)=data)
#define get_ST_DDC_SFDR_reg   (*((volatile unsigned int*) ST_DDC_SFDR_reg))
#define ST_DDC_SFDR_inst_adr                                                         "0x0090"
#define ST_DDC_SFDR_inst                                                             0x0090
#define ST_DDC_SFDR_CIIDDP_shift                                                     (0)
#define ST_DDC_SFDR_CIIDDP_mask                                                      (0x000000FF)
#define ST_DDC_SFDR_CIIDDP(data)                                                     (0x000000FF&((data)<<0))
#define ST_DDC_SFDR_CIIDDP_src(data)                                                 ((0x000000FF&(data))>>0)
#define ST_DDC_SFDR_get_CIIDDP(data)                                                 ((0x000000FF&(data))>>0)


#define ST_DDC_SFBSR                                                                 0x18061A44
#define ST_DDC_SFBSR_reg_addr                                                        "0xB8061A44"
#define ST_DDC_SFBSR_reg                                                             0xB8061A44
#define set_ST_DDC_SFBSR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFBSR_reg)=data)
#define get_ST_DDC_SFBSR_reg   (*((volatile unsigned int*) ST_DDC_SFBSR_reg))
#define ST_DDC_SFBSR_inst_adr                                                        "0x0091"
#define ST_DDC_SFBSR_inst                                                            0x0091
#define ST_DDC_SFBSR_CIRWS_2ND_shift                                                 (5)
#define ST_DDC_SFBSR_CIRWS_2ND_mask                                                  (0x00000020)
#define ST_DDC_SFBSR_CIRWS_2ND(data)                                                 (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_CIRWS_2ND_src(data)                                             ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_get_CIRWS_2ND(data)                                             ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_CIRWS_1ST_shift                                                 (4)
#define ST_DDC_SFBSR_CIRWS_1ST_mask                                                  (0x00000010)
#define ST_DDC_SFBSR_CIRWS_1ST(data)                                                 (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_CIRWS_1ST_src(data)                                             ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_get_CIRWS_1ST(data)                                             ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_CIPPT_2ND_shift                                                 (3)
#define ST_DDC_SFBSR_CIPPT_2ND_mask                                                  (0x00000008)
#define ST_DDC_SFBSR_CIPPT_2ND(data)                                                 (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_CIPPT_2ND_src(data)                                             ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_get_CIPPT_2ND(data)                                             ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_CISPT_2ND_shift                                                 (2)
#define ST_DDC_SFBSR_CISPT_2ND_mask                                                  (0x00000004)
#define ST_DDC_SFBSR_CISPT_2ND(data)                                                 (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_CISPT_2ND_src(data)                                             ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_get_CISPT_2ND(data)                                             ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_CIPPT_1ST_shift                                                 (1)
#define ST_DDC_SFBSR_CIPPT_1ST_mask                                                  (0x00000002)
#define ST_DDC_SFBSR_CIPPT_1ST(data)                                                 (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_CIPPT_1ST_src(data)                                             ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_get_CIPPT_1ST(data)                                             ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_CISPT_1ST_shift                                                 (0)
#define ST_DDC_SFBSR_CISPT_1ST_mask                                                  (0x00000001)
#define ST_DDC_SFBSR_CISPT_1ST(data)                                                 (0x00000001&((data)<<0))
#define ST_DDC_SFBSR_CISPT_1ST_src(data)                                             ((0x00000001&(data))>>0)
#define ST_DDC_SFBSR_get_CISPT_1ST(data)                                             ((0x00000001&(data))>>0)


#define ST_DDC_SFIBLR                                                                0x18061A48
#define ST_DDC_SFIBLR_reg_addr                                                       "0xB8061A48"
#define ST_DDC_SFIBLR_reg                                                            0xB8061A48
#define set_ST_DDC_SFIBLR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFIBLR_reg)=data)
#define get_ST_DDC_SFIBLR_reg   (*((volatile unsigned int*) ST_DDC_SFIBLR_reg))
#define ST_DDC_SFIBLR_inst_adr                                                       "0x0092"
#define ST_DDC_SFIBLR_inst                                                           0x0092
#define ST_DDC_SFIBLR_FFDI_DLEN_shift                                                (0)
#define ST_DDC_SFIBLR_FFDI_DLEN_mask                                                 (0x0000001F)
#define ST_DDC_SFIBLR_FFDI_DLEN(data)                                                (0x0000001F&((data)<<0))
#define ST_DDC_SFIBLR_FFDI_DLEN_src(data)                                            ((0x0000001F&(data))>>0)
#define ST_DDC_SFIBLR_get_FFDI_DLEN(data)                                            ((0x0000001F&(data))>>0)


#define ST_DDC_SFIBRWPR                                                              0x18061A4C
#define ST_DDC_SFIBRWPR_reg_addr                                                     "0xB8061A4C"
#define ST_DDC_SFIBRWPR_reg                                                          0xB8061A4C
#define set_ST_DDC_SFIBRWPR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFIBRWPR_reg)=data)
#define get_ST_DDC_SFIBRWPR_reg   (*((volatile unsigned int*) ST_DDC_SFIBRWPR_reg))
#define ST_DDC_SFIBRWPR_inst_adr                                                     "0x0093"
#define ST_DDC_SFIBRWPR_inst                                                         0x0093
#define ST_DDC_SFIBRWPR_DIFF_WPT_shift                                               (4)
#define ST_DDC_SFIBRWPR_DIFF_WPT_mask                                                (0x000000F0)
#define ST_DDC_SFIBRWPR_DIFF_WPT(data)                                               (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_DIFF_WPT_src(data)                                           ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_get_DIFF_WPT(data)                                           ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_DIFF_RPT_shift                                               (0)
#define ST_DDC_SFIBRWPR_DIFF_RPT_mask                                                (0x0000000F)
#define ST_DDC_SFIBRWPR_DIFF_RPT(data)                                               (0x0000000F&((data)<<0))
#define ST_DDC_SFIBRWPR_DIFF_RPT_src(data)                                           ((0x0000000F&(data))>>0)
#define ST_DDC_SFIBRWPR_get_DIFF_RPT(data)                                           ((0x0000000F&(data))>>0)


#define ST_DDC_SFIBSWPR                                                              0x18061A50
#define ST_DDC_SFIBSWPR_reg_addr                                                     "0xB8061A50"
#define ST_DDC_SFIBSWPR_reg                                                          0xB8061A50
#define set_ST_DDC_SFIBSWPR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFIBSWPR_reg)=data)
#define get_ST_DDC_SFIBSWPR_reg   (*((volatile unsigned int*) ST_DDC_SFIBSWPR_reg))
#define ST_DDC_SFIBSWPR_inst_adr                                                     "0x0094"
#define ST_DDC_SFIBSWPR_inst                                                         0x0094
#define ST_DDC_SFIBSWPR_DIFFSTOP_PT_shift                                            (0)
#define ST_DDC_SFIBSWPR_DIFFSTOP_PT_mask                                             (0x0000000F)
#define ST_DDC_SFIBSWPR_DIFFSTOP_PT(data)                                            (0x0000000F&((data)<<0))
#define ST_DDC_SFIBSWPR_DIFFSTOP_PT_src(data)                                        ((0x0000000F&(data))>>0)
#define ST_DDC_SFIBSWPR_get_DIFFSTOP_PT(data)                                        ((0x0000000F&(data))>>0)


#define ST_DDC_SFOBSR                                                                0x18061A54
#define ST_DDC_SFOBSR_reg_addr                                                       "0xB8061A54"
#define ST_DDC_SFOBSR_reg                                                            0xB8061A54
#define set_ST_DDC_SFOBSR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFOBSR_reg)=data)
#define get_ST_DDC_SFOBSR_reg   (*((volatile unsigned int*) ST_DDC_SFOBSR_reg))
#define ST_DDC_SFOBSR_inst_adr                                                       "0x0095"
#define ST_DDC_SFOBSR_inst                                                           0x0095
#define ST_DDC_SFOBSR_FFDO_DLEN_shift                                                (0)
#define ST_DDC_SFOBSR_FFDO_DLEN_mask                                                 (0x0000001F)
#define ST_DDC_SFOBSR_FFDO_DLEN(data)                                                (0x0000001F&((data)<<0))
#define ST_DDC_SFOBSR_FFDO_DLEN_src(data)                                            ((0x0000001F&(data))>>0)
#define ST_DDC_SFOBSR_get_FFDO_DLEN(data)                                            ((0x0000001F&(data))>>0)


#define ST_DDC_SFOBRWPR                                                              0x18061A58
#define ST_DDC_SFOBRWPR_reg_addr                                                     "0xB8061A58"
#define ST_DDC_SFOBRWPR_reg                                                          0xB8061A58
#define set_ST_DDC_SFOBRWPR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFOBRWPR_reg)=data)
#define get_ST_DDC_SFOBRWPR_reg   (*((volatile unsigned int*) ST_DDC_SFOBRWPR_reg))
#define ST_DDC_SFOBRWPR_inst_adr                                                     "0x0096"
#define ST_DDC_SFOBRWPR_inst                                                         0x0096
#define ST_DDC_SFOBRWPR_DOFF_WPT_shift                                               (4)
#define ST_DDC_SFOBRWPR_DOFF_WPT_mask                                                (0x000000F0)
#define ST_DDC_SFOBRWPR_DOFF_WPT(data)                                               (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_DOFF_WPT_src(data)                                           ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_get_DOFF_WPT(data)                                           ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_DOFF_RPT_shift                                               (0)
#define ST_DDC_SFOBRWPR_DOFF_RPT_mask                                                (0x0000000F)
#define ST_DDC_SFOBRWPR_DOFF_RPT(data)                                               (0x0000000F&((data)<<0))
#define ST_DDC_SFOBRWPR_DOFF_RPT_src(data)                                           ((0x0000000F&(data))>>0)
#define ST_DDC_SFOBRWPR_get_DOFF_RPT(data)                                           ((0x0000000F&(data))>>0)


#define ST_DDC_SFSR                                                                  0x18061A5C
#define ST_DDC_SFSR_reg_addr                                                         "0xB8061A5C"
#define ST_DDC_SFSR_reg                                                              0xB8061A5C
#define set_ST_DDC_SFSR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFSR_reg)=data)
#define get_ST_DDC_SFSR_reg   (*((volatile unsigned int*) ST_DDC_SFSR_reg))
#define ST_DDC_SFSR_inst_adr                                                         "0x0097"
#define ST_DDC_SFSR_inst                                                             0x0097
#define ST_DDC_SFSR_FFDOUF_ST_shift                                                  (7)
#define ST_DDC_SFSR_FFDOUF_ST_mask                                                   (0x00000080)
#define ST_DDC_SFSR_FFDOUF_ST(data)                                                  (0x00000080&((data)<<7))
#define ST_DDC_SFSR_FFDOUF_ST_src(data)                                              ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_get_FFDOUF_ST(data)                                              ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_FFDIOF_ST_shift                                                  (6)
#define ST_DDC_SFSR_FFDIOF_ST_mask                                                   (0x00000040)
#define ST_DDC_SFSR_FFDIOF_ST(data)                                                  (0x00000040&((data)<<6))
#define ST_DDC_SFSR_FFDIOF_ST_src(data)                                              ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_get_FFDIOF_ST(data)                                              ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_FFDONF_ST_shift                                                  (5)
#define ST_DDC_SFSR_FFDONF_ST_mask                                                   (0x00000020)
#define ST_DDC_SFSR_FFDONF_ST(data)                                                  (0x00000020&((data)<<5))
#define ST_DDC_SFSR_FFDONF_ST_src(data)                                              ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_get_FFDONF_ST(data)                                              ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_FFDOET_ST_shift                                                  (4)
#define ST_DDC_SFSR_FFDOET_ST_mask                                                   (0x00000010)
#define ST_DDC_SFSR_FFDOET_ST(data)                                                  (0x00000010&((data)<<4))
#define ST_DDC_SFSR_FFDOET_ST_src(data)                                              ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_get_FFDOET_ST(data)                                              ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_FFDIFU_ST_shift                                                  (3)
#define ST_DDC_SFSR_FFDIFU_ST_mask                                                   (0x00000008)
#define ST_DDC_SFSR_FFDIFU_ST(data)                                                  (0x00000008&((data)<<3))
#define ST_DDC_SFSR_FFDIFU_ST_src(data)                                              ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_get_FFDIFU_ST(data)                                              ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_FFDINE_ST_shift                                                  (2)
#define ST_DDC_SFSR_FFDINE_ST_mask                                                   (0x00000004)
#define ST_DDC_SFSR_FFDINE_ST(data)                                                  (0x00000004&((data)<<2))
#define ST_DDC_SFSR_FFDINE_ST_src(data)                                              ((0x00000004&(data))>>2)
#define ST_DDC_SFSR_get_FFDINE_ST(data)                                              ((0x00000004&(data))>>2)


#define ST_DDC_SFIR                                                                  0x18061A60
#define ST_DDC_SFIR_reg_addr                                                         "0xB8061A60"
#define ST_DDC_SFIR_reg                                                              0xB8061A60
#define set_ST_DDC_SFIR_reg(data)   (*((volatile unsigned int*) ST_DDC_SFIR_reg)=data)
#define get_ST_DDC_SFIR_reg   (*((volatile unsigned int*) ST_DDC_SFIR_reg))
#define ST_DDC_SFIR_inst_adr                                                         "0x0098"
#define ST_DDC_SFIR_inst                                                             0x0098
#define ST_DDC_SFIR_FFDOUF_IE_shift                                                  (7)
#define ST_DDC_SFIR_FFDOUF_IE_mask                                                   (0x00000080)
#define ST_DDC_SFIR_FFDOUF_IE(data)                                                  (0x00000080&((data)<<7))
#define ST_DDC_SFIR_FFDOUF_IE_src(data)                                              ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_get_FFDOUF_IE(data)                                              ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_FFDIOF_IE_shift                                                  (6)
#define ST_DDC_SFIR_FFDIOF_IE_mask                                                   (0x00000040)
#define ST_DDC_SFIR_FFDIOF_IE(data)                                                  (0x00000040&((data)<<6))
#define ST_DDC_SFIR_FFDIOF_IE_src(data)                                              ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_get_FFDIOF_IE(data)                                              ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_FFDONF_IE_shift                                                  (5)
#define ST_DDC_SFIR_FFDONF_IE_mask                                                   (0x00000020)
#define ST_DDC_SFIR_FFDONF_IE(data)                                                  (0x00000020&((data)<<5))
#define ST_DDC_SFIR_FFDONF_IE_src(data)                                              ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_get_FFDONF_IE(data)                                              ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_FFDOET_IE_shift                                                  (4)
#define ST_DDC_SFIR_FFDOET_IE_mask                                                   (0x00000010)
#define ST_DDC_SFIR_FFDOET_IE(data)                                                  (0x00000010&((data)<<4))
#define ST_DDC_SFIR_FFDOET_IE_src(data)                                              ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_get_FFDOET_IE(data)                                              ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_FFDIFU_IE_shift                                                  (3)
#define ST_DDC_SFIR_FFDIFU_IE_mask                                                   (0x00000008)
#define ST_DDC_SFIR_FFDIFU_IE(data)                                                  (0x00000008&((data)<<3))
#define ST_DDC_SFIR_FFDIFU_IE_src(data)                                              ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_get_FFDIFU_IE(data)                                              ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_FFDINE_IE_shift                                                  (2)
#define ST_DDC_SFIR_FFDINE_IE_mask                                                   (0x00000004)
#define ST_DDC_SFIR_FFDINE_IE(data)                                                  (0x00000004&((data)<<2))
#define ST_DDC_SFIR_FFDINE_IE_src(data)                                              ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_get_FFDINE_IE(data)                                              ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_CIPPT_IE_shift                                                   (1)
#define ST_DDC_SFIR_CIPPT_IE_mask                                                    (0x00000002)
#define ST_DDC_SFIR_CIPPT_IE(data)                                                   (0x00000002&((data)<<1))
#define ST_DDC_SFIR_CIPPT_IE_src(data)                                               ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_get_CIPPT_IE(data)                                               ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_CISPT_IE_shift                                                   (0)
#define ST_DDC_SFIR_CISPT_IE_mask                                                    (0x00000001)
#define ST_DDC_SFIR_CISPT_IE(data)                                                   (0x00000001&((data)<<0))
#define ST_DDC_SFIR_CISPT_IE_src(data)                                               ((0x00000001&(data))>>0)
#define ST_DDC_SFIR_get_CISPT_IE(data)                                               ((0x00000001&(data))>>0)


#define ST_DDC_FSMS                                                                  0x18061A64
#define ST_DDC_FSMS_reg_addr                                                         "0xB8061A64"
#define ST_DDC_FSMS_reg                                                              0xB8061A64
#define set_ST_DDC_FSMS_reg(data)   (*((volatile unsigned int*) ST_DDC_FSMS_reg)=data)
#define get_ST_DDC_FSMS_reg   (*((volatile unsigned int*) ST_DDC_FSMS_reg))
#define ST_DDC_FSMS_inst_adr                                                         "0x0099"
#define ST_DDC_FSMS_inst                                                             0x0099
#define ST_DDC_FSMS_CMDFSM_ST_shift                                                  (0)
#define ST_DDC_FSMS_CMDFSM_ST_mask                                                   (0x000000FF)
#define ST_DDC_FSMS_CMDFSM_ST(data)                                                  (0x000000FF&((data)<<0))
#define ST_DDC_FSMS_CMDFSM_ST_src(data)                                              ((0x000000FF&(data))>>0)
#define ST_DDC_FSMS_get_CMDFSM_ST(data)                                              ((0x000000FF&(data))>>0)


#define ST_DDC_DUMMY                                                                 0x18061A68
#define ST_DDC_DUMMY_reg_addr                                                        "0xB8061A68"
#define ST_DDC_DUMMY_reg                                                             0xB8061A68
#define set_ST_DDC_DUMMY_reg(data)   (*((volatile unsigned int*) ST_DDC_DUMMY_reg)=data)
#define get_ST_DDC_DUMMY_reg   (*((volatile unsigned int*) ST_DDC_DUMMY_reg))
#define ST_DDC_DUMMY_inst_adr                                                        "0x009A"
#define ST_DDC_DUMMY_inst                                                            0x009A
#define ST_DDC_DUMMY_Dummy_shift                                                     (0)
#define ST_DDC_DUMMY_Dummy_mask                                                      (0x000000FF)
#define ST_DDC_DUMMY_Dummy(data)                                                     (0x000000FF&((data)<<0))
#define ST_DDC_DUMMY_Dummy_src(data)                                                 ((0x000000FF&(data))>>0)
#define ST_DDC_DUMMY_get_Dummy(data)                                                 ((0x000000FF&(data))>>0)


#define ST_DDC_EDID_SRAM_READ_IRQ_EN                                                 0x18061A70
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_reg_addr                                        "0xB8061A70"
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_reg                                             0xB8061A70
#define set_ST_DDC_EDID_SRAM_READ_IRQ_EN_reg(data)   (*((volatile unsigned int*) ST_DDC_EDID_SRAM_READ_IRQ_EN_reg)=data)
#define get_ST_DDC_EDID_SRAM_READ_IRQ_EN_reg   (*((volatile unsigned int*) ST_DDC_EDID_SRAM_READ_IRQ_EN_reg))
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_inst_adr                                        "0x009C"
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_inst                                            0x009C
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_START_IRQ_EN_shift                              (1)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_START_IRQ_EN_mask                               (0x00000002)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_START_IRQ_EN(data)                              (0x00000002&((data)<<1))
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_START_IRQ_EN_src(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_get_START_IRQ_EN(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_STOP_IRQ_EN_shift                               (0)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_STOP_IRQ_EN_mask                                (0x00000001)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_STOP_IRQ_EN(data)                               (0x00000001&((data)<<0))
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_STOP_IRQ_EN_src(data)                           ((0x00000001&(data))>>0)
#define ST_DDC_EDID_SRAM_READ_IRQ_EN_get_STOP_IRQ_EN(data)                           ((0x00000001&(data))>>0)


#define ST_DDC_EDID_SRAM_READ_AUX                                                    0x18061A74
#define ST_DDC_EDID_SRAM_READ_AUX_reg_addr                                           "0xB8061A74"
#define ST_DDC_EDID_SRAM_READ_AUX_reg                                                0xB8061A74
#define set_ST_DDC_EDID_SRAM_READ_AUX_reg(data)   (*((volatile unsigned int*) ST_DDC_EDID_SRAM_READ_AUX_reg)=data)
#define get_ST_DDC_EDID_SRAM_READ_AUX_reg   (*((volatile unsigned int*) ST_DDC_EDID_SRAM_READ_AUX_reg))
#define ST_DDC_EDID_SRAM_READ_AUX_inst_adr                                           "0x009D"
#define ST_DDC_EDID_SRAM_READ_AUX_inst                                               0x009D
#define ST_DDC_EDID_SRAM_READ_AUX_START_shift                                        (1)
#define ST_DDC_EDID_SRAM_READ_AUX_START_mask                                         (0x00000002)
#define ST_DDC_EDID_SRAM_READ_AUX_START(data)                                        (0x00000002&((data)<<1))
#define ST_DDC_EDID_SRAM_READ_AUX_START_src(data)                                    ((0x00000002&(data))>>1)
#define ST_DDC_EDID_SRAM_READ_AUX_get_START(data)                                    ((0x00000002&(data))>>1)
#define ST_DDC_EDID_SRAM_READ_AUX_STOP_shift                                         (0)
#define ST_DDC_EDID_SRAM_READ_AUX_STOP_mask                                          (0x00000001)
#define ST_DDC_EDID_SRAM_READ_AUX_STOP(data)                                         (0x00000001&((data)<<0))
#define ST_DDC_EDID_SRAM_READ_AUX_STOP_src(data)                                     ((0x00000001&(data))>>0)
#define ST_DDC_EDID_SRAM_READ_AUX_get_STOP(data)                                     ((0x00000001&(data))>>0)


#define ST_DDC_BIST_MODE                                                             0x18061A78
#define ST_DDC_BIST_MODE_reg_addr                                                    "0xB8061A78"
#define ST_DDC_BIST_MODE_reg                                                         0xB8061A78
#define set_ST_DDC_BIST_MODE_reg(data)   (*((volatile unsigned int*) ST_DDC_BIST_MODE_reg)=data)
#define get_ST_DDC_BIST_MODE_reg   (*((volatile unsigned int*) ST_DDC_BIST_MODE_reg))
#define ST_DDC_BIST_MODE_inst_adr                                                    "0x009E"
#define ST_DDC_BIST_MODE_inst                                                        0x009E
#define ST_DDC_BIST_MODE_DDC_BIST_MODE_shift                                         (0)
#define ST_DDC_BIST_MODE_DDC_BIST_MODE_mask                                          (0x00000001)
#define ST_DDC_BIST_MODE_DDC_BIST_MODE(data)                                         (0x00000001&((data)<<0))
#define ST_DDC_BIST_MODE_DDC_BIST_MODE_src(data)                                     ((0x00000001&(data))>>0)
#define ST_DDC_BIST_MODE_get_DDC_BIST_MODE(data)                                     ((0x00000001&(data))>>0)


#define ST_DDC_BIST_DONE                                                             0x18061A7C
#define ST_DDC_BIST_DONE_reg_addr                                                    "0xB8061A7C"
#define ST_DDC_BIST_DONE_reg                                                         0xB8061A7C
#define set_ST_DDC_BIST_DONE_reg(data)   (*((volatile unsigned int*) ST_DDC_BIST_DONE_reg)=data)
#define get_ST_DDC_BIST_DONE_reg   (*((volatile unsigned int*) ST_DDC_BIST_DONE_reg))
#define ST_DDC_BIST_DONE_inst_adr                                                    "0x009F"
#define ST_DDC_BIST_DONE_inst                                                        0x009F
#define ST_DDC_BIST_DONE_DDC_BIST_DONE_shift                                         (0)
#define ST_DDC_BIST_DONE_DDC_BIST_DONE_mask                                          (0x00000001)
#define ST_DDC_BIST_DONE_DDC_BIST_DONE(data)                                         (0x00000001&((data)<<0))
#define ST_DDC_BIST_DONE_DDC_BIST_DONE_src(data)                                     ((0x00000001&(data))>>0)
#define ST_DDC_BIST_DONE_get_DDC_BIST_DONE(data)                                     ((0x00000001&(data))>>0)


#define ST_DDC_BIST_FAIL                                                             0x18061A80
#define ST_DDC_BIST_FAIL_reg_addr                                                    "0xB8061A80"
#define ST_DDC_BIST_FAIL_reg                                                         0xB8061A80
#define set_ST_DDC_BIST_FAIL_reg(data)   (*((volatile unsigned int*) ST_DDC_BIST_FAIL_reg)=data)
#define get_ST_DDC_BIST_FAIL_reg   (*((volatile unsigned int*) ST_DDC_BIST_FAIL_reg))
#define ST_DDC_BIST_FAIL_inst_adr                                                    "0x00A0"
#define ST_DDC_BIST_FAIL_inst                                                        0x00A0
#define ST_DDC_BIST_FAIL_DDC_BIST_FAIL_shift                                         (0)
#define ST_DDC_BIST_FAIL_DDC_BIST_FAIL_mask                                          (0x00000001)
#define ST_DDC_BIST_FAIL_DDC_BIST_FAIL(data)                                         (0x00000001&((data)<<0))
#define ST_DDC_BIST_FAIL_DDC_BIST_FAIL_src(data)                                     ((0x00000001&(data))>>0)
#define ST_DDC_BIST_FAIL_get_DDC_BIST_FAIL(data)                                     ((0x00000001&(data))>>0)


#define ST_DDC_DRF_MODE                                                              0x18061A84
#define ST_DDC_DRF_MODE_reg_addr                                                     "0xB8061A84"
#define ST_DDC_DRF_MODE_reg                                                          0xB8061A84
#define set_ST_DDC_DRF_MODE_reg(data)   (*((volatile unsigned int*) ST_DDC_DRF_MODE_reg)=data)
#define get_ST_DDC_DRF_MODE_reg   (*((volatile unsigned int*) ST_DDC_DRF_MODE_reg))
#define ST_DDC_DRF_MODE_inst_adr                                                     "0x00A1"
#define ST_DDC_DRF_MODE_inst                                                         0x00A1
#define ST_DDC_DRF_MODE_DDC_DRF_MODE_shift                                           (0)
#define ST_DDC_DRF_MODE_DDC_DRF_MODE_mask                                            (0x00000001)
#define ST_DDC_DRF_MODE_DDC_DRF_MODE(data)                                           (0x00000001&((data)<<0))
#define ST_DDC_DRF_MODE_DDC_DRF_MODE_src(data)                                       ((0x00000001&(data))>>0)
#define ST_DDC_DRF_MODE_get_DDC_DRF_MODE(data)                                       ((0x00000001&(data))>>0)


#define ST_DDC_DRF_RESUME                                                            0x18061A88
#define ST_DDC_DRF_RESUME_reg_addr                                                   "0xB8061A88"
#define ST_DDC_DRF_RESUME_reg                                                        0xB8061A88
#define set_ST_DDC_DRF_RESUME_reg(data)   (*((volatile unsigned int*) ST_DDC_DRF_RESUME_reg)=data)
#define get_ST_DDC_DRF_RESUME_reg   (*((volatile unsigned int*) ST_DDC_DRF_RESUME_reg))
#define ST_DDC_DRF_RESUME_inst_adr                                                   "0x00A2"
#define ST_DDC_DRF_RESUME_inst                                                       0x00A2
#define ST_DDC_DRF_RESUME_DDC_DRF_RESUME_shift                                       (0)
#define ST_DDC_DRF_RESUME_DDC_DRF_RESUME_mask                                        (0x00000001)
#define ST_DDC_DRF_RESUME_DDC_DRF_RESUME(data)                                       (0x00000001&((data)<<0))
#define ST_DDC_DRF_RESUME_DDC_DRF_RESUME_src(data)                                   ((0x00000001&(data))>>0)
#define ST_DDC_DRF_RESUME_get_DDC_DRF_RESUME(data)                                   ((0x00000001&(data))>>0)


#define ST_DDC_DRF_DONE                                                              0x18061A8C
#define ST_DDC_DRF_DONE_reg_addr                                                     "0xB8061A8C"
#define ST_DDC_DRF_DONE_reg                                                          0xB8061A8C
#define set_ST_DDC_DRF_DONE_reg(data)   (*((volatile unsigned int*) ST_DDC_DRF_DONE_reg)=data)
#define get_ST_DDC_DRF_DONE_reg   (*((volatile unsigned int*) ST_DDC_DRF_DONE_reg))
#define ST_DDC_DRF_DONE_inst_adr                                                     "0x00A3"
#define ST_DDC_DRF_DONE_inst                                                         0x00A3
#define ST_DDC_DRF_DONE_DDC_DRF_DONE_shift                                           (0)
#define ST_DDC_DRF_DONE_DDC_DRF_DONE_mask                                            (0x00000001)
#define ST_DDC_DRF_DONE_DDC_DRF_DONE(data)                                           (0x00000001&((data)<<0))
#define ST_DDC_DRF_DONE_DDC_DRF_DONE_src(data)                                       ((0x00000001&(data))>>0)
#define ST_DDC_DRF_DONE_get_DDC_DRF_DONE(data)                                       ((0x00000001&(data))>>0)


#define ST_DDC_DRF_PAUSE                                                             0x18061A90
#define ST_DDC_DRF_PAUSE_reg_addr                                                    "0xB8061A90"
#define ST_DDC_DRF_PAUSE_reg                                                         0xB8061A90
#define set_ST_DDC_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) ST_DDC_DRF_PAUSE_reg)=data)
#define get_ST_DDC_DRF_PAUSE_reg   (*((volatile unsigned int*) ST_DDC_DRF_PAUSE_reg))
#define ST_DDC_DRF_PAUSE_inst_adr                                                    "0x00A4"
#define ST_DDC_DRF_PAUSE_inst                                                        0x00A4
#define ST_DDC_DRF_PAUSE_DDC_DRF_PAUSE_shift                                         (0)
#define ST_DDC_DRF_PAUSE_DDC_DRF_PAUSE_mask                                          (0x00000001)
#define ST_DDC_DRF_PAUSE_DDC_DRF_PAUSE(data)                                         (0x00000001&((data)<<0))
#define ST_DDC_DRF_PAUSE_DDC_DRF_PAUSE_src(data)                                     ((0x00000001&(data))>>0)
#define ST_DDC_DRF_PAUSE_get_DDC_DRF_PAUSE(data)                                     ((0x00000001&(data))>>0)


#define ST_DDC_DRF_FAIL                                                              0x18061A94
#define ST_DDC_DRF_FAIL_reg_addr                                                     "0xB8061A94"
#define ST_DDC_DRF_FAIL_reg                                                          0xB8061A94
#define set_ST_DDC_DRF_FAIL_reg(data)   (*((volatile unsigned int*) ST_DDC_DRF_FAIL_reg)=data)
#define get_ST_DDC_DRF_FAIL_reg   (*((volatile unsigned int*) ST_DDC_DRF_FAIL_reg))
#define ST_DDC_DRF_FAIL_inst_adr                                                     "0x00A5"
#define ST_DDC_DRF_FAIL_inst                                                         0x00A5
#define ST_DDC_DRF_FAIL_DDC_DRF_FAIL_shift                                           (0)
#define ST_DDC_DRF_FAIL_DDC_DRF_FAIL_mask                                            (0x00000001)
#define ST_DDC_DRF_FAIL_DDC_DRF_FAIL(data)                                           (0x00000001&((data)<<0))
#define ST_DDC_DRF_FAIL_DDC_DRF_FAIL_src(data)                                       ((0x00000001&(data))>>0)
#define ST_DDC_DRF_FAIL_get_DDC_DRF_FAIL(data)                                       ((0x00000001&(data))>>0)


#define RTCSEC                                                                       0x18061700
#define RTCSEC_reg_addr                                                              "0xB8061700"
#define RTCSEC_reg                                                                   0xB8061700
#define set_RTCSEC_reg(data)   (*((volatile unsigned int*) RTCSEC_reg)=data)
#define get_RTCSEC_reg   (*((volatile unsigned int*) RTCSEC_reg))
#define RTCSEC_inst_adr                                                              "0x00C0"
#define RTCSEC_inst                                                                  0x00C0
#define RTCSEC_RTCSEC_shift                                                          (0)
#define RTCSEC_RTCSEC_mask                                                           (0x0000007F)
#define RTCSEC_RTCSEC(data)                                                          (0x0000007F&((data)<<0))
#define RTCSEC_RTCSEC_src(data)                                                      ((0x0000007F&(data))>>0)
#define RTCSEC_get_RTCSEC(data)                                                      ((0x0000007F&(data))>>0)


#define RTCMIN                                                                       0x18061704
#define RTCMIN_reg_addr                                                              "0xB8061704"
#define RTCMIN_reg                                                                   0xB8061704
#define set_RTCMIN_reg(data)   (*((volatile unsigned int*) RTCMIN_reg)=data)
#define get_RTCMIN_reg   (*((volatile unsigned int*) RTCMIN_reg))
#define RTCMIN_inst_adr                                                              "0x00C1"
#define RTCMIN_inst                                                                  0x00C1
#define RTCMIN_RTCMIN_shift                                                          (0)
#define RTCMIN_RTCMIN_mask                                                           (0x0000003F)
#define RTCMIN_RTCMIN(data)                                                          (0x0000003F&((data)<<0))
#define RTCMIN_RTCMIN_src(data)                                                      ((0x0000003F&(data))>>0)
#define RTCMIN_get_RTCMIN(data)                                                      ((0x0000003F&(data))>>0)


#define RTCHR                                                                        0x18061708
#define RTCHR_reg_addr                                                               "0xB8061708"
#define RTCHR_reg                                                                    0xB8061708
#define set_RTCHR_reg(data)   (*((volatile unsigned int*) RTCHR_reg)=data)
#define get_RTCHR_reg   (*((volatile unsigned int*) RTCHR_reg))
#define RTCHR_inst_adr                                                               "0x00C2"
#define RTCHR_inst                                                                   0x00C2
#define RTCHR_RTCHR_shift                                                            (0)
#define RTCHR_RTCHR_mask                                                             (0x0000001F)
#define RTCHR_RTCHR(data)                                                            (0x0000001F&((data)<<0))
#define RTCHR_RTCHR_src(data)                                                        ((0x0000001F&(data))>>0)
#define RTCHR_get_RTCHR(data)                                                        ((0x0000001F&(data))>>0)


#define RTCDATE1                                                                     0x1806170C
#define RTCDATE1_reg_addr                                                            "0xB806170C"
#define RTCDATE1_reg                                                                 0xB806170C
#define set_RTCDATE1_reg(data)   (*((volatile unsigned int*) RTCDATE1_reg)=data)
#define get_RTCDATE1_reg   (*((volatile unsigned int*) RTCDATE1_reg))
#define RTCDATE1_inst_adr                                                            "0x00C3"
#define RTCDATE1_inst                                                                0x00C3
#define RTCDATE1_RTCDATE1_shift                                                      (0)
#define RTCDATE1_RTCDATE1_mask                                                       (0x000000FF)
#define RTCDATE1_RTCDATE1(data)                                                      (0x000000FF&((data)<<0))
#define RTCDATE1_RTCDATE1_src(data)                                                  ((0x000000FF&(data))>>0)
#define RTCDATE1_get_RTCDATE1(data)                                                  ((0x000000FF&(data))>>0)


#define RTCDATE2                                                                     0x18061710
#define RTCDATE2_reg_addr                                                            "0xB8061710"
#define RTCDATE2_reg                                                                 0xB8061710
#define set_RTCDATE2_reg(data)   (*((volatile unsigned int*) RTCDATE2_reg)=data)
#define get_RTCDATE2_reg   (*((volatile unsigned int*) RTCDATE2_reg))
#define RTCDATE2_inst_adr                                                            "0x00C4"
#define RTCDATE2_inst                                                                0x00C4
#define RTCDATE2_RTCDATE2_shift                                                      (0)
#define RTCDATE2_RTCDATE2_mask                                                       (0x0000007F)
#define RTCDATE2_RTCDATE2(data)                                                      (0x0000007F&((data)<<0))
#define RTCDATE2_RTCDATE2_src(data)                                                  ((0x0000007F&(data))>>0)
#define RTCDATE2_get_RTCDATE2(data)                                                  ((0x0000007F&(data))>>0)


#define ALMMIN                                                                       0x18061714
#define ALMMIN_reg_addr                                                              "0xB8061714"
#define ALMMIN_reg                                                                   0xB8061714
#define set_ALMMIN_reg(data)   (*((volatile unsigned int*) ALMMIN_reg)=data)
#define get_ALMMIN_reg   (*((volatile unsigned int*) ALMMIN_reg))
#define ALMMIN_inst_adr                                                              "0x00C5"
#define ALMMIN_inst                                                                  0x00C5
#define ALMMIN_ALMMIN_shift                                                          (0)
#define ALMMIN_ALMMIN_mask                                                           (0x0000003F)
#define ALMMIN_ALMMIN(data)                                                          (0x0000003F&((data)<<0))
#define ALMMIN_ALMMIN_src(data)                                                      ((0x0000003F&(data))>>0)
#define ALMMIN_get_ALMMIN(data)                                                      ((0x0000003F&(data))>>0)


#define ALMHR                                                                        0x18061718
#define ALMHR_reg_addr                                                               "0xB8061718"
#define ALMHR_reg                                                                    0xB8061718
#define set_ALMHR_reg(data)   (*((volatile unsigned int*) ALMHR_reg)=data)
#define get_ALMHR_reg   (*((volatile unsigned int*) ALMHR_reg))
#define ALMHR_inst_adr                                                               "0x00C6"
#define ALMHR_inst                                                                   0x00C6
#define ALMHR_ALMHR_shift                                                            (0)
#define ALMHR_ALMHR_mask                                                             (0x0000001F)
#define ALMHR_ALMHR(data)                                                            (0x0000001F&((data)<<0))
#define ALMHR_ALMHR_src(data)                                                        ((0x0000001F&(data))>>0)
#define ALMHR_get_ALMHR(data)                                                        ((0x0000001F&(data))>>0)


#define ALMDATE1                                                                     0x1806171C
#define ALMDATE1_reg_addr                                                            "0xB806171C"
#define ALMDATE1_reg                                                                 0xB806171C
#define set_ALMDATE1_reg(data)   (*((volatile unsigned int*) ALMDATE1_reg)=data)
#define get_ALMDATE1_reg   (*((volatile unsigned int*) ALMDATE1_reg))
#define ALMDATE1_inst_adr                                                            "0x00C7"
#define ALMDATE1_inst                                                                0x00C7
#define ALMDATE1_ALMDATE1_shift                                                      (0)
#define ALMDATE1_ALMDATE1_mask                                                       (0x000000FF)
#define ALMDATE1_ALMDATE1(data)                                                      (0x000000FF&((data)<<0))
#define ALMDATE1_ALMDATE1_src(data)                                                  ((0x000000FF&(data))>>0)
#define ALMDATE1_get_ALMDATE1(data)                                                  ((0x000000FF&(data))>>0)


#define ALMDATE2                                                                     0x18061720
#define ALMDATE2_reg_addr                                                            "0xB8061720"
#define ALMDATE2_reg                                                                 0xB8061720
#define set_ALMDATE2_reg(data)   (*((volatile unsigned int*) ALMDATE2_reg)=data)
#define get_ALMDATE2_reg   (*((volatile unsigned int*) ALMDATE2_reg))
#define ALMDATE2_inst_adr                                                            "0x00C8"
#define ALMDATE2_inst                                                                0x00C8
#define ALMDATE2_ALMDATE2_shift                                                      (0)
#define ALMDATE2_ALMDATE2_mask                                                       (0x0000007F)
#define ALMDATE2_ALMDATE2(data)                                                      (0x0000007F&((data)<<0))
#define ALMDATE2_ALMDATE2_src(data)                                                  ((0x0000007F&(data))>>0)
#define ALMDATE2_get_ALMDATE2(data)                                                  ((0x0000007F&(data))>>0)


#define RTCSTOP                                                                      0x18061724
#define RTCSTOP_reg_addr                                                             "0xB8061724"
#define RTCSTOP_reg                                                                  0xB8061724
#define set_RTCSTOP_reg(data)   (*((volatile unsigned int*) RTCSTOP_reg)=data)
#define get_RTCSTOP_reg   (*((volatile unsigned int*) RTCSTOP_reg))
#define RTCSTOP_inst_adr                                                             "0x00C9"
#define RTCSTOP_inst                                                                 0x00C9
#define RTCSTOP_27Mclk_en_shift                                                      (3)
#define RTCSTOP_27Mclk_en_mask                                                       (0x00000008)
#define RTCSTOP_27Mclk_en(data)                                                      (0x00000008&((data)<<3))
#define RTCSTOP_27Mclk_en_src(data)                                                  ((0x00000008&(data))>>3)
#define RTCSTOP_get_27Mclk_en(data)                                                  ((0x00000008&(data))>>3)
#define RTCSTOP_VREF_shift                                                           (1)
#define RTCSTOP_VREF_mask                                                            (0x00000006)
#define RTCSTOP_VREF(data)                                                           (0x00000006&((data)<<1))
#define RTCSTOP_VREF_src(data)                                                       ((0x00000006&(data))>>1)
#define RTCSTOP_get_VREF(data)                                                       ((0x00000006&(data))>>1)
#define RTCSTOP_RTCSTOP_shift                                                        (0)
#define RTCSTOP_RTCSTOP_mask                                                         (0x00000001)
#define RTCSTOP_RTCSTOP(data)                                                        (0x00000001&((data)<<0))
#define RTCSTOP_RTCSTOP_src(data)                                                    ((0x00000001&(data))>>0)
#define RTCSTOP_get_RTCSTOP(data)                                                    ((0x00000001&(data))>>0)


#define RTCACR                                                                       0x18061728
#define RTCACR_reg_addr                                                              "0xB8061728"
#define RTCACR_reg                                                                   0xB8061728
#define set_RTCACR_reg(data)   (*((volatile unsigned int*) RTCACR_reg)=data)
#define get_RTCACR_reg   (*((volatile unsigned int*) RTCACR_reg))
#define RTCACR_inst_adr                                                              "0x00CA"
#define RTCACR_inst                                                                  0x00CA
#define RTCACR_RTCPWR_shift                                                          (7)
#define RTCACR_RTCPWR_mask                                                           (0x00000080)
#define RTCACR_RTCPWR(data)                                                          (0x00000080&((data)<<7))
#define RTCACR_RTCPWR_src(data)                                                      ((0x00000080&(data))>>7)
#define RTCACR_get_RTCPWR(data)                                                      ((0x00000080&(data))>>7)
#define RTCACR_CO_shift                                                              (5)
#define RTCACR_CO_mask                                                               (0x00000060)
#define RTCACR_CO(data)                                                              (0x00000060&((data)<<5))
#define RTCACR_CO_src(data)                                                          ((0x00000060&(data))>>5)
#define RTCACR_get_CO(data)                                                          ((0x00000060&(data))>>5)
#define RTCACR_CI_shift                                                              (3)
#define RTCACR_CI_mask                                                               (0x00000018)
#define RTCACR_CI(data)                                                              (0x00000018&((data)<<3))
#define RTCACR_CI_src(data)                                                          ((0x00000018&(data))>>3)
#define RTCACR_get_CI(data)                                                          ((0x00000018&(data))>>3)
#define RTCACR_CLKSEL_shift                                                          (2)
#define RTCACR_CLKSEL_mask                                                           (0x00000004)
#define RTCACR_CLKSEL(data)                                                          (0x00000004&((data)<<2))
#define RTCACR_CLKSEL_src(data)                                                      ((0x00000004&(data))>>2)
#define RTCACR_get_CLKSEL(data)                                                      ((0x00000004&(data))>>2)
#define RTCACR_BC_shift                                                              (0)
#define RTCACR_BC_mask                                                               (0x00000003)
#define RTCACR_BC(data)                                                              (0x00000003&((data)<<0))
#define RTCACR_BC_src(data)                                                          ((0x00000003&(data))>>0)
#define RTCACR_get_BC(data)                                                          ((0x00000003&(data))>>0)


#define RTCEN                                                                        0x1806172C
#define RTCEN_reg_addr                                                               "0xB806172C"
#define RTCEN_reg                                                                    0xB806172C
#define set_RTCEN_reg(data)   (*((volatile unsigned int*) RTCEN_reg)=data)
#define get_RTCEN_reg   (*((volatile unsigned int*) RTCEN_reg))
#define RTCEN_inst_adr                                                               "0x00CB"
#define RTCEN_inst                                                                   0x00CB
#define RTCEN_RTCEN_shift                                                            (0)
#define RTCEN_RTCEN_mask                                                             (0x000000FF)
#define RTCEN_RTCEN(data)                                                            (0x000000FF&((data)<<0))
#define RTCEN_RTCEN_src(data)                                                        ((0x000000FF&(data))>>0)
#define RTCEN_get_RTCEN(data)                                                        ((0x000000FF&(data))>>0)


#define RTCCR                                                                        0x18061730
#define RTCCR_reg_addr                                                               "0xB8061730"
#define RTCCR_reg                                                                    0xB8061730
#define set_RTCCR_reg(data)   (*((volatile unsigned int*) RTCCR_reg)=data)
#define get_RTCCR_reg   (*((volatile unsigned int*) RTCCR_reg))
#define RTCCR_inst_adr                                                               "0x00CC"
#define RTCCR_inst                                                                   0x00CC
#define RTCCR_rtc_alarm_int_status_shift                                             (31)
#define RTCCR_rtc_alarm_int_status_mask                                              (0x80000000)
#define RTCCR_rtc_alarm_int_status(data)                                             (0x80000000&((data)<<31))
#define RTCCR_rtc_alarm_int_status_src(data)                                         ((0x80000000&(data))>>31)
#define RTCCR_get_rtc_alarm_int_status(data)                                         ((0x80000000&(data))>>31)
#define RTCCR_rtc_date_int_status_shift                                              (30)
#define RTCCR_rtc_date_int_status_mask                                               (0x40000000)
#define RTCCR_rtc_date_int_status(data)                                              (0x40000000&((data)<<30))
#define RTCCR_rtc_date_int_status_src(data)                                          ((0x40000000&(data))>>30)
#define RTCCR_get_rtc_date_int_status(data)                                          ((0x40000000&(data))>>30)
#define RTCCR_rtc_hour_int_status_shift                                              (29)
#define RTCCR_rtc_hour_int_status_mask                                               (0x20000000)
#define RTCCR_rtc_hour_int_status(data)                                              (0x20000000&((data)<<29))
#define RTCCR_rtc_hour_int_status_src(data)                                          ((0x20000000&(data))>>29)
#define RTCCR_get_rtc_hour_int_status(data)                                          ((0x20000000&(data))>>29)
#define RTCCR_rtc_min_int_status_shift                                               (28)
#define RTCCR_rtc_min_int_status_mask                                                (0x10000000)
#define RTCCR_rtc_min_int_status(data)                                               (0x10000000&((data)<<28))
#define RTCCR_rtc_min_int_status_src(data)                                           ((0x10000000&(data))>>28)
#define RTCCR_get_rtc_min_int_status(data)                                           ((0x10000000&(data))>>28)
#define RTCCR_rtc_hsec_int_status_shift                                              (27)
#define RTCCR_rtc_hsec_int_status_mask                                               (0x08000000)
#define RTCCR_rtc_hsec_int_status(data)                                              (0x08000000&((data)<<27))
#define RTCCR_rtc_hsec_int_status_src(data)                                          ((0x08000000&(data))>>27)
#define RTCCR_get_rtc_hsec_int_status(data)                                          ((0x08000000&(data))>>27)
#define RTCCR_RTCRST_shift                                                           (6)
#define RTCCR_RTCRST_mask                                                            (0x00000040)
#define RTCCR_RTCRST(data)                                                           (0x00000040&((data)<<6))
#define RTCCR_RTCRST_src(data)                                                       ((0x00000040&(data))>>6)
#define RTCCR_get_RTCRST(data)                                                       ((0x00000040&(data))>>6)
#define RTCCR_ALARMINTE_shift                                                        (4)
#define RTCCR_ALARMINTE_mask                                                         (0x00000010)
#define RTCCR_ALARMINTE(data)                                                        (0x00000010&((data)<<4))
#define RTCCR_ALARMINTE_src(data)                                                    ((0x00000010&(data))>>4)
#define RTCCR_get_ALARMINTE(data)                                                    ((0x00000010&(data))>>4)
#define RTCCR_DAINTE_shift                                                           (3)
#define RTCCR_DAINTE_mask                                                            (0x00000008)
#define RTCCR_DAINTE(data)                                                           (0x00000008&((data)<<3))
#define RTCCR_DAINTE_src(data)                                                       ((0x00000008&(data))>>3)
#define RTCCR_get_DAINTE(data)                                                       ((0x00000008&(data))>>3)
#define RTCCR_HUINTE_shift                                                           (2)
#define RTCCR_HUINTE_mask                                                            (0x00000004)
#define RTCCR_HUINTE(data)                                                           (0x00000004&((data)<<2))
#define RTCCR_HUINTE_src(data)                                                       ((0x00000004&(data))>>2)
#define RTCCR_get_HUINTE(data)                                                       ((0x00000004&(data))>>2)
#define RTCCR_MUINTE_shift                                                           (1)
#define RTCCR_MUINTE_mask                                                            (0x00000002)
#define RTCCR_MUINTE(data)                                                           (0x00000002&((data)<<1))
#define RTCCR_MUINTE_src(data)                                                       ((0x00000002&(data))>>1)
#define RTCCR_get_MUINTE(data)                                                       ((0x00000002&(data))>>1)
#define RTCCR_HSUINTE_shift                                                          (0)
#define RTCCR_HSUINTE_mask                                                           (0x00000001)
#define RTCCR_HSUINTE(data)                                                          (0x00000001&((data)<<0))
#define RTCCR_HSUINTE_src(data)                                                      ((0x00000001&(data))>>0)
#define RTCCR_get_HSUINTE(data)                                                      ((0x00000001&(data))>>0)


#define ISO_TC0TVR                                                                   0x18061800
#define ISO_TC0TVR_reg_addr                                                          "0xB8061800"
#define ISO_TC0TVR_reg                                                               0xB8061800
#define set_ISO_TC0TVR_reg(data)   (*((volatile unsigned int*) ISO_TC0TVR_reg)=data)
#define get_ISO_TC0TVR_reg   (*((volatile unsigned int*) ISO_TC0TVR_reg))
#define ISO_TC0TVR_inst_adr                                                          "0x0000"
#define ISO_TC0TVR_inst                                                              0x0000
#define ISO_TC0TVR_TC0TVR_shift                                                      (0)
#define ISO_TC0TVR_TC0TVR_mask                                                       (0xFFFFFFFF)
#define ISO_TC0TVR_TC0TVR(data)                                                      (0xFFFFFFFF&((data)<<0))
#define ISO_TC0TVR_TC0TVR_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define ISO_TC0TVR_get_TC0TVR(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define ISO_TC0CVR                                                                   0x18061804
#define ISO_TC0CVR_reg_addr                                                          "0xB8061804"
#define ISO_TC0CVR_reg                                                               0xB8061804
#define set_ISO_TC0CVR_reg(data)   (*((volatile unsigned int*) ISO_TC0CVR_reg)=data)
#define get_ISO_TC0CVR_reg   (*((volatile unsigned int*) ISO_TC0CVR_reg))
#define ISO_TC0CVR_inst_adr                                                          "0x0001"
#define ISO_TC0CVR_inst                                                              0x0001
#define ISO_TC0CVR_TC0CVR_shift                                                      (0)
#define ISO_TC0CVR_TC0CVR_mask                                                       (0xFFFFFFFF)
#define ISO_TC0CVR_TC0CVR(data)                                                      (0xFFFFFFFF&((data)<<0))
#define ISO_TC0CVR_TC0CVR_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define ISO_TC0CVR_get_TC0CVR(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define ISO_TC0CR                                                                    0x18061808
#define ISO_TC0CR_reg_addr                                                           "0xB8061808"
#define ISO_TC0CR_reg                                                                0xB8061808
#define set_ISO_TC0CR_reg(data)   (*((volatile unsigned int*) ISO_TC0CR_reg)=data)
#define get_ISO_TC0CR_reg   (*((volatile unsigned int*) ISO_TC0CR_reg))
#define ISO_TC0CR_inst_adr                                                           "0x0002"
#define ISO_TC0CR_inst                                                               0x0002
#define ISO_TC0CR_TC0En_shift                                                        (31)
#define ISO_TC0CR_TC0En_mask                                                         (0x80000000)
#define ISO_TC0CR_TC0En(data)                                                        (0x80000000&((data)<<31))
#define ISO_TC0CR_TC0En_src(data)                                                    ((0x80000000&(data))>>31)
#define ISO_TC0CR_get_TC0En(data)                                                    ((0x80000000&(data))>>31)
#define ISO_TC0CR_TC0Mode_shift                                                      (30)
#define ISO_TC0CR_TC0Mode_mask                                                       (0x40000000)
#define ISO_TC0CR_TC0Mode(data)                                                      (0x40000000&((data)<<30))
#define ISO_TC0CR_TC0Mode_src(data)                                                  ((0x40000000&(data))>>30)
#define ISO_TC0CR_get_TC0Mode(data)                                                  ((0x40000000&(data))>>30)
#define ISO_TC0CR_TC0Pause_shift                                                     (29)
#define ISO_TC0CR_TC0Pause_mask                                                      (0x20000000)
#define ISO_TC0CR_TC0Pause(data)                                                     (0x20000000&((data)<<29))
#define ISO_TC0CR_TC0Pause_src(data)                                                 ((0x20000000&(data))>>29)
#define ISO_TC0CR_get_TC0Pause(data)                                                 ((0x20000000&(data))>>29)
#define ISO_TC0CR_RvdA_shift                                                         (24)
#define ISO_TC0CR_RvdA_mask                                                          (0x1F000000)
#define ISO_TC0CR_RvdA(data)                                                         (0x1F000000&((data)<<24))
#define ISO_TC0CR_RvdA_src(data)                                                     ((0x1F000000&(data))>>24)
#define ISO_TC0CR_get_RvdA(data)                                                     ((0x1F000000&(data))>>24)


#define ISO_TC0ICR                                                                   0x1806180C
#define ISO_TC0ICR_reg_addr                                                          "0xB806180C"
#define ISO_TC0ICR_reg                                                               0xB806180C
#define set_ISO_TC0ICR_reg(data)   (*((volatile unsigned int*) ISO_TC0ICR_reg)=data)
#define get_ISO_TC0ICR_reg   (*((volatile unsigned int*) ISO_TC0ICR_reg))
#define ISO_TC0ICR_inst_adr                                                          "0x0003"
#define ISO_TC0ICR_inst                                                              0x0003
#define ISO_TC0ICR_TC0IE_shift                                                       (31)
#define ISO_TC0ICR_TC0IE_mask                                                        (0x80000000)
#define ISO_TC0ICR_TC0IE(data)                                                       (0x80000000&((data)<<31))
#define ISO_TC0ICR_TC0IE_src(data)                                                   ((0x80000000&(data))>>31)
#define ISO_TC0ICR_get_TC0IE(data)                                                   ((0x80000000&(data))>>31)


#endif
