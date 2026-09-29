/* Unless the busy byte at *(child+4)+0xad is set, clear bit 0 of the u16 at *(child)+0x1ae,
 * play the anim (ov107 mode 0x11,1), clear +0x28, set the +0x51 byte to 1 and register the
 * handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_AiDownTick(int);
void Ov236_AiDownLoopStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    *(unsigned short *)(*(int *)child + 0x1ae) &= ~1;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x11, 1);
    *(int *)(child + 0x28) = 0;
    *(signed char *)(child + 0x51) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_AiDownTick);
}
