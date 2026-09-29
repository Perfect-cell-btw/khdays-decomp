/*
 * Ov002_SceneOpenPanelStep - the step that waits for the fade and then puts the
 * panel on screen.
 *
 * Nothing happens while a fade of kind 2 is still running. Once it is clear the
 * two entries either side of the panel are selected, the surface is brought up
 * and the two scratch buffers are released. Only when the surface reports state
 * 3 is the scene moved on: the window is opened at 0x20 wide and the scene hands
 * back the step that runs from there.
 *
 * ARM.
 */

#include "game/engine.h"

extern int data_ov002_0207f624;

extern void Ov002_StepSurfaceReveal(void *pSurface);
extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern void Ov002_SelectEntry(int nId);
extern int Ov002_SceneCrawlStep(void);

void *Ov002_SceneOpenPanelStep(void)
{
    int *ctx;
    void *pNext;

    pNext = 0;
    ctx = *(int **)&data_ov002_0207f624;
    if (GetFrameRateMode() == 2 && (Obj_GetFrameCount() & 1) == 1) {
        return 0;
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));
    Ov002_StepSurfaceReveal((char *)ctx + 0xc);
    Ov002_SelectEntry(0xa);
    Ov002_SelectEntry(0xb);

    if (ctx[3] == 3) {
        Ov002_FillMapRows(9, 0, 0, 0x20, 4);
        ctx[0] = 3;
        pNext = Ov002_SceneCrawlStep;
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
    return pNext;
}
