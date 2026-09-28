

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/snd.h"

u32 sAlarmLock = 0;   /* sAlarmLock */
u32 data_0204a2fc = 0;   /* sCaptureLock */
u32 sChannelLock = 0;   /* sChannelLock */

/* NNS_SndAllocAlarm -- NitroSystem resource_mgr.c: NNS_SndAllocAlarm. */
int NNS_SndAllocAlarm (void)
{
    int alarmNo;
    u32 mask = 1;

    for (alarmNo = 0; alarmNo < SND_ALARM_NUM; alarmNo++, mask <<= 1) {
        if ((sAlarmLock & mask) == 0) {
            sAlarmLock |= mask;
            return alarmNo;
        }
    }

    return -1;
}
