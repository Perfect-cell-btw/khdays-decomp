/* Clear +0x2c, pick a landing point at (child)+0x3c = base(+0x224) + rand(|+0x228 - +0x224| + 1),
 * play the anim (ov107 mode 9) and register the handler. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov209_AiAimStart(int);
void Ov209_AiEnterAim(int param_1) {
    int child = *(int *)(param_1 + 4);
    int base, d;
    *(int *)(child + 0x2c) = 0;
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x3c) = base + RandNextScaled(d + 1);
    Ov107_PostTagUpdate(*(int *)child, 9, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov209_AiAimStart);
}
