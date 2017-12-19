/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2013 by CK <cklai@realtek.com>
 *
 */

#ifndef _ASM_ARCH_FW_INFO_H_
#define _ASM_ARCH_FW_INFO_H_

//-----------------------------------------------------------------------------------------------
#include <linux/types.h>


//-----------------------------------------------------------------------------------------------
#define BYTE(d,n)		(((d) >> ((n) << 3)) & 0xFF)
#define SWAPEND32(d)	((BYTE(d,0) << 24) | (BYTE(d,1) << 16) | (BYTE(d,2) << 8) | (BYTE(d,3) << 0))

#ifndef LITTLE_ENDIAN
#define BE32_TO_CPU(value)	SWAPEND32(value)
#define CPU_TO_BE32(value)	(value)
#else
#define BE32_TO_CPU(value)	(value)
#define CPU_TO_BE32(value)	SWAPEND32(value)
#endif

#define FW_DESC_TABLE_V1_T_VERSION_1		0x1
#define FW_DESC_TABLE_V1_T_VERSION_11		0x11
#define FW_DESC_TABLE_V1_T_VERSION_21		0x21

#define FIRMWARE_DESCRIPTION_TABLE_SIGNATURE	"VERONA__" /* 8 bytes signature. */

#define EMMC_EXTERN_PARAM_BLOCK_NO	0x7c
#define EMMC_EXTERN_PARAM_SIZE		0x800
#define EMMC_HW_SETTING_BLOCK_NO	0x104
#define EMMC_BLOCK_SIZE				0x200

//#define BOOT_AV_INFO_MAGICNO BOOT_AV_INFO_MAGICNO_RTK
#define BOOT_AV_INFO_MAGICNO BOOT_AV_INFO_MAGICNO_STD3
#define BOOT_AV_INFO_MAGICNO_RTK	0x2452544B	// $RTK
#define BOOT_AV_INFO_MAGICNO_STD3	0x53544433	// STD3 <= support dynamic decode buffer

//-----------------------------------------------------------------------------------------------
typedef enum {
	FW_IDX_LINUX_KERNEL = 0,
	FW_IDX_AUDIO,
	FW_IDX_VIDEO,
	FW_IDX_SQUASH,
	FW_IDX_JFFS2,
	FW_IDX_BOOTCODE,
} fw_desc_index_t;

typedef enum {
	PART_TYPE_RESERVED = 0,
	PART_TYPE_FW,
	PART_TYPE_FS,
} part_type_code_t;

typedef enum {
	FW_TYPE_RESERVED = 0,
	FW_TYPE_BOOTCODE,
	FW_TYPE_KERNEL,
	FW_TYPE_AUDIO,
	FW_TYPE_VIDEO,
	FW_TYPE_VIDEO_2,
	FW_TYPE_ECPU,
	FW_TYPE_JFFS2,
	FW_TYPE_SQUASH,
	FW_TYPE_EXT3,
	FW_TYPE_ODD,
	FW_TYPE_YAFFS2,
	FW_TYPE_AUDIO_FILE,
	FW_TYPE_VIDEO_FILE,
	FW_TYPE_IMAGE_FILE,
} fw_type_code_t;

typedef enum {
	RTK_PLAT_ERR_OK = 0,
	RTK_PLAT_ERR_PARSE_FW_DESC,
	RTK_PLAT_ERR_READ_FW_IMG,
	RTK_PLAT_ERR_READ_KERNEL_IMG,
	RTK_PLAT_ERR_READ_RESCUE_IMG,
	RTK_PLAT_ERR_BOOT,
} rtk_plat_err_t;

//-----------------------------------------------------------------------------------------------
#if 0 // for nor
typedef struct {
	uchar	signature[8];
	uint	checksum;
	uchar	version;
	uchar	reserved[15];
	uint	length;
} __attribute__((packed)) fw_desc_table_t;

typedef struct {
	uchar	type;
#ifdef LITTLE_ENDIAN
	uchar	reserved:7,
			ro:1;
#else
	uchar	ro:1,
			reserved:7;
#endif
	uint	version;
	uint	target_addr;
	uint	offset;
	uint	length;
	uint	paddings;
	uint	checksum;
	uint	offset_1;
	uchar	reserved_1[2];
} __attribute__((packed)) fw_desc_entry_t;
#endif

typedef struct {
	uchar	signature[8];
	uint	checksum;
	uchar	version;
	uchar	reserved[7];
	uint	paddings;
	uint	part_list_len;
	uint	fw_list_len;
} __attribute__((packed)) fw_desc_table_v1_t;

