/* Releases the animation sub-block of this overlay's shared battle object. */

extern int ReleaseField74AndCleanup(int);
extern int data_ov052_020b80c0;

int Ov052_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov052_020b80c0 + 0x2e84);
}
