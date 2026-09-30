/* Msg_BuildLangPath -- build a language-specific path, MAIN. Copies `src` into the path buffer of
 * gLangPath (+0x04), replacing the '&' placeholder with the two-letter code of the current
 * language (+0x00, an index into data_020427d4; the code pointer advances by one byte per
 * placeholder, so only one is expected), terminates it and returns the buffer. The ROM reloads the
 * character at the top of the loop body instead of reusing the loop test's load, hence the
 * volatile read. */

#include "nitro/types.h"

typedef struct LangPath {
    s16 lang;                           /* +0x00 */
    s16 pad02;
    char *buf;                          /* +0x04 */
} LangPath;

extern LangPath gLangPath;
extern const char *data_020427d4[];      /* two-letter language codes */

char *Msg_BuildLangPath(const char *src)
{
    char *dst = gLangPath.buf;
    const char *p = data_020427d4[gLangPath.lang];

    while (*src != 0) {
        char c = *(const volatile char *)src;

        switch (c) {
        case '&':
            src++;
            dst[0] = p[0];
            dst[1] = *++p;
            dst += 2;
            break;
        default:
            src++;
            *dst++ = c;
            break;
        }
    }
    *dst = 0;
    return gLangPath.buf;
}
