#include <common.h>
#include <command.h>
#ifdef CONFIG_HAS_DATAFLASH
#include <dataflash.h>
#endif
#include <watchdog.h>

//#include <stdio.h>
//#include "app_start.h"
//#include "lx_common.h"

#define LOG_ADDR                   0xb002ff00

#define ALIGN32_FLOOR(addr)        ((addr) & 0xFFFFFFFC)
#define ALIGN16_FLOOR(addr)        ((addr) & 0xFFFFFFFe)

#define WRITE_MEM32(addr, val)     (*(volatile unsigned int *) (addr)) = (val)
#define WRITE_MEM16(addr, val)     (*(volatile unsigned short *) (addr)) = (val)
#define WRITE_MEM8(addr, val)      (*(volatile unsigned char *) (addr)) = (val)
#define READ_MEM32(addr)           (*(volatile unsigned int *) (addr))
#define READ_MEM16(addr)           (*(volatile unsigned short *) (addr))
#define READ_MEM8(addr)            (*(volatile unsigned char *) (addr))

#define DATA_TRAINING              0
#define DATA_TRAINING_EACH_RUN     0
#define DATA_RETRAINING            0
#define REREAD_CHECK               0
#define REREAD_COUNT               20
#define SHOW_ERR_READ              1
#define SHOW_ERR_BLK               0
#define SHOW_LAST_ACC              0
#define SCAN_ERR_DATA              0
#define RANDOM_BG                  1
#define BG_DATA                    0xdeadbeef
// #define BG_DATA 0
#define CHANGE_SEED                0
#define CACHE_FLUSH                1
#define CACHE_FLUSH_WET            50000
#define SHOW_DRIFT                 0
#define CHECK_DRIFT                0

// Random Access type 
//   2: read+write, 
//   1: read only, 
//   0: write only
#define RANDOM_ACC                 2

static unsigned int x = 123456789;
int pass_ddr_test(void);
int fail_ddr_test(int status, unsigned int fail_cnt, unsigned int rd_err_cnt, unsigned int wr_err_cnt);

int pass_uart(void)
{
     WRITE_MEM32(0x4000, 0x23792379);
     WRITE_MEM32(0x3000, 0x97329732);
     return 0;
}

int fail_uart(void)
{
     WRITE_MEM32(0x4000, 0x23792379);
     WRITE_MEM32(0x3020, 0x97329732);
     while(1);
     return 0;
}

void srand2(unsigned int seed)
{
   x = seed;
}

unsigned int rand2(void)
{
   static unsigned int y = 362436;
   static unsigned int z = 521288629;
   static unsigned int c = 7654321;

   unsigned long long t, a= 698769069;

   x = 69069 * x + 12345;
   y ^= (y << 13); y ^= (y >> 17); y ^= (y << 5);
   t = a * z + c; c = (t >> 32); z = t;

   return x + y + z;
}

#ifdef EPP_CS1_ACTIVE
void rlx_flush_dcache_all(void)
{
    __asm__ __volatile__(
       ".set\tnoreorder\n"
       ".set\tnoat\n"
       "\tmfc0\t$1, $20\n"
       "\tandi\t$1, (~(0x00000200)) & 0xffff\n"
       "\tmtc0\t$1, $20\n"
       "\tor\t$1, 0x00000200\n"
       "\tmtc0\t$1, $20\n"
       ".set\tat\n"
       ".set\treorder\n");
}

void turn_on_uc_write_merge (void)
{
  asm("   .set  noat");

  asm("lui  $1, 0xf040");
  asm("ori  $1, $1, 0x0000");
  asm("mtc0 $1, $12");      // Turn on CpU

  asm("   li    $1,  0x02000000");
  asm("   mtc3  $1,  $18"); // MergeUCBase

  asm("   li    $1,  0x02ffffff");
  asm("   mtc3  $1,  $19"); // MergeUCTop

  asm(".word (0x40800000 | (0<<16) | (20<<11) | (0) ) ");   // mtc0 $0 CCTL.sel0
  asm(".word (0x40800000 | (0<<16) | (20<<11) | (1) ) ");   // mtc0 $0 CCTL.sel1

  asm("   li    $1,  0x00100000");
  asm(".word (0x40800000 | (1<<16) | (20<<11) | (0) ) ");   // WBufMergeOn
  asm(".word (0x40800000 | (1<<16) | (20<<11) | (1) ) ");   // MergeUCOn

  asm("   .set  at");
}
#endif // EPP_CS1_ACTIVE

unsigned int err_acc = 0;
int compare_data(unsigned int data0, unsigned int data1, unsigned int mask, unsigned int type)
{
  unsigned int result;
  result = data0 ^ data1;
  if(type == 0)
  {
    result = result & (mask >> 24);
  }
  else if(type == 1)
  {
    result = result & (mask >> 16);
  }
  else
  { 
    result = result & mask;
  }
  if(result == 0)
    return 1;
  else
  { 
    err_acc++;
    return 0;
  }
}

int compare_data2(  volatile unsigned int data0,   volatile unsigned int data1, 
                    volatile unsigned int data1_0, volatile unsigned int data1_1, 
                    volatile unsigned int data2_0, volatile unsigned int data2_1, 
                    volatile unsigned int data3_0, volatile unsigned int data3_1, 
                    volatile unsigned int data4_0, volatile unsigned int data4_1, 
                    volatile unsigned int data5_0, volatile unsigned int data5_1, 
                    volatile unsigned int data6_0, volatile unsigned int data6_1, 
                    volatile unsigned int data7_0, volatile unsigned int data7_1, 
                    unsigned int mask, unsigned int type)
{

  unsigned int result;
  result = (data0 ^ data1)
            | (data1_0 ^ data1_1)
            | (data2_0 ^ data2_1)
            | (data3_0 ^ data3_1)
            | (data4_0 ^ data4_1)
            | (data5_0 ^ data5_1)
            | (data6_0 ^ data6_1)
            | (data7_0 ^ data7_1)
            ;
  if(type == 0)
  {
    result = result & (mask >> 24);
  }
  else if(type == 1)
  {
    result = result & (mask >> 16);
  }
  else
  { 
    result = result & mask;
  }
  if(result == 0)
    return 1;
  else
  { 
    err_acc++;
    return 0;
  }

}

