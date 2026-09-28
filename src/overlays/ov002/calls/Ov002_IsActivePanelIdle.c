extern int Ov002_GetPhaseWord(void);
extern int func_ov022_02083fdc(void);
extern int Ov002_RunShutdownHook(void);
/* True when the active panel reports idle: mode 1 uses the mission query, anything else the
 * local one. */
int Ov002_IsActivePanelIdle(void) {
    int busy;
    if (Ov002_GetPhaseWord() == 1) {
        busy = func_ov022_02083fdc();
    } else {
        busy = Ov002_RunShutdownHook();
    }
    if (busy != 0) {
        return 0;
    }
    return 1;
}
