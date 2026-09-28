

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
inline void * NNS_G3dGetResDataByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;
    if (dict != NULL && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)(&hdr->data[0] + hdr->sizeUnit * idx);
    } else {
        return NULL ;
    }
}
extern fx32 GetTexSRTAnmVectorVal_ (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame);
extern u32 GetTexSRTAnmSinCosVal_ (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame);

/* GetTexSRTAnm_ -- NitroSystem nsbta.c: GetTexSRTAnm_. */
void GetTexSRTAnm_ (const NNSG3dResTexSRTAnm * pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult * pResult)
{

    {
        const NNSG3dResDictTexSRTAnmData * pAnmData =
            (const NNSG3dResDictTexSRTAnmData *)NNS_G3dGetResDataByIdx(&pTexAnm->dict, idx);
        NNSG3dMatAnmResultFlag flag = pResult->flag;

        {
            fx32 transS, transT;

            transS = GetTexSRTAnmVectorVal_(pTexAnm,
                                            pAnmData->transS,
                                            pAnmData->transSEx,
                                            frame);
            transT = GetTexSRTAnmVectorVal_(pTexAnm,
                                            pAnmData->transT,
                                            pAnmData->transTEx,
                                            frame);

            if (transS == 0 && transT == 0) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
                pResult->transS = transS;
                pResult->transT = transT;
            }
        }

        {

            u32 data = GetTexSRTAnmSinCosVal_(pTexAnm,
                                              pAnmData->rot,
                                              pAnmData->rotEx,
                                              frame);

            if (data == ((FX32_ONE << 16) | 0)) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            } else {
                pResult->sinR = (fx16)(data & 0x0000FFFF);
                pResult->cosR = (fx16)(data >> 16);
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            }
        }

        {
            fx32 scaleS, scaleT;

            scaleS = GetTexSRTAnmVectorVal_(pTexAnm,
                                            pAnmData->scaleS,
                                            pAnmData->scaleSEx,
                                            frame);
            scaleT = GetTexSRTAnmVectorVal_(pTexAnm,
                                            pAnmData->scaleT,
                                            pAnmData->scaleTEx,
                                            frame);

            if (scaleS == FX32_ONE && scaleT == FX32_ONE) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
                pResult->scaleS = scaleS;
                pResult->scaleT = scaleT;
            }
        }

        pResult->flag = flag;
    }
}
