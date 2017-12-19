#include <common.h>
#include <asm/arch/rbus/iso_reg.h>
#include <asm/arch/io.h>
#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/pwm.h>

#define printf(fmt,args...)
#define N_MAX  4096
#define M_MAX  3
#define CONFIG_CPU_XTAL_FREQ 27000000

int pwm_init(int index, int pwm_freq_hz, int duty_max, int duty, int invert) {


	int i;

	//printf("int index 0x%x, int pwm_freq_hz 0x%x, int duty_max 0x%x, int duty 0x%x, int invert 0x%x", index, pwm_freq_hz, duty_max, duty, invert);
	long  source_clock, fclk, dutyMax, pwmFreqHz, error, error_best;
	unsigned short N, N_best = 0, M_best = 0;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
	pwm0_duty_set_RBUS 	pwm_duty_set_reg;
//	int regAddr =0 , regval = 0;

	if (index >= 8) return -1;

	printf("pwm_freq_hz = %d\n", pwm_freq_hz);
	source_clock = CONFIG_CPU_XTAL_FREQ;
	//fclk = duty_max * pwm_freq_hz;
	// fclk = (Crystal clock) / 2^M / (N+1)
	dutyMax = duty_max;
	pwmFreqHz = pwm_freq_hz;
	fclk = dutyMax  * pwmFreqHz;
	//printf("-- fclk = 0x%llx,  %lld, %lld\n", fclk, dutyMax, pwmFreqHz);

	error_best = fclk  + 1;
	for (i=0; i<=M_MAX; i++) {
		N = ((source_clock / ( 1 << i)) / fclk);
		//printf("-- N = 0x%x,  %lld, %lld\n", N, (source_clock / ( 1 << i) ), fclk);
		if (N == 0)
			N=1;
		if (N > 0x1000)
			continue;
		error = ABS((source_clock / ( 1 << i )) / (N), fclk);

		//printf("-- error = %lld, error_best = %lld\n", error,  error_best);
		if (error < error_best) {
			error_best = error;
			N_best = N-1;
			M_best = i;
		}
		//printf("-- N_best = 0x%x, M_best = 0x%x\n", N_best,  M_best);
	}

	printf("M = 0x%x\n", M_best);
	printf("N = 0x%x\n", N_best);






	pwm_timing_ctrl_reg.regValue = rtd_inl(PWM0_TIMING_CTRL_reg+ index * 12);
	pwm_timing_ctrl_reg.pwm0_cnt_mode = 1;
	pwm_timing_ctrl_reg.pwm0_ck_sel = 0;
	pwm_timing_ctrl_reg.pwm0_m = M_best;
	pwm_timing_ctrl_reg.pwm0_n = N_best;
	rtd_outl(PWM0_TIMING_CTRL_reg + index * 12, pwm_timing_ctrl_reg.regValue);
	//regAddr = PWM0_TIMING_CTRL_reg + index * 12;
	//regval = IoReg_Read32(regAddr);
	//printf("\033[1;32m reg 0x%x=0x%x\033[m\n", regAddr, regval);

	pwm_duty_set_reg.regValue = rtd_inl(PWM0_DUTY_SET_reg + index * 12);
	pwm_duty_set_reg.pwm0_totalcnt = duty_max;
	pwm_duty_set_reg.pwm0_dut = duty;
	rtd_outl(PWM0_DUTY_SET_reg + index * 12, pwm_duty_set_reg.regValue);
	//regAddr = PWM0_DUTY_SET_reg + index * 12;
	//regval = IoReg_Read32(regAddr);
	//printf("\033[1;32m reg 0x%x=0x%x\033[m\n", regAddr, regval);

	pwm_ctrl_reg.regValue = rtd_inl(PWM0_CTRL_reg + index * 12);
	pwm_ctrl_reg.pwm0_en = 1;
	pwm_ctrl_reg.pwm0l = (invert != 0);
	pwm_ctrl_reg.pwm0_ck = 1;
	pwm_ctrl_reg.pwm0_dut_8b = 0;
	rtd_outl(PWM0_CTRL_reg + index * 12, pwm_ctrl_reg.regValue);
	//regAddr = PWM0_CTRL_reg + index * 12;
	//regval = IoReg_Read32(regAddr);
	//printf("\033[1;32m reg 0x%x=0x%x\033[m\n", regAddr, regval);

	return 0;
}


