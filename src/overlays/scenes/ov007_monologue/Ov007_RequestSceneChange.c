/* State after the fade-out: stores the scene change (5, saved value); returns ~1. */

#include "game/engine.h"

extern char *NNSi_FndGetCurrentRootHeap(void);

int Ov007_RequestSceneChange(void)
{
    char *p = NNSi_FndGetCurrentRootHeap();
    int r1 = *(int *)(p + 0x5000 + 0xac0);
    Scene_RequestPending(5, r1);
    return ~1;
}
