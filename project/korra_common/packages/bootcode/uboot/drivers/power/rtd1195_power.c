#include <common.h>
#include <asm/arch/io.h>
#include <platform_lib/board/power.h>
#include <asm/arch/fw_info.h>

struct power_saving_config
{
	unsigned int magic;
	char power_down_SDIO;
	char power_down_GSPI;
	char power_down_eMMC;
	char power_down_CardReader;
	char power_down_CP_RNG;
	char power_down_MD;
	char power_down_AE;
	char power_down_VCPU_VE1_VE2_GPU;
	char power_down_VO_TVE;
	char power_down_VideoDAC_A; //fw:power_down_VideoDAC_AtoC;
	char power_down_TP;
	char power_down_SE;
	char power_down_HDMITx_MHLTx;
	char power_down_Audio_I2S;
	char power_down_AudioDAC;
	char power_down_SPDIF;
	char power_down_HDMIRx_MHLRx;
	char power_down_LVDS;
	char power_down_MIPI;
	char power_down_LSADC;
	char power_down_ALL_AV;
	char power_down_ETN;
	char power_down_VFD;
	char power_down_CBUS;
	char power_down_CEC;
	char power_down_IR;
	char power_down_reserved1;
	char power_down_reserved2;

};

#define POWER_SAVING (0x18070000 + 0x1200)  // 										 
static struct power_saving_config * pconfig = NULL;


void SDIO_power_off(void)
{
	debug("SDIO off\n");
	//Turn off SDIO (clock from USB)
	rtd_clearbits(0x18000004,0x1000);				//SDIO reset
	rtd_clearbits(0x1800000c,0x44000000);	//SDIO/SDIO_IP clock disable
}

void GSPI_power_off(void)
{	
	debug("GSPI off\n");
	//Turn off GSPI
	rtd_clearbits(0x18000000,0x8);				//GSPI reset
	rtd_clearbits(0x1800000c,0x8);				//GSPI clock disable
}

void eMMC_power_off(void)
{	
	debug("eMMC off\n");
	//Turn off eMMC
	rtd_clearbits(0x18000004,0x800);			//eMMC reset
	rtd_clearbits(0x1800000c,0x11000000);	//eMMC/eMMC_IP clock disable
	rtd_clearbits(0x180001f4,0x1);				//eMMC clock disable
}

void CardReader_power_off(void)
{	
	debug("CardReader off\n");
	//Turn off Card Reader
	//rtd_clearbits(0x18000004,0x400);			//Card Reader reset
	//rtd_clearbits(0x1800000c,0x82000000);	//Card Reader/SD_IP clock disable
	rtd_clearbits(0x180001e4,0x1);				//Card Reader clock disable
}

void CP_RNG_power_off(void)
{	
	debug("CP_RNG off\n");
	//Turn off CP, RNG
	rtd_clearbits(0x18000000,0x2000000);	//CP reset
	rtd_clearbits(0x1800000c,0x80000);	//CP clock disable
	rtd_clearbits(0x18000000,0x2);				//RNG reset
}

void MD_power_off(void)
{	
	debug("MD off\n");
	//Turn off MD
	rtd_clearbits(0x18000000,0x4000000);	//MD reset
	rtd_clearbits(0x1800000c,0x100000);		//MD clock disable
}

void AE_power_off(void)
{	
	debug("AE off\n");
	//Turn off AE
	rtd_clearbits(0x18000000,0x10000000);	//AE reset
}

void VCPU_VE1_VE2_GPU_power_off(void)
{	
	debug("VCPU_VE1_VE2_GPU off\n");
	//Turn off VCPU VE1,VE2,GPU
	rtd_clearbits(0x18000000,0x60000);		//VE1 264.JPEG reset
	rtd_clearbits(0x1800000c,0x3000);			//VE1 264.JPEG clock disable
	rtd_clearbits(0x18000000,0x20);				//VE2 265 reset
	rtd_clearbits(0x1800000c,0x20000000);	//VE2 265 clock disable
	rtd_outl(0x18000118,0x00000004);		//VCPU PLL off
	rtd_clearbits(0x18000000,0x00010000);	//GPU reset
	rtd_clearbits(0x1800000c,0x00000800);	//GPU clock disable
	rtd_setbits(0x180001c4,0x4);					//GPU PLL off
}

