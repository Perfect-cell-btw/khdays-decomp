extern void NNS_FndFreeToExpHeap(void *heap, void *user_ptr);
extern void **data_0204c028;

void NNSi_FndFreeFromDefaultHeap(void *user_ptr) {
    NNS_FndFreeToExpHeap(*data_0204c028, user_ptr);
}
