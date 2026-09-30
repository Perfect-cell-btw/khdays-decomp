/* ov node state callback: stores object[+0x2c]*30/30 into a state field (magic-multiply divide),
 * then advances/guards the node state slot. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov163_Pose2GuardField58Advance(void);
void Ov163_stDiv30Store_2(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[5] = v / 30;
    Ov107_PostTagUpdate((Actor *)(*state), 8, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov163_Pose2GuardField58Advance);
}
