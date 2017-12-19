/* 	CONFIDENTIAL
*********************************************************************************

	File:			dsp_access.c
	Target Device:	DD-1/DD-1SP
	Version:		1.00.04

	Description:	DSP Access Processing

	Copyright(c) 2008 Yamaha Corporation

*********************************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
#include <linux/string.h>
//#include <sysdefs.h>
#include "I2CUtil.h"
#include "common.h"
#include "dsp_access.h"

/* proto type declaratin   extern*/
extern  unsigned char  GetPRESETROMCommand(unsigned short wNum, unsigned char  *pbData);
extern  unsigned long  GetDSPWordSize(unsigned short wAdd);
extern  unsigned long  GetDSPDataSize(unsigned short wAdd, unsigned short wSize);
extern  unsigned char  CheckMDSPREQ(void);

#define I2C_BUS 1
unsigned char dsp_dat[23];
#define DELAY_MTIME 	(2000)

 unsigned char  LoopWait(unsigned long dwWait)
 {
	 unsigned long i;
	/* 
	The "for" sentence processing takes approximately
	12 clocks (=500 nsec).
	Doubled "dwWait" is 1 microsecond.
	*/
	//dwWait *= 2;
	
	for(i = 0; i < dwWait*5000; i++);


 }
/* **************************************************** */
/* GetPRESETROMCommand									*/
/*		parameter:										*/
/*			unsigned short		usNum					*/
/*								(ROM block number)		*/
/*														*/
/*			*unsigned char		pbCommand				*/
/*								(command code)			*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			obtain PRESETROM command. 					*/
/* **************************************************** */
unsigned char  GetPRESETROMCommand(unsigned short wNum, unsigned char  *pbCommand)
{
	unsigned char bResult = SUCCESS;
	
	if(wNum <= PRESETROM0_END)
	{
		*pbCommand = 0x70;
		*(pbCommand+1) = wNum;
	}
	else if(wNum <= PRESETROM1_END)
	{
		*pbCommand = 0x71;
		*(pbCommand+1) = wNum - (PRESETROM0_END+1);
	}
	else if(wNum <= PRESETROM2_END)
	{
		*pbCommand = 0x72;
		*(pbCommand+1) = wNum - (PRESETROM1_END+1);
	}
	else if(wNum <= PRESETROM3_END)
	{
		*pbCommand = 0x73;
		*(pbCommand+1) = wNum - (PRESETROM2_END+1);
	}
	else
	{
		bResult = ERROR_PARAM;
	}
	
	return(bResult);
}

/* **************************************************** */
/* GetDSPWordSize										*/
/*		parameter:										*/
/*			unsigned short		wAdd					*/
/*								(DSP memory address)	*/
/*														*/
/*		return value:									*/
/*			unsigned long		word size				*/
/*														*/
/*		descripton:										*/
/*			obtain word size of the DSP memory.			*/
/* **************************************************** */
unsigned long GetDSPWordSize(unsigned short wAdd)
{
	if   (wAdd <= DSP_MEM_ADD_WRAM0END)	    return(2);
	else if(wAdd <= DSP_MEM_ADD_WRAM1END)	return(4);
	else if(wAdd <= DSP_MEM_ADD_WRAM2END)	return(2);
	else if(wAdd <= DSP_MEM_ADD_CRAMEND	)	return(2);
	else if(wAdd <= DSP_MEM_ADD_MPRAMEND)	return(5);
	else if(wAdd <= DSP_MEM_ADD_QBUSEND)	return(4);
	else if(wAdd <= DSP_MEM_ADD_PEQRAMEND)	return(3);
	else return(2);
}

