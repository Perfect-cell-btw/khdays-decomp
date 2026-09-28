

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/spi.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

BOOL PMi_SetLCDPower(PMLCDPower sw, PMLEDStatus led, BOOL skip, BOOL isSync);
extern BOOL PMi_SetLCDPower (PMLCDPower sw, PMLEDStatus led, BOOL skip, BOOL isSync);

/* PM_SetLCDPower -- NitroSDK pm.c: PM_SetLCDPower. */
BOOL PM_SetLCDPower (PMLCDPower sw)
{
    if (sw != PM_LCD_POWER_ON) {
        sw = PM_LCD_POWER_OFF;
    }

    return PMi_SetLCDPower(sw, PM_LED_NONE, FALSE, TRUE);
}
