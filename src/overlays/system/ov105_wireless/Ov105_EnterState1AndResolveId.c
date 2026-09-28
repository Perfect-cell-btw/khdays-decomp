extern void Ov105_WH_ChangeSysState(int state);
extern int Ov105_SelectChannel(unsigned int id);
extern char data_ov105_020c04c0[];
/* Enter state 1 and resolve the queued id (+10) into the active slot (+2), returning it. */
unsigned short Ov105_EnterState1AndResolveId(void) {
    Ov105_WH_ChangeSysState(1);
    *(short *)(data_ov105_020c04c0 + 2) =
        Ov105_SelectChannel(*(unsigned short *)(data_ov105_020c04c0 + 10));
    return *(unsigned short *)(data_ov105_020c04c0 + 2);
}
