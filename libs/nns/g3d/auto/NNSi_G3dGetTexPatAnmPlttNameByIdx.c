

/* NNSi_G3dGetTexPatAnmPlttNameByIdx -- NitroSystem res_struct_accessor_anm.c: NNSi_G3dGetTexPatAnmPlttNameByIdx. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

const NNSG3dResName * NNSi_G3dGetTexPatAnmPlttNameByIdx (const NNSG3dResTexPatAnm * pPatAnm, u8 plttIdx)
{

    if (pPatAnm && plttIdx < pPatAnm->numPltt) {
        const NNSG3dResName * pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsPlttName);

        return &pNameArray[plttIdx];
    }

    return NULL;
}
