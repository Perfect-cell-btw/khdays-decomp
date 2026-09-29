/* Scene entry for the four-row list: take the root heap block as the context,
 * open the archive named by data_ov022_020b290c, and give each of the four rows
 * its resource -- but only for the rows GameState_IsFlagSet(0x20ee) admits, and the
 * bFirst flag tells Ov002_Slot_SetCellData which admitted row is the first one.
 * Every row clears its own resource pointer first, so a rejected row keeps null.
 * Ten interpolators are initialised: two per row, plus header, footer and cursor.
 * The archive handle is a scratch buffer and is freed before returning the next
 * scene step.
 *
 * Ov002_Slot_SetCellData is declared with FOUR parameters here even though its own
 * matched body only reads two -- this call site sets r0..r3, and a callee's body
 * can never settle its arity, only its callers can. */

#include "game/engine.h"

typedef struct {
    char pad00[0x2c];
    void *pResource;        /* +0x2c -- what Ov002_Slot_SetCellData stores */
} Ov022Row;                 /* 0x30 */

typedef struct {
    Ov022Row rows[4];       /* +0x000 */
    unsigned char bReady;   /* +0x0c0 */
    char padc1[7];
    int tweenHeader[7];     /* +0x0c8 */
    int tweenFooter[7];     /* +0x0e4 */
    int aRowTweenA[4][7];    /* +0x100 */
    int aRowTweenB[4][7];    /* +0x170 */
    int tweenCursor[7];     /* +0x1e0 */
} Ov022RootContext;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern char *Msg_BuildLangPath(char *path);
extern void *Archive_LoadFile(char *path, int heap);
extern int Ov002_Slot_SetCellData(Ov022Row *row, void *arc, int bFirst, int index);
extern void Tween_Clear(void *tween);
extern void Ov022_AdvanceFadeStateThenNextStep(void);

extern void *data_ov022_020b2e74;
extern char data_ov022_020b290c[];

void *Ov022_EnterFourRowScene(void) {
    Ov022RootContext *ctx = NNSi_FndGetCurrentRootHeap();
    void *arc;
    int bFirst = 1;
    int i;

    (&data_ov022_020b2e74)[0] = ctx;
    ctx->bReady = 0;
    arc = Archive_LoadFile(Msg_BuildLangPath(data_ov022_020b290c), 0xf);
    InstallHandlerPairByFlag(0);
    G3dRes_DefaultSetup(arc);
    InstallHandlerPairByFlag(1);
    for (i = 0; i < 4; i++) {
        ctx->rows[i].pResource = 0;
        Tween_Clear(ctx->aRowTweenA[i]);
        Tween_Clear(ctx->aRowTweenB[i]);
        if (GameState_IsFlagSet(0x20ee) == 0) {
            Ov002_Slot_SetCellData(&ctx->rows[i], arc, bFirst, i);
            bFirst = 0;
        }
    }
    Tween_Clear(ctx->tweenHeader);
    Tween_Clear(ctx->tweenFooter);
    Tween_Clear(ctx->tweenCursor);
    NNSi_FndFreeFromDefaultHeap(arc);
    return (void *)&Ov022_AdvanceFadeStateThenNextStep;
}
