extern void Ov105_SetField30IfModeAllows(unsigned int id);
/* A real target id (not 0 and not 0xf) goes to the mode-gated setter; otherwise notify the
 * request's completion callback with "was cancelled". */
void Ov105_DispatchOrNotifyCancel(int req) {
    unsigned int id = *(unsigned short *)(req + 2);
    if (id != 0 && id != 0xf) {
        Ov105_SetField30IfModeAllows(id);
        return;
    }
    if (*(void (**)(int))(req + 0x20) != 0) {
        (*(void (**)(int))(req + 0x20))(id == 0);
    }
}
