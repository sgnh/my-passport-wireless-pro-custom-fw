#include <common.h>
#include <asm/arch/system.h>
#include <wakeup.h>
#include <platform_lib/board/pcb_mgr.h>

#define SHT_KEYPAD     0
#define SHT_CEC        1
#define SHT_PPS        2
#define SHT_WUT        3
#define SHT_IRDA       4
#define SHT_PWEN       5

#ifdef CONFIG_ENABLE_SOS_FUNCTION
#define SHT_SOS		6
#endif //#ifdef CONFIG_ENABLE_SOS_FUNCTION

#define loc_keypad     4*SHT_KEYPAD
#define loc_cec        4*SHT_CEC
#define loc_pps        4*SHT_PPS
#define loc_wut        4*SHT_WUT
#define loc_irda       4*SHT_IRDA
#define loc_pwen       4*SHT_PWEN
#ifdef CONFIG_ENABLE_SOS_FUNCTION
#define loc_sos		4*SHT_SOS
#endif //#ifdef CONFIG_ENABLE_SOS_FUNCTION

#define SHT_GPIO_ADR    0
#define SHT_GPIO_BIT    8
#define SHT_GPIO_IVR    16
#define SHT_GPIO_TYP    20


#define RTD_SHARE_MEM_LEN       64

#define RTD_SHARE_MEM_BASE      0xb8060500
#define PM_EVENT_MSG            RTD_SHARE_MEM_BASE

#define PARAM_LEN_KEYPAD        10
#define PARAM_LEN_PPS           1
#define PARAM_LEN_WUT           1
#define PARAM_LEN_IRDA          16
#define PARAM_LEN_PWEN          3
#define PARAM_LEN_TDUR          2
#define PARAM_LEN_WK_SOR        1
#ifdef CONFIG_ENABLE_SOS_FUNCTION
#define PARAM_LEN_SOS			4
#endif //#ifdef CONFIG_ENABLE_SOS_FUNCTION

#define IDX_REG_INDEX           0                                   //reg0 for index
#define IDX_REG_KEYPAD          1                                   //reg1~10
#define IDX_REG_PPS             (IDX_REG_KEYPAD+PARAM_LEN_KEYPAD)         //reg11
#define IDX_REG_WUT             (IDX_REG_PPS+PARAM_LEN_PPS)         //reg12
#define IDX_REG_IRDA            (IDX_REG_WUT+PARAM_LEN_WUT)         //reg13~28
#define IDX_REG_PWEN            (IDX_REG_IRDA+PARAM_LEN_IRDA)       //reg29~31

//backward counting
#define IDX_REG_TIME_DUR        (RTD_SHARE_MEM_LEN-PARAM_LEN_TDUR)  //reg30~31
#define IDX_REG_WK_SOR          (IDX_REG_TIME_DUR-PARAM_LEN_WK_SOR) //reg29
#define IDX_REG_CUR_TIME        IDX_REG_PPS                         //reg11 <==this location share with PPS

#define SET_KEYPAD_PARM_H(parm)     rtd_outl(RTD_SHARE_MEM_BASE+4*IDX_REG_KEYPAD,parm);
#define SET_KEYPAD_PARM_L(parm)     rtd_outl(RTD_SHARE_MEM_BASE+4*(IDX_REG_KEYPAD+1),parm)
#define SET_KEYPAD_PARM_E(parm)     rtd_outl(RTD_SHARE_MEM_BASE+4*(IDX_REG_KEYPAD+2),parm)
#define SET_KEYPAD_PARM(num,parm)   rtd_outl(RTD_SHARE_MEM_BASE+4*(IDX_REG_KEYPAD+num),parm)
#define GET_PPS_PARM()      rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_PPS) & 0x000000FF
#define GET_CUR_TIME()      rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_PPS) & 0xFFFFFF00
#define SET_PPS_PARM(parm)  rtd_outl(RTD_SHARE_MEM_BASE+4*IDX_REG_PPS,GET_CUR_TIME()|(parm & 0x000000FF))
#define SET_CUR_TIME(parm)  rtd_outl(RTD_SHARE_MEM_BASE+4*IDX_REG_PPS,(parm & 0xFFFFFF00)|GET_PPS_PARM())
#define SET_WUT_PARM(parm)          rtd_outl(RTD_SHARE_MEM_BASE+4*IDX_REG_WUT,parm)
#define SET_IRDA_PARM(num,parm)     rtd_outl(RTD_SHARE_MEM_BASE+4*(IDX_REG_IRDA+num),parm)
#define SET_PWEN_PARM(num,parm)     rtd_outl(RTD_SHARE_MEM_BASE+4*(IDX_REG_PWEN+num),parm)

