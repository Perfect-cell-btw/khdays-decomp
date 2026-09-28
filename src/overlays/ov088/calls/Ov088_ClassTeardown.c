extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov088_freeSubitemChannelResources();
extern void Ov022_DestroyRoot();

void Ov088_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov088_freeSubitemChannelResources(p);
    Ov022_DestroyRoot(p);
}
