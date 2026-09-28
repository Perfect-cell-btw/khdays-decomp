/* Returns the byte at +0xc, or the byte at +0xa when the first is negative. */

int Ov022_GetByteCOrA(int arg0) {
    int r = *(char *)(arg0 + 0xc);
    if (r < 0) r = *(char *)(arg0 + 10);
    return r;
}
