/* Bind a clip to an ov260 model bank: the bank drops its old clip, the model's animation clock
 * (+0x88 -> +0x20 / +0x78) resyncs, the clip loads at 12 bones, the bank attaches to the model on
 * track 0 with `flag` and the model's frame restarts (0203c7ac). */
extern void FreeAllResourceTables(void *bank);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(void *bank, int animation, int clip, int bones);
extern void MainBlob_ResetSlotRows(char *model, void *bank);
extern void SetSubitemState(char *model, int track, int a, int flag);
extern void RefreshObjectCallbacks(char *item, int a);

void Ov260_BindClip(char *model, void *bank, int clip, int flag)
{
    int anim = *(int *)(model + 0x88);

    FreeAllResourceTables(bank);
    NNS_G3dRenderObjInit(anim + 0x20, *(int *)(anim + 0x78));
    Snd_RegisterSeqAndBind(bank, anim, clip, 0xc);
    MainBlob_ResetSlotRows(model, bank);
    SetSubitemState(model, 0, 0, flag);
    RefreshObjectCallbacks(model, 0);
}
