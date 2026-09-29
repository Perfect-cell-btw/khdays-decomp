/* Reset the ov022 block held on the current root heap and, on a cold start
 * (mode 0), rebuild it from the sequence archive: register the archive, take
 * its list, and hand that list to the two sub-builders at +0x3c and +0xe8.
 * The mode is remembered at +0x2c. Returns the module's entry point. */

#include "game/engine.h"

extern int data_ov022_020b28e8;

extern int *NNSi_FndGetCurrentRootHeap(void);
extern void *SND_RegisterSeq(void *archive, int id);
extern void *ResSlot_Acquire(void *seq, int a);
extern void Ov022_LoadMarkerSprites(void *dst, void *list);
extern void Ov022_InitUiSubsystem(void *dst, void *list);
extern void ResSlot_Release(void *seq);
extern void func_ov022_020840e0(void);

void *Ov022_ResetAndBuildFromSeqArchive(int mode) {
    int *ctx = NNSi_FndGetCurrentRootHeap();

    ctx[0] = 0x2a;
    ctx[1] = 0;
    ctx[0x30 / 4] = 0;
    ctx[0x34 / 4] = 0;
    ctx[0x38 / 4] = 0;

    if (mode == 0) {
        void *seq = SND_RegisterSeq(&data_ov022_020b28e8, 0xf);
        void *list;

        InstallHandlerPairByFlag(0);
        list = ResSlot_Acquire(seq, 1);
        InstallHandlerPairByFlag(1);
        Obj_GetIndirectWord(list, 7);
        Ov022_LoadMarkerSprites((char *)ctx + 0x3c, list);
        Ov022_InitUiSubsystem((char *)ctx + 0xe8, list);
        ResSlot_Release(seq);
    }

    ctx[0x2c / 4] = (mode != 0) ? 1 : 0;
    ctx[0x230 / 4] = 0;
    return (void *)&func_ov022_020840e0;
}
