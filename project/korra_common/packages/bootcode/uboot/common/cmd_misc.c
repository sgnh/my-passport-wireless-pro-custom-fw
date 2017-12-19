/*
 * (C) Copyright 2001
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Misc functions
 */
#include <common.h>
#include <command.h>
#if defined(CONFIG_REALTEK_EERPOM_TV010_A)
#include "../drivers/eeprom/EEP_TV010_A/eeprom.h"
#endif

int do_sleep (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ulong start = get_timer(0);
	ulong delay;

	if (argc != 2)
		return CMD_RET_USAGE;

	delay = simple_strtoul(argv[1], NULL, 10) * CONFIG_SYS_HZ;

	while (get_timer(start) < delay) {
		if (ctrlc ())
			return (-1);

		udelay (100);
	}

	return 0;
}

U_BOOT_CMD(
	sleep ,    2,    1,     do_sleep,
	"delay execution for some time",
	"N\n"
	"    - delay execution for N seconds (N is _decimal_ !!!)"
);

void amp_IO(unsigned char bus_id, unsigned short device_id, unsigned char addr, unsigned val)
{
        unsigned char bData;
        unsigned char wData[20];
        unsigned char nwData = 0;

        wData[0] = addr;
        wData[1] = val;
        nwData = 2;
        I2C_Write_EX(bus_id, device_id, nwData, wData);
        //printf("id_addr=%02x, set_addr=%02x, write_data=%02x\n", device_id, wData[0], wData[1]);
        udelay (250);
        wData[0] = 0xD0;
        wData[1] = addr;
        nwData = 2;
        I2C_Read_EX(bus_id, device_id, nwData, wData, 1, &bData);
        //printf("id_addr=%02x, get_addr=%02x, read_data=%02x\n", device_id, wData[1], bData);
        udelay (250);
        EXECUTE_CUSTOMIZE_FUNC(0);
}

extern void AudioAmp_InitAudioOut2I2S_1st(void);
extern void AudioAmp_InitAudioOut2I2S_2nd(void);
int do_ampinit (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	printf("I2C Amp Init ...\n");
	AudioAmp_InitAudioOut2I2S_1st();
	AudioAmp_InitAudioOut2I2S_2nd();
	return 0;
}

U_BOOT_CMD(
        ampinit, 2, 1,    do_ampinit,
        "Run Amp Speaker Initial Task",
        "\n"
        "    - Run Amp Speaker Initial Task"
);


#if defined(CONFIG_REALTEK_EERPOM_TV010_A)
/************************************************************************
 *  Implementation : Public functions
 ************************************************************************/
static unsigned int mhexstr2int(char *s)
{
	return (unsigned int) strtoul (s, (char **) 0, 16);
}