void VO_TVE_power_off(void)
{	
	debug("VO_TVE off\n");
	//Turn off display VO, TVE
	rtd_clearbits(0x18000000,0x100000);		//VO reset
	rtd_clearbits(0x1800000c,0x8000);			//VO clock disable
	rtd_clearbits(0x18000000,0x80000);		//TVE reset
	rtd_clearbits(0x1800000c,0x4000);			//TVE clock disable
	rtd_outl(0x18000180,0x4);				//Display SD2 (DDSB)PLL off 432
	//rtd_clearbits(0x18000128)=0x00000004		//Display SD1(DDSA) PLL can't turn off 432 (NAND Cardreader)
}

void VideoDAC_A_power_off(void)
{	
	debug("VideoDAC_A off\n");
	//Turn off Video DAC A
	//rtd_clearbits(0x18018200,0x780000);		//A~C
	rtd_clearbits(0x180183a0,0xc0000000);	//current DAC disable
	//rtd_outl(0x180188bc,0x7);				//power down
}

void TP_power_off(void)
{	 
	debug("TP off\n");
	//Turn off TP
	rtd_clearbits(0x18000000,0x8000000);	//TP reset
	rtd_clearbits(0x1800000c,0x200000);		//TP clock disable
}

void SE_power_off(void)
{	
	debug("SE off\n");
	//Turn off SE
	rtd_clearbits(0x18000000,0x400000);		//SE reset
	rtd_clearbits(0x1800000c,0x20000);		//SE clock disable
}

void HDMITx_power_off(void)
{	
	debug("HDMITx/MHLTx off\n");
	//Turn off HDMI Tx
	rtd_clearbits(0x18000000,0x1000);			//HDMI Tx reset
	rtd_clearbits(0x1800000c,0x100);			//HDMI Tx clock disable
	rtd_clearbits(0x18000010,0x100000);		//AO for HDMI clock disable
	rtd_outl(0x18000190,0x0);				//HDMI Tx MAC,PHY power down
	rtd_clearbits(0x18007088,0xc);		//AO for HDMI clock disable

}

void Audio_I2S_power_off(void)
{		
	debug("Audio_I2S off\n");
	//Turn off Audio I2S in/out
	rtd_clearbits(0x18000010,0xc00000);		//I2S clock disable
}

void AudioDAC_power_off(void)
{
	debug("AudioDAC off\n");
	//Turn off Audio DAC
	rtd_outl(0x18006604,0xaaa00);		//AO DAC power down
	_sync();
	rtd_clearbits(0x18000010,0xe0000);		//Audio DAC (da,mod,codec) clock disable
}

void SPDIF_power_off(void)
{	
	debug("SPDIF off\n");
	//Turn off SPDIF
	rtd_clearbits(0x18000010,0x200000);		//SPDIF
}

void HDMIRx_power_off(void)
{	
	debug("HDMIRx/MHLRx off\n");
	//Turn off HDMI Rx (flow PLL?)
	rtd_clearbits(0x18000000,0x800);			//HDMI Rx reset
	rtd_clearbits(0x1800000c,0x2);				//HDMI Rx clock disable
	rtd_outl(0x1800ff20,0x0);     				//Turn off HDMI Rx enable
}

void LVDS_power_off(void)
{	
	debug("LVDS off\n");
	//Turn off LVDS (flow, PLL?)
	rtd_clearbits(0x18000000,0x200000);	//LVDS reset
	rtd_clearbits(0x1800000c,0x10000);		//LVDS clock disable
	rtd_setbits(0x180000024,0x420000);	//LVDS clock selection PLLLVDS
}

void MIPI_power_off(void)
{	
	debug("MIPI off\n");
	//Turn off MIPI
	rtd_clearbits(0x18000000,0x40000000);//MIPI reset
	rtd_clearbits(0x1800000c,0x8000000);	//MIPI clock disable
	//Turn off MIPI PHY
//	rtd_outl(0x18004074, 0x0);				
//	rtd_outl(0x18004080, 0x0);
}

