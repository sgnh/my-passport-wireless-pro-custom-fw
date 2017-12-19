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
 * Misc boot support
 */
#include <common.h>
#include <command.h>
#include <rbus/sb2_reg.h>
#include <asm/arch/system.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/fw_info.h>
#include <fdt.h>
#include <rtkspi.h>

#define SPI_BASE_ADDR					(0xB8100000UL)
#define SPI_CODE_PART1					(SPI_BASE_ADDR)
#define SPI_CODE_PART2					(SPI_BASE_ADDR+(1UL<<20))

#define SPI_MAX_PARAM_SIZE				(0x800UL)
#define SPI_RESETROM_SIZE				(0x8000UL)

extern int decrypt_image(char *src, char *dst, uint length, uint *key);

DECLARE_GLOBAL_DATA_PTR;

s_bootcode2_header bootcode2_header;

void spi_read_extra_parameter( void )
{
	unsigned int _iSPI_base_addr;
	
	memset( &bootcode2_header, 0, sizeof(s_bootcode2_header));
	
	_iSPI_base_addr = SPI_RBUS_BASE_ADDR + CONFIG_BOOTCODE2_BASE;

	// read first 16 bytes
	rtkspi_read32( (unsigned int)&bootcode2_header, _iSPI_base_addr, sizeof(s_bootcode2_header));

	printf("*** header magic_tag  0x%08x\n", bootcode2_header.magic_tag);
	printf("*** header secue_mode 0x%08x\n", bootcode2_header.secue_mode);
	printf("*** header data size  0x%08x\n", bootcode2_header.bootcode_size);
	printf("*** header entry addr 0x%08x\n", bootcode2_header.bootcode_entry_addr);
}

int rtk_bootcodeloader(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret;
	unsigned int _iSPI_base_addr;

	//MEM_LAYOUT_WHEN_READ_IMAGE_T mem_layout;

	ret = 0;

	do {
		// read bootcode2 header
		spi_read_extra_parameter();

		if( bootcode2_header.magic_tag != SPI_BOOTCODE_MAGIC ) {
			printf("*** %s %d, bootocde tag(%08x) us invlaid ***\n", __FUNCTION__, __LINE__, bootcode2_header.magic_tag);
			return 0;
		}

		if( bootcode2_header.bootcode_size < (100<<10) ) {
			printf("*** %s %d, bootocde szie(%08x) is seem wrong ***\n", __FUNCTION__, __LINE__, bootcode2_header.magic_tag);
			return 0;
		}

		// verify image ( SHA256 or signature )
		if( bootcode2_header.secue_mode == SPI_BOOTCODE_RTK_MODE ) {
			printf("*** %s %d, Oops! fix me ***\n", __FUNCTION__, __LINE__);
		}
		else
		{
			_iSPI_base_addr = SPI_RBUS_BASE_ADDR + CONFIG_BOOTCODE2_BASE + sizeof(s_bootcode2_header);

			rtkspi_read32( bootcode2_header.bootcode_entry_addr, _iSPI_base_addr, bootcode2_header.bootcode_size );

			// flush data
			flush_cache( bootcode2_header.bootcode_entry_addr, bootcode2_header.bootcode_size );
#if 1			
			ret = Verify_SHA256_hash( (unsigned char *)bootcode2_header.bootcode_entry_addr,
			                          bootcode2_header.bootcode_size - 32,
			                          (unsigned char *)(bootcode2_header.bootcode_entry_addr + bootcode2_header.bootcode_size - 32), 0 );
#endif
		}

		if( ret < 0 ) {
			printf("[ERR] %s: hash value not match\n", __FUNCTION__ );
			return 0;
		}
#if 0
		// restore boot media info ( UATAG_ADDRESS9, UATAG_ADDRESS10 )
		extern unsigned int UATAG_ADDRESS9;
		extern unsigned int UATAG_ADDRESS10;

		_iTagAddr = ( (unsigned int)(&UATAG_ADDRESS9) ) & 0x000000FFUL;
		_iTagAddr |= _iBootcodeIdx_TextAddr;
		*((volatile unsigned int *)_iTagAddr) = UATAG_ADDRESS9;
		
		_iTagAddr = ( (unsigned int)(&UATAG_ADDRESS10) ) & 0x000000FFUL;
		_iTagAddr |= _iBootcodeIdx_TextAddr;
		*((volatile unsigned int *)_iTagAddr) = UATAG_ADDRESS10;
#endif		
		// jump to selected bootcode address
#if 0
		bootm_headers_t	images;

		memset(&images, 0, sizeof(bootm_headers_t));
	
		images.ep = (unsigned long)_iBootcodeIdx_TextAddr;
	
		printf("Start bootcode at 0x%lx ...\n", images.ep);
	
		rtk_plat_boot_go(&images);
#else
		void (*uboot_entry)(void);
		uboot_entry = (void (*)(void))(bootcode2_header.bootcode_entry_addr);
		printf("Start bootcode2 at 0x%08x ...\n", bootcode2_header.bootcode_entry_addr);
		cleanup_before_bootcode();
		uboot_entry();
#endif
	}
	while(0);

	return 0;
}

U_BOOT_CMD(
	bcldr, 4, 0,	rtk_bootcodeloader,
	"load u-boot from spi flash",
	"bcldr\n"
);
