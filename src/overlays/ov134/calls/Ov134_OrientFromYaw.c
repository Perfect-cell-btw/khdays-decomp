/* Ov134_OrientFromYaw: ported from a matched sibling family (same shape, constants and offsets adjusted). */
extern int Angle_TurnToward();
extern int QuatFromAxisAngle();
extern int Quat_FromTwoVectors();
extern int Quat_Multiply();
extern int Srt_SetRotationQuat();

typedef struct { int a, b, c; } Vec3;

extern Vec3 data_02042264;
extern Vec3 data_02041dc8;

typedef struct {
    char *n0;
    char pad4[4];
    int f8;
    int fc;
    int f10;
    int f14;
    Vec3 v18;
} Inner;

typedef struct {
    char pad0[4];
    Inner *inner;
} Obj;

void Ov134_OrientFromYaw(Obj *obj)
{
    Inner *inner = obj->inner;
    char localB[0x10];
    char localA[0x10];

    inner->fc = Angle_TurnToward(inner->fc, inner->f10, inner->f14, 0);

    QuatFromAxisAngle(localB, &data_02042264, inner->fc);
    Quat_FromTwoVectors(localA, &data_02042264, inner->n0 + 0x124);
    Quat_Multiply(localA, localA, localB);
    Srt_SetRotationQuat(inner->n0 + 0xa0, localA);

    *(Vec3 *)(inner->n0 + 0xf0) = inner->v18;
    inner->v18 = data_02041dc8;
}
