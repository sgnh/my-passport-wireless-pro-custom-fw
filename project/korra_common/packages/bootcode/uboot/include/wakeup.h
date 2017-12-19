
#ifndef  __MISC_MGR_WAKEUP_H__
#define  __MISC_MGR_WAKEUP_H__

typedef enum {
	PP_HDMI1 = 0,
	PP_HDMI2,
	PP_HDMI3,
	PP_VGA1,
	PP_VGA2,
	PP_VGA3,
	PP_AV1,
	PP_AV2,
	PP_AV3,
	PP_SOURCE_MAX,
} PP_SOURCE_T;

typedef enum {
    WKSOR_UNDEF,
    WKSOR_KEYPAD,
    WKSOR_WUT,
    WKSOR_IRDA,
    WKSOR_CEC,
    WKSOR_PPS,
} WAKE_UP_T;

extern void rtkpm_clr_pm_task(unsigned int loc);
extern void rtkpm_clr_share_mem(void);
extern void rtkpm_show_share_mem(void);
extern void powerMgr_setup_keypad(unsigned long long param);
extern void powerMgr_setup_keypad_multi(unsigned int num,unsigned long long * param);
extern void powerMgr_setup_wakeup_timer(int days, int hours, int mins);
extern void powerMgr_setup_cec(unsigned int param);
extern void powerMgr_setup_ppsource(PP_SOURCE_T pp_source);
extern void powerMgr_setup_irda( unsigned int protocol ,
                                 unsigned int key_num,
                                 unsigned int * key_array );
extern void powerMgr_setup_power_en(unsigned int pw_num,
                                    unsigned long long * pw_array );
extern void powerMgr_get_sleep_dur(unsigned int * dur_ary);
extern unsigned int powerMgr_get_wakeup_source(void);


typedef enum
{
    BOOTTYPE_UNKNOWN_BOOTTYPE=0,
    BOOTTYPE_NL_BIG_ROOTFS,
    BOOTTYPE_NL_SMALL_ROOTFS,
    BOOTTYPE_TMP_RESCUE,
    BOOTTYPE_NATIVE_RESCUE,
    BOOTTYPE_COMPLETE
} E_BOOTTYPE;

extern int wd_unchange_data_set_bootcode_enter_rescue(void);
extern E_BOOTTYPE wd_unchange_data_get_boottype(void);
extern void  wd_unchange_data_clear_boottype(void) ;

#endif

/* end of file */


