/* Character constructor: builds the rig object, initialises the effect slots unless in the mode
 * that has none, requests its two voice ids and returns the decoder step. */

#include "game/engine.h"

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov074_BuildRigObject(int a);
extern void Ov074_InitEffectSlotsWithTimings(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov074_stateCtorCondConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov074_BuildRigObject(param);
    if (LoadGlobalU16At0() != 0x2a)
        Ov074_InitEffectSlotsWithTimings(obj);
    Ov022_RequestVoiceIds(obj, 0x47, 0xd3);
    return (void *)Ov022_ArmDecoder;
}
