#include <asm/arch/rbus/iso_reg.h>
#include <linux/input.h>
#include <common.h>


struct venus_key {
	u32 scancode;
	u32 keycode;
};

static struct venus_key rtk_mk5_tv_keys[] = {
	{0x18, KEY_POWER},			//POWER
//	{0x5A, KEY_SELECT},			//SOURCE
//	{0x58, KEY_CYCLEWINDOWS},	//PIP
//	{0x1A, KEY_TV},				//TV SYSTEM
	{0x14, KEY_HOME},			//HOME
//	{0x56, KEY_OPTION},			//OPTION MENU
//	{0x54, KEY_INFO},				//MEDIA_INFO
//	{0x19, KEY_REPLY},			//REPEAT
//	{0x57, KEY_BACK},			//RETURN
//	{0x55, KEY_PLAY},				//PLAY/PAUSE
//	{0x17, KEY_STOP},			//STOP
//	{0x15, KEY_ZOOM},			//ZOOM_IN
//	{0x4F, KEY_REWIND},			//FR
	{0x4D, KEY_UP},				//UP
//	{0x16, KEY_FASTFORWARD},	//FF
	{0x0C, KEY_LEFT},				//LEFT
//	{0x4C, KEY_OK},				//OK
	{0x0E, KEY_RIGHT},			//RIGHT
//	{0x08, KEY_PREVIOUS},		//PREVIOUS
	{0x48, KEY_DOWN},			//DOWN
//	{0x09, KEY_NEXT},			//NEXT
	{0x4B, KEY_VOLUMEDOWN},		//VOL-
	{0x49, KEY_VOLUMEUP},		//VOL+
//	{0x0B, KEY_TOUCHPAD_OFF},	//CURSOR
//	{0x0A, KEY_TOUCHPAD_ON},	// GESTURE
};

static struct venus_key Konka_tv_keys[] = {
//	{0x18, KEY_GREEN},			
//	{0x5A, KEY_SELECT},			//SOURCE
//	{0x58, KEY_CYCLEWINDOWS},	//PIP
//	{0x1A, KEY_TV},				//TV SYSTEM
//	{0x14, KEY_HOME},			//HOME
//	{0x56, KEY_OPTION},			//OPTION MENU
//	{0x54, KEY_INFO},				//MEDIA_INFO
//	{0x19, KEY_YELLOW},			
//	{0x57, KEY_BACK},			//RETURN
//	{0x55, KEY_PLAY},				//PLAY/PAUSE
//	{0x17, KEY_STOP},			//STOP
//	{0x15, KEY_ZOOM},			//ZOOM_IN
//	{0x4F, KEY_REWIND},			//FR
	{0x1C, KEY_UP},				//UP
//	{0x16, KEY_FASTFORWARD},	//FF
	{0x0D, KEY_LEFT},				//LEFT
//	{0x4C, KEY_OK},				//OK
	{0x1D, KEY_RIGHT},			//RIGHT
//	{0x08, KEY_PREVIOUS},		//PREVIOUS
	{0x1E, KEY_DOWN},			//DOWN
//	{0x09, KEY_NEXT},			//NEXT
//	{0x4B, KEY_VOLUMEDOWN},		//VOL-
//	{0x49, KEY_VOLUMEUP},		//VOL+
//	{0x0B, KEY_TOUCHPAD_OFF},	//CURSOR
//	{0x0A, KEY_TOUCHPAD_ON},	// GESTURE
};

unsigned int IR_Parsing_key(void)
{
	
	unsigned int scan_code=0;
	int i;
	
	scan_code =(0x00ff0000 & get_IR_RP_reg)>> 16;
	debug("scan_code=%x\n",scan_code);
	
#if defined(CONFIG_IR_KK_Y261_PROTOCOL)
	for(i=0;i<sizeof(Konka_tv_keys)/sizeof(struct venus_key);i++)
	 {
	 		if(scan_code == Konka_tv_keys[i].scancode)
	 		{
	 			debug("Konka_tv_keys[%d].keycode=%d\n",i,Konka_tv_keys[i].keycode);
	 			return Konka_tv_keys[i].keycode;
	 		}		 	
	 }	
		
#else	 
	 for(i=0;i<sizeof(rtk_mk5_tv_keys)/sizeof(struct venus_key);i++)
	 {
	 		if(scan_code == rtk_mk5_tv_keys[i].scancode)
	 		{
	 			debug("rtk_mk5_tv_keys[%d].keycode=%d\n",i,rtk_mk5_tv_keys[i].keycode);
	 			return rtk_mk5_tv_keys[i].keycode;
	 		}		 	
	 }	
#endif	 
	 return 0;	 
}


