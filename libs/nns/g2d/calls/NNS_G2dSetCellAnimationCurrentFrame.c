

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/fx_types.h"
#include "nitro/pxi.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"
#include "nnsys/gfd.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef enum WVRResult {
    WVR_RESULT_SUCCESS = 0,
    WVR_RESULT_OPERATING,
    WVR_RESULT_DISABLE,
    WVR_RESULT_INVALID_PARAM,
    WVR_RESULT_FIFO_ERROR,
    WVR_RESULT_ILLEGAL_STATUS,
    WVR_RESULT_VRAM_LOCKED,
    WVR_RESULT_FATAL_ERROR,
    WVR_RESULT_MAX
} WVRResult;
typedef void (*WVRCallbackFunc) (void * arg, WVRResult result);
typedef void (*MBFakeScanCallbackFunc) (u16 type, void * arg);
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback * arg, u32 defaultGGID);
BOOL NNS_G2dSetAnimCtrlCurrentFrame(NNSG2dAnimController * pAnimCtrl, u16 index);
typedef BOOL (*VramTransferTaskRegisterFuncPtr)(NNS_GFD_DST_TYPE type, u32 dstAddr, void * pSrc, u32 szByte);
extern void func_02012354 (NNSG2dCellAnimation * pCellAnim);

/* NNS_G2dSetCellAnimationCurrentFrame -- NitroSystem g2d_CellAnimation.c: NNS_G2dSetCellAnimationCurrentFrame. */
void NNS_G2dSetCellAnimationCurrentFrame (NNSG2dCellAnimation * pCellAnim, u16 frameIndex)
{

    if ( NNS_G2dSetAnimCtrlCurrentFrame(&pCellAnim->animCtrl, frameIndex)) {
        func_02012354(pCellAnim);
    }
}
