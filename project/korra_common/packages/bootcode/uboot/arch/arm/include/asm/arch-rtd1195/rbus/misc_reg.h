/**************************************************************
// Spec Version                  : 0.0.6
// Parser Version                : DVR_Parser_6.3
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/6/18 10:36:41
***************************************************************/


#ifndef _MIS_REG_H_INCLUDED_
#define _MIS_REG_H_INCLUDED_
#ifdef  _MIS_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GSPI_INT:1;
unsigned int     reserved_1:6;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     reserved_2:6;
unsigned int     RTC_DATE_INT:1;
unsigned int     RTC_HOUR_INT:1;
unsigned int     RTC_MIN_INT:1;
unsigned int     RTC_HSEC_INT:1;
unsigned int     reserved_3:1;
unsigned int     TC1_INT:1;
unsigned int     TC0_INT:1;
unsigned int     UR1_TO_INT:1;
unsigned int     reserved_4:2;
unsigned int     WDOG_NMI_INT:1;
unsigned int     reserved_5:1;
unsigned int     write_data:1;
}UMSK_ISR;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GSPI_INT:1;
unsigned int     I2C2_INT:1;
unsigned int     reserved_1:2;
unsigned int     I2C3_INT:1;
unsigned int     reserved_2:1;
unsigned int     LSADC_INT:1;
unsigned int     GPIODA_INT:1;
unsigned int     GPIOA_INT:1;
unsigned int     reserved_3:3;
unsigned int     I2C4_INT:1;
unsigned int     I2C5_INT:1;
unsigned int     reserved_4:1;
unsigned int     RTC_DATE_INT:1;
unsigned int     RTC_HOUR_INT:1;
unsigned int     RTC_MIN_INT:1;
unsigned int     RTC_HSEC_INT:1;
unsigned int     reserved_5:1;
unsigned int     TC1_INT:1;
unsigned int     TC0_INT:1;
unsigned int     UR1_TO_INT:1;
unsigned int     I2C1_INT:1;
unsigned int     UR1_INT:1;
unsigned int     WDOG_NMI_INT:1;
unsigned int     reserved_6:1;
unsigned int     write_data:1;
}ISR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     WDOG_NMI_INT:1;
unsigned int     reserved_1:1;
unsigned int     TC2_INT:1;
unsigned int     write_data:1;
}UMSK_ISR_SWC;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     WDOG_NMI_INT:1;
unsigned int     I2C_2_INT:1;
unsigned int     TC2_INT:1;
unsigned int     write_data:1;
}ISR_SWC;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     I2C_2_SWC_EN:1;
unsigned int     I2C_2_EN:1;
}SETTING_SWC;

typedef struct 
{
unsigned int     GP_INT:31;
unsigned int     reserved_0:1;
}FAST_INT_EN_0;

typedef struct 
{
unsigned int     GSPI_INT:1;
unsigned int     I2C3_INT:1;
unsigned int     GP_INT:29;
unsigned int     reserved_0:1;
}FAST_INT_EN_1;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     gspi_int:1;
unsigned int     i2c3_int:1;
unsigned int     gpioda_int:1;
unsigned int     gpioa_int:1;
unsigned int     write_data:1;
}FAST_ISR;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_enable3:1;
unsigned int     sel1:4;
unsigned int     write_enable2:1;
unsigned int     sel0:4;
unsigned int     write_enable1:1;
unsigned int     enable:1;
}MISC_DBG;

typedef struct 
{
unsigned int     write_enable4:1;
unsigned int     Rvd4:7;
unsigned int     write_enable3:1;
unsigned int     Rvd3:7;
unsigned int     write_enable2:1;
unsigned int     Rvd2:7;
unsigned int     write_enable1:1;
unsigned int     Rvd1:7;
}MISC_DUMMY;

typedef struct 
{
unsigned int     INT30:1;
unsigned int     INT29:1;
unsigned int     INT28:1;
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
unsigned int     write_data:1;
}UMSK_ISR_GP0A;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     INT59:1;
unsigned int     INT58:1;
unsigned int     INT57:1;
unsigned int     INT56:1;
unsigned int     INT55:1;
unsigned int     INT54:1;
unsigned int     INT53:1;
unsigned int     INT52:1;
unsigned int     INT51:1;
unsigned int     INT50:1;
unsigned int     INT49:1;
unsigned int     INT48:1;
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
unsigned int     write_data:1;
}UMSK_ISR_GP1A;

typedef struct 
{
unsigned int     INT30:1;
unsigned int     INT29:1;
unsigned int     INT28:1;
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
unsigned int     write_data:1;
}UMSK_ISR_GP0DA;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     INT59:1;
unsigned int     INT58:1;
unsigned int     INT57:1;
unsigned int     INT56:1;
unsigned int     INT55:1;
unsigned int     INT54:1;
unsigned int     INT53:1;
unsigned int     INT52:1;
unsigned int     INT51:1;
unsigned int     INT50:1;
unsigned int     INT49:1;
unsigned int     INT48:1;
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
unsigned int     write_data:1;
}UMSK_ISR_GP1DA;

typedef struct 
{
unsigned int     write_enable2:1;
unsigned int     Rvd2:15;
unsigned int     write_enable1:1;
unsigned int     Rvd1:15;
}MISC_DUMMY1;

typedef struct 
{
unsigned int     Rvd3:3;
unsigned int     reserved_0:1;
unsigned int     to_len:8;
unsigned int     to_int_en:1;
unsigned int     TOAUAREQ:1;
unsigned int     FLOW_POL:1;
unsigned int     MDIFEN:1;
unsigned int     reserved_1:2;
unsigned int     TXEMPTHR:6;
unsigned int     reserved_2:2;
unsigned int     RXFULTHR:6;
}UR_CTRL;

typedef struct 
{
unsigned int     int_30:1;
unsigned int     int_29:1;
unsigned int     int_28:1;
unsigned int     int_27:1;
unsigned int     int_26:1;
unsigned int     int_25:1;
unsigned int     int_24:1;
unsigned int     int_23:1;
unsigned int     int_22:1;
unsigned int     int_21:1;
unsigned int     int_20:1;
unsigned int     int_19:1;
unsigned int     int_18:1;
unsigned int     int_17:1;
unsigned int     int_16:1;
unsigned int     int_15:1;
unsigned int     int_14:1;
unsigned int     int_13:1;
unsigned int     int_12:1;
unsigned int     int_11:1;
unsigned int     int_10:1;
unsigned int     int_9:1;
unsigned int     int_8:1;
unsigned int     int_7:1;
unsigned int     int_6:1;
unsigned int     int_5:1;
unsigned int     int_4:1;
unsigned int     int_3:1;
unsigned int     int_2:1;
unsigned int     int_1:1;
unsigned int     int_0:1;
unsigned int     write_data:1;
}FAST_ISR_GPIO0_A;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     int_59:1;
unsigned int     int_58:1;
unsigned int     int_57:1;
unsigned int     int_56:1;
unsigned int     int_55:1;
unsigned int     int_54:1;
unsigned int     int_53:1;
unsigned int     int_52:1;
unsigned int     int_51:1;
unsigned int     int_50:1;
unsigned int     int_49:1;
unsigned int     int_48:1;
unsigned int     int_47:1;
unsigned int     int_46:1;
unsigned int     int_45:1;
unsigned int     int_44:1;
unsigned int     int_43:1;
unsigned int     int_42:1;
unsigned int     int_41:1;
unsigned int     int_40:1;
unsigned int     int_39:1;
unsigned int     int_38:1;
unsigned int     int_37:1;
unsigned int     int_36:1;
unsigned int     int_35:1;
unsigned int     int_34:1;
unsigned int     int_33:1;
unsigned int     int_32:1;
unsigned int     int_31:1;
unsigned int     write_data:1;
}FAST_ISR_GPIO1_A;

typedef struct 
{
unsigned int     int_30:1;
unsigned int     int_29:1;
unsigned int     int_28:1;
unsigned int     int_27:1;
unsigned int     int_26:1;
unsigned int     int_25:1;
unsigned int     int_24:1;
unsigned int     int_23:1;
unsigned int     int_22:1;
unsigned int     int_21:1;
unsigned int     int_20:1;
unsigned int     int_19:1;
unsigned int     int_18:1;
unsigned int     int_17:1;
unsigned int     int_16:1;
unsigned int     int_15:1;
unsigned int     int_14:1;
unsigned int     int_13:1;
unsigned int     int_12:1;
unsigned int     int_11:1;
unsigned int     int_10:1;
unsigned int     int_9:1;
unsigned int     int_8:1;
unsigned int     int_7:1;
unsigned int     int_6:1;
unsigned int     int_5:1;
unsigned int     int_4:1;
unsigned int     int_3:1;
unsigned int     int_2:1;
unsigned int     int_1:1;
unsigned int     int_0:1;
unsigned int     write_data:1;
}FAST_ISR_GPIO0_DA;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     int_59:1;
unsigned int     int_58:1;
unsigned int     int_57:1;
unsigned int     int_56:1;
unsigned int     int_55:1;
unsigned int     int_54:1;
unsigned int     int_53:1;
unsigned int     int_52:1;
unsigned int     int_51:1;
unsigned int     int_50:1;
unsigned int     int_49:1;
unsigned int     int_48:1;
unsigned int     int_47:1;
unsigned int     int_46:1;
unsigned int     int_45:1;
unsigned int     int_44:1;
unsigned int     int_43:1;
unsigned int     int_42:1;
unsigned int     int_41:1;
unsigned int     int_40:1;
unsigned int     int_39:1;
unsigned int     int_38:1;
unsigned int     int_37:1;
unsigned int     int_36:1;
unsigned int     int_35:1;
unsigned int     int_34:1;
unsigned int     int_33:1;
unsigned int     int_32:1;
unsigned int     int_31:1;
unsigned int     write_data:1;
}FAST_ISR_GPIO1_DA;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     I2C3:1;
unsigned int     GSPI:1;
unsigned int     I2C2:1;
unsigned int     reserved_1:4;
unsigned int     LSADC:1;
unsigned int     GPIODA:1;
unsigned int     GPIOA:1;
unsigned int     reserved_2:3;
unsigned int     I2C4:1;
unsigned int     I2C5:1;
unsigned int     reserved_3:1;
unsigned int     RTC_DATE:1;
unsigned int     RTC_HOUR:1;
unsigned int     RTC_MIN:1;
unsigned int     reserved_4:4;
unsigned int     UR1_TO:1;
unsigned int     I2C1:1;
unsigned int     UR1:1;
unsigned int     reserved_5:3;
}MISC_SCPU_INT_EN;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C1_SDA_DEL;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C2_SDA_DEL;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C3_SDA_DEL;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C4_SDA_DEL;

typedef struct 
{
unsigned int     dmy1:20;
unsigned int     reserved_0:3;
unsigned int     en:1;
unsigned int     reserved_1:3;
unsigned int     sel:5;
}I2C5_SDA_DEL;

typedef struct 
{
unsigned int     GPDIR:32;
}GP0DIR;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GPDIR:28;
}GP1DIR;

typedef struct 
{
unsigned int     GPDATO:32;
}GP0DATO;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GPDATO:28;
}GP1DATO;

typedef struct 
{
unsigned int     GPDATI:32;
}GP0DATI;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GPDATI:28;
}GP1DATI;

typedef struct 
{
unsigned int     GP:32;
}GP0IE;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GP:28;
}GP1IE;

typedef struct 
{
unsigned int     GPHA:32;
}GP0DP;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     GPHA:28;
}GP1DP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     write_enable4:1;
unsigned int     CLK4:3;
unsigned int     write_enable3:1;
unsigned int     CLK3:3;
unsigned int     write_enable2:1;
unsigned int     CLK2:3;
unsigned int     write_enable1:1;
unsigned int     CLK1:3;
}MISC_GPDEB;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DLL:8;
}U1RBR_THR_DLL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DLH:8;
}U1IER_DLH;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FIFO16:2;
unsigned int     reserved_1:2;
unsigned int     IID:4;
}U1IIR_FCR;

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
}U1LCR;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     AFCE:1;
unsigned int     LOOP:1;
unsigned int     reserved_1:2;
unsigned int     RTS:1;
unsigned int     DTR:1;
}U1MCR;

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
}U1LSR;

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
}U1MSR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SCR:8;
}U1SCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RBD:8;
}U1SRBR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     FAR:1;
}U1FAR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     FAR:8;
}U1TFR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     RFFE:1;
unsigned int     RFPF:1;
unsigned int     RFWD:8;
}U1RFW;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     RFF:1;
unsigned int     RFNE:1;
unsigned int     TFE:1;
unsigned int     TFNF:1;
unsigned int     BUSY:1;
}U1USR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TFL:8;
}U1TFL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RFL:8;
}U1RFL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     XFR:1;
unsigned int     RFR:1;
unsigned int     UR:1;
}U1SRR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SBCR:1;
}U1SBCR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SDMAM:1;
}U1SDMAM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SFE:1;
}U1SFE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     SRT:2;
}U1SRT;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     STET:2;
}U1STET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     HTX:1;
}U1HTX;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DMASA:1;
}U1DMASA;

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
}U1CPR;

typedef struct 
{
unsigned int     UCV:32;
}U1UCV;

typedef struct 
{
unsigned int     CTR:32;
}U1CTR;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC1_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC1_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC1_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC1_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC1_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC1_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC1_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC1_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC1_FS_SCL_LCNT;

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
}IC1_INTR_STAT;

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
}IC1_INTR_MASK;

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
}IC1_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC1_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC1_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC1_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC1_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC1_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC1_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC1_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC1_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC1_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC1_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC1_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC1_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC1_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC1_ENABLE;

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
}IC1_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC1_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC1_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     SDA_HOLD:16;
}IC1_SDA_HOLD;

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
}IC1_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC1_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC1_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC1_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC1_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC1_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC1_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC1_ENABLE_STATUS;

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
}IC1_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC1_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC1_COMP_TYPE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC2_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC2_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC2_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC2_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC2_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC2_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC2_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC2_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC2_FS_SCL_LCNT;

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
}IC2_INTR_STAT;

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
}IC2_INTR_MASK;

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
}IC2_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC2_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC2_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC2_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC2_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC2_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC2_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC2_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC2_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC2_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC2_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC2_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC2_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC2_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC2_ENABLE;

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
}IC2_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC2_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC2_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     SDA_HOLD:16;
}IC2_SDA_HOLD;

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
}IC2_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC2_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC2_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC2_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC2_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC2_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC2_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC2_ENABLE_STATUS;

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
}IC2_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC2_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC2_COMP_TYPE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC3_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC3_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC3_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC3_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC3_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC3_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC3_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC3_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC3_FS_SCL_LCNT;

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
}IC3_INTR_STAT;

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
}IC3_INTR_MASK;

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
}IC3_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC3_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC3_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC3_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC3_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC3_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC3_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC3_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC3_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC3_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC3_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC3_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC3_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC3_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC3_ENABLE;

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
}IC3_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC3_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC3_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     SDA_HOLD:16;
}IC3_SDA_HOLD;

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
}IC3_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC3_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC3_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC3_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC3_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC3_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC3_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC3_ENABLE_STATUS;

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
}IC3_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC3_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC3_COMP_TYPE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC4_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC4_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC4_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC4_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC4_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC4_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC4_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC4_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC4_FS_SCL_LCNT;

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
}IC4_INTR_STAT;

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
}IC4_INTR_MASK;

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
}IC4_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC4_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC4_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC4_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC4_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC4_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC4_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC4_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC4_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC4_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC4_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC4_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC4_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC4_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC4_ENABLE;

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
}IC4_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC4_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC4_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     SDA_HOLD:16;
}IC4_SDA_HOLD;

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
}IC4_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC4_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC4_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC4_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC4_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC4_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC4_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC4_ENABLE_STATUS;

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
}IC4_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC4_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC4_COMP_TYPE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     IC_SLAVE_DISABLE:1;
unsigned int     IC_RESTART_EN:1;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     IC_10BITADDR_SLAVE:1;
unsigned int     SPEED:2;
unsigned int     MASTER_MODE:1;
}IC5_CON;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     IC_10BITADDR_MASTER:1;
unsigned int     SPECIAL:1;
unsigned int     GC_OR_START:1;
unsigned int     IC_TAR:10;
}IC5_TAR;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     IC_SAR:10;
}IC5_SAR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     IC_HS_MAR:3;
}IC5_HS_MADDR;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     RESTART:1;
unsigned int     STOP:1;
unsigned int     CMD:1;
unsigned int     DAT:8;
}IC5_DATA_CMD;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_HCNT:16;
}IC5_SS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_SS_SCL_LCNT:16;
}IC5_SS_SCL_LCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_HCNT:16;
}IC5_FS_SCL_HCNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     IC_FS_SCL_LCNT:16;
}IC5_FS_SCL_LCNT;

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
}IC5_INTR_STAT;

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
}IC5_INTR_MASK;

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
}IC5_RAW_INTR_STAT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     RX_TL:8;
}IC5_RX_TL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     TX_TL:8;
}IC5_TX_TL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_INTR:1;
}IC5_CLR_INTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_UNDER:1;
}IC5_CLR_RX_UNDER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_OVER:1;
}IC5_CLR_RX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_OVER:1;
}IC5_CLR_TX_OVER;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RD_REQ:1;
}IC5_CLR_RD_REQ;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_TX_ABRT:1;
}IC5_CLR_TX_ABRT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_RX_DONE:1;
}IC5_CLR_RX_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_ACTIVITY:1;
}IC5_CLR_ACTIVITY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_STOP_DET:1;
}IC5_CLR_STOP_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_START_DET:1;
}IC5_CLR_START_DET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     CLR_GEN_CALL:1;
}IC5_CLR_GEN_CALL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ENABLE:1;
}IC5_ENABLE;

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
}IC5_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     TXFLR:4;
}IC5_TXFLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     RXFLR:4;
}IC5_RXFLR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     SDA_HOLD:16;
}IC5_SDA_HOLD;

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
}IC5_TX_ABRT_SOURCE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     NACK:1;
}IC5_SLV_DATA_NACK_ONLY;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     TDMAE:1;
unsigned int     RDMAE:1;
}IC5_DMA_CR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DMATDL:3;
}IC5_DMA_TDLR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DMARDL:4;
}IC5_DMA_RDLR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SDA_SETUP:8;
}IC5_SDA_SETUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ACK_GEN_CALL:1;
}IC5_ACK_GENERAL_CALL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     SLV_RX_DATA_LOST:1;
unsigned int     SLV_DISABLED_WHI:1;
unsigned int     IC_EN:1;
}IC5_ENABLE_STATUS;

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
}IC5_COMP_PARAM_1;

typedef struct 
{
unsigned int     IC_COMP_VERSION:32;
}IC5_COMP_VERSION;

typedef struct 
{
unsigned int     IC_COMP_TYPE:32;
}IC5_COMP_TYPE;

typedef struct 
{
unsigned int     TC0TVR:32;
}TC0TVR;

typedef struct 
{
unsigned int     TC1TVR:32;
}TC1TVR;

typedef struct 
{
unsigned int     TC2TVR:32;
}TC2TVR;

typedef struct 
{
unsigned int     TC0CVR:32;
}TC0CVR;

typedef struct 
{
unsigned int     TC1CVR:32;
}TC1CVR;

typedef struct 
{
unsigned int     TC2VR:32;
}TC2CVR;

typedef struct 
{
unsigned int     TC0En:1;
unsigned int     TC0Mode:1;
unsigned int     TC0Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}TC0CR;

typedef struct 
{
unsigned int     TC1En:1;
unsigned int     TC1Mode:1;
unsigned int     TC1Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}TC1CR;

typedef struct 
{
unsigned int     TC2En:1;
unsigned int     TC2Mode:1;
unsigned int     TC2Pause:1;
unsigned int     RvdA:5;
unsigned int     reserved_0:24;
}TC2CR;

typedef struct 
{
unsigned int     TC0IE:1;
unsigned int     reserved_0:31;
}TC0ICR;

typedef struct 
{
unsigned int     TC1IE:1;
unsigned int     reserved_0:31;
}TC1ICR;

typedef struct 
{
unsigned int     TC2IE:1;
unsigned int     reserved_0:31;
}TC2ICR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     EN:1;
}CLK90K_CTRL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     CNT:9;
}SCPU_CLK27M_90K;

typedef struct 
{
unsigned int     VAL:32;
}SCPU_CLK90K_LO;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     VAL:16;
}SCPU_CLK90K_HI;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     CNT:9;
}ACPU_CLK27M_90K;

typedef struct 
{
unsigned int     VAL:32;
}ACPU_CLK90K_LO;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     VAL:16;
}ACPU_CLK90K_HI;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     EN:1;
}PCR_CLK90K_CTRL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     CNT:9;
}PCR_SCPU_CLK27M_90K;

typedef struct 
{
unsigned int     VAL:32;
}PCR_SCPU_CLK90K_LO;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     VAL:16;
}PCR_SCPU_CLK90K_HI;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     CNT:9;
}PCR_ACPU_CLK27M_90K;

typedef struct 
{
unsigned int     VAL:32;
}PCR_ACPU_CLK90K_LO;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     VAL:16;
}PCR_ACPU_CLK90K_HI;

typedef struct 
{
unsigned int     WD_INT_EN:1;
unsigned int     reserved_0:15;
unsigned int     NMIC:4;
unsigned int     WDC:4;
unsigned int     WDEN:8;
}TCWCR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     WDCLR:1;
}TCWTR;

typedef struct 
{
unsigned int     SEL:32;
}TCWNMI;

typedef struct 
{
unsigned int     SEL:32;
}TCWOV;

typedef struct 
{
unsigned int     WD_INT_EN:1;
unsigned int     reserved_0:15;
unsigned int     NMIC:4;
unsigned int     WDC:4;
unsigned int     WDEN:8;
}TCWCR_SWC;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     WDCLR:1;
}TCWTR_SWC;

typedef struct 
{
unsigned int     SEL:32;
}TCWNMI_SWC;

typedef struct 
{
unsigned int     SEL:32;
}TCWOV_SWC;

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
unsigned int     reserved_0:29;
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
unsigned int     reserved_0:25;
unsigned int     RTCRST:1;
unsigned int     reserved_1:2;
unsigned int     DAINTE:1;
unsigned int     HUINTE:1;
unsigned int     MUINTE:1;
unsigned int     HSUINTE:1;
}RTCCR;

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
unsigned int     reserved_1:10;
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
unsigned int     Power_saving_enable:1;
unsigned int     Power_saving_cycle_time:3;
unsigned int     Power_saving_disable_time:3;
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
}LSADC_PAD0_LEVEL_SET0;

typedef struct 
{
unsigned int     Level_1_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block1_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en1:1;
unsigned int     INT_pending_bit1:1;
}LSADC_PAD0_LEVEL_SET1;

typedef struct 
{
unsigned int     Level_2_top_bound:8;
unsigned int     Level_2_low_bound:8;
unsigned int     Block2_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en2:1;
unsigned int     INT_pending_bit2:1;
}LSADC_PAD0_LEVEL_SET2;

typedef struct 
{
unsigned int     Level_3_top_bound:8;
unsigned int     Level_3_low_bound:8;
unsigned int     Block3_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en3:1;
unsigned int     INT_pending_bit3:1;
}LSADC_PAD0_LEVEL_SET3;

typedef struct 
{
unsigned int     Level_4_top_bound:8;
unsigned int     Level_4_low_bound:8;
unsigned int     Block4_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en4:1;
unsigned int     INT_pending_bit4:1;
}LSADC_PAD0_LEVEL_SET4;

typedef struct 
{
unsigned int     Level_5_top_bound:8;
unsigned int     Level_5_low_bound:8;
unsigned int     Block5_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en5:1;
unsigned int     INT_pending_bit5:1;
}LSADC_PAD0_LEVEL_SET5;

typedef struct 
{
unsigned int     Level_0_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block0_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en0:1;
unsigned int     INT_pending_bit0:1;
}LSADC_PAD1_LEVEL_SET0;

typedef struct 
{
unsigned int     Level_1_top_bound:8;
unsigned int     Level_0_low_bound:8;
unsigned int     Block1_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en1:1;
unsigned int     INT_pending_bit1:1;
}LSADC_PAD1_LEVEL_SET1;

typedef struct 
{
unsigned int     Level_2_top_bound:8;
unsigned int     Level_2_low_bound:8;
unsigned int     Block2_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en2:1;
unsigned int     INT_pending_bit2:1;
}LSADC_PAD1_LEVEL_SET2;

typedef struct 
{
unsigned int     Level_3_top_bound:8;
unsigned int     Level_3_low_bound:8;
unsigned int     Block3_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en3:1;
unsigned int     INT_pending_bit3:1;
}LSADC_PAD1_LEVEL_SET3;

typedef struct 
{
unsigned int     Level_4_top_bound:8;
unsigned int     Level_4_low_bound:8;
unsigned int     Block4_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en4:1;
unsigned int     INT_pending_bit4:1;
}LSADC_PAD1_LEVEL_SET4;

typedef struct 
{
unsigned int     Level_5_top_bound:8;
unsigned int     Level_5_low_bound:8;
unsigned int     Block5_en:1;
unsigned int     reserved_0:13;
unsigned int     INT_en5:1;
unsigned int     INT_pending_bit5:1;
}LSADC_PAD1_LEVEL_SET5;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:2;
unsigned int     ADC_value0latch:6;
unsigned int     reserved_2:7;
unsigned int     INT_latchstatus:1;
}LSADC_INT_PAD0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:2;
unsigned int     ADC_value1latch:6;
unsigned int     reserved_2:7;
unsigned int     INT_latchstatus:1;
}LSADC_INT_PAD1;

#endif

#define MISC_UMSK_ISR                                                                     0x1801B008
#define MISC_UMSK_ISR_reg_addr                                                            "0xB801B008"
#define MISC_UMSK_ISR_reg                                                                 0xB801B008
#define MISC_set_UMSK_ISR_reg(data)   (*((volatile unsigned int*) UMSK_ISR_reg)=data)
#define MISC_get_UMSK_ISR_reg   (*((volatile unsigned int*) UMSK_ISR_reg))
#define MISC_UMSK_ISR_inst_adr                                                            "0x0002"
#define MISC_UMSK_ISR_inst                                                                0x0002
#define UMSK_ISR_GSPI_INT_shift                                                      (27)
#define UMSK_ISR_GSPI_INT_mask                                                       (0x08000000)
#define UMSK_ISR_GSPI_INT(data)                                                      (0x08000000&((data)<<27))
#define UMSK_ISR_GSPI_INT_src(data)                                                  ((0x08000000&(data))>>27)
#define UMSK_ISR_get_GSPI_INT(data)                                                  ((0x08000000&(data))>>27)
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
#define UMSK_ISR_RTC_DATE_INT_shift                                                  (12)
#define UMSK_ISR_RTC_DATE_INT_mask                                                   (0x00001000)
#define UMSK_ISR_RTC_DATE_INT(data)                                                  (0x00001000&((data)<<12))
#define UMSK_ISR_RTC_DATE_INT_src(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_get_RTC_DATE_INT(data)                                              ((0x00001000&(data))>>12)
#define UMSK_ISR_RTC_HOUR_INT_shift                                                  (11)
#define UMSK_ISR_RTC_HOUR_INT_mask                                                   (0x00000800)
#define UMSK_ISR_RTC_HOUR_INT(data)                                                  (0x00000800&((data)<<11))
#define UMSK_ISR_RTC_HOUR_INT_src(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_get_RTC_HOUR_INT(data)                                              ((0x00000800&(data))>>11)
#define UMSK_ISR_RTC_MIN_INT_shift                                                   (10)
#define UMSK_ISR_RTC_MIN_INT_mask                                                    (0x00000400)
#define UMSK_ISR_RTC_MIN_INT(data)                                                   (0x00000400&((data)<<10))
#define UMSK_ISR_RTC_MIN_INT_src(data)                                               ((0x00000400&(data))>>10)
#define UMSK_ISR_get_RTC_MIN_INT(data)                                               ((0x00000400&(data))>>10)
#define MISC_UMSK_ISR_RTC_HSEC_INT_shift                                                  (9)
#define MISC_UMSK_ISR_RTC_HSEC_INT_mask                                                   (0x00000200)
#define MISC_UMSK_ISR_RTC_HSEC_INT(data)                                                  (0x00000200&((data)<<9))
#define MISC_UMSK_ISR_RTC_HSEC_INT_src(data)                                              ((0x00000200&(data))>>9)
#define MISC_UMSK_ISR_get_RTC_HSEC_INT(data)                                              ((0x00000200&(data))>>9)
#define UMSK_ISR_TC1_INT_shift                                                       (7)
#define UMSK_ISR_TC1_INT_mask                                                        (0x00000080)
#define UMSK_ISR_TC1_INT(data)                                                       (0x00000080&((data)<<7))
#define UMSK_ISR_TC1_INT_src(data)                                                   ((0x00000080&(data))>>7)
#define UMSK_ISR_get_TC1_INT(data)                                                   ((0x00000080&(data))>>7)
#define UMSK_ISR_TC0_INT_shift                                                       (6)
#define UMSK_ISR_TC0_INT_mask                                                        (0x00000040)
#define UMSK_ISR_TC0_INT(data)                                                       (0x00000040&((data)<<6))
#define UMSK_ISR_TC0_INT_src(data)                                                   ((0x00000040&(data))>>6)
#define UMSK_ISR_get_TC0_INT(data)                                                   ((0x00000040&(data))>>6)
#define UMSK_ISR_UR1_TO_INT_shift                                                    (5)
#define UMSK_ISR_UR1_TO_INT_mask                                                     (0x00000020)
#define UMSK_ISR_UR1_TO_INT(data)                                                    (0x00000020&((data)<<5))
#define UMSK_ISR_UR1_TO_INT_src(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_get_UR1_TO_INT(data)                                                ((0x00000020&(data))>>5)
#define MISC_UMSK_ISR_WDOG_NMI_INT_shift                                                  (2)
#define MISC_UMSK_ISR_WDOG_NMI_INT_mask                                                   (0x00000004)
#define MISC_UMSK_ISR_WDOG_NMI_INT(data)                                                  (0x00000004&((data)<<2))
#define MISC_UMSK_ISR_WDOG_NMI_INT_src(data)                                              ((0x00000004&(data))>>2)
#define MISC_UMSK_ISR_get_WDOG_NMI_INT(data)                                              ((0x00000004&(data))>>2)
#define UMSK_ISR_write_data_shift                                                    (0)
#define UMSK_ISR_write_data_mask                                                     (0x00000001)
#define UMSK_ISR_write_data(data)                                                    (0x00000001&((data)<<0))
#define UMSK_ISR_write_data_src(data)                                                ((0x00000001&(data))>>0)
#define UMSK_ISR_get_write_data(data)                                                ((0x00000001&(data))>>0)


#define MISC_ISR                                                                          0x1801B00C
#define MISC_ISR_reg_addr                                                                 "0xB801B00C"
#define MISC_ISR_reg                                                                      0xB801B00C
#define MISC_set_ISR_reg(data)   (*((volatile unsigned int*) ISR_reg)=data)
#define MISC_get_ISR_reg   (*((volatile unsigned int*) ISR_reg))
#define MISC_ISR_inst_adr                                                                 "0x0003"
#define MISC_ISR_inst                                                                     0x0003
#define ISR_GSPI_INT_shift                                                           (27)
#define ISR_GSPI_INT_mask                                                            (0x08000000)
#define ISR_GSPI_INT(data)                                                           (0x08000000&((data)<<27))
#define ISR_GSPI_INT_src(data)                                                       ((0x08000000&(data))>>27)
#define ISR_get_GSPI_INT(data)                                                       ((0x08000000&(data))>>27)
#define ISR_I2C2_INT_shift                                                           (26)
#define ISR_I2C2_INT_mask                                                            (0x04000000)
#define ISR_I2C2_INT(data)                                                           (0x04000000&((data)<<26))
#define ISR_I2C2_INT_src(data)                                                       ((0x04000000&(data))>>26)
#define ISR_get_I2C2_INT(data)                                                       ((0x04000000&(data))>>26)
#define ISR_I2C3_INT_shift                                                           (23)
#define ISR_I2C3_INT_mask                                                            (0x00800000)
#define ISR_I2C3_INT(data)                                                           (0x00800000&((data)<<23))
#define ISR_I2C3_INT_src(data)                                                       ((0x00800000&(data))>>23)
#define ISR_get_I2C3_INT(data)                                                       ((0x00800000&(data))>>23)
#define ISR_LSADC_INT_shift                                                          (21)
#define ISR_LSADC_INT_mask                                                           (0x00200000)
#define ISR_LSADC_INT(data)                                                          (0x00200000&((data)<<21))
#define ISR_LSADC_INT_src(data)                                                      ((0x00200000&(data))>>21)
#define ISR_get_LSADC_INT(data)                                                      ((0x00200000&(data))>>21)
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
#define ISR_I2C4_INT_shift                                                           (15)
#define ISR_I2C4_INT_mask                                                            (0x00008000)
#define ISR_I2C4_INT(data)                                                           (0x00008000&((data)<<15))
#define ISR_I2C4_INT_src(data)                                                       ((0x00008000&(data))>>15)
#define ISR_get_I2C4_INT(data)                                                       ((0x00008000&(data))>>15)
#define ISR_I2C5_INT_shift                                                           (14)
#define ISR_I2C5_INT_mask                                                            (0x00004000)
#define ISR_I2C5_INT(data)                                                           (0x00004000&((data)<<14))
#define ISR_I2C5_INT_src(data)                                                       ((0x00004000&(data))>>14)
#define ISR_get_I2C5_INT(data)                                                       ((0x00004000&(data))>>14)
#define ISR_RTC_DATE_INT_shift                                                       (12)
#define ISR_RTC_DATE_INT_mask                                                        (0x00001000)
#define ISR_RTC_DATE_INT(data)                                                       (0x00001000&((data)<<12))
#define ISR_RTC_DATE_INT_src(data)                                                   ((0x00001000&(data))>>12)
#define ISR_get_RTC_DATE_INT(data)                                                   ((0x00001000&(data))>>12)
#define ISR_RTC_HOUR_INT_shift                                                       (11)
#define ISR_RTC_HOUR_INT_mask                                                        (0x00000800)
#define ISR_RTC_HOUR_INT(data)                                                       (0x00000800&((data)<<11))
#define ISR_RTC_HOUR_INT_src(data)                                                   ((0x00000800&(data))>>11)
#define ISR_get_RTC_HOUR_INT(data)                                                   ((0x00000800&(data))>>11)
#define ISR_RTC_MIN_INT_shift                                                        (10)
#define ISR_RTC_MIN_INT_mask                                                         (0x00000400)
#define ISR_RTC_MIN_INT(data)                                                        (0x00000400&((data)<<10))
#define ISR_RTC_MIN_INT_src(data)                                                    ((0x00000400&(data))>>10)
#define ISR_get_RTC_MIN_INT(data)                                                    ((0x00000400&(data))>>10)
#define MISC_ISR_RTC_HSEC_INT_shift                                                       (9)
#define MISC_ISR_RTC_HSEC_INT_mask                                                        (0x00000200)
#define MISC_ISR_RTC_HSEC_INT(data)                                                       (0x00000200&((data)<<9))
#define MISC_ISR_RTC_HSEC_INT_src(data)                                                   ((0x00000200&(data))>>9)
#define ISR_get_RTC_HSEC_INT(data)                                                   ((0x00000200&(data))>>9)
#define ISR_TC1_INT_shift                                                            (7)
#define ISR_TC1_INT_mask                                                             (0x00000080)
#define ISR_TC1_INT(data)                                                            (0x00000080&((data)<<7))
#define ISR_TC1_INT_src(data)                                                        ((0x00000080&(data))>>7)
#define ISR_get_TC1_INT(data)                                                        ((0x00000080&(data))>>7)
#define ISR_TC0_INT_shift                                                            (6)
#define ISR_TC0_INT_mask                                                             (0x00000040)
#define ISR_TC0_INT(data)                                                            (0x00000040&((data)<<6))
#define ISR_TC0_INT_src(data)                                                        ((0x00000040&(data))>>6)
#define ISR_get_TC0_INT(data)                                                        ((0x00000040&(data))>>6)
#define ISR_UR1_TO_INT_shift                                                         (5)
#define ISR_UR1_TO_INT_mask                                                          (0x00000020)
#define ISR_UR1_TO_INT(data)                                                         (0x00000020&((data)<<5))
#define ISR_UR1_TO_INT_src(data)                                                     ((0x00000020&(data))>>5)
#define ISR_get_UR1_TO_INT(data)                                                     ((0x00000020&(data))>>5)
#define ISR_I2C1_INT_shift                                                           (4)
#define ISR_I2C1_INT_mask                                                            (0x00000010)
#define ISR_I2C1_INT(data)                                                           (0x00000010&((data)<<4))
#define ISR_I2C1_INT_src(data)                                                       ((0x00000010&(data))>>4)
#define ISR_get_I2C1_INT(data)                                                       ((0x00000010&(data))>>4)
#define ISR_UR1_INT_shift                                                            (3)
#define ISR_UR1_INT_mask                                                             (0x00000008)
#define ISR_UR1_INT(data)                                                            (0x00000008&((data)<<3))
#define ISR_UR1_INT_src(data)                                                        ((0x00000008&(data))>>3)
#define ISR_get_UR1_INT(data)                                                        ((0x00000008&(data))>>3)
#define MISC_ISR_WDOG_NMI_INT_shift                                                       (2)
#define MISC_ISR_WDOG_NMI_INT_mask                                                        (0x00000004)
#define MISC_ISR_WDOG_NMI_INT(data)                                                       (0x00000004&((data)<<2))
#define MISC_ISR_WDOG_NMI_INT_src(data)                                                   ((0x00000004&(data))>>2)
#define MISC_ISR_get_WDOG_NMI_INT(data)                                                   ((0x00000004&(data))>>2)
#define ISR_write_data_shift                                                         (0)
#define ISR_write_data_mask                                                          (0x00000001)
#define ISR_write_data(data)                                                         (0x00000001&((data)<<0))
#define ISR_write_data_src(data)                                                     ((0x00000001&(data))>>0)
#define ISR_get_write_data(data)                                                     ((0x00000001&(data))>>0)


#define UMSK_ISR_SWC                                                                 0x1801B010
#define UMSK_ISR_SWC_reg_addr                                                        "0xB801B010"
#define UMSK_ISR_SWC_reg                                                             0xB801B010
#define set_UMSK_ISR_SWC_reg(data)   (*((volatile unsigned int*) UMSK_ISR_SWC_reg)=data)
#define get_UMSK_ISR_SWC_reg   (*((volatile unsigned int*) UMSK_ISR_SWC_reg))
#define UMSK_ISR_SWC_inst_adr                                                        "0x0004"
#define UMSK_ISR_SWC_inst                                                            0x0004
#define UMSK_ISR_SWC_WDOG_NMI_INT_shift                                              (3)
#define UMSK_ISR_SWC_WDOG_NMI_INT_mask                                               (0x00000008)
#define UMSK_ISR_SWC_WDOG_NMI_INT(data)                                              (0x00000008&((data)<<3))
#define UMSK_ISR_SWC_WDOG_NMI_INT_src(data)                                          ((0x00000008&(data))>>3)
#define UMSK_ISR_SWC_get_WDOG_NMI_INT(data)                                          ((0x00000008&(data))>>3)
#define UMSK_ISR_SWC_TC2_INT_shift                                                   (1)
#define UMSK_ISR_SWC_TC2_INT_mask                                                    (0x00000002)
#define UMSK_ISR_SWC_TC2_INT(data)                                                   (0x00000002&((data)<<1))
#define UMSK_ISR_SWC_TC2_INT_src(data)                                               ((0x00000002&(data))>>1)
#define UMSK_ISR_SWC_get_TC2_INT(data)                                               ((0x00000002&(data))>>1)
#define UMSK_ISR_SWC_write_data_shift                                                (0)
#define UMSK_ISR_SWC_write_data_mask                                                 (0x00000001)
#define UMSK_ISR_SWC_write_data(data)                                                (0x00000001&((data)<<0))
#define UMSK_ISR_SWC_write_data_src(data)                                            ((0x00000001&(data))>>0)
#define UMSK_ISR_SWC_get_write_data(data)                                            ((0x00000001&(data))>>0)


#define ISR_SWC                                                                      0x1801B014
#define ISR_SWC_reg_addr                                                             "0xB801B014"
#define ISR_SWC_reg                                                                  0xB801B014
#define set_ISR_SWC_reg(data)   (*((volatile unsigned int*) ISR_SWC_reg)=data)
#define get_ISR_SWC_reg   (*((volatile unsigned int*) ISR_SWC_reg))
#define ISR_SWC_inst_adr                                                             "0x0005"
#define ISR_SWC_inst                                                                 0x0005
#define ISR_SWC_WDOG_NMI_INT_shift                                                   (3)
#define ISR_SWC_WDOG_NMI_INT_mask                                                    (0x00000008)
#define ISR_SWC_WDOG_NMI_INT(data)                                                   (0x00000008&((data)<<3))
#define ISR_SWC_WDOG_NMI_INT_src(data)                                               ((0x00000008&(data))>>3)
#define ISR_SWC_get_WDOG_NMI_INT(data)                                               ((0x00000008&(data))>>3)
#define ISR_SWC_I2C_2_INT_shift                                                      (2)
#define ISR_SWC_I2C_2_INT_mask                                                       (0x00000004)
#define ISR_SWC_I2C_2_INT(data)                                                      (0x00000004&((data)<<2))
#define ISR_SWC_I2C_2_INT_src(data)                                                  ((0x00000004&(data))>>2)
#define ISR_SWC_get_I2C_2_INT(data)                                                  ((0x00000004&(data))>>2)
#define ISR_SWC_TC2_INT_shift                                                        (1)
#define ISR_SWC_TC2_INT_mask                                                         (0x00000002)
#define ISR_SWC_TC2_INT(data)                                                        (0x00000002&((data)<<1))
#define ISR_SWC_TC2_INT_src(data)                                                    ((0x00000002&(data))>>1)
#define ISR_SWC_get_TC2_INT(data)                                                    ((0x00000002&(data))>>1)
#define ISR_SWC_write_data_shift                                                     (0)
#define ISR_SWC_write_data_mask                                                      (0x00000001)
#define ISR_SWC_write_data(data)                                                     (0x00000001&((data)<<0))
#define ISR_SWC_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define ISR_SWC_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define SETTING_SWC                                                                  0x1801B018
#define SETTING_SWC_reg_addr                                                         "0xB801B018"
#define SETTING_SWC_reg                                                              0xB801B018
#define set_SETTING_SWC_reg(data)   (*((volatile unsigned int*) SETTING_SWC_reg)=data)
#define get_SETTING_SWC_reg   (*((volatile unsigned int*) SETTING_SWC_reg))
#define SETTING_SWC_inst_adr                                                         "0x0006"
#define SETTING_SWC_inst                                                             0x0006
#define SETTING_SWC_I2C_2_SWC_EN_shift                                               (1)
#define SETTING_SWC_I2C_2_SWC_EN_mask                                                (0x00000002)
#define SETTING_SWC_I2C_2_SWC_EN(data)                                               (0x00000002&((data)<<1))
#define SETTING_SWC_I2C_2_SWC_EN_src(data)                                           ((0x00000002&(data))>>1)
#define SETTING_SWC_get_I2C_2_SWC_EN(data)                                           ((0x00000002&(data))>>1)
#define SETTING_SWC_I2C_2_EN_shift                                                   (0)
#define SETTING_SWC_I2C_2_EN_mask                                                    (0x00000001)
#define SETTING_SWC_I2C_2_EN(data)                                                   (0x00000001&((data)<<0))
#define SETTING_SWC_I2C_2_EN_src(data)                                               ((0x00000001&(data))>>0)
#define SETTING_SWC_get_I2C_2_EN(data)                                               ((0x00000001&(data))>>0)


#define FAST_INT_EN_0                                                                0x1801B01C
#define FAST_INT_EN_0_reg_addr                                                       "0xB801B01C"
#define FAST_INT_EN_0_reg                                                            0xB801B01C
#define set_FAST_INT_EN_0_reg(data)   (*((volatile unsigned int*) FAST_INT_EN_0_reg)=data)
#define get_FAST_INT_EN_0_reg   (*((volatile unsigned int*) FAST_INT_EN_0_reg))
#define FAST_INT_EN_0_inst_adr                                                       "0x0007"
#define FAST_INT_EN_0_inst                                                           0x0007
#define FAST_INT_EN_0_GP_INT_shift                                                   (1)
#define FAST_INT_EN_0_GP_INT_mask                                                    (0xFFFFFFFE)
#define FAST_INT_EN_0_GP_INT(data)                                                   (0xFFFFFFFE&((data)<<1))
#define FAST_INT_EN_0_GP_INT_src(data)                                               ((0xFFFFFFFE&(data))>>1)
#define FAST_INT_EN_0_get_GP_INT(data)                                               ((0xFFFFFFFE&(data))>>1)


#define FAST_INT_EN_1                                                                0x1801B020
#define FAST_INT_EN_1_reg_addr                                                       "0xB801B020"
#define FAST_INT_EN_1_reg                                                            0xB801B020
#define set_FAST_INT_EN_1_reg(data)   (*((volatile unsigned int*) FAST_INT_EN_1_reg)=data)
#define get_FAST_INT_EN_1_reg   (*((volatile unsigned int*) FAST_INT_EN_1_reg))
#define FAST_INT_EN_1_inst_adr                                                       "0x0008"
#define FAST_INT_EN_1_inst                                                           0x0008
#define FAST_INT_EN_1_GSPI_INT_shift                                                 (31)
#define FAST_INT_EN_1_GSPI_INT_mask                                                  (0x80000000)
#define FAST_INT_EN_1_GSPI_INT(data)                                                 (0x80000000&((data)<<31))
#define FAST_INT_EN_1_GSPI_INT_src(data)                                             ((0x80000000&(data))>>31)
#define FAST_INT_EN_1_get_GSPI_INT(data)                                             ((0x80000000&(data))>>31)
#define FAST_INT_EN_1_I2C3_INT_shift                                                 (30)
#define FAST_INT_EN_1_I2C3_INT_mask                                                  (0x40000000)
#define FAST_INT_EN_1_I2C3_INT(data)                                                 (0x40000000&((data)<<30))
#define FAST_INT_EN_1_I2C3_INT_src(data)                                             ((0x40000000&(data))>>30)
#define FAST_INT_EN_1_get_I2C3_INT(data)                                             ((0x40000000&(data))>>30)
#define FAST_INT_EN_1_GP_INT_shift                                                   (1)
#define FAST_INT_EN_1_GP_INT_mask                                                    (0x3FFFFFFE)
#define FAST_INT_EN_1_GP_INT(data)                                                   (0x3FFFFFFE&((data)<<1))
#define FAST_INT_EN_1_GP_INT_src(data)                                               ((0x3FFFFFFE&(data))>>1)
#define FAST_INT_EN_1_get_GP_INT(data)                                               ((0x3FFFFFFE&(data))>>1)


#define FAST_ISR                                                                     0x1801B024
#define FAST_ISR_reg_addr                                                            "0xB801B024"
#define FAST_ISR_reg                                                                 0xB801B024
#define set_FAST_ISR_reg(data)   (*((volatile unsigned int*) FAST_ISR_reg)=data)
#define get_FAST_ISR_reg   (*((volatile unsigned int*) FAST_ISR_reg))
#define FAST_ISR_inst_adr                                                            "0x0009"
#define FAST_ISR_inst                                                                0x0009
#define FAST_ISR_gspi_int_shift                                                      (4)
#define FAST_ISR_gspi_int_mask                                                       (0x00000010)
#define FAST_ISR_gspi_int(data)                                                      (0x00000010&((data)<<4))
#define FAST_ISR_gspi_int_src(data)                                                  ((0x00000010&(data))>>4)
#define FAST_ISR_get_gspi_int(data)                                                  ((0x00000010&(data))>>4)
#define FAST_ISR_i2c3_int_shift                                                      (3)
#define FAST_ISR_i2c3_int_mask                                                       (0x00000008)
#define FAST_ISR_i2c3_int(data)                                                      (0x00000008&((data)<<3))
#define FAST_ISR_i2c3_int_src(data)                                                  ((0x00000008&(data))>>3)
#define FAST_ISR_get_i2c3_int(data)                                                  ((0x00000008&(data))>>3)
#define FAST_ISR_gpioda_int_shift                                                    (2)
#define FAST_ISR_gpioda_int_mask                                                     (0x00000004)
#define FAST_ISR_gpioda_int(data)                                                    (0x00000004&((data)<<2))
#define FAST_ISR_gpioda_int_src(data)                                                ((0x00000004&(data))>>2)
#define FAST_ISR_get_gpioda_int(data)                                                ((0x00000004&(data))>>2)
#define FAST_ISR_gpioa_int_shift                                                     (1)
#define FAST_ISR_gpioa_int_mask                                                      (0x00000002)
#define FAST_ISR_gpioa_int(data)                                                     (0x00000002&((data)<<1))
#define FAST_ISR_gpioa_int_src(data)                                                 ((0x00000002&(data))>>1)
#define FAST_ISR_get_gpioa_int(data)                                                 ((0x00000002&(data))>>1)
#define FAST_ISR_write_data_shift                                                    (0)
#define FAST_ISR_write_data_mask                                                     (0x00000001)
#define FAST_ISR_write_data(data)                                                    (0x00000001&((data)<<0))
#define FAST_ISR_write_data_src(data)                                                ((0x00000001&(data))>>0)
#define FAST_ISR_get_write_data(data)                                                ((0x00000001&(data))>>0)


#define MISC_DBG                                                                          0x1801B02C
#define MISC_DBG_reg_addr                                                                 "0xB801B02C"
#define MISC_DBG_reg                                                                      0xB801B02C
#define MISC_set_DBG_reg(data)   (*((volatile unsigned int*) DBG_reg)=data)
#define MISC_get_DBG_reg   (*((volatile unsigned int*) DBG_reg))
#define MISC_DBG_inst_adr                                                                 "0x000B"
#define MISC_DBG_inst                                                                     0x000B
#define MISC_DBG_write_enable3_shift                                                      (11)
#define MISC_DBG_write_enable3_mask                                                       (0x00000800)
#define MISC_DBG_write_enable3(data)                                                      (0x00000800&((data)<<11))
#define MISC_DBG_write_enable3_src(data)                                                  ((0x00000800&(data))>>11)
#define MISC_DBG_get_write_enable3(data)                                                  ((0x00000800&(data))>>11)
#define MISC_DBG_sel1_shift                                                               (7)
#define MISC_DBG_sel1_mask                                                                (0x00000780)
#define MISC_DBG_sel1(data)                                                               (0x00000780&((data)<<7))
#define MISC_DBG_sel1_src(data)                                                           ((0x00000780&(data))>>7)
#define MISC_DBG_get_sel1(data)                                                           ((0x00000780&(data))>>7)
#define MISC_DBG_write_enable2_shift                                                      (6)
#define MISC_DBG_write_enable2_mask                                                       (0x00000040)
#define MISC_DBG_write_enable2(data)                                                      (0x00000040&((data)<<6))
#define MISC_DBG_write_enable2_src(data)                                                  ((0x00000040&(data))>>6)
#define MISC_DBG_get_write_enable2(data)                                                  ((0x00000040&(data))>>6)
#define MISC_DBG_sel0_shift                                                               (2)
#define MISC_DBG_sel0_mask                                                                (0x0000003C)
#define MISC_DBG_sel0(data)                                                               (0x0000003C&((data)<<2))
#define MISC_DBG_sel0_src(data)                                                           ((0x0000003C&(data))>>2)
#define MISC_DBG_get_sel0(data)                                                           ((0x0000003C&(data))>>2)
#define MISC_DBG_write_enable1_shift                                                      (1)
#define MISC_DBG_write_enable1_mask                                                       (0x00000002)
#define MISC_DBG_write_enable1(data)                                                      (0x00000002&((data)<<1))
#define MISC_DBG_write_enable1_src(data)                                                  ((0x00000002&(data))>>1)
#define MISC_DBG_get_write_enable1(data)                                                  ((0x00000002&(data))>>1)
#define MISC_DBG_enable_shift                                                             (0)
#define MISC_DBG_enable_mask                                                              (0x00000001)
#define MISC_DBG_enable(data)                                                             (0x00000001&((data)<<0))
#define MISC_DBG_enable_src(data)                                                         ((0x00000001&(data))>>0)
#define MISC_DBG_get_enable(data)                                                         ((0x00000001&(data))>>0)


#define MISC_DUMMY                                                                        0x1801B030
#define MISC_DUMMY_reg_addr                                                               "0xB801B030"
#define MISC_DUMMY_reg                                                                    0xB801B030
#define MISC_set_DUMMY_reg(data)   (*((volatile unsigned int*) DUMMY_reg)=data)
#define MISC_get_DUMMY_reg   (*((volatile unsigned int*) DUMMY_reg))
#define MISC_DUMMY_inst_adr                                                               "0x000C"
#define MISC_DUMMY_inst                                                                   0x000C
#define MISC_DUMMY_write_enable4_shift                                                    (31)
#define MISC_DUMMY_write_enable4_mask                                                     (0x80000000)
#define MISC_DUMMY_write_enable4(data)                                                    (0x80000000&((data)<<31))
#define MISC_DUMMY_write_enable4_src(data)                                                ((0x80000000&(data))>>31)
#define MISC_DUMMY_get_write_enable4(data)                                                ((0x80000000&(data))>>31)
#define MISC_DUMMY_Rvd4_shift                                                             (24)
#define MISC_DUMMY_Rvd4_mask                                                              (0x7F000000)
#define MISC_DUMMY_Rvd4(data)                                                             (0x7F000000&((data)<<24))
#define MISC_DUMMY_Rvd4_src(data)                                                         ((0x7F000000&(data))>>24)
#define MISC_DUMMY_get_Rvd4(data)                                                         ((0x7F000000&(data))>>24)
#define MISC_DUMMY_write_enable3_shift                                                    (23)
#define MISC_DUMMY_write_enable3_mask                                                     (0x00800000)
#define MISC_DUMMY_write_enable3(data)                                                    (0x00800000&((data)<<23))
#define MISC_DUMMY_write_enable3_src(data)                                                ((0x00800000&(data))>>23)
#define MISC_DUMMY_get_write_enable3(data)                                                ((0x00800000&(data))>>23)
#define MISC_DUMMY_Rvd3_shift                                                             (16)
#define MISC_DUMMY_Rvd3_mask                                                              (0x007F0000)
#define MISC_DUMMY_Rvd3(data)                                                             (0x007F0000&((data)<<16))
#define MISC_DUMMY_Rvd3_src(data)                                                         ((0x007F0000&(data))>>16)
#define MISC_DUMMY_get_Rvd3(data)                                                         ((0x007F0000&(data))>>16)
#define MISC_DUMMY_write_enable2_shift                                                    (15)
#define MISC_DUMMY_write_enable2_mask                                                     (0x00008000)
#define MISC_DUMMY_write_enable2(data)                                                    (0x00008000&((data)<<15))
#define MISC_DUMMY_write_enable2_src(data)                                                ((0x00008000&(data))>>15)
#define MISC_DUMMY_get_write_enable2(data)                                                ((0x00008000&(data))>>15)
#define MISC_DUMMY_Rvd2_shift                                                             (8)
#define MISC_DUMMY_Rvd2_mask                                                              (0x00007F00)
#define MISC_DUMMY_Rvd2(data)                                                             (0x00007F00&((data)<<8))
#define MISC_DUMMY_Rvd2_src(data)                                                         ((0x00007F00&(data))>>8)
#define MISC_DUMMY_get_Rvd2(data)                                                         ((0x00007F00&(data))>>8)
#define MISC_DUMMY_write_enable1_shift                                                    (7)
#define MISC_DUMMY_write_enable1_mask                                                     (0x00000080)
#define MISC_DUMMY_write_enable1(data)                                                    (0x00000080&((data)<<7))
#define MISC_DUMMY_write_enable1_src(data)                                                ((0x00000080&(data))>>7)
#define MISC_DUMMY_get_write_enable1(data)                                                ((0x00000080&(data))>>7)
#define MISC_DUMMY_Rvd1_shift                                                             (0)
#define MISC_DUMMY_Rvd1_mask                                                              (0x0000007F)
#define MISC_DUMMY_Rvd1(data)                                                             (0x0000007F&((data)<<0))
#define MISC_DUMMY_Rvd1_src(data)                                                         ((0x0000007F&(data))>>0)
#define MISC_DUMMY_get_Rvd1(data)                                                         ((0x0000007F&(data))>>0)


#define UMSK_ISR_GP0A                                                                0x1801B040
#define UMSK_ISR_GP0A_reg_addr                                                       "0xB801B040"
#define UMSK_ISR_GP0A_reg                                                            0xB801B040
#define set_UMSK_ISR_GP0A_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP0A_reg)=data)
#define get_UMSK_ISR_GP0A_reg   (*((volatile unsigned int*) UMSK_ISR_GP0A_reg))
#define UMSK_ISR_GP0A_inst_adr                                                       "0x0010"
#define UMSK_ISR_GP0A_inst                                                           0x0010
#define UMSK_ISR_GP0A_INT30_shift                                                    (31)
#define UMSK_ISR_GP0A_INT30_mask                                                     (0x80000000)
#define UMSK_ISR_GP0A_INT30(data)                                                    (0x80000000&((data)<<31))
#define UMSK_ISR_GP0A_INT30_src(data)                                                ((0x80000000&(data))>>31)
#define UMSK_ISR_GP0A_get_INT30(data)                                                ((0x80000000&(data))>>31)
#define UMSK_ISR_GP0A_INT29_shift                                                    (30)
#define UMSK_ISR_GP0A_INT29_mask                                                     (0x40000000)
#define UMSK_ISR_GP0A_INT29(data)                                                    (0x40000000&((data)<<30))
#define UMSK_ISR_GP0A_INT29_src(data)                                                ((0x40000000&(data))>>30)
#define UMSK_ISR_GP0A_get_INT29(data)                                                ((0x40000000&(data))>>30)
#define UMSK_ISR_GP0A_INT28_shift                                                    (29)
#define UMSK_ISR_GP0A_INT28_mask                                                     (0x20000000)
#define UMSK_ISR_GP0A_INT28(data)                                                    (0x20000000&((data)<<29))
#define UMSK_ISR_GP0A_INT28_src(data)                                                ((0x20000000&(data))>>29)
#define UMSK_ISR_GP0A_get_INT28(data)                                                ((0x20000000&(data))>>29)
#define UMSK_ISR_GP0A_INT27_shift                                                    (28)
#define UMSK_ISR_GP0A_INT27_mask                                                     (0x10000000)
#define UMSK_ISR_GP0A_INT27(data)                                                    (0x10000000&((data)<<28))
#define UMSK_ISR_GP0A_INT27_src(data)                                                ((0x10000000&(data))>>28)
#define UMSK_ISR_GP0A_get_INT27(data)                                                ((0x10000000&(data))>>28)
#define UMSK_ISR_GP0A_INT26_shift                                                    (27)
#define UMSK_ISR_GP0A_INT26_mask                                                     (0x08000000)
#define UMSK_ISR_GP0A_INT26(data)                                                    (0x08000000&((data)<<27))
#define UMSK_ISR_GP0A_INT26_src(data)                                                ((0x08000000&(data))>>27)
#define UMSK_ISR_GP0A_get_INT26(data)                                                ((0x08000000&(data))>>27)
#define UMSK_ISR_GP0A_INT25_shift                                                    (26)
#define UMSK_ISR_GP0A_INT25_mask                                                     (0x04000000)
#define UMSK_ISR_GP0A_INT25(data)                                                    (0x04000000&((data)<<26))
#define UMSK_ISR_GP0A_INT25_src(data)                                                ((0x04000000&(data))>>26)
#define UMSK_ISR_GP0A_get_INT25(data)                                                ((0x04000000&(data))>>26)
#define UMSK_ISR_GP0A_INT24_shift                                                    (25)
#define UMSK_ISR_GP0A_INT24_mask                                                     (0x02000000)
#define UMSK_ISR_GP0A_INT24(data)                                                    (0x02000000&((data)<<25))
#define UMSK_ISR_GP0A_INT24_src(data)                                                ((0x02000000&(data))>>25)
#define UMSK_ISR_GP0A_get_INT24(data)                                                ((0x02000000&(data))>>25)
#define UMSK_ISR_GP0A_INT23_shift                                                    (24)
#define UMSK_ISR_GP0A_INT23_mask                                                     (0x01000000)
#define UMSK_ISR_GP0A_INT23(data)                                                    (0x01000000&((data)<<24))
#define UMSK_ISR_GP0A_INT23_src(data)                                                ((0x01000000&(data))>>24)
#define UMSK_ISR_GP0A_get_INT23(data)                                                ((0x01000000&(data))>>24)
#define UMSK_ISR_GP0A_INT22_shift                                                    (23)
#define UMSK_ISR_GP0A_INT22_mask                                                     (0x00800000)
#define UMSK_ISR_GP0A_INT22(data)                                                    (0x00800000&((data)<<23))
#define UMSK_ISR_GP0A_INT22_src(data)                                                ((0x00800000&(data))>>23)
#define UMSK_ISR_GP0A_get_INT22(data)                                                ((0x00800000&(data))>>23)
#define UMSK_ISR_GP0A_INT21_shift                                                    (22)
#define UMSK_ISR_GP0A_INT21_mask                                                     (0x00400000)
#define UMSK_ISR_GP0A_INT21(data)                                                    (0x00400000&((data)<<22))
#define UMSK_ISR_GP0A_INT21_src(data)                                                ((0x00400000&(data))>>22)
#define UMSK_ISR_GP0A_get_INT21(data)                                                ((0x00400000&(data))>>22)
#define UMSK_ISR_GP0A_INT20_shift                                                    (21)
#define UMSK_ISR_GP0A_INT20_mask                                                     (0x00200000)
#define UMSK_ISR_GP0A_INT20(data)                                                    (0x00200000&((data)<<21))
#define UMSK_ISR_GP0A_INT20_src(data)                                                ((0x00200000&(data))>>21)
#define UMSK_ISR_GP0A_get_INT20(data)                                                ((0x00200000&(data))>>21)
#define UMSK_ISR_GP0A_INT19_shift                                                    (20)
#define UMSK_ISR_GP0A_INT19_mask                                                     (0x00100000)
#define UMSK_ISR_GP0A_INT19(data)                                                    (0x00100000&((data)<<20))
#define UMSK_ISR_GP0A_INT19_src(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_GP0A_get_INT19(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_GP0A_INT18_shift                                                    (19)
#define UMSK_ISR_GP0A_INT18_mask                                                     (0x00080000)
#define UMSK_ISR_GP0A_INT18(data)                                                    (0x00080000&((data)<<19))
#define UMSK_ISR_GP0A_INT18_src(data)                                                ((0x00080000&(data))>>19)
#define UMSK_ISR_GP0A_get_INT18(data)                                                ((0x00080000&(data))>>19)
#define UMSK_ISR_GP0A_INT17_shift                                                    (18)
#define UMSK_ISR_GP0A_INT17_mask                                                     (0x00040000)
#define UMSK_ISR_GP0A_INT17(data)                                                    (0x00040000&((data)<<18))
#define UMSK_ISR_GP0A_INT17_src(data)                                                ((0x00040000&(data))>>18)
#define UMSK_ISR_GP0A_get_INT17(data)                                                ((0x00040000&(data))>>18)
#define UMSK_ISR_GP0A_INT16_shift                                                    (17)
#define UMSK_ISR_GP0A_INT16_mask                                                     (0x00020000)
#define UMSK_ISR_GP0A_INT16(data)                                                    (0x00020000&((data)<<17))
#define UMSK_ISR_GP0A_INT16_src(data)                                                ((0x00020000&(data))>>17)
#define UMSK_ISR_GP0A_get_INT16(data)                                                ((0x00020000&(data))>>17)
#define UMSK_ISR_GP0A_INT15_shift                                                    (16)
#define UMSK_ISR_GP0A_INT15_mask                                                     (0x00010000)
#define UMSK_ISR_GP0A_INT15(data)                                                    (0x00010000&((data)<<16))
#define UMSK_ISR_GP0A_INT15_src(data)                                                ((0x00010000&(data))>>16)
#define UMSK_ISR_GP0A_get_INT15(data)                                                ((0x00010000&(data))>>16)
#define UMSK_ISR_GP0A_INT14_shift                                                    (15)
#define UMSK_ISR_GP0A_INT14_mask                                                     (0x00008000)
#define UMSK_ISR_GP0A_INT14(data)                                                    (0x00008000&((data)<<15))
#define UMSK_ISR_GP0A_INT14_src(data)                                                ((0x00008000&(data))>>15)
#define UMSK_ISR_GP0A_get_INT14(data)                                                ((0x00008000&(data))>>15)
#define UMSK_ISR_GP0A_INT13_shift                                                    (14)
#define UMSK_ISR_GP0A_INT13_mask                                                     (0x00004000)
#define UMSK_ISR_GP0A_INT13(data)                                                    (0x00004000&((data)<<14))
#define UMSK_ISR_GP0A_INT13_src(data)                                                ((0x00004000&(data))>>14)
#define UMSK_ISR_GP0A_get_INT13(data)                                                ((0x00004000&(data))>>14)
#define UMSK_ISR_GP0A_INT12_shift                                                    (13)
#define UMSK_ISR_GP0A_INT12_mask                                                     (0x00002000)
#define UMSK_ISR_GP0A_INT12(data)                                                    (0x00002000&((data)<<13))
#define UMSK_ISR_GP0A_INT12_src(data)                                                ((0x00002000&(data))>>13)
#define UMSK_ISR_GP0A_get_INT12(data)                                                ((0x00002000&(data))>>13)
#define UMSK_ISR_GP0A_INT11_shift                                                    (12)
#define UMSK_ISR_GP0A_INT11_mask                                                     (0x00001000)
#define UMSK_ISR_GP0A_INT11(data)                                                    (0x00001000&((data)<<12))
#define UMSK_ISR_GP0A_INT11_src(data)                                                ((0x00001000&(data))>>12)
#define UMSK_ISR_GP0A_get_INT11(data)                                                ((0x00001000&(data))>>12)
#define UMSK_ISR_GP0A_INT10_shift                                                    (11)
#define UMSK_ISR_GP0A_INT10_mask                                                     (0x00000800)
#define UMSK_ISR_GP0A_INT10(data)                                                    (0x00000800&((data)<<11))
#define UMSK_ISR_GP0A_INT10_src(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_GP0A_get_INT10(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_GP0A_INT9_shift                                                     (10)
#define UMSK_ISR_GP0A_INT9_mask                                                      (0x00000400)
#define UMSK_ISR_GP0A_INT9(data)                                                     (0x00000400&((data)<<10))
#define UMSK_ISR_GP0A_INT9_src(data)                                                 ((0x00000400&(data))>>10)
#define UMSK_ISR_GP0A_get_INT9(data)                                                 ((0x00000400&(data))>>10)
#define UMSK_ISR_GP0A_INT8_shift                                                     (9)
#define UMSK_ISR_GP0A_INT8_mask                                                      (0x00000200)
#define UMSK_ISR_GP0A_INT8(data)                                                     (0x00000200&((data)<<9))
#define UMSK_ISR_GP0A_INT8_src(data)                                                 ((0x00000200&(data))>>9)
#define UMSK_ISR_GP0A_get_INT8(data)                                                 ((0x00000200&(data))>>9)
#define UMSK_ISR_GP0A_INT7_shift                                                     (8)
#define UMSK_ISR_GP0A_INT7_mask                                                      (0x00000100)
#define UMSK_ISR_GP0A_INT7(data)                                                     (0x00000100&((data)<<8))
#define UMSK_ISR_GP0A_INT7_src(data)                                                 ((0x00000100&(data))>>8)
#define UMSK_ISR_GP0A_get_INT7(data)                                                 ((0x00000100&(data))>>8)
#define UMSK_ISR_GP0A_INT6_shift                                                     (7)
#define UMSK_ISR_GP0A_INT6_mask                                                      (0x00000080)
#define UMSK_ISR_GP0A_INT6(data)                                                     (0x00000080&((data)<<7))
#define UMSK_ISR_GP0A_INT6_src(data)                                                 ((0x00000080&(data))>>7)
#define UMSK_ISR_GP0A_get_INT6(data)                                                 ((0x00000080&(data))>>7)
#define UMSK_ISR_GP0A_INT5_shift                                                     (6)
#define UMSK_ISR_GP0A_INT5_mask                                                      (0x00000040)
#define UMSK_ISR_GP0A_INT5(data)                                                     (0x00000040&((data)<<6))
#define UMSK_ISR_GP0A_INT5_src(data)                                                 ((0x00000040&(data))>>6)
#define UMSK_ISR_GP0A_get_INT5(data)                                                 ((0x00000040&(data))>>6)
#define UMSK_ISR_GP0A_INT4_shift                                                     (5)
#define UMSK_ISR_GP0A_INT4_mask                                                      (0x00000020)
#define UMSK_ISR_GP0A_INT4(data)                                                     (0x00000020&((data)<<5))
#define UMSK_ISR_GP0A_INT4_src(data)                                                 ((0x00000020&(data))>>5)
#define UMSK_ISR_GP0A_get_INT4(data)                                                 ((0x00000020&(data))>>5)
#define UMSK_ISR_GP0A_INT3_shift                                                     (4)
#define UMSK_ISR_GP0A_INT3_mask                                                      (0x00000010)
#define UMSK_ISR_GP0A_INT3(data)                                                     (0x00000010&((data)<<4))
#define UMSK_ISR_GP0A_INT3_src(data)                                                 ((0x00000010&(data))>>4)
#define UMSK_ISR_GP0A_get_INT3(data)                                                 ((0x00000010&(data))>>4)
#define UMSK_ISR_GP0A_INT2_shift                                                     (3)
#define UMSK_ISR_GP0A_INT2_mask                                                      (0x00000008)
#define UMSK_ISR_GP0A_INT2(data)                                                     (0x00000008&((data)<<3))
#define UMSK_ISR_GP0A_INT2_src(data)                                                 ((0x00000008&(data))>>3)
#define UMSK_ISR_GP0A_get_INT2(data)                                                 ((0x00000008&(data))>>3)
#define UMSK_ISR_GP0A_INT1_shift                                                     (2)
#define UMSK_ISR_GP0A_INT1_mask                                                      (0x00000004)
#define UMSK_ISR_GP0A_INT1(data)                                                     (0x00000004&((data)<<2))
#define UMSK_ISR_GP0A_INT1_src(data)                                                 ((0x00000004&(data))>>2)
#define UMSK_ISR_GP0A_get_INT1(data)                                                 ((0x00000004&(data))>>2)
#define UMSK_ISR_GP0A_INT0_shift                                                     (1)
#define UMSK_ISR_GP0A_INT0_mask                                                      (0x00000002)
#define UMSK_ISR_GP0A_INT0(data)                                                     (0x00000002&((data)<<1))
#define UMSK_ISR_GP0A_INT0_src(data)                                                 ((0x00000002&(data))>>1)
#define UMSK_ISR_GP0A_get_INT0(data)                                                 ((0x00000002&(data))>>1)
#define UMSK_ISR_GP0A_write_data_shift                                               (0)
#define UMSK_ISR_GP0A_write_data_mask                                                (0x00000001)
#define UMSK_ISR_GP0A_write_data(data)                                               (0x00000001&((data)<<0))
#define UMSK_ISR_GP0A_write_data_src(data)                                           ((0x00000001&(data))>>0)
#define UMSK_ISR_GP0A_get_write_data(data)                                           ((0x00000001&(data))>>0)


#define UMSK_ISR_GP1A                                                                0x1801B044
#define UMSK_ISR_GP1A_reg_addr                                                       "0xB801B044"
#define UMSK_ISR_GP1A_reg                                                            0xB801B044
#define set_UMSK_ISR_GP1A_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP1A_reg)=data)
#define get_UMSK_ISR_GP1A_reg   (*((volatile unsigned int*) UMSK_ISR_GP1A_reg))
#define UMSK_ISR_GP1A_inst_adr                                                       "0x0011"
#define UMSK_ISR_GP1A_inst                                                           0x0011
#define UMSK_ISR_GP1A_INT59_shift                                                    (29)
#define UMSK_ISR_GP1A_INT59_mask                                                     (0x20000000)
#define UMSK_ISR_GP1A_INT59(data)                                                    (0x20000000&((data)<<29))
#define UMSK_ISR_GP1A_INT59_src(data)                                                ((0x20000000&(data))>>29)
#define UMSK_ISR_GP1A_get_INT59(data)                                                ((0x20000000&(data))>>29)
#define UMSK_ISR_GP1A_INT58_shift                                                    (28)
#define UMSK_ISR_GP1A_INT58_mask                                                     (0x10000000)
#define UMSK_ISR_GP1A_INT58(data)                                                    (0x10000000&((data)<<28))
#define UMSK_ISR_GP1A_INT58_src(data)                                                ((0x10000000&(data))>>28)
#define UMSK_ISR_GP1A_get_INT58(data)                                                ((0x10000000&(data))>>28)
#define UMSK_ISR_GP1A_INT57_shift                                                    (27)
#define UMSK_ISR_GP1A_INT57_mask                                                     (0x08000000)
#define UMSK_ISR_GP1A_INT57(data)                                                    (0x08000000&((data)<<27))
#define UMSK_ISR_GP1A_INT57_src(data)                                                ((0x08000000&(data))>>27)
#define UMSK_ISR_GP1A_get_INT57(data)                                                ((0x08000000&(data))>>27)
#define UMSK_ISR_GP1A_INT56_shift                                                    (26)
#define UMSK_ISR_GP1A_INT56_mask                                                     (0x04000000)
#define UMSK_ISR_GP1A_INT56(data)                                                    (0x04000000&((data)<<26))
#define UMSK_ISR_GP1A_INT56_src(data)                                                ((0x04000000&(data))>>26)
#define UMSK_ISR_GP1A_get_INT56(data)                                                ((0x04000000&(data))>>26)
#define UMSK_ISR_GP1A_INT55_shift                                                    (25)
#define UMSK_ISR_GP1A_INT55_mask                                                     (0x02000000)
#define UMSK_ISR_GP1A_INT55(data)                                                    (0x02000000&((data)<<25))
#define UMSK_ISR_GP1A_INT55_src(data)                                                ((0x02000000&(data))>>25)
#define UMSK_ISR_GP1A_get_INT55(data)                                                ((0x02000000&(data))>>25)
#define UMSK_ISR_GP1A_INT54_shift                                                    (24)
#define UMSK_ISR_GP1A_INT54_mask                                                     (0x01000000)
#define UMSK_ISR_GP1A_INT54(data)                                                    (0x01000000&((data)<<24))
#define UMSK_ISR_GP1A_INT54_src(data)                                                ((0x01000000&(data))>>24)
#define UMSK_ISR_GP1A_get_INT54(data)                                                ((0x01000000&(data))>>24)
#define UMSK_ISR_GP1A_INT53_shift                                                    (23)
#define UMSK_ISR_GP1A_INT53_mask                                                     (0x00800000)
#define UMSK_ISR_GP1A_INT53(data)                                                    (0x00800000&((data)<<23))
#define UMSK_ISR_GP1A_INT53_src(data)                                                ((0x00800000&(data))>>23)
#define UMSK_ISR_GP1A_get_INT53(data)                                                ((0x00800000&(data))>>23)
#define UMSK_ISR_GP1A_INT52_shift                                                    (22)
#define UMSK_ISR_GP1A_INT52_mask                                                     (0x00400000)
#define UMSK_ISR_GP1A_INT52(data)                                                    (0x00400000&((data)<<22))
#define UMSK_ISR_GP1A_INT52_src(data)                                                ((0x00400000&(data))>>22)
#define UMSK_ISR_GP1A_get_INT52(data)                                                ((0x00400000&(data))>>22)
#define UMSK_ISR_GP1A_INT51_shift                                                    (21)
#define UMSK_ISR_GP1A_INT51_mask                                                     (0x00200000)
#define UMSK_ISR_GP1A_INT51(data)                                                    (0x00200000&((data)<<21))
#define UMSK_ISR_GP1A_INT51_src(data)                                                ((0x00200000&(data))>>21)
#define UMSK_ISR_GP1A_get_INT51(data)                                                ((0x00200000&(data))>>21)
#define UMSK_ISR_GP1A_INT50_shift                                                    (20)
#define UMSK_ISR_GP1A_INT50_mask                                                     (0x00100000)
#define UMSK_ISR_GP1A_INT50(data)                                                    (0x00100000&((data)<<20))
#define UMSK_ISR_GP1A_INT50_src(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_GP1A_get_INT50(data)                                                ((0x00100000&(data))>>20)
#define UMSK_ISR_GP1A_INT49_shift                                                    (19)
#define UMSK_ISR_GP1A_INT49_mask                                                     (0x00080000)
#define UMSK_ISR_GP1A_INT49(data)                                                    (0x00080000&((data)<<19))
#define UMSK_ISR_GP1A_INT49_src(data)                                                ((0x00080000&(data))>>19)
#define UMSK_ISR_GP1A_get_INT49(data)                                                ((0x00080000&(data))>>19)
#define UMSK_ISR_GP1A_INT48_shift                                                    (18)
#define UMSK_ISR_GP1A_INT48_mask                                                     (0x00040000)
#define UMSK_ISR_GP1A_INT48(data)                                                    (0x00040000&((data)<<18))
#define UMSK_ISR_GP1A_INT48_src(data)                                                ((0x00040000&(data))>>18)
#define UMSK_ISR_GP1A_get_INT48(data)                                                ((0x00040000&(data))>>18)
#define UMSK_ISR_GP1A_INT47_shift                                                    (17)
#define UMSK_ISR_GP1A_INT47_mask                                                     (0x00020000)
#define UMSK_ISR_GP1A_INT47(data)                                                    (0x00020000&((data)<<17))
#define UMSK_ISR_GP1A_INT47_src(data)                                                ((0x00020000&(data))>>17)
#define UMSK_ISR_GP1A_get_INT47(data)                                                ((0x00020000&(data))>>17)
#define UMSK_ISR_GP1A_INT46_shift                                                    (16)
#define UMSK_ISR_GP1A_INT46_mask                                                     (0x00010000)
#define UMSK_ISR_GP1A_INT46(data)                                                    (0x00010000&((data)<<16))
#define UMSK_ISR_GP1A_INT46_src(data)                                                ((0x00010000&(data))>>16)
#define UMSK_ISR_GP1A_get_INT46(data)                                                ((0x00010000&(data))>>16)
#define UMSK_ISR_GP1A_INT45_shift                                                    (15)
#define UMSK_ISR_GP1A_INT45_mask                                                     (0x00008000)
#define UMSK_ISR_GP1A_INT45(data)                                                    (0x00008000&((data)<<15))
#define UMSK_ISR_GP1A_INT45_src(data)                                                ((0x00008000&(data))>>15)
#define UMSK_ISR_GP1A_get_INT45(data)                                                ((0x00008000&(data))>>15)
#define UMSK_ISR_GP1A_INT44_shift                                                    (14)
#define UMSK_ISR_GP1A_INT44_mask                                                     (0x00004000)
#define UMSK_ISR_GP1A_INT44(data)                                                    (0x00004000&((data)<<14))
#define UMSK_ISR_GP1A_INT44_src(data)                                                ((0x00004000&(data))>>14)
#define UMSK_ISR_GP1A_get_INT44(data)                                                ((0x00004000&(data))>>14)
#define UMSK_ISR_GP1A_INT43_shift                                                    (13)
#define UMSK_ISR_GP1A_INT43_mask                                                     (0x00002000)
#define UMSK_ISR_GP1A_INT43(data)                                                    (0x00002000&((data)<<13))
#define UMSK_ISR_GP1A_INT43_src(data)                                                ((0x00002000&(data))>>13)
#define UMSK_ISR_GP1A_get_INT43(data)                                                ((0x00002000&(data))>>13)
#define UMSK_ISR_GP1A_INT42_shift                                                    (12)
#define UMSK_ISR_GP1A_INT42_mask                                                     (0x00001000)
#define UMSK_ISR_GP1A_INT42(data)                                                    (0x00001000&((data)<<12))
#define UMSK_ISR_GP1A_INT42_src(data)                                                ((0x00001000&(data))>>12)
#define UMSK_ISR_GP1A_get_INT42(data)                                                ((0x00001000&(data))>>12)
#define UMSK_ISR_GP1A_INT41_shift                                                    (11)
#define UMSK_ISR_GP1A_INT41_mask                                                     (0x00000800)
#define UMSK_ISR_GP1A_INT41(data)                                                    (0x00000800&((data)<<11))
#define UMSK_ISR_GP1A_INT41_src(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_GP1A_get_INT41(data)                                                ((0x00000800&(data))>>11)
#define UMSK_ISR_GP1A_INT40_shift                                                    (10)
#define UMSK_ISR_GP1A_INT40_mask                                                     (0x00000400)
#define UMSK_ISR_GP1A_INT40(data)                                                    (0x00000400&((data)<<10))
#define UMSK_ISR_GP1A_INT40_src(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GP1A_get_INT40(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GP1A_INT39_shift                                                    (9)
#define UMSK_ISR_GP1A_INT39_mask                                                     (0x00000200)
#define UMSK_ISR_GP1A_INT39(data)                                                    (0x00000200&((data)<<9))
#define UMSK_ISR_GP1A_INT39_src(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GP1A_get_INT39(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GP1A_INT38_shift                                                    (8)
#define UMSK_ISR_GP1A_INT38_mask                                                     (0x00000100)
#define UMSK_ISR_GP1A_INT38(data)                                                    (0x00000100&((data)<<8))
#define UMSK_ISR_GP1A_INT38_src(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GP1A_get_INT38(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GP1A_INT37_shift                                                    (7)
#define UMSK_ISR_GP1A_INT37_mask                                                     (0x00000080)
#define UMSK_ISR_GP1A_INT37(data)                                                    (0x00000080&((data)<<7))
#define UMSK_ISR_GP1A_INT37_src(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GP1A_get_INT37(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GP1A_INT36_shift                                                    (6)
#define UMSK_ISR_GP1A_INT36_mask                                                     (0x00000040)
#define UMSK_ISR_GP1A_INT36(data)                                                    (0x00000040&((data)<<6))
#define UMSK_ISR_GP1A_INT36_src(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GP1A_get_INT36(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GP1A_INT35_shift                                                    (5)
#define UMSK_ISR_GP1A_INT35_mask                                                     (0x00000020)
#define UMSK_ISR_GP1A_INT35(data)                                                    (0x00000020&((data)<<5))
#define UMSK_ISR_GP1A_INT35_src(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GP1A_get_INT35(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GP1A_INT34_shift                                                    (4)
#define UMSK_ISR_GP1A_INT34_mask                                                     (0x00000010)
#define UMSK_ISR_GP1A_INT34(data)                                                    (0x00000010&((data)<<4))
#define UMSK_ISR_GP1A_INT34_src(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GP1A_get_INT34(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GP1A_INT33_shift                                                    (3)
#define UMSK_ISR_GP1A_INT33_mask                                                     (0x00000008)
#define UMSK_ISR_GP1A_INT33(data)                                                    (0x00000008&((data)<<3))
#define UMSK_ISR_GP1A_INT33_src(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GP1A_get_INT33(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GP1A_INT32_shift                                                    (2)
#define UMSK_ISR_GP1A_INT32_mask                                                     (0x00000004)
#define UMSK_ISR_GP1A_INT32(data)                                                    (0x00000004&((data)<<2))
#define UMSK_ISR_GP1A_INT32_src(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GP1A_get_INT32(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GP1A_INT31_shift                                                    (1)
#define UMSK_ISR_GP1A_INT31_mask                                                     (0x00000002)
#define UMSK_ISR_GP1A_INT31(data)                                                    (0x00000002&((data)<<1))
#define UMSK_ISR_GP1A_INT31_src(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GP1A_get_INT31(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GP1A_write_data_shift                                               (0)
#define UMSK_ISR_GP1A_write_data_mask                                                (0x00000001)
#define UMSK_ISR_GP1A_write_data(data)                                               (0x00000001&((data)<<0))
#define UMSK_ISR_GP1A_write_data_src(data)                                           ((0x00000001&(data))>>0)
#define UMSK_ISR_GP1A_get_write_data(data)                                           ((0x00000001&(data))>>0)


#define UMSK_ISR_GP0DA                                                               0x1801B054
#define UMSK_ISR_GP0DA_reg_addr                                                      "0xB801B054"
#define UMSK_ISR_GP0DA_reg                                                           0xB801B054
#define set_UMSK_ISR_GP0DA_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP0DA_reg)=data)
#define get_UMSK_ISR_GP0DA_reg   (*((volatile unsigned int*) UMSK_ISR_GP0DA_reg))
#define UMSK_ISR_GP0DA_inst_adr                                                      "0x0015"
#define UMSK_ISR_GP0DA_inst                                                          0x0015
#define UMSK_ISR_GP0DA_INT30_shift                                                   (31)
#define UMSK_ISR_GP0DA_INT30_mask                                                    (0x80000000)
#define UMSK_ISR_GP0DA_INT30(data)                                                   (0x80000000&((data)<<31))
#define UMSK_ISR_GP0DA_INT30_src(data)                                               ((0x80000000&(data))>>31)
#define UMSK_ISR_GP0DA_get_INT30(data)                                               ((0x80000000&(data))>>31)
#define UMSK_ISR_GP0DA_INT29_shift                                                   (30)
#define UMSK_ISR_GP0DA_INT29_mask                                                    (0x40000000)
#define UMSK_ISR_GP0DA_INT29(data)                                                   (0x40000000&((data)<<30))
#define UMSK_ISR_GP0DA_INT29_src(data)                                               ((0x40000000&(data))>>30)
#define UMSK_ISR_GP0DA_get_INT29(data)                                               ((0x40000000&(data))>>30)
#define UMSK_ISR_GP0DA_INT28_shift                                                   (29)
#define UMSK_ISR_GP0DA_INT28_mask                                                    (0x20000000)
#define UMSK_ISR_GP0DA_INT28(data)                                                   (0x20000000&((data)<<29))
#define UMSK_ISR_GP0DA_INT28_src(data)                                               ((0x20000000&(data))>>29)
#define UMSK_ISR_GP0DA_get_INT28(data)                                               ((0x20000000&(data))>>29)
#define UMSK_ISR_GP0DA_INT27_shift                                                   (28)
#define UMSK_ISR_GP0DA_INT27_mask                                                    (0x10000000)
#define UMSK_ISR_GP0DA_INT27(data)                                                   (0x10000000&((data)<<28))
#define UMSK_ISR_GP0DA_INT27_src(data)                                               ((0x10000000&(data))>>28)
#define UMSK_ISR_GP0DA_get_INT27(data)                                               ((0x10000000&(data))>>28)
#define UMSK_ISR_GP0DA_INT26_shift                                                   (27)
#define UMSK_ISR_GP0DA_INT26_mask                                                    (0x08000000)
#define UMSK_ISR_GP0DA_INT26(data)                                                   (0x08000000&((data)<<27))
#define UMSK_ISR_GP0DA_INT26_src(data)                                               ((0x08000000&(data))>>27)
#define UMSK_ISR_GP0DA_get_INT26(data)                                               ((0x08000000&(data))>>27)
#define UMSK_ISR_GP0DA_INT25_shift                                                   (26)
#define UMSK_ISR_GP0DA_INT25_mask                                                    (0x04000000)
#define UMSK_ISR_GP0DA_INT25(data)                                                   (0x04000000&((data)<<26))
#define UMSK_ISR_GP0DA_INT25_src(data)                                               ((0x04000000&(data))>>26)
#define UMSK_ISR_GP0DA_get_INT25(data)                                               ((0x04000000&(data))>>26)
#define UMSK_ISR_GP0DA_INT24_shift                                                   (25)
#define UMSK_ISR_GP0DA_INT24_mask                                                    (0x02000000)
#define UMSK_ISR_GP0DA_INT24(data)                                                   (0x02000000&((data)<<25))
#define UMSK_ISR_GP0DA_INT24_src(data)                                               ((0x02000000&(data))>>25)
#define UMSK_ISR_GP0DA_get_INT24(data)                                               ((0x02000000&(data))>>25)
#define UMSK_ISR_GP0DA_INT23_shift                                                   (24)
#define UMSK_ISR_GP0DA_INT23_mask                                                    (0x01000000)
#define UMSK_ISR_GP0DA_INT23(data)                                                   (0x01000000&((data)<<24))
#define UMSK_ISR_GP0DA_INT23_src(data)                                               ((0x01000000&(data))>>24)
#define UMSK_ISR_GP0DA_get_INT23(data)                                               ((0x01000000&(data))>>24)
#define UMSK_ISR_GP0DA_INT22_shift                                                   (23)
#define UMSK_ISR_GP0DA_INT22_mask                                                    (0x00800000)
#define UMSK_ISR_GP0DA_INT22(data)                                                   (0x00800000&((data)<<23))
#define UMSK_ISR_GP0DA_INT22_src(data)                                               ((0x00800000&(data))>>23)
#define UMSK_ISR_GP0DA_get_INT22(data)                                               ((0x00800000&(data))>>23)
#define UMSK_ISR_GP0DA_INT21_shift                                                   (22)
#define UMSK_ISR_GP0DA_INT21_mask                                                    (0x00400000)
#define UMSK_ISR_GP0DA_INT21(data)                                                   (0x00400000&((data)<<22))
#define UMSK_ISR_GP0DA_INT21_src(data)                                               ((0x00400000&(data))>>22)
#define UMSK_ISR_GP0DA_get_INT21(data)                                               ((0x00400000&(data))>>22)
#define UMSK_ISR_GP0DA_INT20_shift                                                   (21)
#define UMSK_ISR_GP0DA_INT20_mask                                                    (0x00200000)
#define UMSK_ISR_GP0DA_INT20(data)                                                   (0x00200000&((data)<<21))
#define UMSK_ISR_GP0DA_INT20_src(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GP0DA_get_INT20(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GP0DA_INT19_shift                                                   (20)
#define UMSK_ISR_GP0DA_INT19_mask                                                    (0x00100000)
#define UMSK_ISR_GP0DA_INT19(data)                                                   (0x00100000&((data)<<20))
#define UMSK_ISR_GP0DA_INT19_src(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GP0DA_get_INT19(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GP0DA_INT18_shift                                                   (19)
#define UMSK_ISR_GP0DA_INT18_mask                                                    (0x00080000)
#define UMSK_ISR_GP0DA_INT18(data)                                                   (0x00080000&((data)<<19))
#define UMSK_ISR_GP0DA_INT18_src(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GP0DA_get_INT18(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GP0DA_INT17_shift                                                   (18)
#define UMSK_ISR_GP0DA_INT17_mask                                                    (0x00040000)
#define UMSK_ISR_GP0DA_INT17(data)                                                   (0x00040000&((data)<<18))
#define UMSK_ISR_GP0DA_INT17_src(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GP0DA_get_INT17(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GP0DA_INT16_shift                                                   (17)
#define UMSK_ISR_GP0DA_INT16_mask                                                    (0x00020000)
#define UMSK_ISR_GP0DA_INT16(data)                                                   (0x00020000&((data)<<17))
#define UMSK_ISR_GP0DA_INT16_src(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GP0DA_get_INT16(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GP0DA_INT15_shift                                                   (16)
#define UMSK_ISR_GP0DA_INT15_mask                                                    (0x00010000)
#define UMSK_ISR_GP0DA_INT15(data)                                                   (0x00010000&((data)<<16))
#define UMSK_ISR_GP0DA_INT15_src(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GP0DA_get_INT15(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GP0DA_INT14_shift                                                   (15)
#define UMSK_ISR_GP0DA_INT14_mask                                                    (0x00008000)
#define UMSK_ISR_GP0DA_INT14(data)                                                   (0x00008000&((data)<<15))
#define UMSK_ISR_GP0DA_INT14_src(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GP0DA_get_INT14(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GP0DA_INT13_shift                                                   (14)
#define UMSK_ISR_GP0DA_INT13_mask                                                    (0x00004000)
#define UMSK_ISR_GP0DA_INT13(data)                                                   (0x00004000&((data)<<14))
#define UMSK_ISR_GP0DA_INT13_src(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GP0DA_get_INT13(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GP0DA_INT12_shift                                                   (13)
#define UMSK_ISR_GP0DA_INT12_mask                                                    (0x00002000)
#define UMSK_ISR_GP0DA_INT12(data)                                                   (0x00002000&((data)<<13))
#define UMSK_ISR_GP0DA_INT12_src(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GP0DA_get_INT12(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GP0DA_INT11_shift                                                   (12)
#define UMSK_ISR_GP0DA_INT11_mask                                                    (0x00001000)
#define UMSK_ISR_GP0DA_INT11(data)                                                   (0x00001000&((data)<<12))
#define UMSK_ISR_GP0DA_INT11_src(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GP0DA_get_INT11(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GP0DA_INT10_shift                                                   (11)
#define UMSK_ISR_GP0DA_INT10_mask                                                    (0x00000800)
#define UMSK_ISR_GP0DA_INT10(data)                                                   (0x00000800&((data)<<11))
#define UMSK_ISR_GP0DA_INT10_src(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GP0DA_get_INT10(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GP0DA_INT9_shift                                                    (10)
#define UMSK_ISR_GP0DA_INT9_mask                                                     (0x00000400)
#define UMSK_ISR_GP0DA_INT9(data)                                                    (0x00000400&((data)<<10))
#define UMSK_ISR_GP0DA_INT9_src(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GP0DA_get_INT9(data)                                                ((0x00000400&(data))>>10)
#define UMSK_ISR_GP0DA_INT8_shift                                                    (9)
#define UMSK_ISR_GP0DA_INT8_mask                                                     (0x00000200)
#define UMSK_ISR_GP0DA_INT8(data)                                                    (0x00000200&((data)<<9))
#define UMSK_ISR_GP0DA_INT8_src(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GP0DA_get_INT8(data)                                                ((0x00000200&(data))>>9)
#define UMSK_ISR_GP0DA_INT7_shift                                                    (8)
#define UMSK_ISR_GP0DA_INT7_mask                                                     (0x00000100)
#define UMSK_ISR_GP0DA_INT7(data)                                                    (0x00000100&((data)<<8))
#define UMSK_ISR_GP0DA_INT7_src(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GP0DA_get_INT7(data)                                                ((0x00000100&(data))>>8)
#define UMSK_ISR_GP0DA_INT6_shift                                                    (7)
#define UMSK_ISR_GP0DA_INT6_mask                                                     (0x00000080)
#define UMSK_ISR_GP0DA_INT6(data)                                                    (0x00000080&((data)<<7))
#define UMSK_ISR_GP0DA_INT6_src(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GP0DA_get_INT6(data)                                                ((0x00000080&(data))>>7)
#define UMSK_ISR_GP0DA_INT5_shift                                                    (6)
#define UMSK_ISR_GP0DA_INT5_mask                                                     (0x00000040)
#define UMSK_ISR_GP0DA_INT5(data)                                                    (0x00000040&((data)<<6))
#define UMSK_ISR_GP0DA_INT5_src(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GP0DA_get_INT5(data)                                                ((0x00000040&(data))>>6)
#define UMSK_ISR_GP0DA_INT4_shift                                                    (5)
#define UMSK_ISR_GP0DA_INT4_mask                                                     (0x00000020)
#define UMSK_ISR_GP0DA_INT4(data)                                                    (0x00000020&((data)<<5))
#define UMSK_ISR_GP0DA_INT4_src(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GP0DA_get_INT4(data)                                                ((0x00000020&(data))>>5)
#define UMSK_ISR_GP0DA_INT3_shift                                                    (4)
#define UMSK_ISR_GP0DA_INT3_mask                                                     (0x00000010)
#define UMSK_ISR_GP0DA_INT3(data)                                                    (0x00000010&((data)<<4))
#define UMSK_ISR_GP0DA_INT3_src(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GP0DA_get_INT3(data)                                                ((0x00000010&(data))>>4)
#define UMSK_ISR_GP0DA_INT2_shift                                                    (3)
#define UMSK_ISR_GP0DA_INT2_mask                                                     (0x00000008)
#define UMSK_ISR_GP0DA_INT2(data)                                                    (0x00000008&((data)<<3))
#define UMSK_ISR_GP0DA_INT2_src(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GP0DA_get_INT2(data)                                                ((0x00000008&(data))>>3)
#define UMSK_ISR_GP0DA_INT1_shift                                                    (2)
#define UMSK_ISR_GP0DA_INT1_mask                                                     (0x00000004)
#define UMSK_ISR_GP0DA_INT1(data)                                                    (0x00000004&((data)<<2))
#define UMSK_ISR_GP0DA_INT1_src(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GP0DA_get_INT1(data)                                                ((0x00000004&(data))>>2)
#define UMSK_ISR_GP0DA_INT0_shift                                                    (1)
#define UMSK_ISR_GP0DA_INT0_mask                                                     (0x00000002)
#define UMSK_ISR_GP0DA_INT0(data)                                                    (0x00000002&((data)<<1))
#define UMSK_ISR_GP0DA_INT0_src(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GP0DA_get_INT0(data)                                                ((0x00000002&(data))>>1)
#define UMSK_ISR_GP0DA_write_data_shift                                              (0)
#define UMSK_ISR_GP0DA_write_data_mask                                               (0x00000001)
#define UMSK_ISR_GP0DA_write_data(data)                                              (0x00000001&((data)<<0))
#define UMSK_ISR_GP0DA_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define UMSK_ISR_GP0DA_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define UMSK_ISR_GP1DA                                                               0x1801B058
#define UMSK_ISR_GP1DA_reg_addr                                                      "0xB801B058"
#define UMSK_ISR_GP1DA_reg                                                           0xB801B058
#define set_UMSK_ISR_GP1DA_reg(data)   (*((volatile unsigned int*) UMSK_ISR_GP1DA_reg)=data)
#define get_UMSK_ISR_GP1DA_reg   (*((volatile unsigned int*) UMSK_ISR_GP1DA_reg))
#define UMSK_ISR_GP1DA_inst_adr                                                      "0x0016"
#define UMSK_ISR_GP1DA_inst                                                          0x0016
#define UMSK_ISR_GP1DA_INT59_shift                                                   (29)
#define UMSK_ISR_GP1DA_INT59_mask                                                    (0x20000000)
#define UMSK_ISR_GP1DA_INT59(data)                                                   (0x20000000&((data)<<29))
#define UMSK_ISR_GP1DA_INT59_src(data)                                               ((0x20000000&(data))>>29)
#define UMSK_ISR_GP1DA_get_INT59(data)                                               ((0x20000000&(data))>>29)
#define UMSK_ISR_GP1DA_INT58_shift                                                   (28)
#define UMSK_ISR_GP1DA_INT58_mask                                                    (0x10000000)
#define UMSK_ISR_GP1DA_INT58(data)                                                   (0x10000000&((data)<<28))
#define UMSK_ISR_GP1DA_INT58_src(data)                                               ((0x10000000&(data))>>28)
#define UMSK_ISR_GP1DA_get_INT58(data)                                               ((0x10000000&(data))>>28)
#define UMSK_ISR_GP1DA_INT57_shift                                                   (27)
#define UMSK_ISR_GP1DA_INT57_mask                                                    (0x08000000)
#define UMSK_ISR_GP1DA_INT57(data)                                                   (0x08000000&((data)<<27))
#define UMSK_ISR_GP1DA_INT57_src(data)                                               ((0x08000000&(data))>>27)
#define UMSK_ISR_GP1DA_get_INT57(data)                                               ((0x08000000&(data))>>27)
#define UMSK_ISR_GP1DA_INT56_shift                                                   (26)
#define UMSK_ISR_GP1DA_INT56_mask                                                    (0x04000000)
#define UMSK_ISR_GP1DA_INT56(data)                                                   (0x04000000&((data)<<26))
#define UMSK_ISR_GP1DA_INT56_src(data)                                               ((0x04000000&(data))>>26)
#define UMSK_ISR_GP1DA_get_INT56(data)                                               ((0x04000000&(data))>>26)
#define UMSK_ISR_GP1DA_INT55_shift                                                   (25)
#define UMSK_ISR_GP1DA_INT55_mask                                                    (0x02000000)
#define UMSK_ISR_GP1DA_INT55(data)                                                   (0x02000000&((data)<<25))
#define UMSK_ISR_GP1DA_INT55_src(data)                                               ((0x02000000&(data))>>25)
#define UMSK_ISR_GP1DA_get_INT55(data)                                               ((0x02000000&(data))>>25)
#define UMSK_ISR_GP1DA_INT54_shift                                                   (24)
#define UMSK_ISR_GP1DA_INT54_mask                                                    (0x01000000)
#define UMSK_ISR_GP1DA_INT54(data)                                                   (0x01000000&((data)<<24))
#define UMSK_ISR_GP1DA_INT54_src(data)                                               ((0x01000000&(data))>>24)
#define UMSK_ISR_GP1DA_get_INT54(data)                                               ((0x01000000&(data))>>24)
#define UMSK_ISR_GP1DA_INT53_shift                                                   (23)
#define UMSK_ISR_GP1DA_INT53_mask                                                    (0x00800000)
#define UMSK_ISR_GP1DA_INT53(data)                                                   (0x00800000&((data)<<23))
#define UMSK_ISR_GP1DA_INT53_src(data)                                               ((0x00800000&(data))>>23)
#define UMSK_ISR_GP1DA_get_INT53(data)                                               ((0x00800000&(data))>>23)
#define UMSK_ISR_GP1DA_INT52_shift                                                   (22)
#define UMSK_ISR_GP1DA_INT52_mask                                                    (0x00400000)
#define UMSK_ISR_GP1DA_INT52(data)                                                   (0x00400000&((data)<<22))
#define UMSK_ISR_GP1DA_INT52_src(data)                                               ((0x00400000&(data))>>22)
#define UMSK_ISR_GP1DA_get_INT52(data)                                               ((0x00400000&(data))>>22)
#define UMSK_ISR_GP1DA_INT51_shift                                                   (21)
#define UMSK_ISR_GP1DA_INT51_mask                                                    (0x00200000)
#define UMSK_ISR_GP1DA_INT51(data)                                                   (0x00200000&((data)<<21))
#define UMSK_ISR_GP1DA_INT51_src(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GP1DA_get_INT51(data)                                               ((0x00200000&(data))>>21)
#define UMSK_ISR_GP1DA_INT50_shift                                                   (20)
#define UMSK_ISR_GP1DA_INT50_mask                                                    (0x00100000)
#define UMSK_ISR_GP1DA_INT50(data)                                                   (0x00100000&((data)<<20))
#define UMSK_ISR_GP1DA_INT50_src(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GP1DA_get_INT50(data)                                               ((0x00100000&(data))>>20)
#define UMSK_ISR_GP1DA_INT49_shift                                                   (19)
#define UMSK_ISR_GP1DA_INT49_mask                                                    (0x00080000)
#define UMSK_ISR_GP1DA_INT49(data)                                                   (0x00080000&((data)<<19))
#define UMSK_ISR_GP1DA_INT49_src(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GP1DA_get_INT49(data)                                               ((0x00080000&(data))>>19)
#define UMSK_ISR_GP1DA_INT48_shift                                                   (18)
#define UMSK_ISR_GP1DA_INT48_mask                                                    (0x00040000)
#define UMSK_ISR_GP1DA_INT48(data)                                                   (0x00040000&((data)<<18))
#define UMSK_ISR_GP1DA_INT48_src(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GP1DA_get_INT48(data)                                               ((0x00040000&(data))>>18)
#define UMSK_ISR_GP1DA_INT47_shift                                                   (17)
#define UMSK_ISR_GP1DA_INT47_mask                                                    (0x00020000)
#define UMSK_ISR_GP1DA_INT47(data)                                                   (0x00020000&((data)<<17))
#define UMSK_ISR_GP1DA_INT47_src(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GP1DA_get_INT47(data)                                               ((0x00020000&(data))>>17)
#define UMSK_ISR_GP1DA_INT46_shift                                                   (16)
#define UMSK_ISR_GP1DA_INT46_mask                                                    (0x00010000)
#define UMSK_ISR_GP1DA_INT46(data)                                                   (0x00010000&((data)<<16))
#define UMSK_ISR_GP1DA_INT46_src(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GP1DA_get_INT46(data)                                               ((0x00010000&(data))>>16)
#define UMSK_ISR_GP1DA_INT45_shift                                                   (15)
#define UMSK_ISR_GP1DA_INT45_mask                                                    (0x00008000)
#define UMSK_ISR_GP1DA_INT45(data)                                                   (0x00008000&((data)<<15))
#define UMSK_ISR_GP1DA_INT45_src(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GP1DA_get_INT45(data)                                               ((0x00008000&(data))>>15)
#define UMSK_ISR_GP1DA_INT44_shift                                                   (14)
#define UMSK_ISR_GP1DA_INT44_mask                                                    (0x00004000)
#define UMSK_ISR_GP1DA_INT44(data)                                                   (0x00004000&((data)<<14))
#define UMSK_ISR_GP1DA_INT44_src(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GP1DA_get_INT44(data)                                               ((0x00004000&(data))>>14)
#define UMSK_ISR_GP1DA_INT43_shift                                                   (13)
#define UMSK_ISR_GP1DA_INT43_mask                                                    (0x00002000)
#define UMSK_ISR_GP1DA_INT43(data)                                                   (0x00002000&((data)<<13))
#define UMSK_ISR_GP1DA_INT43_src(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GP1DA_get_INT43(data)                                               ((0x00002000&(data))>>13)
#define UMSK_ISR_GP1DA_INT42_shift                                                   (12)
#define UMSK_ISR_GP1DA_INT42_mask                                                    (0x00001000)
#define UMSK_ISR_GP1DA_INT42(data)                                                   (0x00001000&((data)<<12))
#define UMSK_ISR_GP1DA_INT42_src(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GP1DA_get_INT42(data)                                               ((0x00001000&(data))>>12)
#define UMSK_ISR_GP1DA_INT41_shift                                                   (11)
#define UMSK_ISR_GP1DA_INT41_mask                                                    (0x00000800)
#define UMSK_ISR_GP1DA_INT41(data)                                                   (0x00000800&((data)<<11))
#define UMSK_ISR_GP1DA_INT41_src(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GP1DA_get_INT41(data)                                               ((0x00000800&(data))>>11)
#define UMSK_ISR_GP1DA_INT40_shift                                                   (10)
#define UMSK_ISR_GP1DA_INT40_mask                                                    (0x00000400)
#define UMSK_ISR_GP1DA_INT40(data)                                                   (0x00000400&((data)<<10))
#define UMSK_ISR_GP1DA_INT40_src(data)                                               ((0x00000400&(data))>>10)
#define UMSK_ISR_GP1DA_get_INT40(data)                                               ((0x00000400&(data))>>10)
#define UMSK_ISR_GP1DA_INT39_shift                                                   (9)
#define UMSK_ISR_GP1DA_INT39_mask                                                    (0x00000200)
#define UMSK_ISR_GP1DA_INT39(data)                                                   (0x00000200&((data)<<9))
#define UMSK_ISR_GP1DA_INT39_src(data)                                               ((0x00000200&(data))>>9)
#define UMSK_ISR_GP1DA_get_INT39(data)                                               ((0x00000200&(data))>>9)
#define UMSK_ISR_GP1DA_INT38_shift                                                   (8)
#define UMSK_ISR_GP1DA_INT38_mask                                                    (0x00000100)
#define UMSK_ISR_GP1DA_INT38(data)                                                   (0x00000100&((data)<<8))
#define UMSK_ISR_GP1DA_INT38_src(data)                                               ((0x00000100&(data))>>8)
#define UMSK_ISR_GP1DA_get_INT38(data)                                               ((0x00000100&(data))>>8)
#define UMSK_ISR_GP1DA_INT37_shift                                                   (7)
#define UMSK_ISR_GP1DA_INT37_mask                                                    (0x00000080)
#define UMSK_ISR_GP1DA_INT37(data)                                                   (0x00000080&((data)<<7))
#define UMSK_ISR_GP1DA_INT37_src(data)                                               ((0x00000080&(data))>>7)
#define UMSK_ISR_GP1DA_get_INT37(data)                                               ((0x00000080&(data))>>7)
#define UMSK_ISR_GP1DA_INT36_shift                                                   (6)
#define UMSK_ISR_GP1DA_INT36_mask                                                    (0x00000040)
#define UMSK_ISR_GP1DA_INT36(data)                                                   (0x00000040&((data)<<6))
#define UMSK_ISR_GP1DA_INT36_src(data)                                               ((0x00000040&(data))>>6)
#define UMSK_ISR_GP1DA_get_INT36(data)                                               ((0x00000040&(data))>>6)
#define UMSK_ISR_GP1DA_INT35_shift                                                   (5)
#define UMSK_ISR_GP1DA_INT35_mask                                                    (0x00000020)
#define UMSK_ISR_GP1DA_INT35(data)                                                   (0x00000020&((data)<<5))
#define UMSK_ISR_GP1DA_INT35_src(data)                                               ((0x00000020&(data))>>5)
#define UMSK_ISR_GP1DA_get_INT35(data)                                               ((0x00000020&(data))>>5)
#define UMSK_ISR_GP1DA_INT34_shift                                                   (4)
#define UMSK_ISR_GP1DA_INT34_mask                                                    (0x00000010)
#define UMSK_ISR_GP1DA_INT34(data)                                                   (0x00000010&((data)<<4))
#define UMSK_ISR_GP1DA_INT34_src(data)                                               ((0x00000010&(data))>>4)
#define UMSK_ISR_GP1DA_get_INT34(data)                                               ((0x00000010&(data))>>4)
#define UMSK_ISR_GP1DA_INT33_shift                                                   (3)
#define UMSK_ISR_GP1DA_INT33_mask                                                    (0x00000008)
#define UMSK_ISR_GP1DA_INT33(data)                                                   (0x00000008&((data)<<3))
#define UMSK_ISR_GP1DA_INT33_src(data)                                               ((0x00000008&(data))>>3)
#define UMSK_ISR_GP1DA_get_INT33(data)                                               ((0x00000008&(data))>>3)
#define UMSK_ISR_GP1DA_INT32_shift                                                   (2)
#define UMSK_ISR_GP1DA_INT32_mask                                                    (0x00000004)
#define UMSK_ISR_GP1DA_INT32(data)                                                   (0x00000004&((data)<<2))
#define UMSK_ISR_GP1DA_INT32_src(data)                                               ((0x00000004&(data))>>2)
#define UMSK_ISR_GP1DA_get_INT32(data)                                               ((0x00000004&(data))>>2)
#define UMSK_ISR_GP1DA_INT31_shift                                                   (1)
#define UMSK_ISR_GP1DA_INT31_mask                                                    (0x00000002)
#define UMSK_ISR_GP1DA_INT31(data)                                                   (0x00000002&((data)<<1))
#define UMSK_ISR_GP1DA_INT31_src(data)                                               ((0x00000002&(data))>>1)
#define UMSK_ISR_GP1DA_get_INT31(data)                                               ((0x00000002&(data))>>1)
#define UMSK_ISR_GP1DA_write_data_shift                                              (0)
#define UMSK_ISR_GP1DA_write_data_mask                                               (0x00000001)
#define UMSK_ISR_GP1DA_write_data(data)                                              (0x00000001&((data)<<0))
#define UMSK_ISR_GP1DA_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define UMSK_ISR_GP1DA_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define MISC_DUMMY1                                                                       0x1801B068
#define MISC_DUMMY1_reg_addr                                                              "0xB801B068"
#define MISC_DUMMY1_reg                                                                   0xB801B068
#define MISC_set_DUMMY1_reg(data)   (*((volatile unsigned int*) DUMMY1_reg)=data)
#define MISC_get_DUMMY1_reg   (*((volatile unsigned int*) DUMMY1_reg))
#define MISC_DUMMY1_inst_adr                                                              "0x001A"
#define MISC_DUMMY1_inst                                                                  0x001A
#define MISC_DUMMY1_write_enable2_shift                                                   (31)
#define MISC_DUMMY1_write_enable2_mask                                                    (0x80000000)
#define MISC_DUMMY1_write_enable2(data)                                                   (0x80000000&((data)<<31))
#define MISC_DUMMY1_write_enable2_src(data)                                               ((0x80000000&(data))>>31)
#define MISC_DUMMY1_get_write_enable2(data)                                               ((0x80000000&(data))>>31)
#define MISC_DUMMY1_Rvd2_shift                                                            (16)
#define MISC_DUMMY1_Rvd2_mask                                                             (0x7FFF0000)
#define MISC_DUMMY1_Rvd2(data)                                                            (0x7FFF0000&((data)<<16))
#define MISC_DUMMY1_Rvd2_src(data)                                                        ((0x7FFF0000&(data))>>16)
#define MISC_DUMMY1_get_Rvd2(data)                                                        ((0x7FFF0000&(data))>>16)
#define MISC_DUMMY1_write_enable1_shift                                                   (15)
#define MISC_DUMMY1_write_enable1_mask                                                    (0x00008000)
#define MISC_DUMMY1_write_enable1(data)                                                   (0x00008000&((data)<<15))
#define MISC_DUMMY1_write_enable1_src(data)                                               ((0x00008000&(data))>>15)
#define MISC_DUMMY1_get_write_enable1(data)                                               ((0x00008000&(data))>>15)
#define MISC_DUMMY1_Rvd1_shift                                                            (0)
#define MISC_DUMMY1_Rvd1_mask                                                             (0x00007FFF)
#define MISC_DUMMY1_Rvd1(data)                                                            (0x00007FFF&((data)<<0))
#define MISC_DUMMY1_Rvd1_src(data)                                                        ((0x00007FFF&(data))>>0)
#define MISC_DUMMY1_get_Rvd1(data)                                                        ((0x00007FFF&(data))>>0)


#define UR_CTRL                                                                      0x1801B06C
#define UR_CTRL_reg_addr                                                             "0xB801B06C"
#define UR_CTRL_reg                                                                  0xB801B06C
#define set_UR_CTRL_reg(data)   (*((volatile unsigned int*) UR_CTRL_reg)=data)
#define get_UR_CTRL_reg   (*((volatile unsigned int*) UR_CTRL_reg))
#define UR_CTRL_inst_adr                                                             "0x001B"
#define UR_CTRL_inst                                                                 0x001B
#define UR_CTRL_Rvd3_shift                                                           (29)
#define UR_CTRL_Rvd3_mask                                                            (0xE0000000)
#define UR_CTRL_Rvd3(data)                                                           (0xE0000000&((data)<<29))
#define UR_CTRL_Rvd3_src(data)                                                       ((0xE0000000&(data))>>29)
#define UR_CTRL_get_Rvd3(data)                                                       ((0xE0000000&(data))>>29)
#define UR_CTRL_to_len_shift                                                         (20)
#define UR_CTRL_to_len_mask                                                          (0x0FF00000)
#define UR_CTRL_to_len(data)                                                         (0x0FF00000&((data)<<20))
#define UR_CTRL_to_len_src(data)                                                     ((0x0FF00000&(data))>>20)
#define UR_CTRL_get_to_len(data)                                                     ((0x0FF00000&(data))>>20)
#define UR_CTRL_to_int_en_shift                                                      (19)
#define UR_CTRL_to_int_en_mask                                                       (0x00080000)
#define UR_CTRL_to_int_en(data)                                                      (0x00080000&((data)<<19))
#define UR_CTRL_to_int_en_src(data)                                                  ((0x00080000&(data))>>19)
#define UR_CTRL_get_to_int_en(data)                                                  ((0x00080000&(data))>>19)
#define UR_CTRL_TOAUAREQ_shift                                                       (18)
#define UR_CTRL_TOAUAREQ_mask                                                        (0x00040000)
#define UR_CTRL_TOAUAREQ(data)                                                       (0x00040000&((data)<<18))
#define UR_CTRL_TOAUAREQ_src(data)                                                   ((0x00040000&(data))>>18)
#define UR_CTRL_get_TOAUAREQ(data)                                                   ((0x00040000&(data))>>18)
#define UR_CTRL_FLOW_POL_shift                                                       (17)
#define UR_CTRL_FLOW_POL_mask                                                        (0x00020000)
#define UR_CTRL_FLOW_POL(data)                                                       (0x00020000&((data)<<17))
#define UR_CTRL_FLOW_POL_src(data)                                                   ((0x00020000&(data))>>17)
#define UR_CTRL_get_FLOW_POL(data)                                                   ((0x00020000&(data))>>17)
#define UR_CTRL_MDIFEN_shift                                                         (16)
#define UR_CTRL_MDIFEN_mask                                                          (0x00010000)
#define UR_CTRL_MDIFEN(data)                                                         (0x00010000&((data)<<16))
#define UR_CTRL_MDIFEN_src(data)                                                     ((0x00010000&(data))>>16)
#define UR_CTRL_get_MDIFEN(data)                                                     ((0x00010000&(data))>>16)
#define UR_CTRL_TXEMPTHR_shift                                                       (8)
#define UR_CTRL_TXEMPTHR_mask                                                        (0x00003F00)
#define UR_CTRL_TXEMPTHR(data)                                                       (0x00003F00&((data)<<8))
#define UR_CTRL_TXEMPTHR_src(data)                                                   ((0x00003F00&(data))>>8)
#define UR_CTRL_get_TXEMPTHR(data)                                                   ((0x00003F00&(data))>>8)
#define UR_CTRL_RXFULTHR_shift                                                       (0)
#define UR_CTRL_RXFULTHR_mask                                                        (0x0000003F)
#define UR_CTRL_RXFULTHR(data)                                                       (0x0000003F&((data)<<0))
#define UR_CTRL_RXFULTHR_src(data)                                                   ((0x0000003F&(data))>>0)
#define UR_CTRL_get_RXFULTHR(data)                                                   ((0x0000003F&(data))>>0)


#define FAST_ISR_GPIO0_A                                                             0x1801B070
#define FAST_ISR_GPIO0_A_reg_addr                                                    "0xB801B070"
#define FAST_ISR_GPIO0_A_reg                                                         0xB801B070
#define set_FAST_ISR_GPIO0_A_reg(data)   (*((volatile unsigned int*) FAST_ISR_GPIO0_A_reg)=data)
#define get_FAST_ISR_GPIO0_A_reg   (*((volatile unsigned int*) FAST_ISR_GPIO0_A_reg))
#define FAST_ISR_GPIO0_A_inst_adr                                                    "0x001C"
#define FAST_ISR_GPIO0_A_inst                                                        0x001C
#define FAST_ISR_GPIO0_A_int_30_shift                                                (31)
#define FAST_ISR_GPIO0_A_int_30_mask                                                 (0x80000000)
#define FAST_ISR_GPIO0_A_int_30(data)                                                (0x80000000&((data)<<31))
#define FAST_ISR_GPIO0_A_int_30_src(data)                                            ((0x80000000&(data))>>31)
#define FAST_ISR_GPIO0_A_get_int_30(data)                                            ((0x80000000&(data))>>31)
#define FAST_ISR_GPIO0_A_int_29_shift                                                (30)
#define FAST_ISR_GPIO0_A_int_29_mask                                                 (0x40000000)
#define FAST_ISR_GPIO0_A_int_29(data)                                                (0x40000000&((data)<<30))
#define FAST_ISR_GPIO0_A_int_29_src(data)                                            ((0x40000000&(data))>>30)
#define FAST_ISR_GPIO0_A_get_int_29(data)                                            ((0x40000000&(data))>>30)
#define FAST_ISR_GPIO0_A_int_28_shift                                                (29)
#define FAST_ISR_GPIO0_A_int_28_mask                                                 (0x20000000)
#define FAST_ISR_GPIO0_A_int_28(data)                                                (0x20000000&((data)<<29))
#define FAST_ISR_GPIO0_A_int_28_src(data)                                            ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO0_A_get_int_28(data)                                            ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO0_A_int_27_shift                                                (28)
#define FAST_ISR_GPIO0_A_int_27_mask                                                 (0x10000000)
#define FAST_ISR_GPIO0_A_int_27(data)                                                (0x10000000&((data)<<28))
#define FAST_ISR_GPIO0_A_int_27_src(data)                                            ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO0_A_get_int_27(data)                                            ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO0_A_int_26_shift                                                (27)
#define FAST_ISR_GPIO0_A_int_26_mask                                                 (0x08000000)
#define FAST_ISR_GPIO0_A_int_26(data)                                                (0x08000000&((data)<<27))
#define FAST_ISR_GPIO0_A_int_26_src(data)                                            ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO0_A_get_int_26(data)                                            ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO0_A_int_25_shift                                                (26)
#define FAST_ISR_GPIO0_A_int_25_mask                                                 (0x04000000)
#define FAST_ISR_GPIO0_A_int_25(data)                                                (0x04000000&((data)<<26))
#define FAST_ISR_GPIO0_A_int_25_src(data)                                            ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO0_A_get_int_25(data)                                            ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO0_A_int_24_shift                                                (25)
#define FAST_ISR_GPIO0_A_int_24_mask                                                 (0x02000000)
#define FAST_ISR_GPIO0_A_int_24(data)                                                (0x02000000&((data)<<25))
#define FAST_ISR_GPIO0_A_int_24_src(data)                                            ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO0_A_get_int_24(data)                                            ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO0_A_int_23_shift                                                (24)
#define FAST_ISR_GPIO0_A_int_23_mask                                                 (0x01000000)
#define FAST_ISR_GPIO0_A_int_23(data)                                                (0x01000000&((data)<<24))
#define FAST_ISR_GPIO0_A_int_23_src(data)                                            ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO0_A_get_int_23(data)                                            ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO0_A_int_22_shift                                                (23)
#define FAST_ISR_GPIO0_A_int_22_mask                                                 (0x00800000)
#define FAST_ISR_GPIO0_A_int_22(data)                                                (0x00800000&((data)<<23))
#define FAST_ISR_GPIO0_A_int_22_src(data)                                            ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO0_A_get_int_22(data)                                            ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO0_A_int_21_shift                                                (22)
#define FAST_ISR_GPIO0_A_int_21_mask                                                 (0x00400000)
#define FAST_ISR_GPIO0_A_int_21(data)                                                (0x00400000&((data)<<22))
#define FAST_ISR_GPIO0_A_int_21_src(data)                                            ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO0_A_get_int_21(data)                                            ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO0_A_int_20_shift                                                (21)
#define FAST_ISR_GPIO0_A_int_20_mask                                                 (0x00200000)
#define FAST_ISR_GPIO0_A_int_20(data)                                                (0x00200000&((data)<<21))
#define FAST_ISR_GPIO0_A_int_20_src(data)                                            ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO0_A_get_int_20(data)                                            ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO0_A_int_19_shift                                                (20)
#define FAST_ISR_GPIO0_A_int_19_mask                                                 (0x00100000)
#define FAST_ISR_GPIO0_A_int_19(data)                                                (0x00100000&((data)<<20))
#define FAST_ISR_GPIO0_A_int_19_src(data)                                            ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO0_A_get_int_19(data)                                            ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO0_A_int_18_shift                                                (19)
#define FAST_ISR_GPIO0_A_int_18_mask                                                 (0x00080000)
#define FAST_ISR_GPIO0_A_int_18(data)                                                (0x00080000&((data)<<19))
#define FAST_ISR_GPIO0_A_int_18_src(data)                                            ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO0_A_get_int_18(data)                                            ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO0_A_int_17_shift                                                (18)
#define FAST_ISR_GPIO0_A_int_17_mask                                                 (0x00040000)
#define FAST_ISR_GPIO0_A_int_17(data)                                                (0x00040000&((data)<<18))
#define FAST_ISR_GPIO0_A_int_17_src(data)                                            ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO0_A_get_int_17(data)                                            ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO0_A_int_16_shift                                                (17)
#define FAST_ISR_GPIO0_A_int_16_mask                                                 (0x00020000)
#define FAST_ISR_GPIO0_A_int_16(data)                                                (0x00020000&((data)<<17))
#define FAST_ISR_GPIO0_A_int_16_src(data)                                            ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO0_A_get_int_16(data)                                            ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO0_A_int_15_shift                                                (16)
#define FAST_ISR_GPIO0_A_int_15_mask                                                 (0x00010000)
#define FAST_ISR_GPIO0_A_int_15(data)                                                (0x00010000&((data)<<16))
#define FAST_ISR_GPIO0_A_int_15_src(data)                                            ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO0_A_get_int_15(data)                                            ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO0_A_int_14_shift                                                (15)
#define FAST_ISR_GPIO0_A_int_14_mask                                                 (0x00008000)
#define FAST_ISR_GPIO0_A_int_14(data)                                                (0x00008000&((data)<<15))
#define FAST_ISR_GPIO0_A_int_14_src(data)                                            ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO0_A_get_int_14(data)                                            ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO0_A_int_13_shift                                                (14)
#define FAST_ISR_GPIO0_A_int_13_mask                                                 (0x00004000)
#define FAST_ISR_GPIO0_A_int_13(data)                                                (0x00004000&((data)<<14))
#define FAST_ISR_GPIO0_A_int_13_src(data)                                            ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO0_A_get_int_13(data)                                            ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO0_A_int_12_shift                                                (13)
#define FAST_ISR_GPIO0_A_int_12_mask                                                 (0x00002000)
#define FAST_ISR_GPIO0_A_int_12(data)                                                (0x00002000&((data)<<13))
#define FAST_ISR_GPIO0_A_int_12_src(data)                                            ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO0_A_get_int_12(data)                                            ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO0_A_int_11_shift                                                (12)
#define FAST_ISR_GPIO0_A_int_11_mask                                                 (0x00001000)
#define FAST_ISR_GPIO0_A_int_11(data)                                                (0x00001000&((data)<<12))
#define FAST_ISR_GPIO0_A_int_11_src(data)                                            ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO0_A_get_int_11(data)                                            ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO0_A_int_10_shift                                                (11)
#define FAST_ISR_GPIO0_A_int_10_mask                                                 (0x00000800)
#define FAST_ISR_GPIO0_A_int_10(data)                                                (0x00000800&((data)<<11))
#define FAST_ISR_GPIO0_A_int_10_src(data)                                            ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO0_A_get_int_10(data)                                            ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO0_A_int_9_shift                                                 (10)
#define FAST_ISR_GPIO0_A_int_9_mask                                                  (0x00000400)
#define FAST_ISR_GPIO0_A_int_9(data)                                                 (0x00000400&((data)<<10))
#define FAST_ISR_GPIO0_A_int_9_src(data)                                             ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO0_A_get_int_9(data)                                             ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO0_A_int_8_shift                                                 (9)
#define FAST_ISR_GPIO0_A_int_8_mask                                                  (0x00000200)
#define FAST_ISR_GPIO0_A_int_8(data)                                                 (0x00000200&((data)<<9))
#define FAST_ISR_GPIO0_A_int_8_src(data)                                             ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO0_A_get_int_8(data)                                             ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO0_A_int_7_shift                                                 (8)
#define FAST_ISR_GPIO0_A_int_7_mask                                                  (0x00000100)
#define FAST_ISR_GPIO0_A_int_7(data)                                                 (0x00000100&((data)<<8))
#define FAST_ISR_GPIO0_A_int_7_src(data)                                             ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO0_A_get_int_7(data)                                             ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO0_A_int_6_shift                                                 (7)
#define FAST_ISR_GPIO0_A_int_6_mask                                                  (0x00000080)
#define FAST_ISR_GPIO0_A_int_6(data)                                                 (0x00000080&((data)<<7))
#define FAST_ISR_GPIO0_A_int_6_src(data)                                             ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO0_A_get_int_6(data)                                             ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO0_A_int_5_shift                                                 (6)
#define FAST_ISR_GPIO0_A_int_5_mask                                                  (0x00000040)
#define FAST_ISR_GPIO0_A_int_5(data)                                                 (0x00000040&((data)<<6))
#define FAST_ISR_GPIO0_A_int_5_src(data)                                             ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO0_A_get_int_5(data)                                             ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO0_A_int_4_shift                                                 (5)
#define FAST_ISR_GPIO0_A_int_4_mask                                                  (0x00000020)
#define FAST_ISR_GPIO0_A_int_4(data)                                                 (0x00000020&((data)<<5))
#define FAST_ISR_GPIO0_A_int_4_src(data)                                             ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO0_A_get_int_4(data)                                             ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO0_A_int_3_shift                                                 (4)
#define FAST_ISR_GPIO0_A_int_3_mask                                                  (0x00000010)
#define FAST_ISR_GPIO0_A_int_3(data)                                                 (0x00000010&((data)<<4))
#define FAST_ISR_GPIO0_A_int_3_src(data)                                             ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO0_A_get_int_3(data)                                             ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO0_A_int_2_shift                                                 (3)
#define FAST_ISR_GPIO0_A_int_2_mask                                                  (0x00000008)
#define FAST_ISR_GPIO0_A_int_2(data)                                                 (0x00000008&((data)<<3))
#define FAST_ISR_GPIO0_A_int_2_src(data)                                             ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO0_A_get_int_2(data)                                             ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO0_A_int_1_shift                                                 (2)
#define FAST_ISR_GPIO0_A_int_1_mask                                                  (0x00000004)
#define FAST_ISR_GPIO0_A_int_1(data)                                                 (0x00000004&((data)<<2))
#define FAST_ISR_GPIO0_A_int_1_src(data)                                             ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO0_A_get_int_1(data)                                             ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO0_A_int_0_shift                                                 (1)
#define FAST_ISR_GPIO0_A_int_0_mask                                                  (0x00000002)
#define FAST_ISR_GPIO0_A_int_0(data)                                                 (0x00000002&((data)<<1))
#define FAST_ISR_GPIO0_A_int_0_src(data)                                             ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO0_A_get_int_0(data)                                             ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO0_A_write_data_shift                                            (0)
#define FAST_ISR_GPIO0_A_write_data_mask                                             (0x00000001)
#define FAST_ISR_GPIO0_A_write_data(data)                                            (0x00000001&((data)<<0))
#define FAST_ISR_GPIO0_A_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define FAST_ISR_GPIO0_A_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define FAST_ISR_GPIO1_A                                                             0x1801B074
#define FAST_ISR_GPIO1_A_reg_addr                                                    "0xB801B074"
#define FAST_ISR_GPIO1_A_reg                                                         0xB801B074
#define set_FAST_ISR_GPIO1_A_reg(data)   (*((volatile unsigned int*) FAST_ISR_GPIO1_A_reg)=data)
#define get_FAST_ISR_GPIO1_A_reg   (*((volatile unsigned int*) FAST_ISR_GPIO1_A_reg))
#define FAST_ISR_GPIO1_A_inst_adr                                                    "0x001D"
#define FAST_ISR_GPIO1_A_inst                                                        0x001D
#define FAST_ISR_GPIO1_A_int_59_shift                                                (29)
#define FAST_ISR_GPIO1_A_int_59_mask                                                 (0x20000000)
#define FAST_ISR_GPIO1_A_int_59(data)                                                (0x20000000&((data)<<29))
#define FAST_ISR_GPIO1_A_int_59_src(data)                                            ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO1_A_get_int_59(data)                                            ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO1_A_int_58_shift                                                (28)
#define FAST_ISR_GPIO1_A_int_58_mask                                                 (0x10000000)
#define FAST_ISR_GPIO1_A_int_58(data)                                                (0x10000000&((data)<<28))
#define FAST_ISR_GPIO1_A_int_58_src(data)                                            ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO1_A_get_int_58(data)                                            ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO1_A_int_57_shift                                                (27)
#define FAST_ISR_GPIO1_A_int_57_mask                                                 (0x08000000)
#define FAST_ISR_GPIO1_A_int_57(data)                                                (0x08000000&((data)<<27))
#define FAST_ISR_GPIO1_A_int_57_src(data)                                            ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO1_A_get_int_57(data)                                            ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO1_A_int_56_shift                                                (26)
#define FAST_ISR_GPIO1_A_int_56_mask                                                 (0x04000000)
#define FAST_ISR_GPIO1_A_int_56(data)                                                (0x04000000&((data)<<26))
#define FAST_ISR_GPIO1_A_int_56_src(data)                                            ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO1_A_get_int_56(data)                                            ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO1_A_int_55_shift                                                (25)
#define FAST_ISR_GPIO1_A_int_55_mask                                                 (0x02000000)
#define FAST_ISR_GPIO1_A_int_55(data)                                                (0x02000000&((data)<<25))
#define FAST_ISR_GPIO1_A_int_55_src(data)                                            ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO1_A_get_int_55(data)                                            ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO1_A_int_54_shift                                                (24)
#define FAST_ISR_GPIO1_A_int_54_mask                                                 (0x01000000)
#define FAST_ISR_GPIO1_A_int_54(data)                                                (0x01000000&((data)<<24))
#define FAST_ISR_GPIO1_A_int_54_src(data)                                            ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO1_A_get_int_54(data)                                            ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO1_A_int_53_shift                                                (23)
#define FAST_ISR_GPIO1_A_int_53_mask                                                 (0x00800000)
#define FAST_ISR_GPIO1_A_int_53(data)                                                (0x00800000&((data)<<23))
#define FAST_ISR_GPIO1_A_int_53_src(data)                                            ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO1_A_get_int_53(data)                                            ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO1_A_int_52_shift                                                (22)
#define FAST_ISR_GPIO1_A_int_52_mask                                                 (0x00400000)
#define FAST_ISR_GPIO1_A_int_52(data)                                                (0x00400000&((data)<<22))
#define FAST_ISR_GPIO1_A_int_52_src(data)                                            ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO1_A_get_int_52(data)                                            ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO1_A_int_51_shift                                                (21)
#define FAST_ISR_GPIO1_A_int_51_mask                                                 (0x00200000)
#define FAST_ISR_GPIO1_A_int_51(data)                                                (0x00200000&((data)<<21))
#define FAST_ISR_GPIO1_A_int_51_src(data)                                            ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO1_A_get_int_51(data)                                            ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO1_A_int_50_shift                                                (20)
#define FAST_ISR_GPIO1_A_int_50_mask                                                 (0x00100000)
#define FAST_ISR_GPIO1_A_int_50(data)                                                (0x00100000&((data)<<20))
#define FAST_ISR_GPIO1_A_int_50_src(data)                                            ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO1_A_get_int_50(data)                                            ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO1_A_int_49_shift                                                (19)
#define FAST_ISR_GPIO1_A_int_49_mask                                                 (0x00080000)
#define FAST_ISR_GPIO1_A_int_49(data)                                                (0x00080000&((data)<<19))
#define FAST_ISR_GPIO1_A_int_49_src(data)                                            ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO1_A_get_int_49(data)                                            ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO1_A_int_48_shift                                                (18)
#define FAST_ISR_GPIO1_A_int_48_mask                                                 (0x00040000)
#define FAST_ISR_GPIO1_A_int_48(data)                                                (0x00040000&((data)<<18))
#define FAST_ISR_GPIO1_A_int_48_src(data)                                            ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO1_A_get_int_48(data)                                            ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO1_A_int_47_shift                                                (17)
#define FAST_ISR_GPIO1_A_int_47_mask                                                 (0x00020000)
#define FAST_ISR_GPIO1_A_int_47(data)                                                (0x00020000&((data)<<17))
#define FAST_ISR_GPIO1_A_int_47_src(data)                                            ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO1_A_get_int_47(data)                                            ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO1_A_int_46_shift                                                (16)
#define FAST_ISR_GPIO1_A_int_46_mask                                                 (0x00010000)
#define FAST_ISR_GPIO1_A_int_46(data)                                                (0x00010000&((data)<<16))
#define FAST_ISR_GPIO1_A_int_46_src(data)                                            ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO1_A_get_int_46(data)                                            ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO1_A_int_45_shift                                                (15)
#define FAST_ISR_GPIO1_A_int_45_mask                                                 (0x00008000)
#define FAST_ISR_GPIO1_A_int_45(data)                                                (0x00008000&((data)<<15))
#define FAST_ISR_GPIO1_A_int_45_src(data)                                            ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO1_A_get_int_45(data)                                            ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO1_A_int_44_shift                                                (14)
#define FAST_ISR_GPIO1_A_int_44_mask                                                 (0x00004000)
#define FAST_ISR_GPIO1_A_int_44(data)                                                (0x00004000&((data)<<14))
#define FAST_ISR_GPIO1_A_int_44_src(data)                                            ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO1_A_get_int_44(data)                                            ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO1_A_int_43_shift                                                (13)
#define FAST_ISR_GPIO1_A_int_43_mask                                                 (0x00002000)
#define FAST_ISR_GPIO1_A_int_43(data)                                                (0x00002000&((data)<<13))
#define FAST_ISR_GPIO1_A_int_43_src(data)                                            ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO1_A_get_int_43(data)                                            ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO1_A_int_42_shift                                                (12)
#define FAST_ISR_GPIO1_A_int_42_mask                                                 (0x00001000)
#define FAST_ISR_GPIO1_A_int_42(data)                                                (0x00001000&((data)<<12))
#define FAST_ISR_GPIO1_A_int_42_src(data)                                            ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO1_A_get_int_42(data)                                            ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO1_A_int_41_shift                                                (11)
#define FAST_ISR_GPIO1_A_int_41_mask                                                 (0x00000800)
#define FAST_ISR_GPIO1_A_int_41(data)                                                (0x00000800&((data)<<11))
#define FAST_ISR_GPIO1_A_int_41_src(data)                                            ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO1_A_get_int_41(data)                                            ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO1_A_int_40_shift                                                (10)
#define FAST_ISR_GPIO1_A_int_40_mask                                                 (0x00000400)
#define FAST_ISR_GPIO1_A_int_40(data)                                                (0x00000400&((data)<<10))
#define FAST_ISR_GPIO1_A_int_40_src(data)                                            ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO1_A_get_int_40(data)                                            ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO1_A_int_39_shift                                                (9)
#define FAST_ISR_GPIO1_A_int_39_mask                                                 (0x00000200)
#define FAST_ISR_GPIO1_A_int_39(data)                                                (0x00000200&((data)<<9))
#define FAST_ISR_GPIO1_A_int_39_src(data)                                            ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO1_A_get_int_39(data)                                            ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO1_A_int_38_shift                                                (8)
#define FAST_ISR_GPIO1_A_int_38_mask                                                 (0x00000100)
#define FAST_ISR_GPIO1_A_int_38(data)                                                (0x00000100&((data)<<8))
#define FAST_ISR_GPIO1_A_int_38_src(data)                                            ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO1_A_get_int_38(data)                                            ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO1_A_int_37_shift                                                (7)
#define FAST_ISR_GPIO1_A_int_37_mask                                                 (0x00000080)
#define FAST_ISR_GPIO1_A_int_37(data)                                                (0x00000080&((data)<<7))
#define FAST_ISR_GPIO1_A_int_37_src(data)                                            ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO1_A_get_int_37(data)                                            ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO1_A_int_36_shift                                                (6)
#define FAST_ISR_GPIO1_A_int_36_mask                                                 (0x00000040)
#define FAST_ISR_GPIO1_A_int_36(data)                                                (0x00000040&((data)<<6))
#define FAST_ISR_GPIO1_A_int_36_src(data)                                            ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO1_A_get_int_36(data)                                            ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO1_A_int_35_shift                                                (5)
#define FAST_ISR_GPIO1_A_int_35_mask                                                 (0x00000020)
#define FAST_ISR_GPIO1_A_int_35(data)                                                (0x00000020&((data)<<5))
#define FAST_ISR_GPIO1_A_int_35_src(data)                                            ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO1_A_get_int_35(data)                                            ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO1_A_int_34_shift                                                (4)
#define FAST_ISR_GPIO1_A_int_34_mask                                                 (0x00000010)
#define FAST_ISR_GPIO1_A_int_34(data)                                                (0x00000010&((data)<<4))
#define FAST_ISR_GPIO1_A_int_34_src(data)                                            ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO1_A_get_int_34(data)                                            ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO1_A_int_33_shift                                                (3)
#define FAST_ISR_GPIO1_A_int_33_mask                                                 (0x00000008)
#define FAST_ISR_GPIO1_A_int_33(data)                                                (0x00000008&((data)<<3))
#define FAST_ISR_GPIO1_A_int_33_src(data)                                            ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO1_A_get_int_33(data)                                            ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO1_A_int_32_shift                                                (2)
#define FAST_ISR_GPIO1_A_int_32_mask                                                 (0x00000004)
#define FAST_ISR_GPIO1_A_int_32(data)                                                (0x00000004&((data)<<2))
#define FAST_ISR_GPIO1_A_int_32_src(data)                                            ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO1_A_get_int_32(data)                                            ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO1_A_int_31_shift                                                (1)
#define FAST_ISR_GPIO1_A_int_31_mask                                                 (0x00000002)
#define FAST_ISR_GPIO1_A_int_31(data)                                                (0x00000002&((data)<<1))
#define FAST_ISR_GPIO1_A_int_31_src(data)                                            ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO1_A_get_int_31(data)                                            ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO1_A_write_data_shift                                            (0)
#define FAST_ISR_GPIO1_A_write_data_mask                                             (0x00000001)
#define FAST_ISR_GPIO1_A_write_data(data)                                            (0x00000001&((data)<<0))
#define FAST_ISR_GPIO1_A_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define FAST_ISR_GPIO1_A_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define FAST_ISR_GPIO0_DA                                                            0x1801B078
#define FAST_ISR_GPIO0_DA_reg_addr                                                   "0xB801B078"
#define FAST_ISR_GPIO0_DA_reg                                                        0xB801B078
#define set_FAST_ISR_GPIO0_DA_reg(data)   (*((volatile unsigned int*) FAST_ISR_GPIO0_DA_reg)=data)
#define get_FAST_ISR_GPIO0_DA_reg   (*((volatile unsigned int*) FAST_ISR_GPIO0_DA_reg))
#define FAST_ISR_GPIO0_DA_inst_adr                                                   "0x001E"
#define FAST_ISR_GPIO0_DA_inst                                                       0x001E
#define FAST_ISR_GPIO0_DA_int_30_shift                                               (31)
#define FAST_ISR_GPIO0_DA_int_30_mask                                                (0x80000000)
#define FAST_ISR_GPIO0_DA_int_30(data)                                               (0x80000000&((data)<<31))
#define FAST_ISR_GPIO0_DA_int_30_src(data)                                           ((0x80000000&(data))>>31)
#define FAST_ISR_GPIO0_DA_get_int_30(data)                                           ((0x80000000&(data))>>31)
#define FAST_ISR_GPIO0_DA_int_29_shift                                               (30)
#define FAST_ISR_GPIO0_DA_int_29_mask                                                (0x40000000)
#define FAST_ISR_GPIO0_DA_int_29(data)                                               (0x40000000&((data)<<30))
#define FAST_ISR_GPIO0_DA_int_29_src(data)                                           ((0x40000000&(data))>>30)
#define FAST_ISR_GPIO0_DA_get_int_29(data)                                           ((0x40000000&(data))>>30)
#define FAST_ISR_GPIO0_DA_int_28_shift                                               (29)
#define FAST_ISR_GPIO0_DA_int_28_mask                                                (0x20000000)
#define FAST_ISR_GPIO0_DA_int_28(data)                                               (0x20000000&((data)<<29))
#define FAST_ISR_GPIO0_DA_int_28_src(data)                                           ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO0_DA_get_int_28(data)                                           ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO0_DA_int_27_shift                                               (28)
#define FAST_ISR_GPIO0_DA_int_27_mask                                                (0x10000000)
#define FAST_ISR_GPIO0_DA_int_27(data)                                               (0x10000000&((data)<<28))
#define FAST_ISR_GPIO0_DA_int_27_src(data)                                           ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO0_DA_get_int_27(data)                                           ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO0_DA_int_26_shift                                               (27)
#define FAST_ISR_GPIO0_DA_int_26_mask                                                (0x08000000)
#define FAST_ISR_GPIO0_DA_int_26(data)                                               (0x08000000&((data)<<27))
#define FAST_ISR_GPIO0_DA_int_26_src(data)                                           ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO0_DA_get_int_26(data)                                           ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO0_DA_int_25_shift                                               (26)
#define FAST_ISR_GPIO0_DA_int_25_mask                                                (0x04000000)
#define FAST_ISR_GPIO0_DA_int_25(data)                                               (0x04000000&((data)<<26))
#define FAST_ISR_GPIO0_DA_int_25_src(data)                                           ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO0_DA_get_int_25(data)                                           ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO0_DA_int_24_shift                                               (25)
#define FAST_ISR_GPIO0_DA_int_24_mask                                                (0x02000000)
#define FAST_ISR_GPIO0_DA_int_24(data)                                               (0x02000000&((data)<<25))
#define FAST_ISR_GPIO0_DA_int_24_src(data)                                           ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO0_DA_get_int_24(data)                                           ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO0_DA_int_23_shift                                               (24)
#define FAST_ISR_GPIO0_DA_int_23_mask                                                (0x01000000)
#define FAST_ISR_GPIO0_DA_int_23(data)                                               (0x01000000&((data)<<24))
#define FAST_ISR_GPIO0_DA_int_23_src(data)                                           ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO0_DA_get_int_23(data)                                           ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO0_DA_int_22_shift                                               (23)
#define FAST_ISR_GPIO0_DA_int_22_mask                                                (0x00800000)
#define FAST_ISR_GPIO0_DA_int_22(data)                                               (0x00800000&((data)<<23))
#define FAST_ISR_GPIO0_DA_int_22_src(data)                                           ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO0_DA_get_int_22(data)                                           ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO0_DA_int_21_shift                                               (22)
#define FAST_ISR_GPIO0_DA_int_21_mask                                                (0x00400000)
#define FAST_ISR_GPIO0_DA_int_21(data)                                               (0x00400000&((data)<<22))
#define FAST_ISR_GPIO0_DA_int_21_src(data)                                           ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO0_DA_get_int_21(data)                                           ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO0_DA_int_20_shift                                               (21)
#define FAST_ISR_GPIO0_DA_int_20_mask                                                (0x00200000)
#define FAST_ISR_GPIO0_DA_int_20(data)                                               (0x00200000&((data)<<21))
#define FAST_ISR_GPIO0_DA_int_20_src(data)                                           ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO0_DA_get_int_20(data)                                           ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO0_DA_int_19_shift                                               (20)
#define FAST_ISR_GPIO0_DA_int_19_mask                                                (0x00100000)
#define FAST_ISR_GPIO0_DA_int_19(data)                                               (0x00100000&((data)<<20))
#define FAST_ISR_GPIO0_DA_int_19_src(data)                                           ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO0_DA_get_int_19(data)                                           ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO0_DA_int_18_shift                                               (19)
#define FAST_ISR_GPIO0_DA_int_18_mask                                                (0x00080000)
#define FAST_ISR_GPIO0_DA_int_18(data)                                               (0x00080000&((data)<<19))
#define FAST_ISR_GPIO0_DA_int_18_src(data)                                           ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO0_DA_get_int_18(data)                                           ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO0_DA_int_17_shift                                               (18)
#define FAST_ISR_GPIO0_DA_int_17_mask                                                (0x00040000)
#define FAST_ISR_GPIO0_DA_int_17(data)                                               (0x00040000&((data)<<18))
#define FAST_ISR_GPIO0_DA_int_17_src(data)                                           ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO0_DA_get_int_17(data)                                           ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO0_DA_int_16_shift                                               (17)
#define FAST_ISR_GPIO0_DA_int_16_mask                                                (0x00020000)
#define FAST_ISR_GPIO0_DA_int_16(data)                                               (0x00020000&((data)<<17))
#define FAST_ISR_GPIO0_DA_int_16_src(data)                                           ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO0_DA_get_int_16(data)                                           ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO0_DA_int_15_shift                                               (16)
#define FAST_ISR_GPIO0_DA_int_15_mask                                                (0x00010000)
#define FAST_ISR_GPIO0_DA_int_15(data)                                               (0x00010000&((data)<<16))
#define FAST_ISR_GPIO0_DA_int_15_src(data)                                           ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO0_DA_get_int_15(data)                                           ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO0_DA_int_14_shift                                               (15)
#define FAST_ISR_GPIO0_DA_int_14_mask                                                (0x00008000)
#define FAST_ISR_GPIO0_DA_int_14(data)                                               (0x00008000&((data)<<15))
#define FAST_ISR_GPIO0_DA_int_14_src(data)                                           ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO0_DA_get_int_14(data)                                           ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO0_DA_int_13_shift                                               (14)
#define FAST_ISR_GPIO0_DA_int_13_mask                                                (0x00004000)
#define FAST_ISR_GPIO0_DA_int_13(data)                                               (0x00004000&((data)<<14))
#define FAST_ISR_GPIO0_DA_int_13_src(data)                                           ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO0_DA_get_int_13(data)                                           ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO0_DA_int_12_shift                                               (13)
#define FAST_ISR_GPIO0_DA_int_12_mask                                                (0x00002000)
#define FAST_ISR_GPIO0_DA_int_12(data)                                               (0x00002000&((data)<<13))
#define FAST_ISR_GPIO0_DA_int_12_src(data)                                           ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO0_DA_get_int_12(data)                                           ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO0_DA_int_11_shift                                               (12)
#define FAST_ISR_GPIO0_DA_int_11_mask                                                (0x00001000)
#define FAST_ISR_GPIO0_DA_int_11(data)                                               (0x00001000&((data)<<12))
#define FAST_ISR_GPIO0_DA_int_11_src(data)                                           ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO0_DA_get_int_11(data)                                           ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO0_DA_int_10_shift                                               (11)
#define FAST_ISR_GPIO0_DA_int_10_mask                                                (0x00000800)
#define FAST_ISR_GPIO0_DA_int_10(data)                                               (0x00000800&((data)<<11))
#define FAST_ISR_GPIO0_DA_int_10_src(data)                                           ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO0_DA_get_int_10(data)                                           ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO0_DA_int_9_shift                                                (10)
#define FAST_ISR_GPIO0_DA_int_9_mask                                                 (0x00000400)
#define FAST_ISR_GPIO0_DA_int_9(data)                                                (0x00000400&((data)<<10))
#define FAST_ISR_GPIO0_DA_int_9_src(data)                                            ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO0_DA_get_int_9(data)                                            ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO0_DA_int_8_shift                                                (9)
#define FAST_ISR_GPIO0_DA_int_8_mask                                                 (0x00000200)
#define FAST_ISR_GPIO0_DA_int_8(data)                                                (0x00000200&((data)<<9))
#define FAST_ISR_GPIO0_DA_int_8_src(data)                                            ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO0_DA_get_int_8(data)                                            ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO0_DA_int_7_shift                                                (8)
#define FAST_ISR_GPIO0_DA_int_7_mask                                                 (0x00000100)
#define FAST_ISR_GPIO0_DA_int_7(data)                                                (0x00000100&((data)<<8))
#define FAST_ISR_GPIO0_DA_int_7_src(data)                                            ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO0_DA_get_int_7(data)                                            ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO0_DA_int_6_shift                                                (7)
#define FAST_ISR_GPIO0_DA_int_6_mask                                                 (0x00000080)
#define FAST_ISR_GPIO0_DA_int_6(data)                                                (0x00000080&((data)<<7))
#define FAST_ISR_GPIO0_DA_int_6_src(data)                                            ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO0_DA_get_int_6(data)                                            ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO0_DA_int_5_shift                                                (6)
#define FAST_ISR_GPIO0_DA_int_5_mask                                                 (0x00000040)
#define FAST_ISR_GPIO0_DA_int_5(data)                                                (0x00000040&((data)<<6))
#define FAST_ISR_GPIO0_DA_int_5_src(data)                                            ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO0_DA_get_int_5(data)                                            ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO0_DA_int_4_shift                                                (5)
#define FAST_ISR_GPIO0_DA_int_4_mask                                                 (0x00000020)
#define FAST_ISR_GPIO0_DA_int_4(data)                                                (0x00000020&((data)<<5))
#define FAST_ISR_GPIO0_DA_int_4_src(data)                                            ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO0_DA_get_int_4(data)                                            ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO0_DA_int_3_shift                                                (4)
#define FAST_ISR_GPIO0_DA_int_3_mask                                                 (0x00000010)
#define FAST_ISR_GPIO0_DA_int_3(data)                                                (0x00000010&((data)<<4))
#define FAST_ISR_GPIO0_DA_int_3_src(data)                                            ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO0_DA_get_int_3(data)                                            ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO0_DA_int_2_shift                                                (3)
#define FAST_ISR_GPIO0_DA_int_2_mask                                                 (0x00000008)
#define FAST_ISR_GPIO0_DA_int_2(data)                                                (0x00000008&((data)<<3))
#define FAST_ISR_GPIO0_DA_int_2_src(data)                                            ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO0_DA_get_int_2(data)                                            ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO0_DA_int_1_shift                                                (2)
#define FAST_ISR_GPIO0_DA_int_1_mask                                                 (0x00000004)
#define FAST_ISR_GPIO0_DA_int_1(data)                                                (0x00000004&((data)<<2))
#define FAST_ISR_GPIO0_DA_int_1_src(data)                                            ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO0_DA_get_int_1(data)                                            ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO0_DA_int_0_shift                                                (1)
#define FAST_ISR_GPIO0_DA_int_0_mask                                                 (0x00000002)
#define FAST_ISR_GPIO0_DA_int_0(data)                                                (0x00000002&((data)<<1))
#define FAST_ISR_GPIO0_DA_int_0_src(data)                                            ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO0_DA_get_int_0(data)                                            ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO0_DA_write_data_shift                                           (0)
#define FAST_ISR_GPIO0_DA_write_data_mask                                            (0x00000001)
#define FAST_ISR_GPIO0_DA_write_data(data)                                           (0x00000001&((data)<<0))
#define FAST_ISR_GPIO0_DA_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define FAST_ISR_GPIO0_DA_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define FAST_ISR_GPIO1_DA                                                            0x1801B07C
#define FAST_ISR_GPIO1_DA_reg_addr                                                   "0xB801B07C"
#define FAST_ISR_GPIO1_DA_reg                                                        0xB801B07C
#define set_FAST_ISR_GPIO1_DA_reg(data)   (*((volatile unsigned int*) FAST_ISR_GPIO1_DA_reg)=data)
#define get_FAST_ISR_GPIO1_DA_reg   (*((volatile unsigned int*) FAST_ISR_GPIO1_DA_reg))
#define FAST_ISR_GPIO1_DA_inst_adr                                                   "0x001F"
#define FAST_ISR_GPIO1_DA_inst                                                       0x001F
#define FAST_ISR_GPIO1_DA_int_59_shift                                               (29)
#define FAST_ISR_GPIO1_DA_int_59_mask                                                (0x20000000)
#define FAST_ISR_GPIO1_DA_int_59(data)                                               (0x20000000&((data)<<29))
#define FAST_ISR_GPIO1_DA_int_59_src(data)                                           ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO1_DA_get_int_59(data)                                           ((0x20000000&(data))>>29)
#define FAST_ISR_GPIO1_DA_int_58_shift                                               (28)
#define FAST_ISR_GPIO1_DA_int_58_mask                                                (0x10000000)
#define FAST_ISR_GPIO1_DA_int_58(data)                                               (0x10000000&((data)<<28))
#define FAST_ISR_GPIO1_DA_int_58_src(data)                                           ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO1_DA_get_int_58(data)                                           ((0x10000000&(data))>>28)
#define FAST_ISR_GPIO1_DA_int_57_shift                                               (27)
#define FAST_ISR_GPIO1_DA_int_57_mask                                                (0x08000000)
#define FAST_ISR_GPIO1_DA_int_57(data)                                               (0x08000000&((data)<<27))
#define FAST_ISR_GPIO1_DA_int_57_src(data)                                           ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO1_DA_get_int_57(data)                                           ((0x08000000&(data))>>27)
#define FAST_ISR_GPIO1_DA_int_56_shift                                               (26)
#define FAST_ISR_GPIO1_DA_int_56_mask                                                (0x04000000)
#define FAST_ISR_GPIO1_DA_int_56(data)                                               (0x04000000&((data)<<26))
#define FAST_ISR_GPIO1_DA_int_56_src(data)                                           ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO1_DA_get_int_56(data)                                           ((0x04000000&(data))>>26)
#define FAST_ISR_GPIO1_DA_int_55_shift                                               (25)
#define FAST_ISR_GPIO1_DA_int_55_mask                                                (0x02000000)
#define FAST_ISR_GPIO1_DA_int_55(data)                                               (0x02000000&((data)<<25))
#define FAST_ISR_GPIO1_DA_int_55_src(data)                                           ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO1_DA_get_int_55(data)                                           ((0x02000000&(data))>>25)
#define FAST_ISR_GPIO1_DA_int_54_shift                                               (24)
#define FAST_ISR_GPIO1_DA_int_54_mask                                                (0x01000000)
#define FAST_ISR_GPIO1_DA_int_54(data)                                               (0x01000000&((data)<<24))
#define FAST_ISR_GPIO1_DA_int_54_src(data)                                           ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO1_DA_get_int_54(data)                                           ((0x01000000&(data))>>24)
#define FAST_ISR_GPIO1_DA_int_53_shift                                               (23)
#define FAST_ISR_GPIO1_DA_int_53_mask                                                (0x00800000)
#define FAST_ISR_GPIO1_DA_int_53(data)                                               (0x00800000&((data)<<23))
#define FAST_ISR_GPIO1_DA_int_53_src(data)                                           ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO1_DA_get_int_53(data)                                           ((0x00800000&(data))>>23)
#define FAST_ISR_GPIO1_DA_int_52_shift                                               (22)
#define FAST_ISR_GPIO1_DA_int_52_mask                                                (0x00400000)
#define FAST_ISR_GPIO1_DA_int_52(data)                                               (0x00400000&((data)<<22))
#define FAST_ISR_GPIO1_DA_int_52_src(data)                                           ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO1_DA_get_int_52(data)                                           ((0x00400000&(data))>>22)
#define FAST_ISR_GPIO1_DA_int_51_shift                                               (21)
#define FAST_ISR_GPIO1_DA_int_51_mask                                                (0x00200000)
#define FAST_ISR_GPIO1_DA_int_51(data)                                               (0x00200000&((data)<<21))
#define FAST_ISR_GPIO1_DA_int_51_src(data)                                           ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO1_DA_get_int_51(data)                                           ((0x00200000&(data))>>21)
#define FAST_ISR_GPIO1_DA_int_50_shift                                               (20)
#define FAST_ISR_GPIO1_DA_int_50_mask                                                (0x00100000)
#define FAST_ISR_GPIO1_DA_int_50(data)                                               (0x00100000&((data)<<20))
#define FAST_ISR_GPIO1_DA_int_50_src(data)                                           ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO1_DA_get_int_50(data)                                           ((0x00100000&(data))>>20)
#define FAST_ISR_GPIO1_DA_int_49_shift                                               (19)
#define FAST_ISR_GPIO1_DA_int_49_mask                                                (0x00080000)
#define FAST_ISR_GPIO1_DA_int_49(data)                                               (0x00080000&((data)<<19))
#define FAST_ISR_GPIO1_DA_int_49_src(data)                                           ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO1_DA_get_int_49(data)                                           ((0x00080000&(data))>>19)
#define FAST_ISR_GPIO1_DA_int_48_shift                                               (18)
#define FAST_ISR_GPIO1_DA_int_48_mask                                                (0x00040000)
#define FAST_ISR_GPIO1_DA_int_48(data)                                               (0x00040000&((data)<<18))
#define FAST_ISR_GPIO1_DA_int_48_src(data)                                           ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO1_DA_get_int_48(data)                                           ((0x00040000&(data))>>18)
#define FAST_ISR_GPIO1_DA_int_47_shift                                               (17)
#define FAST_ISR_GPIO1_DA_int_47_mask                                                (0x00020000)
#define FAST_ISR_GPIO1_DA_int_47(data)                                               (0x00020000&((data)<<17))
#define FAST_ISR_GPIO1_DA_int_47_src(data)                                           ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO1_DA_get_int_47(data)                                           ((0x00020000&(data))>>17)
#define FAST_ISR_GPIO1_DA_int_46_shift                                               (16)
#define FAST_ISR_GPIO1_DA_int_46_mask                                                (0x00010000)
#define FAST_ISR_GPIO1_DA_int_46(data)                                               (0x00010000&((data)<<16))
#define FAST_ISR_GPIO1_DA_int_46_src(data)                                           ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO1_DA_get_int_46(data)                                           ((0x00010000&(data))>>16)
#define FAST_ISR_GPIO1_DA_int_45_shift                                               (15)
#define FAST_ISR_GPIO1_DA_int_45_mask                                                (0x00008000)
#define FAST_ISR_GPIO1_DA_int_45(data)                                               (0x00008000&((data)<<15))
#define FAST_ISR_GPIO1_DA_int_45_src(data)                                           ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO1_DA_get_int_45(data)                                           ((0x00008000&(data))>>15)
#define FAST_ISR_GPIO1_DA_int_44_shift                                               (14)
#define FAST_ISR_GPIO1_DA_int_44_mask                                                (0x00004000)
#define FAST_ISR_GPIO1_DA_int_44(data)                                               (0x00004000&((data)<<14))
#define FAST_ISR_GPIO1_DA_int_44_src(data)                                           ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO1_DA_get_int_44(data)                                           ((0x00004000&(data))>>14)
#define FAST_ISR_GPIO1_DA_int_43_shift                                               (13)
#define FAST_ISR_GPIO1_DA_int_43_mask                                                (0x00002000)
#define FAST_ISR_GPIO1_DA_int_43(data)                                               (0x00002000&((data)<<13))
#define FAST_ISR_GPIO1_DA_int_43_src(data)                                           ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO1_DA_get_int_43(data)                                           ((0x00002000&(data))>>13)
#define FAST_ISR_GPIO1_DA_int_42_shift                                               (12)
#define FAST_ISR_GPIO1_DA_int_42_mask                                                (0x00001000)
#define FAST_ISR_GPIO1_DA_int_42(data)                                               (0x00001000&((data)<<12))
#define FAST_ISR_GPIO1_DA_int_42_src(data)                                           ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO1_DA_get_int_42(data)                                           ((0x00001000&(data))>>12)
#define FAST_ISR_GPIO1_DA_int_41_shift                                               (11)
#define FAST_ISR_GPIO1_DA_int_41_mask                                                (0x00000800)
#define FAST_ISR_GPIO1_DA_int_41(data)                                               (0x00000800&((data)<<11))
#define FAST_ISR_GPIO1_DA_int_41_src(data)                                           ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO1_DA_get_int_41(data)                                           ((0x00000800&(data))>>11)
#define FAST_ISR_GPIO1_DA_int_40_shift                                               (10)
#define FAST_ISR_GPIO1_DA_int_40_mask                                                (0x00000400)
#define FAST_ISR_GPIO1_DA_int_40(data)                                               (0x00000400&((data)<<10))
#define FAST_ISR_GPIO1_DA_int_40_src(data)                                           ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO1_DA_get_int_40(data)                                           ((0x00000400&(data))>>10)
#define FAST_ISR_GPIO1_DA_int_39_shift                                               (9)
#define FAST_ISR_GPIO1_DA_int_39_mask                                                (0x00000200)
#define FAST_ISR_GPIO1_DA_int_39(data)                                               (0x00000200&((data)<<9))
#define FAST_ISR_GPIO1_DA_int_39_src(data)                                           ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO1_DA_get_int_39(data)                                           ((0x00000200&(data))>>9)
#define FAST_ISR_GPIO1_DA_int_38_shift                                               (8)
#define FAST_ISR_GPIO1_DA_int_38_mask                                                (0x00000100)
#define FAST_ISR_GPIO1_DA_int_38(data)                                               (0x00000100&((data)<<8))
#define FAST_ISR_GPIO1_DA_int_38_src(data)                                           ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO1_DA_get_int_38(data)                                           ((0x00000100&(data))>>8)
#define FAST_ISR_GPIO1_DA_int_37_shift                                               (7)
#define FAST_ISR_GPIO1_DA_int_37_mask                                                (0x00000080)
#define FAST_ISR_GPIO1_DA_int_37(data)                                               (0x00000080&((data)<<7))
#define FAST_ISR_GPIO1_DA_int_37_src(data)                                           ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO1_DA_get_int_37(data)                                           ((0x00000080&(data))>>7)
#define FAST_ISR_GPIO1_DA_int_36_shift                                               (6)
#define FAST_ISR_GPIO1_DA_int_36_mask                                                (0x00000040)
#define FAST_ISR_GPIO1_DA_int_36(data)                                               (0x00000040&((data)<<6))
#define FAST_ISR_GPIO1_DA_int_36_src(data)                                           ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO1_DA_get_int_36(data)                                           ((0x00000040&(data))>>6)
#define FAST_ISR_GPIO1_DA_int_35_shift                                               (5)
#define FAST_ISR_GPIO1_DA_int_35_mask                                                (0x00000020)
#define FAST_ISR_GPIO1_DA_int_35(data)                                               (0x00000020&((data)<<5))
#define FAST_ISR_GPIO1_DA_int_35_src(data)                                           ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO1_DA_get_int_35(data)                                           ((0x00000020&(data))>>5)
#define FAST_ISR_GPIO1_DA_int_34_shift                                               (4)
#define FAST_ISR_GPIO1_DA_int_34_mask                                                (0x00000010)
#define FAST_ISR_GPIO1_DA_int_34(data)                                               (0x00000010&((data)<<4))
#define FAST_ISR_GPIO1_DA_int_34_src(data)                                           ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO1_DA_get_int_34(data)                                           ((0x00000010&(data))>>4)
#define FAST_ISR_GPIO1_DA_int_33_shift                                               (3)
#define FAST_ISR_GPIO1_DA_int_33_mask                                                (0x00000008)
#define FAST_ISR_GPIO1_DA_int_33(data)                                               (0x00000008&((data)<<3))
#define FAST_ISR_GPIO1_DA_int_33_src(data)                                           ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO1_DA_get_int_33(data)                                           ((0x00000008&(data))>>3)
#define FAST_ISR_GPIO1_DA_int_32_shift                                               (2)
#define FAST_ISR_GPIO1_DA_int_32_mask                                                (0x00000004)
#define FAST_ISR_GPIO1_DA_int_32(data)                                               (0x00000004&((data)<<2))
#define FAST_ISR_GPIO1_DA_int_32_src(data)                                           ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO1_DA_get_int_32(data)                                           ((0x00000004&(data))>>2)
#define FAST_ISR_GPIO1_DA_int_31_shift                                               (1)
#define FAST_ISR_GPIO1_DA_int_31_mask                                                (0x00000002)
#define FAST_ISR_GPIO1_DA_int_31(data)                                               (0x00000002&((data)<<1))
#define FAST_ISR_GPIO1_DA_int_31_src(data)                                           ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO1_DA_get_int_31(data)                                           ((0x00000002&(data))>>1)
#define FAST_ISR_GPIO1_DA_write_data_shift                                           (0)
#define FAST_ISR_GPIO1_DA_write_data_mask                                            (0x00000001)
#define FAST_ISR_GPIO1_DA_write_data(data)                                           (0x00000001&((data)<<0))
#define FAST_ISR_GPIO1_DA_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define FAST_ISR_GPIO1_DA_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define MISC_SCPU_INT_EN                                                                  0x1801B080
#define MISC_SCPU_INT_EN_reg_addr                                                         "0xB801B080"
#define MISC_SCPU_INT_EN_reg                                                              0xB801B080
#define MISC_set_SCPU_INT_EN_reg(data)   (*((volatile unsigned int*) SCPU_INT_EN_reg)=data)
#define MISC_get_SCPU_INT_EN_reg   (*((volatile unsigned int*) SCPU_INT_EN_reg))
#define MISC_SCPU_INT_EN_inst_adr                                                         "0x0020"
#define MISC_SCPU_INT_EN_inst                                                             0x0020
#define SCPU_INT_EN_I2C3_shift                                                       (28)
#define SCPU_INT_EN_I2C3_mask                                                        (0x10000000)
#define SCPU_INT_EN_I2C3(data)                                                       (0x10000000&((data)<<28))
#define SCPU_INT_EN_I2C3_src(data)                                                   ((0x10000000&(data))>>28)
#define SCPU_INT_EN_get_I2C3(data)                                                   ((0x10000000&(data))>>28)
#define SCPU_INT_EN_GSPI_shift                                                       (27)
#define SCPU_INT_EN_GSPI_mask                                                        (0x08000000)
#define SCPU_INT_EN_GSPI(data)                                                       (0x08000000&((data)<<27))
#define SCPU_INT_EN_GSPI_src(data)                                                   ((0x08000000&(data))>>27)
#define SCPU_INT_EN_get_GSPI(data)                                                   ((0x08000000&(data))>>27)
#define SCPU_INT_EN_I2C2_shift                                                       (26)
#define SCPU_INT_EN_I2C2_mask                                                        (0x04000000)
#define SCPU_INT_EN_I2C2(data)                                                       (0x04000000&((data)<<26))
#define SCPU_INT_EN_I2C2_src(data)                                                   ((0x04000000&(data))>>26)
#define SCPU_INT_EN_get_I2C2(data)                                                   ((0x04000000&(data))>>26)
#define SCPU_INT_EN_LSADC_shift                                                      (21)
#define SCPU_INT_EN_LSADC_mask                                                       (0x00200000)
#define SCPU_INT_EN_LSADC(data)                                                      (0x00200000&((data)<<21))
#define SCPU_INT_EN_LSADC_src(data)                                                  ((0x00200000&(data))>>21)
#define SCPU_INT_EN_get_LSADC(data)                                                  ((0x00200000&(data))>>21)
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
#define SCPU_INT_EN_I2C4_shift                                                       (15)
#define SCPU_INT_EN_I2C4_mask                                                        (0x00008000)
#define SCPU_INT_EN_I2C4(data)                                                       (0x00008000&((data)<<15))
#define SCPU_INT_EN_I2C4_src(data)                                                   ((0x00008000&(data))>>15)
#define SCPU_INT_EN_get_I2C4(data)                                                   ((0x00008000&(data))>>15)
#define SCPU_INT_EN_I2C5_shift                                                       (14)
#define SCPU_INT_EN_I2C5_mask                                                        (0x00004000)
#define SCPU_INT_EN_I2C5(data)                                                       (0x00004000&((data)<<14))
#define SCPU_INT_EN_I2C5_src(data)                                                   ((0x00004000&(data))>>14)
#define SCPU_INT_EN_get_I2C5(data)                                                   ((0x00004000&(data))>>14)
#define SCPU_INT_EN_RTC_DATE_shift                                                   (12)
#define SCPU_INT_EN_RTC_DATE_mask                                                    (0x00001000)
#define SCPU_INT_EN_RTC_DATE(data)                                                   (0x00001000&((data)<<12))
#define SCPU_INT_EN_RTC_DATE_src(data)                                               ((0x00001000&(data))>>12)
#define SCPU_INT_EN_get_RTC_DATE(data)                                               ((0x00001000&(data))>>12)
#define SCPU_INT_EN_RTC_HOUR_shift                                                   (11)
#define SCPU_INT_EN_RTC_HOUR_mask                                                    (0x00000800)
#define SCPU_INT_EN_RTC_HOUR(data)                                                   (0x00000800&((data)<<11))
#define SCPU_INT_EN_RTC_HOUR_src(data)                                               ((0x00000800&(data))>>11)
#define SCPU_INT_EN_get_RTC_HOUR(data)                                               ((0x00000800&(data))>>11)
#define SCPU_INT_EN_RTC_MIN_shift                                                    (10)
#define SCPU_INT_EN_RTC_MIN_mask                                                     (0x00000400)
#define SCPU_INT_EN_RTC_MIN(data)                                                    (0x00000400&((data)<<10))
#define SCPU_INT_EN_RTC_MIN_src(data)                                                ((0x00000400&(data))>>10)
#define SCPU_INT_EN_get_RTC_MIN(data)                                                ((0x00000400&(data))>>10)
#define SCPU_INT_EN_UR1_TO_shift                                                     (5)
#define SCPU_INT_EN_UR1_TO_mask                                                      (0x00000020)
#define SCPU_INT_EN_UR1_TO(data)                                                     (0x00000020&((data)<<5))
#define SCPU_INT_EN_UR1_TO_src(data)                                                 ((0x00000020&(data))>>5)
#define SCPU_INT_EN_get_UR1_TO(data)                                                 ((0x00000020&(data))>>5)
#define SCPU_INT_EN_I2C1_shift                                                       (4)
#define SCPU_INT_EN_I2C1_mask                                                        (0x00000010)
#define SCPU_INT_EN_I2C1(data)                                                       (0x00000010&((data)<<4))
#define SCPU_INT_EN_I2C1_src(data)                                                   ((0x00000010&(data))>>4)
#define SCPU_INT_EN_get_I2C1(data)                                                   ((0x00000010&(data))>>4)
#define SCPU_INT_EN_UR1_shift                                                        (3)
#define SCPU_INT_EN_UR1_mask                                                         (0x00000008)
#define SCPU_INT_EN_UR1(data)                                                        (0x00000008&((data)<<3))
#define SCPU_INT_EN_UR1_src(data)                                                    ((0x00000008&(data))>>3)
#define SCPU_INT_EN_get_UR1(data)                                                    ((0x00000008&(data))>>3)


#define I2C1_SDA_DEL                                                                 0x1801B088
#define I2C1_SDA_DEL_reg_addr                                                        "0xB801B088"
#define I2C1_SDA_DEL_reg                                                             0xB801B088
#define set_I2C1_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C1_SDA_DEL_reg)=data)
#define get_I2C1_SDA_DEL_reg   (*((volatile unsigned int*) I2C1_SDA_DEL_reg))
#define I2C1_SDA_DEL_inst_adr                                                        "0x0022"
#define I2C1_SDA_DEL_inst                                                            0x0022
#define I2C1_SDA_DEL_dmy1_shift                                                      (12)
#define I2C1_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C1_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C1_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C1_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C1_SDA_DEL_en_shift                                                        (8)
#define I2C1_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C1_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C1_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C1_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C1_SDA_DEL_sel_shift                                                       (0)
#define I2C1_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C1_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C1_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C1_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define I2C2_SDA_DEL                                                                 0x1801B08c
#define I2C2_SDA_DEL_reg_addr                                                        "0xB801B08C"
#define I2C2_SDA_DEL_reg                                                             0xB801B08C
#define set_I2C2_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C2_SDA_DEL_reg)=data)
#define get_I2C2_SDA_DEL_reg   (*((volatile unsigned int*) I2C2_SDA_DEL_reg))
#define I2C2_SDA_DEL_inst_adr                                                        "0x0023"
#define I2C2_SDA_DEL_inst                                                            0x0023
#define I2C2_SDA_DEL_dmy1_shift                                                      (12)
#define I2C2_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C2_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C2_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C2_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C2_SDA_DEL_en_shift                                                        (8)
#define I2C2_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C2_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C2_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C2_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C2_SDA_DEL_sel_shift                                                       (0)
#define I2C2_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C2_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C2_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C2_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define I2C3_SDA_DEL                                                                 0x1801B090
#define I2C3_SDA_DEL_reg_addr                                                        "0xB801B090"
#define I2C3_SDA_DEL_reg                                                             0xB801B090
#define set_I2C3_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C3_SDA_DEL_reg)=data)
#define get_I2C3_SDA_DEL_reg   (*((volatile unsigned int*) I2C3_SDA_DEL_reg))
#define I2C3_SDA_DEL_inst_adr                                                        "0x0024"
#define I2C3_SDA_DEL_inst                                                            0x0024
#define I2C3_SDA_DEL_dmy1_shift                                                      (12)
#define I2C3_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C3_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C3_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C3_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C3_SDA_DEL_en_shift                                                        (8)
#define I2C3_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C3_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C3_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C3_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C3_SDA_DEL_sel_shift                                                       (0)
#define I2C3_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C3_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C3_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C3_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define I2C4_SDA_DEL                                                                 0x1801B094
#define I2C4_SDA_DEL_reg_addr                                                        "0xB801B094"
#define I2C4_SDA_DEL_reg                                                             0xB801B094
#define set_I2C4_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C4_SDA_DEL_reg)=data)
#define get_I2C4_SDA_DEL_reg   (*((volatile unsigned int*) I2C4_SDA_DEL_reg))
#define I2C4_SDA_DEL_inst_adr                                                        "0x0025"
#define I2C4_SDA_DEL_inst                                                            0x0025
#define I2C4_SDA_DEL_dmy1_shift                                                      (12)
#define I2C4_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C4_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C4_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C4_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C4_SDA_DEL_en_shift                                                        (8)
#define I2C4_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C4_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C4_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C4_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C4_SDA_DEL_sel_shift                                                       (0)
#define I2C4_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C4_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C4_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C4_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define I2C5_SDA_DEL                                                                 0x1801B098
#define I2C5_SDA_DEL_reg_addr                                                        "0xB801B098"
#define I2C5_SDA_DEL_reg                                                             0xB801B098
#define set_I2C5_SDA_DEL_reg(data)   (*((volatile unsigned int*) I2C5_SDA_DEL_reg)=data)
#define get_I2C5_SDA_DEL_reg   (*((volatile unsigned int*) I2C5_SDA_DEL_reg))
#define I2C5_SDA_DEL_inst_adr                                                        "0x0026"
#define I2C5_SDA_DEL_inst                                                            0x0026
#define I2C5_SDA_DEL_dmy1_shift                                                      (12)
#define I2C5_SDA_DEL_dmy1_mask                                                       (0xFFFFF000)
#define I2C5_SDA_DEL_dmy1(data)                                                      (0xFFFFF000&((data)<<12))
#define I2C5_SDA_DEL_dmy1_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C5_SDA_DEL_get_dmy1(data)                                                  ((0xFFFFF000&(data))>>12)
#define I2C5_SDA_DEL_en_shift                                                        (8)
#define I2C5_SDA_DEL_en_mask                                                         (0x00000100)
#define I2C5_SDA_DEL_en(data)                                                        (0x00000100&((data)<<8))
#define I2C5_SDA_DEL_en_src(data)                                                    ((0x00000100&(data))>>8)
#define I2C5_SDA_DEL_get_en(data)                                                    ((0x00000100&(data))>>8)
#define I2C5_SDA_DEL_sel_shift                                                       (0)
#define I2C5_SDA_DEL_sel_mask                                                        (0x0000001F)
#define I2C5_SDA_DEL_sel(data)                                                       (0x0000001F&((data)<<0))
#define I2C5_SDA_DEL_sel_src(data)                                                   ((0x0000001F&(data))>>0)
#define I2C5_SDA_DEL_get_sel(data)                                                   ((0x0000001F&(data))>>0)


#define GP0DIR                                                                       0x1801B100
#define GP0DIR_reg_addr                                                              "0xB801B100"
#define GP0DIR_reg                                                                   0xB801B100
#define set_GP0DIR_reg(data)   (*((volatile unsigned int*) GP0DIR_reg)=data)
#define get_GP0DIR_reg   (*((volatile unsigned int*) GP0DIR_reg))
#define GP0DIR_inst_adr                                                              "0x0040"
#define GP0DIR_inst                                                                  0x0040
#define GP0DIR_GPDIR_shift                                                           (0)
#define GP0DIR_GPDIR_mask                                                            (0xFFFFFFFF)
#define GP0DIR_GPDIR(data)                                                           (0xFFFFFFFF&((data)<<0))
#define GP0DIR_GPDIR_src(data)                                                       ((0xFFFFFFFF&(data))>>0)
#define GP0DIR_get_GPDIR(data)                                                       ((0xFFFFFFFF&(data))>>0)


#define GP1DIR                                                                       0x1801B104
#define GP1DIR_reg_addr                                                              "0xB801B104"
#define GP1DIR_reg                                                                   0xB801B104
#define set_GP1DIR_reg(data)   (*((volatile unsigned int*) GP1DIR_reg)=data)
#define get_GP1DIR_reg   (*((volatile unsigned int*) GP1DIR_reg))
#define GP1DIR_inst_adr                                                              "0x0041"
#define GP1DIR_inst                                                                  0x0041
#define GP1DIR_GPDIR_shift                                                           (0)
#define GP1DIR_GPDIR_mask                                                            (0x0FFFFFFF)
#define GP1DIR_GPDIR(data)                                                           (0x0FFFFFFF&((data)<<0))
#define GP1DIR_GPDIR_src(data)                                                       ((0x0FFFFFFF&(data))>>0)
#define GP1DIR_get_GPDIR(data)                                                       ((0x0FFFFFFF&(data))>>0)


#define GP0DATO                                                                      0x1801B110
#define GP0DATO_reg_addr                                                             "0xB801B110"
#define GP0DATO_reg                                                                  0xB801B110
#define set_GP0DATO_reg(data)   (*((volatile unsigned int*) GP0DATO_reg)=data)
#define get_GP0DATO_reg   (*((volatile unsigned int*) GP0DATO_reg))
#define GP0DATO_inst_adr                                                             "0x0044"
#define GP0DATO_inst                                                                 0x0044
#define GP0DATO_GPDATO_shift                                                         (0)
#define GP0DATO_GPDATO_mask                                                          (0xFFFFFFFF)
#define GP0DATO_GPDATO(data)                                                         (0xFFFFFFFF&((data)<<0))
#define GP0DATO_GPDATO_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define GP0DATO_get_GPDATO(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define GP1DATO                                                                      0x1801B114
#define GP1DATO_reg_addr                                                             "0xB801B114"
#define GP1DATO_reg                                                                  0xB801B114
#define set_GP1DATO_reg(data)   (*((volatile unsigned int*) GP1DATO_reg)=data)
#define get_GP1DATO_reg   (*((volatile unsigned int*) GP1DATO_reg))
#define GP1DATO_inst_adr                                                             "0x0045"
#define GP1DATO_inst                                                                 0x0045
#define GP1DATO_GPDATO_shift                                                         (0)
#define GP1DATO_GPDATO_mask                                                          (0x0FFFFFFF)
#define GP1DATO_GPDATO(data)                                                         (0x0FFFFFFF&((data)<<0))
#define GP1DATO_GPDATO_src(data)                                                     ((0x0FFFFFFF&(data))>>0)
#define GP1DATO_get_GPDATO(data)                                                     ((0x0FFFFFFF&(data))>>0)


#define GP0DATI                                                                      0x1801B120
#define GP0DATI_reg_addr                                                             "0xB801B120"
#define GP0DATI_reg                                                                  0xB801B120
#define set_GP0DATI_reg(data)   (*((volatile unsigned int*) GP0DATI_reg)=data)
#define get_GP0DATI_reg   (*((volatile unsigned int*) GP0DATI_reg))
#define GP0DATI_inst_adr                                                             "0x0048"
#define GP0DATI_inst                                                                 0x0048
#define GP0DATI_GPDATI_shift                                                         (0)
#define GP0DATI_GPDATI_mask                                                          (0xFFFFFFFF)
#define GP0DATI_GPDATI(data)                                                         (0xFFFFFFFF&((data)<<0))
#define GP0DATI_GPDATI_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define GP0DATI_get_GPDATI(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define GP1DATI                                                                      0x1801B124
#define GP1DATI_reg_addr                                                             "0xB801B124"
#define GP1DATI_reg                                                                  0xB801B124
#define set_GP1DATI_reg(data)   (*((volatile unsigned int*) GP1DATI_reg)=data)
#define get_GP1DATI_reg   (*((volatile unsigned int*) GP1DATI_reg))
#define GP1DATI_inst_adr                                                             "0x0049"
#define GP1DATI_inst                                                                 0x0049
#define GP1DATI_GPDATI_shift                                                         (0)
#define GP1DATI_GPDATI_mask                                                          (0x0FFFFFFF)
#define GP1DATI_GPDATI(data)                                                         (0x0FFFFFFF&((data)<<0))
#define GP1DATI_GPDATI_src(data)                                                     ((0x0FFFFFFF&(data))>>0)
#define GP1DATI_get_GPDATI(data)                                                     ((0x0FFFFFFF&(data))>>0)


#define GP0IE                                                                        0x1801B130
#define GP0IE_reg_addr                                                               "0xB801B130"
#define GP0IE_reg                                                                    0xB801B130
#define set_GP0IE_reg(data)   (*((volatile unsigned int*) GP0IE_reg)=data)
#define get_GP0IE_reg   (*((volatile unsigned int*) GP0IE_reg))
#define GP0IE_inst_adr                                                               "0x004C"
#define GP0IE_inst                                                                   0x004C
#define GP0IE_GP_shift                                                               (0)
#define GP0IE_GP_mask                                                                (0xFFFFFFFF)
#define GP0IE_GP(data)                                                               (0xFFFFFFFF&((data)<<0))
#define GP0IE_GP_src(data)                                                           ((0xFFFFFFFF&(data))>>0)
#define GP0IE_get_GP(data)                                                           ((0xFFFFFFFF&(data))>>0)


#define GP1IE                                                                        0x1801B134
#define GP1IE_reg_addr                                                               "0xB801B134"
#define GP1IE_reg                                                                    0xB801B134
#define set_GP1IE_reg(data)   (*((volatile unsigned int*) GP1IE_reg)=data)
#define get_GP1IE_reg   (*((volatile unsigned int*) GP1IE_reg))
#define GP1IE_inst_adr                                                               "0x004D"
#define GP1IE_inst                                                                   0x004D
#define GP1IE_GP_shift                                                               (0)
#define GP1IE_GP_mask                                                                (0x0FFFFFFF)
#define GP1IE_GP(data)                                                               (0x0FFFFFFF&((data)<<0))
#define GP1IE_GP_src(data)                                                           ((0x0FFFFFFF&(data))>>0)
#define GP1IE_get_GP(data)                                                           ((0x0FFFFFFF&(data))>>0)


#define GP0DP                                                                        0x1801B140
#define GP0DP_reg_addr                                                               "0xB801B140"
#define GP0DP_reg                                                                    0xB801B140
#define set_GP0DP_reg(data)   (*((volatile unsigned int*) GP0DP_reg)=data)
#define get_GP0DP_reg   (*((volatile unsigned int*) GP0DP_reg))
#define GP0DP_inst_adr                                                               "0x0050"
#define GP0DP_inst                                                                   0x0050
#define GP0DP_GPHA_shift                                                             (0)
#define GP0DP_GPHA_mask                                                              (0xFFFFFFFF)
#define GP0DP_GPHA(data)                                                             (0xFFFFFFFF&((data)<<0))
#define GP0DP_GPHA_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define GP0DP_get_GPHA(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define GP1DP                                                                        0x1801B144
#define GP1DP_reg_addr                                                               "0xB801B144"
#define GP1DP_reg                                                                    0xB801B144
#define set_GP1DP_reg(data)   (*((volatile unsigned int*) GP1DP_reg)=data)
#define get_GP1DP_reg   (*((volatile unsigned int*) GP1DP_reg))
#define GP1DP_inst_adr                                                               "0x0051"
#define GP1DP_inst                                                                   0x0051
#define GP1DP_GPHA_shift                                                             (0)
#define GP1DP_GPHA_mask                                                              (0x0FFFFFFF)
#define GP1DP_GPHA(data)                                                             (0x0FFFFFFF&((data)<<0))
#define GP1DP_GPHA_src(data)                                                         ((0x0FFFFFFF&(data))>>0)
#define GP1DP_get_GPHA(data)                                                         ((0x0FFFFFFF&(data))>>0)


#define MISC_GPDEB                                                                        0x1801B150
#define MISC_GPDEB_reg_addr                                                               "0xB801B150"
#define MISC_GPDEB_reg                                                                    0xB801B150
#define MISC_set_GPDEB_reg(data)   (*((volatile unsigned int*) GPDEB_reg)=data)
#define MISC_get_GPDEB_reg   (*((volatile unsigned int*) GPDEB_reg))
#define MISC_GPDEB_inst_adr                                                               "0x0054"
#define MISC_GPDEB_inst                                                                   0x0054
#define MISC_GPDEB_write_enable4_shift                                                    (15)
#define MISC_GPDEB_write_enable4_mask                                                     (0x00008000)
#define MISC_GPDEB_write_enable4(data)                                                    (0x00008000&((data)<<15))
#define MISC_GPDEB_write_enable4_src(data)                                                ((0x00008000&(data))>>15)
#define MISC_GPDEB_get_write_enable4(data)                                                ((0x00008000&(data))>>15)
#define MISC_GPDEB_CLK4_shift                                                             (12)
#define MISC_GPDEB_CLK4_mask                                                              (0x00007000)
#define MISC_GPDEB_CLK4(data)                                                             (0x00007000&((data)<<12))
#define MISC_GPDEB_CLK4_src(data)                                                         ((0x00007000&(data))>>12)
#define MISC_GPDEB_get_CLK4(data)                                                         ((0x00007000&(data))>>12)
#define MISC_GPDEB_write_enable3_shift                                                    (11)
#define MISC_GPDEB_write_enable3_mask                                                     (0x00000800)
#define MISC_GPDEB_write_enable3(data)                                                    (0x00000800&((data)<<11))
#define MISC_GPDEB_write_enable3_src(data)                                                ((0x00000800&(data))>>11)
#define MISC_GPDEB_get_write_enable3(data)                                                ((0x00000800&(data))>>11)
#define MISC_GPDEB_CLK3_shift                                                             (8)
#define MISC_GPDEB_CLK3_mask                                                              (0x00000700)
#define MISC_GPDEB_CLK3(data)                                                             (0x00000700&((data)<<8))
#define MISC_GPDEB_CLK3_src(data)                                                         ((0x00000700&(data))>>8)
#define MISC_GPDEB_get_CLK3(data)                                                         ((0x00000700&(data))>>8)
#define MISC_GPDEB_write_enable2_shift                                                    (7)
#define MISC_GPDEB_write_enable2_mask                                                     (0x00000080)
#define MISC_GPDEB_write_enable2(data)                                                    (0x00000080&((data)<<7))
#define MISC_GPDEB_write_enable2_src(data)                                                ((0x00000080&(data))>>7)
#define MISC_GPDEB_get_write_enable2(data)                                                ((0x00000080&(data))>>7)
#define MISC_GPDEB_CLK2_shift                                                             (4)
#define MISC_GPDEB_CLK2_mask                                                              (0x00000070)
#define MISC_GPDEB_CLK2(data)                                                             (0x00000070&((data)<<4))
#define MISC_GPDEB_CLK2_src(data)                                                         ((0x00000070&(data))>>4)
#define MISC_GPDEB_get_CLK2(data)                                                         ((0x00000070&(data))>>4)
#define MISC_GPDEB_write_enable1_shift                                                    (3)
#define MISC_GPDEB_write_enable1_mask                                                     (0x00000008)
#define MISC_GPDEB_write_enable1(data)                                                    (0x00000008&((data)<<3))
#define MISC_GPDEB_write_enable1_src(data)                                                ((0x00000008&(data))>>3)
#define MISC_GPDEB_get_write_enable1(data)                                                ((0x00000008&(data))>>3)
#define MISC_GPDEB_CLK1_shift                                                             (0)
#define MISC_GPDEB_CLK1_mask                                                              (0x00000007)
#define MISC_GPDEB_CLK1(data)                                                             (0x00000007&((data)<<0))
#define MISC_GPDEB_CLK1_src(data)                                                         ((0x00000007&(data))>>0)
#define MISC_GPDEB_get_CLK1(data)                                                         ((0x00000007&(data))>>0)


#define U1RBR_THR_DLL                                                                0x1801B200
#define U1RBR_THR_DLL_reg_addr                                                       "0xB801B200"
#define U1RBR_THR_DLL_reg                                                            0xB801B200
#define set_U1RBR_THR_DLL_reg(data)   (*((volatile unsigned int*) U1RBR_THR_DLL_reg)=data)
#define get_U1RBR_THR_DLL_reg   (*((volatile unsigned int*) U1RBR_THR_DLL_reg))
#define U1RBR_THR_DLL_inst_adr                                                       "0x0080"
#define U1RBR_THR_DLL_inst                                                           0x0080
#define U1RBR_THR_DLL_DLL_shift                                                      (0)
#define U1RBR_THR_DLL_DLL_mask                                                       (0x000000FF)
#define U1RBR_THR_DLL_DLL(data)                                                      (0x000000FF&((data)<<0))
#define U1RBR_THR_DLL_DLL_src(data)                                                  ((0x000000FF&(data))>>0)
#define U1RBR_THR_DLL_get_DLL(data)                                                  ((0x000000FF&(data))>>0)


#define U1IER_DLH                                                                    0x1801B204
#define U1IER_DLH_reg_addr                                                           "0xB801B204"
#define U1IER_DLH_reg                                                                0xB801B204
#define set_U1IER_DLH_reg(data)   (*((volatile unsigned int*) U1IER_DLH_reg)=data)
#define get_U1IER_DLH_reg   (*((volatile unsigned int*) U1IER_DLH_reg))
#define U1IER_DLH_inst_adr                                                           "0x0081"
#define U1IER_DLH_inst                                                               0x0081
#define U1IER_DLH_DLH_shift                                                          (0)
#define U1IER_DLH_DLH_mask                                                           (0x000000FF)
#define U1IER_DLH_DLH(data)                                                          (0x000000FF&((data)<<0))
#define U1IER_DLH_DLH_src(data)                                                      ((0x000000FF&(data))>>0)
#define U1IER_DLH_get_DLH(data)                                                      ((0x000000FF&(data))>>0)


#define U1IIR_FCR                                                                    0x1801B208
#define U1IIR_FCR_reg_addr                                                           "0xB801B208"
#define U1IIR_FCR_reg                                                                0xB801B208
#define set_U1IIR_FCR_reg(data)   (*((volatile unsigned int*) U1IIR_FCR_reg)=data)
#define get_U1IIR_FCR_reg   (*((volatile unsigned int*) U1IIR_FCR_reg))
#define U1IIR_FCR_inst_adr                                                           "0x0082"
#define U1IIR_FCR_inst                                                               0x0082
#define U1IIR_FCR_FIFO16_shift                                                       (6)
#define U1IIR_FCR_FIFO16_mask                                                        (0x000000C0)
#define U1IIR_FCR_FIFO16(data)                                                       (0x000000C0&((data)<<6))
#define U1IIR_FCR_FIFO16_src(data)                                                   ((0x000000C0&(data))>>6)
#define U1IIR_FCR_get_FIFO16(data)                                                   ((0x000000C0&(data))>>6)
#define U1IIR_FCR_IID_shift                                                          (0)
#define U1IIR_FCR_IID_mask                                                           (0x0000000F)
#define U1IIR_FCR_IID(data)                                                          (0x0000000F&((data)<<0))
#define U1IIR_FCR_IID_src(data)                                                      ((0x0000000F&(data))>>0)
#define U1IIR_FCR_get_IID(data)                                                      ((0x0000000F&(data))>>0)


#define U1LCR                                                                        0x1801B20C
#define U1LCR_reg_addr                                                               "0xB801B20C"
#define U1LCR_reg                                                                    0xB801B20C
#define set_U1LCR_reg(data)   (*((volatile unsigned int*) U1LCR_reg)=data)
#define get_U1LCR_reg   (*((volatile unsigned int*) U1LCR_reg))
#define U1LCR_inst_adr                                                               "0x0083"
#define U1LCR_inst                                                                   0x0083
#define U1LCR_DLAB_shift                                                             (7)
#define U1LCR_DLAB_mask                                                              (0x00000080)
#define U1LCR_DLAB(data)                                                             (0x00000080&((data)<<7))
#define U1LCR_DLAB_src(data)                                                         ((0x00000080&(data))>>7)
#define U1LCR_get_DLAB(data)                                                         ((0x00000080&(data))>>7)
#define U1LCR_BRK_shift                                                              (6)
#define U1LCR_BRK_mask                                                               (0x00000040)
#define U1LCR_BRK(data)                                                              (0x00000040&((data)<<6))
#define U1LCR_BRK_src(data)                                                          ((0x00000040&(data))>>6)
#define U1LCR_get_BRK(data)                                                          ((0x00000040&(data))>>6)
#define U1LCR_EPS_shift                                                              (4)
#define U1LCR_EPS_mask                                                               (0x00000010)
#define U1LCR_EPS(data)                                                              (0x00000010&((data)<<4))
#define U1LCR_EPS_src(data)                                                          ((0x00000010&(data))>>4)
#define U1LCR_get_EPS(data)                                                          ((0x00000010&(data))>>4)
#define U1LCR_PEN_shift                                                              (3)
#define U1LCR_PEN_mask                                                               (0x00000008)
#define U1LCR_PEN(data)                                                              (0x00000008&((data)<<3))
#define U1LCR_PEN_src(data)                                                          ((0x00000008&(data))>>3)
#define U1LCR_get_PEN(data)                                                          ((0x00000008&(data))>>3)
#define U1LCR_STB_shift                                                              (2)
#define U1LCR_STB_mask                                                               (0x00000004)
#define U1LCR_STB(data)                                                              (0x00000004&((data)<<2))
#define U1LCR_STB_src(data)                                                          ((0x00000004&(data))>>2)
#define U1LCR_get_STB(data)                                                          ((0x00000004&(data))>>2)
#define U1LCR_WLS_shift                                                              (0)
#define U1LCR_WLS_mask                                                               (0x00000003)
#define U1LCR_WLS(data)                                                              (0x00000003&((data)<<0))
#define U1LCR_WLS_src(data)                                                          ((0x00000003&(data))>>0)
#define U1LCR_get_WLS(data)                                                          ((0x00000003&(data))>>0)


#define U1MCR                                                                        0x1801B210
#define U1MCR_reg_addr                                                               "0xB801B210"
#define U1MCR_reg                                                                    0xB801B210
#define set_U1MCR_reg(data)   (*((volatile unsigned int*) U1MCR_reg)=data)
#define get_U1MCR_reg   (*((volatile unsigned int*) U1MCR_reg))
#define U1MCR_inst_adr                                                               "0x0084"
#define U1MCR_inst                                                                   0x0084
#define U1MCR_AFCE_shift                                                             (5)
#define U1MCR_AFCE_mask                                                              (0x00000020)
#define U1MCR_AFCE(data)                                                             (0x00000020&((data)<<5))
#define U1MCR_AFCE_src(data)                                                         ((0x00000020&(data))>>5)
#define U1MCR_get_AFCE(data)                                                         ((0x00000020&(data))>>5)
#define U1MCR_LOOP_shift                                                             (4)
#define U1MCR_LOOP_mask                                                              (0x00000010)
#define U1MCR_LOOP(data)                                                             (0x00000010&((data)<<4))
#define U1MCR_LOOP_src(data)                                                         ((0x00000010&(data))>>4)
#define U1MCR_get_LOOP(data)                                                         ((0x00000010&(data))>>4)
#define U1MCR_RTS_shift                                                              (1)
#define U1MCR_RTS_mask                                                               (0x00000002)
#define U1MCR_RTS(data)                                                              (0x00000002&((data)<<1))
#define U1MCR_RTS_src(data)                                                          ((0x00000002&(data))>>1)
#define U1MCR_get_RTS(data)                                                          ((0x00000002&(data))>>1)
#define U1MCR_DTR_shift                                                              (0)
#define U1MCR_DTR_mask                                                               (0x00000001)
#define U1MCR_DTR(data)                                                              (0x00000001&((data)<<0))
#define U1MCR_DTR_src(data)                                                          ((0x00000001&(data))>>0)
#define U1MCR_get_DTR(data)                                                          ((0x00000001&(data))>>0)


#define U1LSR                                                                        0x1801B214
#define U1LSR_reg_addr                                                               "0xB801B214"
#define U1LSR_reg                                                                    0xB801B214
#define set_U1LSR_reg(data)   (*((volatile unsigned int*) U1LSR_reg)=data)
#define get_U1LSR_reg   (*((volatile unsigned int*) U1LSR_reg))
#define U1LSR_inst_adr                                                               "0x0085"
#define U1LSR_inst                                                                   0x0085
#define U1LSR_RFE_shift                                                              (7)
#define U1LSR_RFE_mask                                                               (0x00000080)
#define U1LSR_RFE(data)                                                              (0x00000080&((data)<<7))
#define U1LSR_RFE_src(data)                                                          ((0x00000080&(data))>>7)
#define U1LSR_get_RFE(data)                                                          ((0x00000080&(data))>>7)
#define U1LSR_TEMT_shift                                                             (6)
#define U1LSR_TEMT_mask                                                              (0x00000040)
#define U1LSR_TEMT(data)                                                             (0x00000040&((data)<<6))
#define U1LSR_TEMT_src(data)                                                         ((0x00000040&(data))>>6)
#define U1LSR_get_TEMT(data)                                                         ((0x00000040&(data))>>6)
#define U1LSR_THRE_shift                                                             (5)
#define U1LSR_THRE_mask                                                              (0x00000020)
#define U1LSR_THRE(data)                                                             (0x00000020&((data)<<5))
#define U1LSR_THRE_src(data)                                                         ((0x00000020&(data))>>5)
#define U1LSR_get_THRE(data)                                                         ((0x00000020&(data))>>5)
#define U1LSR_BI_shift                                                               (4)
#define U1LSR_BI_mask                                                                (0x00000010)
#define U1LSR_BI(data)                                                               (0x00000010&((data)<<4))
#define U1LSR_BI_src(data)                                                           ((0x00000010&(data))>>4)
#define U1LSR_get_BI(data)                                                           ((0x00000010&(data))>>4)
#define U1LSR_FE_shift                                                               (3)
#define U1LSR_FE_mask                                                                (0x00000008)
#define U1LSR_FE(data)                                                               (0x00000008&((data)<<3))
#define U1LSR_FE_src(data)                                                           ((0x00000008&(data))>>3)
#define U1LSR_get_FE(data)                                                           ((0x00000008&(data))>>3)
#define U1LSR_PE_shift                                                               (2)
#define U1LSR_PE_mask                                                                (0x00000004)
#define U1LSR_PE(data)                                                               (0x00000004&((data)<<2))
#define U1LSR_PE_src(data)                                                           ((0x00000004&(data))>>2)
#define U1LSR_get_PE(data)                                                           ((0x00000004&(data))>>2)
#define U1LSR_OE_shift                                                               (1)
#define U1LSR_OE_mask                                                                (0x00000002)
#define U1LSR_OE(data)                                                               (0x00000002&((data)<<1))
#define U1LSR_OE_src(data)                                                           ((0x00000002&(data))>>1)
#define U1LSR_get_OE(data)                                                           ((0x00000002&(data))>>1)
#define U1LSR_DR_shift                                                               (0)
#define U1LSR_DR_mask                                                                (0x00000001)
#define U1LSR_DR(data)                                                               (0x00000001&((data)<<0))
#define U1LSR_DR_src(data)                                                           ((0x00000001&(data))>>0)
#define U1LSR_get_DR(data)                                                           ((0x00000001&(data))>>0)


#define U1MSR                                                                        0x1801B218
#define U1MSR_reg_addr                                                               "0xB801B218"
#define U1MSR_reg                                                                    0xB801B218
#define set_U1MSR_reg(data)   (*((volatile unsigned int*) U1MSR_reg)=data)
#define get_U1MSR_reg   (*((volatile unsigned int*) U1MSR_reg))
#define U1MSR_inst_adr                                                               "0x0086"
#define U1MSR_inst                                                                   0x0086
#define U1MSR_DCD_shift                                                              (7)
#define U1MSR_DCD_mask                                                               (0x00000080)
#define U1MSR_DCD(data)                                                              (0x00000080&((data)<<7))
#define U1MSR_DCD_src(data)                                                          ((0x00000080&(data))>>7)
#define U1MSR_get_DCD(data)                                                          ((0x00000080&(data))>>7)
#define U1MSR_RI_shift                                                               (6)
#define U1MSR_RI_mask                                                                (0x00000040)
#define U1MSR_RI(data)                                                               (0x00000040&((data)<<6))
#define U1MSR_RI_src(data)                                                           ((0x00000040&(data))>>6)
#define U1MSR_get_RI(data)                                                           ((0x00000040&(data))>>6)
#define U1MSR_DSR_shift                                                              (5)
#define U1MSR_DSR_mask                                                               (0x00000020)
#define U1MSR_DSR(data)                                                              (0x00000020&((data)<<5))
#define U1MSR_DSR_src(data)                                                          ((0x00000020&(data))>>5)
#define U1MSR_get_DSR(data)                                                          ((0x00000020&(data))>>5)
#define U1MSR_CTS_shift                                                              (4)
#define U1MSR_CTS_mask                                                               (0x00000010)
#define U1MSR_CTS(data)                                                              (0x00000010&((data)<<4))
#define U1MSR_CTS_src(data)                                                          ((0x00000010&(data))>>4)
#define U1MSR_get_CTS(data)                                                          ((0x00000010&(data))>>4)
#define U1MSR_DDCD_shift                                                             (3)
#define U1MSR_DDCD_mask                                                              (0x00000008)
#define U1MSR_DDCD(data)                                                             (0x00000008&((data)<<3))
#define U1MSR_DDCD_src(data)                                                         ((0x00000008&(data))>>3)
#define U1MSR_get_DDCD(data)                                                         ((0x00000008&(data))>>3)
#define U1MSR_TERI_shift                                                             (2)
#define U1MSR_TERI_mask                                                              (0x00000004)
#define U1MSR_TERI(data)                                                             (0x00000004&((data)<<2))
#define U1MSR_TERI_src(data)                                                         ((0x00000004&(data))>>2)
#define U1MSR_get_TERI(data)                                                         ((0x00000004&(data))>>2)
#define U1MSR_DDSR_shift                                                             (1)
#define U1MSR_DDSR_mask                                                              (0x00000002)
#define U1MSR_DDSR(data)                                                             (0x00000002&((data)<<1))
#define U1MSR_DDSR_src(data)                                                         ((0x00000002&(data))>>1)
#define U1MSR_get_DDSR(data)                                                         ((0x00000002&(data))>>1)
#define U1MSR_DCTS_shift                                                             (0)
#define U1MSR_DCTS_mask                                                              (0x00000001)
#define U1MSR_DCTS(data)                                                             (0x00000001&((data)<<0))
#define U1MSR_DCTS_src(data)                                                         ((0x00000001&(data))>>0)
#define U1MSR_get_DCTS(data)                                                         ((0x00000001&(data))>>0)


#define U1SCR                                                                        0x1801B21C
#define U1SCR_reg_addr                                                               "0xB801B21C"
#define U1SCR_reg                                                                    0xB801B21C
#define set_U1SCR_reg(data)   (*((volatile unsigned int*) U1SCR_reg)=data)
#define get_U1SCR_reg   (*((volatile unsigned int*) U1SCR_reg))
#define U1SCR_inst_adr                                                               "0x0087"
#define U1SCR_inst                                                                   0x0087
#define U1SCR_SCR_shift                                                              (0)
#define U1SCR_SCR_mask                                                               (0x000000FF)
#define U1SCR_SCR(data)                                                              (0x000000FF&((data)<<0))
#define U1SCR_SCR_src(data)                                                          ((0x000000FF&(data))>>0)
#define U1SCR_get_SCR(data)                                                          ((0x000000FF&(data))>>0)


#define U1SRBR_0                                                                     0x1801B230
#define U1SRBR_1                                                                     0x1801B234
#define U1SRBR_2                                                                     0x1801B238
#define U1SRBR_3                                                                     0x1801B23C
#define U1SRBR_4                                                                     0x1801B240
#define U1SRBR_5                                                                     0x1801B244
#define U1SRBR_6                                                                     0x1801B248
#define U1SRBR_7                                                                     0x1801B24C
#define U1SRBR_8                                                                     0x1801B250
#define U1SRBR_9                                                                     0x1801B254
#define U1SRBR_10                                                                     0x1801B258
#define U1SRBR_11                                                                     0x1801B25C
#define U1SRBR_12                                                                     0x1801B260
#define U1SRBR_13                                                                     0x1801B264
#define U1SRBR_14                                                                     0x1801B268
#define U1SRBR_15                                                                     0x1801B26C
#define U1SRBR_0_reg_addr                                                            "0xB801B230"
#define U1SRBR_1_reg_addr                                                            "0xB801B234"
#define U1SRBR_2_reg_addr                                                            "0xB801B238"
#define U1SRBR_3_reg_addr                                                            "0xB801B23C"
#define U1SRBR_4_reg_addr                                                            "0xB801B240"
#define U1SRBR_5_reg_addr                                                            "0xB801B244"
#define U1SRBR_6_reg_addr                                                            "0xB801B248"
#define U1SRBR_7_reg_addr                                                            "0xB801B24C"
#define U1SRBR_8_reg_addr                                                            "0xB801B250"
#define U1SRBR_9_reg_addr                                                            "0xB801B254"
#define U1SRBR_10_reg_addr                                                            "0xB801B258"
#define U1SRBR_11_reg_addr                                                            "0xB801B25C"
#define U1SRBR_12_reg_addr                                                            "0xB801B260"
#define U1SRBR_13_reg_addr                                                            "0xB801B264"
#define U1SRBR_14_reg_addr                                                            "0xB801B268"
#define U1SRBR_15_reg_addr                                                            "0xB801B26C"
#define U1SRBR_0_reg                                                                 0xB801B230
#define U1SRBR_1_reg                                                                 0xB801B234
#define U1SRBR_2_reg                                                                 0xB801B238
#define U1SRBR_3_reg                                                                 0xB801B23C
#define U1SRBR_4_reg                                                                 0xB801B240
#define U1SRBR_5_reg                                                                 0xB801B244
#define U1SRBR_6_reg                                                                 0xB801B248
#define U1SRBR_7_reg                                                                 0xB801B24C
#define U1SRBR_8_reg                                                                 0xB801B250
#define U1SRBR_9_reg                                                                 0xB801B254
#define U1SRBR_10_reg                                                                 0xB801B258
#define U1SRBR_11_reg                                                                 0xB801B25C
#define U1SRBR_12_reg                                                                 0xB801B260
#define U1SRBR_13_reg                                                                 0xB801B264
#define U1SRBR_14_reg                                                                 0xB801B268
#define U1SRBR_15_reg                                                                 0xB801B26C
#define set_U1SRBR_0_reg(data)   (*((volatile unsigned int*) U1SRBR_0_reg)=data)
#define set_U1SRBR_1_reg(data)   (*((volatile unsigned int*) U1SRBR_1_reg)=data)
#define set_U1SRBR_2_reg(data)   (*((volatile unsigned int*) U1SRBR_2_reg)=data)
#define set_U1SRBR_3_reg(data)   (*((volatile unsigned int*) U1SRBR_3_reg)=data)
#define set_U1SRBR_4_reg(data)   (*((volatile unsigned int*) U1SRBR_4_reg)=data)
#define set_U1SRBR_5_reg(data)   (*((volatile unsigned int*) U1SRBR_5_reg)=data)
#define set_U1SRBR_6_reg(data)   (*((volatile unsigned int*) U1SRBR_6_reg)=data)
#define set_U1SRBR_7_reg(data)   (*((volatile unsigned int*) U1SRBR_7_reg)=data)
#define set_U1SRBR_8_reg(data)   (*((volatile unsigned int*) U1SRBR_8_reg)=data)
#define set_U1SRBR_9_reg(data)   (*((volatile unsigned int*) U1SRBR_9_reg)=data)
#define set_U1SRBR_10_reg(data)   (*((volatile unsigned int*) U1SRBR_10_reg)=data)
#define set_U1SRBR_11_reg(data)   (*((volatile unsigned int*) U1SRBR_11_reg)=data)
#define set_U1SRBR_12_reg(data)   (*((volatile unsigned int*) U1SRBR_12_reg)=data)
#define set_U1SRBR_13_reg(data)   (*((volatile unsigned int*) U1SRBR_13_reg)=data)
#define set_U1SRBR_14_reg(data)   (*((volatile unsigned int*) U1SRBR_14_reg)=data)
#define set_U1SRBR_15_reg(data)   (*((volatile unsigned int*) U1SRBR_15_reg)=data)
#define get_U1SRBR_0_reg   (*((volatile unsigned int*) U1SRBR_0_reg))
#define get_U1SRBR_1_reg   (*((volatile unsigned int*) U1SRBR_1_reg))
#define get_U1SRBR_2_reg   (*((volatile unsigned int*) U1SRBR_2_reg))
#define get_U1SRBR_3_reg   (*((volatile unsigned int*) U1SRBR_3_reg))
#define get_U1SRBR_4_reg   (*((volatile unsigned int*) U1SRBR_4_reg))
#define get_U1SRBR_5_reg   (*((volatile unsigned int*) U1SRBR_5_reg))
#define get_U1SRBR_6_reg   (*((volatile unsigned int*) U1SRBR_6_reg))
#define get_U1SRBR_7_reg   (*((volatile unsigned int*) U1SRBR_7_reg))
#define get_U1SRBR_8_reg   (*((volatile unsigned int*) U1SRBR_8_reg))
#define get_U1SRBR_9_reg   (*((volatile unsigned int*) U1SRBR_9_reg))
#define get_U1SRBR_10_reg   (*((volatile unsigned int*) U1SRBR_10_reg))
#define get_U1SRBR_11_reg   (*((volatile unsigned int*) U1SRBR_11_reg))
#define get_U1SRBR_12_reg   (*((volatile unsigned int*) U1SRBR_12_reg))
#define get_U1SRBR_13_reg   (*((volatile unsigned int*) U1SRBR_13_reg))
#define get_U1SRBR_14_reg   (*((volatile unsigned int*) U1SRBR_14_reg))
#define get_U1SRBR_15_reg   (*((volatile unsigned int*) U1SRBR_15_reg))
#define U1SRBR_0_inst_adr                                                            "0x008C"
#define U1SRBR_1_inst_adr                                                            "0x008D"
#define U1SRBR_2_inst_adr                                                            "0x008E"
#define U1SRBR_3_inst_adr                                                            "0x008F"
#define U1SRBR_4_inst_adr                                                            "0x0090"
#define U1SRBR_5_inst_adr                                                            "0x0091"
#define U1SRBR_6_inst_adr                                                            "0x0092"
#define U1SRBR_7_inst_adr                                                            "0x0093"
#define U1SRBR_8_inst_adr                                                            "0x0094"
#define U1SRBR_9_inst_adr                                                            "0x0095"
#define U1SRBR_10_inst_adr                                                            "0x0096"
#define U1SRBR_11_inst_adr                                                            "0x0097"
#define U1SRBR_12_inst_adr                                                            "0x0098"
#define U1SRBR_13_inst_adr                                                            "0x0099"
#define U1SRBR_14_inst_adr                                                            "0x009A"
#define U1SRBR_15_inst_adr                                                            "0x009B"
#define U1SRBR_0_inst                                                                0x008C
#define U1SRBR_1_inst                                                                0x008D
#define U1SRBR_2_inst                                                                0x008E
#define U1SRBR_3_inst                                                                0x008F
#define U1SRBR_4_inst                                                                0x0090
#define U1SRBR_5_inst                                                                0x0091
#define U1SRBR_6_inst                                                                0x0092
#define U1SRBR_7_inst                                                                0x0093
#define U1SRBR_8_inst                                                                0x0094
#define U1SRBR_9_inst                                                                0x0095
#define U1SRBR_10_inst                                                                0x0096
#define U1SRBR_11_inst                                                                0x0097
#define U1SRBR_12_inst                                                                0x0098
#define U1SRBR_13_inst                                                                0x0099
#define U1SRBR_14_inst                                                                0x009A
#define U1SRBR_15_inst                                                                0x009B
#define U1SRBR_RBD_shift                                                             (0)
#define U1SRBR_RBD_mask                                                              (0x000000FF)
#define U1SRBR_RBD(data)                                                             (0x000000FF&((data)<<0))
#define U1SRBR_RBD_src(data)                                                         ((0x000000FF&(data))>>0)
#define U1SRBR_get_RBD(data)                                                         ((0x000000FF&(data))>>0)


#define U1FAR                                                                        0x1801B270
#define U1FAR_reg_addr                                                               "0xB801B270"
#define U1FAR_reg                                                                    0xB801B270
#define set_U1FAR_reg(data)   (*((volatile unsigned int*) U1FAR_reg)=data)
#define get_U1FAR_reg   (*((volatile unsigned int*) U1FAR_reg))
#define U1FAR_inst_adr                                                               "0x009C"
#define U1FAR_inst                                                                   0x009C
#define U1FAR_FAR_shift                                                              (0)
#define U1FAR_FAR_mask                                                               (0x00000001)
#define U1FAR_FAR(data)                                                              (0x00000001&((data)<<0))
#define U1FAR_FAR_src(data)                                                          ((0x00000001&(data))>>0)
#define U1FAR_get_FAR(data)                                                          ((0x00000001&(data))>>0)


#define U1TFR                                                                        0x1801B274
#define U1TFR_reg_addr                                                               "0xB801B274"
#define U1TFR_reg                                                                    0xB801B274
#define set_U1TFR_reg(data)   (*((volatile unsigned int*) U1TFR_reg)=data)
#define get_U1TFR_reg   (*((volatile unsigned int*) U1TFR_reg))
#define U1TFR_inst_adr                                                               "0x009D"
#define U1TFR_inst                                                                   0x009D
#define U1TFR_FAR_shift                                                              (0)
#define U1TFR_FAR_mask                                                               (0x000000FF)
#define U1TFR_FAR(data)                                                              (0x000000FF&((data)<<0))
#define U1TFR_FAR_src(data)                                                          ((0x000000FF&(data))>>0)
#define U1TFR_get_FAR(data)                                                          ((0x000000FF&(data))>>0)


#define U1RFW                                                                        0x1801B278
#define U1RFW_reg_addr                                                               "0xB801B278"
#define U1RFW_reg                                                                    0xB801B278
#define set_U1RFW_reg(data)   (*((volatile unsigned int*) U1RFW_reg)=data)
#define get_U1RFW_reg   (*((volatile unsigned int*) U1RFW_reg))
#define U1RFW_inst_adr                                                               "0x009E"
#define U1RFW_inst                                                                   0x009E
#define U1RFW_RFFE_shift                                                             (9)
#define U1RFW_RFFE_mask                                                              (0x00000200)
#define U1RFW_RFFE(data)                                                             (0x00000200&((data)<<9))
#define U1RFW_RFFE_src(data)                                                         ((0x00000200&(data))>>9)
#define U1RFW_get_RFFE(data)                                                         ((0x00000200&(data))>>9)
#define U1RFW_RFPF_shift                                                             (8)
#define U1RFW_RFPF_mask                                                              (0x00000100)
#define U1RFW_RFPF(data)                                                             (0x00000100&((data)<<8))
#define U1RFW_RFPF_src(data)                                                         ((0x00000100&(data))>>8)
#define U1RFW_get_RFPF(data)                                                         ((0x00000100&(data))>>8)
#define U1RFW_RFWD_shift                                                             (0)
#define U1RFW_RFWD_mask                                                              (0x000000FF)
#define U1RFW_RFWD(data)                                                             (0x000000FF&((data)<<0))
#define U1RFW_RFWD_src(data)                                                         ((0x000000FF&(data))>>0)
#define U1RFW_get_RFWD(data)                                                         ((0x000000FF&(data))>>0)


#define U1USR                                                                        0x1801B27C
#define U1USR_reg_addr                                                               "0xB801B27C"
#define U1USR_reg                                                                    0xB801B27C
#define set_U1USR_reg(data)   (*((volatile unsigned int*) U1USR_reg)=data)
#define get_U1USR_reg   (*((volatile unsigned int*) U1USR_reg))
#define U1USR_inst_adr                                                               "0x009F"
#define U1USR_inst                                                                   0x009F
#define U1USR_RFF_shift                                                              (4)
#define U1USR_RFF_mask                                                               (0x00000010)
#define U1USR_RFF(data)                                                              (0x00000010&((data)<<4))
#define U1USR_RFF_src(data)                                                          ((0x00000010&(data))>>4)
#define U1USR_get_RFF(data)                                                          ((0x00000010&(data))>>4)
#define U1USR_RFNE_shift                                                             (3)
#define U1USR_RFNE_mask                                                              (0x00000008)
#define U1USR_RFNE(data)                                                             (0x00000008&((data)<<3))
#define U1USR_RFNE_src(data)                                                         ((0x00000008&(data))>>3)
#define U1USR_get_RFNE(data)                                                         ((0x00000008&(data))>>3)
#define U1USR_TFE_shift                                                              (2)
#define U1USR_TFE_mask                                                               (0x00000004)
#define U1USR_TFE(data)                                                              (0x00000004&((data)<<2))
#define U1USR_TFE_src(data)                                                          ((0x00000004&(data))>>2)
#define U1USR_get_TFE(data)                                                          ((0x00000004&(data))>>2)
#define U1USR_TFNF_shift                                                             (1)
#define U1USR_TFNF_mask                                                              (0x00000002)
#define U1USR_TFNF(data)                                                             (0x00000002&((data)<<1))
#define U1USR_TFNF_src(data)                                                         ((0x00000002&(data))>>1)
#define U1USR_get_TFNF(data)                                                         ((0x00000002&(data))>>1)
#define U1USR_BUSY_shift                                                             (0)
#define U1USR_BUSY_mask                                                              (0x00000001)
#define U1USR_BUSY(data)                                                             (0x00000001&((data)<<0))
#define U1USR_BUSY_src(data)                                                         ((0x00000001&(data))>>0)
#define U1USR_get_BUSY(data)                                                         ((0x00000001&(data))>>0)


#define U1TFL                                                                        0x1801B280
#define U1TFL_reg_addr                                                               "0xB801B280"
#define U1TFL_reg                                                                    0xB801B280
#define set_U1TFL_reg(data)   (*((volatile unsigned int*) U1TFL_reg)=data)
#define get_U1TFL_reg   (*((volatile unsigned int*) U1TFL_reg))
#define U1TFL_inst_adr                                                               "0x00A0"
#define U1TFL_inst                                                                   0x00A0
#define U1TFL_TFL_shift                                                              (0)
#define U1TFL_TFL_mask                                                               (0x000000FF)
#define U1TFL_TFL(data)                                                              (0x000000FF&((data)<<0))
#define U1TFL_TFL_src(data)                                                          ((0x000000FF&(data))>>0)
#define U1TFL_get_TFL(data)                                                          ((0x000000FF&(data))>>0)


#define U1RFL                                                                        0x1801B284
#define U1RFL_reg_addr                                                               "0xB801B284"
#define U1RFL_reg                                                                    0xB801B284
#define set_U1RFL_reg(data)   (*((volatile unsigned int*) U1RFL_reg)=data)
#define get_U1RFL_reg   (*((volatile unsigned int*) U1RFL_reg))
#define U1RFL_inst_adr                                                               "0x00A1"
#define U1RFL_inst                                                                   0x00A1
#define U1RFL_RFL_shift                                                              (0)
#define U1RFL_RFL_mask                                                               (0x000000FF)
#define U1RFL_RFL(data)                                                              (0x000000FF&((data)<<0))
#define U1RFL_RFL_src(data)                                                          ((0x000000FF&(data))>>0)
#define U1RFL_get_RFL(data)                                                          ((0x000000FF&(data))>>0)


#define U1SRR                                                                        0x1801B288
#define U1SRR_reg_addr                                                               "0xB801B288"
#define U1SRR_reg                                                                    0xB801B288
#define set_U1SRR_reg(data)   (*((volatile unsigned int*) U1SRR_reg)=data)
#define get_U1SRR_reg   (*((volatile unsigned int*) U1SRR_reg))
#define U1SRR_inst_adr                                                               "0x00A2"
#define U1SRR_inst                                                                   0x00A2
#define U1SRR_XFR_shift                                                              (2)
#define U1SRR_XFR_mask                                                               (0x00000004)
#define U1SRR_XFR(data)                                                              (0x00000004&((data)<<2))
#define U1SRR_XFR_src(data)                                                          ((0x00000004&(data))>>2)
#define U1SRR_get_XFR(data)                                                          ((0x00000004&(data))>>2)
#define U1SRR_RFR_shift                                                              (1)
#define U1SRR_RFR_mask                                                               (0x00000002)
#define U1SRR_RFR(data)                                                              (0x00000002&((data)<<1))
#define U1SRR_RFR_src(data)                                                          ((0x00000002&(data))>>1)
#define U1SRR_get_RFR(data)                                                          ((0x00000002&(data))>>1)
#define U1SRR_UR_shift                                                               (0)
#define U1SRR_UR_mask                                                                (0x00000001)
#define U1SRR_UR(data)                                                               (0x00000001&((data)<<0))
#define U1SRR_UR_src(data)                                                           ((0x00000001&(data))>>0)
#define U1SRR_get_UR(data)                                                           ((0x00000001&(data))>>0)


#define U1SBCR                                                                       0x1801B290
#define U1SBCR_reg_addr                                                              "0xB801B290"
#define U1SBCR_reg                                                                   0xB801B290
#define set_U1SBCR_reg(data)   (*((volatile unsigned int*) U1SBCR_reg)=data)
#define get_U1SBCR_reg   (*((volatile unsigned int*) U1SBCR_reg))
#define U1SBCR_inst_adr                                                              "0x00A4"
#define U1SBCR_inst                                                                  0x00A4
#define U1SBCR_SBCR_shift                                                            (0)
#define U1SBCR_SBCR_mask                                                             (0x00000001)
#define U1SBCR_SBCR(data)                                                            (0x00000001&((data)<<0))
#define U1SBCR_SBCR_src(data)                                                        ((0x00000001&(data))>>0)
#define U1SBCR_get_SBCR(data)                                                        ((0x00000001&(data))>>0)


#define U1SDMAM                                                                      0x1801B294
#define U1SDMAM_reg_addr                                                             "0xB801B294"
#define U1SDMAM_reg                                                                  0xB801B294
#define set_U1SDMAM_reg(data)   (*((volatile unsigned int*) U1SDMAM_reg)=data)
#define get_U1SDMAM_reg   (*((volatile unsigned int*) U1SDMAM_reg))
#define U1SDMAM_inst_adr                                                             "0x00A5"
#define U1SDMAM_inst                                                                 0x00A5
#define U1SDMAM_SDMAM_shift                                                          (0)
#define U1SDMAM_SDMAM_mask                                                           (0x00000001)
#define U1SDMAM_SDMAM(data)                                                          (0x00000001&((data)<<0))
#define U1SDMAM_SDMAM_src(data)                                                      ((0x00000001&(data))>>0)
#define U1SDMAM_get_SDMAM(data)                                                      ((0x00000001&(data))>>0)


#define U1SFE                                                                        0x1801B298
#define U1SFE_reg_addr                                                               "0xB801B298"
#define U1SFE_reg                                                                    0xB801B298
#define set_U1SFE_reg(data)   (*((volatile unsigned int*) U1SFE_reg)=data)
#define get_U1SFE_reg   (*((volatile unsigned int*) U1SFE_reg))
#define U1SFE_inst_adr                                                               "0x00A6"
#define U1SFE_inst                                                                   0x00A6
#define U1SFE_SFE_shift                                                              (0)
#define U1SFE_SFE_mask                                                               (0x00000001)
#define U1SFE_SFE(data)                                                              (0x00000001&((data)<<0))
#define U1SFE_SFE_src(data)                                                          ((0x00000001&(data))>>0)
#define U1SFE_get_SFE(data)                                                          ((0x00000001&(data))>>0)


#define U1SRT                                                                        0x1801B29C
#define U1SRT_reg_addr                                                               "0xB801B29C"
#define U1SRT_reg                                                                    0xB801B29C
#define set_U1SRT_reg(data)   (*((volatile unsigned int*) U1SRT_reg)=data)
#define get_U1SRT_reg   (*((volatile unsigned int*) U1SRT_reg))
#define U1SRT_inst_adr                                                               "0x00A7"
#define U1SRT_inst                                                                   0x00A7
#define U1SRT_SRT_shift                                                              (0)
#define U1SRT_SRT_mask                                                               (0x00000003)
#define U1SRT_SRT(data)                                                              (0x00000003&((data)<<0))
#define U1SRT_SRT_src(data)                                                          ((0x00000003&(data))>>0)
#define U1SRT_get_SRT(data)                                                          ((0x00000003&(data))>>0)


#define U1STET                                                                       0x1801B2A0
#define U1STET_reg_addr                                                              "0xB801B2A0"
#define U1STET_reg                                                                   0xB801B2A0
#define set_U1STET_reg(data)   (*((volatile unsigned int*) U1STET_reg)=data)
#define get_U1STET_reg   (*((volatile unsigned int*) U1STET_reg))
#define U1STET_inst_adr                                                              "0x00A8"
#define U1STET_inst                                                                  0x00A8
#define U1STET_STET_shift                                                            (0)
#define U1STET_STET_mask                                                             (0x00000003)
#define U1STET_STET(data)                                                            (0x00000003&((data)<<0))
#define U1STET_STET_src(data)                                                        ((0x00000003&(data))>>0)
#define U1STET_get_STET(data)                                                        ((0x00000003&(data))>>0)


#define U1HTX                                                                        0x1801B2A4
#define U1HTX_reg_addr                                                               "0xB801B2A4"
#define U1HTX_reg                                                                    0xB801B2A4
#define set_U1HTX_reg(data)   (*((volatile unsigned int*) U1HTX_reg)=data)
#define get_U1HTX_reg   (*((volatile unsigned int*) U1HTX_reg))
#define U1HTX_inst_adr                                                               "0x00A9"
#define U1HTX_inst                                                                   0x00A9
#define U1HTX_HTX_shift                                                              (0)
#define U1HTX_HTX_mask                                                               (0x00000001)
#define U1HTX_HTX(data)                                                              (0x00000001&((data)<<0))
#define U1HTX_HTX_src(data)                                                          ((0x00000001&(data))>>0)
#define U1HTX_get_HTX(data)                                                          ((0x00000001&(data))>>0)


#define U1DMASA                                                                      0x1801B2A8
#define U1DMASA_reg_addr                                                             "0xB801B2A8"
#define U1DMASA_reg                                                                  0xB801B2A8
#define set_U1DMASA_reg(data)   (*((volatile unsigned int*) U1DMASA_reg)=data)
#define get_U1DMASA_reg   (*((volatile unsigned int*) U1DMASA_reg))
#define U1DMASA_inst_adr                                                             "0x00AA"
#define U1DMASA_inst                                                                 0x00AA
#define U1DMASA_DMASA_shift                                                          (0)
#define U1DMASA_DMASA_mask                                                           (0x00000001)
#define U1DMASA_DMASA(data)                                                          (0x00000001&((data)<<0))
#define U1DMASA_DMASA_src(data)                                                      ((0x00000001&(data))>>0)
#define U1DMASA_get_DMASA(data)                                                      ((0x00000001&(data))>>0)


#define U1CPR                                                                        0x1801B2F4
#define U1CPR_reg_addr                                                               "0xB801B2F4"
#define U1CPR_reg                                                                    0xB801B2F4
#define set_U1CPR_reg(data)   (*((volatile unsigned int*) U1CPR_reg)=data)
#define get_U1CPR_reg   (*((volatile unsigned int*) U1CPR_reg))
#define U1CPR_inst_adr                                                               "0x00BD"
#define U1CPR_inst                                                                   0x00BD
#define U1CPR_FIFO_MODE_shift                                                        (16)
#define U1CPR_FIFO_MODE_mask                                                         (0x00FF0000)
#define U1CPR_FIFO_MODE(data)                                                        (0x00FF0000&((data)<<16))
#define U1CPR_FIFO_MODE_src(data)                                                    ((0x00FF0000&(data))>>16)
#define U1CPR_get_FIFO_MODE(data)                                                    ((0x00FF0000&(data))>>16)
#define U1CPR_DMA_EXTRA_shift                                                        (13)
#define U1CPR_DMA_EXTRA_mask                                                         (0x00002000)
#define U1CPR_DMA_EXTRA(data)                                                        (0x00002000&((data)<<13))
#define U1CPR_DMA_EXTRA_src(data)                                                    ((0x00002000&(data))>>13)
#define U1CPR_get_DMA_EXTRA(data)                                                    ((0x00002000&(data))>>13)
#define U1CPR_UART_ADD_ENCODED_PARAMS_shift                                          (12)
#define U1CPR_UART_ADD_ENCODED_PARAMS_mask                                           (0x00001000)
#define U1CPR_UART_ADD_ENCODED_PARAMS(data)                                          (0x00001000&((data)<<12))
#define U1CPR_UART_ADD_ENCODED_PARAMS_src(data)                                      ((0x00001000&(data))>>12)
#define U1CPR_get_UART_ADD_ENCODED_PARAMS(data)                                      ((0x00001000&(data))>>12)
#define U1CPR_SHADOW_shift                                                           (11)
#define U1CPR_SHADOW_mask                                                            (0x00000800)
#define U1CPR_SHADOW(data)                                                           (0x00000800&((data)<<11))
#define U1CPR_SHADOW_src(data)                                                       ((0x00000800&(data))>>11)
#define U1CPR_get_SHADOW(data)                                                       ((0x00000800&(data))>>11)
#define U1CPR_FIFO_STAT_shift                                                        (10)
#define U1CPR_FIFO_STAT_mask                                                         (0x00000400)
#define U1CPR_FIFO_STAT(data)                                                        (0x00000400&((data)<<10))
#define U1CPR_FIFO_STAT_src(data)                                                    ((0x00000400&(data))>>10)
#define U1CPR_get_FIFO_STAT(data)                                                    ((0x00000400&(data))>>10)
#define U1CPR_FIFO_ACCESS_shift                                                      (9)
#define U1CPR_FIFO_ACCESS_mask                                                       (0x00000200)
#define U1CPR_FIFO_ACCESS(data)                                                      (0x00000200&((data)<<9))
#define U1CPR_FIFO_ACCESS_src(data)                                                  ((0x00000200&(data))>>9)
#define U1CPR_get_FIFO_ACCESS(data)                                                  ((0x00000200&(data))>>9)
#define U1CPR_ADDITIONAL_FEAT_shift                                                  (8)
#define U1CPR_ADDITIONAL_FEAT_mask                                                   (0x00000100)
#define U1CPR_ADDITIONAL_FEAT(data)                                                  (0x00000100&((data)<<8))
#define U1CPR_ADDITIONAL_FEAT_src(data)                                              ((0x00000100&(data))>>8)
#define U1CPR_get_ADDITIONAL_FEAT(data)                                              ((0x00000100&(data))>>8)
#define U1CPR_SIR_LP_MODE_shift                                                      (7)
#define U1CPR_SIR_LP_MODE_mask                                                       (0x00000080)
#define U1CPR_SIR_LP_MODE(data)                                                      (0x00000080&((data)<<7))
#define U1CPR_SIR_LP_MODE_src(data)                                                  ((0x00000080&(data))>>7)
#define U1CPR_get_SIR_LP_MODE(data)                                                  ((0x00000080&(data))>>7)
#define U1CPR_SIR_MODE_shift                                                         (6)
#define U1CPR_SIR_MODE_mask                                                          (0x00000040)
#define U1CPR_SIR_MODE(data)                                                         (0x00000040&((data)<<6))
#define U1CPR_SIR_MODE_src(data)                                                     ((0x00000040&(data))>>6)
#define U1CPR_get_SIR_MODE(data)                                                     ((0x00000040&(data))>>6)
#define U1CPR_THRE_MODE_shift                                                        (5)
#define U1CPR_THRE_MODE_mask                                                         (0x00000020)
#define U1CPR_THRE_MODE(data)                                                        (0x00000020&((data)<<5))
#define U1CPR_THRE_MODE_src(data)                                                    ((0x00000020&(data))>>5)
#define U1CPR_get_THRE_MODE(data)                                                    ((0x00000020&(data))>>5)
#define U1CPR_AFCE_MODE_shift                                                        (4)
#define U1CPR_AFCE_MODE_mask                                                         (0x00000010)
#define U1CPR_AFCE_MODE(data)                                                        (0x00000010&((data)<<4))
#define U1CPR_AFCE_MODE_src(data)                                                    ((0x00000010&(data))>>4)
#define U1CPR_get_AFCE_MODE(data)                                                    ((0x00000010&(data))>>4)
#define U1CPR_APB_DATA_WIDTH_shift                                                   (0)
#define U1CPR_APB_DATA_WIDTH_mask                                                    (0x00000003)
#define U1CPR_APB_DATA_WIDTH(data)                                                   (0x00000003&((data)<<0))
#define U1CPR_APB_DATA_WIDTH_src(data)                                               ((0x00000003&(data))>>0)
#define U1CPR_get_APB_DATA_WIDTH(data)                                               ((0x00000003&(data))>>0)


#define U1UCV                                                                        0x1801B2F8
#define U1UCV_reg_addr                                                               "0xB801B2F8"
#define U1UCV_reg                                                                    0xB801B2F8
#define set_U1UCV_reg(data)   (*((volatile unsigned int*) U1UCV_reg)=data)
#define get_U1UCV_reg   (*((volatile unsigned int*) U1UCV_reg))
#define U1UCV_inst_adr                                                               "0x00BE"
#define U1UCV_inst                                                                   0x00BE
#define U1UCV_UCV_shift                                                              (0)
#define U1UCV_UCV_mask                                                               (0xFFFFFFFF)
#define U1UCV_UCV(data)                                                              (0xFFFFFFFF&((data)<<0))
#define U1UCV_UCV_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define U1UCV_get_UCV(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define U1CTR                                                                        0x1801B2FC
#define U1CTR_reg_addr                                                               "0xB801B2FC"
#define U1CTR_reg                                                                    0xB801B2FC
#define set_U1CTR_reg(data)   (*((volatile unsigned int*) U1CTR_reg)=data)
#define get_U1CTR_reg   (*((volatile unsigned int*) U1CTR_reg))
#define U1CTR_inst_adr                                                               "0x00BF"
#define U1CTR_inst                                                                   0x00BF
#define U1CTR_CTR_shift                                                              (0)
#define U1CTR_CTR_mask                                                               (0xFFFFFFFF)
#define U1CTR_CTR(data)                                                              (0xFFFFFFFF&((data)<<0))
#define U1CTR_CTR_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define U1CTR_get_CTR(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define IC1_CON                                                                      0x1801B300
#define IC1_CON_reg_addr                                                             "0xB801B300"
#define IC1_CON_reg                                                                  0xB801B300
#define set_IC1_CON_reg(data)   (*((volatile unsigned int*) IC1_CON_reg)=data)
#define get_IC1_CON_reg   (*((volatile unsigned int*) IC1_CON_reg))
#define IC1_CON_inst_adr                                                             "0x00C0"
#define IC1_CON_inst                                                                 0x00C0
#define IC1_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC1_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC1_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC1_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC1_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC1_CON_IC_RESTART_EN_shift                                                  (5)
#define IC1_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC1_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC1_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC1_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC1_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC1_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC1_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC1_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC1_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC1_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC1_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC1_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC1_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC1_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC1_CON_SPEED_shift                                                          (1)
#define IC1_CON_SPEED_mask                                                           (0x00000006)
#define IC1_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC1_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC1_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC1_CON_MASTER_MODE_shift                                                    (0)
#define IC1_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC1_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC1_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC1_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC1_TAR                                                                      0x1801B304
#define IC1_TAR_reg_addr                                                             "0xB801B304"
#define IC1_TAR_reg                                                                  0xB801B304
#define set_IC1_TAR_reg(data)   (*((volatile unsigned int*) IC1_TAR_reg)=data)
#define get_IC1_TAR_reg   (*((volatile unsigned int*) IC1_TAR_reg))
#define IC1_TAR_inst_adr                                                             "0x00C1"
#define IC1_TAR_inst                                                                 0x00C1
#define IC1_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC1_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC1_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC1_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC1_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC1_TAR_SPECIAL_shift                                                        (11)
#define IC1_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC1_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC1_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC1_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC1_TAR_GC_OR_START_shift                                                    (10)
#define IC1_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC1_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC1_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC1_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC1_TAR_IC_TAR_shift                                                         (0)
#define IC1_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC1_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC1_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC1_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC1_SAR                                                                      0x1801B308
#define IC1_SAR_reg_addr                                                             "0xB801B308"
#define IC1_SAR_reg                                                                  0xB801B308
#define set_IC1_SAR_reg(data)   (*((volatile unsigned int*) IC1_SAR_reg)=data)
#define get_IC1_SAR_reg   (*((volatile unsigned int*) IC1_SAR_reg))
#define IC1_SAR_inst_adr                                                             "0x00C2"
#define IC1_SAR_inst                                                                 0x00C2
#define IC1_SAR_IC_SAR_shift                                                         (0)
#define IC1_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC1_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC1_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC1_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC1_HS_MADDR                                                                 0x1801B30C
#define IC1_HS_MADDR_reg_addr                                                        "0xB801B30C"
#define IC1_HS_MADDR_reg                                                             0xB801B30C
#define set_IC1_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC1_HS_MADDR_reg)=data)
#define get_IC1_HS_MADDR_reg   (*((volatile unsigned int*) IC1_HS_MADDR_reg))
#define IC1_HS_MADDR_inst_adr                                                        "0x00C3"
#define IC1_HS_MADDR_inst                                                            0x00C3
#define IC1_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC1_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC1_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC1_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC1_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC1_DATA_CMD                                                                 0x1801B310
#define IC1_DATA_CMD_reg_addr                                                        "0xB801B310"
#define IC1_DATA_CMD_reg                                                             0xB801B310
#define set_IC1_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC1_DATA_CMD_reg)=data)
#define get_IC1_DATA_CMD_reg   (*((volatile unsigned int*) IC1_DATA_CMD_reg))
#define IC1_DATA_CMD_inst_adr                                                        "0x00C4"
#define IC1_DATA_CMD_inst                                                            0x00C4
#define IC1_DATA_CMD_RESTART_shift                                                   (10)
#define IC1_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC1_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC1_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC1_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC1_DATA_CMD_STOP_shift                                                      (9)
#define IC1_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC1_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC1_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC1_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC1_DATA_CMD_CMD_shift                                                       (8)
#define IC1_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC1_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC1_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC1_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC1_DATA_CMD_DAT_shift                                                       (0)
#define IC1_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC1_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC1_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC1_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC1_SS_SCL_HCNT                                                              0x1801B314
#define IC1_SS_SCL_HCNT_reg_addr                                                     "0xB801B314"
#define IC1_SS_SCL_HCNT_reg                                                          0xB801B314
#define set_IC1_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC1_SS_SCL_HCNT_reg)=data)
#define get_IC1_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC1_SS_SCL_HCNT_reg))
#define IC1_SS_SCL_HCNT_inst_adr                                                     "0x00C5"
#define IC1_SS_SCL_HCNT_inst                                                         0x00C5
#define IC1_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC1_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC1_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC1_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC1_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC1_SS_SCL_LCNT                                                              0x1801B318
#define IC1_SS_SCL_LCNT_reg_addr                                                     "0xB801B318"
#define IC1_SS_SCL_LCNT_reg                                                          0xB801B318
#define set_IC1_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC1_SS_SCL_LCNT_reg)=data)
#define get_IC1_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC1_SS_SCL_LCNT_reg))
#define IC1_SS_SCL_LCNT_inst_adr                                                     "0x00C6"
#define IC1_SS_SCL_LCNT_inst                                                         0x00C6
#define IC1_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC1_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC1_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC1_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC1_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC1_FS_SCL_HCNT                                                              0x1801B31C
#define IC1_FS_SCL_HCNT_reg_addr                                                     "0xB801B31C"
#define IC1_FS_SCL_HCNT_reg                                                          0xB801B31C
#define set_IC1_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC1_FS_SCL_HCNT_reg)=data)
#define get_IC1_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC1_FS_SCL_HCNT_reg))
#define IC1_FS_SCL_HCNT_inst_adr                                                     "0x00C7"
#define IC1_FS_SCL_HCNT_inst                                                         0x00C7
#define IC1_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC1_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC1_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC1_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC1_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC1_FS_SCL_LCNT                                                              0x1801B320
#define IC1_FS_SCL_LCNT_reg_addr                                                     "0xB801B320"
#define IC1_FS_SCL_LCNT_reg                                                          0xB801B320
#define set_IC1_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC1_FS_SCL_LCNT_reg)=data)
#define get_IC1_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC1_FS_SCL_LCNT_reg))
#define IC1_FS_SCL_LCNT_inst_adr                                                     "0x00C8"
#define IC1_FS_SCL_LCNT_inst                                                         0x00C8
#define IC1_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC1_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC1_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC1_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC1_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC1_INTR_STAT                                                                0x1801B32C
#define IC1_INTR_STAT_reg_addr                                                       "0xB801B32C"
#define IC1_INTR_STAT_reg                                                            0xB801B32C
#define set_IC1_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC1_INTR_STAT_reg)=data)
#define get_IC1_INTR_STAT_reg   (*((volatile unsigned int*) IC1_INTR_STAT_reg))
#define IC1_INTR_STAT_inst_adr                                                       "0x00CB"
#define IC1_INTR_STAT_inst                                                           0x00CB
#define IC1_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC1_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC1_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC1_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC1_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC1_INTR_STAT_R_START_DET_shift                                              (10)
#define IC1_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC1_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC1_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC1_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC1_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC1_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC1_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC1_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC1_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC1_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC1_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC1_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC1_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC1_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC1_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC1_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC1_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC1_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC1_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC1_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC1_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC1_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC1_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC1_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC1_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC1_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC1_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC1_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC1_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC1_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC1_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC1_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC1_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC1_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC1_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC1_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC1_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC1_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC1_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC1_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC1_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC1_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC1_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC1_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC1_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC1_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC1_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC1_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC1_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC1_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC1_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC1_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC1_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC1_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC1_INTR_MASK                                                                0x1801B330
#define IC1_INTR_MASK_reg_addr                                                       "0xB801B330"
#define IC1_INTR_MASK_reg                                                            0xB801B330
#define set_IC1_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC1_INTR_MASK_reg)=data)
#define get_IC1_INTR_MASK_reg   (*((volatile unsigned int*) IC1_INTR_MASK_reg))
#define IC1_INTR_MASK_inst_adr                                                       "0x00CC"
#define IC1_INTR_MASK_inst                                                           0x00CC
#define IC1_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC1_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC1_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC1_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC1_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC1_INTR_MASK_M_START_DET_shift                                              (10)
#define IC1_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC1_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC1_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC1_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC1_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC1_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC1_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC1_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC1_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC1_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC1_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC1_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC1_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC1_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC1_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC1_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC1_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC1_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC1_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC1_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC1_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC1_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC1_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC1_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC1_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC1_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC1_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC1_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC1_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC1_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC1_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC1_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC1_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC1_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC1_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC1_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC1_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC1_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC1_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC1_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC1_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC1_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC1_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC1_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC1_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC1_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC1_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC1_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC1_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC1_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC1_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC1_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC1_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC1_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC1_RAW_INTR_STAT                                                            0x1801B334
#define IC1_RAW_INTR_STAT_reg_addr                                                   "0xB801B334"
#define IC1_RAW_INTR_STAT_reg                                                        0xB801B334
#define set_IC1_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC1_RAW_INTR_STAT_reg)=data)
#define get_IC1_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC1_RAW_INTR_STAT_reg))
#define IC1_RAW_INTR_STAT_inst_adr                                                   "0x00CD"
#define IC1_RAW_INTR_STAT_inst                                                       0x00CD
#define IC1_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC1_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC1_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC1_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC1_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC1_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC1_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC1_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC1_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC1_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC1_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC1_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC1_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC1_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC1_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC1_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC1_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC1_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC1_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC1_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC1_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC1_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC1_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC1_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC1_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC1_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC1_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC1_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC1_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC1_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC1_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC1_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC1_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC1_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC1_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC1_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC1_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC1_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC1_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC1_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC1_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC1_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC1_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC1_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC1_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC1_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC1_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC1_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC1_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC1_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC1_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC1_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC1_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC1_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC1_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC1_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC1_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC1_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC1_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC1_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC1_RX_TL                                                                    0x1801B338
#define IC1_RX_TL_reg_addr                                                           "0xB801B338"
#define IC1_RX_TL_reg                                                                0xB801B338
#define set_IC1_RX_TL_reg(data)   (*((volatile unsigned int*) IC1_RX_TL_reg)=data)
#define get_IC1_RX_TL_reg   (*((volatile unsigned int*) IC1_RX_TL_reg))
#define IC1_RX_TL_inst_adr                                                           "0x00CE"
#define IC1_RX_TL_inst                                                               0x00CE
#define IC1_RX_TL_RX_TL_shift                                                        (0)
#define IC1_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC1_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC1_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC1_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC1_TX_TL                                                                    0x1801B33C
#define IC1_TX_TL_reg_addr                                                           "0xB801B33C"
#define IC1_TX_TL_reg                                                                0xB801B33C
#define set_IC1_TX_TL_reg(data)   (*((volatile unsigned int*) IC1_TX_TL_reg)=data)
#define get_IC1_TX_TL_reg   (*((volatile unsigned int*) IC1_TX_TL_reg))
#define IC1_TX_TL_inst_adr                                                           "0x00CF"
#define IC1_TX_TL_inst                                                               0x00CF
#define IC1_TX_TL_TX_TL_shift                                                        (0)
#define IC1_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC1_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC1_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC1_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC1_CLR_INTR                                                                 0x1801B340
#define IC1_CLR_INTR_reg_addr                                                        "0xB801B340"
#define IC1_CLR_INTR_reg                                                             0xB801B340
#define set_IC1_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC1_CLR_INTR_reg)=data)
#define get_IC1_CLR_INTR_reg   (*((volatile unsigned int*) IC1_CLR_INTR_reg))
#define IC1_CLR_INTR_inst_adr                                                        "0x00D0"
#define IC1_CLR_INTR_inst                                                            0x00D0
#define IC1_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC1_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC1_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC1_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC1_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC1_CLR_RX_UNDER                                                             0x1801B344
#define IC1_CLR_RX_UNDER_reg_addr                                                    "0xB801B344"
#define IC1_CLR_RX_UNDER_reg                                                         0xB801B344
#define set_IC1_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC1_CLR_RX_UNDER_reg)=data)
#define get_IC1_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC1_CLR_RX_UNDER_reg))
#define IC1_CLR_RX_UNDER_inst_adr                                                    "0x00D1"
#define IC1_CLR_RX_UNDER_inst                                                        0x00D1
#define IC1_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC1_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC1_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC1_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC1_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC1_CLR_RX_OVER                                                              0x1801B348
#define IC1_CLR_RX_OVER_reg_addr                                                     "0xB801B348"
#define IC1_CLR_RX_OVER_reg                                                          0xB801B348
#define set_IC1_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC1_CLR_RX_OVER_reg)=data)
#define get_IC1_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC1_CLR_RX_OVER_reg))
#define IC1_CLR_RX_OVER_inst_adr                                                     "0x00D2"
#define IC1_CLR_RX_OVER_inst                                                         0x00D2
#define IC1_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC1_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC1_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC1_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC1_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC1_CLR_TX_OVER                                                              0x1801B34C
#define IC1_CLR_TX_OVER_reg_addr                                                     "0xB801B34C"
#define IC1_CLR_TX_OVER_reg                                                          0xB801B34C
#define set_IC1_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC1_CLR_TX_OVER_reg)=data)
#define get_IC1_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC1_CLR_TX_OVER_reg))
#define IC1_CLR_TX_OVER_inst_adr                                                     "0x00D3"
#define IC1_CLR_TX_OVER_inst                                                         0x00D3
#define IC1_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC1_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC1_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC1_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC1_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC1_CLR_RD_REQ                                                               0x1801B350
#define IC1_CLR_RD_REQ_reg_addr                                                      "0xB801B350"
#define IC1_CLR_RD_REQ_reg                                                           0xB801B350
#define set_IC1_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC1_CLR_RD_REQ_reg)=data)
#define get_IC1_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC1_CLR_RD_REQ_reg))
#define IC1_CLR_RD_REQ_inst_adr                                                      "0x00D4"
#define IC1_CLR_RD_REQ_inst                                                          0x00D4
#define IC1_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC1_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC1_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC1_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC1_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC1_CLR_TX_ABRT                                                              0x1801B354
#define IC1_CLR_TX_ABRT_reg_addr                                                     "0xB801B354"
#define IC1_CLR_TX_ABRT_reg                                                          0xB801B354
#define set_IC1_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC1_CLR_TX_ABRT_reg)=data)
#define get_IC1_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC1_CLR_TX_ABRT_reg))
#define IC1_CLR_TX_ABRT_inst_adr                                                     "0x00D5"
#define IC1_CLR_TX_ABRT_inst                                                         0x00D5
#define IC1_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC1_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC1_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC1_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC1_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC1_CLR_RX_DONE                                                              0x1801B358
#define IC1_CLR_RX_DONE_reg_addr                                                     "0xB801B358"
#define IC1_CLR_RX_DONE_reg                                                          0xB801B358
#define set_IC1_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC1_CLR_RX_DONE_reg)=data)
#define get_IC1_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC1_CLR_RX_DONE_reg))
#define IC1_CLR_RX_DONE_inst_adr                                                     "0x00D6"
#define IC1_CLR_RX_DONE_inst                                                         0x00D6
#define IC1_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC1_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC1_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC1_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC1_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC1_CLR_ACTIVITY                                                             0x1801B35C
#define IC1_CLR_ACTIVITY_reg_addr                                                    "0xB801B35C"
#define IC1_CLR_ACTIVITY_reg                                                         0xB801B35C
#define set_IC1_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC1_CLR_ACTIVITY_reg)=data)
#define get_IC1_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC1_CLR_ACTIVITY_reg))
#define IC1_CLR_ACTIVITY_inst_adr                                                    "0x00D7"
#define IC1_CLR_ACTIVITY_inst                                                        0x00D7
#define IC1_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC1_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC1_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC1_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC1_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC1_CLR_STOP_DET                                                             0x1801B360
#define IC1_CLR_STOP_DET_reg_addr                                                    "0xB801B360"
#define IC1_CLR_STOP_DET_reg                                                         0xB801B360
#define set_IC1_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC1_CLR_STOP_DET_reg)=data)
#define get_IC1_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC1_CLR_STOP_DET_reg))
#define IC1_CLR_STOP_DET_inst_adr                                                    "0x00D8"
#define IC1_CLR_STOP_DET_inst                                                        0x00D8
#define IC1_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC1_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC1_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC1_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC1_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC1_CLR_START_DET                                                            0x1801B364
#define IC1_CLR_START_DET_reg_addr                                                   "0xB801B364"
#define IC1_CLR_START_DET_reg                                                        0xB801B364
#define set_IC1_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC1_CLR_START_DET_reg)=data)
#define get_IC1_CLR_START_DET_reg   (*((volatile unsigned int*) IC1_CLR_START_DET_reg))
#define IC1_CLR_START_DET_inst_adr                                                   "0x00D9"
#define IC1_CLR_START_DET_inst                                                       0x00D9
#define IC1_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC1_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC1_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC1_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC1_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC1_CLR_GEN_CALL                                                             0x1801B368
#define IC1_CLR_GEN_CALL_reg_addr                                                    "0xB801B368"
#define IC1_CLR_GEN_CALL_reg                                                         0xB801B368
#define set_IC1_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC1_CLR_GEN_CALL_reg)=data)
#define get_IC1_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC1_CLR_GEN_CALL_reg))
#define IC1_CLR_GEN_CALL_inst_adr                                                    "0x00DA"
#define IC1_CLR_GEN_CALL_inst                                                        0x00DA
#define IC1_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC1_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC1_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC1_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC1_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC1_ENABLE                                                                   0x1801B36C
#define IC1_ENABLE_reg_addr                                                          "0xB801B36C"
#define IC1_ENABLE_reg                                                               0xB801B36C
#define set_IC1_ENABLE_reg(data)   (*((volatile unsigned int*) IC1_ENABLE_reg)=data)
#define get_IC1_ENABLE_reg   (*((volatile unsigned int*) IC1_ENABLE_reg))
#define IC1_ENABLE_inst_adr                                                          "0x00DB"
#define IC1_ENABLE_inst                                                              0x00DB
#define IC1_ENABLE_ENABLE_shift                                                      (0)
#define IC1_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC1_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC1_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC1_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC1_STATUS                                                                   0x1801B370
#define IC1_STATUS_reg_addr                                                          "0xB801B370"
#define IC1_STATUS_reg                                                               0xB801B370
#define set_IC1_STATUS_reg(data)   (*((volatile unsigned int*) IC1_STATUS_reg)=data)
#define get_IC1_STATUS_reg   (*((volatile unsigned int*) IC1_STATUS_reg))
#define IC1_STATUS_inst_adr                                                          "0x00DC"
#define IC1_STATUS_inst                                                              0x00DC
#define IC1_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC1_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC1_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC1_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC1_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC1_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC1_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC1_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC1_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC1_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC1_STATUS_RFF_shift                                                         (4)
#define IC1_STATUS_RFF_mask                                                          (0x00000010)
#define IC1_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC1_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC1_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC1_STATUS_RFNE_shift                                                        (3)
#define IC1_STATUS_RFNE_mask                                                         (0x00000008)
#define IC1_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC1_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC1_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC1_STATUS_TFE_shift                                                         (2)
#define IC1_STATUS_TFE_mask                                                          (0x00000004)
#define IC1_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC1_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC1_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC1_STATUS_TFNF_shift                                                        (1)
#define IC1_STATUS_TFNF_mask                                                         (0x00000002)
#define IC1_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC1_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC1_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC1_STATUS_ACTIVITY_shift                                                    (0)
#define IC1_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC1_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC1_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC1_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC1_TXFLR                                                                    0x1801B374
#define IC1_TXFLR_reg_addr                                                           "0xB801B374"
#define IC1_TXFLR_reg                                                                0xB801B374
#define set_IC1_TXFLR_reg(data)   (*((volatile unsigned int*) IC1_TXFLR_reg)=data)
#define get_IC1_TXFLR_reg   (*((volatile unsigned int*) IC1_TXFLR_reg))
#define IC1_TXFLR_inst_adr                                                           "0x00DD"
#define IC1_TXFLR_inst                                                               0x00DD
#define IC1_TXFLR_TXFLR_shift                                                        (0)
#define IC1_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC1_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC1_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC1_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC1_RXFLR                                                                    0x1801B378
#define IC1_RXFLR_reg_addr                                                           "0xB801B378"
#define IC1_RXFLR_reg                                                                0xB801B378
#define set_IC1_RXFLR_reg(data)   (*((volatile unsigned int*) IC1_RXFLR_reg)=data)
#define get_IC1_RXFLR_reg   (*((volatile unsigned int*) IC1_RXFLR_reg))
#define IC1_RXFLR_inst_adr                                                           "0x00DE"
#define IC1_RXFLR_inst                                                               0x00DE
#define IC1_RXFLR_RXFLR_shift                                                        (0)
#define IC1_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC1_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC1_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC1_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC1_SDA_HOLD                                                                 0x1801B37C
#define IC1_SDA_HOLD_reg_addr                                                        "0xB801B37C"
#define IC1_SDA_HOLD_reg                                                             0xB801B37C
#define set_IC1_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC1_SDA_HOLD_reg)=data)
#define get_IC1_SDA_HOLD_reg   (*((volatile unsigned int*) IC1_SDA_HOLD_reg))
#define IC1_SDA_HOLD_inst_adr                                                        "0x00DF"
#define IC1_SDA_HOLD_inst                                                            0x00DF
#define IC1_SDA_HOLD_SDA_HOLD_shift                                                  (0)
#define IC1_SDA_HOLD_SDA_HOLD_mask                                                   (0x0000FFFF)
#define IC1_SDA_HOLD_SDA_HOLD(data)                                                  (0x0000FFFF&((data)<<0))
#define IC1_SDA_HOLD_SDA_HOLD_src(data)                                              ((0x0000FFFF&(data))>>0)
#define IC1_SDA_HOLD_get_SDA_HOLD(data)                                              ((0x0000FFFF&(data))>>0)


#define IC1_TX_ABRT_SOURCE                                                           0x1801B380
#define IC1_TX_ABRT_SOURCE_reg_addr                                                  "0xB801B380"
#define IC1_TX_ABRT_SOURCE_reg                                                       0xB801B380
#define set_IC1_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC1_TX_ABRT_SOURCE_reg)=data)
#define get_IC1_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC1_TX_ABRT_SOURCE_reg))
#define IC1_TX_ABRT_SOURCE_inst_adr                                                  "0x00E0"
#define IC1_TX_ABRT_SOURCE_inst                                                      0x00E0
#define IC1_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC1_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC1_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC1_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC1_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC1_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC1_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC1_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC1_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC1_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC1_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC1_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC1_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC1_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC1_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC1_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC1_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC1_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC1_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC1_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC1_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC1_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC1_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC1_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC1_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC1_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC1_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC1_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC1_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC1_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC1_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC1_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC1_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC1_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC1_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC1_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC1_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC1_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC1_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC1_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC1_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC1_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC1_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC1_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC1_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC1_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC1_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC1_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC1_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC1_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC1_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC1_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC1_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC1_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC1_SLV_DATA_NACK_ONLY                                                       0x1801B384
#define IC1_SLV_DATA_NACK_ONLY_reg_addr                                              "0xB801B384"
#define IC1_SLV_DATA_NACK_ONLY_reg                                                   0xB801B384
#define set_IC1_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC1_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC1_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC1_SLV_DATA_NACK_ONLY_reg))
#define IC1_SLV_DATA_NACK_ONLY_inst_adr                                              "0x00E1"
#define IC1_SLV_DATA_NACK_ONLY_inst                                                  0x00E1
#define IC1_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC1_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC1_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC1_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC1_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC1_DMA_CR                                                                   0x1801B388
#define IC1_DMA_CR_reg_addr                                                          "0xB801B388"
#define IC1_DMA_CR_reg                                                               0xB801B388
#define set_IC1_DMA_CR_reg(data)   (*((volatile unsigned int*) IC1_DMA_CR_reg)=data)
#define get_IC1_DMA_CR_reg   (*((volatile unsigned int*) IC1_DMA_CR_reg))
#define IC1_DMA_CR_inst_adr                                                          "0x00E2"
#define IC1_DMA_CR_inst                                                              0x00E2
#define IC1_DMA_CR_TDMAE_shift                                                       (1)
#define IC1_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC1_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC1_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC1_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC1_DMA_CR_RDMAE_shift                                                       (0)
#define IC1_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC1_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC1_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC1_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC1_DMA_TDLR                                                                 0x1801B38C
#define IC1_DMA_TDLR_reg_addr                                                        "0xB801B38C"
#define IC1_DMA_TDLR_reg                                                             0xB801B38C
#define set_IC1_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC1_DMA_TDLR_reg)=data)
#define get_IC1_DMA_TDLR_reg   (*((volatile unsigned int*) IC1_DMA_TDLR_reg))
#define IC1_DMA_TDLR_inst_adr                                                        "0x00E3"
#define IC1_DMA_TDLR_inst                                                            0x00E3
#define IC1_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC1_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC1_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC1_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC1_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC1_DMA_RDLR                                                                 0x1801B390
#define IC1_DMA_RDLR_reg_addr                                                        "0xB801B390"
#define IC1_DMA_RDLR_reg                                                             0xB801B390
#define set_IC1_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC1_DMA_RDLR_reg)=data)
#define get_IC1_DMA_RDLR_reg   (*((volatile unsigned int*) IC1_DMA_RDLR_reg))
#define IC1_DMA_RDLR_inst_adr                                                        "0x00E4"
#define IC1_DMA_RDLR_inst                                                            0x00E4
#define IC1_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC1_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC1_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC1_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC1_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC1_SDA_SETUP                                                                0x1801B394
#define IC1_SDA_SETUP_reg_addr                                                       "0xB801B394"
#define IC1_SDA_SETUP_reg                                                            0xB801B394
#define set_IC1_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC1_SDA_SETUP_reg)=data)
#define get_IC1_SDA_SETUP_reg   (*((volatile unsigned int*) IC1_SDA_SETUP_reg))
#define IC1_SDA_SETUP_inst_adr                                                       "0x00E5"
#define IC1_SDA_SETUP_inst                                                           0x00E5
#define IC1_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC1_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC1_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC1_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC1_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC1_ACK_GENERAL_CALL                                                         0x1801B398
#define IC1_ACK_GENERAL_CALL_reg_addr                                                "0xB801B398"
#define IC1_ACK_GENERAL_CALL_reg                                                     0xB801B398
#define set_IC1_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC1_ACK_GENERAL_CALL_reg)=data)
#define get_IC1_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC1_ACK_GENERAL_CALL_reg))
#define IC1_ACK_GENERAL_CALL_inst_adr                                                "0x00E6"
#define IC1_ACK_GENERAL_CALL_inst                                                    0x00E6
#define IC1_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC1_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC1_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC1_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC1_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC1_ENABLE_STATUS                                                            0x1801B39C
#define IC1_ENABLE_STATUS_reg_addr                                                   "0xB801B39C"
#define IC1_ENABLE_STATUS_reg                                                        0xB801B39C
#define set_IC1_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC1_ENABLE_STATUS_reg)=data)
#define get_IC1_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC1_ENABLE_STATUS_reg))
#define IC1_ENABLE_STATUS_inst_adr                                                   "0x00E7"
#define IC1_ENABLE_STATUS_inst                                                       0x00E7
#define IC1_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC1_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC1_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC1_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC1_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC1_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC1_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC1_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC1_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC1_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC1_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC1_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC1_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC1_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC1_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC1_COMP_PARAM_1                                                             0x1801B3F4
#define IC1_COMP_PARAM_1_reg_addr                                                    "0xB801B3F4"
#define IC1_COMP_PARAM_1_reg                                                         0xB801B3F4
#define set_IC1_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC1_COMP_PARAM_1_reg)=data)
#define get_IC1_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC1_COMP_PARAM_1_reg))
#define IC1_COMP_PARAM_1_inst_adr                                                    "0x00FD"
#define IC1_COMP_PARAM_1_inst                                                        0x00FD
#define IC1_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC1_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC1_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC1_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC1_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC1_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC1_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC1_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC1_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC1_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC1_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC1_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC1_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC1_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC1_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC1_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC1_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC1_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC1_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC1_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC1_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC1_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC1_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC1_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC1_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC1_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC1_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC1_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC1_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC1_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC1_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC1_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC1_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC1_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC1_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC1_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC1_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC1_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC1_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC1_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC1_COMP_VERSION                                                             0x1801B3F8
#define IC1_COMP_VERSION_reg_addr                                                    "0xB801B3F8"
#define IC1_COMP_VERSION_reg                                                         0xB801B3F8
#define set_IC1_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC1_COMP_VERSION_reg)=data)
#define get_IC1_COMP_VERSION_reg   (*((volatile unsigned int*) IC1_COMP_VERSION_reg))
#define IC1_COMP_VERSION_inst_adr                                                    "0x00FE"
#define IC1_COMP_VERSION_inst                                                        0x00FE
#define IC1_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC1_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC1_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC1_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC1_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC1_COMP_TYPE                                                                0x1801B3FC
#define IC1_COMP_TYPE_reg_addr                                                       "0xB801B3FC"
#define IC1_COMP_TYPE_reg                                                            0xB801B3FC
#define set_IC1_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC1_COMP_TYPE_reg)=data)
#define get_IC1_COMP_TYPE_reg   (*((volatile unsigned int*) IC1_COMP_TYPE_reg))
#define IC1_COMP_TYPE_inst_adr                                                       "0x00FF"
#define IC1_COMP_TYPE_inst                                                           0x00FF
#define IC1_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC1_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC1_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC1_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC1_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IC2_CON                                                                      0x1801B700
#define IC2_CON_reg_addr                                                             "0xB801B700"
#define IC2_CON_reg                                                                  0xB801B700
#define set_IC2_CON_reg(data)   (*((volatile unsigned int*) IC2_CON_reg)=data)
#define get_IC2_CON_reg   (*((volatile unsigned int*) IC2_CON_reg))
#define IC2_CON_inst_adr                                                             "0x00C0"
#define IC2_CON_inst                                                                 0x00C0
#define IC2_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC2_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC2_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC2_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC2_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC2_CON_IC_RESTART_EN_shift                                                  (5)
#define IC2_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC2_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC2_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC2_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC2_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC2_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC2_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC2_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC2_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC2_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC2_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC2_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC2_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC2_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC2_CON_SPEED_shift                                                          (1)
#define IC2_CON_SPEED_mask                                                           (0x00000006)
#define IC2_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC2_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC2_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC2_CON_MASTER_MODE_shift                                                    (0)
#define IC2_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC2_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC2_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC2_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC2_TAR                                                                      0x1801B704
#define IC2_TAR_reg_addr                                                             "0xB801B704"
#define IC2_TAR_reg                                                                  0xB801B704
#define set_IC2_TAR_reg(data)   (*((volatile unsigned int*) IC2_TAR_reg)=data)
#define get_IC2_TAR_reg   (*((volatile unsigned int*) IC2_TAR_reg))
#define IC2_TAR_inst_adr                                                             "0x00C1"
#define IC2_TAR_inst                                                                 0x00C1
#define IC2_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC2_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC2_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC2_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC2_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC2_TAR_SPECIAL_shift                                                        (11)
#define IC2_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC2_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC2_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC2_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC2_TAR_GC_OR_START_shift                                                    (10)
#define IC2_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC2_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC2_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC2_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC2_TAR_IC_TAR_shift                                                         (0)
#define IC2_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC2_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC2_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC2_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC2_SAR                                                                      0x1801B708
#define IC2_SAR_reg_addr                                                             "0xB801B708"
#define IC2_SAR_reg                                                                  0xB801B708
#define set_IC2_SAR_reg(data)   (*((volatile unsigned int*) IC2_SAR_reg)=data)
#define get_IC2_SAR_reg   (*((volatile unsigned int*) IC2_SAR_reg))
#define IC2_SAR_inst_adr                                                             "0x00C2"
#define IC2_SAR_inst                                                                 0x00C2
#define IC2_SAR_IC_SAR_shift                                                         (0)
#define IC2_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC2_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC2_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC2_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC2_HS_MADDR                                                                 0x1801B70C
#define IC2_HS_MADDR_reg_addr                                                        "0xB801B70C"
#define IC2_HS_MADDR_reg                                                             0xB801B70C
#define set_IC2_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC2_HS_MADDR_reg)=data)
#define get_IC2_HS_MADDR_reg   (*((volatile unsigned int*) IC2_HS_MADDR_reg))
#define IC2_HS_MADDR_inst_adr                                                        "0x00C3"
#define IC2_HS_MADDR_inst                                                            0x00C3
#define IC2_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC2_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC2_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC2_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC2_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC2_DATA_CMD                                                                 0x1801B710
#define IC2_DATA_CMD_reg_addr                                                        "0xB801B710"
#define IC2_DATA_CMD_reg                                                             0xB801B710
#define set_IC2_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC2_DATA_CMD_reg)=data)
#define get_IC2_DATA_CMD_reg   (*((volatile unsigned int*) IC2_DATA_CMD_reg))
#define IC2_DATA_CMD_inst_adr                                                        "0x00C4"
#define IC2_DATA_CMD_inst                                                            0x00C4
#define IC2_DATA_CMD_RESTART_shift                                                   (10)
#define IC2_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC2_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC2_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC2_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC2_DATA_CMD_STOP_shift                                                      (9)
#define IC2_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC2_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC2_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC2_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC2_DATA_CMD_CMD_shift                                                       (8)
#define IC2_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC2_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC2_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC2_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC2_DATA_CMD_DAT_shift                                                       (0)
#define IC2_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC2_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC2_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC2_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC2_SS_SCL_HCNT                                                              0x1801B714
#define IC2_SS_SCL_HCNT_reg_addr                                                     "0xB801B714"
#define IC2_SS_SCL_HCNT_reg                                                          0xB801B714
#define set_IC2_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC2_SS_SCL_HCNT_reg)=data)
#define get_IC2_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC2_SS_SCL_HCNT_reg))
#define IC2_SS_SCL_HCNT_inst_adr                                                     "0x00C5"
#define IC2_SS_SCL_HCNT_inst                                                         0x00C5
#define IC2_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC2_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC2_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC2_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC2_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC2_SS_SCL_LCNT                                                              0x1801B718
#define IC2_SS_SCL_LCNT_reg_addr                                                     "0xB801B718"
#define IC2_SS_SCL_LCNT_reg                                                          0xB801B718
#define set_IC2_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC2_SS_SCL_LCNT_reg)=data)
#define get_IC2_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC2_SS_SCL_LCNT_reg))
#define IC2_SS_SCL_LCNT_inst_adr                                                     "0x00C6"
#define IC2_SS_SCL_LCNT_inst                                                         0x00C6
#define IC2_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC2_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC2_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC2_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC2_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC2_FS_SCL_HCNT                                                              0x1801B71C
#define IC2_FS_SCL_HCNT_reg_addr                                                     "0xB801B71C"
#define IC2_FS_SCL_HCNT_reg                                                          0xB801B71C
#define set_IC2_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC2_FS_SCL_HCNT_reg)=data)
#define get_IC2_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC2_FS_SCL_HCNT_reg))
#define IC2_FS_SCL_HCNT_inst_adr                                                     "0x00C7"
#define IC2_FS_SCL_HCNT_inst                                                         0x00C7
#define IC2_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC2_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC2_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC2_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC2_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC2_FS_SCL_LCNT                                                              0x1801B720
#define IC2_FS_SCL_LCNT_reg_addr                                                     "0xB801B720"
#define IC2_FS_SCL_LCNT_reg                                                          0xB801B720
#define set_IC2_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC2_FS_SCL_LCNT_reg)=data)
#define get_IC2_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC2_FS_SCL_LCNT_reg))
#define IC2_FS_SCL_LCNT_inst_adr                                                     "0x00C8"
#define IC2_FS_SCL_LCNT_inst                                                         0x00C8
#define IC2_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC2_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC2_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC2_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC2_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC2_INTR_STAT                                                                0x1801B72C
#define IC2_INTR_STAT_reg_addr                                                       "0xB801B72C"
#define IC2_INTR_STAT_reg                                                            0xB801B72C
#define set_IC2_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC2_INTR_STAT_reg)=data)
#define get_IC2_INTR_STAT_reg   (*((volatile unsigned int*) IC2_INTR_STAT_reg))
#define IC2_INTR_STAT_inst_adr                                                       "0x00CB"
#define IC2_INTR_STAT_inst                                                           0x00CB
#define IC2_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC2_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC2_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC2_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC2_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC2_INTR_STAT_R_START_DET_shift                                              (10)
#define IC2_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC2_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC2_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC2_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC2_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC2_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC2_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC2_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC2_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC2_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC2_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC2_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC2_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC2_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC2_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC2_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC2_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC2_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC2_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC2_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC2_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC2_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC2_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC2_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC2_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC2_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC2_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC2_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC2_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC2_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC2_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC2_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC2_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC2_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC2_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC2_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC2_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC2_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC2_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC2_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC2_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC2_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC2_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC2_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC2_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC2_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC2_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC2_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC2_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC2_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC2_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC2_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC2_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC2_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC2_INTR_MASK                                                                0x1801B730
#define IC2_INTR_MASK_reg_addr                                                       "0xB801B730"
#define IC2_INTR_MASK_reg                                                            0xB801B730
#define set_IC2_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC2_INTR_MASK_reg)=data)
#define get_IC2_INTR_MASK_reg   (*((volatile unsigned int*) IC2_INTR_MASK_reg))
#define IC2_INTR_MASK_inst_adr                                                       "0x00CC"
#define IC2_INTR_MASK_inst                                                           0x00CC
#define IC2_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC2_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC2_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC2_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC2_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC2_INTR_MASK_M_START_DET_shift                                              (10)
#define IC2_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC2_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC2_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC2_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC2_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC2_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC2_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC2_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC2_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC2_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC2_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC2_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC2_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC2_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC2_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC2_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC2_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC2_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC2_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC2_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC2_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC2_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC2_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC2_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC2_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC2_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC2_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC2_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC2_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC2_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC2_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC2_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC2_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC2_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC2_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC2_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC2_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC2_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC2_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC2_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC2_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC2_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC2_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC2_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC2_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC2_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC2_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC2_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC2_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC2_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC2_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC2_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC2_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC2_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC2_RAW_INTR_STAT                                                            0x1801B734
#define IC2_RAW_INTR_STAT_reg_addr                                                   "0xB801B734"
#define IC2_RAW_INTR_STAT_reg                                                        0xB801B734
#define set_IC2_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC2_RAW_INTR_STAT_reg)=data)
#define get_IC2_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC2_RAW_INTR_STAT_reg))
#define IC2_RAW_INTR_STAT_inst_adr                                                   "0x00CD"
#define IC2_RAW_INTR_STAT_inst                                                       0x00CD
#define IC2_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC2_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC2_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC2_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC2_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC2_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC2_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC2_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC2_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC2_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC2_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC2_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC2_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC2_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC2_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC2_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC2_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC2_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC2_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC2_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC2_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC2_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC2_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC2_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC2_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC2_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC2_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC2_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC2_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC2_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC2_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC2_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC2_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC2_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC2_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC2_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC2_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC2_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC2_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC2_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC2_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC2_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC2_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC2_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC2_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC2_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC2_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC2_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC2_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC2_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC2_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC2_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC2_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC2_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC2_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC2_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC2_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC2_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC2_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC2_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC2_RX_TL                                                                    0x1801B738
#define IC2_RX_TL_reg_addr                                                           "0xB801B738"
#define IC2_RX_TL_reg                                                                0xB801B738
#define set_IC2_RX_TL_reg(data)   (*((volatile unsigned int*) IC2_RX_TL_reg)=data)
#define get_IC2_RX_TL_reg   (*((volatile unsigned int*) IC2_RX_TL_reg))
#define IC2_RX_TL_inst_adr                                                           "0x00CE"
#define IC2_RX_TL_inst                                                               0x00CE
#define IC2_RX_TL_RX_TL_shift                                                        (0)
#define IC2_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC2_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC2_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC2_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC2_TX_TL                                                                    0x1801B73C
#define IC2_TX_TL_reg_addr                                                           "0xB801B73C"
#define IC2_TX_TL_reg                                                                0xB801B73C
#define set_IC2_TX_TL_reg(data)   (*((volatile unsigned int*) IC2_TX_TL_reg)=data)
#define get_IC2_TX_TL_reg   (*((volatile unsigned int*) IC2_TX_TL_reg))
#define IC2_TX_TL_inst_adr                                                           "0x00CF"
#define IC2_TX_TL_inst                                                               0x00CF
#define IC2_TX_TL_TX_TL_shift                                                        (0)
#define IC2_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC2_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC2_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC2_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC2_CLR_INTR                                                                 0x1801B740
#define IC2_CLR_INTR_reg_addr                                                        "0xB801B740"
#define IC2_CLR_INTR_reg                                                             0xB801B740
#define set_IC2_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC2_CLR_INTR_reg)=data)
#define get_IC2_CLR_INTR_reg   (*((volatile unsigned int*) IC2_CLR_INTR_reg))
#define IC2_CLR_INTR_inst_adr                                                        "0x00D0"
#define IC2_CLR_INTR_inst                                                            0x00D0
#define IC2_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC2_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC2_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC2_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC2_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC2_CLR_RX_UNDER                                                             0x1801B744
#define IC2_CLR_RX_UNDER_reg_addr                                                    "0xB801B744"
#define IC2_CLR_RX_UNDER_reg                                                         0xB801B744
#define set_IC2_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC2_CLR_RX_UNDER_reg)=data)
#define get_IC2_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC2_CLR_RX_UNDER_reg))
#define IC2_CLR_RX_UNDER_inst_adr                                                    "0x00D1"
#define IC2_CLR_RX_UNDER_inst                                                        0x00D1
#define IC2_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC2_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC2_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC2_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC2_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC2_CLR_RX_OVER                                                              0x1801B748
#define IC2_CLR_RX_OVER_reg_addr                                                     "0xB801B748"
#define IC2_CLR_RX_OVER_reg                                                          0xB801B748
#define set_IC2_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC2_CLR_RX_OVER_reg)=data)
#define get_IC2_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC2_CLR_RX_OVER_reg))
#define IC2_CLR_RX_OVER_inst_adr                                                     "0x00D2"
#define IC2_CLR_RX_OVER_inst                                                         0x00D2
#define IC2_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC2_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC2_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC2_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC2_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC2_CLR_TX_OVER                                                              0x1801B74C
#define IC2_CLR_TX_OVER_reg_addr                                                     "0xB801B74C"
#define IC2_CLR_TX_OVER_reg                                                          0xB801B74C
#define set_IC2_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC2_CLR_TX_OVER_reg)=data)
#define get_IC2_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC2_CLR_TX_OVER_reg))
#define IC2_CLR_TX_OVER_inst_adr                                                     "0x00D3"
#define IC2_CLR_TX_OVER_inst                                                         0x00D3
#define IC2_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC2_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC2_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC2_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC2_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC2_CLR_RD_REQ                                                               0x1801B750
#define IC2_CLR_RD_REQ_reg_addr                                                      "0xB801B750"
#define IC2_CLR_RD_REQ_reg                                                           0xB801B750
#define set_IC2_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC2_CLR_RD_REQ_reg)=data)
#define get_IC2_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC2_CLR_RD_REQ_reg))
#define IC2_CLR_RD_REQ_inst_adr                                                      "0x00D4"
#define IC2_CLR_RD_REQ_inst                                                          0x00D4
#define IC2_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC2_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC2_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC2_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC2_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC2_CLR_TX_ABRT                                                              0x1801B754
#define IC2_CLR_TX_ABRT_reg_addr                                                     "0xB801B754"
#define IC2_CLR_TX_ABRT_reg                                                          0xB801B754
#define set_IC2_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC2_CLR_TX_ABRT_reg)=data)
#define get_IC2_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC2_CLR_TX_ABRT_reg))
#define IC2_CLR_TX_ABRT_inst_adr                                                     "0x00D5"
#define IC2_CLR_TX_ABRT_inst                                                         0x00D5
#define IC2_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC2_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC2_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC2_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC2_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC2_CLR_RX_DONE                                                              0x1801B758
#define IC2_CLR_RX_DONE_reg_addr                                                     "0xB801B758"
#define IC2_CLR_RX_DONE_reg                                                          0xB801B758
#define set_IC2_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC2_CLR_RX_DONE_reg)=data)
#define get_IC2_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC2_CLR_RX_DONE_reg))
#define IC2_CLR_RX_DONE_inst_adr                                                     "0x00D6"
#define IC2_CLR_RX_DONE_inst                                                         0x00D6
#define IC2_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC2_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC2_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC2_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC2_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC2_CLR_ACTIVITY                                                             0x1801B75C
#define IC2_CLR_ACTIVITY_reg_addr                                                    "0xB801B75C"
#define IC2_CLR_ACTIVITY_reg                                                         0xB801B75C
#define set_IC2_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC2_CLR_ACTIVITY_reg)=data)
#define get_IC2_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC2_CLR_ACTIVITY_reg))
#define IC2_CLR_ACTIVITY_inst_adr                                                    "0x00D7"
#define IC2_CLR_ACTIVITY_inst                                                        0x00D7
#define IC2_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC2_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC2_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC2_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC2_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC2_CLR_STOP_DET                                                             0x1801B760
#define IC2_CLR_STOP_DET_reg_addr                                                    "0xB801B760"
#define IC2_CLR_STOP_DET_reg                                                         0xB801B760
#define set_IC2_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC2_CLR_STOP_DET_reg)=data)
#define get_IC2_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC2_CLR_STOP_DET_reg))
#define IC2_CLR_STOP_DET_inst_adr                                                    "0x00D8"
#define IC2_CLR_STOP_DET_inst                                                        0x00D8
#define IC2_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC2_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC2_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC2_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC2_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC2_CLR_START_DET                                                            0x1801B764
#define IC2_CLR_START_DET_reg_addr                                                   "0xB801B764"
#define IC2_CLR_START_DET_reg                                                        0xB801B764
#define set_IC2_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC2_CLR_START_DET_reg)=data)
#define get_IC2_CLR_START_DET_reg   (*((volatile unsigned int*) IC2_CLR_START_DET_reg))
#define IC2_CLR_START_DET_inst_adr                                                   "0x00D9"
#define IC2_CLR_START_DET_inst                                                       0x00D9
#define IC2_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC2_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC2_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC2_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC2_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC2_CLR_GEN_CALL                                                             0x1801B768
#define IC2_CLR_GEN_CALL_reg_addr                                                    "0xB801B768"
#define IC2_CLR_GEN_CALL_reg                                                         0xB801B768
#define set_IC2_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC2_CLR_GEN_CALL_reg)=data)
#define get_IC2_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC2_CLR_GEN_CALL_reg))
#define IC2_CLR_GEN_CALL_inst_adr                                                    "0x00DA"
#define IC2_CLR_GEN_CALL_inst                                                        0x00DA
#define IC2_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC2_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC2_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC2_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC2_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC2_ENABLE                                                                   0x1801B76C
#define IC2_ENABLE_reg_addr                                                          "0xB801B76C"
#define IC2_ENABLE_reg                                                               0xB801B76C
#define set_IC2_ENABLE_reg(data)   (*((volatile unsigned int*) IC2_ENABLE_reg)=data)
#define get_IC2_ENABLE_reg   (*((volatile unsigned int*) IC2_ENABLE_reg))
#define IC2_ENABLE_inst_adr                                                          "0x00DB"
#define IC2_ENABLE_inst                                                              0x00DB
#define IC2_ENABLE_ENABLE_shift                                                      (0)
#define IC2_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC2_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC2_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC2_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC2_STATUS                                                                   0x1801B770
#define IC2_STATUS_reg_addr                                                          "0xB801B770"
#define IC2_STATUS_reg                                                               0xB801B770
#define set_IC2_STATUS_reg(data)   (*((volatile unsigned int*) IC2_STATUS_reg)=data)
#define get_IC2_STATUS_reg   (*((volatile unsigned int*) IC2_STATUS_reg))
#define IC2_STATUS_inst_adr                                                          "0x00DC"
#define IC2_STATUS_inst                                                              0x00DC
#define IC2_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC2_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC2_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC2_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC2_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC2_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC2_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC2_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC2_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC2_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC2_STATUS_RFF_shift                                                         (4)
#define IC2_STATUS_RFF_mask                                                          (0x00000010)
#define IC2_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC2_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC2_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC2_STATUS_RFNE_shift                                                        (3)
#define IC2_STATUS_RFNE_mask                                                         (0x00000008)
#define IC2_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC2_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC2_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC2_STATUS_TFE_shift                                                         (2)
#define IC2_STATUS_TFE_mask                                                          (0x00000004)
#define IC2_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC2_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC2_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC2_STATUS_TFNF_shift                                                        (1)
#define IC2_STATUS_TFNF_mask                                                         (0x00000002)
#define IC2_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC2_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC2_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC2_STATUS_ACTIVITY_shift                                                    (0)
#define IC2_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC2_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC2_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC2_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC2_TXFLR                                                                    0x1801B774
#define IC2_TXFLR_reg_addr                                                           "0xB801B774"
#define IC2_TXFLR_reg                                                                0xB801B774
#define set_IC2_TXFLR_reg(data)   (*((volatile unsigned int*) IC2_TXFLR_reg)=data)
#define get_IC2_TXFLR_reg   (*((volatile unsigned int*) IC2_TXFLR_reg))
#define IC2_TXFLR_inst_adr                                                           "0x00DD"
#define IC2_TXFLR_inst                                                               0x00DD
#define IC2_TXFLR_TXFLR_shift                                                        (0)
#define IC2_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC2_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC2_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC2_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC2_RXFLR                                                                    0x1801B778
#define IC2_RXFLR_reg_addr                                                           "0xB801B778"
#define IC2_RXFLR_reg                                                                0xB801B778
#define set_IC2_RXFLR_reg(data)   (*((volatile unsigned int*) IC2_RXFLR_reg)=data)
#define get_IC2_RXFLR_reg   (*((volatile unsigned int*) IC2_RXFLR_reg))
#define IC2_RXFLR_inst_adr                                                           "0x00DE"
#define IC2_RXFLR_inst                                                               0x00DE
#define IC2_RXFLR_RXFLR_shift                                                        (0)
#define IC2_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC2_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC2_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC2_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC2_SDA_HOLD                                                                 0x1801B77C
#define IC2_SDA_HOLD_reg_addr                                                        "0xB801B77C"
#define IC2_SDA_HOLD_reg                                                             0xB801B77C
#define set_IC2_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC2_SDA_HOLD_reg)=data)
#define get_IC2_SDA_HOLD_reg   (*((volatile unsigned int*) IC2_SDA_HOLD_reg))
#define IC2_SDA_HOLD_inst_adr                                                        "0x00DF"
#define IC2_SDA_HOLD_inst                                                            0x00DF
#define IC2_SDA_HOLD_SDA_HOLD_shift                                                  (0)
#define IC2_SDA_HOLD_SDA_HOLD_mask                                                   (0x0000FFFF)
#define IC2_SDA_HOLD_SDA_HOLD(data)                                                  (0x0000FFFF&((data)<<0))
#define IC2_SDA_HOLD_SDA_HOLD_src(data)                                              ((0x0000FFFF&(data))>>0)
#define IC2_SDA_HOLD_get_SDA_HOLD(data)                                              ((0x0000FFFF&(data))>>0)


#define IC2_TX_ABRT_SOURCE                                                           0x1801B780
#define IC2_TX_ABRT_SOURCE_reg_addr                                                  "0xB801B780"
#define IC2_TX_ABRT_SOURCE_reg                                                       0xB801B780
#define set_IC2_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC2_TX_ABRT_SOURCE_reg)=data)
#define get_IC2_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC2_TX_ABRT_SOURCE_reg))
#define IC2_TX_ABRT_SOURCE_inst_adr                                                  "0x00E0"
#define IC2_TX_ABRT_SOURCE_inst                                                      0x00E0
#define IC2_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC2_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC2_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC2_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC2_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC2_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC2_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC2_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC2_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC2_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC2_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC2_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC2_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC2_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC2_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC2_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC2_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC2_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC2_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC2_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC2_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC2_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC2_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC2_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC2_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC2_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC2_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC2_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC2_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC2_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC2_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC2_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC2_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC2_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC2_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC2_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC2_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC2_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC2_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC2_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC2_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC2_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC2_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC2_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC2_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC2_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC2_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC2_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC2_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC2_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC2_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC2_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC2_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC2_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC2_SLV_DATA_NACK_ONLY                                                       0x1801B784
#define IC2_SLV_DATA_NACK_ONLY_reg_addr                                              "0xB801B784"
#define IC2_SLV_DATA_NACK_ONLY_reg                                                   0xB801B784
#define set_IC2_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC2_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC2_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC2_SLV_DATA_NACK_ONLY_reg))
#define IC2_SLV_DATA_NACK_ONLY_inst_adr                                              "0x00E1"
#define IC2_SLV_DATA_NACK_ONLY_inst                                                  0x00E1
#define IC2_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC2_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC2_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC2_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC2_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC2_DMA_CR                                                                   0x1801B788
#define IC2_DMA_CR_reg_addr                                                          "0xB801B788"
#define IC2_DMA_CR_reg                                                               0xB801B788
#define set_IC2_DMA_CR_reg(data)   (*((volatile unsigned int*) IC2_DMA_CR_reg)=data)
#define get_IC2_DMA_CR_reg   (*((volatile unsigned int*) IC2_DMA_CR_reg))
#define IC2_DMA_CR_inst_adr                                                          "0x00E2"
#define IC2_DMA_CR_inst                                                              0x00E2
#define IC2_DMA_CR_TDMAE_shift                                                       (1)
#define IC2_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC2_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC2_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC2_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC2_DMA_CR_RDMAE_shift                                                       (0)
#define IC2_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC2_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC2_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC2_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC2_DMA_TDLR                                                                 0x1801B78C
#define IC2_DMA_TDLR_reg_addr                                                        "0xB801B78C"
#define IC2_DMA_TDLR_reg                                                             0xB801B78C
#define set_IC2_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC2_DMA_TDLR_reg)=data)
#define get_IC2_DMA_TDLR_reg   (*((volatile unsigned int*) IC2_DMA_TDLR_reg))
#define IC2_DMA_TDLR_inst_adr                                                        "0x00E3"
#define IC2_DMA_TDLR_inst                                                            0x00E3
#define IC2_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC2_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC2_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC2_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC2_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC2_DMA_RDLR                                                                 0x1801B790
#define IC2_DMA_RDLR_reg_addr                                                        "0xB801B790"
#define IC2_DMA_RDLR_reg                                                             0xB801B790
#define set_IC2_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC2_DMA_RDLR_reg)=data)
#define get_IC2_DMA_RDLR_reg   (*((volatile unsigned int*) IC2_DMA_RDLR_reg))
#define IC2_DMA_RDLR_inst_adr                                                        "0x00E4"
#define IC2_DMA_RDLR_inst                                                            0x00E4
#define IC2_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC2_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC2_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC2_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC2_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC2_SDA_SETUP                                                                0x1801B794
#define IC2_SDA_SETUP_reg_addr                                                       "0xB801B794"
#define IC2_SDA_SETUP_reg                                                            0xB801B794
#define set_IC2_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC2_SDA_SETUP_reg)=data)
#define get_IC2_SDA_SETUP_reg   (*((volatile unsigned int*) IC2_SDA_SETUP_reg))
#define IC2_SDA_SETUP_inst_adr                                                       "0x00E5"
#define IC2_SDA_SETUP_inst                                                           0x00E5
#define IC2_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC2_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC2_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC2_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC2_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC2_ACK_GENERAL_CALL                                                         0x1801B798
#define IC2_ACK_GENERAL_CALL_reg_addr                                                "0xB801B798"
#define IC2_ACK_GENERAL_CALL_reg                                                     0xB801B798
#define set_IC2_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC2_ACK_GENERAL_CALL_reg)=data)
#define get_IC2_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC2_ACK_GENERAL_CALL_reg))
#define IC2_ACK_GENERAL_CALL_inst_adr                                                "0x00E6"
#define IC2_ACK_GENERAL_CALL_inst                                                    0x00E6
#define IC2_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC2_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC2_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC2_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC2_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC2_ENABLE_STATUS                                                            0x1801B79C
#define IC2_ENABLE_STATUS_reg_addr                                                   "0xB801B79C"
#define IC2_ENABLE_STATUS_reg                                                        0xB801B79C
#define set_IC2_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC2_ENABLE_STATUS_reg)=data)
#define get_IC2_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC2_ENABLE_STATUS_reg))
#define IC2_ENABLE_STATUS_inst_adr                                                   "0x00E7"
#define IC2_ENABLE_STATUS_inst                                                       0x00E7
#define IC2_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC2_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC2_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC2_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC2_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC2_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC2_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC2_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC2_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC2_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC2_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC2_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC2_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC2_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC2_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC2_COMP_PARAM_1                                                             0x1801B7F4
#define IC2_COMP_PARAM_1_reg_addr                                                    "0xB801B7F4"
#define IC2_COMP_PARAM_1_reg                                                         0xB801B7F4
#define set_IC2_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC2_COMP_PARAM_1_reg)=data)
#define get_IC2_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC2_COMP_PARAM_1_reg))
#define IC2_COMP_PARAM_1_inst_adr                                                    "0x00FD"
#define IC2_COMP_PARAM_1_inst                                                        0x00FD
#define IC2_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC2_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC2_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC2_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC2_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC2_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC2_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC2_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC2_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC2_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC2_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC2_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC2_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC2_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC2_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC2_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC2_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC2_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC2_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC2_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC2_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC2_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC2_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC2_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC2_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC2_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC2_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC2_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC2_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC2_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC2_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC2_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC2_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC2_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC2_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC2_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC2_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC2_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC2_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC2_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC2_COMP_VERSION                                                             0x1801B7F8
#define IC2_COMP_VERSION_reg_addr                                                    "0xB801B7F8"
#define IC2_COMP_VERSION_reg                                                         0xB801B7F8
#define set_IC2_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC2_COMP_VERSION_reg)=data)
#define get_IC2_COMP_VERSION_reg   (*((volatile unsigned int*) IC2_COMP_VERSION_reg))
#define IC2_COMP_VERSION_inst_adr                                                    "0x00FE"
#define IC2_COMP_VERSION_inst                                                        0x00FE
#define IC2_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC2_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC2_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC2_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC2_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC2_COMP_TYPE                                                                0x1801B7FC
#define IC2_COMP_TYPE_reg_addr                                                       "0xB801B7FC"
#define IC2_COMP_TYPE_reg                                                            0xB801B7FC
#define set_IC2_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC2_COMP_TYPE_reg)=data)
#define get_IC2_COMP_TYPE_reg   (*((volatile unsigned int*) IC2_COMP_TYPE_reg))
#define IC2_COMP_TYPE_inst_adr                                                       "0x00FF"
#define IC2_COMP_TYPE_inst                                                           0x00FF
#define IC2_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC2_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC2_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC2_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC2_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IC3_CON                                                                      0x1801B900
#define IC3_CON_reg_addr                                                             "0xB801B900"
#define IC3_CON_reg                                                                  0xB801B900
#define set_IC3_CON_reg(data)   (*((volatile unsigned int*) IC3_CON_reg)=data)
#define get_IC3_CON_reg   (*((volatile unsigned int*) IC3_CON_reg))
#define IC3_CON_inst_adr                                                             "0x0040"
#define IC3_CON_inst                                                                 0x0040
#define IC3_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC3_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC3_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC3_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC3_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC3_CON_IC_RESTART_EN_shift                                                  (5)
#define IC3_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC3_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC3_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC3_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC3_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC3_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC3_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC3_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC3_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC3_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC3_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC3_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC3_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC3_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC3_CON_SPEED_shift                                                          (1)
#define IC3_CON_SPEED_mask                                                           (0x00000006)
#define IC3_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC3_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC3_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC3_CON_MASTER_MODE_shift                                                    (0)
#define IC3_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC3_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC3_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC3_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC3_TAR                                                                      0x1801B904
#define IC3_TAR_reg_addr                                                             "0xB801B904"
#define IC3_TAR_reg                                                                  0xB801B904
#define set_IC3_TAR_reg(data)   (*((volatile unsigned int*) IC3_TAR_reg)=data)
#define get_IC3_TAR_reg   (*((volatile unsigned int*) IC3_TAR_reg))
#define IC3_TAR_inst_adr                                                             "0x0041"
#define IC3_TAR_inst                                                                 0x0041
#define IC3_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC3_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC3_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC3_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC3_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC3_TAR_SPECIAL_shift                                                        (11)
#define IC3_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC3_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC3_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC3_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC3_TAR_GC_OR_START_shift                                                    (10)
#define IC3_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC3_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC3_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC3_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC3_TAR_IC_TAR_shift                                                         (0)
#define IC3_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC3_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC3_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC3_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC3_SAR                                                                      0x1801B908
#define IC3_SAR_reg_addr                                                             "0xB801B908"
#define IC3_SAR_reg                                                                  0xB801B908
#define set_IC3_SAR_reg(data)   (*((volatile unsigned int*) IC3_SAR_reg)=data)
#define get_IC3_SAR_reg   (*((volatile unsigned int*) IC3_SAR_reg))
#define IC3_SAR_inst_adr                                                             "0x0042"
#define IC3_SAR_inst                                                                 0x0042
#define IC3_SAR_IC_SAR_shift                                                         (0)
#define IC3_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC3_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC3_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC3_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC3_HS_MADDR                                                                 0x1801B90C
#define IC3_HS_MADDR_reg_addr                                                        "0xB801B90C"
#define IC3_HS_MADDR_reg                                                             0xB801B90C
#define set_IC3_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC3_HS_MADDR_reg)=data)
#define get_IC3_HS_MADDR_reg   (*((volatile unsigned int*) IC3_HS_MADDR_reg))
#define IC3_HS_MADDR_inst_adr                                                        "0x0043"
#define IC3_HS_MADDR_inst                                                            0x0043
#define IC3_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC3_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC3_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC3_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC3_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC3_DATA_CMD                                                                 0x1801B910
#define IC3_DATA_CMD_reg_addr                                                        "0xB801B910"
#define IC3_DATA_CMD_reg                                                             0xB801B910
#define set_IC3_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC3_DATA_CMD_reg)=data)
#define get_IC3_DATA_CMD_reg   (*((volatile unsigned int*) IC3_DATA_CMD_reg))
#define IC3_DATA_CMD_inst_adr                                                        "0x0044"
#define IC3_DATA_CMD_inst                                                            0x0044
#define IC3_DATA_CMD_RESTART_shift                                                   (10)
#define IC3_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC3_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC3_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC3_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC3_DATA_CMD_STOP_shift                                                      (9)
#define IC3_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC3_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC3_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC3_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC3_DATA_CMD_CMD_shift                                                       (8)
#define IC3_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC3_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC3_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC3_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC3_DATA_CMD_DAT_shift                                                       (0)
#define IC3_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC3_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC3_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC3_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC3_SS_SCL_HCNT                                                              0x1801B914
#define IC3_SS_SCL_HCNT_reg_addr                                                     "0xB801B914"
#define IC3_SS_SCL_HCNT_reg                                                          0xB801B914
#define set_IC3_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC3_SS_SCL_HCNT_reg)=data)
#define get_IC3_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC3_SS_SCL_HCNT_reg))
#define IC3_SS_SCL_HCNT_inst_adr                                                     "0x0045"
#define IC3_SS_SCL_HCNT_inst                                                         0x0045
#define IC3_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC3_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC3_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC3_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC3_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC3_SS_SCL_LCNT                                                              0x1801B918
#define IC3_SS_SCL_LCNT_reg_addr                                                     "0xB801B918"
#define IC3_SS_SCL_LCNT_reg                                                          0xB801B918
#define set_IC3_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC3_SS_SCL_LCNT_reg)=data)
#define get_IC3_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC3_SS_SCL_LCNT_reg))
#define IC3_SS_SCL_LCNT_inst_adr                                                     "0x0046"
#define IC3_SS_SCL_LCNT_inst                                                         0x0046
#define IC3_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC3_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC3_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC3_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC3_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC3_FS_SCL_HCNT                                                              0x1801B91C
#define IC3_FS_SCL_HCNT_reg_addr                                                     "0xB801B91C"
#define IC3_FS_SCL_HCNT_reg                                                          0xB801B91C
#define set_IC3_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC3_FS_SCL_HCNT_reg)=data)
#define get_IC3_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC3_FS_SCL_HCNT_reg))
#define IC3_FS_SCL_HCNT_inst_adr                                                     "0x0047"
#define IC3_FS_SCL_HCNT_inst                                                         0x0047
#define IC3_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC3_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC3_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC3_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC3_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC3_FS_SCL_LCNT                                                              0x1801B920
#define IC3_FS_SCL_LCNT_reg_addr                                                     "0xB801B920"
#define IC3_FS_SCL_LCNT_reg                                                          0xB801B920
#define set_IC3_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC3_FS_SCL_LCNT_reg)=data)
#define get_IC3_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC3_FS_SCL_LCNT_reg))
#define IC3_FS_SCL_LCNT_inst_adr                                                     "0x0048"
#define IC3_FS_SCL_LCNT_inst                                                         0x0048
#define IC3_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC3_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC3_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC3_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC3_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC3_INTR_STAT                                                                0x1801B92C
#define IC3_INTR_STAT_reg_addr                                                       "0xB801B92C"
#define IC3_INTR_STAT_reg                                                            0xB801B92C
#define set_IC3_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC3_INTR_STAT_reg)=data)
#define get_IC3_INTR_STAT_reg   (*((volatile unsigned int*) IC3_INTR_STAT_reg))
#define IC3_INTR_STAT_inst_adr                                                       "0x004B"
#define IC3_INTR_STAT_inst                                                           0x004B
#define IC3_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC3_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC3_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC3_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC3_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC3_INTR_STAT_R_START_DET_shift                                              (10)
#define IC3_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC3_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC3_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC3_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC3_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC3_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC3_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC3_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC3_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC3_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC3_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC3_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC3_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC3_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC3_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC3_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC3_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC3_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC3_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC3_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC3_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC3_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC3_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC3_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC3_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC3_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC3_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC3_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC3_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC3_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC3_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC3_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC3_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC3_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC3_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC3_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC3_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC3_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC3_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC3_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC3_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC3_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC3_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC3_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC3_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC3_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC3_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC3_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC3_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC3_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC3_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC3_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC3_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC3_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC3_INTR_MASK                                                                0x1801B930
#define IC3_INTR_MASK_reg_addr                                                       "0xB801B930"
#define IC3_INTR_MASK_reg                                                            0xB801B930
#define set_IC3_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC3_INTR_MASK_reg)=data)
#define get_IC3_INTR_MASK_reg   (*((volatile unsigned int*) IC3_INTR_MASK_reg))
#define IC3_INTR_MASK_inst_adr                                                       "0x004C"
#define IC3_INTR_MASK_inst                                                           0x004C
#define IC3_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC3_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC3_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC3_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC3_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC3_INTR_MASK_M_START_DET_shift                                              (10)
#define IC3_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC3_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC3_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC3_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC3_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC3_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC3_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC3_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC3_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC3_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC3_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC3_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC3_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC3_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC3_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC3_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC3_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC3_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC3_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC3_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC3_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC3_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC3_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC3_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC3_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC3_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC3_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC3_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC3_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC3_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC3_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC3_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC3_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC3_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC3_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC3_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC3_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC3_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC3_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC3_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC3_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC3_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC3_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC3_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC3_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC3_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC3_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC3_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC3_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC3_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC3_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC3_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC3_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC3_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC3_RAW_INTR_STAT                                                            0x1801B934
#define IC3_RAW_INTR_STAT_reg_addr                                                   "0xB801B934"
#define IC3_RAW_INTR_STAT_reg                                                        0xB801B934
#define set_IC3_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC3_RAW_INTR_STAT_reg)=data)
#define get_IC3_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC3_RAW_INTR_STAT_reg))
#define IC3_RAW_INTR_STAT_inst_adr                                                   "0x004D"
#define IC3_RAW_INTR_STAT_inst                                                       0x004D
#define IC3_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC3_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC3_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC3_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC3_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC3_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC3_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC3_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC3_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC3_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC3_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC3_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC3_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC3_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC3_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC3_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC3_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC3_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC3_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC3_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC3_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC3_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC3_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC3_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC3_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC3_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC3_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC3_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC3_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC3_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC3_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC3_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC3_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC3_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC3_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC3_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC3_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC3_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC3_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC3_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC3_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC3_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC3_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC3_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC3_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC3_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC3_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC3_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC3_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC3_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC3_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC3_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC3_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC3_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC3_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC3_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC3_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC3_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC3_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC3_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC3_RX_TL                                                                    0x1801B938
#define IC3_RX_TL_reg_addr                                                           "0xB801B938"
#define IC3_RX_TL_reg                                                                0xB801B938
#define set_IC3_RX_TL_reg(data)   (*((volatile unsigned int*) IC3_RX_TL_reg)=data)
#define get_IC3_RX_TL_reg   (*((volatile unsigned int*) IC3_RX_TL_reg))
#define IC3_RX_TL_inst_adr                                                           "0x004E"
#define IC3_RX_TL_inst                                                               0x004E
#define IC3_RX_TL_RX_TL_shift                                                        (0)
#define IC3_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC3_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC3_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC3_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC3_TX_TL                                                                    0x1801B93C
#define IC3_TX_TL_reg_addr                                                           "0xB801B93C"
#define IC3_TX_TL_reg                                                                0xB801B93C
#define set_IC3_TX_TL_reg(data)   (*((volatile unsigned int*) IC3_TX_TL_reg)=data)
#define get_IC3_TX_TL_reg   (*((volatile unsigned int*) IC3_TX_TL_reg))
#define IC3_TX_TL_inst_adr                                                           "0x004F"
#define IC3_TX_TL_inst                                                               0x004F
#define IC3_TX_TL_TX_TL_shift                                                        (0)
#define IC3_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC3_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC3_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC3_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC3_CLR_INTR                                                                 0x1801B940
#define IC3_CLR_INTR_reg_addr                                                        "0xB801B940"
#define IC3_CLR_INTR_reg                                                             0xB801B940
#define set_IC3_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC3_CLR_INTR_reg)=data)
#define get_IC3_CLR_INTR_reg   (*((volatile unsigned int*) IC3_CLR_INTR_reg))
#define IC3_CLR_INTR_inst_adr                                                        "0x0050"
#define IC3_CLR_INTR_inst                                                            0x0050
#define IC3_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC3_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC3_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC3_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC3_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC3_CLR_RX_UNDER                                                             0x1801B944
#define IC3_CLR_RX_UNDER_reg_addr                                                    "0xB801B944"
#define IC3_CLR_RX_UNDER_reg                                                         0xB801B944
#define set_IC3_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC3_CLR_RX_UNDER_reg)=data)
#define get_IC3_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC3_CLR_RX_UNDER_reg))
#define IC3_CLR_RX_UNDER_inst_adr                                                    "0x0051"
#define IC3_CLR_RX_UNDER_inst                                                        0x0051
#define IC3_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC3_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC3_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC3_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC3_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC3_CLR_RX_OVER                                                              0x1801B948
#define IC3_CLR_RX_OVER_reg_addr                                                     "0xB801B948"
#define IC3_CLR_RX_OVER_reg                                                          0xB801B948
#define set_IC3_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC3_CLR_RX_OVER_reg)=data)
#define get_IC3_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC3_CLR_RX_OVER_reg))
#define IC3_CLR_RX_OVER_inst_adr                                                     "0x0052"
#define IC3_CLR_RX_OVER_inst                                                         0x0052
#define IC3_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC3_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC3_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC3_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC3_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC3_CLR_TX_OVER                                                              0x1801B94C
#define IC3_CLR_TX_OVER_reg_addr                                                     "0xB801B94C"
#define IC3_CLR_TX_OVER_reg                                                          0xB801B94C
#define set_IC3_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC3_CLR_TX_OVER_reg)=data)
#define get_IC3_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC3_CLR_TX_OVER_reg))
#define IC3_CLR_TX_OVER_inst_adr                                                     "0x0053"
#define IC3_CLR_TX_OVER_inst                                                         0x0053
#define IC3_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC3_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC3_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC3_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC3_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC3_CLR_RD_REQ                                                               0x1801B950
#define IC3_CLR_RD_REQ_reg_addr                                                      "0xB801B950"
#define IC3_CLR_RD_REQ_reg                                                           0xB801B950
#define set_IC3_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC3_CLR_RD_REQ_reg)=data)
#define get_IC3_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC3_CLR_RD_REQ_reg))
#define IC3_CLR_RD_REQ_inst_adr                                                      "0x0054"
#define IC3_CLR_RD_REQ_inst                                                          0x0054
#define IC3_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC3_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC3_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC3_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC3_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC3_CLR_TX_ABRT                                                              0x1801B954
#define IC3_CLR_TX_ABRT_reg_addr                                                     "0xB801B954"
#define IC3_CLR_TX_ABRT_reg                                                          0xB801B954
#define set_IC3_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC3_CLR_TX_ABRT_reg)=data)
#define get_IC3_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC3_CLR_TX_ABRT_reg))
#define IC3_CLR_TX_ABRT_inst_adr                                                     "0x0055"
#define IC3_CLR_TX_ABRT_inst                                                         0x0055
#define IC3_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC3_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC3_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC3_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC3_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC3_CLR_RX_DONE                                                              0x1801B958
#define IC3_CLR_RX_DONE_reg_addr                                                     "0xB801B958"
#define IC3_CLR_RX_DONE_reg                                                          0xB801B958
#define set_IC3_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC3_CLR_RX_DONE_reg)=data)
#define get_IC3_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC3_CLR_RX_DONE_reg))
#define IC3_CLR_RX_DONE_inst_adr                                                     "0x0056"
#define IC3_CLR_RX_DONE_inst                                                         0x0056
#define IC3_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC3_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC3_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC3_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC3_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC3_CLR_ACTIVITY                                                             0x1801B95C
#define IC3_CLR_ACTIVITY_reg_addr                                                    "0xB801B95C"
#define IC3_CLR_ACTIVITY_reg                                                         0xB801B95C
#define set_IC3_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC3_CLR_ACTIVITY_reg)=data)
#define get_IC3_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC3_CLR_ACTIVITY_reg))
#define IC3_CLR_ACTIVITY_inst_adr                                                    "0x0057"
#define IC3_CLR_ACTIVITY_inst                                                        0x0057
#define IC3_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC3_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC3_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC3_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC3_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC3_CLR_STOP_DET                                                             0x1801B960
#define IC3_CLR_STOP_DET_reg_addr                                                    "0xB801B960"
#define IC3_CLR_STOP_DET_reg                                                         0xB801B960
#define set_IC3_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC3_CLR_STOP_DET_reg)=data)
#define get_IC3_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC3_CLR_STOP_DET_reg))
#define IC3_CLR_STOP_DET_inst_adr                                                    "0x0058"
#define IC3_CLR_STOP_DET_inst                                                        0x0058
#define IC3_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC3_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC3_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC3_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC3_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC3_CLR_START_DET                                                            0x1801B964
#define IC3_CLR_START_DET_reg_addr                                                   "0xB801B964"
#define IC3_CLR_START_DET_reg                                                        0xB801B964
#define set_IC3_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC3_CLR_START_DET_reg)=data)
#define get_IC3_CLR_START_DET_reg   (*((volatile unsigned int*) IC3_CLR_START_DET_reg))
#define IC3_CLR_START_DET_inst_adr                                                   "0x0059"
#define IC3_CLR_START_DET_inst                                                       0x0059
#define IC3_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC3_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC3_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC3_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC3_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC3_CLR_GEN_CALL                                                             0x1801B968
#define IC3_CLR_GEN_CALL_reg_addr                                                    "0xB801B968"
#define IC3_CLR_GEN_CALL_reg                                                         0xB801B968
#define set_IC3_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC3_CLR_GEN_CALL_reg)=data)
#define get_IC3_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC3_CLR_GEN_CALL_reg))
#define IC3_CLR_GEN_CALL_inst_adr                                                    "0x005A"
#define IC3_CLR_GEN_CALL_inst                                                        0x005A
#define IC3_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC3_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC3_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC3_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC3_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC3_ENABLE                                                                   0x1801B96C
#define IC3_ENABLE_reg_addr                                                          "0xB801B96C"
#define IC3_ENABLE_reg                                                               0xB801B96C
#define set_IC3_ENABLE_reg(data)   (*((volatile unsigned int*) IC3_ENABLE_reg)=data)
#define get_IC3_ENABLE_reg   (*((volatile unsigned int*) IC3_ENABLE_reg))
#define IC3_ENABLE_inst_adr                                                          "0x005B"
#define IC3_ENABLE_inst                                                              0x005B
#define IC3_ENABLE_ENABLE_shift                                                      (0)
#define IC3_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC3_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC3_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC3_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC3_STATUS                                                                   0x1801B970
#define IC3_STATUS_reg_addr                                                          "0xB801B970"
#define IC3_STATUS_reg                                                               0xB801B970
#define set_IC3_STATUS_reg(data)   (*((volatile unsigned int*) IC3_STATUS_reg)=data)
#define get_IC3_STATUS_reg   (*((volatile unsigned int*) IC3_STATUS_reg))
#define IC3_STATUS_inst_adr                                                          "0x005C"
#define IC3_STATUS_inst                                                              0x005C
#define IC3_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC3_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC3_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC3_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC3_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC3_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC3_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC3_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC3_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC3_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC3_STATUS_RFF_shift                                                         (4)
#define IC3_STATUS_RFF_mask                                                          (0x00000010)
#define IC3_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC3_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC3_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC3_STATUS_RFNE_shift                                                        (3)
#define IC3_STATUS_RFNE_mask                                                         (0x00000008)
#define IC3_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC3_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC3_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC3_STATUS_TFE_shift                                                         (2)
#define IC3_STATUS_TFE_mask                                                          (0x00000004)
#define IC3_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC3_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC3_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC3_STATUS_TFNF_shift                                                        (1)
#define IC3_STATUS_TFNF_mask                                                         (0x00000002)
#define IC3_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC3_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC3_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC3_STATUS_ACTIVITY_shift                                                    (0)
#define IC3_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC3_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC3_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC3_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC3_TXFLR                                                                    0x1801B974
#define IC3_TXFLR_reg_addr                                                           "0xB801B974"
#define IC3_TXFLR_reg                                                                0xB801B974
#define set_IC3_TXFLR_reg(data)   (*((volatile unsigned int*) IC3_TXFLR_reg)=data)
#define get_IC3_TXFLR_reg   (*((volatile unsigned int*) IC3_TXFLR_reg))
#define IC3_TXFLR_inst_adr                                                           "0x005D"
#define IC3_TXFLR_inst                                                               0x005D
#define IC3_TXFLR_TXFLR_shift                                                        (0)
#define IC3_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC3_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC3_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC3_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC3_RXFLR                                                                    0x1801B978
#define IC3_RXFLR_reg_addr                                                           "0xB801B978"
#define IC3_RXFLR_reg                                                                0xB801B978
#define set_IC3_RXFLR_reg(data)   (*((volatile unsigned int*) IC3_RXFLR_reg)=data)
#define get_IC3_RXFLR_reg   (*((volatile unsigned int*) IC3_RXFLR_reg))
#define IC3_RXFLR_inst_adr                                                           "0x005E"
#define IC3_RXFLR_inst                                                               0x005E
#define IC3_RXFLR_RXFLR_shift                                                        (0)
#define IC3_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC3_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC3_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC3_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC3_SDA_HOLD                                                                 0x1801B97C
#define IC3_SDA_HOLD_reg_addr                                                        "0xB801B97C"
#define IC3_SDA_HOLD_reg                                                             0xB801B97C
#define set_IC3_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC3_SDA_HOLD_reg)=data)
#define get_IC3_SDA_HOLD_reg   (*((volatile unsigned int*) IC3_SDA_HOLD_reg))
#define IC3_SDA_HOLD_inst_adr                                                        "0x005F"
#define IC3_SDA_HOLD_inst                                                            0x005F
#define IC3_SDA_HOLD_SDA_HOLD_shift                                                  (0)
#define IC3_SDA_HOLD_SDA_HOLD_mask                                                   (0x0000FFFF)
#define IC3_SDA_HOLD_SDA_HOLD(data)                                                  (0x0000FFFF&((data)<<0))
#define IC3_SDA_HOLD_SDA_HOLD_src(data)                                              ((0x0000FFFF&(data))>>0)
#define IC3_SDA_HOLD_get_SDA_HOLD(data)                                              ((0x0000FFFF&(data))>>0)


#define IC3_TX_ABRT_SOURCE                                                           0x1801B980
#define IC3_TX_ABRT_SOURCE_reg_addr                                                  "0xB801B980"
#define IC3_TX_ABRT_SOURCE_reg                                                       0xB801B980
#define set_IC3_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC3_TX_ABRT_SOURCE_reg)=data)
#define get_IC3_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC3_TX_ABRT_SOURCE_reg))
#define IC3_TX_ABRT_SOURCE_inst_adr                                                  "0x0060"
#define IC3_TX_ABRT_SOURCE_inst                                                      0x0060
#define IC3_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC3_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC3_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC3_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC3_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC3_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC3_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC3_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC3_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC3_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC3_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC3_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC3_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC3_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC3_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC3_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC3_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC3_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC3_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC3_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC3_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC3_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC3_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC3_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC3_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC3_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC3_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC3_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC3_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC3_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC3_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC3_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC3_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC3_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC3_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC3_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC3_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC3_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC3_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC3_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC3_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC3_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC3_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC3_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC3_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC3_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC3_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC3_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC3_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC3_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC3_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC3_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC3_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC3_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC3_SLV_DATA_NACK_ONLY                                                       0x1801B984
#define IC3_SLV_DATA_NACK_ONLY_reg_addr                                              "0xB801B984"
#define IC3_SLV_DATA_NACK_ONLY_reg                                                   0xB801B984
#define set_IC3_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC3_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC3_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC3_SLV_DATA_NACK_ONLY_reg))
#define IC3_SLV_DATA_NACK_ONLY_inst_adr                                              "0x0061"
#define IC3_SLV_DATA_NACK_ONLY_inst                                                  0x0061
#define IC3_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC3_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC3_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC3_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC3_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC3_DMA_CR                                                                   0x1801B988
#define IC3_DMA_CR_reg_addr                                                          "0xB801B988"
#define IC3_DMA_CR_reg                                                               0xB801B988
#define set_IC3_DMA_CR_reg(data)   (*((volatile unsigned int*) IC3_DMA_CR_reg)=data)
#define get_IC3_DMA_CR_reg   (*((volatile unsigned int*) IC3_DMA_CR_reg))
#define IC3_DMA_CR_inst_adr                                                          "0x0062"
#define IC3_DMA_CR_inst                                                              0x0062
#define IC3_DMA_CR_TDMAE_shift                                                       (1)
#define IC3_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC3_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC3_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC3_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC3_DMA_CR_RDMAE_shift                                                       (0)
#define IC3_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC3_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC3_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC3_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC3_DMA_TDLR                                                                 0x1801B98C
#define IC3_DMA_TDLR_reg_addr                                                        "0xB801B98C"
#define IC3_DMA_TDLR_reg                                                             0xB801B98C
#define set_IC3_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC3_DMA_TDLR_reg)=data)
#define get_IC3_DMA_TDLR_reg   (*((volatile unsigned int*) IC3_DMA_TDLR_reg))
#define IC3_DMA_TDLR_inst_adr                                                        "0x0063"
#define IC3_DMA_TDLR_inst                                                            0x0063
#define IC3_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC3_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC3_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC3_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC3_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC3_DMA_RDLR                                                                 0x1801B990
#define IC3_DMA_RDLR_reg_addr                                                        "0xB801B990"
#define IC3_DMA_RDLR_reg                                                             0xB801B990
#define set_IC3_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC3_DMA_RDLR_reg)=data)
#define get_IC3_DMA_RDLR_reg   (*((volatile unsigned int*) IC3_DMA_RDLR_reg))
#define IC3_DMA_RDLR_inst_adr                                                        "0x0064"
#define IC3_DMA_RDLR_inst                                                            0x0064
#define IC3_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC3_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC3_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC3_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC3_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC3_SDA_SETUP                                                                0x1801B994
#define IC3_SDA_SETUP_reg_addr                                                       "0xB801B994"
#define IC3_SDA_SETUP_reg                                                            0xB801B994
#define set_IC3_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC3_SDA_SETUP_reg)=data)
#define get_IC3_SDA_SETUP_reg   (*((volatile unsigned int*) IC3_SDA_SETUP_reg))
#define IC3_SDA_SETUP_inst_adr                                                       "0x0065"
#define IC3_SDA_SETUP_inst                                                           0x0065
#define IC3_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC3_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC3_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC3_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC3_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC3_ACK_GENERAL_CALL                                                         0x1801B998
#define IC3_ACK_GENERAL_CALL_reg_addr                                                "0xB801B998"
#define IC3_ACK_GENERAL_CALL_reg                                                     0xB801B998
#define set_IC3_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC3_ACK_GENERAL_CALL_reg)=data)
#define get_IC3_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC3_ACK_GENERAL_CALL_reg))
#define IC3_ACK_GENERAL_CALL_inst_adr                                                "0x0066"
#define IC3_ACK_GENERAL_CALL_inst                                                    0x0066
#define IC3_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC3_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC3_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC3_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC3_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC3_ENABLE_STATUS                                                            0x1801B99C
#define IC3_ENABLE_STATUS_reg_addr                                                   "0xB801B99C"
#define IC3_ENABLE_STATUS_reg                                                        0xB801B99C
#define set_IC3_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC3_ENABLE_STATUS_reg)=data)
#define get_IC3_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC3_ENABLE_STATUS_reg))
#define IC3_ENABLE_STATUS_inst_adr                                                   "0x0067"
#define IC3_ENABLE_STATUS_inst                                                       0x0067
#define IC3_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC3_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC3_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC3_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC3_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC3_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC3_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC3_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC3_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC3_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC3_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC3_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC3_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC3_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC3_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC3_COMP_PARAM_1                                                             0x1801B9F4
#define IC3_COMP_PARAM_1_reg_addr                                                    "0xB801B9F4"
#define IC3_COMP_PARAM_1_reg                                                         0xB801B9F4
#define set_IC3_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC3_COMP_PARAM_1_reg)=data)
#define get_IC3_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC3_COMP_PARAM_1_reg))
#define IC3_COMP_PARAM_1_inst_adr                                                    "0x007D"
#define IC3_COMP_PARAM_1_inst                                                        0x007D
#define IC3_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC3_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC3_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC3_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC3_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC3_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC3_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC3_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC3_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC3_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC3_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC3_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC3_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC3_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC3_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC3_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC3_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC3_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC3_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC3_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC3_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC3_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC3_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC3_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC3_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC3_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC3_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC3_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC3_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC3_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC3_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC3_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC3_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC3_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC3_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC3_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC3_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC3_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC3_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC3_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC3_COMP_VERSION                                                             0x1801B9F8
#define IC3_COMP_VERSION_reg_addr                                                    "0xB801B9F8"
#define IC3_COMP_VERSION_reg                                                         0xB801B9F8
#define set_IC3_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC3_COMP_VERSION_reg)=data)
#define get_IC3_COMP_VERSION_reg   (*((volatile unsigned int*) IC3_COMP_VERSION_reg))
#define IC3_COMP_VERSION_inst_adr                                                    "0x007E"
#define IC3_COMP_VERSION_inst                                                        0x007E
#define IC3_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC3_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC3_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC3_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC3_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC3_COMP_TYPE                                                                0x1801B9FC
#define IC3_COMP_TYPE_reg_addr                                                       "0xB801B9FC"
#define IC3_COMP_TYPE_reg                                                            0xB801B9FC
#define set_IC3_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC3_COMP_TYPE_reg)=data)
#define get_IC3_COMP_TYPE_reg   (*((volatile unsigned int*) IC3_COMP_TYPE_reg))
#define IC3_COMP_TYPE_inst_adr                                                       "0x007F"
#define IC3_COMP_TYPE_inst                                                           0x007F
#define IC3_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC3_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC3_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC3_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC3_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IC4_CON                                                                      0x1801BA00
#define IC4_CON_reg_addr                                                             "0xB801BA00"
#define IC4_CON_reg                                                                  0xB801BA00
#define set_IC4_CON_reg(data)   (*((volatile unsigned int*) IC4_CON_reg)=data)
#define get_IC4_CON_reg   (*((volatile unsigned int*) IC4_CON_reg))
#define IC4_CON_inst_adr                                                             "0x0080"
#define IC4_CON_inst                                                                 0x0080
#define IC4_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC4_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC4_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC4_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC4_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC4_CON_IC_RESTART_EN_shift                                                  (5)
#define IC4_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC4_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC4_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC4_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC4_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC4_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC4_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC4_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC4_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC4_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC4_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC4_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC4_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC4_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC4_CON_SPEED_shift                                                          (1)
#define IC4_CON_SPEED_mask                                                           (0x00000006)
#define IC4_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC4_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC4_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC4_CON_MASTER_MODE_shift                                                    (0)
#define IC4_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC4_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC4_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC4_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC4_TAR                                                                      0x1801BA04
#define IC4_TAR_reg_addr                                                             "0xB801BA04"
#define IC4_TAR_reg                                                                  0xB801BA04
#define set_IC4_TAR_reg(data)   (*((volatile unsigned int*) IC4_TAR_reg)=data)
#define get_IC4_TAR_reg   (*((volatile unsigned int*) IC4_TAR_reg))
#define IC4_TAR_inst_adr                                                             "0x0081"
#define IC4_TAR_inst                                                                 0x0081
#define IC4_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC4_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC4_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC4_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC4_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC4_TAR_SPECIAL_shift                                                        (11)
#define IC4_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC4_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC4_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC4_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC4_TAR_GC_OR_START_shift                                                    (10)
#define IC4_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC4_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC4_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC4_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC4_TAR_IC_TAR_shift                                                         (0)
#define IC4_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC4_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC4_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC4_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC4_SAR                                                                      0x1801BA08
#define IC4_SAR_reg_addr                                                             "0xB801BA08"
#define IC4_SAR_reg                                                                  0xB801BA08
#define set_IC4_SAR_reg(data)   (*((volatile unsigned int*) IC4_SAR_reg)=data)
#define get_IC4_SAR_reg   (*((volatile unsigned int*) IC4_SAR_reg))
#define IC4_SAR_inst_adr                                                             "0x0082"
#define IC4_SAR_inst                                                                 0x0082
#define IC4_SAR_IC_SAR_shift                                                         (0)
#define IC4_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC4_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC4_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC4_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC4_HS_MADDR                                                                 0x1801BA0C
#define IC4_HS_MADDR_reg_addr                                                        "0xB801BA0C"
#define IC4_HS_MADDR_reg                                                             0xB801BA0C
#define set_IC4_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC4_HS_MADDR_reg)=data)
#define get_IC4_HS_MADDR_reg   (*((volatile unsigned int*) IC4_HS_MADDR_reg))
#define IC4_HS_MADDR_inst_adr                                                        "0x0083"
#define IC4_HS_MADDR_inst                                                            0x0083
#define IC4_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC4_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC4_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC4_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC4_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC4_DATA_CMD                                                                 0x1801BA10
#define IC4_DATA_CMD_reg_addr                                                        "0xB801BA10"
#define IC4_DATA_CMD_reg                                                             0xB801BA10
#define set_IC4_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC4_DATA_CMD_reg)=data)
#define get_IC4_DATA_CMD_reg   (*((volatile unsigned int*) IC4_DATA_CMD_reg))
#define IC4_DATA_CMD_inst_adr                                                        "0x0084"
#define IC4_DATA_CMD_inst                                                            0x0084
#define IC4_DATA_CMD_RESTART_shift                                                   (10)
#define IC4_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC4_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC4_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC4_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC4_DATA_CMD_STOP_shift                                                      (9)
#define IC4_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC4_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC4_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC4_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC4_DATA_CMD_CMD_shift                                                       (8)
#define IC4_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC4_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC4_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC4_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC4_DATA_CMD_DAT_shift                                                       (0)
#define IC4_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC4_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC4_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC4_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC4_SS_SCL_HCNT                                                              0x1801BA14
#define IC4_SS_SCL_HCNT_reg_addr                                                     "0xB801BA14"
#define IC4_SS_SCL_HCNT_reg                                                          0xB801BA14
#define set_IC4_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC4_SS_SCL_HCNT_reg)=data)
#define get_IC4_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC4_SS_SCL_HCNT_reg))
#define IC4_SS_SCL_HCNT_inst_adr                                                     "0x0085"
#define IC4_SS_SCL_HCNT_inst                                                         0x0085
#define IC4_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC4_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC4_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC4_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC4_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC4_SS_SCL_LCNT                                                              0x1801BA18
#define IC4_SS_SCL_LCNT_reg_addr                                                     "0xB801BA18"
#define IC4_SS_SCL_LCNT_reg                                                          0xB801BA18
#define set_IC4_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC4_SS_SCL_LCNT_reg)=data)
#define get_IC4_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC4_SS_SCL_LCNT_reg))
#define IC4_SS_SCL_LCNT_inst_adr                                                     "0x0086"
#define IC4_SS_SCL_LCNT_inst                                                         0x0086
#define IC4_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC4_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC4_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC4_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC4_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC4_FS_SCL_HCNT                                                              0x1801BA1C
#define IC4_FS_SCL_HCNT_reg_addr                                                     "0xB801BA1C"
#define IC4_FS_SCL_HCNT_reg                                                          0xB801BA1C
#define set_IC4_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC4_FS_SCL_HCNT_reg)=data)
#define get_IC4_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC4_FS_SCL_HCNT_reg))
#define IC4_FS_SCL_HCNT_inst_adr                                                     "0x0087"
#define IC4_FS_SCL_HCNT_inst                                                         0x0087
#define IC4_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC4_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC4_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC4_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC4_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC4_FS_SCL_LCNT                                                              0x1801BA20
#define IC4_FS_SCL_LCNT_reg_addr                                                     "0xB801BA20"
#define IC4_FS_SCL_LCNT_reg                                                          0xB801BA20
#define set_IC4_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC4_FS_SCL_LCNT_reg)=data)
#define get_IC4_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC4_FS_SCL_LCNT_reg))
#define IC4_FS_SCL_LCNT_inst_adr                                                     "0x0088"
#define IC4_FS_SCL_LCNT_inst                                                         0x0088
#define IC4_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC4_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC4_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC4_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC4_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC4_INTR_STAT                                                                0x1801BA2C
#define IC4_INTR_STAT_reg_addr                                                       "0xB801BA2C"
#define IC4_INTR_STAT_reg                                                            0xB801BA2C
#define set_IC4_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC4_INTR_STAT_reg)=data)
#define get_IC4_INTR_STAT_reg   (*((volatile unsigned int*) IC4_INTR_STAT_reg))
#define IC4_INTR_STAT_inst_adr                                                       "0x008B"
#define IC4_INTR_STAT_inst                                                           0x008B
#define IC4_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC4_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC4_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC4_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC4_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC4_INTR_STAT_R_START_DET_shift                                              (10)
#define IC4_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC4_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC4_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC4_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC4_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC4_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC4_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC4_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC4_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC4_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC4_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC4_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC4_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC4_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC4_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC4_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC4_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC4_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC4_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC4_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC4_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC4_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC4_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC4_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC4_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC4_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC4_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC4_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC4_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC4_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC4_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC4_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC4_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC4_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC4_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC4_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC4_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC4_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC4_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC4_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC4_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC4_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC4_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC4_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC4_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC4_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC4_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC4_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC4_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC4_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC4_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC4_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC4_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC4_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC4_INTR_MASK                                                                0x1801BA30
#define IC4_INTR_MASK_reg_addr                                                       "0xB801BA30"
#define IC4_INTR_MASK_reg                                                            0xB801BA30
#define set_IC4_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC4_INTR_MASK_reg)=data)
#define get_IC4_INTR_MASK_reg   (*((volatile unsigned int*) IC4_INTR_MASK_reg))
#define IC4_INTR_MASK_inst_adr                                                       "0x008C"
#define IC4_INTR_MASK_inst                                                           0x008C
#define IC4_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC4_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC4_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC4_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC4_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC4_INTR_MASK_M_START_DET_shift                                              (10)
#define IC4_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC4_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC4_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC4_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC4_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC4_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC4_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC4_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC4_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC4_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC4_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC4_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC4_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC4_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC4_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC4_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC4_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC4_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC4_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC4_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC4_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC4_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC4_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC4_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC4_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC4_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC4_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC4_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC4_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC4_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC4_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC4_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC4_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC4_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC4_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC4_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC4_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC4_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC4_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC4_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC4_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC4_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC4_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC4_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC4_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC4_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC4_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC4_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC4_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC4_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC4_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC4_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC4_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC4_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC4_RAW_INTR_STAT                                                            0x1801BA34
#define IC4_RAW_INTR_STAT_reg_addr                                                   "0xB801BA34"
#define IC4_RAW_INTR_STAT_reg                                                        0xB801BA34
#define set_IC4_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC4_RAW_INTR_STAT_reg)=data)
#define get_IC4_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC4_RAW_INTR_STAT_reg))
#define IC4_RAW_INTR_STAT_inst_adr                                                   "0x008D"
#define IC4_RAW_INTR_STAT_inst                                                       0x008D
#define IC4_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC4_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC4_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC4_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC4_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC4_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC4_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC4_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC4_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC4_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC4_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC4_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC4_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC4_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC4_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC4_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC4_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC4_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC4_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC4_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC4_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC4_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC4_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC4_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC4_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC4_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC4_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC4_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC4_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC4_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC4_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC4_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC4_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC4_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC4_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC4_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC4_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC4_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC4_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC4_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC4_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC4_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC4_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC4_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC4_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC4_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC4_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC4_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC4_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC4_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC4_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC4_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC4_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC4_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC4_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC4_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC4_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC4_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC4_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC4_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC4_RX_TL                                                                    0x1801BA38
#define IC4_RX_TL_reg_addr                                                           "0xB801BA38"
#define IC4_RX_TL_reg                                                                0xB801BA38
#define set_IC4_RX_TL_reg(data)   (*((volatile unsigned int*) IC4_RX_TL_reg)=data)
#define get_IC4_RX_TL_reg   (*((volatile unsigned int*) IC4_RX_TL_reg))
#define IC4_RX_TL_inst_adr                                                           "0x008E"
#define IC4_RX_TL_inst                                                               0x008E
#define IC4_RX_TL_RX_TL_shift                                                        (0)
#define IC4_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC4_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC4_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC4_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC4_TX_TL                                                                    0x1801BA3C
#define IC4_TX_TL_reg_addr                                                           "0xB801BA3C"
#define IC4_TX_TL_reg                                                                0xB801BA3C
#define set_IC4_TX_TL_reg(data)   (*((volatile unsigned int*) IC4_TX_TL_reg)=data)
#define get_IC4_TX_TL_reg   (*((volatile unsigned int*) IC4_TX_TL_reg))
#define IC4_TX_TL_inst_adr                                                           "0x008F"
#define IC4_TX_TL_inst                                                               0x008F
#define IC4_TX_TL_TX_TL_shift                                                        (0)
#define IC4_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC4_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC4_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC4_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC4_CLR_INTR                                                                 0x1801BA40
#define IC4_CLR_INTR_reg_addr                                                        "0xB801BA40"
#define IC4_CLR_INTR_reg                                                             0xB801BA40
#define set_IC4_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC4_CLR_INTR_reg)=data)
#define get_IC4_CLR_INTR_reg   (*((volatile unsigned int*) IC4_CLR_INTR_reg))
#define IC4_CLR_INTR_inst_adr                                                        "0x0090"
#define IC4_CLR_INTR_inst                                                            0x0090
#define IC4_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC4_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC4_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC4_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC4_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC4_CLR_RX_UNDER                                                             0x1801BA44
#define IC4_CLR_RX_UNDER_reg_addr                                                    "0xB801BA44"
#define IC4_CLR_RX_UNDER_reg                                                         0xB801BA44
#define set_IC4_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC4_CLR_RX_UNDER_reg)=data)
#define get_IC4_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC4_CLR_RX_UNDER_reg))
#define IC4_CLR_RX_UNDER_inst_adr                                                    "0x0091"
#define IC4_CLR_RX_UNDER_inst                                                        0x0091
#define IC4_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC4_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC4_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC4_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC4_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC4_CLR_RX_OVER                                                              0x1801BA48
#define IC4_CLR_RX_OVER_reg_addr                                                     "0xB801BA48"
#define IC4_CLR_RX_OVER_reg                                                          0xB801BA48
#define set_IC4_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC4_CLR_RX_OVER_reg)=data)
#define get_IC4_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC4_CLR_RX_OVER_reg))
#define IC4_CLR_RX_OVER_inst_adr                                                     "0x0092"
#define IC4_CLR_RX_OVER_inst                                                         0x0092
#define IC4_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC4_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC4_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC4_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC4_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC4_CLR_TX_OVER                                                              0x1801BA4C
#define IC4_CLR_TX_OVER_reg_addr                                                     "0xB801BA4C"
#define IC4_CLR_TX_OVER_reg                                                          0xB801BA4C
#define set_IC4_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC4_CLR_TX_OVER_reg)=data)
#define get_IC4_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC4_CLR_TX_OVER_reg))
#define IC4_CLR_TX_OVER_inst_adr                                                     "0x0093"
#define IC4_CLR_TX_OVER_inst                                                         0x0093
#define IC4_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC4_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC4_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC4_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC4_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC4_CLR_RD_REQ                                                               0x1801BA50
#define IC4_CLR_RD_REQ_reg_addr                                                      "0xB801BA50"
#define IC4_CLR_RD_REQ_reg                                                           0xB801BA50
#define set_IC4_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC4_CLR_RD_REQ_reg)=data)
#define get_IC4_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC4_CLR_RD_REQ_reg))
#define IC4_CLR_RD_REQ_inst_adr                                                      "0x0094"
#define IC4_CLR_RD_REQ_inst                                                          0x0094
#define IC4_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC4_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC4_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC4_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC4_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC4_CLR_TX_ABRT                                                              0x1801BA54
#define IC4_CLR_TX_ABRT_reg_addr                                                     "0xB801BA54"
#define IC4_CLR_TX_ABRT_reg                                                          0xB801BA54
#define set_IC4_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC4_CLR_TX_ABRT_reg)=data)
#define get_IC4_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC4_CLR_TX_ABRT_reg))
#define IC4_CLR_TX_ABRT_inst_adr                                                     "0x0095"
#define IC4_CLR_TX_ABRT_inst                                                         0x0095
#define IC4_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC4_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC4_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC4_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC4_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC4_CLR_RX_DONE                                                              0x1801BA58
#define IC4_CLR_RX_DONE_reg_addr                                                     "0xB801BA58"
#define IC4_CLR_RX_DONE_reg                                                          0xB801BA58
#define set_IC4_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC4_CLR_RX_DONE_reg)=data)
#define get_IC4_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC4_CLR_RX_DONE_reg))
#define IC4_CLR_RX_DONE_inst_adr                                                     "0x0096"
#define IC4_CLR_RX_DONE_inst                                                         0x0096
#define IC4_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC4_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC4_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC4_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC4_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC4_CLR_ACTIVITY                                                             0x1801BA5C
#define IC4_CLR_ACTIVITY_reg_addr                                                    "0xB801BA5C"
#define IC4_CLR_ACTIVITY_reg                                                         0xB801BA5C
#define set_IC4_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC4_CLR_ACTIVITY_reg)=data)
#define get_IC4_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC4_CLR_ACTIVITY_reg))
#define IC4_CLR_ACTIVITY_inst_adr                                                    "0x0097"
#define IC4_CLR_ACTIVITY_inst                                                        0x0097
#define IC4_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC4_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC4_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC4_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC4_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC4_CLR_STOP_DET                                                             0x1801BA60
#define IC4_CLR_STOP_DET_reg_addr                                                    "0xB801BA60"
#define IC4_CLR_STOP_DET_reg                                                         0xB801BA60
#define set_IC4_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC4_CLR_STOP_DET_reg)=data)
#define get_IC4_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC4_CLR_STOP_DET_reg))
#define IC4_CLR_STOP_DET_inst_adr                                                    "0x0098"
#define IC4_CLR_STOP_DET_inst                                                        0x0098
#define IC4_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC4_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC4_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC4_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC4_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC4_CLR_START_DET                                                            0x1801BA64
#define IC4_CLR_START_DET_reg_addr                                                   "0xB801BA64"
#define IC4_CLR_START_DET_reg                                                        0xB801BA64
#define set_IC4_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC4_CLR_START_DET_reg)=data)
#define get_IC4_CLR_START_DET_reg   (*((volatile unsigned int*) IC4_CLR_START_DET_reg))
#define IC4_CLR_START_DET_inst_adr                                                   "0x0099"
#define IC4_CLR_START_DET_inst                                                       0x0099
#define IC4_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC4_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC4_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC4_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC4_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC4_CLR_GEN_CALL                                                             0x1801BA68
#define IC4_CLR_GEN_CALL_reg_addr                                                    "0xB801BA68"
#define IC4_CLR_GEN_CALL_reg                                                         0xB801BA68
#define set_IC4_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC4_CLR_GEN_CALL_reg)=data)
#define get_IC4_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC4_CLR_GEN_CALL_reg))
#define IC4_CLR_GEN_CALL_inst_adr                                                    "0x009A"
#define IC4_CLR_GEN_CALL_inst                                                        0x009A
#define IC4_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC4_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC4_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC4_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC4_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC4_ENABLE                                                                   0x1801BA6C
#define IC4_ENABLE_reg_addr                                                          "0xB801BA6C"
#define IC4_ENABLE_reg                                                               0xB801BA6C
#define set_IC4_ENABLE_reg(data)   (*((volatile unsigned int*) IC4_ENABLE_reg)=data)
#define get_IC4_ENABLE_reg   (*((volatile unsigned int*) IC4_ENABLE_reg))
#define IC4_ENABLE_inst_adr                                                          "0x009B"
#define IC4_ENABLE_inst                                                              0x009B
#define IC4_ENABLE_ENABLE_shift                                                      (0)
#define IC4_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC4_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC4_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC4_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC4_STATUS                                                                   0x1801BA70
#define IC4_STATUS_reg_addr                                                          "0xB801BA70"
#define IC4_STATUS_reg                                                               0xB801BA70
#define set_IC4_STATUS_reg(data)   (*((volatile unsigned int*) IC4_STATUS_reg)=data)
#define get_IC4_STATUS_reg   (*((volatile unsigned int*) IC4_STATUS_reg))
#define IC4_STATUS_inst_adr                                                          "0x009C"
#define IC4_STATUS_inst                                                              0x009C
#define IC4_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC4_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC4_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC4_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC4_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC4_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC4_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC4_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC4_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC4_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC4_STATUS_RFF_shift                                                         (4)
#define IC4_STATUS_RFF_mask                                                          (0x00000010)
#define IC4_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC4_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC4_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC4_STATUS_RFNE_shift                                                        (3)
#define IC4_STATUS_RFNE_mask                                                         (0x00000008)
#define IC4_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC4_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC4_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC4_STATUS_TFE_shift                                                         (2)
#define IC4_STATUS_TFE_mask                                                          (0x00000004)
#define IC4_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC4_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC4_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC4_STATUS_TFNF_shift                                                        (1)
#define IC4_STATUS_TFNF_mask                                                         (0x00000002)
#define IC4_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC4_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC4_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC4_STATUS_ACTIVITY_shift                                                    (0)
#define IC4_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC4_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC4_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC4_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC4_TXFLR                                                                    0x1801BA74
#define IC4_TXFLR_reg_addr                                                           "0xB801BA74"
#define IC4_TXFLR_reg                                                                0xB801BA74
#define set_IC4_TXFLR_reg(data)   (*((volatile unsigned int*) IC4_TXFLR_reg)=data)
#define get_IC4_TXFLR_reg   (*((volatile unsigned int*) IC4_TXFLR_reg))
#define IC4_TXFLR_inst_adr                                                           "0x009D"
#define IC4_TXFLR_inst                                                               0x009D
#define IC4_TXFLR_TXFLR_shift                                                        (0)
#define IC4_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC4_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC4_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC4_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC4_RXFLR                                                                    0x1801BA78
#define IC4_RXFLR_reg_addr                                                           "0xB801BA78"
#define IC4_RXFLR_reg                                                                0xB801BA78
#define set_IC4_RXFLR_reg(data)   (*((volatile unsigned int*) IC4_RXFLR_reg)=data)
#define get_IC4_RXFLR_reg   (*((volatile unsigned int*) IC4_RXFLR_reg))
#define IC4_RXFLR_inst_adr                                                           "0x009E"
#define IC4_RXFLR_inst                                                               0x009E
#define IC4_RXFLR_RXFLR_shift                                                        (0)
#define IC4_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC4_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC4_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC4_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC4_SDA_HOLD                                                                 0x1801BA7C
#define IC4_SDA_HOLD_reg_addr                                                        "0xB801BA7C"
#define IC4_SDA_HOLD_reg                                                             0xB801BA7C
#define set_IC4_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC4_SDA_HOLD_reg)=data)
#define get_IC4_SDA_HOLD_reg   (*((volatile unsigned int*) IC4_SDA_HOLD_reg))
#define IC4_SDA_HOLD_inst_adr                                                        "0x009F"
#define IC4_SDA_HOLD_inst                                                            0x009F
#define IC4_SDA_HOLD_SDA_HOLD_shift                                                  (0)
#define IC4_SDA_HOLD_SDA_HOLD_mask                                                   (0x0000FFFF)
#define IC4_SDA_HOLD_SDA_HOLD(data)                                                  (0x0000FFFF&((data)<<0))
#define IC4_SDA_HOLD_SDA_HOLD_src(data)                                              ((0x0000FFFF&(data))>>0)
#define IC4_SDA_HOLD_get_SDA_HOLD(data)                                              ((0x0000FFFF&(data))>>0)


#define IC4_TX_ABRT_SOURCE                                                           0x1801BA80
#define IC4_TX_ABRT_SOURCE_reg_addr                                                  "0xB801BA80"
#define IC4_TX_ABRT_SOURCE_reg                                                       0xB801BA80
#define set_IC4_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC4_TX_ABRT_SOURCE_reg)=data)
#define get_IC4_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC4_TX_ABRT_SOURCE_reg))
#define IC4_TX_ABRT_SOURCE_inst_adr                                                  "0x00A0"
#define IC4_TX_ABRT_SOURCE_inst                                                      0x00A0
#define IC4_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC4_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC4_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC4_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC4_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC4_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC4_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC4_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC4_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC4_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC4_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC4_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC4_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC4_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC4_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC4_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC4_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC4_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC4_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC4_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC4_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC4_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC4_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC4_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC4_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC4_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC4_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC4_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC4_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC4_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC4_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC4_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC4_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC4_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC4_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC4_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC4_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC4_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC4_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC4_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC4_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC4_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC4_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC4_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC4_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC4_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC4_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC4_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC4_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC4_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC4_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC4_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC4_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC4_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC4_SLV_DATA_NACK_ONLY                                                       0x1801BA84
#define IC4_SLV_DATA_NACK_ONLY_reg_addr                                              "0xB801BA84"
#define IC4_SLV_DATA_NACK_ONLY_reg                                                   0xB801BA84
#define set_IC4_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC4_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC4_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC4_SLV_DATA_NACK_ONLY_reg))
#define IC4_SLV_DATA_NACK_ONLY_inst_adr                                              "0x00A1"
#define IC4_SLV_DATA_NACK_ONLY_inst                                                  0x00A1
#define IC4_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC4_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC4_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC4_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC4_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC4_DMA_CR                                                                   0x1801BA88
#define IC4_DMA_CR_reg_addr                                                          "0xB801BA88"
#define IC4_DMA_CR_reg                                                               0xB801BA88
#define set_IC4_DMA_CR_reg(data)   (*((volatile unsigned int*) IC4_DMA_CR_reg)=data)
#define get_IC4_DMA_CR_reg   (*((volatile unsigned int*) IC4_DMA_CR_reg))
#define IC4_DMA_CR_inst_adr                                                          "0x00A2"
#define IC4_DMA_CR_inst                                                              0x00A2
#define IC4_DMA_CR_TDMAE_shift                                                       (1)
#define IC4_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC4_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC4_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC4_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC4_DMA_CR_RDMAE_shift                                                       (0)
#define IC4_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC4_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC4_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC4_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC4_DMA_TDLR                                                                 0x1801BA8C
#define IC4_DMA_TDLR_reg_addr                                                        "0xB801BA8C"
#define IC4_DMA_TDLR_reg                                                             0xB801BA8C
#define set_IC4_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC4_DMA_TDLR_reg)=data)
#define get_IC4_DMA_TDLR_reg   (*((volatile unsigned int*) IC4_DMA_TDLR_reg))
#define IC4_DMA_TDLR_inst_adr                                                        "0x00A3"
#define IC4_DMA_TDLR_inst                                                            0x00A3
#define IC4_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC4_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC4_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC4_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC4_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC4_DMA_RDLR                                                                 0x1801BA90
#define IC4_DMA_RDLR_reg_addr                                                        "0xB801BA90"
#define IC4_DMA_RDLR_reg                                                             0xB801BA90
#define set_IC4_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC4_DMA_RDLR_reg)=data)
#define get_IC4_DMA_RDLR_reg   (*((volatile unsigned int*) IC4_DMA_RDLR_reg))
#define IC4_DMA_RDLR_inst_adr                                                        "0x00A4"
#define IC4_DMA_RDLR_inst                                                            0x00A4
#define IC4_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC4_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC4_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC4_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC4_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC4_SDA_SETUP                                                                0x1801BA94
#define IC4_SDA_SETUP_reg_addr                                                       "0xB801BA94"
#define IC4_SDA_SETUP_reg                                                            0xB801BA94
#define set_IC4_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC4_SDA_SETUP_reg)=data)
#define get_IC4_SDA_SETUP_reg   (*((volatile unsigned int*) IC4_SDA_SETUP_reg))
#define IC4_SDA_SETUP_inst_adr                                                       "0x00A5"
#define IC4_SDA_SETUP_inst                                                           0x00A5
#define IC4_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC4_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC4_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC4_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC4_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC4_ACK_GENERAL_CALL                                                         0x1801BA98
#define IC4_ACK_GENERAL_CALL_reg_addr                                                "0xB801BA98"
#define IC4_ACK_GENERAL_CALL_reg                                                     0xB801BA98
#define set_IC4_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC4_ACK_GENERAL_CALL_reg)=data)
#define get_IC4_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC4_ACK_GENERAL_CALL_reg))
#define IC4_ACK_GENERAL_CALL_inst_adr                                                "0x00A6"
#define IC4_ACK_GENERAL_CALL_inst                                                    0x00A6
#define IC4_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC4_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC4_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC4_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC4_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC4_ENABLE_STATUS                                                            0x1801BA9C
#define IC4_ENABLE_STATUS_reg_addr                                                   "0xB801BA9C"
#define IC4_ENABLE_STATUS_reg                                                        0xB801BA9C
#define set_IC4_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC4_ENABLE_STATUS_reg)=data)
#define get_IC4_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC4_ENABLE_STATUS_reg))
#define IC4_ENABLE_STATUS_inst_adr                                                   "0x00A7"
#define IC4_ENABLE_STATUS_inst                                                       0x00A7
#define IC4_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC4_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC4_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC4_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC4_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC4_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC4_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC4_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC4_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC4_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC4_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC4_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC4_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC4_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC4_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC4_COMP_PARAM_1                                                             0x1801BAF4
#define IC4_COMP_PARAM_1_reg_addr                                                    "0xB801BAF4"
#define IC4_COMP_PARAM_1_reg                                                         0xB801BAF4
#define set_IC4_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC4_COMP_PARAM_1_reg)=data)
#define get_IC4_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC4_COMP_PARAM_1_reg))
#define IC4_COMP_PARAM_1_inst_adr                                                    "0x00BD"
#define IC4_COMP_PARAM_1_inst                                                        0x00BD
#define IC4_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC4_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC4_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC4_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC4_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC4_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC4_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC4_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC4_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC4_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC4_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC4_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC4_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC4_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC4_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC4_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC4_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC4_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC4_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC4_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC4_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC4_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC4_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC4_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC4_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC4_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC4_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC4_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC4_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC4_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC4_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC4_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC4_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC4_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC4_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC4_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC4_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC4_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC4_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC4_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC4_COMP_VERSION                                                             0x1801BAF8
#define IC4_COMP_VERSION_reg_addr                                                    "0xB801BAF8"
#define IC4_COMP_VERSION_reg                                                         0xB801BAF8
#define set_IC4_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC4_COMP_VERSION_reg)=data)
#define get_IC4_COMP_VERSION_reg   (*((volatile unsigned int*) IC4_COMP_VERSION_reg))
#define IC4_COMP_VERSION_inst_adr                                                    "0x00BE"
#define IC4_COMP_VERSION_inst                                                        0x00BE
#define IC4_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC4_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC4_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC4_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC4_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC4_COMP_TYPE                                                                0x1801BAFC
#define IC4_COMP_TYPE_reg_addr                                                       "0xB801BAFC"
#define IC4_COMP_TYPE_reg                                                            0xB801BAFC
#define set_IC4_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC4_COMP_TYPE_reg)=data)
#define get_IC4_COMP_TYPE_reg   (*((volatile unsigned int*) IC4_COMP_TYPE_reg))
#define IC4_COMP_TYPE_inst_adr                                                       "0x00BF"
#define IC4_COMP_TYPE_inst                                                           0x00BF
#define IC4_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC4_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC4_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC4_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC4_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IC5_CON                                                                      0x1801BB00
#define IC5_CON_reg_addr                                                             "0xB801BB00"
#define IC5_CON_reg                                                                  0xB801BB00
#define set_IC5_CON_reg(data)   (*((volatile unsigned int*) IC5_CON_reg)=data)
#define get_IC5_CON_reg   (*((volatile unsigned int*) IC5_CON_reg))
#define IC5_CON_inst_adr                                                             "0x00C0"
#define IC5_CON_inst                                                                 0x00C0
#define IC5_CON_IC_SLAVE_DISABLE_shift                                               (6)
#define IC5_CON_IC_SLAVE_DISABLE_mask                                                (0x00000040)
#define IC5_CON_IC_SLAVE_DISABLE(data)                                               (0x00000040&((data)<<6))
#define IC5_CON_IC_SLAVE_DISABLE_src(data)                                           ((0x00000040&(data))>>6)
#define IC5_CON_get_IC_SLAVE_DISABLE(data)                                           ((0x00000040&(data))>>6)
#define IC5_CON_IC_RESTART_EN_shift                                                  (5)
#define IC5_CON_IC_RESTART_EN_mask                                                   (0x00000020)
#define IC5_CON_IC_RESTART_EN(data)                                                  (0x00000020&((data)<<5))
#define IC5_CON_IC_RESTART_EN_src(data)                                              ((0x00000020&(data))>>5)
#define IC5_CON_get_IC_RESTART_EN(data)                                              ((0x00000020&(data))>>5)
#define IC5_CON_IC_10BITADDR_MASTER_shift                                            (4)
#define IC5_CON_IC_10BITADDR_MASTER_mask                                             (0x00000010)
#define IC5_CON_IC_10BITADDR_MASTER(data)                                            (0x00000010&((data)<<4))
#define IC5_CON_IC_10BITADDR_MASTER_src(data)                                        ((0x00000010&(data))>>4)
#define IC5_CON_get_IC_10BITADDR_MASTER(data)                                        ((0x00000010&(data))>>4)
#define IC5_CON_IC_10BITADDR_SLAVE_shift                                             (3)
#define IC5_CON_IC_10BITADDR_SLAVE_mask                                              (0x00000008)
#define IC5_CON_IC_10BITADDR_SLAVE(data)                                             (0x00000008&((data)<<3))
#define IC5_CON_IC_10BITADDR_SLAVE_src(data)                                         ((0x00000008&(data))>>3)
#define IC5_CON_get_IC_10BITADDR_SLAVE(data)                                         ((0x00000008&(data))>>3)
#define IC5_CON_SPEED_shift                                                          (1)
#define IC5_CON_SPEED_mask                                                           (0x00000006)
#define IC5_CON_SPEED(data)                                                          (0x00000006&((data)<<1))
#define IC5_CON_SPEED_src(data)                                                      ((0x00000006&(data))>>1)
#define IC5_CON_get_SPEED(data)                                                      ((0x00000006&(data))>>1)
#define IC5_CON_MASTER_MODE_shift                                                    (0)
#define IC5_CON_MASTER_MODE_mask                                                     (0x00000001)
#define IC5_CON_MASTER_MODE(data)                                                    (0x00000001&((data)<<0))
#define IC5_CON_MASTER_MODE_src(data)                                                ((0x00000001&(data))>>0)
#define IC5_CON_get_MASTER_MODE(data)                                                ((0x00000001&(data))>>0)


#define IC5_TAR                                                                      0x1801BB04
#define IC5_TAR_reg_addr                                                             "0xB801BB04"
#define IC5_TAR_reg                                                                  0xB801BB04
#define set_IC5_TAR_reg(data)   (*((volatile unsigned int*) IC5_TAR_reg)=data)
#define get_IC5_TAR_reg   (*((volatile unsigned int*) IC5_TAR_reg))
#define IC5_TAR_inst_adr                                                             "0x00C1"
#define IC5_TAR_inst                                                                 0x00C1
#define IC5_TAR_IC_10BITADDR_MASTER_shift                                            (12)
#define IC5_TAR_IC_10BITADDR_MASTER_mask                                             (0x00001000)
#define IC5_TAR_IC_10BITADDR_MASTER(data)                                            (0x00001000&((data)<<12))
#define IC5_TAR_IC_10BITADDR_MASTER_src(data)                                        ((0x00001000&(data))>>12)
#define IC5_TAR_get_IC_10BITADDR_MASTER(data)                                        ((0x00001000&(data))>>12)
#define IC5_TAR_SPECIAL_shift                                                        (11)
#define IC5_TAR_SPECIAL_mask                                                         (0x00000800)
#define IC5_TAR_SPECIAL(data)                                                        (0x00000800&((data)<<11))
#define IC5_TAR_SPECIAL_src(data)                                                    ((0x00000800&(data))>>11)
#define IC5_TAR_get_SPECIAL(data)                                                    ((0x00000800&(data))>>11)
#define IC5_TAR_GC_OR_START_shift                                                    (10)
#define IC5_TAR_GC_OR_START_mask                                                     (0x00000400)
#define IC5_TAR_GC_OR_START(data)                                                    (0x00000400&((data)<<10))
#define IC5_TAR_GC_OR_START_src(data)                                                ((0x00000400&(data))>>10)
#define IC5_TAR_get_GC_OR_START(data)                                                ((0x00000400&(data))>>10)
#define IC5_TAR_IC_TAR_shift                                                         (0)
#define IC5_TAR_IC_TAR_mask                                                          (0x000003FF)
#define IC5_TAR_IC_TAR(data)                                                         (0x000003FF&((data)<<0))
#define IC5_TAR_IC_TAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC5_TAR_get_IC_TAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC5_SAR                                                                      0x1801BB08
#define IC5_SAR_reg_addr                                                             "0xB801BB08"
#define IC5_SAR_reg                                                                  0xB801BB08
#define set_IC5_SAR_reg(data)   (*((volatile unsigned int*) IC5_SAR_reg)=data)
#define get_IC5_SAR_reg   (*((volatile unsigned int*) IC5_SAR_reg))
#define IC5_SAR_inst_adr                                                             "0x00C2"
#define IC5_SAR_inst                                                                 0x00C2
#define IC5_SAR_IC_SAR_shift                                                         (0)
#define IC5_SAR_IC_SAR_mask                                                          (0x000003FF)
#define IC5_SAR_IC_SAR(data)                                                         (0x000003FF&((data)<<0))
#define IC5_SAR_IC_SAR_src(data)                                                     ((0x000003FF&(data))>>0)
#define IC5_SAR_get_IC_SAR(data)                                                     ((0x000003FF&(data))>>0)


#define IC5_HS_MADDR                                                                 0x1801BB0C
#define IC5_HS_MADDR_reg_addr                                                        "0xB801BB0C"
#define IC5_HS_MADDR_reg                                                             0xB801BB0C
#define set_IC5_HS_MADDR_reg(data)   (*((volatile unsigned int*) IC5_HS_MADDR_reg)=data)
#define get_IC5_HS_MADDR_reg   (*((volatile unsigned int*) IC5_HS_MADDR_reg))
#define IC5_HS_MADDR_inst_adr                                                        "0x00C3"
#define IC5_HS_MADDR_inst                                                            0x00C3
#define IC5_HS_MADDR_IC_HS_MAR_shift                                                 (0)
#define IC5_HS_MADDR_IC_HS_MAR_mask                                                  (0x00000007)
#define IC5_HS_MADDR_IC_HS_MAR(data)                                                 (0x00000007&((data)<<0))
#define IC5_HS_MADDR_IC_HS_MAR_src(data)                                             ((0x00000007&(data))>>0)
#define IC5_HS_MADDR_get_IC_HS_MAR(data)                                             ((0x00000007&(data))>>0)


#define IC5_DATA_CMD                                                                 0x1801BB10
#define IC5_DATA_CMD_reg_addr                                                        "0xB801BB10"
#define IC5_DATA_CMD_reg                                                             0xB801BB10
#define set_IC5_DATA_CMD_reg(data)   (*((volatile unsigned int*) IC5_DATA_CMD_reg)=data)
#define get_IC5_DATA_CMD_reg   (*((volatile unsigned int*) IC5_DATA_CMD_reg))
#define IC5_DATA_CMD_inst_adr                                                        "0x00C4"
#define IC5_DATA_CMD_inst                                                            0x00C4
#define IC5_DATA_CMD_RESTART_shift                                                   (10)
#define IC5_DATA_CMD_RESTART_mask                                                    (0x00000400)
#define IC5_DATA_CMD_RESTART(data)                                                   (0x00000400&((data)<<10))
#define IC5_DATA_CMD_RESTART_src(data)                                               ((0x00000400&(data))>>10)
#define IC5_DATA_CMD_get_RESTART(data)                                               ((0x00000400&(data))>>10)
#define IC5_DATA_CMD_STOP_shift                                                      (9)
#define IC5_DATA_CMD_STOP_mask                                                       (0x00000200)
#define IC5_DATA_CMD_STOP(data)                                                      (0x00000200&((data)<<9))
#define IC5_DATA_CMD_STOP_src(data)                                                  ((0x00000200&(data))>>9)
#define IC5_DATA_CMD_get_STOP(data)                                                  ((0x00000200&(data))>>9)
#define IC5_DATA_CMD_CMD_shift                                                       (8)
#define IC5_DATA_CMD_CMD_mask                                                        (0x00000100)
#define IC5_DATA_CMD_CMD(data)                                                       (0x00000100&((data)<<8))
#define IC5_DATA_CMD_CMD_src(data)                                                   ((0x00000100&(data))>>8)
#define IC5_DATA_CMD_get_CMD(data)                                                   ((0x00000100&(data))>>8)
#define IC5_DATA_CMD_DAT_shift                                                       (0)
#define IC5_DATA_CMD_DAT_mask                                                        (0x000000FF)
#define IC5_DATA_CMD_DAT(data)                                                       (0x000000FF&((data)<<0))
#define IC5_DATA_CMD_DAT_src(data)                                                   ((0x000000FF&(data))>>0)
#define IC5_DATA_CMD_get_DAT(data)                                                   ((0x000000FF&(data))>>0)


#define IC5_SS_SCL_HCNT                                                              0x1801BB14
#define IC5_SS_SCL_HCNT_reg_addr                                                     "0xB801BB14"
#define IC5_SS_SCL_HCNT_reg                                                          0xB801BB14
#define set_IC5_SS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC5_SS_SCL_HCNT_reg)=data)
#define get_IC5_SS_SCL_HCNT_reg   (*((volatile unsigned int*) IC5_SS_SCL_HCNT_reg))
#define IC5_SS_SCL_HCNT_inst_adr                                                     "0x00C5"
#define IC5_SS_SCL_HCNT_inst                                                         0x00C5
#define IC5_SS_SCL_HCNT_IC_SS_SCL_HCNT_shift                                         (0)
#define IC5_SS_SCL_HCNT_IC_SS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC5_SS_SCL_HCNT_IC_SS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC5_SS_SCL_HCNT_IC_SS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC5_SS_SCL_HCNT_get_IC_SS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC5_SS_SCL_LCNT                                                              0x1801BB18
#define IC5_SS_SCL_LCNT_reg_addr                                                     "0xB801BB18"
#define IC5_SS_SCL_LCNT_reg                                                          0xB801BB18
#define set_IC5_SS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC5_SS_SCL_LCNT_reg)=data)
#define get_IC5_SS_SCL_LCNT_reg   (*((volatile unsigned int*) IC5_SS_SCL_LCNT_reg))
#define IC5_SS_SCL_LCNT_inst_adr                                                     "0x00C6"
#define IC5_SS_SCL_LCNT_inst                                                         0x00C6
#define IC5_SS_SCL_LCNT_IC_SS_SCL_LCNT_shift                                         (0)
#define IC5_SS_SCL_LCNT_IC_SS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC5_SS_SCL_LCNT_IC_SS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC5_SS_SCL_LCNT_IC_SS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC5_SS_SCL_LCNT_get_IC_SS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC5_FS_SCL_HCNT                                                              0x1801BB1C
#define IC5_FS_SCL_HCNT_reg_addr                                                     "0xB801BB1C"
#define IC5_FS_SCL_HCNT_reg                                                          0xB801BB1C
#define set_IC5_FS_SCL_HCNT_reg(data)   (*((volatile unsigned int*) IC5_FS_SCL_HCNT_reg)=data)
#define get_IC5_FS_SCL_HCNT_reg   (*((volatile unsigned int*) IC5_FS_SCL_HCNT_reg))
#define IC5_FS_SCL_HCNT_inst_adr                                                     "0x00C7"
#define IC5_FS_SCL_HCNT_inst                                                         0x00C7
#define IC5_FS_SCL_HCNT_IC_FS_SCL_HCNT_shift                                         (0)
#define IC5_FS_SCL_HCNT_IC_FS_SCL_HCNT_mask                                          (0x0000FFFF)
#define IC5_FS_SCL_HCNT_IC_FS_SCL_HCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC5_FS_SCL_HCNT_IC_FS_SCL_HCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC5_FS_SCL_HCNT_get_IC_FS_SCL_HCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC5_FS_SCL_LCNT                                                              0x1801BB20
#define IC5_FS_SCL_LCNT_reg_addr                                                     "0xB801BB20"
#define IC5_FS_SCL_LCNT_reg                                                          0xB801BB20
#define set_IC5_FS_SCL_LCNT_reg(data)   (*((volatile unsigned int*) IC5_FS_SCL_LCNT_reg)=data)
#define get_IC5_FS_SCL_LCNT_reg   (*((volatile unsigned int*) IC5_FS_SCL_LCNT_reg))
#define IC5_FS_SCL_LCNT_inst_adr                                                     "0x00C8"
#define IC5_FS_SCL_LCNT_inst                                                         0x00C8
#define IC5_FS_SCL_LCNT_IC_FS_SCL_LCNT_shift                                         (0)
#define IC5_FS_SCL_LCNT_IC_FS_SCL_LCNT_mask                                          (0x0000FFFF)
#define IC5_FS_SCL_LCNT_IC_FS_SCL_LCNT(data)                                         (0x0000FFFF&((data)<<0))
#define IC5_FS_SCL_LCNT_IC_FS_SCL_LCNT_src(data)                                     ((0x0000FFFF&(data))>>0)
#define IC5_FS_SCL_LCNT_get_IC_FS_SCL_LCNT(data)                                     ((0x0000FFFF&(data))>>0)


#define IC5_INTR_STAT                                                                0x1801BB2C
#define IC5_INTR_STAT_reg_addr                                                       "0xB801BB2C"
#define IC5_INTR_STAT_reg                                                            0xB801BB2C
#define set_IC5_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC5_INTR_STAT_reg)=data)
#define get_IC5_INTR_STAT_reg   (*((volatile unsigned int*) IC5_INTR_STAT_reg))
#define IC5_INTR_STAT_inst_adr                                                       "0x00CB"
#define IC5_INTR_STAT_inst                                                           0x00CB
#define IC5_INTR_STAT_R_GEN_CALL_shift                                               (11)
#define IC5_INTR_STAT_R_GEN_CALL_mask                                                (0x00000800)
#define IC5_INTR_STAT_R_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC5_INTR_STAT_R_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC5_INTR_STAT_get_R_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC5_INTR_STAT_R_START_DET_shift                                              (10)
#define IC5_INTR_STAT_R_START_DET_mask                                               (0x00000400)
#define IC5_INTR_STAT_R_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC5_INTR_STAT_R_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC5_INTR_STAT_get_R_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC5_INTR_STAT_R_STOP_DET_shift                                               (9)
#define IC5_INTR_STAT_R_STOP_DET_mask                                                (0x00000200)
#define IC5_INTR_STAT_R_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC5_INTR_STAT_R_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC5_INTR_STAT_get_R_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC5_INTR_STAT_R_ACTIVITY_shift                                               (8)
#define IC5_INTR_STAT_R_ACTIVITY_mask                                                (0x00000100)
#define IC5_INTR_STAT_R_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC5_INTR_STAT_R_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC5_INTR_STAT_get_R_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC5_INTR_STAT_R_RX_DONE_shift                                                (7)
#define IC5_INTR_STAT_R_RX_DONE_mask                                                 (0x00000080)
#define IC5_INTR_STAT_R_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC5_INTR_STAT_R_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC5_INTR_STAT_get_R_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC5_INTR_STAT_R_TX_ABRT_shift                                                (6)
#define IC5_INTR_STAT_R_TX_ABRT_mask                                                 (0x00000040)
#define IC5_INTR_STAT_R_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC5_INTR_STAT_R_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC5_INTR_STAT_get_R_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC5_INTR_STAT_R_RD_REQ_shift                                                 (5)
#define IC5_INTR_STAT_R_RD_REQ_mask                                                  (0x00000020)
#define IC5_INTR_STAT_R_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC5_INTR_STAT_R_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC5_INTR_STAT_get_R_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC5_INTR_STAT_R_TX_EMPTY_shift                                               (4)
#define IC5_INTR_STAT_R_TX_EMPTY_mask                                                (0x00000010)
#define IC5_INTR_STAT_R_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC5_INTR_STAT_R_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC5_INTR_STAT_get_R_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC5_INTR_STAT_R_TX_OVER_shift                                                (3)
#define IC5_INTR_STAT_R_TX_OVER_mask                                                 (0x00000008)
#define IC5_INTR_STAT_R_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC5_INTR_STAT_R_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC5_INTR_STAT_get_R_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC5_INTR_STAT_R_RX_FULL_shift                                                (2)
#define IC5_INTR_STAT_R_RX_FULL_mask                                                 (0x00000004)
#define IC5_INTR_STAT_R_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC5_INTR_STAT_R_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC5_INTR_STAT_get_R_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC5_INTR_STAT_R_RX_OVER_shift                                                (1)
#define IC5_INTR_STAT_R_RX_OVER_mask                                                 (0x00000002)
#define IC5_INTR_STAT_R_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC5_INTR_STAT_R_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC5_INTR_STAT_get_R_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC5_INTR_STAT_R_RX_UNDER_shift                                               (0)
#define IC5_INTR_STAT_R_RX_UNDER_mask                                                (0x00000001)
#define IC5_INTR_STAT_R_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC5_INTR_STAT_R_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC5_INTR_STAT_get_R_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC5_INTR_MASK                                                                0x1801BB30
#define IC5_INTR_MASK_reg_addr                                                       "0xB801BB30"
#define IC5_INTR_MASK_reg                                                            0xB801BB30
#define set_IC5_INTR_MASK_reg(data)   (*((volatile unsigned int*) IC5_INTR_MASK_reg)=data)
#define get_IC5_INTR_MASK_reg   (*((volatile unsigned int*) IC5_INTR_MASK_reg))
#define IC5_INTR_MASK_inst_adr                                                       "0x00CC"
#define IC5_INTR_MASK_inst                                                           0x00CC
#define IC5_INTR_MASK_M_GEN_CALL_shift                                               (11)
#define IC5_INTR_MASK_M_GEN_CALL_mask                                                (0x00000800)
#define IC5_INTR_MASK_M_GEN_CALL(data)                                               (0x00000800&((data)<<11))
#define IC5_INTR_MASK_M_GEN_CALL_src(data)                                           ((0x00000800&(data))>>11)
#define IC5_INTR_MASK_get_M_GEN_CALL(data)                                           ((0x00000800&(data))>>11)
#define IC5_INTR_MASK_M_START_DET_shift                                              (10)
#define IC5_INTR_MASK_M_START_DET_mask                                               (0x00000400)
#define IC5_INTR_MASK_M_START_DET(data)                                              (0x00000400&((data)<<10))
#define IC5_INTR_MASK_M_START_DET_src(data)                                          ((0x00000400&(data))>>10)
#define IC5_INTR_MASK_get_M_START_DET(data)                                          ((0x00000400&(data))>>10)
#define IC5_INTR_MASK_M_STOP_DET_shift                                               (9)
#define IC5_INTR_MASK_M_STOP_DET_mask                                                (0x00000200)
#define IC5_INTR_MASK_M_STOP_DET(data)                                               (0x00000200&((data)<<9))
#define IC5_INTR_MASK_M_STOP_DET_src(data)                                           ((0x00000200&(data))>>9)
#define IC5_INTR_MASK_get_M_STOP_DET(data)                                           ((0x00000200&(data))>>9)
#define IC5_INTR_MASK_M_ACTIVITY_shift                                               (8)
#define IC5_INTR_MASK_M_ACTIVITY_mask                                                (0x00000100)
#define IC5_INTR_MASK_M_ACTIVITY(data)                                               (0x00000100&((data)<<8))
#define IC5_INTR_MASK_M_ACTIVITY_src(data)                                           ((0x00000100&(data))>>8)
#define IC5_INTR_MASK_get_M_ACTIVITY(data)                                           ((0x00000100&(data))>>8)
#define IC5_INTR_MASK_M_RX_DONE_shift                                                (7)
#define IC5_INTR_MASK_M_RX_DONE_mask                                                 (0x00000080)
#define IC5_INTR_MASK_M_RX_DONE(data)                                                (0x00000080&((data)<<7))
#define IC5_INTR_MASK_M_RX_DONE_src(data)                                            ((0x00000080&(data))>>7)
#define IC5_INTR_MASK_get_M_RX_DONE(data)                                            ((0x00000080&(data))>>7)
#define IC5_INTR_MASK_M_TX_ABRT_shift                                                (6)
#define IC5_INTR_MASK_M_TX_ABRT_mask                                                 (0x00000040)
#define IC5_INTR_MASK_M_TX_ABRT(data)                                                (0x00000040&((data)<<6))
#define IC5_INTR_MASK_M_TX_ABRT_src(data)                                            ((0x00000040&(data))>>6)
#define IC5_INTR_MASK_get_M_TX_ABRT(data)                                            ((0x00000040&(data))>>6)
#define IC5_INTR_MASK_M_RD_REQ_shift                                                 (5)
#define IC5_INTR_MASK_M_RD_REQ_mask                                                  (0x00000020)
#define IC5_INTR_MASK_M_RD_REQ(data)                                                 (0x00000020&((data)<<5))
#define IC5_INTR_MASK_M_RD_REQ_src(data)                                             ((0x00000020&(data))>>5)
#define IC5_INTR_MASK_get_M_RD_REQ(data)                                             ((0x00000020&(data))>>5)
#define IC5_INTR_MASK_M_TX_EMPTY_shift                                               (4)
#define IC5_INTR_MASK_M_TX_EMPTY_mask                                                (0x00000010)
#define IC5_INTR_MASK_M_TX_EMPTY(data)                                               (0x00000010&((data)<<4))
#define IC5_INTR_MASK_M_TX_EMPTY_src(data)                                           ((0x00000010&(data))>>4)
#define IC5_INTR_MASK_get_M_TX_EMPTY(data)                                           ((0x00000010&(data))>>4)
#define IC5_INTR_MASK_M_TX_OVER_shift                                                (3)
#define IC5_INTR_MASK_M_TX_OVER_mask                                                 (0x00000008)
#define IC5_INTR_MASK_M_TX_OVER(data)                                                (0x00000008&((data)<<3))
#define IC5_INTR_MASK_M_TX_OVER_src(data)                                            ((0x00000008&(data))>>3)
#define IC5_INTR_MASK_get_M_TX_OVER(data)                                            ((0x00000008&(data))>>3)
#define IC5_INTR_MASK_M_RX_FULL_shift                                                (2)
#define IC5_INTR_MASK_M_RX_FULL_mask                                                 (0x00000004)
#define IC5_INTR_MASK_M_RX_FULL(data)                                                (0x00000004&((data)<<2))
#define IC5_INTR_MASK_M_RX_FULL_src(data)                                            ((0x00000004&(data))>>2)
#define IC5_INTR_MASK_get_M_RX_FULL(data)                                            ((0x00000004&(data))>>2)
#define IC5_INTR_MASK_M_RX_OVER_shift                                                (1)
#define IC5_INTR_MASK_M_RX_OVER_mask                                                 (0x00000002)
#define IC5_INTR_MASK_M_RX_OVER(data)                                                (0x00000002&((data)<<1))
#define IC5_INTR_MASK_M_RX_OVER_src(data)                                            ((0x00000002&(data))>>1)
#define IC5_INTR_MASK_get_M_RX_OVER(data)                                            ((0x00000002&(data))>>1)
#define IC5_INTR_MASK_M_RX_UNDER_shift                                               (0)
#define IC5_INTR_MASK_M_RX_UNDER_mask                                                (0x00000001)
#define IC5_INTR_MASK_M_RX_UNDER(data)                                               (0x00000001&((data)<<0))
#define IC5_INTR_MASK_M_RX_UNDER_src(data)                                           ((0x00000001&(data))>>0)
#define IC5_INTR_MASK_get_M_RX_UNDER(data)                                           ((0x00000001&(data))>>0)


#define IC5_RAW_INTR_STAT                                                            0x1801BB34
#define IC5_RAW_INTR_STAT_reg_addr                                                   "0xB801BB34"
#define IC5_RAW_INTR_STAT_reg                                                        0xB801BB34
#define set_IC5_RAW_INTR_STAT_reg(data)   (*((volatile unsigned int*) IC5_RAW_INTR_STAT_reg)=data)
#define get_IC5_RAW_INTR_STAT_reg   (*((volatile unsigned int*) IC5_RAW_INTR_STAT_reg))
#define IC5_RAW_INTR_STAT_inst_adr                                                   "0x00CD"
#define IC5_RAW_INTR_STAT_inst                                                       0x00CD
#define IC5_RAW_INTR_STAT_GEN_CALL_shift                                             (11)
#define IC5_RAW_INTR_STAT_GEN_CALL_mask                                              (0x00000800)
#define IC5_RAW_INTR_STAT_GEN_CALL(data)                                             (0x00000800&((data)<<11))
#define IC5_RAW_INTR_STAT_GEN_CALL_src(data)                                         ((0x00000800&(data))>>11)
#define IC5_RAW_INTR_STAT_get_GEN_CALL(data)                                         ((0x00000800&(data))>>11)
#define IC5_RAW_INTR_STAT_START_DET_shift                                            (10)
#define IC5_RAW_INTR_STAT_START_DET_mask                                             (0x00000400)
#define IC5_RAW_INTR_STAT_START_DET(data)                                            (0x00000400&((data)<<10))
#define IC5_RAW_INTR_STAT_START_DET_src(data)                                        ((0x00000400&(data))>>10)
#define IC5_RAW_INTR_STAT_get_START_DET(data)                                        ((0x00000400&(data))>>10)
#define IC5_RAW_INTR_STAT_STOP_DET_shift                                             (9)
#define IC5_RAW_INTR_STAT_STOP_DET_mask                                              (0x00000200)
#define IC5_RAW_INTR_STAT_STOP_DET(data)                                             (0x00000200&((data)<<9))
#define IC5_RAW_INTR_STAT_STOP_DET_src(data)                                         ((0x00000200&(data))>>9)
#define IC5_RAW_INTR_STAT_get_STOP_DET(data)                                         ((0x00000200&(data))>>9)
#define IC5_RAW_INTR_STAT_ACTIVITY_shift                                             (8)
#define IC5_RAW_INTR_STAT_ACTIVITY_mask                                              (0x00000100)
#define IC5_RAW_INTR_STAT_ACTIVITY(data)                                             (0x00000100&((data)<<8))
#define IC5_RAW_INTR_STAT_ACTIVITY_src(data)                                         ((0x00000100&(data))>>8)
#define IC5_RAW_INTR_STAT_get_ACTIVITY(data)                                         ((0x00000100&(data))>>8)
#define IC5_RAW_INTR_STAT_RX_DONE_shift                                              (7)
#define IC5_RAW_INTR_STAT_RX_DONE_mask                                               (0x00000080)
#define IC5_RAW_INTR_STAT_RX_DONE(data)                                              (0x00000080&((data)<<7))
#define IC5_RAW_INTR_STAT_RX_DONE_src(data)                                          ((0x00000080&(data))>>7)
#define IC5_RAW_INTR_STAT_get_RX_DONE(data)                                          ((0x00000080&(data))>>7)
#define IC5_RAW_INTR_STAT_TX_ABRT_shift                                              (6)
#define IC5_RAW_INTR_STAT_TX_ABRT_mask                                               (0x00000040)
#define IC5_RAW_INTR_STAT_TX_ABRT(data)                                              (0x00000040&((data)<<6))
#define IC5_RAW_INTR_STAT_TX_ABRT_src(data)                                          ((0x00000040&(data))>>6)
#define IC5_RAW_INTR_STAT_get_TX_ABRT(data)                                          ((0x00000040&(data))>>6)
#define IC5_RAW_INTR_STAT_RD_REQ_shift                                               (5)
#define IC5_RAW_INTR_STAT_RD_REQ_mask                                                (0x00000020)
#define IC5_RAW_INTR_STAT_RD_REQ(data)                                               (0x00000020&((data)<<5))
#define IC5_RAW_INTR_STAT_RD_REQ_src(data)                                           ((0x00000020&(data))>>5)
#define IC5_RAW_INTR_STAT_get_RD_REQ(data)                                           ((0x00000020&(data))>>5)
#define IC5_RAW_INTR_STAT_TX_EMPTY_shift                                             (4)
#define IC5_RAW_INTR_STAT_TX_EMPTY_mask                                              (0x00000010)
#define IC5_RAW_INTR_STAT_TX_EMPTY(data)                                             (0x00000010&((data)<<4))
#define IC5_RAW_INTR_STAT_TX_EMPTY_src(data)                                         ((0x00000010&(data))>>4)
#define IC5_RAW_INTR_STAT_get_TX_EMPTY(data)                                         ((0x00000010&(data))>>4)
#define IC5_RAW_INTR_STAT_TX_OVER_shift                                              (3)
#define IC5_RAW_INTR_STAT_TX_OVER_mask                                               (0x00000008)
#define IC5_RAW_INTR_STAT_TX_OVER(data)                                              (0x00000008&((data)<<3))
#define IC5_RAW_INTR_STAT_TX_OVER_src(data)                                          ((0x00000008&(data))>>3)
#define IC5_RAW_INTR_STAT_get_TX_OVER(data)                                          ((0x00000008&(data))>>3)
#define IC5_RAW_INTR_STAT_RX_FULL_shift                                              (2)
#define IC5_RAW_INTR_STAT_RX_FULL_mask                                               (0x00000004)
#define IC5_RAW_INTR_STAT_RX_FULL(data)                                              (0x00000004&((data)<<2))
#define IC5_RAW_INTR_STAT_RX_FULL_src(data)                                          ((0x00000004&(data))>>2)
#define IC5_RAW_INTR_STAT_get_RX_FULL(data)                                          ((0x00000004&(data))>>2)
#define IC5_RAW_INTR_STAT_RX_OVER_shift                                              (1)
#define IC5_RAW_INTR_STAT_RX_OVER_mask                                               (0x00000002)
#define IC5_RAW_INTR_STAT_RX_OVER(data)                                              (0x00000002&((data)<<1))
#define IC5_RAW_INTR_STAT_RX_OVER_src(data)                                          ((0x00000002&(data))>>1)
#define IC5_RAW_INTR_STAT_get_RX_OVER(data)                                          ((0x00000002&(data))>>1)
#define IC5_RAW_INTR_STAT_RX_UNDER_shift                                             (0)
#define IC5_RAW_INTR_STAT_RX_UNDER_mask                                              (0x00000001)
#define IC5_RAW_INTR_STAT_RX_UNDER(data)                                             (0x00000001&((data)<<0))
#define IC5_RAW_INTR_STAT_RX_UNDER_src(data)                                         ((0x00000001&(data))>>0)
#define IC5_RAW_INTR_STAT_get_RX_UNDER(data)                                         ((0x00000001&(data))>>0)


#define IC5_RX_TL                                                                    0x1801BB38
#define IC5_RX_TL_reg_addr                                                           "0xB801BB38"
#define IC5_RX_TL_reg                                                                0xB801BB38
#define set_IC5_RX_TL_reg(data)   (*((volatile unsigned int*) IC5_RX_TL_reg)=data)
#define get_IC5_RX_TL_reg   (*((volatile unsigned int*) IC5_RX_TL_reg))
#define IC5_RX_TL_inst_adr                                                           "0x00CE"
#define IC5_RX_TL_inst                                                               0x00CE
#define IC5_RX_TL_RX_TL_shift                                                        (0)
#define IC5_RX_TL_RX_TL_mask                                                         (0x000000FF)
#define IC5_RX_TL_RX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC5_RX_TL_RX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC5_RX_TL_get_RX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC5_TX_TL                                                                    0x1801BB3C
#define IC5_TX_TL_reg_addr                                                           "0xB801BB3C"
#define IC5_TX_TL_reg                                                                0xB801BB3C
#define set_IC5_TX_TL_reg(data)   (*((volatile unsigned int*) IC5_TX_TL_reg)=data)
#define get_IC5_TX_TL_reg   (*((volatile unsigned int*) IC5_TX_TL_reg))
#define IC5_TX_TL_inst_adr                                                           "0x00CF"
#define IC5_TX_TL_inst                                                               0x00CF
#define IC5_TX_TL_TX_TL_shift                                                        (0)
#define IC5_TX_TL_TX_TL_mask                                                         (0x000000FF)
#define IC5_TX_TL_TX_TL(data)                                                        (0x000000FF&((data)<<0))
#define IC5_TX_TL_TX_TL_src(data)                                                    ((0x000000FF&(data))>>0)
#define IC5_TX_TL_get_TX_TL(data)                                                    ((0x000000FF&(data))>>0)


#define IC5_CLR_INTR                                                                 0x1801BB40
#define IC5_CLR_INTR_reg_addr                                                        "0xB801BB40"
#define IC5_CLR_INTR_reg                                                             0xB801BB40
#define set_IC5_CLR_INTR_reg(data)   (*((volatile unsigned int*) IC5_CLR_INTR_reg)=data)
#define get_IC5_CLR_INTR_reg   (*((volatile unsigned int*) IC5_CLR_INTR_reg))
#define IC5_CLR_INTR_inst_adr                                                        "0x00D0"
#define IC5_CLR_INTR_inst                                                            0x00D0
#define IC5_CLR_INTR_CLR_INTR_shift                                                  (0)
#define IC5_CLR_INTR_CLR_INTR_mask                                                   (0x00000001)
#define IC5_CLR_INTR_CLR_INTR(data)                                                  (0x00000001&((data)<<0))
#define IC5_CLR_INTR_CLR_INTR_src(data)                                              ((0x00000001&(data))>>0)
#define IC5_CLR_INTR_get_CLR_INTR(data)                                              ((0x00000001&(data))>>0)


#define IC5_CLR_RX_UNDER                                                             0x1801BB44
#define IC5_CLR_RX_UNDER_reg_addr                                                    "0xB801BB44"
#define IC5_CLR_RX_UNDER_reg                                                         0xB801BB44
#define set_IC5_CLR_RX_UNDER_reg(data)   (*((volatile unsigned int*) IC5_CLR_RX_UNDER_reg)=data)
#define get_IC5_CLR_RX_UNDER_reg   (*((volatile unsigned int*) IC5_CLR_RX_UNDER_reg))
#define IC5_CLR_RX_UNDER_inst_adr                                                    "0x00D1"
#define IC5_CLR_RX_UNDER_inst                                                        0x00D1
#define IC5_CLR_RX_UNDER_CLR_RX_UNDER_shift                                          (0)
#define IC5_CLR_RX_UNDER_CLR_RX_UNDER_mask                                           (0x00000001)
#define IC5_CLR_RX_UNDER_CLR_RX_UNDER(data)                                          (0x00000001&((data)<<0))
#define IC5_CLR_RX_UNDER_CLR_RX_UNDER_src(data)                                      ((0x00000001&(data))>>0)
#define IC5_CLR_RX_UNDER_get_CLR_RX_UNDER(data)                                      ((0x00000001&(data))>>0)


#define IC5_CLR_RX_OVER                                                              0x1801BB48
#define IC5_CLR_RX_OVER_reg_addr                                                     "0xB801BB48"
#define IC5_CLR_RX_OVER_reg                                                          0xB801BB48
#define set_IC5_CLR_RX_OVER_reg(data)   (*((volatile unsigned int*) IC5_CLR_RX_OVER_reg)=data)
#define get_IC5_CLR_RX_OVER_reg   (*((volatile unsigned int*) IC5_CLR_RX_OVER_reg))
#define IC5_CLR_RX_OVER_inst_adr                                                     "0x00D2"
#define IC5_CLR_RX_OVER_inst                                                         0x00D2
#define IC5_CLR_RX_OVER_CLR_RX_OVER_shift                                            (0)
#define IC5_CLR_RX_OVER_CLR_RX_OVER_mask                                             (0x00000001)
#define IC5_CLR_RX_OVER_CLR_RX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC5_CLR_RX_OVER_CLR_RX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC5_CLR_RX_OVER_get_CLR_RX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC5_CLR_TX_OVER                                                              0x1801BB4C
#define IC5_CLR_TX_OVER_reg_addr                                                     "0xB801BB4C"
#define IC5_CLR_TX_OVER_reg                                                          0xB801BB4C
#define set_IC5_CLR_TX_OVER_reg(data)   (*((volatile unsigned int*) IC5_CLR_TX_OVER_reg)=data)
#define get_IC5_CLR_TX_OVER_reg   (*((volatile unsigned int*) IC5_CLR_TX_OVER_reg))
#define IC5_CLR_TX_OVER_inst_adr                                                     "0x00D3"
#define IC5_CLR_TX_OVER_inst                                                         0x00D3
#define IC5_CLR_TX_OVER_CLR_TX_OVER_shift                                            (0)
#define IC5_CLR_TX_OVER_CLR_TX_OVER_mask                                             (0x00000001)
#define IC5_CLR_TX_OVER_CLR_TX_OVER(data)                                            (0x00000001&((data)<<0))
#define IC5_CLR_TX_OVER_CLR_TX_OVER_src(data)                                        ((0x00000001&(data))>>0)
#define IC5_CLR_TX_OVER_get_CLR_TX_OVER(data)                                        ((0x00000001&(data))>>0)


#define IC5_CLR_RD_REQ                                                               0x1801BB50
#define IC5_CLR_RD_REQ_reg_addr                                                      "0xB801BB50"
#define IC5_CLR_RD_REQ_reg                                                           0xB801BB50
#define set_IC5_CLR_RD_REQ_reg(data)   (*((volatile unsigned int*) IC5_CLR_RD_REQ_reg)=data)
#define get_IC5_CLR_RD_REQ_reg   (*((volatile unsigned int*) IC5_CLR_RD_REQ_reg))
#define IC5_CLR_RD_REQ_inst_adr                                                      "0x00D4"
#define IC5_CLR_RD_REQ_inst                                                          0x00D4
#define IC5_CLR_RD_REQ_CLR_RD_REQ_shift                                              (0)
#define IC5_CLR_RD_REQ_CLR_RD_REQ_mask                                               (0x00000001)
#define IC5_CLR_RD_REQ_CLR_RD_REQ(data)                                              (0x00000001&((data)<<0))
#define IC5_CLR_RD_REQ_CLR_RD_REQ_src(data)                                          ((0x00000001&(data))>>0)
#define IC5_CLR_RD_REQ_get_CLR_RD_REQ(data)                                          ((0x00000001&(data))>>0)


#define IC5_CLR_TX_ABRT                                                              0x1801BB54
#define IC5_CLR_TX_ABRT_reg_addr                                                     "0xB801BB54"
#define IC5_CLR_TX_ABRT_reg                                                          0xB801BB54
#define set_IC5_CLR_TX_ABRT_reg(data)   (*((volatile unsigned int*) IC5_CLR_TX_ABRT_reg)=data)
#define get_IC5_CLR_TX_ABRT_reg   (*((volatile unsigned int*) IC5_CLR_TX_ABRT_reg))
#define IC5_CLR_TX_ABRT_inst_adr                                                     "0x00D5"
#define IC5_CLR_TX_ABRT_inst                                                         0x00D5
#define IC5_CLR_TX_ABRT_CLR_TX_ABRT_shift                                            (0)
#define IC5_CLR_TX_ABRT_CLR_TX_ABRT_mask                                             (0x00000001)
#define IC5_CLR_TX_ABRT_CLR_TX_ABRT(data)                                            (0x00000001&((data)<<0))
#define IC5_CLR_TX_ABRT_CLR_TX_ABRT_src(data)                                        ((0x00000001&(data))>>0)
#define IC5_CLR_TX_ABRT_get_CLR_TX_ABRT(data)                                        ((0x00000001&(data))>>0)


#define IC5_CLR_RX_DONE                                                              0x1801BB58
#define IC5_CLR_RX_DONE_reg_addr                                                     "0xB801BB58"
#define IC5_CLR_RX_DONE_reg                                                          0xB801BB58
#define set_IC5_CLR_RX_DONE_reg(data)   (*((volatile unsigned int*) IC5_CLR_RX_DONE_reg)=data)
#define get_IC5_CLR_RX_DONE_reg   (*((volatile unsigned int*) IC5_CLR_RX_DONE_reg))
#define IC5_CLR_RX_DONE_inst_adr                                                     "0x00D6"
#define IC5_CLR_RX_DONE_inst                                                         0x00D6
#define IC5_CLR_RX_DONE_CLR_RX_DONE_shift                                            (0)
#define IC5_CLR_RX_DONE_CLR_RX_DONE_mask                                             (0x00000001)
#define IC5_CLR_RX_DONE_CLR_RX_DONE(data)                                            (0x00000001&((data)<<0))
#define IC5_CLR_RX_DONE_CLR_RX_DONE_src(data)                                        ((0x00000001&(data))>>0)
#define IC5_CLR_RX_DONE_get_CLR_RX_DONE(data)                                        ((0x00000001&(data))>>0)


#define IC5_CLR_ACTIVITY                                                             0x1801BB5C
#define IC5_CLR_ACTIVITY_reg_addr                                                    "0xB801BB5C"
#define IC5_CLR_ACTIVITY_reg                                                         0xB801BB5C
#define set_IC5_CLR_ACTIVITY_reg(data)   (*((volatile unsigned int*) IC5_CLR_ACTIVITY_reg)=data)
#define get_IC5_CLR_ACTIVITY_reg   (*((volatile unsigned int*) IC5_CLR_ACTIVITY_reg))
#define IC5_CLR_ACTIVITY_inst_adr                                                    "0x00D7"
#define IC5_CLR_ACTIVITY_inst                                                        0x00D7
#define IC5_CLR_ACTIVITY_CLR_ACTIVITY_shift                                          (0)
#define IC5_CLR_ACTIVITY_CLR_ACTIVITY_mask                                           (0x00000001)
#define IC5_CLR_ACTIVITY_CLR_ACTIVITY(data)                                          (0x00000001&((data)<<0))
#define IC5_CLR_ACTIVITY_CLR_ACTIVITY_src(data)                                      ((0x00000001&(data))>>0)
#define IC5_CLR_ACTIVITY_get_CLR_ACTIVITY(data)                                      ((0x00000001&(data))>>0)


#define IC5_CLR_STOP_DET                                                             0x1801BB60
#define IC5_CLR_STOP_DET_reg_addr                                                    "0xB801BB60"
#define IC5_CLR_STOP_DET_reg                                                         0xB801BB60
#define set_IC5_CLR_STOP_DET_reg(data)   (*((volatile unsigned int*) IC5_CLR_STOP_DET_reg)=data)
#define get_IC5_CLR_STOP_DET_reg   (*((volatile unsigned int*) IC5_CLR_STOP_DET_reg))
#define IC5_CLR_STOP_DET_inst_adr                                                    "0x00D8"
#define IC5_CLR_STOP_DET_inst                                                        0x00D8
#define IC5_CLR_STOP_DET_CLR_STOP_DET_shift                                          (0)
#define IC5_CLR_STOP_DET_CLR_STOP_DET_mask                                           (0x00000001)
#define IC5_CLR_STOP_DET_CLR_STOP_DET(data)                                          (0x00000001&((data)<<0))
#define IC5_CLR_STOP_DET_CLR_STOP_DET_src(data)                                      ((0x00000001&(data))>>0)
#define IC5_CLR_STOP_DET_get_CLR_STOP_DET(data)                                      ((0x00000001&(data))>>0)


#define IC5_CLR_START_DET                                                            0x1801BB64
#define IC5_CLR_START_DET_reg_addr                                                   "0xB801BB64"
#define IC5_CLR_START_DET_reg                                                        0xB801BB64
#define set_IC5_CLR_START_DET_reg(data)   (*((volatile unsigned int*) IC5_CLR_START_DET_reg)=data)
#define get_IC5_CLR_START_DET_reg   (*((volatile unsigned int*) IC5_CLR_START_DET_reg))
#define IC5_CLR_START_DET_inst_adr                                                   "0x00D9"
#define IC5_CLR_START_DET_inst                                                       0x00D9
#define IC5_CLR_START_DET_CLR_START_DET_shift                                        (0)
#define IC5_CLR_START_DET_CLR_START_DET_mask                                         (0x00000001)
#define IC5_CLR_START_DET_CLR_START_DET(data)                                        (0x00000001&((data)<<0))
#define IC5_CLR_START_DET_CLR_START_DET_src(data)                                    ((0x00000001&(data))>>0)
#define IC5_CLR_START_DET_get_CLR_START_DET(data)                                    ((0x00000001&(data))>>0)


#define IC5_CLR_GEN_CALL                                                             0x1801BB68
#define IC5_CLR_GEN_CALL_reg_addr                                                    "0xB801BB68"
#define IC5_CLR_GEN_CALL_reg                                                         0xB801BB68
#define set_IC5_CLR_GEN_CALL_reg(data)   (*((volatile unsigned int*) IC5_CLR_GEN_CALL_reg)=data)
#define get_IC5_CLR_GEN_CALL_reg   (*((volatile unsigned int*) IC5_CLR_GEN_CALL_reg))
#define IC5_CLR_GEN_CALL_inst_adr                                                    "0x00DA"
#define IC5_CLR_GEN_CALL_inst                                                        0x00DA
#define IC5_CLR_GEN_CALL_CLR_GEN_CALL_shift                                          (0)
#define IC5_CLR_GEN_CALL_CLR_GEN_CALL_mask                                           (0x00000001)
#define IC5_CLR_GEN_CALL_CLR_GEN_CALL(data)                                          (0x00000001&((data)<<0))
#define IC5_CLR_GEN_CALL_CLR_GEN_CALL_src(data)                                      ((0x00000001&(data))>>0)
#define IC5_CLR_GEN_CALL_get_CLR_GEN_CALL(data)                                      ((0x00000001&(data))>>0)


#define IC5_ENABLE                                                                   0x1801BB6C
#define IC5_ENABLE_reg_addr                                                          "0xB801BB6C"
#define IC5_ENABLE_reg                                                               0xB801BB6C
#define set_IC5_ENABLE_reg(data)   (*((volatile unsigned int*) IC5_ENABLE_reg)=data)
#define get_IC5_ENABLE_reg   (*((volatile unsigned int*) IC5_ENABLE_reg))
#define IC5_ENABLE_inst_adr                                                          "0x00DB"
#define IC5_ENABLE_inst                                                              0x00DB
#define IC5_ENABLE_ENABLE_shift                                                      (0)
#define IC5_ENABLE_ENABLE_mask                                                       (0x00000001)
#define IC5_ENABLE_ENABLE(data)                                                      (0x00000001&((data)<<0))
#define IC5_ENABLE_ENABLE_src(data)                                                  ((0x00000001&(data))>>0)
#define IC5_ENABLE_get_ENABLE(data)                                                  ((0x00000001&(data))>>0)


#define IC5_STATUS                                                                   0x1801BB70
#define IC5_STATUS_reg_addr                                                          "0xB801BB70"
#define IC5_STATUS_reg                                                               0xB801BB70
#define set_IC5_STATUS_reg(data)   (*((volatile unsigned int*) IC5_STATUS_reg)=data)
#define get_IC5_STATUS_reg   (*((volatile unsigned int*) IC5_STATUS_reg))
#define IC5_STATUS_inst_adr                                                          "0x00DC"
#define IC5_STATUS_inst                                                              0x00DC
#define IC5_STATUS_SLV_ACTIVITY_shift                                                (6)
#define IC5_STATUS_SLV_ACTIVITY_mask                                                 (0x00000040)
#define IC5_STATUS_SLV_ACTIVITY(data)                                                (0x00000040&((data)<<6))
#define IC5_STATUS_SLV_ACTIVITY_src(data)                                            ((0x00000040&(data))>>6)
#define IC5_STATUS_get_SLV_ACTIVITY(data)                                            ((0x00000040&(data))>>6)
#define IC5_STATUS_MST_ACTIVITY_shift                                                (5)
#define IC5_STATUS_MST_ACTIVITY_mask                                                 (0x00000020)
#define IC5_STATUS_MST_ACTIVITY(data)                                                (0x00000020&((data)<<5))
#define IC5_STATUS_MST_ACTIVITY_src(data)                                            ((0x00000020&(data))>>5)
#define IC5_STATUS_get_MST_ACTIVITY(data)                                            ((0x00000020&(data))>>5)
#define IC5_STATUS_RFF_shift                                                         (4)
#define IC5_STATUS_RFF_mask                                                          (0x00000010)
#define IC5_STATUS_RFF(data)                                                         (0x00000010&((data)<<4))
#define IC5_STATUS_RFF_src(data)                                                     ((0x00000010&(data))>>4)
#define IC5_STATUS_get_RFF(data)                                                     ((0x00000010&(data))>>4)
#define IC5_STATUS_RFNE_shift                                                        (3)
#define IC5_STATUS_RFNE_mask                                                         (0x00000008)
#define IC5_STATUS_RFNE(data)                                                        (0x00000008&((data)<<3))
#define IC5_STATUS_RFNE_src(data)                                                    ((0x00000008&(data))>>3)
#define IC5_STATUS_get_RFNE(data)                                                    ((0x00000008&(data))>>3)
#define IC5_STATUS_TFE_shift                                                         (2)
#define IC5_STATUS_TFE_mask                                                          (0x00000004)
#define IC5_STATUS_TFE(data)                                                         (0x00000004&((data)<<2))
#define IC5_STATUS_TFE_src(data)                                                     ((0x00000004&(data))>>2)
#define IC5_STATUS_get_TFE(data)                                                     ((0x00000004&(data))>>2)
#define IC5_STATUS_TFNF_shift                                                        (1)
#define IC5_STATUS_TFNF_mask                                                         (0x00000002)
#define IC5_STATUS_TFNF(data)                                                        (0x00000002&((data)<<1))
#define IC5_STATUS_TFNF_src(data)                                                    ((0x00000002&(data))>>1)
#define IC5_STATUS_get_TFNF(data)                                                    ((0x00000002&(data))>>1)
#define IC5_STATUS_ACTIVITY_shift                                                    (0)
#define IC5_STATUS_ACTIVITY_mask                                                     (0x00000001)
#define IC5_STATUS_ACTIVITY(data)                                                    (0x00000001&((data)<<0))
#define IC5_STATUS_ACTIVITY_src(data)                                                ((0x00000001&(data))>>0)
#define IC5_STATUS_get_ACTIVITY(data)                                                ((0x00000001&(data))>>0)


#define IC5_TXFLR                                                                    0x1801BB74
#define IC5_TXFLR_reg_addr                                                           "0xB801BB74"
#define IC5_TXFLR_reg                                                                0xB801BB74
#define set_IC5_TXFLR_reg(data)   (*((volatile unsigned int*) IC5_TXFLR_reg)=data)
#define get_IC5_TXFLR_reg   (*((volatile unsigned int*) IC5_TXFLR_reg))
#define IC5_TXFLR_inst_adr                                                           "0x00DD"
#define IC5_TXFLR_inst                                                               0x00DD
#define IC5_TXFLR_TXFLR_shift                                                        (0)
#define IC5_TXFLR_TXFLR_mask                                                         (0x0000000F)
#define IC5_TXFLR_TXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC5_TXFLR_TXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC5_TXFLR_get_TXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC5_RXFLR                                                                    0x1801BB78
#define IC5_RXFLR_reg_addr                                                           "0xB801BB78"
#define IC5_RXFLR_reg                                                                0xB801BB78
#define set_IC5_RXFLR_reg(data)   (*((volatile unsigned int*) IC5_RXFLR_reg)=data)
#define get_IC5_RXFLR_reg   (*((volatile unsigned int*) IC5_RXFLR_reg))
#define IC5_RXFLR_inst_adr                                                           "0x00DE"
#define IC5_RXFLR_inst                                                               0x00DE
#define IC5_RXFLR_RXFLR_shift                                                        (0)
#define IC5_RXFLR_RXFLR_mask                                                         (0x0000000F)
#define IC5_RXFLR_RXFLR(data)                                                        (0x0000000F&((data)<<0))
#define IC5_RXFLR_RXFLR_src(data)                                                    ((0x0000000F&(data))>>0)
#define IC5_RXFLR_get_RXFLR(data)                                                    ((0x0000000F&(data))>>0)


#define IC5_SDA_HOLD                                                                 0x1801BB7C
#define IC5_SDA_HOLD_reg_addr                                                        "0xB801BB7C"
#define IC5_SDA_HOLD_reg                                                             0xB801BB7C
#define set_IC5_SDA_HOLD_reg(data)   (*((volatile unsigned int*) IC5_SDA_HOLD_reg)=data)
#define get_IC5_SDA_HOLD_reg   (*((volatile unsigned int*) IC5_SDA_HOLD_reg))
#define IC5_SDA_HOLD_inst_adr                                                        "0x00DF"
#define IC5_SDA_HOLD_inst                                                            0x00DF
#define IC5_SDA_HOLD_SDA_HOLD_shift                                                  (0)
#define IC5_SDA_HOLD_SDA_HOLD_mask                                                   (0x0000FFFF)
#define IC5_SDA_HOLD_SDA_HOLD(data)                                                  (0x0000FFFF&((data)<<0))
#define IC5_SDA_HOLD_SDA_HOLD_src(data)                                              ((0x0000FFFF&(data))>>0)
#define IC5_SDA_HOLD_get_SDA_HOLD(data)                                              ((0x0000FFFF&(data))>>0)


#define IC5_TX_ABRT_SOURCE                                                           0x1801BB80
#define IC5_TX_ABRT_SOURCE_reg_addr                                                  "0xB801BB80"
#define IC5_TX_ABRT_SOURCE_reg                                                       0xB801BB80
#define set_IC5_TX_ABRT_SOURCE_reg(data)   (*((volatile unsigned int*) IC5_TX_ABRT_SOURCE_reg)=data)
#define get_IC5_TX_ABRT_SOURCE_reg   (*((volatile unsigned int*) IC5_TX_ABRT_SOURCE_reg))
#define IC5_TX_ABRT_SOURCE_inst_adr                                                  "0x00E0"
#define IC5_TX_ABRT_SOURCE_inst                                                      0x00E0
#define IC5_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_shift                                     (15)
#define IC5_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_mask                                      (0x00008000)
#define IC5_TX_ABRT_SOURCE_ABRT_SLVRD_INTX(data)                                     (0x00008000&((data)<<15))
#define IC5_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_src(data)                                 ((0x00008000&(data))>>15)
#define IC5_TX_ABRT_SOURCE_get_ABRT_SLVRD_INTX(data)                                 ((0x00008000&(data))>>15)
#define IC5_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_shift                                    (14)
#define IC5_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_mask                                     (0x00004000)
#define IC5_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST(data)                                    (0x00004000&((data)<<14))
#define IC5_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_src(data)                                ((0x00004000&(data))>>14)
#define IC5_TX_ABRT_SOURCE_get_ABRT_SLV_ARBLOST(data)                                ((0x00004000&(data))>>14)
#define IC5_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_shift                                (13)
#define IC5_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_mask                                 (0x00002000)
#define IC5_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO(data)                                (0x00002000&((data)<<13))
#define IC5_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_src(data)                            ((0x00002000&(data))>>13)
#define IC5_TX_ABRT_SOURCE_get_ABRT_SLVFLUSH_TXFIFO(data)                            ((0x00002000&(data))>>13)
#define IC5_TX_ABRT_SOURCE_ARB_LOST_shift                                            (12)
#define IC5_TX_ABRT_SOURCE_ARB_LOST_mask                                             (0x00001000)
#define IC5_TX_ABRT_SOURCE_ARB_LOST(data)                                            (0x00001000&((data)<<12))
#define IC5_TX_ABRT_SOURCE_ARB_LOST_src(data)                                        ((0x00001000&(data))>>12)
#define IC5_TX_ABRT_SOURCE_get_ARB_LOST(data)                                        ((0x00001000&(data))>>12)
#define IC5_TX_ABRT_SOURCE_ARB_MASTER_DIS_shift                                      (11)
#define IC5_TX_ABRT_SOURCE_ARB_MASTER_DIS_mask                                       (0x00000800)
#define IC5_TX_ABRT_SOURCE_ARB_MASTER_DIS(data)                                      (0x00000800&((data)<<11))
#define IC5_TX_ABRT_SOURCE_ARB_MASTER_DIS_src(data)                                  ((0x00000800&(data))>>11)
#define IC5_TX_ABRT_SOURCE_get_ARB_MASTER_DIS(data)                                  ((0x00000800&(data))>>11)
#define IC5_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_shift                                 (10)
#define IC5_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_mask                                  (0x00000400)
#define IC5_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT(data)                                 (0x00000400&((data)<<10))
#define IC5_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_src(data)                             ((0x00000400&(data))>>10)
#define IC5_TX_ABRT_SOURCE_get_ABRT_10B_RD_NORSTRT(data)                             ((0x00000400&(data))>>10)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_shift                                  (9)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_mask                                   (0x00000200)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT(data)                                  (0x00000200&((data)<<9))
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_src(data)                              ((0x00000200&(data))>>9)
#define IC5_TX_ABRT_SOURCE_get_ABRT_SBYTE_NORSTRT(data)                              ((0x00000200&(data))>>9)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_shift                                     (8)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_mask                                      (0x00000100)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_NORSTRT(data)                                     (0x00000100&((data)<<8))
#define IC5_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_src(data)                                 ((0x00000100&(data))>>8)
#define IC5_TX_ABRT_SOURCE_get_ABRT_HS_NORSTRT(data)                                 ((0x00000100&(data))>>8)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_shift                                   (7)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_mask                                    (0x00000080)
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET(data)                                   (0x00000080&((data)<<7))
#define IC5_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_src(data)                               ((0x00000080&(data))>>7)
#define IC5_TX_ABRT_SOURCE_get_ABRT_SBYTE_ACKDET(data)                               ((0x00000080&(data))>>7)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_ACKDET_shift                                      (6)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_ACKDET_mask                                       (0x00000040)
#define IC5_TX_ABRT_SOURCE_ABRT_HS_ACKDET(data)                                      (0x00000040&((data)<<6))
#define IC5_TX_ABRT_SOURCE_ABRT_HS_ACKDET_src(data)                                  ((0x00000040&(data))>>6)
#define IC5_TX_ABRT_SOURCE_get_ABRT_HS_ACKDET(data)                                  ((0x00000040&(data))>>6)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_READ_shift                                     (5)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_READ_mask                                      (0x00000020)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_READ(data)                                     (0x00000020&((data)<<5))
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_READ_src(data)                                 ((0x00000020&(data))>>5)
#define IC5_TX_ABRT_SOURCE_get_ABRT_GCALL_READ(data)                                 ((0x00000020&(data))>>5)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_shift                                    (4)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_mask                                     (0x00000010)
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_NOACK(data)                                    (0x00000010&((data)<<4))
#define IC5_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_src(data)                                ((0x00000010&(data))>>4)
#define IC5_TX_ABRT_SOURCE_get_ABRT_GCALL_NOACK(data)                                ((0x00000010&(data))>>4)
#define IC5_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_shift                                   (3)
#define IC5_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_mask                                    (0x00000008)
#define IC5_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK(data)                                   (0x00000008&((data)<<3))
#define IC5_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_src(data)                               ((0x00000008&(data))>>3)
#define IC5_TX_ABRT_SOURCE_get_ABRT_TXDATA_NOACK(data)                               ((0x00000008&(data))>>3)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_shift                                  (2)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_mask                                   (0x00000004)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK(data)                                  (0x00000004&((data)<<2))
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_src(data)                              ((0x00000004&(data))>>2)
#define IC5_TX_ABRT_SOURCE_get_ABRT_10ADDR2_NOACK(data)                              ((0x00000004&(data))>>2)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_shift                                  (1)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_mask                                   (0x00000002)
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK(data)                                  (0x00000002&((data)<<1))
#define IC5_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_src(data)                              ((0x00000002&(data))>>1)
#define IC5_TX_ABRT_SOURCE_get_ABRT_10ADDR1_NOACK(data)                              ((0x00000002&(data))>>1)
#define IC5_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_shift                                  (0)
#define IC5_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_mask                                   (0x00000001)
#define IC5_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK(data)                                  (0x00000001&((data)<<0))
#define IC5_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_src(data)                              ((0x00000001&(data))>>0)
#define IC5_TX_ABRT_SOURCE_get_ABRT_7B_ADDR_NOACK(data)                              ((0x00000001&(data))>>0)


#define IC5_SLV_DATA_NACK_ONLY                                                       0x1801BB84
#define IC5_SLV_DATA_NACK_ONLY_reg_addr                                              "0xB801BB84"
#define IC5_SLV_DATA_NACK_ONLY_reg                                                   0xB801BB84
#define set_IC5_SLV_DATA_NACK_ONLY_reg(data)   (*((volatile unsigned int*) IC5_SLV_DATA_NACK_ONLY_reg)=data)
#define get_IC5_SLV_DATA_NACK_ONLY_reg   (*((volatile unsigned int*) IC5_SLV_DATA_NACK_ONLY_reg))
#define IC5_SLV_DATA_NACK_ONLY_inst_adr                                              "0x00E1"
#define IC5_SLV_DATA_NACK_ONLY_inst                                                  0x00E1
#define IC5_SLV_DATA_NACK_ONLY_NACK_shift                                            (0)
#define IC5_SLV_DATA_NACK_ONLY_NACK_mask                                             (0x00000001)
#define IC5_SLV_DATA_NACK_ONLY_NACK(data)                                            (0x00000001&((data)<<0))
#define IC5_SLV_DATA_NACK_ONLY_NACK_src(data)                                        ((0x00000001&(data))>>0)
#define IC5_SLV_DATA_NACK_ONLY_get_NACK(data)                                        ((0x00000001&(data))>>0)


#define IC5_DMA_CR                                                                   0x1801BB88
#define IC5_DMA_CR_reg_addr                                                          "0xB801BB88"
#define IC5_DMA_CR_reg                                                               0xB801BB88
#define set_IC5_DMA_CR_reg(data)   (*((volatile unsigned int*) IC5_DMA_CR_reg)=data)
#define get_IC5_DMA_CR_reg   (*((volatile unsigned int*) IC5_DMA_CR_reg))
#define IC5_DMA_CR_inst_adr                                                          "0x00E2"
#define IC5_DMA_CR_inst                                                              0x00E2
#define IC5_DMA_CR_TDMAE_shift                                                       (1)
#define IC5_DMA_CR_TDMAE_mask                                                        (0x00000002)
#define IC5_DMA_CR_TDMAE(data)                                                       (0x00000002&((data)<<1))
#define IC5_DMA_CR_TDMAE_src(data)                                                   ((0x00000002&(data))>>1)
#define IC5_DMA_CR_get_TDMAE(data)                                                   ((0x00000002&(data))>>1)
#define IC5_DMA_CR_RDMAE_shift                                                       (0)
#define IC5_DMA_CR_RDMAE_mask                                                        (0x00000001)
#define IC5_DMA_CR_RDMAE(data)                                                       (0x00000001&((data)<<0))
#define IC5_DMA_CR_RDMAE_src(data)                                                   ((0x00000001&(data))>>0)
#define IC5_DMA_CR_get_RDMAE(data)                                                   ((0x00000001&(data))>>0)


#define IC5_DMA_TDLR                                                                 0x1801BB8C
#define IC5_DMA_TDLR_reg_addr                                                        "0xB801BB8C"
#define IC5_DMA_TDLR_reg                                                             0xB801BB8C
#define set_IC5_DMA_TDLR_reg(data)   (*((volatile unsigned int*) IC5_DMA_TDLR_reg)=data)
#define get_IC5_DMA_TDLR_reg   (*((volatile unsigned int*) IC5_DMA_TDLR_reg))
#define IC5_DMA_TDLR_inst_adr                                                        "0x00E3"
#define IC5_DMA_TDLR_inst                                                            0x00E3
#define IC5_DMA_TDLR_DMATDL_shift                                                    (0)
#define IC5_DMA_TDLR_DMATDL_mask                                                     (0x00000007)
#define IC5_DMA_TDLR_DMATDL(data)                                                    (0x00000007&((data)<<0))
#define IC5_DMA_TDLR_DMATDL_src(data)                                                ((0x00000007&(data))>>0)
#define IC5_DMA_TDLR_get_DMATDL(data)                                                ((0x00000007&(data))>>0)


#define IC5_DMA_RDLR                                                                 0x1801BB90
#define IC5_DMA_RDLR_reg_addr                                                        "0xB801BB90"
#define IC5_DMA_RDLR_reg                                                             0xB801BB90
#define set_IC5_DMA_RDLR_reg(data)   (*((volatile unsigned int*) IC5_DMA_RDLR_reg)=data)
#define get_IC5_DMA_RDLR_reg   (*((volatile unsigned int*) IC5_DMA_RDLR_reg))
#define IC5_DMA_RDLR_inst_adr                                                        "0x00E4"
#define IC5_DMA_RDLR_inst                                                            0x00E4
#define IC5_DMA_RDLR_DMARDL_shift                                                    (0)
#define IC5_DMA_RDLR_DMARDL_mask                                                     (0x0000000F)
#define IC5_DMA_RDLR_DMARDL(data)                                                    (0x0000000F&((data)<<0))
#define IC5_DMA_RDLR_DMARDL_src(data)                                                ((0x0000000F&(data))>>0)
#define IC5_DMA_RDLR_get_DMARDL(data)                                                ((0x0000000F&(data))>>0)


#define IC5_SDA_SETUP                                                                0x1801BB94
#define IC5_SDA_SETUP_reg_addr                                                       "0xB801BB94"
#define IC5_SDA_SETUP_reg                                                            0xB801BB94
#define set_IC5_SDA_SETUP_reg(data)   (*((volatile unsigned int*) IC5_SDA_SETUP_reg)=data)
#define get_IC5_SDA_SETUP_reg   (*((volatile unsigned int*) IC5_SDA_SETUP_reg))
#define IC5_SDA_SETUP_inst_adr                                                       "0x00E5"
#define IC5_SDA_SETUP_inst                                                           0x00E5
#define IC5_SDA_SETUP_SDA_SETUP_shift                                                (0)
#define IC5_SDA_SETUP_SDA_SETUP_mask                                                 (0x000000FF)
#define IC5_SDA_SETUP_SDA_SETUP(data)                                                (0x000000FF&((data)<<0))
#define IC5_SDA_SETUP_SDA_SETUP_src(data)                                            ((0x000000FF&(data))>>0)
#define IC5_SDA_SETUP_get_SDA_SETUP(data)                                            ((0x000000FF&(data))>>0)


#define IC5_ACK_GENERAL_CALL                                                         0x1801BB98
#define IC5_ACK_GENERAL_CALL_reg_addr                                                "0xB801BB98"
#define IC5_ACK_GENERAL_CALL_reg                                                     0xB801BB98
#define set_IC5_ACK_GENERAL_CALL_reg(data)   (*((volatile unsigned int*) IC5_ACK_GENERAL_CALL_reg)=data)
#define get_IC5_ACK_GENERAL_CALL_reg   (*((volatile unsigned int*) IC5_ACK_GENERAL_CALL_reg))
#define IC5_ACK_GENERAL_CALL_inst_adr                                                "0x00E6"
#define IC5_ACK_GENERAL_CALL_inst                                                    0x00E6
#define IC5_ACK_GENERAL_CALL_ACK_GEN_CALL_shift                                      (0)
#define IC5_ACK_GENERAL_CALL_ACK_GEN_CALL_mask                                       (0x00000001)
#define IC5_ACK_GENERAL_CALL_ACK_GEN_CALL(data)                                      (0x00000001&((data)<<0))
#define IC5_ACK_GENERAL_CALL_ACK_GEN_CALL_src(data)                                  ((0x00000001&(data))>>0)
#define IC5_ACK_GENERAL_CALL_get_ACK_GEN_CALL(data)                                  ((0x00000001&(data))>>0)


#define IC5_ENABLE_STATUS                                                            0x1801BB9C
#define IC5_ENABLE_STATUS_reg_addr                                                   "0xB801BB9C"
#define IC5_ENABLE_STATUS_reg                                                        0xB801BB9C
#define set_IC5_ENABLE_STATUS_reg(data)   (*((volatile unsigned int*) IC5_ENABLE_STATUS_reg)=data)
#define get_IC5_ENABLE_STATUS_reg   (*((volatile unsigned int*) IC5_ENABLE_STATUS_reg))
#define IC5_ENABLE_STATUS_inst_adr                                                   "0x00E7"
#define IC5_ENABLE_STATUS_inst                                                       0x00E7
#define IC5_ENABLE_STATUS_SLV_RX_DATA_LOST_shift                                     (2)
#define IC5_ENABLE_STATUS_SLV_RX_DATA_LOST_mask                                      (0x00000004)
#define IC5_ENABLE_STATUS_SLV_RX_DATA_LOST(data)                                     (0x00000004&((data)<<2))
#define IC5_ENABLE_STATUS_SLV_RX_DATA_LOST_src(data)                                 ((0x00000004&(data))>>2)
#define IC5_ENABLE_STATUS_get_SLV_RX_DATA_LOST(data)                                 ((0x00000004&(data))>>2)
#define IC5_ENABLE_STATUS_SLV_DISABLED_WHI_shift                                     (1)
#define IC5_ENABLE_STATUS_SLV_DISABLED_WHI_mask                                      (0x00000002)
#define IC5_ENABLE_STATUS_SLV_DISABLED_WHI(data)                                     (0x00000002&((data)<<1))
#define IC5_ENABLE_STATUS_SLV_DISABLED_WHI_src(data)                                 ((0x00000002&(data))>>1)
#define IC5_ENABLE_STATUS_get_SLV_DISABLED_WHI(data)                                 ((0x00000002&(data))>>1)
#define IC5_ENABLE_STATUS_IC_EN_shift                                                (0)
#define IC5_ENABLE_STATUS_IC_EN_mask                                                 (0x00000001)
#define IC5_ENABLE_STATUS_IC_EN(data)                                                (0x00000001&((data)<<0))
#define IC5_ENABLE_STATUS_IC_EN_src(data)                                            ((0x00000001&(data))>>0)
#define IC5_ENABLE_STATUS_get_IC_EN(data)                                            ((0x00000001&(data))>>0)


#define IC5_COMP_PARAM_1                                                             0x1801BBF4
#define IC5_COMP_PARAM_1_reg_addr                                                    "0xB801BBF4"
#define IC5_COMP_PARAM_1_reg                                                         0xB801BBF4
#define set_IC5_COMP_PARAM_1_reg(data)   (*((volatile unsigned int*) IC5_COMP_PARAM_1_reg)=data)
#define get_IC5_COMP_PARAM_1_reg   (*((volatile unsigned int*) IC5_COMP_PARAM_1_reg))
#define IC5_COMP_PARAM_1_inst_adr                                                    "0x00FD"
#define IC5_COMP_PARAM_1_inst                                                        0x00FD
#define IC5_COMP_PARAM_1_TX_BUFFER_DEPTH_shift                                       (16)
#define IC5_COMP_PARAM_1_TX_BUFFER_DEPTH_mask                                        (0x00FF0000)
#define IC5_COMP_PARAM_1_TX_BUFFER_DEPTH(data)                                       (0x00FF0000&((data)<<16))
#define IC5_COMP_PARAM_1_TX_BUFFER_DEPTH_src(data)                                   ((0x00FF0000&(data))>>16)
#define IC5_COMP_PARAM_1_get_TX_BUFFER_DEPTH(data)                                   ((0x00FF0000&(data))>>16)
#define IC5_COMP_PARAM_1_RX_BUFFER_DEPTH_shift                                       (8)
#define IC5_COMP_PARAM_1_RX_BUFFER_DEPTH_mask                                        (0x0000FF00)
#define IC5_COMP_PARAM_1_RX_BUFFER_DEPTH(data)                                       (0x0000FF00&((data)<<8))
#define IC5_COMP_PARAM_1_RX_BUFFER_DEPTH_src(data)                                   ((0x0000FF00&(data))>>8)
#define IC5_COMP_PARAM_1_get_RX_BUFFER_DEPTH(data)                                   ((0x0000FF00&(data))>>8)
#define IC5_COMP_PARAM_1_ADD_ENCODED_PARAMS_shift                                    (7)
#define IC5_COMP_PARAM_1_ADD_ENCODED_PARAMS_mask                                     (0x00000080)
#define IC5_COMP_PARAM_1_ADD_ENCODED_PARAMS(data)                                    (0x00000080&((data)<<7))
#define IC5_COMP_PARAM_1_ADD_ENCODED_PARAMS_src(data)                                ((0x00000080&(data))>>7)
#define IC5_COMP_PARAM_1_get_ADD_ENCODED_PARAMS(data)                                ((0x00000080&(data))>>7)
#define IC5_COMP_PARAM_1_HAS_DMA_shift                                               (6)
#define IC5_COMP_PARAM_1_HAS_DMA_mask                                                (0x00000040)
#define IC5_COMP_PARAM_1_HAS_DMA(data)                                               (0x00000040&((data)<<6))
#define IC5_COMP_PARAM_1_HAS_DMA_src(data)                                           ((0x00000040&(data))>>6)
#define IC5_COMP_PARAM_1_get_HAS_DMA(data)                                           ((0x00000040&(data))>>6)
#define IC5_COMP_PARAM_1_INTR_IO_shift                                               (5)
#define IC5_COMP_PARAM_1_INTR_IO_mask                                                (0x00000020)
#define IC5_COMP_PARAM_1_INTR_IO(data)                                               (0x00000020&((data)<<5))
#define IC5_COMP_PARAM_1_INTR_IO_src(data)                                           ((0x00000020&(data))>>5)
#define IC5_COMP_PARAM_1_get_INTR_IO(data)                                           ((0x00000020&(data))>>5)
#define IC5_COMP_PARAM_1_HC_COUNT_VALUES_shift                                       (4)
#define IC5_COMP_PARAM_1_HC_COUNT_VALUES_mask                                        (0x00000010)
#define IC5_COMP_PARAM_1_HC_COUNT_VALUES(data)                                       (0x00000010&((data)<<4))
#define IC5_COMP_PARAM_1_HC_COUNT_VALUES_src(data)                                   ((0x00000010&(data))>>4)
#define IC5_COMP_PARAM_1_get_HC_COUNT_VALUES(data)                                   ((0x00000010&(data))>>4)
#define IC5_COMP_PARAM_1_MAX_SPEED_MODE_shift                                        (2)
#define IC5_COMP_PARAM_1_MAX_SPEED_MODE_mask                                         (0x0000000C)
#define IC5_COMP_PARAM_1_MAX_SPEED_MODE(data)                                        (0x0000000C&((data)<<2))
#define IC5_COMP_PARAM_1_MAX_SPEED_MODE_src(data)                                    ((0x0000000C&(data))>>2)
#define IC5_COMP_PARAM_1_get_MAX_SPEED_MODE(data)                                    ((0x0000000C&(data))>>2)
#define IC5_COMP_PARAM_1_APB_DATA_WIDTH_shift                                        (0)
#define IC5_COMP_PARAM_1_APB_DATA_WIDTH_mask                                         (0x00000003)
#define IC5_COMP_PARAM_1_APB_DATA_WIDTH(data)                                        (0x00000003&((data)<<0))
#define IC5_COMP_PARAM_1_APB_DATA_WIDTH_src(data)                                    ((0x00000003&(data))>>0)
#define IC5_COMP_PARAM_1_get_APB_DATA_WIDTH(data)                                    ((0x00000003&(data))>>0)


#define IC5_COMP_VERSION                                                             0x1801BBF8
#define IC5_COMP_VERSION_reg_addr                                                    "0xB801BBF8"
#define IC5_COMP_VERSION_reg                                                         0xB801BBF8
#define set_IC5_COMP_VERSION_reg(data)   (*((volatile unsigned int*) IC5_COMP_VERSION_reg)=data)
#define get_IC5_COMP_VERSION_reg   (*((volatile unsigned int*) IC5_COMP_VERSION_reg))
#define IC5_COMP_VERSION_inst_adr                                                    "0x00FE"
#define IC5_COMP_VERSION_inst                                                        0x00FE
#define IC5_COMP_VERSION_IC_COMP_VERSION_shift                                       (0)
#define IC5_COMP_VERSION_IC_COMP_VERSION_mask                                        (0xFFFFFFFF)
#define IC5_COMP_VERSION_IC_COMP_VERSION(data)                                       (0xFFFFFFFF&((data)<<0))
#define IC5_COMP_VERSION_IC_COMP_VERSION_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define IC5_COMP_VERSION_get_IC_COMP_VERSION(data)                                   ((0xFFFFFFFF&(data))>>0)


#define IC5_COMP_TYPE                                                                0x1801BBFC
#define IC5_COMP_TYPE_reg_addr                                                       "0xB801BBFC"
#define IC5_COMP_TYPE_reg                                                            0xB801BBFC
#define set_IC5_COMP_TYPE_reg(data)   (*((volatile unsigned int*) IC5_COMP_TYPE_reg)=data)
#define get_IC5_COMP_TYPE_reg   (*((volatile unsigned int*) IC5_COMP_TYPE_reg))
#define IC5_COMP_TYPE_inst_adr                                                       "0x00FF"
#define IC5_COMP_TYPE_inst                                                           0x00FF
#define IC5_COMP_TYPE_IC_COMP_TYPE_shift                                             (0)
#define IC5_COMP_TYPE_IC_COMP_TYPE_mask                                              (0xFFFFFFFF)
#define IC5_COMP_TYPE_IC_COMP_TYPE(data)                                             (0xFFFFFFFF&((data)<<0))
#define IC5_COMP_TYPE_IC_COMP_TYPE_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IC5_COMP_TYPE_get_IC_COMP_TYPE(data)                                         ((0xFFFFFFFF&(data))>>0)


#define TC0TVR                                                                       0x1801B500
#define TC0TVR_reg_addr                                                              "0x1801B500"
#define TC0TVR_reg                                                                   0x1801B500
#define set_TC0TVR_reg(data)   (*((volatile unsigned int*) TC0TVR_reg)=data)
#define get_TC0TVR_reg   (*((volatile unsigned int*) TC0TVR_reg))
#define TC0TVR_inst_adr                                                              "0x0040"
#define TC0TVR_inst                                                                  0x0040
#define TC0TVR_TC0TVR_shift                                                          (0)
#define TC0TVR_TC0TVR_mask                                                           (0xFFFFFFFF)
#define TC0TVR_TC0TVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC0TVR_TC0TVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC0TVR_get_TC0TVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC1TVR                                                                       0x1801B504
#define TC1TVR_reg_addr                                                              "0x1801B504"
#define TC1TVR_reg                                                                   0x1801B504
#define set_TC1TVR_reg(data)   (*((volatile unsigned int*) TC1TVR_reg)=data)
#define get_TC1TVR_reg   (*((volatile unsigned int*) TC1TVR_reg))
#define TC1TVR_inst_adr                                                              "0x0041"
#define TC1TVR_inst                                                                  0x0041
#define TC1TVR_TC1TVR_shift                                                          (0)
#define TC1TVR_TC1TVR_mask                                                           (0xFFFFFFFF)
#define TC1TVR_TC1TVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC1TVR_TC1TVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC1TVR_get_TC1TVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC2TVR                                                                       0x1801B508
#define TC2TVR_reg_addr                                                              "0x1801B508"
#define TC2TVR_reg                                                                   0x1801B508
#define set_TC2TVR_reg(data)   (*((volatile unsigned int*) TC2TVR_reg)=data)
#define get_TC2TVR_reg   (*((volatile unsigned int*) TC2TVR_reg))
#define TC2TVR_inst_adr                                                              "0x0042"
#define TC2TVR_inst                                                                  0x0042
#define TC2TVR_TC2TVR_shift                                                          (0)
#define TC2TVR_TC2TVR_mask                                                           (0xFFFFFFFF)
#define TC2TVR_TC2TVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC2TVR_TC2TVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC2TVR_get_TC2TVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC0CVR                                                                       0x1801B50C
#define TC0CVR_reg_addr                                                              "0x1801B50C"
#define TC0CVR_reg                                                                   0x1801B50C
#define set_TC0CVR_reg(data)   (*((volatile unsigned int*) TC0CVR_reg)=data)
#define get_TC0CVR_reg   (*((volatile unsigned int*) TC0CVR_reg))
#define TC0CVR_inst_adr                                                              "0x0043"
#define TC0CVR_inst                                                                  0x0043
#define TC0CVR_TC0CVR_shift                                                          (0)
#define TC0CVR_TC0CVR_mask                                                           (0xFFFFFFFF)
#define TC0CVR_TC0CVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC0CVR_TC0CVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC0CVR_get_TC0CVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC1CVR                                                                       0x1801B510
#define TC1CVR_reg_addr                                                              "0x1801B510"
#define TC1CVR_reg                                                                   0x1801B510
#define set_TC1CVR_reg(data)   (*((volatile unsigned int*) TC1CVR_reg)=data)
#define get_TC1CVR_reg   (*((volatile unsigned int*) TC1CVR_reg))
#define TC1CVR_inst_adr                                                              "0x0044"
#define TC1CVR_inst                                                                  0x0044
#define TC1CVR_TC1CVR_shift                                                          (0)
#define TC1CVR_TC1CVR_mask                                                           (0xFFFFFFFF)
#define TC1CVR_TC1CVR(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TC1CVR_TC1CVR_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TC1CVR_get_TC1CVR(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define TC2CVR                                                                       0x1801B514
#define TC2CVR_reg_addr                                                              "0x1801B514"
#define TC2CVR_reg                                                                   0x1801B514
#define set_TC2CVR_reg(data)   (*((volatile unsigned int*) TC2CVR_reg)=data)
#define get_TC2CVR_reg   (*((volatile unsigned int*) TC2CVR_reg))
#define TC2CVR_inst_adr                                                              "0x0045"
#define TC2CVR_inst                                                                  0x0045
#define TC2CVR_TC2VR_shift                                                           (0)
#define TC2CVR_TC2VR_mask                                                            (0xFFFFFFFF)
#define TC2CVR_TC2VR(data)                                                           (0xFFFFFFFF&((data)<<0))
#define TC2CVR_TC2VR_src(data)                                                       ((0xFFFFFFFF&(data))>>0)
#define TC2CVR_get_TC2VR(data)                                                       ((0xFFFFFFFF&(data))>>0)


#define TC0CR                                                                        0x1801B518
#define TC0CR_reg_addr                                                               "0x1801B518"
#define TC0CR_reg                                                                    0x1801B518
#define set_TC0CR_reg(data)   (*((volatile unsigned int*) TC0CR_reg)=data)
#define get_TC0CR_reg   (*((volatile unsigned int*) TC0CR_reg))
#define TC0CR_inst_adr                                                               "0x0046"
#define TC0CR_inst                                                                   0x0046
#define TC0CR_TC0En_shift                                                            (31)
#define TC0CR_TC0En_mask                                                             (0x80000000)
#define TC0CR_TC0En(data)                                                            (0x80000000&((data)<<31))
#define TC0CR_TC0En_src(data)                                                        ((0x80000000&(data))>>31)
#define TC0CR_get_TC0En(data)                                                        ((0x80000000&(data))>>31)
#define TC0CR_TC0Mode_shift                                                          (30)
#define TC0CR_TC0Mode_mask                                                           (0x40000000)
#define TC0CR_TC0Mode(data)                                                          (0x40000000&((data)<<30))
#define TC0CR_TC0Mode_src(data)                                                      ((0x40000000&(data))>>30)
#define TC0CR_get_TC0Mode(data)                                                      ((0x40000000&(data))>>30)
#define TC0CR_TC0Pause_shift                                                         (29)
#define TC0CR_TC0Pause_mask                                                          (0x20000000)
#define TC0CR_TC0Pause(data)                                                         (0x20000000&((data)<<29))
#define TC0CR_TC0Pause_src(data)                                                     ((0x20000000&(data))>>29)
#define TC0CR_get_TC0Pause(data)                                                     ((0x20000000&(data))>>29)
#define TC0CR_RvdA_shift                                                             (24)
#define TC0CR_RvdA_mask                                                              (0x1F000000)
#define TC0CR_RvdA(data)                                                             (0x1F000000&((data)<<24))
#define TC0CR_RvdA_src(data)                                                         ((0x1F000000&(data))>>24)
#define TC0CR_get_RvdA(data)                                                         ((0x1F000000&(data))>>24)


#define TC1CR                                                                        0x1801B51C
#define TC1CR_reg_addr                                                               "0x1801B51C"
#define TC1CR_reg                                                                    0x1801B51C
#define set_TC1CR_reg(data)   (*((volatile unsigned int*) TC1CR_reg)=data)
#define get_TC1CR_reg   (*((volatile unsigned int*) TC1CR_reg))
#define TC1CR_inst_adr                                                               "0x0047"
#define TC1CR_inst                                                                   0x0047
#define TC1CR_TC1En_shift                                                            (31)
#define TC1CR_TC1En_mask                                                             (0x80000000)
#define TC1CR_TC1En(data)                                                            (0x80000000&((data)<<31))
#define TC1CR_TC1En_src(data)                                                        ((0x80000000&(data))>>31)
#define TC1CR_get_TC1En(data)                                                        ((0x80000000&(data))>>31)
#define TC1CR_TC1Mode_shift                                                          (30)
#define TC1CR_TC1Mode_mask                                                           (0x40000000)
#define TC1CR_TC1Mode(data)                                                          (0x40000000&((data)<<30))
#define TC1CR_TC1Mode_src(data)                                                      ((0x40000000&(data))>>30)
#define TC1CR_get_TC1Mode(data)                                                      ((0x40000000&(data))>>30)
#define TC1CR_TC1Pause_shift                                                         (29)
#define TC1CR_TC1Pause_mask                                                          (0x20000000)
#define TC1CR_TC1Pause(data)                                                         (0x20000000&((data)<<29))
#define TC1CR_TC1Pause_src(data)                                                     ((0x20000000&(data))>>29)
#define TC1CR_get_TC1Pause(data)                                                     ((0x20000000&(data))>>29)
#define TC1CR_RvdA_shift                                                             (24)
#define TC1CR_RvdA_mask                                                              (0x1F000000)
#define TC1CR_RvdA(data)                                                             (0x1F000000&((data)<<24))
#define TC1CR_RvdA_src(data)                                                         ((0x1F000000&(data))>>24)
#define TC1CR_get_RvdA(data)                                                         ((0x1F000000&(data))>>24)


#define TC2CR                                                                        0x1801B520
#define TC2CR_reg_addr                                                               "0x1801B520"
#define TC2CR_reg                                                                    0x1801B520
#define set_TC2CR_reg(data)   (*((volatile unsigned int*) TC2CR_reg)=data)
#define get_TC2CR_reg   (*((volatile unsigned int*) TC2CR_reg))
#define TC2CR_inst_adr                                                               "0x0048"
#define TC2CR_inst                                                                   0x0048
#define TC2CR_TC2En_shift                                                            (31)
#define TC2CR_TC2En_mask                                                             (0x80000000)
#define TC2CR_TC2En(data)                                                            (0x80000000&((data)<<31))
#define TC2CR_TC2En_src(data)                                                        ((0x80000000&(data))>>31)
#define TC2CR_get_TC2En(data)                                                        ((0x80000000&(data))>>31)
#define TC2CR_TC2Mode_shift                                                          (30)
#define TC2CR_TC2Mode_mask                                                           (0x40000000)
#define TC2CR_TC2Mode(data)                                                          (0x40000000&((data)<<30))
#define TC2CR_TC2Mode_src(data)                                                      ((0x40000000&(data))>>30)
#define TC2CR_get_TC2Mode(data)                                                      ((0x40000000&(data))>>30)
#define TC2CR_TC2Pause_shift                                                         (29)
#define TC2CR_TC2Pause_mask                                                          (0x20000000)
#define TC2CR_TC2Pause(data)                                                         (0x20000000&((data)<<29))
#define TC2CR_TC2Pause_src(data)                                                     ((0x20000000&(data))>>29)
#define TC2CR_get_TC2Pause(data)                                                     ((0x20000000&(data))>>29)
#define TC2CR_RvdA_shift                                                             (24)
#define TC2CR_RvdA_mask                                                              (0x1F000000)
#define TC2CR_RvdA(data)                                                             (0x1F000000&((data)<<24))
#define TC2CR_RvdA_src(data)                                                         ((0x1F000000&(data))>>24)
#define TC2CR_get_RvdA(data)                                                         ((0x1F000000&(data))>>24)


#define TC0ICR                                                                       0x1801B524
#define TC0ICR_reg_addr                                                              "0x1801B524"
#define TC0ICR_reg                                                                   0x1801B524
#define set_TC0ICR_reg(data)   (*((volatile unsigned int*) TC0ICR_reg)=data)
#define get_TC0ICR_reg   (*((volatile unsigned int*) TC0ICR_reg))
#define TC0ICR_inst_adr                                                              "0x0049"
#define TC0ICR_inst                                                                  0x0049
#define TC0ICR_TC0IE_shift                                                           (31)
#define TC0ICR_TC0IE_mask                                                            (0x80000000)
#define TC0ICR_TC0IE(data)                                                           (0x80000000&((data)<<31))
#define TC0ICR_TC0IE_src(data)                                                       ((0x80000000&(data))>>31)
#define TC0ICR_get_TC0IE(data)                                                       ((0x80000000&(data))>>31)


#define TC1ICR                                                                       0x1801B528
#define TC1ICR_reg_addr                                                              "0x1801B528"
#define TC1ICR_reg                                                                   0x1801B528
#define set_TC1ICR_reg(data)   (*((volatile unsigned int*) TC1ICR_reg)=data)
#define get_TC1ICR_reg   (*((volatile unsigned int*) TC1ICR_reg))
#define TC1ICR_inst_adr                                                              "0x004A"
#define TC1ICR_inst                                                                  0x004A
#define TC1ICR_TC1IE_shift                                                           (31)
#define TC1ICR_TC1IE_mask                                                            (0x80000000)
#define TC1ICR_TC1IE(data)                                                           (0x80000000&((data)<<31))
#define TC1ICR_TC1IE_src(data)                                                       ((0x80000000&(data))>>31)
#define TC1ICR_get_TC1IE(data)                                                       ((0x80000000&(data))>>31)


#define TC2ICR                                                                       0x1801B52C
#define TC2ICR_reg_addr                                                              "0x1801B52C"
#define TC2ICR_reg                                                                   0x1801B52C
#define set_TC2ICR_reg(data)   (*((volatile unsigned int*) TC2ICR_reg)=data)
#define get_TC2ICR_reg   (*((volatile unsigned int*) TC2ICR_reg))
#define TC2ICR_inst_adr                                                              "0x004B"
#define TC2ICR_inst                                                                  0x004B
#define TC2ICR_TC2IE_shift                                                           (31)
#define TC2ICR_TC2IE_mask                                                            (0x80000000)
#define TC2ICR_TC2IE(data)                                                           (0x80000000&((data)<<31))
#define TC2ICR_TC2IE_src(data)                                                       ((0x80000000&(data))>>31)
#define TC2ICR_get_TC2IE(data)                                                       ((0x80000000&(data))>>31)


#define CLK90K_CTRL                                                                  0x1801B538
#define CLK90K_CTRL_reg_addr                                                         "0x1801B538"
#define CLK90K_CTRL_reg                                                              0x1801B538
#define set_CLK90K_CTRL_reg(data)   (*((volatile unsigned int*) CLK90K_CTRL_reg)=data)
#define get_CLK90K_CTRL_reg   (*((volatile unsigned int*) CLK90K_CTRL_reg))
#define CLK90K_CTRL_inst_adr                                                         "0x004E"
#define CLK90K_CTRL_inst                                                             0x004E
#define CLK90K_CTRL_EN_shift                                                         (0)
#define CLK90K_CTRL_EN_mask                                                          (0x00000001)
#define CLK90K_CTRL_EN(data)                                                         (0x00000001&((data)<<0))
#define CLK90K_CTRL_EN_src(data)                                                     ((0x00000001&(data))>>0)
#define CLK90K_CTRL_get_EN(data)                                                     ((0x00000001&(data))>>0)


#define SCPU_CLK27M_90K                                                              0x1801B53C
#define SCPU_CLK27M_90K_reg_addr                                                     "0x1801B53C"
#define SCPU_CLK27M_90K_reg                                                          0x1801B53C
#define set_SCPU_CLK27M_90K_reg(data)   (*((volatile unsigned int*) SCPU_CLK27M_90K_reg)=data)
#define get_SCPU_CLK27M_90K_reg   (*((volatile unsigned int*) SCPU_CLK27M_90K_reg))
#define SCPU_CLK27M_90K_inst_adr                                                     "0x004F"
#define SCPU_CLK27M_90K_inst                                                         0x004F
#define SCPU_CLK27M_90K_CNT_shift                                                    (0)
#define SCPU_CLK27M_90K_CNT_mask                                                     (0x000001FF)
#define SCPU_CLK27M_90K_CNT(data)                                                    (0x000001FF&((data)<<0))
#define SCPU_CLK27M_90K_CNT_src(data)                                                ((0x000001FF&(data))>>0)
#define SCPU_CLK27M_90K_get_CNT(data)                                                ((0x000001FF&(data))>>0)


#define SCPU_CLK90K_LO                                                               0x1801B540
#define SCPU_CLK90K_LO_reg_addr                                                      "0x1801B540"
#define SCPU_CLK90K_LO_reg                                                           0x1801B540
#define set_SCPU_CLK90K_LO_reg(data)   (*((volatile unsigned int*) SCPU_CLK90K_LO_reg)=data)
#define get_SCPU_CLK90K_LO_reg   (*((volatile unsigned int*) SCPU_CLK90K_LO_reg))
#define SCPU_CLK90K_LO_inst_adr                                                      "0x0050"
#define SCPU_CLK90K_LO_inst                                                          0x0050
#define SCPU_CLK90K_LO_VAL_shift                                                     (0)
#define SCPU_CLK90K_LO_VAL_mask                                                      (0xFFFFFFFF)
#define SCPU_CLK90K_LO_VAL(data)                                                     (0xFFFFFFFF&((data)<<0))
#define SCPU_CLK90K_LO_VAL_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define SCPU_CLK90K_LO_get_VAL(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define SCPU_CLK90K_HI                                                               0x1801B544
#define SCPU_CLK90K_HI_reg_addr                                                      "0x1801B544"
#define SCPU_CLK90K_HI_reg                                                           0x1801B544
#define set_SCPU_CLK90K_HI_reg(data)   (*((volatile unsigned int*) SCPU_CLK90K_HI_reg)=data)
#define get_SCPU_CLK90K_HI_reg   (*((volatile unsigned int*) SCPU_CLK90K_HI_reg))
#define SCPU_CLK90K_HI_inst_adr                                                      "0x0051"
#define SCPU_CLK90K_HI_inst                                                          0x0051
#define SCPU_CLK90K_HI_VAL_shift                                                     (0)
#define SCPU_CLK90K_HI_VAL_mask                                                      (0x0000FFFF)
#define SCPU_CLK90K_HI_VAL(data)                                                     (0x0000FFFF&((data)<<0))
#define SCPU_CLK90K_HI_VAL_src(data)                                                 ((0x0000FFFF&(data))>>0)
#define SCPU_CLK90K_HI_get_VAL(data)                                                 ((0x0000FFFF&(data))>>0)


#define ACPU_CLK27M_90K                                                              0x1801B548
#define ACPU_CLK27M_90K_reg_addr                                                     "0x1801B548"
#define ACPU_CLK27M_90K_reg                                                          0x1801B548
#define set_ACPU_CLK27M_90K_reg(data)   (*((volatile unsigned int*) ACPU_CLK27M_90K_reg)=data)
#define get_ACPU_CLK27M_90K_reg   (*((volatile unsigned int*) ACPU_CLK27M_90K_reg))
#define ACPU_CLK27M_90K_inst_adr                                                     "0x0052"
#define ACPU_CLK27M_90K_inst                                                         0x0052
#define ACPU_CLK27M_90K_CNT_shift                                                    (0)
#define ACPU_CLK27M_90K_CNT_mask                                                     (0x000001FF)
#define ACPU_CLK27M_90K_CNT(data)                                                    (0x000001FF&((data)<<0))
#define ACPU_CLK27M_90K_CNT_src(data)                                                ((0x000001FF&(data))>>0)
#define ACPU_CLK27M_90K_get_CNT(data)                                                ((0x000001FF&(data))>>0)


#define ACPU_CLK90K_LO                                                               0x1801B54C
#define ACPU_CLK90K_LO_reg_addr                                                      "0x1801B54C"
#define ACPU_CLK90K_LO_reg                                                           0x1801B54C
#define set_ACPU_CLK90K_LO_reg(data)   (*((volatile unsigned int*) ACPU_CLK90K_LO_reg)=data)
#define get_ACPU_CLK90K_LO_reg   (*((volatile unsigned int*) ACPU_CLK90K_LO_reg))
#define ACPU_CLK90K_LO_inst_adr                                                      "0x0053"
#define ACPU_CLK90K_LO_inst                                                          0x0053
#define ACPU_CLK90K_LO_VAL_shift                                                     (0)
#define ACPU_CLK90K_LO_VAL_mask                                                      (0xFFFFFFFF)
#define ACPU_CLK90K_LO_VAL(data)                                                     (0xFFFFFFFF&((data)<<0))
#define ACPU_CLK90K_LO_VAL_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define ACPU_CLK90K_LO_get_VAL(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define ACPU_CLK90K_HI                                                               0x1801B550
#define ACPU_CLK90K_HI_reg_addr                                                      "0x1801B550"
#define ACPU_CLK90K_HI_reg                                                           0x1801B550
#define set_ACPU_CLK90K_HI_reg(data)   (*((volatile unsigned int*) ACPU_CLK90K_HI_reg)=data)
#define get_ACPU_CLK90K_HI_reg   (*((volatile unsigned int*) ACPU_CLK90K_HI_reg))
#define ACPU_CLK90K_HI_inst_adr                                                      "0x0054"
#define ACPU_CLK90K_HI_inst                                                          0x0054
#define ACPU_CLK90K_HI_VAL_shift                                                     (0)
#define ACPU_CLK90K_HI_VAL_mask                                                      (0x0000FFFF)
#define ACPU_CLK90K_HI_VAL(data)                                                     (0x0000FFFF&((data)<<0))
#define ACPU_CLK90K_HI_VAL_src(data)                                                 ((0x0000FFFF&(data))>>0)
#define ACPU_CLK90K_HI_get_VAL(data)                                                 ((0x0000FFFF&(data))>>0)


#define PCR_CLK90K_CTRL                                                              0x1801B570
#define PCR_CLK90K_CTRL_reg_addr                                                     "0x1801B570"
#define PCR_CLK90K_CTRL_reg                                                          0x1801B570
#define set_PCR_CLK90K_CTRL_reg(data)   (*((volatile unsigned int*) PCR_CLK90K_CTRL_reg)=data)
#define get_PCR_CLK90K_CTRL_reg   (*((volatile unsigned int*) PCR_CLK90K_CTRL_reg))
#define PCR_CLK90K_CTRL_inst_adr                                                     "0x005C"
#define PCR_CLK90K_CTRL_inst                                                         0x005C
#define PCR_CLK90K_CTRL_EN_shift                                                     (0)
#define PCR_CLK90K_CTRL_EN_mask                                                      (0x00000001)
#define PCR_CLK90K_CTRL_EN(data)                                                     (0x00000001&((data)<<0))
#define PCR_CLK90K_CTRL_EN_src(data)                                                 ((0x00000001&(data))>>0)
#define PCR_CLK90K_CTRL_get_EN(data)                                                 ((0x00000001&(data))>>0)


#define PCR_SCPU_CLK27M_90K                                                          0x1801B574
#define PCR_SCPU_CLK27M_90K_reg_addr                                                 "0x1801B574"
#define PCR_SCPU_CLK27M_90K_reg                                                      0x1801B574
#define set_PCR_SCPU_CLK27M_90K_reg(data)   (*((volatile unsigned int*) PCR_SCPU_CLK27M_90K_reg)=data)
#define get_PCR_SCPU_CLK27M_90K_reg   (*((volatile unsigned int*) PCR_SCPU_CLK27M_90K_reg))
#define PCR_SCPU_CLK27M_90K_inst_adr                                                 "0x005D"
#define PCR_SCPU_CLK27M_90K_inst                                                     0x005D
#define PCR_SCPU_CLK27M_90K_CNT_shift                                                (0)
#define PCR_SCPU_CLK27M_90K_CNT_mask                                                 (0x000001FF)
#define PCR_SCPU_CLK27M_90K_CNT(data)                                                (0x000001FF&((data)<<0))
#define PCR_SCPU_CLK27M_90K_CNT_src(data)                                            ((0x000001FF&(data))>>0)
#define PCR_SCPU_CLK27M_90K_get_CNT(data)                                            ((0x000001FF&(data))>>0)


#define PCR_SCPU_CLK90K_LO                                                           0x1801B578
#define PCR_SCPU_CLK90K_LO_reg_addr                                                  "0x1801B578"
#define PCR_SCPU_CLK90K_LO_reg                                                       0x1801B578
#define set_PCR_SCPU_CLK90K_LO_reg(data)   (*((volatile unsigned int*) PCR_SCPU_CLK90K_LO_reg)=data)
#define get_PCR_SCPU_CLK90K_LO_reg   (*((volatile unsigned int*) PCR_SCPU_CLK90K_LO_reg))
#define PCR_SCPU_CLK90K_LO_inst_adr                                                  "0x005E"
#define PCR_SCPU_CLK90K_LO_inst                                                      0x005E
#define PCR_SCPU_CLK90K_LO_VAL_shift                                                 (0)
#define PCR_SCPU_CLK90K_LO_VAL_mask                                                  (0xFFFFFFFF)
#define PCR_SCPU_CLK90K_LO_VAL(data)                                                 (0xFFFFFFFF&((data)<<0))
#define PCR_SCPU_CLK90K_LO_VAL_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define PCR_SCPU_CLK90K_LO_get_VAL(data)                                             ((0xFFFFFFFF&(data))>>0)


#define PCR_SCPU_CLK90K_HI                                                           0x1801B57C
#define PCR_SCPU_CLK90K_HI_reg_addr                                                  "0x1801B57C"
#define PCR_SCPU_CLK90K_HI_reg                                                       0x1801B57C
#define set_PCR_SCPU_CLK90K_HI_reg(data)   (*((volatile unsigned int*) PCR_SCPU_CLK90K_HI_reg)=data)
#define get_PCR_SCPU_CLK90K_HI_reg   (*((volatile unsigned int*) PCR_SCPU_CLK90K_HI_reg))
#define PCR_SCPU_CLK90K_HI_inst_adr                                                  "0x005F"
#define PCR_SCPU_CLK90K_HI_inst                                                      0x005F
#define PCR_SCPU_CLK90K_HI_VAL_shift                                                 (0)
#define PCR_SCPU_CLK90K_HI_VAL_mask                                                  (0x0000FFFF)
#define PCR_SCPU_CLK90K_HI_VAL(data)                                                 (0x0000FFFF&((data)<<0))
#define PCR_SCPU_CLK90K_HI_VAL_src(data)                                             ((0x0000FFFF&(data))>>0)
#define PCR_SCPU_CLK90K_HI_get_VAL(data)                                             ((0x0000FFFF&(data))>>0)


#define PCR_ACPU_CLK27M_90K                                                          0x1801B580
#define PCR_ACPU_CLK27M_90K_reg_addr                                                 "0x1801B580"
#define PCR_ACPU_CLK27M_90K_reg                                                      0x1801B580
#define set_PCR_ACPU_CLK27M_90K_reg(data)   (*((volatile unsigned int*) PCR_ACPU_CLK27M_90K_reg)=data)
#define get_PCR_ACPU_CLK27M_90K_reg   (*((volatile unsigned int*) PCR_ACPU_CLK27M_90K_reg))
#define PCR_ACPU_CLK27M_90K_inst_adr                                                 "0x0060"
#define PCR_ACPU_CLK27M_90K_inst                                                     0x0060
#define PCR_ACPU_CLK27M_90K_CNT_shift                                                (0)
#define PCR_ACPU_CLK27M_90K_CNT_mask                                                 (0x000001FF)
#define PCR_ACPU_CLK27M_90K_CNT(data)                                                (0x000001FF&((data)<<0))
#define PCR_ACPU_CLK27M_90K_CNT_src(data)                                            ((0x000001FF&(data))>>0)
#define PCR_ACPU_CLK27M_90K_get_CNT(data)                                            ((0x000001FF&(data))>>0)


#define PCR_ACPU_CLK90K_LO                                                           0x1801B584
#define PCR_ACPU_CLK90K_LO_reg_addr                                                  "0x1801B584"
#define PCR_ACPU_CLK90K_LO_reg                                                       0x1801B584
#define set_PCR_ACPU_CLK90K_LO_reg(data)   (*((volatile unsigned int*) PCR_ACPU_CLK90K_LO_reg)=data)
#define get_PCR_ACPU_CLK90K_LO_reg   (*((volatile unsigned int*) PCR_ACPU_CLK90K_LO_reg))
#define PCR_ACPU_CLK90K_LO_inst_adr                                                  "0x0061"
#define PCR_ACPU_CLK90K_LO_inst                                                      0x0061
#define PCR_ACPU_CLK90K_LO_VAL_shift                                                 (0)
#define PCR_ACPU_CLK90K_LO_VAL_mask                                                  (0xFFFFFFFF)
#define PCR_ACPU_CLK90K_LO_VAL(data)                                                 (0xFFFFFFFF&((data)<<0))
#define PCR_ACPU_CLK90K_LO_VAL_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define PCR_ACPU_CLK90K_LO_get_VAL(data)                                             ((0xFFFFFFFF&(data))>>0)


#define PCR_ACPU_CLK90K_HI                                                           0x1801B588
#define PCR_ACPU_CLK90K_HI_reg_addr                                                  "0x1801B588"
#define PCR_ACPU_CLK90K_HI_reg                                                       0x1801B588
#define set_PCR_ACPU_CLK90K_HI_reg(data)   (*((volatile unsigned int*) PCR_ACPU_CLK90K_HI_reg)=data)
#define get_PCR_ACPU_CLK90K_HI_reg   (*((volatile unsigned int*) PCR_ACPU_CLK90K_HI_reg))
#define PCR_ACPU_CLK90K_HI_inst_adr                                                  "0x0062"
#define PCR_ACPU_CLK90K_HI_inst                                                      0x0062
#define PCR_ACPU_CLK90K_HI_VAL_shift                                                 (0)
#define PCR_ACPU_CLK90K_HI_VAL_mask                                                  (0x0000FFFF)
#define PCR_ACPU_CLK90K_HI_VAL(data)                                                 (0x0000FFFF&((data)<<0))
#define PCR_ACPU_CLK90K_HI_VAL_src(data)                                             ((0x0000FFFF&(data))>>0)
#define PCR_ACPU_CLK90K_HI_get_VAL(data)                                             ((0x0000FFFF&(data))>>0)


#define TCWCR                                                                        0x1801B5B0
#define TCWCR_reg_addr                                                               "0x1801B5B0"
#define TCWCR_reg                                                                    0x1801B5B0
#define set_TCWCR_reg(data)   (*((volatile unsigned int*) TCWCR_reg)=data)
#define get_TCWCR_reg   (*((volatile unsigned int*) TCWCR_reg))
#define TCWCR_inst_adr                                                               "0x006C"
#define TCWCR_inst                                                                   0x006C
#define TCWCR_WD_INT_EN_shift                                                        (31)
#define TCWCR_WD_INT_EN_mask                                                         (0x80000000)
#define TCWCR_WD_INT_EN(data)                                                        (0x80000000&((data)<<31))
#define TCWCR_WD_INT_EN_src(data)                                                    ((0x80000000&(data))>>31)
#define TCWCR_get_WD_INT_EN(data)                                                    ((0x80000000&(data))>>31)
#define TCWCR_NMIC_shift                                                             (12)
#define TCWCR_NMIC_mask                                                              (0x0000F000)
#define TCWCR_NMIC(data)                                                             (0x0000F000&((data)<<12))
#define TCWCR_NMIC_src(data)                                                         ((0x0000F000&(data))>>12)
#define TCWCR_get_NMIC(data)                                                         ((0x0000F000&(data))>>12)
#define TCWCR_WDC_shift                                                              (8)
#define TCWCR_WDC_mask                                                               (0x00000F00)
#define TCWCR_WDC(data)                                                              (0x00000F00&((data)<<8))
#define TCWCR_WDC_src(data)                                                          ((0x00000F00&(data))>>8)
#define TCWCR_get_WDC(data)                                                          ((0x00000F00&(data))>>8)
#define TCWCR_WDEN_shift                                                             (0)
#define TCWCR_WDEN_mask                                                              (0x000000FF)
#define TCWCR_WDEN(data)                                                             (0x000000FF&((data)<<0))
#define TCWCR_WDEN_src(data)                                                         ((0x000000FF&(data))>>0)
#define TCWCR_get_WDEN(data)                                                         ((0x000000FF&(data))>>0)


#define TCWTR                                                                        0x1801B5B4
#define TCWTR_reg_addr                                                               "0x1801B5B4"
#define TCWTR_reg                                                                    0x1801B5B4
#define set_TCWTR_reg(data)   (*((volatile unsigned int*) TCWTR_reg)=data)
#define get_TCWTR_reg   (*((volatile unsigned int*) TCWTR_reg))
#define TCWTR_inst_adr                                                               "0x006D"
#define TCWTR_inst                                                                   0x006D
#define TCWTR_WDCLR_shift                                                            (0)
#define TCWTR_WDCLR_mask                                                             (0x00000001)
#define TCWTR_WDCLR(data)                                                            (0x00000001&((data)<<0))
#define TCWTR_WDCLR_src(data)                                                        ((0x00000001&(data))>>0)
#define TCWTR_get_WDCLR(data)                                                        ((0x00000001&(data))>>0)


#define TCWNMI                                                                       0x1801B5B8
#define TCWNMI_reg_addr                                                              "0x1801B5B8"
#define TCWNMI_reg                                                                   0x1801B5B8
#define set_TCWNMI_reg(data)   (*((volatile unsigned int*) TCWNMI_reg)=data)
#define get_TCWNMI_reg   (*((volatile unsigned int*) TCWNMI_reg))
#define TCWNMI_inst_adr                                                              "0x006E"
#define TCWNMI_inst                                                                  0x006E
#define TCWNMI_SEL_shift                                                             (0)
#define TCWNMI_SEL_mask                                                              (0xFFFFFFFF)
#define TCWNMI_SEL(data)                                                             (0xFFFFFFFF&((data)<<0))
#define TCWNMI_SEL_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define TCWNMI_get_SEL(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define TCWOV                                                                        0x1801B5BC
#define TCWOV_reg_addr                                                               "0x1801B5BC"
#define TCWOV_reg                                                                    0x1801B5BC
#define set_TCWOV_reg(data)   (*((volatile unsigned int*) TCWOV_reg)=data)
#define get_TCWOV_reg   (*((volatile unsigned int*) TCWOV_reg))
#define TCWOV_inst_adr                                                               "0x006F"
#define TCWOV_inst                                                                   0x006F
#define TCWOV_SEL_shift                                                              (0)
#define TCWOV_SEL_mask                                                               (0xFFFFFFFF)
#define TCWOV_SEL(data)                                                              (0xFFFFFFFF&((data)<<0))
#define TCWOV_SEL_src(data)                                                          ((0xFFFFFFFF&(data))>>0)
#define TCWOV_get_SEL(data)                                                          ((0xFFFFFFFF&(data))>>0)


#define TCWCR_SWC                                                                    0x1801B5C0
#define TCWCR_SWC_reg_addr                                                           "0x1801B5C0"
#define TCWCR_SWC_reg                                                                0x1801B5C0
#define set_TCWCR_SWC_reg(data)   (*((volatile unsigned int*) TCWCR_SWC_reg)=data)
#define get_TCWCR_SWC_reg   (*((volatile unsigned int*) TCWCR_SWC_reg))
#define TCWCR_SWC_inst_adr                                                           "0x0070"
#define TCWCR_SWC_inst                                                               0x0070
#define TCWCR_SWC_WD_INT_EN_shift                                                    (31)
#define TCWCR_SWC_WD_INT_EN_mask                                                     (0x80000000)
#define TCWCR_SWC_WD_INT_EN(data)                                                    (0x80000000&((data)<<31))
#define TCWCR_SWC_WD_INT_EN_src(data)                                                ((0x80000000&(data))>>31)
#define TCWCR_SWC_get_WD_INT_EN(data)                                                ((0x80000000&(data))>>31)
#define TCWCR_SWC_NMIC_shift                                                         (12)
#define TCWCR_SWC_NMIC_mask                                                          (0x0000F000)
#define TCWCR_SWC_NMIC(data)                                                         (0x0000F000&((data)<<12))
#define TCWCR_SWC_NMIC_src(data)                                                     ((0x0000F000&(data))>>12)
#define TCWCR_SWC_get_NMIC(data)                                                     ((0x0000F000&(data))>>12)
#define TCWCR_SWC_WDC_shift                                                          (8)
#define TCWCR_SWC_WDC_mask                                                           (0x00000F00)
#define TCWCR_SWC_WDC(data)                                                          (0x00000F00&((data)<<8))
#define TCWCR_SWC_WDC_src(data)                                                      ((0x00000F00&(data))>>8)
#define TCWCR_SWC_get_WDC(data)                                                      ((0x00000F00&(data))>>8)
#define TCWCR_SWC_WDEN_shift                                                         (0)
#define TCWCR_SWC_WDEN_mask                                                          (0x000000FF)
#define TCWCR_SWC_WDEN(data)                                                         (0x000000FF&((data)<<0))
#define TCWCR_SWC_WDEN_src(data)                                                     ((0x000000FF&(data))>>0)
#define TCWCR_SWC_get_WDEN(data)                                                     ((0x000000FF&(data))>>0)


#define TCWTR_SWC                                                                    0x1801B5C4
#define TCWTR_SWC_reg_addr                                                           "0x1801B5C4"
#define TCWTR_SWC_reg                                                                0x1801B5C4
#define set_TCWTR_SWC_reg(data)   (*((volatile unsigned int*) TCWTR_SWC_reg)=data)
#define get_TCWTR_SWC_reg   (*((volatile unsigned int*) TCWTR_SWC_reg))
#define TCWTR_SWC_inst_adr                                                           "0x0071"
#define TCWTR_SWC_inst                                                               0x0071
#define TCWTR_SWC_WDCLR_shift                                                        (0)
#define TCWTR_SWC_WDCLR_mask                                                         (0x00000001)
#define TCWTR_SWC_WDCLR(data)                                                        (0x00000001&((data)<<0))
#define TCWTR_SWC_WDCLR_src(data)                                                    ((0x00000001&(data))>>0)
#define TCWTR_SWC_get_WDCLR(data)                                                    ((0x00000001&(data))>>0)


#define TCWNMI_SWC                                                                   0x1801B5C8
#define TCWNMI_SWC_reg_addr                                                          "0x1801B5C8"
#define TCWNMI_SWC_reg                                                               0x1801B5C8
#define set_TCWNMI_SWC_reg(data)   (*((volatile unsigned int*) TCWNMI_SWC_reg)=data)
#define get_TCWNMI_SWC_reg   (*((volatile unsigned int*) TCWNMI_SWC_reg))
#define TCWNMI_SWC_inst_adr                                                          "0x0072"
#define TCWNMI_SWC_inst                                                              0x0072
#define TCWNMI_SWC_SEL_shift                                                         (0)
#define TCWNMI_SWC_SEL_mask                                                          (0xFFFFFFFF)
#define TCWNMI_SWC_SEL(data)                                                         (0xFFFFFFFF&((data)<<0))
#define TCWNMI_SWC_SEL_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define TCWNMI_SWC_get_SEL(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define TCWOV_SWC                                                                    0x1801B5CC
#define TCWOV_SWC_reg_addr                                                           "0x1801B5CC"
#define TCWOV_SWC_reg                                                                0x1801B5CC
#define set_TCWOV_SWC_reg(data)   (*((volatile unsigned int*) TCWOV_SWC_reg)=data)
#define get_TCWOV_SWC_reg   (*((volatile unsigned int*) TCWOV_SWC_reg))
#define TCWOV_SWC_inst_adr                                                           "0x0073"
#define TCWOV_SWC_inst                                                               0x0073
#define TCWOV_SWC_SEL_shift                                                          (0)
#define TCWOV_SWC_SEL_mask                                                           (0xFFFFFFFF)
#define TCWOV_SWC_SEL(data)                                                          (0xFFFFFFFF&((data)<<0))
#define TCWOV_SWC_SEL_src(data)                                                      ((0xFFFFFFFF&(data))>>0)
#define TCWOV_SWC_get_SEL(data)                                                      ((0xFFFFFFFF&(data))>>0)


#define RTCSEC                                                                       0x1801B600
#define RTCSEC_reg_addr                                                              "0xB801B600"
#define RTCSEC_reg                                                                   0xB801B600
#define set_RTCSEC_reg(data)   (*((volatile unsigned int*) RTCSEC_reg)=data)
#define get_RTCSEC_reg   (*((volatile unsigned int*) RTCSEC_reg))
#define RTCSEC_inst_adr                                                              "0x0080"
#define RTCSEC_inst                                                                  0x0080
#define RTCSEC_RTCSEC_shift                                                          (0)
#define RTCSEC_RTCSEC_mask                                                           (0x0000007F)
#define RTCSEC_RTCSEC(data)                                                          (0x0000007F&((data)<<0))
#define RTCSEC_RTCSEC_src(data)                                                      ((0x0000007F&(data))>>0)
#define RTCSEC_get_RTCSEC(data)                                                      ((0x0000007F&(data))>>0)


#define RTCMIN                                                                       0x1801B604
#define RTCMIN_reg_addr                                                              "0xB801B604"
#define RTCMIN_reg                                                                   0xB801B604
#define set_RTCMIN_reg(data)   (*((volatile unsigned int*) RTCMIN_reg)=data)
#define get_RTCMIN_reg   (*((volatile unsigned int*) RTCMIN_reg))
#define RTCMIN_inst_adr                                                              "0x0081"
#define RTCMIN_inst                                                                  0x0081
#define RTCMIN_RTCMIN_shift                                                          (0)
#define RTCMIN_RTCMIN_mask                                                           (0x0000003F)
#define RTCMIN_RTCMIN(data)                                                          (0x0000003F&((data)<<0))
#define RTCMIN_RTCMIN_src(data)                                                      ((0x0000003F&(data))>>0)
#define RTCMIN_get_RTCMIN(data)                                                      ((0x0000003F&(data))>>0)


#define RTCHR                                                                        0x1801B608
#define RTCHR_reg_addr                                                               "0xB801B608"
#define RTCHR_reg                                                                    0xB801B608
#define set_RTCHR_reg(data)   (*((volatile unsigned int*) RTCHR_reg)=data)
#define get_RTCHR_reg   (*((volatile unsigned int*) RTCHR_reg))
#define RTCHR_inst_adr                                                               "0x0082"
#define RTCHR_inst                                                                   0x0082
#define RTCHR_RTCHR_shift                                                            (0)
#define RTCHR_RTCHR_mask                                                             (0x0000001F)
#define RTCHR_RTCHR(data)                                                            (0x0000001F&((data)<<0))
#define RTCHR_RTCHR_src(data)                                                        ((0x0000001F&(data))>>0)
#define RTCHR_get_RTCHR(data)                                                        ((0x0000001F&(data))>>0)


#define RTCDATE1                                                                     0x1801B60C
#define RTCDATE1_reg_addr                                                            "0xB801B60C"
#define RTCDATE1_reg                                                                 0xB801B60C
#define set_RTCDATE1_reg(data)   (*((volatile unsigned int*) RTCDATE1_reg)=data)
#define get_RTCDATE1_reg   (*((volatile unsigned int*) RTCDATE1_reg))
#define RTCDATE1_inst_adr                                                            "0x0083"
#define RTCDATE1_inst                                                                0x0083
#define RTCDATE1_RTCDATE1_shift                                                      (0)
#define RTCDATE1_RTCDATE1_mask                                                       (0x000000FF)
#define RTCDATE1_RTCDATE1(data)                                                      (0x000000FF&((data)<<0))
#define RTCDATE1_RTCDATE1_src(data)                                                  ((0x000000FF&(data))>>0)
#define RTCDATE1_get_RTCDATE1(data)                                                  ((0x000000FF&(data))>>0)


#define RTCDATE2                                                                     0x1801B610
#define RTCDATE2_reg_addr                                                            "0xB801B610"
#define RTCDATE2_reg                                                                 0xB801B610
#define set_RTCDATE2_reg(data)   (*((volatile unsigned int*) RTCDATE2_reg)=data)
#define get_RTCDATE2_reg   (*((volatile unsigned int*) RTCDATE2_reg))
#define RTCDATE2_inst_adr                                                            "0x0084"
#define RTCDATE2_inst                                                                0x0084
#define RTCDATE2_RTCDATE2_shift                                                      (0)
#define RTCDATE2_RTCDATE2_mask                                                       (0x0000007F)
#define RTCDATE2_RTCDATE2(data)                                                      (0x0000007F&((data)<<0))
#define RTCDATE2_RTCDATE2_src(data)                                                  ((0x0000007F&(data))>>0)
#define RTCDATE2_get_RTCDATE2(data)                                                  ((0x0000007F&(data))>>0)


#define ALMMIN                                                                       0x1801B614
#define ALMMIN_reg_addr                                                              "0xB801B614"
#define ALMMIN_reg                                                                   0xB801B614
#define set_ALMMIN_reg(data)   (*((volatile unsigned int*) ALMMIN_reg)=data)
#define get_ALMMIN_reg   (*((volatile unsigned int*) ALMMIN_reg))
#define ALMMIN_inst_adr                                                              "0x0085"
#define ALMMIN_inst                                                                  0x0085
#define ALMMIN_ALMMIN_shift                                                          (0)
#define ALMMIN_ALMMIN_mask                                                           (0x0000003F)
#define ALMMIN_ALMMIN(data)                                                          (0x0000003F&((data)<<0))
#define ALMMIN_ALMMIN_src(data)                                                      ((0x0000003F&(data))>>0)
#define ALMMIN_get_ALMMIN(data)                                                      ((0x0000003F&(data))>>0)


#define ALMHR                                                                        0x1801B618
#define ALMHR_reg_addr                                                               "0xB801B618"
#define ALMHR_reg                                                                    0xB801B618
#define set_ALMHR_reg(data)   (*((volatile unsigned int*) ALMHR_reg)=data)
#define get_ALMHR_reg   (*((volatile unsigned int*) ALMHR_reg))
#define ALMHR_inst_adr                                                               "0x0086"
#define ALMHR_inst                                                                   0x0086
#define ALMHR_ALMHR_shift                                                            (0)
#define ALMHR_ALMHR_mask                                                             (0x0000001F)
#define ALMHR_ALMHR(data)                                                            (0x0000001F&((data)<<0))
#define ALMHR_ALMHR_src(data)                                                        ((0x0000001F&(data))>>0)
#define ALMHR_get_ALMHR(data)                                                        ((0x0000001F&(data))>>0)


#define ALMDATE1                                                                     0x1801B61C
#define ALMDATE1_reg_addr                                                            "0xB801B61C"
#define ALMDATE1_reg                                                                 0xB801B61C
#define set_ALMDATE1_reg(data)   (*((volatile unsigned int*) ALMDATE1_reg)=data)
#define get_ALMDATE1_reg   (*((volatile unsigned int*) ALMDATE1_reg))
#define ALMDATE1_inst_adr                                                            "0x0087"
#define ALMDATE1_inst                                                                0x0087
#define ALMDATE1_ALMDATE1_shift                                                      (0)
#define ALMDATE1_ALMDATE1_mask                                                       (0x000000FF)
#define ALMDATE1_ALMDATE1(data)                                                      (0x000000FF&((data)<<0))
#define ALMDATE1_ALMDATE1_src(data)                                                  ((0x000000FF&(data))>>0)
#define ALMDATE1_get_ALMDATE1(data)                                                  ((0x000000FF&(data))>>0)


#define ALMDATE2                                                                     0x1801B620
#define ALMDATE2_reg_addr                                                            "0xB801B620"
#define ALMDATE2_reg                                                                 0xB801B620
#define set_ALMDATE2_reg(data)   (*((volatile unsigned int*) ALMDATE2_reg)=data)
#define get_ALMDATE2_reg   (*((volatile unsigned int*) ALMDATE2_reg))
#define ALMDATE2_inst_adr                                                            "0x0088"
#define ALMDATE2_inst                                                                0x0088
#define ALMDATE2_ALMDATE2_shift                                                      (0)
#define ALMDATE2_ALMDATE2_mask                                                       (0x0000007F)
#define ALMDATE2_ALMDATE2(data)                                                      (0x0000007F&((data)<<0))
#define ALMDATE2_ALMDATE2_src(data)                                                  ((0x0000007F&(data))>>0)
#define ALMDATE2_get_ALMDATE2(data)                                                  ((0x0000007F&(data))>>0)


#define RTCSTOP                                                                      0x1801B624
#define RTCSTOP_reg_addr                                                             "0xB801B624"
#define RTCSTOP_reg                                                                  0xB801B624
#define set_RTCSTOP_reg(data)   (*((volatile unsigned int*) RTCSTOP_reg)=data)
#define get_RTCSTOP_reg   (*((volatile unsigned int*) RTCSTOP_reg))
#define RTCSTOP_inst_adr                                                             "0x0089"
#define RTCSTOP_inst                                                                 0x0089
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


#define RTCACR                                                                       0x1801B628
#define RTCACR_reg_addr                                                              "0xB801B628"
#define RTCACR_reg                                                                   0xB801B628
#define set_RTCACR_reg(data)   (*((volatile unsigned int*) RTCACR_reg)=data)
#define get_RTCACR_reg   (*((volatile unsigned int*) RTCACR_reg))
#define RTCACR_inst_adr                                                              "0x008A"
#define RTCACR_inst                                                                  0x008A
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


#define RTCEN                                                                        0x1801B62C
#define RTCEN_reg_addr                                                               "0xB801B62C"
#define RTCEN_reg                                                                    0xB801B62C
#define set_RTCEN_reg(data)   (*((volatile unsigned int*) RTCEN_reg)=data)
#define get_RTCEN_reg   (*((volatile unsigned int*) RTCEN_reg))
#define RTCEN_inst_adr                                                               "0x008B"
#define RTCEN_inst                                                                   0x008B
#define RTCEN_RTCEN_shift                                                            (0)
#define RTCEN_RTCEN_mask                                                             (0x000000FF)
#define RTCEN_RTCEN(data)                                                            (0x000000FF&((data)<<0))
#define RTCEN_RTCEN_src(data)                                                        ((0x000000FF&(data))>>0)
#define RTCEN_get_RTCEN(data)                                                        ((0x000000FF&(data))>>0)


#define RTCCR                                                                        0x1801B630
#define RTCCR_reg_addr                                                               "0xB801B630"
#define RTCCR_reg                                                                    0xB801B630
#define set_RTCCR_reg(data)   (*((volatile unsigned int*) RTCCR_reg)=data)
#define get_RTCCR_reg   (*((volatile unsigned int*) RTCCR_reg))
#define RTCCR_inst_adr                                                               "0x008C"
#define RTCCR_inst                                                                   0x008C
#define RTCCR_RTCRST_shift                                                           (6)
#define RTCCR_RTCRST_mask                                                            (0x00000040)
#define RTCCR_RTCRST(data)                                                           (0x00000040&((data)<<6))
#define RTCCR_RTCRST_src(data)                                                       ((0x00000040&(data))>>6)
#define RTCCR_get_RTCRST(data)                                                       ((0x00000040&(data))>>6)
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


#define ST_PAD0                                                                      0x1801BC00
#define ST_PAD0_reg_addr                                                             "0xB801BC00"
#define ST_PAD0_reg                                                                  0xB801BC00
#define set_ST_PAD0_reg(data)   (*((volatile unsigned int*) ST_PAD0_reg)=data)
#define get_ST_PAD0_reg   (*((volatile unsigned int*) ST_PAD0_reg))
#define ST_PAD0_inst_adr                                                             "0x0000"
#define ST_PAD0_inst                                                                 0x0000
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


#define ST_PAD1                                                                      0x1801BC04
#define ST_PAD1_reg_addr                                                             "0xB801BC04"
#define ST_PAD1_reg                                                                  0xB801BC04
#define set_ST_PAD1_reg(data)   (*((volatile unsigned int*) ST_PAD1_reg)=data)
#define get_ST_PAD1_reg   (*((volatile unsigned int*) ST_PAD1_reg))
#define ST_PAD1_inst_adr                                                             "0x0001"
#define ST_PAD1_inst                                                                 0x0001
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


#define ST_LSADC_CTRL                                                                0x1801BC20
#define ST_LSADC_CTRL_reg_addr                                                       "0xB801BC20"
#define ST_LSADC_CTRL_reg                                                            0xB801BC20
#define set_ST_LSADC_CTRL_reg(data)   (*((volatile unsigned int*) ST_LSADC_CTRL_reg)=data)
#define get_ST_LSADC_CTRL_reg   (*((volatile unsigned int*) ST_LSADC_CTRL_reg))
#define ST_LSADC_CTRL_inst_adr                                                       "0x0008"
#define ST_LSADC_CTRL_inst                                                           0x0008
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


#define ST_LSADC_STATUS                                                              0x1801BC24
#define ST_LSADC_STATUS_reg_addr                                                     "0xB801BC24"
#define ST_LSADC_STATUS_reg                                                          0xB801BC24
#define set_ST_LSADC_STATUS_reg(data)   (*((volatile unsigned int*) ST_LSADC_STATUS_reg)=data)
#define get_ST_LSADC_STATUS_reg   (*((volatile unsigned int*) ST_LSADC_STATUS_reg))
#define ST_LSADC_STATUS_inst_adr                                                     "0x0009"
#define ST_LSADC_STATUS_inst                                                         0x0009
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


#define ST_LSADC_ANALOG_CTRL                                                         0x1801BC28
#define ST_LSADC_ANALOG_CTRL_reg_addr                                                "0xB801BC28"
#define ST_LSADC_ANALOG_CTRL_reg                                                     0xB801BC28
#define set_ST_LSADC_ANALOG_CTRL_reg(data)   (*((volatile unsigned int*) ST_LSADC_ANALOG_CTRL_reg)=data)
#define get_ST_LSADC_ANALOG_CTRL_reg   (*((volatile unsigned int*) ST_LSADC_ANALOG_CTRL_reg))
#define ST_LSADC_ANALOG_CTRL_inst_adr                                                "0x000A"
#define ST_LSADC_ANALOG_CTRL_inst                                                    0x000A
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


#define ST_LSADC_PERI_TOP_DEBUG                                                      0x1801BC2C
#define ST_LSADC_PERI_TOP_DEBUG_reg_addr                                             "0xB801BC2C"
#define ST_LSADC_PERI_TOP_DEBUG_reg                                                  0xB801BC2C
#define set_ST_LSADC_PERI_TOP_DEBUG_reg(data)   (*((volatile unsigned int*) ST_LSADC_PERI_TOP_DEBUG_reg)=data)
#define get_ST_LSADC_PERI_TOP_DEBUG_reg   (*((volatile unsigned int*) ST_LSADC_PERI_TOP_DEBUG_reg))
#define ST_LSADC_PERI_TOP_DEBUG_inst_adr                                             "0x000B"
#define ST_LSADC_PERI_TOP_DEBUG_inst                                                 0x000B
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_shift                           (16)
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_mask                            (0x00070000)
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel(data)                           (0x00070000&((data)<<16))
#define ST_LSADC_PERI_TOP_DEBUG_Lsadc_2_ifd_data_sel_src(data)                       ((0x00070000&(data))>>16)
#define ST_LSADC_PERI_TOP_DEBUG_get_Lsadc_2_ifd_data_sel(data)                       ((0x00070000&(data))>>16)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_enable_shift                            (14)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_enable_mask                             (0x00004000)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_enable(data)                            (0x00004000&((data)<<14))
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_enable_src(data)                        ((0x00004000&(data))>>14)
#define ST_LSADC_PERI_TOP_DEBUG_get_Power_saving_enable(data)                        ((0x00004000&(data))>>14)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_cycle_time_shift                        (11)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_cycle_time_mask                         (0x00003800)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_cycle_time(data)                        (0x00003800&((data)<<11))
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_cycle_time_src(data)                    ((0x00003800&(data))>>11)
#define ST_LSADC_PERI_TOP_DEBUG_get_Power_saving_cycle_time(data)                    ((0x00003800&(data))>>11)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_disable_time_shift                      (8)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_disable_time_mask                       (0x00000700)
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_disable_time(data)                      (0x00000700&((data)<<8))
#define ST_LSADC_PERI_TOP_DEBUG_Power_saving_disable_time_src(data)                  ((0x00000700&(data))>>8)
#define ST_LSADC_PERI_TOP_DEBUG_get_Power_saving_disable_time(data)                  ((0x00000700&(data))>>8)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_shift                                 (0)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_mask                                  (0x000000FF)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug(data)                                 (0x000000FF&((data)<<0))
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_src(data)                             ((0x000000FF&(data))>>0)
#define ST_LSADC_PERI_TOP_DEBUG_get_peri_top_debug(data)                             ((0x000000FF&(data))>>0)


#define LSADC_PAD0_LEVEL_SET0                                                        0x1801BC30
#define LSADC_PAD0_LEVEL_SET0_reg_addr                                               "0xB801BC30"
#define LSADC_PAD0_LEVEL_SET0_reg                                                    0xB801BC30
#define set_LSADC_PAD0_LEVEL_SET0_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET0_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET0_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET0_reg))
#define LSADC_PAD0_LEVEL_SET0_inst_adr                                               "0x000C"
#define LSADC_PAD0_LEVEL_SET0_inst                                                   0x000C
#define LSADC_PAD0_LEVEL_SET0_Level_0_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET0_Level_0_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET0_Level_0_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET0_Level_0_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET0_get_Level_0_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET0_Level_0_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET0_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET0_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET0_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET0_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET0_Block0_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET0_Block0_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET0_Block0_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET0_Block0_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET0_get_Block0_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET0_INT_en0_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET0_INT_en0_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET0_INT_en0(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET0_INT_en0_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET0_get_INT_en0(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET0_INT_pending_bit0_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET0_INT_pending_bit0_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET0_INT_pending_bit0(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET0_INT_pending_bit0_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET0_get_INT_pending_bit0(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD0_LEVEL_SET1                                                        0x1801BC34
#define LSADC_PAD0_LEVEL_SET1_reg_addr                                               "0xB801BC34"
#define LSADC_PAD0_LEVEL_SET1_reg                                                    0xB801BC34
#define set_LSADC_PAD0_LEVEL_SET1_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET1_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET1_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET1_reg))
#define LSADC_PAD0_LEVEL_SET1_inst_adr                                               "0x000D"
#define LSADC_PAD0_LEVEL_SET1_inst                                                   0x000D
#define LSADC_PAD0_LEVEL_SET1_Level_1_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET1_Level_1_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET1_Level_1_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET1_Level_1_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET1_get_Level_1_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET1_Level_0_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET1_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET1_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET1_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET1_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET1_Block1_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET1_Block1_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET1_Block1_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET1_Block1_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET1_get_Block1_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET1_INT_en1_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET1_INT_en1_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET1_INT_en1(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET1_INT_en1_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET1_get_INT_en1(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET1_INT_pending_bit1_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET1_INT_pending_bit1_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET1_INT_pending_bit1(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET1_INT_pending_bit1_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET1_get_INT_pending_bit1(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD0_LEVEL_SET2                                                        0x1801BC38
#define LSADC_PAD0_LEVEL_SET2_reg_addr                                               "0xB801BC38"
#define LSADC_PAD0_LEVEL_SET2_reg                                                    0xB801BC38
#define set_LSADC_PAD0_LEVEL_SET2_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET2_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET2_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET2_reg))
#define LSADC_PAD0_LEVEL_SET2_inst_adr                                               "0x000E"
#define LSADC_PAD0_LEVEL_SET2_inst                                                   0x000E
#define LSADC_PAD0_LEVEL_SET2_Level_2_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET2_Level_2_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET2_Level_2_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET2_Level_2_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET2_get_Level_2_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET2_Level_2_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET2_Level_2_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET2_Level_2_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET2_Level_2_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET2_get_Level_2_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET2_Block2_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET2_Block2_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET2_Block2_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET2_Block2_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET2_get_Block2_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET2_INT_en2_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET2_INT_en2_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET2_INT_en2(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET2_INT_en2_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET2_get_INT_en2(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET2_INT_pending_bit2_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET2_INT_pending_bit2_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET2_INT_pending_bit2(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET2_INT_pending_bit2_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET2_get_INT_pending_bit2(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD0_LEVEL_SET3                                                        0x1801BC3C
#define LSADC_PAD0_LEVEL_SET3_reg_addr                                               "0xB801BC3C"
#define LSADC_PAD0_LEVEL_SET3_reg                                                    0xB801BC3C
#define set_LSADC_PAD0_LEVEL_SET3_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET3_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET3_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET3_reg))
#define LSADC_PAD0_LEVEL_SET3_inst_adr                                               "0x000F"
#define LSADC_PAD0_LEVEL_SET3_inst                                                   0x000F
#define LSADC_PAD0_LEVEL_SET3_Level_3_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET3_Level_3_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET3_Level_3_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET3_Level_3_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET3_get_Level_3_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET3_Level_3_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET3_Level_3_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET3_Level_3_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET3_Level_3_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET3_get_Level_3_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET3_Block3_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET3_Block3_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET3_Block3_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET3_Block3_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET3_get_Block3_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET3_INT_en3_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET3_INT_en3_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET3_INT_en3(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET3_INT_en3_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET3_get_INT_en3(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET3_INT_pending_bit3_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET3_INT_pending_bit3_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET3_INT_pending_bit3(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET3_INT_pending_bit3_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET3_get_INT_pending_bit3(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD0_LEVEL_SET4                                                        0x1801BC40
#define LSADC_PAD0_LEVEL_SET4_reg_addr                                               "0xB801BC40"
#define LSADC_PAD0_LEVEL_SET4_reg                                                    0xB801BC40
#define set_LSADC_PAD0_LEVEL_SET4_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET4_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET4_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET4_reg))
#define LSADC_PAD0_LEVEL_SET4_inst_adr                                               "0x0010"
#define LSADC_PAD0_LEVEL_SET4_inst                                                   0x0010
#define LSADC_PAD0_LEVEL_SET4_Level_4_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET4_Level_4_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET4_Level_4_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET4_Level_4_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET4_get_Level_4_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET4_Level_4_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET4_Level_4_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET4_Level_4_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET4_Level_4_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET4_get_Level_4_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET4_Block4_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET4_Block4_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET4_Block4_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET4_Block4_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET4_get_Block4_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET4_INT_en4_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET4_INT_en4_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET4_INT_en4(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET4_INT_en4_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET4_get_INT_en4(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET4_INT_pending_bit4_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET4_INT_pending_bit4_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET4_INT_pending_bit4(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET4_INT_pending_bit4_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET4_get_INT_pending_bit4(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD0_LEVEL_SET5                                                        0x1801BC44
#define LSADC_PAD0_LEVEL_SET5_reg_addr                                               "0xB801BC44"
#define LSADC_PAD0_LEVEL_SET5_reg                                                    0xB801BC44
#define set_LSADC_PAD0_LEVEL_SET5_reg(data)   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET5_reg)=data)
#define get_LSADC_PAD0_LEVEL_SET5_reg   (*((volatile unsigned int*) LSADC_PAD0_LEVEL_SET5_reg))
#define LSADC_PAD0_LEVEL_SET5_inst_adr                                               "0x0011"
#define LSADC_PAD0_LEVEL_SET5_inst                                                   0x0011
#define LSADC_PAD0_LEVEL_SET5_Level_5_top_bound_shift                                (24)
#define LSADC_PAD0_LEVEL_SET5_Level_5_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD0_LEVEL_SET5_Level_5_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD0_LEVEL_SET5_Level_5_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET5_get_Level_5_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD0_LEVEL_SET5_Level_5_low_bound_shift                                (16)
#define LSADC_PAD0_LEVEL_SET5_Level_5_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD0_LEVEL_SET5_Level_5_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD0_LEVEL_SET5_Level_5_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET5_get_Level_5_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD0_LEVEL_SET5_Block5_en_shift                                        (15)
#define LSADC_PAD0_LEVEL_SET5_Block5_en_mask                                         (0x00008000)
#define LSADC_PAD0_LEVEL_SET5_Block5_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD0_LEVEL_SET5_Block5_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET5_get_Block5_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD0_LEVEL_SET5_INT_en5_shift                                          (1)
#define LSADC_PAD0_LEVEL_SET5_INT_en5_mask                                           (0x00000002)
#define LSADC_PAD0_LEVEL_SET5_INT_en5(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD0_LEVEL_SET5_INT_en5_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET5_get_INT_en5(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD0_LEVEL_SET5_INT_pending_bit5_shift                                 (0)
#define LSADC_PAD0_LEVEL_SET5_INT_pending_bit5_mask                                  (0x00000001)
#define LSADC_PAD0_LEVEL_SET5_INT_pending_bit5(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD0_LEVEL_SET5_INT_pending_bit5_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD0_LEVEL_SET5_get_INT_pending_bit5(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET0                                                        0x1801BC48
#define LSADC_PAD1_LEVEL_SET0_reg_addr                                               "0xB801BC48"
#define LSADC_PAD1_LEVEL_SET0_reg                                                    0xB801BC48
#define set_LSADC_PAD1_LEVEL_SET0_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET0_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET0_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET0_reg))
#define LSADC_PAD1_LEVEL_SET0_inst_adr                                               "0x0012"
#define LSADC_PAD1_LEVEL_SET0_inst                                                   0x0012
#define LSADC_PAD1_LEVEL_SET0_Level_0_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET0_Level_0_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET0_Level_0_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET0_Level_0_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET0_get_Level_0_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET0_Level_0_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET0_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET0_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET0_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET0_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET0_Block0_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET0_Block0_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET0_Block0_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET0_Block0_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET0_get_Block0_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET0_INT_en0_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET0_INT_en0_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET0_INT_en0(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET0_INT_en0_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET0_get_INT_en0(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET0_INT_pending_bit0_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET0_INT_pending_bit0_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET0_INT_pending_bit0(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET0_INT_pending_bit0_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET0_get_INT_pending_bit0(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET1                                                        0x1801BC4C
#define LSADC_PAD1_LEVEL_SET1_reg_addr                                               "0xB801BC4C"
#define LSADC_PAD1_LEVEL_SET1_reg                                                    0xB801BC4C
#define set_LSADC_PAD1_LEVEL_SET1_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET1_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET1_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET1_reg))
#define LSADC_PAD1_LEVEL_SET1_inst_adr                                               "0x0013"
#define LSADC_PAD1_LEVEL_SET1_inst                                                   0x0013
#define LSADC_PAD1_LEVEL_SET1_Level_1_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET1_Level_1_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET1_Level_1_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET1_Level_1_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET1_get_Level_1_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET1_Level_0_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET1_Level_0_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET1_Level_0_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET1_Level_0_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET1_get_Level_0_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET1_Block1_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET1_Block1_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET1_Block1_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET1_Block1_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET1_get_Block1_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET1_INT_en1_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET1_INT_en1_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET1_INT_en1(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET1_INT_en1_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET1_get_INT_en1(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET1_INT_pending_bit1_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET1_INT_pending_bit1_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET1_INT_pending_bit1(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET1_INT_pending_bit1_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET1_get_INT_pending_bit1(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET2                                                        0x1801BC50
#define LSADC_PAD1_LEVEL_SET2_reg_addr                                               "0xB801BC50"
#define LSADC_PAD1_LEVEL_SET2_reg                                                    0xB801BC50
#define set_LSADC_PAD1_LEVEL_SET2_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET2_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET2_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET2_reg))
#define LSADC_PAD1_LEVEL_SET2_inst_adr                                               "0x0014"
#define LSADC_PAD1_LEVEL_SET2_inst                                                   0x0014
#define LSADC_PAD1_LEVEL_SET2_Level_2_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET2_Level_2_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET2_Level_2_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET2_Level_2_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET2_get_Level_2_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET2_Level_2_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET2_Level_2_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET2_Level_2_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET2_Level_2_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET2_get_Level_2_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET2_Block2_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET2_Block2_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET2_Block2_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET2_Block2_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET2_get_Block2_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET2_INT_en2_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET2_INT_en2_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET2_INT_en2(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET2_INT_en2_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET2_get_INT_en2(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET2_INT_pending_bit2_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET2_INT_pending_bit2_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET2_INT_pending_bit2(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET2_INT_pending_bit2_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET2_get_INT_pending_bit2(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET3                                                        0x1801BC54
#define LSADC_PAD1_LEVEL_SET3_reg_addr                                               "0xB801BC54"
#define LSADC_PAD1_LEVEL_SET3_reg                                                    0xB801BC54
#define set_LSADC_PAD1_LEVEL_SET3_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET3_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET3_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET3_reg))
#define LSADC_PAD1_LEVEL_SET3_inst_adr                                               "0x0015"
#define LSADC_PAD1_LEVEL_SET3_inst                                                   0x0015
#define LSADC_PAD1_LEVEL_SET3_Level_3_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET3_Level_3_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET3_Level_3_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET3_Level_3_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET3_get_Level_3_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET3_Level_3_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET3_Level_3_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET3_Level_3_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET3_Level_3_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET3_get_Level_3_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET3_Block3_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET3_Block3_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET3_Block3_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET3_Block3_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET3_get_Block3_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET3_INT_en3_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET3_INT_en3_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET3_INT_en3(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET3_INT_en3_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET3_get_INT_en3(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET3_INT_pending_bit3_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET3_INT_pending_bit3_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET3_INT_pending_bit3(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET3_INT_pending_bit3_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET3_get_INT_pending_bit3(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET4                                                        0x1801BC58
#define LSADC_PAD1_LEVEL_SET4_reg_addr                                               "0xB801BC58"
#define LSADC_PAD1_LEVEL_SET4_reg                                                    0xB801BC58
#define set_LSADC_PAD1_LEVEL_SET4_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET4_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET4_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET4_reg))
#define LSADC_PAD1_LEVEL_SET4_inst_adr                                               "0x0016"
#define LSADC_PAD1_LEVEL_SET4_inst                                                   0x0016
#define LSADC_PAD1_LEVEL_SET4_Level_4_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET4_Level_4_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET4_Level_4_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET4_Level_4_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET4_get_Level_4_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET4_Level_4_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET4_Level_4_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET4_Level_4_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET4_Level_4_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET4_get_Level_4_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET4_Block4_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET4_Block4_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET4_Block4_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET4_Block4_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET4_get_Block4_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET4_INT_en4_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET4_INT_en4_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET4_INT_en4(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET4_INT_en4_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET4_get_INT_en4(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET4_INT_pending_bit4_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET4_INT_pending_bit4_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET4_INT_pending_bit4(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET4_INT_pending_bit4_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET4_get_INT_pending_bit4(data)                             ((0x00000001&(data))>>0)


#define LSADC_PAD1_LEVEL_SET5                                                        0x1801BC5C
#define LSADC_PAD1_LEVEL_SET5_reg_addr                                               "0xB801BC5C"
#define LSADC_PAD1_LEVEL_SET5_reg                                                    0xB801BC5C
#define set_LSADC_PAD1_LEVEL_SET5_reg(data)   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET5_reg)=data)
#define get_LSADC_PAD1_LEVEL_SET5_reg   (*((volatile unsigned int*) LSADC_PAD1_LEVEL_SET5_reg))
#define LSADC_PAD1_LEVEL_SET5_inst_adr                                               "0x0017"
#define LSADC_PAD1_LEVEL_SET5_inst                                                   0x0017
#define LSADC_PAD1_LEVEL_SET5_Level_5_top_bound_shift                                (24)
#define LSADC_PAD1_LEVEL_SET5_Level_5_top_bound_mask                                 (0xFF000000)
#define LSADC_PAD1_LEVEL_SET5_Level_5_top_bound(data)                                (0xFF000000&((data)<<24))
#define LSADC_PAD1_LEVEL_SET5_Level_5_top_bound_src(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET5_get_Level_5_top_bound(data)                            ((0xFF000000&(data))>>24)
#define LSADC_PAD1_LEVEL_SET5_Level_5_low_bound_shift                                (16)
#define LSADC_PAD1_LEVEL_SET5_Level_5_low_bound_mask                                 (0x00FF0000)
#define LSADC_PAD1_LEVEL_SET5_Level_5_low_bound(data)                                (0x00FF0000&((data)<<16))
#define LSADC_PAD1_LEVEL_SET5_Level_5_low_bound_src(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET5_get_Level_5_low_bound(data)                            ((0x00FF0000&(data))>>16)
#define LSADC_PAD1_LEVEL_SET5_Block5_en_shift                                        (15)
#define LSADC_PAD1_LEVEL_SET5_Block5_en_mask                                         (0x00008000)
#define LSADC_PAD1_LEVEL_SET5_Block5_en(data)                                        (0x00008000&((data)<<15))
#define LSADC_PAD1_LEVEL_SET5_Block5_en_src(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET5_get_Block5_en(data)                                    ((0x00008000&(data))>>15)
#define LSADC_PAD1_LEVEL_SET5_INT_en5_shift                                          (1)
#define LSADC_PAD1_LEVEL_SET5_INT_en5_mask                                           (0x00000002)
#define LSADC_PAD1_LEVEL_SET5_INT_en5(data)                                          (0x00000002&((data)<<1))
#define LSADC_PAD1_LEVEL_SET5_INT_en5_src(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET5_get_INT_en5(data)                                      ((0x00000002&(data))>>1)
#define LSADC_PAD1_LEVEL_SET5_INT_pending_bit5_shift                                 (0)
#define LSADC_PAD1_LEVEL_SET5_INT_pending_bit5_mask                                  (0x00000001)
#define LSADC_PAD1_LEVEL_SET5_INT_pending_bit5(data)                                 (0x00000001&((data)<<0))
#define LSADC_PAD1_LEVEL_SET5_INT_pending_bit5_src(data)                             ((0x00000001&(data))>>0)
#define LSADC_PAD1_LEVEL_SET5_get_INT_pending_bit5(data)                             ((0x00000001&(data))>>0)


#define LSADC_INT_PAD0                                                               0x1801BC78
#define LSADC_INT_PAD0_reg_addr                                                      "0xB801BC78"
#define LSADC_INT_PAD0_reg                                                           0xB801BC78
#define set_LSADC_INT_PAD0_reg(data)   (*((volatile unsigned int*) LSADC_INT_PAD0_reg)=data)
#define get_LSADC_INT_PAD0_reg   (*((volatile unsigned int*) LSADC_INT_PAD0_reg))
#define LSADC_INT_PAD0_inst_adr                                                      "0x001E"
#define LSADC_INT_PAD0_inst                                                          0x001E
#define LSADC_INT_PAD0_ADC_value0latch_shift                                         (8)
#define LSADC_INT_PAD0_ADC_value0latch_mask                                          (0x00003F00)
#define LSADC_INT_PAD0_ADC_value0latch(data)                                         (0x00003F00&((data)<<8))
#define LSADC_INT_PAD0_ADC_value0latch_src(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD0_get_ADC_value0latch(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD0_INT_latchstatus_shift                                         (0)
#define LSADC_INT_PAD0_INT_latchstatus_mask                                          (0x00000001)
#define LSADC_INT_PAD0_INT_latchstatus(data)                                         (0x00000001&((data)<<0))
#define LSADC_INT_PAD0_INT_latchstatus_src(data)                                     ((0x00000001&(data))>>0)
#define LSADC_INT_PAD0_get_INT_latchstatus(data)                                     ((0x00000001&(data))>>0)


#define LSADC_INT_PAD1                                                               0x1801BC7C
#define LSADC_INT_PAD1_reg_addr                                                      "0xB801BC7C"
#define LSADC_INT_PAD1_reg                                                           0xB801BC7C
#define set_LSADC_INT_PAD1_reg(data)   (*((volatile unsigned int*) LSADC_INT_PAD1_reg)=data)
#define get_LSADC_INT_PAD1_reg   (*((volatile unsigned int*) LSADC_INT_PAD1_reg))
#define LSADC_INT_PAD1_inst_adr                                                      "0x001F"
#define LSADC_INT_PAD1_inst                                                          0x001F
#define LSADC_INT_PAD1_ADC_value1latch_shift                                         (8)
#define LSADC_INT_PAD1_ADC_value1latch_mask                                          (0x00003F00)
#define LSADC_INT_PAD1_ADC_value1latch(data)                                         (0x00003F00&((data)<<8))
#define LSADC_INT_PAD1_ADC_value1latch_src(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD1_get_ADC_value1latch(data)                                     ((0x00003F00&(data))>>8)
#define LSADC_INT_PAD1_INT_latchstatus_shift                                         (0)
#define LSADC_INT_PAD1_INT_latchstatus_mask                                          (0x00000001)
#define LSADC_INT_PAD1_INT_latchstatus(data)                                         (0x00000001&((data)<<0))
#define LSADC_INT_PAD1_INT_latchstatus_src(data)                                     ((0x00000001&(data))>>0)
#define LSADC_INT_PAD1_get_INT_latchstatus(data)                                     ((0x00000001&(data))>>0)


#endif
