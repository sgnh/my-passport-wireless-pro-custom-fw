//#include <stdio.h>
//#include <stdlib.h>
#include <linux/string.h>
//#include <sysdefs.h>
#include "I2CUtil.h"
#include "common.h"
#include "dsp_DLD.h"
#include "dsp_access.h"

//#define DELAY_MTIME 	(30000)


int Openi2sOut()
{
	int ret =0;
	ret = DSPLoadPreset(0x0FB , 0, FALSE);        // PS 0FB          ; [2 CF ]   ]
	ret = DSPLoadPreset(0x280, 0, FALSE);   //SDO0  open [PWL 0 to 1]  SDO0  GPIO9
	ret = DSPLoadPreset(0x28D, 0, FALSE);//[PWL SDO0 Unlimit]
	ret = DSPLoadPreset(0x285, 0, FALSE);   //SDO1  open [PWL 1to2]  GPIO8
	ret = DSPLoadPreset(0x28F, 0, FALSE);        //[PWL SDO1 Unlimit]
     return ret ;
}

int i2sMute()
{
	int ret =0;
	ret = DSPLoadPreset(0x289 , 0, FALSE);        // Mute L2/R2  output  (Demo 板) GPIO 8
	ret = DSPLoadPreset(0x284 , 0, FALSE);  //Mute L1/R1  output     GPIO9
	return ret ;
}

#if 1 //mynew
// 适用于 专业 karaok
int  DLD_Initialize_1st()    //初始化， Music 和 Mic  已经混合 。能够出声
{
	int Ret=0, i;
	unsigned char data;

#if 1 //first part
	display_evaluate_time("yamaha_1st-001");

	Ret = DSPReadReg(0x19,&data) ;  //? YSS961  ID  0x80
	for(i=0; i<10 && Ret!=0; i++)
		Ret = DSPReadReg(0x19,&data) ;
	if (Ret!=0)
		printf("   YAMAHA not ready at this board, ret=%d\n", Ret);
	display_evaluate_time("yamaha_1st-002");	// 32ms

	Ret =DSPPartWriteReg(0x10, 0x00, 0x07);
	display_evaluate_time("yamaha_1st-003");	// 80ms

	Ret = DSPPartWriteReg(0x11, 0x00, 0x03);
	display_evaluate_time("yamaha_1st-004");

	Ret = DSPLoadPreset(0x0C0, 0, FALSE);
	display_evaluate_time("yamaha_1st-005");	//42ms

	Ret = DSPLoadPreset(0x0D5, 0, FALSE);
	Ret = DSPLoadPreset(0x244, 0, FALSE);
	Ret = DSPLoadPreset(0x2BE, 0, FALSE);
	display_evaluate_time("yamaha_1st-006");
	/* set registers */

	Ret =DSPPartWriteReg(0x08, 0x23, 0xFF);    // I2S  inpout  format
	Ret =DSPPartWriteReg(0x09, 0x23, 0xFF);  // I2S  outpiut  format

	Ret =DSPPartWriteReg(0x0A, 0x02, 0x03);
	Ret =DSPPartWriteReg(0x0B, 0x00, 0x03);          //07 ->03
	Ret =DSPPartWriteReg(0x0E, 0x00, 0x03);
	Ret =DSPPartWriteReg(0x23, 0x04, 0x04);
	display_evaluate_time("yamaha_1st-007");
#endif

#if 0 //second part
	Ret =DSPPartWriteReg(0x07, 0x20, 0x3F);

	Ret =DSPPartWriteReg(0x11, 0x03, 0x03);
	Ret = DSPLoadPreset(0x24A, 0, FALSE);
	Ret = DSPLoadPreset(0x159, 0, FALSE);

	Ret = DSPLoadPreset(0x3BA, 0, FALSE);
	Ret = DSPLoadPreset(0x2B4, 0, FALSE);
	Ret = DSPLoadPreset(0x2FB, 0, FALSE);          //  -12dB

	Ret= DSPPartWriteReg(0x10, 0x07, 0x07);
	Openi2sOut();
#endif

	return 0;
}

int  DLD_Initialize_2nd()    //初始化， Music 和 Mic  已经混合 。能够出声
{
	int Ret=0;
	unsigned char data;

#if 1 //second part
	display_evaluate_time("yamaha_2nd-001");
	Ret =DSPPartWriteReg(0x07, 0x20, 0x3F);

	Ret =DSPPartWriteReg(0x11, 0x03, 0x03);
	display_evaluate_time("yamaha_2nd-002");

	Ret = DSPLoadPreset(0x24A, 0, FALSE);
	display_evaluate_time("yamaha_2nd-003");

	Ret = DSPLoadPreset(0x159, 0, FALSE);
	Ret = DSPLoadPreset(0x3BA, 0, FALSE);
	Ret = DSPLoadPreset(0x2B4, 0, FALSE);
	Ret = DSPLoadPreset(0x2FB, 0, FALSE);          //  -12dB
	display_evaluate_time("yamaha_2nd-004");

	Ret= DSPPartWriteReg(0x10, 0x07, 0x07);
	display_evaluate_time("yamaha_2nd-005");

	Openi2sOut();
	display_evaluate_time("yamaha_2nd-006");
#endif

	//this is test sound, for debug use
	//Ret = DSPLoadPreset(0x020, 0, FALSE);	 //	 [Power_On_Short_02] 和玄
	return Ret;
}
#endif


