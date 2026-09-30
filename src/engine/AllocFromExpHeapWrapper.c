/* Allocates 4-byte-aligned memory from the given expanded heap, or from the default game heap when
 * none is given. */

extern int NNS_FndAllocFromExpHeapEx();
extern int gCurrentHeap;

int AllocFromExpHeapWrapper(int size, int *heap) {
    if (heap == 0) heap = *(int **)&gCurrentHeap;
    return NNS_FndAllocFromExpHeapEx(*heap, size, 4);
}
