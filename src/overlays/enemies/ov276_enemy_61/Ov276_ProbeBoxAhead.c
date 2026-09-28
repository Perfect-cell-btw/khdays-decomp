/* Ov276_ProbeBoxAhead: ported from a matched sibling family (same shape, constants and offsets adjusted). */
extern int Angle_TurnToward();
extern int QuatFromAxisAngle();
extern int Srt_SetRotationQuat();
extern int VEC_Add();
extern int ScaleVec3Fx12();
extern int VEC_Normalize();
extern int Vec3TransformViaTempMtx();
extern int Collision_CastSphereEx();
extern int ScaleVec3Fixed27();

typedef struct { int a, b, c; } Vec3;

extern Vec3 data_02042264;
extern Vec3 data_02041dc8;

typedef struct {
    char pad0[0x2c];
    int f2c;
} Field0;

typedef struct {
    Field0 *field0;
    void *f4;
    char pad8[0x74];
    int f7c;
} Node;

typedef struct {
    Node *n0;
    char pad4[8];
    Vec3 *fc;
    Vec3 v10;
    char pad1c[0xc];
    Vec3 v28;
    char pad34[0xc];
    int f40;
    int f44;
    char pad48[0xc];
    int f54;
} Inner;

typedef struct {
    Field0 *field0;
    Inner *inner;
} Obj;

typedef struct {
    char pad0[8];
    int f8;
    void *fc;
} Result;

void Ov276_ProbeBoxAhead(Obj *obj)
{
    Inner *inner = obj->inner;
    int local28[4];
    Vec3 local1c;
    char local10[0xc];
    int box[4];
    void *node4;
    Result *res;

    local1c = inner->v10;

    inner->f40 = Angle_TurnToward(inner->f40, inner->f44,
                               obj->field0->f2c * 0xbe / 100, 0);
    QuatFromAxisAngle(local28, &data_02042264, inner->f40);
    Srt_SetRotationQuat((char *)inner->n0 + 0xa0, local28);
    VEC_Add(&local1c, &inner->v28, &local1c);
    ScaleVec3Fx12(0xb00, &inner->v28, &inner->v28);

    if (VEC_Normalize(&inner->v28, local10) < 0x80) {
        inner->v28 = data_02041dc8;
    }

    node4 = inner->n0->f4;
    box[1] = 0;
    box[2] = 0x10cd;
    box[3] = 0x1c00 - 0x10cd;
    Vec3TransformViaTempMtx(&box[1], (char *)inner->n0 + 0xa0, &box[1]);
    VEC_Add(&box[1], inner->fc, &box[1]);
    box[0] = 0;
    res = (Result *)Collision_CastSphereEx(*(int *)((char *)node4 + 0x7c), &box[1], &local1c, 0x10cd);
    if (res != 0 && res->f8 == 0) {
        ScaleVec3Fixed27(res->fc, &local1c, &local1c);
    }

    *(Vec3 *)((char *)inner->n0 + 0xf0) = local1c;
    inner->v10 = data_02041dc8;

    inner->f54 = inner->f54 - obj->field0->f2c;
    if (inner->f54 <= 0) {
        inner->f54 = 0;
    }
}
