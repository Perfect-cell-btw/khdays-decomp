/* Reset the menu root back to state 1: re-init the sub-object at +0xdc, and if a
 * slot is still bound at +0xbc release it three ways and mark it free (-1). When
 * the secondary object at +0x04 is absent, run Ov002_FlushDirtyMaps first. Always
 * reports 0.
 *
 * The bound slot is read twice rather than cached -- that is the ROM, and the
 * second read is what keeps the two release calls in the same register. */
typedef struct {
    int nState;             /* +0x00 */
    int pSecondary;         /* +0x04 */
    char pad08[0xb4];
    int nBoundSlot;         /* +0xbc, -1 = free */
    char padc0[0x1c];
    int aSubObject[1];      /* +0xdc */
} Ov002MenuRoot;

extern void Ov002_TickSelectionWidget(void *sub);
extern void Ov002_PushMapSnapshot(int slot);
extern void Ov002_SelectEntryByKey(int slot);
extern void Ov002_World_ClearSelection(void);
extern void Ov002_FlushDirtyMaps(void);
extern void Ov002_AgeDeferredFrees(void);

extern Ov002MenuRoot *data_ov002_0207f60c;

int Ov002_ResetMenuRoot(void) {
    Ov002MenuRoot *ctx = data_ov002_0207f60c;

    Ov002_TickSelectionWidget(ctx->aSubObject);

    if (ctx->nBoundSlot >= 0) {
        Ov002_PushMapSnapshot(ctx->nBoundSlot);
        Ov002_SelectEntryByKey(ctx->nBoundSlot);
        Ov002_World_ClearSelection();
        ctx->nBoundSlot = -1;
    }

    if (ctx->pSecondary == 0) {
        Ov002_FlushDirtyMaps();
    }

    ctx->nState = 1;
    Ov002_AgeDeferredFrees();
    return 0;
}
