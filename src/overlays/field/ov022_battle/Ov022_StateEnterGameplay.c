typedef signed char s8;
typedef unsigned short u16;

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x3b];
    s8 phase;
    s8 state;
} Ov022Context;

typedef struct GameRuntimeContext {
    void *activeObject;
    char pad_0004[0x38];
    int pendingValue;
} GameRuntimeContext;

extern Ov022Context *data_ov022_020b2e60;

extern void Ov002_SubmitEnabledRowMask(void);
extern GameRuntimeContext *func_ov107_020c9848(void);
extern void Ov002_SetCurrentSlotFlag1(int enabled);
extern int GameState_IsFlagSet(unsigned int flagId);
extern void Ov002_UpdateAnySlotBusyFlag(void);
extern void func_02020878(char value);
extern void *Ov022_StateGameplayHub(void);

Ov022StateCallback Ov022_StateEnterGameplay(void)
{
    Ov022Context *context = data_ov022_020b2e60;

    if ((context->flags & 4) != 0) {
        context->flags &= ~4;
    } else {
        context->state = 2;
    }

    Ov002_SubmitEnabledRowMask();
    context->flags &= ~0x10;

    if (func_ov107_020c9848() != 0 &&
        func_ov107_020c9848()->activeObject != 0) {
        Ov002_SetCurrentSlotFlag1(1);
        if (GameState_IsFlagSet(0x20b5) != 0) {
            GameRuntimeContext *runtime = func_ov107_020c9848();
            if (runtime != 0) {
                runtime->pendingValue = 0;
            }
        }
    }

    Ov002_UpdateAnySlotBusyFlag();
    if ((context->flags & 0x100) != 0) {
        func_02020878(1);
        context->flags &= ~0x100;
    }

    return Ov022_StateGameplayHub;
}
