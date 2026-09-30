/* Frees a block to the given expanded heap, or to the current heap when none is given. */

extern int NNS_FndFreeToExpHeap();
extern int gCurrentHeap;

int ExpHeap_Free(int block, int *heap) {
    if (heap == 0) heap = *(int **)&gCurrentHeap;
    return NNS_FndFreeToExpHeap(*heap, block);
}
