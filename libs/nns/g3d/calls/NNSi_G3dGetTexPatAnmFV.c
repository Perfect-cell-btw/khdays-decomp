

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm * pPatAnm, u32 idx);
extern const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx (const NNSG3dResTexPatAnm * pPatAnm, u32 idx);

/* NNSi_G3dGetTexPatAnmFV -- NitroSystem res_struct_accessor_anm.c: NNSi_G3dGetTexPatAnmFV. */
const NNSG3dResTexPatAnmFV * NNSi_G3dGetTexPatAnmFV (const NNSG3dResTexPatAnm * pPatAnm, u32 idx, u32 frame)
{
    {
        const NNSG3dResDictTexPatAnmData * pAnmData =
            NNSi_G3dGetTexPatAnmDataByIdx(pPatAnm, idx);
        {

            const NNSG3dResTexPatAnmFV * pfvArray
                = (const NNSG3dResTexPatAnmFV *)((u8 *)pPatAnm + pAnmData->offset);

            const u32 fvIdx = (u32)((fx32)pAnmData->ratioDataFrame * frame >> FX32_SHIFT);

            {
                u32 realFvIdx = fvIdx;

                while (realFvIdx > 0 && pfvArray[ realFvIdx ].idxFrame >= frame) {
                    realFvIdx--;
                }

                while (realFvIdx + 1 < pAnmData->numFV && pfvArray[ realFvIdx + 1 ].idxFrame <= frame) {
                    realFvIdx++;
                }

                return &pfvArray[realFvIdx];
            }
        }
    }
}
