

/* NitroSDK SND library (ARM9 side): command interface to the ARM7 sound driver. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

extern void PushCommand_impl(int command, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
#define PushCommand(c, a0, a1, a2, a3) PushCommand_impl((c), (u32)(a0), (u32)(a1), (u32)(a2), (u32)(a3))

extern void OS_InitMutex(OSMutex *mutex);
extern void SND_CommandInit(void);              /* SND_CommandInit */
extern void SND_AlarmInit(void);
extern BOOL data_0204472c;                    /* initialized */
extern OSMutex data_02044730;                 /* sSndMutex */
#define initialized data_0204472c
#define sSndMutex data_02044730

/* SND_Init -- bring up the ARM9 sound library once: the driver mutex, the command
 * pool and the alarm callbacks. */
void SND_Init(void)
{
    {
        if (initialized)
            return;
        initialized = TRUE;
    }

    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}
