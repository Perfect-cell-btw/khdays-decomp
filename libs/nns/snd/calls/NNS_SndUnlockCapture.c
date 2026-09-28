

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os.h"

u32 sAlarmLock = 0;   /* sAlarmLock */
u32 data_0204a2fc = 0;   /* sCaptureLock */
u32 sChannelLock = 0;   /* sChannelLock */

/* NNS_SndUnlockCapture -- NitroSystem resource_mgr.c: NNS_SndUnlockCapture. */
void NNS_SndUnlockCapture (u32 capBitFlag)
{
    data_0204a2fc &= ~capBitFlag;
}
