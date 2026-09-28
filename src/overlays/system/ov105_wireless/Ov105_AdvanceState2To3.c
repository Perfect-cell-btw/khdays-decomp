extern void Ov105_WH_ChangeSysState(int state);
extern char data_ov105_020c04c0[];
/* Advance from state 2 to state 3, clearing the pending id; returns 1 when it fired. */
int Ov105_AdvanceState2To3(void) {
    if (*(int *)(data_ov105_020c04c0 + 0x24) == 2) {
        *(unsigned short *)(data_ov105_020c04c0 + 6) = 0;
        Ov105_WH_ChangeSysState(3);
        return 1;
    }
    return 0;
}
