/* Ov251_BeginRecover: ported from a matched sibling family (same shape, constants and offsets adjusted). */

#include "game/enemy_common.h"

extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov251_GuardFieldCClearField1cAdvance_2(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned int f : 8; };

void Ov251_BeginRecover(int *self) {
    int *s = (int *)self[1];
    ((struct hw60 *)(*s + 0x60))->hi |= (unsigned char)2;
    *(unsigned short *)(*s + 0x100 + 0xae) |= 1;
    ((struct b8 *)(*(int *)(*s + 0x388) + 8))->f &= ~1;
    Ov107_PostTagUpdate((Actor *)(*s), 5, 0);
    s[7] = 0;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov251_GuardFieldCClearField1cAdvance_2);
}
