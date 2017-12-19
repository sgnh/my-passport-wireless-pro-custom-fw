#ifndef AUDIOAMP_USERSPACE_ACCESS_LIBRARY
#define AUDIOAMP_USERSPACE_ACCESS_LIBRARY
#ifdef __cplusplus
extern "C" {
#endif

#include <common.h>

extern int pcb_mgr_get_enum_info_byname(char *enum_name, unsigned long long *value);

#ifndef BOOL
typedef int BOOL;
#endif

#define UINT8 unsigned char

void AudioAmp_InitAudioOut2I2S_1st(void);
void AudioAmp_InitAudioOut2I2S_2nd(void);
void AudioAmp_Set951RST(BOOL val);
void AudioAmp_SetOscillator(void);
void AudioAmp_SetMute(BOOL isMute);
void AudioAmp_SetMasterVolume(UINT8 iValue);

#ifdef __cplusplus
}
#endif

#endif

