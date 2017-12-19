/************************************************************************
 *
 *  logo_disp_read_edid.c
 *
 *  get monitor mode (DVI/HDMI) from display device
 *
 *
 ************************************************************************/

/************************************************************************
 *  Include files
 ************************************************************************/
#include <common.h>
#include <extern_param.h>
#include <asm/arch/fw_info.h>
#include <asm/arch/io.h>
#include <asm/arch/system.h>
#include <asm/arch/rbus/iso_reg.h>
#include <asm/arch/rbus/cbus_tx_reg.h>
#include <asm/arch/rbus/crt_reg.h>
#include <asm/arch/rbus/hdmitx_reg.h>
#include <asm/arch/system.h>
#include "rtk_rpc.h"
#include "../i2c/rtk_i2c-lib.h"

#define S_OK         0
#define S_FALSE     -1

#define EDID_LENGTH 128

#define DEBUG__LOGO_DISP_READ_EDID
#ifndef DEBUG__LOGO_DISP_READ_EDID
#define printf(...) ;
#endif

#define I2C_Read(args...)                I2C_Read_EX(1, args)

static int vo_hdmi_mode = VO_HDMI_ON;

unsigned char EDID[EDID_LENGTH*2];
uchar checksum_128;
uchar checksum_256;


#define MHL_DEBUG 0

#if MHL_DEBUG
#define MHL_DBG(format, ...) printf(format , ## __VA_ARGS__)
#else
#define MHL_DBG(format, ...) 
#endif

/************************************************************************
 *  Implementation : Global functions
 ************************************************************************/
void dump_raw_edid(unsigned char *edid , int len)
{	
	int i;
	printf("RAW EDID:\n");
	
	for(i=1;i<=len;i++){	
					
		printf("0x%02x,",edid[i-1]);
			
			if(i%16==0)
				printf("\n");					
	}	  
}

static const unsigned char edid_header[] = {
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
};


int rtk_edid_header_is_valid(const unsigned char *raw_edid)
{
	int i, score = 0;

	for (i = 0; i < sizeof(edid_header); i++)
		if (raw_edid[i] == edid_header[i])
			score++;

	return score;
}

int rtk_edid_block_valid(unsigned char *raw_edid, int block)
{
	int i;
	unsigned char csum = 0;
	
	if (block == 0) {
		int score = rtk_edid_header_is_valid(raw_edid);
		if (score != 8)
			return 0;		
	}

	for (i = 0; i < EDID_LENGTH; i++)
		csum += raw_edid[i];
	if (csum) {
		printf("EDID checksum is invalid, remainder is %d\n", csum);		

		/* allow CEA to slide through, switches mangle this */
		if (raw_edid[0] != 0x02)
			return 0;
	}

	return 1;
}


int I2C_Read_Segment(unsigned char* Segment, int block, unsigned char* pData)
{	
	int ret;
	unsigned char SubAddr=EDID_LENGTH*block;
	
	ret=I2C_Write_EX(1, 0x30,1, Segment, NON_STOP);
			
	return I2C_Read(0x50,1,&SubAddr, EDID_LENGTH, pData , NON_STOP);
}

static int Read_EDID_block(int block, unsigned char *EDID_buf)
{

	unsigned char i2c_addr=0x50;
	unsigned char SubAddr=EDID_LENGTH*block;
	unsigned short nSubAddrByte=1;
	unsigned short nDataByte=EDID_LENGTH;
	unsigned char  Segment=block/2;
	

	if(block<=1)
		return I2C_Read(i2c_addr,nSubAddrByte,&SubAddr, nDataByte, EDID_buf, 0);	
	else
		return I2C_Read_Segment(&Segment,block,EDID_buf);
	
	return S_OK ;
}


