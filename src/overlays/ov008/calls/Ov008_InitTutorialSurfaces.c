/* Ov008_InitTutorialSurfaces -- Ov008_InitTutorialSurfaces: set up page B's seven 4bpp
 * tile surfaces from the tutorial config table (each gets the narrow glyph pixel
 * source and VRAM slot 0x1b) and mark each as dirty, then point the page's text
 * loader at "UI/tutorial/root_&.s.z".
 */
typedef unsigned char u8;

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

extern const Ov008TutorialCfgTable data_ov008_0208fb6c;
extern char data_ov008_02090b70[];                                  /* "UI/tutorial/root_&.s.z" */

extern Ov008PageB *Ov008_GetPageB(void);                       /* Ov008_GetPageB */
extern void *Ov008_GetCtxBlock968c(void);                             /* Ov008_GetCtxBlock968c */
extern int Ov008_ResetEntry(int nSlot);                          /* Ov008_ResetEntry */
extern void TileSurface_Init4bpp(TileSurface *pSurface, const TileSurfaceCfg *pCfg); /* TileSurface_Init4bpp */
extern void Ov008_VarTable_Load(void *pLoader, const char *pPath);

void Ov008_InitTutorialSurfaces(void)
{
    Ov008TutorialCfgTable cfgs;
    u8 i;
    Ov008PageB *pPage;
    TileSurfaceCfg *pCfg;

    pPage = Ov008_GetPageB();
    cfgs = data_ov008_0208fb6c;
    for (i = 0; i < SURFACE_COUNT; i++) {
        pCfg = &cfgs.aCfg[i];
        pCfg->pPixels = Ov008_GetCtxBlock968c();
        pCfg->nVramTarget = Ov008_ResetEntry(VRAM_SLOT_TUTORIAL);
        TileSurface_Init4bpp(&pPage->aSurface[i], pCfg);
        pPage->aSurface[i].bDirty = 1;
    }
    Ov008_VarTable_Load(pPage->textLoader, data_ov008_02090b70);
}
