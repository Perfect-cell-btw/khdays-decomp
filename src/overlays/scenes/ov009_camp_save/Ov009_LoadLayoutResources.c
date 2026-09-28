/* For each of the n records in the blob, alloc, copy its payload, and register it. */
extern void *NNS_FndAllocFromDefaultExpHeapEx(int size, int align);
extern void MIi_CpuCopyFast(const void *src, void *dst, int size);
extern void Ov009_AllocResourceEntry(int owner, void *obj, unsigned short kind);
void Ov009_LoadLayoutResources(int param_1, int param_2) {
    unsigned int n = *(unsigned int *)param_2;
    unsigned int i;
    int p = param_2 + 4;
    for (i = 0; i < n; i++) {
        void *obj = NNS_FndAllocFromDefaultExpHeapEx(*(int *)p - 8, 4);
        MIi_CpuCopyFast((const void *)(p + 8), obj, *(int *)p - 8);
        Ov009_AllocResourceEntry(param_1, obj, *(unsigned short *)(p + 4));
        p += *(int *)p;
    }
}
