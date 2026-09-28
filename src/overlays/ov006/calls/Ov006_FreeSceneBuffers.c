/* Ov006_FreeSceneBuffers -- free the Mission Mode scene's dynamic buffers, ov006.
 * Frees the primary buffer (base[0]) if allocated, then walks the 4-entry buffer table at
 * base+8 (8-byte stride), freeing and nulling each non-null pointer. */
extern void NNSi_FndFreeFromDefaultHeap(int p);
extern int  data_ov006_020565e4;

void Ov006_FreeSceneBuffers(void) {
    unsigned int i;
    if (*(int *)data_ov006_020565e4 != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)data_ov006_020565e4);
        *(int *)data_ov006_020565e4 = 0;
    }
    i = 0;
    do {
        int p = *(int *)(data_ov006_020565e4 + i * 8 + 8);
        if (p != 0) {
            NNSi_FndFreeFromDefaultHeap(p);
            *(int *)(data_ov006_020565e4 + i * 8 + 8) = 0;
        }
        i = i + 1 & 0xff;
    } while (i < 4);
}
