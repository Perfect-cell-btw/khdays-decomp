/* Ov245_ChargeUpTick -- charge-up tick: the +0x30 timer runs up by the frame step. Past 3.0
 * the three +0x394 slot items are launched (020d0794) from the actor's +0x3b4 goal raised by
 * 10.0 along data_02042258 rotated in thirds around data_02042264 (0x2182), each with a random
 * spread (0.5 + 3.5 random, plus a random rise), the +4 item's +0xa8 cleared and the node moved
 * to 020cff94. Under 2.5 the +0xc position eases towards the +0x390 owner's +0x190 anchor (rate
 * 0.83 per 0x88 of the step) and the goal eases towards the position (rate 0.5, capped at 0.25
 * per frame), while the goal's +0x3c0..+0x3c8 scale follows 3/4 of the timer capped at 1.5. */
typedef struct { int x, y, z; } Vec3;
struct Ov245Actor { char pad[0x394]; int slots[3]; };

extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int FX_Div(int num, int den);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void QuatFromAxisAngle(int *quat, const Vec3 *axis, int angle);
extern int RandNextScaled(int scale);
extern void Ov245_InvokeHookAndRearm(int item, void *anchor, const Vec3 *dir);
extern void Vec3TransformViaTempMtx(Vec3 *out, const int *quat, const Vec3 *in);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Vec3 data_02042258;
extern const Vec3 data_02042264;
extern const Vec3 data_02042240;
extern void Ov245_Carrier_AiStep_QueueAction2OnAnimEnd(void);

void Ov245_ChargeUpTick(int *node) {
    int *state = (int *)node[1];
    Vec3 n;
    Vec3 d;
    int quat[4];
    Vec3 origin;
    Vec3 dir;
    Vec3 v;
    int scale;
    int rest;
    int sum;
    int i;
    int actor;
    int rise;

    state[0xc] += *(int *)(node[0] + 0x2c);
    if (state[0xc] < 0x3000) {
        if (state[0xc] >= 0x2800) {
            return;
        }
        scale = state[0xc] * 0x2400 / 0x3000;
        if (scale > 0x1800) {
            scale = 0x1800;
        }
        VEC_Subtract((Vec3 *)(*(int *)(*state + 0x390) + 0x190), (Vec3 *)(state + 3), &d);
        sum = 0;
        for (rest = *(int *)(node[0] + 0x2c); rest > 0; rest -= 0x88) {
            int ratio = FX_Div(rest <= 0x88 ? rest : 0x88, 0x88);
            int t = (int)(((long long)ratio * 0xd40 + 0x800) >> 12);
            sum += (int)(((long long)(0x1000 - sum) * (0x1000 - t) + 0x800) >> 12);
        }
        ScaleVec3Fx12(sum, &d, &d);
        VEC_Add((Vec3 *)(state + 3), &d, (Vec3 *)(state + 3));
        VEC_Subtract((Vec3 *)(state + 3), (Vec3 *)(*state + 0x3b4), &d);
        d.y = 0;
        sum = 0;
        for (rest = *(int *)(node[0] + 0x2c); rest > 0; rest -= 0x88) {
            int ratio = FX_Div(rest <= 0x88 ? rest : 0x88, 0x88);
            int t = (int)(((long long)ratio * 0x800 + 0x800) >> 12);
            sum += (int)(((long long)(0x1000 - sum) * (0x1000 - t) + 0x800) >> 12);
        }
        ScaleVec3Fx12(sum, &d, &d);
        if (VEC_Normalize(&d, &n) > 0x400) {
            ScaleVec3Fx12(0x400, &n, &d);
        }
        VEC_Add((Vec3 *)(*state + 0x3b4), &d, (Vec3 *)(*state + 0x3b4));
        actor = *state;
        *(int *)(actor + 0x3c0) = scale;
        *(int *)(actor + 0x3c4) = scale;
        *(int *)(actor + 0x3c8) = scale;
        return;
    }
    origin = *(Vec3 *)(*state + 0x3b4);
    origin.y += 0xa000;
    dir = data_02042258;
    QuatFromAxisAngle(quat, &data_02042264, 0x2182);
    for (i = 0; i < 3; i++) {
        ScaleVec3Fx12(RandNextScaled(0x3801) + 0x800, &dir, &v);
        VEC_Add(&origin, &dir, &v);
        rise = RandNextScaled(0x3801 + 0x6800) + (i - i);
        v.y += rise;
        Ov245_InvokeHookAndRearm(((struct Ov245Actor *)*state)->slots[i], &v, &data_02042240);
        Vec3TransformViaTempMtx(&dir, quat, &dir);
    }
    *(unsigned char *)(state[1] + 0xa8) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_Carrier_AiStep_QueueAction2OnAnimEnd);
}
