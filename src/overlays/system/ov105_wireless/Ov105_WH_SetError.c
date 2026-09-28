/* NitroSDK wireless helper (wh.c) WH_SetError: records the error code (+0x30) unless the system
 * state (+0x24) is already ERROR (9) or FATAL (10) -- the ROM spells that as the unsigned range
 * test (state - 9) > 1. */
extern int data_ov105_020c04c0;
void Ov105_WH_SetError(int code) {
    if ((unsigned int)((&data_ov105_020c04c0)[9] - 9) > 1) (&data_ov105_020c04c0)[12] = code;
}
