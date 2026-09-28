/* d1400 */
#include "nitro/types.h"
typedef struct { int x, y, z; } Vec3;
typedef struct { Vec3 p0; Vec3 dir; int nLength; int nRadius; } Segment;

extern int Ov107_CollectSegmentOverlaps(int owner, Segment *seg, int *hits);
extern void VEC_Subtract(const void *a, const void *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern int Ov107_InvokeHitCallback(int hit, int owner, int item, int kind, Vec3 *push, int z);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);

int Ov256_AttackHitTestB(int *node, int bMask, u16 kind)
{
    int *state = (int *)node[1];
    Segment seg;
    int hits[4];
    Vec3 push;
    long n;
    long i;

    seg = *(Segment *)(**(int **)(*state + 0x388) + 0x78);
    seg.nRadius += 0x1000;
    n = Ov107_CollectSegmentOverlaps(*(int *)(*state + 0x3ac), &seg, hits);
    for (i = 0; i < n; i++) {
        u8 bit = 1 << *(u16 *)(hits[i] + 2);

        if (bMask != 0 && (*((u8 *)state + 0x6c) & bit) != 0) {
            continue;
        }
        VEC_Subtract((void *)(hits[i] + 0x74), (void *)(*state + 0x74), &push);
        VEC_Normalize(&push, &push);
        if (Ov107_InvokeHitCallback(hits[i], *state, *(int *)(*state + 0x3ac), kind, &push, 0) == 0) {
            continue;
        }
        func_ov107_020c0b90(*(int *)(*state + 0x3ac), 0, *(Vec3 *)(hits[i] + 0x190), 0);
        *((u8 *)state + 0x6c) |= bit;
    }
    if (bMask != 0) {
        return *((u8 *)state + 0x6c) != 0;
    }
    return n != 0;
}
