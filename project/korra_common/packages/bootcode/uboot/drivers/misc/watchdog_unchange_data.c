#include <common.h>
#include <asm/arch/system.h>
#include <wakeup.h>

//
//
//   b80612c ~ b806124 is used by ROM code
//
//

int  wd_unchage_data_set_bootcode_enter_rescue(void)
{

    rtd_outl(0xb8060120, 0x2379DCBA);
    return 0;
}

E_BOOTTYPE wd_unchange_data_get_boottype(void) {

	printf("b8060120 = %x\n", rtd_inl(0xb8060120));
    	if (rtd_inl(0xb8060120) == 0x2379DCBA) {
			printf("AP tell to resuce mode\n");
		return BOOTTYPE_NATIVE_RESCUE;
	}
	return BOOTTYPE_COMPLETE;
}

void  wd_unchange_data_clear_boottype(void) {

       rtd_outl(0xb8060120, 0);
}

