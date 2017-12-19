

/************************************************************************
 *  Include files
 ************************************************************************/

//#include <sysdefs.h>
//#include <sys_api.h>
//#include <syscon_api.h>
//#include <env_api.h>
//#include <env.h>
//#include <product.h>

//#include <syserror.h>
//#include <stdio.h>
//#include <string.h>
#include <common.h>
#include <malloc.h>
#include <linux/ctype.h>

#include <asm/arch/panelConfigParameter.h>

#if defined(VBY_ONE_PANEL_CMI_V500_4K2K_VBY1)
#include <asm/arch/panel/CMI_V500_4K2K_VBY1.h>
#elif defined(VBY_ONE_PANEL_CHINA_STAR_4K2K_VBY1)
#include <asm/arch/panel/China_Star_4K2K_VBY1.h>
#elif defined(LVDS_PANEL_TSB_CMI_V400HJ2_PE1_REVC1)
#include <asm/arch/panel/CMI_V400HJ2-PE1_REVC1.h>
#elif defined(LVDS_PANEL_TSB_SAMSUNG_LSC400HM03)
#include <asm/arch/panel/tsb_samsung_lsc400hm03.h>
#elif defined(CONFIG_PANEL_NAME)
#include CONFIG_PANEL_NAME
#else
#include <asm/arch/panel/default_panel.h>
#endif

#include <asm/arch/factorylib.h>

/************************************************************************
 *  Definitions
 ************************************************************************/
//#define PANEL_ADJUST_PRINT	printf
#define PANEL_ADJUST_PRINT

/************************************************************************
 *  Public variables
 ************************************************************************/
struct _PANEL_CONFIG_PARAMETER  default_panel_parameter;
//UINT8 LVDS_4_PORTS_INDEX;
/************************************************************************
 *  Static variables
 ************************************************************************/

/* Default settings of env. variables */



/************************************************************************
 *  Static function prototypes
 ************************************************************************/

/************************************************************************
 *  Implementation : Static functions
 ************************************************************************/


#define MAXUINT(w)	(\
		((w) == sizeof(UINT8))  ? 0xFFU :\
		((w) == sizeof(UINT16)) ? 0xFFFFU :\
		((w) == sizeof(UINT32)) ? 0xFFFFFFFFU : 0\
		        )

unsigned long
strtoul(
	const 	char 	*str,
		char 	**endptr,
		int 	base)
{
	const char *s;
	unsigned long acc, cutoff;
	int c;
	int neg, any, cutlim;

	/*
	 * See strtol for comments as to the logic used.
	 */
	s = str;
	do {
		c = (unsigned char) *s++;
	} while (isspace(c));
	if (c == '-') {
		neg = 1;
		c = *s++;
	} else {
		neg = 0;
		if (c == '+')
			c = *s++;
	}
	if ((base == 0 || base == 16) &&
	    c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;

	cutoff = MAXUINT(sizeof(UINT32)) / (unsigned long)base;
	cutlim = MAXUINT(sizeof(UINT32)) % (unsigned long)base;
	for (acc = 0, any = 0;; c = (unsigned char) *s++) {
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0)
			continue;
		if ((acc > cutoff) || (acc == cutoff && c > cutlim)) {
			any = -1;
			acc = MAXUINT(sizeof(UINT32));
			/* errno = ERANGE; */
		} else {
			any = 1;
			acc *= (unsigned long)base;
			acc += c;
		}
	}
	if (neg && any > 0)
		acc = -acc;
	if (endptr != 0)
		*endptr = (char *) (any ? s - 1 : (char *) str);
	return (acc);
}

uint env_panel_change_panel_bin_in_factory(char *panel_bin_path)
{
	int ret = 0;

	ret = factory_delete(panel_bin_path);
	if (ret)
	{
		printf("[ERR] remove %s failed\n", panel_bin_path);
	}

	ret = factory_write(panel_bin_path, (char *)&default_panel_parameter, sizeof(default_panel_parameter));
	if (ret)
	{
		printf("[ERR] write %s failed\n", panel_bin_path);
	}

	ret = factory_save();
	if (ret)
	{
		printf("[ERR] save facroty failed\n");
	}

	return ret;
}

