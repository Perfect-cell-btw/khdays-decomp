/* Ov000_RunTransientLayoutPass -- build, hand over and tear down one transient layout pass.
 * Everything lives on the stack: an NNSFndList threaded at offset 0x28, a 0x100-byte state block
 * and a 0x1e0-byte work area. The state is initialised, populated from `arg`, resolved, handed to
 * PlayRecord_FoldFrame for the caller's object, post-processed, and released again before returning --
 * nothing survives the call. */
extern void NNS_FndInitList(void *list, int offset);
extern void Ov000_InitRecordContext(void *state, int v);
extern void Ov000_BuildMenuGrid(void *state, void *work, void *list, int arg);
extern void Ov000_RebuildViewAndCountCells(void *state, void *work, void *list);
extern void PlayRecord_FoldFrame(int obj, void *state);
extern void Ov000_ReleaseHandleGridAndList(void *state, void *work, void *list);
extern void func_ov000_02058360(void *state);

void Ov000_RunTransientLayoutPass(int obj, int arg) {
    char list[0xc];
    char work[0x1e0];
    char state[0x100];

    NNS_FndInitList(list, 0x28);
    Ov000_InitRecordContext(state, 0);
    Ov000_BuildMenuGrid(state, work, list, arg);
    Ov000_RebuildViewAndCountCells(state, work, list);
    PlayRecord_FoldFrame(obj, state);
    Ov000_ReleaseHandleGridAndList(state, work, list);
    func_ov000_02058360(state);
}