/* **************************************************** */
/* GetDSPDataSize										*/
/*		parameter:										*/
/*			unsigned short		wAdd					*/
/*								(DSP memory address)	*/
/*														*/
/*			unsigned short		wSize					*/
/*								(data size)				*/
/*														*/
/*		return value:									*/
/*			unsigned long		byte size				*/
/*														*/
/*		description:									*/
/*			obtain byte size.							*/
/* **************************************************** */
unsigned long  GetDSPDataSize(unsigned short wAdd, unsigned short wSize)
{
	unsigned short wCnt;
	unsigned long dwResult = 0;
	
	for(wCnt = 0; wCnt < wSize; wCnt++)
	{
		dwResult += GetDSPWordSize(wAdd + wCnt);
	}
	
	return(dwResult);
}

/* **************************************************** */
/* CheckMDSPREQ											*/
/*		parameter:										*/
/*			none										*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			check DSP register : 0x13 MDSPREQ.			*/
/* **************************************************** */
unsigned char CheckMDSPREQ(void)
{
	unsigned char bData, bResult;
	unsigned char wData[20];
	unsigned char nwData = 0;
	
	/* wait for 1 sample time(=21 microseconds) */
	//LoopWait(RT_MAX_WAIT);
	udelay(DELAY_MTIME);
	
	wData[0] = DSP_REG_ADD_MDSPREQ;
	nwData = 1;
	I2C_Read_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData,1,&bData);

	if(bData != DSP_REG_DATA_RTREADY)
	{
		return(ERROR_RT);
	}
	return 0;
}

/* **************************************************** */
/* CheckError											*/
/*		parameter:										*/
/*			none										*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			check errors of DSP. 						*/
/* **************************************************** */
unsigned char  CheckError(void)
{
	unsigned char  bMDSPST, bSDSPST, bDAMPST0, bDAMPST1, bPLLERR;
	unsigned char bResult;
	
	bResult  = DSPReadReg(0x1B, &bMDSPST);		/* 0x1B MDSPST */
	bResult += DSPReadReg(0x20, &bSDSPST);		/* 0x20 SDSPST */
	bResult += DSPReadReg(0x21, &bDAMPST0);		/* 0x21 DAMPST0 */
	bResult += DSPReadReg(0x22, &bDAMPST1);		/* 0x22 DAMPST1 */
	bResult += DSPReadReg(0x23, &bPLLERR);		/* 0x23 PLLERR */

	if(bResult == SUCCESS)
	{
		if( (bMDSPST  & DSP_REG_MASK_MDSPERR)  |	/* check MDSPERR bit */
			(bSDSPST  & DSP_REG_MASK_SDSPERR)  |	/* check SDSPERR bit */
			(bDAMPST0 & DSP_REG_MASK_DAIFERR)  |	/* check DAIFERR bit */
			(bDAMPST1 & DSP_REG_MASK_TJDET2)   |	/* check TJDET[2] bit */
			(bPLLERR  & DSP_REG_MASK_PLLERR) )		/* check PLLERR bit */
			
		{
			return(ERROR_DSP);
		}
	}
	return(bResult);
}

/* **************************************************** */
/* DSPWriteReg											*/
/*		parameter:										*/
/*			unsigned char		bAdd					*/
/*								(destination address)	*/
/*														*/
/*			unsigned char		bData					*/
/*								(setting data)			*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			set DSP register.							*/
/* **************************************************** */
unsigned char DSPWriteReg(unsigned char bAdd, unsigned char bData)   //add :[0x00 -- 0x3F]
{
	int	dRet;	
	unsigned char wData[20];
	unsigned char nwData = 0;
	//	printf("machdep_I2C_WriteReg dAddress= %d, bData= 0x%02x \n", dAddress, bData);	
	// Set Transfer Direction
	udelay(DELAY_MTIME);
 	wData[0] = bAdd;
 	wData[1] = bData;
 	nwData = 2;
 	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);
	return 0;
}

