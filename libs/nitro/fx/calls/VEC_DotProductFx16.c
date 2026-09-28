
#include "nitro/fx.h"

typedef struct { fx16 x, y, z; } VecFx16;

fx32 VEC_DotProductFx16(const VecFx32 *v, const VecFx16 *m)
{
    long long s = (long long)v->x * m->x
                + (long long)v->y * m->y
                + (long long)v->z * m->z;
    return (fx32)((s + 0x800) >> 12);
}
