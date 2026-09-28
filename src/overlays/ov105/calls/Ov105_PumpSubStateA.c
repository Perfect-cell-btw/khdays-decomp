extern int Ov105_RunTransitionSlot9(void *handler);
extern void Ov105_SetField30IfModeAllows(int id);
extern void Ov105_DispatchTargetOrReset(int req);
/* Pump the sub-state with its handler; unless it reports 2 (still running), publish the result
 * and report done. */
int Ov105_PumpSubStateA(void) {
    int r = Ov105_RunTransitionSlot9(&Ov105_DispatchTargetOrReset);
    if (r != 2) {
        Ov105_SetField30IfModeAllows(r);
        return 0;
    }
    return 1;
}
