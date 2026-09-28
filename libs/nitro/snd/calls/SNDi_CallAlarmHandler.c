

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

/* SNDi_CallAlarmHandler -- run the callback of the alarm named by the ARM7 message
 * (alarm number in the low byte, registration id in the next). */
void SNDi_CallAlarmHandler(int msg)
{
    AlarmCallbackInfo *info;
    int alarmNo = msg & 0xff;
    int id = (msg >> 8) & 0xff;

    info = &sCallbackTable[alarmNo];

    if (id == info->id) {
        if (info->func != NULL) {
            info->func(info->arg);
        }
    }
}
