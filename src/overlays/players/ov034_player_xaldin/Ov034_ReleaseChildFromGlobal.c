/* Releases the animation sub-block of this overlay's shared battle object. */

extern int ReleaseField74AndCleanup(int);
extern int data_ov034_020b5660;

int Ov034_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov034_020b5660 + 0x2d0c);
}
