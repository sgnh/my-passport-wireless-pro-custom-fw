/**
* @file rbusPinmuxReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2010/6/17
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PINMUX_REG_H_
#define _RBUS_PINMUX_REG_H_

#include "rbusTypes.h"




// PINMUX Register Address

#define PINMUX_GPIO_CFG_0_VADDR                    (0xb8000800)
#define PINMUX_GPIO_CFG_1_VADDR                    (0xb8000804)
#define PINMUX_GPIO_CFG_2_VADDR                    (0xb8000808)
#define PINMUX_GPIO_CFG_3_VADDR                    (0xb800080c)
#define PINMUX_GPIO_CFG_4_VADDR                    (0xb8000810)
#define PINMUX_GPIO_CFG_5_VADDR                    (0xb8000814)
#define PINMUX_GPIO_CFG_6_VADDR                    (0xb8000818)
#define PINMUX_GPIO_CFG_7_VADDR                    (0xb800081c)
#define PINMUX_GPIO_CFG_8_VADDR                    (0xb8000820)
#define PINMUX_GPIO_CFG_9_VADDR                    (0xb8000824)
#define PINMUX_GPIO_CFG_10_VADDR                   (0xb8000828)
#define PINMUX_GPIO_CFG_11_VADDR                   (0xb800082c)
#define PINMUX_GPIO_CFG_12_VADDR                   (0xb8000830)
#define PINMUX_GPIO_CFG_13_VADDR                   (0xb8000834)
#define PINMUX_GPIO_CFG_14_VADDR                   (0xb8000838)
#define PINMUX_GPIO_CFG_15_VADDR                   (0xb800083c)
#define PINMUX_GPIO_CFG_16_VADDR                   (0xb8000840)
#define PINMUX_GPIO_CFG_17_VADDR                   (0xb8000844)
#define PINMUX_GPIO_CFG_18_VADDR                   (0xb8000848)
#define PINMUX_GPIO_CFG_19_VADDR                   (0xb800084c)
#define PINMUX_GPIO_CFG_20_VADDR                   (0xb8000850)
#define PINMUX_GPIO_CFG_21_VADDR                   (0xb8000854)
#define PINMUX_GPIO_CFG_22_VADDR                   (0xb8000858)
#define PINMUX_GPIO_CFG_23_VADDR                   (0xb800085c)
#define PINMUX_GPIO_CFG_24_VADDR                   (0xb8000860)
#define PINMUX_GPIO_CFG_25_VADDR                   (0xb8000864)
#define PINMUX_GPIO_CFG_26_VADDR                   (0xb8000868)
#define PINMUX_GPIO_CFG_27_VADDR                   (0xb800086c)
#define PINMUX_GPIO_CFG_28_VADDR                   (0xb8000870)
#define PINMUX_GPIO_CFG_29_VADDR                   (0xb8000874)
#define PINMUX_GPIO_CFG_30_VADDR                   (0xb8000878)
#define PINMUX_GPIO_CFG_31_VADDR                   (0xb800087c)
#define PINMUX_GPIO_CFG_32_VADDR                   (0xb8000880)
#define PINMUX_GPIO_CFG_33_VADDR                   (0xb8000884)
#define PINMUX_LVDS_CFG_0_VADDR                    (0xb8000890)
#define PINMUX_LVDS_CFG_1_VADDR                    (0xb8000894)
#define PINMUX_LVDS_CFG_2_VADDR                    (0xb8000898)
#define PINMUX_LVDS_CFG_3_VADDR                    (0xb800089c)
#define PINMUX_LVDS_CFG_4_VADDR                    (0xb80008a0)
#define PINMUX_LVDS_CFG_5_VADDR                    (0xb80008a4)
#define PINMUX_LVDS_CFG_6_VADDR                    (0xb80008a8)
#define PINMUX_LVDS_CFG_7_VADDR                    (0xb80008ac)
#define PINMUX_SCART_FSW_CFG_VADDR                 (0xb80008b0)
#define PINMUX_TUN_I2C_CFG_VADDR                   (0xb80008b4)
#define PINMUX_PIN_MUX_CTRL0_VADDR                 (0xb80008c0)
#define PINMUX_PIN_MUX_CTRL1_VADDR                 (0xb80008c4)
#define PINMUX_PIN_MUX_CTRL2_VADDR                 (0xb80008c8)
#define PINMUX_PIN_MUX_CTRL3_VADDR                 (0xb80008cc)
#define PINMUX_SCHMIDT_TRIGGER_0_VADDR             (0xb8000900)
#define PINMUX_SCHMIDT_TRIGGER_1_VADDR             (0xb8000904)
#define PINMUX_SCHMIDT_TRIGGER_2_VADDR             (0xb8000908)
#define PINMUX_SCHMIDT_TRIGGER_3_VADDR             (0xb800090c)
#define PINMUX_MAIN_TEST_PIN_CTRL_VADDR            (0xb8000910)
#define PINMUX_PXY_CFG1_VADDR                      (0xb8000914)
#define PINMUX_LVDS_CTRL_0_VADDR                   (0xb8000950)
#define PINMUX_LVDS_CTRL_1_VADDR                   (0xb8000954)
#define PINMUX_LVDS_IBG_CTRL_VADDR                 (0xb8000958)
#define PINMUX_LVDS_PLL_CTRL_0_VADDR               (0xb800095c)
#define PINMUX_LVDS_PLL_CTRL_1_VADDR               (0xb8000960)
#define PINMUX_LVDS_PLL_CTRL_2_VADDR               (0xb8000964)
#define PINMUX_LVDS_PLL_CTRL_3_VADDR               (0xb8000968)
#define PINMUX_LVDS_PLL_CTRL_4_VADDR               (0xb800096c)
#define PINMUX_RSDS_CTRL_0_VADDR                   (0xb8000970)
#define PINMUX_LVDS_MISC_CTRL_0_VADDR              (0xb8000974)
#define PINMUX_LVDS_MISC_CTRL_1_VADDR              (0xb8000978)
#define PINMUX_LVDS_MISC_CTRL_2_VADDR              (0xb800097c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PINMUX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_0_ps:4;
        RBus_UInt32  gpio_0_pu:1;
        RBus_UInt32  gpio_0_pd:1;
        RBus_UInt32  gpio_0_ds:1;
        RBus_UInt32  gpio_0_sr:1;
        RBus_UInt32  gpio_1_ps:4;
        RBus_UInt32  gpio_1_pu:1;
        RBus_UInt32  gpio_1_pd:1;
        RBus_UInt32  gpio_1_ds:1;
        RBus_UInt32  gpio_1_sr:1;
        RBus_UInt32  gpio_2_ps:4;
        RBus_UInt32  gpio_2_pu:1;
        RBus_UInt32  gpio_2_pd:1;
        RBus_UInt32  gpio_2_ds:1;
        RBus_UInt32  gpio_2_sr:1;
        RBus_UInt32  gpio_3_ps:4;
        RBus_UInt32  gpio_3_pu:1;
        RBus_UInt32  gpio_3_pd:1;
        RBus_UInt32  gpio_3_ds:1;
        RBus_UInt32  gpio_3_sr:1;
    };
}gpio_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_4_ps:4;
        RBus_UInt32  gpio_4_pu:1;
        RBus_UInt32  gpio_4_pd:1;
        RBus_UInt32  gpio_4_ds:1;
        RBus_UInt32  gpio_4_sr:1;
        RBus_UInt32  gpio_5_ps:4;
        RBus_UInt32  gpio_5_pu:1;
        RBus_UInt32  gpio_5_pd:1;
        RBus_UInt32  gpio_5_ds:1;
        RBus_UInt32  gpio_5_sr:1;
        RBus_UInt32  gpio_6_ps:4;
        RBus_UInt32  gpio_6_pu:1;
        RBus_UInt32  gpio_6_pd:1;
        RBus_UInt32  gpio_6_ds:1;
        RBus_UInt32  gpio_6_sr:1;
        RBus_UInt32  gpio_7_ps:4;
        RBus_UInt32  gpio_7_pu:1;
        RBus_UInt32  gpio_7_pd:1;
        RBus_UInt32  gpio_7_ds:1;
        RBus_UInt32  gpio_7_sr:1;
    };
}gpio_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_8_ps:4;
        RBus_UInt32  gpio_8_pu:1;
        RBus_UInt32  gpio_8_pd:1;
        RBus_UInt32  gpio_8_ds:1;
        RBus_UInt32  gpio_8_sr:1;
        RBus_UInt32  gpio_9_ps:4;
        RBus_UInt32  gpio_9_pu:1;
        RBus_UInt32  gpio_9_pd:1;
        RBus_UInt32  gpio_9_ds:1;
        RBus_UInt32  gpio_9_sr:1;
        RBus_UInt32  gpio_10_ps:4;
        RBus_UInt32  gpio_10_pu:1;
        RBus_UInt32  gpio_10_pd:1;
        RBus_UInt32  gpio_10_ds:1;
        RBus_UInt32  gpio_10_sr:1;
        RBus_UInt32  gpio_11_ps:4;
        RBus_UInt32  gpio_11_pu:1;
        RBus_UInt32  gpio_11_pd:1;
        RBus_UInt32  gpio_11_ds:1;
        RBus_UInt32  gpio_11_sr:1;
    };
}gpio_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_12_ps:4;
        RBus_UInt32  gpio_12_pu:1;
        RBus_UInt32  gpio_12_pd:1;
        RBus_UInt32  gpio_12_ds:1;
        RBus_UInt32  gpio_12_sr:1;
        RBus_UInt32  gpio_13_ps:4;
        RBus_UInt32  gpio_13_pu:1;
        RBus_UInt32  gpio_13_pd:1;
        RBus_UInt32  gpio_13_ds:1;
        RBus_UInt32  gpio_13_sr:1;
        RBus_UInt32  gpio_14_ps:4;
        RBus_UInt32  gpio_14_pu:1;
        RBus_UInt32  gpio_14_pd:1;
        RBus_UInt32  gpio_14_ds:1;
        RBus_UInt32  gpio_14_sr:1;
        RBus_UInt32  gpio_15_ps:4;
        RBus_UInt32  gpio_15_pu:1;
        RBus_UInt32  gpio_15_pd:1;
        RBus_UInt32  gpio_15_ds:1;
        RBus_UInt32  gpio_15_sr:1;
    };
}gpio_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_16_ps:4;
        RBus_UInt32  gpio_16_pu:1;
        RBus_UInt32  gpio_16_pd:1;
        RBus_UInt32  gpio_16_ds:1;
        RBus_UInt32  gpio_16_sr:1;
        RBus_UInt32  gpio_17_ps:4;
        RBus_UInt32  gpio_17_pu:1;
        RBus_UInt32  gpio_17_pd:1;
        RBus_UInt32  gpio_17_ds:1;
        RBus_UInt32  gpio_17_sr:1;
        RBus_UInt32  gpio_18_ps:4;
        RBus_UInt32  gpio_18_pu:1;
        RBus_UInt32  gpio_18_pd:1;
        RBus_UInt32  gpio_18_ds:1;
        RBus_UInt32  gpio_18_sr:1;
        RBus_UInt32  gpio_19_ps:4;
        RBus_UInt32  gpio_19_pu:1;
        RBus_UInt32  gpio_19_pd:1;
        RBus_UInt32  gpio_19_ds:1;
        RBus_UInt32  gpio_19_sr:1;
    };
}gpio_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_20_ps:4;
        RBus_UInt32  gpio_20_pu:1;
        RBus_UInt32  gpio_20_pd:1;
        RBus_UInt32  gpio_20_ds:1;
        RBus_UInt32  gpio_20_sr:1;
        RBus_UInt32  gpio_21_ps:4;
        RBus_UInt32  gpio_21_pu:1;
        RBus_UInt32  gpio_21_pd:1;
        RBus_UInt32  gpio_21_ds:1;
        RBus_UInt32  gpio_21_sr:1;
        RBus_UInt32  gpio_22_ps:4;
        RBus_UInt32  gpio_22_pu:1;
        RBus_UInt32  gpio_22_pd:1;
        RBus_UInt32  gpio_22_ds:1;
        RBus_UInt32  gpio_22_sr:1;
        RBus_UInt32  gpio_23_ps:4;
        RBus_UInt32  gpio_23_pu:1;
        RBus_UInt32  gpio_23_pd:1;
        RBus_UInt32  gpio_23_ds:1;
        RBus_UInt32  gpio_23_sr:1;
    };
}gpio_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_24_ps:4;
        RBus_UInt32  gpio_24_pu:1;
        RBus_UInt32  gpio_24_pd:1;
        RBus_UInt32  gpio_24_ds:1;
        RBus_UInt32  gpio_24_sr:1;
        RBus_UInt32  gpio_25_ps:4;
        RBus_UInt32  gpio_25_pu:1;
        RBus_UInt32  gpio_25_pd:1;
        RBus_UInt32  gpio_25_ds:1;
        RBus_UInt32  gpio_25_sr:1;
        RBus_UInt32  gpio_26_ps:4;
        RBus_UInt32  gpio_26_pu:1;
        RBus_UInt32  gpio_26_pd:1;
        RBus_UInt32  gpio_26_ds:1;
        RBus_UInt32  gpio_26_sr:1;
        RBus_UInt32  gpio_27_ps:4;
        RBus_UInt32  gpio_27_pu:1;
        RBus_UInt32  gpio_27_pd:1;
        RBus_UInt32  gpio_27_ds:1;
        RBus_UInt32  gpio_27_sr:1;
    };
}gpio_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_28_ps:4;
        RBus_UInt32  gpio_28_pu:1;
        RBus_UInt32  gpio_28_pd:1;
        RBus_UInt32  gpio_28_ds:1;
        RBus_UInt32  gpio_28_sr:1;
        RBus_UInt32  gpio_29_ps:4;
        RBus_UInt32  gpio_29_pu:1;
        RBus_UInt32  gpio_29_pd:1;
        RBus_UInt32  gpio_29_ds:1;
        RBus_UInt32  gpio_29_sr:1;
        RBus_UInt32  gpio_30_ps:4;
        RBus_UInt32  gpio_30_pu:1;
        RBus_UInt32  gpio_30_pd:1;
        RBus_UInt32  gpio_30_ds:1;
        RBus_UInt32  gpio_30_sr:1;
        RBus_UInt32  gpio_31_ps:4;
        RBus_UInt32  gpio_31_pu:1;
        RBus_UInt32  gpio_31_pd:1;
        RBus_UInt32  gpio_31_ds:1;
        RBus_UInt32  gpio_31_sr:1;
    };
}gpio_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_32_ps:4;
        RBus_UInt32  gpio_32_pu:1;
        RBus_UInt32  gpio_32_pd:1;
        RBus_UInt32  gpio_32_ds:1;
        RBus_UInt32  gpio_32_sr:1;
        RBus_UInt32  gpio_33_ps:4;
        RBus_UInt32  gpio_33_pu:1;
        RBus_UInt32  gpio_33_pd:1;
        RBus_UInt32  gpio_33_ds:1;
        RBus_UInt32  gpio_33_sr:1;
        RBus_UInt32  gpio_34_ps:4;
        RBus_UInt32  gpio_34_pu:1;
        RBus_UInt32  gpio_34_pd:1;
        RBus_UInt32  gpio_34_ds:1;
        RBus_UInt32  gpio_34_sr:1;
        RBus_UInt32  gpio_35_ps:4;
        RBus_UInt32  gpio_35_pu:1;
        RBus_UInt32  gpio_35_pd:1;
        RBus_UInt32  gpio_35_ds:1;
        RBus_UInt32  gpio_35_sr:1;
    };
}gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_36_ps:4;
        RBus_UInt32  gpio_36_pu:1;
        RBus_UInt32  gpio_36_pd:1;
        RBus_UInt32  gpio_36_ds:1;
        RBus_UInt32  gpio_36_sr:1;
        RBus_UInt32  gpio_37_ps:4;
        RBus_UInt32  gpio_37_pu:1;
        RBus_UInt32  gpio_37_pd:1;
        RBus_UInt32  gpio_37_ds:1;
        RBus_UInt32  gpio_37_sr:1;
        RBus_UInt32  gpio_38_ps:4;
        RBus_UInt32  gpio_38_pu:1;
        RBus_UInt32  gpio_38_pd:1;
        RBus_UInt32  gpio_38_ds:1;
        RBus_UInt32  gpio_38_sr:1;
        RBus_UInt32  gpio_39_ps:4;
        RBus_UInt32  gpio_39_pu:1;
        RBus_UInt32  gpio_39_pd:1;
        RBus_UInt32  gpio_39_ds:1;
        RBus_UInt32  gpio_39_sr:1;
    };
}gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_40_ps:4;
        RBus_UInt32  gpio_40_pu:1;
        RBus_UInt32  gpio_40_pd:1;
        RBus_UInt32  gpio_40_ds:1;
        RBus_UInt32  gpio_40_sr:1;
        RBus_UInt32  gpio_41_ps:4;
        RBus_UInt32  gpio_41_pu:1;
        RBus_UInt32  gpio_41_pd:1;
        RBus_UInt32  gpio_41_ds:1;
        RBus_UInt32  gpio_41_sr:1;
        RBus_UInt32  gpio_42_ps:4;
        RBus_UInt32  gpio_42_pu:1;
        RBus_UInt32  gpio_42_pd:1;
        RBus_UInt32  gpio_42_ds:1;
        RBus_UInt32  gpio_42_sr:1;
        RBus_UInt32  gpio_43_ps:4;
        RBus_UInt32  gpio_43_pu:1;
        RBus_UInt32  gpio_43_pd:1;
        RBus_UInt32  gpio_43_ds:1;
        RBus_UInt32  gpio_43_sr:1;
    };
}gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_44_ps:4;
        RBus_UInt32  gpio_44_pu:1;
        RBus_UInt32  gpio_44_pd:1;
        RBus_UInt32  gpio_44_ds:1;
        RBus_UInt32  gpio_44_sr:1;
        RBus_UInt32  gpio_45_ps:4;
        RBus_UInt32  gpio_45_pu:1;
        RBus_UInt32  gpio_45_pd:1;
        RBus_UInt32  gpio_45_ds:1;
        RBus_UInt32  gpio_45_sr:1;
        RBus_UInt32  gpio_46_ps:4;
        RBus_UInt32  gpio_46_pu:1;
        RBus_UInt32  gpio_46_pd:1;
        RBus_UInt32  gpio_46_ds:1;
        RBus_UInt32  gpio_46_sr:1;
        RBus_UInt32  gpio_47_ps:4;
        RBus_UInt32  gpio_47_pu:1;
        RBus_UInt32  gpio_47_pd:1;
        RBus_UInt32  gpio_47_ds:1;
        RBus_UInt32  gpio_47_sr:1;
    };
}gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_48_ps:4;
        RBus_UInt32  gpio_48_pu:1;
        RBus_UInt32  gpio_48_pd:1;
        RBus_UInt32  gpio_48_ds:1;
        RBus_UInt32  gpio_48_sr:1;
        RBus_UInt32  gpio_49_ps:4;
        RBus_UInt32  gpio_49_pu:1;
        RBus_UInt32  gpio_49_pd:1;
        RBus_UInt32  gpio_49_ds:1;
        RBus_UInt32  gpio_49_sr:1;
        RBus_UInt32  res1:16;
    };
}gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_13_dummy:32;
    };
}gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_14_dummy:32;
    };
}gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gpio_78_ps:4;
        RBus_UInt32  gpio_78_pu:1;
        RBus_UInt32  gpio_78_pd:1;
        RBus_UInt32  gpio_78_ds:1;
        RBus_UInt32  gpio_78_sr:1;
        RBus_UInt32  gpio_79_ps:4;
        RBus_UInt32  gpio_79_pu:1;
        RBus_UInt32  gpio_79_pd:1;
        RBus_UInt32  gpio_79_ds:1;
        RBus_UInt32  gpio_79_sr:1;
    };
}gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_80_ps:4;
        RBus_UInt32  gpio_80_pu:1;
        RBus_UInt32  gpio_80_pd:1;
        RBus_UInt32  gpio_80_ds:1;
        RBus_UInt32  gpio_80_sr:1;
        RBus_UInt32  gpio_81_ps:4;
        RBus_UInt32  gpio_81_pu:1;
        RBus_UInt32  gpio_81_pd:1;
        RBus_UInt32  gpio_81_ds:1;
        RBus_UInt32  gpio_81_sr:1;
        RBus_UInt32  gpio_82_ps:4;
        RBus_UInt32  gpio_82_pu:1;
        RBus_UInt32  gpio_82_pd:1;
        RBus_UInt32  gpio_82_ds:1;
        RBus_UInt32  gpio_82_sr:1;
        RBus_UInt32  gpio_83_ps:4;
        RBus_UInt32  gpio_83_pu:1;
        RBus_UInt32  gpio_83_pd:1;
        RBus_UInt32  gpio_83_ds:1;
        RBus_UInt32  gpio_83_sr:1;
    };
}gpio_cfg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_84_ps:4;
        RBus_UInt32  gpio_84_pu:1;
        RBus_UInt32  gpio_84_pd:1;
        RBus_UInt32  gpio_84_ds:1;
        RBus_UInt32  gpio_84_sr:1;
        RBus_UInt32  gpio_85_ps:4;
        RBus_UInt32  gpio_85_pu:1;
        RBus_UInt32  gpio_85_pd:1;
        RBus_UInt32  gpio_85_ds:1;
        RBus_UInt32  gpio_85_sr:1;
        RBus_UInt32  gpio_86_ps:4;
        RBus_UInt32  gpio_86_pu:1;
        RBus_UInt32  gpio_86_pd:1;
        RBus_UInt32  gpio_86_ds:1;
        RBus_UInt32  gpio_86_sr:1;
        RBus_UInt32  gpio_87_ps:4;
        RBus_UInt32  gpio_87_pu:1;
        RBus_UInt32  gpio_87_pd:1;
        RBus_UInt32  gpio_87_ds:1;
        RBus_UInt32  gpio_87_sr:1;
    };
}gpio_cfg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_88_ps:4;
        RBus_UInt32  gpio_88_pu:1;
        RBus_UInt32  gpio_88_pd:1;
        RBus_UInt32  gpio_88_ds:1;
        RBus_UInt32  gpio_88_sr:1;
        RBus_UInt32  gpio_89_ps:4;
        RBus_UInt32  gpio_89_pu:1;
        RBus_UInt32  gpio_89_pd:1;
        RBus_UInt32  gpio_89_ds:1;
        RBus_UInt32  gpio_89_sr:1;
        RBus_UInt32  gpio_90_ps:4;
        RBus_UInt32  gpio_90_pu:1;
        RBus_UInt32  gpio_90_pd:1;
        RBus_UInt32  gpio_90_ds:1;
        RBus_UInt32  gpio_90_sr:1;
        RBus_UInt32  gpio_91_ps:4;
        RBus_UInt32  gpio_91_pu:1;
        RBus_UInt32  gpio_91_pd:1;
        RBus_UInt32  gpio_91_ds:1;
        RBus_UInt32  gpio_91_sr:1;
    };
}gpio_cfg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_92_ps:4;
        RBus_UInt32  gpio_92_pu:1;
        RBus_UInt32  gpio_92_pd:1;
        RBus_UInt32  gpio_92_ds:1;
        RBus_UInt32  gpio_92_sr:1;
        RBus_UInt32  gpio_93_ps:4;
        RBus_UInt32  gpio_93_pu:1;
        RBus_UInt32  gpio_93_pd:1;
        RBus_UInt32  gpio_93_ds:1;
        RBus_UInt32  gpio_93_sr:1;
        RBus_UInt32  gpio_94_ps:4;
        RBus_UInt32  gpio_94_pu:1;
        RBus_UInt32  gpio_94_pd:1;
        RBus_UInt32  gpio_94_ds:1;
        RBus_UInt32  gpio_94_sr:1;
        RBus_UInt32  gpio_95_ps:4;
        RBus_UInt32  gpio_95_pu:1;
        RBus_UInt32  gpio_95_pd:1;
        RBus_UInt32  gpio_95_ds:1;
        RBus_UInt32  gpio_95_sr:1;
    };
}gpio_cfg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_96_ps:4;
        RBus_UInt32  gpio_96_pu:1;
        RBus_UInt32  gpio_96_pd:1;
        RBus_UInt32  gpio_96_ds:1;
        RBus_UInt32  gpio_96_sr:1;
        RBus_UInt32  gpio_97_ps:4;
        RBus_UInt32  gpio_97_pu:1;
        RBus_UInt32  gpio_97_pd:1;
        RBus_UInt32  gpio_97_ds:1;
        RBus_UInt32  gpio_97_sr:1;
        RBus_UInt32  gpio_98_ps:4;
        RBus_UInt32  gpio_98_pu:1;
        RBus_UInt32  gpio_98_pd:1;
        RBus_UInt32  gpio_98_ds:1;
        RBus_UInt32  gpio_98_sr:1;
        RBus_UInt32  gpio_99_ps:4;
        RBus_UInt32  gpio_99_pu:1;
        RBus_UInt32  gpio_99_pd:1;
        RBus_UInt32  gpio_99_ds:1;
        RBus_UInt32  gpio_99_sr:1;
    };
}gpio_cfg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_100_ps:4;
        RBus_UInt32  gpio_100_pu:1;
        RBus_UInt32  gpio_100_pd:1;
        RBus_UInt32  gpio_100_ds:1;
        RBus_UInt32  gpio_100_sr:1;
        RBus_UInt32  gpio_101_ps:4;
        RBus_UInt32  gpio_101_pu:1;
        RBus_UInt32  gpio_101_pd:1;
        RBus_UInt32  gpio_101_ds:1;
        RBus_UInt32  gpio_101_sr:1;
        RBus_UInt32  gpio_102_ps:4;
        RBus_UInt32  gpio_102_pu:1;
        RBus_UInt32  gpio_102_pd:1;
        RBus_UInt32  gpio_102_ds:1;
        RBus_UInt32  gpio_102_sr:1;
        RBus_UInt32  gpio_103_ps:4;
        RBus_UInt32  gpio_103_pu:1;
        RBus_UInt32  gpio_103_pd:1;
        RBus_UInt32  gpio_103_ds:1;
        RBus_UInt32  gpio_103_sr:1;
    };
}gpio_cfg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_104_ps:4;
        RBus_UInt32  gpio_104_pu:1;
        RBus_UInt32  gpio_104_pd:1;
        RBus_UInt32  gpio_104_ds:1;
        RBus_UInt32  gpio_104_sr:1;
        RBus_UInt32  gpio_105_ps:4;
        RBus_UInt32  gpio_105_pu:1;
        RBus_UInt32  gpio_105_pd:1;
        RBus_UInt32  gpio_105_ds:1;
        RBus_UInt32  gpio_105_sr:1;
        RBus_UInt32  gpio_106_ps:4;
        RBus_UInt32  gpio_106_pu:1;
        RBus_UInt32  gpio_106_pd:1;
        RBus_UInt32  gpio_106_ds:1;
        RBus_UInt32  gpio_106_sr:1;
        RBus_UInt32  gpio_107_ps:4;
        RBus_UInt32  gpio_107_pu:1;
        RBus_UInt32  gpio_107_pd:1;
        RBus_UInt32  gpio_107_ds:1;
        RBus_UInt32  gpio_107_sr:1;
    };
}gpio_cfg_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_108_ps:4;
        RBus_UInt32  gpio_108_pu:1;
        RBus_UInt32  gpio_108_pd:1;
        RBus_UInt32  gpio_108_ds:1;
        RBus_UInt32  gpio_108_sr:1;
        RBus_UInt32  gpio_109_ps:4;
        RBus_UInt32  gpio_109_pu:1;
        RBus_UInt32  gpio_109_pd:1;
        RBus_UInt32  gpio_109_ds:1;
        RBus_UInt32  gpio_109_sr:1;
        RBus_UInt32  gpio_110_ps:4;
        RBus_UInt32  gpio_110_pu:1;
        RBus_UInt32  gpio_110_pd:1;
        RBus_UInt32  gpio_110_ds:1;
        RBus_UInt32  gpio_110_sr:1;
        RBus_UInt32  gpio_111_ps:4;
        RBus_UInt32  gpio_111_pu:1;
        RBus_UInt32  gpio_111_pd:1;
        RBus_UInt32  gpio_111_ds:1;
        RBus_UInt32  gpio_111_sr:1;
    };
}gpio_cfg_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_112_ps:4;
        RBus_UInt32  gpio_112_pu:1;
        RBus_UInt32  gpio_112_pd:1;
        RBus_UInt32  gpio_112_ds:1;
        RBus_UInt32  gpio_112_sr:1;
        RBus_UInt32  gpio_113_ps:4;
        RBus_UInt32  gpio_113_pu:1;
        RBus_UInt32  gpio_113_pd:1;
        RBus_UInt32  gpio_113_ds:1;
        RBus_UInt32  gpio_113_sr:1;
        RBus_UInt32  gpio_114_ps:4;
        RBus_UInt32  gpio_114_pu:1;
        RBus_UInt32  gpio_114_pd:1;
        RBus_UInt32  gpio_114_ds:1;
        RBus_UInt32  gpio_114_sr:1;
        RBus_UInt32  gpio_115_ps:4;
        RBus_UInt32  gpio_115_pu:1;
        RBus_UInt32  gpio_115_pd:1;
        RBus_UInt32  gpio_115_ds:1;
        RBus_UInt32  gpio_115_sr:1;
    };
}gpio_cfg_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_116_ps:4;
        RBus_UInt32  gpio_116_pu:1;
        RBus_UInt32  gpio_116_pd:1;
        RBus_UInt32  gpio_116_ds:1;
        RBus_UInt32  gpio_116_sr:1;
        RBus_UInt32  gpio_117_ps:4;
        RBus_UInt32  gpio_117_pu:1;
        RBus_UInt32  gpio_117_pd:1;
        RBus_UInt32  gpio_117_ds:1;
        RBus_UInt32  gpio_117_sr:1;
        RBus_UInt32  gpio_118_ps:4;
        RBus_UInt32  gpio_118_pu:1;
        RBus_UInt32  gpio_118_pd:1;
        RBus_UInt32  gpio_118_ds:1;
        RBus_UInt32  gpio_118_sr:1;
        RBus_UInt32  gpio_119_ps:4;
        RBus_UInt32  gpio_119_pu:1;
        RBus_UInt32  gpio_119_pd:1;
        RBus_UInt32  gpio_119_ds:1;
        RBus_UInt32  gpio_119_sr:1;
    };
}gpio_cfg_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_120_ps:4;
        RBus_UInt32  gpio_120_pu:1;
        RBus_UInt32  gpio_120_pd:1;
        RBus_UInt32  gpio_120_ds:1;
        RBus_UInt32  gpio_120_sr:1;
        RBus_UInt32  gpio_121_ps:4;
        RBus_UInt32  gpio_121_pu:1;
        RBus_UInt32  gpio_121_pd:1;
        RBus_UInt32  gpio_121_ds:1;
        RBus_UInt32  gpio_121_sr:1;
        RBus_UInt32  gpio_122_ps:4;
        RBus_UInt32  gpio_122_pu:1;
        RBus_UInt32  gpio_122_pd:1;
        RBus_UInt32  gpio_122_ds:1;
        RBus_UInt32  gpio_122_sr:1;
        RBus_UInt32  gpio_123_ps:4;
        RBus_UInt32  gpio_123_pu:1;
        RBus_UInt32  gpio_123_pd:1;
        RBus_UInt32  gpio_123_ds:1;
        RBus_UInt32  gpio_123_sr:1;
    };
}gpio_cfg_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_124_ps:4;
        RBus_UInt32  gpio_124_pu:1;
        RBus_UInt32  gpio_124_pd:1;
        RBus_UInt32  gpio_124_ds:1;
        RBus_UInt32  gpio_124_sr:1;
        RBus_UInt32  gpio_125_ps:4;
        RBus_UInt32  gpio_125_pu:1;
        RBus_UInt32  gpio_125_pd:1;
        RBus_UInt32  gpio_125_ds:1;
        RBus_UInt32  gpio_125_sr:1;
        RBus_UInt32  gpio_126_ps:4;
        RBus_UInt32  gpio_126_pu:1;
        RBus_UInt32  gpio_126_pd:1;
        RBus_UInt32  gpio_126_ds:1;
        RBus_UInt32  gpio_126_sr:1;
        RBus_UInt32  gpio_127_ps:4;
        RBus_UInt32  gpio_127_pu:1;
        RBus_UInt32  gpio_127_pd:1;
        RBus_UInt32  gpio_127_ds:1;
        RBus_UInt32  gpio_127_sr:1;
    };
}gpio_cfg_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_128_ps:4;
        RBus_UInt32  gpio_128_pu:1;
        RBus_UInt32  gpio_128_pd:1;
        RBus_UInt32  gpio_128_ds:1;
        RBus_UInt32  gpio_128_sr:1;
        RBus_UInt32  gpio_129_ps:4;
        RBus_UInt32  gpio_129_pu:1;
        RBus_UInt32  gpio_129_pd:1;
        RBus_UInt32  gpio_129_ds:1;
        RBus_UInt32  gpio_129_sr:1;
        RBus_UInt32  gpio_130_ps:4;
        RBus_UInt32  gpio_130_pu:1;
        RBus_UInt32  gpio_130_pd:1;
        RBus_UInt32  gpio_130_ds:1;
        RBus_UInt32  gpio_130_sr:1;
        RBus_UInt32  res1:8;
    };
}gpio_cfg_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_fp_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_dn_ps:4;
        RBus_UInt32  lvds_a_cp_ps:4;
        RBus_UInt32  lvds_a_cn_ps:4;
    };
}lvds_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_bp_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  res1:16;
    };
}lvds_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_fp_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_en_ps:4;
        RBus_UInt32  lvds_b_dp_ps:4;
        RBus_UInt32  lvds_b_dn_ps:4;
        RBus_UInt32  lvds_b_cp_ps:4;
        RBus_UInt32  lvds_b_cn_ps:4;
    };
}lvds_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_bp_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_an_ps:4;
        RBus_UInt32  res1:16;
    };
}lvds_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_fp_ps:4;
        RBus_UInt32  lvds_c_fn_ps:4;
        RBus_UInt32  lvds_c_ep_ps:4;
        RBus_UInt32  lvds_c_en_ps:4;
        RBus_UInt32  lvds_c_dp_ps:4;
        RBus_UInt32  lvds_c_dn_ps:4;
        RBus_UInt32  lvds_c_cp_ps:4;
        RBus_UInt32  lvds_c_cn_ps:4;
    };
}lvds_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_bp_ps:4;
        RBus_UInt32  lvds_c_bn_ps:4;
        RBus_UInt32  lvds_c_ap_ps:4;
        RBus_UInt32  lvds_c_an_ps:4;
        RBus_UInt32  res1:16;
    };
}lvds_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_fp_ps:4;
        RBus_UInt32  lvds_d_fn_ps:4;
        RBus_UInt32  lvds_d_ep_ps:4;
        RBus_UInt32  lvds_d_en_ps:4;
        RBus_UInt32  lvds_d_dp_ps:4;
        RBus_UInt32  lvds_d_dn_ps:4;
        RBus_UInt32  lvds_d_cp_ps:4;
        RBus_UInt32  lvds_d_cn_ps:4;
    };
}lvds_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_bp_ps:4;
        RBus_UInt32  lvds_d_bn_ps:4;
        RBus_UInt32  lvds_d_ap_ps:4;
        RBus_UInt32  lvds_d_an_ps:4;
        RBus_UInt32  res1:16;
    };
}lvds_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scart_fsw_0_ps:4;
        RBus_UInt32  scart_fsw_1_ps:4;
        RBus_UInt32  res1:24;
    };
}scart_fsw_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2c_sda_ps:4;
        RBus_UInt32  i2c_sda_pu:1;
        RBus_UInt32  i2c_sda_pd:1;
        RBus_UInt32  i2c_sda_ds:1;
        RBus_UInt32  i2c_sda_sr:1;
        RBus_UInt32  i2c_scl_ps:4;
        RBus_UInt32  i2c_scl_pu:1;
        RBus_UInt32  i2c_scl_pd:1;
        RBus_UInt32  i2c_scl_ds:1;
        RBus_UInt32  i2c_scl_sr:1;
        RBus_UInt32  res1:16;
    };
}tun_i2c_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2c2_in_sel:4;
        RBus_UInt32  i2c1_in_sel:4;
        RBus_UInt32  i2c0_in_sel:4;
        RBus_UInt32  uart3_in_sel:4;
        RBus_UInt32  uart2_in_sel:4;
        RBus_UInt32  uart1_in_sel:4;
        RBus_UInt32  uart0_in_sel:4;
        RBus_UInt32  spdif_in_sel:4;
    };
}pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2s_in_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sc_in_sel:4;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  usb_pwr_flag1_in_sel:2;
        RBus_UInt32  irrx_in_sel:4;
        RBus_UInt32  anttx3_in_sel:1;
        RBus_UInt32  anttx2_in_sel:1;
        RBus_UInt32  anttx1_in_sel:1;
        RBus_UInt32  anttx0_in_sel:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  usb3_pwr_flag0_in_sel:1;
        RBus_UInt32  dtv_i2c_sel:1;
        RBus_UInt32  phif_enable:1;
    };
}pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  gpio_50_in_sel:1;
        RBus_UInt32  gpio_51_in_sel:1;
        RBus_UInt32  gpio_52_in_sel:1;
        RBus_UInt32  gpio_53_in_sel:1;
        RBus_UInt32  gpio_54_in_sel:1;
        RBus_UInt32  gpio_55_in_sel:1;
        RBus_UInt32  gpio_56_in_sel:1;
        RBus_UInt32  gpio_57_in_sel:1;
        RBus_UInt32  gpio_58_in_sel:1;
        RBus_UInt32  gpio_59_in_sel:1;
        RBus_UInt32  gpio_60_in_sel:1;
        RBus_UInt32  gpio_61_in_sel:1;
        RBus_UInt32  gpio_62_in_sel:1;
        RBus_UInt32  gpio_63_in_sel:1;
        RBus_UInt32  gpio_64_in_sel:1;
        RBus_UInt32  gpio_65_in_sel:1;
        RBus_UInt32  gpio_66_in_sel:1;
        RBus_UInt32  gpio_67_in_sel:1;
        RBus_UInt32  gpio_68_in_sel:1;
        RBus_UInt32  gpio_69_in_sel:1;
    };
}pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uni_pwm_7_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  uni_pwm_6_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  uni_pwm_5_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  uni_pwm_4_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  uni_pwm_3_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  uni_pwm_2_sel:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  uni_pwm_1_sel:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  uni_pwm_0_sel:3;
	
	};
}pin_mux_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2c_scl_smt:1;
        RBus_UInt32  i2c_sda_smt:1;
        RBus_UInt32  gpio_0_smt:1;
        RBus_UInt32  gpio_1_smt:1;
        RBus_UInt32  gpio_2_smt:1;
        RBus_UInt32  gpio_3_smt:1;
        RBus_UInt32  gpio_4_smt:1;
        RBus_UInt32  gpio_5_smt:1;
        RBus_UInt32  gpio_6_smt:1;
        RBus_UInt32  gpio_7_smt:1;
        RBus_UInt32  gpio_8_smt:1;
        RBus_UInt32  gpio_9_smt:1;
        RBus_UInt32  gpio_10_smt:1;
        RBus_UInt32  gpio_11_smt:1;
        RBus_UInt32  gpio_12_smt:1;
        RBus_UInt32  gpio_13_smt:1;
        RBus_UInt32  gpio_14_smt:1;
        RBus_UInt32  gpio_15_smt:1;
        RBus_UInt32  gpio_16_smt:1;
        RBus_UInt32  gpio_17_smt:1;
        RBus_UInt32  gpio_18_smt:1;
        RBus_UInt32  gpio_19_smt:1;
        RBus_UInt32  gpio_20_smt:1;
        RBus_UInt32  gpio_21_smt:1;
        RBus_UInt32  gpio_22_smt:1;
        RBus_UInt32  gpio_23_smt:1;
        RBus_UInt32  gpio_24_smt:1;
        RBus_UInt32  gpio_25_smt:1;
        RBus_UInt32  gpio_26_smt:1;
        RBus_UInt32  gpio_27_smt:1;
        RBus_UInt32  gpio_28_smt:1;
        RBus_UInt32  gpio_29_smt:1;
    };
}schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_30_smt:1;
        RBus_UInt32  gpio_31_smt:1;
        RBus_UInt32  gpio_32_smt:1;
        RBus_UInt32  gpio_33_smt:1;
        RBus_UInt32  gpio_34_smt:1;
        RBus_UInt32  gpio_35_smt:1;
        RBus_UInt32  gpio_36_smt:1;
        RBus_UInt32  gpio_37_smt:1;
        RBus_UInt32  gpio_38_smt:1;
        RBus_UInt32  gpio_39_smt:1;
        RBus_UInt32  gpio_40_smt:1;
        RBus_UInt32  gpio_41_smt:1;
        RBus_UInt32  gpio_42_smt:1;
        RBus_UInt32  gpio_43_smt:1;
        RBus_UInt32  gpio_44_smt:1;
        RBus_UInt32  gpio_45_smt:1;
        RBus_UInt32  gpio_46_smt:1;
        RBus_UInt32  gpio_47_smt:1;
        RBus_UInt32  gpio_48_smt:1;
        RBus_UInt32  gpio_49_smt:1;
        RBus_UInt32  gpio_78_smt:1;
        RBus_UInt32  gpio_79_smt:1;
        RBus_UInt32  gpio_80_smt:1;
        RBus_UInt32  gpio_81_smt:1;
        RBus_UInt32  gpio_82_smt:1;
        RBus_UInt32  gpio_83_smt:1;
        RBus_UInt32  gpio_84_smt:1;
        RBus_UInt32  gpio_85_smt:1;
        RBus_UInt32  gpio_86_smt:1;
        RBus_UInt32  gpio_87_smt:1;
        RBus_UInt32  gpio_88_smt:1;
        RBus_UInt32  gpio_89_smt:1;
    };
}schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_90_smt:1;
        RBus_UInt32  gpio_91_smt:1;
        RBus_UInt32  gpio_92_smt:1;
        RBus_UInt32  gpio_93_smt:1;
        RBus_UInt32  gpio_94_smt:1;
        RBus_UInt32  gpio_95_smt:1;
        RBus_UInt32  gpio_96_smt:1;
        RBus_UInt32  gpio_97_smt:1;
        RBus_UInt32  gpio_98_smt:1;
        RBus_UInt32  gpio_99_smt:1;
        RBus_UInt32  gpio_100_smt:1;
        RBus_UInt32  gpio_101_smt:1;
        RBus_UInt32  gpio_102_smt:1;
        RBus_UInt32  gpio_103_smt:1;
        RBus_UInt32  gpio_104_smt:1;
        RBus_UInt32  gpio_105_smt:1;
        RBus_UInt32  gpio_106_smt:1;
        RBus_UInt32  gpio_107_smt:1;
        RBus_UInt32  gpio_108_smt:1;
        RBus_UInt32  gpio_109_smt:1;
        RBus_UInt32  gpio_110_smt:1;
        RBus_UInt32  gpio_111_smt:1;
        RBus_UInt32  gpio_112_smt:1;
        RBus_UInt32  gpio_113_smt:1;
        RBus_UInt32  gpio_114_smt:1;
        RBus_UInt32  gpio_115_smt:1;
        RBus_UInt32  gpio_116_smt:1;
        RBus_UInt32  gpio_117_smt:1;
        RBus_UInt32  gpio_118_smt:1;
        RBus_UInt32  gpio_119_smt:1;
        RBus_UInt32  gpio_120_smt:1;
        RBus_UInt32  gpio_121_smt:1;
    };
}schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_122_smt:1;
        RBus_UInt32  gpio_123_smt:1;
        RBus_UInt32  gpio_124_smt:1;
        RBus_UInt32  gpio_125_smt:1;
        RBus_UInt32  gpio_126_smt:1;
        RBus_UInt32  gpio_127_smt:1;
        RBus_UInt32  gpio_128_smt:1;
        RBus_UInt32  gpio_129_smt:1;
        RBus_UInt32  gpio_130_smt:1;
        RBus_UInt32  res1:23;
    };
}schmidt_trigger_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg:16;
        RBus_UInt32  main_ext_clk_en:8;
        RBus_UInt32  testpin_mux:8;
    };
}main_test_pin_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}pxy_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  edalagl1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  edalagl0:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  odalagl1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  odalagl0:6;
    };
}lvds_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_sl1:4;
        RBus_UInt32  pre_sl0:4;
        RBus_UInt32  pre_sr_enl:2;
        RBus_UInt32  pre_sr_sell:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  tst_sell1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tst_sell0:3;
        RBus_UInt32  sl:2;
        RBus_UInt32  ttlo_2xdrvl:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcm_sell1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  vcm_sell0:3;
    };
}lvds_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ibhx_sell1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ibhx_sell0:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ibhn_sell1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  ibhn_sell0:3;
        RBus_UInt32  ibecktx_sell1:2;
        RBus_UInt32  ibecktx_sell0:2;
        RBus_UInt32  ibocktx_sell1:2;
        RBus_UInt32  ibocktx_sell0:2;
        RBus_UInt32  ibtx_sell1:2;
        RBus_UInt32  ibtx_sell0:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  wdol:2;
    };
}lvds_ibg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_calbpl:2;
        RBus_UInt32  pll_callchl:2;
        RBus_UInt32  pll_calswl:2;
        RBus_UInt32  pll_cmpenl:2;
        RBus_UInt32  pll_psctrlel1:12;
        RBus_UInt32  pll_psctrlel0:12;
    };
}lvds_pll_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_csl1:2;
        RBus_UInt32  pll_csl0:2;
        RBus_UInt32  pll_nl1:2;
        RBus_UInt32  pll_nl0:2;
        RBus_UInt32  pll_psctrlol1:12;
        RBus_UInt32  pll_psctrlol0:12;
    };
}lvds_pll_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_cpl:2;
        RBus_UInt32  pll_sel_div2l:2;
        RBus_UInt32  pll_epi_enl:2;
        RBus_UInt32  pll_opi_enl:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_ipl1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_ipl0:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_rsl1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll_rsl0:3;
        RBus_UInt32  pll_powl:2;
        RBus_UInt32  pll_vcorstbl:2;
        RBus_UInt32  pll_sel_psctrlvbpl1:2;
        RBus_UInt32  pll_sel_psctrlvbpl0:2;
    };
}lvds_pll_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_reserved:8;
        RBus_UInt32  pll_reserve1l:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  pll_wdrstl:2;
        RBus_UInt32  pll_wdsetl:2;
        RBus_UInt32  pll_vcomdl1:2;
        RBus_UInt32  pll_vcomdl0:2;
    };
}lvds_pll_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  pll_call:4;
        RBus_UInt32  pll_vo1l:2;
        RBus_UInt32  pll_vo2l:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll_rstbl:2;
    };
}lvds_pll_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}rsds_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pdbl:2;
        RBus_UInt32  ib_powl:2;
        RBus_UInt32  ser_sell1:2;
        RBus_UInt32  ser_sell0:2;
    };
}lvds_misc_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  resvrl_low_msb:24;
    };
}lvds_misc_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  resvrl_low_lsb:24;
    };
}lvds_misc_ctrl_2_RBUS;





#else //apply LITTLE_ENDIAN


//======PINMUX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_3_sr:1;
        RBus_UInt32  gpio_3_ds:1;
        RBus_UInt32  gpio_3_pd:1;
        RBus_UInt32  gpio_3_pu:1;
        RBus_UInt32  gpio_3_ps:4;
        RBus_UInt32  gpio_2_sr:1;
        RBus_UInt32  gpio_2_ds:1;
        RBus_UInt32  gpio_2_pd:1;
        RBus_UInt32  gpio_2_pu:1;
        RBus_UInt32  gpio_2_ps:4;
        RBus_UInt32  gpio_1_sr:1;
        RBus_UInt32  gpio_1_ds:1;
        RBus_UInt32  gpio_1_pd:1;
        RBus_UInt32  gpio_1_pu:1;
        RBus_UInt32  gpio_1_ps:4;
        RBus_UInt32  gpio_0_sr:1;
        RBus_UInt32  gpio_0_ds:1;
        RBus_UInt32  gpio_0_pd:1;
        RBus_UInt32  gpio_0_pu:1;
        RBus_UInt32  gpio_0_ps:4;
    };
}gpio_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_7_sr:1;
        RBus_UInt32  gpio_7_ds:1;
        RBus_UInt32  gpio_7_pd:1;
        RBus_UInt32  gpio_7_pu:1;
        RBus_UInt32  gpio_7_ps:4;
        RBus_UInt32  gpio_6_sr:1;
        RBus_UInt32  gpio_6_ds:1;
        RBus_UInt32  gpio_6_pd:1;
        RBus_UInt32  gpio_6_pu:1;
        RBus_UInt32  gpio_6_ps:4;
        RBus_UInt32  gpio_5_sr:1;
        RBus_UInt32  gpio_5_ds:1;
        RBus_UInt32  gpio_5_pd:1;
        RBus_UInt32  gpio_5_pu:1;
        RBus_UInt32  gpio_5_ps:4;
        RBus_UInt32  gpio_4_sr:1;
        RBus_UInt32  gpio_4_ds:1;
        RBus_UInt32  gpio_4_pd:1;
        RBus_UInt32  gpio_4_pu:1;
        RBus_UInt32  gpio_4_ps:4;
    };
}gpio_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_11_sr:1;
        RBus_UInt32  gpio_11_ds:1;
        RBus_UInt32  gpio_11_pd:1;
        RBus_UInt32  gpio_11_pu:1;
        RBus_UInt32  gpio_11_ps:4;
        RBus_UInt32  gpio_10_sr:1;
        RBus_UInt32  gpio_10_ds:1;
        RBus_UInt32  gpio_10_pd:1;
        RBus_UInt32  gpio_10_pu:1;
        RBus_UInt32  gpio_10_ps:4;
        RBus_UInt32  gpio_9_sr:1;
        RBus_UInt32  gpio_9_ds:1;
        RBus_UInt32  gpio_9_pd:1;
        RBus_UInt32  gpio_9_pu:1;
        RBus_UInt32  gpio_9_ps:4;
        RBus_UInt32  gpio_8_sr:1;
        RBus_UInt32  gpio_8_ds:1;
        RBus_UInt32  gpio_8_pd:1;
        RBus_UInt32  gpio_8_pu:1;
        RBus_UInt32  gpio_8_ps:4;
    };
}gpio_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_15_sr:1;
        RBus_UInt32  gpio_15_ds:1;
        RBus_UInt32  gpio_15_pd:1;
        RBus_UInt32  gpio_15_pu:1;
        RBus_UInt32  gpio_15_ps:4;
        RBus_UInt32  gpio_14_sr:1;
        RBus_UInt32  gpio_14_ds:1;
        RBus_UInt32  gpio_14_pd:1;
        RBus_UInt32  gpio_14_pu:1;
        RBus_UInt32  gpio_14_ps:4;
        RBus_UInt32  gpio_13_sr:1;
        RBus_UInt32  gpio_13_ds:1;
        RBus_UInt32  gpio_13_pd:1;
        RBus_UInt32  gpio_13_pu:1;
        RBus_UInt32  gpio_13_ps:4;
        RBus_UInt32  gpio_12_sr:1;
        RBus_UInt32  gpio_12_ds:1;
        RBus_UInt32  gpio_12_pd:1;
        RBus_UInt32  gpio_12_pu:1;
        RBus_UInt32  gpio_12_ps:4;
    };
}gpio_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_19_sr:1;
        RBus_UInt32  gpio_19_ds:1;
        RBus_UInt32  gpio_19_pd:1;
        RBus_UInt32  gpio_19_pu:1;
        RBus_UInt32  gpio_19_ps:4;
        RBus_UInt32  gpio_18_sr:1;
        RBus_UInt32  gpio_18_ds:1;
        RBus_UInt32  gpio_18_pd:1;
        RBus_UInt32  gpio_18_pu:1;
        RBus_UInt32  gpio_18_ps:4;
        RBus_UInt32  gpio_17_sr:1;
        RBus_UInt32  gpio_17_ds:1;
        RBus_UInt32  gpio_17_pd:1;
        RBus_UInt32  gpio_17_pu:1;
        RBus_UInt32  gpio_17_ps:4;
        RBus_UInt32  gpio_16_sr:1;
        RBus_UInt32  gpio_16_ds:1;
        RBus_UInt32  gpio_16_pd:1;
        RBus_UInt32  gpio_16_pu:1;
        RBus_UInt32  gpio_16_ps:4;
    };
}gpio_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_23_sr:1;
        RBus_UInt32  gpio_23_ds:1;
        RBus_UInt32  gpio_23_pd:1;
        RBus_UInt32  gpio_23_pu:1;
        RBus_UInt32  gpio_23_ps:4;
        RBus_UInt32  gpio_22_sr:1;
        RBus_UInt32  gpio_22_ds:1;
        RBus_UInt32  gpio_22_pd:1;
        RBus_UInt32  gpio_22_pu:1;
        RBus_UInt32  gpio_22_ps:4;
        RBus_UInt32  gpio_21_sr:1;
        RBus_UInt32  gpio_21_ds:1;
        RBus_UInt32  gpio_21_pd:1;
        RBus_UInt32  gpio_21_pu:1;
        RBus_UInt32  gpio_21_ps:4;
        RBus_UInt32  gpio_20_sr:1;
        RBus_UInt32  gpio_20_ds:1;
        RBus_UInt32  gpio_20_pd:1;
        RBus_UInt32  gpio_20_pu:1;
        RBus_UInt32  gpio_20_ps:4;
    };
}gpio_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_27_sr:1;
        RBus_UInt32  gpio_27_ds:1;
        RBus_UInt32  gpio_27_pd:1;
        RBus_UInt32  gpio_27_pu:1;
        RBus_UInt32  gpio_27_ps:4;
        RBus_UInt32  gpio_26_sr:1;
        RBus_UInt32  gpio_26_ds:1;
        RBus_UInt32  gpio_26_pd:1;
        RBus_UInt32  gpio_26_pu:1;
        RBus_UInt32  gpio_26_ps:4;
        RBus_UInt32  gpio_25_sr:1;
        RBus_UInt32  gpio_25_ds:1;
        RBus_UInt32  gpio_25_pd:1;
        RBus_UInt32  gpio_25_pu:1;
        RBus_UInt32  gpio_25_ps:4;
        RBus_UInt32  gpio_24_sr:1;
        RBus_UInt32  gpio_24_ds:1;
        RBus_UInt32  gpio_24_pd:1;
        RBus_UInt32  gpio_24_pu:1;
        RBus_UInt32  gpio_24_ps:4;
    };
}gpio_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_31_sr:1;
        RBus_UInt32  gpio_31_ds:1;
        RBus_UInt32  gpio_31_pd:1;
        RBus_UInt32  gpio_31_pu:1;
        RBus_UInt32  gpio_31_ps:4;
        RBus_UInt32  gpio_30_sr:1;
        RBus_UInt32  gpio_30_ds:1;
        RBus_UInt32  gpio_30_pd:1;
        RBus_UInt32  gpio_30_pu:1;
        RBus_UInt32  gpio_30_ps:4;
        RBus_UInt32  gpio_29_sr:1;
        RBus_UInt32  gpio_29_ds:1;
        RBus_UInt32  gpio_29_pd:1;
        RBus_UInt32  gpio_29_pu:1;
        RBus_UInt32  gpio_29_ps:4;
        RBus_UInt32  gpio_28_sr:1;
        RBus_UInt32  gpio_28_ds:1;
        RBus_UInt32  gpio_28_pd:1;
        RBus_UInt32  gpio_28_pu:1;
        RBus_UInt32  gpio_28_ps:4;
    };
}gpio_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_35_sr:1;
        RBus_UInt32  gpio_35_ds:1;
        RBus_UInt32  gpio_35_pd:1;
        RBus_UInt32  gpio_35_pu:1;
        RBus_UInt32  gpio_35_ps:4;
        RBus_UInt32  gpio_34_sr:1;
        RBus_UInt32  gpio_34_ds:1;
        RBus_UInt32  gpio_34_pd:1;
        RBus_UInt32  gpio_34_pu:1;
        RBus_UInt32  gpio_34_ps:4;
        RBus_UInt32  gpio_33_sr:1;
        RBus_UInt32  gpio_33_ds:1;
        RBus_UInt32  gpio_33_pd:1;
        RBus_UInt32  gpio_33_pu:1;
        RBus_UInt32  gpio_33_ps:4;
        RBus_UInt32  gpio_32_sr:1;
        RBus_UInt32  gpio_32_ds:1;
        RBus_UInt32  gpio_32_pd:1;
        RBus_UInt32  gpio_32_pu:1;
        RBus_UInt32  gpio_32_ps:4;
    };
}gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_39_sr:1;
        RBus_UInt32  gpio_39_ds:1;
        RBus_UInt32  gpio_39_pd:1;
        RBus_UInt32  gpio_39_pu:1;
        RBus_UInt32  gpio_39_ps:4;
        RBus_UInt32  gpio_38_sr:1;
        RBus_UInt32  gpio_38_ds:1;
        RBus_UInt32  gpio_38_pd:1;
        RBus_UInt32  gpio_38_pu:1;
        RBus_UInt32  gpio_38_ps:4;
        RBus_UInt32  gpio_37_sr:1;
        RBus_UInt32  gpio_37_ds:1;
        RBus_UInt32  gpio_37_pd:1;
        RBus_UInt32  gpio_37_pu:1;
        RBus_UInt32  gpio_37_ps:4;
        RBus_UInt32  gpio_36_sr:1;
        RBus_UInt32  gpio_36_ds:1;
        RBus_UInt32  gpio_36_pd:1;
        RBus_UInt32  gpio_36_pu:1;
        RBus_UInt32  gpio_36_ps:4;
    };
}gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_43_sr:1;
        RBus_UInt32  gpio_43_ds:1;
        RBus_UInt32  gpio_43_pd:1;
        RBus_UInt32  gpio_43_pu:1;
        RBus_UInt32  gpio_43_ps:4;
        RBus_UInt32  gpio_42_sr:1;
        RBus_UInt32  gpio_42_ds:1;
        RBus_UInt32  gpio_42_pd:1;
        RBus_UInt32  gpio_42_pu:1;
        RBus_UInt32  gpio_42_ps:4;
        RBus_UInt32  gpio_41_sr:1;
        RBus_UInt32  gpio_41_ds:1;
        RBus_UInt32  gpio_41_pd:1;
        RBus_UInt32  gpio_41_pu:1;
        RBus_UInt32  gpio_41_ps:4;
        RBus_UInt32  gpio_40_sr:1;
        RBus_UInt32  gpio_40_ds:1;
        RBus_UInt32  gpio_40_pd:1;
        RBus_UInt32  gpio_40_pu:1;
        RBus_UInt32  gpio_40_ps:4;
    };
}gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_47_sr:1;
        RBus_UInt32  gpio_47_ds:1;
        RBus_UInt32  gpio_47_pd:1;
        RBus_UInt32  gpio_47_pu:1;
        RBus_UInt32  gpio_47_ps:4;
        RBus_UInt32  gpio_46_sr:1;
        RBus_UInt32  gpio_46_ds:1;
        RBus_UInt32  gpio_46_pd:1;
        RBus_UInt32  gpio_46_pu:1;
        RBus_UInt32  gpio_46_ps:4;
        RBus_UInt32  gpio_45_sr:1;
        RBus_UInt32  gpio_45_ds:1;
        RBus_UInt32  gpio_45_pd:1;
        RBus_UInt32  gpio_45_pu:1;
        RBus_UInt32  gpio_45_ps:4;
        RBus_UInt32  gpio_44_sr:1;
        RBus_UInt32  gpio_44_ds:1;
        RBus_UInt32  gpio_44_pd:1;
        RBus_UInt32  gpio_44_pu:1;
        RBus_UInt32  gpio_44_ps:4;
    };
}gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gpio_49_sr:1;
        RBus_UInt32  gpio_49_ds:1;
        RBus_UInt32  gpio_49_pd:1;
        RBus_UInt32  gpio_49_pu:1;
        RBus_UInt32  gpio_49_ps:4;
        RBus_UInt32  gpio_48_sr:1;
        RBus_UInt32  gpio_48_ds:1;
        RBus_UInt32  gpio_48_pd:1;
        RBus_UInt32  gpio_48_pu:1;
        RBus_UInt32  gpio_48_ps:4;
    };
}gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_13_dummy:32;
    };
}gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_14_dummy:32;
    };
}gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_79_sr:1;
        RBus_UInt32  gpio_79_ds:1;
        RBus_UInt32  gpio_79_pd:1;
        RBus_UInt32  gpio_79_pu:1;
        RBus_UInt32  gpio_79_ps:4;
        RBus_UInt32  gpio_78_sr:1;
        RBus_UInt32  gpio_78_ds:1;
        RBus_UInt32  gpio_78_pd:1;
        RBus_UInt32  gpio_78_pu:1;
        RBus_UInt32  gpio_78_ps:4;
        RBus_UInt32  res1:16;
    };
}gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_83_sr:1;
        RBus_UInt32  gpio_83_ds:1;
        RBus_UInt32  gpio_83_pd:1;
        RBus_UInt32  gpio_83_pu:1;
        RBus_UInt32  gpio_83_ps:4;
        RBus_UInt32  gpio_82_sr:1;
        RBus_UInt32  gpio_82_ds:1;
        RBus_UInt32  gpio_82_pd:1;
        RBus_UInt32  gpio_82_pu:1;
        RBus_UInt32  gpio_82_ps:4;
        RBus_UInt32  gpio_81_sr:1;
        RBus_UInt32  gpio_81_ds:1;
        RBus_UInt32  gpio_81_pd:1;
        RBus_UInt32  gpio_81_pu:1;
        RBus_UInt32  gpio_81_ps:4;
        RBus_UInt32  gpio_80_sr:1;
        RBus_UInt32  gpio_80_ds:1;
        RBus_UInt32  gpio_80_pd:1;
        RBus_UInt32  gpio_80_pu:1;
        RBus_UInt32  gpio_80_ps:4;
    };
}gpio_cfg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_87_sr:1;
        RBus_UInt32  gpio_87_ds:1;
        RBus_UInt32  gpio_87_pd:1;
        RBus_UInt32  gpio_87_pu:1;
        RBus_UInt32  gpio_87_ps:4;
        RBus_UInt32  gpio_86_sr:1;
        RBus_UInt32  gpio_86_ds:1;
        RBus_UInt32  gpio_86_pd:1;
        RBus_UInt32  gpio_86_pu:1;
        RBus_UInt32  gpio_86_ps:4;
        RBus_UInt32  gpio_85_sr:1;
        RBus_UInt32  gpio_85_ds:1;
        RBus_UInt32  gpio_85_pd:1;
        RBus_UInt32  gpio_85_pu:1;
        RBus_UInt32  gpio_85_ps:4;
        RBus_UInt32  gpio_84_sr:1;
        RBus_UInt32  gpio_84_ds:1;
        RBus_UInt32  gpio_84_pd:1;
        RBus_UInt32  gpio_84_pu:1;
        RBus_UInt32  gpio_84_ps:4;
    };
}gpio_cfg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_91_sr:1;
        RBus_UInt32  gpio_91_ds:1;
        RBus_UInt32  gpio_91_pd:1;
        RBus_UInt32  gpio_91_pu:1;
        RBus_UInt32  gpio_91_ps:4;
        RBus_UInt32  gpio_90_sr:1;
        RBus_UInt32  gpio_90_ds:1;
        RBus_UInt32  gpio_90_pd:1;
        RBus_UInt32  gpio_90_pu:1;
        RBus_UInt32  gpio_90_ps:4;
        RBus_UInt32  gpio_89_sr:1;
        RBus_UInt32  gpio_89_ds:1;
        RBus_UInt32  gpio_89_pd:1;
        RBus_UInt32  gpio_89_pu:1;
        RBus_UInt32  gpio_89_ps:4;
        RBus_UInt32  gpio_88_sr:1;
        RBus_UInt32  gpio_88_ds:1;
        RBus_UInt32  gpio_88_pd:1;
        RBus_UInt32  gpio_88_pu:1;
        RBus_UInt32  gpio_88_ps:4;
    };
}gpio_cfg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_95_sr:1;
        RBus_UInt32  gpio_95_ds:1;
        RBus_UInt32  gpio_95_pd:1;
        RBus_UInt32  gpio_95_pu:1;
        RBus_UInt32  gpio_95_ps:4;
        RBus_UInt32  gpio_94_sr:1;
        RBus_UInt32  gpio_94_ds:1;
        RBus_UInt32  gpio_94_pd:1;
        RBus_UInt32  gpio_94_pu:1;
        RBus_UInt32  gpio_94_ps:4;
        RBus_UInt32  gpio_93_sr:1;
        RBus_UInt32  gpio_93_ds:1;
        RBus_UInt32  gpio_93_pd:1;
        RBus_UInt32  gpio_93_pu:1;
        RBus_UInt32  gpio_93_ps:4;
        RBus_UInt32  gpio_92_sr:1;
        RBus_UInt32  gpio_92_ds:1;
        RBus_UInt32  gpio_92_pd:1;
        RBus_UInt32  gpio_92_pu:1;
        RBus_UInt32  gpio_92_ps:4;
    };
}gpio_cfg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_99_sr:1;
        RBus_UInt32  gpio_99_ds:1;
        RBus_UInt32  gpio_99_pd:1;
        RBus_UInt32  gpio_99_pu:1;
        RBus_UInt32  gpio_99_ps:4;
        RBus_UInt32  gpio_98_sr:1;
        RBus_UInt32  gpio_98_ds:1;
        RBus_UInt32  gpio_98_pd:1;
        RBus_UInt32  gpio_98_pu:1;
        RBus_UInt32  gpio_98_ps:4;
        RBus_UInt32  gpio_97_sr:1;
        RBus_UInt32  gpio_97_ds:1;
        RBus_UInt32  gpio_97_pd:1;
        RBus_UInt32  gpio_97_pu:1;
        RBus_UInt32  gpio_97_ps:4;
        RBus_UInt32  gpio_96_sr:1;
        RBus_UInt32  gpio_96_ds:1;
        RBus_UInt32  gpio_96_pd:1;
        RBus_UInt32  gpio_96_pu:1;
        RBus_UInt32  gpio_96_ps:4;
    };
}gpio_cfg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_103_sr:1;
        RBus_UInt32  gpio_103_ds:1;
        RBus_UInt32  gpio_103_pd:1;
        RBus_UInt32  gpio_103_pu:1;
        RBus_UInt32  gpio_103_ps:4;
        RBus_UInt32  gpio_102_sr:1;
        RBus_UInt32  gpio_102_ds:1;
        RBus_UInt32  gpio_102_pd:1;
        RBus_UInt32  gpio_102_pu:1;
        RBus_UInt32  gpio_102_ps:4;
        RBus_UInt32  gpio_101_sr:1;
        RBus_UInt32  gpio_101_ds:1;
        RBus_UInt32  gpio_101_pd:1;
        RBus_UInt32  gpio_101_pu:1;
        RBus_UInt32  gpio_101_ps:4;
        RBus_UInt32  gpio_100_sr:1;
        RBus_UInt32  gpio_100_ds:1;
        RBus_UInt32  gpio_100_pd:1;
        RBus_UInt32  gpio_100_pu:1;
        RBus_UInt32  gpio_100_ps:4;
    };
}gpio_cfg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_107_sr:1;
        RBus_UInt32  gpio_107_ds:1;
        RBus_UInt32  gpio_107_pd:1;
        RBus_UInt32  gpio_107_pu:1;
        RBus_UInt32  gpio_107_ps:4;
        RBus_UInt32  gpio_106_sr:1;
        RBus_UInt32  gpio_106_ds:1;
        RBus_UInt32  gpio_106_pd:1;
        RBus_UInt32  gpio_106_pu:1;
        RBus_UInt32  gpio_106_ps:4;
        RBus_UInt32  gpio_105_sr:1;
        RBus_UInt32  gpio_105_ds:1;
        RBus_UInt32  gpio_105_pd:1;
        RBus_UInt32  gpio_105_pu:1;
        RBus_UInt32  gpio_105_ps:4;
        RBus_UInt32  gpio_104_sr:1;
        RBus_UInt32  gpio_104_ds:1;
        RBus_UInt32  gpio_104_pd:1;
        RBus_UInt32  gpio_104_pu:1;
        RBus_UInt32  gpio_104_ps:4;
    };
}gpio_cfg_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_111_sr:1;
        RBus_UInt32  gpio_111_ds:1;
        RBus_UInt32  gpio_111_pd:1;
        RBus_UInt32  gpio_111_pu:1;
        RBus_UInt32  gpio_111_ps:4;
        RBus_UInt32  gpio_110_sr:1;
        RBus_UInt32  gpio_110_ds:1;
        RBus_UInt32  gpio_110_pd:1;
        RBus_UInt32  gpio_110_pu:1;
        RBus_UInt32  gpio_110_ps:4;
        RBus_UInt32  gpio_109_sr:1;
        RBus_UInt32  gpio_109_ds:1;
        RBus_UInt32  gpio_109_pd:1;
        RBus_UInt32  gpio_109_pu:1;
        RBus_UInt32  gpio_109_ps:4;
        RBus_UInt32  gpio_108_sr:1;
        RBus_UInt32  gpio_108_ds:1;
        RBus_UInt32  gpio_108_pd:1;
        RBus_UInt32  gpio_108_pu:1;
        RBus_UInt32  gpio_108_ps:4;
    };
}gpio_cfg_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_115_sr:1;
        RBus_UInt32  gpio_115_ds:1;
        RBus_UInt32  gpio_115_pd:1;
        RBus_UInt32  gpio_115_pu:1;
        RBus_UInt32  gpio_115_ps:4;
        RBus_UInt32  gpio_114_sr:1;
        RBus_UInt32  gpio_114_ds:1;
        RBus_UInt32  gpio_114_pd:1;
        RBus_UInt32  gpio_114_pu:1;
        RBus_UInt32  gpio_114_ps:4;
        RBus_UInt32  gpio_113_sr:1;
        RBus_UInt32  gpio_113_ds:1;
        RBus_UInt32  gpio_113_pd:1;
        RBus_UInt32  gpio_113_pu:1;
        RBus_UInt32  gpio_113_ps:4;
        RBus_UInt32  gpio_112_sr:1;
        RBus_UInt32  gpio_112_ds:1;
        RBus_UInt32  gpio_112_pd:1;
        RBus_UInt32  gpio_112_pu:1;
        RBus_UInt32  gpio_112_ps:4;
    };
}gpio_cfg_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_119_sr:1;
        RBus_UInt32  gpio_119_ds:1;
        RBus_UInt32  gpio_119_pd:1;
        RBus_UInt32  gpio_119_pu:1;
        RBus_UInt32  gpio_119_ps:4;
        RBus_UInt32  gpio_118_sr:1;
        RBus_UInt32  gpio_118_ds:1;
        RBus_UInt32  gpio_118_pd:1;
        RBus_UInt32  gpio_118_pu:1;
        RBus_UInt32  gpio_118_ps:4;
        RBus_UInt32  gpio_117_sr:1;
        RBus_UInt32  gpio_117_ds:1;
        RBus_UInt32  gpio_117_pd:1;
        RBus_UInt32  gpio_117_pu:1;
        RBus_UInt32  gpio_117_ps:4;
        RBus_UInt32  gpio_116_sr:1;
        RBus_UInt32  gpio_116_ds:1;
        RBus_UInt32  gpio_116_pd:1;
        RBus_UInt32  gpio_116_pu:1;
        RBus_UInt32  gpio_116_ps:4;
    };
}gpio_cfg_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_123_sr:1;
        RBus_UInt32  gpio_123_ds:1;
        RBus_UInt32  gpio_123_pd:1;
        RBus_UInt32  gpio_123_pu:1;
        RBus_UInt32  gpio_123_ps:4;
        RBus_UInt32  gpio_122_sr:1;
        RBus_UInt32  gpio_122_ds:1;
        RBus_UInt32  gpio_122_pd:1;
        RBus_UInt32  gpio_122_pu:1;
        RBus_UInt32  gpio_122_ps:4;
        RBus_UInt32  gpio_121_sr:1;
        RBus_UInt32  gpio_121_ds:1;
        RBus_UInt32  gpio_121_pd:1;
        RBus_UInt32  gpio_121_pu:1;
        RBus_UInt32  gpio_121_ps:4;
        RBus_UInt32  gpio_120_sr:1;
        RBus_UInt32  gpio_120_ds:1;
        RBus_UInt32  gpio_120_pd:1;
        RBus_UInt32  gpio_120_pu:1;
        RBus_UInt32  gpio_120_ps:4;
    };
}gpio_cfg_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_127_sr:1;
        RBus_UInt32  gpio_127_ds:1;
        RBus_UInt32  gpio_127_pd:1;
        RBus_UInt32  gpio_127_pu:1;
        RBus_UInt32  gpio_127_ps:4;
        RBus_UInt32  gpio_126_sr:1;
        RBus_UInt32  gpio_126_ds:1;
        RBus_UInt32  gpio_126_pd:1;
        RBus_UInt32  gpio_126_pu:1;
        RBus_UInt32  gpio_126_ps:4;
        RBus_UInt32  gpio_125_sr:1;
        RBus_UInt32  gpio_125_ds:1;
        RBus_UInt32  gpio_125_pd:1;
        RBus_UInt32  gpio_125_pu:1;
        RBus_UInt32  gpio_125_ps:4;
        RBus_UInt32  gpio_124_sr:1;
        RBus_UInt32  gpio_124_ds:1;
        RBus_UInt32  gpio_124_pd:1;
        RBus_UInt32  gpio_124_pu:1;
        RBus_UInt32  gpio_124_ps:4;
    };
}gpio_cfg_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gpio_130_sr:1;
        RBus_UInt32  gpio_130_ds:1;
        RBus_UInt32  gpio_130_pd:1;
        RBus_UInt32  gpio_130_pu:1;
        RBus_UInt32  gpio_130_ps:4;
        RBus_UInt32  gpio_129_sr:1;
        RBus_UInt32  gpio_129_ds:1;
        RBus_UInt32  gpio_129_pd:1;
        RBus_UInt32  gpio_129_pu:1;
        RBus_UInt32  gpio_129_ps:4;
        RBus_UInt32  gpio_128_sr:1;
        RBus_UInt32  gpio_128_ds:1;
        RBus_UInt32  gpio_128_pd:1;
        RBus_UInt32  gpio_128_pu:1;
        RBus_UInt32  gpio_128_ps:4;
    };
}gpio_cfg_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_cn_ps:4;
        RBus_UInt32  lvds_a_cp_ps:4;
        RBus_UInt32  lvds_a_dn_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_fp_ps:4;
    };
}lvds_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_bp_ps:4;
    };
}lvds_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_cn_ps:4;
        RBus_UInt32  lvds_b_cp_ps:4;
        RBus_UInt32  lvds_b_dn_ps:4;
        RBus_UInt32  lvds_b_dp_ps:4;
        RBus_UInt32  lvds_b_en_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_fp_ps:4;
    };
}lvds_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lvds_b_an_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_bp_ps:4;
    };
}lvds_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_cn_ps:4;
        RBus_UInt32  lvds_c_cp_ps:4;
        RBus_UInt32  lvds_c_dn_ps:4;
        RBus_UInt32  lvds_c_dp_ps:4;
        RBus_UInt32  lvds_c_en_ps:4;
        RBus_UInt32  lvds_c_ep_ps:4;
        RBus_UInt32  lvds_c_fn_ps:4;
        RBus_UInt32  lvds_c_fp_ps:4;
    };
}lvds_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lvds_c_an_ps:4;
        RBus_UInt32  lvds_c_ap_ps:4;
        RBus_UInt32  lvds_c_bn_ps:4;
        RBus_UInt32  lvds_c_bp_ps:4;
    };
}lvds_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_cn_ps:4;
        RBus_UInt32  lvds_d_cp_ps:4;
        RBus_UInt32  lvds_d_dn_ps:4;
        RBus_UInt32  lvds_d_dp_ps:4;
        RBus_UInt32  lvds_d_en_ps:4;
        RBus_UInt32  lvds_d_ep_ps:4;
        RBus_UInt32  lvds_d_fn_ps:4;
        RBus_UInt32  lvds_d_fp_ps:4;
    };
}lvds_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lvds_d_an_ps:4;
        RBus_UInt32  lvds_d_ap_ps:4;
        RBus_UInt32  lvds_d_bn_ps:4;
        RBus_UInt32  lvds_d_bp_ps:4;
    };
}lvds_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scart_fsw_1_ps:4;
        RBus_UInt32  scart_fsw_0_ps:4;
    };
}scart_fsw_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  i2c_scl_sr:1;
        RBus_UInt32  i2c_scl_ds:1;
        RBus_UInt32  i2c_scl_pd:1;
        RBus_UInt32  i2c_scl_pu:1;
        RBus_UInt32  i2c_scl_ps:4;
        RBus_UInt32  i2c_sda_sr:1;
        RBus_UInt32  i2c_sda_ds:1;
        RBus_UInt32  i2c_sda_pd:1;
        RBus_UInt32  i2c_sda_pu:1;
        RBus_UInt32  i2c_sda_ps:4;
    };
}tun_i2c_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spdif_in_sel:4;
        RBus_UInt32  uart0_in_sel:4;
        RBus_UInt32  uart1_in_sel:4;
        RBus_UInt32  uart2_in_sel:4;
        RBus_UInt32  uart3_in_sel:4;
        RBus_UInt32  i2c0_in_sel:4;
        RBus_UInt32  i2c1_in_sel:4;
        RBus_UInt32  i2c2_in_sel:4;
    };
}pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:12;
        RBus_UInt32  anttx0_in_sel:1;
        RBus_UInt32  anttx1_in_sel:1;
        RBus_UInt32  anttx2_in_sel:1;
        RBus_UInt32  anttx3_in_sel:1;
        RBus_UInt32  irrx_in_sel:4;
        RBus_UInt32  usb_pwr_flag1_in_sel:2;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  sc_in_sel:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2s_in_sel:1;
    };
}pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_69_in_sel:1;
        RBus_UInt32  gpio_68_in_sel:1;
        RBus_UInt32  gpio_67_in_sel:1;
        RBus_UInt32  gpio_66_in_sel:1;
        RBus_UInt32  gpio_65_in_sel:1;
        RBus_UInt32  gpio_64_in_sel:1;
        RBus_UInt32  gpio_63_in_sel:1;
        RBus_UInt32  gpio_62_in_sel:1;
        RBus_UInt32  gpio_61_in_sel:1;
        RBus_UInt32  gpio_60_in_sel:1;
        RBus_UInt32  gpio_59_in_sel:1;
        RBus_UInt32  gpio_58_in_sel:1;
        RBus_UInt32  gpio_57_in_sel:1;
        RBus_UInt32  gpio_56_in_sel:1;
        RBus_UInt32  gpio_55_in_sel:1;
        RBus_UInt32  gpio_54_in_sel:1;
        RBus_UInt32  gpio_53_in_sel:1;
        RBus_UInt32  gpio_52_in_sel:1;
        RBus_UInt32  gpio_51_in_sel:1;
        RBus_UInt32  gpio_50_in_sel:1;
        RBus_UInt32  res1:12;
    };
}pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uni_pwm_7_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  uni_pwm_6_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  uni_pwm_5_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  uni_pwm_4_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  uni_pwm_3_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  uni_pwm_2_sel:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  uni_pwm_1_sel:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  uni_pwm_0_sel:3;
	};
}pin_mux_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_29_smt:1;
        RBus_UInt32  gpio_28_smt:1;
        RBus_UInt32  gpio_27_smt:1;
        RBus_UInt32  gpio_26_smt:1;
        RBus_UInt32  gpio_25_smt:1;
        RBus_UInt32  gpio_24_smt:1;
        RBus_UInt32  gpio_23_smt:1;
        RBus_UInt32  gpio_22_smt:1;
        RBus_UInt32  gpio_21_smt:1;
        RBus_UInt32  gpio_20_smt:1;
        RBus_UInt32  gpio_19_smt:1;
        RBus_UInt32  gpio_18_smt:1;
        RBus_UInt32  gpio_17_smt:1;
        RBus_UInt32  gpio_16_smt:1;
        RBus_UInt32  gpio_15_smt:1;
        RBus_UInt32  gpio_14_smt:1;
        RBus_UInt32  gpio_13_smt:1;
        RBus_UInt32  gpio_12_smt:1;
        RBus_UInt32  gpio_11_smt:1;
        RBus_UInt32  gpio_10_smt:1;
        RBus_UInt32  gpio_9_smt:1;
        RBus_UInt32  gpio_8_smt:1;
        RBus_UInt32  gpio_7_smt:1;
        RBus_UInt32  gpio_6_smt:1;
        RBus_UInt32  gpio_5_smt:1;
        RBus_UInt32  gpio_4_smt:1;
        RBus_UInt32  gpio_3_smt:1;
        RBus_UInt32  gpio_2_smt:1;
        RBus_UInt32  gpio_1_smt:1;
        RBus_UInt32  gpio_0_smt:1;
        RBus_UInt32  i2c_sda_smt:1;
        RBus_UInt32  i2c_scl_smt:1;
    };
}schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_89_smt:1;
        RBus_UInt32  gpio_88_smt:1;
        RBus_UInt32  gpio_87_smt:1;
        RBus_UInt32  gpio_86_smt:1;
        RBus_UInt32  gpio_85_smt:1;
        RBus_UInt32  gpio_84_smt:1;
        RBus_UInt32  gpio_83_smt:1;
        RBus_UInt32  gpio_82_smt:1;
        RBus_UInt32  gpio_81_smt:1;
        RBus_UInt32  gpio_80_smt:1;
        RBus_UInt32  gpio_79_smt:1;
        RBus_UInt32  gpio_78_smt:1;
        RBus_UInt32  gpio_49_smt:1;
        RBus_UInt32  gpio_48_smt:1;
        RBus_UInt32  gpio_47_smt:1;
        RBus_UInt32  gpio_46_smt:1;
        RBus_UInt32  gpio_45_smt:1;
        RBus_UInt32  gpio_44_smt:1;
        RBus_UInt32  gpio_43_smt:1;
        RBus_UInt32  gpio_42_smt:1;
        RBus_UInt32  gpio_41_smt:1;
        RBus_UInt32  gpio_40_smt:1;
        RBus_UInt32  gpio_39_smt:1;
        RBus_UInt32  gpio_38_smt:1;
        RBus_UInt32  gpio_37_smt:1;
        RBus_UInt32  gpio_36_smt:1;
        RBus_UInt32  gpio_35_smt:1;
        RBus_UInt32  gpio_34_smt:1;
        RBus_UInt32  gpio_33_smt:1;
        RBus_UInt32  gpio_32_smt:1;
        RBus_UInt32  gpio_31_smt:1;
        RBus_UInt32  gpio_30_smt:1;
    };
}schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_121_smt:1;
        RBus_UInt32  gpio_120_smt:1;
        RBus_UInt32  gpio_119_smt:1;
        RBus_UInt32  gpio_118_smt:1;
        RBus_UInt32  gpio_117_smt:1;
        RBus_UInt32  gpio_116_smt:1;
        RBus_UInt32  gpio_115_smt:1;
        RBus_UInt32  gpio_114_smt:1;
        RBus_UInt32  gpio_113_smt:1;
        RBus_UInt32  gpio_112_smt:1;
        RBus_UInt32  gpio_111_smt:1;
        RBus_UInt32  gpio_110_smt:1;
        RBus_UInt32  gpio_109_smt:1;
        RBus_UInt32  gpio_108_smt:1;
        RBus_UInt32  gpio_107_smt:1;
        RBus_UInt32  gpio_106_smt:1;
        RBus_UInt32  gpio_105_smt:1;
        RBus_UInt32  gpio_104_smt:1;
        RBus_UInt32  gpio_103_smt:1;
        RBus_UInt32  gpio_102_smt:1;
        RBus_UInt32  gpio_101_smt:1;
        RBus_UInt32  gpio_100_smt:1;
        RBus_UInt32  gpio_99_smt:1;
        RBus_UInt32  gpio_98_smt:1;
        RBus_UInt32  gpio_97_smt:1;
        RBus_UInt32  gpio_96_smt:1;
        RBus_UInt32  gpio_95_smt:1;
        RBus_UInt32  gpio_94_smt:1;
        RBus_UInt32  gpio_93_smt:1;
        RBus_UInt32  gpio_92_smt:1;
        RBus_UInt32  gpio_91_smt:1;
        RBus_UInt32  gpio_90_smt:1;
    };
}schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  gpio_130_smt:1;
        RBus_UInt32  gpio_129_smt:1;
        RBus_UInt32  gpio_128_smt:1;
        RBus_UInt32  gpio_127_smt:1;
        RBus_UInt32  gpio_126_smt:1;
        RBus_UInt32  gpio_125_smt:1;
        RBus_UInt32  gpio_124_smt:1;
        RBus_UInt32  gpio_123_smt:1;
        RBus_UInt32  gpio_122_smt:1;
    };
}schmidt_trigger_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testpin_mux:8;
        RBus_UInt32  main_ext_clk_en:8;
        RBus_UInt32  dummy_reg:16;
    };
}main_test_pin_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}pxy_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odalagl0:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  odalagl1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  edalagl0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  edalagl1:6;
        RBus_UInt32  res1:2;
    };
}lvds_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcm_sell0:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  vcm_sell1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ttlo_2xdrvl:2;
        RBus_UInt32  sl:2;
        RBus_UInt32  tst_sell0:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tst_sell1:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pre_sr_sell:2;
        RBus_UInt32  pre_sr_enl:2;
        RBus_UInt32  pre_sl0:4;
        RBus_UInt32  pre_sl1:4;
    };
}lvds_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdol:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  ibtx_sell0:2;
        RBus_UInt32  ibtx_sell1:2;
        RBus_UInt32  ibocktx_sell0:2;
        RBus_UInt32  ibocktx_sell1:2;
        RBus_UInt32  ibecktx_sell0:2;
        RBus_UInt32  ibecktx_sell1:2;
        RBus_UInt32  ibhn_sell0:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  ibhn_sell1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ibhx_sell0:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ibhx_sell1:3;
        RBus_UInt32  res1:1;
    };
}lvds_ibg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_psctrlel0:12;
        RBus_UInt32  pll_psctrlel1:12;
        RBus_UInt32  pll_cmpenl:2;
        RBus_UInt32  pll_calswl:2;
        RBus_UInt32  pll_callchl:2;
        RBus_UInt32  pll_calbpl:2;
    };
}lvds_pll_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_psctrlol0:12;
        RBus_UInt32  pll_psctrlol1:12;
        RBus_UInt32  pll_nl0:2;
        RBus_UInt32  pll_nl1:2;
        RBus_UInt32  pll_csl0:2;
        RBus_UInt32  pll_csl1:2;
    };
}lvds_pll_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_sel_psctrlvbpl0:2;
        RBus_UInt32  pll_sel_psctrlvbpl1:2;
        RBus_UInt32  pll_vcorstbl:2;
        RBus_UInt32  pll_powl:2;
        RBus_UInt32  pll_rsl0:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll_rsl1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_ipl0:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_ipl1:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_opi_enl:2;
        RBus_UInt32  pll_epi_enl:2;
        RBus_UInt32  pll_sel_div2l:2;
        RBus_UInt32  pll_cpl:2;
    };
}lvds_pll_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_vcomdl0:2;
        RBus_UInt32  pll_vcomdl1:2;
        RBus_UInt32  pll_wdsetl:2;
        RBus_UInt32  pll_wdrstl:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  pll_reserve1l:2;
        RBus_UInt32  pll_reserved:8;
    };
}lvds_pll_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_rstbl:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll_vo2l:2;
        RBus_UInt32  pll_vo1l:2;
        RBus_UInt32  pll_call:4;
        RBus_UInt32  res1:20;
    };
}lvds_pll_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}rsds_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ser_sell0:2;
        RBus_UInt32  ser_sell1:2;
        RBus_UInt32  ib_powl:2;
        RBus_UInt32  pdbl:2;
        RBus_UInt32  res1:24;
    };
}lvds_misc_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  resvrl_low_msb:24;
        RBus_UInt32  res1:8;
    };
}lvds_misc_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  resvrl_low_lsb:24;
        RBus_UInt32  res1:8;
    };
}lvds_misc_ctrl_2_RBUS;


#endif







#endif //_RBUS_PINMUX_REG_H_


