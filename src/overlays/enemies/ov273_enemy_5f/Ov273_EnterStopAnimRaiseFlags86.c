/* Raise flags 0x86 in the high byte at (*child)+0x60, clear bit 0 in the low byte of the
 * (*child)+0x3d4 slot's +8 word, stop the anim (ov107 mode 0,0) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_PublishFinishPose(int);
struct lo8_020cd654 { unsigned f : 8; };
void Ov273_EnterStopAnimRaiseFlags86(int param_1) {
    int child = *(int *)(param_1 + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    ((struct lo8_020cd654 *)(*(int *)(*(int *)child + 0x3d4) + 8))->f &= ~1;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_PublishFinishPose);
}
