/* Ov025_InitStatusPanelSurfaces -- Ov008_InitStatusPanelSurfaces: create the six tile
 * surfaces of the status panel (+0x64, 0x3c each) from the templates
 * data_ov025_020b43d8 / f6d8 / f700 / f728 / f750 / f688 copied to the stack.
 * The first five share the VRAM target of slot 0x18 and the pixel buffer of
 * context block 968c; the sixth (f688) uses slot 0x1a with the same buffer.
 * The first surface's word at +0x28 is set to 5, slot 0x18 is marked used and
 * the panel's text loader (+0x58) is pointed at "UI/cm/str/status_&.s.z".
 *
 * NOTE: compiled with #pragma opt_common_subs off (push/pop scoped): with CSE on
 * mwcc schedules the third upload's arguments the other way round (add r0 before
 * add r1); no source form changed that, the pragma reproduces the ROM.
 */

#include "nitro/types.h"

#define SURFACE_COUNT 6
#define VRAM_SLOT_MAIN 0x18
#define VRAM_SLOT_LAST 0x1a

typedef struct TileSurfaceCfg {
    int   nId;                /* 0x00 */
    int   nUnk04;             /* 0x04 */
    int   nWidthTiles;        /* 0x08 */
    int   nHeightTiles;       /* 0x0c */
    int   nCharBase;          /* 0x10 */
    int   nPaletteIndex;      /* 0x14 */
    int   nVramTarget;        /* 0x18 */
    int   nUnk1c;             /* 0x1c */
    void *pPixels;            /* 0x20 */
    int   nUnk24;             /* 0x24 */
} TileSurfaceCfg;

typedef struct TileSurface {
    u8  pad_00[0x28];
    int bDirty;               /* 0x28 */
    u8  pad_2c[0x3c - 0x2c];
} TileSurface;

typedef struct Ov008StatusPanel {
    u8  pad_00[0x58];
    u8  textLoader[0xc];      /* 0x58 */
    TileSurface aSurface[SURFACE_COUNT]; /* 0x64 */
} Ov008StatusPanel;

extern const TileSurfaceCfg data_ov025_020b43d8;
extern const TileSurfaceCfg data_ov025_020b4400;
extern const TileSurfaceCfg data_ov025_020b4428;
extern const TileSurfaceCfg data_ov025_020b4450;
extern const TileSurfaceCfg data_ov025_020b4478;
extern const TileSurfaceCfg data_ov025_020b43b0;
extern const char data_ov025_020b52d4[];                                  /* "UI/cm/str/status_&.s.z" */
extern int   Ov025_LookupEntry(int nSlot);                              /* Ov008_ResetEntry: slot handle */
extern void *Ov025_GetCtxBlock968c(void);                                   /* Ov008_GetCtxBlock968c */
extern void  TileSurface_InitAndUpload8bpp(TileSurface *pSurface, const TileSurfaceCfg *pCfg); /* TileSurface_InitAndUpload8bpp */
extern void  Ov025_MarkSlotUsed(int nSlot);                              /* Ov008_MarkSlotUsed */
extern void  Ov025_InitResourceRecord(void *pLoader, const char *pPath);       /* Ov008_Set_5c4c */

#pragma opt_common_subs off
#pragma push
#pragma opt_common_subs off
void Ov025_InitStatusPanelSurfaces(Ov008StatusPanel *pPanel)
{
    TileSurfaceCfg cfg0;
    TileSurfaceCfg cfg1;
    TileSurfaceCfg cfg2;
    TileSurfaceCfg cfg3;
    TileSurfaceCfg cfg4;
    TileSurfaceCfg cfg5;

    cfg0 = data_ov025_020b43d8;
    cfg1 = data_ov025_020b4400;
    cfg2 = data_ov025_020b4428;
    cfg3 = data_ov025_020b4450;
    cfg4 = data_ov025_020b4478;
    cfg5 = data_ov025_020b43b0;
    cfg4.nVramTarget = Ov025_LookupEntry(VRAM_SLOT_MAIN);
    cfg3.nVramTarget = cfg4.nVramTarget;
    cfg2.nVramTarget = cfg4.nVramTarget;
    cfg1.nVramTarget = cfg4.nVramTarget;
    cfg0.nVramTarget = cfg4.nVramTarget;
    cfg4.pPixels = Ov025_GetCtxBlock968c();
    cfg3.pPixels = cfg4.pPixels;
    cfg2.pPixels = cfg4.pPixels;
    cfg1.pPixels = cfg4.pPixels;
    cfg0.pPixels = cfg4.pPixels;
    cfg5.nVramTarget = Ov025_LookupEntry(VRAM_SLOT_LAST);
    cfg5.pPixels = Ov025_GetCtxBlock968c();
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[0], &cfg0);
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[1], &cfg1);
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[2], &cfg2);
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[3], &cfg3);
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[4], &cfg4);
    TileSurface_InitAndUpload8bpp(&pPanel->aSurface[5], &cfg5);
    pPanel->aSurface[0].bDirty = 5;
    Ov025_MarkSlotUsed(VRAM_SLOT_MAIN);
    Ov025_InitResourceRecord(pPanel->textLoader, data_ov025_020b52d4);
}
#pragma pop
