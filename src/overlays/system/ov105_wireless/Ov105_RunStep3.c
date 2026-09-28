extern void Ov105_SetField24(int state);
extern int Ov105_WM_SetParentParameter(void *fn, void *arg);
extern void Ov105_SetField30IfModeAllows(void);
extern void Ov105_WH_StateOutSetParentParam(void);
extern int data_ov105_020c0580;

/* Runs the step-3 sub-task; returns 1 while it is still going, 0 once it has finished and the
 * task has moved on to step 9. */
int Ov105_RunStep3(void) {
    Ov105_SetField24(3);
    if (Ov105_WM_SetParentParameter((void *)&Ov105_WH_StateOutSetParentParam, &data_ov105_020c0580) == 2) {
        return 1;
    }
    Ov105_SetField30IfModeAllows();
    Ov105_SetField24(9);
    return 0;
}
