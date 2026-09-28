/* Ov245_BindMotion -- bind a motion: resets the actor's +0x390 track (0202a440), refreshes the
 * +0x384 item's model (+0x88, 02014b5c on its +0x20 with +0x78), attaches the pool resource
 * `index + 1` to the track (0202a388, slot 0xc), hooks the track onto the item (0203b9ac), starts
 * channel 0 with the given flag (0203b9fc) and halts the item's motion (0203c7ac). */
struct Ov245Model { char pad[0x20]; char anim[0x58]; int pool78; };

extern void FreeAllResourceTables(void *track);
extern void NNS_G3dRenderObjInit(void *anim, int pool);
extern void *Ov107_PackTextureHandle(int self, int index);
extern void Snd_RegisterSeqAndBind(void *track, struct Ov245Model *model, void *resource, int slot);
extern void MainBlob_ResetSlotRows(int item, void *track);
extern void SetSubitemState(int item, int channel, int a, int flag);
extern void RefreshObjectCallbacks(int item, int a);

void Ov245_BindMotion(int self, int index, int flag) {
    struct Ov245Model *model = *(struct Ov245Model **)(*(int *)(self + 0x384) + 0x88);

    FreeAllResourceTables((void *)(self + 0x390));
    NNS_G3dRenderObjInit(model->anim, model->pool78);
    Snd_RegisterSeqAndBind((void *)(self + 0x390), model, Ov107_PackTextureHandle(self, index + 1), 0xc);
    MainBlob_ResetSlotRows(*(int *)(self + 0x384), (void *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, flag);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
