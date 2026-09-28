/* Ov008_CheckMissionMenuConfirmInput -- test whether the title menu confirm should fire, ov006.
 * When the title is idle (base+0x20 == 0), checks the currently highlighted option
 * (Ov008_MissionCommitRowSelection on the 0-based cursor from base+0x38); when active, checks the generic
 * confirm (Ov008_MissionResetInputBuffers). Either success selects the confirm state fn
 * (Ov008_UpdateMissionMenuConfirmScreen). Always refreshes the cursor sprite (Ov008_SetMissionCursorSelection(0xff)) and, on
 * confirm, plays the decide SFX (Ov008_RequestMenuState(2,0)). Returns the selected state (or 0). */
extern int  Ov008_MissionResetInputBuffers(void);
extern int  Ov008_MissionCommitRowSelection(int option);
extern void Ov008_SetMissionCursorSelection(int a);
extern void Ov008_RequestMenuState(int a, int b, int c);
extern int  data_ov008_02090fa0;
extern void Ov008_UpdateMissionMenuConfirmScreen(void);

int Ov008_CheckMissionMenuConfirmInput(void) {
    int result = 0;
    if (*(int *)(data_ov008_02090fa0 + 0x20) != 0) {
        if (Ov008_MissionResetInputBuffers() != 0) {
            result = (int)Ov008_UpdateMissionMenuConfirmScreen;
        }
    } else {
        if (Ov008_MissionCommitRowSelection((*(int *)(data_ov008_02090fa0 + 0x38) - 1U) & 0xff) != 0) {
            result = (int)Ov008_UpdateMissionMenuConfirmScreen;
        }
    }
    Ov008_SetMissionCursorSelection(-1);
    if (result != 0) {
        Ov008_RequestMenuState(2, 0, 0);
    }
    return result;
}