static int Read_EDID(unsigned char *EDID_buf)
{
	int i;
	unsigned char buf[EDID_LENGTH];
	
	I2CN_Init(1);
	
	for (i = 0; i < 4; i++) {
	
		if(Read_EDID_block(0, buf))
			return S_FALSE;
			
		if (rtk_edid_block_valid(buf, 0))
			break;	
	}
	//dump_raw_edid(buf , EDID_LENGTH);
	
	memcpy(EDID_buf,buf,sizeof(buf));
	
	if (EDID_buf[0x7e] == 0)
	{
		vo_hdmi_mode = VO_DVI_ON;
		printf("DVI mode\n");		
		I2CN_UnInit(1);
		return 0;
	}
	
	memset(buf,0x0,sizeof(buf));	
	for (i = 0; i < 4; i++) {
	
		if(Read_EDID_block(1, buf))
			return S_FALSE;
			
		if (rtk_edid_block_valid(buf, 1))
			break;	
	}		
	//dump_raw_edid(buf,EDID_LENGTH);
	
	memcpy(EDID_buf+EDID_LENGTH,buf,sizeof(buf));
	
	//dump_raw_edid(EDID_buf , 256);	
	
#if 0
	for (i = 0; i < 4; i++) {
	
		if(Read_EDID_block(2, buf))
			return S_FALSE;
			
		if (rtk_edid_block_valid(buf, 2))
			break;	
	}		
	dump_raw_edid(buf,EDID_LENGTH);
	
	for (i = 0; i < 4; i++) 
	{
		if(Read_EDID_block(3, buf))
			return S_FALSE;
			
		if (rtk_edid_block_valid(buf, 3))
			break;	
	}		
	dump_raw_edid(buf,EDID_LENGTH);
#endif
				
	I2CN_UnInit(1);

	return 0;
}

static int HDMITx_HPD(void)
{
#if defined CONFIG_HDMITx_HPD_IGPIO_NUM	
	return getISOGPIO(CONFIG_HDMITx_HPD_IGPIO_NUM);
#else	
	return 0;
#endif		
}


#define SRC0 0x0
#define SRC1 0x1
#define SRC2 0x2
#define SRC3 0x3
#define SRC4 0x4
#define SRC5 0x5
#define SRC6 0x6
#define SRC7 0x7


void cbus_hw_init(void)
{

	printf("cbus init\n");
	rtd_outl(DISP_PLL_DIV2_reg , 0x01819100);
	rtd_outl(PLL_HDMI_reg , 0x00000013);
	rtd_outl(PLL_HDMI_reg , 0x0000001b);

}

