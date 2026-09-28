

#include "nitro/types.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* GXx_GetMasterBrightness_ -- NitroSDK gx.c: GXx_GetMasterBrightness_. */
int GXx_GetMasterBrightness_ (vu16 *reg)
{
	u16 mode = (u16)(*reg & REG_GX_MASTER_BRIGHT_E_MOD_MASK);

	if (mode == 0) {
		return 0;
	} else if (mode == (1 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT))   {
		return *reg & REG_GX_MASTER_BRIGHT_E_VALUE_MASK;
	} else if (mode == (2 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT))   {
		return -(*reg & REG_GX_MASTER_BRIGHT_E_VALUE_MASK);
	} else {
		return 0;
	}
}
