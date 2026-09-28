

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void PM_PrependPreSleepCallback(PMSleepCallbackInfo * info);
void PM_AppendPostSleepCallback(PMSleepCallbackInfo * info);

/* NNS_SndStrmStart -- NitroSystem stream.c: NNS_SndStrmStart. */
void NNS_SndStrmStart (NNSSndStrm * stream)
{

    SND_StartTimer(
        stream->chBitMask,
        0,
        (u32)(1 << stream->alarmNo),
        0
        );

    if (!stream->startFlag) {
        PM_PrependPreSleepCallback(&stream->preSleepInfo);
        PM_AppendPostSleepCallback(&stream->postSleepInfo);

        stream->startFlag = TRUE;
    }
}
