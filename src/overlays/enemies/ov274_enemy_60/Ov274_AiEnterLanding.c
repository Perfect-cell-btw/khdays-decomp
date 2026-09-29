/* Reset the timer (+0x24=0), play the anim (ov107 mode 6), clear the phase bytes
 * (+0x50/+0x52) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov274_LandingTick(int);
void Ov274_AiEnterLanding(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x24) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 6, 0);
    *(signed char *)(child + 0x50) = 0;
    *(signed char *)(child + 0x52) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov274_LandingTick);
}
