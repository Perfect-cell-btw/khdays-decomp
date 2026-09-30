/* AI step: once the actor is active, queues its stored action, posts pose 0 and ends the step. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov301_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (!(((struct hw60 *)(*state + 0x60))->lo & 1)) return;
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    Ov107_PostTagUpdate((Actor *)(*state), 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
