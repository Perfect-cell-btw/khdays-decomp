/* Approach decision tick: scales the +0x50 velocity by 0.8 (0xccd), publishes it as the +0xc
 * velocity, sets the +0x48 rate to 30/10 of the frame step and, unless the +8 flag byte is set,
 * rolls a percentage: while the +0x6c wait is spent it picks pose 8 / 0xc / 0xd (33/33/34 %),
 * otherwise pose 5 (80 %) or 4; then dispatches with a null handler. */

#include "game/engine.h"

struct v3 { int a, b, c; };
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov213_ApproachDecisionTick(int *node) {
    int *state = (int *)node[1];
    int v;
    int r;
    ScaleVec3Fx12(0xccd, state + 0x14, state + 0x14);
    *(struct v3 *)(state + 3) = *(struct v3 *)(state + 0x14);
    state[0x12] = *(int *)(node[0] + 0x2c) * 30 / 10;
    if (*(unsigned char *)state[2] != 0) return;
    r = RandNextScaled(0x65) + (v - v);
    if (state[0x1b] <= 0) {
        if (r < 0x21) {
            *(signed char *)(*state + 0x1c7) = 8;
        } else if (r < 0x42) {
            *(signed char *)(*state + 0x1c7) = 0xc;
        } else {
            *(signed char *)(*state + 0x1c7) = 0xd;
        }
    } else {
        if (r < 0x50) {
            *(signed char *)(*state + 0x1c7) = 5;
        } else {
            *(signed char *)(*state + 0x1c7) = 4;
        }
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), (void *)0);
}
