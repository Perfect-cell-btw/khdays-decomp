

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"

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
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback * arg, u32 defaultGGID);
void PMi_DeleteList(PMSleepCallbackInfo ** listp, PMSleepCallbackInfo * info);
extern PMSleepCallbackInfo * data_020463e4;
extern void PMi_DeleteList (PMSleepCallbackInfo ** listp, PMSleepCallbackInfo * info);

/* PM_DeletePostSleepCallback -- NitroSDK pm.c: PM_DeletePostSleepCallback. */
void PM_DeletePostSleepCallback (PMSleepCallbackInfo * info)
{
    PMi_DeleteList(&data_020463e4, info);
}
