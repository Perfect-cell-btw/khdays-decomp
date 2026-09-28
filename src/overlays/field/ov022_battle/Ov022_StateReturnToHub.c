/* Fades both screens to white and moves to ending the key sharing session, clearing game-state
 * field 0x20e6. */

#include "nitro/types.h"

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x1a];
    int viewX;
    int viewY;
} Ov022Context;

extern u8 data_0204be04;
extern Ov022Context *data_ov022_020b2e60;

extern void Ov022_UpdateCameraAndViews(int mode);
extern int func_02023c40(void);
extern void StoreToGlobalPtr4Field28(int value);
extern void GameState_SetField(int field, int width, int value);
extern void SetMasterBrightnessMain(int brightness);
extern void SetMasterBrightnessSub(int brightness);
extern void *Ov022_EndKeySharingSession(void);

Ov022StateCallback Ov022_StateReturnToHub(void)
{
    Ov022Context *context = data_ov022_020b2e60;
    Ov022StateCallback next = 0;

    if (data_0204be04 != 0) {
        return next;
    }

    Ov022_UpdateCameraAndViews(1);

    int completed = 0;

    context->viewX += func_02023c40() == 1 ? 0x2000 : 0x1800;
    if (context->viewX >= 0x10000) {
        context->viewX = 0x10000;
        completed = 1;
    }
    context->viewY = context->viewX;

    if (completed != 0) {
        StoreToGlobalPtr4Field28(1);
        next = Ov022_EndKeySharingSession;
        GameState_SetField(0x20e6, 1, 0);
    }

    SetMasterBrightnessMain(context->viewX >> 12);
    SetMasterBrightnessSub(context->viewY >> 12);
    return next;
}
