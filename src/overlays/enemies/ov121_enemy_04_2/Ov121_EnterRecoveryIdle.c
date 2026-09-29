/* Enter the recovery idle: set 0x40 in the hw60 high byte, play animation 7 and stop the
 * sub-effect at +0x3a0 before continuing in the next step.
 *
 * Matched byte-exact 2026-07-23, first compile. One of three byte-identical siblings. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov121_AiTrackOffsetTick(void);

void Ov121_EnterRecoveryIdle(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate((Actor *)state[0], 7, 0);
    Ov107_StartAnim(*(int *)(state[0] + 0x3a0), 1, 0);
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), Ov121_AiTrackOffsetTick);
}
