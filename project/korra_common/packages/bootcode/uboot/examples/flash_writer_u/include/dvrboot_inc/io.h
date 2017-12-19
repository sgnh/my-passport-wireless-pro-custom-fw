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

#define RBUS_BASE_VIRT      0x18000000
#define RBUS_BASE_VIRT_OLD  0xb8000000
#define RBUS_BASE_SIZE	    0x70000

#if defined(Board_CPU_RTD1195)
#define SPI_FLASH_BASE_VIRT         0x18100000
#define SPI_FLASH_BASE_VIRT_OLD     0xb8100000
#elif defined(Board_CPU_RTD1192)
#define SPI_FLASH_BASE_VIRT         0x88100000
#define SPI_FLASH_BASE_VIRT_OLD     0x48100000
#else
#define SPI_FLASH_BASE_VIRT         0x18100000
#define SPI_FLASH_BASE_VIRT_OLD     0xb8100000
#endif
#define SPI_FLASH_BASE_SIZE         0x02000000


/*
 * Generic virtual read/write.  Note that we don't support half-word
 * read/writes.  We define __arch_*[bl] here, and leave __arch_*w
 * to the architecture specific code.
 */
#define __arch_getb(a)			(*(volatile unsigned char *)(a))
#define __arch_getw(a)			(*(volatile unsigned short *)(a))
#define __arch_getl(a)			(*(volatile unsigned int *)(a))

#define __arch_putb(v,a)		(*(volatile unsigned char *)(a) = (v))
#define __arch_putw(v,a)		(*(volatile unsigned short *)(a) = (v))
#define __arch_putl(v,a)		(*(volatile unsigned int *)(a) = (v))



#define __raw_writeb(v,a)	__arch_putb(v,a)
#define __raw_writew(v,a)	__arch_putw(v,a)
#define __raw_writel(v,a)	__arch_putl(v,a)

#define __raw_readb(a)		__arch_getb(a)
#define __raw_readw(a)		__arch_getw(a)
#define __raw_readl(a)		__arch_getl(a)



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
    if (addr < (RBUS_BASE_VIRT_OLD+RBUS_BASE_SIZE) && addr >= RBUS_BASE_VIRT_OLD)                       // 0xB800_0000 <= addr < 0xB807_0000 
        return __raw_readl(addr-RBUS_BASE_VIRT_OLD+RBUS_BASE_VIRT);                                     // 0x1800_0000 <= addr < 0x1807_0000
    else if (addr < (SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_SIZE) && addr >= SPI_FLASH_BASE_VIRT_OLD)   // 0xB810_0000 <= addr < 0xBA10_0000 ( range 32MB )
        return __raw_readl(addr-SPI_FLASH_BASE_VIRT_OLD+SPI_FLASH_BASE_VIRT);                           // 0x1810_0000 <= addr < 0x1A10_0000
    else                                                                                                //
        return __raw_readl(addr);                                                                       //
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

#define rtd_maskl(offset, andMask, orMask) rtd_outl(offset, ((rtd_inl(offset) & (andMask)) | (orMask)))
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

#endif	//_ASM_MACH_IO_H_
