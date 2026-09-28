extern char *Archive_LoadFile(void *source, int count);
extern void Ov008_LoadLayoutResources(void *context, void *data);
extern void Ov008_LoadElemsFromLayout(void *context, void *data);
extern void Ov008_BuildLayoutFromTagTable(void *context, void *data);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_LoadLayoutResource(void *context, void *source)
{
    char *block = Archive_LoadFile(source, 0xe);
    int offset0 = *(int *)block;
    int offset2 = *(int *)(block + 8);
    int offset1 = *(int *)(block + 4);

    Ov008_LoadLayoutResources(context, block + offset0);
    Ov008_LoadElemsFromLayout(context, block + offset1);
    Ov008_BuildLayoutFromTagTable(context, block + offset2);

    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
    }
}
