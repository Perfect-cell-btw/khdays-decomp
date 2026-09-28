

#include "nitro/types.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u16 data_02044674;
void OSi_ClearAlarmBit(int timerNum);

/* OS_EndAlarm -- NitroSDK os_alarm.c: OS_EndAlarm. */
void OS_EndAlarm (void)
{
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    if (data_02044674) {

        OSi_ClearAlarmBit(OSi_ALARM_TIMER);

        data_02044674 = FALSE;
    }

    (void)OS_RestoreInterrupts(enabled);
}
