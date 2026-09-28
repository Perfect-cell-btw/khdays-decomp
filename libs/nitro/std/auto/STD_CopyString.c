#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* STD_CopyString -- NitroSDK std_string.c: STD_CopyString. */
char * STD_CopyString (char * destp, const char * srcp)
{
    char * retval = destp;

    while (*srcp) {
        *destp++ = (char)*srcp++;
    }

    *destp = '\0';

    return retval;
}
