/*
 * Ov002_ScenePanelIdleStep - the panel's per-frame step once it is open.
 *
 * The entry lines are redrawn and the caption box flushed every frame. B closes
 * the panel outright. A on a panel that has entries opens the entry it is on.
 * Anything that dismisses an empty panel - A, B or start - closes the window
 * instead, plays the sound that goes with what was on screen, and lets the
 * closing step take over.
 *
 * ARM.
 */

typedef unsigned short u16;

extern int data_ov002_0207f624;
extern u16 data_0204c190;

extern void EnqueueObjGfxCommand(void *pSurface);
extern void PlaySound(int nId, int nKind);

extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern void Ov002_SceneDrawEntryLines(void);
extern void Ov002_StepCursorWrapping(void);
extern void Ov002_StepCursorWrappingBack(void);
extern void Ov002_LatchPendingPayload(void);

void *Ov002_ScenePanelIdleStep(void)
{
    int *ctx;
    int nButtons;
    int nCount;

    ctx = *(int **)&data_ov002_0207f624;
    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));
    Ov002_SceneDrawEntryLines();
    EnqueueObjGfxCommand((char *)ctx + 0x6f8);

    nButtons = data_0204c190;
    if (nButtons & 0x40) {
        Ov002_StepCursorWrappingBack();
    } else {
        nCount = *(int *)((char *)ctx + 0x7e0);
        if (nCount > 0 && (nButtons & 0x80)) {
            Ov002_StepCursorWrapping();
        } else if ((nButtons & 1) || (nCount == 0 && (nButtons & 0x82))) {
            Ov002_FillMapRows(9, 0, 0, 0x20, 0x18);
            Ov002_LatchPendingPayload();
            PlaySound(0, *(int *)((char *)ctx + 0x7e0) > 0 ? 1 : 0xa);
        }
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
    return 0;
}
