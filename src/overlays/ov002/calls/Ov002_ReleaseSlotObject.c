extern void ReleaseField74AndCleanup(void *object);
extern void FreeAllResourceTables(void *object);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov002_ReleaseSlotObject(void *object)
{
    if (*(signed char *)((char *)object + 1) != 0) {
        ReleaseField74AndCleanup((char *)object + 4);

        if ((*(unsigned char *)object & 4) != 0) {
            FreeAllResourceTables((char *)object + 0x13c);
            NNSi_FndFreeFromDefaultHeap(*(void **)((char *)object + 0x160));
        }

        *(unsigned char *)object = 0;
    }
}