unsigned int IR_Protocol_Selection(void)
{
	unsigned int psr_val=0;
	
#ifdef CONFIG_IR_NEC_PROTOCOL   	
	// NEC
	// IRSBC=20uS(50KHz) sampling rate
	// IRRBL=>(9mS*80%=IRRBL*IRSBC*4)=>0x5a
	// IRRML=>(560uS*80%=IRRML*IRSBC)=>0x16
	// IRRDZL=>((1.12mS-560uS)*80%=IRRDZL*IRSBC)=>0x16
	// IRRDOL=>((2.25mS-560uS)*80%=IRRDOL*IRSBC)=>0x43

	psr_val = (IR_PSR_IRRBL(0x5a)| IR_PSR_IRRML(0x16)|IR_PSR_IRRDZL(0x16) | IR_PSR_IRRDOL(0x43));

#elif defined(CONFIG_IR_SONY_PROTOCOL)
	// SONY
	// IRSBC=20uS(50KHz) sampling rate
	// IRRBL=>(2.4mS*80%=IRRBL*IRSBC*4)=>0x18
	// IRRML=>(600uS*80%=IRRML*IRSBC)=>0x18
	// IRRDZL=>((1.2mS-600uS)*80%=IRRDZL*IRSBC)=>0x18
	// IRRDOL=>((1.8mS-600uS)*80%=IRRDOL*IRSBC)=>0x30
	psr_val = (IR_PSR_IRRBL(0x18)| IR_PSR_IRRML(0x18)|IR_PSR_IRRDZL(0x18) | IR_PSR_IRRDOL(0x30));

#elif defined(CONFIG_IR_RC5_PROTOCOL)

	psr_val = (IR_PSR_IRRBL(0x0)| IR_PSR_IRRML(0x23)|IR_PSR_IRRDZL(0x23) | IR_PSR_IRRDOL(0x23));

#elif defined(CONFIG_IR_RC6_PROTOCOL)

	psr_val = (IR_PSR_IRRBL(0x1a)| IR_PSR_IRRML(0x0e)|IR_PSR_IRRDZL(0x0e) | IR_PSR_IRRDOL(0x0e));
	
#elif defined(CONFIG_IR_KK_Y261_PROTOCOL)

	psr_val = (IR_PSR_IRRBL(0x1e)| IR_PSR_IRRML(0x14)|IR_PSR_IRRDZL(0x3c) | IR_PSR_IRRDOL(0x64));	

#endif	
	
	return psr_val;
}

unsigned int IR_Protocol_Extension(void)
{
	unsigned int per_val=0;
	
#ifdef CONFIG_IR_NEC_PROTOCOL   	
	// NEC
	// IRRDL=>0x1
	// IRRRL=>(2.25mS*80%=IRRRL*IRSBC*4)=>0x16
	// IRRSL=>(4.5mS*80%=IRRSL*IRSBC*4)=>0x2d

	per_val = (IR_PER_IRRDL(0x1) |IR_PER_UP_IRRRL(0x16) | IR_PER_IRRSL(0x2d));

#elif defined(CONFIG_IR_SONY_PROTOCOL)
	// SONY
	// IRRDL=>0x1
	// IRRRL=>(0mS*80%=IRRRL*IRSBC*4)=>0x0
	// IRRSL=>(600uS*80%=IRRSL*IRSBC*4)=>0x6

	per_val = (IR_PER_IRRDL(0x1) |IR_PER_UP_IRRRL(0x0) | IR_PER_IRRSL(0x6));

#elif defined(CONFIG_IR_RC5_PROTOCOL)

	per_val = 0;

#elif defined(CONFIG_IR_RC6_PROTOCOL)

	per_val = (IR_PER_IRRDL(0x02) |IR_PER_UP_IRRRL(0x0) | IR_PER_IRRSL(0x8));
	
#elif defined(CONFIG_IR_KK_Y261_PROTOCOL)

	per_val = (IR_PER_IRRDL(0x03) |IR_PER_UP_IRRRL(0x0) | IR_PER_IRRSL(0x1a));		

#endif	
	
	return per_val;
}

