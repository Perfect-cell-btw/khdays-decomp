/* Ov025_Hub_SetupTextSurfaces -- Ov025_Hub_SetupTextSurfaces: build the two text surfaces of the records
 * hub (+0x10 and +0x4c) from the templates data_ov025_020b38d4 / 020b38fc with the shared tile
 * pixel buffer (02084c84) and VRAM slot 9 (02084aa4), uploaded as 4bpp tiles (0202ff8c); +0x74
 * is set.  String 7 of the hub's string set (+4; 02089894) is drawn on the first surface right
 * aligned (flags 0x821) twice, at (0xff, 3) in colour 1 under (0xfe, 2) in colour 2
 * (Text_DrawDirectional 020301c8), the surface uploaded (020300f8) and slot 9 marked (02084964). */

#include "nitro/types.h"

typedef struct TileSurfaceCfg {
    u32  nUnk00;
    u32  nUnk04;
    u32  nWidthTiles;
    u32  nHeightTiles;
    u32  nRowTiles;
    u32  nPaletteIndex;
    u32  nVramTarget;
    u32  nUnk1c;
    void *pPixels;
    u32  nUnk24;
} TileSurfaceCfg;

typedef struct Ov025HubScene {
    int  nField00;            /* 0x00 */
    u8   strings[0xc];        /* 0x04: the hub string set */
    u8   surfaceTitle[0x3c];  /* 0x10: the title surface */
    u8   surfaceBody[0x28];   /* 0x4c: the second surface */
    int  bTextReady;          /* 0x74 */
} Ov025HubScene;

extern void *Ov025_GetCtxBlock968c(void);                             /* Ov008_GetCtxBlock968c: the tile pixel buffer */
extern int   Ov025_LookupEntry(int nSlot);                        /* Ov008_ResetEntry: slot handle */
extern void  TileSurface_InitAndUpload4bpp(void *pSurface, TileSurfaceCfg *pCfg);   /* TileSurface_InitAndUpload4bpp */
extern const u16 *Ov025_GetVarRecordByIndex(void *pStrings, int nIndex);  /* Ov025_GetString */
extern void  Text_DrawDirectional_2(void *pSurface, int nX, int nY, int nColour, u32 nFlags, const u16 *pText); /* Text_DrawDirectional */
extern void  EnqueueObjGfxCommand(void *pSurface);                         /* TileSurface_Upload */
extern void  Ov025_MarkSlotUsed(int nSlot);                        /* Ov008_MarkSlotUsed */
extern TileSurfaceCfg data_ov025_020b38d4;
extern TileSurfaceCfg data_ov025_020b38fc;

void Ov025_Hub_SetupTextSurfaces(Ov025HubScene *pScene)
{
    TileSurfaceCfg cfgTitle;
    TileSurfaceCfg cfgBody;
    const u16 *pTitle;

    cfgTitle = data_ov025_020b38d4;
    cfgBody = data_ov025_020b38fc;
    cfgTitle.pPixels = Ov025_GetCtxBlock968c();
    cfgTitle.nVramTarget = Ov025_LookupEntry(9);
    cfgBody.pPixels = Ov025_GetCtxBlock968c();
    cfgBody.nVramTarget = Ov025_LookupEntry(9);
    TileSurface_InitAndUpload4bpp(pScene->surfaceTitle, &cfgTitle);
    TileSurface_InitAndUpload4bpp(pScene->surfaceBody, &cfgBody);
    pScene->bTextReady = 1;
    pTitle = Ov025_GetVarRecordByIndex(pScene->strings, 7);
    Text_DrawDirectional_2(pScene->surfaceTitle, 0xff, 3, 1, 0x821, pTitle);
    Text_DrawDirectional_2(pScene->surfaceTitle, 0xfe, 2, 2, 0x821, pTitle);
    EnqueueObjGfxCommand(pScene->surfaceTitle);
    Ov025_MarkSlotUsed(9);
}
