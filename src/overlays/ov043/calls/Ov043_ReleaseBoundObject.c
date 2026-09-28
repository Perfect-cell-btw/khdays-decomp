/* Clear the +0x2d34 byte of the sub-block and tail-call 0202a7dc. */
extern int ReleaseField74AndCleanup(int);
int Ov043_ReleaseBoundObject(int param_1) {
    int p = param_1 + 0x2c2c;
    *(unsigned char *)(p + 0x108) = 0;
    return ReleaseField74AndCleanup(p);
}
