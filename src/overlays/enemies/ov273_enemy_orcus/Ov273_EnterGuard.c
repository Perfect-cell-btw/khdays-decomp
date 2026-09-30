/* Guard entry: raise flag 0x80 and clear bit 0 in the high byte at (*holder)+0x60, set bits
 * 0-1 of the +0x1ae halfword, clear bit 0 in the low byte of the +0x3d4 slot's +8 word, spawn
 * effect 0 (kind 0x4d) at the +4 anchor, reset the +0x1c7 request and dispatch null. */

#include "nitro/types.h"

struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot();

void Ov273_EnterGuard(int this_) {
    int holder = *(int *)(this_ + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x80;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    {
        int actor = *(int *)holder;
        u16 hw = *(u16 *)(actor + 0x60);
        *(u16 *)(actor + 0x60) = (hw & ~0xff00) |
            (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);
    }
    *(unsigned short *)(*(int *)holder + 0x100 + 0xae) |= 3;
    ((struct bf *)(*(int *)(*(int *)holder + 0x3d4) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*(int *)holder, 0, 0x4d, *(int *)(holder + 4));
    *(signed char *)(*(int *)holder + 0x1c7) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
