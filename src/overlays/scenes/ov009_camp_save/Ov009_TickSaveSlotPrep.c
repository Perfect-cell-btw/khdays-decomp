typedef unsigned char u8;

typedef struct Ov009SaveSlot {
    u8 pad_00[0x10];
    int result;
    u8 pad_14[0x1c - 0x14];
} Ov009SaveSlot;

typedef struct Ov009SaveContext {
    int variant;
    u8 pad_004[0x8 - 0x4];
    int state;
    int result;
    u8 pad_010[0x14 - 0x10];
    Ov009SaveSlot slots[3];
    int pending;
    u8 pad_06c[0x240 - 0x06c];
    int interactionLock;
    int field244;
    u8 slotPhase;
} Ov009SaveContext;

extern void MI_CpuFill8(void *dst, int value, unsigned int size);
extern void Ov009_StartCardTransfer(Ov009SaveContext *ctx, int slot);
extern int Ov009_PollSaveTransfer(Ov009SaveContext *ctx, int slot, int arg2,
                              int arg3);
extern void Ov009_FillSaveSlotInfo(Ov009SaveContext *ctx, int slot, int result);

/* Advance one save-slot preparation pass and return its local phase. */
int Ov009_TickSaveSlotPrep(Ov009SaveContext *ctx, int slot, int unused, int arg3)
{
    int result;
    int phase = ctx->slotPhase;

    switch (phase) {
    case 0:
        MI_CpuFill8(&ctx->slots[slot], 0, sizeof(Ov009SaveSlot));
        ctx->slots[slot].result = -1;
        Ov009_StartCardTransfer(ctx, slot);
        ctx->slotPhase = 1;
        break;

    case 1:
        result = Ov009_PollSaveTransfer(ctx, slot, phase, arg3);
        if (result == 3) {
            ctx->slotPhase = 2;
            ctx->result = 3;
            ctx->interactionLock = 1;
            ctx->field244 = 0;
        } else if (result >= 0) {
            Ov009_FillSaveSlotInfo(ctx, slot, result);
            ctx->slotPhase = 2;
        }
        break;
    }

    return ctx->slotPhase;
}