static UINT32 eep_parse_main(char eep_address_index, char* hex_string)
{
	UINT8 read_buf[32];
	UINT8 hex_buf[3];
	bool isStr = false;
	int i = 0;
	hex_buf[2] = 0;
	memset(read_buf, 0, 32);

	if (hex_string == NULL) {
		switch(eep_address_index) {
			case 'a':
				Eeprom_Read(EEP_AD_DATE, 5, read_buf);
				printf("a=0x%02x%02x%02x%02x%02x\n",read_buf[0],read_buf[1],read_buf[2],read_buf[3],read_buf[4]);
				break;
			case 'b':
				Eeprom_Read(EEP_AD_SERIALCODE_IDENT, 2, read_buf);
				printf("b=0x%02x%02x\n",read_buf[0],read_buf[1]);
				break;
			case 'c':
				Eeprom_Read(EEP_AD_SERIALCODE, SERIAL_CODE_SIZE, read_buf);
				printf("c0=0x%02x%02x%02x%02x%02x%02x%02x%02x\n",read_buf[0],read_buf[1],read_buf[2],read_buf[3],read_buf[4], read_buf[5], read_buf[6], read_buf[7]);
				printf("c1=0x%02x%02x%02x%02x%02x%02x%02x%02x\n",read_buf[8],read_buf[9],read_buf[10],read_buf[11],read_buf[12], read_buf[13], read_buf[14], read_buf[15]);
				printf("c2=0x%02x%02x%02x%02x%02x%02x%02x%02x\n",read_buf[16],read_buf[17],read_buf[18],read_buf[19],read_buf[20], read_buf[21], read_buf[22], read_buf[23]);
				printf("c3=0x%02x%02x%02x%02x%02x%02x%02x%02x\n",read_buf[24],read_buf[25],read_buf[26],read_buf[27],read_buf[28], read_buf[29], read_buf[30], read_buf[31]);
				printf("read_buf = [%s]\n", read_buf);
				break;
			case 'd':
				Eeprom_Read(EEP_AD_MAC, MAC_SIZE, read_buf);
				printf("d=0x%02x%02x%02x%02x%02x%02x\n",read_buf[0],read_buf[1],read_buf[2],read_buf[3],read_buf[4], read_buf[5]);
				break;
			default:
				break;
		}
	}
	else {
		if (hex_string[0] == '0' && hex_string[1] == 'x') {
			printf("input is hex = %s\n", hex_string);
			hex_string = hex_string+2;
			for (i = 0; i < 32 || i < strlen(hex_string); i++) {
				hex_buf[0] = *hex_string;
				hex_buf[1] = *(hex_string+1);
				read_buf[i] = mhexstr2int(hex_buf);
				hex_string = hex_string+2;
			}
		}
		else {
			isStr = true;
			printf("input is string = %s\n", hex_string);
		}
		
		switch(eep_address_index) {
			case 'a':
				if (!isStr)
					Eeprom_Write(EEP_AD_DATE, 5, read_buf);
				break;
			case 'b':
				if (!isStr)
					Eeprom_Write(EEP_AD_SERIALCODE_IDENT, 2, read_buf);
				break;
			case 'c':
				if (isStr)
					Eeprom_Write(EEP_AD_SERIALCODE, SERIAL_CODE_SIZE, hex_string);
				else
					Eeprom_Write(EEP_AD_SERIALCODE, SERIAL_CODE_SIZE, read_buf);
				break;
			case 'd':
				if (!isStr)
					Eeprom_Write(EEP_AD_MAC, MAC_SIZE, read_buf);
				break;
			default:
				break;
		}
	}
	return OK;

}

int do_eeprom (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	char *pch;
	char *pch2;

	if( argc > 3 ) {
		printf("eep [<eep_name>] [<assigned_value>]\n");
	    return OK;
	}

	if( argc == 1 ) {
		printf("eep [<eep_name>] [<assigned_value>]\n");
		printf("<eep_name>\n");
		printf("  a\t EEP_AD_DATE\n");
		printf("  b\t EEP_AD_SERIALCODE_IDENT\n");
		printf("  c\t EEP_AD_SERIALCODE\n");
		printf("  d\t EEP_AD_MAC\n");
		printf("\n\n");
		printf("example read: eep c\n");
		printf("example read: eep d\n");
		printf("example: eep a 0x20091212\n");
		printf("example: eep b 0x01a2\n");
		printf("example: eep c 0x0102030405060708091011121314151617181920212223242526272829303132\n");
		printf("example: eep c \"Company Skyworth: Sep 21 2012  05:01:27  ..\"\n");
		printf("example: eep d 0x001a9a6688ee\n\n\n");
	    return OK;
	}

	if( argc >= 2) {
		pch = argv[1];
		if (*pch!='a' && *pch!='b' && *pch!='c' && *pch!='d') {
			printf("ERROR!argv[1] is not a/b/c/d\n");
			return OK;
		}
	}

	if( argc == 2) {
		if (pch != NULL) {
			eep_parse_main(*pch, NULL);
		}
	}

	if( argc == 3) {
		pch2 = argv[2];
		if (pch != NULL) {
			eep_parse_main(*pch, pch2);
		}
	}
	return OK;
}

