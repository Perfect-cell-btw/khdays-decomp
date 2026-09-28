

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

extern const u8 data_02041ae0[9][4];

/* getRotDataByIdx_ -- NitroSystem nsbca.c: getRotDataByIdx_. */
BOOL getRotDataByIdx_ (MtxFx33 * pRot, const void * pArrayRot3, const void * pArrayRot5, NNSG3dJntAnmRIdx info)
{
    if (info & NNS_G3D_JNTANM_RIDX_PIVOT) {
        const fx16 * data;
        fx32 A, B;
        u32 idxPivot;

        pRot->_00 = pRot->_01 = pRot->_02 =
        pRot->_10 = pRot->_11 = pRot->_12 =
        pRot->_20 = pRot->_21 = pRot->_22 = 0;

        data = (const fx16 *)pArrayRot3 + ((info & NNS_G3D_JNTANM_RIDX_IDXDATA_MASK) * 3);
        A = *(data + 1);
        B = *(data + 2);
        idxPivot = (u32)((*data & NNS_G3D_JNTANM_PIVOTINFO_IDXPIVOT_MASK) >>
                         NNS_G3D_JNTANM_PIVOT_INFO_IDXPIVOT_SHIFT);

        pRot->a[idxPivot] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_MINUS) ? -FX32_ONE : FX32_ONE;

        pRot->a[data_02041ae0[idxPivot][0]] = A;
        pRot->a[data_02041ae0[idxPivot][1]] = B;

        pRot->a[data_02041ae0[idxPivot][2]] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVC) ? -B : B;
        pRot->a[data_02041ae0[idxPivot][3]] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVD) ? -A : A;

        return FALSE;
    } else {
        const fx16 * data = (fx16 *)pArrayRot5 +
                            ((info & NNS_G3D_JNTANM_RIDX_IDXDATA_MASK) * 5);
        fx16 _12;

        _12 = (fx16)(data[4] & 7);
        pRot->_11 = (data[4] >> 3);

        _12 = (fx16)((_12 << 3) | (data[0] & 7));
        pRot->_00 = (data[0] >> 3);

        _12 = (fx16)((_12 << 3) | (data[1] & 7));
        pRot->_01 = (data[1] >> 3);

        _12 = (fx16)((_12 << 3) | (data[2] & 7));
        pRot->_02 = (data[2] >> 3);

        _12 = (fx16)((_12 << 3) | (data[3] & 7));
        pRot->_10 = (data[3] >> 3);

        pRot->_12 = ((fx16)(_12 << 3) >> 3);

        return TRUE;
    }
}