#if 0 //my old
// 适用于 专业 karaok
int  DLD_Initialize_1st()    //初始化， Music 和 Mic  已经混合 。能够出声
{
#if 1

	int Ret=0;
	unsigned char data;

#if 1
	Ret =DSPPartWriteReg(0x10, 0x00, 0x07);	//FMMUTEN=MDSPMUTEN=SDSPMUTEN=0
	//printf("ret is %d\n",Ret);
	Ret = DSPPartWriteReg(0x11, 0x00, 0x03);//	MDSPSTART=SDSPSTART=0
	//printf("ret is %d\n",Ret);
	Ret = DSPLoadPreset(0x0C2, 0, FALSE);  //[Karaoke Mode]
	//printf("ret is %d\n",Ret);

	//#DOWNLOADD ..\Instruction\DD-1inst_DLD.mdspcfg
	Ret = DSPWriteMem(0x458C, inst_DLD, 566);
	//printf("ret is %d\n",Ret);
	//#DOWNLOADD MDSP\DD-1coef_MDSPThrough.mdspcfg
	Ret = DSPWriteMem(0x4200, MDSPThrough1, 37);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x422C, MDSPThrough2, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x4230, MDSPThrough3, 13);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x423F, MDSPThrough4, 13);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x4250, MDSPThrough5, 4);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADD MDSP\KCNormal45ms.mdspcfg
	Ret = DSPWriteMem(0x4179, KCNormal1, 8);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x4182, KCNormal2, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
#endif


