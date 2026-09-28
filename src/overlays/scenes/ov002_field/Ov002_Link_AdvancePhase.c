/* When the session is ready, advances the slot phase (3 for the host, 4 otherwise); returns 1 while
 * it is not ready. */

extern int Session_IsReady();
extern int Ov002_AdvanceSlotPhase();

int Ov002_Link_AdvancePhase(int arg0) {
    if (Session_IsReady(arg0) == 0) {
        return 1;
    }
    return Ov002_AdvanceSlotPhase((arg0 != 0 ? 3 : 4) & 0xff);
}
