#include "cache.h"
#include "sysdefs.h"
#include "dvrboot_inc/mis_reg.h"
#include "dvrboot_inc/sys_reg.h"
#include "dvrboot_inc/util.h"
#include "dvrboot_inc/mcp.h"
#include "dvrboot_inc/string.h"
#include "dvrboot_inc/timer.h"

static void cp_delay (void)
{
        volatile int i;

	udelay(5);
        asm volatile("" : : : "memory");
}

static inline int log_2_n_round_up(unsigned int n)
{
	int log2n = -1;
	unsigned int temp = n;

	while (temp) {
		log2n++;
		temp >>= 1;
	}

	if (n & (n - 1))
		return log2n + 1; /* not power of 2 - round up */
	else
		return log2n; /* power of 2 */
}

static void set_csselr(unsigned int level, unsigned int type)
{	UINT32 csselr = level << 1 | type;

	/* Write to Cache Size Selection Register(CSSELR) */
	asm volatile ("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
}

static unsigned int get_ccsidr(void)
{
	unsigned int ccsidr;

	/* Read current CP15 Cache Size ID Register */
	asm volatile ("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
	return ccsidr;
}

static unsigned int get_clidr(void)
{
	unsigned int clidr;

	/* Read current CP15 Cache Level ID Register */
	asm volatile ("mrc p15,1,%0,c0,c0,1" : "=r" (clidr));
	return clidr;
}

static void v7_clean_inval_dcache_level_setway(unsigned int level, unsigned int num_sets,
					       unsigned int num_ways, unsigned int way_shift,
					       unsigned int log2_line_len)
{
	int way, set, setway;

	/*
	 * For optimal assembly code:
	 *	a. count down
	 *	b. have bigger loop inside
	 */
	for (way = num_ways - 1; way >= 0 ; way--) {
		for (set = num_sets - 1; set >= 0; set--) {
			setway = (level << 1) | (set << log2_line_len) |
				 (way << way_shift);
			/*
			 * Clean & Invalidate data/unified
			 * cache line by set/way
			 */
			asm volatile ("	mcr p15, 0, %0, c7, c14, 2"
					: : "r" (setway));
		}
	}
	/* DSB to make sure the operation is complete */
	CP15DSB;
}

static void v7_inval_dcache_level_setway(unsigned int level, unsigned int num_sets,
					 unsigned int num_ways, unsigned int way_shift,
					 unsigned int log2_line_len)
{
	int way, set, setway;

	/*
	 * For optimal assembly code:
	 *	a. count down
	 *	b. have bigger loop inside
	 */
	for (way = num_ways - 1; way >= 0 ; way--) {
		for (set = num_sets - 1; set >= 0; set--) {
			setway = (level << 1) | (set << log2_line_len) |
				 (way << way_shift);
			/* Invalidate data/unified cache line by set/way */
			asm volatile ("	mcr p15, 0, %0, c7, c6, 2"
					: : "r" (setway));
		}
	}
	/* DSB to make sure the operation is complete */
	CP15DSB;
}

static void v7_maint_dcache_level_setway(unsigned int level, unsigned int operation)
{
	unsigned int ccsidr;
	unsigned int num_sets, num_ways, log2_line_len, log2_num_ways;
	unsigned int way_shift;

	set_csselr(level, ARMV7_CSSELR_IND_DATA_UNIFIED);

	ccsidr = get_ccsidr();

	log2_line_len = ((ccsidr & CCSIDR_LINE_SIZE_MASK) >>
				CCSIDR_LINE_SIZE_OFFSET) + 2;
	/* Converting from words to bytes */
	log2_line_len += 2;

	num_ways  = ((ccsidr & CCSIDR_ASSOCIATIVITY_MASK) >>
			CCSIDR_ASSOCIATIVITY_OFFSET) + 1;
	num_sets  = ((ccsidr & CCSIDR_NUM_SETS_MASK) >>
			CCSIDR_NUM_SETS_OFFSET) + 1;
	/*
	 * According to ARMv7 ARM number of sets and number of ways need
	 * not be a power of 2
	 */
	log2_num_ways = log_2_n_round_up(num_ways);

	way_shift = (32 - log2_num_ways);
	if (operation == ARMV7_DCACHE_INVAL_ALL) {
		v7_inval_dcache_level_setway(level, num_sets, num_ways,
				      way_shift, log2_line_len);
	}
	else if (operation == ARMV7_DCACHE_CLEAN_INVAL_ALL) {
		v7_clean_inval_dcache_level_setway(level, num_sets, num_ways,
						   way_shift, log2_line_len);
	}
}

void v7_maint_dcache_all(unsigned int operation)
{
	unsigned int level, cache_type, level_start_bit = 0;

	unsigned int clidr = get_clidr();

	for (level = 0; level < 7; level++) {
		cache_type = (clidr >> level_start_bit) & 0x7;
		if ((cache_type == ARMV7_CLIDR_CTYPE_DATA_ONLY) ||
		    (cache_type == ARMV7_CLIDR_CTYPE_INSTRUCTION_DATA) ||
		    (cache_type == ARMV7_CLIDR_CTYPE_UNIFIED))
			v7_maint_dcache_level_setway(level, operation);
		level_start_bit += 3;
	}
}

/* Invalidate TLB */
static void v7_inval_tlb(void)
{
	/* Invalidate entire unified TLB */
	asm volatile ("mcr p15, 0, %0, c8, c7, 0" : : "r" (0));
	/* Invalidate entire data TLB */
	asm volatile ("mcr p15, 0, %0, c8, c6, 0" : : "r" (0));
	/* Invalidate entire instruction TLB */
	asm volatile ("mcr p15, 0, %0, c8, c5, 0" : : "r" (0));
	/* Full system DSB - make sure that the invalidation is complete */
	CP15DSB;
	/* Full system ISB - make sure the instruction stream sees it */
	CP15ISB;
}

void arm_init_before_mmu(void)
{
	v7_maint_dcache_all(ARMV7_DCACHE_INVAL_ALL);
	v7_inval_tlb();
}

/*
    each time clean one cache line.
    A7
    icache cache line size : 32B
    dcache cache line size : 64B
    L2 : 64B
  */
void sys_dcache_flush_MVA(UINT32 start_adr, UINT32 end_adr)
{
    UINT32 i=0;
    UINT32* addr=NULL;

    CP15DSB;
    sync();
    for(addr=(UINT32*)((UINT32)start_adr&0xFFFFFFE0); addr<end_adr;addr+=8)
    {
        asm volatile("MOV r0, %0" : : "r"(addr));
        /* Clean and Invalidate D-Cache single entry using MVA format */
        asm volatile("MCR p15, 0, r0, c7, c14, 1");
        /* Invalidate I-Cache single entry using MVA format */
        //asm volatile("MCR p15, 0, r0, c7, c5, 1");
    }
    sync();
}

static int mmu_enabled(void)
{
	return get_cr() & CR_M;
}

void enable_dcache()
{
    unsigned int reg;

    reg = get_cr();	/* get control reg. */
    cp_delay();
    reg |= CR_C;	// enable d-cache
    set_cr(reg);
    cp_delay();    
}

void disable_mmu_cache()
{
	//#define FORCE_DISABLE_MMU
	unsigned int reg, cache_bit=0;

	reg = get_cr();
	cp_delay();

	//1. disable i-cache
	set_cr(reg & ~CR_I);
	cp_delay();
	
	reg = get_cr();
	cp_delay();
	
	//2. disable d-cache
	/* if cache isn;t enabled no need to disable */
	#ifndef FORCE_DISABLE_MMU
	if ((reg & CR_C) != CR_C)
		return;
	#endif
	/* if disabling data cache, disable mmu too */
	cache_bit |= CR_C;
	cache_bit |= CR_M;
	v7_maint_dcache_all(ARMV7_DCACHE_CLEAN_INVAL_ALL);
	set_cr(reg & ~cache_bit);
}

void disable_dcache()
{
	unsigned int reg, cache_bit=0;

	reg = get_cr();
	cp_delay();
	
	//2. disable d-cache
	/* if cache isn;t enabled no need to disable */
	if ((reg & CR_C) != CR_C)
		return;
	/* if disabling data cache, disable mmu too */
	cache_bit |= CR_C;
	v7_maint_dcache_all(ARMV7_DCACHE_CLEAN_INVAL_ALL);
	set_cr(reg & ~cache_bit);

}
