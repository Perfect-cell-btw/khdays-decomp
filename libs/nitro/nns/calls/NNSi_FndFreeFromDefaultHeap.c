extern void NNS_FndFreeToExpHeap(void *heap, void *user_ptr);
extern void **gCurrentHeap;

void NNSi_FndFreeFromDefaultHeap(void *user_ptr) {
    NNS_FndFreeToExpHeap(*gCurrentHeap, user_ptr);
}
