/* Orientation tick of the ov239 enemy: the +0xc yaw turns toward the +0x10 target yaw by three
 * frame-times, the actor's +0xa0 transform takes the yaw as a quaternion about the up axis
 * composed with the +0x124 rig rotation, and the +0x14 velocity moves to the actor's +0xf0 and
 * is zeroed. */
typedef struct { int v[4]; } Xform;
typedef struct { int x, y, z; } Vec3;

extern int Angle_TurnToward(int cur, int target, int step, int *out);
extern void QuatFromAxisAngle(Xform *out, const Vec3 *axis, int angle);
extern void Quat_FromTwoVectors(Xform *out, const Vec3 *axis, void *rig);
extern void Quat_Multiply(Xform *out, const Xform *a, const Xform *b);
extern void Srt_SetRotationQuat(void *srt, const Xform *x);
extern const Vec3 data_02042264;
extern const Vec3 data_02041dc8;

void Ov239_OrientationTick(int *node)
{
    int *state = (int *)node[1];
    Xform a;
    Xform b;
    Vec3 *vel;

    state[3] = Angle_TurnToward(state[3], state[4], *(int *)(*node + 0x2c) * 0x1e / 10, 0);
    QuatFromAxisAngle(&a, &data_02042264, state[3]);
    Quat_FromTwoVectors(&b, &data_02042264, (void *)(*state + 0x124));
    Quat_Multiply(&b, &b, &a);
    Srt_SetRotationQuat((void *)(*state + 0xa0), &b);
    vel = (Vec3 *)(state + 5);
    *(Vec3 *)(*state + 0xf0) = *vel;
    *vel = data_02041dc8;
}
