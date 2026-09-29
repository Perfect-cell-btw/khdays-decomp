/* Rebuild the two rider work lists (+0x38c for the +0x384 rider, +0x390 for the +0x388 one) for
 * move `slot`: copy the const 23-entry pose table to a local buffer, seed each list from the
 * rider's *(+0x88) owner, append the slot's pose from the actor's pool (020c9440), bind the rider
 * with channel 0 = (0, flag) and re-init it. Moves 0xd / 0xe / 0xf show the +0x3b0 prop's +0x28
 * rig (clear +0x5c bit 1) and set its channels 0, 2, 4, 1 to (0, 0), (1, 1) or (2, 0); any other
 * move hides it. Unless the move is 0xd or 0xe, the +0x3c4 effect is released and cleared. */

#include "game/enemy_common.h"

extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
extern void SetSubitemState(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
struct Buf23 { int w[23]; };
extern const struct Buf23 data_ov278_020d626c;

void Ov278_PlayRiderMove(int self, int slot, int flag) {
    struct Buf23 buf = data_ov278_020d626c;
    int owner;
    int kind;
    int rig;

    FreeAllResourceTables(*(int *)(self + 0x38c));
    owner = *(int *)(*(int *)(self + 0x384) + 0x88);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    kind = buf.w[slot];
    Snd_RegisterSeqAndBind(*(int *)(self + 0x38c), owner, Ov107_PackTextureHandle((char *)self, kind), 0xc);
    MainBlob_ResetSlotRows(*(int *)(self + 0x384), *(int *)(self + 0x38c));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, flag);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);

    FreeAllResourceTables(*(int *)(self + 0x390));
    owner = *(int *)(*(int *)(self + 0x388) + 0x88);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(*(int *)(self + 0x390), owner, Ov107_PackTextureHandle((char *)self, kind), 0xc);
    MainBlob_ResetSlotRows(*(int *)(self + 0x388), *(int *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x388), 0, 0, flag);
    RefreshObjectCallbacks(*(int *)(self + 0x388), 0);

    if (slot == 0xd) {
        rig = *(int *)(*(int *)(self + 0x3b0) + 0x28);
        *(int *)(rig + 0x5c) &= ~2;
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 0, 0, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 2, 0, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 4, 0, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 1, 0, 0);
    } else if (slot == 0xe) {
        rig = *(int *)(*(int *)(self + 0x3b0) + 0x28);
        *(int *)(rig + 0x5c) &= ~2;
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 0, 1, 1);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 2, 1, 1);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 4, 1, 1);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 1, 1, 1);
    } else if (slot == 0xf) {
        rig = *(int *)(*(int *)(self + 0x3b0) + 0x28);
        *(int *)(rig + 0x5c) &= ~2;
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 0, 2, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 2, 2, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 4, 2, 0);
        SetSubitemState(*(int *)(*(int *)(self + 0x3b0) + 0x28), 1, 2, 0);
    } else {
        *(int *)(*(int *)(*(int *)(self + 0x3b0) + 0x28) + 0x5c) |= 2;
    }

    if (slot != 0xd && slot != 0xe && *(int *)(self + 0x3c4) != 0) {
        Ov107_UnlinkNodeFromOwner((void *)(*(int *)(self + 0x3c4)));
        *(int *)(self + 0x3c4) = 0;
    }
}
