extern void *Archive_LoadFile(void *source, int count);
extern void Ov008_InstantiateAndLinkElements(void *context, void *block, int arg2);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_LoadBlockProcessAndFree(void *context, void *source, int arg2)
{
    void *block = Archive_LoadFile(source, 0xe);

    Ov008_InstantiateAndLinkElements(context, block, arg2);

    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
    }
}
