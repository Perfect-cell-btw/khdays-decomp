/* Polls the save card transfer; when it ends, restores the transient flags after a write and resets
 * the transfer state; returns the result (-1 while busy). */

typedef unsigned char u8;

typedef struct Ov009SaveSlot {
    u8 pad00[0x10];
    int result;
    u8 pad14[0x08];
} Ov009SaveSlot;

typedef struct Ov009SaveContext {
    int variant;
    u8 pad004[0x04];
    int state;
    int result;
    u8 pad010[0x04];
    Ov009SaveSlot slots[3];
    int pending;
    u8 pad06c[0x1d0];
    int transferState;
    int interactionLock;
    int field244;
    u8 slotPhase;
    u8 pad249[0x1cb7];
    u8 flag18bd;
    u8 flag18c9;
} Ov009SaveContext;

extern int Ov009_PollSaveLoad(void);
extern int Ov009_CardTransferStep(int state, int arg1, int arg2, int arg3);
extern void GameState_SetFlag(int flag);
extern void Ov009_SetupWorkArea(int slot);

int Ov009_PollSaveTransfer(Ov009SaveContext *ctx, int arg1, int arg2, int arg3)
{
    int result;

    switch (ctx->transferState) {
    case 1:
        result = Ov009_PollSaveLoad();
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = Ov009_CardTransferStep(ctx->transferState, arg1, arg2, arg3);
        break;
    default:
        ctx->transferState = 0;
        result = 3;
        break;
    }

    switch (result) {
    case 0:
    case 2:
    case 3:
    case 4:
        if (ctx->transferState == 3) {
            if (ctx->flag18bd != 0) {
                GameState_SetFlag(0x18bd);
            }
            if (ctx->flag18c9 != 0) {
                GameState_SetFlag(0x18c9);
            }
        }
        ctx->transferState = 0;
        break;
    case 1:
    default:
        result = -1;
        break;
    }

    if (result == 2) {
        Ov009_SetupWorkArea(1);
    }

    return result;
}
