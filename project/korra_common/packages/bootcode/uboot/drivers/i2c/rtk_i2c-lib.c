#include <common.h>
#include "rtk_i2c-api.h"
#include "rtk_i2c-lib.h"
//#include "rtk_i2c-recover.h"

#include <asm/arch/io.h>
#include <asm/arch/rbus/iso_reg.h>

unsigned char i2c_init_rdy = 0;
unsigned int  spd;


#define FIFO_THRESHOLD                   4
#define DEFAULT_SPEED                    100	//must use 400KHz, then NETWORK ping ok, and AMP, YAMAHA will ok too, gene@20110714

//#define i2c_print(fmt,args...)	 		printf(fmt,## args)
//#define i2c_pprint(fmt,args...)	 		printf(fmt,## args)
#define i2c_print(fmt,args...)
#define i2c_pprint(fmt,args...)		
#define i2c_ppprint(fmt,args...)	 	printf(fmt,## args)

/*======================================================================
 * Func : I2C_Init
 *
 * Desc : Init I2C
 *
 * Parm : N/A
 *
 * Retn : N/A
 *======================================================================*/
void I2C_Init(void)
{
    int i;
    unsigned char rx_fifo_depth;
    i2c_pprint("%s %d\n", __FUNCTION__, __LINE__);		
    if (i2c_init_rdy==0)
    {
        for (i=0; i<RTK_I2C_CNT; i++ )
        {
            rx_fifo_depth = ((GET_IC_COMP_PARAM_1(i) >>  8) & 0xFF)+1;
            SET_IC_ENABLE(i, 0);
            SET_IC_INTR_MASK(i, 0);                // disable all interrupt
            SET_IC_CON(i, IC_SLAVE_DISABLE | IC_RESTART_EN | SPEED_SS | IC_MASTER_MODE);
            //SET_IC_TX_TL(i, FIFO_THRESHOLD);
            //SET_IC_RX_TL(i, rx_fifo_depth - FIFO_THRESHOLD);
            I2C_SetSpeed(i, DEFAULT_SPEED);
        }
        i2c_init_rdy = 1;
    }
}

/*======================================================================
 * Func : I2CN_Init
 *
 * Desc : Init I2CN
 *
 * Parm : Bus ID
 *
 * Retn : N/A
 *======================================================================*/
void I2CN_Init(int Bus_ID)
{
    int i = Bus_ID;
    unsigned char rx_fifo_depth;
   	
	//set pinmux 0x18007310		
	rtd_maskl(MUXPAD0_reg, ~(MUXPAD0_i2c_sda_0_mask | MUXPAD0_i2c_scl_0_mask), MUXPAD0_i2c_sda_0(0x1) |MUXPAD0_i2c_scl_0(0x1));
		
    if (i2c_init_rdy==0)
    {

        rx_fifo_depth = ((GET_IC_COMP_PARAM_1(i) >>  8) & 0xFF)+1;
        SET_IC_ENABLE(i, 0);
        SET_IC_INTR_MASK(i, 0);                // disable all interrupt
        SET_IC_CON(i, IC_SLAVE_DISABLE | IC_RESTART_EN | SPEED_SS | IC_MASTER_MODE);
        SET_IC_TX_TL(i, FIFO_THRESHOLD);
        SET_IC_RX_TL(i, rx_fifo_depth - FIFO_THRESHOLD);
        I2C_SetSpeed(i, DEFAULT_SPEED);

        i2c_init_rdy = 1;
    }
}


/*======================================================================
 * Func : I2C_UnInit
 *
 * Desc : Uninit I2C
 *
 * Parm : N/A
 *
 * Retn : N/A
 *======================================================================*/
void I2C_UnInit(void)
{
    int i;

    if (i2c_init_rdy)
    {
        for (i=0; i<RTK_I2C_CNT; i++ )
        {
            SET_IC_ENABLE(i, 0);
            SET_IC_INTR_MASK(i, 0);
        }
        i2c_init_rdy = 0;
    }
		
}


/*======================================================================
 * Func : I2CN_UnInit
 *
 * Desc : Uninit I2CN
 *
 * Parm : Bus_ID
 *
 * Retn : N/A
 *======================================================================*/
void I2CN_UnInit(int Bus_ID)
{
    int i = Bus_ID;

    if (i2c_init_rdy)
    {
        for (i=0; i<RTK_I2C_CNT; i++ )
        {
            SET_IC_ENABLE(i, 0);
            SET_IC_INTR_MASK(i, 0);
        }
        i2c_init_rdy = 0;
    }
	
	rtd_maskl(MUXPAD0_reg, ~(MUXPAD0_i2c_sda_0_mask | MUXPAD0_i2c_scl_0_mask), MUXPAD0_i2c_sda_0(0) |MUXPAD0_i2c_scl_0(0));	
}


/*======================================================================
 * Func : I2C_Write_EX
 *
 * Desc : Single I2C Write Function (Extended Version)
 *
 * Parm : Id        : bus id
 *        Addr      : target address (7bits)
 *        nData     : number of bytes to write
 *        pData     : data to write
 *
 * Retn : S_OK / S_FALSE
 *======================================================================*/
int I2C_Write_EX(
    unsigned char           Id,
    unsigned short          Addr,
    unsigned short          nData,
    unsigned char*          pData,
	unsigned int            flag
    )
{
    return I2C_StartXfer(Id, Addr, nData, pData, 0, NULL, flag);
}



/*======================================================================
 * Func : I2C_Read_EX
 *
 * Desc : Single I2C Read Function
 *
 * Parm : id           : bus id
 *        Addr         : Target Address (7bits)
 *        nSubAddr     : number of bytes of sub address
 *        pSubAddr     : sub address
 *        nData        : numver of bytes to read
 *        pData        : data to read
 *
 * Retn : S_OK / S_FALSE
 *======================================================================*/
