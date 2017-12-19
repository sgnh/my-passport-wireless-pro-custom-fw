/* 	CONFIDENTIAL
*********************************************************************************

	File:			common.h
	Target Device:	DD-1/DD-1SP/SPR-1
	Version:		1.00.02

	Description:	Common definition

	Copyright(c) 2008 Yamaha Corporation

*********************************************************************************/
#ifndef _COMMON_H_
#define _COMMON_H_

//#include <stdio.h>
//#include <stdlib.h>
#include <linux/string.h>
//#include <sysdefs.h>
#include "I2CUtil.h"
/* type definition */
//typedef unsigned char	UC;
//typedef unsigned short	US;
//typedef unsigned long	UL;

/* general definition */
#define OFF		0
#define ON		1

#define FALSE	0
#define TRUE	1

#define LOW		0
#define HIGH	1

/* result code definition */
#define SUCCESS			0
#define ERROR_NAK		1
#define ERROR_BUS		2
#define ERROR_RT		3
#define ERROR_DSP 		4
#define ERROR_PARAM 	5
////////////////////////////////////////////////////////////////////////////////
#define UINT8                   unsigned char
#define UINT16                  unsigned short
#define UINT32                  unsigned long
#define SINT8                   signed char
#define SINT16                  signed short
#define SINT32                  signed long

#define MASMW_SUCCESS				(0)			/* success 								*/
#define MASMW_ERROR					(-1)		/* error								*/
#define MASMW_ERROR_ARGUMENT		(-2)		/* error of arguments					*/
#define MASMW_ERROR_RESOURCE_OVER	(-3)		/* over specified resources				*/
#define MASMW_ERROR_ID				(-4)		/* error id number 						*/
#define MASMW_ERROR_TIMEOUT			(-5)		/* timeout*/

#define MAPI_TIMEOUT                        (1)
#define MAPI_SUCCESS                        (0)
#define MAPI_ERROR                          (-1)
#define MAPI_ERROR_ARGUMENT                 (-2)
#define MAPI_ERROR_RESOURCE_OVER            (-3)
#define MAPI_ERROR_ID                       (-4)

/////////////////////////////////////////////////////////////////////////////////////////
/* define */
#define MACHDEP_WRITE_TRANS_MODE	(0)

#define MACHDEP_READ_TRANS_MODE		(1)
/* MC-1 Slave Address */
#define	DD1SP_SLAVE_ADDRESS		(0x6C) // (0x3A)

#if 0
/* bit definition */
#define BITNONE	0x00

#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80


/* ------------------- */
/* register definition */
/* ------------------- */

/* register address definition */
#pragma ADDRESS cm0_addr	0006H			/* system clock control register 0 */
#pragma ADDRESS cm1_addr	0007H			/* system clock control register 1 */
#pragma ADDRESS csr_addr	0008H			/* chip select control register */
#pragma ADDRESS prcr_addr	000aH			/* protect register */
#pragma ADDRESS dbr_addr	000bH			/* data bank register */
#pragma ADDRESS cse_addr	001bH			/* chip select expansion control register */

#pragma ADDRESS plc0_addr	001cH			/* PLC control register 0 */
#pragma ADDRESS pm2_addr	001eH			/* processor mode register 2 */

#pragma ADDRESS u0bcnic_addr	0047H		/* UART0 bus collision detection interrupt control register */
#pragma ADDRESS s0tic_addr		0051H		/* UART0 transmit interrupt control register */

#pragma ADDRESS ifsr2a_addr	035eH			/* interrupt request cause select register 2 */

#pragma ADDRESS u0smr4_addr	036cH			/* UART0 special mode register 4 */
#pragma ADDRESS u0smr3_addr	036dH			/* UART0 special mode register 3 */
#pragma ADDRESS u0smr2_addr	036eH			/* UART0 special mode register 2 */
#pragma ADDRESS u0smr_addr	036fH			/* UART0 special mode register */
#pragma ADDRESS u0mr_addr	03a0H			/* UART0 transmit/receive mode register */
#pragma ADDRESS u0brg_addr	03a1H			/* UART0 bit rate generator */
#pragma ADDRESS u0tb_addr	03a2H			/* UART0 transmit buffer register */
#pragma ADDRESS u0c0_addr	03a4H			/* UART0 transmit/receive control register 0 */
#pragma ADDRESS u0c1_addr	03a5H			/* UART0 transmit/receive control register 1 */
#pragma ADDRESS u0rb_addr	03a6H			/* UART0 receive buffer register */
#pragma ADDRESS ucon_addr	03b0H			/* UART transmit/receive control register 2 */

#pragma ADDRESS pur0_addr	03fcH			/* pull-up control register 0 */
#pragma ADDRESS pur1_addr	03fdH			/* pull-up control register 1 */
#pragma ADDRESS pur2_addr	03feH			/* pull-up control register 2 */

#pragma ADDRESS pd0_addr	03e2H			/* port P0 direction register */
#pragma ADDRESS pd1_addr	03e3H			/* port P1 direction register */
#pragma ADDRESS pd2_addr	03e6H			/* port P2 direction register */
#pragma ADDRESS pd3_addr	03e7H			/* port P3 direction register */
#pragma ADDRESS pd4_addr	03eaH			/* port P4 direction register */
#pragma ADDRESS pd5_addr	03ebH			/* port P5 direction register */
#pragma ADDRESS p7_addr		03edH			/* port P7 register */
#pragma ADDRESS pd6_addr	03eeH			/* port P6 direction register */
#pragma ADDRESS pd7_addr	03efH			/* port P7 direction register */
#pragma ADDRESS p8_addr		03f0H			/* Port P8 register */
#pragma ADDRESS pd8_addr	03f2H			/* port P8 direction register */
#pragma ADDRESS pd9_addr	03f3H			/* port P9 direction register */
#pragma ADDRESS pd10_addr	03f6H			/* port P10 direction register */