#ifdef RTL_SIM
     #define MAX_BURST    0x4
     #define MAX_SAMPLE   0x10
#else // RTL_SIM
     #define MAX_BURST    0x400
     #define MAX_SAMPLE   0x1000000
#endif // RTL_SIM

#if 0
     #define DRAM_BASE        (0x01000000+0x01000000)
     #define DRAM_SIZE        (0x00200000)
     #define TEST_BLOCK       (0x00002000)
     #define SRAM_BASE        (0x02000000+0x01000000)
#else // run-time input
     #define DRAM_BASE        (_dram_base)
     #define DRAM_SIZE        (_dram_size)
     #define TEST_BLOCK       (_test_block)
     #define SRAM_BASE        (_sram_base)
#endif

#define SOCKET_SUPPORT 0
#define STATUS_W2_SRAM 0

// Timeout setting
// Stress Test: 3600 sec (1hr)
// Normal Test: 65 sec
// Fast   test: 5 sec

#ifdef RTL_SIM
#define TEST_RTL_SIM 
#else // FPGA_SIM
// #define TEST_TIME_5SEC
#define TEST_TIME_1HR
#endif // RTL_SIM

#ifdef TEST_TIME_1HR
     // Stress test
     #define STOP_ERR_CNT 1
     //#define MAX_TEST_RUN 9000
     //#define MAX_TEST_PT  5000
     #define MAX_TEST_RUN 9000
     #define MAX_TEST_PT  5000
     #define RANDOM_SINGLE 1
     #define RANDOM_BLOCK  1
     #define RANDOM_READ   1
#else // TEST_TIME_1HR
     #ifdef TEST_TIME_10MIN
          #define STOP_ERR_CNT 1000
          #define MAX_TEST_RUN 15000
          #define MAX_TEST_PT  50000
          #define RANDOM_SINGLE 1
          #define RANDOM_BLOCK  1
          #define RANDOM_READ   1
     #else // else TEST_TIME_10MIN
          #ifdef TEST_TIME_5SEC
               // Fast test
               #define STOP_ERR_CNT 20
               #define MAX_TEST_RUN 500
               #define MAX_TEST_PT  5000
               #define RANDOM_SINGLE 1
               #define RANDOM_BLOCK  0
               #define RANDOM_READ   0
          #else // FAST_TEST
               #ifdef RTL_SIM
                    #define STOP_ERR_CNT 1
                    #define MAX_TEST_RUN 2
                    #define MAX_TEST_PT  100
                    #define RANDOM_SINGLE 1
                    #define RANDOM_BLOCK  0
                    #define RANDOM_READ   0
               #else // FPGA_SIM
                    // Normal test, test time 1 min
                    #define STOP_ERR_CNT 1
                    #define MAX_TEST_RUN 5
                    #define MAX_TEST_PT  2000
                    #define RANDOM_SINGLE 1
                    #define RANDOM_BLOCK  1
                    #define RANDOM_READ   1
               #endif // FPGA_SIM
          #endif // else TEST_TIME_1SEC
     #endif // else TEST_TIME_10MIN
#endif // else TEST_TIME_1HR

#define DEBUG 1

struct ACC {
  unsigned int cache_type;
  unsigned int access_type;
  unsigned int access_oper;
  unsigned int sram_addr;
  unsigned int gold_data;
  unsigned int dram_addr;
  unsigned int rdata;
  unsigned int wdata;
};


void show_mem (unsigned int addr) {
  volatile unsigned int *mem_ptr = addr;
  printf("Show Mem Addr: 0x%08x = 0x%08x.\n", addr, *mem_ptr);
}

