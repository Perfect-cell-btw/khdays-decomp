#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define OSi_ALARM_TIMER OS_TIMER_1

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
typedef enum {
    OS_TIMER_0 = 0,
    OS_TIMER_1 = 1,
    OS_TIMER_2 = 2,
    OS_TIMER_3 = 3
} OSTimer;
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
