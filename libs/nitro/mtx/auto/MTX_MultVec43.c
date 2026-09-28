

#include "nitro/fx.h"

void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst)
{
    register fx32 x, y, z;

    x = vec->x;
    y = vec->y;
    z = vec->z;

    dst->x = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10 + (fx64)z * m->_20) >> 12);
    dst->x += m->_30;

    dst->y = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11 + (fx64)z * m->_21) >> 12);
    dst->y += m->_31;

    dst->z = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12 + (fx64)z * m->_22) >> 12);
    dst->z += m->_32;
}