void LSADC_power_off(void)
{
	debug("LSADC off\n");
	//Turn off LSADC
	rtd_outl(0x1801bc28,0x0);					//LSADC power down
}

void ALL_AV_power_off(void)
{	
	debug("all AV off\n");
	//Turn off all AV
	rtd_clearbits(0x18000000,0x8000);			//AIO reset
	rtd_clearbits(0x1800000c,0x400);			//AIO clock disable
}
//ISO	block

void ETN_power_off(void)
{	
	debug("ETN off\n");		
	//Turn off ETN & PHY
	rtd_clearbits(0x18007088,0x600);			//ISO ETN ISO reset
	rtd_clearbits(0x1800708c,0x1800);			//ISO ETN clock disable
	rtd_clearbits(0x18000000,0x4000);			//CRT ETN reset
	rtd_clearbits(0x1800000c,0x200);			//CRT ETN clock disable
	rtd_outl(0x1800705c,0x0);				//ISO APHY/DPHY isolation
	rtd_outl(0x18007074,0x09d81153);	//Turn off PLL_ETN
}

void VFD_power_off(void)
{	
	debug("VFD off\n");	
	//Turn off VFD
	rtd_clearbits(0x18007088,0x1);				//ISO VFD ISO reset
	rtd_clearbits(0x1800708c,0x2);				//ISO VFD clock disable
}

void CBUS_power_off(void)
{
	debug("CBUS off\n");
	//Turn off CBUS
	rtd_clearbits(0x18007088,0x2060);			//ISO CBUS reset
	rtd_clearbits(0x1800708c,0x78);				//ISO CBUS clock disable
	//Turn off CBUS Tx Phy
	rtd_outl(0x180370d0, 0x03900000);
}

void CEC_power_off(void)
{
	debug("CEC off\n");
	//Turn off CEC
	rtd_clearbits(0x18007088,0xc);			//ISO CEC reset
	rtd_clearbits(0x1800708c,0x4);				//ISO CEC clock disable
	//Turn off CEC Rx
	rtd_outl(0x18037200, 0x0f14ca1f);		
	rtd_outl(0x18037204, 0x05);
}

void IR_power_off(void)
{
	rtd_clearbits(0x18007088,0x2);				//ISO IR reset
}

void Enhance_Wifi_storage(void)
{
	debug("Enhance Wifi storage \n");
//	rtd_outl(0x18000110,0x4);				//ACPU PLL
	rtd_outl(0x18000124,0xa);				//AUD 1A/2A
	rtd_outl(0x180001C4,0x4);				//GPU PLL OEB
#if defined(CONFIG_SYS_RTK_EMMC_FLASH) || defined(CONFIG_SYS_RTK_SPI_FLASH)
	rtd_outl(0x180001EC,0);					//SD PLL
#endif	
#if defined(CONFIG_SYS_RTK_NAND_FLASH) || defined(CONFIG_SYS_RTK_SPI_FLASH)
	rtd_outl(0x180001FC,0);					//EMMC PLL
	rtd_outl(0x180001f4, 0x078d7892);			//EMMC LDO
#endif	

#if defined(CONFIG_SYS_RTK_EMMC_FLASH) || defined(CONFIG_SYS_RTK_SPI_FLASH)
	rtd_outl(0x180001e0, 0x00380000); 			//SD LDO
	rtd_outl(0x180001e4, 0x078d7892);
#endif

}


