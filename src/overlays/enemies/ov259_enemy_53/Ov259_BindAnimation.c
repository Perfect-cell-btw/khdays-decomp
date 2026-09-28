/* Bind an animation to one of the ov259 actor's items: the `work` list is reset (0202a440), the
 * item's +0x88 animation set rewinds (02014b5c), the list is refilled with pose `poseIndex` of the
 * actor's pool (0202a388) and attached to the item, which starts on channel 0 (looping per bit 0 of
 * the actor's +0x311) and is re-initialised. */
#include "nitro/types.h"
struct Flag311 { u8 loop : 1; };

extern void FreeAllResourceTables(void *list);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern void Snd_RegisterSeqAndBind(void *list, int b, void *c, int d);
extern void MainBlob_ResetSlotRows(int item, void *list);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);

void Ov259_BindAnimation(char *self, int item, void *work, int poseIndex)
{
    int anim = *(int *)(item + 0x88);

    FreeAllResourceTables(work);
    NNS_G3dRenderObjInit(anim + 0x20, *(int *)(anim + 0x78));
    Snd_RegisterSeqAndBind(work, anim, Ov107_PackTextureHandle(self, poseIndex), 0xc);
    MainBlob_ResetSlotRows(item, work);
    SetSubitemState(item, 0, 0, ((struct Flag311 *)(self + 0x311))->loop);
    RefreshObjectCallbacks(item, 0);
}
