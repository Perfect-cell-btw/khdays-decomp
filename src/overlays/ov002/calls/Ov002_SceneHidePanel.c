/*
 * Ov002_SceneHidePanel - drop the panel off screen without tearing the scene
 * down.
 *
 * The surfaces are closed, both text contexts are torn down (each only if it was
 * opened), the cursor is dismissed, and the three windows are folded away at
 * once. The scene goes back to state 0 and waits there.
 *
 * THUMB.
 */

extern int data_ov002_0207f624;

extern void FreeAllListNodeSubBuffers(void *pContext);
extern void Obj_SetField14(int nObject, void *pStep);

extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern void Ov002_ReleasePendingRequest(void);
extern void Ov002_SetTagTrackerArmed(int nValue);
extern int Ov002_PanelIdleState(void);

void Ov002_SceneHidePanel(void)
{
    int *ctx;

    ctx = *(int **)&data_ov002_0207f624;
    Ov002_ReleasePendingRequest();

    if (*(int *)((char *)ctx + 0x7b8) != 0) {
        FreeAllListNodeSubBuffers((char *)ctx + 0x6f8);
        *(int *)((char *)ctx + 0x7b8) = 0;
    }
    if (*(int *)((char *)ctx + 0x7bc) != 0) {
        FreeAllListNodeSubBuffers((char *)ctx + 0x734);
        *(int *)((char *)ctx + 0x7bc) = 0;
    }

    Ov002_SetTagTrackerArmed(0);
    Ov002_FillMapRows(0xa, 0, 0, 0x20, 0x18);
    Ov002_FillMapRows(9, 0, 0, 0x20, 0x18);
    Ov002_FillMapRows(0xb, 0, 0, 0x20, 0x18);

    ctx[0] = 0;
    Obj_SetField14(*(int *)((char *)ctx + 0x6a4), Ov002_PanelIdleState);
}
