

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

inline REGType16v * GetBGnCNT (NNSG2dBGSelect n)
{
    extern REGType16v * const data_02041ac0[];
    return data_02041ac0[n];
}
inline BOOL IsMainBG (NNSG2dBGSelect bg)
{
    return (bg <= NNS_G2D_BGSELECT_MAIN3);
}
inline u16 MakeBGnCNTVal256x16Pltt (GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    return (u16)(
        (screenSize << 14 )
        | (screenBase << 8 )
        | (charBase << 2 )
        | (areaOver << 13 )
        | GX_BG_EXTMODE_256x16PLTT
        );
}
inline void SetBGnControl256x16Pltt (NNSG2dBGSelect n, GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    *GetBGnCNT(n) = (u16)(
        (*GetBGnCNT(n) & (0x0003 | 0x0040 ))
        | MakeBGnCNTVal256x16Pltt(screenSize, areaOver, screenBase, charBase)
        );
}
extern const u8 data_020419f4[2][8];
extern void ChangeBGModeByTableMain (const u8 modeTable[]);
extern void ChangeBGModeByTableSub (const u8 modeTable[]);

/* SetBGnControlTo256x16Pltt -- NitroSystem g2d_Screen.c: SetBGnControlTo256x16Pltt. */
void SetBGnControlTo256x16Pltt (NNSG2dBGSelect n, GXBGScrSize256x16Pltt size, GXBGAreaOver areaOver, GXBGScrBase scnBase, GXBGCharBase chrBase)
{
    if (IsMainBG(n)) {
        ChangeBGModeByTableMain(data_020419f4[n - 2]);
    } else {
        ChangeBGModeByTableSub(data_020419f4[n - 6]);
    }
    SetBGnControl256x16Pltt(n, size, areaOver, scnBase, chrBase);
}
