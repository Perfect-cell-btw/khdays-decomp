/* Append a work-list entry (param_3) seeded from the owner sub-object at *(+0x88): reset
 * it, clear +0xc, bind the owner list, register the entry with tag param_2 and bind it to
 * the owner. No-op when param_2 is 0. */
extern void FreeAllResourceTables(int a);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int a, int b, int c, int d);
extern void MainBlob_ResetSlotRows(int a, int b);
void Ov257_AppendWorkEntry(int param_1, int param_2, int param_3) {
    int owner;
    if (param_2 == 0) return;
    FreeAllResourceTables(param_3);
    *(int *)(param_3 + 0xc) = 0;
    owner = *(int *)(param_1 + 0x88);
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(param_3, owner, param_2, 0xc);
    MainBlob_ResetSlotRows(param_1, param_3);
}
