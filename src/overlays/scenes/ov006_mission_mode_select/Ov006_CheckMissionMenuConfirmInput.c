/* Ov006_CheckMissionMenuConfirmInput -- test whether the Mission Mode menu confirm should fire, ov006.
 * When the Mission Mode is idle (base+0x20 == 0), checks the currently highlighted option
 * (Ov006_MissionCommitRowSelection on the 0-based cursor from base+0x38); when active, checks the generic
 * confirm (Ov006_MissionResetInputBuffers). Either success selects the confirm state fn
 * (Ov006_UpdateMissionMenuConfirmScreen). Always refreshes the cursor sprite (Ov006_SetMissionCursorSelection(0xff)) and, on
 * confirm, plays the decide SFX (Ov006_RequestMenuState(2,0)). Returns the selected state (or 0). */
extern int  Ov006_MissionResetInputBuffers(void);
extern int  Ov006_MissionCommitRowSelection(int option);
extern void Ov006_SetMissionCursorSelection(int a);
extern void Ov006_RequestMenuState(int a, int b, int c);
extern int  data_ov006_02056660;
extern void Ov006_UpdateMissionMenuConfirmScreen(void);

int Ov006_CheckMissionMenuConfirmInput(void) {
    int result = 0;
    if (*(int *)(data_ov006_02056660 + 0x20) != 0) {
        if (Ov006_MissionResetInputBuffers() != 0) {
            result = (int)Ov006_UpdateMissionMenuConfirmScreen;
        }
    } else {
        if (Ov006_MissionCommitRowSelection((*(int *)(data_ov006_02056660 + 0x38) - 1U) & 0xff) != 0) {
            result = (int)Ov006_UpdateMissionMenuConfirmScreen;
        }
    }
    Ov006_SetMissionCursorSelection(-1);
    if (result != 0) {
        Ov006_RequestMenuState(2, 0, 0);
    }
    return result;
}
