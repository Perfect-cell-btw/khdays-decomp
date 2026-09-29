/* Circle tick of the ov218 enemy (the ov220 d2b08 wander with its state one word further): a negative
 * distance to the target ends the state; within 0x8000 the +0x10 yaw turns by pi (copied to +0x4c
 * unless the +0x60 flag is set), the +0x5c side flips, the +0x54 rate is re-rolled to 0x8000 +
 * rand(0x10000), the +0x58 speed is 0x4000, bit 15 of +0x50 is cleared, the tick hands off to the
 * flight state (020cd098) and runs it at once, and the actor wants animation 1; beyond it a finished
 * idle countdown (020cc7f8) just returns, else animation 0 is wanted. A wanted animation different
 * from the +0x48 one is played. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern int Ov218_DistanceToTarget(int *node);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov218_FlightTick(int *node);
extern int Ov218_WalkDecide(int *node, int value);

void Ov218_CircleTick(int *node)
{
    int *state = (int *)node[1];
    int dist;
    int anim;

    dist = Ov218_DistanceToTarget(node);
    if (dist < 0) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (dist < 0x8000) {
        state[4] += 0x3244;
        if (state[0x18] == 0) {
            state[0x13] = state[4];
        }
        *(u8 *)(state + 0x17) ^= 1;
        state[0x15] = RandNextScaled(0x10000) + 0x8000;
        state[0x16] = 0x4000;
        state[0x14] &= 0x7fff;
        anim = 1;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov218_FlightTick);
        Ov218_FlightTick(node);
    } else {
        if (Ov218_WalkDecide(node, dist) != 0) {
            return;
        }
        anim = 0;
    }
    if (anim < 0) {
        return;
    }
    if (state[0x12] != anim) {
        state[0x12] = anim;
        Ov107_PostTagUpdate((Actor *)(*state), anim, 1);
    }
}
