/* Decay the counter at state[0xb] by 0x100, copy the vec3 at state+0x28 down to state+0x1c, and
 * ONLY IF bit 0 of owner+0x17a is set, fire attack 6 (flag 0) and chain the next step.
 * Byte-identical across ov293/ov121/ov122/ov293, so all four share this name. Retired from two
 * competing names, both wrong: AdvancePositionUnlessHitFlag inverted the gate (it fires IF the
 * flag, not unless) and described the vec copy as a position advance; ConfigSubStateThenAdvanceSlot
 * mentioned neither the decay nor the copy. */

#include "game/enemy_common.h"

struct v3 { int x, y, z; };
struct bit0 { unsigned char b : 1; };
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov293_AdvanceStateSetField18_2(void);

void Ov293_DecayCopyPosFireOnHitFlag(int *node) {
    int *state = (int *)node[1];
    state[0xb] -= 0x100;
    *(struct v3 *)((char *)state + 0x1c) = *(struct v3 *)((char *)state + 0x28);
    if (!((struct bit0 *)(*state + 0x17a))->b) return;
    Ov107_PostTagUpdate((Actor *)(*state), 6, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov293_AdvanceStateSetField18_2);
}
