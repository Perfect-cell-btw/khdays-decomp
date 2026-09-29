/* Ov253_TauntTick -- taunt tick: the +0x18 speed follows six times the frame step (30 / 5);
 * once the +8 item's animation is free sprite request 4 (data_ov253_020d4964 + 4 with the
 * actor's +2 id) is dispatched, pose 5 (flag 1) plays, the +0x1c timer is armed with 4.0 plus a
 * random 4.0 and the node moves to 020d0ab8. */

#include "game/enemy_common.h"
#include "game/engine.h"

struct hpair { unsigned short a, b; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const struct hpair data_ov253_020d4964[];
extern void Ov253_TauntWaitTick(void);

void Ov253_TauntTick(int *node) {
    int *state = (int *)node[1];

    state[6] = *(int *)(node[0] + 0x2c) * 0x1e / 5;
    if (*(unsigned char *)state[2] != 0) {
        return;
    }
    {
        struct hpair buf = data_ov253_020d4964[1];
        buf.a = *(unsigned short *)(*state + 2);
        MsgQueue_Post(4, &buf, 4);
    }
    Ov107_PostTagUpdate((Actor *)(*state), 5, 1);
    state[7] = RandNextScaled(0x4001) + 0x4000;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_TauntWaitTick);
}
