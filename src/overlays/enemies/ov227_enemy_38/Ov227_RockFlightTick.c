/* Flight tick of the ov227 enemy's thrown rock. Below 1.5 of speed the +0xc velocity grows by 5 % per
 * 1/30 s slice of the frame (0x88 each). Touching the owner (020d42d8) breaks it: message 0 at the
 * owner and sub-state 0. Otherwise the velocity is cast from the +4 position against the world
 * (01fff920): a wall hit clips the step to the contact, keeps the contact point in +0x18, sends
 * messages 1 and 0 there and message 9 to the owner's +0x38c partner, flags the owner (+0x60 bit 15),
 * fires reaction 0x14d mode 0x11 at the position, clears the velocity, the +0x24 timer and +0x28, and
 * hands over to 020d4a94. On landing (+0x17a bit 1) or after 5.0 the rock breaks the same way as a
 * touch (landing also fires reaction 0x14d). */
#include "nitro/types.h"
typedef struct Vec3 { int x, y, z; } Vec3;
struct Bits17a { unsigned char bit0 : 1, bit1 : 1; };
struct CollisionResult { int pad00; int pad04; int pad08; int nAlong; };

extern int VEC_Mag(Vec3 *v);
extern int FX_Div(int num, int den);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *d);
extern int Ov227_HitSweep(int *state, Vec3 *pos);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern struct CollisionResult *Collision_CastRay(void *collision, Vec3 *position, Vec3 *direction);
extern void ScaleVec3Fixed27(int scale, Vec3 *in, Vec3 *out);
extern void VEC_Add(Vec3 *a, Vec3 *b, Vec3 *d);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, Vec3 *at);
extern void Ov227_GrowTick(void);
extern const Vec3 data_02041dc8;

#define FX_MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

void Ov227_RockFlightTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 step;
    Vec3 zero;
    int world = *(int *)(*state + 4);
    struct CollisionResult *hit;
    int rem;
    int owner;

    if (VEC_Mag((Vec3 *)(state + 3)) < 0x1800) {
        for (rem = *(int *)(node[0] + 0x2c); rem > 0; rem -= 0x88) {
            ScaleVec3Fx12(FX_MUL(FX_Div(rem <= 0x88 ? rem : 0x88, 0x88), 0xcd) + 0x1000,
                          (Vec3 *)(state + 3), (Vec3 *)(state + 3));
        }
    }
    if (Ov227_HitSweep(state, (Vec3 *)(*state + 0x74)) != 0) {
        owner = *state;
        func_ov107_020c0b90(owner, 0, *(Vec3 *)(owner + 0x74), 1);
        *(unsigned char *)(*state + 0x1c7) = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    step = *(Vec3 *)(state + 3);
    hit = Collision_CastRay(*(void **)(world + 0x7c), (Vec3 *)state[1], &step);
    if (hit != 0) {
        ScaleVec3Fixed27(hit->nAlong, &step, &step);
        VEC_Add(&step, (Vec3 *)state[1], (Vec3 *)(state + 6));
        func_ov107_020c0b90(*state, 1, *(Vec3 *)(state + 6), 0);
        func_ov107_020c0b90(*state, 0, *(Vec3 *)(state + 6), 1);
        zero = data_02041dc8;
        func_ov107_020c0b90(*(int *)(*state + 0x38c), 9, zero, 0);
        owner = *state;
        {
            u16 hw = *(u16 *)(owner + 0x60);
            *(u16 *)(owner + 0x60) = (hw & ~0xff00) |
                ((((((unsigned int)hw << 0x10) >> 0x18) | 0x80) << 0x18) >> 0x10);
        }
        Ov107_BuildAndSendUpdate(state[0], 0x14d, 0x11, (Vec3 *)state[1]);
        *(Vec3 *)(state + 3) = zero;
        state[9] = 0;
        *(unsigned char *)(state + 10) = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov227_GrowTick);
        return;
    }
    owner = *state;
    if (((struct Bits17a *)(owner + 0x17a))->bit1 != 0) {
        func_ov107_020c0b90(owner, 0, *(Vec3 *)(owner + 0x74), 1);
        Ov107_BuildAndSendUpdate(state[0], 0x14d, 0x11, (Vec3 *)state[1]);
        *(unsigned char *)(*state + 0x1c7) = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    state[9] += *(int *)(node[0] + 0x2c);
    if (state[9] < 0x5000) {
        return;
    }
    owner = *state;
    func_ov107_020c0b90(owner, 0, *(Vec3 *)(owner + 0x74), 1);
    *(unsigned char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
