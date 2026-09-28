/* Ov253_StunEnter -- stun entry: sends message data_ov253_020d4964 + 8 (kind 4) to the
 * actor's +0x24 hook when set, fires reaction 0x16c/6 at the +4 anchor, raises bit 0 of +0x1ae,
 * raises bits 1 and 7 then clears bit 0 of the +0x60 high byte, clears bit 0 of the +0x3b4
 * item's +8 low byte and releases the node slot. */
#include "nitro/types.h"
struct hpair { unsigned short a, b; };
struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern int data_ov253_020d4964;

void Ov253_StunEnter(int *node) {
    int *state = (int *)node[1];
    struct hpair msg = *(struct hpair *)((char *)&data_ov253_020d4964 + 8);
    void (*hook)(int, struct hpair *, int) = *(void (**)(int, struct hpair *, int))(*state + 0x24);

    if (hook != 0) {
        hook(*state, &msg, 4);
    }
    Ov107_BuildAndSendUpdate(*state, 0x16c, 6, (void *)state[1]);
    *(u16 *)(*state + 0x100 + 0xae) |= 1;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x82) << 0x18) >> 0x10);
    }
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);
    }
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo &= ~1;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
