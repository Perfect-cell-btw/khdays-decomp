/* Rebuild the two rider work lists (+0x388 for the +0x384 rider, +0x390 for the +0x38c one)
 * for pose slot `slot`: copy the const pose table to a local buffer, seed each entry from the
 * rider's *(+0x88) owner, query the +0x394 pool for the slot's pose, append it, clear the
 * owner's five +2 / +0xca halfword pairs, bind the rider to its list with channel 0 = (0, flag),
 * then run the 020cda7c hook and re-init both riders. */

#include "game/enemy_common.h"

extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
extern void SetSubitemState(int a, int b, int c, int d);
extern void Ov236_RiderPresenceHook(int self);
extern void RefreshObjectCallbacks(int a, int b);
struct Buf17 { int w[17]; };
extern const struct Buf17 data_ov236_020d6328;

void Ov236_RebuildRiderListsA(int self, int slot, int flag) {
    struct Buf17 buf = data_ov236_020d6328;
    int i;
    int owner;
    int kind;

    FreeAllResourceTables(*(int *)(self + 0x388));
    owner = *(int *)(*(int *)(self + 0x384) + 0x88);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    kind = buf.w[slot];
    Snd_RegisterSeqAndBind(*(int *)(self + 0x388), owner, Ov107_PackTextureHandle((char *)(*(int *)(self + 0x394)), kind), 0xc);
    for (i = 0; i < 5; i++) {
        ((short *)owner)[i + 1] = -1;
        ((short *)owner)[i + 0x65] = -1;
    }
    MainBlob_ResetSlotRows(*(int *)(self + 0x384), *(int *)(self + 0x388));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, flag);

    FreeAllResourceTables(*(int *)(self + 0x390));
    owner = *(int *)(*(int *)(self + 0x38c) + 0x88);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(*(int *)(self + 0x390), owner, Ov107_PackTextureHandle((char *)(*(int *)(self + 0x394)), kind), 0xc);
    for (i = 0; i < 5; i++) {
        ((short *)owner)[i + 1] = -1;
        ((short *)owner)[i + 0x65] = -1;
    }
    MainBlob_ResetSlotRows(*(int *)(self + 0x38c), *(int *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x38c), 0, 0, flag);

    Ov236_RiderPresenceHook(self);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    RefreshObjectCallbacks(*(int *)(self + 0x38c), 0);
}
