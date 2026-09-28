/* Ov253_CarriedHopTick -- carried item hop: the +8 / +0x14 endpoints follow the actor's +0x38c
 * item table at the +0x24 hop index plus one and at the index; the +0x20 timer runs up and its
 * ratio over 0.25 (clamped to 1.0) places the +4 item along the segment at scale 2.0, turned to
 * face it about data_02042264; once complete the item sits at the far end, the timer restarts
 * and the hop count drops -- at zero bit 1 of the item's +0x5c is raised and the node moves to
 * 020d150c. */
typedef struct { int x, y, z; } Vec3;
struct Ov253Items { char pad[0x38c]; int items[4]; };
struct Ov253ItemsNext { char pad[0x390]; int items[3]; };

extern int FX_Div(int num, int den);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void Quat_FromTwoVectors(void *rotation, const Vec3 *from, const Vec3 *to);
extern void Srt_SetScaleUniform(void *srt, int scale);
extern void Srt_SetTranslation(void *srt, const Vec3 *translation);
extern void Srt_SetRotationQuat(void *srt, const void *rotation);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Vec3 data_02042264;
extern void Ov253_CarriedReturnTick(void);

void Ov253_CarriedHopTick(int *node) {
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 pos;
    int rot[4];
    int t;
    int len;

    *(Vec3 *)(state + 2) = *(Vec3 *)(((struct Ov253ItemsNext *)*state)->items[state[9]] + 0x14);
    *(Vec3 *)(state + 5) = *(Vec3 *)(((struct Ov253Items *)*state)->items[state[9]] + 0x14);
    state[8] += *(int *)(node[0] + 0x2c);
    t = FX_Div(state[8], 0x400);
    if (t > 0x1000) {
        t = 0x1000;
    }
    VEC_Subtract((Vec3 *)(state + 5), (Vec3 *)(state + 2), &dir);
    len = VEC_Normalize(&dir, &dir);
    ScaleVec3Fx12((int)(((long long)len * t + 0x800) >> 12), &dir, &pos);
    VEC_Add((Vec3 *)(state + 2), &pos, &pos);
    Quat_FromTwoVectors(rot, &data_02042264, &dir);
    Srt_SetTranslation((void *)(state[1] + 0x30), &pos);
    Srt_SetScaleUniform((void *)(state[1] + 0x30), 0x2000);
    Srt_SetRotationQuat((void *)(state[1] + 0x30), rot);
    if (t < 0x1000) {
        return;
    }
    Srt_SetTranslation((void *)(state[1] + 0x30), (Vec3 *)(state + 5));
    state[8] = 0;
    state[9] -= 1;
    if (state[9] != 0) {
        return;
    }
    state[9] = 0;
    *(int *)(state[1] + 0x5c) |= 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_CarriedReturnTick);
}
