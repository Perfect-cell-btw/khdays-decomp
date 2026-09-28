/* Decrements a global counter (data_0204bda0) when it is positive; returns its value. */

extern int data_0204bda0;

int func_020208f0(void) {
    int v = *(short *)&data_0204bda0;
    if (v > 0) {
        v -= 1;
        *(short *)&data_0204bda0 = v;
    }
    return v;
}
