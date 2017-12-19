/*
 * (C) Copyright 2000-2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 *
 */
#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/arch/rbus/crt_reg.h>
#include <asm/arch/system.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/panelConfigParameter.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/flash_writer_u/mcp.h>
#include <watchdog.h>

#define PINMUX_REG_BASE		0xb8000800
#define GPIO_MUXCFG_23		(PINMUX_REG_BASE + 0x5c)
#define GPIO_MUXCFG_24		(PINMUX_REG_BASE + 0x60)

void set_spi_pin_mux(void)
{
	//use uboot setting
#if 1
	int reg_val;

	// set GPIO_122_ps[15:12] to "	0: SPI_CS_N,<O>"
	// set GPIO_123_ps[7:4] to "	0: SPI_SCLK,<O>"
	reg_val = rtd_inl(GPIO_MUXCFG_23) & 0xffff0f0f;
	rtd_outl(GPIO_MUXCFG_23, reg_val);

	// set GPIO_125_ps[23:20] to "	0: SPI_DI,<I/O>"
	// set GPIO_126_ps[15:12] to "	0: SPI_DO,<I/O>"
	reg_val = rtd_inl(GPIO_MUXCFG_24) & 0xff0f0fff;
	rtd_outl(GPIO_MUXCFG_24, reg_val);
#endif
}

int rtk_freecpu(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int _iAddress;
	unsigned int _i;
	int _iCPUID;
	
	_iCPUID = 0;
	_iAddress = 0;
	
	if( argc >= 2 ) {
		if( strncmp(argv[1], "acpu", 4) == 0 ) {
			_iCPUID = 0;
		}
		else {
			_iCPUID = -1;
		}
	}
	
	if( argc >= 3 ) {
		_iAddress = simple_strtoul(argv[2], NULL, 16);
	}
	
	printf("target cpu id = %d\n", _iCPUID );
	printf("target address = 0x%08x\n", _iAddress );
	
	if( _iCPUID < 0 ) {
		return -1;
	}
		
	do {
		printf("\nRelease HW semaphore....");
	    *((volatile unsigned int *)0x000000E0) = 0;
		rtd_outl(0xB801A618, _iAddress);
		rtd_outl(0xB801A000, 0);
		printf("Done\n");
		
		//set_spi_pin_mux();
		
		//rtd_outl(0xb801a800, 0x00000003);
	}
	while(0);

	return 0;
}

U_BOOT_CMD(
	freecpu, 3, 0,	rtk_freecpu,
	"to free specified cpu",
	"free cpu_name address\n"
	"\t- cpu_name acpu\n"
	"\t- address  default 0x00000000\n"
);

