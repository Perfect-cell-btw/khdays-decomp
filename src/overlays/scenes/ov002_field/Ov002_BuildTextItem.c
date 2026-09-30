/* Build one text item from the const TileSurfaceCfg template at
 * data_ov002_0207dbe8: patch in the VRAM target handle for id 9 and point the
 * surface at the context's +0x24 pixel block, mark the context dirty at +0x4c,
 * then initialise the 4bpp surface at +0xbc (TileSurface_Init4bpp = TileSurface_Init
 * with upload off and 4bpp), draw the string looked up at index 8, and release
 * the lookup. The template is 40 bytes, which is exactly sizeof(TileSurfaceCfg). */
/* TileSurfaceCfg -- spelled out locally because delinking rules out shared headers. */
typedef struct {
    int nUnk00;
    int nUnk04;
    int nWidthTiles;
    int nHeightTiles;
    int nRowTiles;
    int nPaletteIndex;
    int nVramTarget;   /* +0x18 */
    int nUnk1c;
    void *pPixels;     /* +0x20 */
    int nUnk24;
} TileSurfaceCfg;

typedef struct {
    int w0;
    int w4;
    int w8;
} Ov002StringRef;

extern int data_ov002_0207f614;
extern const TileSurfaceCfg data_ov002_0207dbe8;
extern int gOv002UiBtlTextPath;

extern void Ov002_InitResourceRecord(void *ref, void *src);
extern int Ov002_GetItemResource(int id);
extern int TileSurface_Init4bpp(void *widget, void *cfg);
extern void *Ov002_GetVarRecordByIndex(void *ref, int idx);
extern void Text_DrawWithShadow(void *widget, int a, int b, int c, void *text, int d);
extern void EnqueueObjGfxCommand(void *widget);
extern void Ov002_FreeResourceRecordBuffer(void *ref);

void Ov002_BuildTextItem(void) {
    TileSurfaceCfg cfg;
    Ov002StringRef ref;
    char *ctx = (char *)*(int *)&data_ov002_0207f614;

    cfg = data_ov002_0207dbe8;
    Ov002_InitResourceRecord(&ref, &gOv002UiBtlTextPath);
    cfg.nVramTarget = Ov002_GetItemResource(9);
    cfg.pPixels = ctx + 0x24;
    *(int *)(ctx + 0x4c) = 1;
    TileSurface_Init4bpp(ctx + 0xbc, &cfg);
    Text_DrawWithShadow(ctx + 0xbc, 2, 3, 2, Ov002_GetVarRecordByIndex(&ref, 8), 1);
    EnqueueObjGfxCommand(ctx + 0xbc);
    Ov002_FreeResourceRecordBuffer(&ref);
}