#define GET_EVENT_MSG()             rtd_inl(PM_EVENT_MSG)
#define SET_EVENT_MSG(msg)          rtd_outl(PM_EVENT_MSG,msg)
#define SET_EVENT_IDX(msg,loc,idx)  msg = ((msg & ~(0xf<<loc))|(idx<<loc))

#define GET_TIME_DUR(x,y)           x = rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_TIME_DUR); \
                                    y = rtd_inl(RTD_SHARE_MEM_BASE+4*(IDX_REG_TIME_DUR+1))

#define GET_WK_SOR()               rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_WK_SOR)

unsigned int get_gpio_info(unsigned char GPIO_NUM)
{
	unsigned int loop=0;
	unsigned int bitOffset=0;
    unsigned int regAddr=0;

    while(loop < 2){    //iso gpio have 2 set only
        if(GPIO_NUM <= (31+(32*loop))){
            bitOffset = GPIO_NUM - (32*loop);
            regAddr = loop*4;
            return ((bitOffset<<SHT_GPIO_BIT) | regAddr );
        }
        loop++;
    }
    return 0;
}

void rtkpm_clr_pm_task(unsigned int loc)
{
    unsigned int msg;
    char str[][8]={"KEYPAD","CEC","PPS",
                    "WUT","IRDA","PWEN"};

    printf("\n(%s)2012/05/09 15:55\n",__func__);
    printf("\n%sYou like to clear %s task.\n",__func__,str[loc]);
    msg = GET_EVENT_MSG();
    msg &= ~(0xf<<(loc*4));
    SET_EVENT_MSG(msg);
    printf("pm_event_msg=0x%x\n",msg);
}

void rtkpm_clr_share_mem(void)
{
    int i;

    printf("\n(%s)2013/04/23 14:55\n",__func__);
    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        rtd_outl(RTD_SHARE_MEM_BASE+(4*i),0);
    }
}

void rtkpm_show_share_mem(void)
{
    int i;

    printf("\n(%s)2012/05/09 15:55\n",__func__);
    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        printf("mem[%i]=0x%x\n",i,rtd_inl(RTD_SHARE_MEM_BASE+(4*i)));
    }
}

void powerMgr_setup_keypad_multi(unsigned int num,unsigned long long* param)
{
    unsigned int para_tmp;
    unsigned int pm_event_msg;
    unsigned char kptype;
    unsigned char kpidx;
    unsigned char param1;
    unsigned char param2;
    unsigned char i;
    unsigned char valid_flag;
    unsigned char valid_num;

    printf("\n(%s)2012/05/09 15:55\n",__func__);

    if(num>PARAM_LEN_KEYPAD)
        num =PARAM_LEN_KEYPAD;

    valid_num = 0;
    for(i=0;i<num;i++){
        printf("keypad param%u=0x%llx\n",i,*(param+i));
        valid_flag = 0;
        kptype = GET_PIN_TYPE(*(param+i));
        kpidx = GET_PIN_INDEX(*(param+i));
        printf("kptype=%u\n",kptype);
        printf("kpidx=%u\n",kpidx);
        switch(kptype){
            case PCB_PIN_TYPE_ISO_GPIO:
                printf("PCB_PIN_TYPE_ISO_GPIO\n");
                //kpidx = gpio pin index
                para_tmp = get_gpio_info(kpidx);        //get addr & shift
                kpidx = GET_GPIO_INVERT(*(param+i));    //get invert message
                para_tmp|=(kpidx&0xf)<<16;
                para_tmp|=(kptype&0xf)<<20;
                valid_flag =1;
                break;
            case PCB_PIN_TYPE_LSADC:
                printf("PCB_PIN_TYPE_LSADC\n");
                //kpidx  = lsadc set
                param1 = GET_LSADC_HITVALUE(*(param+i));    //get hit value
                param2 = GET_LSADC_TOLERANCE(*(param+i));   //get tolerance
                para_tmp = (param1<<8)|param2;
                para_tmp|=(kpidx&0xf)<<16;
                para_tmp|=(kptype&0xf)<<20;
                valid_flag =1;
                break;
            case PCB_PIN_TYPE_ISO_UNIPWM:
            case PCB_PIN_TYPE_ISO_PWM:
            default:
                printf("unknow pin type\n");
                break;

        }
        if(valid_flag){
            printf("KEYPAD_PARM%u=0x%8x\n",valid_num,para_tmp);
            SET_KEYPAD_PARM(valid_num,para_tmp);
            valid_num++;
        }
    }

    pm_event_msg = GET_EVENT_MSG();
    printf("Valid keypad paramteter have %u set.\n",valid_num);
    SET_EVENT_IDX(pm_event_msg,loc_keypad,valid_num);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
}


