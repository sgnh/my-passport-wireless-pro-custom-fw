/**
* @file rbusSYSTEMReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-8-2
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_SYSTEM_REG_H_
#define _RBUS_SYSTEM_REG_H_

#include "rbusTypes.h"




// SYSTEM Register Address

#define SYSTEM_SC_VERID_VADDR                         (0xb8060000)
#define SYSTEM_SC_LV_RST_VADDR                        (0xb8060004)
#define SYSTEM_SC_POL_VADDR                           (0xb8060008)
#define SYSTEM_ST_CTRL0_VADDR                         (0xb8060010)
#define SYSTEM_ST_SRST0_VADDR                         (0xb8060030)
#define SYSTEM_ST_SRST1_VADDR                         (0xb8060034)
#define SYSTEM_ST_CLKEN0_VADDR                        (0xb8060040)
#define SYSTEM_ST_CLKEN1_VADDR                        (0xb8060044)
#define SYSTEM_ST_BUSCLK_VADDR                        (0xb8060050)
#define SYSTEM_ST_EMCUCLK_VADDR                       (0xb8060054)
#define SYSTEM_ST_CLKMUX_VADDR                        (0xb8060058)
#define SYSTEM_ST_ALU_0_VADDR                         (0xb806005c)
#define SYSTEM_ALU_IE_VADDR                           (0xb8060060)
#define SYSTEM_ALU_IP_VADDR                           (0xb8060064)
#define SYSTEM_ALU_PASS_VADDR                         (0xb8060068)
#define SYSTEM_STB_IRQ_ALL_VADDR                      (0xb806006c)
#define SYSTEM_ST_RING_OSC_0_VADDR                    (0xb80600e4)
#define SYSTEM_ST_RING_OSC_1_VADDR                    (0xb80600e8)
#define SYSTEM_ST_DBG_1_VADDR                         (0xb80600f0)
#define SYSTEM_WDOG_DATA1_VADDR                       (0xb8060100)
#define SYSTEM_WDOG_DATA2_VADDR                       (0xb8060104)
#define SYSTEM_WDOG_DATA3_VADDR                       (0xb8060108)
#define SYSTEM_WDOG_DATA4_VADDR                       (0xb806010c)
#define SYSTEM_WDOG_DATA5_VADDR                       (0xb8060110)
#define SYSTEM_WDOG_DATA6_VADDR                       (0xb8060114)
#define SYSTEM_WDOG_DATA7_VADDR                       (0xb8060118)
#define SYSTEM_WDOG_DATA8_VADDR                       (0xb806011c)
#define SYSTEM_WDOG_DATA9_VADDR                       (0xb8060120)
#define SYSTEM_WDOG_DATA10_VADDR                      (0xb8060124)
#define SYSTEM_WDOG_DATA11_VADDR                      (0xb8060128)
#define SYSTEM_WDOG_DATA12_VADDR                      (0xb806012c)
#define SYSTEM_SYS_SRST0_VADDR                        (0xb8000100)
#define SYSTEM_SYS_SRST1_VADDR                        (0xb8000104)
#define SYSTEM_SYS_SRST2_VADDR                        (0xb8000108)
#define SYSTEM_SYS_SRST3_VADDR                        (0xb800010c)
#define SYSTEM_SYS_CLKEN0_VADDR                       (0xb8000110)
#define SYSTEM_SYS_CLKEN1_VADDR                       (0xb8000114)
#define SYSTEM_SYS_CLKEN2_VADDR                       (0xb8000118)
#define SYSTEM_SYS_CLKEN3_VADDR                       (0xb800011c)
#define SYSTEM_SYS_CPUSEL_VADDR                       (0xb8000200)
#define SYSTEM_SYS_CLKSEL_VADDR                       (0xb8000204)
#define SYSTEM_SYS_CLKDIV_VADDR                       (0xb8000214)
#define SYSTEM_SYS_ARM_WD_VADDR                       (0xb8000218)
#define SYSTEM_SYS_TVSB1_VADDR                        (0xb800021c)
#define SYSTEM_EFUSE_CTRL0_VADDR                      (0xb8000240)
#define SYSTEM_POWER_CTRL0_VADDR                      (0xb8000260)
#define SYSTEM_TM_CTRL0_VADDR                         (0xb8000280)
#define SYSTEM_TM_CTRL1_VADDR                         (0xb8000284)
#define SYSTEM_TM_CTRL2_VADDR                         (0xb800028c)
#define SYSTEM_SS_12T_LVT_0_VADDR                     (0xb8008f50)
#define SYSTEM_SS_12T_LVT_1_VADDR                     (0xb8008f54)
#define SYSTEM_SS_12T_RVT_0_VADDR                     (0xb8000298)
#define SYSTEM_SS_12T_RVT_1_VADDR                     (0xb800029c)
#define SYSTEM_SS_9T_LVT_0_VADDR                      (0xb80006c0)
#define SYSTEM_SS_9T_LVT_1_VADDR                      (0xb80006c4)
#define SYSTEM_SS_9T_RVT_0_VADDR                      (0xb80006c8)
#define SYSTEM_SS_9T_RVT_1_VADDR                      (0xb80006cc)
#define SYSTEM_SS_7T_0_VADDR                          (0xb801c3f0)
#define SYSTEM_SS_7T_1_VADDR                          (0xb801c3f4)
#define SYSTEM_SC_DEBUG_0_VADDR                       (0xb8000310)
#define SYSTEM_SYS_PLL_SCPU1_VADDR                    (0xb8000400)
#define SYSTEM_SYS_PLL_SCPU2_VADDR                    (0xb8000404)
#define SYSTEM_SYS_PLL_ACPU1_VADDR                    (0xb8000408)
#define SYSTEM_SYS_PLL_ACPU2_VADDR                    (0xb800040c)
#define SYSTEM_SYS_PLL_VCPU1_VADDR                    (0xb8000410)
#define SYSTEM_SYS_PLL_VCPU2_VADDR                    (0xb8000414)
#define SYSTEM_SYS_PLL_CPU_VADDR                      (0xb800041c)
#define SYSTEM_SYS_PLL_BUS1_VADDR                     (0xb8000420)
#define SYSTEM_SYS_PLL_BUS2_VADDR                     (0xb8000424)
#define SYSTEM_SYS_PLL_BUS3_VADDR                     (0xb8000428)
#define SYSTEM_SYS_PLL_H_BUS1_VADDR                   (0xb8000430)
#define SYSTEM_SYS_PLL_H_BUS2_VADDR                   (0xb8000434)
#define SYSTEM_SYS_PLL_H_BUS3_VADDR                   (0xb8000438)
#define SYSTEM_SYS_PLL_2_BUS1_VADDR                   (0xb8000440)
#define SYSTEM_SYS_PLL_2_BUS2_VADDR                   (0xb8000444)
#define SYSTEM_SYS_PLL_2_BUS3_VADDR                   (0xb8000448)
#define SYSTEM_SYS_PLL_GPU1_VADDR                     (0xb8000450)
#define SYSTEM_SYS_PLL_GPU2_VADDR                     (0xb8000454)
#define SYSTEM_SYS_PLL_2_GPU1_VADDR                   (0xb8000458)
#define SYSTEM_SYS_PLL_2_GPU2_VADDR                   (0xb800045c)
#define SYSTEM_SYS_PLL_VODMA1_VADDR                   (0xb8000460)
#define SYSTEM_SYS_PLL_VODMA2_VADDR                   (0xb8000464)
#define SYSTEM_SYS_PLLBUS_TST_VADDR                   (0xb8000468)
#define SYSTEM_SYS_PLL_DISP_SD1_VADDR                 (0xb8000470)
#define SYSTEM_SYS_PLL_DISP_SD2_VADDR                 (0xb8000474)
#define SYSTEM_SYS_PLL_DISP_SD3_VADDR                 (0xb8000478)
#define SYSTEM_SYS_PLL_DISP_SD4_VADDR                 (0xb800047c)
#define SYSTEM_SYS_PLL_DISP_SD5_VADDR                 (0xb8000480)
#define SYSTEM_SYS_PLL_DISP_SD6_VADDR                 (0xb8000484)
#define SYSTEM_SYS_PLL_DISP_SD7_VADDR                 (0xb8000488)
#define SYSTEM_AI_CLKCR_VADDR                         (0xb800048c)
#define SYSTEM_SYS_PLL_DISP1_VADDR                    (0xb8000490)
#define SYSTEM_SYS_PLL_DISP2_VADDR                    (0xb8000494)
#define SYSTEM_SYS_PLL_VBY11_VADDR                    (0xb8000498)
#define SYSTEM_SYS_PLL_VBY12_VADDR                    (0xb800049c)
#define SYSTEM_SYS_PLL_ETN1_VADDR                     (0xb80004a0)
#define SYSTEM_SYS_PLL_ETN2_VADDR                     (0xb80004a4)
#define SYSTEM_SYS_PLL_WD_OUT_VADDR                   (0xb80004ac)
#define SYSTEM_SYS_PLL_512FS1_VADDR                   (0xb80004b0)
#define SYSTEM_SYS_PLL_512FS2_VADDR                   (0xb80004b4)
#define SYSTEM_SYS_PLL_DIF1_VADDR                     (0xb80004c0)
#define SYSTEM_SYS_PLL_DIF2_VADDR                     (0xb80004c4)
#define SYSTEM_SYS_PLL_DIF3_VADDR                     (0xb80004c8)
#define SYSTEM_SYS_PLL_27X1_VADDR                     (0xb80004d0)
#define SYSTEM_SYS_PLL_27X2_VADDR                     (0xb80004d4)
#define SYSTEM_SYS_PLL_27X3_VADDR                     (0xb80004d8)
#define SYSTEM_SYS_PLL_27X4_VADDR                     (0xb80004dc)
#define SYSTEM_SYS_PLL_AUD1_VADDR                     (0xb80004e0)
#define SYSTEM_SYS_PLL_AUD3_VADDR                     (0xb80004e4)
#define SYSTEM_SYS_PLL_AUD4_VADDR                     (0xb80004e8)
#define SYSTEM_SYS_PLL_PSAUD1_VADDR                   (0xb80004f0)
#define SYSTEM_SYS_PLL_PSAUD2_VADDR                   (0xb80004f4)
#define SYSTEM_SYS_PLL_DDR1_VADDR                     (0xb8000500)
#define SYSTEM_SYS_PLL_DDR2_VADDR                     (0xb8000504)
#define SYSTEM_SYS_PLL_DDR3_VADDR                     (0xb8000508)
#define SYSTEM_SYS_PLL_DDR4_VADDR                     (0xb800050c)
#define SYSTEM_SYS_PLL_DDR_SSC1_VADDR                 (0xb8000510)
#define SYSTEM_SYS_PLL_DDR_SSC2_VADDR                 (0xb8000514)
#define SYSTEM_SYS_PLL_DDR_SSC3_VADDR                 (0xb8000518)
#define SYSTEM_SYS_PLL_DDR5_VADDR                     (0xb800051c)
#define SYSTEM_SYS_PLL_DDR1_2_VADDR                   (0xb8000520)
#define SYSTEM_SYS_PLL_DDR2_2_VADDR                   (0xb8000524)
#define SYSTEM_SYS_PLL_DDR3_2_VADDR                   (0xb8000528)
#define SYSTEM_SYS_PLL_DDR4_2_VADDR                   (0xb800052c)
#define SYSTEM_SYS_PLL_DDR_SSC1_2_VADDR               (0xb8000530)
#define SYSTEM_SYS_PLL_DDR_SSC2_2_VADDR               (0xb8000534)
#define SYSTEM_SYS_PLL_DDR_SSC3_2_VADDR               (0xb8000538)
#define SYSTEM_SYS_PLL_DDR5_2_VADDR                   (0xb800053c)
#define SYSTEM_SC_BUSPLL_SSC_VADDR                    (0xb8000600)
#define SYSTEM_SC_BUSHPLL_SSC_VADDR                   (0xb8000604)
#define SYSTEM_SC_BUS2PLL_SSC_VADDR                   (0xb8000608)
#define SYSTEM_SYS_DCLKSS_VADDR                       (0xb8000640)
#define SYSTEM_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR      (0xb8000644)
#define SYSTEM_DPLL_IN_FSYNC_TRACKING_CTRL2_VADDR     (0xb8000648)
#define SYSTEM_DPLL_IN_FSYNC_TRACKING_DEBUG_VADDR     (0xb800064c)
#define SYSTEM_DCLK_FRC2FSYNC_SPEEDUP_VADDR           (0xb8000650)
#define SYSTEM_DPLL_STATUS_RO_VADDR                   (0xb8000654)
#define SYSTEM_DCLKSS_FREQ_VADDR                      (0xb8000658)
#define SYSTEM_DCLKSS_PROFILE0_VADDR                  (0xb800065c)
#define SYSTEM_DCLKSS_PROFILE1_VADDR                  (0xb8000660)
#define SYSTEM_DCLKSS_PROFILE2_VADDR                  (0xb8000664)
#define SYSTEM_DCLKSS_PROFILE3_VADDR                  (0xb8000668)
#define SYSTEM_DCLKSS_PROFILE4_VADDR                  (0xb800066c)
#define SYSTEM_DCLKSS_PROFILE5_VADDR                  (0xb8000670)
#define SYSTEM_DCLKSS_PROFILE6_VADDR                  (0xb8000674)
#define SYSTEM_DCLKSS_PROFILE7_VADDR                  (0xb8000678)
#define SYSTEM_DCLKSS_PROFILE8_VADDR                  (0xb800067c)
#define SYSTEM_DCLKSS_PROFILE9_VADDR                  (0xb8000680)
#define SYSTEM_DCLKSS_PROFILE10_VADDR                 (0xb8000684)
#define SYSTEM_DCLKSS_PROFILE11_VADDR                 (0xb8000688)
#define SYSTEM_DCLKSS_PROFILE12_VADDR                 (0xb800068c)
#define SYSTEM_DCLKSS_PROFILE13_VADDR                 (0xb8000690)
#define SYSTEM_DCLKSS_PROFILE14_VADDR                 (0xb8000694)
#define SYSTEM_DCLKSS_PROFILE15_VADDR                 (0xb8000698)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======SYSTEM register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vercode:32;
    };
}sc_verid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  div_emb:2;
        RBus_UInt32  cap_emb:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  en_emb:1;
        RBus_UInt32  det_ddr2_off:1;
        RBus_UInt32  main_pow_on:1;
        RBus_UInt32  main_por_en:1;
        RBus_UInt32  det_ddr_off:1;
        RBus_UInt32  por_v33set_l:2;
        RBus_UInt32  por_v11set_l:2;
        RBus_UInt32  por_reser:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ldov11_sel:2;
        RBus_UInt32  stbldo_pow:1;
    };
}sc_lv_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boption_rst_bypass:1;
        RBus_UInt32  boption_efuse:1;
        RBus_UInt32  boption_debounce_n:1;
        RBus_UInt32  boption_gpu:1;
        RBus_UInt32  boption_arm:1;
        RBus_UInt32  boption_6:1;
        RBus_UInt32  boption_5:1;
        RBus_UInt32  boption_4:1;
        RBus_UInt32  boption_3:1;
        RBus_UInt32  boption_2:1;
        RBus_UInt32  boption_1:1;
        RBus_UInt32  boption_0:1;
        RBus_UInt32  at_speed_pll_done:1;
        RBus_UInt32  porl_host_s_en:1;
        RBus_UInt32  porl_at_speed_scan:1;
        RBus_UInt32  porl_boot_mode_n:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  porl_test_mode:5;
        RBus_UInt32  porl_test_en_n:1;
        RBus_UInt32  porl_pll_en:1;
        RBus_UInt32  porl_ejtag_en_n:1;
        RBus_UInt32  res2:1;
    };
}sc_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  rstn_mt:1;
        RBus_UInt32  mt_isln_en:1;
    };
}st_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  rstn_i2c0_off:1;
        RBus_UInt32  rstn_uart0_off:1;
        RBus_UInt32  rstn_irda_off:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_pad_mux:1;
        RBus_UInt32  rstn_iso_misc_off:1;
        RBus_UInt32  rstn_iso_misc:1;
    };
}st_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  rstn_osc:1;
        RBus_UInt32  rstn_rtc:1;
        RBus_UInt32  rstn_emcu_top:1;
        RBus_UInt32  rstn_emcu_core:1;
        RBus_UInt32  rstn_hdmi_det:1;
        RBus_UInt32  rstn_cec:1;
        RBus_UInt32  rstn_syncp:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  rstn_alu:1;
        RBus_UInt32  rstn_irda:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_lsadc:1;
    };
}st_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  clken_i2c0_off:1;
        RBus_UInt32  clken_uart0_off:1;
        RBus_UInt32  clken_irda_off:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_pad_mux:1;
        RBus_UInt32  clken_iso_misc_off:1;
        RBus_UInt32  clken_iso_misc:1;
    };
}st_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  clken_osc:1;
        RBus_UInt32  clken_rtc:1;
        RBus_UInt32  clken_emcu_core:1;
        RBus_UInt32  clken_hdmi_det:1;
        RBus_UInt32  clken_cec:1;
        RBus_UInt32  clken_syncp:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_alu:1;
        RBus_UInt32  clken_irda:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_lsadc:1;
    };
}st_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  bus_div_en:1;
        RBus_UInt32  bus_div_apply:1;
        RBus_UInt32  bus_div_busy:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bus_div_sel:3;
        RBus_UInt32  res3:11;
        RBus_UInt32  bus_clksel:1;
    };
}st_busclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  emcu_div_en:1;
        RBus_UInt32  emcu_div_apply:1;
        RBus_UInt32  emcu_div_busy:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  emcu_div_sel:3;
        RBus_UInt32  res3:11;
        RBus_UInt32  res4:1;
    };
}st_emcuclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  wow_gmac_clksel:1;
        RBus_UInt32  wow_clksel:1;
        RBus_UInt32  osc_clksel:1;
        RBus_UInt32  uart_clksel:1;
    };
}st_clkmux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st2_isln_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  st2_wakeup_tim:4;
        RBus_UInt32  st2_pw_interval:4;
        RBus_UInt32  st2_iso_p_tim:4;
        RBus_UInt32  st2_iso_tim:4;
        RBus_UInt32  st2_de_iso_ps_tim:4;
        RBus_UInt32  st2_de_iso_tim:4;
        RBus_UInt32  st2_rst_period:4;
    };
}st_alu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_cbus:1;
        RBus_UInt32  stie_iso_misc:1;
    };
}alu_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_cbus:1;
        RBus_UInt32  stip_iso_misc:1;
    };
}alu_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_iso_misc:1;
    };
}alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  rtc_scpu_ie:1;
        RBus_UInt32  cec_scpu_ie:1;
        RBus_UInt32  cbus_scpu_ie:1;
        RBus_UInt32  hdmi_clk_det_scpu_ie:1;
        RBus_UInt32  syncp_scpu_ie:1;
        RBus_UInt32  iso_misc_off_scpu_ie:1;
        RBus_UInt32  iso_misc_scpu_ie:1;
    };
}stb_irq_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  osc_sw_s:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  osc_status:2;
        RBus_UInt32  osc_cnt_diff:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  osc_rstb_emb:1;
        RBus_UInt32  osc_tracking_mode:1;
        RBus_UInt32  osc_tracking_en:1;
    };
}st_ring_osc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  s_emb:7;
        RBus_UInt32  dummy180600e8_11_9:3;
        RBus_UInt32  osc_cnt_diff_max_clr:1;
        RBus_UInt32  osc_cnt_diff_max:8;
    };
}st_ring_osc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  alu_test_mode_en:1;
        RBus_UInt32  alu_dbg_sel:7;
        RBus_UInt32  SYSTEM_dbg_sel:4;
        RBus_UInt32  res2:14;
        RBus_UInt32  dbg_div_sel:2;
    };
}st_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data1:32;
    };
}wdog_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data2:32;
    };
}wdog_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data3:32;
    };
}wdog_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data4:32;
    };
}wdog_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data5:32;
    };
}wdog_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data6:32;
    };
}wdog_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data7:32;
    };
}wdog_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data8:32;
    };
}wdog_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data9:32;
    };
}wdog_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data10:32;
    };
}wdog_data10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data11:32;
    };
}wdog_data11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data12:32;
    };
}wdog_data12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  rstn_pllreg:1;
    };
}sys_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_tvsb1:1;
        RBus_UInt32  rstn_tvsb2:1;
        RBus_UInt32  rstn_tvsb3:1;
        RBus_UInt32  rstn_tvsb2_dc2:1;
        RBus_UInt32  rstn_tvsb3_dc2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_dcphy:1;
        RBus_UInt32  rstn_dcu:1;
        RBus_UInt32  rstn_if_demod:1;
        RBus_UInt32  rstn_vdec:1;
        RBus_UInt32  rstn_vdec2:1;
        RBus_UInt32  rstn_vbis0:1;
        RBus_UInt32  rstn_audio2_dac:1;
        RBus_UInt32  rstn_audio_adc:1;
        RBus_UInt32  rstn_audio_dac:1;
        RBus_UInt32  rstn_audio:1;
        RBus_UInt32  rstn_ifadc:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rstn_me:1;
        RBus_UInt32  rstn_apll_adc:1;
        RBus_UInt32  rstn_hdmi:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_dispim:1;
        RBus_UInt32  rstn_disp:1;
    };
}sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  rstn_osdcmp:1;
        RBus_UInt32  rstn_etn:1;
        RBus_UInt32  rstn_cr:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  rstn_usb_arb:1;
        RBus_UInt32  dummy18000108_19:1;
        RBus_UInt32  rstn_usb3_mac:1;
        RBus_UInt32  dummy18000108_17:1;
        RBus_UInt32  rstn_getn:1;
        RBus_UInt32  dummy18000108_15_13:3;
        RBus_UInt32  rstn_padmux:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  rstn_uart3:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  rstn_pc:1;
    };
}sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_scpu_dbg:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  rstn_usb3_phy:1;
        RBus_UInt32  rstn_usb3_p0_mdio:1;
        RBus_UInt32  res5:1;
    };
}sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  clken_pllreg:1;
    };
}sys_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_tvsb1:1;
        RBus_UInt32  clken_tvsb2:1;
        RBus_UInt32  clken_tvsb3:1;
        RBus_UInt32  clken_tvsb2_dc2:1;
        RBus_UInt32  clken_tvsb3_dc2:1;
        RBus_UInt32  dummy18000114_26:1;
        RBus_UInt32  clken_dcphy:1;
        RBus_UInt32  clken_dcu:1;
        RBus_UInt32  clken_if_demod:1;
        RBus_UInt32  clken_vdec:1;
        RBus_UInt32  dummy18000114_21:1;
        RBus_UInt32  clken_vbis0:1;
        RBus_UInt32  clken_audio_daad_128fs:1;
        RBus_UInt32  clken_audio_daad_256fs:1;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  dummy18000114_14_13:2;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  dummy18000114_4:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_dispim:1;
        RBus_UInt32  clken_disp:1;
    };
}sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  clken_spds:1;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  clken_osdcmp:1;
        RBus_UInt32  clken_etn:1;
        RBus_UInt32  clken_cr:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_usb:1;
        RBus_UInt32  clken_getn_phy:1;
        RBus_UInt32  clken_getn:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  clken_audio2_daad_256fs:1;
        RBus_UInt32  clken_audio2_daad_128fs:1;
        RBus_UInt32  clken_padmux:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  clken_uart3:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  clken_pc:1;
    };
}sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  res3:16;
    };
}sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  acpu_clksel:1;
    };
}sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  epi_dbg_clksel:1;
        RBus_UInt32  epi_div_clksel:1;
        RBus_UInt32  sd_clksel:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  atvin_clk_sel:1;
        RBus_UInt32  atvin_vd_clk_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_clksel:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  vdec_x27_clksel:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  vbis0_yppsel:1;
        RBus_UInt32  inv_vbis0_clk:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  uart_clksel:1;
    };
}sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_demod_multi_req_disable:1;
        RBus_UInt32  demod_i2c_saddr_sel:1;
        RBus_UInt32  aud_dtv_freq_sel:3;
    };
}sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  arm_wd_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  arm_wd_cnt:12;
    };
}sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800021c_31_1:31;
        RBus_UInt32  tvsb1_dc2_sel:1;
    };
}sys_tvsb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  efuse_ready:1;
    };
}efuse_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  atv_iso_en:1;
        RBus_UInt32  atv_wek_status:1;
        RBus_UInt32  atv_str_status:1;
        RBus_UInt32  atv_wek_pow:1;
        RBus_UInt32  atv_str_pow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_iso_en:1;
        RBus_UInt32  dtv_wek_status:1;
        RBus_UInt32  dtv_str_status:1;
        RBus_UInt32  dtv_wek_pow:1;
        RBus_UInt32  dtv_str_pow:1;
    };
}power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tm_enable:1;
        RBus_UInt32  tm_data_valid:1;
        RBus_UInt32  tm_data_sampled:1;
        RBus_UInt32  tm_reverse_cmp_out:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  tm_data_out:6;
        RBus_UInt32  tm_pwron_dly:16;
    };
}tm_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_compare_dly:16;
        RBus_UInt32  tm_sample_dly:16;
    };
}tm_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  tm_sbg:3;
        RBus_UInt32  tm_sos:3;
        RBus_UInt32  tm_sinl:2;
        RBus_UInt32  res2:2;
    };
}tm_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  data_in:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  data_in_ready:1;
        RBus_UInt32  wire_sel:1;
        RBus_UInt32  ro_sel:3;
        RBus_UInt32  dss_rst_n:1;
    };
}ss_12t_lvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  count_out:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  wsort_go:1;
        RBus_UInt32  ready:1;
    };
}ss_12t_lvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_12t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rvt_12t_ro_sel:3;
        RBus_UInt32  rvt_12t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rvt_12t_ready:1;
        RBus_UInt32  rvt_12t_count_out:20;
    };
}ss_12t_rvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rvt_12t_data_in_ready:1;
        RBus_UInt32  rvt_12t_data_in:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  rvt_12t_data_read_ack:1;
        RBus_UInt32  rvt_12t_wsort_go:1;
    };
}ss_12t_rvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvt_9t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  lvt_9t_ro_sel:3;
        RBus_UInt32  lvt_9t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lvt_9t_ready:1;
        RBus_UInt32  lvt_9t_count_out:20;
    };
}ss_9t_lvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  lvt_9t_data_in_ready:1;
        RBus_UInt32  lvt_9t_data_in:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  lvt_9t_data_read_ack:1;
        RBus_UInt32  lvt_9t_wsort_go:1;
    };
}ss_9t_lvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_9t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rvt_9t_ro_sel:3;
        RBus_UInt32  rvt_9t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rvt_9t_ready:1;
        RBus_UInt32  rvt_9t_count_out:20;
    };
}ss_9t_rvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rvt_9t_data_in_ready:1;
        RBus_UInt32  rvt_9t_data_in:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  rvt_9t_data_read_ack:1;
        RBus_UInt32  rvt_9t_wsort_go:1;
    };
}ss_9t_rvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rlvt_7t_ro_sel:3;
        RBus_UInt32  rlvt_7t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rlvt_7t_ready:1;
        RBus_UInt32  rlvt_7t_count_out:20;
    };
}ss_7t_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rlvt_7t_data_in_ready:1;
        RBus_UInt32  rlvt_7t_data_in:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  rlvt_7t_data_read_ack:1;
        RBus_UInt32  rlvt_7t_wsort_go:1;
    };
}ss_7t_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  top_ssc_dbg_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  SYSTEM_dbg_sel:8;
    };
}sc_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllscpu_cp:2;
        RBus_UInt32  pllscpu_n:2;
        RBus_UInt32  pllscpu_m:8;
        RBus_UInt32  pllscpu_ip:3;
        RBus_UInt32  pllscpu_o:2;
        RBus_UInt32  pllscpu_wdset:1;
        RBus_UInt32  pllscpu_wdrst:1;
        RBus_UInt32  pllscpu_cs:2;
        RBus_UInt32  pllscpu_rs:3;
    };
}sys_pll_scpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllscpu_vcorb:1;
        RBus_UInt32  pllscpu_oeb:1;
        RBus_UInt32  pllscpu_rstb:1;
        RBus_UInt32  pllscpu_pow:1;
    };
}sys_pll_scpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllacpu_m:7;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_rs:3;
    };
}sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_pow:1;
    };
}sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllvcpu_m:7;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_rs:3;
    };
}sys_pll_vcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_pow:1;
    };
}sys_pll_vcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  pllcpu_reg:2;
    };
}sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_n:2;
        RBus_UInt32  pllbus_m:7;
        RBus_UInt32  pllbus_ip:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_rs:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_cs:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cp:2;
        RBus_UInt32  pllbus_r3:3;
        RBus_UInt32  pllbus_c3:2;
    };
}sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18000424_18:1;
        RBus_UInt32  pllbus_pi_rl:2;
        RBus_UInt32  pllbus_pi_rs:2;
        RBus_UInt32  pllbus_pi_bias:2;
        RBus_UInt32  dummy18000424_11:1;
        RBus_UInt32  pllbus_wdmode:2;
        RBus_UInt32  dummy18000424_8_6:3;
        RBus_UInt32  pllbus_fupdn:1;
        RBus_UInt32  pllbus_psen:1;
        RBus_UInt32  pllbus_vcorb:1;
        RBus_UInt32  dummy18000424_2:1;
        RBus_UInt32  pllbus_tst:1;
        RBus_UInt32  pllbus_pstst:1;
    };
}sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllbus_o:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_pow:1;
    };
}sys_pll_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_n_h:2;
        RBus_UInt32  pllbus_m_h:7;
        RBus_UInt32  pllbus_ip_h:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_rs_h:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_cs_h:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cp_h:2;
        RBus_UInt32  pllbus_r3_h:3;
        RBus_UInt32  pllbus_c3_h:2;
    };
}sys_pll_h_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18000434_18:1;
        RBus_UInt32  pllbus_pi_rl_h:2;
        RBus_UInt32  pllbus_pi_rs_h:2;
        RBus_UInt32  pllbus_pi_bias_h:2;
        RBus_UInt32  dummy18000434_11:1;
        RBus_UInt32  pllbus_wdmode_h:2;
        RBus_UInt32  dummy18000434_8_6:3;
        RBus_UInt32  pllbus_fupdn_h:1;
        RBus_UInt32  pllbus_psen_h:1;
        RBus_UInt32  pllbus_vcorb_h:1;
        RBus_UInt32  dummy18000434_2:1;
        RBus_UInt32  pllbus_tst_h:1;
        RBus_UInt32  pllbus_pstst_h:1;
    };
}sys_pll_h_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllbus_o_h:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_pow_h:1;
    };
}sys_pll_h_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_n_2:2;
        RBus_UInt32  pllbus_m_2:7;
        RBus_UInt32  pllbus_ip_2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_rs_2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_cs_2:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cp_2:2;
        RBus_UInt32  pllbus_r3_2:3;
        RBus_UInt32  pllbus_c3_2:2;
    };
}sys_pll_2_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18000444_18:1;
        RBus_UInt32  pllbus_pi_rl_2:2;
        RBus_UInt32  pllbus_pi_rs_2:2;
        RBus_UInt32  pllbus_pi_bias_2:2;
        RBus_UInt32  dummy18000444_11:1;
        RBus_UInt32  pllbus_wdmode_2:2;
        RBus_UInt32  dummy18000444_8_6:3;
        RBus_UInt32  pllbus_fupdn_2:1;
        RBus_UInt32  pllbus_psen_2:1;
        RBus_UInt32  pllbus_vcorb_2:1;
        RBus_UInt32  dummy18000444_2:1;
        RBus_UInt32  pllbus_tst_2:1;
        RBus_UInt32  pllbus_pstst_2:1;
    };
}sys_pll_2_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllbus_o_2:1;
        RBus_UInt32  pllbus_oeb_2:1;
        RBus_UInt32  pllbus_rstb_2:1;
        RBus_UInt32  pllbus_pow_2:1;
    };
}sys_pll_2_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllgpu_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllgpu_m:7;
        RBus_UInt32  pllgpu_ip:3;
        RBus_UInt32  pllgpu_o:2;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  pllgpu_cs:2;
        RBus_UInt32  pllgpu_rs:3;
    };
}sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllgpu_tst:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_pow:1;
    };
}sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllgpu_n_2:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllgpu_m_2:7;
        RBus_UInt32  pllgpu_ip_2:3;
        RBus_UInt32  pllgpu_o_2:2;
        RBus_UInt32  pllgpu_wdset_2:1;
        RBus_UInt32  pllgpu_wdrst_2:1;
        RBus_UInt32  pllgpu_cs_2:2;
        RBus_UInt32  pllgpu_rs_2:3;
    };
}sys_pll_2_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllgpu_tst_2:1;
        RBus_UInt32  pllgpu_oeb_2:1;
        RBus_UInt32  pllgpu_rstb_2:1;
        RBus_UInt32  pllgpu_pow_2:1;
    };
}sys_pll_2_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllvodma_m:7;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_rs:3;
    };
}sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_pow:1;
    };
}sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pllbus_reser:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbustst_sel:5;
    };
}sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldds_n:2;
        RBus_UInt32  plldds_m:7;
        RBus_UInt32  plldds_ip:3;
        RBus_UInt32  plldds_rs:3;
        RBus_UInt32  plldds_cs:2;
        RBus_UInt32  plldds_cp:2;
        RBus_UInt32  plldds_r3:3;
        RBus_UInt32  plldds_c3:2;
        RBus_UInt32  plldds_pi_rl:2;
        RBus_UInt32  plldds_pi_rs:2;
        RBus_UInt32  plldds_pi_bias:2;
        RBus_UInt32  plldds_wdmode:2;
    };
}sys_pll_disp_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000474_28_25:4;
        RBus_UInt32  pcr_a_smooth_en:1;
        RBus_UInt32  dummy18000474_23:1;
        RBus_UInt32  pcr_a_phase_sel:1;
        RBus_UInt32  dummy18000474_21:1;
        RBus_UInt32  pcr_a_ctl_en:1;
        RBus_UInt32  dummy18000474_19:1;
        RBus_UInt32  plldds_fupdn:1;
        RBus_UInt32  dummy18000474_17:1;
        RBus_UInt32  plldds_ddsen:1;
        RBus_UInt32  dummy18000474_15:1;
        RBus_UInt32  plldds_vcorb:1;
        RBus_UInt32  dummy18000474_13:1;
        RBus_UInt32  plldds_tst:1;
        RBus_UInt32  plldds_pstst:1;
        RBus_UInt32  dummy18000474_10:1;
        RBus_UInt32  res2:10;
    };
}sys_pll_disp_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy18000478_30:1;
        RBus_UInt32  psaud1_fupdn:1;
        RBus_UInt32  psaud1_div:1;
        RBus_UInt32  dummy18000478_27:1;
        RBus_UInt32  psaud1_tst:1;
        RBus_UInt32  psaud1_psen:1;
        RBus_UInt32  dummy18000478_24:1;
        RBus_UInt32  psaud2_fupdn:1;
        RBus_UInt32  psaud2_div:1;
        RBus_UInt32  psaud2_tst:1;
        RBus_UInt32  psaud2_psen:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud1_oeb:1;
        RBus_UInt32  psaud1_rstb:1;
        RBus_UInt32  psaud2_oeb:1;
        RBus_UInt32  psaud2_rstb:1;
    };
}sys_pll_disp_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  plldds_o:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldds_oeb:1;
        RBus_UInt32  plldds_rstb:1;
        RBus_UInt32  plldds_pow:1;
    };
}sys_pll_disp_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldds_pcr_acc:16;
        RBus_UInt32  plldds_pcr_overflow:16;
    };
}sys_pll_disp_sd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_pcr_a_n_nxt:16;
        RBus_UInt32  pcr_a_n_nxt:16;
    };
}sys_pll_disp_sd6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pcr_a_n_nxt_add:8;
        RBus_UInt32  pcr_a_n_nxt_add_period:16;
    };
}sys_pll_disp_sd7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps:1;
        RBus_UInt32  psc:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd:1;
        RBus_UInt32  su:1;
    };
}ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_cs:2;
    };
}sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  dpll_reg:2;
        RBus_UInt32  dpll_fupdn:1;
        RBus_UInt32  dpll_stop:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  dpll_bpphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_bpn:1;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res4:5;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_clksel:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_pwdn:1;
    };
}sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vby1_dpll_m:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  vby1_dpll_n:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  vby1_dpll_ip:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  vby1_dpll_rs:3;
        RBus_UInt32  vby1_dpll_cp:2;
        RBus_UInt32  vby1_dpll_cs:2;
    };
}sys_pll_vby11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vby1_dpll_reser:4;
        RBus_UInt32  vby1_dpll_reg:2;
        RBus_UInt32  vby1_dpll_fupdn:1;
        RBus_UInt32  vby1_dpll_stop:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  vby1_dpll_reserve:1;
        RBus_UInt32  vby1_dpll_bpphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vby1_dpll_bpn:1;
        RBus_UInt32  vby1_dpll_o:2;
        RBus_UInt32  res4:5;
        RBus_UInt32  vby1_dpll_rstb:1;
        RBus_UInt32  vby1_dpll_wdrst:1;
        RBus_UInt32  vby1_dpll_wdset:1;
        RBus_UInt32  vby1_dpll_clksel:1;
        RBus_UInt32  vby1_dpll_freeze:1;
        RBus_UInt32  vby1_dpll_vcorstb:1;
        RBus_UInt32  vby1_dpll_pwdn:1;
    };
}sys_pll_vby12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  plletn_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  plletn_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plletn_ip:3;
        RBus_UInt32  plletn_o:4;
        RBus_UInt32  res4:2;
        RBus_UInt32  plletn_wdmode:2;
        RBus_UInt32  plletn_lf_cp:2;
        RBus_UInt32  plletn_lf_rs:2;
    };
}sys_pll_etn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  plletn_ldo_sel:2;
        RBus_UInt32  plletn_ldo_pow:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  plletn_rstb:1;
        RBus_UInt32  plletn_pow:1;
    };
}sys_pll_etn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  pllgpu2_wdout:1;
        RBus_UInt32  pllvby1_wdout:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  pllbus2_wdout:1;
        RBus_UInt32  plletn_wdout:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldds_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  pllscpu_wdout:1;
    };
}sys_pll_wd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_wdset:1;
    };
}sys_pll_512fs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_pow:1;
    };
}sys_pll_512fs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:11;
    };
}sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  plldif_divdig_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  plldif_divadc_sel:2;
    };
}sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  plldif_pd_d2s:1;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_pow:1;
    };
}sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  pll27x_m_sel:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_m:7;
    };
}sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  xixo_load:1;
        RBus_UInt32  xixo_drive_sel:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  pll27x_pow_ldo11v:1;
        RBus_UInt32  pll27x_ldo11v_sel:2;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_pow_ldo:1;
        RBus_UInt32  pll27x_ldo_sel:2;
        RBus_UInt32  res8:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res9:2;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  pll27x_ps_duty_sel:1;
    };
}sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pll27x_reserve:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_pow:1;
    };
}sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  ckin_pllaud_mux:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  ck_ifadc_mux:1;
    };
}sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllaud_rs:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllaud_cs:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_tst:1;
    };
}sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_pwdn:1;
    };
}sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bb_micbias_clksel:2;
    };
}sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_ctrl:1;
    };
}sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  psaud_div:4;
    };
}sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_pll_dbug_en:1;
        RBus_UInt32  reg_pll_rstb_in:1;
        RBus_UInt32  reg_oeb:1;
        RBus_UInt32  reg_pll_en:1;
    };
}sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_en_post_pi:7;
        RBus_UInt32  reg_reserved:4;
        RBus_UInt32  reg_post_pi_rs:1;
        RBus_UInt32  reg_pll_sel_cpmode:1;
        RBus_UInt32  reg_pdiv:2;
        RBus_UInt32  reg_cco_kvco:1;
        RBus_UInt32  reg_icp:4;
        RBus_UInt32  reg_post_pi_bias:2;
        RBus_UInt32  reg_post_pi_rl:2;
        RBus_UInt32  reg_pll_ldo_vsel:2;
        RBus_UInt32  reg_lpf_sr:3;
        RBus_UInt32  reg_lpf_cp:1;
        RBus_UInt32  reg_loop_pi_isel:2;
    };
}sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_post_pi_sel3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_post_pi_sel0:6;
    };
}sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  reg_post_pi_sel6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel4:6;
    };
}sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_f390k:2;
        RBus_UInt32  reg_cmu_en_wd:1;
        RBus_UInt32  reg_time2_rst_width:2;
        RBus_UInt32  reg_time_rdy_ckout:2;
        RBus_UInt32  reg_time0_ck:3;
    };
}sys_pll_ddr_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_ssc_mode:1;
        RBus_UInt32  reg_cmu_ncode_in:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_cmu_fcode_in:13;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_cmu_en_ssc:1;
        RBus_UInt32  reg_cmu_bypass_pi:1;
        RBus_UInt32  reg_cmu_en_center_in:1;
    };
}sys_pll_ddr_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_weighting_sel:3;
        RBus_UInt32  reg_order:1;
        RBus_UInt32  reg_cmu_tbase_in:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_step_in:13;
    };
}sys_pll_ddr_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_ck3_div2_ph:1;
        RBus_UInt32  reg_ck2x3_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_ck2_div2_ph:1;
        RBus_UInt32  reg_ck2x2_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_ck1_div2_ph:1;
        RBus_UInt32  reg_ck2x1_sel:1;
    };
}sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_pll_dbug_en:1;
        RBus_UInt32  reg_pll_rstb_in:1;
        RBus_UInt32  reg_oeb:1;
        RBus_UInt32  reg_pll_en:1;
    };
}sys_pll_ddr1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_en_post_pi:7;
        RBus_UInt32  reg_reserved:4;
        RBus_UInt32  reg_post_pi_rs:1;
        RBus_UInt32  reg_pll_sel_cpmode:1;
        RBus_UInt32  reg_pdiv:2;
        RBus_UInt32  reg_cco_kvco:1;
        RBus_UInt32  reg_icp:4;
        RBus_UInt32  reg_post_pi_bias:2;
        RBus_UInt32  reg_post_pi_rl:2;
        RBus_UInt32  reg_pll_ldo_vsel:2;
        RBus_UInt32  reg_lpf_sr:3;
        RBus_UInt32  reg_lpf_cp:1;
        RBus_UInt32  reg_loop_pi_isel:2;
    };
}sys_pll_ddr2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_post_pi_sel3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_post_pi_sel0:6;
    };
}sys_pll_ddr3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  reg_post_pi_sel6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel4:6;
    };
}sys_pll_ddr4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_f390k:2;
        RBus_UInt32  reg_cmu_en_wd:1;
        RBus_UInt32  reg_time2_rst_width:2;
        RBus_UInt32  reg_time_rdy_ckout:2;
        RBus_UInt32  reg_time0_ck:3;
    };
}sys_pll_ddr_ssc1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_ssc_mode:1;
        RBus_UInt32  reg_cmu_ncode_in:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_cmu_fcode_in:13;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_cmu_en_ssc:1;
        RBus_UInt32  reg_cmu_bypass_pi:1;
        RBus_UInt32  reg_cmu_en_center_in:1;
    };
}sys_pll_ddr_ssc2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_weighting_sel:3;
        RBus_UInt32  reg_order:1;
        RBus_UInt32  reg_cmu_tbase_in:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_step_in:13;
    };
}sys_pll_ddr_ssc3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_ck3_div2_ph:1;
        RBus_UInt32  reg_ck2x3_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_ck2_div2_ph:1;
        RBus_UInt32  reg_ck2x2_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_ck1_div2_ph:1;
        RBus_UInt32  reg_ck2x1_sel:1;
    };
}sys_pll_ddr5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_ssc_sse:1;
        RBus_UInt32  bus_ssc_ckinv:1;
        RBus_UInt32  bus_ssc_sss:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  bus_ssc_ssn:7;
        RBus_UInt32  bus_ssc_ssfpv:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  bus_ssc_stms:2;
    };
}sc_buspll_ssc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bush_ssc_sse:1;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  bush_ssc_sss:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  bush_ssc_ssn:7;
        RBus_UInt32  bush_ssc_ssfpv:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  bush_ssc_stms:2;
    };
}sc_bushpll_ssc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus2_ssc_sse:1;
        RBus_UInt32  bus2_ssc_ckinv:1;
        RBus_UInt32  bus2_ssc_sss:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  bus2_ssc_ssn:7;
        RBus_UInt32  bus2_ssc_ssfpv:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  bus2_ssc_stms:2;
    };
}sc_bus2pll_ssc_RBUS;

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
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_en:1;
    };
}sys_dclkss_RBUS;

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
}dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_neg_th:12;
        RBus_UInt32  in_frame_tracking_pos_th:12;
        RBus_UInt32  in_frame_tracking_mul:8;
    };
}dpll_in_fsync_tracking_ctrl2_RBUS;

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
}dpll_in_fsync_tracking_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  frc2fsync_speedup_m_code:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  frc2fsync_speedup_offset:11;
    };
}dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  final_m_code:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  final_profile:13;
    };
}dpll_status_ro_RBUS;

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
}dclkss_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800065c_31_30:2;
        RBus_UInt32  dclk_ss_shuffle_en:1;
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  dclk_profile_remap_1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_0:12;
    };
}dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_2:12;
    };
}dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_4:12;
    };
}dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_6:12;
    };
}dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_8:12;
    };
}dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_10:12;
    };
}dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_13:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_12:12;
    };
}dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_15:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_14:12;
    };
}dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_17:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_16:12;
    };
}dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_19:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_18:12;
    };
}dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_21:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_20:12;
    };
}dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_22:12;
    };
}dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_25:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_24:12;
    };
}dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_27:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_26:12;
    };
}dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_29:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_28:12;
    };
}dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_31:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_30:12;
    };
}dclkss_profile15_RBUS;





#else //apply LITTLE_ENDIAN


//======SYSTEM register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vercode:32;
    };
}sc_verid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stbldo_pow:1;
        RBus_UInt32  ldov11_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  por_reser:4;
        RBus_UInt32  por_v11set_l:2;
        RBus_UInt32  por_v33set_l:2;
        RBus_UInt32  det_ddr_off:1;
        RBus_UInt32  main_por_en:1;
        RBus_UInt32  main_pow_on:1;
        RBus_UInt32  det_ddr2_off:1;
        RBus_UInt32  en_emb:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_emb:2;
        RBus_UInt32  div_emb:2;
        RBus_UInt32  res1:8;
    };
}sc_lv_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  porl_ejtag_en_n:1;
        RBus_UInt32  porl_pll_en:1;
        RBus_UInt32  porl_test_en_n:1;
        RBus_UInt32  porl_test_mode:5;
        RBus_UInt32  res1:7;
        RBus_UInt32  porl_boot_mode_n:1;
        RBus_UInt32  porl_at_speed_scan:1;
        RBus_UInt32  porl_host_s_en:1;
        RBus_UInt32  at_speed_pll_done:1;
        RBus_UInt32  boption_0:1;
        RBus_UInt32  boption_1:1;
        RBus_UInt32  boption_2:1;
        RBus_UInt32  boption_3:1;
        RBus_UInt32  boption_4:1;
        RBus_UInt32  boption_5:1;
        RBus_UInt32  boption_6:1;
        RBus_UInt32  boption_arm:1;
        RBus_UInt32  boption_gpu:1;
        RBus_UInt32  boption_debounce_n:1;
        RBus_UInt32  boption_efuse:1;
        RBus_UInt32  boption_rst_bypass:1;
    };
}sc_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_isln_en:1;
        RBus_UInt32  rstn_mt:1;
        RBus_UInt32  res1:30;
    };
}st_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_iso_misc:1;
        RBus_UInt32  rstn_iso_misc_off:1;
        RBus_UInt32  rstn_pad_mux:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_irda_off:1;
        RBus_UInt32  rstn_uart0_off:1;
        RBus_UInt32  rstn_i2c0_off:1;
        RBus_UInt32  res1:25;
    };
}st_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_lsadc:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_irda:1;
        RBus_UInt32  rstn_alu:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_syncp:1;
        RBus_UInt32  rstn_cec:1;
        RBus_UInt32  rstn_hdmi_det:1;
        RBus_UInt32  rstn_emcu_core:1;
        RBus_UInt32  rstn_emcu_top:1;
        RBus_UInt32  rstn_rtc:1;
        RBus_UInt32  rstn_osc:1;
        RBus_UInt32  res1:19;
    };
}st_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_iso_misc:1;
        RBus_UInt32  clken_iso_misc_off:1;
        RBus_UInt32  clken_pad_mux:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_irda_off:1;
        RBus_UInt32  clken_uart0_off:1;
        RBus_UInt32  clken_i2c0_off:1;
        RBus_UInt32  res1:25;
    };
}st_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_lsadc:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_irda:1;
        RBus_UInt32  clken_alu:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_syncp:1;
        RBus_UInt32  clken_cec:1;
        RBus_UInt32  clken_hdmi_det:1;
        RBus_UInt32  clken_emcu_core:1;
        RBus_UInt32  clken_rtc:1;
        RBus_UInt32  clken_osc:1;
        RBus_UInt32  res1:20;
    };
}st_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_clksel:1;
        RBus_UInt32  res3:11;
        RBus_UInt32  bus_div_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  bus_div_busy:1;
        RBus_UInt32  bus_div_apply:1;
        RBus_UInt32  bus_div_en:1;
        RBus_UInt32  res1:13;
    };
}st_busclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:11;
        RBus_UInt32  emcu_div_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  emcu_div_busy:1;
        RBus_UInt32  emcu_div_apply:1;
        RBus_UInt32  emcu_div_en:1;
        RBus_UInt32  res1:13;
    };
}st_emcuclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uart_clksel:1;
        RBus_UInt32  osc_clksel:1;
        RBus_UInt32  wow_clksel:1;
        RBus_UInt32  wow_gmac_clksel:1;
        RBus_UInt32  res1:28;
    };
}st_clkmux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st2_rst_period:4;
        RBus_UInt32  st2_de_iso_tim:4;
        RBus_UInt32  st2_de_iso_ps_tim:4;
        RBus_UInt32  st2_iso_tim:4;
        RBus_UInt32  st2_iso_p_tim:4;
        RBus_UInt32  st2_pw_interval:4;
        RBus_UInt32  st2_wakeup_tim:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  st2_isln_en:1;
    };
}st_alu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stie_iso_misc:1;
        RBus_UInt32  stie_cbus:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  res1:27;
    };
}alu_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stip_iso_misc:1;
        RBus_UInt32  stip_cbus:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  res1:27;
    };
}alu_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stpass_iso_misc:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  res1:27;
    };
}alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iso_misc_scpu_ie:1;
        RBus_UInt32  iso_misc_off_scpu_ie:1;
        RBus_UInt32  syncp_scpu_ie:1;
        RBus_UInt32  hdmi_clk_det_scpu_ie:1;
        RBus_UInt32  cbus_scpu_ie:1;
        RBus_UInt32  cec_scpu_ie:1;
        RBus_UInt32  rtc_scpu_ie:1;
        RBus_UInt32  res1:25;
    };
}stb_irq_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_tracking_en:1;
        RBus_UInt32  osc_tracking_mode:1;
        RBus_UInt32  osc_rstb_emb:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  osc_cnt_diff:8;
        RBus_UInt32  osc_status:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  osc_sw_s:7;
        RBus_UInt32  res1:9;
    };
}st_ring_osc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_cnt_diff_max:8;
        RBus_UInt32  osc_cnt_diff_max_clr:1;
        RBus_UInt32  dummy180600e8_11_9:3;
        RBus_UInt32  s_emb:7;
        RBus_UInt32  res1:13;
    };
}st_ring_osc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_div_sel:2;
        RBus_UInt32  res2:14;
        RBus_UInt32  SYSTEM_dbg_sel:4;
        RBus_UInt32  alu_dbg_sel:7;
        RBus_UInt32  alu_test_mode_en:1;
        RBus_UInt32  res1:4;
    };
}st_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data1:32;
    };
}wdog_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data2:32;
    };
}wdog_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data3:32;
    };
}wdog_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data4:32;
    };
}wdog_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data5:32;
    };
}wdog_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data6:32;
    };
}wdog_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data7:32;
    };
}wdog_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data8:32;
    };
}wdog_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data9:32;
    };
}wdog_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data10:32;
    };
}wdog_data10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data11:32;
    };
}wdog_data11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data12:32;
    };
}wdog_data12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_pllreg:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  res1:21;
    };
}sys_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_disp:1;
        RBus_UInt32  rstn_dispim:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rstn_hdmi:1;
        RBus_UInt32  rstn_apll_adc:1;
        RBus_UInt32  rstn_me:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rstn_ifadc:1;
        RBus_UInt32  rstn_audio:1;
        RBus_UInt32  rstn_audio_dac:1;
        RBus_UInt32  rstn_audio_adc:1;
        RBus_UInt32  rstn_audio2_dac:1;
        RBus_UInt32  rstn_vbis0:1;
        RBus_UInt32  rstn_vdec2:1;
        RBus_UInt32  rstn_vdec:1;
        RBus_UInt32  rstn_if_demod:1;
        RBus_UInt32  rstn_dcu:1;
        RBus_UInt32  rstn_dcphy:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_tvsb3_dc2:1;
        RBus_UInt32  rstn_tvsb2_dc2:1;
        RBus_UInt32  rstn_tvsb3:1;
        RBus_UInt32  rstn_tvsb2:1;
        RBus_UInt32  rstn_tvsb1:1;
    };
}sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_pc:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  rstn_uart3:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  rstn_padmux:1;
        RBus_UInt32  dummy18000108_15_13:3;
        RBus_UInt32  rstn_getn:1;
        RBus_UInt32  dummy18000108_17:1;
        RBus_UInt32  rstn_usb3_mac:1;
        RBus_UInt32  dummy18000108_19:1;
        RBus_UInt32  rstn_usb_arb:1;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rstn_cr:1;
        RBus_UInt32  rstn_etn:1;
        RBus_UInt32  rstn_osdcmp:1;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:2;
    };
}sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res5:1;
        RBus_UInt32  rstn_usb3_p0_mdio:1;
        RBus_UInt32  rstn_usb3_phy:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  rstn_scpu_dbg:1;
    };
}sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_pllreg:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:21;
    };
}sys_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_disp:1;
        RBus_UInt32  clken_dispim:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  dummy18000114_4:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  dummy18000114_14_13:2;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  clken_audio_daad_256fs:1;
        RBus_UInt32  clken_audio_daad_128fs:1;
        RBus_UInt32  clken_vbis0:1;
        RBus_UInt32  dummy18000114_21:1;
        RBus_UInt32  clken_vdec:1;
        RBus_UInt32  clken_if_demod:1;
        RBus_UInt32  clken_dcu:1;
        RBus_UInt32  clken_dcphy:1;
        RBus_UInt32  dummy18000114_26:1;
        RBus_UInt32  clken_tvsb3_dc2:1;
        RBus_UInt32  clken_tvsb2_dc2:1;
        RBus_UInt32  clken_tvsb3:1;
        RBus_UInt32  clken_tvsb2:1;
        RBus_UInt32  clken_tvsb1:1;
    };
}sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_pc:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  clken_uart3:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  clken_padmux:1;
        RBus_UInt32  clken_audio2_daad_128fs:1;
        RBus_UInt32  clken_audio2_daad_256fs:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  clken_getn:1;
        RBus_UInt32  clken_getn_phy:1;
        RBus_UInt32  clken_usb:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_cr:1;
        RBus_UInt32  clken_etn:1;
        RBus_UInt32  clken_osdcmp:1;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  clken_spds:1;
        RBus_UInt32  res1:2;
    };
}sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:16;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  res1:6;
    };
}sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_clksel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  res1:27;
    };
}sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uart_clksel:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  inv_vbis0_clk:1;
        RBus_UInt32  vbis0_yppsel:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  vdec_x27_clksel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_clksel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  atvin_vd_clk_sel:1;
        RBus_UInt32  atvin_clk_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sd_clksel:3;
        RBus_UInt32  epi_div_clksel:1;
        RBus_UInt32  epi_dbg_clksel:1;
        RBus_UInt32  res1:7;
    };
}sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aud_dtv_freq_sel:3;
        RBus_UInt32  demod_i2c_saddr_sel:1;
        RBus_UInt32  dtv_demod_multi_req_disable:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  res1:21;
    };
}sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arm_wd_cnt:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  arm_wd_en:1;
        RBus_UInt32  res1:15;
    };
}sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tvsb1_dc2_sel:1;
        RBus_UInt32  dummy1800021c_31_1:31;
    };
}sys_tvsb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  efuse_ready:1;
        RBus_UInt32  res1:31;
    };
}efuse_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_str_pow:1;
        RBus_UInt32  dtv_wek_pow:1;
        RBus_UInt32  dtv_str_status:1;
        RBus_UInt32  dtv_wek_status:1;
        RBus_UInt32  dtv_iso_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  atv_str_pow:1;
        RBus_UInt32  atv_wek_pow:1;
        RBus_UInt32  atv_str_status:1;
        RBus_UInt32  atv_wek_status:1;
        RBus_UInt32  atv_iso_en:1;
        RBus_UInt32  res1:19;
    };
}power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_pwron_dly:16;
        RBus_UInt32  tm_data_out:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  tm_reverse_cmp_out:1;
        RBus_UInt32  tm_data_sampled:1;
        RBus_UInt32  tm_data_valid:1;
        RBus_UInt32  tm_enable:1;
        RBus_UInt32  res1:4;
    };
}tm_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_sample_dly:16;
        RBus_UInt32  tm_compare_dly:16;
    };
}tm_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  tm_sinl:2;
        RBus_UInt32  tm_sos:3;
        RBus_UInt32  tm_sbg:3;
        RBus_UInt32  res1:22;
    };
}tm_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_rst_n:1;
        RBus_UInt32  ro_sel:3;
        RBus_UInt32  wire_sel:1;
        RBus_UInt32  data_in_ready:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  data_in:20;
        RBus_UInt32  res1:4;
    };
}ss_12t_lvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ready:1;
        RBus_UInt32  wsort_go:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  count_out:20;
        RBus_UInt32  res1:8;
    };
}ss_12t_lvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_12t_count_out:20;
        RBus_UInt32  rvt_12t_ready:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rvt_12t_wire_sel:1;
        RBus_UInt32  rvt_12t_ro_sel:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  rvt_12t_dss_rst_n:1;
    };
}ss_12t_rvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_12t_wsort_go:1;
        RBus_UInt32  rvt_12t_data_read_ack:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rvt_12t_data_in:20;
        RBus_UInt32  rvt_12t_data_in_ready:1;
        RBus_UInt32  res1:7;
    };
}ss_12t_rvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvt_9t_count_out:20;
        RBus_UInt32  lvt_9t_ready:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lvt_9t_wire_sel:1;
        RBus_UInt32  lvt_9t_ro_sel:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  lvt_9t_dss_rst_n:1;
    };
}ss_9t_lvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvt_9t_wsort_go:1;
        RBus_UInt32  lvt_9t_data_read_ack:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  lvt_9t_data_in:20;
        RBus_UInt32  lvt_9t_data_in_ready:1;
        RBus_UInt32  res1:7;
    };
}ss_9t_lvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_9t_count_out:20;
        RBus_UInt32  rvt_9t_ready:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rvt_9t_wire_sel:1;
        RBus_UInt32  rvt_9t_ro_sel:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  rvt_9t_dss_rst_n:1;
    };
}ss_9t_rvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvt_9t_wsort_go:1;
        RBus_UInt32  rvt_9t_data_read_ack:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rvt_9t_data_in:20;
        RBus_UInt32  rvt_9t_data_in_ready:1;
        RBus_UInt32  res1:7;
    };
}ss_9t_rvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_count_out:20;
        RBus_UInt32  rlvt_7t_ready:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rlvt_7t_wire_sel:1;
        RBus_UInt32  rlvt_7t_ro_sel:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  rlvt_7t_dss_rst_n:1;
    };
}ss_7t_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_wsort_go:1;
        RBus_UInt32  rlvt_7t_data_read_ack:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rlvt_7t_data_in:20;
        RBus_UInt32  rlvt_7t_data_in_ready:1;
        RBus_UInt32  res1:7;
    };
}ss_7t_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  SYSTEM_dbg_sel:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  top_ssc_dbg_sel:3;
        RBus_UInt32  res2:4;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res1:14;
    };
}sc_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_rs:3;
        RBus_UInt32  pllscpu_cs:2;
        RBus_UInt32  pllscpu_wdrst:1;
        RBus_UInt32  pllscpu_wdset:1;
        RBus_UInt32  pllscpu_o:2;
        RBus_UInt32  pllscpu_ip:3;
        RBus_UInt32  pllscpu_m:8;
        RBus_UInt32  pllscpu_n:2;
        RBus_UInt32  pllscpu_cp:2;
        RBus_UInt32  res1:8;
    };
}sys_pll_scpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_pow:1;
        RBus_UInt32  pllscpu_rstb:1;
        RBus_UInt32  pllscpu_oeb:1;
        RBus_UInt32  pllscpu_vcorb:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_scpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_rs:3;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res1:7;
    };
}sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_pow:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_rs:3;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res1:7;
    };
}sys_pll_vcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_pow:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}sys_pll_vcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllcpu_reg:2;
        RBus_UInt32  res1:30;
    };
}sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_c3:2;
        RBus_UInt32  pllbus_r3:3;
        RBus_UInt32  pllbus_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_rs:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_ip:3;
        RBus_UInt32  pllbus_m:7;
        RBus_UInt32  pllbus_n:2;
        RBus_UInt32  res1:5;
    };
}sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pstst:1;
        RBus_UInt32  pllbus_tst:1;
        RBus_UInt32  dummy18000424_2:1;
        RBus_UInt32  pllbus_vcorb:1;
        RBus_UInt32  pllbus_psen:1;
        RBus_UInt32  pllbus_fupdn:1;
        RBus_UInt32  dummy18000424_8_6:3;
        RBus_UInt32  pllbus_wdmode:2;
        RBus_UInt32  dummy18000424_11:1;
        RBus_UInt32  pllbus_pi_bias:2;
        RBus_UInt32  pllbus_pi_rs:2;
        RBus_UInt32  pllbus_pi_rl:2;
        RBus_UInt32  dummy18000424_18:1;
        RBus_UInt32  res1:13;
    };
}sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  pllbus_o:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_c3_h:2;
        RBus_UInt32  pllbus_r3_h:3;
        RBus_UInt32  pllbus_cp_h:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cs_h:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_rs_h:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_ip_h:3;
        RBus_UInt32  pllbus_m_h:7;
        RBus_UInt32  pllbus_n_h:2;
        RBus_UInt32  res1:5;
    };
}sys_pll_h_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pstst_h:1;
        RBus_UInt32  pllbus_tst_h:1;
        RBus_UInt32  dummy18000434_2:1;
        RBus_UInt32  pllbus_vcorb_h:1;
        RBus_UInt32  pllbus_psen_h:1;
        RBus_UInt32  pllbus_fupdn_h:1;
        RBus_UInt32  dummy18000434_8_6:3;
        RBus_UInt32  pllbus_wdmode_h:2;
        RBus_UInt32  dummy18000434_11:1;
        RBus_UInt32  pllbus_pi_bias_h:2;
        RBus_UInt32  pllbus_pi_rs_h:2;
        RBus_UInt32  pllbus_pi_rl_h:2;
        RBus_UInt32  dummy18000434_18:1;
        RBus_UInt32  res1:13;
    };
}sys_pll_h_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  pllbus_o_h:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_h_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_c3_2:2;
        RBus_UInt32  pllbus_r3_2:3;
        RBus_UInt32  pllbus_cp_2:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllbus_cs_2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_rs_2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_ip_2:3;
        RBus_UInt32  pllbus_m_2:7;
        RBus_UInt32  pllbus_n_2:2;
        RBus_UInt32  res1:5;
    };
}sys_pll_2_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pstst_2:1;
        RBus_UInt32  pllbus_tst_2:1;
        RBus_UInt32  dummy18000444_2:1;
        RBus_UInt32  pllbus_vcorb_2:1;
        RBus_UInt32  pllbus_psen_2:1;
        RBus_UInt32  pllbus_fupdn_2:1;
        RBus_UInt32  dummy18000444_8_6:3;
        RBus_UInt32  pllbus_wdmode_2:2;
        RBus_UInt32  dummy18000444_11:1;
        RBus_UInt32  pllbus_pi_bias_2:2;
        RBus_UInt32  pllbus_pi_rs_2:2;
        RBus_UInt32  pllbus_pi_rl_2:2;
        RBus_UInt32  dummy18000444_18:1;
        RBus_UInt32  res1:13;
    };
}sys_pll_2_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow_2:1;
        RBus_UInt32  pllbus_rstb_2:1;
        RBus_UInt32  pllbus_oeb_2:1;
        RBus_UInt32  pllbus_o_2:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_2_bus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_rs:3;
        RBus_UInt32  pllgpu_cs:2;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  pllgpu_o:2;
        RBus_UInt32  pllgpu_ip:3;
        RBus_UInt32  pllgpu_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllgpu_n:2;
        RBus_UInt32  res1:10;
    };
}sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_pow:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  pllgpu_tst:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_rs_2:3;
        RBus_UInt32  pllgpu_cs_2:2;
        RBus_UInt32  pllgpu_wdrst_2:1;
        RBus_UInt32  pllgpu_wdset_2:1;
        RBus_UInt32  pllgpu_o_2:2;
        RBus_UInt32  pllgpu_ip_2:3;
        RBus_UInt32  pllgpu_m_2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllgpu_n_2:2;
        RBus_UInt32  res1:10;
    };
}sys_pll_2_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_pow_2:1;
        RBus_UInt32  pllgpu_rstb_2:1;
        RBus_UInt32  pllgpu_oeb_2:1;
        RBus_UInt32  pllgpu_tst_2:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_2_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_rs:3;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  res1:10;
    };
}sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_pow:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbustst_sel:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reser:4;
        RBus_UInt32  res1:12;
    };
}sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldds_wdmode:2;
        RBus_UInt32  plldds_pi_bias:2;
        RBus_UInt32  plldds_pi_rs:2;
        RBus_UInt32  plldds_pi_rl:2;
        RBus_UInt32  plldds_c3:2;
        RBus_UInt32  plldds_r3:3;
        RBus_UInt32  plldds_cp:2;
        RBus_UInt32  plldds_cs:2;
        RBus_UInt32  plldds_rs:3;
        RBus_UInt32  plldds_ip:3;
        RBus_UInt32  plldds_m:7;
        RBus_UInt32  plldds_n:2;
    };
}sys_pll_disp_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:10;
        RBus_UInt32  dummy18000474_10:1;
        RBus_UInt32  plldds_pstst:1;
        RBus_UInt32  plldds_tst:1;
        RBus_UInt32  dummy18000474_13:1;
        RBus_UInt32  plldds_vcorb:1;
        RBus_UInt32  dummy18000474_15:1;
        RBus_UInt32  plldds_ddsen:1;
        RBus_UInt32  dummy18000474_17:1;
        RBus_UInt32  plldds_fupdn:1;
        RBus_UInt32  dummy18000474_19:1;
        RBus_UInt32  pcr_a_ctl_en:1;
        RBus_UInt32  dummy18000474_21:1;
        RBus_UInt32  pcr_a_phase_sel:1;
        RBus_UInt32  dummy18000474_23:1;
        RBus_UInt32  pcr_a_smooth_en:1;
        RBus_UInt32  dummy18000474_28_25:4;
        RBus_UInt32  res1:3;
    };
}sys_pll_disp_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud2_rstb:1;
        RBus_UInt32  psaud2_oeb:1;
        RBus_UInt32  psaud1_rstb:1;
        RBus_UInt32  psaud1_oeb:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud2_psen:1;
        RBus_UInt32  psaud2_tst:1;
        RBus_UInt32  psaud2_div:1;
        RBus_UInt32  psaud2_fupdn:1;
        RBus_UInt32  dummy18000478_24:1;
        RBus_UInt32  psaud1_psen:1;
        RBus_UInt32  psaud1_tst:1;
        RBus_UInt32  dummy18000478_27:1;
        RBus_UInt32  psaud1_div:1;
        RBus_UInt32  psaud1_fupdn:1;
        RBus_UInt32  dummy18000478_30:1;
        RBus_UInt32  res1:1;
    };
}sys_pll_disp_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldds_pow:1;
        RBus_UInt32  plldds_rstb:1;
        RBus_UInt32  plldds_oeb:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldds_o:2;
        RBus_UInt32  res1:26;
    };
}sys_pll_disp_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldds_pcr_overflow:16;
        RBus_UInt32  plldds_pcr_acc:16;
    };
}sys_pll_disp_sd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_a_n_nxt:16;
        RBus_UInt32  n_pcr_a_n_nxt:16;
    };
}sys_pll_disp_sd6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_a_n_nxt_add_period:16;
        RBus_UInt32  pcr_a_n_nxt_add:8;
        RBus_UInt32  res1:8;
    };
}sys_pll_disp_sd7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su:1;
        RBus_UInt32  sd:1;
        RBus_UInt32  res5:7;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  psc:1;
        RBus_UInt32  tmps:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res1:6;
    };
}ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res1:4;
    };
}sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pwdn:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_clksel:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  dpll_bpn:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_bpphs:1;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dpll_stop:1;
        RBus_UInt32  dpll_fupdn:1;
        RBus_UInt32  dpll_reg:2;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  res1:4;
    };
}sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1_dpll_cs:2;
        RBus_UInt32  vby1_dpll_cp:2;
        RBus_UInt32  vby1_dpll_rs:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  vby1_dpll_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  vby1_dpll_n:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  vby1_dpll_m:8;
        RBus_UInt32  res1:4;
    };
}sys_pll_vby11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1_dpll_pwdn:1;
        RBus_UInt32  vby1_dpll_vcorstb:1;
        RBus_UInt32  vby1_dpll_freeze:1;
        RBus_UInt32  vby1_dpll_clksel:1;
        RBus_UInt32  vby1_dpll_wdset:1;
        RBus_UInt32  vby1_dpll_wdrst:1;
        RBus_UInt32  vby1_dpll_rstb:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  vby1_dpll_o:2;
        RBus_UInt32  vby1_dpll_bpn:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vby1_dpll_bpphs:1;
        RBus_UInt32  vby1_dpll_reserve:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  vby1_dpll_stop:1;
        RBus_UInt32  vby1_dpll_fupdn:1;
        RBus_UInt32  vby1_dpll_reg:2;
        RBus_UInt32  vby1_dpll_reser:4;
        RBus_UInt32  res1:4;
    };
}sys_pll_vby12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plletn_lf_rs:2;
        RBus_UInt32  plletn_lf_cp:2;
        RBus_UInt32  plletn_wdmode:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  plletn_o:4;
        RBus_UInt32  plletn_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  plletn_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plletn_n:2;
        RBus_UInt32  res1:6;
    };
}sys_pll_etn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plletn_pow:1;
        RBus_UInt32  plletn_rstb:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  plletn_ldo_pow:1;
        RBus_UInt32  plletn_ldo_sel:2;
        RBus_UInt32  res1:25;
    };
}sys_pll_etn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_wdout:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  plldds_wdout:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plletn_wdout:1;
        RBus_UInt32  pllbus2_wdout:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pllvby1_wdout:1;
        RBus_UInt32  pllgpu2_wdout:1;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  res1:14;
    };
}sys_pll_wd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_wdset:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res1:1;
    };
}sys_pll_512fs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_pow:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  res1:29;
    };
}sys_pll_512fs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res5:11;
        RBus_UInt32  res4:1;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res1:2;
    };
}sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_divadc_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  plldif_divdig_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:19;
    };
}sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_pow:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  plldif_pd_d2s:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_m:7;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_m_sel:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res1:2;
    };
}sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_ps_duty_sel:1;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  res9:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res8:2;
        RBus_UInt32  pll27x_ldo_sel:2;
        RBus_UInt32  pll27x_pow_ldo:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_ldo11v_sel:2;
        RBus_UInt32  pll27x_pow_ldo11v:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  xixo_drive_sel:2;
        RBus_UInt32  xixo_load:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:8;
    };
}sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_pow:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pll27x_reserve:10;
        RBus_UInt32  res1:14;
    };
}sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ck_ifadc_mux:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  ckin_pllaud_mux:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  res1:7;
    };
}sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_tst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllaud_cs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllaud_rs:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res1:14;
    };
}sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_pwdn:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_micbias_clksel:2;
        RBus_UInt32  res1:30;
    };
}sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_ctrl:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_div:4;
        RBus_UInt32  res1:28;
    };
}sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pll_en:1;
        RBus_UInt32  reg_oeb:1;
        RBus_UInt32  reg_pll_rstb_in:1;
        RBus_UInt32  reg_pll_dbug_en:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_loop_pi_isel:2;
        RBus_UInt32  reg_lpf_cp:1;
        RBus_UInt32  reg_lpf_sr:3;
        RBus_UInt32  reg_pll_ldo_vsel:2;
        RBus_UInt32  reg_post_pi_rl:2;
        RBus_UInt32  reg_post_pi_bias:2;
        RBus_UInt32  reg_icp:4;
        RBus_UInt32  reg_cco_kvco:1;
        RBus_UInt32  reg_pdiv:2;
        RBus_UInt32  reg_pll_sel_cpmode:1;
        RBus_UInt32  reg_post_pi_rs:1;
        RBus_UInt32  reg_reserved:4;
        RBus_UInt32  reg_en_post_pi:7;
    };
}sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_post_pi_sel0:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_post_pi_sel1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel3:6;
        RBus_UInt32  res1:2;
    };
}sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_post_pi_sel4:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel6:6;
        RBus_UInt32  res1:10;
    };
}sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_time0_ck:3;
        RBus_UInt32  reg_time_rdy_ckout:2;
        RBus_UInt32  reg_time2_rst_width:2;
        RBus_UInt32  reg_cmu_en_wd:1;
        RBus_UInt32  reg_f390k:2;
        RBus_UInt32  res1:22;
    };
}sys_pll_ddr_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_cmu_en_center_in:1;
        RBus_UInt32  reg_cmu_bypass_pi:1;
        RBus_UInt32  reg_cmu_en_ssc:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_cmu_fcode_in:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_cmu_ncode_in:8;
        RBus_UInt32  reg_cmu_ssc_mode:1;
        RBus_UInt32  res1:3;
    };
}sys_pll_ddr_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_cmu_step_in:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_tbase_in:12;
        RBus_UInt32  reg_order:1;
        RBus_UInt32  reg_weighting_sel:3;
    };
}sys_pll_ddr_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ck2x1_sel:1;
        RBus_UInt32  reg_ck1_div2_ph:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_ck2x2_sel:1;
        RBus_UInt32  reg_ck2_div2_ph:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_ck2x3_sel:1;
        RBus_UInt32  reg_ck3_div2_ph:1;
        RBus_UInt32  res1:22;
    };
}sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pll_en:1;
        RBus_UInt32  reg_oeb:1;
        RBus_UInt32  reg_pll_rstb_in:1;
        RBus_UInt32  reg_pll_dbug_en:1;
        RBus_UInt32  res1:28;
    };
}sys_pll_ddr1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_loop_pi_isel:2;
        RBus_UInt32  reg_lpf_cp:1;
        RBus_UInt32  reg_lpf_sr:3;
        RBus_UInt32  reg_pll_ldo_vsel:2;
        RBus_UInt32  reg_post_pi_rl:2;
        RBus_UInt32  reg_post_pi_bias:2;
        RBus_UInt32  reg_icp:4;
        RBus_UInt32  reg_cco_kvco:1;
        RBus_UInt32  reg_pdiv:2;
        RBus_UInt32  reg_pll_sel_cpmode:1;
        RBus_UInt32  reg_post_pi_rs:1;
        RBus_UInt32  reg_reserved:4;
        RBus_UInt32  reg_en_post_pi:7;
    };
}sys_pll_ddr2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_post_pi_sel0:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_post_pi_sel1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel3:6;
        RBus_UInt32  res1:2;
    };
}sys_pll_ddr3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_post_pi_sel4:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_post_pi_sel5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_post_pi_sel6:6;
        RBus_UInt32  res1:10;
    };
}sys_pll_ddr4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_time0_ck:3;
        RBus_UInt32  reg_time_rdy_ckout:2;
        RBus_UInt32  reg_time2_rst_width:2;
        RBus_UInt32  reg_cmu_en_wd:1;
        RBus_UInt32  reg_f390k:2;
        RBus_UInt32  res1:22;
    };
}sys_pll_ddr_ssc1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_cmu_en_center_in:1;
        RBus_UInt32  reg_cmu_bypass_pi:1;
        RBus_UInt32  reg_cmu_en_ssc:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_cmu_fcode_in:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_cmu_ncode_in:8;
        RBus_UInt32  reg_cmu_ssc_mode:1;
        RBus_UInt32  res1:3;
    };
}sys_pll_ddr_ssc2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_cmu_step_in:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_cmu_tbase_in:12;
        RBus_UInt32  reg_order:1;
        RBus_UInt32  reg_weighting_sel:3;
    };
}sys_pll_ddr_ssc3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ck2x1_sel:1;
        RBus_UInt32  reg_ck1_div2_ph:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_ck2x2_sel:1;
        RBus_UInt32  reg_ck2_div2_ph:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_ck2x3_sel:1;
        RBus_UInt32  reg_ck3_div2_ph:1;
        RBus_UInt32  res1:22;
    };
}sys_pll_ddr5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_ssc_stms:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  bus_ssc_ssfpv:8;
        RBus_UInt32  bus_ssc_ssn:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bus_ssc_sss:6;
        RBus_UInt32  bus_ssc_ckinv:1;
        RBus_UInt32  bus_ssc_sse:1;
    };
}sc_buspll_ssc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bush_ssc_stms:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  bush_ssc_ssfpv:8;
        RBus_UInt32  bush_ssc_ssn:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bush_ssc_sss:6;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  bush_ssc_sse:1;
    };
}sc_bushpll_ssc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus2_ssc_stms:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  bus2_ssc_ssfpv:8;
        RBus_UInt32  bus2_ssc_ssn:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bus2_ssc_sss:6;
        RBus_UInt32  bus2_ssc_ckinv:1;
        RBus_UInt32  bus2_ssc_sse:1;
    };
}sc_bus2pll_ssc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_ss_en:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  dclk_ss_rag:4;
        RBus_UInt32  dclk_freq_syn_slt:6;
        RBus_UInt32  dclk_ss_test:1;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  dclk_offset_11_0:12;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  dclk_field_flag_mode_en:1;
    };
}sys_dclkss_RBUS;

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
}dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_mul:8;
        RBus_UInt32  in_frame_tracking_pos_th:12;
        RBus_UInt32  in_frame_tracking_neg_th:12;
    };
}dpll_in_fsync_tracking_ctrl2_RBUS;

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
}dpll_in_fsync_tracking_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc2fsync_speedup_offset:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  frc2fsync_speedup_m_code:3;
        RBus_UInt32  res1:13;
    };
}dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_profile:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  final_m_code:10;
        RBus_UInt32  res1:6;
    };
}dpll_status_ro_RBUS;

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
}dclkss_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_profile_remap_1:12;
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  dclk_ss_shuffle_en:1;
        RBus_UInt32  dummy1800065c_31_30:2;
    };
}dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_3:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_5:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_7:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_9:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_11:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_13:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_15:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_17:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_19:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_21:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_23:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_25:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_27:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_29:12;
        RBus_UInt32  res1:4;
    };
}dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_profile_remap_31:13;
        RBus_UInt32  res1:3;
    };
}dclkss_profile15_RBUS;


#endif







#endif //_RBUS_SYSTEM_REG_H_


