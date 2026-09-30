/* Ov023_BuildEventTextPath -- Ov023_BuildEventTextPath: build the path of an event's text file.
 * The path starts as "ev/EV_" (gOv023EvEvPath) and gets, by the event code's third
 * character, "S" for 'S' (the shared file), "DP" for 'D', or otherwise the code's fifth and
 * sixth characters one at a time (STD_StrnCat 0201fa6c), then ".p2" (STD_StrCat 0201fa3c).
 * Returns the path, which lives in the caller's frame as a 0x40 stack buffer. */

#include "nitro/types.h"

extern char *STD_StrCat(char *pszDst, const char *pszSrc);           /* STD_StrCat */
extern char *STD_StrnCat(char *pszDst, const char *pszSrc, int nMax); /* STD_StrnCat */
extern const u8 gOv023EvEvPath[];                              /* "ev/EV_" */
extern const char gOv023SName[];                            /* "S" */
extern const char gOv023DpName[];                            /* "DP" */
extern const char gOv023P2Name[];                            /* ".p2" */

char *Ov023_BuildEventTextPath(const char *pszCode)
{
    char szPath[0x40];

    {
        u32 nRemaining;
        const u8 *pSrc;
        u8 *pDst;

        pSrc = gOv023EvEvPath;
        pDst = (u8 *)szPath;
        nRemaining = 7;
        do {
            *pDst = *pSrc;
            pSrc++;
            pDst++;
            nRemaining--;
        } while (nRemaining != 0);
    }
    if (pszCode[2] == 'S') {
        STD_StrCat(szPath, gOv023SName);
    } else if (pszCode[2] == 'D') {
        STD_StrCat(szPath, gOv023DpName);
    } else {
        STD_StrnCat(szPath, pszCode + 4, 1);
        STD_StrnCat(szPath, pszCode + 5, 1);
    }
    STD_StrCat(szPath, gOv023P2Name);
    return szPath;
}
