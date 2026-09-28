extern int Ov105_RunTransitionSlotB(void *handler);
extern void Ov105_SetField30IfModeAllows(int id);
extern void Ov105_WH_StateOutEndScan(int req);
/* Pump the sub-state with its handler; unless it reports 2 (still running), publish the result
 * and report done. */
int Ov105_PumpSubStateB(void) {
    int r = Ov105_RunTransitionSlotB(&Ov105_WH_StateOutEndScan);
    if (r != 2) {
        Ov105_SetField30IfModeAllows(r);
        return 0;
    }
    return 1;
}
