#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

/* khdays: shared-bss */
u32 sAlarmLock = 0;   /* sAlarmLock */
u32 data_0204a2fc = 0;   /* sCaptureLock */
u32 sChannelLock = 0;   /* sChannelLock */

/* NNS_SndUnlockCapture -- NitroSystem resource_mgr.c: NNS_SndUnlockCapture. */
void NNS_SndUnlockCapture (u32 capBitFlag)
{
    data_0204a2fc &= ~capBitFlag;
}
