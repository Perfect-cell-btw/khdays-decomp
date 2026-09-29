/* Ov253_SummonEnter -- summon entry: sends message data_ov253_020d49ec (kind 4) to the actor's
 * +0x24 hook when set, fires reaction 0x16b/0xa on the +0x388 item at its +0x394 joint's +0x14
 * anchor, sets pose 2, clears the +0x1c timer and moves the node to 020d30c8. */

#include "game/enemy_common.h"

struct hpair { unsigned short a, b; };

extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const struct hpair data_ov253_020d49ec;
extern void Ov253_AiShrinkTick(void);

void Ov253_SummonEnter(int *node) {
    int *state = (int *)node[1];
    struct hpair msg = data_ov253_020d49ec;
    void (*hook)(int, struct hpair *, int) = *(void (**)(int, struct hpair *, int))(*state + 0x24);

    if (hook != 0) {
        hook(*state, &msg, 4);
    }
    Ov107_BuildAndSendUpdate(*(int *)(*state + 0x388), 0x16b, 0xa, (void *)(*(int *)(*(int *)(*state + 0x388) + 0x394) + 0x14));
    Ov107_PostTagUpdate((Actor *)(*state), 2, 0);
    state[7] = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_AiShrinkTick);
}
