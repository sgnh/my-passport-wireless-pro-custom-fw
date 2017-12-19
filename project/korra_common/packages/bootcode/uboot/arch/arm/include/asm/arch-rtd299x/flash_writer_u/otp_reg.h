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
#define OTP_REG_BASE                    0x18038000

#define OTP_DATA                        (OTP_REG_BASE + 0)

#define OTP_EFUSE_SECUREBOOT            0x180381d8
#define OTP_EFUSE_BACKDOOR              0x180381d8


/* OTP state */
#define TWO_STATE_VIRGIN                0
#define TWO_STATE_DEFAULT               1
#define TWO_STATE_SECURE                3

#define THREE_STATE_VIRGIN              0
#define THREE_STATE_DEFAULT             1
#define THREE_STATE_PROTECTED           3
#define THREE_STATE_SECURE              7
#define THREE_STATE_SECURE1             3
#define THREE_STATE_SECURE2             5

#define FOUR_STATE_VIRGIN               0
#define FOUR_STATE_DEFAULT              1
#define FOUR_STATE_SECURE1              3
#define FOUR_STATE_SECURE2              5
#define FOUR_STATE_SECURE3              9

#endif /* #ifndef OTP_REG_H */