/* **************************************************** */
/* DSPReadReg											*/
/*		parameter:										*/
/*			unsigned char		bAdd					*/
/*								(source address)		*/
/*														*/
/*			*unsigned char		pbData					*/
/*								(acquired data)			*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			obtain data form DSP register.				*/
/* **************************************************** */
unsigned char  DSPReadReg(unsigned char bAdd, unsigned char  *pbData)  //add :[0x00 -- 0x3F]
{
	UINT8 * dataBuffer=(UINT8 *)dsp_dat;
	int i2c_speed = 100, ret;
	//unsigned char* pAddr = (unsigned char*)malloc(sizeof(unsigned char));
	//udelay(DELAY_MTIME);
	dataBuffer[0] = bAdd;
	//I2C_SetSpeed(I2C_BUS,i2c_speed);
	
	ret = I2C_Read_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,1,dataBuffer,1,pbData);
	return ret;
}

/* **************************************************** */
/* DSPPartWriteReg										*/
/*		parameter:										*/
/*			unsigned char		bAdd					*/
/*						   		(destination address)	*/
/*														*/
/*			unsigned char		bData					*/
/*								(setting data)			*/
/*														*/
/*			unsigned char		bMask					*/
/*								(mask)					*/
/*														*/
/*		return value:									*/
/*			unsigned char		processing result		*/
/*														*/
/*		description:									*/
/*			set DSP register by bits					*/
/* **************************************************** */
unsigned char  DSPPartWriteReg(unsigned char bAdd, unsigned char bData, unsigned char bMask)  //add :[0x00 -- 0x3F]
{
	unsigned char bResult, bTmp;
//	LoopWait(RT_MAX_WAIT);
	udelay(DELAY_MTIME);
	/* obtain data from register */
	bResult = DSPReadReg(bAdd, &bTmp);
	if(bResult != SUCCESS)
	{
//		return(bResult);
	}
	
	/* create setting data */
	bData = ( (bTmp & ~bMask) | (bData & bMask) );
	//printf("bData 0x%x",bData);
	
	/* set register */
	bResult = DSPWriteReg(bAdd, bData);
	
	return(bResult);
}

/* ******************************************************************** */
/* DSPLoadPreset														*/
/*		parameter:														*/
/*			unsigned short		wNum									*/
/*								(ROM block number)						*/
/*																		*/
/*			unsigned short		wAdd									*/
/*								(top address of transfer destination)	*/
/*																		*/
/*			unsigned char		bSetAdd									*/
/*								(1: set address)						*/
/*								(others: not set address)				*/
/*																		*/
/*		return value:													*/
/*			unsigned char		processing result						*/
/*																		*/
/*		description:													*/
/*			load preset pattern.										*/
/* ******************************************************************** */
unsigned char  DSPLoadPreset(unsigned short wNum, unsigned short wAdd, unsigned char bSetAdd)   //add :[0x000 -- 0x3FF]
{
	unsigned char bCommand[2], bStartAdd[2];
	unsigned char bResult;
	unsigned short wNakCount = 0;
	unsigned char  dRet ;
	unsigned char wData[20];
	unsigned char nwData = 0;

	//LoopWait(RT_MAX_WAIT);
	udelay(DELAY_MTIME);
	
	/* check ROM block number */
	if((wNum < DSP_ROM_NUM_MIN) || (wNum > DSP_ROM_NUM_MAX))
	{
		return 1;
	}
	
	/* when setting address */
	if(bSetAdd == TRUE)
	{
		/* check address */
		if( (wAdd < DSP_MEM_ADD_CRAMTOP) || (wAdd > DSP_MEM_ADD_CRAMEND) )
		{
			return 1;
		}
		
		bStartAdd[0] = ( (wAdd - DSP_MEM_ADD_CRAMTOP) >> 8 ) & 0xFF;
		bStartAdd[1] = (wAdd - DSP_MEM_ADD_CRAMTOP) & 0xFF;
	}
	
	/* obtain PRESETROM command */
	GetPRESETROMCommand(wNum, bCommand);
	
	if(bSetAdd == TRUE)
	{
		wData[0] = DSP_COM_WRITEREAD;
		wData[1] = (DSP_MEM_ADD_RTSTARTADR >> 8) & 0xFF;
		wData[2] = DSP_MEM_ADD_RTSTARTADR & 0xFF;
		wData[3] = bStartAdd[0];
		wData[4] = bStartAdd[1];
		nwData = 5;
		I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);
	}
	wData[0] = bCommand[0];
	wData[1] = bCommand[1];
	nwData = 2;
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);

	return 0;	 
}



