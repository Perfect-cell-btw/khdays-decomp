/*
 * Enters a phase: normalises the mode the caller asked for, records it, and
 * runs whatever that phase needs on the way in.
 *
 * Mode six becomes two while the boot-mode flag is set. The recorded phase is
 * the mode itself, except that three and four both settle on five and six on
 * two. From there the phase picks its entry work: the three that come up
 * through the same route silence two cues and arm the first screen, two arms
 * the second, the five that share the tail clear the three phase cues before
 * arming, ten silences the cues and arms its own, and anything else falls to
 * the default. The common tail runs either way.
 *
 * One thing here is load-bearing rather than style. The two modes that settle
 * on five jump to a label placed after the six case rather than sharing an
 * `if`. Written as one condition the compiler turns the pair into a range test
 * and the function comes out four bytes short; written as two `if`s with the
 * store inline it comes out four bytes long. Only the jump gives the original's
 * layout, where the five case is emitted last and reloads its own offset.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct Ov002RootContext {
    char pad0000[0x8b58];
    int nPhase;
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;
extern u8 data_0204c240;
extern u8 gPartyState;
extern u8 data_0204c4f2;
extern u8 data_0204c4f3;
extern int data_ov002_0207efcc;

extern void Ov002_ArmPromptButtons(int nMode);
extern void GameState_SetField(int nId, int a, int b);
extern void Ov002_BringUpMissionOverlays(void);
extern void Ov002_EnterOverlay23(void);
extern void Ov002_EnterOverlay24(void);
extern void Ov002_LoadSubFlowOverlay(int nPhase);
extern void Ov002_ClearRosterRow(void);
extern void Ov002_CreateOverlayObjectOutsidePhases(void);
extern void ModelFile_LoadFirst(void *pArg);

void Ov002_EnterPhase(int nMode)
{
    Ov002RootContext *pCtx;

    pCtx = data_ov002_0207fa00;
    if (nMode == 6 && (data_0204c240 & 4) != 0) {
        nMode = 2;
    }

    Ov002_ArmPromptButtons(nMode);
    pCtx->nPhase = nMode;
    if (nMode == 3) {
        goto five;
    }
    if (nMode == 4) {
        goto five;
    }
    if (nMode == 6) {
        pCtx->nPhase = 2;
    }
    goto dispatch;
five:
    pCtx->nPhase = 5;
dispatch:

    switch (pCtx->nPhase) {
    case 1:
    case 5:
    case 7:
        GameState_SetField(0x2484, 1, 0);
        GameState_SetField(0x248f, 1, 0);
        Ov002_BringUpMissionOverlays();
        ModelFile_LoadFirst(&data_ov002_0207efcc);
        break;

    case 2:
        Ov002_EnterOverlay23();
        ModelFile_LoadFirst(&data_ov002_0207efcc);
        break;

    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        gPartyState = 0;
        data_0204c4f3 = 0;
        data_0204c4f2 = 0;
        Ov002_LoadSubFlowOverlay(pCtx->nPhase);
        break;

    case 10:
        GameState_SetField(0x2484, 1, 0);
        GameState_SetField(0x248f, 1, 0);
        Ov002_EnterOverlay24();
        break;

    default:
        Ov002_ClearRosterRow();
        break;
    }

    Ov002_CreateOverlayObjectOutsidePhases();
}
