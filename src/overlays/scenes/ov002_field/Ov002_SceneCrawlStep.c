/*
 * Ov002_SceneCrawlStep - the step that types the crawl out and then moves on.
 *
 * The entry the scene names first is selected, and while any of the three
 * blocking hardware flags is up nothing happens but the idle wait. Otherwise a
 * fade of kind 2 with its low bit set stops the frame, and when it does not, one
 * character is typed. The frame the crawl reports finished the screen is either
 * rebuilt around the current entry and its tag tracker armed, or - when there is
 * nothing left to draw - the tracker is armed on its own; either way the scene
 * moves to state 4 and hands back the step that runs from there. The object
 * graphics block is queued unless the crawl asked to be left alone, and the entry
 * the scene names second is selected on the way out.
 *
 * ARM. Twin of Ov002_SceneOpenPanelStep, which hands this step back.
 */

#include "game/engine.h"

extern int data_ov002_0207f624;
extern unsigned short data_0204c190;

extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_WaitThenPlayIdle(void);
extern int Ov002_StepCrawlChar(int nCount);
extern void Ov002_SceneDrawEntryLines(void);
extern void Ov002_MoveCursorTo(int nEntry);
extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_6(int nEntry, int nKey);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int nEntry, int bArmed);
extern void Ov002_SetTagTrackerArmed(int bArmed);
extern void EnqueueObjGfxCommand(int nBlock);
extern int Ov002_ScenePanelIdleStep(void);

void *Ov002_SceneCrawlStep(void)
{
    /* The declaration order is load-bearing: mwccarm hands out the
     * callee-saved registers by rank here, and the context must not
     * come first. */
    void *pNext;
    int *ctx;
    int nEntry;

    pNext = 0;
    ctx = *(int **)&data_ov002_0207f624;
    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));

    if ((data_0204c190 & 0x83) != 0) {
        Ov002_WaitThenPlayIdle();
    } else {
        if (func_02023c40() != 2 || (func_02023c50() & 1) == 0) {
            if (Ov002_StepCrawlChar(1) == 0) {
                if (ctx[0x1f8] > 0) {
                    Ov002_SceneDrawEntryLines();
                    Ov002_MoveCursorTo(ctx[0x1f7]);
                    nEntry = Ov002_Ctx_FindActiveEntryByTag(0xd);
                    Ov002_Ctx_SetTagTrackerNodeArmed_6(nEntry, *(int *)((char *)ctx + 0x69c));
                    Ov002_Ctx_SetTagTrackerNodeArmed_5(nEntry, 1);
                } else {
                    Ov002_SetTagTrackerArmed(1);
                }
                pNext = Ov002_ScenePanelIdleStep;
                ctx[0] = 4;
            }
            EnqueueObjGfxCommand((int)((char *)ctx + 0x6f8));
        }
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
    return pNext;
}
