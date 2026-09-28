

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/pxi.h"

#define SND_COMMAND_BLOCK (1 << 0)

BOOL SND_FlushCommand(u32 flags);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void PushCommand_16(int decay);
void NNSi_SndCaptureStop(void);
void NNS_SndPlayerStopSeqAll(int fadeFrame);
void NNS_SndArcStrmStopAll(int fadeFrame);

/* NNS_SndStopSoundAll -- NitroSystem main.c: NNS_SndStopSoundAll. */
void NNS_SndStopSoundAll (void)
{
    u32 commandTag;

    NNS_SndPlayerStopSeqAll(0);
#ifndef SDK_SMALL_BUILD
    NNS_SndArcStrmStopAll(0);
#endif
    NNSi_SndCaptureStop();

    PushCommand_16(0);
    SND_StopTimer(0xffff, 0xffff, 0xffff, 0);

    commandTag = SND_GetCurrentCommandTag();
    (void)SND_FlushCommand(SND_COMMAND_BLOCK);
    SND_WaitForCommandProc(commandTag);
}
