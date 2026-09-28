/* Ov105_GetTransitionFrame -- read the current transition frame, ov105. Returns 0x8000 while
 * a transition is running (Ov105_IsDeviceReady != 0), else the shared frame word @0x027ffcfa. */
extern int Ov105_IsDeviceReady(void);
int Ov105_GetTransitionFrame(void) {
    if (Ov105_IsDeviceReady() != 0) {
        return 0x8000;
    }
    return *(unsigned short *)0x27ffcfa;
}
