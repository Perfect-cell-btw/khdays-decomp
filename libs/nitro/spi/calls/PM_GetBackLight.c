

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/mi.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

u32 PMi_ReadRegister(u16 registerAddr, u16 * buffer);
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
extern u32 PMi_ReadRegister (u16 registerAddr, u16 * buffer);

/* PM_GetBackLight -- NitroSDK pm.c: PM_GetBackLight. */
u32 PM_GetBackLight (PMBackLightSwitch * top, PMBackLightSwitch * bottom)
{
    u16 reg;
    u32 result;

    if ((result = PMi_ReadRegister(REG_PMIC_CTL_ADDR, &reg)) == PM_SUCCESS) {
        if (top) {
            *top = (reg & PMIC_CTL_BKLT2) ? PM_BACKLIGHT_ON : PM_BACKLIGHT_OFF;
        }
        if (bottom) {
            *bottom = (reg & PMIC_CTL_BKLT1) ? PM_BACKLIGHT_ON : PM_BACKLIGHT_OFF;
        }
    }

    return result;
}
