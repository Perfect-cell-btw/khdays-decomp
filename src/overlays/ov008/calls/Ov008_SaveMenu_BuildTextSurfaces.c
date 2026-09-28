typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TileSurfaceCfg {
    u32 field00;
    u32 field04;
    u32 widthTiles;
    u32 heightTiles;
    u32 rowTiles;
    u32 paletteIndex;
    int vramTarget;
    u32 field1c;
    void *pixels;
    u32 field24;
} TileSurfaceCfg;

typedef struct Ov009SaveContext {
    u8 pad000[0x158];
    u8 varRecords[0x0c];
    u8 surface168[0x3c];
    u8 surface1a4[0x3c];
    u8 surface1e0[1];
} Ov009SaveContext;

extern const TileSurfaceCfg data_ov008_0208f538;
extern const TileSurfaceCfg data_ov008_0208f560;
extern const TileSurfaceCfg data_ov008_0208f510;

extern void *Ov008_GetCtxBlock968c(void);
extern int Ov008_ResetEntry(int slot);
extern void TileSurface_InitAndUpload4bpp(void *surface, const TileSurfaceCfg *config);
extern u16 *Ov008_GetVarRecordByIndex(void *records, int index);
extern void Ov008_DrawWithShadow(
    void *surface,
    int x,
    int y,
    int style,
    const u16 *text,
    int shadow
);
extern void Ov008_DrawTextNewline(
    void *surface,
    int x,
    int y,
    int style,
    const u16 *text
);
extern void EnqueueObjGfxCommand(void *surface);
extern void Ov008_MarkSlotUsed(int slot);

void Ov008_SaveMenu_BuildTextSurfaces(Ov009SaveContext *ctx)
{
    TileSurfaceCfg config168 = data_ov008_0208f538;
    TileSurfaceCfg config1e0 = data_ov008_0208f560;
    TileSurfaceCfg config1a4 = data_ov008_0208f510;
    const u16 *text;

    config168.pixels = Ov008_GetCtxBlock968c();
    config168.vramTarget = Ov008_ResetEntry(9);
    config1a4.pixels = Ov008_GetCtxBlock968c();
    config1a4.vramTarget = Ov008_ResetEntry(9);
    config1e0.pixels = Ov008_GetCtxBlock968c();
    config1e0.vramTarget = Ov008_ResetEntry(9);

    TileSurface_InitAndUpload4bpp(ctx->surface168, &config168);
    TileSurface_InitAndUpload4bpp(ctx->surface1a4, &config1a4);
    TileSurface_InitAndUpload4bpp(ctx->surface1e0, &config1e0);

    text = Ov008_GetVarRecordByIndex(ctx->varRecords, 0);
    Ov008_DrawWithShadow(ctx->surface168, 0x8e, 2, 2, text, 1);

    text = Ov008_GetVarRecordByIndex(ctx->varRecords, 1);
    Ov008_DrawTextNewline(ctx->surface1a4, 0x62, 0, 2, text);

    EnqueueObjGfxCommand(ctx->surface1a4);
    EnqueueObjGfxCommand(ctx->surface168);
    EnqueueObjGfxCommand(ctx->surface1e0);
    Ov008_MarkSlotUsed(9);
}
