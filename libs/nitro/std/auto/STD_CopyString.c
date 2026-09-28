

#include "nitro/types.h"
#include "nitro/os.h"

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
