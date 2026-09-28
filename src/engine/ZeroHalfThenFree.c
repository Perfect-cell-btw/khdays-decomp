/* Clears the first halfword of a block and frees it to the default heap. */

extern int NNSi_FndFreeFromDefaultHeap();

int ZeroHalfThenFree(void *arg0) {
    *(short *)arg0 = 0;
    return NNSi_FndFreeFromDefaultHeap(arg0);
}
