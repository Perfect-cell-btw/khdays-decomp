/* Releases the animation sub-block of this overlay's shared battle object. */

extern int ReleaseField74AndCleanup(int);
extern int data_ov072_020ba7a0;

int Ov072_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov072_020ba7a0 + 0x2e84);
}
