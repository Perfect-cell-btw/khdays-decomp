extern int Ov105_WMi_CheckStateEx(int a, int b);
extern void Ov105_SetCommandArg(int slot, int arg);
extern int Ov105_WMi_SendCommand(int slot, int flag);
/* Same transition shape as 020bda94, driving stage 7 into slot 9. */
int Ov105_RunTransitionSlot9(int arg) {
    int r = Ov105_WMi_CheckStateEx(1, 7);
    if (r != 0) {
        return r;
    }
    Ov105_SetCommandArg(9, arg);
    r = Ov105_WMi_SendCommand(9, 0);
    if (r == 0) {
        r = 2;
    }
    return r;
}
