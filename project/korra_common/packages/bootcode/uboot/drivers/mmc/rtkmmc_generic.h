#ifndef __RTKMMC_GENERIC_H__
#define __RTKMMC_GENERIC_H__

#ifdef __RTKMMC_GENERIC_C__
	#define EXTERN_CALL
#else
	#define EXTERN_CALL extern
#endif

#endif // end of CONFIG_GENERIC_MMC