U_BOOT_CMD(
        eep, 3, 1,    do_eeprom,
        "eeprom write special area and set value to it",
        " [<eep_name>]  [<assigned_value>]\n"
        "    - just type eep will show usage examples"
);
#endif

#ifdef CONFIG_BOARD_TV005_L4300_RTD2993_EMMC
#include <asm/arch/system.h>
int rtk_plat_do_etherfix(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if (argc != 1)
                return CMD_RET_USAGE;

	rtd_outl(0xb801605c,0x841f0a46);// change Page to a46
	mdelay(100);
	rtd_outl(0xb801605c,0x84140003);// set fuse_rdy = 1 , set ext_ini_done = 1, to skip ext_ini
	mdelay(10);
	rtd_outl(0xb801605c,0x04140000);// read fuse_redy
	mdelay(10);
	rtd_inl(0xb801605c);

	rtd_outl(0xb801605c,0x841f0a42);// change Page to a42
	mdelay(100);

	rtd_outl(0xb801605c,0x04100000);// polling rg_phy_status = 1
	mdelay(10);
	rtd_inl(0xb801605c);
	mdelay(10);

	rtd_outl(0xb801605c,0x04010000);// read link status
	mdelay(100);
	rtd_outl(0xb801605c,0x04010000);// read link status
	mdelay(100);
	rtd_inl(0xb801605c);

	printf("Ether Fix for Toshiba L4300 10/100 Ether Phy\n");

        return 0;
}

U_BOOT_CMD(
        etherfix, 1, 0,    rtk_plat_do_etherfix,
	"Ether Fix for Toshiba L4300 10/100 Ether Phy",
	"\n"
        "    - Run Ether Fix for Toshiba L4300 10/100 Ether Phy"
);


#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/pcb.h>

#ifdef CONFIG_CUSTOMIZE_FUNC_REGISTER
#include <common.h>
#include <watchdog.h>
int count_pwm_led = 0;
int skip_condition= 32;
ulong pwm_led_currTime = 0;
ulong pwm_led_saveTime = 0;

#define LED_DEBUG 0

void tv005_update_led(void)
{
        int i, T_scale=32, X; // 32ms/32000us
        ulong T_up_GR=0x1F, T_down_GR=0x3E, T_max_G=0x3E, T_max_R=0x3E;
        ulong L_min_G=0x00, L_min_R=0x00, L_typ_G=0x34, L_typ_R=0x34, L_max_G=0xFB, L_max_R=0xFB;
        
        X=(int)(T_scale/skip_condition);
        i=count_pwm_led;
        pwm_led_currTime = get_timer_masked();
        if ( pwm_led_saveTime != 0)
        {
            if ( (pwm_led_currTime - pwm_led_saveTime) < skip_condition )
            {
                #if LED_DEBUG
                printf("The gap is too short... skip !!\n");   
                #endif
                goto skip; 
            }
            #if LED_DEBUG
            printf("pwm_led_currTime - pwm_led_saveTime = %8u ms\n", pwm_led_currTime - pwm_led_saveTime);
            #endif
        }
        //Stage I
        //for (i=0; i< T_up_GR*X; i++)
        if ( i < T_up_GR*X ) 
        {
            IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_min_G+(int)((L_max_G-L_min_G)*i/T_up_GR/X)));
            //mdelay((int)(T_scale));
            #if LED_DEBUG
            printf("Stage I: T_up_GR %d (%d)\n", i,  (int)(L_min_G+(int)((L_max_G-L_min_G)*i/T_up_GR/X)));
            #endif
        }
        //Stage II
        // flat area
        else if ( (i >= T_up_GR*X) && (i < (T_up_GR+T_max_G)*X) )
        {
            IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
            //mdelay(T_max_G*T_scale);
            #if LED_DEBUG
            printf("Stage II: T_max_G %d (%d)\n", i, L_max_G);
            #endif
        }
        //Stage III
        //for (i=0; i< T_down_GR*X; i++)
        else if ( (i >= (T_up_GR+T_max_G)*X) && (i < (T_up_GR+T_max_G+T_down_GR)*X) )
        {
            IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_max_G-(int)((L_max_G-L_typ_G)*(i-((T_up_GR+T_max_G)*X))/T_down_GR/X)));
            //mdelay((int)(T_scale));
            #if LED_DEBUG
            printf("Stage III: T_max_G %d (%d)\n", i, (int)(L_max_G-(int)((L_max_G-L_typ_G)*(i-((T_up_GR+T_max_G)*X))/T_down_GR/X)));
            #endif
        }     
        //Stage Last
        else
        {
            IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
            #if LED_DEBUG
            printf("Stage End: L_typ_G %d (%d)\n", i, L_typ_G);
            #endif
        } 
        count_pwm_led++;
