extern void NNSi_FndFreeFromDefaultHeap(void *);
void Ov008_FreeResourceRecordBuffer(void **slot)
{
    if (*slot != 0) {
        NNSi_FndFreeFromDefaultHeap(*slot);
    }
}