int ddr_random_test( unsigned int _dram_base,
                     unsigned int _dram_size,
                     unsigned int _test_block,
                     unsigned int _sram_base,
                     unsigned int _iteration_limit,
                     unsigned int _pt_iteration_limit,
                     unsigned int _change_seed )
{
  unsigned int i, j, k,l ;
  unsigned int cache_type;
  unsigned int access_type;
  unsigned int access_oper=0;
  unsigned int offset_addr=0;
  unsigned int sram_addr;
  unsigned int dram_addr;
  unsigned int burst = MAX_BURST;
  unsigned int samples;
  int          test_run;
  unsigned int dram_test_base;

  unsigned int rdata, wdata;
  unsigned int golddata;
  unsigned int
                golddata1, rdata1,
                golddata2, rdata2,
                golddata3, rdata3,
                golddata4, rdata4,
                golddata5, rdata5,
                golddata6, rdata6,
                golddata7, rdata7;

  unsigned int wdata_array[MAX_BURST];
  unsigned int fail_count = 0;
  unsigned int overall_fail = 0;
  unsigned int mask;
  struct ACC last_acc;
  unsigned int rand_bg = BG_DATA;
  volatile unsigned int *status_ptr = LOG_ADDR;
  unsigned int new_seed;
  unsigned int cur_dqs_lat_b0, cur_dqs_lat_b1;
  unsigned int last_dqs_lat_b0, last_dqs_lat_b1;
  unsigned int cur_drift_b0, cur_drift_b1;
  unsigned int last_drift_b0, last_drift_b1;

  int retest_total_run = REREAD_COUNT;
  int retest_pass;
  int retest_rdata_match;
  int retest_run;
  unsigned int retest_dram_addr;
  unsigned int retest_rdata;
  unsigned int rd_err_count = 0;
  unsigned int pos_rd_err_count = 0;
  unsigned int pos_wr_err_count = 0;

  unsigned int eblk_addr;
  unsigned int eblk_data[8];
  int eblk_idx;

  unsigned int scan_data;
  unsigned int scan_sram_addr;
  unsigned int scan_dram_addr;
  unsigned int scan_dram_data;
  int scan_match_cnt;
  // Show some memory data for debug

  // show_mem (0xbfb06020); // DDR PLL
  // printf("START HERE\n");


  //User define the test type
  cache_type = 0;  //0: cacheable, 1: uncacheable
  access_type = 2; //0: Byte, 1: HWord, 2: Word

  last_acc.access_type = 2;
  last_acc.access_oper = 1;
  last_acc.sram_addr = 0xdeadbeef;
  last_acc.gold_data = 0xdeadbeef;
  last_acc.dram_addr = 0xdeadbeef;
  last_acc.rdata = 0xdeadbeef;
  last_acc.wdata = 0xdeadbeef;

  //clean log SRAM
  // for(i=0; i < 8; i++)
  //   *(status_ptr+i) = 0x1234dead;

  if (_change_seed == 1)
  {
    new_seed = *(status_ptr + 16);
    printf ("Current seed: 0x%08x.\n", new_seed);
    srand2(new_seed);
    *(status_ptr + 16) = rand2();

  }
  else
  {
    srand2(0x5726);  
  }

  // rlx_flush_dcache_all();

  #ifdef EPP_CS1_ACTIVE
  turn_on_uc_write_merge ();
  #endif // EPP_CS1_ACTIVE 


  if(SOCKET_SUPPORT == 1)
  {
    mask = 0xefefffff;
    printf("\nDDR Random Test with block size %x from %x size %x, DQ12 skip\n", TEST_BLOCK, DRAM_BASE, DRAM_SIZE);
  }
  else
  {
    mask = 0xffffffff;
    printf("\nDDR Random Test with block size %x from %x size %x, All Bits\n", TEST_BLOCK, DRAM_BASE, DRAM_SIZE);
  }

  if (DATA_TRAINING)
  {
    // Data Training test
    if (run_data_training(&cur_dqs_lat_b0, &cur_dqs_lat_b1) != 0) 
       return fail_ddr_test(1, 0, 0, 0);
    printf("Current DQS latency: DQS_LAT0=%d, DQS_LAT1=%d\n", cur_dqs_lat_b0, cur_dqs_lat_b1);
    last_dqs_lat_b0 = cur_dqs_lat_b0;
    last_dqs_lat_b1 = cur_dqs_lat_b1;
  } // DATA_TRAINING

  if ((SHOW_DRIFT==1) || (CHECK_DRIFT==1))
  {
    get_dqs_drift(&cur_drift_b0, &cur_drift_b1);
    if (SHOW_DRIFT==1)
    {
      printf("DDR DQS Drift (B0, B1) = (%d%d, %d%d)\n",
            (cur_drift_b0>>1) & 1, cur_drift_b0 & 1, 
            (cur_drift_b1>>1) & 1, cur_drift_b1 & 1 );
    }
    last_drift_b0 = cur_drift_b0;
    last_drift_b1 = cur_drift_b1;
  }


  if(RANDOM_SINGLE == 1)
  {
    printf("\nSTART MEM_TEST1: Random Single Test with Block size %x\n", TEST_BLOCK);

    for (test_run = 1; test_run <= _iteration_limit; test_run++)
    {

      //Decide the base address of DRAM
      dram_test_base = (rand2() % (unsigned int) (DRAM_SIZE - TEST_BLOCK));
      dram_test_base = ALIGN32_FLOOR(DRAM_BASE + dram_test_base);
          //Chuck 
      //cache_type = rand2() % 2;
   
      // Randomly determine operation/addr/data
      if (RANDOM_ACC > 1)
        access_oper = rand2() % 2; //R+W
      else
        access_oper = RANDOM_ACC;

      access_type = rand2() % 4; //Byte/Half/Word/TW
      //access_type = 2; // Word only
      // access_type = 0; // Byte only
      offset_addr = rand2() % (unsigned int) (TEST_BLOCK-0x20); 

     //Chuck
     #if (0)
      if(cache_type == 0) //uncache
      {
          dram_test_base = dram_test_base | 0x20000000;
      }
     #endif
      if(DEBUG) {
          printf("%08d/%08d  dram_test_base = 0x%08x, offset_addr=0x%08x, access_oper=%d\n",
          test_run, _iteration_limit, dram_test_base, offset_addr, access_oper);
      }    

      //printf("Select Range %x\n", dram_test_base);

      //clean the dram and sram
      for(i = dram_test_base, j = SRAM_BASE; i < TEST_BLOCK + dram_test_base; i+=4, j+=4)
      {
        if (RANDOM_BG)
          rand_bg = rand2();
        WRITE_MEM32(i, rand_bg);
        WRITE_MEM32(j, rand_bg);
      }
      // rlx_flush_dcache_all();

      for(i = 0; i < _pt_iteration_limit; i++)
      {
        if (CHECK_DRIFT==1)
        {
          get_dqs_drift(&cur_drift_b0, &cur_drift_b1);
          if ((cur_drift_b0 != last_drift_b0) || (cur_drift_b1 != last_drift_b1))
          {
            printf("Run %d, PT %d, DQS drift changed from (%d%d, %d%d) to (%d%d, %d%d)\n", 
              test_run, i,
              (last_drift_b0>>1) & 1, last_drift_b0 & 1, 
              (last_drift_b1>>1) & 1, last_drift_b1 & 1, 
              (cur_drift_b0>>1) & 1, cur_drift_b0 & 1, 
              (cur_drift_b1>>1) & 1, cur_drift_b1 & 1 );
          }
          last_drift_b0 = cur_drift_b0;
          last_drift_b1 = cur_drift_b1;
        }
  
        if(access_oper == 0) //write
        {
          //wdata       = rand2() & mask;
          wdata       = 0xa5a5a5a5;
          // wdata       =  dram_test_base + offset_addr;
          if (access_type == 0) //byte
          {
            wdata = wdata & 0xFF;
            WRITE_MEM8((offset_addr + dram_test_base), wdata);
            WRITE_MEM8((offset_addr + SRAM_BASE), wdata);
          }
          else if (access_type == 1) //hword
          {
            dram_addr = ALIGN16_FLOOR(offset_addr + dram_test_base);
            sram_addr = ALIGN16_FLOOR(offset_addr + SRAM_BASE);
            wdata = wdata & 0xFFFF;
            WRITE_MEM16(dram_addr, wdata);
            WRITE_MEM16(sram_addr, wdata);
          }
          else if (access_type == 2) //word
          {
            dram_addr = ALIGN32_FLOOR(offset_addr + dram_test_base);
            sram_addr = ALIGN32_FLOOR(offset_addr + SRAM_BASE);
            WRITE_MEM32(dram_addr, wdata);
            WRITE_MEM32(sram_addr, wdata);
          }
          else //twin-word
          {
            continue;
          }
        }
        else  //read
        {
          if (access_type == 0) //byte
          {
            dram_addr = offset_addr + dram_test_base;
            sram_addr = offset_addr + SRAM_BASE;
            rdata = READ_MEM8(dram_addr);
            rdata1 = READ_MEM8(dram_addr+1);
            rdata2 = READ_MEM8(dram_addr+2);
            rdata3 = READ_MEM8(dram_addr+3);
            rdata4 = READ_MEM8(dram_addr+4);
            rdata5 = READ_MEM8(dram_addr+5);
            rdata6 = READ_MEM8(dram_addr+6);
            rdata7 = READ_MEM8(dram_addr+7);
            golddata = READ_MEM8(sram_addr);
            golddata1 = READ_MEM8(sram_addr+1);
            golddata2 = READ_MEM8(sram_addr+2);
            golddata3 = READ_MEM8(sram_addr+3);
            golddata4 = READ_MEM8(sram_addr+4);
            golddata5 = READ_MEM8(sram_addr+5);
            golddata6 = READ_MEM8(sram_addr+6);
            golddata7 = READ_MEM8(sram_addr+7);
 
          }
          else if (access_type == 1) //hword
          {
            dram_addr = ALIGN16_FLOOR(offset_addr + dram_test_base);
            sram_addr = ALIGN16_FLOOR(offset_addr + SRAM_BASE);

            rdata = READ_MEM16(dram_addr);
            golddata = READ_MEM16(sram_addr);
            rdata1 = READ_MEM16(dram_addr+2);
            golddata1 = READ_MEM16(sram_addr+2);
            rdata2 = READ_MEM16(dram_addr+4);
            golddata2 = READ_MEM16(sram_addr+4);
            rdata3 = READ_MEM16(dram_addr+6);
            golddata3 = READ_MEM16(sram_addr+6);

            rdata4 = READ_MEM16(dram_addr+8);
            golddata4 = READ_MEM16(sram_addr+8);
            rdata5 = READ_MEM16(dram_addr+10);
            golddata5 = READ_MEM16(sram_addr+10);
            rdata6 = READ_MEM16(dram_addr+12);
            golddata6 = READ_MEM16(sram_addr+12);
            rdata7 = READ_MEM16(dram_addr+14);
            golddata7 = READ_MEM16(sram_addr+14);
          }
          else if (access_type == 2) //word
          {
            dram_addr = ALIGN32_FLOOR(offset_addr + dram_test_base);
            sram_addr = ALIGN32_FLOOR(offset_addr + SRAM_BASE);

            rdata = READ_MEM32(dram_addr);
            golddata = READ_MEM32(sram_addr);
         if(rdata!=golddata)   { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata  = 0x%08x, gold_data  = 0x%08x\n", dram_addr, sram_addr,  rdata, golddata);  return fail_uart(); }
            rdata1 = READ_MEM32(dram_addr+4 );
            golddata1 = READ_MEM32(sram_addr+4 );
         if(rdata1!=golddata1) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata1 = 0x%08x, gold_data1 = 0x%08x\n", dram_addr+4, sram_addr+4,  rdata1, golddata1); return fail_uart();}
            rdata2 = READ_MEM32(dram_addr+8 );
            golddata2 = READ_MEM32(sram_addr+8 );
         if(rdata2!=golddata2) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata2 = 0x%08x, gold_data2 = 0x%08x\n", dram_addr+8, sram_addr+8,  rdata2, golddata2); return fail_uart();}
            rdata3 = READ_MEM32(dram_addr+12);
            golddata3 = READ_MEM32(sram_addr+12);
         if(rdata3!=golddata3) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata3 = 0x%08x, gold_data3 = 0x%08x\n", dram_addr+12, sram_addr+12,  rdata3, golddata3); return fail_uart();}

            rdata4 = READ_MEM32(dram_addr+16);
            golddata4 = READ_MEM32(sram_addr+16);
         if(rdata4!=golddata4) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata4 = 0x%08x, gold_data4 = 0x%08x\n", dram_addr+16, sram_addr+16,  rdata4, golddata4); return fail_uart();}
            rdata5 = READ_MEM32(dram_addr+20);
            golddata5 = READ_MEM32(sram_addr+20);
         if(rdata5!=golddata5) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata5 = 0x%08x, gold_data5 = 0x%08x\n", dram_addr+20, sram_addr+20,  rdata5, golddata5); return fail_uart();}
            rdata6 = READ_MEM32(dram_addr+24);
            golddata6 = READ_MEM32(sram_addr+24);
         if(rdata6!=golddata6) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata6 = 0x%08x, gold_data6 = 0x%08x\n", dram_addr+24, sram_addr+24,  rdata6, golddata6); return fail_uart();}
            rdata7 = READ_MEM32(dram_addr+28);
            golddata7 = READ_MEM32(sram_addr+28);
         if(rdata7!=golddata7) { WRITE_MEM32(0x300000, 0x5555aaaa);printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata7 = 0x%08x, gold_data7 = 0x%08x\n", dram_addr+28, sram_addr+28,  rdata7, golddata7); return fail_uart();}

          }
          else //twin-word
          {
            continue;
          }

          if (wdata % 2) rand2(); // dummy for testing nonblocking load

          // Test random add cache flush
          #ifdef EPP_CS1_ACTIVE
          if (CACHE_FLUSH == 1) {
            if ((rand2() % CACHE_FLUSH_WET) == 1) {
              rlx_flush_dcache_all();
            }
          } // CACHE_FLUSH
         #endif //EPP_CS1_ACTIVE 

 
          //if(rdata != golddata)
          if ((compare_data2(rdata, golddata,
                            rdata1, golddata1,
                            rdata2, golddata2,
                            rdata3, golddata3,
                            rdata4, golddata4,
                            rdata5, golddata5,
                            rdata6, golddata6,
                            rdata7, golddata7,
                            mask, access_type) == 0)
             )
          {
               printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata  = 0x%08x, gold_data  = 0x%08x\n", dram_addr, sram_addr,  rdata, golddata);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata1 = 0x%08x, gold_data1 = 0x%08x\n", dram_addr+4, sram_addr+4,  rdata1, golddata1);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata2 = 0x%08x, gold_data2 = 0x%08x\n", dram_addr+8, sram_addr+8,  rdata2, golddata2);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata3 = 0x%08x, gold_data3 = 0x%08x\n", dram_addr+12, sram_addr+12,  rdata3, golddata3);

          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata4 = 0x%08x, gold_data4 = 0x%08x\n", dram_addr+16, sram_addr+16,  rdata4, golddata4);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata5 = 0x%08x, gold_data5 = 0x%08x\n", dram_addr+20, sram_addr+20,  rdata5, golddata5);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata6 = 0x%08x, gold_data6 = 0x%08x\n", dram_addr+24, sram_addr+24,  rdata6, golddata6);
          printf("mismatch dram_addr=0x%08x sram_addr=0x%08x: rdata7 = 0x%08x, gold_data7 = 0x%08x\n", dram_addr+28, sram_addr+28,  rdata7, golddata7);

               WRITE_MEM32(0x300000, 0x5555aaaa);
         fail_uart();
          
            if (SHOW_LAST_ACC) 
            {
              if (last_acc.access_oper == 0) 
              {
                printf("Last acc write Addr:0x%08x, Data:0x%08x\n", last_acc.dram_addr, last_acc.wdata);
              } else 
              {
                printf("Last acc Read Addr:0x%08x, Expect:0x%08x Actual:0x%08x ErrBit:%08x\n", 
                  last_acc.dram_addr, last_acc.gold_data, last_acc.rdata, 
                  last_acc.gold_data ^ last_acc.rdata);
              }
            } // SHOW_LAST_ACC

            if (DATA_RETRAINING) {
              if (run_data_training(&cur_dqs_lat_b0, &cur_dqs_lat_b1) != 0) 
                 return fail_ddr_test(0, fail_count, rd_err_count+pos_rd_err_count, pos_wr_err_count);
              if ((cur_dqs_lat_b0 != last_dqs_lat_b0) || (cur_dqs_lat_b1 != last_dqs_lat_b1))
              {
                printf("Data Re-training DQS latency changed: from (%d, %d) to (%d,%d)\n", 
                    last_dqs_lat_b0, last_dqs_lat_b1, cur_dqs_lat_b0, cur_dqs_lat_b1);
              }
              last_dqs_lat_b0 = cur_dqs_lat_b0;
              last_dqs_lat_b1 = cur_dqs_lat_b1;
            } // DATA_RETRAINING

            if (SHOW_ERR_BLK) 
            {
               //Chuck
               #if (0)
              eblk_addr = (dram_addr & 0xffffffe0) | 0x20000000; // uncacheable
               #else
              eblk_addr = (dram_addr & 0xffffffe0);
               #endif
              for (eblk_idx = 0; eblk_idx < 8; eblk_idx++) 
              {
                eblk_data[eblk_idx] = READ_MEM32(eblk_addr + eblk_idx*4);
              }
              printf("Error Block Addr:0x%08x, %08x, %08x, %08x, %08x.\n", 
                eblk_addr, eblk_data[0], eblk_data[1], eblk_data[2], eblk_data[3]);
              printf("Error Block Addr:0x%08x, %08x, %08x, %08x, %08x.\n", 
                eblk_addr+16, eblk_data[4], eblk_data[5], eblk_data[6], eblk_data[7]);
            } // SHOW_ERR_BLK

            if (REREAD_CHECK) 
            {
               //Chuck
            #if (0)
              retest_dram_addr = dram_addr | 0x20000000; // Force uncacheable read
               #else
              retest_dram_addr = dram_addr;
               #endif
              retest_pass =0;
              retest_rdata_match = 0;
              for ( retest_run=0; retest_run < retest_total_run; retest_run++) 
              {
                //delay_loop(10000);
                if (access_type == 0) //byte
                  retest_rdata = READ_MEM8(retest_dram_addr);
                else if (access_type == 1) //hword
                  retest_rdata = READ_MEM16(retest_dram_addr);
                else if (access_type == 2) //word
                  retest_rdata = READ_MEM32(retest_dram_addr);

                rand2(); // dummy for testing nonblocking load

                // printf("[Info] Double check the read word: %x\n", retest_rdata);
                if(compare_data(retest_rdata, golddata, mask, access_type) != 0) 
                {
                  // printf("[Info] Re-Read check pass: %x\n", retest_rdata);
                  retest_pass++;
                } 
                else 
                {
                  if(compare_data(retest_rdata, rdata, mask, access_type) != 0) 
                  {
                    // printf("[Info] Re-read check fail: %x, but match first read data\n", retest_rdata);
                    retest_rdata_match++;
                  }
                  //else
                  //{
                    // printf("[Info] Re-read check fail: %x\n", retest_rdata);
                  //}
                }
              }
              if (retest_pass == retest_total_run)
              {
                rd_err_count++;
              }
              else if ( retest_pass > 3)
              {
                pos_rd_err_count++;
              }
              else if (retest_rdata_match == retest_total_run)
              {
                pos_wr_err_count++;
              }
            } // REREAD_CHECK

            if (SHOW_ERR_READ == 1)
            {
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr, golddata, rdata, golddata^rdata);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 1, golddata1, rdata1, golddata1^rdata1);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 2, golddata2, rdata2, golddata2^rdata2);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 3, golddata3, rdata3, golddata3^rdata3);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 4, golddata4, rdata4, golddata4^rdata4);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 5, golddata5, rdata5, golddata5^rdata5);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 6, golddata6, rdata6, golddata6^rdata6);
              printf("[Fail] Run:%d, PT:%d, Addr:0x%08x SRAM_ADDR=0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n",
                test_run, i, dram_addr, sram_addr + (1<< access_type) * 7, golddata7, rdata7, golddata7^rdata7);

              if (REREAD_CHECK)
              {
                if (retest_pass == retest_total_run)
                {
                  printf(" ErrType: read");
                }
                else if ((retest_total_run - retest_pass) < 4)
                {
                  printf(" ErrType: Possible read\n");
                  printf("[Info] Re-read pass: %d/%d(RD Err), match first rdata: %d/%d", 
                         retest_pass, retest_total_run, retest_rdata_match, retest_total_run);
                }
                else if (retest_rdata_match == retest_total_run)
                {
                  printf(" ErrType: Possible write");
                }
                else
                {
                  printf(" ErrType: Unknown\n");
                  printf("[Info] Re-read pass: %d/%d(RD Err), match first rdata: %d/%d", 
                         retest_pass, retest_total_run, retest_rdata_match, retest_total_run);
                }
              }
              printf("\n");
            } // SHOW_ERR_READ

            if (SCAN_ERR_DATA) // Scan error data pattern from SRAM
            {
               if (RANDOM_BG || (rdata != BG_DATA)) 
               {
                scan_match_cnt = 0;
                for(scan_sram_addr = SRAM_BASE, scan_dram_addr = dram_test_base; 
                  scan_sram_addr < TEST_BLOCK + SRAM_BASE; 
                  scan_sram_addr+=4, scan_dram_addr+=4)
                {
                  scan_data = READ_MEM32(scan_sram_addr);
                  if (scan_data == rdata) {
                    scan_dram_data = READ_MEM32(scan_dram_addr);
                    printf("Scan SRAM Match, DRAM Addr:0x%08x, ErrBit:0x%08x, Data:%08x, ErrBit:0x%08x.\n", 
                      scan_dram_addr, (dram_addr ^ scan_dram_addr) & 0x0fffffff,
                      scan_dram_data, rdata ^ scan_dram_data);
                    scan_match_cnt++;
                  }
                }
                // printf("Scan SRAM Match count: %d\n", scan_match_cnt);
                if (scan_match_cnt == 0) {
                    printf("Scan SRAM no match.\n"); 
                }
              } else {
                    printf("Scan SRAM abort due to error data is bg pattern.\n"); 
              }
            }  // SCAN_ERR_DATA
            fail_count = fail_count + 1;

            if (STOP_ERR_CNT != 0) 
            {
              if (fail_count >= STOP_ERR_CNT) 
              {
                if (REREAD_CHECK) 
                {
                  printf("[ABORT] Test1 abort, exceed max err count runs:%d, faults:%d RD_ERR:%d, possible RD_ERR:%d possible WR_ERR:%d\n", 
                       test_run, fail_count, rd_err_count, pos_rd_err_count, pos_wr_err_count);
                }
                else
                {
                  printf("[ABORT] Test1 abort, exceed max err count runs:%d, faults:%d.\n", 
                       test_run, fail_count);
                }
                return fail_ddr_test(0, fail_count, rd_err_count+pos_rd_err_count, pos_wr_err_count);
              }
            }
          }
        }


      }

 
      // for write only test, read and check whole block after write done
      if (RANDOM_ACC == 0) 
      {
        for(i = dram_test_base, j = SRAM_BASE; i < TEST_BLOCK + dram_test_base; i+=4, j+=4)
        {
            //Chuck
          #if (0)
          rdata = READ_MEM32(i|0x20000000);
          #else
          rdata = READ_MEM32(i);
          #endif
          golddata = READ_MEM32(j);
          if(compare_data(rdata, golddata, mask, 2) == 0)
          {
            if (SHOW_ERR_READ)
            {
              printf("[Fail] Read back, Run:%d, PT:%d, Addr:0x%08x Expect:0x%08x Actual:0x%08x ErrBit:%08x\n", test_run, i, dram_addr, golddata, rdata, golddata^rdata);
            }
            fail_count = fail_count + 1;
          }
        }
      } // RANDOM_ACC == 0 , write only test

      if(DEBUG == 1)
      {
#if 0
        if(test_run % 100 == 0)
        {
          printf("Complete %3d runs from %x, fail count = %d\n", test_run, dram_test_base, fail_count);   
        }else
        {
          printf("Complete %3d runs from %x, fail count = %d\n", test_run, dram_test_base, fail_count);   
        }
#else
        if(fail_count!=0)
          printf("Complete %d runs from %x, fail count = %d\n", test_run, dram_test_base, fail_count);   
#endif
      }
      else
      {
        if(test_run % 100 == 0)
        {
          if ((SHOW_DRIFT==1))
          {
            get_dqs_drift(&cur_drift_b0, &cur_drift_b1);
            printf("Complete %5d runs from %x, fail count = %d, DQS drift = (%d%d, %d%d)\n", 
              test_run, dram_test_base, fail_count,
              (cur_drift_b0>>1) & 1, cur_drift_b0 & 1, 
              (cur_drift_b1>>1) & 1, cur_drift_b1 & 1 );
          }
          else
          {
            printf("Complete %5d runs from %x, fail count = %d\n", test_run, dram_test_base, fail_count);   
          }
        }
      }
      last_acc.access_type = access_type;
      last_acc.access_oper = access_oper;
      last_acc.sram_addr = sram_addr;
      last_acc.gold_data = golddata;
      last_acc.dram_addr = dram_addr;
      last_acc.wdata = wdata;
      last_acc.rdata = rdata;
      if (CHECK_DRIFT==1)
      {
        get_dqs_drift(&cur_drift_b0, &cur_drift_b1);
        if ((cur_drift_b0 != last_drift_b0) || (cur_drift_b1 != last_drift_b1))
        {
          printf("Run %d, DQS drift changed from (%d%d, %d%d) to (%d%d, %d%d)\n", test_run, 
            (last_drift_b0>>1) & 1, last_drift_b0 & 1, 
            (last_drift_b1>>1) & 1, last_drift_b1 & 1, 
            (cur_drift_b0>>1) & 1, cur_drift_b0 & 1, 
            (cur_drift_b1>>1) & 1, cur_drift_b1 & 1 );
        }
        last_drift_b0 = cur_drift_b0;
        last_drift_b1 = cur_drift_b1;
      }
    }
    printf("[DONE] Test1 Done with %d runs, %d faults!", test_run, fail_count);
    if (REREAD_CHECK == 1) 
    {
      printf(" RD_ERR:%d, possible RD_ERR:%d, possible WR_ERR:%d", 
             rd_err_count, pos_rd_err_count, pos_wr_err_count);
    }
    printf("\n");
    overall_fail += fail_count;
  }

  if (overall_fail)
    return fail_ddr_test(0, overall_fail, rd_err_count+pos_rd_err_count, pos_wr_err_count);