skip:
        pwm_led_saveTime = get_timer_masked();
}

void tv005_finish_led(void)
{
        int j, start=count_pwm_led, T_scale=32, X;
        ulong T_up_GR=0x1F, T_down_GR=0x3E, T_max_G=0x3E;
    
        X=(int)(T_scale/skip_condition);
        for (j=start; j <= (T_up_GR+T_max_G+T_down_GR)*X; j++)
        {
            tv005_update_led();
            mdelay(skip_condition);
        }        
}
#endif

int rtk_plat_do_panelbl(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ulong freq;
	ulong duty;

	if (argc != 3)
                return CMD_RET_USAGE;

     	freq = simple_strtoul(argv[1], NULL, 16);
	duty = simple_strtoul(argv[2], NULL, 16);

	printf("Panel BackLight PWM SetFreq=%d, SetDuty=%d\n", freq, duty);
	IO_PWM_SetFreq(PIN_BL_ADJ, freq);
	IO_PWM_SetDuty(PIN_BL_ADJ, duty);

        return 0;
}

U_BOOT_CMD(
        panelbl, 3, 0,    rtk_plat_do_panelbl,
        "Panel BackLight PWM Setting",
        "[Frequency] [Duty Cycle]\n"
        "    - Change Panel BlackLight by Frequency and Duty Cycle"
);

int rtk_plat_do_ledr(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        ulong freq;
        ulong duty;

	if (argc != 3)
                return CMD_RET_USAGE;

        freq = simple_strtoul(argv[1], NULL, 16);
        duty = simple_strtoul(argv[2], NULL, 16);

	printf("Red LED PWM SetFreq=%d, SetDuty=%d\n", freq, duty);
	IO_PWM_SetFreq(PIN_RED_LED, freq);
	IO_PWM_SetDuty(PIN_RED_LED, duty);

        return 0;
}

U_BOOT_CMD(
        ledr, 3, 0,    rtk_plat_do_ledr,
        "Red LED PWM Setting",
        "[Frequency] [Duty Cycle]\n"
        "    - Change Red LED by Frequency and Duty Cycle"
);

int rtk_plat_do_ledg(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        ulong freq;
        ulong duty;

        if (argc != 3)
                return CMD_RET_USAGE;

        freq = simple_strtoul(argv[1], NULL, 16);
        duty = simple_strtoul(argv[2], NULL, 16);

        printf("Green LED PWM SetFreq=%d, SetDuty=%d\n", freq, duty);
        IO_PWM_SetFreq(PIN_GREEN_LED, freq);
        IO_PWM_SetDuty(PIN_GREEN_LED, duty);

        return 0;
}

U_BOOT_CMD(
        ledg, 3, 0,    rtk_plat_do_ledg,
        "Green LED PWM Setting",
        "[Frequency] [Duty Cycle]\n"
        "    - Change Green LED by Frequency and Duty Cycle"
);

