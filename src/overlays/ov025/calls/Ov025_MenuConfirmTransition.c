/* Ov025_MenuConfirmTransition -- ov008 menu "confirm" transition with a one-shot cue (id 0x35bd).
 * Resets two sub-widgets (Ov025_SetCtxField9678/020511c8), toggles two others
 * (Ov025_SetCtxObject9630(1)/02051010(0)); if cue 0x35bd is not already active
 * (GameState_IsFlagSet), arm it: Ov025_ArmCueRequest(0x1e,1,1), trigger GameState_SetFlag(0x35bd) and
 * advance to step 4 (Ov025_SetGlobalConfigAndInit); otherwise just set the active slot. Fires the UI
 * event PlaySound(0,1) at the end. */
extern void Ov025_SetCtxField9678(int a);
extern void Ov025_SetCtxField967c(int a);
extern void Ov025_SetCtxObject9630(int a);
extern void Ov025_SetCtxObject9634(int a);
extern int  GameState_IsFlagSet(int cue);
extern void Ov025_ArmCueRequest(int a, int b, int c);
extern void GameState_SetFlag(int cue);
extern void Ov025_SetGlobalConfigAndInit(int step);
extern void Ov025_SetTargetSlot(int a, int b);
extern void PlaySound(int a, int b);

void Ov025_MenuConfirmTransition(void) {
    Ov025_SetCtxField9678(0);
    Ov025_SetCtxField967c(0);
    Ov025_SetCtxObject9630(1);
    Ov025_SetCtxObject9634(0);
    if (GameState_IsFlagSet(0x35bd) == 0) {
        Ov025_ArmCueRequest(0x1e, 1, 1);
        GameState_SetFlag(0x35bd);
        Ov025_SetGlobalConfigAndInit(4);
    } else {
        Ov025_SetTargetSlot(1, -1);
    }
    PlaySound(0, 1);
}
