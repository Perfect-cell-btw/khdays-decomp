/* Mount step: once both riders (+0x3b4 / +0x3b8) raise bit 1 of their +0x1ac flags the actor's
 * +0x3bd latch is set; the +0xc yaw steps towards the +0x10 target by the +0x14 rate and the
 * +0xa0 orientation is rebuilt about world Y; while the actor's +0x17a bit 1 is set 0.5 along the
 * direction from the +0x34 anchor towards the origin is added to the +0x18 velocity; the +0x54 timer counts the frame step down while positive; the
 * velocity is handed to the actor's +0xf0 motion slot and cleared. */
typedef struct { int x, y, z; } Vec3;
struct Bits17a { unsigned char b0 : 1, b1 : 1; };
extern int Angle_TurnToward(int cur, int want, int step, int *state);
extern void Srt_SetRotationAxisAngle(void *quat, const Vec3 *axis, int angle);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern const Vec3 data_02042264;
extern const Vec3 data_02041dc8;

void Ov236_MountStep(int *self) {
    int *ctx = (int *)self[1];
    Vec3 dir;
    {
        int actor = ctx[0];
        int b = *(unsigned short *)(*(int *)(actor + 0x3b8) + 0x100 + 0xac) & 2;
        int a = *(unsigned short *)(*(int *)(actor + 0x3b4) + 0x100 + 0xac) & 2;
        if (a != 0 && b != 0) {
            *(unsigned char *)(actor + 0x3bd) = 1;
        }
    }
    ctx[3] = Angle_TurnToward(ctx[3], ctx[4], ctx[5], 0);
    Srt_SetRotationAxisAngle((void *)(ctx[0] + 0xa0), &data_02042264, ctx[3]);
    if (((struct Bits17a *)(ctx[0] + 0x17a))->b1 != 0) {
        VEC_Subtract(&data_02041dc8, (Vec3 *)ctx[0xd], &dir);
        VEC_Normalize(&dir, &dir);
        ScaleVec3Fx12(0x800, &dir, &dir);
        VEC_Add((Vec3 *)(ctx + 6), &dir, (Vec3 *)(ctx + 6));
    }
    if (ctx[0x15] > 0) {
        ctx[0x15] -= *(int *)(self[0] + 0x2c);
    }
    {
        Vec3 *p18 = (Vec3 *)(ctx + 6);
        *(Vec3 *)(ctx[0] + 0xf0) = *p18;
        *p18 = data_02041dc8;
    }
}