void powerMgr_setup_keypad(unsigned long long param)
{
    unsigned long long para_tmp = param;
    printf("\n(%s)2012/05/10 14:30 no more usage.\n",__func__);
}


void powerMgr_setup_cec(unsigned int param)
{
    unsigned int pm_event_msg;

    printf("\n(%s)2012/05/09 15:55\n",__func__);

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_cec,1);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
}

void powerMgr_setup_ppsource(PP_SOURCE_T pp_source)
{
    unsigned int pm_event_msg;
    char str[][10]={"HDMI1","HDMI2","HDMI3",
                    "VGA1","VGA2","VGA3",
                    "AV1","AV2","AV3"};
    printf("\n(%s)2012/05/09 15:55\n",__func__);

    if(pp_source < PP_SOURCE_MAX){
        printf("previously source is %s\n",str[pp_source]);
        SET_PPS_PARM(pp_source);
        pm_event_msg = GET_EVENT_MSG();
        SET_EVENT_IDX(pm_event_msg,loc_pps,PARAM_LEN_PPS);
        SET_EVENT_MSG(pm_event_msg);
        printf("pm_event_msg=0x%x\n",pm_event_msg);
    }else{
        printf("unknow previously source.\n");
    }
}

void powerMgr_setup_wakeup_timer(int days, int hours, int mins)
{
    unsigned int pm_event_msg;
    unsigned int total_mins;

    printf("\n(%s)2012/05/09 15:55\n",__func__);

    if(hours > 23)
        hours = 23;
    if(mins > 59)
        mins = 59;

    total_mins = days * 24 *60 + hours *60 +mins;

    printf("sleeping time is %ddays %dhours %dmins\n",days,hours,mins);
    printf("total sleeping time is %u minute\n",total_mins);

    SET_WUT_PARM(total_mins);

    printf("IDX_REG_WUT adr =0x%x\n",
            RTD_SHARE_MEM_BASE+4*IDX_REG_WUT);
    printf("IDX_REG_WUT val =0x%x\n",
            rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_WUT));
    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_wut,PARAM_LEN_WUT);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
    printf("msg adr =0x%x\n",PM_EVENT_MSG);
    printf("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));
}

void powerMgr_setup_wakeup_min( unsigned int reason,
                                unsigned int mins)
{
    unsigned int pm_event_msg;
    unsigned int s_reason;

    printf("\n(%s)2012/11/09 15:10\n",__func__);

    if(reason && reason < 0x10){
        s_reason = reason;
    }else{
        s_reason = PARAM_LEN_WUT;
    }

    printf("sleeping time is %u minute\n",mins);
    printf("sleeping reason is %u\n",s_reason);

    SET_WUT_PARM(mins);

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_wut,s_reason);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
    printf("msg adr =0x%x\n",PM_EVENT_MSG);
    printf("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));
}

void powerMgr_setup_irda(unsigned int protocol ,
                         unsigned int key_num,
                         unsigned int * key_array )
{
    unsigned int i;
    unsigned int pm_event_msg;

    printf("\n(%s)2012/05/09 15:55\n",__func__);

    printf("IrDA Protocol is %u\n",protocol);
    SET_IRDA_PARM(0,protocol);
    if(key_num>=PARAM_LEN_IRDA)
        key_num = PARAM_LEN_IRDA-1;

    for(i=0 ;i<key_num; i++){
        printf("IR_KEY%u=0x%x\n",1+i,*(key_array+i));
        SET_IRDA_PARM(1+i,*(key_array+i));
    }

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_irda,key_num);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
}

