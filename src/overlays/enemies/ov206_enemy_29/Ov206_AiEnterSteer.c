/* Reset the timer (+0x24), pick a landing point at (child)+0x2c = base(+0x224) +
 * rand(|+0x228 - +0x224| + 1), play the anim (ov107 mode 0xb) and register the handler. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov206_AiSteerStart(int);
void Ov206_AiEnterSteer(int param_1) {
    int child = *(int *)(param_1 + 4);
    int base, d;
    *(int *)(child + 0x24) = 0;
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x2c) = base + RandNextScaled(d + 1);
    Ov107_PostTagUpdate(*(int *)child, 0xb, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov206_AiSteerStart);
}
