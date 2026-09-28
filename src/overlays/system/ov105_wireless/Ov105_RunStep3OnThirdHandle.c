extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_WM_SetWEPKey(void *fn, int handle, void *arg);
extern void Ov105_WH_SetError(int code);
extern void Ov105_ApplyTargetThenState9B(void);
extern int data_ov105_020c04c0;
extern int data_ov105_020c0520;
extern int data_ov105_020c05c0;

/* Runs the step-3 sub-task through the backend's own opener; returns 1 while it is still going,
 * 0 once it has finished and the task has moved on to step 9. */
int Ov105_RunStep3OnThirdHandle(void) {
    int result;

    int handle;
    Ov105_WH_ChangeSysState(3);
    handle = (*(int (**)(void *, void *))((char *)&data_ov105_020c04c0 + 0x40))(
        &data_ov105_020c0520, &data_ov105_020c05c0);
    result = Ov105_WM_SetWEPKey((void *)&Ov105_ApplyTargetThenState9B, handle, &data_ov105_020c0520);
    if (result == 2) {
        return 1;
    }
    Ov105_WH_SetError(result);
    Ov105_WH_ChangeSysState(9);
    return 0;
}
