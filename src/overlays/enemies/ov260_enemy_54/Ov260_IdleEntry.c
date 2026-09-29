/* Idle entry of the ov260 actor while it is active (+0x60 bit 0): the idle time +0x60 is rolled
 * between the +0x224 / +0x228 bounds, +8, +0xc, the +0x470 flag and +0x80 clear, pose 0x1e plays and
 * the default move (+0x1c9) is queued before the node ends. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct flags16 { unsigned short lo : 8; unsigned short hi : 8; };

extern int RandNextScaled(int n);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov260_IdleEntry(int *node)
{
    int *state = (int *)node[1];
    int v;
    int lo;

    if ((((struct flags16 *)(*state + 0x60))->lo & 1) == 0) {
        return;
    }
    lo = *(int *)(*state + 0x224);
    v = *(int *)(*state + 0x228) - lo;
    if (v < 0) {
        v = -v;
    }
    state[0x18] = lo + RandNextScaled(v + 1);
    state[2] = 0;
    state[3] = 0;
    *(int *)(*state + 0x470) = 0;
    state[0x20] = 0;
    Ov107_PostTagUpdate((Actor *)(*state), 0x1e, 0);
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
