

/* texmtxCalc_flagRS_ -- NitroSystem maya.c: texmtxCalc_flagRS_. */

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void texmtxCalc_flagRS_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = FX32_ONE;
    m->_11 = FX32_ONE;

    m->_01 = 0;

    m->_30 = -(anm->transS * anm->origWidth) << 4;
    m->_31 = (anm->transT * anm->origHeight) << 4;

    m->_10 = 0;
}