//----------------------------------------------------------------------//
  fail_count = 0;
  //User define the test type
  //Chuck
  //cache_type = 0;  //0: cacheable, 1: uncacheable
  access_type = 2; //0: Byte, 1: HWord, 2: Word
 
 
  if(RANDOM_BLOCK == 1)
  {
    printf("\nSTART MEM_TEST2: Random Block\n");
    for (test_run = 0; test_run < _iteration_limit; test_run++)
    {
      printf("%08d/%08d  ",test_run,_iteration_limit);
      //Generate burst length and write data randomly
      burst = rand2() % (unsigned int) MAX_BURST;
      access_type = rand2() % 3;
      
      //Generate addrress randomly
      offset_addr = rand2() % (unsigned int) DRAM_SIZE;
      
      //Refine the write data and address depends on access width
      if (access_type == 0)
      {
          //wdata = wdata & 0xFF;
      }
      else if (access_type == 1)
      {
        offset_addr = ALIGN16_FLOOR(offset_addr);
      }
      else
      {
        offset_addr = ALIGN32_FLOOR(offset_addr);
      }

      dram_addr   = DRAM_BASE + offset_addr;
      sram_addr  = SRAM_BASE + offset_addr;

       //Chuck
      //
       //Chuckcache_type = rand2() % 2;

       //Chuck
      //dram_addr = cache_type ? (dram_addr | 0x20000000) : dram_addr;
      //sram_addr = cache_type ? (sram_addr | 0x20000000) : sram_addr;

      if(DEBUG)
        printf("Test 0x%x vs 0x%x with size 0x%x\n", sram_addr, dram_addr, burst);

      /* Prepare Write Data */
      for (i = 0, j = sram_addr; i < burst ; i++)
      {
        wdata = rand2();

        if (access_type == 0)
        {    
          wdata = wdata & 0xFF;
          WRITE_MEM8(j, wdata);
        }
        else if (access_type == 1)
        {
          wdata = wdata & 0xFFFF;
          WRITE_MEM16(j, wdata);
        }
        else
        {
          WRITE_MEM32(j, wdata);
        }
        j = j + (1 << access_type);
      }

      /* Write to memory */
      for (i = 0, j = dram_addr, k = sram_addr; i < burst ; i++)
      {
        if (access_type == 0)
        {
          WRITE_MEM8(j, *(unsigned char*)k);
        }
        else if (access_type == 1)
        {
          WRITE_MEM16(j, *(unsigned short*)k);
        }
        else
        {
          WRITE_MEM32(j, *(unsigned int*)k);
        }
      
        j = j + (1 << access_type);
        k = k + (1 << access_type);
      }
      
      //flush cache if cacheable address is used
      #ifdef EPP_CS1_ACTIVE
      rlx_flush_dcache_all();
      #endif //EPP_CS1_ACTIVE 

      /* Read Verify */
      for (i = 0, j = dram_addr, k= sram_addr; i < burst ; i++)
      {
      //Read data from external memory
        if (access_type == 0)
        {
            rdata       = READ_MEM8(j);
            golddata    = READ_MEM8(k);
        }
        else if (access_type == 1)
        {
            rdata       = READ_MEM16(j);
            golddata    = READ_MEM16(k);
        }
        else
        {
            rdata       = READ_MEM32(j);
            golddata    = READ_MEM32(k);
        }

        if (burst % 2) rand2(); // dummy for nonblocking load
        j = j + (1 << access_type);
        k = k + (1 << access_type);

        //Compare data
        //if (rdata != golddata)
        if((compare_data(rdata, golddata, mask, access_type) == 0)
          )
        {
          if(DEBUG)
          {
            printf("[Fail] Addr:0x%08x Expect:0x%08x Actual:0x%08x\n", j-(1<<access_type), golddata, rdata);
          }
          fail_count = fail_count + 1;
          break;
        }
      }
       
      //Report Procedure  
      if ((test_run % 1000) == 0 && test_run >0)
        printf ("Now samples is %d (%d), fail count %d\n", test_run, access_type, fail_count);
    }
    printf("[DONE] Test2 Done with %d faults!\n", fail_count);
    overall_fail += fail_count;
  }

  if (overall_fail)
    return fail_ddr_test(0, overall_fail, rd_err_count+pos_rd_err_count, pos_wr_err_count);

