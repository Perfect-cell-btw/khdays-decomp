/* Ov025_ReportDetail_SetupSurface -- Ov025_ReportDetail_SetupSurface: build the text surface at +4 of the
 * report detail view of page B (Ov025_GetPageB 02084b14) from the template data_ov025_020b4978
 * with the shared tile pixel buffer (02084c84) and VRAM slot 0x19 (02084aa4), uploaded as 4bpp
 * tiles (0202ff8c).  Part of the detail screen setup 020b00f0. */
typedef unsigned char  u8;
typedef unsigned int   u32;

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

typedef struct Ov025ReportDetailPage {
    int  nField00;            /* 0x00 */
    u8   surface[0x3c];       /* 0x04: the text surface (TileSurface) */
} Ov025ReportDetailPage;

extern Ov025ReportDetailPage *Ov025_GetPageB(void);            /* Ov025_GetPageB */
extern void *Ov025_GetCtxBlock968c(void);                             /* Ov025_GetCtxBlock968c */
extern int   Ov025_LookupEntry(int nSlot);                        /* Ov025_ResetEntry: slot handle */
extern void  TileSurface_InitAndUpload4bpp(void *pSurface, TileSurfaceCfg *pCfg);   /* TileSurface_InitAndUpload4bpp */
extern TileSurfaceCfg data_ov025_020b4978;

void Ov025_ReportDetail_SetupSurface(void)
{
    TileSurfaceCfg cfg;
    Ov025ReportDetailPage *pPage;

    cfg = data_ov025_020b4978;
    pPage = Ov025_GetPageB();
    cfg.pPixels = Ov025_GetCtxBlock968c();
    cfg.nVramTarget = Ov025_LookupEntry(0x19);
    TileSurface_InitAndUpload4bpp(pPage->surface, &cfg);
}
