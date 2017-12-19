/************************************************************************
 *
 *  logo_disp.c
 *
 *  Belong to logo_disp module
 *
 *  This module implements logo display function
 *
 ************************************************************************/

/************************************************************************
 *  Include files
 ************************************************************************/
#include <common.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/fw_info.h>
#include <logo_disp/logo_disp_api.h>

/************************************************************************
 *  Public variables
 ************************************************************************/

extern t_extern_param *ext_para_ptr;
extern uint sys_logo_start;
extern uchar sys_logo_enabled;
extern uchar sys_logo_is_HDMI;

/************************************************************************
 *  Function Prototypes
 ************************************************************************/
extern void LOGO_DISP_setup(t_extern_param *logo_param_ptr);
extern void LOGO_DISP_get_Monitor_mode(unsigned char *is_hdmi_mode);
static void  LOGO_decode_CLUT(uint logo_reg_537X, unsigned char *clut_addr);

/************************************************************************
 *  Implementation : Global functions
 ************************************************************************/
#if 0
void  LOGO_DISP_setup(t_extern_param *logo_param_ptr)
{
	if ( logo_param_ptr->logo_type == 0)
	{
	  printf("NTSC logo\n");
	  LOGO_DISP_525p(logo_param_ptr);
	}
	else
	{
	  printf("PAL logo\n");
	  LOGO_DISP_625p(logo_param_ptr);
	}
}
#endif

int LOGO_DISP_init(void)
{
	unsigned char *a,*b;

	// check if logo has already inited
	if (sys_logo_enabled)
		return 0;

	sys_logo_enabled = 1;

#if 0 //FIXME at rtd299x
	// check monitor device mode (DVI/HDMI)
	sys_logo_is_HDMI = 0;
	LOGO_DISP_get_Monitor_mode(&sys_logo_is_HDMI);
#endif

	*(volatile unsigned int *)LOGO_SET_CNT_ADDR = SWAPEND32((uint)LOGO_SET_CNT);
	/* this value will be the counter to decide when to change picture */
	*(volatile unsigned int *)LOGO_CHG_CNT_ADDR = SWAPEND32((uint)LOGO_SET_CNT);
	/* this value will save the current displayed picture # */
	*(volatile unsigned int *)LOGO_NO_ADDR = 0x0;

	/* copy logo to sys_logo_start (next to top of sp) */
	a = (unsigned char *)sys_logo_start;
	b = (unsigned char *)ext_para_ptr->logo_img_saddr;
	memcpy(a, b, ext_para_ptr->logo_img_len);

	/* this value will save the 1st picture addr*/
	*(volatile unsigned int *)LOGO1_START_ADDR = SWAPEND32((uint)a);
	*(volatile unsigned int *)LOGO1_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo_offset);

	a += ext_para_ptr->logo_img_len;

	/* copy logo 2 */
	if (ext_para_ptr->logo2_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo2_img_saddr;
		memcpy(a, b, ext_para_ptr->logo2_img_len);

        /* this value will save the 2nd picture addr*/
		*(volatile unsigned int *)LOGO2_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO2_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo2_offset);

		a += ext_para_ptr->logo2_img_len;
	}

	/* copy logo 3 */
	if (ext_para_ptr->logo3_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo3_img_saddr;
		memcpy(a, b, ext_para_ptr->logo3_img_len);

		/* this value will save the 3rd picture addr*/
		*(volatile unsigned int *)LOGO3_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO3_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo3_offset);

		a += ext_para_ptr->logo3_img_len;
	}

	/* copy logo 4 */
	if (ext_para_ptr->logo4_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo4_img_saddr;
		memcpy(a, b, ext_para_ptr->logo4_img_len);

		/* this value will save the 4th picture addr*/
		*(volatile unsigned int *)LOGO4_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO4_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo4_offset);

		a += ext_para_ptr->logo4_img_len;
	}

	/* copy logo 5 */
	if (ext_para_ptr->logo5_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo5_img_saddr;
		memcpy(a, b, ext_para_ptr->logo5_img_len);

		/* this value will save the 5th picture addr*/
		*(volatile unsigned int *)LOGO5_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO5_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo5_offset);

		a += ext_para_ptr->logo5_img_len;
	}

	/* copy logo 6 */
	if (ext_para_ptr->logo6_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo6_img_saddr;
		memcpy(a, b, ext_para_ptr->logo6_img_len);

		/* this value will save the 6th picture addr*/
		*(volatile unsigned int *)LOGO6_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO6_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo6_offset);

		a += ext_para_ptr->logo6_img_len;
	}

	/* copy logo 7 */
	if (ext_para_ptr->logo7_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo7_img_saddr;
		memcpy(a, b, ext_para_ptr->logo7_img_len);

		/* this value will save the 7th picture addr*/
		*(volatile unsigned int *)LOGO7_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO7_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo7_offset);

		a += ext_para_ptr->logo7_img_len;
	}

	/* copy logo 8 */
	if (ext_para_ptr->logo8_img_len != 0) {
		b = (unsigned char *)ext_para_ptr->logo8_img_saddr;
		memcpy(a, b, ext_para_ptr->logo8_img_len);

		/* this value will save the 8th picture addr*/
		*(volatile unsigned int *)LOGO8_START_ADDR = SWAPEND32((uint)a);
		*(volatile unsigned int *)LOGO8_END_ADDR = SWAPEND32((uint)a+ext_para_ptr->logo8_offset);

		a += ext_para_ptr->logo7_img_len;
	}

