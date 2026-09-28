extern int Ov002_GetPanelRequestBlock(void);
extern int Ov002_World_IsFlagBitSet(int bit);
extern void Ov002_SetPanelField003c(int a);
extern void Ov002_SetSeatFlag(int a, int b);
extern int Ov002_GetPanelField018c(void);
extern void GameState_SetField(int id, int a, unsigned short b);
extern void Ov002_ClearCurrentCaption(void);
extern void Ov002_ReleaseBattleViewFocus(void);

/* Confirms the highlighted mission: plays the accept cue, tears the browser down and starts the
 * mission, unless nothing is selected or the confirmation is refused. */
int Ov002_ConfirmMission(void) {
    int sel = Ov002_GetPanelRequestBlock();
    if (sel >= 0) {
        if (Ov002_World_IsFlagBitSet(sel) != 0) {
            Ov002_SetPanelField003c(1);
            Ov002_SetSeatFlag(sel, 0);
        }
        if (Ov002_GetPanelField018c() != 0) {
            GameState_SetField(0x208d, 2, (unsigned short)sel);
            Ov002_ClearCurrentCaption();
            Ov002_ReleaseBattleViewFocus();
            GameState_SetField(0x20ef, 1, 0);
            return 1;
        }
    }
    return 0;
}
