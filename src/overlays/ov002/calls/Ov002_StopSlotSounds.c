/*
 * Ov002_StopSlotSounds - silence every sound one slot owns.
 *
 * The slot's list of handles hangs off the context, and how many entries it
 * has is fixed per slot by the table. Each handle is played out and then
 * released. A caller that does not want the slot silenced is answered with
 * nothing done.
 *
 * ARM.
 */

typedef struct {
    int a[2];
} Ov002SlotPair;

typedef struct {
    Ov002SlotPair counts;
    Ov002SlotPair leave;
    Ov002SlotPair enter;
} Ov002CueTable;

typedef struct {
    char pad000[0x8c];
    int *aLists[2];
} Ov002SlotCtx;

extern const Ov002CueTable data_ov002_0207e460;
extern Ov002SlotCtx *data_ov002_0207f9f0;

extern void Ov002_Ctx_InvokeTagTrackerCallback(int hCue);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_4(int hCue, int nArg);

void Ov002_StopSlotSounds(int nSlot, int bStop)
{
    Ov002SlotPair counts;
    Ov002SlotCtx *ctx;
    int i;

    ctx = data_ov002_0207f9f0;
    counts = data_ov002_0207e460.counts;
    if (bStop == 0) {
        return;
    }
    for (i = 0; i < counts.a[nSlot]; i++) {
        Ov002_Ctx_InvokeTagTrackerCallback(ctx->aLists[nSlot][i]);
        Ov002_Ctx_SetTagTrackerNodeArmed_4(ctx->aLists[nSlot][i], 0);
    }
}
