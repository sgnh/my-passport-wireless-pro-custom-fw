#include <common.h>
#include <command.h>
//#include <platform_lib/board/gpio.h>
#include <asm/arch/io.h>
#include <asm/arch/rbus/misc_reg.h>
#include <asm/arch/rbus/iso_reg.h>

int pmx_do_pmxgpio(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int reg;
	int i; 

	for (i = 0; i < 20; i++){
		rtd_outl(GPDIR_reg, rtd_inl(GPDIR_reg) & (~(0x01 << i)));
		printf("[PMX] : ISOGPIO%2d = (%d)\n", 
			i, 
			(rtd_inl(GPDATI_reg) & (0x01 << i)) >> i);
	}


	return 0;
}
U_BOOT_CMD(
	pmxgpio, 1, 0,	pmx_do_pmxgpio, 
	"Primax GPIO test",
	""
);
