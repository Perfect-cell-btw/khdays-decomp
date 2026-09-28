extern void Ov105_WH_SetError(int code);
extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_SetSessionCallback(void *fn);
extern void Ov105_TerminateOnState8(void);

/* Step handler: leaves for state 0xa when the request word is set or the sub-task is still
 * running, otherwise falls back to state 1. */
void Ov105_StepOrFallBack(unsigned short *req) {
    int result;

    if (req[1] != 0) {
        Ov105_WH_SetError(req[1]);
        Ov105_WH_ChangeSysState(0xa);
        return;
    }
    result = Ov105_SetSessionCallback((void *)&Ov105_TerminateOnState8);
    if (result != 0) {
        Ov105_WH_SetError(result);
        Ov105_WH_ChangeSysState(0xa);
        return;
    }
    Ov105_WH_ChangeSysState(1);
}
