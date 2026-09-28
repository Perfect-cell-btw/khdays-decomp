/* Releases and frees the stream group at +0x2644. */

extern void func_ov022_02091228(int v);
extern void NNSi_FndFreeFromDefaultHeap(void *p);

void Ov039_FreeAttachedGroup(char *base) {
    func_ov022_02091228(*(int *)(base + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(void **)(base + 0x2644));
}
