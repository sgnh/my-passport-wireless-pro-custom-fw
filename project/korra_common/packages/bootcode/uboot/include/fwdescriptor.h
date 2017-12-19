/* bsd */
typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;
typedef unsigned long		u_long;

/* sysv */
typedef unsigned char		unchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;

#define WDCKORRA_SIGN "WDCKORRA"

typedef struct {
    unchar	signature[8];
    unchar	version[16];
    ulong  normallinuxoff;
    ulong  normallinuxsize;
    ulong  normaldtboff;
    ulong  normaldtbsize;
    ulong  blueaudiooff;
    ulong  blueaudionsize;
    ulong  rescuelinuxoff;
    ulong  rescuelinuxsize;
    ulong  rescuedtboff;
    ulong  rescuedtbsize;
    ulong  rootfilesystem;
    ulong  debuglevel;	
    ulong  checksum;
} __attribute__((packed)) wd_fw_desc_table_t;

