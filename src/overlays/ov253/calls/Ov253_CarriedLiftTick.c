/* Ov253_CarriedLiftTick -- carried item lift: the +8 / +0x14 endpoints follow the +0x39c and +0x398
 * joints' anchors; the +0x20 timer runs up and its ratio over 0.333 (clamped to 1.0) places the
 * +4 item along the segment, scaled by twice the ratio and turned to face the segment about
 * data_02042264; once complete the item sits at the far end with scale 2.0, the timer restarts,
 * the +0x24 hop count becomes 2 and the node moves to 020d139c. */
typedef struct { int x, y, z; } Vec3;

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
extern void Ov253_CarriedHopTick(void);

void Ov253_CarriedLiftTick(int *node) {
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 pos;
    int rot[4];
    int t;
    int len;

    *(Vec3 *)(state + 2) = *(Vec3 *)(*(int *)(*state + 0x39c) + 0x14);
    *(Vec3 *)(state + 5) = *(Vec3 *)(*(int *)(*state + 0x398) + 0x14);
    state[8] += *(int *)(node[0] + 0x2c);
    t = FX_Div(state[8], 0x555);
    if (t > 0x1000) {
        t = 0x1000;
    }
    VEC_Subtract((Vec3 *)(state + 5), (Vec3 *)(state + 2), &dir);
    len = VEC_Normalize(&dir, &dir);
    ScaleVec3Fx12((int)(((long long)len * t + 0x800) >> 12), &dir, &pos);
    VEC_Add((Vec3 *)(state + 2), &pos, &pos);
    Quat_FromTwoVectors(rot, &data_02042264, &dir);
    Srt_SetScaleUniform((void *)(state[1] + 0x30), t * 2);
    Srt_SetTranslation((void *)(state[1] + 0x30), &pos);
    Srt_SetRotationQuat((void *)(state[1] + 0x30), rot);
    if (t < 0x1000) {
        return;
    }
    Srt_SetTranslation((void *)(state[1] + 0x30), (Vec3 *)(state + 5));
    Srt_SetScaleUniform((void *)(state[1] + 0x30), 0x2000);
    state[8] = 0;
    state[9] = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_CarriedHopTick);
}
