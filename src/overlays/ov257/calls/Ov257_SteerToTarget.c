/* Steering helper of the ov257 states: returns the gap from the owner to the target (the distance
 * between their +0x74 centres less both +0x80 radii; 0 without a target) after turning the +0x2c
 * orientation to face it about data_02042264. The +0x3d0 part's motion step (020c9f48) is then
 * turned by the +0x1c orientation and stored in *dir, its speed in *speed (either may be null),
 * with or without a target. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int w[4]; } Quat;

extern void VEC_Subtract(const void *a, const void *b, Vec3 *out);
extern int func_020050b4(int y, int x);
extern void QuatFromAxisAngle(Quat *out, const Vec3 *axis, int angle);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern int Ov107_ActionResource_GetOffsetAndScale(int part, Vec3 *out);
extern void Vec3TransformViaTempMtx(Vec3 *out, void *q, const Vec3 *in);
extern const Vec3 data_02042264;

int Ov257_SteerToTarget(int *state, int target, Vec3 *dir, int *speed)
{
    Vec3 step;
    Vec3 d;
    int gap;
    int s;
    int owner;

    gap = 0;
    if (target != 0) {
        owner = *state;
        VEC_Subtract((void *)(target + 0x74), (void *)(owner + 0x74), &d);
        QuatFromAxisAngle((Quat *)(state + 0xb), &data_02042264, func_020050b4(d.x, d.z));
        gap = VEC_Normalize(&d, &d) - *(int *)(owner + 0x80) - *(int *)(target + 0x80);
    }
    s = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x3d0), &step);
    Vec3TransformViaTempMtx(&step, state + 7, &step);
    if (dir != 0) {
        *dir = step;
    }
    if (speed != 0) {
        *speed = s;
    }
    return gap;
}
