#include "game/engine.h"

extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov007_RequestSceneChange(void);

/* Per-frame brightness ramp-DOWN (level = -frame/2) over 0x20 frames; once it
 * bottoms out, hold at -0x10 and return the next handler. */
int Ov007_FadeOutStep(void) {
    int root = NNSi_FndGetCurrentRootHeap();
    int ret = 0;
    int frame = *(int *)(root + 0x20) + 1;

    *(int *)(root + 0x20) = frame;
    if (frame >= 0x20) {
        SetMasterBrightnessMain(-0x10);
        ret = (int)Ov007_RequestSceneChange;
    } else {
        SetMasterBrightnessMain(-frame / 2);
    }
    return ret;
}
