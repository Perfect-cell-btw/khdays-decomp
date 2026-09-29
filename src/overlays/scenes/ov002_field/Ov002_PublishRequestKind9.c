/* Publish request kind 9 to the display list at +0xbc with priority 8 and mask
 * 0xf, then raise the scene's pending event 0x48 and close the request. Does
 * nothing at all while the object at +0x4c is absent -- and note the handle is
 * fetched BEFORE that check, which is why the ROM calls Ov002_GetItemResource
 * ahead of loading the context. */

#include "game/engine.h"

typedef struct {
    char pad00[0x4c];
    int pTarget;            /* +0x4c */
    char pad50[0x6c];
    int aDisplayList[1];    /* +0xbc */
} Ov002PanelContext;

extern int Ov002_GetItemResource(int kind);
extern void Ov002_TakeLock(int a);
extern int Ov002_ForwardToSubDc(int event);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int);
extern void Ov002_SelectEntry(int kind);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_PublishRequestKind9(void) {
    int handle = Ov002_GetItemResource(9);
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (ctx->pTarget == 0) {
        return;
    }

    Draw_ScaledValue(ctx->aDisplayList, handle, 8, 0, 0xf);
    Ov002_TakeLock(1);
    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x48));
    Ov002_SelectEntry(9);
}
