/* Creates the main and sub expanded heaps and their allocators, and sets the default and current
 * heaps. */

extern void Ov001_CreateMainAndSubHeaps(void **out_heap0, void **out_heap1);
extern void NNS_FndInitAllocatorForExpHeap(void *allocator, void *heap, int align);
extern void **data_0204c024;
extern void **gCurrentHeap;
extern void **data_0204c02c;
extern void *data_0204c030;
extern int data_0204c034;
extern void *data_0204c044;
extern int data_0204c048;

void func_ov001_0204cf5c(void) {
    void *heap0;
    void *heap1;

    Ov001_CreateMainAndSubHeaps(&heap0, &heap1);
    data_0204c044 = heap0;
    NNS_FndInitAllocatorForExpHeap(&data_0204c048, heap0, 4);
    data_0204c024 = &data_0204c044;
    data_0204c030 = heap1;
    NNS_FndInitAllocatorForExpHeap(&data_0204c034, heap1, 4);
    data_0204c02c = &data_0204c030;
    gCurrentHeap = &data_0204c030;
}
