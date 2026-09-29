/* Opening per-frame update: runs the pending task queue step, updates the brightness and the sound
 * manager. */

#include "game/engine.h"

extern int data_ov012_0205cb20;
extern void FrameStep_UpdateTaskQueue();
extern void Ov012_UpdateOpeningBrightness();

void Ov012_UpdateOpeningGlobals(void) {
    int base = data_ov012_0205cb20;
    if (base == 0) return;
    if (*(unsigned char *)(base + 0x8be1) != 0) {
        FrameStep_UpdateTaskQueue();
        *(unsigned char *)(data_ov012_0205cb20 + 0x8be1) = 0;
    }
    Ov012_UpdateOpeningBrightness(base);
    SoundMgr_Update();
}
