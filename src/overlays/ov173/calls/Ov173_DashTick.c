/* Dash tick of the ov173 enemy (x2: ov173/174). Once the +0x48 timer passes 0x600 and a target is
 * held (+0x10): aims at the target (flat direction, scaled to both radii plus 0x1000), rotates the
 * aim around Y by a random angle in [-0xc91, 0xc91], adds the raw offset, caps the resulting
 * +0x20 velocity at 0x7800, clips it against the world (+0x7c) with a sphere cast of the actor's
 * radius and a ray cast (each hit scales the velocity by the hit's +0xc fraction), drops the
 * target and advances to Ov173_EndDash. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int m[9]; } Mtx33;

struct CastHit {
    char pad00[0xc];
    int nFraction;
};

extern int RandNextScaled(int bound);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void MTX_RotY33_(Mtx33 *m, int sin, int cos);
extern void MTX_MultVec33(const Vec3 *v, const Mtx33 *m, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern struct CastHit *Collision_CastSphere(void *world, const Vec3 *from, const Vec3 *step, int radius);
extern struct CastHit *Collision_CastRayEx(void *world, const Vec3 *from, const Vec3 *step, void *filter);
extern void ScaleVec3Fixed27(int scale, const Vec3 *v, Vec3 *out);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const short data_0203d210[];
extern void Ov173_EndDash(void);

void Ov173_DashTick(int *node)
{
    int *state = (int *)node[1];
    Mtx33 rot;
    Vec3 aim;
    Vec3 dir;
    int angle;
    int idx;
    int scene;
    struct CastHit *hit;

    state[0x12] += *(int *)(*node + 0x2c);
    if (state[0x12] < 0x600) {
        return;
    }
    if (state[4] != 0) {
        angle = RandNextScaled(0x1923) - 0xc91;
        scene = *(int *)(*state + 4);
        VEC_Subtract((Vec3 *)(state[4] + 0x74), (Vec3 *)(*state + 0x74), &dir);
        dir.y = 0;
        VEC_Normalize(&dir, &aim);
        ScaleVec3Fx12(*(int *)(state[4] + 0x80) + *(int *)(*state + 0x80) + 0x1000, &aim, &aim);
        idx = (unsigned short)((0x28BE60DB9391LL * angle + 0x80000000000LL) >> 44);   /* FX_RAD_TO_IDX */
        MTX_RotY33_(&rot, data_0203d210[(idx >> 4) << 1], data_0203d210[((idx >> 4) << 1) + 1]);
        MTX_MultVec33(&aim, &rot, (Vec3 *)(state + 8));
        VEC_Add((Vec3 *)(state + 8), &dir, (Vec3 *)(state + 8));
        if (VEC_Normalize((Vec3 *)(state + 8), &aim) > 0x7800) {
            ScaleVec3Fx12(0x7800, &aim, (Vec3 *)(state + 8));
        }
        hit = Collision_CastSphere(*(void **)(scene + 0x7c), (Vec3 *)state[2], (Vec3 *)(state + 8), *(int *)(*state + 0x80));
        if (hit != 0) {
            ScaleVec3Fixed27(hit->nFraction, (Vec3 *)(state + 8), (Vec3 *)(state + 8));
        }
        hit = Collision_CastRayEx(*(void **)(scene + 0x7c), (Vec3 *)state[2], (Vec3 *)(state + 8), 0);
        if (hit != 0) {
            ScaleVec3Fixed27(hit->nFraction, (Vec3 *)(state + 8), (Vec3 *)(state + 8));
        }
        state[4] = 0;
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov173_EndDash);
}
