/* Refreshes the current phase and, in state 3, updates the scene's widget. */

#include "game/engine.h"

extern void Ov011_RefreshCurrentPhase();
extern int data_ov011_0205e960;

void Ov011_RunSetupThenInvokeIfState3(void) {
    int r1;
    Ov011_RefreshCurrentPhase();
    r1 = *(int *)((char *)&data_ov011_0205e960 + 4);
    if (*(int *)(r1 + 4) != 3) return;
    DispObjList_UpdateImmediate(r1 + 0x28508);
}
