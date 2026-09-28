extern void NNSi_FndFreeFromDefaultHeap();

void Ov000_FreeResourceRecordBuffer(void **p)
{
    void *v = p[0];
    if (v) {
        NNSi_FndFreeFromDefaultHeap(v);
    }
}
