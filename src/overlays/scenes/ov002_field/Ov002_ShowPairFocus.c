/*
 * Ov002_ShowPairFocus - run the highlight cue for one half of the active pair.
 *
 * Kinds 0 and 1 own a fixed pair of cue ids, one for gaining focus and one for
 * losing it, and are looked up and played straight away. Any other kind
 * restyles the node the caller passes - 0xd focused, 0xc not - and replays it.
 *
 * ARM.
 */

#include "nitro/types.h"

extern int Ov002_ForwardToSubDc(u16 nCue);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int hCue);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_3(int hCue, u8 nStyle);

void Ov002_ShowPairFocus(int nKind, int hNode, int bOn)
{
    switch (nKind) {
    case 0:
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc((u16)(bOn ? 0x460 : 0x44c)));
        break;
    case 1:
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc((u16)(bOn ? 0x461 : 0x44d)));
        break;
    default:
        Ov002_Ctx_SetTagTrackerNodeArmed_3(hNode, (u8)(bOn ? 0xd : 0xc));
        Ov002_Ctx_InvokeTagTrackerCallback(hNode);
        break;
    }
}
