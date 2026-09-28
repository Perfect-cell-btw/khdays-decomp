extern void Ov105_WH_SetError(unsigned int id);
extern void Ov105_WH_Finalize(void);
extern int Ov105_WH_StateInEndChild(void);
extern void Ov105_WH_ChangeSysState(int state);

/* If the request carries a target id, apply it and finish; otherwise try the fallback and only
 * go to state 9 when it declines. */
void Ov105_OnRequestDoneB(int req) {
    if (*(unsigned short *)(req + 2) != 0) {
        Ov105_WH_SetError(*(unsigned short *)(req + 2));
        Ov105_WH_Finalize();
        return;
    }
    if (Ov105_WH_StateInEndChild() != 0) {
        return;
    }
    Ov105_WH_ChangeSysState(9);
}
