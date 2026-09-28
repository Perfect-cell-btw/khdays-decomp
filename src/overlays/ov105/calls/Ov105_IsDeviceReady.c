extern char data_ov105_020bfa20[];
/* Report 3 (not ready) while the device's u16 handle is still zero, else 0. */
int Ov105_IsDeviceReady(void) {
    if (*(unsigned short *)data_ov105_020bfa20 != 0) {
        return 0;
    }
    return 3;
}
