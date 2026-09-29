/* Rebuild the +0x384 work list for the actor at *(+0x3a8): copy the const pose table to
 * a local buffer, seed the entry from *(owner+0x88), query the ov107 pose (buffer indexed
 * by +0x310), append the result, then re-init and finalize the owner list (flag from bit 0
 * of +0x311). */

#include "game/enemy_common.h"

extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
extern void SetSubitemState(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
struct Buf_020ce7fc { int w[27]; };
extern const struct Buf_020ce7fc data_ov233_020d0d9c;
struct b0_020ce7fc { unsigned char b0 : 1; };
void Ov233_RebindClip(int param_1) {
    struct Buf_020ce7fc buf = data_ov233_020d0d9c;
    int owner = *(int *)(*(int *)(param_1 + 0x3a8) + 0x88);
    FreeAllResourceTables(param_1 + 0x384);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(param_1 + 0x384, owner,
                  Ov107_PackTextureHandle((char *)param_1, buf.w[*(signed char *)(param_1 + 0x310)]), 0xc);
    MainBlob_ResetSlotRows(*(int *)(param_1 + 0x3a8), param_1 + 0x384);
    SetSubitemState(*(int *)(param_1 + 0x3a8), 0, 0,
                  ((struct b0_020ce7fc *)(param_1 + 0x311))->b0);
    RefreshObjectCallbacks(*(int *)(param_1 + 0x3a8), 0);
}
