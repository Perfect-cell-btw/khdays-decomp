extern int ZeroHalfThenFree();

int Ov025_FreeMsgBlock(int arg0) {
    return ZeroHalfThenFree(*(int *)(arg0 + 0x1b4));
}
