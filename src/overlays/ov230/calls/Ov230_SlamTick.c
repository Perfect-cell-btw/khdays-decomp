/* Slam tick of the ov230 enemy (sibling of the ov249 one): the impulse at ctx+0x1c is copied out to
 * ctx+0x10 and grown in 0x88 steps of the elapsed time. The first time the owner sinks below five
 * times the +0x20 depth (+0x13c) the eight +0x3c0 shards burst out (+0x61): each is placed 1.5 to 5.0
 * out at an eighth of a turn apart around the +0xc point, at the height of the ground under the owner
 * (a 200.0 drop ray) and launched along data_02042240 (020d5c58). The owner's +0x494 contact sphere,
 * moved by the copied impulse, is swept with kind 2 (020d2af8). Once the owner lands (+0x17a bit 0)
 * the owner's +0x180 point is kept at ctx+0x34 lowered to the +0x80 floor less 0x200, effect 6 spawns
 * there, animation 0x19 plays, reaction 0x147 mode 0xc fires at it, the +0x4c timer restarts and the
 * tick hands over to 020d5794. */
typedef struct { int x, y, z; } Vec3;
typedef struct { Vec3 pos; int radius; } Sphere;
typedef struct { int m[9]; } Mtx33;
struct Bits17a { unsigned char b0 : 1; };
struct Shards { char pad[0x3c0]; int shards[8]; };

extern int FX_Div(int a, int b);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *out);
extern int Collision_CastRay(int collision, Vec3 *start, Vec3 *ray);
extern void ScaleVec3Fixed27(int scale, Vec3 *in, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void MTX_RotY33_(Mtx33 *pMtx, int nSin, int nCos);
extern int RandNextScaled(int bound);
extern void MTX_MultVec33(const Vec3 *pIn, const Mtx33 *pMtx, Vec3 *pOut);
extern void Ov230_SetTwoVecsAndFlag(int shard, Vec3 at, Vec3 dir);
extern void Ov230_ContactSweep(int *ctx, int kind, Sphere *sphere, void *box);
extern void func_ov107_020c0b90(int actor, int a, Vec3 v, int b);
extern void Ov107_PostTagUpdate(int owner, int mode, int arg);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int self, int action, void *cb);
extern void Ov230_AiExpandingSweepTick(void);
extern const Vec3 data_02042240;
extern const short data_0203d210[];

#define ANG2IDX(a) ((unsigned short)(((long long)(a) * 0x28be60db9391LL + 0x80000000000LL) >> 44) >> 4)

void Ov230_SlamTick(int self)
{
    int *ctx;
    Sphere sphere;
    Mtx33 mtx;
    Vec3 pos;
    Vec3 ray;
    Vec3 dir;
    int hit;
    int step;
    int i;
    int ground;
    int world;

    ctx = *(int **)(self + 4);
    *(Vec3 *)((char *)ctx + 0x10) = *(Vec3 *)((char *)ctx + 0x1c);

    step = *(int *)(*(int *)self + 0x2c);
    while (step > 0) {
        ScaleVec3Fx12((int)(((long long)FX_Div(step <= 0x88 ? step : 0x88, 0x88) * 0xabLL
                             + 0x800LL)
                            >> 12)
                          + 0x1000,
                      (Vec3 *)((char *)ctx + 0x1c), (Vec3 *)((char *)ctx + 0x1c));
        step -= 0x88;
    }

    if (*((unsigned char *)ctx + 0x61) == 0) {
        int owner = ctx[0];
        int depth = *(int *)(owner + 0x13c);

        if (depth < -ctx[8] * 5) {
            world = *(int *)(owner + 4);
            ground = *(int *)(owner + 0x78) - depth;
            pos = *(Vec3 *)(owner + 0x74);
            ray.x = 0;
            ray.y = -0xc8000;
            ray.z = 0;
            hit = Collision_CastRay(*(int *)(world + 0x7c), &pos, &ray);
            if (hit != 0) {
                ScaleVec3Fixed27(*(int *)(hit + 0xc), &ray, &ray);
                VEC_Add(&ray, &pos, &pos);
                ground = pos.y;
            }
            dir = data_02042240;
            for (i = 0; i < 8; i++) {
                int idx = ANG2IDX(i * 0x6488 / 8);

                MTX_RotY33_(&mtx, data_0203d210[idx * 2], data_0203d210[idx * 2 + 1]);
                pos.z = RandNextScaled(0x3800) + 0x1800;
                pos.x = 0;
                pos.y = 0;
                MTX_MultVec33(&pos, &mtx, &pos);
                VEC_Add(&pos, (Vec3 *)ctx[3], &pos);
                pos.y = ground;
                Ov230_SetTwoVecsAndFlag(((struct Shards *)ctx[0])->shards[i], pos, dir);
            }
            *((unsigned char *)ctx + 0x61) = 1;
        }
    }

    sphere = *(Sphere *)(ctx[0] + 0x494);
    VEC_Add(&sphere.pos, (Vec3 *)((char *)ctx + 0x10), &sphere.pos);
    Ov230_ContactSweep(ctx, 2, &sphere, 0);
    if (((struct Bits17a *)(ctx[0] + 0x17a))->b0 == 0) {
        return;
    }
    *(Vec3 *)((char *)ctx + 0x34) = *(Vec3 *)(ctx[0] + 0x180);
    ctx[0xe] -= *(int *)(ctx[0] + 0x80) - 0x200;
    func_ov107_020c0b90(ctx[0], 6, *(Vec3 *)((char *)ctx + 0x34), 0);
    Ov107_PostTagUpdate(ctx[0], 0x19, 0);
    Ov107_BuildAndSendUpdate(ctx[0], 0x147, 0xc, (char *)ctx + 0x34);
    ctx[0x13] = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), Ov230_AiExpandingSweepTick);
}
