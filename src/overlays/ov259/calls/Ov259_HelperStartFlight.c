/* Start the flight of an ov259 helper: the owner's next move is 1, +0x18 takes `dir`, +0x28 the
 * heading and the +0xc velocity is `dir` at 0.3125. The launch point (owner pose origin nudged
 * 0x10e along x) and the heading / ground-normal orientation are computed but not stored, as in
 * the original. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int x, y, z, w; } Quat;

extern void Vec3TransformViaTempMtx(Vec3 *out, const void *m, const Vec3 *in);
extern void QuatFromAxisAngle(Quat *out, const Vec3 *axis, int angle);
extern void Quat_FromTwoVectors(Quat *out, const Vec3 *from, const Vec3 *to);
extern void Quat_Multiply(Quat *a, Quat *out, Quat *b);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *d);
extern const Vec3 data_02041dc8;
extern const Vec3 data_02042264;

void Ov259_HelperStartFlight(int *state, Vec3 *dir, int heading)
{
    Vec3 at;
    Quat yaw;
    Quat tilt;

    *(signed char *)(*state + 0x1c7) = 1;
    *(Vec3 *)(state + 6) = *dir;
    Vec3TransformViaTempMtx(&at, (void *)(*state + 0xa0), &data_02041dc8);
    at.x += 0x10e;
    state[10] = heading;
    QuatFromAxisAngle(&yaw, &data_02042264, heading);
    Quat_FromTwoVectors(&tilt, &data_02042264, (Vec3 *)(*state + 0x124));
    Quat_Multiply(&tilt, &tilt, &yaw);
    ScaleVec3Fx12(0x500, (Vec3 *)(state + 6), (Vec3 *)(state + 3));
}
