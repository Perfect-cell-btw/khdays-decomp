extern void *EntityMgr_RunRayCast(int a, void *b, void *c, int d);
extern void Vec3ScaleAddQ27(int a, void *b, void *c, void *d);
extern int data_ov049_020b4d00;

typedef struct { int x, y, z; } Vec3;

void Ov049_ResolveHitPositionRaised(Vec3 *src, int *out) {
    Vec3 a;
    int q[3];
    void *r;
    int *ctx;
    a = *src;
    *(Vec3 *)out = a;
    a.y += 0x25000;
    q[0] = 0;
    q[1] = -0x4a000;
    q[2] = 0;
    ctx = *(int **)&data_ov049_020b4d00;
    r = EntityMgr_RunRayCast(*(unsigned short *)((char *)ctx + 0x66), &a, q, ctx[8]);
    if (r == 0) {
        out[1] -= 0x25000;
        return;
    }
    Vec3ScaleAddQ27(*(int *)((char *)r + 0xc), q, &a, out);
    out[1] += 0x333;
}
