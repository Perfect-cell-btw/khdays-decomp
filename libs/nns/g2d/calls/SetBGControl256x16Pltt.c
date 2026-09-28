

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern GXBGAreaOver data_02047390;
typedef struct ScreenSizeMap {
    u16 width;
    u16 height;
    u16 scnSize;
} ScreenSizeMap;
extern const ScreenSizeMap data_02041a24[4];
extern GXBGAreaOver data_02047390;
extern const ScreenSizeMap * SelectScnSize (const ScreenSizeMap tbl[4], int w, int h);
extern void SetBGnControlTo256x16Pltt (NNSG2dBGSelect n, GXBGScrSize256x16Pltt size, GXBGAreaOver areaOver, GXBGScrBase scnBase, GXBGCharBase chrBase);

/* SetBGControl256x16Pltt -- NitroSystem g2d_Screen.c: SetBGControl256x16Pltt. */
void SetBGControl256x16Pltt (NNSG2dBGSelect bg, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase)
{
    const ScreenSizeMap * pSizeMap;

    pSizeMap = SelectScnSize(data_02041a24, screenWidth, screenHeight);

    SetBGnControlTo256x16Pltt(bg, (GXBGScrSize256x16Pltt)pSizeMap->scnSize, data_02047390, scnBase, chrBase);
}
