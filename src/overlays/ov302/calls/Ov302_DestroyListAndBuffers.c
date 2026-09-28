extern void Ov002_FreeResourceRecordBuffer();
extern void Ov302_DestroyAllListObjects();
extern void NNSi_FndFreeFromDefaultHeap();

struct S {
    char pad[0x14];
    void *f14;
};

void Ov302_DestroyListAndBuffers(struct S *p)
{
    Ov002_FreeResourceRecordBuffer(p);
    Ov302_DestroyAllListObjects(p);
    if (p->f14) {
        NNSi_FndFreeFromDefaultHeap(p->f14);
        p->f14 = 0;
    }
}
