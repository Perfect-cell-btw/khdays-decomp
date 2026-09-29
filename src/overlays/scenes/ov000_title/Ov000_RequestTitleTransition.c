/* Ov000_RequestTitleTransition -- request the logo->title transition, ov000. Fades the screen
 * (SetSelectionIfChanged/InvokeSubStructAndStampByte), then latches scene 7 with an arg reflecting whether
 * the logo already finished (heap+0x4c30==0). Returns the spawn sentinel (-2). */

#include "game/engine.h"

extern void *NNSi_FndGetCurrentRootHeap(void);
int Ov000_RequestTitleTransition(void) {
    char *h = (char *)NNSi_FndGetCurrentRootHeap();
    int arg = (*(signed char *)(h + 0x4c30) == 0);
    SetSelectionIfChanged(0x1f);
    InvokeSubStructAndStampByte(0x40, 0xa);
    Scene_RequestPending(7, arg);
    return -2;
}
