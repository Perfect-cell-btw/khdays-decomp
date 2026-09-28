typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x22];
    u64 startedAt;
    char pad_002c[8];
    int duration;
} Ov022Context;

typedef struct GameRuntimeContext {
    char pad_0000[0x3c];
    int pendingValue;
} GameRuntimeContext;

extern u8 data_0204c240;
extern Ov022Context *data_ov022_020b2e60;

extern int func_02023c40(void);
extern void Ov002_UpdateHudRecord(int id, int slot, int payload);
extern u64 OS_GetTick(void);
extern void Ov022_NotifyRowsAndFlag(void);
extern int func_ov022_02083f0c(void);
extern void Ov002_SetOrClearFlag200(int object, int enabled);
extern GameRuntimeContext *func_ov107_020c9848(void);
extern void RequestQueue_SetOrPushKind3(int event);
extern void SoundMgr_SetListenersEnabled(int enabled);
extern void GameState_SetField(int field, int width, int value);

extern void *Ov022_ExpireTimerThenNextStep(void);
extern void *func_ov022_02083844(void);

Ov022StateCallback Ov022_StateBeginResultSequence(void)
{
    Ov022Context *context = data_ov022_020b2e60;

    if ((data_0204c240 & 4) == 0) {
        GameRuntimeContext *runtime;
        int duration;

        context->flags |= 0x10;
        context->duration = func_02023c40() == 1 ? 0xf0 : 0xa0;
        Ov002_UpdateHudRecord(-2, -3, 0);
        context->startedAt = OS_GetTick();
        Ov022_NotifyRowsAndFlag();
        Ov002_SetOrClearFlag200(func_ov022_02083f0c(), 1);

        duration = func_02023c40() == 1 ? 0xf0 : 0xa0;
        runtime = func_ov107_020c9848();
        if (runtime != 0) {
            runtime->pendingValue = duration;
        }

        RequestQueue_SetOrPushKind3(0x78);
        SoundMgr_SetListenersEnabled(1);
        GameState_SetField(0x20e6, 1, 1);
        return Ov022_ExpireTimerThenNextStep;
    }

    context->flags |= 0x10;
    return func_ov022_02083844;
}
