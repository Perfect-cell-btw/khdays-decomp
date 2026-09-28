extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_FreeDetailBuffer(void *object)
{
    void *block = *(void **)((char *)object + 0x174);

    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
        *(int *)((char *)object + 0x174) = 0;
    }
}
