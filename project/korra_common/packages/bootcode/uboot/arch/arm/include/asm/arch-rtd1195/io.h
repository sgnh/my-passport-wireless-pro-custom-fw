/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 * IO mappings for RTD299X
 */

#ifndef _ASM_MACH_IO_H_
#define _ASM_MACH_IO_H_

#include <asm/io.h>

#define RBUS_BASE_VIRT      0x18000000
#define RBUS_BASE_VIRT_OLD  0xb8000000
#define RBUS_BASE_SIZE		0x40000

#define SPI_FLASH_BASE_VIRT 		0x18100000
#define SPI_FLASH_BASE_VIRT_OLD		0xb8100000
#define SPI_FLASH_BASE_SIZE			0x1000000

#define GET_MAPPED_RBUS_ADDR(x)		(x - RBUS_BASE_VIRT_OLD + RBUS_BASE_VIRT)

static inline unsigned char rtd_inb(unsigned int addr)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)
        return __raw_readb(addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
		return __raw_readb(addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        return __raw_readb(addr);
}
static inline unsigned short rtd_inw(unsigned int addr)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)
        return __raw_readw(addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
		return __raw_readw(addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        return __raw_readw(addr);
}
static inline unsigned int rtd_inl(unsigned int addr)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)
        return __raw_readl(addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
		return __raw_readl(addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        return __raw_readl(addr);
}
static inline void rtd_outb(unsigned int addr, unsigned char val)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)
        __raw_writeb(val,addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
        __raw_writeb(val, addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        __raw_writeb(val,addr);
}
static inline void rtd_outw(unsigned int addr, unsigned short val)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)
        __raw_writew(val,addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
        __raw_writew(val, addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        __raw_writew(val,addr);
}
static inline void rtd_outl(unsigned int addr, unsigned int val)
{
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= 0xb8000000)
        __raw_writel(val,addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);
	else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)
        __raw_writel(val, addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);
    else
        __raw_writel(val,addr);
}

static inline int rtd_size_aligned(unsigned int x, unsigned int y)
{
    if (x&(y-1)) 
	{
		x &= ~(y-1);
		x += y;
	}
	return x;
}

#define rtd_maskl(offset, andMask, orMask) rtd_outl(offset, ((rtd_inl(offset) & (andMask)) | (orMask)))
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))
#define rtd_readbits(offset, Mask)    ((rtd_inl(offset) >> (Mask)) & 0x1)

#define rtd_fld_get(val, start, end) (((val) & rtd_fld_mask(start, end)) >> (end))
#define rtd_fld_mask(start, end)    (((1 << (start - end + 1)) - 1) << (end))

#define _BIT0            0x00000001
#define _BIT1            0x00000002
#define _BIT2            0x00000004
#define _BIT3            0x00000008
#define _BIT4            0x00000010
#define _BIT5            0x00000020
#define _BIT6            0x00000040
#define _BIT7            0x00000080
#define _BIT8            0x00000100
#define _BIT9            0x00000200
#define _BIT10           0x00000400
#define _BIT11           0x00000800
#define _BIT12           0x00001000
#define _BIT13           0x00002000
#define _BIT14           0x00004000
#define _BIT15           0x00008000
#define _BIT16           0x00010000
#define _BIT17           0x00020000
#define _BIT18           0x00040000
#define _BIT19           0x00080000
#define _BIT20           0x00100000
#define _BIT21           0x00200000
#define _BIT22           0x00400000
#define _BIT23           0x00800000
#define _BIT24           0x01000000
#define _BIT25           0x02000000
#define _BIT26           0x04000000
#define _BIT27           0x08000000
#define _BIT28           0x10000000
#define _BIT29           0x20000000
#define _BIT30           0x40000000
#define _BIT31           0x80000000

#define _sync()     asm("DMB");\
					rtd_inl(0x1801a020);\
					asm("DMB");
									
#endif	//_ASM_MACH_IO_H_
