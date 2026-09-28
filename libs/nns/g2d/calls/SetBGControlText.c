

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef struct ScreenSizeMap {
    u16 width;
    u16 height;
    u16 scnSize;
} ScreenSizeMap;
extern const ScreenSizeMap data_02041a54[4];
extern const ScreenSizeMap * SelectScnSize (const ScreenSizeMap tbl[4], int w, int h);
extern void SetBGnControlToText (NNSG2dBGSelect n, GXBGScrSizeText size, GXBGColorMode cmode, GXBGScrBase scnBase, GXBGCharBase chrBase);

/* SetBGControlText -- NitroSystem g2d_Screen.c: SetBGControlText. */
void SetBGControlText (NNSG2dBGSelect bg, GXBGColorMode colorMode, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase)
{
    const ScreenSizeMap * pSizeMap;

    pSizeMap = SelectScnSize(data_02041a54, screenWidth, screenHeight);

    SetBGnControlToText(bg, (GXBGScrSizeText)pSizeMap->scnSize, colorMode, scnBase, chrBase);
}
