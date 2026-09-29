/* Rebuild the +0x388 work list for the actor at *(+0x384): reset it, seed an entry
 * from the sub-object at *(owner+0x88), run the local setup + ov107 query (index+1),
 * append the result, then re-init and finalize the owner list. */
extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern int Ov225_ArmModelCallback(int a);
extern int Ov107_PackTextureHandle(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
extern void SetSubitemState(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
void Ov225_RebindClip(int param_1, int param_2, int param_3) {
    int owner = *(int *)(*(int *)(param_1 + 0x384) + 0x88);
    FreeAllResourceTables(param_1 + 0x388);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Ov225_ArmModelCallback(param_1);
    Snd_RegisterSeqAndBind(param_1 + 0x388, owner, Ov107_PackTextureHandle(param_1, param_2 + 1), 0xc);
    MainBlob_ResetSlotRows(*(int *)(param_1 + 0x384), param_1 + 0x388);
    SetSubitemState(*(int *)(param_1 + 0x384), 0, 0, param_3);
    RefreshObjectCallbacks(*(int *)(param_1 + 0x384), 0);
}
