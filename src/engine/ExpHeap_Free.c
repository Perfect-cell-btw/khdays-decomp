/* Frees a block to the given expanded heap, or to the current heap when none is given. */

extern int NNS_FndFreeToExpHeap();
extern int data_0204c028;

int ExpHeap_Free(int block, int *heap) {
    if (heap == 0) heap = *(int **)&data_0204c028;
    return NNS_FndFreeToExpHeap(*heap, block);
}
