/* Ov008_InitMissionMenuSurfaces -- Ov008_InitMissionMenuSurfaces: create the mission
 * menu's five tile surfaces (+0xc, 0x3c each).  The first (template
 * data_ov008_0208fa9c) is created on slot 0x1a with block 968c's pixels and
 * its base cell (+0x138) and two fresh cells (+0x13c, +0x140) recorded.  The
 * other four share slot 0x18: the second (faec, 968c pixels) at character
 * base 0x160, the third (fb14, e5c pixels) at 0x188, the fourth at 0x1ac
 * from template fa4c (e5c pixels, no transfer) or fa74 (transfer, +0x150),
 * and the fifth (fac4, 968c pixels) at 0x1b0 or 0x1b6 accordingly.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

#define SURFACE_COUNT 5
#define SLOT_FIRST    0x1a
#define SLOT_ROWS     0x18
#define CHAR_BASE_ROWS 0x160

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
    u8 pad[0x3c];
} TileSurface;

typedef struct Ov008MissionMenu {
    u8  pad_000[0xc];
    TileSurface aSurface[SURFACE_COUNT]; /* 0x00c */
    void *pBaseCell;          /* 0x138 */
    void *pCellA;             /* 0x13c */
    void *pCellB;             /* 0x140 */
    u8  pad_144[0x150 - 0x144];
    int bTransfer;            /* 0x150 */
} Ov008MissionMenu;

extern const TileSurfaceCfg data_ov008_0208fa9c;
extern const TileSurfaceCfg data_ov008_0208faec;
extern const TileSurfaceCfg data_ov008_0208fb14;
extern const TileSurfaceCfg data_ov008_0208fa4c;
extern const TileSurfaceCfg data_ov008_0208fa74;
extern const TileSurfaceCfg data_ov008_0208fac4;
extern void *Ov008_GetCtxBlock968c(void);                                   /* Ov008_GetCtxBlock968c */
extern void *Ov008_GetDescriptor0(void);                                   /* pixel buffer */
extern int   Ov008_ResetEntry(int nSlot);                              /* Ov008_ResetEntry: slot handle */
extern void  TileSurface_InitAndUpload8bpp(TileSurface *pSurface, const TileSurfaceCfg *pCfg); /* TileSurface_InitAndUpload8bpp */
extern void *Obj_GetWord18(TileSurface *pSurface);                        /* base cell */
extern void *TileSurface_AddCanvas(TileSurface *pSurface, int nArg);              /* new cell */

void Ov008_InitMissionMenuSurfaces(Ov008MissionMenu *pMenu)
{
    TileSurfaceCfg cfgFirst;
    TileSurfaceCfg cfgA;
    TileSurfaceCfg cfgB;
    TileSurfaceCfg cfgC;
    TileSurfaceCfg cfgD;
    TileSurfaceCfg cfgE;
    int nCharBase;
    int nVram;

    cfgFirst = data_ov008_0208fa9c;
    cfgFirst.pPixels = Ov008_GetCtxBlock968c();
    cfgFirst.nVramTarget = Ov008_ResetEntry(SLOT_FIRST);
    TileSurface_InitAndUpload8bpp(&pMenu->aSurface[0], &cfgFirst);
    pMenu->pBaseCell = Obj_GetWord18(&pMenu->aSurface[0]);
    pMenu->pCellA = TileSurface_AddCanvas(&pMenu->aSurface[0], 0);
    pMenu->pCellB = TileSurface_AddCanvas(&pMenu->aSurface[0], 0);
    cfgA = data_ov008_0208faec;
    cfgB = data_ov008_0208fb14;
    cfgC = data_ov008_0208fa4c;
    cfgD = data_ov008_0208fa74;
    cfgE = data_ov008_0208fac4;
    cfgA.pPixels = Ov008_GetCtxBlock968c();
    cfgB.pPixels = Ov008_GetDescriptor0();
    cfgC.pPixels = Ov008_GetDescriptor0();
    cfgD.pPixels = Ov008_GetDescriptor0();
    cfgE.pPixels = Ov008_GetCtxBlock968c();
    nVram = Ov008_ResetEntry(SLOT_ROWS);
    nCharBase = CHAR_BASE_ROWS;
    cfgA.nCharBase = nCharBase;
    cfgA.nVramTarget = nVram;
    cfgB.nVramTarget = nVram;
    cfgC.nVramTarget = nVram;
    cfgD.nVramTarget = nVram;
    cfgE.nVramTarget = nVram;
    TileSurface_InitAndUpload8bpp(&pMenu->aSurface[1], &cfgA);
    cfgB.nCharBase = 0x188;
    TileSurface_InitAndUpload8bpp(&pMenu->aSurface[3], &cfgB);
    if (pMenu->bTransfer == 0) {
        cfgC.nCharBase = 0x1ac;
        nCharBase += 0x50;
        TileSurface_InitAndUpload8bpp(&pMenu->aSurface[2], &cfgC);
    } else {
        cfgD.nCharBase = 0x1ac;
        nCharBase += 0x56;
        TileSurface_InitAndUpload8bpp(&pMenu->aSurface[2], &cfgD);
    }
    cfgE.nCharBase = nCharBase;
    TileSurface_InitAndUpload8bpp(&pMenu->aSurface[4], &cfgE);
}