/* ******************************************************************** */
/* DSPWriteMem															*/
/*		parameter:														*/
/*			unsigned short		wAdd									*/
/*								(top address of transfer destination)	*/
/*																		*/
/*			*unsigned char		pbData									*/
/*								(setting data)							*/
/*																		*/
/*			unsigned short		wWordSize								*/
/*								(data size. word by word.)				*/
/*																		*/
/*		return value:													*/
/*			unsigned char		processing result						*/
/*																		*/
/*		description:													*/
/*			set DSP memory.												*/
/* ******************************************************************** */

unsigned char  DSPWriteMem(unsigned short wAdd, unsigned char  *pbData, unsigned short wWordSize)    ////add :[0x0000 -- 0xFFFF]
{
	unsigned long   dwByteSize, dwTmp, dwCnt;
	unsigned short   wNakCount = 0;
	unsigned char wData[3000];
	unsigned short nwData = 0;
	long dRet;
   	//LoopWait(RT_MAX_WAIT*5);
   	udelay(DELAY_MTIME);
	udelay(DELAY_MTIME);
	udelay(DELAY_MTIME);
	udelay(DELAY_MTIME);
	udelay(DELAY_MTIME);
	
	/* check size */
	if( (wWordSize < 0) || (wWordSize > TRANS_MAX_SIZE) )
	{
		return(ERROR_PARAM);
	}
	//printf("DSPWriteMem-1\n");
	/* check area */
	dwTmp = (unsigned long)wAdd + (unsigned long)wWordSize - 1;
	if( (wAdd < DSP_MEM_ADD_RAMTOP) || (dwTmp > DSP_MEM_ADD_RAMEND) )
	{
		return(ERROR_PARAM);
	}
	/* convert size by words to by bytes */
	dwByteSize = GetDSPDataSize(wAdd, wWordSize);
	wData[0] = DSP_COM_WRITEREAD;
	wData[1] = (unsigned char)( (wAdd >> 8) & 0xFF );
	wData[2] = (unsigned char)(wAdd & 0xFF);
	nwData = 3;
	for(dwCnt = 0; dwCnt < dwByteSize; dwCnt++, pbData++)
	{
		wData[3+dwCnt] = *pbData;
		nwData++;
	}
	//printf("DSPWriteMem nwData is %d\n",nwData);
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);

	return 0;
}

