

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
BOOL func_02011c88(NNSG2dAnimController * pAnimCtrl, fx32 frames);
static inline const NNSG2dAnimFrame * GetFrameEnd_ (const NNSG2dAnimSequence * pSequence)
{
    return pSequence->pAnmFrameArray + (pSequence->numFrames);
}
static inline const NNSG2dAnimFrame * GetFrameLoopBegin_ (const NNSG2dAnimSequence * pSequence)
{
    return pSequence->pAnmFrameArray + pSequence->loopStartFrameIdx;
}
static inline BOOL IsAnimCtrlMovingForward_ (const NNSG2dAnimController * pAnimCtrl)
{
    return (pAnimCtrl->speed > 0) ^ (pAnimCtrl->bReverse) ? 1 : 0 ;
}
extern BOOL func_02011c88 (NNSG2dAnimController * pAnimCtrl, fx32 frames);

/* NNS_G2dResetAnimCtrlState -- NitroSystem g2d_Animation.c: NNS_G2dResetAnimCtrlState. */
void NNS_G2dResetAnimCtrlState (NNSG2dAnimController * pAnimCtrl)
{

    if ( IsAnimCtrlMovingForward_(pAnimCtrl)) {
        pAnimCtrl->pCurrent = GetFrameLoopBegin_(pAnimCtrl->pAnimSequence);
    } else {
        pAnimCtrl->pCurrent = GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1;
    }

    pAnimCtrl->pActiveCurrent = pAnimCtrl->pCurrent;
    pAnimCtrl->currentTime = 0;

    (void)func_02011c88(pAnimCtrl, 0);
}
