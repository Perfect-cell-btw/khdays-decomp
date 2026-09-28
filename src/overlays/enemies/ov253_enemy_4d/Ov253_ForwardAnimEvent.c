extern int SetSubitemState();

int Ov253_ForwardAnimEvent(int *r0, int r1, int r2) {
    return SetSubitemState(r0[0xE1], 0, (short)r1, r2);
}
