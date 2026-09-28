#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

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
