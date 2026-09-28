/* Allocate 0x20 bytes from the given expanding heap. */
extern void *NNS_FndAllocFromDefaultExpHeapEx(void *heap, int size);
void *Ov024_MobiClip_Alloc(void *param_1) {
    return NNS_FndAllocFromDefaultExpHeapEx(param_1, 0x20);
}