void cbus_discovery(void)
{
    ulong start;
	ulong delay = 5000 ;
	unsigned int _800omhs_mask=0,_800omhs_unmask=0;
	unsigned int _1200omhs_mask=0,_1200omhs_unmask=0;
	int ret;
	
    printf("cbus discovery: \n");
	MHL_DBG("0x18037014 default=0x%x \n",get_CBUS_CTRL5_reg);
	MHL_DBG("0x180370D0 default=0x%x \n",get_PHY_CTRL_reg);
	MHL_DBG("0x180370d4 default=0x%x \n",get_CBUS_CTRL10_reg);
	
	
	rtd_setbits(CBUS_CTRL10_reg, CBUS_CTRL10_fw_r1k_det_en_mask);
	MHL_DBG("set 0x180370dc[1]=0x%x \n",get_CBUS_CTRL10_reg);
	
	
	if(GET_IC_VERSION()<0x00020000)
	{
		_800omhs_mask   = ~(PHY_CTRL_reg_mhl_r10k_test_tx_mask | //~bit14/28
							PHY_CTRL_reg_r1k_vth_sel_tx_mask); 
							
		_800omhs_unmask = ( PHY_CTRL_reg_en_bias_txrx_mask | //bit 17/29/31
							PHY_CTRL_reg_mhl_r1k_det_tx_mask | 
							PHY_CTRL_reg_mhl_bmos_en_tx_mask);	
		
		MHL_DBG("set 0x180370D0[31,29,~28,17,~14]=");	
		
	}		
	else
	{
		_800omhs_mask   = ~( PHY_CTRL_reg_r1k_vth_sel_tx_mask); //~bit 28	
														
		_800omhs_unmask = ( PHY_CTRL_reg_mhl_r10k_test_tx_mask | //bit 14/17/29/31
							PHY_CTRL_reg_en_bias_txrx_mask |	
							PHY_CTRL_reg_mhl_r1k_det_tx_mask | 
							PHY_CTRL_reg_mhl_bmos_en_tx_mask);	
							
		MHL_DBG("set 0x180370D0[31,29,~28,17,14]=");					
	}
		
	rtd_maskl(PHY_CTRL_reg, _800omhs_mask, _800omhs_unmask);						 							  
	MHL_DBG("0x%x \n",get_PHY_CTRL_reg);						  
   
	ret= rtd_readbits(PHY_STATUS_reg,PHY_STATUS_rego_mhl_r1k_det_tx_shift);
	printf("PHY_STATUS=0x%x; 0.8 connect %s\n",get_PHY_STATUS_reg,ret?"ok":"failed");
   
//======================================================================================
		
	if(GET_IC_VERSION()<0x00020000)	
	{
		_1200omhs_mask   = ~(PHY_CTRL_reg_mhl_r10k_test_tx_mask); //~bit 14 
							
		_1200omhs_unmask = ( PHY_CTRL_reg_en_bias_txrx_mask | //bit 17/28/29/31
							 PHY_CTRL_reg_r1k_vth_sel_tx_mask |	
							 PHY_CTRL_reg_mhl_r1k_det_tx_mask | 
							 PHY_CTRL_reg_mhl_bmos_en_tx_mask);	
		
		MHL_DBG("set 0x180370D0[31,29,28,17,~14]=");	
		
	}		
	else
	{
		_1200omhs_mask   = 0xffffffff; 
														
		_1200omhs_unmask = ( PHY_CTRL_reg_mhl_r10k_test_tx_mask | //bit 14/17/28/29/31
							 PHY_CTRL_reg_r1k_vth_sel_tx_mask |
							 PHY_CTRL_reg_en_bias_txrx_mask |	
							 PHY_CTRL_reg_mhl_r1k_det_tx_mask | 
							 PHY_CTRL_reg_mhl_bmos_en_tx_mask);	
							
		MHL_DBG("set 0x180370D0[31,29,28,17,14]=");					
	}

	rtd_maskl(PHY_CTRL_reg,	_1200omhs_mask,_1200omhs_unmask);						
    MHL_DBG("0x%x \n",get_PHY_CTRL_reg);
	
	ret= rtd_readbits(PHY_STATUS_reg,PHY_STATUS_rego_mhl_r1k_det_tx_shift);
	printf("PHY_STATUS=0x%x; 1.2 connect %s\n",get_PHY_STATUS_reg,ret?"ok":"failed");
	
 
//======================================================================================

	
	rtd_maskl(PHY_CTRL_reg,~( PHY_CTRL_reg_r1k_vth_sel_tx_mask | //~bit 28/29
							  PHY_CTRL_reg_mhl_r1k_det_tx_mask )	
						  , ( PHY_CTRL_reg_mhl_r10k_test_tx_mask| //bit 14/17/31
						      PHY_CTRL_reg_en_bias_txrx_mask|	
							  PHY_CTRL_reg_mhl_bmos_en_tx_mask));	
	
	MHL_DBG("\nset 0x180370D0[31,~29,~28,17,14]=0x%x \n",get_PHY_CTRL_reg);																								   
    
	rtd_setbits(CBUS_CTRL10_reg, CBUS_CTRL10_fw_r1k_det_mask);
	MHL_DBG("set 0x180370dc[0]=0x%x \n",get_CBUS_CTRL10_reg);
	    
	// check wake up pulse and discovery occur
    start = get_timer(0);
    while (get_timer(start) < delay) {
	
		debug("wait connect 0x%x(%x),0x%x,0x%x,0x%x\n",rtd_inl(CBUS_STATUS_reg),rtd_fld_get(get_CBUS_STATUS_reg,3,1),rtd_inl(PHY_CTRL_reg),rtd_inl(PHY_STATUS_reg),rtd_inl(CBUS_CTRL10_reg));	
        
		if(rtd_fld_get(get_CBUS_STATUS_reg,3,1) == SRC6) // SRC6
        {	
			debug("get_timer(start)=%ld\n",get_timer(start));
            cbus_hw_init();
			vo_hdmi_mode = VO_MHL_ON;
            break;
        }        
    }
	
       
}

