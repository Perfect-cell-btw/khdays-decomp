/* If the object has no active handle (+0x158 and +0x180 both zero) and both
 * counters at +0x17a/+0x178 exceed 1, kick off the transition (mode 1). */

#include "game/engine.h"

extern void Ov008_MissionMenuStep(int obj, int mode);

void Ov008_StepForwardIfIdle(int param_1) {
    if (*(int *)(param_1 + 0x158) == 0 && *(int *)(param_1 + 0x180) == 0 &&
        *(unsigned char *)(param_1 + 0x17a) > 1 && *(unsigned char *)(param_1 + 0x178) > 1) {
        Ov008_MissionMenuStep(param_1, 1);
        PlaySound(0, 2);
    }
}
