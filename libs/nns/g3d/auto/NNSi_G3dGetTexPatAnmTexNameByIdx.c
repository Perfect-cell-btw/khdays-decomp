

/* NNSi_G3dGetTexPatAnmTexNameByIdx -- NitroSystem res_struct_accessor_anm.c: NNSi_G3dGetTexPatAnmTexNameByIdx. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

const NNSG3dResName * NNSi_G3dGetTexPatAnmTexNameByIdx (const NNSG3dResTexPatAnm * pPatAnm, u8 texIdx)
{

    if (pPatAnm && texIdx < pPatAnm->numTex) {
        const NNSG3dResName * pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsTexName);

        return &pNameArray[texIdx];
    }

    return NULL;
}
