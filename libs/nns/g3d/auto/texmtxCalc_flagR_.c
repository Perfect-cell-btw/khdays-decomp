

/* texmtxCalc_flagR_ -- NitroSystem maya.c: texmtxCalc_flagR_. */

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void texmtxCalc_flagR_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = -(fx32)((fx64)anm->scaleS * anm->transS >> (FX32_SHIFT - 4)) * anm->origWidth;
    m->_31 = ((-anm->scaleT - anm->scaleT + FX32_ONE * 2) * anm->origHeight << 3) +
             (fx32)((fx64)anm->scaleT * anm->transT >> (FX32_SHIFT - 4)) * anm->origHeight;

    m->_10 = 0;
}
