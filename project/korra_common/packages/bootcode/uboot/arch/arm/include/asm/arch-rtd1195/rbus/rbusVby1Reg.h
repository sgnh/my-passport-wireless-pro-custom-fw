/**
* @file rbusVby1Reg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/2/20
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_VBY1_REG_H_
#define _RBUS_VBY1_REG_H_

#include "rbus/rbusTypes.h"




// VBY1 Register Address

#define VBY1_VIDEO_FORMAT_VADDR                    (0xb802d600)
#define VBY1_LANE_STATUS_VADDR                     (0xb802d604)
#define VBY1_CTL_VADDR                             (0xb802d608)
#define VBY1_PLL_TRACKING_VADDR                    (0xb802d60c)
#define VBY1_TRANSMIT_CONTROL_VADDR                (0xb802d610)
#define VBY1_TRANSMIT_STATUS_VADDR                 (0xb802d614)
#define VBY1_THREE_FLAG_VADDR                      (0xb802d618)
#define VBY1_INTERRUPT_VADDR                       (0xb802d61c)
#define VBY1_CRC_CONTROL_VADDR                     (0xb802d620)
#define VBY1_CRC_RESULT_VADDR                      (0xb802d624)
#define VBY1_CTS_FIFO_VADDR                        (0xb802d628)
#define VBY1_VBY1_BIST0_VADDR                      (0xb802d62c)
#define VBY1_VBY1_BIST1_VADDR                      (0xb802d630)
#define VBY1_VBY1_BIST2_VADDR                      (0xb802d634)
#define VBY1_VBY1_BIST3_VADDR                      (0xb802d638)
#define VBY1_VBY1_BIST4_VADDR                      (0xb802d63c)
#define VBY1_VBY1_DEBUG_VADDR                      (0xb802d640)
#define VBY1_VBY1_FW_CTRL_VADDR                    (0xb802d644)
#define VBY1_VBY1_OUT_CTRL_VADDR                   (0xb802d648)
#define VBY1_VBY1_BIT_SHIFT_CTRL_VADDR             (0xb802d64c)
#define VBY1_SYS_DCLKSS_VADDR                      (0xb802d660)
#define VBY1_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR     (0xb802d664)
#define VBY1_DPLL_IN_FSYNC_TRACKING_CTRL2_VADDR    (0xb802d668)
#define VBY1_DPLL_IN_FSYNC_TRACKING_DEBUG_VADDR    (0xb802d66c)
#define VBY1_DCLK_FRC2FSYNC_SPEEDUP_VADDR          (0xb802d670)
#define VBY1_DPLL_STATUS_RO_VADDR                  (0xb802d674)
#define VBY1_DCLKSS_FREQ_VADDR                     (0xb802d678)
#define VBY1_DCLKSS_PROFILE0_VADDR                 (0xb802d67c)
#define VBY1_DCLKSS_PROFILE1_VADDR                 (0xb802d680)
#define VBY1_DCLKSS_PROFILE2_VADDR                 (0xb802d684)
#define VBY1_DCLKSS_PROFILE3_VADDR                 (0xb802d688)
#define VBY1_DCLKSS_PROFILE4_VADDR                 (0xb802d68c)
#define VBY1_DCLKSS_PROFILE5_VADDR                 (0xb802d690)
#define VBY1_DCLKSS_PROFILE6_VADDR                 (0xb802d694)
#define VBY1_DCLKSS_PROFILE7_VADDR                 (0xb802d698)
#define VBY1_DCLKSS_PROFILE8_VADDR                 (0xb802d69c)
#define VBY1_DCLKSS_PROFILE9_VADDR                 (0xb802d6a0)
#define VBY1_DCLKSS_PROFILE10_VADDR                (0xb802d6a4)
#define VBY1_DCLKSS_PROFILE11_VADDR                (0xb802d6a8)
#define VBY1_DCLKSS_PROFILE12_VADDR                (0xb802d6ac)
#define VBY1_DCLKSS_PROFILE13_VADDR                (0xb802d6b0)
#define VBY1_DCLKSS_PROFILE14_VADDR                (0xb802d6b4)
#define VBY1_DCLKSS_PROFILE15_VADDR                (0xb802d6b8)
#define VBY1_PHY0_TXBIST_00_VADDR                  (0xb802d6c0)
#define VBY1_PHY0_TXBIST_01_VADDR                  (0xb802d6c4)
#define VBY1_PHY0_TXBIST_02_VADDR                  (0xb802d6c8)
#define VBY1_PHY0_APHY_00_VADDR                    (0xb802d6cc)
#define VBY1_PHY0_APHY_01_VADDR                    (0xb802d6d0)
#define VBY1_PHY0_APHY_02_VADDR                    (0xb802d6d4)
#define VBY1_PHY0_APHY_03_VADDR                    (0xb802d6d8)
#define VBY1_PHY0_APHY_04_VADDR                    (0xb802d6dc)
#define VBY1_PHY1_TXBIST_00_VADDR                  (0xb802d6e0)
#define VBY1_PHY1_TXBIST_01_VADDR                  (0xb802d6e4)
#define VBY1_PHY1_TXBIST_02_VADDR                  (0xb802d6e8)
#define VBY1_PHY1_APHY_00_VADDR                    (0xb802d6ec)
#define VBY1_PHY1_APHY_01_VADDR                    (0xb802d6f0)
#define VBY1_PHY1_APHY_02_VADDR                    (0xb802d6f4)
#define VBY1_PHY1_APHY_03_VADDR                    (0xb802d6f8)
#define VBY1_PHY1_APHY_04_VADDR                    (0xb802d6fc)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======VBY1 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  color_format:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  win:10;
    };
}video_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pixel_mode:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  lane_count:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  section:5;
        RBus_UInt32  res4:5;
        RBus_UInt32  byte_mode:3;
    };
}lane_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ctl:24;
    };
}ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  over_boundary:1;
        RBus_UInt32  under_boundary:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  reg_boundary:5;
    };
}pll_tracking_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_en:1;
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  transfer_en:1;
        RBus_UInt32  video_trans_mode:1;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  dummy1802d610_23_22:2;
        RBus_UInt32  reg_delay:22;
    };
}transmit_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d614_31_7:25;
        RBus_UInt32  num_check_fail:1;
        RBus_UInt32  aln_finish:1;
        RBus_UInt32  initial_finish:1;
        RBus_UInt32  cdr_out_en:1;
        RBus_UInt32  video_en:1;
        RBus_UInt32  aln_en:1;
        RBus_UInt32  initial_en:1;
    };
}transmit_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  three_mode:2;
        RBus_UInt32  three_en:1;
    };
}three_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d61c_31_8:24;
        RBus_UInt32  int_async_over_boundary_en:1;
        RBus_UInt32  int_async_under_boundary_en:1;
        RBus_UInt32  int_cts_full_en:1;
        RBus_UInt32  int_cts_empty_en:1;
        RBus_UInt32  int_async_over_boundary:1;
        RBus_UInt32  int_async_under_boundary:1;
        RBus_UInt32  int_cts_full:1;
        RBus_UInt32  int_cts_empty:1;
    };
}interrupt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reg_crc_start:1;
        RBus_UInt32  reg_crc_conti:1;
    };
}crc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  rd_addr_initial:4;
        RBus_UInt32  full_boundary:4;
        RBus_UInt32  empty_boundary:4;
        RBus_UInt32  dummy1802d628_6_5:2;
        RBus_UInt32  force_rstn_delay_en:1;
        RBus_UInt32  force_rstn:1;
        RBus_UInt32  en_bypass:1;
        RBus_UInt32  full_mask_error:1;
        RBus_UInt32  empty_mask_error:1;
    };
}cts_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  bist_fail_15:1;
        RBus_UInt32  bist_fail_14:1;
        RBus_UInt32  bist_fail_13:1;
        RBus_UInt32  bist_fail_12:1;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}vby1_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drf_bist_fail_15:1;
        RBus_UInt32  drf_bist_fail_14:1;
        RBus_UInt32  drf_bist_fail_13:1;
        RBus_UInt32  drf_bist_fail_12:1;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
    };
}vby1_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_7:4;
    };
}vby1_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_8:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  rm_12:4;
        RBus_UInt32  rm_13:4;
        RBus_UInt32  rm_14:4;
        RBus_UInt32  rm_15:4;
    };
}vby1_bist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  rme_12:1;
        RBus_UInt32  rme_13:1;
        RBus_UInt32  rme_14:1;
        RBus_UInt32  rme_15:1;
    };
}vby1_bist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  debug_mode:5;
    };
}vby1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_htpdn_ctrl:1;
        RBus_UInt32  fw_lockn_ctrl:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  fw_htpdn:1;
        RBus_UInt32  fw_lockn:1;
    };
}vby1_fw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  lsb_msb_swap:1;
        RBus_UInt32  lane_swap:1;
    };
}vby1_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_shift_enable:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  output_bit:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  shift_bit:2;
    };
}vby1_bit_shift_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_field_flag_mode_en:1;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  dclk_offset_11_0:12;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  dclk_ss_test:1;
        RBus_UInt32  dclk_freq_syn_slt:6;
        RBus_UInt32  dclk_ss_rag:4;
        RBus_UInt32  dummy1802d660_3:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy1802d660_1:1;
        RBus_UInt32  dclk_ss_en:1;
    };
}vby1_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_mcode_slow_modify_valid:1;
        RBus_UInt32  sscg_mcode_slow_modify_stable:1;
        RBus_UInt32  sscg_mcode_slow_modify_pixel:12;
        RBus_UInt32  sscg_offset_slow_modify_valid:1;
        RBus_UInt32  sscg_offset_slow_modify_stable:1;
        RBus_UInt32  sscg_offset_slow_modify_pixel:12;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_general_en:1;
    };
}vby1_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_neg_th:12;
        RBus_UInt32  in_frame_tracking_pos_th:12;
        RBus_UInt32  in_frame_tracking_mul:8;
    };
}vby1_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_flag:1;
        RBus_UInt32  sscg_profile_over_underflow_flag:1;
        RBus_UInt32  sscg_profile_protection:1;
        RBus_UInt32  sscg_offset_over_th_max:13;
        RBus_UInt32  dpll_mcode_protection:1;
        RBus_UInt32  dpll_mcode_protection_ready_width:2;
        RBus_UInt32  sscg_offset_over_th_value:13;
    };
}vby1_dpll_in_fsync_tracking_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  frc2fsync_speedup_m_code:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  frc2fsync_speedup_offset:11;
    };
}vby1_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  final_m_code:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  final_profile:13;
    };
}vby1_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_profile_force_64n_en:2;
        RBus_UInt32  dclk_ss_async_protection:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  dclk_ss_fmdiv:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  dclk_ss_protection_cnt_max:7;
    };
}vby1_dclkss_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d67c_31_30:2;
        RBus_UInt32  dclk_ss_shuffle_en:1;
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  dclk_profile_remap_1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_0:12;
    };
}vby1_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_2:12;
    };
}vby1_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_4:12;
    };
}vby1_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_6:12;
    };
}vby1_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_8:12;
    };
}vby1_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_10:12;
    };
}vby1_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_13:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_12:12;
    };
}vby1_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_15:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_14:12;
    };
}vby1_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_17:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_16:12;
    };
}vby1_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_19:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_18:12;
    };
}vby1_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_21:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_20:12;
    };
}vby1_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_22:12;
    };
}vby1_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_25:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_24:12;
    };
}vby1_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_27:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_26:12;
    };
}vby1_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_29:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_28:12;
    };
}vby1_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_31:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_30:12;
    };
}vby1_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_repeat_0:1;
        RBus_UInt32  bist_tp_sel_0:1;
        RBus_UInt32  delay_sel0_0:3;
        RBus_UInt32  delay_sel1_0:3;
        RBus_UInt32  delay_sel2_0:3;
        RBus_UInt32  delay_sel3_0:3;
        RBus_UInt32  delay_sel4_0:3;
        RBus_UInt32  delay_sel5_0:3;
        RBus_UInt32  delay_sel6_0:3;
        RBus_UInt32  delay_sel7_0:3;
        RBus_UInt32  tp_type_sel_0:1;
        RBus_UInt32  scramble_default_0:1;
        RBus_UInt32  txbist_mode_0:2;
        RBus_UInt32  prbs_sel_0:1;
        RBus_UInt32  x1x2_sel_0:1;
    };
}phy0_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_01_0:4;
        RBus_UInt32  enhance_mode_0:1;
        RBus_UInt32  prbs_reverse_0:1;
        RBus_UInt32  scramble_dis_0:1;
        RBus_UInt32  pn_swap_0:1;
        RBus_UInt32  bist_seed_0:8;
        RBus_UInt32  packet_length_0:8;
        RBus_UInt32  packet_number_0:8;
    };
}phy0_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_02_0:8;
        RBus_UInt32  lane_enable_0:8;
        RBus_UInt32  debug_sel_0:8;
        RBus_UInt32  err_period_0:8;
    };
}phy0_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_emon_tx0_0:1;
        RBus_UInt32  vby1tx_em_tx0_0:3;
        RBus_UInt32  vby1tx_emon_tx1_0:1;
        RBus_UInt32  vby1tx_em_tx1_0:3;
        RBus_UInt32  vby1tx_emon_tx2_0:1;
        RBus_UInt32  vby1tx_em_tx2_0:3;
        RBus_UInt32  vby1tx_emon_tx3_0:1;
        RBus_UInt32  vby1tx_em_tx3_0:3;
        RBus_UInt32  vby1tx_emon_tx4_0:1;
        RBus_UInt32  vby1tx_em_tx4_0:3;
        RBus_UInt32  vby1tx_emon_tx5_0:1;
        RBus_UInt32  vby1tx_em_tx5_0:3;
        RBus_UInt32  vby1tx_emon_tx6_0:1;
        RBus_UInt32  vby1tx_em_tx6_0:3;
        RBus_UInt32  vby1tx_emon_tx7_0:1;
        RBus_UInt32  vby1tx_em_tx7_0:3;
    };
}phy0_aphy_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_idrv_tx0_0:4;
        RBus_UInt32  vby1tx_idrv_tx1_0:4;
        RBus_UInt32  vby1tx_idrv_tx2_0:4;
        RBus_UInt32  vby1tx_idrv_tx3_0:4;
        RBus_UInt32  vby1tx_idrv_tx4_0:4;
        RBus_UInt32  vby1tx_idrv_tx5_0:4;
        RBus_UInt32  vby1tx_idrv_tx6_0:4;
        RBus_UInt32  vby1tx_idrv_tx7_0:4;
    };
}phy0_aphy_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_powz0_0:1;
        RBus_UInt32  vby1tx_z0tune_0:1;
        RBus_UInt32  vby1tx_z0entst_0:1;
        RBus_UInt32  vby1tx_z0set_0:5;
        RBus_UInt32  vby1tx_z0_ok_0:1;
        RBus_UInt32  vby1tx_z0_bound_0:1;
        RBus_UInt32  vby1tx_res_0:5;
        RBus_UInt32  res1:17;
    };
}phy0_aphy_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pow_0:1;
        RBus_UInt32  vby1tx_powlv_0:1;
        RBus_UInt32  vby1tx_pll_test_0:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  vby1tx_pow_tx0_0:1;
        RBus_UInt32  vby1tx_pow_tx1_0:1;
        RBus_UInt32  vby1tx_pow_tx2_0:1;
        RBus_UInt32  vby1tx_pow_tx3_0:1;
        RBus_UInt32  vby1tx_pow_tx4_0:1;
        RBus_UInt32  vby1tx_pow_tx5_0:1;
        RBus_UInt32  vby1tx_pow_tx6_0:1;
        RBus_UInt32  vby1tx_pow_tx7_0:1;
        RBus_UInt32  vby1tx_vsel_0:2;
        RBus_UInt32  vby1tx_lv_0:2;
        RBus_UInt32  vby1tx_pll_rstb_0:1;
        RBus_UInt32  vby1tx_pll_rs_0:3;
        RBus_UInt32  vby1tx_pll_cs_0:2;
        RBus_UInt32  vby1tx_pll_ldo_pow_0:1;
        RBus_UInt32  vby1tx_pll_pow_0:1;
    };
}phy0_aphy_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_cp_0:2;
        RBus_UInt32  vby1tx_pll_ldo_sel_0:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  vby1tx_pll_wdo_0:1;
        RBus_UInt32  vby1tx_pll_wdmode_0:2;
        RBus_UInt32  reserved_0:16;
        RBus_UInt32  vby1tx_cksel_0:2;
        RBus_UInt32  vby1tx_pll_div_0:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  vby1tx_pll_ip_0:3;
    };
}phy0_aphy_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_repeat_1:1;
        RBus_UInt32  bist_tp_sel_1:1;
        RBus_UInt32  delay_sel0_1:3;
        RBus_UInt32  delay_sel1_1:3;
        RBus_UInt32  delay_sel2_1:3;
        RBus_UInt32  delay_sel3_1:3;
        RBus_UInt32  delay_sel4_1:3;
        RBus_UInt32  delay_sel5_1:3;
        RBus_UInt32  delay_sel6_1:3;
        RBus_UInt32  delay_sel7_1:3;
        RBus_UInt32  tp_type_sel_1:1;
        RBus_UInt32  scramble_default_1:1;
        RBus_UInt32  txbist_mode_1:2;
        RBus_UInt32  prbs_sel_1:1;
        RBus_UInt32  x1x2_sel_1:1;
    };
}phy1_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_01_1:4;
        RBus_UInt32  enhance_mode_1:1;
        RBus_UInt32  prbs_reverse_1:1;
        RBus_UInt32  scramble_dis_1:1;
        RBus_UInt32  pn_swap_1:1;
        RBus_UInt32  bist_seed_1:8;
        RBus_UInt32  packet_length_1:8;
        RBus_UInt32  packet_number_1:8;
    };
}phy1_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_02_1:8;
        RBus_UInt32  lane_enable_1:8;
        RBus_UInt32  debug_sel_1:8;
        RBus_UInt32  err_period_1:8;
    };
}phy1_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_emon_tx0_1:1;
        RBus_UInt32  vby1tx_em_tx0_1:3;
        RBus_UInt32  vby1tx_emon_tx1_1:1;
        RBus_UInt32  vby1tx_em_tx1_1:3;
        RBus_UInt32  vby1tx_emon_tx2_1:1;
        RBus_UInt32  vby1tx_em_tx2_1:3;
        RBus_UInt32  vby1tx_emon_tx3_1:1;
        RBus_UInt32  vby1tx_em_tx3_1:3;
        RBus_UInt32  vby1tx_emon_tx4_1:1;
        RBus_UInt32  vby1tx_em_tx4_1:3;
        RBus_UInt32  vby1tx_emon_tx5_1:1;
        RBus_UInt32  vby1tx_em_tx5_1:3;
        RBus_UInt32  vby1tx_emon_tx6_1:1;
        RBus_UInt32  vby1tx_em_tx6_1:3;
        RBus_UInt32  vby1tx_emon_tx7_1:1;
        RBus_UInt32  vby1tx_em_tx7_1:3;
    };
}phy1_aphy_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_idrv_tx0_1:4;
        RBus_UInt32  vby1tx_idrv_tx1_1:4;
        RBus_UInt32  vby1tx_idrv_tx2_1:4;
        RBus_UInt32  vby1tx_idrv_tx3_1:4;
        RBus_UInt32  vby1tx_idrv_tx4_1:4;
        RBus_UInt32  vby1tx_idrv_tx5_1:4;
        RBus_UInt32  vby1tx_idrv_tx6_1:4;
        RBus_UInt32  vby1tx_idrv_tx7_1:4;
    };
}phy1_aphy_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_powz0_1:1;
        RBus_UInt32  vby1tx_z0tune_1:1;
        RBus_UInt32  vby1tx_z0entst_1:1;
        RBus_UInt32  vby1tx_z0set_1:5;
        RBus_UInt32  vby1tx_z0_ok_1:1;
        RBus_UInt32  vby1tx_z0_bound_1:1;
        RBus_UInt32  vby1tx_res_1:5;
        RBus_UInt32  res1:17;
    };
}phy1_aphy_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pow_1:1;
        RBus_UInt32  vby1tx_powlv_1:1;
        RBus_UInt32  vby1tx_pll_test_1:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  vby1tx_pow_tx0_1:1;
        RBus_UInt32  vby1tx_pow_tx1_1:1;
        RBus_UInt32  vby1tx_pow_tx2_1:1;
        RBus_UInt32  vby1tx_pow_tx3_1:1;
        RBus_UInt32  vby1tx_pow_tx4_1:1;
        RBus_UInt32  vby1tx_pow_tx5_1:1;
        RBus_UInt32  vby1tx_pow_tx6_1:1;
        RBus_UInt32  vby1tx_pow_tx7_1:1;
        RBus_UInt32  vby1tx_vsel_1:2;
        RBus_UInt32  vby1tx_lv_1:2;
        RBus_UInt32  vby1tx_pll_rstb_1:1;
        RBus_UInt32  vby1tx_pll_rs_1:3;
        RBus_UInt32  vby1tx_pll_cs_1:2;
        RBus_UInt32  vby1tx_pll_ldo_pow_1:1;
        RBus_UInt32  vby1tx_pll_pow_1:1;
    };
}phy1_aphy_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_cp_1:2;
        RBus_UInt32  vby1tx_pll_ldo_sel_1:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  vby1tx_pll_wdo_1:1;
        RBus_UInt32  vby1tx_pll_wdmode_1:2;
        RBus_UInt32  reserved_1:16;
        RBus_UInt32  vby1tx_cksel_1:2;
        RBus_UInt32  vby1tx_pll_div_1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  vby1tx_pll_ip_1:3;
    };
}phy1_aphy_04_RBUS;





#else //apply LITTLE_ENDIAN


//======VBY1 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  color_format:4;
        RBus_UInt32  res1:12;
    };
}video_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte_mode:3;
        RBus_UInt32  res4:5;
        RBus_UInt32  section:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  lane_count:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  pixel_mode:3;
        RBus_UInt32  res1:5;
    };
}lane_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctl:24;
        RBus_UInt32  res1:8;
    };
}ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_boundary:5;
        RBus_UInt32  res1:25;
        RBus_UInt32  under_boundary:1;
        RBus_UInt32  over_boundary:1;
    };
}pll_tracking_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_delay:22;
        RBus_UInt32  dummy1802d610_23_22:2;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  video_trans_mode:1;
        RBus_UInt32  transfer_en:1;
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  reg_en:1;
    };
}transmit_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  initial_en:1;
        RBus_UInt32  aln_en:1;
        RBus_UInt32  video_en:1;
        RBus_UInt32  cdr_out_en:1;
        RBus_UInt32  initial_finish:1;
        RBus_UInt32  aln_finish:1;
        RBus_UInt32  num_check_fail:1;
        RBus_UInt32  dummy1802d614_31_7:25;
    };
}transmit_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  three_en:1;
        RBus_UInt32  three_mode:2;
        RBus_UInt32  res1:29;
    };
}three_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_cts_empty:1;
        RBus_UInt32  int_cts_full:1;
        RBus_UInt32  int_async_under_boundary:1;
        RBus_UInt32  int_async_over_boundary:1;
        RBus_UInt32  int_cts_empty_en:1;
        RBus_UInt32  int_cts_full_en:1;
        RBus_UInt32  int_async_under_boundary_en:1;
        RBus_UInt32  int_async_over_boundary_en:1;
        RBus_UInt32  dummy1802d61c_31_8:24;
    };
}interrupt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_crc_conti:1;
        RBus_UInt32  reg_crc_start:1;
        RBus_UInt32  res1:30;
    };
}crc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  empty_mask_error:1;
        RBus_UInt32  full_mask_error:1;
        RBus_UInt32  en_bypass:1;
        RBus_UInt32  force_rstn:1;
        RBus_UInt32  force_rstn_delay_en:1;
        RBus_UInt32  dummy1802d628_6_5:2;
        RBus_UInt32  empty_boundary:4;
        RBus_UInt32  full_boundary:4;
        RBus_UInt32  rd_addr_initial:4;
        RBus_UInt32  res1:13;
    };
}cts_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  bist_fail_12:1;
        RBus_UInt32  bist_fail_13:1;
        RBus_UInt32  bist_fail_14:1;
        RBus_UInt32  bist_fail_15:1;
        RBus_UInt32  res1:16;
    };
}vby1_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  drf_bist_fail_12:1;
        RBus_UInt32  drf_bist_fail_13:1;
        RBus_UInt32  drf_bist_fail_14:1;
        RBus_UInt32  drf_bist_fail_15:1;
        RBus_UInt32  res1:16;
    };
}vby1_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_7:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}vby1_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_15:4;
        RBus_UInt32  rm_14:4;
        RBus_UInt32  rm_13:4;
        RBus_UInt32  rm_12:4;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_8:4;
    };
}vby1_bist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_15:1;
        RBus_UInt32  rme_14:1;
        RBus_UInt32  rme_13:1;
        RBus_UInt32  rme_12:1;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res1:16;
    };
}vby1_bist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:5;
        RBus_UInt32  res1:27;
    };
}vby1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_lockn:1;
        RBus_UInt32  fw_htpdn:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  fw_lockn_ctrl:1;
        RBus_UInt32  fw_htpdn_ctrl:1;
    };
}vby1_fw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_swap:1;
        RBus_UInt32  lsb_msb_swap:1;
        RBus_UInt32  res1:30;
    };
}vby1_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shift_bit:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  output_bit:4;
        RBus_UInt32  res1:19;
        RBus_UInt32  bit_shift_enable:1;
    };
}vby1_bit_shift_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_ss_en:1;
        RBus_UInt32  dummy1802d660_1:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy1802d660_3:1;
        RBus_UInt32  dclk_ss_rag:4;
        RBus_UInt32  dclk_freq_syn_slt:6;
        RBus_UInt32  dclk_ss_test:1;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  dclk_offset_11_0:12;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  dclk_field_flag_mode_en:1;
    };
}vby1_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_general_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  sscg_offset_slow_modify_pixel:12;
        RBus_UInt32  sscg_offset_slow_modify_stable:1;
        RBus_UInt32  sscg_offset_slow_modify_valid:1;
        RBus_UInt32  sscg_mcode_slow_modify_pixel:12;
        RBus_UInt32  sscg_mcode_slow_modify_stable:1;
        RBus_UInt32  sscg_mcode_slow_modify_valid:1;
    };
}vby1_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_mul:8;
        RBus_UInt32  in_frame_tracking_pos_th:12;
        RBus_UInt32  in_frame_tracking_neg_th:12;
    };
}vby1_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_th_value:13;
        RBus_UInt32  dpll_mcode_protection_ready_width:2;
        RBus_UInt32  dpll_mcode_protection:1;
        RBus_UInt32  sscg_offset_over_th_max:13;
        RBus_UInt32  sscg_profile_protection:1;
        RBus_UInt32  sscg_profile_over_underflow_flag:1;
        RBus_UInt32  sscg_offset_over_flag:1;
    };
}vby1_dpll_in_fsync_tracking_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc2fsync_speedup_offset:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  frc2fsync_speedup_m_code:3;
        RBus_UInt32  res1:13;
    };
}vby1_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_profile:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  final_m_code:10;
        RBus_UInt32  res1:6;
    };
}vby1_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_ss_protection_cnt_max:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  dclk_ss_fmdiv:7;
        RBus_UInt32  res1:14;
        RBus_UInt32  dclk_ss_async_protection:1;
        RBus_UInt32  final_profile_force_64n_en:2;
    };
}vby1_dclkss_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_1:12;
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  dclk_ss_shuffle_en:1;
        RBus_UInt32  dummy1802d67c_31_30:2;
    };
}vby1_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_3:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_5:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_7:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_9:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_11:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_13:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_15:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_17:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_19:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_21:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_23:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_25:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_27:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_29:12;
        RBus_UInt32  res1:4;
    };
}vby1_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_31:13;
        RBus_UInt32  res1:3;
    };
}vby1_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x1x2_sel_0:1;
        RBus_UInt32  prbs_sel_0:1;
        RBus_UInt32  txbist_mode_0:2;
        RBus_UInt32  scramble_default_0:1;
        RBus_UInt32  tp_type_sel_0:1;
        RBus_UInt32  delay_sel7_0:3;
        RBus_UInt32  delay_sel6_0:3;
        RBus_UInt32  delay_sel5_0:3;
        RBus_UInt32  delay_sel4_0:3;
        RBus_UInt32  delay_sel3_0:3;
        RBus_UInt32  delay_sel2_0:3;
        RBus_UInt32  delay_sel1_0:3;
        RBus_UInt32  delay_sel0_0:3;
        RBus_UInt32  bist_tp_sel_0:1;
        RBus_UInt32  bist_repeat_0:1;
    };
}phy0_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  packet_number_0:8;
        RBus_UInt32  packet_length_0:8;
        RBus_UInt32  bist_seed_0:8;
        RBus_UInt32  pn_swap_0:1;
        RBus_UInt32  scramble_dis_0:1;
        RBus_UInt32  prbs_reverse_0:1;
        RBus_UInt32  enhance_mode_0:1;
        RBus_UInt32  reserved_txbist_01_0:4;
    };
}phy0_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_period_0:8;
        RBus_UInt32  debug_sel_0:8;
        RBus_UInt32  lane_enable_0:8;
        RBus_UInt32  reserved_txbist_02_0:8;
    };
}phy0_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_em_tx7_0:3;
        RBus_UInt32  vby1tx_emon_tx7_0:1;
        RBus_UInt32  vby1tx_em_tx6_0:3;
        RBus_UInt32  vby1tx_emon_tx6_0:1;
        RBus_UInt32  vby1tx_em_tx5_0:3;
        RBus_UInt32  vby1tx_emon_tx5_0:1;
        RBus_UInt32  vby1tx_em_tx4_0:3;
        RBus_UInt32  vby1tx_emon_tx4_0:1;
        RBus_UInt32  vby1tx_em_tx3_0:3;
        RBus_UInt32  vby1tx_emon_tx3_0:1;
        RBus_UInt32  vby1tx_em_tx2_0:3;
        RBus_UInt32  vby1tx_emon_tx2_0:1;
        RBus_UInt32  vby1tx_em_tx1_0:3;
        RBus_UInt32  vby1tx_emon_tx1_0:1;
        RBus_UInt32  vby1tx_em_tx0_0:3;
        RBus_UInt32  vby1tx_emon_tx0_0:1;
    };
}phy0_aphy_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_idrv_tx7_0:4;
        RBus_UInt32  vby1tx_idrv_tx6_0:4;
        RBus_UInt32  vby1tx_idrv_tx5_0:4;
        RBus_UInt32  vby1tx_idrv_tx4_0:4;
        RBus_UInt32  vby1tx_idrv_tx3_0:4;
        RBus_UInt32  vby1tx_idrv_tx2_0:4;
        RBus_UInt32  vby1tx_idrv_tx1_0:4;
        RBus_UInt32  vby1tx_idrv_tx0_0:4;
    };
}phy0_aphy_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  vby1tx_res_0:5;
        RBus_UInt32  vby1tx_z0_bound_0:1;
        RBus_UInt32  vby1tx_z0_ok_0:1;
        RBus_UInt32  vby1tx_z0set_0:5;
        RBus_UInt32  vby1tx_z0entst_0:1;
        RBus_UInt32  vby1tx_z0tune_0:1;
        RBus_UInt32  vby1tx_powz0_0:1;
    };
}phy0_aphy_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_pow_0:1;
        RBus_UInt32  vby1tx_pll_ldo_pow_0:1;
        RBus_UInt32  vby1tx_pll_cs_0:2;
        RBus_UInt32  vby1tx_pll_rs_0:3;
        RBus_UInt32  vby1tx_pll_rstb_0:1;
        RBus_UInt32  vby1tx_lv_0:2;
        RBus_UInt32  vby1tx_vsel_0:2;
        RBus_UInt32  vby1tx_pow_tx7_0:1;
        RBus_UInt32  vby1tx_pow_tx6_0:1;
        RBus_UInt32  vby1tx_pow_tx5_0:1;
        RBus_UInt32  vby1tx_pow_tx4_0:1;
        RBus_UInt32  vby1tx_pow_tx3_0:1;
        RBus_UInt32  vby1tx_pow_tx2_0:1;
        RBus_UInt32  vby1tx_pow_tx1_0:1;
        RBus_UInt32  vby1tx_pow_tx0_0:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  vby1tx_pll_test_0:1;
        RBus_UInt32  vby1tx_powlv_0:1;
        RBus_UInt32  vby1tx_pow_0:1;
    };
}phy0_aphy_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_ip_0:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  vby1tx_pll_div_0:2;
        RBus_UInt32  vby1tx_cksel_0:2;
        RBus_UInt32  reserved_0:16;
        RBus_UInt32  vby1tx_pll_wdmode_0:2;
        RBus_UInt32  vby1tx_pll_wdo_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vby1tx_pll_ldo_sel_0:2;
        RBus_UInt32  vby1tx_pll_cp_0:2;
    };
}phy0_aphy_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x1x2_sel_1:1;
        RBus_UInt32  prbs_sel_1:1;
        RBus_UInt32  txbist_mode_1:2;
        RBus_UInt32  scramble_default_1:1;
        RBus_UInt32  tp_type_sel_1:1;
        RBus_UInt32  delay_sel7_1:3;
        RBus_UInt32  delay_sel6_1:3;
        RBus_UInt32  delay_sel5_1:3;
        RBus_UInt32  delay_sel4_1:3;
        RBus_UInt32  delay_sel3_1:3;
        RBus_UInt32  delay_sel2_1:3;
        RBus_UInt32  delay_sel1_1:3;
        RBus_UInt32  delay_sel0_1:3;
        RBus_UInt32  bist_tp_sel_1:1;
        RBus_UInt32  bist_repeat_1:1;
    };
}phy1_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  packet_number_1:8;
        RBus_UInt32  packet_length_1:8;
        RBus_UInt32  bist_seed_1:8;
        RBus_UInt32  pn_swap_1:1;
        RBus_UInt32  scramble_dis_1:1;
        RBus_UInt32  prbs_reverse_1:1;
        RBus_UInt32  enhance_mode_1:1;
        RBus_UInt32  reserved_txbist_01_1:4;
    };
}phy1_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_period_1:8;
        RBus_UInt32  debug_sel_1:8;
        RBus_UInt32  lane_enable_1:8;
        RBus_UInt32  reserved_txbist_02_1:8;
    };
}phy1_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_em_tx7_1:3;
        RBus_UInt32  vby1tx_emon_tx7_1:1;
        RBus_UInt32  vby1tx_em_tx6_1:3;
        RBus_UInt32  vby1tx_emon_tx6_1:1;
        RBus_UInt32  vby1tx_em_tx5_1:3;
        RBus_UInt32  vby1tx_emon_tx5_1:1;
        RBus_UInt32  vby1tx_em_tx4_1:3;
        RBus_UInt32  vby1tx_emon_tx4_1:1;
        RBus_UInt32  vby1tx_em_tx3_1:3;
        RBus_UInt32  vby1tx_emon_tx3_1:1;
        RBus_UInt32  vby1tx_em_tx2_1:3;
        RBus_UInt32  vby1tx_emon_tx2_1:1;
        RBus_UInt32  vby1tx_em_tx1_1:3;
        RBus_UInt32  vby1tx_emon_tx1_1:1;
        RBus_UInt32  vby1tx_em_tx0_1:3;
        RBus_UInt32  vby1tx_emon_tx0_1:1;
    };
}phy1_aphy_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_idrv_tx7_1:4;
        RBus_UInt32  vby1tx_idrv_tx6_1:4;
        RBus_UInt32  vby1tx_idrv_tx5_1:4;
        RBus_UInt32  vby1tx_idrv_tx4_1:4;
        RBus_UInt32  vby1tx_idrv_tx3_1:4;
        RBus_UInt32  vby1tx_idrv_tx2_1:4;
        RBus_UInt32  vby1tx_idrv_tx1_1:4;
        RBus_UInt32  vby1tx_idrv_tx0_1:4;
    };
}phy1_aphy_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  vby1tx_res_1:5;
        RBus_UInt32  vby1tx_z0_bound_1:1;
        RBus_UInt32  vby1tx_z0_ok_1:1;
        RBus_UInt32  vby1tx_z0set_1:5;
        RBus_UInt32  vby1tx_z0entst_1:1;
        RBus_UInt32  vby1tx_z0tune_1:1;
        RBus_UInt32  vby1tx_powz0_1:1;
    };
}phy1_aphy_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_pow_1:1;
        RBus_UInt32  vby1tx_pll_ldo_pow_1:1;
        RBus_UInt32  vby1tx_pll_cs_1:2;
        RBus_UInt32  vby1tx_pll_rs_1:3;
        RBus_UInt32  vby1tx_pll_rstb_1:1;
        RBus_UInt32  vby1tx_lv_1:2;
        RBus_UInt32  vby1tx_vsel_1:2;
        RBus_UInt32  vby1tx_pow_tx7_1:1;
        RBus_UInt32  vby1tx_pow_tx6_1:1;
        RBus_UInt32  vby1tx_pow_tx5_1:1;
        RBus_UInt32  vby1tx_pow_tx4_1:1;
        RBus_UInt32  vby1tx_pow_tx3_1:1;
        RBus_UInt32  vby1tx_pow_tx2_1:1;
        RBus_UInt32  vby1tx_pow_tx1_1:1;
        RBus_UInt32  vby1tx_pow_tx0_1:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  vby1tx_pll_test_1:1;
        RBus_UInt32  vby1tx_powlv_1:1;
        RBus_UInt32  vby1tx_pow_1:1;
    };
}phy1_aphy_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1tx_pll_ip_1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  vby1tx_pll_div_1:2;
        RBus_UInt32  vby1tx_cksel_1:2;
        RBus_UInt32  reserved_1:16;
        RBus_UInt32  vby1tx_pll_wdmode_1:2;
        RBus_UInt32  vby1tx_pll_wdo_1:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vby1tx_pll_ldo_sel_1:2;
        RBus_UInt32  vby1tx_pll_cp_1:2;
    };
}phy1_aphy_04_RBUS;


#endif







#endif //_RBUS_VBY1_REG_H_

