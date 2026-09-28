/* NitroSDK os_emulator.c: OSi_ConsoleTypeCache, the console type OS_GetConsoleType caches;
 * OSi_CONSOLE_NOT_DETECT (-1) until the first call. */

#include "nitro/types.h"
#include "nitro/os.h"

u32 data_020422b0 = OSi_CONSOLE_NOT_DETECT;