typedef struct {
	uchar	type;
#ifdef LITTLE_ENDIAN
	uchar	reserved:7,
			ro:1;
#else
	uchar	ro:1,
			reserved:7;
#endif
	uint	length;
	uchar	fw_count;
	uchar	fw_type;
	uchar	reserved_1[8];
	uchar	mount_point[32];
} __attribute__((packed)) part_desc_entry_v1_t;

// for fw_desc_table_v1_t.version = FW_DESC_TABLE_V1_T_VERSION_1
typedef struct {
	uchar	type;
#ifdef LITTLE_ENDIAN
	uchar	reserved:6,
			lzma:1,
			ro:1;
#else
	uchar	ro:1,
			lzma:1,
			reserved:6;
#endif
	uint	version;
	uint	target_addr;
	uint	offset;
	uint	length;
	uint	paddings;
	uint	checksum;
	uchar	reserved_1[6];
} __attribute__((packed)) fw_desc_entry_v1_t;

// for fw_desc_table_v1_t.version = FW_DESC_TABLE_V1_T_VERSION_11
typedef struct {
	fw_desc_entry_v1_t v1;
	uint	act_size;
	uchar	hash[32];
	uchar	part_num;
	uchar	reserved[27];
} __attribute__((packed)) fw_desc_entry_v11_t;


// for fw_desc_table_v1_t.version = FW_DESC_TABLE_V1_T_VERSION_21
typedef struct {
	fw_desc_entry_v1_t v1;
	uint	act_size;
	uchar	part_num;
	uchar	RSA_sign[256];
	uchar	reserved[27];
} __attribute__((packed)) fw_desc_entry_v21_t;

 /* copy from darwin boot audio/video data info */
typedef struct {
	uint	dwMagicNumber;			//identificatin String "$RTK" or "STD3"

	uint	dwVideoStreamAddress;	//The Location of Video ES Stream
	uint	dwVideoStreamLength;	//Video ES Stream Length

	uint	dwAudioStreamAddress;	//The Location of Audio ES Stream
	uint	dwAudioStreamLength;	//Audio ES Stream Length

	uchar	bVideoDone;
	uchar	bAudioDone;

	uchar	bHDMImode;				//monitor device mode (DVI/HDMI)

	char	dwAudioStreamVolume;	//Audio ES Stream Volume -60 ~ 40

	char	dwAudioStreamRepeat;	//0 : no repeat ; 1 :repeat

	uchar	bPowerOnImage;			// Alternative of power on image or video
	uchar	bRotate;				// enable v &h flip
	uint	dwVideoStreamType;		// Video Stream Type

	uint	audio_buffer_addr;		// Audio decode buffer
	uint	audio_buffer_size;
	uint	video_buffer_addr;		// Video decode buffer
	uint	video_buffer_size;
	uint	last_image_addr;		// Buffer used to keep last image
	uint	last_image_size;
} boot_av_info_t;

/* Boot flash type (saved extern param, logo, rescue) */
typedef enum {
	BOOT_NOR_SERIAL,
	BOOT_NAND,
	BOOT_EMMC
} BOOT_FLASH_T;

typedef enum {
	FLASH_TYPE_NAND = 0,
	FLASH_TYPE_SPI,
	FLASH_TYPE_EMMC,
	FLASH_TYPE_UNKNOWN
} FLASH_TYPE_T;

#define FLASH_TYPE_NAND_STRING		"nand"
#define FLASH_TYPE_SPI_STRING		"spi"
#define FLASH_TYPE_EMMC_STRING		"emmc"
#define FLASH_TYPE_UNKNOWN_STRING	"none"

typedef enum {
	NONE_SECURE_BOOT = 0,
	NDS_SECURE_BOOT,
	RTK_SECURE_BOOT,
	DCAS_SECURE_BOOT
} SECUTE_BOOT_T;

extern BOOT_FLASH_T boot_flash_type;

//-----------------------------------------------------------------------------------------------
extern int do_bootm_linux(int flag, int argc, char *argv[], bootm_headers_t *images);

//-----------------------------------------------------------------------------------------------
typedef struct{
	uchar bIsEncrypted;			/* must fill this value before we call get layout */
	uchar bIsCompressed;		/* must fill this value before we call get layout */

	uint flash_to_ram_addr;		/* will get this result at least */
	uint encrpyted_addr;		/* option result */
	uint decrypted_addr;		/* option result */
	uint compressed_addr;		/* option result */
	uint decompressed_addr;		/* option result */
	uint image_target_addr;		/* must fill this value before we call get layout */
} MEM_LAYOUT_WHEN_READ_IMAGE_T;

extern uint get_mem_layout_when_read_image(MEM_LAYOUT_WHEN_READ_IMAGE_T *mem_layout);

#endif	// _ASM_ARCH_FW_INFO_H_

