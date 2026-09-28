

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
extern const ScreenSizeMap data_02041a3c[4];
extern GXBGAreaOver data_02047390;
extern const ScreenSizeMap * SelectScnSize (const ScreenSizeMap tbl[4], int w, int h);
extern void SetBGnControlToAffine (NNSG2dBGSelect n, GXBGScrSizeAffine size, GXBGAreaOver areaOver, GXBGScrBase scnBase, GXBGCharBase chrBase);

/* SetBGControlAffine -- NitroSystem g2d_Screen.c: SetBGControlAffine. */
void SetBGControlAffine (NNSG2dBGSelect bg, int screenWidth, int screenHeight, GXBGScrBase scnBase, GXBGCharBase chrBase)
{
    const ScreenSizeMap * pSizeMap;

    pSizeMap = SelectScnSize(data_02041a3c, screenWidth, screenHeight);

    SetBGnControlToAffine(bg, (GXBGScrSizeAffine)pSizeMap->scnSize, data_02047390, scnBase, chrBase);
}