static int set_resolution(void)
{
	struct _BOOT_TV_STD_INFO boot_info;
	
	if(get_one_step_info())
	{
		//compare current sink with one step info.
		memset(&boot_info, 0x0, sizeof(struct _BOOT_TV_STD_INFO));
		memcpy(&boot_info, VO_RESOLUTION,sizeof(struct _BOOT_TV_STD_INFO));
				
		if( SWAPEND32(boot_info.tv_sys.hdmiInfo.hdmiMode)== vo_hdmi_mode 
			&& EDID[EDID_LENGTH-1] == checksum_128 
			&& EDID[2*EDID_LENGTH-1] == checksum_256)
	    {				
			printf("One step\n");
			return S_OK;			
		}	
		else
			printf("Sink changed \n");						
	}
	
	memset(&boot_info, 0x0, sizeof(struct _BOOT_TV_STD_INFO));

	boot_info.dwMagicNumber = SWAPEND32(0xC0DE0BEE); /* set magic pattern in first word */
	boot_info.tv_sys.interfaceType = SWAPEND32(VO_ANALOG_AND_DIGITAL);

    char *s;
    int tv_system;

	s = getenv ("tv_system");
	
	if(vo_hdmi_mode == VO_MHL_ON)
	{
		tv_system = s ? (int)simple_strtol(s, NULL, 10) : CONFIG_DEFAULT_MHL_TV_SYSTEM;
		if( !(tv_system == 27 || tv_system == 28 ||	tv_system == 1))
			tv_system = CONFIG_DEFAULT_MHL_TV_SYSTEM;
	}
	else		
		tv_system = s ? (int)simple_strtol(s, NULL, 10) : CONFIG_DEFAULT_TV_SYSTEM;
		
	printf("tv_system=%d mode=%d\n",tv_system,vo_hdmi_mode);
			
	boot_info.tv_sys.videoInfo.standard  = SWAPEND32(tv_system);
	boot_info.tv_sys.videoInfo.enProg    =  1;
	boot_info.tv_sys.videoInfo.enDIF     =  1;
	boot_info.tv_sys.videoInfo.enCompRGB =  0;
	boot_info.tv_sys.videoInfo.pedType   = SWAPEND32(1);
	boot_info.tv_sys.videoInfo.dataInt0  = SWAPEND32(4);
	boot_info.tv_sys.videoInfo.dataInt1  = SWAPEND32(0);
		
	boot_info.tv_sys.hdmiInfo.hdmiMode          = SWAPEND32(vo_hdmi_mode);
	boot_info.tv_sys.hdmiInfo.audioSampleFreq   = SWAPEND32(3);
	boot_info.tv_sys.hdmiInfo.audioChannelCount = 1; 
	boot_info.tv_sys.hdmiInfo.dataByte1         = 64;
	boot_info.tv_sys.hdmiInfo.dataByte2         = 168;
	boot_info.tv_sys.hdmiInfo.dataByte3         = 0;
	boot_info.tv_sys.hdmiInfo.dataByte4         = 0;
	boot_info.tv_sys.hdmiInfo.dataByte5         = 0;
	boot_info.tv_sys.hdmiInfo.dataInt0          = SWAPEND32(1);
	
	rtd_outl( MIPS_ONE_STEP_INFO_ADDR , SWAPEND32(VO_RESOLUTION)) ; /* tell video firmware where we put the info. 0xa000b0c8*/
	memcpy(VO_RESOLUTION, & boot_info, sizeof(struct _BOOT_TV_STD_INFO) );
	flush_cache(MIPS_ONE_STEP_INFO_ADDR, sizeof(unsigned int));
	flush_cache(VO_RESOLUTION, sizeof(struct _BOOT_TV_STD_INFO));
	
	return S_OK;
}

int sink_capability_handler(int set)
{
	if(HDMITx_HPD())
		Read_EDID(EDID);
#ifdef CONFIG_SUPPORT_MHL		
	else
		cbus_discovery();		
#endif			
	if(set)
		set_resolution();
	
	return S_OK;
}

