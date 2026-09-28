/* Charge release of the ov237 actor: the +0x1c clock runs up at the frame rate (wrapping past 0x2a8
 * with the +0x57 hit mask cleared). The data_ov237_020d1b70 direction and the data_ov237_020d1bd0
 * push are turned by the +0x10 heading; a 1.0 sphere 6.5 out along the direction from the +0x444
 * rig's +0x14 point, then a box 3.5 out oriented along the direction (half-extents 0.27 / 0.27 / 3.5),
 * hit once each (effect 1, kind 2) with that push (020cdbe4). */
#include "nitro/types.h"
typedef struct { int x, y, z; } Vec3;
typedef struct { int x, y, z, w; } Quat;
typedef struct { int m[9]; } Mtx33;
typedef struct { Vec3 pos; int radius; } Sphere;
typedef struct { Vec3 pos; Vec3 axis[3]; int ext[3]; } Box;

extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void MTX_RotY33_(Mtx33 *pMtx, int nSin, int nCos);
extern void MTX_MultVec33(const Vec3 *pIn, const Mtx33 *pMtx, Vec3 *pOut);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int Ov237_AttackHitTest(int *node, void *sphere, void *box, void *segment, Vec3 *push, int once, unsigned short effect, int kind);
extern void Quat_FromTwoVectors(Quat *out, const Vec3 *from, const Vec3 *to);
extern void Vec3TransformViaTempMtx(Vec3 *out, const Quat *q, const Vec3 *in);
extern const short data_0203d210[];
extern const Vec3 data_ov237_020d1b70;
extern const Vec3 data_ov237_020d1bd0;
extern const Vec3 data_02042258;
extern const Vec3 data_02042264;
extern const Vec3 data_02042270;

#define ANG2IDX(a) ((unsigned short)(((long long)(a) * 0x28be60db9391LL + 0x80000000000LL) >> 44) >> 4)

void Ov237_ChargeRelease(int *node)
{
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 push;
    Mtx33 rot;
    Sphere sphere;
    Box box;
    Vec3 reach;
    Vec3 ax;
    Vec3 ay;
    Vec3 az;
    Quat q;

    dir = data_ov237_020d1b70;
    push = data_ov237_020d1bd0;
    state[7] += *(int *)(node[0] + 0x2c);
    VEC_Normalize(&dir, &dir);
    if (state[7] >= 0x2a8) {
        state[7] = 0;
        *((u8 *)state + 0x57) = 0;
    }
    {
        int idx = ANG2IDX(state[4]) * 2;

        MTX_RotY33_(&rot, data_0203d210[idx], data_0203d210[idx + 1]);
    }
    MTX_MultVec33(&dir, &rot, &dir);
    MTX_MultVec33(&push, &rot, &push);
    VEC_Normalize(&dir, &dir);
    ScaleVec3Fx12(0x6800, &dir, &sphere.pos);
    VEC_Add(&sphere.pos, (Vec3 *)(*(int *)(*state + 0x444) + 0x14), &sphere.pos);
    sphere.radius = 0x1000;
    Ov237_AttackHitTest(node, &sphere, 0, 0, &push, 1, 1, 2);
    reach = dir;
    ScaleVec3Fx12(0x3800, &reach, &reach);
    VEC_Add((Vec3 *)(*(int *)(*state + 0x444) + 0x14), &reach, &box.pos);
    Quat_FromTwoVectors(&q, &data_02042258, &dir);
    Vec3TransformViaTempMtx(&ax, &q, &data_02042270);
    Vec3TransformViaTempMtx(&ay, &q, &data_02042264);
    Vec3TransformViaTempMtx(&az, &q, &data_02042258);
    box.axis[0] = ax;
    box.axis[1] = ay;
    box.axis[2] = az;
    box.ext[0] = 0x440;
    box.ext[1] = 0x440;
    box.ext[2] = 0x3800;
    Ov237_AttackHitTest(node, 0, &box, 0, &push, 1, 1, 2);
}
