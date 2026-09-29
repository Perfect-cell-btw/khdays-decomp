/* Set the target rate (+0x2c = owner_rate*30/10), play the anim (ov107 mode 1,1), pick a
 * landing point at (child)+0x50 = base(+0x224) + rand(|+0x228 - +0x224| + 1) and register the handler. */

#include "game/enemy_common.h"

extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov119_BackOffTick(int);
void Ov119_AiEnterBackOff(int param_1) {
    int child = *(int *)(param_1 + 4);
    int base, d;
    *(int *)(child + 0x2c) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 1, 1);
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x50) = base + RandNextScaled(d + 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov119_BackOffTick);
}