int rtk_plat_do_sdd(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        int ret = 0, i, T_scale=32, X=1; // 32ms/32000us
        ulong T_up_GR=0x1F, T_down_GR=0x3E, T_max_G=0x3E, T_max_R=0x3E;
        ulong L_min_G=0x00, L_min_R=0x00, L_typ_G=0x34, L_typ_R=0x34, L_max_G=0xFB, L_max_R=0xFB;

	printf("T_up_GR=0x%02x, T_down_GR=0x%02x, T_max_G=0x%02x, T_max_R=0x%02x\n", T_up_GR, T_down_GR, T_max_G, T_max_R);
	printf("L_min_G=0x%02x, L_min_R=0x%02x, L_typ_G=0x%02x, L_typ_R=0x%02x, L_max_G=0x%02x, L_max_R=0x%02x\n", L_min_G, L_min_R, L_typ_G, L_typ_R, L_max_G, L_max_R);
        if (argc != 3)
                return CMD_RET_USAGE;

        if (argv[1][0] == 'a' && argv[1][1] == 'c' )
	{
		if ( simple_strtoul(argv[2], NULL, 16) == 1 )	// ac on
		{
			//IO_PWM_SetFreq(PIN_RED_LED, 200);
			//IO_PWM_SetDuty(PIN_RED_LED, 0);
			//IO_PWM_SetFreq(PIN_GREEN_LED, 200);
			//IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			//mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			for (i=0; i< T_up_GR*X; i++)
			{
				IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_min_G+(int)((L_max_G-L_min_G)*i/T_up_GR/X)));
				mdelay((int)(T_scale));
			}
			IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
			mdelay(T_max_G*T_scale);
			for (i=0; i< T_down_GR*X; i++)
			{
				IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_max_G-(int)((L_max_G-L_typ_G)*i/T_down_GR/X)));
				mdelay((int)(T_scale));
			}
			IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
			//mdelay(T_down_GR*T_scale);// 32 ms x T_down_GR about 2 sec
		}
		else if ( simple_strtoul(argv[2], NULL, 16) == 0 )	// ac off
		{
			IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
			IO_PWM_SetDuty(PIN_RED_LED, L_typ_R);
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			IO_PWM_SetDuty(PIN_RED_LED, 0);
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			mdelay(T_max_G*T_scale);// 32 ms x T_max_G about 2 sec
			mdelay(T_down_GR*T_scale);// 32 ms x T_down_GR about 2 sec
		}
		else
		{
			return CMD_RET_USAGE;
		}
	}
	else if (argv[1][0] == 'd' && argv[1][1] == 'c' )
        {
                if ( simple_strtoul(argv[2], NULL, 16) == 1 ) // dc on
                {
			//IO_PWM_SetDuty(PIN_RED_LED, L_typ_R);
			//IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			//mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			//IO_PWM_SetFreq(PIN_RED_LED, 200);
			//IO_PWM_SetDuty(PIN_RED_LED, 0);
			//IO_PWM_SetFreq(PIN_GREEN_LED, 200);
			//IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			//mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			for (i=0; i< T_up_GR*X; i++)
			{
				IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_min_G+(int)((L_max_G-L_min_G)*i/T_up_GR/X)));
				mdelay((int)(T_scale));
			}
			IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
			mdelay(T_max_G*T_scale);
			for (i=0; i< T_down_GR*X; i++)
			{
				IO_PWM_SetDuty(PIN_GREEN_LED, (int)(L_max_G-(int)((L_max_G-L_typ_G)*i/T_down_GR/X)));
				mdelay((int)(T_scale));
			}
			IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
			//mdelay(T_down_GR*T_scale);// 32 ms x T_down_GR about 2 sec

                }
                else if ( simple_strtoul(argv[2], NULL, 16) == 0 )    // dc off
                {
			//IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
			IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
			IO_PWM_SetDuty(PIN_RED_LED, 0);
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			IO_PWM_SetDuty(PIN_RED_LED, 0);
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec // As short as possible
			IO_PWM_SetDuty(PIN_GREEN_LED, 0);
			IO_PWM_SetDuty(PIN_RED_LED, L_typ_R);
			mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
			mdelay(T_max_G*T_scale);// 32 ms x T_max_G about 2 sec
			mdelay(T_down_GR*T_scale);// 32 ms x T_down_GR about 2 sec
                }
                else
                {
                        return CMD_RET_USAGE;
                }
        }
	else if (argv[1][0] == 'u' && argv[1][1] == 'p' )
	{
                if ( simple_strtoul(argv[2], NULL, 16) == 0 )    // software update failure
                {
                        IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
                        IO_PWM_SetDuty(PIN_RED_LED, 0);
                        mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
                        IO_PWM_SetDuty(PIN_GREEN_LED, 0);
                        IO_PWM_SetDuty(PIN_RED_LED, 0);
                        mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec // As short as possible
                        IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
                        IO_PWM_SetDuty(PIN_RED_LED, L_max_R);
                        mdelay(3000);// 3 sec Period of SW Update
                        IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
                        IO_PWM_SetDuty(PIN_RED_LED, L_max_R);
                }
                else if ( simple_strtoul(argv[2], NULL, 16) == 1 )    // software update success
                {
                        IO_PWM_SetDuty(PIN_GREEN_LED, L_typ_G);
                        IO_PWM_SetDuty(PIN_RED_LED, 0);
                        mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec
                        IO_PWM_SetDuty(PIN_GREEN_LED, 0);
                        IO_PWM_SetDuty(PIN_RED_LED, 0);
                        mdelay(T_up_GR*T_scale);// 32 ms x T_up_GR about 1 sec // As short as possible
                        IO_PWM_SetDuty(PIN_GREEN_LED, L_max_G);
                        IO_PWM_SetDuty(PIN_RED_LED, L_max_R);
                        mdelay(3000);// 3 sec Period of SW Update
                        IO_PWM_SetDuty(PIN_GREEN_LED, 0);
                        IO_PWM_SetDuty(PIN_RED_LED, 0);
                }
                else
                {
                        return CMD_RET_USAGE;
                }

	}
	else
	{
        	return CMD_RET_USAGE;
	}

        return ret;
}

