
.text 
.global start

start:

@ 0x00: Reset
	b	start2

@ 0x04: Undefined instruction exception
HandleUndef:
	b	HandleUndef

@ 0x08: Software interrupt exception  
HandleSWI:
	b	HandleSWI

@ 0x0C: Prefetch Abort (Instruction Fetch Memory Abort)
HandlePrefetchAbort:
	b	HandlePrefetchAbort

@ 0x10: Data Access Memory Abort
HandleDataAbort:
	b	HandleDataAbort

@ 0x14: Not used
HandleNotUsed:
	b	HandleNotUsed

@ 0x18: IRQ(Interrupt Request) exception
HandleIRQ:
	b	HandleIRQ

@ 0x1C: FIQ(Fast Interrupt Request) exception
HandleFIQ:
	b	HandleFIQ
