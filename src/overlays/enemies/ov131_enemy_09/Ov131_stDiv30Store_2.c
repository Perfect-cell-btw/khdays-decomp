/* ov node state callback: stores object[+0x2c]*30/30 into a state field (magic-multiply divide),
 * then advances/guards the node state slot. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov131_stIdlePose2Advance(void);
void Ov131_stDiv30Store_2(int *param_1) {
    int v = *(int *)(*param_1 + 0x2c) * 0x1e;
    int *state = (int *)param_1[1];
    state[5] = v / 30;
    Ov107_PostTagUpdate((Actor *)(*state), 8, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 8), Ov131_stIdlePose2Advance);
}
