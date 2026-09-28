int Ov008_ClampWrapIndex(int a, int b, int c) {
    if (a < b) {
        a = (short)(c - 1);
    }
    if (a >= c) {
        a = b;
    }
    return a;
}
