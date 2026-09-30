/* ov node state callback: stores object[+0x2c]*30/5 into a state field (magic-multiply divide),
 * then advances/guards the node state slot. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov204_ApproachDecision(void);
void Ov204_stDiv5Store(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[15] = v / 5;
    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov204_ApproachDecision);
}
