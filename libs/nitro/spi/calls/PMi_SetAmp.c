

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/mi.h"
#include "nitro/pxi.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/snd.h"
#include "nitro/wm.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

PMLCDPower PM_GetLCDPower(void);
u32 PMi_WriteRegister(u16 registerAddr, u16 data);
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
typedef void (*MBCommPStateCallback) (u16 child_aid, u32 status, void * arg);
typedef void (*MBCommCStateCallbackFunc) (u32 status, void * arg);
typedef void (*MBFakeScanCallbackFunc) (u16 type, void * arg);
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback * arg, u32 defaultGGID);
extern u32 PMi_WriteRegister (u16 registerAddr, u16 data);
extern PMLCDPower PM_GetLCDPower (void);

/* PMi_SetAmp -- NitroSDK pm.c: PMi_SetAmp. */
u32 PMi_SetAmp (PMAmpSwitch status)
{
    if (PM_GetLCDPower()) {
        return PMi_WriteRegister(REG_PMIC_OP_CTL_ADDR, (u16)status);
    } else {
        return PM_RESULT_SUCCESS;
    }
}