//	sys_sync();

	/* transform logo color lookup table from ext_para_ptr */

	/* we offer 5 roller logos for Video using */
	LOGO_decode_CLUT(ext_para_ptr->logo_reg_5370, (uchar *)(LOGO1_CLUT_ADDR + 0));
	LOGO_decode_CLUT(ext_para_ptr->logo_reg_5374, (uchar *)(LOGO1_CLUT_ADDR + 3));
	LOGO_decode_CLUT(ext_para_ptr->logo_reg_5378, (uchar *)(LOGO1_CLUT_ADDR + 6));
	LOGO_decode_CLUT(ext_para_ptr->logo_reg_537c, (uchar *)(LOGO1_CLUT_ADDR + 9));

	if (ext_para_ptr->logo2_img_len != 0) {
		LOGO_decode_CLUT(ext_para_ptr->logo2_reg_5370, (uchar *)(LOGO2_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo2_reg_5374, (uchar *)(LOGO2_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo2_reg_5378, (uchar *)(LOGO2_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo2_reg_537c, (uchar *)(LOGO2_CLUT_ADDR + 9));
	}

	if (ext_para_ptr->logo3_img_len != 0) {
		LOGO_decode_CLUT(ext_para_ptr->logo3_reg_5370, (uchar *)(LOGO3_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo3_reg_5374, (uchar *)(LOGO3_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo3_reg_5378, (uchar *)(LOGO3_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo3_reg_537c, (uchar *)(LOGO3_CLUT_ADDR + 9));
	}

	if (ext_para_ptr->logo4_img_len != 0) {
		LOGO_decode_CLUT(ext_para_ptr->logo4_reg_5370, (uchar *)(LOGO4_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo4_reg_5374, (uchar *)(LOGO4_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo4_reg_5378, (uchar *)(LOGO4_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo4_reg_537c, (uchar *)(LOGO4_CLUT_ADDR + 9));
	}

	if (ext_para_ptr->logo5_img_len != 0) {
		LOGO_decode_CLUT(ext_para_ptr->logo5_reg_5370, (uchar *)(LOGO5_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo5_reg_5374, (uchar *)(LOGO5_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo5_reg_5378, (uchar *)(LOGO5_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo5_reg_537c, (uchar *)(LOGO5_CLUT_ADDR + 9));
	}

	if ((ext_para_ptr->logo2_img_len != 0) &&
		(ext_para_ptr->logo3_img_len != 0) &&
		(ext_para_ptr->logo4_img_len != 0) &&
		(ext_para_ptr->logo5_img_len != 0) )
	{
		/* this value will set rolling picture  */
		*(volatile unsigned int *)LOGO_MAGIC_ADDR = 0x78beadde;
	}
	else
	{
		*(volatile unsigned int *)LOGO_MAGIC_ADDR = 0;
	}

//	sys_dcache_flush_all();
	LOGO_DISP_setup( ext_para_ptr );

#ifdef CONFIG_SYS_LOGO_DISP // Board_PANEL_NULL
	disable_force_bg();
#endif

	return 0;
}


void LOGO_DISP_change(uint logo_no)
{

	/* this value will set still picture  */
	*(volatile unsigned int *)LOGO_MAGIC_ADDR = (logo_no << 24)&0xff000000 | 0xbeadde ;

	if ((logo_no == 5) && (ext_para_ptr->logo6_img_len != 0))
	{
//		memcpy((unsigned char *)sys_logo_start,
//		       (unsigned char *)ext_para_ptr->logo6_img_saddr,
//		                        ext_para_ptr->logo6_img_len);

		/* transform logo color lookup table from ext_para_ptr */

		LOGO_decode_CLUT(ext_para_ptr->logo6_reg_5370, (uchar *)(LOGO6_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo6_reg_5374, (uchar *)(LOGO6_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo6_reg_5378, (uchar *)(LOGO6_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo6_reg_537c, (uchar *)(LOGO6_CLUT_ADDR + 9));
	}
	else if ((logo_no == 6) && (ext_para_ptr->logo7_img_len != 0))
	{
//		memcpy((unsigned char *)sys_logo_start,
//		       (unsigned char *)ext_para_ptr->logo7_img_saddr,
//		                        ext_para_ptr->logo7_img_len);
			/* transform logo color lookup table from ext_para_ptr */

		LOGO_decode_CLUT(ext_para_ptr->logo7_reg_5370, (uchar *)(LOGO7_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo7_reg_5374, (uchar *)(LOGO7_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo7_reg_5378, (uchar *)(LOGO7_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo7_reg_537c, (uchar *)(LOGO7_CLUT_ADDR + 9));
	}
	else if ((logo_no == 7) && (ext_para_ptr->logo8_img_len != 0))

	{
//		memcpy((unsigned char *)sys_logo_start,
//		       (unsigned char *)ext_para_ptr->logo8_img_saddr,
//		                        ext_para_ptr->logo8_img_len);
		/* transform logo color lookup table from ext_para_ptr */

		LOGO_decode_CLUT(ext_para_ptr->logo8_reg_5370, (uchar *)(LOGO8_CLUT_ADDR + 0));
		LOGO_decode_CLUT(ext_para_ptr->logo8_reg_5374, (uchar *)(LOGO8_CLUT_ADDR + 3));
		LOGO_decode_CLUT(ext_para_ptr->logo8_reg_5378, (uchar *)(LOGO8_CLUT_ADDR + 6));
		LOGO_decode_CLUT(ext_para_ptr->logo8_reg_537c, (uchar *)(LOGO8_CLUT_ADDR + 9));
	}

//	sys_sync();
//	LOGO_DISP_setup( ext_para_ptr );
}

/************************************************************************
 * Decode one logo color lookup table register value into array
 *
 *-------------------------------------------------------------
 *          Input: logo_reg_537X (Neptune format)             *
 *-------------------------------------------------------------
 *
 *          +------+------+------+------+
 *          |    0    |    cr   |    cb   |    y    |
 *          +------+------+------+------+
 *     bit 31                                           0
 *
 *-------------------------------------------------------------
 *          Output: CLUT table array (Mars format)            *
 *-------------------------------------------------------------
 *
 * address of the CLUT table should be 8 byte aligned.
 * y cr cb ... 63 107 165 85 109 165 137 116 152 235 128 128
 * address     val
 * 0x00       0x3f
 * 0x01       0x6b
 * 0x02       0xa5
 * 0x03       0x55
 * 0x04       0x6d
 * 0x05       0xa5
 * 0x06       0x89
 * 0x07       0x74
 * 0x08       0x98
 * 0x09       0xeb
 * 0x0a       0x80
 * 0x0b       0x80
 ************************************************************************/
static void  LOGO_decode_CLUT(uint logo_reg_537X, unsigned char *clut_addr)
{
	unsigned char y, cb, cr;
	/* transform YCrCb to RBG for darwin */
	unsigned char r, g, b;

	y  = logo_reg_537X & 0xff;
	cb = (logo_reg_537X >> 8) & 0xff;
	cr = (logo_reg_537X >> 16) & 0xff;

	*(volatile unsigned char *)(clut_addr + 0) = y;
	*(volatile unsigned char *)(clut_addr + 1) = cr;
	*(volatile unsigned char *)(clut_addr + 2) = cb;

    r = (1164*(y-16) + 1596*(cr-128)) / 1000 ;                 /* R */
    g = (1164*(y-16) -  813*(cr-128) -  391*(cb-128)) / 1000 ; /* G */
    b = (1164*(y-16)                 + 2018*(cb-128)) / 1000 ; /* B */

	*(volatile unsigned char *)(clut_addr + 0) = r;
	*(volatile unsigned char *)(clut_addr + 1) = b;
	*(volatile unsigned char *)(clut_addr + 2) = g;
}

