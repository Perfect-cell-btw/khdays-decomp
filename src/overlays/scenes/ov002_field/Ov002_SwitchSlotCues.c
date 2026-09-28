/*
 * Ov002_SwitchSlotCues - hand the pair cues over from one slot to the other.
 *
 * The table holds two cue pairs: the one the slot being left answers to and
 * the one the slot being entered answers to, each indexed by slot. When the
 * caller asks for them to be heard, the outgoing slot's cue is played first
 * and the incoming slot's second. The new slot is recorded either way.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    int a[2];
} Ov002CuePair;

typedef struct {
    int nUnk00;
    int nUnk04;
    Ov002CuePair leave;
    Ov002CuePair enter;
} Ov002CueTable;

extern const Ov002CueTable data_ov002_0207e460;
extern int *data_ov002_0207f9f0;

extern int Ov002_ForwardToSubDc(int nCue);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int hCue);

void Ov002_SwitchSlotCues(int nSlot, int bPlay)
{
    Ov002CuePair enter;
    Ov002CuePair leave;
    int *ctx;

    ctx = data_ov002_0207f9f0;
    enter = data_ov002_0207e460.enter;
    leave = data_ov002_0207e460.leave;
    if (bPlay != 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc((u16)leave.a[ctx[2]]));
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc((u16)enter.a[nSlot]));
    }
    ctx[2] = nSlot;
}
