/* Ov005_RunTransientLayoutPass -- build, hand over and tear down one transient layout pass.
 * Everything lives on the stack: an NNSFndList threaded at offset 0x28, a 0x100-byte state block
 * and a 0x1e0-byte work area. The state is initialised, populated from `arg`, resolved, handed to
 * PlayRecord_FoldFrame for the caller's object, post-processed, and released again before returning --
 * nothing survives the call. */
extern void NNS_FndInitList(void *list, int offset);
extern void Ov005_InitRecordContext(void *state, int v);
extern void Ov005_BuildMenuGrid(void *state, void *work, void *list, int arg);
extern void Ov005_RebuildViewAndCountCells(void *state, void *work, void *list);
extern void PlayRecord_FoldFrame(int obj, void *state);
extern void Ov005_ReleaseHandleGridAndList(void *state, void *work, void *list);
extern void Ov005_ReleasePanelViewVeneer(void *state);

void Ov005_RunTransientLayoutPass(int obj, int arg) {
    char list[0xc];
    char work[0x1e0];
    char state[0x100];

    NNS_FndInitList(list, 0x28);
    Ov005_InitRecordContext(state, 0);
    Ov005_BuildMenuGrid(state, work, list, arg);
    Ov005_RebuildViewAndCountCells(state, work, list);
    PlayRecord_FoldFrame(obj, state);
    Ov005_ReleaseHandleGridAndList(state, work, list);
    Ov005_ReleasePanelViewVeneer(state);
}
