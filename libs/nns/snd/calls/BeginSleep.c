

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/pxi.h"

#define SND_COMMAND_BLOCK (1 << 0)

BOOL SND_FlushCommand(u32 flags);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void NNSi_SndCaptureBeginSleep(void);

/* BeginSleep -- NitroSystem main.c: BeginSleep. */
void BeginSleep (void *)
{
    u32 commandTag;

    NNSi_SndCaptureBeginSleep();

    SND_StopTimer(0, 0, 0, 0);

    commandTag = SND_GetCurrentCommandTag();
    (void)SND_FlushCommand(SND_COMMAND_BLOCK);
    SND_WaitForCommandProc(commandTag);
}