//--------------------------------------------------------------//
  if(RANDOM_READ == 1)
  {
    printf("\nSTART MEM_TEST3: Random Read Test\n");
    fail_count = 0;
 
    for (samples = 0; samples < _iteration_limit; samples++)
    {
      //Generate burst length and write data randomly
      //burst = rand2() % (unsigned int) BLOCK_SIZE;
      burst = 0x2000; // 8K accesses (8KB/16KB/32KB for byte/half word/word access)
      access_type = rand2() % 3;

     //Chuck
     #if (0)
      if (rand2() % 4)
      cache_type = 0; // cacheable 
      else cache_type = 1;
     #endif
          
      //Generate addrress randomly
      offset_addr = rand2() % (unsigned int) DRAM_SIZE;
 
      //Refine the write data and address depends on access width
      if (access_type == 0)
      {
         //wdata = wdata & 0xFF;
      }
      else if (access_type == 1)
        offset_addr = ALIGN16_FLOOR(offset_addr);
      else
        offset_addr = ALIGN32_FLOOR(offset_addr);
 
      dram_addr   = DRAM_BASE + offset_addr;
      sram_addr   = SRAM_BASE;
      
       //Chuck
      //Modify due to cacheble
      //dram_addr = cache_type ? (dram_addr | 0x20000000) : dram_addr;

      printf("%08d/%08d  ",samples,_iteration_limit);
      printf("sram_addr:0x%08x, dram_addr:0x%08x access_type=%d\n", sram_addr, dram_addr, access_type);

      //printf("Copy DRAM %x to SRAM %x %x\n", dram_addr, sram_addr, burst);

      //clean SRAM
      for (i = 0, j = sram_addr; i < burst ; i++)
      {
        if (access_type == 0)
        {    
          WRITE_MEM8(j, 0);
        }
        else if (access_type == 1)
        {
          WRITE_MEM16(j, 0);
        }
        else
        {
          WRITE_MEM32(j, 0);
        }
        j = j + (1 << access_type);
      }

      //Initial read from DRAM
      for (i = 0, j = sram_addr, k = dram_addr; i < burst ; i++)
      {
        if (access_type == 0)
        {    
          WRITE_MEM8(j, *(unsigned char*)k);
        }
        else if (access_type == 1)
        {
          WRITE_MEM16(j, *(unsigned short*)k);
        }
        else
        {
          WRITE_MEM32(j, *(unsigned int*)k);
        }
 
        j = j + (1 << access_type);
        k = k + (1 << access_type);
      }

      // printf("Init Done\n");

      //Compare data
      // for (l = 0; l < 10 ; l++)
      {
        unsigned int l, m, n, o, p, q;
        l=n=p=sram_addr;
        m=o=q=dram_addr;

        for (i = 0, j = sram_addr, k = dram_addr; i < burst - 4 ; i++)
        {
          if (access_type == 0)
          {    
            rdata       = READ_MEM8(j);
            golddata    = READ_MEM8(k);
            rdata1      = READ_MEM8(l);
            golddata1   = READ_MEM8(m);
            rdata2      = READ_MEM8(n);
            golddata2   = READ_MEM8(o);
            rdata3      = READ_MEM8(p);
            golddata3   = READ_MEM8(q);
          }
          else if (access_type == 1)
          {
            rdata       = READ_MEM16(j);
            rdata1      = READ_MEM16(l);
            rdata2      = READ_MEM16(n);
            rdata3      = READ_MEM16(p);
            golddata    = READ_MEM16(k);
            golddata1   = READ_MEM16(m);
            golddata2   = READ_MEM16(o);
            golddata3   = READ_MEM16(q);
          }
          else
          {
            rdata       = READ_MEM32(j);
            golddata    = READ_MEM32(k);
            rdata1      = READ_MEM32(l);
            golddata1   = READ_MEM32(m);
            rdata2      = READ_MEM32(n);
            golddata2   = READ_MEM32(o);
            rdata3      = READ_MEM32(p);
            golddata3   = READ_MEM32(q);
          }

          if ((offset_addr >> 3) % 2) rand2(); // dummy for testing non-blocking load feature
          j = j + (1 << access_type);
          k = k + (1 << access_type);
          l = j + (1 << access_type) * 2;
          m = k + (1 << access_type) * 2;
          n = j + (1 << access_type) * 3;
          o = k + (1 << access_type) * 3;
          p = j + (1 << access_type) * 4;
          q = k + (1 << access_type) * 4;

          //if (rdata != golddata)
          if((compare_data(rdata, golddata, mask, access_type) == 0)
            || (compare_data(rdata1, golddata1, mask, access_type) == 0)
            || (compare_data(rdata2, golddata2, mask, access_type) == 0)
            || (compare_data(rdata3, golddata3, mask, access_type) == 0)
            )
          {
            if(DEBUG)
            {
              printf("Compare Failed at %x with %x\n", k, golddata);
            }  
            fail_count++;
            break;
          }
      
        }
      }
      if(DEBUG)
      {
        if (fail_count > 0) {
          printf("Copy DRAM %x to SRAM %x and compare with %d errors\n", dram_addr, sram_addr, fail_count);
          break;
        }
      }  
      if ((samples % 200) == 0 && samples >0)
        printf ("Now samples count %d , fail count %d\n", samples, fail_count);
      if (fail_count > 0)
        return fail_ddr_test(0, overall_fail, rd_err_count+pos_rd_err_count, pos_wr_err_count);
    }
    printf("[DONE] Test3 Done with %d faults!\n", fail_count);
    overall_fail += fail_count;
  }

  if(overall_fail == 0)
  {
    return 0;//pass_ddr_test();
  }
  else
  {
    return 0;//fail_ddr_test(0, overall_fail, rd_err_count+pos_rd_err_count, pos_wr_err_count);
  }
  //pass();
}

