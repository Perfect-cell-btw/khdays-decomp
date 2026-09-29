/* Enters gameplay: submits the row mask, updates the current slot flags and busy state, and returns
 * the gameplay hub step. */

#include "nitro/types.h"
#include "game/engine.h"

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
extern GameRuntimeContext *Ov107_GetActorManager(void);
extern void Ov002_SetCurrentSlotFlag1(int enabled);
extern void Ov002_UpdateAnySlotBusyFlag(void);
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

    if (Ov107_GetActorManager() != 0 &&
        Ov107_GetActorManager()->activeObject != 0) {
        Ov002_SetCurrentSlotFlag1(1);
        if (GameState_IsFlagSet(0x20b5) != 0) {
            GameRuntimeContext *runtime = Ov107_GetActorManager();
            if (runtime != 0) {
                runtime->pendingValue = 0;
            }
        }
    }

    Ov002_UpdateAnySlotBusyFlag();
    if ((context->flags & 0x100) != 0) {
        PauseMenu_SetAllowed(1);
        context->flags &= ~0x100;
    }

    return Ov022_StateGameplayHub;
}
