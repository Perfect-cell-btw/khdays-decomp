extern void Ov105_SetField30IfModeAllows(unsigned int id);
extern int Ov105_PumpSubStateA(void);
extern void Ov105_KickIdleHandler(void);

/* If the request carries a target id, apply it and finish; otherwise try the fallback and only
 * finish when it declines. */
void Ov105_OnRequestDoneA(int req) {
    if (*(unsigned short *)(req + 2) != 0) {
        Ov105_SetField30IfModeAllows(*(unsigned short *)(req + 2));
        Ov105_KickIdleHandler();
        return;
    }
    if (Ov105_PumpSubStateA() != 0) {
        return;
    }
    Ov105_KickIdleHandler();
}
