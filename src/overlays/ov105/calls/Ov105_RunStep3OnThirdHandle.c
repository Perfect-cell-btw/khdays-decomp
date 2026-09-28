extern void Ov105_SetField24(int state);
extern int Ov105_WM_SetWEPKey(void *fn, int handle, void *arg);
extern void Ov105_SetField30IfModeAllows(void);
extern void Ov105_ApplyTargetThenState9B(void);
extern int data_ov105_020c04c0;
extern int data_ov105_020c0520;
extern int data_ov105_020c05c0;

/* Runs the step-3 sub-task through the backend's own opener; returns 1 while it is still going,
 * 0 once it has finished and the task has moved on to step 9. */
int Ov105_RunStep3OnThirdHandle(void) {
    int handle;
    Ov105_SetField24(3);
    handle = (*(int (**)(void *, void *))((char *)&data_ov105_020c04c0 + 0x40))(
        &data_ov105_020c0520, &data_ov105_020c05c0);
    if (Ov105_WM_SetWEPKey((void *)&Ov105_ApplyTargetThenState9B, handle, &data_ov105_020c0520) == 2) {
        return 1;
    }
    Ov105_SetField30IfModeAllows();
    Ov105_SetField24(9);
    return 0;
}
