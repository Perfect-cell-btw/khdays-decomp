

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/hw.h"

typedef void *OSMessage;

typedef int OSTimer;
#define OS_TIMER_0 0
#define OS_TIMER_PRESCALER_64 (1UL << 0)
#define OSi_TICK_TIMERCONTROL  (REG_OS_TM0CNT_H_E_MASK | REG_OS_TM0CNT_H_I_MASK | OS_TIMER_PRESCALER_64)
#define OSi_TICK_TIMER         OS_TIMER_0

static inline void OS_SetTimerCount(OSTimer id, u16 count)
{
    *((vu16 *)((u32)REG_TM0CNT_L_ADDR + id * 4)) = count;
}

static inline void OS_SetTimerControl(OSTimer id, u16 control)
{
    *((vu16 *)((u32)REG_TM0CNT_H_ADDR + id * 4)) = control;
}

/* os_tick.c statics, one .bss block: OSi_UseTick (u16), OSi_NeedResetTimer, OSi_TickCounter. */
extern struct { u16 useTick; u16 pad; BOOL needResetTimer; volatile u64 tickCounter; } data_02044664;
#define OSi_NeedResetTimer data_02044664.needResetTimer
#define OSi_TickCounter data_02044664.tickCounter
extern void OSi_EnterTimerCallback(int timerNo, void (*callback)(void *), void *arg);

/* OSi_CountUpTick -- NitroSDK os_tick.c: OSi_CountUpTick, the timer 0 overflow handler:
 * bump the 64-bit tick counter, restart the timer when a reset was requested, and
 * re-arm itself as the timer callback. */
void OSi_CountUpTick(void)
{
    OSi_TickCounter++;

    if (OSi_NeedResetTimer) {
        OS_SetTimerControl(OSi_TICK_TIMER, 0);
        OS_SetTimerCount((OSTimer)OSi_TICK_TIMER, (u16)0);
        OS_SetTimerControl(OSi_TICK_TIMER, (u16)OSi_TICK_TIMERCONTROL);

        OSi_NeedResetTimer = FALSE;
    }

    OSi_EnterTimerCallback(OSi_TICK_TIMER, (void (*)(void *))OSi_CountUpTick, 0);
}
