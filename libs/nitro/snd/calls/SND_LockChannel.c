

/* NitroSDK SND library (ARM9 side): command interface to the ARM7 sound driver. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

extern void PushCommand_impl(int command, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
#define PushCommand(c, a0, a1, a2, a3) PushCommand_impl((c), (u32)(a0), (u32)(a1), (u32)(a2), (u32)(a3))

/* SND_LockChannel -- queue a LOCK_CHANNEL command for the channels in the bit mask. */
void SND_LockChannel(u32 chBitMask, u32 flags)
{
    PushCommand(SND_COMMAND_LOCK_CHANNEL, chBitMask, flags, 0, 0);
}
