/* Scene entry for the result screen: the context is the root heap block plus
 * 0x8ba8, and the first thing it does is free the bound slot at +0x0c. The
 * reason code at +0x02 -- a SIGNED halfword, hence the register-offset ldrsh --
 * then picks which result banner to queue. mwcc normalises the switch by adding
 * 7, which is why the ROM tests `reason + 7` against 5 unsigned and indexes a
 * six-entry halfword table.
 *
 * The case bodies are written in the order the ROM lays them out; mwcc emits
 * them in source order, so that order is evidence, not preference. */
typedef struct {
    short nUnk00;       /* +0x00 */
    short nReason;      /* +0x02 signed, -7..-2 select a banner */
    char pad04[8];
    int nBoundSlot;     /* +0x0c, -1 = free */
} Ov002ResultContext;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_EnterPhase(int banner);
extern void Ov002_DispatchStateEnter(int a);
extern void Ov002_TickResultScene(void);

void *Ov002_EnterResultScene(void) {
    Ov002ResultContext *ctx =
        (Ov002ResultContext *)((char *)NNSi_FndGetCurrentRootHeap() + 0x8ba8);

    ctx->nBoundSlot = -1;

    switch (ctx->nReason) {
    case -2:
        Ov002_EnterPhase(8);
        break;

    case -7:
        Ov002_EnterPhase(0xd);
        break;

    case -5:
        Ov002_EnterPhase(0xb);
        break;

    case -6:
        Ov002_EnterPhase(0xc);
        break;

    case -4:
    case -3:
        Ov002_EnterPhase(9);
        break;
    }

    Ov002_DispatchStateEnter(0);
    return (void *)&Ov002_TickResultScene;
}
