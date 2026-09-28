

/* texmtxCalc_flagTR__2 -- NitroSystem 3dsmax.c: texmtxCalc_flagTR_. */

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void texmtxCalc_flagTR__2 (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = ((-anm->scaleS + FX32_ONE) * anm->origWidth) << 3;
    m->_31 = ((-anm->scaleT + FX32_ONE) * anm->origHeight) << 3;

    m->_10 = 0;
}
