/**
* @file rbusPifReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012/8/5
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PIF_REG_H_
#define _RBUS_PIF_REG_H_

#include "rbusTypes.h"




// PIF Register Address

#define PIF_LVDS_CTRL0_VADDR                       (0xb802d000)
#define PIF_LVDS_CTRL1_VADDR                       (0xb802d008)
#define PIF_LVDS_CTRL2_VADDR                       (0xb802d00c)
#define PIF_LVDS_CTRL3_VADDR                       (0xb802d010)
#define PIF_MLVDS_CTRL0_VADDR                      (0xb802d040)
#define PIF_MLVDS_CTRL1_VADDR                      (0xb802d044)
#define PIF_MLVDS_CTRL2_VADDR                      (0xb802d048)
#define PIF_MLVDS_CTRL3_VADDR                      (0xb802d04c)
#define PIF_PAT_DET_WINDOW_H_INI_STA_WIDTH_VADDR   (0xb802d050)
#define PIF_PAT_DET_WINDOW_V_INI_STA_HEIGHT_VADDR  (0xb802d054)
#define PIF_PATTERN_DETECT_CTRL_VADDR              (0xb802d058)
#define PIF_PAT_DET_SUM1_VADDR                     (0xb802d05c)
#define PIF_PAT_DET_SUM2_VADDR                     (0xb802d060)
#define PIF_PAT_DET_SUM3_VADDR                     (0xb802d064)
#define PIF_PAT_DET_SUM4_VADDR                     (0xb802d068)
#define PIF_PAT_DET_SUM5_VADDR                     (0xb802d06c)
#define PIF_PAT_DET_SUM6_VADDR                     (0xb802d070)
#define PIF_PAT_DET_SUM7_VADDR                     (0xb802d074)
#define PIF_PAT_DET_SUM8_VADDR                     (0xb802d078)
#define PIF_PAT_DET_TH1_VADDR                      (0xb802d07c)
#define PIF_PAT_DET_TH2_VADDR                      (0xb802d080)
#define PIF_PAT_DET_TH3_VADDR                      (0xb802d084)
#define PIF_PAT_DET_TH4_VADDR                      (0xb802d088)
#define PIF_PAT_DET_TH5_VADDR                      (0xb802d08c)
#define PIF_PAT_DET_TH6_VADDR                      (0xb802d090)
#define PIF_PAT_DET_TH7_VADDR                      (0xb802d094)
#define PIF_PAT_DET_TH8_VADDR                      (0xb802d098)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  lvds_epi_sel:1;
    };
}lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_arsv1_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  res2:1;
    };
}lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_crsv1_sel:3;
        RBus_UInt32  lvds_crsv0_sel:3;
        RBus_UInt32  lvds_cden_sel:3;
        RBus_UInt32  lvds_cvs_sel:3;
        RBus_UInt32  lvds_chs_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_drsv1_sel:3;
        RBus_UInt32  lvds_drsv0_sel:3;
        RBus_UInt32  lvds_dden_sel:3;
        RBus_UInt32  lvds_dvs_sel:3;
        RBus_UInt32  lvds_dhs_sel:3;
        RBus_UInt32  res2:1;
    };
}lvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  lvds_mirror:1;
        RBus_UInt32  lvds_map:1;
        RBus_UInt32  ttl_en:1;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  lvds_bport_en:1;
        RBus_UInt32  lvds_cport_en:1;
        RBus_UInt32  lvds_dport_en:1;
        RBus_UInt32  res2:4;
    };
}lvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  mlvds_map_type_sel:4;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  mlvds_8p_special_swap:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  mlvds_mirror:1;
        RBus_UInt32  mlvds_mode:2;
    };
}mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel:8;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mlvds_rst_high:5;
    };
}mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_region:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_4ck_inv:1;
        RBus_UInt32  mlvds_3ck_inv:1;
        RBus_UInt32  mlvds_2ck_inv:1;
        RBus_UInt32  mlvds_1ck_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  fw_merge_tcon_en:1;
        RBus_UInt32  p3_tcon_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  p3_tcon_sel:5;
        RBus_UInt32  p2_tcon_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  p2_tcon_sel:5;
        RBus_UInt32  p1_tcon_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  p1_tcon_sel:5;
    };
}mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low:32;
    };
}mlvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  pat_det_width:13;
    };
}pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_height:12;
    };
}pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  pat_det_auto:1;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_1:26;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_2:26;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_3:26;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_4:26;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_5:26;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_6:26;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_7:26;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sum_line_8:26;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th1:26;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th2:26;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th3:26;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th4:26;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th5:26;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th6:26;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th7:26;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pat_th8:26;
    };
}pat_det_th8_RBUS;





#else //apply LITTLE_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_epi_sel:1;
        RBus_UInt32  res1:31;
    };
}lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_arsv1_sel:3;
    };
}lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  lvds_dhs_sel:3;
        RBus_UInt32  lvds_dvs_sel:3;
        RBus_UInt32  lvds_dden_sel:3;
        RBus_UInt32  lvds_drsv0_sel:3;
        RBus_UInt32  lvds_drsv1_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_chs_sel:3;
        RBus_UInt32  lvds_cvs_sel:3;
        RBus_UInt32  lvds_cden_sel:3;
        RBus_UInt32  lvds_crsv0_sel:3;
        RBus_UInt32  lvds_crsv1_sel:3;
    };
}lvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:4;
        RBus_UInt32  lvds_dport_en:1;
        RBus_UInt32  lvds_cport_en:1;
        RBus_UInt32  lvds_bport_en:1;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  ttl_en:1;
        RBus_UInt32  lvds_map:1;
        RBus_UInt32  lvds_mirror:1;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  res1:20;
    };
}lvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_mode:2;
        RBus_UInt32  mlvds_mirror:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_8p_special_swap:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  mlvds_map_type_sel:4;
        RBus_UInt32  res1:20;
    };
}mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_high:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_sel:8;
    };
}mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_tcon_sel:5;
        RBus_UInt32  res5:2;
        RBus_UInt32  p1_tcon_en:1;
        RBus_UInt32  p2_tcon_sel:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  p2_tcon_en:1;
        RBus_UInt32  p3_tcon_sel:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  p3_tcon_en:1;
        RBus_UInt32  fw_merge_tcon_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mlvds_1ck_inv:1;
        RBus_UInt32  mlvds_2ck_inv:1;
        RBus_UInt32  mlvds_3ck_inv:1;
        RBus_UInt32  mlvds_4ck_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_rst_low_region:1;
    };
}mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low:32;
    };
}mlvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res1:3;
    };
}pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_height:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res1:4;
    };
}pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_auto:1;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  res1:20;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:26;
        RBus_UInt32  res1:6;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:26;
        RBus_UInt32  res1:6;
    };
}pat_det_th8_RBUS;


#endif







#endif //_RBUS_PIF_REG_H_