int fail_ddr_test(int status, unsigned int fail_cnt, unsigned int rd_err_cnt, 
                  unsigned int wr_err_cnt)
{
  volatile unsigned int *status_ptr = LOG_ADDR;
  if (status == 0)
  {
    *status_ptr       = 0x0000dead;
    *(status_ptr+1)   = fail_cnt;
    *(status_ptr+2)   = rd_err_cnt;
    *(status_ptr+3)   = wr_err_cnt;
  } 
  else if (status == 1)
  {
    *status_ptr       = 0x0001dead;
  }
  fail_uart();
}

int pass_ddr_test()
{
  volatile unsigned int *status_ptr = LOG_ADDR;
  *status_ptr       = 0xabcd;
  *(status_ptr+1)   = 0x0;
  pass_uart();
}

int do_mem_mtester (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
     unsigned int _dram_base;
     unsigned int _dram_size;
     unsigned int _test_block;
     unsigned int _sram_base;
     unsigned int _iteration_limit;
     unsigned int _pt_iteration_limit;
     unsigned int _change_seed;

     if (argc > 1)
		_dram_base = (unsigned int)simple_strtoul(argv[1], NULL, 16);
	else
		_dram_base = (unsigned int)0x02000000UL; // offset@32MB

	if (argc > 2)
		_dram_size = (unsigned int)simple_strtoul(argv[2], NULL, 16);
	else
		_dram_size = 0x00200000; // 2MB

	if (argc > 3)
		_test_block = (unsigned int)simple_strtoul(argv[3], NULL, 16);
	else
		_test_block = (unsigned int)0x00002000;

	if (argc > 4)
		_sram_base = (unsigned int)simple_strtoul(argv[4], NULL, 16);
	else
		_sram_base = (unsigned int)0x03000000UL;// offset@48MB

	if (argc > 5)
		_iteration_limit = (unsigned int)simple_strtoul(argv[5], NULL, 16);
	else
		_iteration_limit = 100UL;

	if (argc > 6)
		_pt_iteration_limit = (unsigned int)simple_strtoul(argv[6], NULL, 16);
	else
		_pt_iteration_limit = 100UL;

	if (argc > 7)
		_change_seed = (unsigned int)simple_strtoul(argv[7], NULL, 16);
	else
		_change_seed = 0;
     
     ddr_random_test( _dram_base,
                      _dram_size,
                      _test_block,
                      _sram_base, 
                      _iteration_limit,
                      _pt_iteration_limit,
                      _change_seed );     

     return 0;    
}

U_BOOT_CMD(
     mtester,  8,   1,   do_mem_mtester,
     "advanced RAM read/write test",
     "[dram_base [dram_size [test_block [sram_base [iterations [pt_iterations [cheng_seed]]]]]]]"
);
