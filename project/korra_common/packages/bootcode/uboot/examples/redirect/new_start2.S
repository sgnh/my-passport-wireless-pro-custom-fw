
.text 
.global start2

#define LEN_USR_STACK 0
#define LEN_ABT_STACK 0
#define LEN_UND_STACK 0
#define LEN_SYS_STACK 0
#define LEN_IRQ_STACK 0
#define LEN_FIQ_STACK 0
#define LEN_SVC_STACK 64

#define OFFSET_USR_STACK 	(0)
#define OFFSET_SVC_STACK 	(OFFSET_USR_STACK + LEN_USR_STACK)
#define OFFSET_FIQ_STACK 	(OFFSET_SVC_STACK + LEN_SVC_STACK)
#define OFFSET_IRQ_STACK 	(OFFSET_FIQ_STACK + LEN_FIQ_STACK)
#define OFFSET_ABT_STACK 	(OFFSET_IRQ_STACK + LEN_IRQ_STACK)
#define OFFSET_UND_STACK 	(OFFSET_ABT_STACK + LEN_ABT_STACK)
#define OFFSET_SYS_STACK 	(OFFSET_UND_STACK + LEN_UND_STACK)

#define STACK_BASE			0x00020000
#define STACK_BASE2			(STACK_BASE-LEN_SVC_STACK)
#define STACK_UPPER_BOUND	(STACK_BASE-LEN_SVC_STACK-LEN_SVC_STACK)
#define STACK_SIZE			(LEN_SVC_STACK+LEN_SVC_STACK)
#define MAGIC_TAG   		0x1801a610
#define JUMP_ADDRESS		0x00020000

CPU0_MAGIC_TAG:
	.word	0xdeadbeef
CPU1_MAGIC_TAG:
	.word	0xdeadbeef

start2:

@ --  invalidate L1 i-cache, d-cache
     @
     @ r4, r5, r6, r7, r8
     @
     @ Disable MMU
     MRC   p15, 0, r4, c1, c0, 0   @ Read Control Register configuration data
     BIC   r1, r4, #0x1
     MCR   p15, 0, r4, c1, c0, 0   @ Write Control Register configuration data

     @ Disable L1 Caches
     MRC   p15, 0, r4, c1, c0, 0   @ Read Control Register configuration data
     BIC   r4, r4, #(0x1 << 12)    @ Disable I Cache
     BIC   r4, r4, #(0x1 << 2)     @ Disable D Cache
     MCR   p15, 0, r4, c1, c0, 0   @ Write Control Register configuration data

     @ Invalidate L1 Caches
     @ Invalidate Instruction cache
     MOV   r4, #0
     MCR   p15, 0, r4, c7, c5, 0   @ Invalidate Data cache

     @ to make the code general purpose, we calculate the
     @ cache size first and loop through each set + way
     @ 32KB = 4 way * 256 sets * 32 bytes
     @
     MRC   p15, 1, r5, c0, c0, 0   @ Read Cache Size ID 
     LDR   r8, =0x1ff              @ MOV   r8, #0x1ff
     AND   r5, r8, r5, LSR #13     @ r5 = no. of sets - 1
     
     MOV   r6, #0                  @ r6 = way counter way_loop
way_loop:
     MOV   r8, #0                  @ r8 = set counter set_loop
set_loop:
     MOV   r7, r6, LSL #30         @
     ORR   r7, r8, LSL #5          @ r7 = set/way cache operation format
     MCR   p15, 0, r7, c7, c6, 2   @ Invalidate line described by r7
     ADD   r8, r8, #1              @ Increment set counter
     CMP   r8, r5                  @ Last set reached yet?
     BLE   set_loop                @ if not, iterate set_loop
     ADD   r6, r6, #1              @ else, next
     CMP   r6, #4                  @ Last way reached yet?
     BLT   way_loop                @ if not, iterate way_loop

     @ Full system DSB - make sure that the invalidation is complete
     MOV   r4, #0
     MCR   p15, 0, r4, c7, c10, 4

     @ Invalidate TLB
     @ Invalidate entire unified TLB
     MOV   r4, #0
     MCR   p15, 0, r4, c8, c7, 0
     @ Invalidate entire data TLB
     MOV   r4, #0
     MCR   p15, 0, r4, c8, c6, 0
     @ Invalidate entire instruction TLB
     MOV   r4, #0
     MCR   p15, 0, r4, c8, c5, 0
     
     @ Full system ISB - make sure the instruction stream sees it
     MOV   r4, #0
     MCR   p15, 0, r4, c7, c5, 4