U_BOOT_CMD(
        sdd, 3, 0,    rtk_plat_do_sdd,
        "Software Design Data Running",
        "[ac|dc|up] [0|1]\n"
	"    - Software DD Demo for dc on/off, ac on/off and software update fail/success"
);

#include <i2c.h>
/*
int i2c_set_bus_num(unsigned int bus);			// set which bus to access.
int i2c_read(uchar chip, uint addr, int alen, uchar *buffer, int len);
int i2c_write(uchar chip, uint addr, int alen, uchar *buffer, int len);
*/

int do_i2ctest (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        ulong id_addr, i;
        unsigned char bData, bResult;
        unsigned char wData[20];
        unsigned char nwData = 0;

        if (argc != 2)
                return CMD_RET_USAGE;

        id_addr = simple_strtoul(argv[1], NULL, 16);
	printf("id_addr=%02x\n\n", id_addr);
	I2C_Init();

        mdelay(10);

	if (id_addr==0xff)
	{
		for (i=0; i<0xFF; i++)
		{
			#if 1
        		if (id_addr>0x30 && id_addr < 0x38)
			{
				printf("xxxXXXXXXXXXXXXXXXXXXXXXXXx\n");
				continue;

			}
			wData[0] = 0xF1;
        		nwData = 1;
        		I2C_Read_EX(2, i, nwData, wData, 1, &bData);
			printf("id_addr=%02x, read_data=%02x\n", i, bData);
			#else
			wData[0] = i;
                        nwData = 1;
                        I2C_Read_EX(2, 0x40, nwData, wData, 1, &bData);
                        printf("get_addr=%02x, read_data=%02x\n", i, bData);
			#endif
		}
	}
	else if (id_addr==0x40)
	{
		#if 1
		for (i=0; i<0xFF; i++)
		{
			wData[0] = 0xD0;
			wData[1] = i;
                        nwData = 2;
                        I2C_Read_EX(2, id_addr, nwData, wData, 1, &bData);
                        printf("id_addr=%02x, get_addr=%02x, read_data=%02x\n", id_addr, i, bData);
		}
		#else
		wData[0] = 0x03;
         	wData[1] = 0x04;
         	nwData = 2;
         	I2C_Write_EX(2, id_addr, nwData, wData);
                printf("id_addr=%02x, set_addr=%02x, write_data=%02x\n", id_addr, wData[0], wData[1]);

		#if 1
		wData[0] = 0xD0;
		wData[1] = 0x03;
                nwData = 2;
                I2C_Read_EX(2, id_addr, nwData, wData, 1, &bData);
                printf("id_addr=%02x, get_addr=%02x, read_data=%02x\n", id_addr, wData[1], bData);
		#else
		wData[0] = 0xD0;
		wData[1] = 0x03;
                nwData = 2;
         	I2C_Write_EX(2, id_addr, nwData, wData);
                printf("id_addr=%02x, set_addr=%02x, write_data=%02x\n", id_addr, wData[0], wData[1]);
                I2C_Read_EX(2, id_addr, 0, NULL, 1, &bData);
                printf("id_addr=%02x, get_addr=%02x, read_data=%02x\n", id_addr, wData[1], bData);
		#endif
		#endif
	}
	else
	{
		wData[0] = 0xD0;
		wData[1] = 0x00;
	        nwData = 2;
        	I2C_Read_EX(2, id_addr, nwData, wData, 1, &bData);
		printf("id_addr=%02x, read_data=%02x\n", id_addr, bData);
	}

        return 0;
}

