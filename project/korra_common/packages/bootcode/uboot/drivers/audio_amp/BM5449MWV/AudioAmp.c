#include <common.h>
#include <asm/arch/io.h>
#include <asm/arch/system.h>
#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/pcb.h>
#include <platform_lib/board/pwm.h>
#include <i2c.h>
#include "AudioAmp.h"

//#define printf(fmt,args...)

static unsigned long long m_I2C_MASTER=0, m_AMP_DEVICE_ADDR=0, m_PIN_AMP_MUTE=0;
static unsigned long long m_PIN_951_RST=0;
extern void amp_IO(unsigned char bus_id, unsigned short device_id, unsigned char addr, unsigned val);

void AudioAmp_InitAudioOut2I2S_1st(void)
{
        unsigned long long value=0;

	#if 0	// too slow remove for tv005	
	pcb_mgr_show_all_enum_info();
        if (pcb_mgr_get_enum_info_byname("AMP_I2C", &value) < 0) {
                printf("no AMP_I2C\n");
                m_I2C_MASTER = 0;
        } else {
                m_I2C_MASTER = value;
                printf("get AMP_I2C %08x%08x\n", HI32(value), LO32(value));
        }
        if (pcb_mgr_get_enum_info_byname("AMP_DEVICE_ADDR", &value) < 0) {
                printf("no AMP_DEVICE_ADDR\n");
                m_AMP_DEVICE_ADDR = 0;
        } else {
                m_AMP_DEVICE_ADDR = value;
                printf("get AMP_DEVICE_ADDR %08x%08x \n", HI32(value), LO32(value));

        }
        if (pcb_mgr_get_enum_info_byname("PIN_AMP_MUTE", &value) < 0) {
                printf("no PIN_AMP_MUTE\n");
                m_PIN_AMP_MUTE = 0;
        } else {
                m_PIN_AMP_MUTE = value;
               printf("get AMP_MUTE %08x%08x\n", HI32(value), LO32(value));

        }

        if (pcb_mgr_get_enum_info_byname("PIN_MISC_951_RST", &value) < 0) {
                printf("no PIN_MISC_951_RST\n");
                m_PIN_951_RST = 0;
        } else {
                m_PIN_951_RST = value;
                printf("get MISC_951_RST = %08x%08x\n", HI32(value), LO32(value));
        }
        if (m_PIN_AMP_MUTE) {
                //reset AMP
                IO_Set(m_PIN_AMP_MUTE, 0);
		printf("get m_PIN_AMP_MUTE = %d (reset AMP!)\n", m_PIN_AMP_MUTE);
        }
        if (m_PIN_951_RST) {
                //reset Yamaha YYS951
                IO_Set(m_PIN_951_RST, 1);
		printf("get m_PIN_951_RST = %d (reset Yamaha YYS951!)\n", m_PIN_951_RST);
        }
	#else
	m_I2C_MASTER = 2;
 	m_AMP_DEVICE_ADDR = 0x40;	
	#endif
	I2C_Init();
}

