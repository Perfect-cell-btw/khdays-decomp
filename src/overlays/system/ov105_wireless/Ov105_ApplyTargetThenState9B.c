extern void Ov105_WH_SetError(unsigned int id);
extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_WH_StateInStartChild(void);
/* If the request carries a target id, apply it and go to state 9; otherwise try the fallback and
 * only fall back to state 9 when it declines. */
void Ov105_ApplyTargetThenState9B(int req) {
    if (*(unsigned short *)(req + 2) != 0) {
        Ov105_WH_SetError(*(unsigned short *)(req + 2));
        Ov105_WH_ChangeSysState(9);
        return;
    }
    if (Ov105_WH_StateInStartChild() != 0) {
        return;
    }
    Ov105_WH_ChangeSysState(9);
}