U_BOOT_CMD(
        i2ctest ,    2,    0,     do_i2ctest,
        "i2c test",
        "N\n"
        "    - run i2c test"
);

int do_gpiotest (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        ulong id_addr;

        if (argc != 2)
                return CMD_RET_USAGE;

        id_addr = simple_strtoul(argv[1], NULL, 16);
        printf("id_addr=%02x\n\n", id_addr);

	if (id_addr == 0)
	{
		IO_Set( PIN_AMP_SHDN, 0 );
	}
	else
	{
		IO_Set( PIN_AMP_SHDN, 1 );
	}
	return 0;

}

U_BOOT_CMD(
        gpiotest ,    2,    0,     do_gpiotest,
        "gpio test",
        "N\n"
        "    - run gpio test"
);

int do_ampvol (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        ulong val;

        if (argc != 2)
                return CMD_RET_USAGE;

        val = simple_strtoul(argv[1], NULL, 16);
        printf("val=%02x\n\n", val);

	// Setting of volume Default = FFh
	amp_IO(2, 0x40, 0x11, val);
	amp_IO(2, 0x40, 0x13, val);
	amp_IO(2, 0x40, 0x15, val);
	amp_IO(2, 0x40, 0x17, val);

        return 0;
}

U_BOOT_CMD(
        ampvol ,    2,    0,     do_ampvol,
        "AMP Volumn test",
        "N\n"
        "    - run AMP Volumn test"
);

int do_dtvrst (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
        printf("DTV PIN_NRST reset!! \n");
        IO_Set(PIN_DTV_NRST, 1 );
        mdelay(1);
        IO_Set(PIN_DTV_NRST, 0 );
        mdelay(1);
        IO_Set(PIN_DTV_NRST, 1 );

	return 0;
}

U_BOOT_CMD(
        dtvrst, 1, 0,    do_dtvrst,
        "Reset DVT demod for Toshiba L4300",
        "\n"
        "    - Reset DVT demod for Toshiba L4300"
);
#endif
