extern void NNSi_FndFreeFromDefaultHeap(void *);

void Ov007_FreeResourceRecordBuffer(void **p)
{
    if (*p) {
        NNSi_FndFreeFromDefaultHeap(*p);
    }
}
