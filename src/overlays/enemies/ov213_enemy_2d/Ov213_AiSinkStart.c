/* Reset +0xc/+0x14 and set +0x10 = -0x400; unless the busy byte at *(child+8) is set, play the
 * anim (ov107 mode 0xf,1), clear +0x1c and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov213_AiSinkTick(int);
void Ov213_AiSinkStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0xc) = 0;
    *(int *)(child + 0x10) = -0x400;
    *(int *)(child + 0x14) = 0;
    if (*(unsigned char *)*(int *)(child + 8) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xf, 1);
    *(int *)(child + 0x1c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov213_AiSinkTick);
}
