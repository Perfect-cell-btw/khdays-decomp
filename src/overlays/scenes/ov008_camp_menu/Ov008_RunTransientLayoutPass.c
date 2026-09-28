/* Ov008_RunTransientLayoutPass -- build, hand over and tear down one transient layout pass.
 * Everything lives on the stack: an NNSFndList threaded at offset 0x28, a 0x100-byte state block
 * and a 0x1e0-byte work area. The state is initialised, populated from `arg`, resolved, handed to
 * PlayRecord_FoldFrame for the caller's object, post-processed, and released again before returning --
 * nothing survives the call. */
extern void NNS_FndInitList(void *list, int offset);
extern void Ov008_InitRecordContext(void *state, int v);
extern void Ov008_BuildMenuGrid(void *state, void *work, void *list, int arg);
extern void Ov008_RebuildViewAndCountCells(void *state, void *work, void *list);
extern void PlayRecord_FoldFrame(int obj, void *state);
extern void Ov008_ReleaseHandleGridAndList(void *state, void *work, void *list);
extern void func_ov008_02053464(void *state);

void Ov008_RunTransientLayoutPass(int obj, int arg) {
    char list[0xc];
    char work[0x1e0];
    char state[0x100];

    NNS_FndInitList(list, 0x28);
    Ov008_InitRecordContext(state, 0);
    Ov008_BuildMenuGrid(state, work, list, arg);
    Ov008_RebuildViewAndCountCells(state, work, list);
    PlayRecord_FoldFrame(obj, state);
    Ov008_ReleaseHandleGridAndList(state, work, list);
    func_ov008_02053464(state);
}
