/* Resolves a reach sweep from a sweep record (reordering its fields). Returns what
 * Ov022_ResolveReachSweep returns. */

extern int Ov022_ResolveReachSweep(int arg0, void *arg1, int arg2);

typedef struct { int a; int b; int c; } Vec3w;

int func_ov022_020a1c28(int arg0, int *arg1, int arg2, int arg3) {
    struct { int w0; int w1; int w2; int w3; int w4; int w5; int w6; int w7; } buf;
    *(Vec3w *)&buf.w0 = *(Vec3w *)arg1;
    *(Vec3w *)&buf.w3 = *(Vec3w *)(arg1 + 5);
    buf.w6 = arg1[3];
    buf.w7 = arg1[4];
    return Ov022_ResolveReachSweep(arg0, &buf, arg2);
}
