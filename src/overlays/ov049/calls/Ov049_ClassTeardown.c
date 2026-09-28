extern char *NNSi_FndGetCurrentRootHeap(void);
extern unsigned char data_0204c240;
extern void FreeAllResourceTables(void *);
extern void NNSi_FndFreeFromDefaultHeap(void *);
extern void Ov002_FreeResourceTables(void *, void *);
extern void Ov049_ReleaseChannelAndFreeSubObject(void *);
extern void Ov022_DestroyRoot(void *);

void Ov049_ClassTeardown(void)
{
    char *r4 = NNSi_FndGetCurrentRootHeap();
    if (!(data_0204c240 & 4)) {
        FreeAllResourceTables(r4 + 0x2c2c);
        NNSi_FndFreeFromDefaultHeap(*(void **)(r4 + 0x2c50));
    }
    Ov002_FreeResourceTables(r4 + 0x2c54, r4 + 0x910);
    Ov002_FreeResourceTables(r4 + 0x2ca8, r4 + 0x910);
    Ov049_ReleaseChannelAndFreeSubObject(r4);
    Ov022_DestroyRoot(r4);
}
