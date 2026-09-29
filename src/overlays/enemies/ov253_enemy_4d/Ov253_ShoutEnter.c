/* Ov253_ShoutEnter -- shout entry: dispatches sprite request 4 (data_ov253_020d4964 + 0x10
 * with the actor's +2 id), sets pose 8, raises bit 0 of the +0x3b4 item's +8 low byte, clears
 * the +0x1c timer and the +0x32 flag and moves the node to 020cfc60. */

#include "game/enemy_common.h"

struct hpair { unsigned short a, b; };
struct w8 { unsigned int lo : 8, rest : 24; };

extern void func_02031384(int a, void *req, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern int data_ov253_020d4964;
extern void Ov253_ShoutTick(void);

void Ov253_ShoutEnter(int *node) {
    int *state = (int *)node[1];
    struct hpair buf = *(struct hpair *)((char *)&data_ov253_020d4964 + 0x10);

    buf.a = *(unsigned short *)(*state + 2);
    func_02031384(4, &buf, 4);
    Ov107_PostTagUpdate((Actor *)(*state), 8, 0);
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo |= 1;
    state[7] = 0;
    *((unsigned char *)state + 0x32) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_ShoutTick);
}