/* **************************************************************** */
/* DSPReadMem														*/
/*		parameter:													*/
/*			unsigned short		wAdd								*/
/*								(top address of transfer source)	*/
/*																	*/
/*			*unsigned char		pbData								*/
/*								(acquired data)						*/
/*																	*/
/*			unsigned short		wWordSize							*/
/*								(data size. word by word.)			*/
/*		return value:												*/
/*																	*/
/*			unsigned char		processing result					*/
/*																	*/
/*		description:												*/
/*			obtain data form DSP memory.							*/
/* **************************************************************** */
unsigned char  DSPReadMem(unsigned short wAdd, unsigned long  *pbData, unsigned short wWordSize)  ////add :[0x0000 -- 0FFFF]
{
	unsigned long dwByteSize, dwTmp;
	unsigned char bResult;
	unsigned short wNakCount = 0;
	unsigned char wData[4];
	unsigned char rData[2];
	
	/* check size */
	if( (wWordSize < 0) || (wWordSize > TRANS_MAX_SIZE) )
	{
		return(ERROR_PARAM);
	}
	
	/* check area */
	dwTmp = (unsigned long)wAdd + (unsigned long)wWordSize - 1;
	if( (wAdd < DSP_MEM_ADD_RAMTOP) || (dwTmp > DSP_MEM_ADD_RAMEND) )
	{
		return(ERROR_PARAM);
	}
	
	/* convert size by words to by bytes */
	dwByteSize = GetDSPDataSize(wAdd, wWordSize);
	
	wData[0] = DSP_COM_WRITEREAD;
	wData[1] = (wAdd >> 8) & 0xFF;
	wData[2] = wAdd & 0xFF;
	wData[3] = 0x00;
	rData[0] = 0;
	rData[1] = 0;
	*pbData = 0;
	if(wAdd >=0x8000 )
	{
		I2C_Read_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,4,wData,2,rData);
		*pbData = (*pbData <<8)|rData[0];
		*pbData = (*pbData <<8)|rData[1];
	}else{
		I2C_Read_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,4,wData,1,rData);
		*pbData = (*pbData <<8)|rData[0];
	}	
	return 0;
}

/* ******************************************************************** */
/* MDSPCoefRTDL															*/
/*		parameter:														*/
/*			unsigned short		wAdd									*/
/*								(top address of transfer destination)	*/
/*																		*/
/*			*unsigned char		pbData									*/
/*								(setting data)							*/
/*																		*/
/*			unsigned short		wWordSize								*/
/*								(data size. word by word.)				*/
/*		return value:													*/
/*																		*/
/*			unsigned char		processing result						*/
/*																		*/
/*		description:													*/
/*			set DSP memory by runtime transfer.							*/
/* ******************************************************************** */
unsigned char  MDSPCoefRTDL(unsigned short wAdd, unsigned short  *pbData, unsigned short wWordSize)  //add :[0x4000 -- 0x43FF] dd
{
	unsigned long dwByteSize, dwTmp;
	unsigned char bStartAdd[2];
	unsigned char bResult;
	int dCnt;
	unsigned short wNakCount = 0;
	unsigned short data;
	unsigned char wData[20];
	unsigned char nwData = 0;
	//LoopWait(RT_MAX_WAIT);
	udelay(DELAY_MTIME);
	
	/* check size */
	if( (wWordSize < 1) || (wWordSize > RT_MAX_SIZE) )
	{
		return(ERROR_PARAM);
	}
	
	/* check area */
	dwTmp = (unsigned long)wAdd + (unsigned long)wWordSize - 1;
	if( (wAdd < DSP_MEM_ADD_CRAMTOP) || (dwTmp > DSP_MEM_ADD_CRAMEND) )
	{
		return(ERROR_PARAM);
	}
	
	/* prepare transfer data (top address of transfer destination) */
	bStartAdd[0] = ( (wAdd - DSP_MEM_ADD_CRAMTOP) >> 8 ) & 0xFF;
	bStartAdd[1] = (wAdd - DSP_MEM_ADD_CRAMTOP) & 0xFF;
	
	/* convert size by words to by bytes */
	dwByteSize = GetDSPDataSize(wAdd, wWordSize);

	wData[0] = DSP_COM_WRITEREAD;
	wData[1] = (DSP_MEM_ADD_RTSTARTADR >> 8) & 0xFF;
	wData[2] = DSP_MEM_ADD_RTSTARTADR & 0xFF;
	wData[3] = bStartAdd[0] ;
	wData[4] = bStartAdd[1] ;
	wData[5] = 0x00;
	wData[6] = (unsigned char)(wWordSize - 1);
	nwData = 7;
	for (dCnt = 0; dCnt < wWordSize; ++dCnt )
	{
		wData[7+dCnt*2] = (*(pbData+dCnt) >> 8) & 0xFF;
		wData[7+dCnt*2+1] = ( *(pbData+dCnt) ) & 0xFF;
		nwData += 2;
	}
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);
	
	wData[0] = DSP_REG_ADD_MDSPREQ;
	wData[1] = DSP_REG_DATA_RTDL;
	nwData = 2;
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);

	return(CheckMDSPREQ());       //fcl 2010.3.12
}