void powerMgr_setup_power_en(unsigned int pw_num,
                             unsigned long long * pw_array )
{
    unsigned int i;
    unsigned int pm_event_msg;
    unsigned int index;
    unsigned int invert;
    unsigned int para_tmp;
    unsigned int valid_num;
    printf("\n(%s)2012/05/09 15:55\n",__func__);

    printf("Power enable line have %u set.\n",pw_num);

    if(pw_num>PARAM_LEN_PWEN)
        pw_num = PARAM_LEN_PWEN;

    valid_num = 0;
    for(i=0 ;i<pw_num; i++){
        printf("en_power para%u=0x%llx\n",i,*(pw_array+i));
        printf("GET_PIN_TYPE:%x\n",GET_PIN_TYPE(*(pw_array+i)));

        if(GET_PIN_TYPE(*(pw_array+i)) ==
           PCB_PIN_TYPE_ISO_GPIO)
        {
            index = GET_PIN_INDEX(*(pw_array+i));
            invert = GET_GPIO_INVERT(*(pw_array+i));
            para_tmp = get_gpio_info(index);
            SET_PWEN_PARM(valid_num,para_tmp|(invert<<SHT_GPIO_IVR));
            valid_num++;
            //printf("index=0x%x\n",index);
            //printf("invert=0x%x\n",invert);
            //printf("para_tmp=0x%x\n",para_tmp);
            //printf("final_para=0x%x\n",para_tmp|(invert<<SHT_GPIO_IVR));
        }
    }

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_pwen,valid_num);
    SET_EVENT_MSG(pm_event_msg);
    printf("pm_event_msg=0x%x\n",pm_event_msg);
}

#ifdef CONFIG_ENABLE_SOS_FUNCTION
//USER:LewisLee DATE:2012/10/03
//for customer request, to record error shot down mode
void powerMgr_setup_sos_multi(unsigned int event)
{
	unsigned int pm_event_msg;

	printf("\n powerMgr_setup_sos_multi : %x\n", event);

	if(event > PARAM_LEN_SOS)
		event = 0;

	pm_event_msg = GET_EVENT_MSG();
	SET_EVENT_IDX(pm_event_msg, loc_sos, event);
	SET_EVENT_MSG(pm_event_msg);
	printf("pm_event_msg=0x%x\n",pm_event_msg);
}
#endif //#ifdef CONFIG_ENABLE_SOS_FUNCTION

void powerMgr_get_sleep_dur(unsigned int * dur_ary)
{
    unsigned int dur_h;
    unsigned int dur_l;
    printf("\n(%s)2012/05/09 15:55\n",__func__);

    dur_h = dur_l =0;
    GET_TIME_DUR(dur_h,dur_l);

    dur_ary[0] = dur_l;                    //min
    dur_ary[1] = (dur_h >> 24) & 0xff;     //sec
    dur_ary[2] = dur_h & 0xffffff;         //ms
    printf("\nsleep duration: %umin %usec %ums",
            dur_ary[0],dur_ary[1],dur_ary[2]);

}

unsigned int powerMgr_get_wakeup_source(void)
{
    unsigned int wk_source;
    char str[][7]={"UNDEF","KEYPAD","WUT","IRDA","CEC","PPS"};

    printf("\n(%s)2012/05/30 19:50\n",__func__);
    wk_source = GET_WK_SOR();

    printf("\nwakeup source : %u",wk_source);
    return wk_source;

}

void powerMgr_set_cur_time(int hours,int mins,int sec)
{
    unsigned int cur_time;
    printf("\n(%s)2013/04/23 13:55\n",__func__);

    if(hours > 23)
        hours = 23;
    if(mins > 59)
        mins = 59;
    if(sec > 59)
        sec = 59;
    cur_time = hours<<24|mins<<16|sec<<8;
    SET_CUR_TIME(cur_time);

    printf("\nrecord current time : %dhour, %dmin, %dsec",
            hours,mins,sec);
}

unsigned int powerMgr_get_rec_time(void)
{
    unsigned int cur_time;

    printf("\n(%s)2012/07/16 19:50\n",__func__);
    cur_time =GET_CUR_TIME();
    cur_time=(cur_time>>8);

    printf("\nrecorded time : %uhour, %umin, %usec",
            (cur_time>>16)& 0xff,
            (cur_time>> 8)& 0xff,
            (cur_time>> 0)& 0xff);

    return cur_time;

}

void powerMgr_set_sharemem(unsigned char addr,unsigned int value)
{
    unsigned int cur_time;

    printf("\n(%s)2013/04/22 19:10\n",__func__);
    if(addr>31){
        printf("The address is to much.\n");
    }else{
        rtd_outl(RTD_SHARE_MEM_BASE+(4*addr),value);

        printf("\nthe share_memory %u = 0x%08x",
                addr,
                rtd_inl(RTD_SHARE_MEM_BASE+4*addr));
    }
}

void powerMgr_show_version(void)
{
    printf("\nEMCU Libs 2013/05/06 11:00\n");

}



/* end of file */





