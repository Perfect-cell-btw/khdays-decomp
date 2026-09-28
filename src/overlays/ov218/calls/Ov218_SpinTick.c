/* Spin tick of the ov218 actor: the +0xc heading turns toward the +0x10 goal at four times the frame
 * rate (0203d040); the actor's pose becomes the rotation from up to its +0x124 normal combined with the
 * heading about up, its +0xf0 velocity mirrors +0x28, and for the frame (in 0x88-sized slices) the
 * velocity damps by 0.12 and the +0x1c spin by 0.125 per slice. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int x, y, z, w; } Quat;

extern int Angle_TurnToward(int a, int b, int c, int d);
extern void QuatFromAxisAngle(Quat *out, const Vec3 *axis, int angle);
extern void Quat_FromTwoVectors(Quat *out, const Vec3 *from, const Vec3 *to);
extern void Quat_Multiply(Quat *out, const Quat *a, const Quat *b);
extern void Srt_SetRotationQuat(void *srt, const Quat *rot);
extern int FX_Div(int num, int den);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern const Vec3 data_02042264;

#define FX_MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

void Ov218_SpinTick(int *node)
{
    int *state = (int *)node[1];
    Quat spin;
    Quat tilt;
    int remaining;

    state[3] = Angle_TurnToward(state[3], state[4], *(int *)(node[0] + 0x2c) * 4, 0);
    QuatFromAxisAngle(&spin, &data_02042264, state[3]);
    Quat_FromTwoVectors(&tilt, &data_02042264, (Vec3 *)(*state + 0x124));
    Quat_Multiply(&tilt, &tilt, &spin);
    Srt_SetRotationQuat((void *)(*state + 0xa0), &tilt);
    *(Vec3 *)(*state + 0xf0) = *(Vec3 *)(state + 0xa);
    for (remaining = *(int *)(node[0] + 0x2c); remaining > 0; remaining -= 0x88) {
        ScaleVec3Fx12(0x1000 - FX_MUL(FX_Div(remaining <= 0x88 ? remaining : 0x88, 0x88), 0x1f0),
                      (Vec3 *)(state + 0xa), (Vec3 *)(state + 0xa));
        state[7] = FX_MUL(state[7], 0x1000 - FX_MUL(FX_Div(remaining <= 0x88 ? remaining : 0x88, 0x88), 0x200));
    }
}
