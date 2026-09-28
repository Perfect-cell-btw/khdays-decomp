extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_WM_SetParentParameter(void *fn, void *arg);
extern void Ov105_WH_SetError(int code);
extern void Ov105_WH_StateOutSetParentParam(void);
extern int data_ov105_020c0580;

/* Runs the step-3 sub-task; returns 1 while it is still going, 0 once it has finished and the
 * task has moved on to step 9. */
int Ov105_RunStep3(void) {
    int result;

    Ov105_WH_ChangeSysState(3);
    result = Ov105_WM_SetParentParameter((void *)&Ov105_WH_StateOutSetParentParam, &data_ov105_020c0580);
    if (result == 2) {
        return 1;
    }
    Ov105_WH_SetError(result);
    Ov105_WH_ChangeSysState(9);
    return 0;
}