unsigned int IR_Sampling_Frequency(void)
{
	unsigned int sample_feq=0;

#ifdef CONFIG_IR_NEC_PROTOCOL   	
	//IR Sampling Frequency, 50kHz
	sample_feq = 0x21b;

#elif defined(CONFIG_IR_SONY_PROTOCOL)
	//sample clock 33MHz/660=50kHz
	sample_feq = 0x293;	
	
#elif defined(CONFIG_IR_RC5_PROTOCOL)

	sample_feq = 0x293;

#elif defined(CONFIG_IR_RC6_PROTOCOL)

	sample_feq = 0x293;
	
#elif defined(CONFIG_IR_KK_Y261_PROTOCOL)

	sample_feq = 0x293;

#endif	
	
	return sample_feq ;
}

unsigned int IR_Control(void)
{
	unsigned int control_val=0;

#ifdef CONFIG_IR_NEC_PROTOCOL   
	//	set Modulation length adjustable disable
	//  Data valid interrupt enable
	//  IR RX endian select is First received bit is in the LSB of FIFO
	//  IRRC unit enable
	//  Coding mode is "length"
	//  Burst mode enable (9ms AGC burst)
	//  Data phase mode is "normal"
	//  Data number is 32 bits	

	//control_val = 0x3df;
	control_val = 0x1df; //change endian

#elif defined(CONFIG_IR_SONY_PROTOCOL)
	// 	set Modulation length adjustable enable
	//	Data valid interrupt disable
	//  IR RX endian select is First received bit is in the LSB of FIFO
	//  IRRC unit enable
	//  Coding mode is "length"
	//  Burst mode enable (2.4ms AGC burst)
	//  Data phase mode is "normal"
	//  Data number is 12 bits
	
	control_val = 0xbcb ;	
	
#elif defined(CONFIG_IR_RC5_PROTOCOL)

	control_val = 0x30c;

#elif defined(CONFIG_IR_RC6_PROTOCOL)

	control_val = 0x715;
	
#elif defined(CONFIG_IR_KK_Y261_PROTOCOL)

	control_val = 0x7cf;	  
	
#endif	
	
	return control_val ;
}

void IR_init(void)
{
	unsigned int psr_val,per_val,sample_feq,control_val;
	//-------- for NEC & Sample Clock Rate = 50KHz --------
	//Each pulse is a 560μs long 38kHz carrier burst (about 21 cycles). 
	//A logical "1" takes 2.25ms to transmit, while a logical "0" is only half of that, being 1.125ms.


	set_SOFT_RESET_reg(get_SOFT_RESET_reg | SOFT_RESET_rstn_ir_mask);//rstn_ir
	set_CLOCK_ENABLE_reg(get_CLOCK_ENABLE_reg | CLOCK_ENABLE_clk_en_misc_ir_mask); //clock enable
	set_MUXPAD0_reg(get_MUXPAD0_reg |0x40);			//muxpad mux to ir_RX port
	set_IR_CR_reg(get_IR_CR_reg | IR_CR_IRSR_mask);   	//Software reset
	
	debug("get_SOFT_RESET_reg=0x%x\n,",get_SOFT_RESET_reg);
	debug("get_CLOCK_ENABLE_reg=0x%x\n,",get_CLOCK_ENABLE_reg);
	debug("get_MUXPAD0_reg=0x%x\n,",get_MUXPAD0_reg);
	debug("get_IR_CR_reg=0x%x\n,",get_IR_CR_reg);
	
	psr_val= IR_Protocol_Selection();	                               
	set_IR_PSR_reg(psr_val); 
	debug("get_IR_PSR_reg=0x%x\n,",get_IR_PSR_reg);
	
	per_val= IR_Protocol_Extension();
	set_IR_PER_reg( per_val); 
	debug("get_IR_PER_reg=0x%x\n,",get_IR_PER_reg);
		
	sample_feq = IR_Sampling_Frequency();
	set_IR_SF_reg(sample_feq);  
	debug("get_IR_SF_reg=0x%x\n,",get_IR_SF_reg);
	
	control_val = IR_Control();
	set_IR_CR_reg(control_val);
	debug("get_IR_CR_reg=0x%x\n,",get_IR_CR_reg);

	return ;
}
	