/* Ov253_AimFollow -- camera/aim follow: the +8 distance eases towards 10.0 by a thirtieth;
 * the +4 item's +0x74 position is kept at +0x20 and the +0xc rotation's forward (data_02042258)
 * scaled by the distance gives an aim point, kept at least 1.0 above the +0x24 height; the
 * rotation is then rebuilt to face that point (0202ed60). */
typedef struct { int x, y, z; } Vec3;

extern void Vec3TransformViaTempMtx(Vec3 *out, void *rotation, const Vec3 *in);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void Quat_FromTwoVectors(void *rotation, const Vec3 *from, const Vec3 *to);
extern const Vec3 data_02042258;

void Ov253_AimFollow(int *node) {
    int *state = (int *)node[1];
    Vec3 fwd;
    Vec3 aim;
    Vec3 dir;

    state[2] += (0xa000 - state[2]) / 30;
    *(Vec3 *)(state + 8) = *(Vec3 *)(state[1] + 0x74);
    Vec3TransformViaTempMtx(&fwd, (void *)(state + 3), &data_02042258);
    ScaleVec3Fx12(state[2], &fwd, &aim);
    VEC_Add(&aim, (Vec3 *)(state + 8), &aim);
    if (aim.y < state[9] + 0x1000) {
        aim.y = state[9] + 0x1000;
    }
    VEC_Subtract(&aim, (Vec3 *)(state + 8), &dir);
    VEC_Normalize(&dir, &dir);
    Quat_FromTwoVectors((void *)(state + 3), &data_02042258, &dir);
}
