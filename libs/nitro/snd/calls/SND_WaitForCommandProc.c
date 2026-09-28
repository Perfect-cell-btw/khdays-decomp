

/* NitroSDK SND library (ARM9 side): command interface to the ARM7 sound driver. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

extern void PushCommand_impl(int command, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
#define PushCommand(c, a0, a1, a2, a3) PushCommand_impl((c), (u32)(a0), (u32)(a1), (u32)(a2), (u32)(a3))

extern BOOL SND_IsFinishedCommandTag(u32 tag);           /* SND_IsFinishedCommandTag */
extern const SNDCommand *SND_RecvCommandReply(u32 flags);   /* SND_RecvCommandReply */
extern void RequestCommandProc(void);

/* SND_WaitForCommandProc -- block until the ARM7 has processed the command list with
 * `tag`: reap replies, kick the driver, then wait reply by reply. */
void SND_WaitForCommandProc(u32 tag)
{
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }

    while (SND_RecvCommandReply(SND_COMMAND_NOBLOCK) != NULL) {
    }

    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }

    RequestCommandProc();

    while (!SND_IsFinishedCommandTag(tag)) {
        (void)SND_RecvCommandReply(SND_COMMAND_BLOCK);
    }
}
