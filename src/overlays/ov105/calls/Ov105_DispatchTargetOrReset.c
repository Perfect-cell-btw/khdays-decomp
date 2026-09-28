extern void Ov105_SetField30IfModeAllows(unsigned int id);
extern void Ov105_WH_FreeBuffers(void);
extern void Ov105_SetField24(int state);
/* If the request carries a target id, hand it to the mode-gated setter; otherwise reset and go
 * back to state 1. */
void Ov105_DispatchTargetOrReset(int req) {
    if (*(unsigned short *)(req + 2) != 0) {
        Ov105_SetField30IfModeAllows(*(unsigned short *)(req + 2));
        return;
    }
    Ov105_WH_FreeBuffers();
    Ov105_SetField24(1);
}
