/* Facing step of an ov256 part: in move 1 the +0xa0 pose follows the +0x18 heading; +0xf0 keeps the
 * last +0xc velocity, which then clears. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int x, y, z, w; } Quat;

extern void QuatFromAxisAngle(Quat *out, const Vec3 *axis, int angle);
extern void Srt_SetRotationQuat(char *srt, Quat *q);
extern const Vec3 data_02042264;
extern const Vec3 data_02041dc8;

void Ov256_FacingStep(int *node)
{
    int *state = (int *)node[1];
    Quat q;

    if (*(signed char *)(*state + 0x1c6) == 1) {
        QuatFromAxisAngle(&q, &data_02042264, state[6]);
        Srt_SetRotationQuat((char *)(*state + 0xa0), &q);
    }
    {
        Vec3 *vel = (Vec3 *)(state + 3);

        *(Vec3 *)(*state + 0xf0) = *vel;
        *vel = data_02041dc8;
    }
}
