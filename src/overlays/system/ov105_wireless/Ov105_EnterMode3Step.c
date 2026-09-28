/*
 * Ov105_EnterMode3Step -- x3 (ov105/...). Enter mode 3 and run its callback-driven step.
 * Set mode via 020be49c(3), then run 020be294(&020be880). If it reports 2 (still busy) return 1;
 * otherwise commit the result through 020be4ac(result) and return 0.
 */
extern void Ov105_WH_ChangeSysState(int mode);
extern int Ov105_WM_EndMP(void *cb);
extern void Ov105_WH_SetError(int result);
extern void Ov105_OnRequestDoneA(void);

int Ov105_EnterMode3Step(void) {
    int r;

    Ov105_WH_ChangeSysState(3);
    r = Ov105_WM_EndMP(&Ov105_OnRequestDoneA);
    if (r == 2) {
        return 1;
    }
    Ov105_WH_SetError(r);
    return 0;
}
