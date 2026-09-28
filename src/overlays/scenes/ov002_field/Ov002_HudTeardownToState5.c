/* Tear the HUD context down to state 5 and hand the scene to
 * Ov002_SceneClosePanelStep.  Returns immediately if the context was never built.
 *
 * The two tiled surfaces are released with the same pair in the same order
 * (Obj_InvokeInnerVtable4 then EnqueueObjGfxCommand), the second only when the count at +0x7e0
 * is positive -- so the second surface is conditional on there being rows to
 * draw, not on a separate allocated flag.
 *
 * Note the ROM builds ctx+0x734 twice by two different routes: once as
 * 0x7e0 - 0xac (reusing the constant it just loaded for the count) and once
 * from its own pool entry.  That is mwcc rematerialising, not two addresses. */
typedef struct {
    int nState;             /* +0x000 */
    char pad04[8];
    int aSub0c[1];          /* +0x00c */
    char pad10[0x694];
    int nHandle6a4;         /* +0x6a4 */
    char pad6a8[0x50];
    int aSurfaceA[1];       /* +0x6f8 */
    char pad6fc[0x38];
    int aSurfaceB[1];       /* +0x734 */
    char pad738[0xa8];
    int nCount7e0;          /* +0x7e0 */
} Ov002HudCtx;

extern void Obj_InvokeInnerVtable4(int *p);
extern void EnqueueObjGfxCommand(int *p);
extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern void Ov002_TickTimedEffect(int *p);
extern void Ov002_MoveCursorTo(int a);
extern void Ov002_SetTagTrackerArmed(int a);
extern void Obj_SetField14(int handle, void (*callback)(void));
extern void Ov002_SceneClosePanelStep(void);

extern Ov002HudCtx *data_ov002_0207f624;

void Ov002_HudTeardownToState5(void) {
    Ov002HudCtx *ctx = data_ov002_0207f624;

    if (ctx == 0) return;

    Obj_InvokeInnerVtable4(ctx->aSurfaceA);
    EnqueueObjGfxCommand(ctx->aSurfaceA);
    Ov002_FillMapRows(0xa, 0, 0, 0x20, 0x18);
    if (ctx->nCount7e0 > 0) {
        Obj_InvokeInnerVtable4(ctx->aSurfaceB);
        EnqueueObjGfxCommand(ctx->aSurfaceB);
    }
    Ov002_TickTimedEffect(ctx->aSub0c);
    Ov002_MoveCursorTo(-1);
    Ov002_SetTagTrackerArmed(0);
    ctx->nState = 5;
    Obj_SetField14(ctx->nHandle6a4, Ov002_SceneClosePanelStep);
}
