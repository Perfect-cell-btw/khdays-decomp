

/* NitroSDK SND library (ARM9 side): command interface to the ARM7 sound driver. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

extern void PushCommand_impl(int command, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
#define PushCommand(c, a0, a1, a2, a3) PushCommand_impl((c), (u32)(a0), (u32)(a1), (u32)(a2), (u32)(a3))

/* SND_PauseSeq -- queue a PAUSE_SEQ command (pause or resume) for the sequence player. */
void SND_PauseSeq(int playerNo, BOOL flag)
{
    PushCommand(SND_COMMAND_PAUSE_SEQ, playerNo, flag, 0, 0);
}
