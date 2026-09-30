/* Publish the swing: send the canned 4-byte block from the config table to the owner's notify
 * hook, play animation 4 with flag 1, clear the timer, refresh the owner, rebuild the look-at
 * matrix from state[0xc..] and turn it into the quaternion at state[0x25..].
 *
 * Matched byte-exact 2026-07-23, closing an old park. The config pair has to be a STRUCT-TYPED
 * GLOBAL copied with a plain struct assignment: the copy is then one unit for the scheduler and
 * the `state` load drops into the gap between the two halfword loads and the two halfword stores,
 * where the ROM has it. Read as two array elements, the scheduler splits the pair and the state
 * load lands one slot early.
 *
 * One of three byte-identical siblings. */

#include "game/enemy_common.h"

struct pt { unsigned short a, b; };
extern void Ov201_AimLeadTarget(int self);
extern void Mtx33_LookAt(void *out, void *a, int b, void *c);
extern void Quat_FromMtx33(void *a, void *b);
extern void SetIndexedSlot(int self, int idx, int cb);
struct blk { unsigned short pad[4]; struct pt p; };
extern struct blk data_ov201_020d546c;
extern int data_02042264;
extern void Ov201_OrientReadyTimerNodeGate(void);

void Ov201_PublishSwing(int *self) {
    int *state = (int *)self[1];
    struct pt pt;
    int buf[9];
    void (*fp)(int, void *, int);

    pt = data_ov201_020d546c.p;
    fp = *(void (**)(int, void *, int))(*state + 0x24);
    if (fp != 0) {
        fp(*state, &pt, 4);
    }
    Ov107_PostTagUpdate((Actor *)(*state), 4, 1);
    state[0x14] = 0;
    Ov201_AimLeadTarget((int)self);
    Mtx33_LookAt(&buf, (void *)(state + 0xc), state[0x13], &data_02042264);
    Quat_FromMtx33((void *)(state + 0x25), &buf);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov201_OrientReadyTimerNodeGate);
}
