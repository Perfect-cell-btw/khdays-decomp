/* Circling tick of the ov283 actor: the +0x48 clock runs up at the frame rate, firing the first swipe
 * (020cc830 part 0) past 0x88 and the second (part 1) past 0x550, which also rewinds the clock and the
 * +0x81 fired bits. Within 6.0 of the target (020ccb48) the actor circles (+0x70 set): the +0x40 goal
 * heading advances by the +0x34 step and the +0x3c drift (mirrored to +0x44) and the orbit moves
 * (020ccbe0); farther it stops circling and picks move 6 (or 10 on a d100 roll up to 5). The +0x50
 * limit gains twice the frame rate; past 0x7f80 the next move is 9. With clear floor three +0x80
 * ranges ahead the +0x3c drift grows by 0.2 toward the +0x7c side (up to 1.57). Unless the swipe
 * window (020ccca8) is open, a d100 roll up to 10 makes the next move 9; otherwise +0x34 rerolls
 * (1.57 to 3.14) and one time in five the actor faces the target (+0x38 / +0x40) and dashes (5). */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec3;

extern void Ov283_MapHeldItemKindToAnim(int actor, int part);
extern int Ov283_MeasureTargetGap(int *node);
extern void Ov283_AimVelocity(int *node);
extern int Ov283_AiCheckTargetDistance(int *node);
extern int RandNextScaled(int bound);
extern int Rand16NextScaled(int bound);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern int Collision_CastSphereEx(int collision, Vec3 *origin, Vec3 *dir, int radius, void *ignore);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern int func_020050b4(int x, int z);
extern const short data_0203d210[];

#define ANG2IDX(a) ((unsigned short)(((long long)(a) * 0x28be60db9391LL + 0x80000000000LL) >> 44) >> 4)

void Ov283_CircleTick(int *node)
{
    int *state = (int *)node[1];
    int world = *(int *)(*state + 4);
    Vec3 out;
    Vec3 dir;
    int hit;
    int lo = 0;

    state[0x12] += *(int *)(node[0] + 0x2c);
    if (!(*((u8 *)state + 0x81) & 1) && state[0x12] >= 0x88) {
        *((u8 *)state + 0x81) |= 1;
        Ov283_MapHeldItemKindToAnim(*state, 0);
    }
    if (!(*((u8 *)state + 0x81) & 2) && state[0x12] >= 0x550) {
        *((u8 *)state + 0x81) |= 2;
        Ov283_MapHeldItemKindToAnim(*state, 1);
        state[0x12] = 0;
        *((u8 *)state + 0x81) = 0;
    }
    if (Ov283_MeasureTargetGap(node) < 0x6000) {
        state[0x1c] = 1;
        state[0x10] += state[0xd];
        state[0x11] = state[0x10] += state[0xf];
        Ov283_AimVelocity(node);
    } else {
        state[0x1c] = 0;
        if (RandNextScaled(0x65) + lo > 5) {
            *(signed char *)(*state + 0x1c7) = 6;
        } else {
            *(signed char *)(*state + 0x1c7) = 10;
        }
    }
    state[0x14] += *(int *)(node[0] + 0x2c) * 2;
    if (state[0x14] > 0x7f80) {
        *(signed char *)(*state + 0x1c7) = 9;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    {
        int idx = ANG2IDX(state[0xe]) * 2;

        dir.x = data_0203d210[idx];
        dir.y = 0;
        dir.z = data_0203d210[idx + 1];
    }
    ScaleVec3Fx12(*(int *)(*state + 0x80) * 3, &dir, &out);
    hit = Collision_CastSphereEx(*(int *)(world + 0x7c), (Vec3 *)(*state + 0x74), &out, 0x100, 0);
    if (hit != 0 && *(int *)(hit + 8) == 0) {
        if (state[0x1f] != 0) {
            if (state[0xf] < 0x1922) {
                state[0xf] += 0x330;
            }
        } else {
            if (state[0xf] > -0x1922) {
                state[0xf] += 0x330;
            }
        }
    }
    if (Ov283_AiCheckTargetDistance(node) != 0) {
        return;
    }
    if (RandNextScaled(0x65) + lo > 10) {
        state[0xd] = Rand16NextScaled(0x1922) + 0x1922;
        if ((unsigned int)RandNextScaled(100) >= 0x14) {
            return;
        }
        {
            int idx = ANG2IDX(state[0xe]) * 2;

            dir.x = data_0203d210[idx];
            dir.y = 0;
            dir.z = data_0203d210[idx + 1];
        }
        VEC_Subtract((Vec3 *)(*(int *)(*state + 0x390) + 0x74), (Vec3 *)(*state + 0x74), &out);
        VEC_Normalize(&out, &out);
        state[0xe] = state[0x10] = func_020050b4(out.x, out.z);
        *(signed char *)(*state + 0x1c7) = 5;
        return;
    }
    *(signed char *)(*state + 0x1c7) = 9;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