struct bit_def {
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
};

union byte_def {
		struct	bit_def bit;
		char	byte;
};

union {
	struct {
		char		b0:1;
		char		b1:1;
		char		b2:1;
		char		b3:1;
		char		b4:1;
		char		b5:1;
		char		b6:1;
		char		b7:1;
		char		b8:1;
		char		b9:1;
		char		b10:1;
		char		b11:1;
		char		b12:1;
		char		b13:1;
		char		b14:1;
		char		b15:1;
	} bit;
	struct {
		char		low;
		char		high;
	} byte;
	unsigned short	word;
} u0rb_addr, u0tb_addr;

/* system clock control register 0-1 */
union byte_def cm0_addr;
union byte_def cm1_addr;
#define bCm0		cm0_addr.byte
#define bCm1		cm1_addr.byte
#define bitCm11		cm1_addr.bit.b1

/* chip select control register */
union byte_def csr_addr;
#define bCsr		csr_addr.byte

/* protect register */
union byte_def prcr_addr;
#define bPrcr		prcr_addr.byte
#define bitPrc0		prcr_addr.bit.b0
#define bitPrc1		prcr_addr.bit.b1
#define bitPrc2		prcr_addr.bit.b2

/* data bank register */
union byte_def dbr_addr;
#define bDbr		dbr_addr.byte

/* chip select expansion control register */
union byte_def cse_addr;
#define bCse		cse_addr.byte

/* PLC control register 0 */
union byte_def plc0_addr;
#define bPlc0		plc0_addr.byte
#define bitPlc07	plc0_addr.bit.b7

/* processor mode register 2 */
union byte_def pm2_addr;
#define bPm2		pm2_addr.byte

/* UART0 bus collision detection interrupt control register */
union byte_def u0bcnic_addr;
#define bU0bcnic	u0bcnic_addr.byte

/* UART0 transmit interrupt control register */
union byte_def s0tic_addr;
#define bS0tic			s0tic_addr.byte
#define bitIr_s0tic		s0tic_addr.bit.b3

/* interrupt request cause select register 2 */
union byte_def ifsr2a_addr;
#define bIfsr2a		ifsr2a_addr.byte

/* UART0 special mode register (2-4) */
union byte_def u0smr4_addr;
union byte_def u0smr3_addr;
union byte_def u0smr2_addr;
union byte_def u0smr_addr;
#define bU0smr4			u0smr4_addr.byte
#define bU0smr3			u0smr3_addr.byte
#define bU0smr2			u0smr2_addr.byte
#define bU0smr			u0smr_addr.byte
#define bitAls_u0smr2	u0smr2_addr.bit.b3
#define bitBbs_u0smr	u0smr_addr.bit.b2

/* UART0 transmit/receive mode register */
union byte_def u0mr_addr;
#define bU0mr		u0mr_addr.byte

/* UART0 bit rate generator */
union byte_def u0brg_addr;
#define bU0brg		u0brg_addr.byte

/* UART0 transmit/receive control register 0-1 */
union byte_def u0c0_addr;
union byte_def u0c1_addr;
#define bU0c0		u0c0_addr.byte
#define bU0c1		u0c1_addr.byte

/* UART0 transmit/receive buffer register */
#define wU0tb		u0tb_addr.word
#define wU0rb		u0rb_addr.word

/* UART transmit/receive control register 2 */
union byte_def ucon_addr;
#define bUcon		ucon_addr.byte

/* pull-up control register 0-2 */
union byte_def pur0_addr;
union byte_def pur1_addr;
union byte_def pur2_addr;
#define bPur0		pur0_addr.byte
#define bPur1		pur1_addr.byte
#define bPur2		pur2_addr.byte

/* port P0-10 direction register */
union byte_def pd0_addr;
union byte_def pd1_addr;
union byte_def pd2_addr;
union byte_def pd3_addr;
union byte_def pd4_addr;
union byte_def pd5_addr;
union byte_def pd6_addr;
union byte_def pd7_addr;
union byte_def pd8_addr;
union byte_def pd9_addr;
union byte_def pd10_addr;
#define bPd0		pd0_addr.byte
#define bPd1		pd1_addr.byte
#define bPd2		pd2_addr.byte
#define bPd3		pd3_addr.byte
#define bPd4		pd4_addr.byte
#define bPd5		pd5_addr.byte
#define bPd6		pd6_addr.byte
#define bPd7		pd7_addr.byte
#define bPd8		pd8_addr.byte
#define bPd9		pd9_addr.byte
#define bPd10		pd10_addr.byte

/* port P7-8 register */
union byte_def p7_addr;
union byte_def p8_addr;
#define bP7			p7_addr.byte
#define bP8			p8_addr.byte
#define bitP7_3		p7_addr.bit.b3
#define bitP8_1		p8_addr.bit.b1

#endif 
#endif
/* -------------------------- */
/* end of register definition */
/* -------------------------- */

/* end of file */
