typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    unsigned long long qwStart;
    unsigned long long qwInterval;
    int bActive;
    int nPhase;
} Ov002GaugeSlot;

typedef struct {
    u16 wA;
    u16 wB;
} Ov002CountPair;

typedef struct {
    int aHandles[4];                    /* +0x00 */
    u8 pad0010[0x10];
    int nSurface;                       /* +0x20 */
    u8 pad0024[4];
    u8 bDirty;                          /* +0x28 */
    u8 pad0029[7];
    int nSoundState;                    /* +0x30 */
    u8 pad0034[0x14];
    unsigned bTweenB : 1;               /* +0x48 */
    unsigned long long aHold[4];        /* +0x4c */
    Ov002GaugeSlot aSlots[4];           /* +0x6c */
    Ov002CountPair aCounts[4];          /* +0xcc */
    u8 pad00dc[0x18];
    u8 aTweenA[0x1c];                   /* +0xf4 */
    u8 aTweenAState[0x1c];              /* +0x110 */
    u8 aTweenB[0x1c];                   /* +0x12c */
    u8 aTweenBState[0x1c];              /* +0x148 */
    u8 pad0164[0x14];
    int bPromptPending;                 /* +0x178 */
} Ov002SceneCtx;

extern u8 data_0204be04;
extern Ov002SceneCtx *data_ov002_0207f618;
extern int data_ov002_0207ddfc;

extern int Ov002_StepGaugePair(u8 *pDst, u8 *pSrc, int nMode, int nArg);
extern void Ov002_RepaintPanelRows(void);
extern void Ov002_RepaintSubPanelRows(void);
extern int Ov002_GetPanelField01b0(void);
extern int Ov002_AdvanceGaugeSlot(int nIndex, Ov002GaugeSlot *pSlot);
extern void GFXi_EnqueueCommand(int nQueue, int nTarget, int nSrc, int nSize);
extern unsigned long long OS_GetTick(void);
extern void Ov002_UploadSlotIconPalette(int nIndex, int nMode);
extern int Ov002_RunShutdownHook(void);
extern void PlaySoundChecked(int nBank, int nSound);
extern void ForwardToHandlerOrCurrentObject(int nBank, int nSound, int nFlag);

int Ov002_TickScene(void) {
    int bIdle = 1;
    Ov002SceneCtx *ctx = data_ov002_0207f618;
    int i;
    Ov002GaugeSlot *slot;
    int *pTable;

    if (data_0204be04 != 0) {
        return 0;
    }

    if (Ov002_StepGaugePair(ctx->aTweenAState, ctx->aTweenA, 0,
                            ctx->aHandles[0]) != 0) {
        Ov002_RepaintPanelRows();
        bIdle = 0;
    }

    if (ctx->bTweenB == 1 &&
        Ov002_StepGaugePair(ctx->aTweenBState, ctx->aTweenB, 1,
                            ctx->nSurface) != 0) {
        Ov002_RepaintSubPanelRows();
    }

    if (ctx->bPromptPending != 0 && bIdle != 0) {
        Ov002_RepaintPanelRows();
    }

    if (Ov002_GetPanelField01b0() == 0) {
        slot = ctx->aSlots;
        pTable = &data_ov002_0207ddfc;

        for (i = 0; i < 4; i++) {
            if (Ov002_AdvanceGaugeSlot(i, slot) != 0) {
                ctx->bDirty = ctx->bDirty | (1 << (i + 3));
            }
            if ((ctx->bDirty & (1 << (i + 3))) != 0) {
                GFXi_EnqueueCommand(7, pTable[0], ctx->aHandles[i], pTable[1]);
            }
            if (ctx->aHold[i] != 0) {
                if (ctx->aHold[i] + 104731 < OS_GetTick()) {
                    ctx->aHold[i] = 0;
                    Ov002_UploadSlotIconPalette(i, ctx->aCounts[i].wB != 0 ? 0 : 2);
                }
            }
            slot = slot + 1;
            pTable = pTable + 3;
        }

        if ((ctx->bDirty & 2) != 0) {
            GFXi_EnqueueCommand(7, 0x5e0, ctx->nSurface, 0xc0);
        }
        ctx->bDirty = 0;
    }

    if (ctx->nSoundState != 0) {
        if (Ov002_RunShutdownHook() != 0) {
            ForwardToHandlerOrCurrentObject(0, 8, 5);
            ctx->nSoundState = 0;
        }
    } else {
        if (ctx->aSlots[0].bActive != 0 && Ov002_RunShutdownHook() == 0) {
            PlaySoundChecked(0, 8);
            ctx->nSoundState = 1;
        }
    }

    return 0;
}
