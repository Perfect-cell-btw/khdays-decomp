/* Ov203_MotionTick: motion tick of the ov202 enemy (x2), variant of the matched ov163 sibling: the +0xc angle only advances while the actor's +0x1c4 bit 1 is clear. */

#include "game/actor.h"

extern int Angle_TurnToward();
extern int QuatFromAxisAngle();
extern int Quat_FromTwoVectors();
extern int Quat_Multiply();
extern int Srt_SetRotationQuat();
extern int INITi_CpuClear32_0x01ff86fc();

typedef struct { int a, b, c; } Vec3;

extern Vec3 data_02042264;

typedef struct {
    char pad0[0x2c];
    int f2c;
} Field0;

typedef struct {
    Actor *n0;
    char pad4[4];
    int fc;
    int f10;
    int f14;
    Vec3 v18;
    char pad24[0x10];
    int f34;
} Inner;

typedef struct {
    Field0 *field0;
    Inner *inner;
} Obj;

void Ov203_MotionTick(Obj *obj)
{
    Inner *inner = obj->inner;
    int v;
    char localB[0x10];
    char localA[0x10];

    if ((inner->n0->flags1c4 & 2) == 0) {
        inner->fc = Angle_TurnToward(inner->fc, inner->f10, inner->f14, 0);
    }

    if (!((unsigned)(inner->n0->flags60.raw << 24) >> 24 & 0x40) && ((unsigned)(inner->n0->contact17a.raw << 31) >> 31)) {
        QuatFromAxisAngle(localB, &data_02042264, inner->fc);
        Quat_FromTwoVectors(localA, &data_02042264, (char *)inner->n0 + 0x124);
        Quat_Multiply(localA, localA, localB);
        Srt_SetRotationQuat((char *)inner->n0 + 0xa0, localA);
    }

    v = inner->f34;
    if (v > 0) {
        inner->f34 = v - obj->field0->f2c;
    }

    *(Vec3 *)((char *)inner->n0 + 0xf0) = inner->v18;
    INITi_CpuClear32_0x01ff86fc(0, &inner->v18, 0xc);
}