@ -- clear the content of magic tag
     LDR  r0 , =MAGIC_TAG
     LDR  r1 , =0x00000000
     STR  r1 , [r0]

#if 0 // simulate 2nd CPU
     B     run_secondary
#endif

     MRC   p15, 0, r0, c0, c0, 5
     AND   r0, r0, #0x3 
     CMP   r0, #0
     BNE   run_secondary
  
@ -- set default stack of super visor mdoe
@ -- also update line 124
     LDR  r0, =STACK_BASE
     MOV  SP, r0

@ -- NOP
     MOV  r0 , #0
     MOV  r0 , #0
     MOV  r0 , #0

@ -- Clear RAM
@ -- r0  start address
@ -- r1  zero
@ -- r2  end address 
     LDR  r0 , =STACK_UPPER_BOUND
     MOV  r1 , #0
     ADD  r2 , r0 , #(STACK_SIZE)
INIT_SRAM:
     CMP  r0 , r2
     STRLO r1 , [r0]
     ADDLO r0 , r0 , #4
     BLO  INIT_SRAM

@ -- initial cpu register ( heap, stack... )
@ -- set stack base address
     LDR     r0, =STACK_BASE

     MSR     CPSR_c, #0xD3 ; #MODE_SVC:OR:DIS_IRQ:OR:DIS_FIRQ
     SUB     r3, r0, #OFFSET_SVC_STACK
     MOV     SP, r3

     MSR     CPSR_c, #0xD1 ; #MODE_FIQ:OR:DIS_IRQ:OR:DIS_FIRQ
     SUB     r3, r0, #OFFSET_FIQ_STACK
     MOV     SP, r3

     MSR     CPSR_c, #0xD2 ; #MODE_IRQ:OR:DIS_IRQ:OR:DIS_FIRQ
     SUB     r3, r0, #OFFSET_IRQ_STACK
     MOV     SP, r3

@ -- MSR     CPSR_c, #0xD7 ; #MODE_ABT:OR:DIS_IRQ:OR:DIS_FIRQ
@ -- SUB     r3, r0, #OFFSET_ABT_STACK
@ -- MOV     SP, r3

@ -- MSR     CPSR_c, #0xDB ; #MODE_UND:OR:DIS_IRQ:OR:DIS_FIRQ
@ -- SUB     r3, r0, #OFFSET_UND_STACK
@ -- MOV     SP, r3

     MSR     CPSR_c, #0xDF ; #MODE_SYS:OR:DIS_IRQ:OR:DIS_FIRQ
     SUB     r3, r0, #OFFSET_SYS_STACK
     MOV     SP, r3

@ -- please not set CPSR_c to user mode
@ -- MSR     CPSR_c, #0xD0 ; #MODE_USR:OR:DIS_IRQ:OR:DIS_FIRQ
@ -- SUB     r3, r0, #OFFSET_USR_STACK
@ -- MOV     SP, r3

@ -- back to supervisor mode
     MSR     CPSR_c, #0xD3 ; #MODE_SVC:OR:DIS_IRQ:OR:DIS_FIRQ

@ -- Jump to u-boot
@ -- IMPORT  main
check_cpu0_tag:
     LDR     r0 , =0x0001F800
     LDR     r1, [r0]
     LDR     r2 , =0xdeadbeef
     CMP     r1, r2
     BNE     check_cpu0_tag
     LDR     r0, =JUMP_ADDRESS
     MOV     PC, r0

run_secondary:
     LDR   r0, =STACK_BASE2
     MOV   SP, r0
     MSR   CPSR_c, #0xD3 ; #MODE_SVC:OR:DIS_IRQ:OR:DIS_FIRQ
     B     run_secondary2
enter_wfi:
     WFI
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r1 , #0
     LDR   r0 , =MAGIC_TAG
     STR   r1 , [r0]
run_secondary2:
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     LDR   r0 , =MAGIC_TAG
     LDR   r1, [r0]
     CMP   r1, #0
     BEQ   run_secondary2
     LDR   r2 , =0xFFFFFFFF
     CMP   r1, r2
     BEQ   enter_wfi
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     MOV   r0, r0
     @load adddress to run
     LDR   r1, =MAGIC_TAG
     LDR   r2, [r1]
     MOV   PC, r2

