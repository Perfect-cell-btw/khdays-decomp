

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/fx_types.h"
#include "nitro/pxi.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"
#include "nnsys/g2d.h"

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
void NNS_G2dInitAnimCallBackFunctor(NNSG2dAnimCallBackFunctor * pCallBack);
extern void NNS_G2dInitAnimCallBackFunctor (NNSG2dCallBackFunctor * pCallBack);

/* NNS_G2dInitAnimCtrl -- NitroSystem g2d_Animation.c: NNS_G2dInitAnimCtrl. */
void NNS_G2dInitAnimCtrl (NNSG2dAnimController * pAnimCtrl)
{

    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->callbackFunctor);

    pAnimCtrl->pCurrent = NULL;
    pAnimCtrl->pActiveCurrent = NULL;

    pAnimCtrl->bReverse = FALSE;
    pAnimCtrl->bActive = TRUE;

    pAnimCtrl->currentTime = 0;
    pAnimCtrl->speed = FX32_ONE;

    pAnimCtrl->overriddenPlayMode = NNS_G2D_ANIMATIONPLAYMODE_INVALID;
    pAnimCtrl->pAnimSequence = NULL;
}
