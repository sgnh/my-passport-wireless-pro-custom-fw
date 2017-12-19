/*
 * Copyright (c) 2004-2008 Texas Instruments
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x00000000;

	. = ALIGN(4);
	.text :
	{
		__image_copy_start = .;
		CPUDIR/start.o (.text)
		*(.text)
	}

	. = ALIGN(4);
	.rodata : { *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*))) }

	. = ALIGN(4);
	.data : {
		*(.data)

		/********* Insert A/V CPU related image start *********/
		. = ALIGN(8);

		_f_exc_redirect_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.exc_redirect)
		. = ALIGN(8);
		_e_exc_redirect_img = .;

		_f_exc_dispatch_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.exc_dispatch)
		. = ALIGN(8);
		_e_exc_dispatch_img = .;

		_f_a_entry_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.a_entry)
		. = ALIGN(8);
		_e_a_entry_img = .;

		_f_v_entry_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.v_entry)
		. = ALIGN(8);
		_e_v_entry_img = .;

		_f_isrvideo_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.isrvideoimg)
		. = ALIGN(8);
		_e_isrvideo_img = .;

		_f_rosbootvector_img = .;
		MIPS_BOOTLOAD_LIB_PATH (.rosbootvectorimg)
		. = ALIGN(8);
		_e_rosbootvector_img = .;

		/********* Insert A/V CPU related image end *********/

	}

	. = ALIGN(4);

	. = .;
	__u_boot_cmd_start = .;
	.u_boot_cmd : { *(.u_boot_cmd) }
	__u_boot_cmd_end = .;

	. = ALIGN(4);

	__image_copy_end = .;

	.rel.dyn : {
		__rel_dyn_start = .;
		*(.rel*)
		__rel_dyn_end = .;
	}

	.dynsym : {
		__dynsym_start = .;
		*(.dynsym)
	}

	_end = .;

	/*
	 * Deprecated: this MMU section is used by pxa at present but
	 * should not be used by new boards/CPUs.
	 */
	. = ALIGN(4096);
	.mmutable : {
		*(.mmutable)
	}
	
	.bss __rel_dyn_start (OVERLAY) : {	
		__bss_start = .;
		*(.bss)
		 . = ALIGN(4);
		__bss_end__ = .;
	}

	. += 0x10000;
	__stack_start = .;

	/DISCARD/ : { *(.dynstr*) }
	/DISCARD/ : { *(.dynamic*) }
	/DISCARD/ : { *(.plt*) }
	/DISCARD/ : { *(.interp*) }
	/DISCARD/ : { *(.gnu*) }
}