void RTK_set_power_saving_config(void)
{
	
	struct power_saving_config temp;	
	pconfig =(struct power_saving_config *)POWER_SAVING;
	
	memset(&temp,0x0,sizeof(temp));		   	
	temp.magic = 0x65868380; //PSVA( power saving version A)
	
#ifdef CONFIG_POWER_DOWN_SDIO
	temp.power_down_SDIO =1;	
#endif

#ifdef CONFIG_POWER_DOWN_GSPI
	temp.power_down_GSPI =1;
#endif

#ifdef CONFIG_POWER_DOWN_eMMC
	temp.power_down_eMMC =1;
#endif

#ifdef CONFIG_POWER_DOWN_CardReader
	temp.power_down_CardReader =1;
#endif

#ifdef CONFIG_POWER_DOWN_CP_RNG
	temp.power_down_CP_RNG =1;
#endif

#ifdef CONFIG_POWER_DOWN_MD
	temp.power_down_MD =1;
#endif

#ifdef CONFIG_POWER_DOWN_AE
	temp.power_down_AE =1;
#endif

#ifdef CONFIG_POWER_DOWN_VCPU_VE1_VE2_GPU
	temp.power_down_VCPU_VE1_VE2_GPU =1;
#endif

#ifdef CONFIG_POWER_DOWN_VO_TVE
	temp.power_down_VO_TVE =1;
#endif

#ifdef CONFIG_POWER_DOWN_VideoDAC_A
	temp.power_down_VideoDAC_A =1;
#endif

#ifdef CONFIG_POWER_DOWN_TP
	temp.power_down_TP =1;
#endif

#ifdef CONFIG_POWER_DOWN_SE
	temp.power_down_SE =1;
#endif

#ifdef CONFIG_POWER_DOWN_HDMITx_MHLTx
	temp.power_down_HDMITx_MHLTx =1;
#endif

#ifdef CONFIG_POWER_DOWN_Audio_I2S
	temp.power_down_Audio_I2S =1;
#endif

#ifdef CONFIG_POWER_DOWN_AudioDAC
	temp.power_down_AudioDAC =1;
#endif

#ifdef CONFIG_POWER_DOWN_SPDIF
	temp.power_down_SPDIF =1;
#endif 

#ifdef CONFIG_POWER_DOWN_HDMIRx_MHLRx
	temp.power_down_HDMIRx_MHLRx =1;
#endif

#ifdef CONFIG_POWER_DOWN_LVDS
	temp.power_down_LVDS =1;
#endif

#ifdef CONFIG_POWER_DOWN_MIPI
	temp.power_down_MIPI =1;
#endif

#ifdef CONFIG_POWER_DOWN_LSADC
   temp.power_down_LSADC =1;
#endif

#ifdef CONFIG_POWER_DOWN_ALL_AV
   temp.power_down_ALL_AV =1;
#endif

//ISO	block
#ifdef CONFIG_POWER_DOWN_ETN
	 temp.power_down_ETN =1;
#endif

#ifdef CONFIG_POWER_DOWN_VFD
	temp.power_down_VFD =1;
#endif

#ifdef CONFIG_POWER_DOWN_CBUS
	 temp.power_down_CBUS =1;
#endif

#ifdef CONFIG_POWER_DOWN_CEC
	temp.power_down_CEC =1;
#endif

#ifdef CONFIG_POWER_DOWN_IR
	temp.power_down_IR =1;
#endif
	
	memcpy(pconfig, &temp, sizeof(temp) );
	flush_cache(pconfig, sizeof(temp));	
}


void RTK_power_saving(void)
{
#ifdef CONFIG_POWER_DOWN_SDIO
	SDIO_power_off();	
#endif

#ifdef CONFIG_POWER_DOWN_GSPI
	GSPI_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_eMMC
	eMMC_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_CardReader
	CardReader_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_CP_RNG
	CP_RNG_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_MD
	MD_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_AE
	AE_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_VCPU_VE1_VE2_GPU
	VCPU_VE1_VE2_GPU_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_VO_TVE
	VO_TVE_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_VideoDAC_A
	VideoDAC_A_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_TP
	TP_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_SE
	SE_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_HDMITx_MHLTx
	HDMITx_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_Audio_I2S
	Audio_I2S_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_AudioDAC
	AudioDAC_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_SPDIF
	SPDIF_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_HDMIRx_MHLRx
	HDMIRx_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_LVDS
	LVDS_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_MIPI
	MIPI_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_LSADC
   LSADC_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_ALL_AV
   ALL_AV_power_off();
#endif

//ISO	block
#ifdef CONFIG_POWER_DOWN_ETN
	ETN_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_VFD
	VFD_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_CBUS
	CBUS_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_CEC
	CEC_power_off();
#endif

#ifdef CONFIG_POWER_DOWN_IR
	IR_power_off();
#endif

#ifdef CONFIG_BOARD_QA_RTD1195_WIFI_STORAGE
	Enhance_Wifi_storage();
#endif	

	RTK_set_power_saving_config();
	
}
