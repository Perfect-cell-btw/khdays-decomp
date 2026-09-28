extern int Ov105_IsDeviceReady(void);
extern void DC_InvalidateRange(void *addr, unsigned int size);
extern char data_ov105_020bfa20[];
/* Poll the sub-device: once the precheck clears, invalidate the two-byte status word and report
 * 3 while it still reads 1 or less, else 0. */
int Ov105_PollDeviceStatus(void) {
    int r = Ov105_IsDeviceReady();
    if (r == 0) {
        DC_InvalidateRange(*(void **)(*(int *)(data_ov105_020bfa20 + 4) + 4), 2);
        if (**(unsigned short **)(*(int *)(data_ov105_020bfa20 + 4) + 4) <= 1) {
            r = 3;
        } else {
            r = 0;
        }
        return r;
    }
    return r;
}
