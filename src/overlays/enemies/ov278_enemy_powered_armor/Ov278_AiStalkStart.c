/* Unless the busy byte at *(child+0x20) is set, play the anim (ov107 mode 8,1), kick the
 * secondary anim (ov107_020c9ee8 mode 4,1 on *(child)+0x3c8), roll +0x14 = rand(0x3001) +
 * 0x2000, clear +0x18 and the +0x74 byte and register the handler. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_StalkTick(int);
void Ov278_AiStalkStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0x20) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 8, 1);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3c8), 4, 1);
    *(int *)(child + 0x14) = RandNextScaled(0x3001) + 0x2000;
    *(int *)(child + 0x18) = 0;
    *(signed char *)(child + 0x74) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_StalkTick);
}
