/* Creates the three text surfaces of the save page and draws its captions. */

#include "nitro/types.h"
#include "game/engine.h"

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
    u8 pad000[0x15c];
    u8 varRecords[0x0c];
    u8 surface168[0x3c];
    u8 surface1a4[0x3c];
    u8 surface1e0[1];
} Ov009SaveContext;

extern const TileSurfaceCfg data_ov009_02056058;
extern const TileSurfaceCfg data_ov009_02056080;
extern const TileSurfaceCfg data_ov009_02056030;

extern void *Ov009_GetCtxBlock968c(void);
extern int Ov009_ResourceNodeCallback_2(int slot);
extern u16 *Ov009_GetVarRecordByIndex(void *records, int index);
extern void Ov009_DrawWithShadow(
    void *surface,
    int x,
    int y,
    int style,
    const u16 *text,
    int shadow
);
extern void Ov009_DrawTextNewline(
    void *surface,
    int x,
    int y,
    int style,
    const u16 *text
);
extern void EnqueueObjGfxCommand(void *surface);
extern void Ov009_MarkSlotUsed(int slot);

void Ov009_SaveMenu_BuildTextSurfaces(Ov009SaveContext *ctx)
{
    TileSurfaceCfg config168 = data_ov009_02056058;
    TileSurfaceCfg config1e0 = data_ov009_02056080;
    TileSurfaceCfg config1a4 = data_ov009_02056030;
    const u16 *text;

    config168.pixels = Ov009_GetCtxBlock968c();
    config168.vramTarget = Ov009_ResourceNodeCallback_2(9);
    config1a4.pixels = Ov009_GetCtxBlock968c();
    config1a4.vramTarget = Ov009_ResourceNodeCallback_2(9);
    config1e0.pixels = Ov009_GetCtxBlock968c();
    config1e0.vramTarget = Ov009_ResourceNodeCallback_2(9);

    TileSurface_InitAndUpload4bpp(ctx->surface168, &config168);
    TileSurface_InitAndUpload4bpp(ctx->surface1a4, &config1a4);
    TileSurface_InitAndUpload4bpp(ctx->surface1e0, &config1e0);

    text = Ov009_GetVarRecordByIndex(ctx->varRecords, 0);
    Ov009_DrawWithShadow(ctx->surface168, 0x8e, 2, 2, text, 1);

    text = Ov009_GetVarRecordByIndex(ctx->varRecords, 1);
    Ov009_DrawTextNewline(ctx->surface1a4, 0x62, 0, 2, text);

    EnqueueObjGfxCommand(ctx->surface1a4);
    EnqueueObjGfxCommand(ctx->surface168);
    EnqueueObjGfxCommand(ctx->surface1e0);
    Ov009_MarkSlotUsed(9);
}
