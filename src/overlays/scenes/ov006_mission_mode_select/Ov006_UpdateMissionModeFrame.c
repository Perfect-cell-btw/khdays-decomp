/* Ov006_UpdateMissionModeFrame -- Mission Mode per-frame state function, ov006.
 * Copies the 15-entry sub-state handler table (data_ov006_020562d0) to the stack, runs the
 * per-frame Mission Mode helpers (Ov006_CommitPendingSubState input/logic, Ov006_UpdateCharacterSelectTweens animation),
 * updates the shared object (Ov006_TickSelectionWidget on obj+8), then dispatches the current
 * sub-state's handler (obj[0x94f4] indexes the table) when it is valid (>= 0), and finishes
 * with the three render/commit passes (Ov006_RefreshCharacterSelectPortrait / 02054ab0 / 02053fd0). */
struct Table15 { void (*fn[15])(void); };
extern struct Table15 data_ov006_020562d0;
extern int *data_ov006_02056664;
extern void Ov006_CommitPendingSubState(void);
extern void Ov006_UpdateCharacterSelectTweens(void);
extern void Ov006_TickSelectionWidget(void *p);
extern void Ov006_RefreshCharacterSelectPortrait(void);
extern void Ov006_FlushDirtyCells(void);
extern void Ov006_CommitMissionModeUiSlots(void);

int Ov006_UpdateMissionModeFrame(void) {
    struct Table15 tbl = data_ov006_020562d0;
    int st;
    Ov006_CommitPendingSubState();
    Ov006_UpdateCharacterSelectTweens();
    Ov006_TickSelectionWidget((char *)data_ov006_02056664 + 8);
    st = *(int *)((char *)data_ov006_02056664 + 0x94f4);
    if (-1 < st) {
        tbl.fn[st]();
    }
    Ov006_RefreshCharacterSelectPortrait();
    Ov006_FlushDirtyCells();
    Ov006_CommitMissionModeUiSlots();
    return 0;
}
