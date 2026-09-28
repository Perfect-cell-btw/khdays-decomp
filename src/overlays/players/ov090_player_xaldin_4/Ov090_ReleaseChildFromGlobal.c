/* Releases the animation sub-block of this overlay's shared battle object. */

extern int ReleaseField74AndCleanup(int);
extern int data_ov090_020bcc00;

int Ov090_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov090_020bcc00 + 0x2d0c);
}
