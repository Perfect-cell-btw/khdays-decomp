/* Twin of Ov008_StepForwardIfIdle that starts the transition with mode -1. */

#include "game/engine.h"

extern void Ov008_MissionMenuStep(int obj, int mode);

void Ov008_StepBackIfIdle(int param_1) {
    if (*(int *)(param_1 + 0x158) == 0 && *(int *)(param_1 + 0x180) == 0 &&
        *(unsigned char *)(param_1 + 0x17a) > 1 && *(unsigned char *)(param_1 + 0x178) > 1) {
        Ov008_MissionMenuStep(param_1, -1);
        PlaySound(0, 2);
    }
}
