/*
 * Ov002_SceneReopenPanel - bring the panel back up after the caller changed
 * what it should show.
 *
 * Nothing happens if the scene is gone. A request pointer, when one is given,
 * is applied first. The window is then reopened at 0x20 wide, the caption box
 * takes a fresh tile buffer and is uploaded, and the entry box does the same
 * when there is anything in it. The pen is put back to the top left.
 *
 * Where it goes from there depends on whether the caller asked for a picture:
 * without one the scene loads the tile set for the picture slot and moves to
 * state 1; with one the surface is built (once) and the scene moves to state 2.
 * Either way the step that follows is armed and the entry either side of the
 * panel is selected.
 *
 * THUMB.
 */

extern int data_ov002_0207f624;
extern int data_ov002_0207eb28[];

extern void TileSurface_InitAndUpload4bpp(void *pSurface, const void *pConfig);
extern void EnqueueObjGfxCommand(void *pSurface);
extern void Obj_SetField14(int nObject, void *pStep);

extern void Ov002_InitSurfaceContext(void *pSurface, int nKind, int nSize, int a0,
                                int a1, int a2, int a3, int nBufferA,
                                int nBufferB, void *pSource, int nLast);
extern void Ov002_AppendEntry(int nFile, void *pStep, int nValue);
extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern int Ov002_GetItemResource(int nId);
extern void Ov002_SelectEntry(int nId);
extern void Ov002_SceneOpenPanelSurface(void *pNode);
extern int Ov002_PanelIdleState_2(void);
extern int Ov002_SceneOpenPanelStep(void);
extern void Ov002_Scene_ApplyPanelRequestIfAny(void *pRequest, int *pScene);

void Ov002_SceneReopenPanel(void *pRequest)
{
    void *pSource;
    int *p;
    int nBufferA;
    int *ctx;
    int nBufferB;

    ctx = *(int **)&data_ov002_0207f624;
    if (ctx == 0) {
        return;
    }

    if (pRequest != 0) {
        Ov002_Scene_ApplyPanelRequestIfAny(pRequest, &data_ov002_0207f624);
    }
    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));
    Ov002_FillMapRows(9, 0, 0, 0x20, 0x20);

    *(int *)((char *)ctx + 0x6c0) = Ov002_GetItemResource(9);
    TileSurface_InitAndUpload4bpp((char *)ctx + 0x6f8, (char *)ctx + 0x6a8);
    EnqueueObjGfxCommand((char *)ctx + 0x6f8);
    *(int *)((char *)ctx + 0x7b8) = 1;

    if (*(int *)((char *)ctx + 0x7e0) > 0) {
        *(int *)((char *)ctx + 0x6e8) = Ov002_GetItemResource(9);
        TileSurface_InitAndUpload4bpp((char *)ctx + 0x734, (char *)ctx + 0x6d0);
        EnqueueObjGfxCommand((char *)ctx + 0x734);
        *(int *)((char *)ctx + 0x7bc) = 1;
    }

    Ov002_SelectEntry(9);
    pSource = 0;
    *(int *)((char *)ctx + 0x7d0) = 0;
    *(int *)((char *)ctx + 0x7d4) = 0;
    *(int *)((char *)ctx + 0x7d8) = 0;

    if (*(int *)((char *)ctx + 0x664) != 0) {
        p = (int *)((char *)ctx + 0x668);
        if (*(int *)((char *)ctx + 0x660) == 0) {
            if (p[9] != 0) {
                pSource = p + 10;
            }
            nBufferA = Ov002_GetItemResource(0xb);
            nBufferB = Ov002_GetItemResource(10);
            Ov002_InitSurfaceContext((char *)ctx + 0xc, 3, 0, p[0], p[1], p[2], p[3],
                                nBufferA, nBufferB, pSource, 0xe);
            *(int *)((char *)ctx + 0x660) = 1;
        }
        ctx[0] = 2;
        Obj_SetField14(*(int *)((char *)ctx + 0x6a4), Ov002_SceneOpenPanelStep);
    } else {
        Ov002_AppendEntry(data_ov002_0207eb28[*(int *)((char *)ctx + 0x67c)],
                            Ov002_SceneOpenPanelSurface, 0);
        ctx[0] = 1;
        Obj_SetField14(*(int *)((char *)ctx + 0x6a4), Ov002_PanelIdleState_2);
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
}
