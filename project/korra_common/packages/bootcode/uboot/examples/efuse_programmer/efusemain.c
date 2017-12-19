#include "../flash_writer_u/include/project_config_f.h"
#include "dvrboot_inc/util.h"
#include "dvrboot_inc/string.h"
#include "dvrboot_inc/otp_reg.h"
#include "dvrboot_inc/io.h"

extern unsigned char rsa_pub_key[];
extern unsigned char rsa_pub_key_end;
extern unsigned char aes_key[];
extern unsigned char aes_key_end;
extern unsigned char aes_seed[];
extern unsigned char aes_seed_end;
extern unsigned char cust_data[];
extern unsigned char cust_data_end;

__align__ unsigned char dec_array[32*2]={0};
__align__ unsigned char v_array[1024]={0};
__align__ unsigned char otp_retry_cnt=0;

/************************************************************************
 *  Public variables
 ************************************************************************/

int printf(const char *fmt, ...);
int obfuse_getset(int type, unsigned char* enc_array,unsigned int ofset,unsigned int len);

//-----------------------------------------------------------------------------
// dummy function
//-----------------------------------------------------------------------------
int ctrlc()
{
	return 0;
}

int printf(const char *fmt, ...)
{
	return 1;
}
//-----------------------------------------------------------------------------
void* memcpy(void* dest, const void* src, size_t count) {
    char* dst8 = (char*)dest;
    char* src8 = (char*)src;

    while (count--) {
        *dst8++ = *src8++;
    }
    return dest;
}

/**
 *  * memcmp - Compare two areas of memory
 *   * @cs: One area of memory
 *    * @ct: Another area of memory
 *     * @count: The size of the area.
 *      */
int memcmp(const void * cs,const void * ct,size_t count)
{
        const unsigned char *su1, *su2;
        int res = 0;

        for( su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
                if ((res = *su1 - *su2) != 0)
                        break;
        return res;
}
//-----------------------------------------------------------------------------
int do_program(void)
{
 	UINT32	rsa_pub_key_size  = (unsigned int )(&rsa_pub_key_end  - rsa_pub_key);
    	UINT32	aes_key_size = (unsigned int )(&aes_key_end - aes_key);
    	UINT32	aes_seed_size = (unsigned int )(&aes_seed_end - aes_seed);
    	UINT32	cust_data_size = (unsigned int )(&cust_data_end - cust_data);
	int res = -1;

	prints("\nefuse programmer v1.02 start....\n");

#ifdef Config_Secure_Key_TRUE
	prints("\tfor secure boot platform, \n");
	prints("\t-w rsa \n");

	//0. judge go or not
	if (obfuse_judge())
	{
		prints("judge fail \n");
		return 0;
	}
	sync();
	//1. burn the rsa public key directly
	start_program(0, rsa_pub_key_size, rsa_pub_key);
	
	//2.1 write aes
	prints("\t-w key \n");
	#ifdef DEBUG_PRT
	hexdump("aes_key :", aes_key, 16);
	#endif
	res = obfuse_getset(1,aes_key,2304,aes_key_size);
	sync();	
	if (!res)
		return res;

	//2.2 write seed
	prints("\t-w seed \n");
	#ifdef DEBUG_PRT
	hexdump("aes_seed :", aes_seed, 16);
	#endif
	otp_retry_cnt=0;
	res = obfuse_getset(1,aes_seed,2048,aes_seed_size);
	sync();	
	if (!res)
		return res;
	
	//3. secure burn
	do_burn_efuse_bootenc();
	sync();
	do_burn_efuse_hwchk(2); //chk later
	sync();
	do_burn_efuse_secureboot();
	sync();
#else
	prints("\tfor non-secure boot platform, \n");
#endif
	if (cust_data_size > 0)
	{
		if (cust_data_size >= 511)
		{
			prints("\tmax. cust_data length is 511B\n");
			res = 0;
			return res;
	        }	
		prints("\t-w cust_data\n");
		#ifdef DEBUG_PRT
		hexdump("cust_data :", cust_data, cust_data_size);
		#endif
		otp_retry_cnt=0;
        	res = obfuse_getset(0,cust_data,4096,cust_data_size);
        	sync();
        	if (!res)
                	return res;
		sync();
	}
	else
		prints("\tno cust_data\n");

	res = 0;	// complete without failure

	return res;
}

/************************************************************************
 *
 *                          efusemain
 *  Description :
 *  -------------
 *  main function of efuse programmer
 *
 *  Parameters :
 *  ------------
 *
 *
 *
 *  Return values :
 *  ---------------
 *
 *
 *
 *
 ************************************************************************/
int efusemain (int argc, char * const argv[])
{
	int		ret = -1;
	extern unsigned int mcp_dscpt_addr;

	mcp_dscpt_addr = 0;
	otp_retry_cnt = 0;
	init_uart();
	set_focus_uart(0);
	if ((ret = do_program()) != 0) {
		return -1;
	}

	if (ret == 0)
		prints("program OTP OKOKOKOKOKOK!!!!!!!\n");
	else
		prints("program OTP failfailfail!!!!!!!\n");
    return 0;
}