int I2C_Read_EX(
    unsigned char           Id,
    unsigned short          Addr,
    unsigned short          nSubAddr,
    unsigned char*          pSubAddr,
    unsigned short          nData,
    unsigned char*          pData,
	unsigned int 			flag
    )
{
    return I2C_StartXfer(Id, Addr, nSubAddr, pSubAddr, nData, pData, flag);
}




/*======================================================================
 * Func : I2C_SetSpeed
 *
 * Desc : this function is used to change the operation speed of i2c adapter
 *
 * Parm : Id           : bus id
 *        KHz          : operation speed
 *
 * Retn : S_OK / S_FALSE
 *======================================================================*/
int I2C_SetSpeed(unsigned char Id, int KHz)
{
    unsigned char i = Id;
	unsigned int div_h = 108;
    unsigned int div_l = 127;

    if (KHz < 10 || KHz > 400)
    {
        i2c_print("[I2C%d] warning, speed %d out of range, speed should between 10 ~ 150KHz\n", i, KHz);
        return -1;
    }


    div_h = (div_h * 100)/KHz;
    div_l = (div_l * 100)/KHz;

    if (div_h >= 0xFFFF || div_h==0 ||
        div_l >= 0xFFFF || div_l==0)
    {
        i2c_print("[I2C%d] fatal, set speed failed : divider divider out of range. div_h = %d, div_l = %d\n", i, div_h, div_l);
        return -1;
    }

    SET_IC_CON(i, (GET_IC_CON(i) & (~IC_SPEED)) | SPEED_SS);
	SET_IC_SS_SCL_HCNT(i, div_h);
    SET_IC_SS_SCL_LCNT(i, div_l);
    i2c_print("[I2C%d] i2c speed changed to %d KHz\n", i, KHz);
    if(KHz!=100)
		i2c_ppprint("[I2C%d] i2c speed changed to %d KHz\n", i, KHz);		
    return 0;
}


/*======================================================================
 * Func : I2C_Transfer_EX
 *
 * Desc : this function supports atomic multiple messages read/write
 *        via i2c message data structure
 *
 * Parm : Id           : bus id
 *        pMsgs       : messages
 *        nMsg        : number of messages
 *
 * Retn : S_OK / S_FALSE
 *======================================================================*/ 
int I2C_StartXfer(
    unsigned char           Id,
    unsigned short          Addr,
    unsigned short          nSubAddr,
    unsigned char*          pSubAddr,
    unsigned short          nData,
    unsigned char*          pData,
	unsigned int			flag
    )
{
    int i = Id;
    int tx_len = 0;
    int rx_len = 0;
    int ret = S_FALSE;
    int delay_loop = 0;
    int event;	 

    if (i >= RTK_I2C_CNT)
        return S_FALSE;

     //	I2C_Init();
					
    SET_IC_TAR(i, Addr & 0x7F);	
    SET_IC_CON(i, GET_IC_CON(i) & (~IC_10BITADDR_MASTER));
    CLR_IC_INTR(i);
    SET_IC_ENABLE(i, 1);

    tx_len = 0;

#define TxComplete()        (tx_len >= nData + nSubAddr)    // it should add the same number of read command to tx fifo
#define RxComplete()        (rx_len >= nData)

    i2c_pprint("s");

	while (delay_loop++ < 10000)		
    {
        // check status
        event = GET_IC_INTR_STAT(i);

        if (event & TX_ABRT_BIT) {
            i2c_ppprint("tx abort!!!!\n");
            break;
        }
		
        if ((event & STOP_DET_BIT) || (nData && RxComplete()))
        {
            if (RxComplete()) {
            	i2c_pprint("Complete!!!! \n ");				
                ret = S_OK;
            } else {
           	 i2c_ppprint("Xmit not Complete!!!!\n");
            }
            break;
        }
		
        // TX Thread
        while(!TxComplete() && NOT_TXFULL(i))
        {
            if (tx_len < nSubAddr)
			{
				if( flag & NON_STOP)
				{			
					SET_IC_DATA_CMD(i, pSubAddr[tx_len]|(0x1<<10));
					
					if(nData==0) //write.
					{
						udelay(50);
						goto done;
					}													
				}																				
				else
					SET_IC_DATA_CMD(i, pSubAddr[tx_len]);																						
			}
            else				
			{
				if( tx_len== nData)				
					SET_IC_DATA_CMD(i, (READ_CMD|(0x1<<9)) );														
				else
					SET_IC_DATA_CMD(i, READ_CMD);  // send read command to rx fifo				
			}
				
            tx_len++;
        }
        i2c_pprint("w");
        // RX Thread
        while(!RxComplete() && NOT_RXEMPTY(i))
        {				
            pData[rx_len++] = (unsigned char)(GET_IC_DATA_CMD(i) & 0xFF);			
			udelay(50);
			i2c_pprint("r");			
        }	
    }

    i2c_pprint("e");

    if (ret != S_OK)
    {
        i2c_ppprint("[I2C%d] timeout\n", i);
#if 0
        if (i2c_bus_jam_detect(i)) {
            i2c_ppprint("[I2C%d] try to bus jam recovery\n", i);
          //  i2c_bus_jam_recover(i);   // try to recover
        }
#endif
    }

done:
    CLR_IC_INTR(i);	
	SET_IC_ENABLE(i, 0);

    return ret;

#undef TxComplete
#undef RxComplete
}


unsigned char I2C_GetBusCount(void)
{
    return RTK_I2C_CNT;
}


