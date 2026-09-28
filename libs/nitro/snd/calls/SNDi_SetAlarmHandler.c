

/* NitroSDK SND library (ARM9 side): command interface to the ARM7 sound driver. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

extern void PushCommand_impl(int command, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
#define PushCommand(c, a0, a1, a2, a3) PushCommand_impl((c), (u32)(a0), (u32)(a1), (u32)(a2), (u32)(a3))

typedef struct AlarmCallbackInfo {
    SNDAlarmHandler func;         /* 0x00 */
    void *arg;                    /* 0x04 */
    u8 id;                        /* 0x08 */
} AlarmCallbackInfo;
extern AlarmCallbackInfo data_02046220[8];    /* sCallbackTable */
#define sCallbackTable data_02046220

/* SNDi_SetAlarmHandler -- register the ARM9 callback of a sound alarm; the bumped id
 * lets a stale alarm message be ignored. */
u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg)
{
    AlarmCallbackInfo *info;

    info = &sCallbackTable[alarmNo];

    info->func = handler;
    info->arg = arg;
    info->id++;

    return info->id;
}
