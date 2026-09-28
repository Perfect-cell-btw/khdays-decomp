extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_RunTransitionSlot2(void *step);
extern void Ov105_WH_StateOutEnd(void);
/* Enter state 3 and run the scripted step; unless it reports 2 (still running), drop to state 9. */
int Ov105_RunScriptedStepState3(void) {
    Ov105_WH_ChangeSysState(3);
    if (Ov105_RunTransitionSlot2(&Ov105_WH_StateOutEnd) != 2) {
        Ov105_WH_ChangeSysState(9);
        return 0;
    }
    return 1;
}