void env_panel_set_default(void)
{
	default_panel_parameter.iCONFIG_DISPLAY_PORT					= CONFIG_DISPLAY_PORT ;
	default_panel_parameter.iCONFIG_DISPLAY_COLOR_BITS				= CONFIG_DISPLAY_COLOR_BITS ;
	default_panel_parameter.iCONFIG_DISPLAY_EVEN_RSV1_BIT			= CONFIG_DISPLAY_EVEN_RSV1_BIT ;
	default_panel_parameter.iCONFIG_DISPLAY_ODD_RSV1_BIT			= CONFIG_DISPLAY_ODD_RSV1_BIT ;
	default_panel_parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE		= CONFIG_DISPLAY_BITMAPPING_TABLE ;
	default_panel_parameter.iCONFIG_DISPLAY_PORTAB_SWAP 			= CONFIG_DISPLAY_PORTAB_SWAP ;
	default_panel_parameter.iCONFIG_DISPLAY_RED_BLUE_SWAP			= CONFIG_DISPLAY_RED_BLUE_SWAP ;
	default_panel_parameter.iCONFIG_DISPLAY_MSB_LSB_SWAP			= CONFIG_DISPLAY_MSB_LSB_SWAP ;
	default_panel_parameter.iCONFIG_DISPLAY_SKEW_DATA_OUTPUT		= CONFIG_DISPLAY_SKEW_DATA_OUTPUT ;
	default_panel_parameter.iCONFIG_DISPLAY_OUTPUT_INVERSE			= CONFIG_DISPLAY_OUTPUT_INVERSE ;
	default_panel_parameter.iCONFIG_DISPLAY_VERTICAL_SYNC_NORMAL	= CONFIG_DISPLAY_VERTICAL_SYNC_NORMAL ;
	default_panel_parameter.iCONFIG_DISPLAY_HORIZONTAL_SYNC_NORMAL	= CONFIG_DISPLAY_HORIZONTAL_SYNC_NORMAL ;
	default_panel_parameter.iCONFIG_DISPLAY_RATIO_4X3				= CONFIG_DISPLAY_RATIO_4X3 ;
	default_panel_parameter.iCONFIG_DISPLAY_CLOCK_MAX				= CONFIG_DISPLAY_CLOCK_MAX ;
	default_panel_parameter.iCONFIG_DISPLAY_CLOCK_MIN				= CONFIG_DISPLAY_CLOCK_MIN ;
	default_panel_parameter.iCONFIG_DISPLAY_REFRESH_RATE			= CONFIG_DISPLAY_REFRESH_RATE ;
	default_panel_parameter.iCONFIG_DISPLAY_CLOCK_TYPICAL			= CONFIG_DISPLAY_CLOCK_TYPICAL ;
	default_panel_parameter.iCONFIG_DISP_HORIZONTAL_TOTAL			= CONFIG_DISP_HORIZONTAL_TOTAL ;
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL 			= CONFIG_DISP_VERTICAL_TOTAL ;
	default_panel_parameter.iCONFIG_DISP_HSYNC_WIDTH				= CONFIG_DISP_HSYNC_WIDTH ;
	default_panel_parameter.iCONFIG_DISP_VSYNC_LENGTH				= CONFIG_DISP_VSYNC_LENGTH ;
	default_panel_parameter.iCONFIG_DISP_DEN_STA_HPOS				= CONFIG_DISP_DEN_STA_HPOS ;
	default_panel_parameter.iCONFIG_DISP_DEN_END_HPOS				= CONFIG_DISP_DEN_END_HPOS ;
	default_panel_parameter.iCONFIG_DISP_DEN_STA_VPOS				= CONFIG_DISP_DEN_STA_VPOS ;
	default_panel_parameter.iCONFIG_DISP_DEN_END_VPOS				= CONFIG_DISP_DEN_END_VPOS ;
	default_panel_parameter.iCONFIG_DISP_ACT_STA_HPOS				= CONFIG_DISP_ACT_STA_HPOS ;
	default_panel_parameter.iCONFIG_DISP_ACT_END_HPOS				= CONFIG_DISP_ACT_END_HPOS ;
	default_panel_parameter.iCONFIG_DISP_ACT_STA_VPOS				= CONFIG_DISP_ACT_STA_VPOS ;
	default_panel_parameter.iCONFIG_DISP_ACT_END_VPOS				= CONFIG_DISP_ACT_END_VPOS ;
	default_panel_parameter.iCONFIG_DISP_HSYNC_LASTLINE 			= CONFIG_DISP_HSYNC_LASTLINE ;
	default_panel_parameter.iCONFIG_DISP_DCLK_DELAY 				= CONFIG_DISP_DCLK_DELAY ;
	default_panel_parameter._iCONFIG_DISP_ACT_STA_BIOS				= _CONFIG_DISP_ACT_STA_BIOS ;
	default_panel_parameter.iCONFIG_DEFAULT_DPLL_M_DIVIDER			= CONFIG_DEFAULT_DPLL_M_DIVIDER ;
	default_panel_parameter.iCONFIG_DEFAULT_DPLL_N_DIVIDER			= CONFIG_DEFAULT_DPLL_N_DIVIDER ;
	default_panel_parameter.iPANEL_TO_LVDS_ON_ms					= PANEL_TO_LVDS_ON_ms ;
	default_panel_parameter.iLVDS_TO_LIGHT_ON_ms					= LVDS_TO_LIGHT_ON_ms ;
	default_panel_parameter.iLIGHT_TO_LDVS_OFF_ms					= LIGHT_TO_LDVS_OFF_ms ;
	default_panel_parameter.iLVDS_TO_PANEL_OFF_ms					= LVDS_TO_PANEL_OFF_ms ;
	default_panel_parameter.iPANEL_OFF_TO_ON_ms 					= PANEL_OFF_TO_ON_ms ;
	default_panel_parameter.iCONFIG_BACKLIGHT_PWM_FREQ				= CONFIG_BACKLIGHT_PWM_FREQ ;
	default_panel_parameter.iCONFIG_BACKLIGHT_PWM_DUTY				= CONFIG_BACKLIGHT_PWM_DUTY ;
	default_panel_parameter.iFIX_LAST_LINE_ENABLE					= FIX_LAST_LINE_ENABLE ;
	default_panel_parameter.iFIX_LAST_LINE_4X_ENABLE				= FIX_LAST_LINE_4X_ENABLE ;
	default_panel_parameter.iVFLIP									= CONFIG_VFLIP_ON ;
	default_panel_parameter.iPICASSO_CONTROL_ON 					= CONFIG_PICASSO_CONTROL_ON ;
	default_panel_parameter.i3D_DISPLAY_SUPPORT 					= CONFIG_3D_DISPLAY_SUPPORT_ON ;
	default_panel_parameter.i3D_LINE_ALTERNATIVE_SUPPORT			= CONFIG_3D_LINE_ALTERNATIVE_ON ;
	default_panel_parameter.i3D_PR_OUTPUT_LR_SWAP					= CONFIG_3D_PR_OUTPUT_LR_SWAP ;
	default_panel_parameter.i3D_SG_OUTPUT_120HZ_ON					= CONFIG_3D_SG_OUTPUT_120HZ_ON ;
	default_panel_parameter.i3D_SG_24HZ_OUTPUT_FHD_ON				= CONFIG_3D_SG_24HZ_OUTPUT_FHD_ON ;
	default_panel_parameter.iSCALER_2D_3D_CVT_HWSHIFT_ENABLE		= CONFIG_SCALER_2D_3D_CVT_HWSHIFT_ON ;
	default_panel_parameter.iCONFIG_SFG_SEG_NUM 					= CONFIG_SFG_SEG_NUM;
	default_panel_parameter.iCONFIG_SFG_PORT_NUM					= CONFIG_SFG_PORT_NUM;
	default_panel_parameter.iCONFIG_DISPLAY_PORT_CONFIG1			= CONFIG_DISPLAY_PORT_CONFIG1;
	default_panel_parameter.iCONFIG_DISPLAY_PORT_CONFIG2			= CONFIG_DISPLAY_PORT_CONFIG2;

#ifdef CONFIG_LVDS_4_PORTS_INDEX
	default_panel_parameter.iCONFIG_LVDS_4_PORTS_INDEX				= CONFIG_LVDS_4_PORTS_INDEX;
#else
	default_panel_parameter.iCONFIG_LVDS_4_PORTS_INDEX				= 0;
#endif

#ifdef CONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN	= CONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN;
#else
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN	= 0;
#endif

#ifdef CONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX	= CONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX;
#else
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX	= 0;
#endif

#ifdef CONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN	= CONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN;
#else
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN	= 0;
#endif

#ifdef CONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX	= CONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX;
#else
	default_panel_parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX	= 0;
#endif

#ifdef CONFIG_LVDS_PN_SWAP
	default_panel_parameter.iCONFIG_LVDS_PN_SWAP	= 1;
	printf(" LVDS_PN_SWAP ON \n ");
#else
	default_panel_parameter.iCONFIG_LVDS_PN_SWAP	= 0;
#endif

#ifdef CONFIG_LVDS_MIRROR
	default_panel_parameter.iCONFIG_LVDS_MIRROR 	= 1;
	printf(" Rescue_With_Lvds_Mirror ON \n ");
#else
	default_panel_parameter.iCONFIG_LVDS_MIRROR 	= 0;
#endif

#ifdef CONFIG_PANEL_TYPE
	default_panel_parameter.iCONFIG_PANEL_TYPE 	= CONFIG_PANEL_TYPE;
#else
	default_panel_parameter.iCONFIG_PANEL_TYPE 	= 0;
#endif

#ifdef CONFIG_PANEL_CUSTOM_INDEX
	default_panel_parameter.iCONFIG_PANEL_CUSTOM_INDEX = CONFIG_PANEL_CUSTOM_INDEX;
#else
	default_panel_parameter.iCONFIG_PANEL_CUSTOM_INDEX	= 0;
#endif

	//Reserve some parametets for use.
	default_panel_parameter.iCONFIG_DISP_RESVER05	= 0;
	default_panel_parameter.iCONFIG_DISP_RESVER06	= 0;
	default_panel_parameter.iCONFIG_SR_MODE 		= CONFIG_SR_MODE;
	default_panel_parameter.iCONFIG_SR_PIXEL_MODE	= CONFIG_SR_PIXEL_MODE;

	strcpy(default_panel_parameter.sPanelName, CONFIG_DISP_PANEL_NAME);
}

