/* Ov008_UpdateMissionModeFrame -- title screen per-frame state function, ov006.
 * Copies the 15-entry sub-state handler table (data_ov008_0208fd8c) to the stack, runs the
 * per-frame title helpers (Ov008_CommitPendingSubState input/logic, Ov008_UpdateCharacterSelectTweens animation),
 * updates the shared object (Ov008_TickSelectionWidget on obj+8), then dispatches the current
 * sub-state's handler (obj[0x94f4] indexes the table) when it is valid (>= 0), and finishes
 * with the three render/commit passes (Ov008_RefreshCharacterSelectPortrait / 02054ab0 / 02053fd0). */
struct Table15 { void (*fn[15])(void); };
extern struct Table15 data_ov008_0208fd8c;
extern int *data_ov008_02090fa4;
extern void Ov008_CommitPendingSubState(void);
extern void Ov008_UpdateCharacterSelectTweens(void);
extern void Ov008_TickSelectionWidget(void *p);
extern void Ov008_RefreshCharacterSelectPortrait(void);
extern void Ov008_FlushDirtyCells_2(void);
extern void Ov008_CommitMissionModeUiSlots(void);

int Ov008_UpdateMissionModeFrame(void) {
    struct Table15 tbl = data_ov008_0208fd8c;
    int st;
    Ov008_CommitPendingSubState();
    Ov008_UpdateCharacterSelectTweens();
    Ov008_TickSelectionWidget((char *)data_ov008_02090fa4 + 8);
    st = *(int *)((char *)data_ov008_02090fa4 + 0x94f4);
    if (-1 < st) {
        tbl.fn[st]();
    }
    Ov008_RefreshCharacterSelectPortrait();
    Ov008_FlushDirtyCells_2();
    Ov008_CommitMissionModeUiSlots();
    return 0;
}
