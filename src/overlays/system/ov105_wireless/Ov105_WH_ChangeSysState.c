/* NitroSDK wireless helper (wh.c) WH_ChangeSysState: sets the system state (+0x24): 1 idle, 3 busy,
 * 9 error, 10 fatal. */
extern int data_ov105_020c04c0;
void Ov105_WH_ChangeSysState(int state) {
    *(int *)((char *)&data_ov105_020c04c0 + 0x24) = state;
}
