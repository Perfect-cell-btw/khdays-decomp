/* Arms a periodic alarm that re-arms itself (used by the protection checks). */

typedef long long s64;
typedef unsigned int u32;

typedef void (*OSAlarmHandler)(void *arg);

typedef struct OSAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 pad_08[5];
    s64 period;
    s64 fire;
} OSAlarm;

typedef struct Ov004Context {
    char pad_0000[0x55ec];
    OSAlarm alarm;
} Ov004Context;

extern Ov004Context *data_ov004_02051384;

extern void OS_InitAlarm(void);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern s64 OS_GetTick(void);
extern void OS_SetPeriodicAlarm(OSAlarm *alarm, s64 fire, s64 period,
                          OSAlarmHandler handler, void *arg);

void Ov004_RearmIdleAlarm(void *arg) {
    register char *alarmBase;
    s64 tick;
    s64 fire;

    if (data_ov004_02051384->alarm.handler != 0) {
        return;
    }

    OS_InitAlarm();
    OS_CreateAlarm(&data_ov004_02051384->alarm);
    tick = OS_GetTick();
    fire = tick + 0x7fd88LL;
    alarmBase = (char *)data_ov004_02051384 + 0x1ec;
    OS_SetPeriodicAlarm((OSAlarm *)(alarmBase + 0x5400), fire, 0x7fd88,
                  Ov004_RearmIdleAlarm, 0);
}