#if 1
	//#DOWNLOADD MDSP\DD-1coef_Headroom5bit.mdspcfg
	Ret = DSPWriteMem(0x400D, Headroom5bit1, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
	Ret = DSPWriteMem(0x407F, Headroom5bit2, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
	Ret = DSPWriteMem(0x409E, Headroom5bit3, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	Ret = DSPWriteMem(0x415A, Headroom5bit4, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
	Ret = DSPWriteMem(0x4181, Headroom5bit5, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
	Ret = DSPWriteMem(0x4228, Headroom5bit6, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
	Ret = DSPWriteMem(0x4254, Headroom5bit7, 1);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);


	Ret = DSPLoadPreset(0x0244, 0, FALSE);	 //[LPS No Delay]

   	/*Add here for DownLoad  10BandPEQ */

	/* set registers */

	Ret =DSPPartWriteReg(0x08, 0x23, 0xFF);  //Reg 0x08   I2S 输入
	Ret =DSPPartWriteReg(0x09, 0x23, 0xFF);	//Reg  0x09    I2S 输出

	Ret =DSPPartWriteReg(0x0A, 0x02, 0x03);	//WRAMRTMD=1, WRAMMD=0
	Ret =DSPPartWriteReg(0x0B, 0x00, 0x07);	  //DCCOFF=DEMON=DCM=0

#endif

#if 0
#if 1
	Ret =DSPPartWriteReg(0x0E, 0x00, 0x03);	 //FSM[1:0]=00
	Ret =DSPPartWriteReg(0x23, 0x04, 0x04);	//PLLERRE=1
	Ret =DSPPartWriteReg(0x07, 0x20, 0x3F);	 //PI=1, PIO=0, AIFMD[3:0]=0x0

	Ret = DSPPartWriteReg(0x11, 0x03, 0x03);	//MDSPSTART=SDSPSTART=1

	Ret = DSPLoadPreset(0x24A, 0, FALSE);	  //[LPS Through Sel]
	Ret = DSPLoadPreset(0x232, 0, FALSE);	  //[LD Normal]
	//printf("DLD_Initialize -7\n");
	//msleep(20);
	Ret = DSPLoadPreset(0x1F9, 0, FALSE);	   //[SV Mute]
	Ret = DSPLoadPreset(0x3BA, 0, FALSE);	   //[SV Mute]
	Ret = DSPLoadPreset(0x2B4, 0, FALSE);    //[SV Curve Mid]
//	Ret = DSPLoadPreset(0x31F, 0, FALSE);	  // [SV -30.0dB]
	Ret = DSPLoadPreset(0x301, 0, FALSE);	  // [SV -15.0dB]


	//#DOWNLOADM MDSP\DD-1coef_FMIX_10BandPEQSel.mdspcfg

	Ret = DSPWriteMem(0x422C, FMIX_10BandPEQSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_FMIX_FMMix.mdspcfg
	Ret = DSPWriteMem(0x422A, FMIX_FMMix, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_TCS_TCSSel.mdspcfg
	Ret = DSPWriteMem(0x423B, TCS_TCSSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_TCM_TCMSel.mdspcfg
	Ret = DSPWriteMem(0x424A, TCM_TCMSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);


	//#DOWNLOADM MDSP\DD-1coef_MEQ_EQSel.mdspcfg
	Ret = DSPWriteMem(0x4223, MEQ_EQSel, 2);

	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_MSV_CurveMid.mdspcfg
	Ret = DSPWriteMem(0x4252, MSV_CurveMid, 2);

	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_MSV_-30dB.mdspcfg
	Ret = DSPWriteMem(0x4250, MSV_30dB, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);


	Ret=  DSPPartWriteReg(0x10, 0x07, 0x07);	//FMMUTEN=MDSPMUTEN=SDSPMUTEN=1
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
#endif

	Ret = DSPLoadPreset(0x237 , 0, FALSE);	  // Mic  LR  Input
//	udelay(DELAY_MTIME);
	//printf("DLD_Initialize success\n");
	printf("YSS951 ok\n");
	Openi2sOut();
//	udelay(1000000);

	//DLD_KaraokeEchoEffect(0,1);

	//this is test sound, for debug use
	Ret = DSPLoadPreset(0x020, 0, FALSE);	 //	 [Power_On_Short_02] 和玄
#endif
	//i2sMute();
	return Ret;
#endif

}

int  DLD_Initialize_2nd()    //初始化， Music 和 Mic  已经混合 。能够出声
{
	int Ret=0;
	unsigned char data;

#if 1
	Ret =DSPPartWriteReg(0x0E, 0x00, 0x03);	 //FSM[1:0]=00
	Ret =DSPPartWriteReg(0x23, 0x04, 0x04);	//PLLERRE=1
	Ret =DSPPartWriteReg(0x07, 0x20, 0x3F);	 //PI=1, PIO=0, AIFMD[3:0]=0x0

	Ret = DSPPartWriteReg(0x11, 0x03, 0x03);	//MDSPSTART=SDSPSTART=1

	Ret = DSPLoadPreset(0x24A, 0, FALSE);	  //[LPS Through Sel]
	Ret = DSPLoadPreset(0x232, 0, FALSE);	  //[LD Normal]
	//printf("DLD_Initialize -7\n");
	//msleep(20);
	Ret = DSPLoadPreset(0x1F9, 0, FALSE);	   //[SV Mute]
	Ret = DSPLoadPreset(0x3BA, 0, FALSE);	   //[SV Mute]
	Ret = DSPLoadPreset(0x2B4, 0, FALSE);    //[SV Curve Mid]
//	Ret = DSPLoadPreset(0x31F, 0, FALSE);	  // [SV -30.0dB]
	Ret = DSPLoadPreset(0x301, 0, FALSE);	  // [SV -15.0dB]

	//#DOWNLOADM MDSP\DD-1coef_FMIX_10BandPEQSel.mdspcfg

	Ret = DSPWriteMem(0x422C, FMIX_10BandPEQSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_FMIX_FMMix.mdspcfg
	Ret = DSPWriteMem(0x422A, FMIX_FMMix, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_TCS_TCSSel.mdspcfg
	Ret = DSPWriteMem(0x423B, TCS_TCSSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_TCM_TCMSel.mdspcfg
	Ret = DSPWriteMem(0x424A, TCM_TCMSel, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);


	//#DOWNLOADM MDSP\DD-1coef_MEQ_EQSel.mdspcfg
	Ret = DSPWriteMem(0x4223, MEQ_EQSel, 2);

	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_MSV_CurveMid.mdspcfg
	Ret = DSPWriteMem(0x4252, MSV_CurveMid, 2);

	if(Ret != SUCCESS) printf("ret is %d\n",Ret);

	//#DOWNLOADM MDSP\DD-1coef_MSV_-30dB.mdspcfg
	Ret = DSPWriteMem(0x4250, MSV_30dB, 2);
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);


	Ret=  DSPPartWriteReg(0x10, 0x07, 0x07);	//FMMUTEN=MDSPMUTEN=SDSPMUTEN=1
	if(Ret != SUCCESS) printf("ret is %d\n",Ret);
#endif

	Ret = DSPLoadPreset(0x237 , 0, FALSE);	  // Mic  LR  Input
//	udelay(DELAY_MTIME);
	//printf("DLD_Initialize success\n");
	printf("YSS951 ok\n");
	Openi2sOut();
//	udelay(1000000);

	//DLD_KaraokeEchoEffect(0,1);

	//this is test sound, for debug use
	Ret = DSPLoadPreset(0x020, 0, FALSE);	 //	 [Power_On_Short_02] 和玄

	//i2sMute();
	return Ret;
}
#endif

// value 0: Super Echo   1: Church  2: KaraokeEcho  3: Hall  4:JazzClub   5: OnStage
// 6: KaraokePro  7:   KaraokeSuperPro
//flag :  1: add 208ms    0 :add 178ms

//设置Mic 的ECHO
int DLD_KaraokeEchoEffect(int vlaue,int flag )   //请参数设置为 ：  0 ，1
{
	int ret=0;

	unsigned long ReadData2;
	unsigned long ReadData3;
	unsigned char data_0x000[2]= {0x40,0x3E} ;
	unsigned char data_0x001[2]= {0x00,0x01} ;
	unsigned char data_0x002[2];
	unsigned char data_0x003[2];

	unsigned char data_0x000_m[2]= {0x42,0x50} ;
	unsigned char data_0x001_m[2]= {0x00,0x01} ;

	unsigned char data_0x004[2];
	unsigned char data_0x005[2];


	unsigned short data;


	ret =	DSPWriteMem(0x0000, data_0x000, 1);
	ret =	DSPWriteMem(0x0001, data_0x001, 1);

	ret = DSPPartWriteReg(0x13, 0x03, 0x0F);
	ret = DSPReadMem(0x0002, &ReadData2, 1);
	ret = DSPReadMem(0x0003, &ReadData3, 1);

	data_0x002[0] =  ReadData2>>8; data_0x002[1] =  ReadData2;
	data_0x003[0] =  ReadData3>>8; data_0x003[1] =  ReadData3;


	ret =	DSPWriteMem(0x0000, data_0x000_m, 1);
	ret =	DSPWriteMem(0x0001, data_0x001_m, 1);

	ret = DSPPartWriteReg(0x13, 0x03, 0x0F);
	ret = DSPReadMem(0x0002, &ReadData2, 1);
	ret = DSPReadMem(0x0003, &ReadData3, 1);

	data_0x004[0] =  ReadData2>>8; data_0x004[1] =  ReadData2;
	data_0x005[0] =  ReadData3>>8; data_0x005[1] =  ReadData3;

	ret = DSPLoadPreset(0x3BA, 0, FALSE) ;  //SV Mute

    ret = DSPWriteMem(0x4250, MSV_Mute, 2);  //MSV Mute

	//  Sleep(30);//等待20ms
	ret = DSPPartWriteReg(0x10, 0x00, 0x03);
	ret = DSPPartWriteReg(0x11, 0x00, 0x03);

	//ret = DSPLoadPreset(0x1F7, 0, FALSE);		  // DLD_V200 要去掉

	//////////////////////////////////

	switch(vlaue)

	{
	case 0 :  // [kARAOKE Super Echo]
		ret = DSPLoadPreset(0x3EF, 0, FALSE);
		if(flag == 1)  // add 208ms
		{
			ret = DSPWriteMem(0x40B9, SuperEcho208ms1, 1);
			ret = DSPWriteMem(0x40C7, SuperEcho208ms1, 2);
		}
		break;

	case 1 : // [kARAOKE Church]
		ret = DSPLoadPreset(0x3F0, 0, FALSE);
		if(flag == 1)  //.add 208ms
		{
			ret = DSPWriteMem(0x40B9, Church208ms1, 1);
			ret = DSPWriteMem(0x40C9, Church208ms2, 1);
			ret = DSPWriteMem(0x40CB, Church208ms3, 1);
			ret = DSPWriteMem(0x40D4, Church208ms4, 4);
			ret = DSPWriteMem(0x40D9, Church208ms5, 4);
			ret = DSPWriteMem(0x40DE, Church208ms6, 6);
			ret = DSPWriteMem(0x40E5, Church208ms7, 5);
			ret = DSPWriteMem(0x40EB, Church208ms8, 3);
		}

		if(flag == 0)  //.add 178ms
		{
			ret = DSPWriteMem(0x40B9, Church178ms, 1);
			ret = DSPWriteMem(0x40D4, Church208ms4, 4);
			ret = DSPWriteMem(0x40D9, Church208ms5, 4);
			ret = DSPWriteMem(0x40DE, Church208ms6, 6);
			ret = DSPWriteMem(0x40E5, Church208ms7, 5);
			ret = DSPWriteMem(0x40EB, Church208ms8, 3);
		}
		break;

	case 2 :  // KaraokeEcho

		ret = DSPLoadPreset(0x3EE, 0, FALSE);
		if(flag == 1) //.add 208ms
		{
			ret = DSPWriteMem(0x40B9, Echo208ms1, 1);
			ret = DSPWriteMem(0x40BD, Echo208ms2, 1);
			ret = DSPWriteMem(0x40C7, Echo208ms3, 1);
			ret = DSPWriteMem(0x40D4, Echo208ms4, 1);
			ret = DSPWriteMem(0x40DB, Echo208ms5, 1);

		}

		break;

	case 3 :  //KaraokeHall
		ret = DSPLoadPreset(0x3EE, 0, FALSE);

		if(flag == 1)//.add 208ms
		{
			ret = DSPWriteMem(0x40B9, Hall208ms1, 1);
			ret = DSPWriteMem(0x40C7, Hall208ms2, 39);
		}

		if(flag == 0) //.add 178ms
		{
			ret = DSPWriteMem(0x40B9, Hall208ms1, 1);
			ret = DSPWriteMem(0x40C7, Hall208ms2, 39);
		}

		break;

	case 4 :  // KaraokeJazzClub
		ret = DSPLoadPreset(0x3F2, 0, FALSE);

		if(flag == 1) //.add 208ms
		{
			ret = DSPWriteMem(0x40B9, JazzClub208ms1, 1);
			ret = DSPWriteMem(0x40C4, JazzClub208ms2, 2);
			ret = DSPWriteMem(0x40C7, JazzClub208ms3, 39);
		}
		if(flag == 0) //.add 178ms
		{
			ret = DSPWriteMem(0x40B9, JazzClub208ms1, 1);
			ret = DSPWriteMem(0x40C4, JazzClub208ms2, 2);
			ret = DSPWriteMem(0x40C7, JazzClub208ms3, 39);
		}
		break;

	case 5:  //KaraokeOnStage
		ret = DSPLoadPreset(0x3F0, 0, FALSE);

		if(flag == 1)  //.add 208ms
		{
			ret = DSPWriteMem(0x40B9, OnStage208ms1, 1);
			ret = DSPWriteMem(0x40C9, OnStage208ms2, 1);
			ret = DSPWriteMem(0x40CB, OnStage208ms3, 1);
			ret = DSPWriteMem(0x40DA, OnStage208ms4, 1);
		}

		break;

	case 6:  // KaraokePro and KaraokePro208ms

		ret = DSPLoadPreset(0x3F1, 0, FALSE);
		break;

	case 7: // KaraokeSuperPro and  KaraokeSuperPro208ms
		ret = DSPLoadPreset(0x3F1, 0, FALSE);

		break;



	default:

		// [kARAOKE Super Echo]
		ret = DSPLoadPreset(0x3EF, 0, FALSE);
		if(flag == 1)  // add 208ms
		{

			ret = DSPWriteMem(0x40B9, SuperEcho208ms1, 1);
			ret = DSPWriteMem(0x40C7, SuperEcho208ms1, 2);
		}
		break;
	}

	//////////////////////////////////////

	ret = DSPWriteMem(0x40C6, REAtt2bit, 1);

	ret =DSPPartWriteReg(0x11, 0x03, 0x03);	// Start DSP


	//Sleep(30); //等待20ms
	ret = DSPPartWriteReg(0x10, 0x03, 0x03);
	//ret =	DSPWriteMem(0x0000, 0x403E, 1);
	//ret =	DSPWriteMem(0x0001, 0x0001, 1);
	ret =	DSPWriteMem(0x0000, data_0x000, 1);
	ret =	DSPWriteMem(0x0001, data_0x001, 1);

	//ret =	DSPWriteMem(0x0002, ReadData2, 1);
	//ret =	DSPWriteMem(0x0003, ReadData3, 1);
	ret =	DSPWriteMem(0x0002, data_0x002, 1);
	ret =	DSPWriteMem(0x0003, data_0x003, 1);

	ret = DSPPartWriteReg(0x13, 0x02, 0x0F);


	//ret =	DSPWriteMem(0x0000, 0x403E, 1);
	//ret =	DSPWriteMem(0x0001, 0x0001, 1);
	ret =	DSPWriteMem(0x0000, data_0x000_m, 1);
	ret =	DSPWriteMem(0x0001, data_0x001_m, 1);

	ret =	DSPWriteMem(0x0002, data_0x004, 1);
	ret =	DSPWriteMem(0x0003, data_0x005, 1);
  	ret = DSPPartWriteReg(0x13, 0x02, 0x0F);


	return ret;

}


// 0: KC0c   1: KC50c   2: KC100c     3: KC150c  4: KC200c      5:  KC250c
//     -1: KC-50c  -2:KC-100c   -3:KC-150c  -4: KC-200c   -5: KC-250c
int DLD_Keyshift(int vlaue )  //vlaue: [-5  --  5]
{
  int ret=0;

  switch(vlaue)

	{
	case 0 :  //  KC0c45ms
     ret = DSPLoadPreset(0x213, 0, FALSE);

		break;

	case 1 : //KC+50c45ms
		 ret = DSPLoadPreset(0x214, 0, FALSE);


		break;

	case 2 :  // KC+100c45m
		  ret = DSPLoadPreset(0x215, 0, FALSE);

		break;

	case 3 :  // KC+150c45ms
		 ret = DSPLoadPreset(0x216, 0, FALSE);

		break;

	case 4 :  //   KC+200c45ms
		 ret = DSPLoadPreset(0x217, 0, FALSE);

		break;
	case 5 :  //   KC+250c45ms
		 ret = DSPLoadPreset(0x218, 0, FALSE);

		break;

	case -1:   //KC-50c45ms
		 ret = DSPLoadPreset(0x212, 0, FALSE);


		break;

	case -2:  // KC-100c45ms
		 ret = DSPLoadPreset(0x211, 0, FALSE);



		break;

	case -3: // KC-150c45ms
       ret = DSPLoadPreset(0x210, 0, FALSE);



		break;
	case -4: //   KC-200c45ms

      ret = DSPLoadPreset(0x20F, 0, FALSE);

		break;

	case -5:  //   KC-250c45ms
	   ret = DSPLoadPreset(0x20E, 0, FALSE);
		break;


	default://  KC0c45ms
		  ret = DSPLoadPreset(0x213, 0, FALSE);
		break;
	}


   ret = DSPLoadPreset(0x1FA, 0, FALSE);
   return ret;
}
#if 0
int DLD_Keyshift(int vlaue )  //vlaue: [-5  --  5]
{

	int ret=0;
	unsigned long ReadData2;
	unsigned long ReadData3;
	unsigned char data_0x000[2] = {0x40,0x3E};
	unsigned char data_0x001[2] = {0x00,0x01};
	unsigned char data_0x002[2];
	unsigned char data_0x003[2];


	//ret =	DSPWriteMem(0x0000, 0x403E, 1);
	//ret =	DSPWriteMem(0x0001, 0x0001, 1);
	ret =	DSPWriteMem(0x0000, data_0x000, 1);
	ret =	DSPWriteMem(0x0001, data_0x001, 1);


	ret = DSPPartWriteReg(0x13, 0x03, 0x0F);
	ret = DSPReadMem(0x0002, &ReadData2, 1);
	ret = DSPReadMem(0x0003, &ReadData3, 1);

	data_0x002[0] =  ReadData2>>8; data_0x002[1] =  ReadData2;
	data_0x003[0] =  ReadData3>>8; data_0x003[1] =  ReadData3;



	ret = DSPLoadPreset(0x3BA, 0, FALSE);
	//Sleep(20ms)

	ret = DSPPartWriteReg(0x10, 0x00, 0x03);
	ret = DSPPartWriteReg(0x11, 0x00, 0x03);

	//#DOWNLOADD MDSP\KC0c45ms.mdspcfg
	switch(vlaue)

	{
	case 0 :  //  KC0c45ms
		ret = DSPWriteMem(0x417B, KC0c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC0c45ms2, 2);
		break;

	case 1 : //KC+50c45ms
		ret = DSPWriteMem(0x417B, KC50c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC50c45ms2, 2);
		break;

	case 2 :  // KC+100c45m
		ret = DSPWriteMem(0x417B, KC100c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC100c45ms2, 2);
		break;

	case 3 :  // KC+150c45ms

		ret = DSPWriteMem(0x417B, KC150c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC150c45ms2, 2);
		break;

	case 4 :  //   KC+200c45ms
		ret = DSPWriteMem(0x417B, KC200c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC200c45ms2, 2);
		break;
	case 5 :  //   KC+250c45ms
		ret = DSPWriteMem(0x417B, KC250c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC250c45ms2, 2);
		break;

	case -1:   //KC-50c45ms
		ret = DSPWriteMem(0x417B, KC_50c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC_50c45ms2, 2);

		break;

	case -2:  // KC-100c45ms
		ret = DSPWriteMem(0x417B, KC_100c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC_100c45ms2, 2);


		break;

	case -3: // KC-150c45ms

		ret = DSPWriteMem(0x417B, KC_150c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC_150c45ms2, 2);


		break;
	case -4: //   KC-200c45ms
		ret = DSPWriteMem(0x417B, KC_200c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC_200c45ms2, 2);


		break;

	case -5:  //   KC-250c45ms
		ret = DSPWriteMem(0x417B, KC_250c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC_250c45ms2, 2);

		break;


	default://  KC0c45ms
		ret = DSPWriteMem(0x417B, KC0c45ms1, 6);
		ret = DSPWriteMem(0x4182, KC0c45ms2, 2);

		break;
	}

	ret = DSPPartWriteReg(0x0F, 0x03, 0x03);

	ret =DSPPartWriteReg(0x11, 0x03, 0x03);
	ret = DSPPartWriteReg(0x10, 0x03, 0x03);
	//Sleep(20ms)

	//ret =	DSPWriteMem(0x0000, 0x403E, 1);
	//ret =	DSPWriteMem(0x0001, 0x0001, 1);
	ret =	DSPWriteMem(0x0000, data_0x000, 1);
	ret =	DSPWriteMem(0x0001, data_0x001, 1);


	//ret =	DSPWriteMem(0x0002, ReadData2, 1);
	//ret =	DSPWriteMem(0x0003, ReadData3, 1);
	ret =	DSPWriteMem(0x0002, data_0x002, 1);
	ret =	DSPWriteMem(0x0003, data_0x003, 1);

	ret = DSPPartWriteReg(0x13, 0x02, 0x0F);



	return ret;

}
#endif
// -128dB --  18dB
int  DLD_SetMicVolume(int t_volume)       //  t_volume :    -128dB  - 18dB    step:1  Mic音量控制 :
{

	int ret ;
    t_volume = (-2)*t_volume + 36;
	if (t_volume > 292)
		t_volume = 292;
	if(t_volume < 0)
		t_volume = 0;
	ret = MDSPCoefRTDL(0x4250, &MicVolume_0x4250[t_volume], 1) ;
	ret = MDSPCoefRTDL(0x4251, &MicVolume_0x4251[t_volume], 1) ;

	return ret;
}
int DLD_SetMusicVolume(int t_volume)       //  t_volume :[-128 - 18] dB  step :1 。  Music音量控制
{

	int ret ;
	int volume;
	volume = t_volume*(-2) + 739 ;

	if(volume>953)
	{
		volume = 953 ;
	}

	if(volume < 703)
	{
       volume = 703 ;
	}

	ret = DSPLoadPreset(volume, 0, FALSE);
	return ret;
}
int  DLD_SetEchoLevel(int t_volume)       //  t_volume :[0 - 10]  step :1 。
{
	unsigned short EchoLevel[11] = {
		0x0000,0x0666 ,0x0CCD,0x1333 , 0x199A,  0x2000 , 0x2666, 0x2CCD ,0x3333 ,
		0x399A,0x4000
	};
	//t_volume : 0  :Mute    1: -20dB  2: -14dB    3:  -10dB  4: -8dB   5:  -6dB   6: -4dB  7: -3dB   8: -2dB
	//       9:  -1dB    10:0dB
	int ret ;
	int volume ;
	if (t_volume > 10)
		t_volume = 10;
	if(t_volume < 0)
		t_volume = 0;
	ret = MDSPCoefRTDL(0x40C4, &EchoLevel[t_volume], 1) ;
	ret = MDSPCoefRTDL(0x40C5, &EchoLevel[t_volume], 1) ;

	return ret;
}

int  DLD_SetEchoTime(int t_time)   //   t_time: [0--5]   对卡拉OKEcho延时 0 -208ms

{
	unsigned short echotime;
	unsigned short echotime0,echotime1 ;
	int ret;
	switch(t_time)

	{
	case 0 :  // delay 38ms
		echotime   = 0x0720 ;
		break;

	case 1 :  //delay 88ms
		echotime   = 0x1080  ;
		break;

	case 2 :  //delay 118ms
		echotime   =  0x1620 ;
		break;

	case 3 :  //delay 148ms
		echotime   = 0x1BC0  ;
		break;

	case 4 :  //delay 178ms
		echotime   =  0x2160  ;
		break;

	case 5:  //当为208ms 时候，系统Echo。
		echotime   =   0x2701;  //delay 208ms    当Super Echo 的time  ,长于178ms  ,
		// 则要满足FBTime[15:0]=FTTime1[15:0]=(FTime0[15:0]+232)
		break;

	default:
		break;
	}

	//if(t_time == 0)
	echotime0 = echotime - 232 ;
	echotime1 = echotime;
	ret = MDSPCoefRTDL(0x40C7, &echotime0, 1) ;		//	FTime0
	ret = MDSPCoefRTDL(0x40C8, &echotime1, 1) ;		//	FTime1
	ret = MDSPCoefRTDL(0x40B9, &echotime, 1) ;		//	FBTime


	return ret;
}



// vlaue 5 -> default
int DLD_EchoRepeat(int vlaue )  //vlaue: [0  --  10]
{

	int ret=0;

	unsigned short EchoRepea[11] = {
	0x0000,0x0666 ,0x0CCD,0x1333 , 0x199A,  0x2000 ,
	0x2300,0x2600, 0x2900,0x2C00 ,0x3000 ,

	};

	if (vlaue > 10)
	vlaue = 10;
	if(vlaue < 0)
	vlaue = 0;
	ret = MDSPCoefRTDL(0x40BD, &EchoRepea[vlaue], 1) ;


	return ret;


}
//type : 0:Bass  1:Mid   2: Treble
//Bass  value :[-4 -  4  ,step:1] 【-8dB - 8dB  step:2dB】
 //  Mid  value [-5 -  5 ,step:1] 【 -5dB - 5dB  step:1dB】
//Treble  value [-4 -  4  ,step:1]【-8dB - 8dB  step:2dB】
int DLD_MusicBassMidTrebleCon(int type,int value)
{
	unsigned short *data;


	int ret;

	if(type== 0)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCS_Bass0;
			break;

		case 1 :  //
            data  =  TCS_Bass2;
			break;

		case 2 :
            data  =  TCS_Bass4;
			break;

		case 3 :  //
            data  =  TCS_Bass6;
			break;

		case 4 :  //
            data  =  TCS_Bass8;
			break;

		case -1:  //
          data  =  TCS_Bass_2;
			break;
     case -2:  //
         data  =  TCS_Bass_4;
			break;
		case -3:  //
       data  =  TCS_Bass_6;
			break;
       case -4:  //
         data  =  TCS_Bass_8;
			break;

		default:
         data  =  TCS_Bass0;
			break;
		}
   ret = MDSPCoefRTDL(0x4230, data, 3) ;		//	 Bass
	}

	if(type== 1)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCS_Mid0;
			break;

		case 1 :  //
            data  =  TCS_Mid1;
			break;

		case 2 :  //
            data  =  TCS_Mid2;
			break;

		case 3 :  //
            data  =  TCS_Mid3;
			break;

		case 4 :  //
            data  =  TCS_Mid4;
			break;
      case 5 :  //
            data  =  TCS_Mid5;
			break;
		case -1:  //
          data  =  TCS_Mid_1;
			break;
     case -2:  //
         data  =  TCS_Mid_2;
			break;
		case -3:  //
       data  =  TCS_Mid_3;
			break;
       case -4:  //
         data  =  TCS_Mid_4;
			break;
      case -5:  //
         data  =  TCS_Mid_5;
			break;

		default:
         data  =  TCS_Mid0;
			break;
		}
   ret = MDSPCoefRTDL(0x4233, data, 5) ;		//	 Mid
	}

	if(type== 2)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCS_Treble0;
			break;

		case 1 :  //
            data  =  TCS_Treble2;
			break;

		case 2 :  //
            data  =  TCS_Treble4;
			break;

		case 3 :  //
            data  =  TCS_Treble6;
			break;

		case 4 :  //
            data  =  TCS_Treble8;
			break;

		case -1:  //
          data  =  TCS_Treble_2;
			break;
     case -2:  //
         data  =  TCS_Treble_4;
			break;
		case -3:  //
       data  =  TCS_Treble_6;
			break;
       case -4:  //
         data  =  TCS_Treble_8;
			break;

		default:
         data  =  TCS_Treble0;
			break;
		}
   ret = MDSPCoefRTDL(0x4238, data, 3) ;		//	 Treble
	}




	return ret;
}


//type : 0 ->Bass  1:Mid   2: Treble
 //Bass  value :[-4 -  4  ,step:1] 【-8dB - 8dB  step:2dB】
 //  Mid  value [-5 -  5 ,step:1] 【 -5dB - 5dB  step:1dB】
//Treble  value [-4 -  4  ,step:1]【-8dB - 8dB  step:2dB】
int DLD_MicBassMidTrebleCon(int type,int value)
{
	unsigned short *data;


	int ret;

	if(type== 0)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCM_Bass0;
			break;

		case 1 :  //
            data  =  TCM_Bass2;
			break;

		case 2 :
            data  =  TCM_Bass4;
			break;

		case 3 :  //
            data  =  TCM_Bass6;
			break;

		case 4 :  //
            data  =  TCM_Bass8;
			break;

		case -1:  //
          data  =  TCM_Bass_2;
			break;
     case -2:  //
         data  =  TCM_Bass_4;
			break;
		case -3:  //
       data  =  TCM_Bass_6;
			break;
       case -4:  //
         data  =  TCM_Bass_8;
			break;

		default:
         data  =  TCM_Bass0;
			break;
		}
   ret = MDSPCoefRTDL(0x423F, data, 3) ;		//	 Bass
	}

	if(type== 1)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCM_Mid0;
			break;

		case 1 :  //
            data  =  TCM_Mid1;
			break;

		case 2 :  //
            data  =  TCM_Mid2;
			break;

		case 3 :  //
            data  =  TCM_Mid3;
			break;

		case 4 :  //
            data  =  TCM_Mid4;
			break;
      case 5 :  //
            data  =  TCM_Mid5;
			break;
		case -1:  //
          data  =  TCM_Mid_1;
			break;
     case -2:  //
         data  =  TCM_Mid_2;
			break;
		case -3:  //
       data  =  TCM_Mid_3;
			break;
       case -4:  //
         data  =  TCM_Mid_4;
			break;
      case -5:  //
         data  =  TCM_Mid_5;
			break;

		default:
         data  =  TCM_Mid0;
			break;
		}
   ret = MDSPCoefRTDL(0x4242, data, 5) ;		//	 Mid
	}

	if(type== 2)
	{
		switch(value)

		{
		case 0 :  //
             data  =  TCM_Treble0;
			break;

		case 1 :  //
            data  =  TCM_Treble2;
			break;

		case 2 :  //
            data  =  TCM_Treble4;
			break;

		case 3 :  //
            data  =  TCM_Treble6;
			break;

		case 4 :  //
            data  =  TCM_Treble8;
			break;

		case -1:  //
          data  =  TCM_Treble_2;
			break;
     case -2:  //
         data  =  TCM_Treble_4;
			break;
		case -3:  //
       data  =  TCM_Treble_6;
			break;
       case -4:  //
         data  =  TCM_Treble_8;
			break;

		default:
         data  =  TCS_Treble0;
			break;
		}

		 ret = MDSPCoefRTDL(0x4247, data, 3) ;		//	 Treble
	}

	return ret;
}

