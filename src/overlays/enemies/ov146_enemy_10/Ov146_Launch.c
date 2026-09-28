/* Launch the ov146 actor along `dir`: the +0xc velocity is its unit vector at 0.5 with a 0.625 lift,
 * +0x1c clears and the next move is 1. */
typedef struct { int x, y, z; } Vec3;

extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);

void Ov146_Launch(int *state, Vec3 dir)
{
    VEC_Normalize(&dir, (Vec3 *)(state + 3));
    ScaleVec3Fx12(0x800, (Vec3 *)(state + 3), (Vec3 *)(state + 3));
    state[4] = 0xa00;
    state[7] = 0;
    *(unsigned char *)(*state + 0x1c7) = 1;
}
