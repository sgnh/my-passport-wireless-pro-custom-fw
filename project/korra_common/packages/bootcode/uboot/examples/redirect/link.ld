ENTRY(_start)
SECTIONS
{
	. = 0x00000000;

	.text 	: { 
		__text_start = .;
		*(.text);
		. = ALIGN(4);
		__text_end = .;
	} 

	.data	: { 
        __data_start = .;
        *(.data)  *(.lit4) *(.lit8) *(.rodata); *(.rodata.*)
        *(.sdata)
        . = ALIGN(4);
        __data_end = .;
    } 

	.bss	: 
	{
		__bss_start = .;
		*(.sbss) *(.bss) *(.scommon)
		. = ALIGN(4);
	        __bss_end = .; 
	}
 /DISCARD/ : { *(.dynstr*) }
 /DISCARD/ : { *(.dynamic*) }
 /DISCARD/ : { *(.plt*) }
 /DISCARD/ : { *(.interp*) }
 /DISCARD/ : { *(.gnu*) }
}





