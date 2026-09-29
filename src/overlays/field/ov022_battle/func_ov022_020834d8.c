/* Enables the sound listeners, records the local player's pending object, flags the dispatcher,
 * runs the frame and resets the camera; returns the roster step. */

#include "game/engine.h"

extern void func_ov022_020884ec(unsigned int arg0);
extern void Ov022_SetBit3OnPtr20(int arg0, int arg1);
extern void Ov022_UpdateCameraAndViews(int arg0);
extern void Ov002_ResetCameraFraming(void);
extern int data_0204be04;
extern int data_ov022_020b2e60;
extern void Ov022_StateRosterStep(void);

int func_ov022_020834d8(void) {
    unsigned int u;
    int e;
    if (*(unsigned char *)&data_0204be04 != 0) return 0;
    SoundMgr_SetListenersEnabled(1);
    u = QueryActiveStateOrDelegate();
    e = GetEntryField20ByIndex(u);
    *(int *)(*(int *)&data_ov022_020b2e60 + 0x30) = *(int *)(e + 0x2668);
    func_ov022_020884ec(u);
    Ov022_SetBit3OnPtr20(*(int *)(*(int *)&data_ov022_020b2e60 + 8), 1);
    Ov022_UpdateCameraAndViews(1);
    Ov002_ResetCameraFraming();
    return (int)Ov022_StateRosterStep;
}
