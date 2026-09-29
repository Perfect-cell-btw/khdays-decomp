/* Rebuild the +0x394 work list for the actor at *(+0x384): reset it, seed the entry
 * from *(owner+0x88), query the ov107 pose (index at +0x310, +1), append the result,
 * then re-init and finalize the owner list (flag from bit 0 of +0x311). */

#include "game/enemy_common.h"

extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
extern void SetSubitemState(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
struct b0_020cc4d8 { unsigned char b0 : 1; };
void Ov263_RebindClip(int param_1) {
    int owner = *(int *)(*(int *)(param_1 + 0x384) + 0x88);
    FreeAllResourceTables(param_1 + 0x394);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(param_1 + 0x394, owner,
                  Ov107_PackTextureHandle((char *)param_1, *(signed char *)(param_1 + 0x310) + 1), 0xc);
    MainBlob_ResetSlotRows(*(int *)(param_1 + 0x384), param_1 + 0x394);
    SetSubitemState(*(int *)(param_1 + 0x384), 0, 0,
                  ((struct b0_020cc4d8 *)(param_1 + 0x311))->b0);
    RefreshObjectCallbacks(*(int *)(param_1 + 0x384), 0);
}
