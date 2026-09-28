/*
 * Runs the enter handler for whichever state the session is in, then rebuilds
 * the slot token.
 *
 * Fourteen states share four handlers: three of them enter one way, one enters
 * another, five share a third, and one has its own; the rest do nothing. The
 * token is remade afterwards either way, through the installed maker and from
 * the shared request block.
 *
 * One thing here is load-bearing rather than style. The argument is threaded
 * through to every handler rather than dropped. That is what keeps it in the
 * first register across the dispatch and pushes the whole table walk one
 * register up; written with no argument the compiler starts its temporaries at
 * the first register instead and eleven bytes come out wrong.
 *
 * THUMB.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ov002RootContext {
    char pad0000[0x8b4c];
    int nSlotToken;
    char pad8b50[8];
    int nState;
    char pad8b5c[0x24];
    int (*pMake)(void *pArg);
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;
extern int data_0204c270;

extern void Ov002_SnapshotResultReport(int a);
extern void Ov002_FormatDayCounter(int a);
extern void Ov002_SetPhasePromptSelector(int a);
extern void Ov002_ResetSelectionAndFormatValue(int a);

void Ov002_DispatchStateEnter(int nArg)
{
    Ov002RootContext *pCtx;

    pCtx = data_ov002_0207fa00;
    switch (pCtx->nState) {
    case 1:
    case 5:
    case 7:
        Ov002_SnapshotResultReport(nArg);
        break;
    case 2:
        Ov002_FormatDayCounter(nArg);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        Ov002_SetPhasePromptSelector(nArg);
        break;
    case 10:
        Ov002_ResetSelectionAndFormatValue(nArg);
        break;
    }

    pCtx->nSlotToken = pCtx->pMake(&data_0204c270);
}
