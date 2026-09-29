/*
 * Ov002_SetPageReady - say whether this page is ready and act on it.
 *
 * Nothing is recorded while the page is still busy, the machine is not idle or
 * the board still has work of its own. Otherwise the flag is kept for the slot
 * on screen, that slot also starts the fade, and a ready page asks the caption
 * screen for its line, playing the cue that goes with it once it is accepted.
 *
 * ARM.
 */

#include "game/engine.h"

typedef struct {
    char pad000[4];
    int nSlot;
    char pad008[0x20];
    int bReady;
} Ov002TabCtx;

extern Ov002TabCtx *data_ov002_0207f99c;

extern int Ov002_ForwardToSubDc(int nCue);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);
extern int Ov002_RequestCaption(int nMode, int nTake);
extern int Ov002_Field_IsActive(void);
extern int Ov002_RunShutdownHook(void);

void Ov002_SetPageReady(int bReady)
{
    Ov002TabCtx *ctx;

    ctx = data_ov002_0207f99c;
    if (Ov002_RunShutdownHook() != 0) {
        return;
    }
    if (PauseMenu_GetMode() != 0) {
        return;
    }
    if (Ov002_Field_IsActive() != 0) {
        return;
    }

    if (ctx->nSlot == Session_GetLocalPlayerIndex()) {
        ctx->bReady = bReady;
    }
    if (ctx->nSlot == Session_GetLocalPlayerIndex()) {
        PlaySound(0, 1);
    }

    if (bReady != 0 && Ov002_RequestCaption(0, 0) != 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x5e1));
    }
}
