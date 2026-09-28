/* Clears the global track counter and resets its tracks. */

extern int data_0204c4d8;
extern int Ov002_ResetTracks();

int Ov002_ResetGlobalTracks(void) {
    *(int *)((char *)&data_0204c4d8 + 0x14) = 0;
    return Ov002_ResetTracks(&data_0204c4d8);
}
