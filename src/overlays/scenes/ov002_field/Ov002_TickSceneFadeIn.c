/*
 * Ov002_TickSceneFadeIn - one frame of the scene's fade-in state.
 *
 * The mirror of Ov002_TickSceneFadeOut. Does nothing while bit 2 of the
 * context flags is set. Otherwise it winds the fade timer at +0x04 down by the
 * per-frame step, runs the scene update, and once the timer drops to 0x100 or
 * below it clears bit 1, selects Ov002_BeginSceneSetup as the next state and -
 * unless bit 3 says otherwise - blanks the main screen. It then pushes the
 * master brightness at +0x08 to the sub screen under the same bit 3, winds
 * that brightness down and clamps it at -0x10000.
 *
 * ARM. As in the fade-out, the result is seeded to null before the guard so
 * both exits return the same register, which is what makes the guard a
 * predicated early return.
 */

#include "game/engine.h"

typedef void (*Ov002StateFn)(void);

extern void Ov002_UpdateSceneFrame(void); /* per-frame scene update */
extern void Ov002_GetBootModeStep(void); /* the state entered once faded in */

extern int data_ov002_0207f600;        /* slot holding the scene context */

Ov002StateFn Ov002_TickSceneFadeIn(void)
{
    Ov002StateFn pNext;
    int nStep;

    pNext = 0;
    if ((*(unsigned int *)data_ov002_0207f600 & 4) != 0) {
        return pNext;
    }

    nStep = func_02023c40() == 1 ? 0xc00 : 0x800;
    *(int *)(data_ov002_0207f600 + 4) =
        *(int *)(data_ov002_0207f600 + 4) - nStep;
    Ov002_UpdateSceneFrame();

    if (*(int *)(data_ov002_0207f600 + 4) <= 0x100) {
        *(unsigned int *)data_ov002_0207f600 =
            *(unsigned int *)data_ov002_0207f600 & ~2;
        pNext = Ov002_GetBootModeStep;
        if ((*(unsigned int *)data_ov002_0207f600 & 8) == 0) {
            SetMasterBrightnessMain(-0x10);
        }
    }

    if ((*(unsigned int *)data_ov002_0207f600 & 8) == 0) {
        SetMasterBrightnessSub(*(int *)(data_ov002_0207f600 + 8) >> 12);
    }

    nStep = func_02023c40() == 1 ? 0x3000 : 0x1800;
    *(int *)(data_ov002_0207f600 + 8) =
        *(int *)(data_ov002_0207f600 + 8) - nStep;
    if (*(int *)(data_ov002_0207f600 + 8) < -0x10000) {
        *(int *)(data_ov002_0207f600 + 8) = -0x10000;
    }
    return pNext;
}
