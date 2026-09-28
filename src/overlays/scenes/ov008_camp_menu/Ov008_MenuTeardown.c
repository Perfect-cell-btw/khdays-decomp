/* Ov008_MenuTeardown -- tear down an ov008 menu object: release its two renderers
 * (obj+0x4f4, obj+0x51c), free each live text buffer (obj+0x1b8 / obj+0x31c, gated by
 * obj+0x140 / obj+0x144), release the base node (obj+0x38) and run the final cleanup. */
extern void NNS_GfdSetFrmTexVramState(int p);
extern void NNS_GfdSetFrmPlttVramState(int p);
extern void Ov008_ReleaseSlotObject(int p);
extern void ReleaseField74AndCleanup(int p);
extern void Ov008_FreeMsgBlock(int obj);

void Ov008_MenuTeardown(int param_1) {
    NNS_GfdSetFrmTexVramState(param_1 + 0x4f4);
    NNS_GfdSetFrmPlttVramState(param_1 + 0x51c);
    if (*(int *)(param_1 + 0x140) != 0) {
        Ov008_ReleaseSlotObject(param_1 + 0x1b8);
    }
    if (*(int *)(param_1 + 0x144) != 0) {
        Ov008_ReleaseSlotObject(param_1 + 0x31c);
    }
    ReleaseField74AndCleanup(param_1 + 0x38);
    Ov008_FreeMsgBlock(param_1);
}
