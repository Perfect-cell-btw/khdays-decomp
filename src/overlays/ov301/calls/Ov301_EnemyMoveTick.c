/* ov301 enemy physics/movement tick (484B). Advances a spawn cursor (x/10 rate),
 * samples a curve, optionally mirrors the velocity vector, applies Q12 fixed-point
 * damping to vx/vz and a clamped ramp to vy, then flags the actor and commits. */
extern int  Angle_TurnToward(int a, int b, int c, int *d);
extern void QuatFromAxisAngle(int *out, int *tbl, int t);
extern void Srt_SetRotationQuat(unsigned int *a, int *b);
extern void ScaleVec3Fx12(int scale, int *src, unsigned int *dst);   /* ScaleVec3Fx12 */
extern void Ov107_MoveNodeAndRelayout(int a, void *desc);
extern int data_02042264[];

struct blk3 { int x, y, z; };
struct wd { unsigned b : 8, rest : 24; };

void Ov301_EnemyMoveTick(int *param_1) {
    int iVar7 = *(int *)(*param_1 + 0x2c) * 0x5a;
    int q = iVar7 / 10;
    int *piVar6 = (int *)param_1[1];
    unsigned short uVar1;
    unsigned int t;
    int v[4];
    int desc[3];

    desc[0] = 0x0f2f;
    desc[1] = 0;
    desc[2] = 0xeea3;

    if (piVar6[0x10] == 0)
        piVar6[9] = Angle_TurnToward(piVar6[9], piVar6[10], q, 0);
    else
        piVar6[9] = piVar6[10];

    QuatFromAxisAngle(v, data_02042264, piVar6[9]);
    Srt_SetRotationQuat((unsigned int *)(*piVar6 + 0xa0), v);

    if (((unsigned)*(unsigned char *)(*piVar6 + 0x17a) << 0x1e) >> 0x1f) {
        int m = -1;
        piVar6[3] = piVar6[3] * m;
        piVar6[5] = piVar6[5] * m;
        ScaleVec3Fx12(0x1500, piVar6 + 3, (unsigned int *)(piVar6 + 3));
    }

    *(struct blk3 *)(*piVar6 + 0xf0) = *(struct blk3 *)(piVar6 + 3);

    piVar6[3] = (int)(((long long)piVar6[3] * 0xd00 + 0x800) >> 12);
    piVar6[5] = (int)(((long long)piVar6[5] * 0xd00 + 0x800) >> 12);
    if (piVar6[4] > 0x30) {
        piVar6[4] = (int)(((long long)piVar6[4] * 0xe00 + 0x800) >> 12);
    } else {
        if (piVar6[4] > -0x380)
            piVar6[4] -= 0x34;
    }

    uVar1 = *(unsigned short *)(*piVar6 + 0x60);
    t = ((unsigned)uVar1 << 16) >> 24;
    t |= 4;
    *(unsigned short *)(*piVar6 + 0x60) =
        (*(unsigned short *)(*piVar6 + 0x60) & ~0xff00) | ((t << 24) >> 16);
    ((struct wd *)(*(int *)(*piVar6 + 0x388) + 8))->b |= 2;

    Ov107_MoveNodeAndRelayout(*piVar6, desc);
}
