/* Ground-attack tick of an ov235 state: a three-phase trigger on the rig's channel-0 frame
 * (0203bec0) -- at 1.0 reaction +0x3c8 mode 1 fires at the +8 point, at 4.0 mode 0, and once the
 * frame falls back below 4.0 the cycle restarts (+0x65). Once the +0xc idle byte clears and the owner
 * is grounded (+0x17a bit 0), mode 3 fires at the +4 point, the +0x4c cooldown is re-rolled in
 * [+0x224, +0x228], +0x50 clears and sub-state 2 is requested. */

#include "game/engine.h"

struct Bits17a { unsigned char b0 : 1; };

extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);

static inline int RandRange(int lo, int hi)
{
    int d = hi - lo;

    if (d < 0) {
        d = -d;
    }
    return lo + RandNextScaled(d + 1);
}

void Ov235_GroundAttackTick2(int *node)
{
    int *state = (int *)node[1];

    {
        unsigned char phase = *((unsigned char *)state + 0x65);

        if (phase == 0) {
            if (queryTableEntry(*(int *)(*state + 0x384), 0) >= 0x1000) {
                Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3c8), 1, (void *)state[2]);
                *((unsigned char *)state + 0x65) = 1;
            }
        } else if (phase == 1) {
            if (queryTableEntry(*(int *)(*state + 0x384), 0) >= 0x4000) {
                Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3c8), 0, (void *)state[2]);
                *((unsigned char *)state + 0x65) = 2;
            }
        } else if (phase == 2) {
            if (queryTableEntry(*(int *)(*state + 0x384), 0) < 0x4000) {
                *((unsigned char *)state + 0x65) = 0;
            }
        }
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    if (((struct Bits17a *)(*state + 0x17a))->b0 == 0) {
        return;
    }
    Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3c8), 3, (void *)state[1]);
    state[0x13] = RandRange(*(int *)(*state + 0x224), *(int *)(*state + 0x228));
    state[0x14] = 0;
    *(unsigned char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