#if 0 //basic init
Ret =  DSPReadReg(0x19,&data) ;  //? YSS961  ID  0x80
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x10, 0x00, 0x07);
usleep(DELAY_MTIME);
Ret = DSPPartWriteReg(0x11, 0x00, 0x03);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x0C0, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x0D5, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x244, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x2BE, 0, FALSE);
usleep(DELAY_MTIME);
/* set registers */
Ret =DSPPartWriteReg(0x08, 0x03, 0xFF);    // I2S  inpout  format
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x09, 0x03, 0xFF);  // I2S  outpiut  format
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x0A, 0x02, 0x03);
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x0B, 0x00, 0x03);          //07 ->03
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x0E, 0x00, 0x03);
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x23, 0x04, 0x04);
usleep(DELAY_MTIME);

Ret =DSPPartWriteReg(0x07, 0x20, 0x3F);
usleep(DELAY_MTIME);
Ret =DSPPartWriteReg(0x11, 0x03, 0x03);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x24A, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x159, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x3BA, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x2B4, 0, FALSE);
usleep(DELAY_MTIME);
Ret = DSPLoadPreset(0x2FB, 0, FALSE);          //  -12dB
usleep(DELAY_MTIME);
Ret= DSPPartWriteReg(0x10, 0x07, 0x07);
usleep(DELAY_MTIME);
Openi2sOut();


#endif
