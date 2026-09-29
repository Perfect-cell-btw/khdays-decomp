/* Ov023_StepFade -- advance the ov023 fade one step.
 * The fade record lives at +0x104 of the scene object (data_ov023_0208a784[1]); while its current
 * value (+8) is still short of the target (+0xc), step it (Ov023_StepInterpolation) and push the new
 * brightness (+0x10) to both screens. */

#include "game/engine.h"

extern void Ov023_StepInterpolation(int slot);
extern int data_ov023_0208a784;

void Ov023_StepFade(void) {
    int *slot = (int *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x104);
    if (slot[2] < slot[3]) {
        Ov023_StepInterpolation((int)slot);
        SetMasterBrightnessMain(slot[4]);
        SetMasterBrightnessSub(slot[4]);
    }
}
