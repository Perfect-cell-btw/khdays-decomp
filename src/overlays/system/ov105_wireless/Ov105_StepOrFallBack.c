extern void Ov105_SetField30IfModeAllows(void);
extern void Ov105_SetField24(int state);
extern int Ov105_SetSessionCallback(void *fn);
extern void Ov105_TerminateOnState8(void);

/* Step handler: leaves for state 0xa when the request word is set or the sub-task is still
 * running, otherwise falls back to state 1. */
void Ov105_StepOrFallBack(unsigned short *req) {
    if (req[1] != 0) {
        Ov105_SetField30IfModeAllows();
        Ov105_SetField24(0xa);
        return;
    }
    if (Ov105_SetSessionCallback((void *)&Ov105_TerminateOnState8) != 0) {
        Ov105_SetField30IfModeAllows();
        Ov105_SetField24(0xa);
        return;
    }
    Ov105_SetField24(1);
}
