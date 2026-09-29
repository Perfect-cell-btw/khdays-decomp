/*
 * Ov002_RequestPageAdvance - move the page on, now or as soon as it can.
 *
 * Nothing happens while a handover is already queued or the page still has work
 * of its own. Otherwise the fade is started and the advance is taken straight
 * away if the screen is free and the caption accepts it; when it is not, the
 * same step is left queued for the close step to make later.
 *
 * ARM.
 */

#include "game/engine.h"

typedef struct {
    char pad000[0x38];
    void (*pfnDone)(void);
} Ov002PageContext;

extern Ov002PageContext *data_ov002_0207f634;

extern int Ov002_CancelQueuedLoads(void);
extern int Ov002_RequestCaption(int nMode, int nTake);
extern void Ov002_ShowPanel9WithString(void);
extern int Ov002_RunShutdownHook(void);

void Ov002_RequestPageAdvance(void)
{
    Ov002PageContext *ctx;

    ctx = data_ov002_0207f634;
    if (ctx->pfnDone != 0) {
        return;
    }
    if (Ov002_RunShutdownHook() != 0) {
        return;
    }

    PlaySound(0, 1);
    if (Ov002_CancelQueuedLoads() != 0 && Ov002_RequestCaption(1, 0) != 0) {
        Ov002_ShowPanel9WithString();
    } else {
        ctx->pfnDone = Ov002_ShowPanel9WithString;
    }
}
