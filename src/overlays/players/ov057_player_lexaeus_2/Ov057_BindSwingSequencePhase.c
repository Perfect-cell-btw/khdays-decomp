/* Re-arms the five tracks of a swing sequence for the given phase: sets the
 * sequence state, releases every previous handle, binds each track to the
 * requested source/phase, and restarts its frame from zero. The
 * actor is not touched -- the caller passes it only because every routine in
 * the family takes it first. */

#include "nitro/types.h"

extern void NNS_G3dRenderObjRemoveAnmObj(void *p, int handle);
extern void BindAnimTrack(void *p, u16 idx, int a, short b);
extern void Anim_SetFrameWrapped(void *p, int idx, int a);

void Ov057_BindSwingSequencePhase(int pActor, int *pSwing, int phase)
{
    int trackIndex;

    switch (phase) {
    case 0:
        pSwing[0] = 1;
        break;
    case 1:
        pSwing[0] = 3;
        break;
    case 2:
        pSwing[0] = 2;
        break;
    case 3:
        pSwing[0] = 3;
        break;
    }
    for (trackIndex = 0; trackIndex < 5; trackIndex++) {
        if (pSwing[trackIndex + 4] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((char *)pSwing + 0x24, pSwing[trackIndex + 4]);
            pSwing[trackIndex + 4] = 0;
        }
        BindAnimTrack((char *)pSwing + 4, (u16)trackIndex,
                      *(int *)((char *)pSwing + 0x10c), (short)phase);
        Anim_SetFrameWrapped((char *)pSwing + 4, (u16)trackIndex, 0);
    }
}
