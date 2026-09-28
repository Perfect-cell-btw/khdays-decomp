

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/fx_types.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"
#include "nnsys/g3d.h"

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
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback * arg, u32 defaultGGID);

/* NNS_G3dRenderObjSetCallBack -- NitroSystem kernel.c: NNS_G3dRenderObjSetCallBack. */
void NNS_G3dRenderObjSetCallBack (NNSG3dRenderObj * pRenderObj, NNSG3dSbcCallBackFunc func, u8 *, u8 cmd, NNSG3dSbcCallBackTiming timing)
{

    pRenderObj->cbFunc = func;
    pRenderObj->cbCmd = cmd;
    pRenderObj->cbTiming = (u8)timing;
}
