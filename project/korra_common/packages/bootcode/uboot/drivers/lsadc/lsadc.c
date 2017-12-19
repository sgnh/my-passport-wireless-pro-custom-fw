#include <common.h>
#include <asm/arch/rbus/iso_reg.h>
#include <platform_lib/board/lsadc.h>
#include <asm/arch/io.h>

/*========================Functions===============================*/
void lsadc_last_init(void)
{
#if defined(CONFIG_RTD299X) // (wilma+ 2013/06/29)
	rtd_outl(ST_LSADC_CTRL_reg,0x16100000);  //Digital setting
	rtd_outl(ST_LSADC_CTRL_reg,0x16100001);  //Digital Enable (last enable)
#endif	
}

int lsadc_init(int index, int voltage_mode)
{
#if defined(CONFIG_RTD299X) // (wilma+ 2013/06/29)	
	st_lsadc_ctrl_RBUS st_lsadc_ctrl_reg;
	st_pad0_RBUS st_pad0_reg;

	if (index >= 8) {
		return -1;
	}

	rtd_outl(ST_LSADC_ANALOG_CTRL_reg, 0x00010101);

	udelay(1000);
	st_lsadc_ctrl_reg.regValue = rtd_inl(ST_LSADC_CTRL_reg);
	if (st_lsadc_ctrl_reg.enable != 0) {
		st_lsadc_ctrl_reg.enable = 0;
		rtd_outl(ST_LSADC_CTRL_reg, st_lsadc_ctrl_reg.regValue);
	}

	st_pad0_reg.regValue = 0;
	st_pad0_reg.pad0_active = 1;
	st_pad0_reg.pad0_sw = index;

	if (voltage_mode) {	// if voltage mode
		st_pad0_reg.pad0_ctrl = 0;
	}
	else {
		st_pad0_reg.pad0_ctrl = 1;
	}

	rtd_outl(ST_PAD0_reg + index * 4, st_pad0_reg.regValue);
#endif
	return 0;
}


int lsdac_get(int index)
{
	
#if defined(CONFIG_RTD299X) // (wilma+ 2013/06/29)	
	st_lsadc_ctrl_RBUS st_lsadc_ctrl_reg;
	st_pad0_RBUS st_pad0_reg;

	if (index >= 8) {
		return -1;
	}

	st_lsadc_ctrl_reg.regValue = rtd_inl(ST_LSADC_CTRL_reg);
	if (st_lsadc_ctrl_reg.enable == 0) {
		st_lsadc_ctrl_reg.enable = 1;
		rtd_outl(ST_LSADC_CTRL_reg, st_lsadc_ctrl_reg.regValue);
	}

	st_pad0_reg.regValue = rtd_inl(ST_PAD0_reg + index * 4);

	//printf("%d = %x %x\n", index, rtd_inl(ST_PAD0_reg + index * 4), rtd_inl(0xb8061500));
	//printf("%x \n", rtd_inl(0xb8061500));

	return st_pad0_reg.adc_val0;
#endif	
	return 0;
}

