typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ov009GameState {
    int value0;
    int pad004;
    int value8;
    u8 pad00c[0x1ca0];
} Ov009GameState;

typedef struct Ov009SaveContext {
    int variant;
    int nextVariant;
    int state;
    int currentSlot;
    int phase;
    u8 pad014[0x148];
    u8 resource15c[0xc0];
    u8 tween21c[0x24];
    int interactionLock;
    int field244;
    u8 slotPhase;
    u8 pad249[0x03];
    Ov009GameState snapshot;
    int bestSlot;
    u32 bestPackedValue;
} Ov009SaveContext;

extern Ov009GameState *volatile data_0204be18;
extern const char data_ov009_02056378[];

extern void Ov009_InitSubScreenGraphics(void);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned int size);
extern void Ov009_InitResourceRecord(void *resource, const char *path);
extern int Ov009_TickSaveSlotPrep(Ov009SaveContext *ctx, int slot);
extern int GameState_GetField(int field, int kind);
extern void Ov009_LoadMenuBgWithVariantChars(void);
extern void Ov009_SaveMenu_BuildLayout(Ov009SaveContext *ctx);
extern void Ov009_SaveMenu_BuildTextSurfaces(Ov009SaveContext *ctx);
extern void Ov009_PlaceElementByVariant(Ov009SaveContext *ctx, int mode, int variant);
extern void Ov009_SaveMenu_UpdateNumbers(Ov009SaveContext *ctx);
extern void Tween_Clear(void *tween);
extern void Ov009_DrawNumberDigits(int value);
extern void Ov009_DrawMenuText(Ov009SaveContext *ctx, int mode);
extern void Ov009_SetMenuEntriesVisible(int enabled, int mode);

int Ov009_TickSlotScanState(Ov009SaveContext *ctx)
{
    int done = 0;

    switch (ctx->phase) {
    case 0:
        Ov009_InitSubScreenGraphics();
        MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
        MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
        MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
        Ov009_InitResourceRecord(ctx->resource15c, data_ov009_02056378);
        ctx->snapshot = *data_0204be18;
        ctx->slotPhase = 0;
        ctx->state = 0;
        ctx->phase++;
        break;

    case 1:
        if (Ov009_TickSaveSlotPrep(ctx, ctx->currentSlot) == 2) {
            u32 high = GameState_GetField(0xc77, 0x10);
            u32 low = GameState_GetField(0xc87, 0x10);
            u32 packed = low | high << 16;

            if (packed > ctx->bestPackedValue) {
                ctx->bestPackedValue = packed;
                ctx->bestSlot = ctx->currentSlot;
            }
            ctx->currentSlot++;
            ctx->slotPhase = 0;
            if (ctx->currentSlot >= 3) {
                ctx->phase++;
            }
        }
        break;

    case 2:
        *data_0204be18 = ctx->snapshot;
        Ov009_LoadMenuBgWithVariantChars();
        Ov009_SaveMenu_BuildLayout(ctx);
        Ov009_SaveMenu_BuildTextSurfaces(ctx);
        ctx->variant = GameState_GetField(0xc98, 2);
        Ov009_PlaceElementByVariant(ctx, 0, ctx->variant);
        Ov009_SaveMenu_UpdateNumbers(ctx);
        Tween_Clear(ctx->tween21c);
        Ov009_DrawNumberDigits(data_0204be18->value8);
        ctx->phase++;
        break;

    case 3:
        if (ctx->interactionLock != 0) {
            Ov009_DrawMenuText(ctx, 4);
            Ov009_SetMenuEntriesVisible(0, 0);
            ctx->state = 5;
        }
        done = 1;
        break;
    }

    return done;
}
