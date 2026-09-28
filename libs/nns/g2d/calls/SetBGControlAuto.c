

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/gx.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef enum NNSG2dScreenFormat {
    NNS_G2D_SCREENFORMAT_TEXT,
    NNS_G2D_SCREENFORMAT_AFFINE,
    NNS_G2D_SCREENFORMAT_AFFINEEXT,
    NNS_G2D_SCREENFORMAT_PLTBMP,
    NNS_G2D_SCREENFORMAT_DCBMP
} NNSG2dScreenFormat;
typedef enum NNSG2dBGSelect {
    NNS_G2D_BGSELECT_MAIN0,
    NNS_G2D_BGSELECT_MAIN1,
    NNS_G2D_BGSELECT_MAIN2,
    NNS_G2D_BGSELECT_MAIN3,
    NNS_G2D_BGSELECT_SUB0,
    NNS_G2D_BGSELECT_SUB1,
    NNS_G2D_BGSELECT_SUB2,
    NNS_G2D_BGSELECT_SUB3,
    NNS_G2D_BGSELECT_NUM
} NNSG2dBGSelect;
extern void SetBGControlText (NNSG2dBGSelect bg, GXBGColorMode colorMode, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase);
extern void SetBGControlAffine (NNSG2dBGSelect bg, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase);
extern void SetBGControl256x16Pltt (NNSG2dBGSelect bg, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase);

/* SetBGControlAuto -- NitroSystem g2d_Screen.c: SetBGControlAuto. */
void SetBGControlAuto (NNSG2dBGSelect bg, NNSG2dScreenFormat screenFormat, GXBGColorMode colorMode, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase)
{
    switch (screenFormat) {
    case NNS_G2D_SCREENFORMAT_TEXT:
        SetBGControlText(bg, colorMode, screenWidth, screenHeight, scnBase, chrBase);
        break;
    case NNS_G2D_SCREENFORMAT_AFFINE:
        SetBGControlAffine(bg, screenWidth, screenHeight, scnBase, chrBase);
        break;
    case NNS_G2D_SCREENFORMAT_AFFINEEXT:
        SetBGControl256x16Pltt(bg, screenWidth, screenHeight, scnBase, chrBase);
        break;
    default:
        break;
    }
}
