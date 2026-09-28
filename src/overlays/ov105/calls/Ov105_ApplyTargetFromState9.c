extern void Ov105_SetField24(int state);
extern void Ov105_SetField30IfModeAllows(unsigned int id);
extern void Ov105_WH_FreeBuffers(void);
/* If the request carries a target id, go to state 9 and apply it; otherwise reset and return to
 * state 1. */
void Ov105_ApplyTargetFromState9(int req) {
    if (*(unsigned short *)(req + 2) != 0) {
        Ov105_SetField24(9);
        Ov105_SetField30IfModeAllows(*(unsigned short *)(req + 2));
        return;
    }
    Ov105_WH_FreeBuffers();
    Ov105_SetField24(1);
}