int iso_pwm_init(int index, int pwm_freq_hz, int duty_max, int duty, int invert) {

	int i;



	//printf("int index 0x%x, int pwm_freq_hz 0x%x, int duty_max 0x%x, int duty 0x%x, int invert 0x%x", index, pwm_freq_hz, duty_max, duty, invert);
	long  source_clock, fclk, dutyMax, pwmFreqHz, error, error_best;
	unsigned short N, N_best = 0, M_best = 0;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
	pwm0_duty_set_RBUS 	pwm_duty_set_reg;

	if (index >= 2) return -1;
	source_clock = CONFIG_CPU_XTAL_FREQ;
	//fclk = duty_max * pwm_freq_hz;
	// fclk = (Crystal clock) / 2^M / (N+1)
	dutyMax = duty_max;
	pwmFreqHz = pwm_freq_hz;
	fclk = dutyMax  * pwmFreqHz;
	//printf("-- fclk = 0x%llx,  %lld, %lld\n", fclk, dutyMax, pwmFreqHz);

	error_best = fclk  + 1;
	for (i=0; i<=M_MAX; i++) {
		N = ((source_clock / ( 1 << i)) / fclk);
		//printf("-- N = 0x%x,  %lld, %lld\n", N, (source_clock / ( 1 << i) ), fclk);
		if (N == 0)
			N=1;
		if (N > 0x1000)
			continue;
		error = ABS((source_clock / ( 1 << i )) / (N), fclk);

		//printf("-- error = %lld, error_best = %lld\n", error,  error_best);
		if (error < error_best) {
			error_best = error;
			N_best = N-1;
			M_best = i;
		}
		//printf("-- N_best = 0x%x, M_best = 0x%x\n", N_best,  M_best);
	}

	printf("M = 0x%x\n", M_best);
	printf("N = 0x%x\n", N_best);

#if 0 //(wilma+ 2013/06/29)
	pwm_ctrl_reg.regValue = rtd_inl(ISO_PWM0_CTRL_reg + index * 12);
	pwm_ctrl_reg.pwm0l = (invert != 0);
	pwm_ctrl_reg.pwm0_ck = 1;
	pwm_ctrl_reg.pwm0_dut_8b = 0;
	pwm_ctrl_reg.pwm0_en = 1;//hardy20111125
	rtd_outl(ISO_PWM0_CTRL_reg + index * 12, pwm_ctrl_reg.regValue);


	pwm_timing_ctrl_reg.regValue = rtd_inl(ISO_PWM0_TIMING_CTRL_reg+ index * 12);
	pwm_timing_ctrl_reg.pwm0_ck_sel = 0;
	pwm_timing_ctrl_reg.pwm0_cnt_mode = 1;
	pwm_timing_ctrl_reg.pwm0_m = M_best;
	pwm_timing_ctrl_reg.pwm0_n = N_best;
	rtd_outl(ISO_PWM0_TIMING_CTRL_reg + index * 12, pwm_timing_ctrl_reg.regValue);


	pwm_duty_set_reg.regValue = rtd_inl(ISO_PWM0_DUTY_SET_reg + index * 12);
	pwm_duty_set_reg.pwm0_totalcnt = duty_max;
	pwm_duty_set_reg.pwm0_dut = duty;
	rtd_outl(ISO_PWM0_DUTY_SET_reg + index * 12, pwm_duty_set_reg.regValue);
#endif

	return 0;
}



int pwm_set(int index, int duty) {
	pwm0_duty_set_RBUS 	pwm_duty_set_reg;
	int duty_max;

	//printf("\033[1;31m %s: index = %d, duty = %d\033[m\n", __FUNCTION__, index, duty);
	if (index >= 8) return -1;

	pwm_duty_set_reg.regValue = rtd_inl(PWM0_DUTY_SET_reg + index * 12);
	duty_max = pwm_duty_set_reg.pwm0_totalcnt;

	if (duty >= duty_max) duty = duty_max;
	if (duty <= 0) duty = 0;
	pwm_duty_set_reg.pwm0_dut = duty;

	//printf("\033[1;31m pwm_duty_set_reg.pwm0_dut = %d\033[m\n", pwm_duty_set_reg.pwm0_dut);
	rtd_outl(PWM0_DUTY_SET_reg + index * 12, pwm_duty_set_reg.regValue);

	return 0;
}


int iso_pwm_set(int index, int duty) {


#if defined(CONFIG_RTD299X) // (wilma+ 2013/06/29)
	pwm0_duty_set_RBUS 	pwm_duty_set_reg;
	int duty_max;

	//printf("\033[1;31m %s: index = %d, duty = %d\033[m\n", __FUNCTION__, index, duty);
	if (index >= 8) return -1;

	pwm_duty_set_reg.regValue = rtd_inl(ISO_PWM0_DUTY_SET_reg + index * 12);
	duty_max = pwm_duty_set_reg.pwm0_totalcnt;

	if (duty >= duty_max) duty = duty_max;
	if (duty <= 0) duty = 0;
	pwm_duty_set_reg.pwm0_dut = duty;

	//printf("\033[1;31m pwm_duty_set_reg.pwm0_dut = %d\033[m\n", pwm_duty_set_reg.pwm0_dut);
	rtd_outl(ISO_PWM0_DUTY_SET_reg + index * 12, pwm_duty_set_reg.regValue);
#endif
	return 0;
}

#if 0 // rtd299x not support
int unipwm_init(int unimux_index , int index, int pwm_freq_hz, int duty_max, int duty, int invert) {
	if (unimux_index >= 8) return -1;
	if (index >= 2) return  -1;

	rtd_maskl(PIN_MUX_CTRL3_reg, ~(0xF << (unimux_index * 4)), (index<< (unimux_index * 4)));
	pwm_init(index, pwm_freq_hz, duty_max, duty, invert);
}

int iso_unipwm_init(int unimux_index , int index, int pwm_freq_hz, int duty_max, int duty, int invert) {
	if (unimux_index >= 2) return -1;
	if (index >= 2) return  -1;

	rtd_maskl(ISO_PIN_MUX_CTRL1_reg, ~(0x3 << (unimux_index * 2)), (index<< (unimux_index * 2)));
	iso_pwm_init(index, pwm_freq_hz, duty_max, duty, invert);
}

int unipwm_set(int unimux_index, int duty)
{        int index;
	if (unimux_index >= 8) return -1;


	index = (rtd_inl(PIN_MUX_CTRL3_reg)  >> (unimux_index * 4)) & 0x7;
	pwm_set(index, duty);
}
int iso_unipwm_set(int unimux_index , int duty) {

        int index;
	if (unimux_index >= 2) return -1;

	index = rtd_inl(PIN_MUX_CTRL3_reg)  >> (unimux_index * 4);
	iso_pwm_set(index, duty);

}
#endif


