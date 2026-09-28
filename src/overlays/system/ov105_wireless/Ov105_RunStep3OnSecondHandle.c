extern void Ov105_SetField24(int state);
extern int func_ov105_020bd9ec(int handle, void *fn, int a);
extern void Ov105_SetField30IfModeAllows(void);
extern void Ov105_StepOrFallBack(void);
extern char *data_ov105_020c04c0;

/* Runs the step-3 sub-task on the backend's second handle; 1 while it is still going, 0 once it
 * has finished and the task has moved on to step 0xa. */
int Ov105_RunStep3OnSecondHandle(void) {
    Ov105_SetField24(3);
    if (func_ov105_020bd9ec(*(int *)((char *)&data_ov105_020c04c0 + 0x4c),
                                   (void *)&Ov105_StepOrFallBack, 2) == 2) {
        return 1;
    }
    Ov105_SetField30IfModeAllows();
    Ov105_SetField24(0xa);
    return 0;
}
