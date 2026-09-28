extern int NNSi_FndFreeFromDefaultHeap();

void FreeAndClearIfNonNeg(int *arg0, int arg1) {
    if (arg1 >= 0 && *arg0 != 0) NNSi_FndFreeFromDefaultHeap(*arg0);
    *arg0 = 0;
}
