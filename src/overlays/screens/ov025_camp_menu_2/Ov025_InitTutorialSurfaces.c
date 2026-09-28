/* Ov025_InitTutorialSurfaces -- Ov008_InitTutorialSurfaces: set up page B's seven 4bpp
 * tile surfaces from the tutorial config table (each gets the narrow glyph pixel
 * source and VRAM slot 0x1b) and mark each as dirty, then point the page's text
 * loader at "UI/tutorial/root_&.s.z".
 */
#include "nitro/types.h"

#define SURFACE_COUNT 7
#define VRAM_SLOT_TUTORIAL 0x1b

typedef struct TileSurfaceCfg {
    int   nUnk00;
    int   nUnk04;
    int   nWidthTiles;
    int   nHeightTiles;
    int   nRowTiles;
    int   nPaletteIndex;
    int   nVramTarget;
    int   nUnk1c;
    void *pPixels;
    int   nUnk24;
} TileSurfaceCfg;

typedef struct Ov008TutorialCfgTable {
    TileSurfaceCfg aCfg[SURFACE_COUNT];
} Ov008TutorialCfgTable;

typedef struct TileSurface {
    u8  pad_00[0x28];
    int bDirty;               /* 0x28 */
    u8  pad_2c[0x3c - 0x2c];
} TileSurface;

typedef struct Ov008PageB {
    u8          pad_000[0x38];
    TileSurface aSurface[SURFACE_COUNT]; /* 0x038 */
    u8          textLoader[1];           /* 0x1dc */
} Ov008PageB;

extern const Ov008TutorialCfgTable data_ov025_020b4844;
extern char data_ov025_020b56a4[];                                  /* "UI/tutorial/root_&.s.z" */

extern Ov008PageB *Ov025_GetPageB(void);                       /* Ov008_GetPageB */
extern void *Ov025_GetCtxBlock968c(void);                             /* Ov008_GetCtxBlock968c */
extern int Ov025_LookupEntry(int nSlot);                          /* Ov008_ResetEntry */
extern void TileSurface_Init4bpp(TileSurface *pSurface, const TileSurfaceCfg *pCfg); /* TileSurface_Init4bpp */
extern void Ov025_InitResourceRecord(void *pLoader, const char *pPath);

void Ov025_InitTutorialSurfaces(void)
{
    Ov008TutorialCfgTable cfgs;
    u8 i;
    Ov008PageB *pPage;
    TileSurfaceCfg *pCfg;

    pPage = Ov025_GetPageB();
    cfgs = data_ov025_020b4844;
    for (i = 0; i < SURFACE_COUNT; i++) {
        pCfg = &cfgs.aCfg[i];
        pCfg->pPixels = Ov025_GetCtxBlock968c();
        pCfg->nVramTarget = Ov025_LookupEntry(VRAM_SLOT_TUTORIAL);
        TileSurface_Init4bpp(&pPage->aSurface[i], pCfg);
        pPage->aSurface[i].bDirty = 1;
    }
    Ov025_InitResourceRecord(pPage->textLoader, data_ov025_020b56a4);
}
