/* Starts the battle scene: sets up the context and session object, pushes the VRAM state, sets the
 * scene scale and markers, and returns the battle entry poll step. */

#include "nitro/types.h"
#include "game/engine.h"

typedef int (*Ov022StateCallback)(void);

typedef struct Ov022InitArgs {
    s16 kind;
    s16 x;
    s16 y;
    char pad_0006[0x82];
    void *externalObject;
} Ov022InitArgs;

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[6];
    void *slots[3];
    void *childObjects[2];
    int viewX;
    int viewY;
    char pad_0024[8];
    void *externalObject;
    int value;
    int scale;
    u16 x;
    u16 y;
    s8 kind;
    s8 phase;
    s8 state;
} Ov022Context;

extern Ov022Context *data_ov022_020b2e60;
extern u8 data_0204be04;

extern Ov022Context *NNSi_FndGetCurrentRootHeap(void);
extern void Ov022_SetupSessionObject(void);
extern void Ov002_RefreshSessionMarkerDestinations(void);
extern void Ov002_SetSceneScale(int value);
extern void Ov002_TeardownAllSpawnSlots(void);
extern int Ov022_PollBattleEntry(void);

Ov022StateCallback Ov022_BeginScene(Ov022InitArgs *args)
{
    Ov022Context *context;

    context = NNSi_FndGetCurrentRootHeap();
    data_ov022_020b2e60 = context;
    context->viewX = (int)0xffff0000;
    context->viewY = (int)0xffff0000;
    context->kind = (s8)args->kind;
    context->externalObject = args->externalObject;
    context->x = args->x;
    context->y = args->y;
    context->phase = -1;
    context->value = 0;
    data_0204be04 = 0;
    Ov022_SetupSessionObject();
    EntityMgr_PushVramState();
    context->flags = 0x16;
    context->scale = GetFrameRateMode() == 1 ? 0x1800 : 0x1000;
    context->state = -1;
    Ov002_RefreshSessionMarkerDestinations();
    Ov002_SetSceneScale(context->scale);
    Ov002_TeardownAllSpawnSlots();
    return Ov022_PollBattleEntry;
}

