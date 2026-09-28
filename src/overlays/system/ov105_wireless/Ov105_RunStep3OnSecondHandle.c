extern void Ov105_WH_ChangeSysState(int state);
extern int func_ov105_020bd9ec(int handle, void *fn, int a);
extern void Ov105_WH_SetError(int code);
extern void Ov105_StepOrFallBack(void);
extern char *data_ov105_020c04c0;

/* Runs the step-3 sub-task on the backend's second handle; 1 while it is still going, 0 once it
 * has finished and the task has moved on to step 0xa. */
int Ov105_RunStep3OnSecondHandle(void) {
    int result;

    Ov105_WH_ChangeSysState(3);
    result = func_ov105_020bd9ec(*(int *)((char *)&data_ov105_020c04c0 + 0x4c),
                                   (void *)&Ov105_StepOrFallBack, 2);
    if (result == 2) {
        return 1;
    }
    Ov105_WH_SetError(result);
    Ov105_WH_ChangeSysState(0xa);
    return 0;
}
