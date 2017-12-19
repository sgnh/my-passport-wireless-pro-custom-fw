MEMORY {
	INIT_CODE (rx)    : ORIGIN = 0x00000000, LENGTH = 32
	INIT_CODE2(rx)    : ORIGIN = 0x0001F800, LENGTH = 1792
	SRAM_256  (rw)    : ORIGIN = 0x0001FE00, LENGTH = 256
}

ENTRY(start)

SECTIONS {

	.start :
	     { 
	          ./new_start.o(.text);
	     } > INIT_CODE
	. = ALIGN(4);

	.start2 :
	     { 
	          ./new_start2.o(.text);
	     } > INIT_CODE2
	. = ALIGN(4);

	.rodata : 
	     { 
	          *(.rodata);
	     } > INIT_CODE2
	. = ALIGN(4);
	_rodata_end = .;

	.data :
	     { 
	          *(.data);	     
	     } > SRAM_256
	. = ALIGN(4);
	_data_end = .;

	.bss :
	     { 
	          *(.bss);
	     } > SRAM_256
	. = ALIGN(4);
	_bss_end =.;
}

