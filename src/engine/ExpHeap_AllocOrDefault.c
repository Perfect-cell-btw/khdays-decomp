/* Allocates memory with the given alignment from the given expanded heap, or from the default game
 * heap when none is given. */

extern void *NNS_FndAllocFromExpHeapEx(int heap, unsigned size, int align);
extern int **gCurrentHeap;

void *ExpHeap_AllocOrDefault(unsigned size, int align, int **heapPP) {
    if (heapPP == 0) heapPP = gCurrentHeap;
    return NNS_FndAllocFromExpHeapEx(*(int *)heapPP, size, align);
}