void AudioAmp_InitAudioOut2I2S_2nd(void)
{

	if ( m_I2C_MASTER != 0 && m_AMP_DEVICE_ADDR != 0 )
	{
        	// Start up
		// Mute on
		#if 1 
                IO_Set( PIN_AMP_MUTEX, 0 );
                // Reset
                IO_Set( PIN_AMP_RSTX, 0 );
                mdelay(1);
                IO_Set( PIN_AMP_RSTX, 1 );
                mdelay(1);
                // PWD
                IO_Set( PIN_AMP_SHDN, 1 );
                mdelay(1);
                IO_Set( PIN_AMP_SHDN, 0 );
                mdelay(1);
		#endif
        	
		//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE9, 0x34);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x03, 0x02);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x01, 0x00);

        	// Setting of volume Default = FFh
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x11, val);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x13, val);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x15, val);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x17, val);

        	#if 0 // TSB SW DD rev1
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x01, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x03, 0x02);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x11, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x11, 0x46);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x90, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x90, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA1, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC8, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC9, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCA, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE9, 0x25);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE9, 0x34);
                #else // TSB SW DD rev3 
                #if 1 // Shrinked Table (/// for keep default)
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x01, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x02, 0x82);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x03, 0x02);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x04, 0x10);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x05, 0x12);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x06, 0x03);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x07, 0x10);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x08, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x09, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0A, 0x00); // Not used
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0B, 0x28);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0C, 0x00); // Not used
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0D, 0x02); 
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0F, 0x00); // Not used

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x10, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x11, 0x58);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x12, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x13, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x14, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x15, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x16, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x17, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x18, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x19, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1A, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1B, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1C, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1D, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1E, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1F, 0x60);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x20, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x21, 0x6C);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x22, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x23, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x24, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x25, 0x12);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x26, 0x12);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x27, 0x12);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x28, 0x0F);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x29, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2A, 0x05);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2B, 0x11);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2D, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2E, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2F, 0x00); // Not used

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x30, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x31, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x32, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x33, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x34, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x35, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x36, 0xE1);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x37, 0xE1);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x38, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x39, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3A, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3B, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3C, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3D, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3E, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3F, 0x40);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x40, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x41, 0xE0);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x42, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x43, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x44, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x45, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x46, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x47, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x48, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x49, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4B, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4D, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4F, 0x00);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x50, 0x40);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x51, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x52, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x53, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x54, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x55, 0x18);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x56, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x57, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x58, 0x40);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x59, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5A, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5B, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5C, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5D, 0x18);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5E, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5F, 0x13);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x60, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x61, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x62, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x63, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x64, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x65, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x66, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x67, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x68, 0x40);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x69, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6A, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6B, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6C, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6D, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6E, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6F, 0x13);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x70, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x71, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x72, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x73, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x74, 0x40);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x75, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x76, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x77, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x78, 0x40);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x79, 0x80);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7A, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7B, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7C, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7D, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7E, 0x3B);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7F, 0x13);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x80, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x81, 0x04);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x82, 0x79);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x83, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x84, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x85, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x86, 0x60);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x87, 0xFF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x88, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x89, 0x60);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8B, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8C, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8D, 0x4C);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8E, 0x79);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8F, 0x40);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x90, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x91, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x92, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x93, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x94, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x95, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x96, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x97, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x98, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x99, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9B, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9D, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9F, 0x00);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA0, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA1, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA3, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA4, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA6, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA7, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAF, 0x00);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB0, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB1, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB3, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB4, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB5, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB6, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB7, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB8, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBF, 0x00);

        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC0, 0x13);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC1, 0xCF);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC2, 0x7D);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC3, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC4, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC5, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC8, 0x03);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC9, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCA, 0x07);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCB, 0x0C);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCC, 0x06);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCD, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCE, 0x0F);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCF, 0x09);

        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD0, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD1, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD3, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD4, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD7, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDF, 0x00);

        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE0, 0x00); // Not used
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE1, 0x1F);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE2, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE3, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE4, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE5, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE6, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE8, 0x04);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE9, 0x34);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEA, 0xC2);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEB, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEC, 0x01);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xED, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEE, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEF, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF0, 0x10);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF1, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF2, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF3, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF4, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF7, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF9, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFA, 0x00);
        	///amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFF, 0x00);
                #else // Original Table
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x01, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x02, 0x82);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x03, 0x02);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x04, 0x10);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x05, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x06, 0x03);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x07, 0x10);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x08, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x09, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0A, 0x00); // Not used
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0B, 0x28);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0C, 0x00); // Not used
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0D, 0x02); 
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x0F, 0x00); // Not used

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x10, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x11, 0x58);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x12, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x13, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x14, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x15, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x16, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x17, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x18, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x19, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1A, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1B, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1C, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1D, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1E, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x1F, 0x60);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x20, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x21, 0x6C);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x22, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x23, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x24, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x25, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x26, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x27, 0x12);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x28, 0x0F);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x29, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2A, 0x05);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2B, 0x11);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2D, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2E, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x2F, 0x00); // Not used

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x30, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x31, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x32, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x33, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x34, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x35, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x36, 0xE1);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x37, 0xE1);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x38, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x39, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3A, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3B, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3C, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3D, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3E, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x3F, 0x40);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x40, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x41, 0xE0);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x42, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x43, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x44, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x45, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x46, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x47, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x48, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x49, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4B, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4D, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x4F, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x50, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x51, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x52, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x53, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x54, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x55, 0x18);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x56, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x57, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x58, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x59, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5A, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5B, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5C, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5D, 0x18);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5E, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x5F, 0x13);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x60, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x61, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x62, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x63, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x64, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x65, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x66, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x67, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x68, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x69, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6A, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6B, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6C, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6D, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6E, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x6F, 0x13);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x70, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x71, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x72, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x73, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x74, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x75, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x76, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x77, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x78, 0x40);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x79, 0x80);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7A, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7B, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7C, 0x40);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7D, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7E, 0x3B);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x7F, 0x13);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x80, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x81, 0x04);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x82, 0x79);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x83, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x84, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x85, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x86, 0x60);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x87, 0xFF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x88, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x89, 0x60);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8B, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8C, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8D, 0x4C);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8E, 0x79);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x8F, 0x40);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x90, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x91, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x92, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x93, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x94, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x95, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x96, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x97, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x98, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x99, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9A, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9B, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9C, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9D, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9E, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0x9F, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA0, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA1, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA3, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA4, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA6, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA7, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xA9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xAF, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB0, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB1, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB3, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB4, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB5, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB6, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB8, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xB9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xBF, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC0, 0x13);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC1, 0xCF);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC2, 0x7D);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC3, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC4, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC5, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC8, 0x03);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xC9, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCA, 0x07);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCB, 0x0C);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCC, 0x06);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCD, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCE, 0x0F);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xCF, 0x09);

        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD0, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD1, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD2, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD3, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD4, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD7, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xD9, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDA, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xDF, 0x00);

        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE0, 0x00); // Not used
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE1, 0x1F);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE2, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE3, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE4, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE5, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE6, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE8, 0x04);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xE9, 0x34);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEA, 0xC2);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEB, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEC, 0x01);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xED, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEE, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xEF, 0x00);

        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF0, 0x10);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF1, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF2, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF3, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF4, 0x00); // Not used
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF5, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF6, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF7, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF8, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xF9, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFA, 0x00);
        	amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFB, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFC, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFD, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFE, 0x00);
        	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 0xFF, 0x00);
                #endif
                #endif		

		// Mute off
                mdelay(1);
		IO_Set( PIN_AMP_MUTEX, 1 );
	}
}
void AudioAmp_SetMute(BOOL isMute)
{

}
void AudioAmp_SetMasterVolume(UINT8 iValue)
{

}
void AudioAmp_SetSubWoof(BOOL isEnable)
{

}
void AudioAmp_SetOscillator(void)
{

}
void AudioAmp_Set951RST(BOOL val)
{

}





