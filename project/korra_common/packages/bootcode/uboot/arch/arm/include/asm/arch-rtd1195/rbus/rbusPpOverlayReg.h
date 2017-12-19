/**
* @file rbusPpOverlayReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012/8/15
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PPOVERLAY_REG_H_
#define _RBUS_PPOVERLAY_REG_H_

#include "rbusTypes.h"




// PPOVERLAY Register Address
#define PPOVERLAY_DISPLAY_TIMING_CTRL1_ADDR        (0x18028000)
#define PPOVERLAY_DISPLAY_TIMING_CTRL2_ADDR        (0x18028004)
#define PPOVERLAY_DH_WIDTH_ADDR                    (0x18028008)
#define PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_ADDR   (0x1802800c)
#define PPOVERLAY_DV_LENGTH_ADDR                   (0x18028010)
#define PPOVERLAY_DV_TOTAL_ADDR                    (0x18028014)
#define PPOVERLAY_DH_DEN_START_END_ADDR            (0x18028018)
#define PPOVERLAY_DV_DEN_START_END_ADDR            (0x1802801c)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING_ADDR        (0x18028020)
#define PPOVERLAY_DISPLAY_BACKGROUND_COLOR_ADDR    (0x18028024)
#define PPOVERLAY_DOUBLE_BUFFER_CTRL_ADDR          (0x18028028)
#define PPOVERLAY_DVS_PHASE_ERROR_SET_ADDR         (0x1802802c)
#define PPOVERLAY_MEASURE_TWO_DVS_PHASE_ERROR_RESULT_ADDR  (0x18028030)
#define PPOVERLAY_MEASURE_TOTAL_PIXELS_RESULT1_ADDR  (0x18028034)
#define PPOVERLAY_MEASURE_TOTAL_PIXELS_RESULT2_ADDR  (0x18028038)
#define PPOVERLAY_MEASURE_DVTOTAL_LAST_LINE_PIXELS_RESULT1_ADDR  (0x1802803c)
#define PPOVERLAY_MEASURE_DVTOTAL_LAST_LINE_PIXELS_RESULT2_ADDR  (0x18028040)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING3_ADDR       (0x18028044)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING4_ADDR       (0x18028048)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING1_ADDR       (0x1802804c)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING2_ADDR       (0x18028050)
#define PPOVERLAY_DVS_ABNORMAL_CONTROL_ADDR        (0x18028054)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING5_ADDR       (0x18028058)
#define PPOVERLAY_NEW_FIX_LAST_LINE_MODE_CONTROL_ADDR  (0x18028060)
#define PPOVERLAY_FS_FLL_MODE_CONTROL_ADDR         (0x18028064)
#define PPOVERLAY_DTG_IE_ADDR                      (0x180280f0)
#define PPOVERLAY_DTG_PENDING_STATUS_ADDR          (0x180280f4)
#define PPOVERLAY_DTG_NO_IE_PENDING_STATUS_ADDR    (0x180280f8)
#define PPOVERLAY_MAIN_DISPLAY_CONTROL_RSV_ADDR    (0x18028100)
#define PPOVERLAY_MAIN_DISPLAY_CONTROL_ADDR        (0x18028104)
#define PPOVERLAY_MAIN_BORDER_HIGHLIGHT_BORDER_COLOR_ADDR  (0x18028108)
#define PPOVERLAY_MAIN_BACKGROUND_COLOR_ADDR       (0x1802810c)
#define PPOVERLAY_MAIN_DEN_H_START_END_ADDR        (0x18028110)
#define PPOVERLAY_MAIN_DEN_V_START_END_ADDR        (0x18028114)
#define PPOVERLAY_MAIN_BACKGROUND_H_START_END_ADDR (0x18028118)
#define PPOVERLAY_MAIN_BACKGROUND_V_START_END_ADDR (0x1802811c)
#define PPOVERLAY_MAIN_ACTIVE_H_START_END_ADDR     (0x18028120)
#define PPOVERLAY_MAIN_ACTIVE_V_START_END_ADDR     (0x18028124)
#define PPOVERLAY_HIGHLIGHT_WINDOW_CONTROL_ADDR    (0x18028128)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_INITIAL_START_WIDTH_ADDR  (0x1802812c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_INITIAL_START_HEIGHT_ADDR  (0x18028130)
#define PPOVERLAY_HIGHLIGHT_WINDOW_UPDATE_STEP_ADDR  (0x18028134)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_BOUNDARY_ADDR (0x18028138)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_BOUNDARY_ADDR (0x1802813c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_STATUS_ADDR   (0x18028140)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_STATUS_ADDR   (0x18028144)
#define PPOVERLAY_HIGHLIGHT_WINDOW_BOUNDARY_CONDITION_ADDR  (0x18028148)
#define PPOVERLAY_HIGHLIGHT_WINDOW_BORDER_WIDTH_ADDR  (0x1802814c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_MIN_STATUS_ADDR (0x18028150)
#define PPOVERLAY_HIGHLIGHT_WINDOW_DB_CTRL_ADDR    (0x18028154)
#define PPOVERLAY_MP_DISP_ENABLE_ADDR              (0x18028200)
#define PPOVERLAY_MP_LAYOUT_FORCE_TO_BACKGROUND_ADDR  (0x18028204)
#define PPOVERLAY_SUB_BORDER_HIGHLIGHT_BORDER_COLOR_ADDR  (0x18028208)
#define PPOVERLAY_SUB_BACKGROUND_COLOR_ADDR        (0x1802820c)
#define PPOVERLAY_SUB_DEN_H_START_WIDTH_ADDR       (0x18028210)
#define PPOVERLAY_SUB_DEN_V_START_LENGTH_ADDR      (0x18028214)
#define PPOVERLAY_SUB_BACKGROUND_H_START_END_ADDR  (0x18028218)
#define PPOVERLAY_SUB_BACKGROUND_V_START_END_ADDR  (0x1802821c)
#define PPOVERLAY_SUB_ACTIVE_H_START_END_ADDR      (0x18028220)
#define PPOVERLAY_SUB_ACTIVE_V_START_END_ADDR      (0x18028224)
#define PPOVERLAY_DTG_LC_ADDR                      (0x18028228)
#define PPOVERLAY_SRAM_OK_MAIN_SET_ADDR            (0x1802822c)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_ODD_ADDR     (0x18028230)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_EVEN_ADDR    (0x18028234)
#define PPOVERLAY_SRAM_OK_SUB_SET_ADDR             (0x18028238)
#define PPOVERLAY_SRAM_OK_SUB_RESULT_ODD_ADDR      (0x1802823c)
#define PPOVERLAY_SRAM_OK_SUB_RESULT_EVEN_ADDR     (0x18028240)
#define PPOVERLAY_RBUS_CONTROL_ADDR                (0x18028244)
#define PPOVERLAY_NEW_MEAS0_LINECNT_REAL_ADDR      (0x18028248)
#define PPOVERLAY_MEASURE_NOT_FRAME_SYNC_LINE_PIXELS_MAIN_PATH_ADDR  (0x1802824c)
#define PPOVERLAY_MEASURE_NOT_FRAME_SYNC_LINE_PIXELS_SUB_PATH_ADDR  (0x18028250)
#define PPOVERLAY_D_DOMAIN_COUNTER_DVS_CTRL_ADDR   (0x18028254)
#define PPOVERLAY_FS54_CTRL_ADDR                   (0x18028260)
#define PPOVERLAY_FS54_DH_ADDR                     (0x18028264)
#define PPOVERLAY_FS54_DV_ADDR                     (0x18028268)
#define PPOVERLAY_FS54_DV_DLY_ADDR                 (0x1802826c)
#define PPOVERLAY_FS54_DCLK_COUNTER_ADDR           (0x18028270)
#define PPOVERLAY_FS54_DCLK_M_ADDR                 (0x18028274)
#define PPOVERLAY_FS54_DCLK_N_ADDR                 (0x18028278)
#define PPOVERLAY_FS54_PSEUDO_DV_ADDR              (0x1802827c)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_CTRL_ADDR     (0x18028280)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_STATUS1_ADDR  (0x18028284)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_STATUS2_ADDR  (0x18028288)
#define PPOVERLAY_XTAL_COUNT_ICLK_CTRL_ADDR        (0x18028290)
#define PPOVERLAY_DCLK_SEL_ADDR                    (0x18028294)
#define PPOVERLAY_DMA_3D_CTRL_ADDR                 (0x18028298)
#define PPOVERLAY_D3DTG_DV_TOTAL_ADDR              (0x1802829c)
#define PPOVERLAY_D3DTG_DH_TOTAL_ADDR              (0x180282a0)
#define PPOVERLAY_D3DTG_DV_DEN_START_END_ADDR      (0x180282a4)
#define PPOVERLAY_D3DTG_DH_DEN_START_END_ADDR      (0x180282a8)
#define PPOVERLAY_OSD1_3D_OFFSET_ADDR              (0x180282b4)
#define PPOVERLAY_OSD2_3D_OFFSET_ADDR              (0x180282b8)
#define PPOVERLAY_SUBT_3D_OFFSET_ADDR              (0x180282bc)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_LEFT_ADDR    (0x180282c4)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_RIGHT_ADDR   (0x180282c8)
#define PPOVERLAY_LFLAG_GEN_ADDR                   (0x180282cc)
#define PPOVERLAY_DEN_H_EXTEND_ADDR                (0x180282d0)
#define PPOVERLAY_IVS_CNT_ADDR                     (0x180282d4)
#define PPOVERLAY_DVS_CNT_ADDR                     (0x180282d8)
#define PPOVERLAY_D3DTG_DVS_CNT_ADDR               (0x180282dc)

#define PPOVERLAY_DISPLAY_TIMING_CTRL1_VADDR       (0xb8028000)
#define PPOVERLAY_DISPLAY_TIMING_CTRL2_VADDR       (0xb8028004)
#define PPOVERLAY_DH_WIDTH_VADDR                   (0xb8028008)
#define PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_VADDR  (0xb802800c)
#define PPOVERLAY_DV_LENGTH_VADDR                  (0xb8028010)
#define PPOVERLAY_DV_TOTAL_VADDR                   (0xb8028014)
#define PPOVERLAY_DH_DEN_START_END_VADDR           (0xb8028018)
#define PPOVERLAY_DV_DEN_START_END_VADDR           (0xb802801c)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING_VADDR       (0xb8028020)
#define PPOVERLAY_DISPLAY_BACKGROUND_COLOR_VADDR   (0xb8028024)
#define PPOVERLAY_DOUBLE_BUFFER_CTRL_VADDR         (0xb8028028)
#define PPOVERLAY_DVS_PHASE_ERROR_SET_VADDR        (0xb802802c)
#define PPOVERLAY_MEASURE_TWO_DVS_PHASE_ERROR_RESULT_VADDR  (0xb8028030)
#define PPOVERLAY_MEASURE_TOTAL_PIXELS_RESULT1_VADDR  (0xb8028034)
#define PPOVERLAY_MEASURE_TOTAL_PIXELS_RESULT2_VADDR  (0xb8028038)
#define PPOVERLAY_MEASURE_DVTOTAL_LAST_LINE_PIXELS_RESULT1_VADDR  (0xb802803c)
#define PPOVERLAY_MEASURE_DVTOTAL_LAST_LINE_PIXELS_RESULT2_VADDR  (0xb8028040)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING3_VADDR      (0xb8028044)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING4_VADDR      (0xb8028048)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING1_VADDR      (0xb802804c)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING2_VADDR      (0xb8028050)
#define PPOVERLAY_DVS_ABNORMAL_CONTROL_VADDR       (0xb8028054)
#define PPOVERLAY_FS_IV_DV_FINE_TUNING5_VADDR      (0xb8028058)
#define PPOVERLAY_NEW_FIX_LAST_LINE_MODE_CONTROL_VADDR  (0xb8028060)
#define PPOVERLAY_FS_FLL_MODE_CONTROL_VADDR        (0xb8028064)
#define PPOVERLAY_DTG_IE_VADDR                     (0xb80280f0)
#define PPOVERLAY_DTG_PENDING_STATUS_VADDR         (0xb80280f4)
#define PPOVERLAY_DTG_NO_IE_PENDING_STATUS_VADDR   (0xb80280f8)
#define PPOVERLAY_MAIN_DISPLAY_CONTROL_RSV_VADDR   (0xb8028100)
#define PPOVERLAY_MAIN_DISPLAY_CONTROL_VADDR       (0xb8028104)
#define PPOVERLAY_MAIN_BORDER_HIGHLIGHT_BORDER_COLOR_VADDR  (0xb8028108)
#define PPOVERLAY_MAIN_BACKGROUND_COLOR_VADDR      (0xb802810c)
#define PPOVERLAY_MAIN_DEN_H_START_END_VADDR       (0xb8028110)
#define PPOVERLAY_MAIN_DEN_V_START_END_VADDR       (0xb8028114)
#define PPOVERLAY_MAIN_BACKGROUND_H_START_END_VADDR  (0xb8028118)
#define PPOVERLAY_MAIN_BACKGROUND_V_START_END_VADDR  (0xb802811c)
#define PPOVERLAY_MAIN_ACTIVE_H_START_END_VADDR    (0xb8028120)
#define PPOVERLAY_MAIN_ACTIVE_V_START_END_VADDR    (0xb8028124)
#define PPOVERLAY_HIGHLIGHT_WINDOW_CONTROL_VADDR   (0xb8028128)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_INITIAL_START_WIDTH_VADDR  (0xb802812c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_INITIAL_START_HEIGHT_VADDR  (0xb8028130)
#define PPOVERLAY_HIGHLIGHT_WINDOW_UPDATE_STEP_VADDR  (0xb8028134)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_BOUNDARY_VADDR  (0xb8028138)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_BOUNDARY_VADDR  (0xb802813c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_H_STATUS_VADDR  (0xb8028140)
#define PPOVERLAY_HIGHLIGHT_WINDOW_V_STATUS_VADDR  (0xb8028144)
#define PPOVERLAY_HIGHLIGHT_WINDOW_BOUNDARY_CONDITION_VADDR  (0xb8028148)
#define PPOVERLAY_HIGHLIGHT_WINDOW_BORDER_WIDTH_VADDR  (0xb802814c)
#define PPOVERLAY_HIGHLIGHT_WINDOW_MIN_STATUS_VADDR  (0xb8028150)
#define PPOVERLAY_HIGHLIGHT_WINDOW_DB_CTRL_VADDR   (0xb8028154)
#define PPOVERLAY_MP_DISP_ENABLE_VADDR             (0xb8028200)
#define PPOVERLAY_MP_LAYOUT_FORCE_TO_BACKGROUND_VADDR  (0xb8028204)
#define PPOVERLAY_SUB_BORDER_HIGHLIGHT_BORDER_COLOR_VADDR  (0xb8028208)
#define PPOVERLAY_SUB_BACKGROUND_COLOR_VADDR       (0xb802820c)
#define PPOVERLAY_SUB_DEN_H_START_WIDTH_VADDR      (0xb8028210)
#define PPOVERLAY_SUB_DEN_V_START_LENGTH_VADDR     (0xb8028214)
#define PPOVERLAY_SUB_BACKGROUND_H_START_END_VADDR (0xb8028218)
#define PPOVERLAY_SUB_BACKGROUND_V_START_END_VADDR (0xb802821c)
#define PPOVERLAY_SUB_ACTIVE_H_START_END_VADDR     (0xb8028220)
#define PPOVERLAY_SUB_ACTIVE_V_START_END_VADDR     (0xb8028224)
#define PPOVERLAY_DTG_LC_VADDR                     (0xb8028228)
#define PPOVERLAY_SRAM_OK_MAIN_SET_VADDR           (0xb802822c)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_ODD_VADDR    (0xb8028230)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_EVEN_VADDR   (0xb8028234)
#define PPOVERLAY_SRAM_OK_SUB_SET_VADDR            (0xb8028238)
#define PPOVERLAY_SRAM_OK_SUB_RESULT_ODD_VADDR     (0xb802823c)
#define PPOVERLAY_SRAM_OK_SUB_RESULT_EVEN_VADDR    (0xb8028240)
#define PPOVERLAY_RBUS_CONTROL_VADDR               (0xb8028244)
#define PPOVERLAY_NEW_MEAS0_LINECNT_REAL_VADDR     (0xb8028248)
#define PPOVERLAY_MEASURE_NOT_FRAME_SYNC_LINE_PIXELS_MAIN_PATH_VADDR  (0xb802824c)
#define PPOVERLAY_MEASURE_NOT_FRAME_SYNC_LINE_PIXELS_SUB_PATH_VADDR  (0xb8028250)
#define PPOVERLAY_D_DOMAIN_COUNTER_DVS_CTRL_VADDR  (0xb8028254)
#define PPOVERLAY_FS54_CTRL_VADDR                  (0xb8028260)
#define PPOVERLAY_FS54_DH_VADDR                    (0xb8028264)
#define PPOVERLAY_FS54_DV_VADDR                    (0xb8028268)
#define PPOVERLAY_FS54_DV_DLY_VADDR                (0xb802826c)
#define PPOVERLAY_FS54_DCLK_COUNTER_VADDR          (0xb8028270)
#define PPOVERLAY_FS54_DCLK_M_VADDR                (0xb8028274)
#define PPOVERLAY_FS54_DCLK_N_VADDR                (0xb8028278)
#define PPOVERLAY_FS54_PSEUDO_DV_VADDR             (0xb802827c)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_CTRL_VADDR    (0xb8028280)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_STATUS1_VADDR (0xb8028284)
#define PPOVERLAY_FIX_LAST_LINE_EXIT_STATUS2_VADDR (0xb8028288)
#define PPOVERLAY_XTAL_COUNT_ICLK_CTRL_VADDR       (0xb8028290)
#define PPOVERLAY_DCLK_SEL_VADDR                   (0xb8028294)
#define PPOVERLAY_DMA_3D_CTRL_VADDR                (0xb8028298)
#define PPOVERLAY_D3DTG_DV_TOTAL_VADDR             (0xb802829c)
#define PPOVERLAY_D3DTG_DH_TOTAL_VADDR             (0xb80282a0)
#define PPOVERLAY_D3DTG_DV_DEN_START_END_VADDR     (0xb80282a4)
#define PPOVERLAY_D3DTG_DH_DEN_START_END_VADDR     (0xb80282a8)
#define PPOVERLAY_OSD1_3D_OFFSET_VADDR             (0xb80282b4)
#define PPOVERLAY_OSD2_3D_OFFSET_VADDR             (0xb80282b8)
#define PPOVERLAY_SUBT_3D_OFFSET_VADDR             (0xb80282bc)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_LEFT_VADDR   (0xb80282c4)
#define PPOVERLAY_SRAM_OK_MAIN_RESULT_RIGHT_VADDR  (0xb80282c8)
#define PPOVERLAY_LFLAG_GEN_VADDR                  (0xb80282cc)
#define PPOVERLAY_DEN_H_EXTEND_VADDR               (0xb80282d0)
#define PPOVERLAY_IVS_CNT_VADDR                    (0xb80282d4)
#define PPOVERLAY_DVS_CNT_VADDR                    (0xb80282d8)
#define PPOVERLAY_D3DTG_DVS_CNT_VADDR              (0xb80282dc)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PPOVERLAY register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_frc_fsync:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_frc_on_fsync:1;
        RBus_UInt32  disp_line_4x:1;
        RBus_UInt32  disp_fix_last_line:1;
        RBus_UInt32  disp_fsync_en:1;
        RBus_UInt32  disp_data_fsync_mode:1;
        RBus_UInt32  disp_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  double_dvs_en:1;
        RBus_UInt32  wde_to_free_run:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dout_force_bg:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dhs_first_mask:1;
        RBus_UInt32  res5:5;
        RBus_UInt32  gat_sw_en:1;
        RBus_UInt32  fsync_fll_mode:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  gat_seq:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  auto_switch_fll_to_fs:1;
        RBus_UInt32  res8:3;
    };
}display_timing_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_mode:2;
        RBus_UInt32  sr_pixel_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  uzu_sram_free:1;
        RBus_UInt32  shpnr_line_mode:2;
        RBus_UInt32  repeat_flag_mode:2;
        RBus_UInt32  mfield_flag_mode:2;
        RBus_UInt32  res2:16;
        RBus_UInt32  frc2fsync_protection:1;
        RBus_UInt32  frc2fsync_speedup_period:1;
        RBus_UInt32  frc2fsync_speedup_en:1;
        RBus_UInt32  frc2fsync_en:1;
    };
}display_timing_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dh_width:8;
    };
}dh_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dh_total:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dh_total_last_line:13;
    };
}dh_total_last_line_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dv_length:8;
    };
}dv_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  dv_total:13;
    };
}dv_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dh_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dh_den_end:13;
    };
}dh_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dv_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dv_den_end:13;
    };
}dv_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  db_vs_m2bg:1;
        RBus_UInt32  db_vs_s2bg:1;
        RBus_UInt32  dummy18028020_1_0:2;
    };
}fs_iv_dv_fine_tuning_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  d_bg_r:8;
        RBus_UInt32  d_bg_g:8;
        RBus_UInt32  d_bg_b:8;
    };
}display_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf_en_n:1;
        RBus_UInt32  dreg_dbuf_read_sel:1;
        RBus_UInt32  dreg_dbuf_set:1;
    };
}double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  old_fll_unlocked_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  w_value_th:13;
    };
}dvs_phase_error_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  two_dvs_phase_error_cntr:1;
        RBus_UInt32  two_dvs_phase_error_flag:1;
        RBus_UInt32  two_dvs_phase_error_po:1;
        RBus_UInt32  two_dvs_phase_error:22;
    };
}measure_two_dvs_phase_error_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_topixels_ctr:1;
        RBus_UInt32  measure_topixels_mode:1;
        RBus_UInt32  measure_topixels_2f:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  total_pixels_first_cnt:28;
    };
}measure_total_pixels_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  total_pixels_second_cnt:28;
    };
}measure_total_pixels_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_dvllpixels_ctr:1;
        RBus_UInt32  measure_dvllpixels_mode:1;
        RBus_UInt32  measure_dvllpixels_2f:1;
        RBus_UInt32  dv_total_value_first:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  last_line_value_first:13;
    };
}measure_dvtotal_last_line_pixels_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dv_total_value_second:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  last_line_value_second:13;
    };
}measure_dvtotal_last_line_pixels_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028044_31_29:3;
        RBus_UInt32  iv2dv_3d_line_l:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_3d_line_r:13;
    };
}fs_iv_dv_fine_tuning3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_3d_pixel_r:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_3d_pixel2_l:13;
    };
}fs_iv_dv_fine_tuning4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802804c_31_30:2;
        RBus_UInt32  iv2dv_3d_flag_en:1;
        RBus_UInt32  iv2dv_3d_flag_inv:1;
        RBus_UInt32  dummy1802804c_27_26:2;
        RBus_UInt32  res1:22;
        RBus_UInt32  iv2dv_toggle_en:1;
        RBus_UInt32  iv2dv_toggle_inv:1;
        RBus_UInt32  dummy1802804c_1_0:2;
    };
}fs_iv_dv_fine_tuning1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_pixel:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_pixel2:13;
    };
}fs_iv_dv_fine_tuning2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvs_abnormal_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dvs_long_line_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dvs_short_line_th:13;
    };
}dvs_abnormal_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028058_31_29:3;
        RBus_UInt32  iv2dv_line:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_line_2:13;
    };
}fs_iv_dv_fine_tuning5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  iv2dv_line_new_fll:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_pixel_new_fll:13;
    };
}new_fix_last_line_mode_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs_fll_range_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  win_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  win_end:13;
    };
}fs_fll_mode_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  d_counter_dvs_ie:1;
        RBus_UInt32  db_vs_irq_en:1;
        RBus_UInt32  dvs_long_event:1;
        RBus_UInt32  dvs_short_event:1;
        RBus_UInt32  fll_exit_irq_en:1;
        RBus_UInt32  fix_last_line_ivs_too_close_event_ie:1;
        RBus_UInt32  fix_last_line_no_ivs_event_ie:1;
        RBus_UInt32  fix_last_line_less_than_th_event_ie:1;
        RBus_UInt32  fix_last_line_more_than_th_event_ie:1;
        RBus_UInt32  fix_last_line_less_event_ie:1;
        RBus_UInt32  fix_last_line_more_event_ie:1;
        RBus_UInt32  auto_switch_x_event_ie:1;
        RBus_UInt32  dtg_vlc_ie:1;
        RBus_UInt32  sv_den_sta_event_ie:1;
        RBus_UInt32  sv_den_end_event_ie:1;
        RBus_UInt32  mv_den_sta_event_ie:1;
        RBus_UInt32  mv_den_end_event_ie:1;
    };
}dtg_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  d_counter_dvs_irq:1;
        RBus_UInt32  double_vs_error_flag:1;
        RBus_UInt32  dvs_long:1;
        RBus_UInt32  dvs_short:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  fix_last_line_ivs_too_close_event:1;
        RBus_UInt32  fix_last_line_no_ivs_event:1;
        RBus_UInt32  fix_last_line_less_than_th_event:1;
        RBus_UInt32  fix_last_line_more_than_th_event:1;
        RBus_UInt32  fix_last_line_less_event:1;
        RBus_UInt32  fix_last_line_more_event:1;
        RBus_UInt32  auto_switch_x_event:1;
        RBus_UInt32  dtg_vlc_status:1;
        RBus_UInt32  sv_den_sta_event:1;
        RBus_UInt32  sv_den_end_event:1;
        RBus_UInt32  mv_den_sta_event:1;
        RBus_UInt32  mv_den_end_event:1;
    };
}dtg_pending_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  d3dtg_fsync_err:1;
        RBus_UInt32  hlw_error_flag:1;
        RBus_UInt32  hlw_bc1_flag:1;
        RBus_UInt32  hlw_bc2_flag:1;
        RBus_UInt32  hlw_bc3_flag:1;
        RBus_UInt32  hlw_bc4_flag:1;
        RBus_UInt32  hlw_bc5_flag:1;
        RBus_UInt32  old_fll_unlocked_event:1;
    };
}dtg_no_ie_pending_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  main_wd_to_background:1;
        RBus_UInt32  main_wd_to_free_run:1;
        RBus_UInt32  dummy18028100_13_4:10;
        RBus_UInt32  m_hbd_en:1;
        RBus_UInt32  m_bd_trans:1;
        RBus_UInt32  m_force_bg:1;
        RBus_UInt32  m_disp_en:1;
    };
}main_display_control_rsv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}main_display_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  m_bd_r:4;
        RBus_UInt32  m_bd_g:4;
        RBus_UInt32  m_bd_b:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_hbd_r:4;
        RBus_UInt32  m_hbd_g:4;
        RBus_UInt32  m_hbd_b:4;
    };
}main_border_highlight_border_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  m_bg_r:4;
        RBus_UInt32  m_bg_g:4;
        RBus_UInt32  m_bg_b:4;
    };
}main_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mh_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_den_end:13;
    };
}main_den_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_den_end:13;
    };
}main_den_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mh_bg_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_bg_end:13;
    };
}main_background_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_bg_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_bg_end:13;
    };
}main_background_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mh_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_act_end:13;
    };
}main_active_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_act_end:13;
    };
}main_active_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hlw_update_rate:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  hlw_mode:2;
        RBus_UInt32  hlw_en:1;
    };
}highlight_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_h_ini_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_ini_width:13;
    };
}highlight_window_h_initial_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_v_ini_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_ini_height:13;
    };
}highlight_window_v_initial_start_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_h_sta_step:8;
        RBus_UInt32  hlw_width_step:8;
        RBus_UInt32  hlw_v_sta_step:8;
        RBus_UInt32  hlw_height_step:8;
    };
}highlight_window_update_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_h_bd_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_h_bd_end:13;
    };
}highlight_window_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_v_bd_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_v_bd_end:13;
    };
}highlight_window_v_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_h_cur_sta_pos:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_cur_width:13;
    };
}highlight_window_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_v_cur_sta_pos:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_cur_height:13;
    };
}highlight_window_v_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hlw_v_sta_dir_inv_bc1_en:1;
        RBus_UInt32  hlw_v_sta_dir_inv_bc2_en:1;
        RBus_UInt32  hlw_h_sta_dir_inv_bc3_en:1;
        RBus_UInt32  hlw_h_sta_dir_inv_bc4_en:1;
    };
}highlight_window_boundary_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hlw_up_bd_w:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hlw_down_bd_w:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hlw_left_bd_w:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  hlw_right_bd_w:6;
    };
}highlight_window_border_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hlw_min_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_min_height:13;
    };
}highlight_window_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  hlw_db_en_n:1;
        RBus_UInt32  hlw_db_read_sel:1;
        RBus_UInt32  hlw_db_apply:1;
    };
}highlight_window_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_disp_en:16;
        RBus_UInt32  mp_hbd_en:16;
    };
}mp_disp_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_force_bg:16;
        RBus_UInt32  sub_wd_to_background:1;
        RBus_UInt32  sub_wd_to_free_run:1;
        RBus_UInt32  dummy18028204_13_8:6;
        RBus_UInt32  mph_layout:2;
        RBus_UInt32  mpv_layout:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_bd_trans:1;
        RBus_UInt32  s_force_bg:1;
        RBus_UInt32  s_disp_en:1;
    };
}mp_layout_force_to_background_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  s_bd_r:4;
        RBus_UInt32  s_bd_g:4;
        RBus_UInt32  s_bd_b:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  s_hbd_r:4;
        RBus_UInt32  s_hbd_g:4;
        RBus_UInt32  s_hbd_b:4;
    };
}sub_border_highlight_border_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  s_bg_r:4;
        RBus_UInt32  s_bg_g:4;
        RBus_UInt32  s_bg_b:4;
    };
}sub_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sh_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_den_width:13;
    };
}sub_den_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sv_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_den_length:13;
    };
}sub_den_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sh_bg_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_bg_end:13;
    };
}sub_background_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sv_bg_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_bg_end:13;
    };
}sub_background_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sh_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_act_end:13;
    };
}sub_active_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_act_end:13;
    };
}sub_active_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtg_vlcen:1;
        RBus_UInt32  dtg_vlc_mode:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  dtg_vlc_src_sel:1;
        RBus_UInt32  dummy18028228_15_13:3;
        RBus_UInt32  dtg_vln:13;
    };
}dtg_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sram_ok_main_meas_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sram_ok_main_line_th:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  sram_ok_main_16pix_th:8;
    };
}sram_ok_main_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028230_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_main_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_main_odd:13;
    };
}sram_ok_main_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028234_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_main_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_main_even:13;
    };
}sram_ok_main_result_even_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sram_ok_sub_meas_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sram_ok_sub_line_th:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  sram_ok_sub_16pix_th:8;
    };
}sram_ok_sub_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802823c_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_sub_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_sub_odd:13;
    };
}sram_ok_sub_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028240_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_sub_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_sub_even:13;
    };
}sram_ok_sub_result_even_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  rbus_reset:1;
    };
}rbus_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d3dtg_line_cnt_rt:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  line_cnt_rt:13;
    };
}new_meas0_linecnt_real_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_not_fs_line_pixel_en:1;
        RBus_UInt32  m_field_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  m_not_fs_line_value:13;
        RBus_UInt32  m_underflow_flag:1;
        RBus_UInt32  m_overflow_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m_not_fs_pixel_value:13;
    };
}measure_not_frame_sync_line_pixels_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_not_fs_line_pixel_en:1;
        RBus_UInt32  s_field_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_not_fs_line_value:13;
        RBus_UInt32  s_underflow_flag:1;
        RBus_UInt32  s_overflow_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  s_not_fs_pixel_value:13;
    };
}measure_not_frame_sync_line_pixels_sub_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_counter_dvs_en:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  d_counter_dvs_mask:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_counter_dvs_set:13;
    };
}d_domain_counter_dvs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_en:1;
        RBus_UInt32  fs54_db_load:1;
        RBus_UInt32  fs54_frc_fastslow:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  fs54_main_sub_sel:1;
        RBus_UInt32  fs54_force:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  fs54_vs_align:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  fs54_timing_en:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  fs54_pseudo_fsync_en:1;
        RBus_UInt32  fs54_dclk_slow_modify_en:1;
        RBus_UInt32  fs54_dclk_en:1;
    };
}fs54_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fs54_dh_total:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_dh_last_line:13;
    };
}fs54_dh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  fs54_dv_total:13;
    };
}fs54_dv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fs54_iv2dv_pixel:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_iv2dv_line:13;
    };
}fs54_dv_dly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  fs54_dclk_slow_modify_counter:12;
    };
}fs54_dclk_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  fs54_dclk_m_fs54:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  fs54_dclk_m_ori:10;
    };
}fs54_dclk_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fs54_dclk_n_fs54:8;
        RBus_UInt32  fs54_dclk_n_ori:8;
    };
}fs54_dclk_n_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fs54_pseudo_dv:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_pseudo_offset:13;
    };
}fs54_pseudo_dv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fix_last_line_exit_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  more_line_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  less_line_th:13;
    };
}fix_last_line_exit_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  fll_status_counter:13;
    };
}fix_last_line_exit_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  wd_fix_last_more_en:1;
        RBus_UInt32  wd_fix_last_less_en:1;
        RBus_UInt32  wd_fix_last_more_than_th_en:1;
        RBus_UInt32  wd_fix_last_less_than_th_en:1;
        RBus_UInt32  wd_fix_last_no_ivs_en:1;
        RBus_UInt32  wd_fix_last_line_ivs_too_close_en:1;
    };
}fix_last_line_exit_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xclk_max:8;
        RBus_UInt32  xclk_min:8;
        RBus_UInt32  iclk_num:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  auto_switch_x_en:1;
    };
}xtal_count_iclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dclk_sel_by_vs_en:1;
        RBus_UInt32  dclk_sel:2;
    };
}dclk_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_mode_revised:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  d3dtg_dv_line_delay:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  dfrc_pixel_mode_status:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  d3dtg_frc_fsync_status:1;
        RBus_UInt32  d3dtg_frc2fsync_by_hw:1;
        RBus_UInt32  d3dtg_fsync_en:1;
        RBus_UInt32  d3dtg_mode:3;
        RBus_UInt32  d3dtg_en:1;
    };
}dma_3d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  d3dtg_dv_total:13;
    };
}d3dtg_dv_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d3dtg_dh_total_last_line:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dh_total:13;
    };
}d3dtg_dh_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d3dtg_dv_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dv_den_end:13;
    };
}d3dtg_dv_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d3dtg_dh_den_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dh_den_end:13;
    };
}d3dtg_dh_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  right_osd1_dir:1;
        RBus_UInt32  right_osd1_offset:11;
        RBus_UInt32  left_osd1_dir:1;
        RBus_UInt32  left_osd1_offset:11;
    };
}osd1_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  right_osd2_dir:1;
        RBus_UInt32  right_osd2_offset:11;
        RBus_UInt32  left_osd2_dir:1;
        RBus_UInt32  left_osd2_offset:11;
    };
}osd2_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  right_subt_dir:1;
        RBus_UInt32  right_subt_offset:11;
        RBus_UInt32  left_subt_dir:1;
        RBus_UInt32  left_subt_offset:11;
    };
}subt_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180282c4_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_main_left:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_main_left:13;
    };
}sram_ok_main_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180282c8_31_29:3;
        RBus_UInt32  line_cnt_sram_ok_main_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pix_cnt_sram_ok_main_right:13;
    };
}sram_ok_main_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_line_alt:1;
        RBus_UInt32  gdma_osd_lflag_inv:1;
        RBus_UInt32  gdma_subt_line_alt:1;
        RBus_UInt32  gdma_subt_lflag_inv:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  d3dtg_lflag_cnt_reset:1;
        RBus_UInt32  d3dtg_lflag_mode:1;
        RBus_UInt32  d3dtg_lflag_free_run:1;
        RBus_UInt32  d3dtg_lflag_mode_3d:1;
        RBus_UInt32  d3dtg_lflag_inv:1;
        RBus_UInt32  d3dtg_lflag:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  lflag_cnt_reset:1;
        RBus_UInt32  lflag_mode:1;
        RBus_UInt32  lflag_free_run:1;
        RBus_UInt32  lflag_mode_3d:1;
        RBus_UInt32  lflag_inv:1;
        RBus_UInt32  lflag:1;
    };
}lflag_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_h_extend_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  den_h_left_ext:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  den_h_right_ext:13;
    };
}den_h_extend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remove_half_ivs:1;
        RBus_UInt32  remove_half_ivs_mode:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  ivs_cnt:25;
    };
}ivs_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  dvs_cnt:25;
    };
}dvs_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  d3dtg_dvs_cnt:25;
    };
}d3dtg_dvs_cnt_RBUS;





#else //apply LITTLE_ENDIAN


//======PPOVERLAY register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res8:3;
        RBus_UInt32  auto_switch_fll_to_fs:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  gat_seq:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  fsync_fll_mode:1;
        RBus_UInt32  gat_sw_en:1;
        RBus_UInt32  res5:5;
        RBus_UInt32  dhs_first_mask:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dout_force_bg:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  wde_to_free_run:1;
        RBus_UInt32  double_dvs_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  disp_en:1;
        RBus_UInt32  disp_data_fsync_mode:1;
        RBus_UInt32  disp_fsync_en:1;
        RBus_UInt32  disp_fix_last_line:1;
        RBus_UInt32  disp_line_4x:1;
        RBus_UInt32  disp_frc_on_fsync:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_frc_fsync:1;
    };
}display_timing_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc2fsync_en:1;
        RBus_UInt32  frc2fsync_speedup_en:1;
        RBus_UInt32  frc2fsync_speedup_period:1;
        RBus_UInt32  frc2fsync_protection:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  mfield_flag_mode:2;
        RBus_UInt32  repeat_flag_mode:2;
        RBus_UInt32  shpnr_line_mode:2;
        RBus_UInt32  uzu_sram_free:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_pixel_mode:2;
        RBus_UInt32  sr_mode:2;
    };
}display_timing_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dh_width:8;
        RBus_UInt32  res1:24;
    };
}dh_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dh_total_last_line:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dh_total:13;
        RBus_UInt32  res1:3;
    };
}dh_total_last_line_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dv_length:8;
        RBus_UInt32  res1:24;
    };
}dv_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dv_total:13;
        RBus_UInt32  res1:19;
    };
}dv_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dh_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dh_den_sta:13;
        RBus_UInt32  res1:3;
    };
}dh_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dv_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dv_den_sta:13;
        RBus_UInt32  res1:3;
    };
}dv_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18028020_1_0:2;
        RBus_UInt32  db_vs_s2bg:1;
        RBus_UInt32  db_vs_m2bg:1;
        RBus_UInt32  res1:28;
    };
}fs_iv_dv_fine_tuning_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_bg_b:8;
        RBus_UInt32  d_bg_g:8;
        RBus_UInt32  d_bg_r:8;
        RBus_UInt32  res1:8;
    };
}display_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf_set:1;
        RBus_UInt32  dreg_dbuf_read_sel:1;
        RBus_UInt32  dreg_dbuf_en_n:1;
        RBus_UInt32  res1:29;
    };
}double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_value_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  old_fll_unlocked_th:13;
        RBus_UInt32  res1:3;
    };
}dvs_phase_error_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_dvs_phase_error:22;
        RBus_UInt32  two_dvs_phase_error_po:1;
        RBus_UInt32  two_dvs_phase_error_flag:1;
        RBus_UInt32  two_dvs_phase_error_cntr:1;
        RBus_UInt32  res1:7;
    };
}measure_two_dvs_phase_error_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_pixels_first_cnt:28;
        RBus_UInt32  res1:1;
        RBus_UInt32  measure_topixels_2f:1;
        RBus_UInt32  measure_topixels_mode:1;
        RBus_UInt32  measure_topixels_ctr:1;
    };
}measure_total_pixels_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_pixels_second_cnt:28;
        RBus_UInt32  res1:4;
    };
}measure_total_pixels_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  last_line_value_first:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dv_total_value_first:13;
        RBus_UInt32  measure_dvllpixels_2f:1;
        RBus_UInt32  measure_dvllpixels_mode:1;
        RBus_UInt32  measure_dvllpixels_ctr:1;
    };
}measure_dvtotal_last_line_pixels_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  last_line_value_second:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dv_total_value_second:13;
        RBus_UInt32  res1:3;
    };
}measure_dvtotal_last_line_pixels_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2dv_3d_line_r:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_3d_line_l:13;
        RBus_UInt32  dummy18028044_31_29:3;
    };
}fs_iv_dv_fine_tuning3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2dv_3d_pixel2_l:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_3d_pixel_r:13;
        RBus_UInt32  res1:3;
    };
}fs_iv_dv_fine_tuning4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802804c_1_0:2;
        RBus_UInt32  iv2dv_toggle_inv:1;
        RBus_UInt32  iv2dv_toggle_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  dummy1802804c_27_26:2;
        RBus_UInt32  iv2dv_3d_flag_inv:1;
        RBus_UInt32  iv2dv_3d_flag_en:1;
        RBus_UInt32  dummy1802804c_31_30:2;
    };
}fs_iv_dv_fine_tuning1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2dv_pixel2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_pixel:13;
        RBus_UInt32  res1:3;
    };
}fs_iv_dv_fine_tuning2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvs_short_line_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dvs_long_line_th:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  dvs_abnormal_en:1;
    };
}dvs_abnormal_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2dv_line_2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  iv2dv_line:13;
        RBus_UInt32  dummy18028058_31_29:3;
    };
}fs_iv_dv_fine_tuning5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2dv_pixel_new_fll:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  iv2dv_line_new_fll:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_fll_mode:1;
    };
}new_fix_last_line_mode_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  win_sta:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  fs_fll_range_mode:1;
    };
}fs_fll_mode_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_den_end_event_ie:1;
        RBus_UInt32  mv_den_sta_event_ie:1;
        RBus_UInt32  sv_den_end_event_ie:1;
        RBus_UInt32  sv_den_sta_event_ie:1;
        RBus_UInt32  dtg_vlc_ie:1;
        RBus_UInt32  auto_switch_x_event_ie:1;
        RBus_UInt32  fix_last_line_more_event_ie:1;
        RBus_UInt32  fix_last_line_less_event_ie:1;
        RBus_UInt32  fix_last_line_more_than_th_event_ie:1;
        RBus_UInt32  fix_last_line_less_than_th_event_ie:1;
        RBus_UInt32  fix_last_line_no_ivs_event_ie:1;
        RBus_UInt32  fix_last_line_ivs_too_close_event_ie:1;
        RBus_UInt32  fll_exit_irq_en:1;
        RBus_UInt32  dvs_short_event:1;
        RBus_UInt32  dvs_long_event:1;
        RBus_UInt32  db_vs_irq_en:1;
        RBus_UInt32  d_counter_dvs_ie:1;
        RBus_UInt32  res1:15;
    };
}dtg_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_den_end_event:1;
        RBus_UInt32  mv_den_sta_event:1;
        RBus_UInt32  sv_den_end_event:1;
        RBus_UInt32  sv_den_sta_event:1;
        RBus_UInt32  dtg_vlc_status:1;
        RBus_UInt32  auto_switch_x_event:1;
        RBus_UInt32  fix_last_line_more_event:1;
        RBus_UInt32  fix_last_line_less_event:1;
        RBus_UInt32  fix_last_line_more_than_th_event:1;
        RBus_UInt32  fix_last_line_less_than_th_event:1;
        RBus_UInt32  fix_last_line_no_ivs_event:1;
        RBus_UInt32  fix_last_line_ivs_too_close_event:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dvs_short:1;
        RBus_UInt32  dvs_long:1;
        RBus_UInt32  double_vs_error_flag:1;
        RBus_UInt32  d_counter_dvs_irq:1;
        RBus_UInt32  res1:15;
    };
}dtg_pending_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  old_fll_unlocked_event:1;
        RBus_UInt32  hlw_bc5_flag:1;
        RBus_UInt32  hlw_bc4_flag:1;
        RBus_UInt32  hlw_bc3_flag:1;
        RBus_UInt32  hlw_bc2_flag:1;
        RBus_UInt32  hlw_bc1_flag:1;
        RBus_UInt32  hlw_error_flag:1;
        RBus_UInt32  d3dtg_fsync_err:1;
        RBus_UInt32  res1:24;
    };
}dtg_no_ie_pending_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_disp_en:1;
        RBus_UInt32  m_force_bg:1;
        RBus_UInt32  m_bd_trans:1;
        RBus_UInt32  m_hbd_en:1;
        RBus_UInt32  dummy18028100_13_4:10;
        RBus_UInt32  main_wd_to_free_run:1;
        RBus_UInt32  main_wd_to_background:1;
        RBus_UInt32  res1:16;
    };
}main_display_control_rsv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}main_display_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_hbd_b:4;
        RBus_UInt32  m_hbd_g:4;
        RBus_UInt32  m_hbd_r:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_bd_b:4;
        RBus_UInt32  m_bd_g:4;
        RBus_UInt32  m_bd_r:4;
        RBus_UInt32  res1:4;
    };
}main_border_highlight_border_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_bg_b:4;
        RBus_UInt32  m_bg_g:4;
        RBus_UInt32  m_bg_r:4;
        RBus_UInt32  res1:20;
    };
}main_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mh_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_den_sta:13;
        RBus_UInt32  res1:3;
    };
}main_den_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_den_sta:13;
        RBus_UInt32  res1:3;
    };
}main_den_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mh_bg_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_bg_sta:13;
        RBus_UInt32  res1:3;
    };
}main_background_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_bg_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_bg_sta:13;
        RBus_UInt32  res1:3;
    };
}main_background_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mh_act_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mh_act_sta:13;
        RBus_UInt32  res1:3;
    };
}main_active_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_act_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mv_act_sta:13;
        RBus_UInt32  res1:3;
    };
}main_active_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_en:1;
        RBus_UInt32  hlw_mode:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  hlw_update_rate:8;
        RBus_UInt32  res1:16;
    };
}highlight_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_ini_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_h_ini_sta:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_h_initial_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_ini_height:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_v_ini_sta:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_v_initial_start_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_height_step:8;
        RBus_UInt32  hlw_v_sta_step:8;
        RBus_UInt32  hlw_width_step:8;
        RBus_UInt32  hlw_h_sta_step:8;
    };
}highlight_window_update_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_h_bd_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_h_bd_sta:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_v_bd_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_v_bd_sta:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_v_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_cur_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_h_cur_sta_pos:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_cur_height:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_v_cur_sta_pos:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_v_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_h_sta_dir_inv_bc4_en:1;
        RBus_UInt32  hlw_h_sta_dir_inv_bc3_en:1;
        RBus_UInt32  hlw_v_sta_dir_inv_bc2_en:1;
        RBus_UInt32  hlw_v_sta_dir_inv_bc1_en:1;
        RBus_UInt32  res1:28;
    };
}highlight_window_boundary_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_right_bd_w:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  hlw_left_bd_w:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hlw_down_bd_w:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hlw_up_bd_w:6;
        RBus_UInt32  res1:2;
    };
}highlight_window_border_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_min_height:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hlw_min_width:13;
        RBus_UInt32  res1:3;
    };
}highlight_window_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlw_db_apply:1;
        RBus_UInt32  hlw_db_read_sel:1;
        RBus_UInt32  hlw_db_en_n:1;
        RBus_UInt32  res1:29;
    };
}highlight_window_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_hbd_en:16;
        RBus_UInt32  mp_disp_en:16;
    };
}mp_disp_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_disp_en:1;
        RBus_UInt32  s_force_bg:1;
        RBus_UInt32  s_bd_trans:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mpv_layout:2;
        RBus_UInt32  mph_layout:2;
        RBus_UInt32  dummy18028204_13_8:6;
        RBus_UInt32  sub_wd_to_free_run:1;
        RBus_UInt32  sub_wd_to_background:1;
        RBus_UInt32  mp_force_bg:16;
    };
}mp_layout_force_to_background_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_hbd_b:4;
        RBus_UInt32  s_hbd_g:4;
        RBus_UInt32  s_hbd_r:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  s_bd_b:4;
        RBus_UInt32  s_bd_g:4;
        RBus_UInt32  s_bd_r:4;
        RBus_UInt32  res1:4;
    };
}sub_border_highlight_border_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_bg_b:4;
        RBus_UInt32  s_bg_g:4;
        RBus_UInt32  s_bg_r:4;
        RBus_UInt32  res1:20;
    };
}sub_background_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sh_den_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_den_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_den_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_den_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_den_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_den_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sh_bg_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_bg_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_background_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_bg_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_bg_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_background_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sh_act_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_act_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_active_h_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_act_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_act_sta:13;
        RBus_UInt32  res1:3;
    };
}sub_active_v_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtg_vln:13;
        RBus_UInt32  dummy18028228_15_13:3;
        RBus_UInt32  dtg_vlc_src_sel:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  dtg_vlc_mode:1;
        RBus_UInt32  dtg_vlcen:1;
    };
}dtg_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_ok_main_16pix_th:8;
        RBus_UInt32  res3:4;
        RBus_UInt32  sram_ok_main_line_th:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  sram_ok_main_meas_en:1;
        RBus_UInt32  res1:15;
    };
}sram_ok_main_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_main_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_main_odd:13;
        RBus_UInt32  dummy18028230_31_29:3;
    };
}sram_ok_main_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_main_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_main_even:13;
        RBus_UInt32  dummy18028234_31_29:3;
    };
}sram_ok_main_result_even_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_ok_sub_16pix_th:8;
        RBus_UInt32  res3:4;
        RBus_UInt32  sram_ok_sub_line_th:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  sram_ok_sub_meas_en:1;
        RBus_UInt32  res1:15;
    };
}sram_ok_sub_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_sub_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_sub_odd:13;
        RBus_UInt32  dummy1802823c_31_29:3;
    };
}sram_ok_sub_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_sub_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_sub_even:13;
        RBus_UInt32  dummy18028240_31_29:3;
    };
}sram_ok_sub_result_even_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rbus_reset:1;
        RBus_UInt32  res1:31;
    };
}rbus_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_cnt_rt:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_line_cnt_rt:13;
        RBus_UInt32  res1:3;
    };
}new_meas0_linecnt_real_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_not_fs_pixel_value:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  m_overflow_flag:1;
        RBus_UInt32  m_underflow_flag:1;
        RBus_UInt32  m_not_fs_line_value:13;
        RBus_UInt32  res1:1;
        RBus_UInt32  m_field_flag:1;
        RBus_UInt32  m_not_fs_line_pixel_en:1;
    };
}measure_not_frame_sync_line_pixels_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_not_fs_pixel_value:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  s_overflow_flag:1;
        RBus_UInt32  s_underflow_flag:1;
        RBus_UInt32  s_not_fs_line_value:13;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_field_flag:1;
        RBus_UInt32  s_not_fs_line_pixel_en:1;
    };
}measure_not_frame_sync_line_pixels_sub_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_counter_dvs_set:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_counter_dvs_mask:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  d_counter_dvs_en:1;
    };
}d_domain_counter_dvs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dclk_en:1;
        RBus_UInt32  fs54_dclk_slow_modify_en:1;
        RBus_UInt32  fs54_pseudo_fsync_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  fs54_timing_en:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  fs54_vs_align:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  fs54_force:1;
        RBus_UInt32  fs54_main_sub_sel:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  fs54_frc_fastslow:1;
        RBus_UInt32  fs54_db_load:1;
        RBus_UInt32  fs54_en:1;
    };
}fs54_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dh_last_line:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_dh_total:13;
        RBus_UInt32  res1:3;
    };
}fs54_dh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dv_total:13;
        RBus_UInt32  res1:19;
    };
}fs54_dv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_iv2dv_line:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_iv2dv_pixel:13;
        RBus_UInt32  res1:3;
    };
}fs54_dv_dly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dclk_slow_modify_counter:12;
        RBus_UInt32  res1:20;
    };
}fs54_dclk_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dclk_m_ori:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  fs54_dclk_m_fs54:10;
        RBus_UInt32  res1:6;
    };
}fs54_dclk_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_dclk_n_ori:8;
        RBus_UInt32  fs54_dclk_n_fs54:8;
        RBus_UInt32  res1:16;
    };
}fs54_dclk_n_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs54_pseudo_offset:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  fs54_pseudo_dv:13;
        RBus_UInt32  res1:3;
    };
}fs54_pseudo_dv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  less_line_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  more_line_th:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  fix_last_line_exit_en:1;
    };
}fix_last_line_exit_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fll_status_counter:13;
        RBus_UInt32  res1:19;
    };
}fix_last_line_exit_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wd_fix_last_line_ivs_too_close_en:1;
        RBus_UInt32  wd_fix_last_no_ivs_en:1;
        RBus_UInt32  wd_fix_last_less_than_th_en:1;
        RBus_UInt32  wd_fix_last_more_than_th_en:1;
        RBus_UInt32  wd_fix_last_less_en:1;
        RBus_UInt32  wd_fix_last_more_en:1;
        RBus_UInt32  res1:26;
    };
}fix_last_line_exit_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_switch_x_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  iclk_num:8;
        RBus_UInt32  xclk_min:8;
        RBus_UInt32  xclk_max:8;
    };
}xtal_count_iclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_sel:2;
        RBus_UInt32  dclk_sel_by_vs_en:1;
        RBus_UInt32  res1:29;
    };
}dclk_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_en:1;
        RBus_UInt32  d3dtg_mode:3;
        RBus_UInt32  d3dtg_fsync_en:1;
        RBus_UInt32  d3dtg_frc2fsync_by_hw:1;
        RBus_UInt32  d3dtg_frc_fsync_status:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dfrc_pixel_mode_status:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  d3dtg_dv_line_delay:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  d3dtg_mode_revised:1;
    };
}dma_3d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_dv_total:13;
        RBus_UInt32  res1:19;
    };
}d3dtg_dv_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_dh_total:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dh_total_last_line:13;
        RBus_UInt32  res1:3;
    };
}d3dtg_dh_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_dv_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dv_den_sta:13;
        RBus_UInt32  res1:3;
    };
}d3dtg_dv_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_dh_den_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d3dtg_dh_den_sta:13;
        RBus_UInt32  res1:3;
    };
}d3dtg_dh_den_start_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_osd1_offset:11;
        RBus_UInt32  left_osd1_dir:1;
        RBus_UInt32  right_osd1_offset:11;
        RBus_UInt32  right_osd1_dir:1;
        RBus_UInt32  res1:8;
    };
}osd1_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_osd2_offset:11;
        RBus_UInt32  left_osd2_dir:1;
        RBus_UInt32  right_osd2_offset:11;
        RBus_UInt32  right_osd2_dir:1;
        RBus_UInt32  res1:8;
    };
}osd2_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_subt_offset:11;
        RBus_UInt32  left_subt_dir:1;
        RBus_UInt32  right_subt_offset:11;
        RBus_UInt32  right_subt_dir:1;
        RBus_UInt32  res1:8;
    };
}subt_3d_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_main_left:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_main_left:13;
        RBus_UInt32  dummy180282c4_31_29:3;
    };
}sram_ok_main_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_cnt_sram_ok_main_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  line_cnt_sram_ok_main_right:13;
        RBus_UInt32  dummy180282c8_31_29:3;
    };
}sram_ok_main_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lflag:1;
        RBus_UInt32  lflag_inv:1;
        RBus_UInt32  lflag_mode_3d:1;
        RBus_UInt32  lflag_free_run:1;
        RBus_UInt32  lflag_mode:1;
        RBus_UInt32  lflag_cnt_reset:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  d3dtg_lflag:1;
        RBus_UInt32  d3dtg_lflag_inv:1;
        RBus_UInt32  d3dtg_lflag_mode_3d:1;
        RBus_UInt32  d3dtg_lflag_free_run:1;
        RBus_UInt32  d3dtg_lflag_mode:1;
        RBus_UInt32  d3dtg_lflag_cnt_reset:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  gdma_subt_lflag_inv:1;
        RBus_UInt32  gdma_subt_line_alt:1;
        RBus_UInt32  gdma_osd_lflag_inv:1;
        RBus_UInt32  gdma_osd_line_alt:1;
    };
}lflag_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_h_right_ext:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  den_h_left_ext:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  den_h_extend_en:1;
    };
}den_h_extend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ivs_cnt:25;
        RBus_UInt32  res1:3;
        RBus_UInt32  remove_half_ivs_mode:3;
        RBus_UInt32  remove_half_ivs:1;
    };
}ivs_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvs_cnt:25;
        RBus_UInt32  res1:7;
    };
}dvs_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d3dtg_dvs_cnt:25;
        RBus_UInt32  res1:7;
    };
}d3dtg_dvs_cnt_RBUS;


#endif







#endif //_RBUS_PPOVERLAY_REG_H_

