/* Homing turn tick: snapshots the +8 target's +0x10 position into +0x70, runs the +0x18 timer
 * and maps it to a 0..1 blend t. The +0x30 rotation faces the target from the +4 anchor, the
 * +0x20 pose slerps towards it by 30/5 of the frame step, its forward (data_02042258) scaled by
 * the +0x1c speed and by t is blended with (1 - t) of the +0x64 base velocity into +0xc, and the
 * +0x40 rotation is rebuilt from data_0204227c and the same direction. Once t reaches 1.0 the timer and +0x7c
 * clear, bit 1 of the actor's +0x394 is raised and the node moves to 020d1208. */
typedef struct { int x, y, z; } Vec3;

extern int FX_Div(int num, int den);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void Quat_FromTwoVectors(void *rotation, const Vec3 *from, const Vec3 *to);
extern void Quat_Slerp(void *a, int s, void *b, void *m);
extern void Vec3TransformViaTempMtx(Vec3 *out, void *rotation, const Vec3 *in);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Vec3 data_02042258;
extern const Vec3 data_0204227c;
extern void Ov213_HomingDashTick(void);

void Ov213_HomingTurnTick(int *node) {
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 fwd;
    int t;

    *(Vec3 *)(state + 0x1c) = *(Vec3 *)(state[2] + 0x10);
    state[6] += *(int *)(node[0] + 0x2c);
    t = FX_Div(state[6], 0x1000);
    if (t > 0x1000) t = 0x1000;
    VEC_Subtract((Vec3 *)(state + 0x1c), (Vec3 *)state[1], &dir);
    VEC_Normalize(&dir, &dir);
    Quat_FromTwoVectors((void *)(state + 0xc), &data_02042258, &dir);
    Quat_Slerp(state + 8, *(int *)(node[0] + 0x2c) * 30 / 5, state + 8, state + 0xc);
    Vec3TransformViaTempMtx(&fwd, (void *)(state + 8), &data_02042258);
    ScaleVec3Fx12(state[7], &fwd, &fwd);
    ScaleVec3Fx12(t, &fwd, &fwd);
    ScaleVec3Fx12(0x1000 - t, (Vec3 *)(state + 0x19), (Vec3 *)(state + 3));
    VEC_Add((Vec3 *)(state + 3), &fwd, (Vec3 *)(state + 3));
    Quat_FromTwoVectors((void *)(state + 0x10), &data_0204227c, &dir);
    if (t < 0x1000) return;
    state[6] = 0;
    state[0x1f] = 0;
    *(int *)(*state + 0x394) |= 2;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov213_HomingDashTick);
}
