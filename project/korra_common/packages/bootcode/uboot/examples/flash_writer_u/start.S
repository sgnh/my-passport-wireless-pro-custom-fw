#include "include/project_config_f.h"

.text 
.global start

start:      
        mrc     p15, 0, r1, c0, c0, 5     @ Read Multiprocessor Affinity Register
       ands    r1, r1, #0x03              @ Mask off, leaving the CPU ID field
        cmp         r1,#0x00                      @ core0 : 0x00 , others 0x01 , 0x02 ...
        bne         run_secondary

#ifdef FPGA
       b       reset
#endif
	mov	R3,sp
	MOV 	R3, R3,LSR#24
	cmp	R3,#16
	beq	reset	
	bl	dvrmain 

.globl _stack_start
_stack_start:
	.word 0x02000000
.globl _stack_start1
_stack_start1:
	.word 0x02500000
	
reset:	
	ldr sp, _stack_start
	bic	sp, sp, #7
	b	dvrmain

run_secondary:
     ldr   sp, _stack_start1
     MSR   CPSR_c, #0xD3 ; #MODE_SVC:OR:DIS_IRQ:OR:DIS_FIRQ
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
9:
     b	   9b
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0

@add empty raise() to fix (when use new EABI xscale cross compiler to) compile
@error gcc/config/arm/lib1funcs.asm:1266: undefined reference to `raise'
.globl raise
raise:
    nop
    mov pc, lr