/* **************************************************************** */
/* MDSPCoefRTUL														*/
/*		parameter:													*/
/*			unsigned short		wAdd								*/
/*								(top address of transfer source)	*/
/*																	*/
/*			*unsigned char		pbData								*/
/*								(acquired data)						*/
/*																	*/
/*			unsigned short		usWordSize							*/
/*								(data size.word by word.)			*/
/*																	*/
/*		return value:												*/
/*			unsigned char		processing result					*/
/*																	*/
/*		description:												*/
/*			obtain data from  DSP memory by runtime transfer.		*/
/* **************************************************************** */
unsigned char  MDSPCoefRTUL(unsigned short wAdd, unsigned short  *pbData, unsigned short wWordSize)      //add :[0x4000 -- 0x43FF]
{
	unsigned long dwByteSize, dwTmp;
	unsigned char bStartAdd[2];
	unsigned char bResult;
	unsigned char dCnt ;
	unsigned short wNakCount = 0;
	unsigned char wData[20];
	unsigned char rData[RT_MAX_SIZE];
	unsigned char nwData = 0;

	/* check size */
	if( (wWordSize < 1) || (wWordSize > RT_MAX_SIZE) )
	{
		return(ERROR_PARAM);
	}
		
	/* check area */
	dwTmp = (unsigned long)wAdd + (unsigned long)wWordSize - 1;
	if( (wAdd < DSP_MEM_ADD_CRAMTOP) || (dwTmp > DSP_MEM_ADD_CRAMEND) )
	{
		return(ERROR_PARAM);
	}
	
	/* prepare the transfer data (top address of transfer source) */
	bStartAdd[0] = ( (wAdd - DSP_MEM_ADD_CRAMTOP) >> 8 ) & 0xFF;
	bStartAdd[1] = (wAdd - DSP_MEM_ADD_CRAMTOP) & 0xFF;
	
	/* convert size by words to by bytes */
	dwByteSize = GetDSPDataSize(wAdd, wWordSize);
	
	wData[0] = DSP_COM_WRITEREAD;
	wData[1] = (DSP_MEM_ADD_RTSTARTADR >> 8) & 0xFF;
	wData[2] = DSP_MEM_ADD_RTSTARTADR & 0xFF;
	wData[3] = bStartAdd[0];
	wData[4] = bStartAdd[1];
	wData[5] = 0x00;
	wData[6] = (unsigned char)(wWordSize - 1);
	nwData = 7;
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);
	
	wData[0] = DSP_REG_ADD_MDSPREQ;
	wData[1] = DSP_REG_DATA_RTDL;
	nwData = 2;
	I2C_Write_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData);

	bResult = CheckMDSPREQ();
		
	/* when processing for DSP is failed */
	if(bResult != SUCCESS)
	{
		return(bResult);
	}
	
	wData[0] = DSP_COM_WRITEREAD;
	wData[1] = (DSP_MEM_ADD_RTDATA0 >> 8) & 0xFF;
	wData[2] = DSP_MEM_ADD_RTDATA0 & 0xFF;
	wData[3] = 0x00;
	wData[4] = DSP_COM_WRITEREAD;
	nwData = 5;
	I2C_Read_EX(I2C_BUS,DD1SP_SLAVE_ADDRESS,nwData,wData,wWordSize*2,rData);
	
	for (dCnt = 0; dCnt < wWordSize; ++dCnt )
	{
		*(pbData+dCnt) = rData[dCnt*2];
		*(pbData+dCnt) = (*(pbData+dCnt) <<8)|rData[dCnt*2+1];
	}

	return 0;
}

