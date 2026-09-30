/* State after the fade-out: stores the scene change (5, saved value); returns ~1. */

#include "game/engine.h"

#include "game/scene.h"
extern char *NNSi_FndGetCurrentRootHeap(void);

int Ov007_RequestSceneChange(void)
{
    char *p = NNSi_FndGetCurrentRootHeap();
    int r1 = *(int *)(p + 0x5000 + 0xac0);
    Scene_RequestPending(SCENE_CALENDAR, r1);
    return ~1;
}
