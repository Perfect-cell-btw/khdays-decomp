/* Set anim 5, mark +0x78=1, raise flag 0x40 in the high byte of the u16 at
 * (*child)+0x60, clear +0x75/+0x5c, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov226_SweepStrikeEntry(void);
void Ov226_AiEnterCuedAnim(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 5, 0);
    *(int *)(child + 0x78) = 1;
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x40;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    *(unsigned char *)(child + 0x75) = 0;
    *(int *)(child + 0x5c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov226_SweepStrikeEntry);
}
