/**
* @file rbusSfgReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012/7/11
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_SFG_REG_H_
#define _RBUS_SFG_REG_H_

#include "rbusTypes.h"




// SFG Register Address

#define SFG_SFG_ZZ_SHIFT_DBG_CTRL_VADDR            (0xb802d100)
#define SFG_SFG_SWAP_CTRL0_VADDR                   (0xb802d104)
#define SFG_SFG_SWAP_CTRL1_VADDR                   (0xb802d108)
#define SFG_SFG_SWAP_CTRL2_VADDR                   (0xb802d10c)
#define SFG_SFG_CRC_CTRL_VADDR                     (0xb802d110)
#define SFG_SFG_CRC_RESULT_VADDR                   (0xb802d114)
#define SFG_SFG_CRC_R_RESULT_VADDR                 (0xb802d118)
#define SFG_SFG_L_DES_CRC_VADDR                    (0xb802d11c)
#define SFG_SFG_R_DES_CRC_VADDR                    (0xb802d120)
#define SFG_SFG_CRC_ERR_CNT_VADDR                  (0xb802d124)
#define SFG_SFG_FORCE_BG_AT_DIF_VADDR              (0xb802d128)
#define SFG_SFG_DUMMY_CTRL_0_VADDR                 (0xb802d130)
#define SFG_SFG_DUMMY_CTRL_1_VADDR                 (0xb802d134)
#define SFG_SFG_DUMMY_CTRL_2_VADDR                 (0xb802d138)
#define SFG_SFG_DUMMY_CTRL_3_VADDR                 (0xb802d13c)
#define SFG_SFG_CTRL_0_VADDR                       (0xb802d140)
#define SFG_SFG_CTRL_1_VADDR                       (0xb802d144)
#define SFG_SFG_CTRL_2_VADDR                       (0xb802d148)
#define SFG_SFG_CTRL_3_VADDR                       (0xb802d14c)
#define SFG_SFG_CTRL_4_VADDR                       (0xb802d150)
#define SFG_SFG_SEG_START_0_VADDR                  (0xb802d154)
#define SFG_SFG_SEG_START_1_VADDR                  (0xb802d158)
#define SFG_SFG_SEG_START_2_VADDR                  (0xb802d15c)
#define SFG_SFG_SEG_START_3_VADDR                  (0xb802d160)
#define SFG_SFG_CTRL_6_VADDR                       (0xb802d164)
#define SFG_SFG_CTRL_7_VADDR                       (0xb802d168)
#define SFG_SFG_CTRL_8_VADDR                       (0xb802d16c)
#define SFG_SFG_CTRL_9_VADDR                       (0xb802d170)
#define SFG_SFG_CTRL_A_VADDR                       (0xb802d174)
#define SFG_SFG_BISR_RM_VADDR                      (0xb802d178)
#define SFG_SFG_BISR_RME_VADDR                     (0xb802d17c)
#define SFG_SFG_BISR_LS_VADDR                      (0xb802d180)
#define SFG_SFG_BISR_FAIL_VADDR                    (0xb802d184)
#define SFG_SFG_TG_AUTO_1_VADDR                    (0xb802d188)
#define SFG_SFG_TG_AUTO_2_VADDR                    (0xb802d18c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======SFG register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zz_shift_last_sel_odd:2;
        RBus_UInt32  zz_shift_last_sel_even:2;
        RBus_UInt32  zz_shift_1st_sel_odd:2;
        RBus_UInt32  zz_shift_1st_sel_even:2;
        RBus_UInt32  zz_shift_sp_odd:2;
        RBus_UInt32  zz_shift_sp_even:2;
        RBus_UInt32  zz_shift_mode_odd:1;
        RBus_UInt32  zz_shift_mode_even:1;
        RBus_UInt32  dout_pre_rb_swap:1;
        RBus_UInt32  dispd_debug_mode:3;
        RBus_UInt32  dout_mode:2;
        RBus_UInt32  dout_en:1;
        RBus_UInt32  dvs_inv:1;
        RBus_UInt32  dhs_inv:1;
        RBus_UInt32  dden_inv:1;
        RBus_UInt32  daclk_inv:1;
        RBus_UInt32  daclk_en:1;
        RBus_UInt32  dout_rb_swap:1;
        RBus_UInt32  dout_bit_swap:1;
        RBus_UInt32  dout_data_inv:1;
        RBus_UInt32  dclk_dly_sel:3;
    };
}sfg_zz_shift_dbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_mode_switch:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  force_bg_dif_aport:1;
        RBus_UInt32  force_bg_dif_bport:1;
        RBus_UInt32  force_bg_dif_cport:1;
        RBus_UInt32  force_bg_dif_dport:1;
        RBus_UInt32  force_bg_dif_eport:1;
        RBus_UInt32  force_bg_dif_fport:1;
        RBus_UInt32  force_bg_dif_gport:1;
        RBus_UInt32  force_bg_dif_hport:1;
        RBus_UInt32  force_bg_dif_iport:1;
        RBus_UInt32  force_bg_dif_jport:1;
        RBus_UInt32  force_bg_dif_kport:1;
        RBus_UInt32  force_bg_dif_lport:1;
        RBus_UInt32  force_bg_dif_mport:1;
        RBus_UInt32  force_bg_dif_nport:1;
        RBus_UInt32  force_bg_dif_oport:1;
        RBus_UInt32  force_bg_dif_pport:1;
    };
}sfg_swap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_porta:4;
        RBus_UInt32  output_portb:4;
        RBus_UInt32  output_portc:4;
        RBus_UInt32  output_portd:4;
        RBus_UInt32  output_porte:4;
        RBus_UInt32  output_portf:4;
        RBus_UInt32  output_portg:4;
        RBus_UInt32  output_porth:4;
    };
}sfg_swap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_porti:4;
        RBus_UInt32  output_portj:4;
        RBus_UInt32  output_portk:4;
        RBus_UInt32  output_portl:4;
        RBus_UInt32  output_portm:4;
        RBus_UInt32  output_portn:4;
        RBus_UInt32  output_porto:4;
        RBus_UInt32  output_portp:4;
    };
}sfg_swap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sfg_crc_mode:1;
        RBus_UInt32  sfg_crc_l_auto_cmp_en:1;
        RBus_UInt32  sfg_crc_r_auto_cmp_en:1;
        RBus_UInt32  sfg_crc_conti:1;
        RBus_UInt32  sfg_crc_start:1;
    };
}sfg_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_crc_result_0:32;
    };
}sfg_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_crc_result_1:32;
    };
}sfg_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_l_des_crc:32;
    };
}sfg_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_r_des_crc:32;
    };
}sfg_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_l_crc_err_cnt:16;
        RBus_UInt32  sfg_r_crc_err_cnt:16;
    };
}sfg_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_force_bg_dif:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  bg_dif_red:10;
        RBus_UInt32  bg_dif_grn:10;
        RBus_UInt32  bg_dif_blu:10;
    };
}sfg_force_bg_at_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_0_front_dummy_num_odd:2;
        RBus_UInt32  seg_0_back_dummy_num_odd:2;
        RBus_UInt32  seg_0_front_dummy_num_even:2;
        RBus_UInt32  seg_0_back_dummy_num_even:2;
        RBus_UInt32  seg_1_front_dummy_num_odd:2;
        RBus_UInt32  seg_1_back_dummy_num_odd:2;
        RBus_UInt32  seg_1_front_dummy_num_even:2;
        RBus_UInt32  seg_1_back_dummy_num_even:2;
        RBus_UInt32  seg_2_front_dummy_num_odd:2;
        RBus_UInt32  seg_2_back_dummy_num_odd:2;
        RBus_UInt32  seg_2_front_dummy_num_even:2;
        RBus_UInt32  seg_2_back_dummy_num_even:2;
        RBus_UInt32  seg_3_front_dummy_num_odd:2;
        RBus_UInt32  seg_3_back_dummy_num_odd:2;
        RBus_UInt32  seg_3_front_dummy_num_even:2;
        RBus_UInt32  seg_3_back_dummy_num_even:2;
    };
}sfg_dummy_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_4_front_dummy_num_odd:2;
        RBus_UInt32  seg_4_back_dummy_num_odd:2;
        RBus_UInt32  seg_4_front_dummy_num_even:2;
        RBus_UInt32  seg_4_back_dummy_num_even:2;
        RBus_UInt32  seg_5_front_dummy_num_odd:2;
        RBus_UInt32  seg_5_back_dummy_num_odd:2;
        RBus_UInt32  seg_5_front_dummy_num_even:2;
        RBus_UInt32  seg_5_back_dummy_num_even:2;
        RBus_UInt32  seg_6_front_dummy_num_odd:2;
        RBus_UInt32  seg_6_back_dummy_num_odd:2;
        RBus_UInt32  seg_6_front_dummy_num_even:2;
        RBus_UInt32  seg_6_back_dummy_num_even:2;
        RBus_UInt32  seg_7_front_dummy_num_odd:2;
        RBus_UInt32  seg_7_back_dummy_num_odd:2;
        RBus_UInt32  seg_7_front_dummy_num_even:2;
        RBus_UInt32  seg_7_back_dummy_num_even:2;
    };
}sfg_dummy_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_8_front_dummy_num_odd:2;
        RBus_UInt32  seg_8_back_dummy_num_odd:2;
        RBus_UInt32  seg_8_front_dummy_num_even:2;
        RBus_UInt32  seg_8_back_dummy_num_even:2;
        RBus_UInt32  seg_9_front_dummy_num_odd:2;
        RBus_UInt32  seg_9_back_dummy_num_odd:2;
        RBus_UInt32  seg_9_front_dummy_num_even:2;
        RBus_UInt32  seg_9_back_dummy_num_even:2;
        RBus_UInt32  seg_10_front_dummy_num_odd:2;
        RBus_UInt32  seg_10_back_dummy_num_odd:2;
        RBus_UInt32  seg_10_front_dummy_num_even:2;
        RBus_UInt32  seg_10_back_dummy_num_even:2;
        RBus_UInt32  seg_11_front_dummy_num_odd:2;
        RBus_UInt32  seg_11_back_dummy_num_odd:2;
        RBus_UInt32  seg_11_front_dummy_num_even:2;
        RBus_UInt32  seg_11_back_dummy_num_even:2;
    };
}sfg_dummy_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_12_front_dummy_num_odd:2;
        RBus_UInt32  seg_12_back_dummy_num_odd:2;
        RBus_UInt32  seg_12_front_dummy_num_even:2;
        RBus_UInt32  seg_12_back_dummy_num_even:2;
        RBus_UInt32  seg_13_front_dummy_num_odd:2;
        RBus_UInt32  seg_13_back_dummy_num_odd:2;
        RBus_UInt32  seg_13_front_dummy_num_even:2;
        RBus_UInt32  seg_13_back_dummy_num_even:2;
        RBus_UInt32  seg_14_front_dummy_num_odd:2;
        RBus_UInt32  seg_14_back_dummy_num_odd:2;
        RBus_UInt32  seg_14_front_dummy_num_even:2;
        RBus_UInt32  seg_14_back_dummy_num_even:2;
        RBus_UInt32  seg_15_front_dummy_num_odd:2;
        RBus_UInt32  seg_15_back_dummy_num_odd:2;
        RBus_UInt32  seg_15_front_dummy_num_even:2;
        RBus_UInt32  seg_15_back_dummy_num_even:2;
    };
}sfg_dummy_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d140_31_26:6;
        RBus_UInt32  mask_one_eye_black_en:1;
        RBus_UInt32  mask_one_eye_black_left:1;
        RBus_UInt32  dummy_pixel_shift_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  req_epi_mode:1;
        RBus_UInt32  pif_2d2g_sw_line01:1;
        RBus_UInt32  pif_2d2g_sw_line23:1;
        RBus_UInt32  pif_2d2g_en:1;
        RBus_UInt32  h_flip_en:1;
        RBus_UInt32  seg_num:4;
        RBus_UInt32  port_num:4;
    };
}sfg_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg0_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg1_start:13;
    };
}sfg_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg2_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg3_start:13;
    };
}sfg_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg4_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg5_start:13;
    };
}sfg_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg6_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg7_start:13;
    };
}sfg_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg8_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg9_start:13;
    };
}sfg_seg_start_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg10_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg11_start:13;
    };
}sfg_seg_start_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg12_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg13_start:13;
    };
}sfg_seg_start_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seg14_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg15_start:13;
    };
}sfg_seg_start_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypass_mode:1;
        RBus_UInt32  tg_auto_cfg:1;
        RBus_UInt32  pif_2d2g_hs_sel:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  debug_sel:3;
    };
}sfg_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hsync_width:8;
        RBus_UInt32  hsync_delay:16;
    };
}sfg_ctrl_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vsync_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  vsync_start:8;
    };
}sfg_ctrl_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_dh_den_sta:16;
        RBus_UInt32  req_start:16;
    };
}sfg_ctrl_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_line_length:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  hsync_threshold:16;
    };
}sfg_ctrl_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sfg_sram3_rm:4;
        RBus_UInt32  sfg_sram2_rm:4;
        RBus_UInt32  sfg_sram1_rm:4;
        RBus_UInt32  sfg_sram0_rm:4;
    };
}sfg_bisr_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sfg_sram3_rme:1;
        RBus_UInt32  sfg_sram2_rme:1;
        RBus_UInt32  sfg_sram1_rme:1;
        RBus_UInt32  sfg_sram0_rme:1;
    };
}sfg_bisr_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sfg_sram3_ls:1;
        RBus_UInt32  sfg_sram2_ls:1;
        RBus_UInt32  sfg_sram1_ls:1;
        RBus_UInt32  sfg_sram0_ls:1;
    };
}sfg_bisr_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_bisr_repaired:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  sfg_drf_fail_3:1;
        RBus_UInt32  sfg_drf_fail_2:1;
        RBus_UInt32  sfg_drf_fail_1:1;
        RBus_UInt32  sfg_drf_fail_0:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  sfg_bisr_fail_3:1;
        RBus_UInt32  sfg_bisr_fail_2:1;
        RBus_UInt32  sfg_bisr_fail_1:1;
        RBus_UInt32  sfg_bisr_fail_0:1;
    };
}sfg_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_delay_auto:16;
        RBus_UInt32  req_start_auto:16;
    };
}sfg_tg_auto_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_2d2g_hs_sel_auto:1;
        RBus_UInt32  vsync_start_auto:8;
        RBus_UInt32  vsync_end_auto:8;
        RBus_UInt32  hsync_width_auto:8;
    };
}sfg_tg_auto_2_RBUS;





#else //apply LITTLE_ENDIAN


//======SFG register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_dly_sel:3;
        RBus_UInt32  dout_data_inv:1;
        RBus_UInt32  dout_bit_swap:1;
        RBus_UInt32  dout_rb_swap:1;
        RBus_UInt32  daclk_en:1;
        RBus_UInt32  daclk_inv:1;
        RBus_UInt32  dden_inv:1;
        RBus_UInt32  dhs_inv:1;
        RBus_UInt32  dvs_inv:1;
        RBus_UInt32  dout_en:1;
        RBus_UInt32  dout_mode:2;
        RBus_UInt32  dispd_debug_mode:3;
        RBus_UInt32  dout_pre_rb_swap:1;
        RBus_UInt32  zz_shift_mode_even:1;
        RBus_UInt32  zz_shift_mode_odd:1;
        RBus_UInt32  zz_shift_sp_even:2;
        RBus_UInt32  zz_shift_sp_odd:2;
        RBus_UInt32  zz_shift_1st_sel_even:2;
        RBus_UInt32  zz_shift_1st_sel_odd:2;
        RBus_UInt32  zz_shift_last_sel_even:2;
        RBus_UInt32  zz_shift_last_sel_odd:2;
    };
}sfg_zz_shift_dbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_bg_dif_pport:1;
        RBus_UInt32  force_bg_dif_oport:1;
        RBus_UInt32  force_bg_dif_nport:1;
        RBus_UInt32  force_bg_dif_mport:1;
        RBus_UInt32  force_bg_dif_lport:1;
        RBus_UInt32  force_bg_dif_kport:1;
        RBus_UInt32  force_bg_dif_jport:1;
        RBus_UInt32  force_bg_dif_iport:1;
        RBus_UInt32  force_bg_dif_hport:1;
        RBus_UInt32  force_bg_dif_gport:1;
        RBus_UInt32  force_bg_dif_fport:1;
        RBus_UInt32  force_bg_dif_eport:1;
        RBus_UInt32  force_bg_dif_dport:1;
        RBus_UInt32  force_bg_dif_cport:1;
        RBus_UInt32  force_bg_dif_bport:1;
        RBus_UInt32  force_bg_dif_aport:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  dclk_mode_switch:2;
    };
}sfg_swap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_porth:4;
        RBus_UInt32  output_portg:4;
        RBus_UInt32  output_portf:4;
        RBus_UInt32  output_porte:4;
        RBus_UInt32  output_portd:4;
        RBus_UInt32  output_portc:4;
        RBus_UInt32  output_portb:4;
        RBus_UInt32  output_porta:4;
    };
}sfg_swap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_portp:4;
        RBus_UInt32  output_porto:4;
        RBus_UInt32  output_portn:4;
        RBus_UInt32  output_portm:4;
        RBus_UInt32  output_portl:4;
        RBus_UInt32  output_portk:4;
        RBus_UInt32  output_portj:4;
        RBus_UInt32  output_porti:4;
    };
}sfg_swap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_crc_start:1;
        RBus_UInt32  sfg_crc_conti:1;
        RBus_UInt32  sfg_crc_r_auto_cmp_en:1;
        RBus_UInt32  sfg_crc_l_auto_cmp_en:1;
        RBus_UInt32  sfg_crc_mode:1;
        RBus_UInt32  res1:27;
    };
}sfg_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_crc_result_0:32;
    };
}sfg_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_crc_result_1:32;
    };
}sfg_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_l_des_crc:32;
    };
}sfg_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_r_des_crc:32;
    };
}sfg_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_r_crc_err_cnt:16;
        RBus_UInt32  sfg_l_crc_err_cnt:16;
    };
}sfg_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bg_dif_blu:10;
        RBus_UInt32  bg_dif_grn:10;
        RBus_UInt32  bg_dif_red:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  en_force_bg_dif:1;
    };
}sfg_force_bg_at_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_3_back_dummy_num_even:2;
        RBus_UInt32  seg_3_front_dummy_num_even:2;
        RBus_UInt32  seg_3_back_dummy_num_odd:2;
        RBus_UInt32  seg_3_front_dummy_num_odd:2;
        RBus_UInt32  seg_2_back_dummy_num_even:2;
        RBus_UInt32  seg_2_front_dummy_num_even:2;
        RBus_UInt32  seg_2_back_dummy_num_odd:2;
        RBus_UInt32  seg_2_front_dummy_num_odd:2;
        RBus_UInt32  seg_1_back_dummy_num_even:2;
        RBus_UInt32  seg_1_front_dummy_num_even:2;
        RBus_UInt32  seg_1_back_dummy_num_odd:2;
        RBus_UInt32  seg_1_front_dummy_num_odd:2;
        RBus_UInt32  seg_0_back_dummy_num_even:2;
        RBus_UInt32  seg_0_front_dummy_num_even:2;
        RBus_UInt32  seg_0_back_dummy_num_odd:2;
        RBus_UInt32  seg_0_front_dummy_num_odd:2;
    };
}sfg_dummy_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_7_back_dummy_num_even:2;
        RBus_UInt32  seg_7_front_dummy_num_even:2;
        RBus_UInt32  seg_7_back_dummy_num_odd:2;
        RBus_UInt32  seg_7_front_dummy_num_odd:2;
        RBus_UInt32  seg_6_back_dummy_num_even:2;
        RBus_UInt32  seg_6_front_dummy_num_even:2;
        RBus_UInt32  seg_6_back_dummy_num_odd:2;
        RBus_UInt32  seg_6_front_dummy_num_odd:2;
        RBus_UInt32  seg_5_back_dummy_num_even:2;
        RBus_UInt32  seg_5_front_dummy_num_even:2;
        RBus_UInt32  seg_5_back_dummy_num_odd:2;
        RBus_UInt32  seg_5_front_dummy_num_odd:2;
        RBus_UInt32  seg_4_back_dummy_num_even:2;
        RBus_UInt32  seg_4_front_dummy_num_even:2;
        RBus_UInt32  seg_4_back_dummy_num_odd:2;
        RBus_UInt32  seg_4_front_dummy_num_odd:2;
    };
}sfg_dummy_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_11_back_dummy_num_even:2;
        RBus_UInt32  seg_11_front_dummy_num_even:2;
        RBus_UInt32  seg_11_back_dummy_num_odd:2;
        RBus_UInt32  seg_11_front_dummy_num_odd:2;
        RBus_UInt32  seg_10_back_dummy_num_even:2;
        RBus_UInt32  seg_10_front_dummy_num_even:2;
        RBus_UInt32  seg_10_back_dummy_num_odd:2;
        RBus_UInt32  seg_10_front_dummy_num_odd:2;
        RBus_UInt32  seg_9_back_dummy_num_even:2;
        RBus_UInt32  seg_9_front_dummy_num_even:2;
        RBus_UInt32  seg_9_back_dummy_num_odd:2;
        RBus_UInt32  seg_9_front_dummy_num_odd:2;
        RBus_UInt32  seg_8_back_dummy_num_even:2;
        RBus_UInt32  seg_8_front_dummy_num_even:2;
        RBus_UInt32  seg_8_back_dummy_num_odd:2;
        RBus_UInt32  seg_8_front_dummy_num_odd:2;
    };
}sfg_dummy_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_15_back_dummy_num_even:2;
        RBus_UInt32  seg_15_front_dummy_num_even:2;
        RBus_UInt32  seg_15_back_dummy_num_odd:2;
        RBus_UInt32  seg_15_front_dummy_num_odd:2;
        RBus_UInt32  seg_14_back_dummy_num_even:2;
        RBus_UInt32  seg_14_front_dummy_num_even:2;
        RBus_UInt32  seg_14_back_dummy_num_odd:2;
        RBus_UInt32  seg_14_front_dummy_num_odd:2;
        RBus_UInt32  seg_13_back_dummy_num_even:2;
        RBus_UInt32  seg_13_front_dummy_num_even:2;
        RBus_UInt32  seg_13_back_dummy_num_odd:2;
        RBus_UInt32  seg_13_front_dummy_num_odd:2;
        RBus_UInt32  seg_12_back_dummy_num_even:2;
        RBus_UInt32  seg_12_front_dummy_num_even:2;
        RBus_UInt32  seg_12_back_dummy_num_odd:2;
        RBus_UInt32  seg_12_front_dummy_num_odd:2;
    };
}sfg_dummy_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  port_num:4;
        RBus_UInt32  seg_num:4;
        RBus_UInt32  h_flip_en:1;
        RBus_UInt32  pif_2d2g_en:1;
        RBus_UInt32  pif_2d2g_sw_line23:1;
        RBus_UInt32  pif_2d2g_sw_line01:1;
        RBus_UInt32  req_epi_mode:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy_pixel_shift_en:1;
        RBus_UInt32  mask_one_eye_black_left:1;
        RBus_UInt32  mask_one_eye_black_en:1;
        RBus_UInt32  dummy1802d140_31_26:6;
    };
}sfg_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg1_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg0_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg3_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg2_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg5_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg4_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg7_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg6_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg9_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg8_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_seg_start_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg11_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg10_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_seg_start_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg13_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg12_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_seg_start_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg15_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  seg14_start:13;
        RBus_UInt32  res1:3;
    };
}sfg_seg_start_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_sel:3;
        RBus_UInt32  res1:26;
        RBus_UInt32  pif_2d2g_hs_sel:1;
        RBus_UInt32  tg_auto_cfg:1;
        RBus_UInt32  bypass_mode:1;
    };
}sfg_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_delay:16;
        RBus_UInt32  hsync_width:8;
        RBus_UInt32  res1:8;
    };
}sfg_ctrl_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  vsync_end:8;
        RBus_UInt32  res1:8;
    };
}sfg_ctrl_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_start:16;
        RBus_UInt32  sfg_dh_den_sta:16;
    };
}sfg_ctrl_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_threshold:16;
        RBus_UInt32  res1:3;
        RBus_UInt32  final_line_length:13;
    };
}sfg_ctrl_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_sram0_rm:4;
        RBus_UInt32  sfg_sram1_rm:4;
        RBus_UInt32  sfg_sram2_rm:4;
        RBus_UInt32  sfg_sram3_rm:4;
        RBus_UInt32  res1:16;
    };
}sfg_bisr_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_sram0_rme:1;
        RBus_UInt32  sfg_sram1_rme:1;
        RBus_UInt32  sfg_sram2_rme:1;
        RBus_UInt32  sfg_sram3_rme:1;
        RBus_UInt32  res1:28;
    };
}sfg_bisr_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_sram0_ls:1;
        RBus_UInt32  sfg_sram1_ls:1;
        RBus_UInt32  sfg_sram2_ls:1;
        RBus_UInt32  sfg_sram3_ls:1;
        RBus_UInt32  res1:28;
    };
}sfg_bisr_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfg_bisr_fail_0:1;
        RBus_UInt32  sfg_bisr_fail_1:1;
        RBus_UInt32  sfg_bisr_fail_2:1;
        RBus_UInt32  sfg_bisr_fail_3:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  sfg_drf_fail_0:1;
        RBus_UInt32  sfg_drf_fail_1:1;
        RBus_UInt32  sfg_drf_fail_2:1;
        RBus_UInt32  sfg_drf_fail_3:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  sfg_bisr_repaired:1;
    };
}sfg_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_start_auto:16;
        RBus_UInt32  hsync_delay_auto:16;
    };
}sfg_tg_auto_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_width_auto:8;
        RBus_UInt32  vsync_end_auto:8;
        RBus_UInt32  vsync_start_auto:8;
        RBus_UInt32  pif_2d2g_hs_sel_auto:1;
        RBus_UInt32  res1:7;
    };
}sfg_tg_auto_2_RBUS;


#endif







#endif //_RBUS_SFG_REG_H_

