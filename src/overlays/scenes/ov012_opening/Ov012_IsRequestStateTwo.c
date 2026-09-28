extern int NNSi_FndGetCurrentRootHeap();

int Ov012_IsRequestStateTwo(void) {
    int h = NNSi_FndGetCurrentRootHeap();
    return *(int *)(h + 0x8bd8) == 2 || *(int *)(h + 0x8bdc) == 2;
}
