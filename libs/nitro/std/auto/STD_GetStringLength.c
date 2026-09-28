

#include "nitro/types.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* STD_GetStringLength -- NitroSDK std_string.c: STD_GetStringLength. */
int STD_GetStringLength (const char * str)
{
    int n = 0;
    while (str[n]) {
        n++;
    }
    return n;
}
