/*
This is a piece of redirect code, and is used to make CPU jump to actual bootcode's address
It will check 0x1801a610, and if valid, CPU will do the jump.
Otherwise, CPU jumps to default address 0x20000
*/

.globl _start
_start: b	reset
		b	reset
		b	reset
		b	reset
		b	reset
		b	reset
		b	reset
		nop

reset:
	orr r0, r0, #402653184  @0x18000000
	orr r0, r0, #106496 	@0x1a000
	ldr r1, [r0, #1552] 	@0x610
	cmp r1, #0				
	beq non_equ
	blx r1
non_equ:
	mov r1, #131072 		@0x20000
	blx r1
