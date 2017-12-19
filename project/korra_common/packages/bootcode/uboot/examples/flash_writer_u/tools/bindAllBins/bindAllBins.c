#include <stdio.h>
#include "../../include/project_config_f.h"

#if defined(Board_CPU_RTD1195)
#define ARM_ROMCODE_MAX_SIZE	(42*1024)
#elif defined(Board_CPU_RTD1192)
#define ARM_ROMCODE_MAX_SIZE    (60*1024)
#else
#define ARM_ROMCODE_MAX_SIZE	(42*1024)
#endif
#define MIPS_ROMCODE_MAX_SIZE	(4*1024)

void printUsage()
{
	printf("bindAllbins : error parameter \n");
	printf("[usage]\n");
	printf("\tgenerate header :\n");
	printf("\t\nbindAllbins header\n");
	printf("\tnon-secure mode :\n");
	printf("\t\nbindAllbins \n");
	printf("\tsecure mode :\n");
	printf("\t\nbindAllbins secure\n");
}

main(int argc, char * const argv[])
{
	char *Out_file="./Bind/bind.bin";
	char *ARM_romcode_file="./Bind/arm_romcode.bin";
	char *MIPS_romcode_file="./Bind/mips_romcode.bin";
	char *Parameter_file=NULL;
	char *Hwsetting_header_file="./Bind/hwsetting_header.bin";
	char *Hwsetting_header_file_enc="./Bind/hwsetting_header_enc.bin";
	char *Hwsetting_file="./Bind/hwsetting.bin";
	char *uboot_file="./Bind/uboot.bin";
	char *Rescue_file="./Bind/rescue.bin";
	char *FSBL_file="./Bind/fsbl.bin";
	char *FSBL_OS_file="./Bind/fsbl_os.bin";
	char *Hwsetting_padding_file="./Bind/hwsetting_padding.bin";
	char *uboot_padding_file="./Bind/uboot_padding.bin";
	char *Rescue_padding_file="./Bind/rescue_padding.bin";
	char *FSBL_padding_file="./Bind/fsbl_padding.bin";
	char *FSBL_OS_padding_file="./Bind/fsbl_os_padding.bin";

	unsigned int ARM_alignByte =0;
	unsigned int MIPS_alignByte =0;

	FILE*	ptr_OUT=NULL;
	FILE*	ptr_ARM_romcode=NULL;
	FILE*	ptr_MIPS_romcode=NULL;
	FILE*	ptr_Parameter=NULL;
	FILE*	ptr_HWsetting_header=NULL;
	FILE*	ptr_HWsetting=NULL;
	FILE*	ptr_uboot=NULL;
	FILE*	ptr_Rescue=NULL;
	FILE*   ptr_FSBL=NULL;
	FILE*   ptr_FSBL_OS=NULL;
	FILE*	ptr_HWsetting_padding=NULL;
	FILE*	ptr_uboot_padding=NULL;
	FILE*	ptr_Rescue_padding=NULL;
	FILE*   ptr_FSBL_padding=NULL;
	FILE*   ptr_FSBL_OS_padding=NULL;

	unsigned int arm_romcode_less=0;
	unsigned int mips_romcode_less=0;
	unsigned int arm_romcode_size=0;
	unsigned int mips_romcode_size=0;
	unsigned int hwsetting_size=0;
	unsigned int uboot_size=0;
	unsigned int rescue_size=0;
	unsigned int secure_fsbl_size=0;
	unsigned int secure_fsbl_os_size=0;
	unsigned int tmp_r=0;
	unsigned int tmp_w=0;
	unsigned int hwsetting_padding_size=0;
	unsigned int uboot_padding_size=0;
	unsigned int rescue_padding_size=0;
	unsigned int secure_fsbl_padding_size=0;
	unsigned int secure_fsbl_os_padding_size=0;

	int ret=0,w_ret=0,i=0;
	char buf[1024]={0};
	//attribute
	int secureMode = 0;
	int genHeader = 0;
	int simulation= 0;
	int boot_enc= 0;

	#if 0
	if (argc==2)
	{
		if (strcmp(argv[1], "secure") == 0)
		{
			printf("bindAllbins : secure mode \n");
			secureMode = 1;
			genHeader = 0;
		}
		else if (strcmp(argv[1], "header") == 0)
		{
			printf("bindAllbins : generate header \n");
			secureMode = 0;
			genHeader = 1;
		}
		else
		{
			printUsage();
			return;
		}
	}
	else if (argc==3)
	{
		for (i=1;i<=2;i++)
		{
			if (strcmp(argv[i], "secure") == 0)
			{
				printf("bindAllbins : secure mode \n");
				secureMode = 1;
			}
			if (strcmp(argv[i], "header") == 0)
			{
				printf("bindAllbins : generate header \n");
				genHeader = 1;
			}
		}
	}
	else if (argc > 3)
	{
		printUsage();
		return;
	}
	else
	#else
	for (i=1;i<argc;i++)
	{
			if (strcmp(argv[i], "secure") == 0)
			{
				printf("bindAllbins : secure mode \n");
				secureMode = 1;
			}
			if (strcmp(argv[i], "header") == 0)
			{
				printf("bindAllbins : generate header \n");
				genHeader = 1;
			}
			if (strcmp(argv[i], "simulation") == 0)
			{
				printf("bindAllbins : simulation mode \n");
				simulation = 1;
			}
			if (strcmp(argv[i], "boot_enc") == 0)
			{
				printf("bindAllbins : uboot encryption \n");
				boot_enc = 1;
			}
		
	}
	#endif
//		printf("bindAllbins : normal mode \n");
	ptr_OUT = fopen(Out_file, "wb");
	ptr_ARM_romcode = fopen(ARM_romcode_file, "rb");
	ptr_MIPS_romcode = fopen(MIPS_romcode_file, "rb");
	ptr_Parameter = fopen(Parameter_file, "rb");
	ptr_HWsetting = fopen(Hwsetting_file, "rb");
	if ((secureMode == 1)&&(genHeader==1))
	{
		ptr_HWsetting_header = fopen(Hwsetting_header_file, "wb");
	}
	else if ((secureMode == 1)&&(genHeader==0))
	{
		ptr_HWsetting_header = fopen(Hwsetting_header_file_enc, "rb");
	}
	else
	{	//secureMode == 0
		if (genHeader == 1)
			ptr_HWsetting_header = fopen(Hwsetting_header_file, "wb");
		else
			ptr_HWsetting_header = fopen(Hwsetting_header_file, "rb");
	}
	ptr_uboot = fopen(uboot_file, "rb");
	ptr_Rescue = fopen(Rescue_file, "rb");
	ptr_HWsetting_padding = fopen(Hwsetting_padding_file, "rb");
	ptr_uboot_padding = fopen(uboot_padding_file, "rb");
	ptr_Rescue_padding = fopen(Rescue_padding_file, "rb");
        if(secureMode) {	
		ptr_FSBL = fopen(FSBL_file, "rb");
		ptr_FSBL_padding = fopen(FSBL_padding_file, "rb");
		ptr_FSBL_OS = fopen(FSBL_OS_file, "rb");
		ptr_FSBL_OS_padding = fopen(FSBL_OS_padding_file, "rb");
	}

	if ((ptr_OUT == NULL) || (ptr_HWsetting == NULL) || (ptr_ARM_romcode == NULL) || (ptr_MIPS_romcode == NULL)
	    || (ptr_HWsetting_padding == NULL))
	
	{
		printf("file open error\n");
		goto error_out;
	}

	fseek(ptr_ARM_romcode, 1, SEEK_END);
	fseek(ptr_MIPS_romcode, 1, SEEK_END);
	fseek(ptr_HWsetting, 1, SEEK_END);
	fseek(ptr_uboot, 1, SEEK_END);
	fseek(ptr_Rescue, 1, SEEK_END);
	if(ptr_FSBL) fseek(ptr_FSBL, 1, SEEK_END);
	if(ptr_FSBL_OS) fseek(ptr_FSBL_OS, 1, SEEK_END);
	fseek(ptr_HWsetting_padding, 1, SEEK_END);
	fseek(ptr_uboot_padding, 1, SEEK_END);
	fseek(ptr_Rescue_padding, 1, SEEK_END);
	if(ptr_FSBL_padding) fseek(ptr_FSBL_padding, 1, SEEK_END);
	if(ptr_FSBL_OS_padding) fseek(ptr_FSBL_OS_padding, 1, SEEK_END);

	arm_romcode_size = ftell(ptr_ARM_romcode)-1;	
	mips_romcode_size = ftell(ptr_MIPS_romcode)-1;	
	hwsetting_size = ftell(ptr_HWsetting)-1;	
	uboot_size = ftell(ptr_uboot)-1;	
	rescue_size = ftell(ptr_Rescue)-1;	
	if(ptr_FSBL) secure_fsbl_size = ftell(ptr_FSBL)-1;
	if(ptr_FSBL_OS) secure_fsbl_os_size = ftell(ptr_FSBL_OS)-1;
	hwsetting_padding_size = ftell(ptr_HWsetting_padding)-1;	
	uboot_padding_size = ftell(ptr_uboot_padding)-1;	
	rescue_padding_size = ftell(ptr_Rescue_padding)-1;	
	if(ptr_FSBL_padding) secure_fsbl_padding_size = ftell(ptr_FSBL_padding)-1;
	if(ptr_FSBL_OS_padding) secure_fsbl_os_padding_size = ftell(ptr_FSBL_OS_padding)-1;
	
	if ((secureMode == 1) && (simulation == 0))
	{
		//due to file size doesn't include signature
		//rsa2048
		hwsetting_size -= 256;
		rescue_size -= 256;
		//real size
		#if 0
		hwsetting_size -= hwsetting_padding_size;
		uboot_size -= uboot_padding_size;
		rescue_size -= rescue_padding_size;
		#endif
	}
	else
	{
		//due to file size doesn't include signature
		//sha256
		hwsetting_size -= 32;
		rescue_size -= 32;
		//real size
		#if 0
		hwsetting_size -= hwsetting_padding_size;
		uboot_size -= uboot_padding_size;
		rescue_size -= rescue_padding_size;
		#endif
	}
	if ((boot_enc == 1)&&(simulation==0))
	{
		uboot_size -= 256;
	}
	else
	{
		uboot_size -= 32;
	}
	if (simulation==0)
	{
		secure_fsbl_size -= 256;
		secure_fsbl_os_size -= 256;
	}
	else
	{
		secure_fsbl_size -= 32;
		secure_fsbl_os_size -= 32;
	}
	printf("arm romcode size = %08x, mips romcode size = %08x\n", arm_romcode_size,mips_romcode_size);
	printf("real hwsetting size = %08x, real uboot size = %08x, real rescue size = %08x\n", hwsetting_size,uboot_size,rescue_size);
	printf("hwsetting padding size = %08x, uboot padding size = %08x, rescue padding size = %08x\n", hwsetting_padding_size,uboot_padding_size,rescue_padding_size);
	if(ptr_FSBL != NULL)
		printf("fsbl size = %08x, fsbl padding size = %08x\n", secure_fsbl_size, secure_fsbl_padding_size);
	if(ptr_FSBL_OS != NULL)
		printf("fsbl os size = %08x, fsbl os padding size = %08x\n", secure_fsbl_os_size, secure_fsbl_os_padding_size);
	
	fseek(ptr_ARM_romcode, 0, SEEK_SET);
	fseek(ptr_MIPS_romcode, 0, SEEK_SET);
	fseek(ptr_HWsetting, 0, SEEK_SET);
	fseek(ptr_uboot, 0, SEEK_SET);
	fseek(ptr_Rescue, 0, SEEK_SET);
	if(ptr_FSBL) fseek(ptr_FSBL, 0, SEEK_SET);
	if(ptr_FSBL_OS) fseek(ptr_FSBL_OS, 0, SEEK_SET);
	fseek(ptr_HWsetting_padding, 0, SEEK_SET);
	fseek(ptr_uboot_padding, 0, SEEK_SET);
	fseek(ptr_Rescue_padding, 0, SEEK_SET);
	if(ptr_FSBL_OS_padding) fseek(ptr_FSBL_OS_padding, 0, SEEK_SET);

	if (genHeader == 1)
	{
		unsigned int padding_len=0;
		printf("generate header : %s \n", Hwsetting_header_file);
		memset(buf,0x00,1024);
		tmp_r=tmp_w=0;
		w_ret=0;
		//4.1 write 96B header
		w_ret = fwrite(&hwsetting_size, 4, 1, ptr_HWsetting_header);
		w_ret += fwrite(&uboot_size, 4, 1, ptr_HWsetting_header);
		if (ptr_FSBL)
			fwrite(&secure_fsbl_size, 4, 1, ptr_HWsetting_header);
		else
			fwrite(buf, 4, 1, ptr_HWsetting_header);
		if (ptr_FSBL_OS)
			fwrite(&secure_fsbl_os_size, 4, 1, ptr_HWsetting_header);
		else
			fwrite(buf, 4, 1, ptr_HWsetting_header);
		w_ret += fwrite(&rescue_size, 4, 1, ptr_HWsetting_header);
		padding_len = 88-w_ret*4;
		printf("header write length : %d , padding length : %d\n", w_ret*4+8, padding_len);
		for(i=0;i<padding_len;i++)
		{
			w_ret = fwrite(buf, 1, 1, ptr_HWsetting_header);
			tmp_w+=w_ret;
		}
		goto error_out;
	}

	if ((arm_romcode_size > ARM_ROMCODE_MAX_SIZE) || (mips_romcode_size > MIPS_ROMCODE_MAX_SIZE))	
	{
		printf("exceed max romcode size \n");
		goto error_out;
	}

	arm_romcode_less = ARM_ROMCODE_MAX_SIZE - arm_romcode_size;
	mips_romcode_less = MIPS_ROMCODE_MAX_SIZE - mips_romcode_size;
	printf("arm romcode less size = %08x, mips romcode less size = %08x\n", arm_romcode_less,mips_romcode_less);

	//1. write arm romcode
	do
	{
		ret = fread(buf, 1, 1, ptr_ARM_romcode);
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("arm romcode r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	memset(buf,0x00,1024);
	for(i=0;i<arm_romcode_less;i++)	
		w_ret = fwrite(buf, 1, 1, ptr_OUT);
	//2. write mips romcode
	do
	{
		ret = fread(buf, 1, 1, ptr_MIPS_romcode);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("mips romcode r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	memset(buf,0x00,1024);
	for(i=0;i<mips_romcode_less;i++)	
		w_ret = fwrite(buf, 1, 1, ptr_OUT);
	//3. write parameter
	if (ptr_Parameter == NULL)
	{
		memset(buf,0x00,1024);
		for(i=0;i<0x800;i++)
		{
			w_ret = fwrite(buf, 1, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	}
	else
	{
	  	do
		{
			ret = fread(buf, 1, 1, ptr_Parameter);
			tmp_r+=ret;
			if (ret > 0)
			{
				w_ret = fwrite(buf, ret, 1, ptr_OUT);
				tmp_w+=w_ret;
			}
		} while (ret > 0);
	}
	printf("parameter r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	memset(buf,0x00,1024);
	//4. write hwsetting
	//4.1 write header
	do
	{
		ret = fread(buf, 1, 1, ptr_HWsetting_header);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	if (secureMode == 1)
		printf("bind header %s\n", Hwsetting_header_file_enc);
	else
		printf("bind header %s\n", Hwsetting_header_file);
	tmp_r=tmp_w=0;
	memset(buf,0x00,1024);
	//4.2 write body
	do
	{
		ret = fread(buf, 1, 1, ptr_HWsetting);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("hwsetting r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	//5. write bootcode
	do
	{
		ret = fread(buf, 1, 1, ptr_uboot);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("bootcode r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	//6. write fsbl
	if (ptr_FSBL){
	do
	{
		ret = fread(buf, 1, 1, ptr_FSBL);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("fsbl r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	}
	//7. write fsbl_os
	if (ptr_FSBL_OS){
	do
	{
		ret = fread(buf, 1, 1, ptr_FSBL_OS);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("fsbl_os r=%08x, w=%08x\n", tmp_r, tmp_w);
	tmp_r=tmp_w=0;
	}
	//8. write rescue
	do
	{
		ret = fread(buf, 1, 1, ptr_Rescue);	
		tmp_r+=ret;
		if (ret > 0)
		{
			w_ret = fwrite(buf, ret, 1, ptr_OUT);
			tmp_w+=w_ret;
		}
	} while (ret > 0);
	printf("rescue r=%08x, w=%08x\n", tmp_r, tmp_w);

error_out:
	if (ptr_OUT)
		fclose(ptr_OUT);
	if (ptr_Parameter)
		fclose(ptr_Parameter);
	if (ptr_ARM_romcode)
		fclose(ptr_ARM_romcode);
	if (ptr_MIPS_romcode)
		fclose(ptr_MIPS_romcode);
	if (ptr_HWsetting_header)
		fclose(ptr_HWsetting_header);
	if (ptr_HWsetting)
		fclose(ptr_HWsetting);
	if (ptr_uboot)
		fclose(ptr_uboot);
	if (ptr_Rescue)
		fclose(ptr_Rescue);
	if (ptr_FSBL)
		fclose(ptr_FSBL);
	if (ptr_FSBL_OS)
		fclose(ptr_FSBL_OS);
	if (ptr_HWsetting_padding)
		fclose(ptr_HWsetting_padding);
	if (ptr_uboot_padding)
		fclose(ptr_uboot_padding);
	if (ptr_Rescue_padding)
		fclose(ptr_Rescue_padding);
	if (ptr_FSBL_padding)
		fclose(ptr_FSBL_padding);
	if (ptr_FSBL_OS_padding)
		fclose(ptr_FSBL_OS_padding);
}
