

/* texmtxCalc_flagTR_ -- NitroSystem maya.c: texmtxCalc_flagTR_. */

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void texmtxCalc_flagTR_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = 0;
    m->_31 = ((-2 * anm->scaleT + FX32_ONE * 2) * anm->origHeight << 3);

    m->_10 = 0;
}
