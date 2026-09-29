/*
 * Ov002_StepPageClose - close the page down and hand over when it is ready.
 *
 * The teardown runs once: the tag tracker for tag 9 is armed, the fade is
 * started, and the two closing passes are kicked - the first of them only when
 * the mode word says so.
 *
 * After that, the page's completion callback is made as soon as the screen is
 * free and the caption screen accepts the request that goes with it.
 *
 * ARM.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    char pad000[4];
    int bClosing;
    char pad008[0x30];
    void (*pfnDone)(void);
} Ov002PageContext;

extern Ov002PageContext *data_ov002_0207f634;
extern u8 data_0204c240;

extern int Ov002_CancelQueuedLoads(void);
extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int nEntry, int nValue);
extern int Ov002_RequestCaption(int nMode, int nTake);
extern void Ov002_FlushPendingDraw(void);
extern void Ov002_PushScrollSpan(void);
extern int Ov002_GetSessionField14(void);

int Ov002_StepPageClose(void)
{
    Ov002PageContext *ctx;

    ctx = data_ov002_0207f634;
    if (ctx->bClosing == 0 && Ov002_GetSessionField14() != 0) {
        ctx->bClosing = 1;
        Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(9), 1);
        PlaySoundChecked(0, 0x2d);
    }

    if (data_0204c240 == 0 || (data_0204c240 & 1) != 0) {
        Ov002_PushScrollSpan();
    }
    Ov002_FlushPendingDraw();

    if (ctx->pfnDone != 0 && Ov002_CancelQueuedLoads() != 0 &&
        Ov002_RequestCaption(1, 0) != 0) {
        ctx->pfnDone();
    }
    return 0;
}
