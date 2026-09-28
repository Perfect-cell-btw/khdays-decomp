

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void INITi_CpuClear32_0x01ff86fc(u32 data, void * destp, u32 size);
static inline void MI_CpuFill32 (void * dest, u32 data, u32 size)
{
    INITi_CpuClear32_0x01ff86fc(data, dest, size);
}
static inline void MI_CpuClear32 (void * dest, u32 size)
{
    MI_CpuFill32(dest, 0, size);
}
extern NNSG3dFuncAnmBlendMat data_020424b0;
extern NNSG3dFuncAnmBlendJnt data_020424ac;
extern NNSG3dFuncAnmBlendVis data_020424a8;

/* NNS_G3dRenderObjInit -- NitroSystem kernel.c: NNS_G3dRenderObjInit. */
void NNS_G3dRenderObjInit (NNSG3dRenderObj * pRenderObj, NNSG3dResMdl * pResMdl)
{

    MI_CpuClear32(pRenderObj, sizeof(NNSG3dRenderObj));

    pRenderObj->funcBlendMat = data_020424b0;
    pRenderObj->funcBlendJnt = data_020424ac;
    pRenderObj->funcBlendVis = data_020424a8;

    pRenderObj->resMdl = pResMdl;
}
