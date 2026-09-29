/* Rebind the ov146 actor's +0x388 animation slot to record `id` + 0xc of its +0x3b4 set in the +0x384
 * rig's +0x88 bank, then play layer 0 (and layer 2 for kinds 8/9, +0x310) with `loop` and reset the
 * rig pose. */
typedef struct { char data[0x24]; } AnimSlot;

extern void FreeAllResourceTables(AnimSlot *slot);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void *Ov107_PackTextureHandle(int set, int index);
extern void Snd_RegisterSeqAndBind(AnimSlot *slot, int bank, void *record, int d);
extern void MainBlob_ResetSlotRows(int rig, AnimSlot *slot);
extern void SetSubitemState(int rig, int channel, int a, int b);
extern void RefreshObjectCallbacks(int rig, int a);

void Ov146_RebindAnimSlot(char *actor, int id, int loop)
{
    int bank = *(int *)(*(int *)(actor + 0x384) + 0x88);

    FreeAllResourceTables((AnimSlot *)(actor + 0x388));
    NNS_G3dRenderObjInit(bank + 0x20, *(int *)(bank + 0x78));
    Snd_RegisterSeqAndBind((AnimSlot *)(actor + 0x388), bank, Ov107_PackTextureHandle(*(int *)(actor + 0x3b4), id + 0xc), 0xc);
    MainBlob_ResetSlotRows(*(int *)(actor + 0x384), (AnimSlot *)(actor + 0x388));
    SetSubitemState(*(int *)(actor + 0x384), 0, 0, loop);
    if (!(*(signed char *)(actor + 0x310) != 8 && *(signed char *)(actor + 0x310) != 9)) {
        SetSubitemState(*(int *)(actor + 0x384), 2, 0, loop);
    }
    RefreshObjectCallbacks(*(int *)(actor + 0x384), 0);
}