uchar env_setup_env_panel(uchar *panel_filename)
{
	char *raw_ptr = NULL;
	uint parameter_len = 0;
	unsigned int rc = 1;	/* 0:fail 1:success */
	int file_len = 0;
	int i = 0;
	char tmp_str[3] = {0};
	char *raw1 = NULL;
	char *raw2 = NULL;
	char *raw3 = NULL;
#if 0 // debug
	unsigned char* p;
#endif

	parameter_len = sizeof(default_panel_parameter);

	if (panel_filename == NULL) // set default value
	{
		env_panel_set_default();
	}
	else
	{
		/* read panel parameter from factory */
		if ((factory_read((char *)panel_filename, &raw_ptr, &file_len) == 0) && file_len == parameter_len) {
			memcpy(&default_panel_parameter, raw_ptr, sizeof(default_panel_parameter));

			printf("Panel: Use parameters in %s\n", panel_filename);
		}
		else {
			if (file_len != 0) {
				printf("Panel: Use default config (panel.bin size is not matched)\n");
				printf("[WARN] size of panel.bin is 0x%x\n", file_len);
				printf("[WARN] size of default_panel_parameter is 0x%x\n", parameter_len);
			}
			else{
				printf("Panel: Use default config (%s is not found)\n", panel_filename);
			}
			//reset to default panel
			env_panel_set_default();
		}

		printf("Panel: %s\n", default_panel_parameter.sPanelName);
	}

	raw1 = malloc(128);
	raw2 = malloc(128);
	raw3 = malloc(128);

	if ((raw1 == NULL) || (raw2 == NULL) || (raw3 == NULL))
	{
		printf("[ERR] %s:%d: malloc for raw data failed\n", __FUNCTION__, __LINE__);
		return 0;
	}

	/***********************************************
	 * FIXME: use magic number here is a bad decision !!!!!!!!!!
	 ***********************************************/

	/* generate panel env */
	for (i = 0 ; i < 50 ; i++)
		sprintf( raw1+2*i, "%.2x", *((UINT8 *)&default_panel_parameter+i));

	if (parameter_len < 100)
	{
		for (i = 50 ; i < parameter_len ; i++)
			sprintf( raw2+2*(i-50), "%.2x", *((UINT8 *)&default_panel_parameter+i));
	}
	else
	{
		for (i = 50 ; i < 100 ; i++)
			sprintf( raw2+2*(i-50), "%.2x", *((UINT8 *)&default_panel_parameter+i));

		for (i = 100 ; i < parameter_len ; i++)
			sprintf( raw3+2*(i-100), "%.2x", *((UINT8 *)&default_panel_parameter+i));
	}

//	printf("sizeof(default_panel_parameter)=%d \n", parameter_len);//hcy test

#if 0 // debug
	printf("bootcode inside panel parameter\n" ) ;
	p = (unsigned char*)&default_panel_parameter  ;

	for (i=0; i < sizeof(default_panel_parameter); i++) {
		if (i%16 == 0)
			printf("\n %02x",*p++ ) ;
		else
			printf(" %02x",*p++ ) ;
	}
	printf("\n" ) ;
#endif

	/* set panel_parameter1 */
	raw_ptr = raw1; /* Create new */

	if (setenv("panel_parameter_1", raw_ptr))
	{
		rc = 0;
	}

	for (i = 0 ; i < 50 ; i++)
	{
		strncpy(tmp_str, raw_ptr+2*i, 2);
		tmp_str[2] = '\0';
		*((UINT8 *)&default_panel_parameter+i) = strtoul(tmp_str, (char **)NULL, 16);
	}

	if (parameter_len < 100) // paramter size is less than 100, only need use two raws
	{
		/* set panel_parameter2 */
		raw_ptr = raw2;  /* Create new */

		if (setenv("panel_parameter_2", raw_ptr))
		{
			rc = 0;
		}

		for (i = 50 ; i < parameter_len ; i++)
		{
			strncpy(tmp_str, raw_ptr+2*(i-50), 2);
			tmp_str[2] = '\0';
			*((UINT8 *)&default_panel_parameter+i) = strtoul(tmp_str, (char **)NULL, 16);
		}
	}
	else
	{
		/* set panel_parameter2 */
		raw_ptr = raw2;  /* Create new */
		if (setenv("panel_parameter_2", raw_ptr))
		{
			rc = 0;
		}

		for (i = 50 ; i < 100 ; i++)
		{
			strncpy(tmp_str, raw_ptr+2*(i-50), 2);
			tmp_str[2] = '\0';
			*((UINT8 *)&default_panel_parameter+i) = strtoul(tmp_str, (char **)NULL, 16);
		}

		/* set panel_parameter3 */
		raw_ptr = raw3;  /* Create new */
		if (setenv("panel_parameter_3", raw_ptr))
		{
			rc = 0;
		}

		for (i = 100 ; i < parameter_len  ; i++)
		{
			strncpy(tmp_str, raw_ptr+2*(i-100), 2);
			tmp_str[2] = '\0';
			*((UINT8 *)&default_panel_parameter+i) = strtoul(tmp_str, (char **)NULL, 16);
		}
	}

//	LVDS_4_PORTS_INDEX = default_panel_parameter.iCONFIG_LVDS_4_PORTS_INDEX;

#if 0 // debug
	printf("\n\nenv's final panel parameter\n" ) ;
	p = (unsigned char*)&default_panel_parameter  ;

	for (i=0; i< sizeof(default_panel_parameter); i++) {
		if (i%16 == 0)
			printf("\n %02x",*p++ ) ;
		else
			printf(" %02x",*p++ ) ;
	}
	printf("\n" ) ;
#endif

	/* set panel_file_name */
	raw_ptr = default_panel_parameter.sPanelName;
	if (setenv("panel_file_name", raw_ptr))
	{
		rc = 0;
	}

	free((void *)raw1);
	free((void *)raw2);
	free((void *)raw3);

	return rc;
}

