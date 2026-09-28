extern void *EntityMgr_RunCastSimple(int a, void *b, void *c, int d);
extern void Vec3ScaleAddQ27(int a, void *b, void *c, void *d);
extern int data_ov083_020b9b00;

typedef struct { int x, y, z; } Vec3;

void Ov083_ResolveHitPositionOrFallback(Vec3 *src, int *out) {
    Vec3 a;
    int q[3];
    void *r;
    int *ctx;
    a = *src;
    *(Vec3 *)out = a;
    q[0] = 0;
    q[1] = 0x5ccd;
    q[2] = 0;
    ctx = *(int **)&data_ov083_020b9b00;
    r = EntityMgr_RunCastSimple(*(unsigned short *)((char *)ctx + 0x66), &a, q, ctx[8]);
    if (r == 0) {
        out[1] += 0x5000;
        return;
    }
    Vec3ScaleAddQ27(*(int *)((char *)r + 0xc), q, &a, out);
    out[1] -= 0xe67;
}
