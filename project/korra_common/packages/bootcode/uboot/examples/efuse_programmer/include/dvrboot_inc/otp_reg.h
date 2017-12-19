/************************************************************************
 *
 *  otp_reg.h
 *
 *  Defines for Nike OTP registers
 *
 ************************************************************************/

#ifndef OTP_REG_H
#define OTP_REG_H

/************************************************************************
 *  Definition
 ************************************************************************/
#define OTP_REG_BASE           0xb8038000

#define OTP_EF_CTRL			(OTP_REG_BASE + 0x200)
#define OTP_EF_CTRL_ST		(OTP_REG_BASE + 0x204)

#define OTP_EFUSE_SECUREBOOT			0xb80381d8
#define OTP_EFUSE_BACKDOOR				0xb80381d8


#define EF_CTRL_WRITE_EN1			(1 << 12)



#endif /* #ifndef OTP_REG_H */
