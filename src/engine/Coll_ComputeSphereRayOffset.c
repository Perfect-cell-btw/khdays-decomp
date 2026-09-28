/* Ray-sphere intersection: from the ray origin and direction and the sphere centre and radius,
 * computes the offset along the direction to the far intersection; returns 0 when the ray misses.
 */

typedef int fx32;
typedef struct { fx32 x, y, z; } Vec;

extern void VEC_Subtract(const Vec *a, const Vec *b, Vec *dst);
extern fx32 VEC_DotProduct(const Vec *a, const Vec *b);
extern fx32 FX_Sqrt(fx32 x);
extern void ScaleVec3Fx12(fx32 a, const Vec *b, void *c);

#define FX_MUL(a, b) ((fx32)(((long long)(a) * (long long)(b) + 0x800) >> 12))

int Coll_ComputeSphereRayOffset(const Vec *a, const Vec *b, const Vec *c, fx32 d, void *e)
{
    Vec diff;
    fx32 dot;
    fx32 disc;

    VEC_Subtract(a, c, &diff);
    dot = VEC_DotProduct(&diff, b);
    disc = FX_MUL(d, d) + (FX_MUL(dot, dot) - VEC_DotProduct(&diff, &diff));
    if (disc < 0) return 0;
    ScaleVec3Fx12(FX_Sqrt(disc) - dot, b, e);
    return 1;
}
